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
OLD = ROOT / 'tests/evidence/diagnostics/gen24-cpr'
E = Path(__file__).resolve().parent
B = ROOT / 'bench/runs/gen25'

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
assert summary['generation'] == review['generation'] == 25
assert summary['commit'] == review['commit'] == 'eaa7b36225b0d3ae29720a319295b0fac34e995b'
assert summary['binary_sha256'] == review['binary_sha256'] == '0383b0488863b837ebae02e78b00c86bba11eea96916ee0816b8db2dcb0ba189'
assert len(read(B / 'correctness-inputs.json')) == 202
decode_controller = ROOT / 'tests/evidence/diagnostics/gen25/run_prepared.py'
assert decode_controller.is_file(), 'Await the prepared decode guard, without executing it.'
assert not (E / 'preparation.json').exists()

names = ['run_prepared.py', 'analyze_and_archive.py', 'extract_numeric_contexts.py',
         'extract_table_contexts.py', 'extract_remaining_contexts.py', 'finalize.py',
         'write_report.py', 'cleanup_cache.py', 'perf/analyze_cpr_perf.py', 'perf/seal_perf.py']
prepared = {}
for name in names:
    before = (OLD / name).read_text()
    after = before.replace('gen24', 'gen25').replace('GEN24', 'GEN25').replace('Generation 24', 'Generation 25')
    if name == 'run_prepared.py':
        after = replace_once(after, "assert summary['generation']==24", "assert summary['generation']==25")
        after = replace_once(after,
            "'Impl/Semantics.lean'} <= set(correctness)",
            "'Impl/Semantics.lean','Impl/ScoreGate.lean','Proofs/ScoreGateInteger.lean'} <= set(correctness)")
    if name == 'analyze_and_archive.py':
        after = replace_once(after,
            "assert source_review['commb_semantic_reuse_live_path_verified']",
            "assert source_review['commb_semantic_reuse_live_path_verified']\nassert source_review['score_scaling_identity_live_path_verified']")
    if name == 'finalize.py':
        after = replace_once(after,
            "    assert source_review['commb_semantic_reuse_live_path_verified']",
            "    assert source_review['commb_semantic_reuse_live_path_verified']\n    assert source_review['score_scaling_identity_live_path_verified']")
    if name == 'write_report.py':
        after = replace_once(after,
            "assert source['commb_semantic_reuse_live_path_verified']",
            "assert source['commb_semantic_reuse_live_path_verified']\nassert source['score_scaling_identity_live_path_verified']")
        after = replace_once(after,
            'standalone symbols do not imply absent inlined work or a measured hit rate.\n',
            'standalone symbols do not imply absent inlined work or a measured hit rate.\n\nThe current score-scaling path returns the numerator directly when the exact\ncommon denominator equals the rational denominator, and preserves the original\ninteger division/product otherwise. Its unrestricted proof and actual native\nbranches are bound by the source review. Caller counts and inlined instruction\ntotals do not reveal the equal-denominator input frequency or elapsed savings.\n')
    if name == 'perf/seal_perf.py':
        after = replace_once(after, 'diagnostics/gen23-cpr/perf/analyze_cpr_perf.py',
                                   'diagnostics/gen24-cpr/perf/analyze_cpr_perf.py')
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
plan.update(generation=25, prepared_utc=datetime.now(timezone.utc).isoformat(),
            evidence=rel(E), cache='.cache/gen25-cpr-costs', decode_controller=rel(decode_controller))
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
plan['expected_prior_csv_rows'] = 52
for key in ['prerequisites', 'commands', 'remaining_before_execution']:
    plan[key] = [s.replace('gen24', 'gen25') for s in plan[key]]
plan['changes'] = [
    'Ten finalized controllers advance gen24 to gen25 with unchanged 202-input and 22-native-set counts; explicit current ScoreGate source/proof guard and native-review obligation added.',
    'All nine shared driver, validator, profiler, parser, numerical attribution and archive helpers remain byte-identical. No new instrumentation or workload change.',
    'The completed reviewed benchmark, exact timed source and worker are bound; published artifact identity remains null until root release.',
    'All current round/fromBits/sub/div numeric contexts, motion/pairing stages and complete decoder attribution remain. No rational argument or guard-hit observations are invented.',
    'The regressed gen25 measurement is retained unchanged. No rerun, timing prediction, added Float code, callback movement, or optimization selection occurs.'
]
plan['score_scaling_review_obligations'] = [
    'Require score_scaling_identity_live_path_verified from actual current linked source/native review, alongside all prior semantic/validity/CRC/conversion/table/affine keys.',
    'Inspect the numerator-return equality branch and original division/product fallback in actual compiled callers, preserving unrestricted rational semantics and signed numerator behavior.',
    'No denominator-argument values are captured by existing Callgrind. Do not infer equal-denominator frequency from inclusive costs, missing inline boundaries, or caller populations.',
    'Audit all 172432 tracking rows,11347 positions, complete final state and same-generation complete message digest using the unchanged actual frozen worker and live batch path.'
]
plan['prepared_runtime_bindings'] = {name:sha(ROOT/name) for name in ['Impl/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Impl/CommB.lean','Impl/Semantics.lean']}
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
