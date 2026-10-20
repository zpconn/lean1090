#!/usr/bin/env python3
"""Prepare current reviewed fresh adapters and immutable seeds; no campaign run."""
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

P = Path('tests/evidence/optimization/gen26')
OLD = Path('tests/evidence/optimization/gen25')
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
now = lambda: datetime.now(timezone.utc).isoformat()


def write(path, value):
    with path.open('x') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


names = ['fresh-orchestrate.py', 'fresh-run-campaign.py', 'fresh-verify.py',
         'fresh-retained-hashes.py', 'prepare_preflight.py',
         'finish_campaign.py', 'check_handoff.py']
prior = load(OLD / 'preparation.json')
assert not (P / 'preparation.json').exists() and not (P / 'seed-selection.json').exists()
fixed_paths = ['run_full_gate.py', 'select_finish_gate.py', 'fixed-finishing-preparation.json',
               'integration/run_production_build.py', 'integration/validate_build.py',
               'integration/preparation.json']
fixed_before = {str(P / name): sha(P / name) for name in fixed_paths}
prepared = {}
for name in names:
    assert sha(OLD / name) == prior['adaptations'][name]['sha256'], name
    assert not (P / name).exists(), name
    assert not (P / 'preparation-adaptations' / (name + '.adaptation.diff')).exists()
    before = (OLD / name).read_text()
    after = before.replace('gen25', 'GEN_CURRENT').replace('gen24', 'gen25').replace('GEN_CURRENT', 'gen26')
    if name == 'finish_campaign.py':
        assert "native_review['score_scaling_identity_live_path_verified']" in after
        after = after.replace('score_scaling_identity_live_path_verified', 'binary64_round_identity_live_path_verified')
        # Preserve the executed gen25 fix, including all pre-unlink log bindings.
        assert after.index("replay_run=load(R/'comparison-attempt-01/execution.json')") < after.index("cmd=['python3'")
        for text in ["replay_run['script_sha256']==sha(R/'replay_comparison.py')",
                     "replay_run['stdout_sha256']==sha(R/'comparison-attempt-01/stdout.log')==sha(R/'comparison-replay.json')",
                     "replay_run['stderr_sha256']==sha(R/'comparison-attempt-01/stderr.log')"]:
            assert text in after
    ast.parse(after, filename=str(P / name))
    prepared[name] = (before, after)
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
assert len(csv_rows) == 52
history = {name.replace('gen24', 'gen25'): sha(name.replace('gen24', 'gen25')) for name in prior['history_bindings']}
assert sha(prior['reporting_helper']['path']) == prior['reporting_helper']['sha256']
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
    'authorization': 'Root released gen26 fresh preparation and one collision-checked seed selection after both gen25 cleanups. Generation still requires completed integration and separate root release.',
    'generator_source_sha256': prior['unchanged_generator_inputs'],
    'preparer_sha256': sha(__file__), 'no_campaign_started': True})
adaptations = {}
for name, (before, after) in prepared.items():
    with (P / name).open('x') as stream:
        stream.write(after)
    diff_path = P / 'preparation-adaptations' / (name + '.adaptation.diff')
    with diff_path.open('x') as stream:
        stream.write(''.join(difflib.unified_diff(before.splitlines(True), after.splitlines(True), fromfile=str(OLD / name), tofile=str(P / name))))
    adaptations[name] = dict(path=str(P / name), sha256=sha(P / name), prior_path=str(OLD / name), prior_sha256=sha(OLD / name), diff_path=str(diff_path), diff_sha256=sha(diff_path))
prep = dict(prior)
prep.pop('unexecuted_native_flag_correction', None)
prep.update(recorded_utc=now(), helpers={str(P / name): dict(sha256=sha(P / name), reused_from=str(OLD / name), prior_sha256=sha(OLD / name)) for name in names[:4]},
    preflight_preparer_sha256=sha(P / 'prepare_preflight.py'), expected_fresh_source_count=127, expected_gate_input_count=202,
    selected_scope=dict(runtime=['Impl/Binary64.lean'], existing_proofs=['Proofs/Binary64Runtime.lean'], new_proofs=[], concept='Exact small-dyadic identity guard in pure rational binary64 rounding, preserving the original arbitrary-rational fallback and existing Float boundaries.'),
    prepared_runtime_sha256=sha('Impl/Binary64.lean'), prepared_runtime_hashes={'Impl/Binary64.lean': sha('Impl/Binary64.lean')}, prepared_runtime_hashes_are_not_final=True,
    predecessor=dict(measured_source='eaa7b36225b0d3ae29720a319295b0fac34e995b', artifact_commit='240cc329f5334e8557687eddc56a854edd2720bc'),
    prior_csv_rows=52, prior_csv_sha256=sha('bench/results.csv'), history_bindings=history,
    source_inventory_prior=dict(path=str(OLD / 'fresh-message-run.json'), sha256=sha(OLD / 'fresh-message-run.json')),
    source_inventory_check=dict(prior_count=127, current_names_count=127, added=[], current_content_hashes='Deferred until completed combined build and explicit root execution release.'),
    seed_selection=dict(path=str(P / 'seed-selection.json'), sha256=sha(P / 'seed-selection.json')), adaptations=adaptations,
    cache_preparation=dict(path='.cache/gen26-gate', status='Not inspected or changed; reviewed preflight permits fixed-gate cache entries and requires only the two fresh fixture paths absent.'),
    native_review_contract=dict(review=str(P / 'native-review/review.json'), inputs=str(P / 'native-review/native-inputs.json'), flag='binary64_round_identity_live_path_verified', status='passed', linked_native_sets=22),
    preparer=dict(path=str(Path(__file__)), sha256=sha(__file__)),
    no_seeds_sampled=False, no_campaign_started=True, no_cache_or_native_changes=True, no_final_source_or_binary_preflight_captured=True,
    reviewer_execution_contract=dict(path=str(P / 'independent-review/comparison-attempt-01/execution.json'), stdout='stdout.log', stderr='stderr.log', checked_before_cleanup=True),
    correction='The executed current gen25 finisher already binds actual comparison-attempt-01 execution, stdout/stderr and script/result hashes before cleanup; preserved unchanged except generation and native flag.',
    prior_preparation_sha256=sha(OLD / 'preparation.json'), existing_fixed_preparation_preserved=fixed_before)
prep['execution_paths'] = {key: value.replace('gen25', 'gen26') for key, value in prior['execution_paths'].items()}
prep['execution_commands_not_run'] = [value.replace('gen25', 'gen26') for value in prior['execution_commands_not_run']]
assert {name: sha(name) for name in fixed_before} == fixed_before
write(P / 'preparation.json', prep)
print(json.dumps(dict(status='prepared_not_executed', preparation_sha256=sha(P / 'preparation.json'), message_seed=message_seed, commb_seed=commb_seed, seed_selection_sha256=sha(P / 'seed-selection.json'), source_names=len(current_names), prior_csv_rows=len(csv_rows), fresh_helpers=len(names), historical_seed_values_checked=historical_count, fixed_files_unchanged=len(fixed_before))))
