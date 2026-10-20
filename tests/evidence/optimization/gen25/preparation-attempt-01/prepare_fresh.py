#!/usr/bin/env python3
"""Prepare reviewed campaign adapters and record seeds, without executing them."""
import sys
sys.dont_write_bytecode = True
import ast
import csv
from datetime import datetime, timezone
import difflib
import hashlib
import json
from pathlib import Path
import secrets

P = Path('tests/evidence/optimization/gen25')
OLD = Path('tests/evidence/optimization/gen24')
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
now = lambda: datetime.now(timezone.utc).isoformat()


def write(path, value):
    with path.open('x') as stream:
        stream.write(json.dumps(value, indent=2) + '\n')


names = ['fresh-orchestrate.py', 'fresh-run-campaign.py', 'fresh-verify.py',
         'fresh-retained-hashes.py', 'prepare_preflight.py',
         'finish_campaign.py', 'check_handoff.py']
fixed_names = ['run_full_gate.py', 'select_finish_gate.py']
prior = load(OLD / 'preparation.json')
assert not (P / 'preparation.json').exists() and not (P / 'seed-selection.json').exists()
for name in names:
    assert sha(OLD / name) == prior['adaptations'][name]['sha256'], name
for name in names + fixed_names:
    assert not (P / name).exists(), name
for name, digest in prior['unchanged_generator_inputs'].items():
    assert sha(name) == digest, name

previous_names = set(load(OLD / 'fresh-message-run.json')['source_sha256_before'])
current_names = set(previous_names)
for directory in ['Impl', 'Model', 'Spec', 'Proofs', 'CLI', 'Tests']:
    current_names.update(str(p) for p in Path(directory).rglob('*.lean'))
current_names.update(['lakefile.toml', 'lake-manifest.json', 'lean-toolchain', 'Capstones.lean'])
assert len(previous_names) == len(current_names) == 127 and current_names == previous_names
with Path('bench/results.csv').open(newline='') as stream:
    csv_rows = list(csv.DictReader(stream))
assert len(csv_rows) == 50

old_seeds = load(OLD / 'fresh-seeds.json')
seed_paths = set(old_seeds['historical_seed_records_sha256']) | {str(OLD / 'fresh-seeds.json')}
seen, seed_bindings = set(), {}
for name in sorted(seed_paths):
    seed_bindings[name] = sha(name)
    if name in old_seeds['historical_seed_records_sha256']:
        assert seed_bindings[name] == old_seeds['historical_seed_records_sha256'][name], name
    seen.update(value for key, value in load(name).items() if 'seed' in key and type(value) is int)
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
    'sampling': 'Independent secrets.randbits(32) draws during explicitly authorized preparation; historical and mutual collisions rejected.',
    'historical_seed_values_checked': historical_count,
    'historical_seed_records_sha256': seed_bindings, 'rejected_draws': rejected,
    'authorization': 'Root explicitly released gen25 preparation and seed recording after both gen24 cleanups; execution awaits combined-build pass and separate root release.',
    'generator_source_sha256': prior['unchanged_generator_inputs'],
    'preparer_sha256': sha(__file__), 'no_campaign_started': True})

adaptations = {}
(P / 'preparation-adaptations').mkdir()
for name in names + fixed_names:
    before = (OLD / name).read_text()
    source = before.replace('gen24', 'GEN_CURRENT').replace('gen23', 'gen24').replace('GEN_CURRENT', 'gen25')
    if name == 'select_finish_gate.py':
        source = source.replace("'--generation', '24'", "'--generation', '25'")
    if name == 'finish_campaign.py':
        source = source.replace('commb_semantic_reuse_live_path_verified', 'score_gate_equal_denominator_live_path_verified')
        source = source.replace("R/'comparison-replay-01.log'", "R/'comparison-attempt-01/execution.json',R/'comparison-attempt-01/stdout.log',R/'comparison-attempt-01/stderr.log'")
        marker = "assert execution['exit_code']==0 and replay['temporary_duplicate_outputs_removed'] and not independent['findings']\n"
        assert source.count(marker) == 1
        source = source.replace(marker, marker + """# Bind the completed generic reviewer execution and both logs before any unlink.
replay_run=load(R/'comparison-attempt-01/execution.json')
assert replay_run['status']=='passed' and replay_run['exit_code']==0
assert replay_run['script']==str(R/'replay_comparison.py')
assert replay_run['script_sha256']==sha(R/'replay_comparison.py')
assert replay_run['stdout_sha256']==sha(R/'comparison-attempt-01/stdout.log')==sha(R/'comparison-replay.json')
assert replay_run['stderr_sha256']==sha(R/'comparison-attempt-01/stderr.log')
""")
    ast.parse(source, filename=str(P / name))
    with (P / name).open('x') as stream:
        stream.write(source)
    diff_path = P / 'preparation-adaptations' / (name + '.adaptation.diff')
    diff_path.write_text(''.join(difflib.unified_diff(before.splitlines(True), source.splitlines(True), fromfile=str(OLD / name), tofile=str(P / name))))
    adaptations[name] = dict(path=str(P / name), sha256=sha(P / name), prior_path=str(OLD / name), prior_sha256=sha(OLD / name), diff_path=str(diff_path), diff_sha256=sha(diff_path))

scope = dict(runtime=['Impl/ScoreGate.lean'], existing_proofs=['Proofs/ScoreGateInteger.lean'], new_proofs=[], concept='Exact equal-denominator identity in scaled score numerators, with unrestricted original fallback; no new Float or callback work.')
history = {name.replace('gen23', 'gen24'): sha(name.replace('gen23', 'gen24')) for name in prior['history_bindings']}
prep = dict(prior)
prep.update(recorded_utc=now(), helpers={str(P / name): dict(sha256=sha(P / name), reused_from=str(OLD / name), prior_sha256=sha(OLD / name)) for name in names[:4]},
    preflight_preparer_sha256=sha(P / 'prepare_preflight.py'), expected_fresh_source_count=127, expected_gate_input_count=202,
    selected_scope=scope, prepared_runtime_sha256=sha('Impl/ScoreGate.lean'), prepared_runtime_hashes={'Impl/ScoreGate.lean': sha('Impl/ScoreGate.lean')},
    prepared_runtime_hashes_are_not_final=True,
    predecessor=dict(measured_source='cc337104e8d756f2acaef134096c4d593b888f5f', artifact_commit='d0f58661bba5e9903b9c939c83cb96ff3936f177'),
    prior_csv_rows=50, prior_csv_sha256=sha('bench/results.csv'), history_bindings=history,
    source_inventory_prior=dict(path=str(OLD / 'fresh-message-run.json'), sha256=sha(OLD / 'fresh-message-run.json')),
    source_inventory_check=dict(prior_count=127, current_names_count=127, added=[], current_content_hashes='Deferred until completed combined build and explicit root execution release.'),
    seed_selection=dict(path=str(P / 'seed-selection.json'), sha256=sha(P / 'seed-selection.json')),
    adaptations={name: adaptations[name] for name in names},
    cache_preparation=dict(path='.cache/gen25-gate', status='Not inspected or changed; reviewed preflight permits fixed-gate cache entries and requires only the two fresh fixture paths absent.'),
    native_review_contract=dict(review=str(P / 'native-review/review.json'), inputs=str(P / 'native-review/native-inputs.json'), flag='score_gate_equal_denominator_live_path_verified', status='passed', linked_native_sets=22),
    preparer=dict(path=str(Path(__file__)), sha256=sha(__file__)),
    no_seeds_sampled=False, no_campaign_started=True, no_cache_or_native_changes=True, no_final_source_or_binary_preflight_captured=True,
    reviewer_execution_contract=dict(path=str(P / 'independent-review/comparison-attempt-01/execution.json'), stdout='stdout.log', stderr='stderr.log', checked_before_cleanup=True),
    correction='Replace obsolete flat replay log with actual generic execution/stdout/stderr; verify all three plus script/result bindings before cleanup. Previous failed finisher and recovery remain unchanged.')
prep['execution_paths'] = {key: value.replace('gen24', 'gen25') for key, value in prior['execution_paths'].items()}
prep['execution_commands_not_run'] = [value.replace('gen24', 'gen25') for value in prior['execution_commands_not_run']]
assert sha(prep['reporting_helper']['path']) == prep['reporting_helper']['sha256']
write(P / 'preparation.json', prep)
write(P / 'fixed-finishing-preparation.json', dict(status='prepared_not_executed', recorded_utc=now(),
    adaptations={name: adaptations[name] for name in fixed_names},
    expected_gate_input_count=202, expected_fresh_source_count=127,
    generic_helpers={name: sha(name) for name in ['review/diagnostics/run_generation_benchmark.py', 'review/diagnostics/finish_generation_gate.py', 'review/diagnostics/archive_generation_gate.py', 'review/diagnostics/cleanup_verified_scratch.py']},
    launch_condition='Root explicit release after passing combined build and source/binary identity checks; no gate or archive execution during preparation.',
    cleanup_condition='Both complete fixed and fresh passes; exact unique approved-prefix roots from passed gate interval; archive-first byte identity checks; both historical roots and fresh path protected.',
    no_gate_archive_or_cleanup_executed=True))
print(json.dumps(dict(status='prepared_not_executed', preparation_sha256=sha(P / 'preparation.json'), fixed_finishing_preparation_sha256=sha(P / 'fixed-finishing-preparation.json'), message_seed=message_seed, commb_seed=commb_seed, seed_selection_sha256=sha(P / 'seed-selection.json'), source_names=len(current_names), prior_csv_rows=len(csv_rows), fresh_helpers=len(names), fixed_helpers=len(fixed_names))))
