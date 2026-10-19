#!/usr/bin/env python3
"""Prepare narrow fresh-campaign adaptations; do not import or execute them."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import ast, csv, difflib, hashlib, json, secrets

P = Path('tests/evidence/optimization/gen24')
OLD = Path('tests/evidence/optimization/gen23')
def sha(p):
    with Path(p).open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()
def load(p):
    return json.loads(Path(p).read_text())
def write(p, value):
    assert not p.exists(), p
    p.write_text(json.dumps(value, indent=2) + '\n')
def now():
    return datetime.now(timezone.utc).isoformat()

assert not (P / 'preparation.json').exists()
assert not (P / 'seed-selection.json').exists()
names = ['fresh-orchestrate.py', 'fresh-run-campaign.py', 'fresh-verify.py',
         'fresh-retained-hashes.py', 'prepare_preflight.py',
         'finish_campaign.py', 'check_handoff.py']
prior_prep = load(OLD / 'preparation.json')
for name in names:
    assert sha(OLD / name) == prior_prep['adaptations'][name]['sha256'], name
    assert not (P / name).exists(), name
for name, h in prior_prep['unchanged_generator_inputs'].items():
    assert sha(name) == h, name

prior_seeds = load(OLD / 'fresh-seeds.json')
paths = set(prior_seeds['historical_seed_records_sha256']) | {str(OLD / 'fresh-seeds.json')}
seen, seed_bindings = set(), {}
for name in sorted(paths):
    seed_bindings[name] = sha(name)
    if name in prior_seeds['historical_seed_records_sha256']:
        assert seed_bindings[name] == prior_seeds['historical_seed_records_sha256'][name]
    for key, value in load(name).items():
        if 'seed' in key and type(value) is int:
            seen.add(value)
historical_count = len(seen)
rejected = []
def draw():
    while True:
        value = secrets.randbits(32)
        if value not in seen:
            seen.add(value)
            return value
        rejected.append(value)
message_seed, commb_seed = draw(), draw()
write(P / 'seed-selection.json', {
    'status': 'recorded_before_generation', 'recorded_utc': now(),
    'message_seed': message_seed, 'commb_seed': commb_seed,
    'sampling': 'Independent secrets.randbits(32) draws during explicitly authorized preparation; all prior and mutual collisions rejected.',
    'historical_seed_values_checked': historical_count,
    'historical_seed_records_sha256': seed_bindings, 'rejected_draws': rejected,
    'authorization': 'Root explicitly authorized seed sampling/recording during preparation; no executable generation until later release.',
    'generator_source_sha256': prior_prep['unchanged_generator_inputs'],
    'preparer_sha256': sha(__file__), 'no_campaign_started': True,
})

adaptations = {}
(P / 'preparation-adaptations').mkdir()
for name in names:
    before = (OLD / name).read_text()
    source = before.replace('gen23', 'GEN_CURRENT').replace('gen22', 'gen23').replace('GEN_CURRENT', 'gen24')
    source = source.replace('==125', '==127').replace('==200', '==202')
    if name == 'finish_campaign.py':
        source = source.replace('commb_validity_tables_live_path_verified', 'commb_semantic_reuse_live_path_verified')
    if name == 'prepare_preflight.py':
        source = source.replace('bind the integrated build and sample seeds before launch', 'bind the integrated build and the already recorded fresh seeds before launch')
        source = source.replace('json,secrets,subprocess', 'json,subprocess')
        start = source.index('historical_count=len(seen)')
        end = source.index('C.mkdir(exist_ok=True)', start)
        source = source[:start] + '''historical_count=len(seen)
selection=load(P/'seed-selection.json')
assert sha(P/'seed-selection.json')==prep['seed_selection']['sha256']
assert selection['status']=='recorded_before_generation'
assert selection['historical_seed_records_sha256']==bindings
assert selection['historical_seed_values_checked']==historical_count
assert selection['generator_source_sha256']==prep['unchanged_generator_inputs']
message_seed,commb_seed=selection['message_seed'],selection['commb_seed']
assert type(message_seed) is int and type(commb_seed) is int
assert 0<=message_seed<2**32 and 0<=commb_seed<2**32 and message_seed!=commb_seed
assert message_seed not in seen and commb_seed not in seen
''' + source[end:]
        source = source.replace("sampling='Independent secrets.randbits(32) draws immediately before authorized campaign; prior and mutual collisions rejected.'", "sampling=selection['sampling'],seed_selection_sha256=sha(P/'seed-selection.json'),seed_selected_utc=selection['recorded_utc']")
    ast.parse(source, filename=str(P / name))
    (P / name).write_text(source)
    diff_path = P / 'preparation-adaptations' / (name + '.adaptation.diff')
    diff_path.write_text(''.join(difflib.unified_diff(before.splitlines(True), source.splitlines(True), fromfile=str(OLD / name), tofile=str(P / name))))
    adaptations[name] = dict(path=str(P / name), sha256=sha(P / name), prior_path=str(OLD / name), prior_sha256=sha(OLD / name), diff_path=str(diff_path), diff_sha256=sha(diff_path))

previous_names = set(load(OLD / 'fresh-message-run.json')['source_sha256_before'])
current_names = set(previous_names)
for directory in ['Impl', 'Model', 'Spec', 'Proofs', 'CLI', 'Tests']:
    current_names.update(str(p) for p in Path(directory).rglob('*.lean'))
current_names.update(['lakefile.toml', 'lake-manifest.json', 'lean-toolchain', 'Capstones.lean'])
added = sorted(current_names - previous_names)
assert len(previous_names) == 125 and len(current_names) == 127
assert added == ['Proofs/CommBSemanticReuse.lean', 'Proofs/CommBValueReuse.lean']
with Path('bench/results.csv').open(newline='') as f:
    csv_rows = list(csv.DictReader(f))
assert len(csv_rows) == 48
scope = dict(runtime=['Impl/CommB.lean', 'Impl/Semantics.lean'], existing_proofs=['Proofs/Decoder.lean', 'Proofs/CommBTables.lean', 'Proofs/CommBPenalty.lean'], new_proofs=added, concept='Share exact Comm-B scalar values and NumericField expression lists; preserve arbitrary-input old-body equalities, absent statuses, register 30/44 behavior, and all Float evaluation boundaries.')
history = {name.replace('gen22', 'gen23'): sha(name.replace('gen22', 'gen23')) for name in prior_prep['history_bindings']}
prep = dict(prior_prep)
prep.update(recorded_utc=now(), helpers={str(P/name):dict(sha256=sha(P/name),reused_from=str(OLD/name),prior_sha256=sha(OLD/name)) for name in names[:4]}, preflight_preparer_sha256=sha(P/'prepare_preflight.py'), expected_fresh_source_count=127, expected_gate_input_count=202, selected_scope=scope, prepared_runtime_sha256=sha('Impl/Semantics.lean'), prepared_runtime_hashes={name:sha(name) for name in scope['runtime']}, predecessor=dict(measured_source='9b6868f21fcac0a59044153f01e6691d091dbb5c', artifact_commit='0ead24dfeba4f6cb95926f0a0fb8624f4ed08807'), prior_csv_rows=48, prior_csv_sha256=sha('bench/results.csv'), history_bindings=history, source_inventory_prior=dict(path=str(OLD/'fresh-message-run.json'),sha256=sha(OLD/'fresh-message-run.json')), source_inventory_check=dict(prior_count=125,current_names_count=127,added=added,current_content_hashes='Deferred to reviewed preflight against the completed combined build and staged correctness inventory.'), seed_policy='Root authorized collision-checked seeds during preparation. Final source/binary preflight and executable generation require separate release; preflight rechecks all seed history and consumes the immutable selection without resampling.', seed_selection=dict(path=str(P/'seed-selection.json'),sha256=sha(P/'seed-selection.json')), adaptations=adaptations, cache_preparation=dict(path='.cache/gen24-gate',status='Not inspected or changed by preparation; preflight records initial entries and requires both selected fresh fixture paths absent.'), native_review_contract=dict(review=str(P/'native-review/review.json'),inputs=str(P/'native-review/native-inputs.json'),flag='commb_semantic_reuse_live_path_verified',status='passed',linked_native_sets=22), no_seeds_sampled=False, preparer=dict(path=str(Path(__file__)),sha256=sha(__file__)))
prep['execution_paths'] = {key:value.replace('gen23','gen24') for key,value in prior_prep['execution_paths'].items()}
prep['execution_commands_not_run'] = [value.replace('gen23','gen24') for value in prior_prep['execution_commands_not_run']]
assert sha(prep['reporting_helper']['path']) == prep['reporting_helper']['sha256']
write(P/'preparation.json', prep)
print(json.dumps(dict(status='prepared_not_executed',preparation_sha256=sha(P/'preparation.json'),message_seed=message_seed,commb_seed=commb_seed,seed_selection_sha256=sha(P/'seed-selection.json'),source_names=len(current_names),prior_csv_rows=len(csv_rows),helpers=len(names))))
