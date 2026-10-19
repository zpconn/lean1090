#!/usr/bin/env python3
"""Prepare evidence-local CPR controllers; never import or run a controller."""
import sys
sys.dont_write_bytecode = True
import ast
import difflib
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
OLD = ROOT / 'tests/evidence/diagnostics/gen21-cpr'
E = Path(__file__).resolve().parent
B = ROOT / 'bench/runs/gen22'

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

names = ['run_prepared.py', 'analyze_and_archive.py', 'extract_numeric_contexts.py',
         'extract_table_contexts.py', 'extract_remaining_contexts.py', 'finalize.py',
         'write_report.py', 'cleanup_cache.py', 'perf/analyze_cpr_perf.py', 'perf/seal_perf.py']
bindings = {}
diff = []
for name in names:
    prior = OLD / name
    destination = E / name
    before = prior.read_text()
    after = before.replace('gen21', 'gen22').replace('GEN21', 'GEN22').replace('Generation 21', 'Generation 22')
    if name == 'run_prepared.py':
        after = replace_once(after, "assert summary['generation']==21", "assert summary['generation']==22")
        after = replace_once(after, 'assert len(correctness)==195', 'assert len(correctness)==197')
        after = replace_once(after,
            "assert {'Proofs/ParityByteBits.lean','Proofs/FoldBlocks.lean','Proofs/ParityByte.lean'} <= set(correctness)",
            "assert {'Proofs/ParityByteBits.lean','Proofs/FoldBlocks.lean','Proofs/ParityByte.lean','Proofs/FrameWord.lean','Proofs/RawSyndromeSpec.lean'} <= set(correctness)")
        after = replace_once(after, "assert summary['generation']==22", "assert summary['generation']==22\n assert summary['commit']==plan['benchmark_bindings']['timed_commit']\n assert summary['binary_sha256']==plan['benchmark_bindings']['worker_sha256']\n assert sha(B/'summary.json')==plan['benchmark_bindings']['summary_sha256']\n assert sha(B/'results-review.json')==plan['benchmark_bindings']['result_review_sha256']")
    if name == 'analyze_and_archive.py':
        after = replace_once(after,
            "assert source_review['worker_sha256'] == collection['worker_sha256']",
            "assert source_review['worker_sha256'] == collection['worker_sha256']\nassert source_review['raw_word_syndrome_live_path_verified']\nassert source_review['decode_frame_with_word_anchor']")
    if name == 'finalize.py':
        after = replace_once(after,
            "    assert source_review['status'] == 'passed_read_only_source_and_native_review'",
            "    assert source_review['status'] == 'passed_read_only_source_and_native_review'\n    assert source_review['raw_word_syndrome_live_path_verified']\n    assert source_review['decode_frame_with_word_anchor']")
    if name == 'write_report.py':
        after = replace_once(after,
            "source = load(B/'independent-review/source-review.json')",
            "source = load(B/'independent-review/source-review.json')\nassert source['raw_word_syndrome_live_path_verified']\nassert source['decode_frame_with_word_anchor']")
        after = replace_once(after,
            'frozen files or build configuration changed during diagnosis.\n',
            'frozen files or build configuration changed during diagnosis.\n\nThe current decoder calls the paired parser `{source[\'decode_frame_with_word_anchor\']}`\nand reuses its returned wire word for CRC. The independent current native\nreview verifies that live path and the byte/general-bit fallback loops. The\ncommitted decoder subpartition recognizes this parser as frame/CRC; the full\nCPR partition and numeric extraction are unchanged. Absent standalone parser,\nframe-syndrome or packing entries are not interpreted as absent inlined work.\n')
        after = replace_once(after,
            'attribution algorithm is used unchanged. [Complete compressed analysis]',
            'CPR attribution algorithm is used unchanged, with the current paired-parser\nclassification in the decoder subpartition. [Complete compressed analysis]')
    if name == 'perf/seal_perf.py':
        after = replace_once(after, 'diagnostics/gen20-cpr/perf/analyze_cpr_perf.py',
                                   'diagnostics/gen21-cpr/perf/analyze_cpr_perf.py')
    ast.parse(after, filename=rel(destination))
    assert not destination.exists(), destination
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(after)
    bindings[name] = {'prior_path': rel(prior), 'prior_sha256': sha(prior),
                      'prepared_path': rel(destination), 'prepared_sha256': sha(destination)}
    diff.extend(difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                                   fromfile=rel(prior), tofile=rel(destination)))

with (E / 'preparation.diff').open('x') as stream:
    stream.writelines(diff)
plan = read(OLD / 'preparation.json')
plan['generation'] = 22
plan['prepared_utc'] = datetime.now(timezone.utc).isoformat()
plan['evidence'] = rel(E)
plan['cache'] = '.cache/gen22-cpr-costs'
plan['decode_controller'] = 'tests/evidence/diagnostics/gen22/run_prepared.py'
generic = [name for name in plan['helpers'] if name.startswith('review/')]
generic += ['review/diagnostics/analyze_callgrind.py']
plan['helpers'] = {row['prepared_path']: row['prepared_sha256'] for row in bindings.values()}
plan['helpers'].update({name: sha(ROOT / name) for name in generic})
plan['helpers'][plan['decode_controller']] = sha(ROOT / plan['decode_controller'])
plan['prior_controller_bindings'] = bindings
build = read(OLD / 'build-execution.json')
plan['prior_successful_build'] = {'path': rel(OLD / 'build-execution.json'),
    'sha256': sha(OLD / 'build-execution.json'), 'executed_controller_sha256': build['controller_sha256']}
plan['prior_final_review'] = {'path': rel(OLD / 'independent-review/independent-review.json'),
    'sha256': sha(OLD / 'independent-review/independent-review.json')}
summary = read(B / 'summary.json')
review = read(B / 'results-review.json')
assert summary['status'] == 'complete' and review['status'] == 'passed'
assert summary['generation'] == review['generation'] == 22
assert summary['commit'] == review['commit'] and summary['binary_sha256'] == review['binary_sha256']
assert len(read(B / 'correctness-inputs.json')) == 197
plan['benchmark_bindings'] = {'status': 'measurement_and_result_review_passed_artifact_release_required',
    'directory': rel(B), 'timed_commit': summary['commit'], 'worker_sha256': summary['binary_sha256'],
    'artifact_commit': None, 'summary_sha256': sha(B / 'summary.json'),
    'result_review_sha256': sha(B / 'results-review.json')}
plan['expected_correctness_inputs'] = 197
plan['expected_prior_csv_rows'] = 46
for key in ['prerequisites', 'commands', 'remaining_before_execution']:
    plan[key] = [s.replace('gen21', 'gen22').replace('195', '197') for s in plan[key]]
plan['changes'] = [
    'Eight finalized producer controllers and two corrected saved-sample helpers adapted from gen21 paths; no completed output copied.',
    'Current committed analyze_callgrind recognizes decodeFrameWithWord as frame/CRC; all remaining shared CPR helper bytes are unchanged and source-hash bound.',
    'Explicit 197-input inventory includes FrameWord and RawSyndromeSpec; exact reviewed timed source/worker/summary/result-review are pinned; future artifact commit remains unknown.',
    'Analysis, finalizer and report require independent raw-word syndrome/live paired-parser source review before output; report distinguishes removed standalone boundaries from inlining.',
    'No runtime, proof, frozen adapter, callback, workload, output/state lifetime or accounting algorithm edits in this preparation.'
]
plan['raw_word_review_obligations'] = [
    'Require raw_word_syndrome_live_path_verified and decode_frame_with_word_anchor in current CPR source review, bound to the same-generation decode source review.',
    'Verify actual timed-worker and diagnostic-driver generated C/assembly: immediate live decode/streamStep, returned raw-word sharing and one selected syndrome path; preserve rejection and byte/bit fallback behavior.',
    'Do not require obsolete standalone frameSyndrome/checksum/packFields entries on the main path or infer zero inlined work from absent symbols.',
    'Use the committed paired-parser stage mapping and exact current native anchors. Preserve full self-cost reconciliation, actual descendant contexts, and non-additive helper edges.',
    'Full 172432-message output digest must equal the same-generation decode retained digest; complete inputs/airports/row tracking/final StreamState/routed positions remain audited.'
]
plan['diagnostic_tooling_validation'] = {
    'path': 'tests/evidence/optimization/gen22/diagnostic-tooling/validation.json',
    'sha256': sha(ROOT / 'tests/evidence/optimization/gen22/diagnostic-tooling/validation.json')}
plan['syntax_check'] = {'method': 'ast.parse only; no controller import/execution', 'files': names}
plan['diff'] = {'path': rel(E / 'preparation.diff'), 'sha256': sha(E / 'preparation.diff')}
plan['preparation_script_sha256'] = sha(__file__)
plan['inspection_note'] = 'An initial rg read of the not-yet-created gen22-cpr directory reported it absent; no controller or workload was executed.'
assert not plan['native_work_started'] and not plan['profile_or_capture_started']
assert not plan['history_snapshot_started'] and not plan['artifact_commit_known']
with (E / 'preparation.json').open('x') as stream:
    json.dump(plan, stream, indent=2)
    stream.write('\n')
print(json.dumps({'status': 'prepared_not_executed', 'preparation_sha256': sha(E / 'preparation.json'),
                  'files_syntax_checked': len(names), 'artifact_commit': None}))
