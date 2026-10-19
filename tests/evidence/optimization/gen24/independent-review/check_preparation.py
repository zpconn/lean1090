#!/usr/bin/env python3
"""Read-only review of the generation 24 fresh producer preparation."""
import sys
sys.dont_write_bytecode = True
import ast
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

P = Path('tests/evidence/optimization/gen24')
O = Path('tests/evidence/optimization/gen23')
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
bindings = {}
checks = []
def bind(p, expected=None):
    h = sha(p)
    assert expected is None or h == expected, str(p)
    bindings[str(p)] = h
    return h
def check(condition, label):
    assert condition, label
    checks.append(label)

prep = load(P / 'preparation.json')
bind(P / 'preparation.json', '9272ff1d5a112a06646bb7a6fd10c95930d78930b8d2c2b19bc98352c91252b3')
for name, info in prep['helpers'].items():
    bind(name, info['sha256'])
    bind(info['reused_from'], info['prior_sha256'])
names = list(prep['adaptations'])
check(len(names)==7,'all seven producer/helper adaptations')
for name in names:
    info=prep['adaptations'][name];old,new=O/name,P/name
    expected=old.read_text().replace('gen23','__CURRENT__').replace('gen22','gen23').replace('__CURRENT__','gen24').replace('==125','==127').replace('==200','==202')
    if name == 'finish_campaign.py':
        expected=expected.replace('commb_validity_tables_live_path_verified','commb_semantic_reuse_live_path_verified')
    if name == 'prepare_preflight.py':
        expected=expected.replace('bind the integrated build and sample seeds before launch','bind the integrated build and the already recorded fresh seeds before launch').replace('json,secrets,subprocess','json,subprocess')
        start=expected.index('def draw():');end=expected.index('C.mkdir(exist_ok=True)',start)
        replacement="""selection=load(P/'seed-selection.json')
assert sha(P/'seed-selection.json')==prep['seed_selection']['sha256']
assert selection['status']=='recorded_before_generation'
assert selection['historical_seed_records_sha256']==bindings
assert selection['historical_seed_values_checked']==historical_count
assert selection['generator_source_sha256']==prep['unchanged_generator_inputs']
message_seed,commb_seed=selection['message_seed'],selection['commb_seed']
assert type(message_seed) is int and type(commb_seed) is int
assert 0<=message_seed<2**32 and 0<=commb_seed<2**32 and message_seed!=commb_seed
assert message_seed not in seen and commb_seed not in seen
"""
        expected=expected[:start]+replacement+expected[end:]
        expected=expected.replace("sampling='Independent secrets.randbits(32) draws immediately before authorized campaign; prior and mutual collisions rejected.'", "sampling=selection['sampling'],seed_selection_sha256=sha(P/'seed-selection.json'),seed_selected_utc=selection['recorded_utc']")
    check(new.read_text()==expected,name+': exact generation/count adaptation and explicit native guard')
    ast.parse(new.read_text(),filename=str(new))
    bind(old,info['prior_sha256']);bind(new,info['sha256']);bind(info['diff_path'],info['diff_sha256'])
bind(P / 'prepare_preflight.py', prep['preflight_preparer_sha256'])
for p, h in prep['history_bindings'].items():
    bind(p, h)
prior = prep['source_inventory_prior']
bind(prior['path'], prior['sha256'])
old_names = set(load(prior['path'])['source_sha256_before'])
current = set(old_names)
for directory in ['Impl', 'Model', 'Spec', 'Proofs', 'CLI', 'Tests']:
    current.update(str(p) for p in Path(directory).rglob('*.lean'))
current.update(['lakefile.toml', 'lake-manifest.json', 'lean-toolchain', 'Capstones.lean'])
check(len(old_names) == 125 and len(current) == 127, 'complete source inventory adds exactly two proofs')
check(sorted(current - old_names) == sorted(prep['selected_scope']['new_proofs']), 'only the two CommB sharing proofs added')
bind('bench/results.csv', prep['prior_csv_sha256'])
check(len(list(csv.DictReader(Path('bench/results.csv').read_text().splitlines()))) == 48, 'exact 48 prior result rows')
bind(prep['reporting_helper']['path'], prep['reporting_helper']['sha256'])
check(prep['expected_gate_input_count'] == 202 and prep['expected_fresh_source_count'] == 127, 'future preflight expects 202 inputs and 127 sources')
check(sorted(current - old_names) == ['Proofs/CommBSemanticReuse.lean', 'Proofs/CommBValueReuse.lean'], 'exact new source names')
for p,h in prep['unchanged_generator_inputs'].items(): bind(p,h)
preflight = (P / 'prepare_preflight.py').read_text()
check("gate==build['all_inputs_before']==build['all_inputs_after']" in preflight, 'later execution checks exact actual build inventory')
check("build['status']=='passed' and build['exit_code']==0" in preflight, 'later execution requires successful combined build')
check("assert h==build['binary_hashes'][Path(name).name]" in preflight, 'later execution binds actual binaries')
check(not (P / 'fresh-preflight.json').exists() and not (P / 'fresh-seeds.json').exists(), 'no seeds or preflight before release')
check(not (P / 'fresh-execution.json').exists(), 'producer not executed at review')
orchestrator = ast.parse((P / 'fresh-orchestrate.py').read_text())
retained = next(ast.literal_eval(n.value) for n in orchestrator.body if isinstance(n, ast.Assign) and any(isinstance(t, ast.Name) and t.id == 'EXPECTED_RETENTION' for t in n.targets))
check(len(retained) == len(set(retained)) == 33, 'exact 33 unique retained members')
selection_path=P/'seed-selection.json';selection=load(selection_path);bind(selection_path,prep['seed_selection']['sha256'])
bind(P/'prepare_fresh.py',selection['preparer_sha256']);ast.parse((P/'prepare_fresh.py').read_text())
prior_seeds=load(O/'fresh-seeds.json');history=set(prior_seeds['historical_seed_records_sha256'])|{str(O/'fresh-seeds.json')};seen=set()
check(history==set(selection['historical_seed_records_sha256']),'complete historical seed membership')
for p in sorted(history):
    bind(p,selection['historical_seed_records_sha256'][p])
    for key,value in load(p).items():
        if 'seed' in key and type(value) is int:seen.add(value)
check(len(seen)==selection['historical_seed_values_checked']==80,'all 80 previous seed values checked')
new_seeds=[selection['message_seed'],selection['commb_seed']]
check(len(set(new_seeds))==2 and all(type(x) is int and 0<=x<2**32 and x not in seen for x in new_seeds),'new 32-bit seeds differ and have no historical collisions')
check(selection['generator_source_sha256']==prep['unchanged_generator_inputs'],'seed selection binds unchanged generators')
check(selection['status']=='recorded_before_generation' and selection['no_campaign_started'],'authorized selection predates campaign')
out = P / 'independent-review/preparation-review.json'
assert not out.exists()
record = dict(status='passed_read_only_preparation_review', findings=[], recorded_utc=datetime.now(timezone.utc).isoformat(), checks=checks, check_count=len(checks), bindings=bindings, reviewer_sha256=sha(__file__), source_count=127, gate_input_count=202, retained_file_count=33,
    assessment=['Six helpers change only generation/count/native-flag bindings. Preflight additionally consumes the explicitly authorized prior seed selection, verifying its hash, complete history hashes and collision freedom without resampling.', 'The unchanged generation commands require the actual passed combined-build inventory, source/binary identities and explicit root release before launch.', 'Exact 33-member retention, overwrite rejection, all coverage/comparison checks and strict post-review selected cleanup remain unchanged.', 'No controller import, generation, compiler, native decoder or cleanup executed by this review.'])
out.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(dict(status='passed', checks=len(checks), review=str(out), sha256=sha(out))))
