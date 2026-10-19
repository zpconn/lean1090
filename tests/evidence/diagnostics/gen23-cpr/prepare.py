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
OLD = ROOT / 'tests/evidence/diagnostics/gen22-cpr'
E = Path(__file__).resolve().parent
B = ROOT / 'bench/runs/gen23'

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
assert summary['generation'] == review['generation'] == 23
assert summary['commit'] == review['commit'] == '9b6868f21fcac0a59044153f01e6691d091dbb5c'
assert summary['binary_sha256'] == review['binary_sha256'] == 'ece1cad565de9b2b45288ee494b2b944e51f3cd6ac00b4728eaa41d94e55d47e'
assert len(read(B / 'correctness-inputs.json')) == 200
decode_controller = ROOT / 'tests/evidence/diagnostics/gen23/run_prepared.py'
assert decode_controller.is_file(), 'Await the prepared decode guard, without executing it.'
assert not (E / 'preparation.json').exists()

names = ['run_prepared.py', 'analyze_and_archive.py', 'extract_numeric_contexts.py',
         'extract_table_contexts.py', 'extract_remaining_contexts.py', 'finalize.py',
         'write_report.py', 'cleanup_cache.py', 'perf/analyze_cpr_perf.py', 'perf/seal_perf.py']
prepared = {}
for name in names:
    before = (OLD / name).read_text()
    after = before.replace('gen22', 'gen23').replace('GEN22', 'GEN23').replace('Generation 22', 'Generation 23')
    if name == 'run_prepared.py':
        after = replace_once(after, "assert summary['generation']==22", "assert summary['generation']==23")
        after = replace_once(after, 'assert len(correctness)==197', 'assert len(correctness)==200')
        after = replace_once(after,
            "'Proofs/FrameWord.lean','Proofs/RawSyndromeSpec.lean'} <= set(correctness)",
            "'Proofs/FrameWord.lean','Proofs/RawSyndromeSpec.lean','Proofs/CommBValidity40.lean','Proofs/CommBValidity50.lean','Proofs/CommBValidity60.lean'} <= set(correctness)")
    if name == 'analyze_and_archive.py':
        after = replace_once(after,
            "assert source_review['decode_frame_with_word_anchor']",
            "assert source_review['decode_frame_with_word_anchor']\nassert source_review['commb_validity_tables_live_path_verified']")
    if name == 'finalize.py':
        after = replace_once(after,
            "    assert source_review['decode_frame_with_word_anchor']",
            "    assert source_review['decode_frame_with_word_anchor']\n    assert source_review['commb_validity_tables_live_path_verified']")
    if name == 'write_report.py':
        after = replace_once(after,
            "assert source['decode_frame_with_word_anchor']",
            "assert source['decode_frame_with_word_anchor']\nassert source['commb_validity_tables_live_path_verified']")
        after = replace_once(after,
            'frame-syndrome or packing entries are not interpreted as absent inlined work.\n',
            'frame-syndrome or packing entries are not interpreted as absent inlined work.\n\nThe current source/native review also verifies the immutable Bool field-code\ntables used by BDS40, BDS50 and BDS60 validity checks, including the live lookup\nand initialization paths. Their actual descendants remain in the same complete\ncaller-context accounting; inclusive instruction costs do not establish lookup\nhit rates or separate initialization populations. The numerical callback\nboundary and its tested-only operations remain unchanged.\n')
    if name == 'perf/seal_perf.py':
        after = replace_once(after, 'diagnostics/gen21-cpr/perf/analyze_cpr_perf.py',
                                   'diagnostics/gen22-cpr/perf/analyze_cpr_perf.py')
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
plan.update(generation=23, prepared_utc=datetime.now(timezone.utc).isoformat(),
            evidence=rel(E), cache='.cache/gen23-cpr-costs', decode_controller=rel(decode_controller))
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
plan['expected_correctness_inputs'] = 200
plan['expected_prior_csv_rows'] = 48
for key in ['prerequisites', 'commands', 'remaining_before_execution']:
    plan[key] = [s.replace('gen22', 'gen23').replace('197', '200') for s in plan[key]]
plan['changes'] = [
    'Ten finalized evidence-local CPR controllers adapted from gen22; only paths/generation, inventory guard and current validity-table review/report requirements change.',
    'All nine shared driver, validation, profile, accounting and archive helper sources remain byte-identical and are referenced rather than copied.',
    'The 200-input inventory includes the three CommBValidity proof modules. Actual reviewed timed source, worker, summary and result-review are pinned; published artifact commit remains unresolved.',
    'Analysis, finalizer and report additionally require commb_validity_tables_live_path_verified from current linked source/native inspection; prior raw-word CRC, conversion, power and affine requirements remain.',
    'No runtime, proof, frozen adapter, callback, corpus, output/state lifetime or numerical attribution algorithm changes. No controller or native work executed.'
]
plan['validity_table_review_obligations'] = [
    'Verify actual linked worker and diagnostic-driver BDS40/BDS50/BDS60 Bool table sizes, field projections, lookup and initialization paths; retain arbitrary-word behavior and original status/sentinel guards.',
    'Require commb_validity_tables_live_path_verified in the current CPR source review, bound to the same-generation decode source review and fresh native inputs.',
    'Keep full self-cost reconciliation and actual descendants in the existing exclusive partition. Helper rows overlap and cannot be summed with exclusive stages.',
    'Do not infer a corpus hit rate, initialization population or absent inlined work from inclusive costs or missing standalone helper symbols.',
    'The existing tested-only Float callback boundary is unchanged; no new hardware operations or work moved into callbacks is authorized.'
]
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
