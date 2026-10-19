#!/usr/bin/env python3
"""Prepare CPR diagnostic sources without importing or executing controllers."""
import sys
sys.dont_write_bytecode = True
import ast
import difflib
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
OLD = ROOT / 'tests/evidence/diagnostics/gen23-cpr'
E = Path(__file__).resolve().parent
B = ROOT / 'bench/runs/gen24'

def sha(p):
    with Path(p).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()

def read(p):
    return json.loads(Path(p).read_text())

def rel(p):
    return str(p.relative_to(ROOT))

def replace_once(text, before, after):
    assert text.count(before) == 1, before
    return text.replace(before, after)

summary = read(B / 'summary.json')
review = read(B / 'results-review.json')
assert summary['status'] == 'complete' and review['status'] == 'passed'
assert summary['generation'] == review['generation'] == 24
assert summary['commit'] == review['commit'] == 'cc337104e8d756f2acaef134096c4d593b888f5f'
assert summary['binary_sha256'] == review['binary_sha256'] == '2af19ab4d11000ae0fe849e7c54221d1ad0dfd8b027990135536d7b574a3dedc'
assert len(read(B / 'correctness-inputs.json')) == 202
decode_controller = ROOT / 'tests/evidence/diagnostics/gen24/run_prepared.py'
assert decode_controller.is_file(), 'Await the prepared decode guard, without executing it.'
assert not (E / 'preparation.json').exists()

names = ['run_prepared.py', 'analyze_and_archive.py', 'extract_numeric_contexts.py',
         'extract_table_contexts.py', 'extract_remaining_contexts.py', 'finalize.py',
         'write_report.py', 'cleanup_cache.py', 'perf/analyze_cpr_perf.py', 'perf/seal_perf.py']
prepared = {}
for name in names:
    before = (OLD / name).read_text()
    after = before.replace('gen23', 'gen24').replace('GEN23', 'GEN24').replace('Generation 23', 'Generation 24')
    if name == 'run_prepared.py':
        after = replace_once(after, "assert summary['generation']==23", "assert summary['generation']==24")
        after = replace_once(after, 'assert len(correctness)==200', 'assert len(correctness)==202')
        after = replace_once(after,
            "'Proofs/CommBValidity60.lean'} <= set(correctness)",
            "'Proofs/CommBValidity60.lean','Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean','Impl/CommB.lean','Impl/Semantics.lean'} <= set(correctness)")
    if name == 'analyze_and_archive.py':
        after = replace_once(after,
            "assert source_review['commb_validity_tables_live_path_verified']",
            "assert source_review['commb_validity_tables_live_path_verified']\nassert source_review['commb_semantic_reuse_live_path_verified']")
    if name == 'finalize.py':
        after = replace_once(after,
            "    assert source_review['commb_validity_tables_live_path_verified']",
            "    assert source_review['commb_validity_tables_live_path_verified']\n    assert source_review['commb_semantic_reuse_live_path_verified']")
    if name == 'write_report.py':
        after = replace_once(after,
            "assert source['commb_validity_tables_live_path_verified']",
            "assert source['commb_validity_tables_live_path_verified']\nassert source['commb_semantic_reuse_live_path_verified']")
        after = replace_once(after,
            'boundary and its tested-only operations remain unchanged.\n',
            'boundary and its tested-only operations remain unchanged.\n\nThe source/native review also binds current Comm-B semantic sharing: scalar\nviews derive from the existing table values, while standard and oracle numeric\nviews share one pure NumericField expression list. Register 30/44 behavior,\nabsent statuses, expression structure and Float evaluation boundaries remain\nunchanged. Actual descendant calls stay in the full decoder partition; absent\nstandalone symbols do not imply absent inlined work or a measured hit rate.\n')
    if name == 'perf/seal_perf.py':
        after = replace_once(after, 'diagnostics/gen22-cpr/perf/analyze_cpr_perf.py',
                                   'diagnostics/gen23-cpr/perf/analyze_cpr_perf.py')
    ast.parse(after, filename=rel(E / name))
    assert not (E / name).exists(), name
    prepared[name] = (before, after)

bindings = {}
diff = []
for name, (before, after) in prepared.items():
    prior = OLD / name
    destination = E / name
    destination.parent.mkdir(parents=True, exist_ok=True)
    with destination.open('x') as stream:
        stream.write(after)
    bindings[name] = {'prior_path': rel(prior), 'prior_sha256': sha(prior),
                      'prepared_path': rel(destination), 'prepared_sha256': sha(destination)}
    diff.extend(difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                                   fromfile=rel(prior), tofile=rel(destination)))
with (E / 'preparation.diff').open('x') as stream:
    stream.writelines(diff)

plan = read(OLD / 'preparation.json')
plan.update(generation=24, prepared_utc=datetime.now(timezone.utc).isoformat(),
            evidence=rel(E), cache='.cache/gen24-cpr-costs', decode_controller=rel(decode_controller))
generic = {name: digest for name, digest in plan['helpers'].items() if name.startswith('review/')}
assert all(sha(ROOT / name) == digest for name, digest in generic.items()), 'Shared tooling must remain unchanged.'
plan['helpers'] = {row['prepared_path']: row['prepared_sha256'] for row in bindings.values()}
plan['helpers'].update(generic)
plan['helpers'][rel(decode_controller)] = sha(decode_controller)
plan['prior_controller_bindings'] = bindings
build = read(OLD / 'build-execution.json')
plan['prior_successful_build'] = {'path': rel(OLD / 'build-execution.json'),
    'sha256': sha(OLD / 'build-execution.json'), 'executed_controller_sha256': build['controller_sha256']}
plan['prior_final_review'] = {'path': rel(OLD / 'independent-review/independent-review.json'),
    'sha256': sha(OLD / 'independent-review/independent-review.json')}
plan['benchmark_bindings'] = {'status': 'measurement_and_result_review_passed_artifact_release_required',
    'directory': rel(B), 'timed_commit': summary['commit'], 'worker_sha256': summary['binary_sha256'],
    'artifact_commit': None, 'summary_sha256': sha(B / 'summary.json'),
    'result_review_sha256': sha(B / 'results-review.json')}
plan['expected_correctness_inputs'] = 202
plan['expected_prior_csv_rows'] = 50
for key in ['prerequisites', 'commands', 'remaining_before_execution']:
    plan[key] = [s.replace('gen23', 'gen24').replace('200', '202') for s in plan[key]]
plan['changes'] = [
    'Ten finalized evidence-local CPR controllers adapted from gen23; only paths/generation, inventory guard and current semantic-sharing review/report requirements change.',
    'All nine shared driver, validation, profile, accounting and archive helpers remain byte-identical and are referenced rather than copied.',
    'The 202-input inventory includes CommBValueReuse and CommBSemanticReuse; both changed runtime sources are explicitly required. Actual reviewed timed source, worker, summary and result-review are pinned; published artifact commit remains unresolved.',
    'Analysis, finalizer and report additionally require commb_semantic_reuse_live_path_verified from current linked source/native inspection; all prior validity-table, raw-word CRC, conversion, power and affine requirements remain.',
    'No runtime, proof, frozen adapter, callback, corpus, output/state lifetime or numerical attribution algorithm changes. No controller or native work executed.'
]
plan['semantic_reuse_review_obligations'] = [
    'Bind actual current Impl/CommB.lean and Impl/Semantics.lean hashes plus all 22 timed native sets; verify actual linked commB, commBOracleValues, commBStandardFloatsFromOracle and surviving descendants.',
    'Require commb_semantic_reuse_live_path_verified in current CPR source review, bound to the same-generation decode source review and fresh native inputs.',
    'Establish shared scalar table values and one pure NumericField list, preserving arbitrary words, absent status, register 30 early empty behavior, register 44 temperature override, and ADS-B branches.',
    'Preserve full actual caller contexts and exclusive self-cost reconciliation; report removed duplicate calls only from current source/native and observed contexts, never infer zero inlined work from absent helper symbols.',
    'Retain direct round/fromBits/toFloat and rational-normalization contexts alongside current pairing, motion and all remaining decoder partitions. Helper inclusive costs overlap; existing tested-only Float callbacks remain separately attributed and unchanged.',
    'Audit all 172432 message/tracking rows, 11347 positions and complete final state against the actual worker and batch path, then match the same-generation complete message digest.'
]
plan['prepared_runtime_bindings'] = {name:sha(ROOT/name) for name in ['Impl/CommB.lean','Impl/Semantics.lean']}
for name,digest in plan['prepared_runtime_bindings'].items():
    assert read(B/'correctness-inputs.json')[name] == digest
plan['syntax_check'] = {'method': 'ast.parse only; no controller import/execution', 'files': names}
plan['diff'] = {'path': rel(E / 'preparation.diff'), 'sha256': sha(E / 'preparation.diff')}
plan['preparation_script_sha256'] = sha(__file__)
plan.pop('inspection_note', None)
assert not plan['native_work_started'] and not plan['profile_or_capture_started']
assert not plan['history_snapshot_started'] and not plan['artifact_commit_known']
with (E / 'preparation.json').open('x') as stream:
    json.dump(plan, stream, indent=2)
    stream.write('\n')
print(json.dumps({'status': 'prepared_not_executed', 'preparation_sha256': sha(E / 'preparation.json'),
                  'files_syntax_checked': len(names), 'artifact_commit': None}))
