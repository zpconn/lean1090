#!/usr/bin/env python3
"""Read-only final evidence checks; writes this review's result JSON only."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

B = Path('tests/evidence/diagnostics/gen4')
R = B / 'independent-review'
def read(path): return json.loads(Path(path).read_text())
def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()
checks = read(R / 'final-checks.json')
assert checks['status'] == 'passed'
validation = read(B / 'validation.json')
manifest = read(B / 'archive-manifest.json')
analysis = read(B / 'analysis/analysis.json')
campaign = read(B / 'campaign.json')
mach = read(B / 'mach-penalty-observations.json')
report = Path('docs/GEN4-COST-BREAKDOWN.md').read_text()
assert checks['report_sha256'] == sha('docs/GEN4-COST-BREAKDOWN.md') == validation['report_sha256']
assert checks['validation_sha256'] == sha(B / 'validation.json')
assert checks['analysis_sha256'] == sha(B / 'analysis/analysis.json')
assert checks['manifest_sha256'] == sha(B / 'archive-manifest.json')
assert sha(B / 'source-review.json') == 'e11da2996d34eced6fefb79b24c53f26133884e0140ec2e1cf0b94a8ae57ed48'

# The supplement preserves the initial finalizer outputs and adds no native run.
previous = read(B / 'validation-before-mach-addendum.json')
assert sha(B / 'report-before-mach-addendum.md') == 'cb6fec20bdde37e526e9b9f4e7a087058128af5536438cea7ce6a544d7625c10'
assert sha(B / 'validation-before-mach-addendum.json') == '9a73590ad9ad4618aece3d495b267f861a3a068c492ae1590922ddfdb89f0555'
assert report.startswith((B / 'report-before-mach-addendum.md').read_text())
assert {k: v for k, v in validation.items() if k not in ('report_sha256', 'mach_addendum')} == {
    k: v for k, v in previous.items() if k != 'report_sha256'}
supplement_files = validation['mach_addendum']['files']
assert set(supplement_files) == {str(B / name) for name in (
    'extract_mach_costs.py', 'mach-penalty-observations.json', 'append_mach_report.py',
    'report-before-mach-addendum.md', 'validation-before-mach-addendum.json')}
for name, item in supplement_files.items():
    assert sha(name) == item['sha256'] and Path(name).stat().st_size == item['bytes']

# Check every report row in the supplemental section against the independently
# raw-recounted extraction (the preceding checker verifies every source row).
P = 'lp_lean1090_Lean1090_Impl_'
labels = {'frame_crc': 'Frame / CRC', 'adsb_fields': 'ADS-B fields',
          'commb_inference': 'Comm-B inference', 'semantic_oracle_values': 'Semantic / oracle values',
          'output_model_control': 'Output / control'}
for row in mach['unique_stage_observations']:
    if row['symbol'] != P + 'cbMach64': continue
    n = row['totals']; count = n.get('native_entries', 0)
    own = n.get('self_ir', 0); inclusive = n.get('inclusive_ir', 0)
    assert f"| {labels[row['stage']]} | {count:,} | {own:,} | {inclusive:,} |" in report
for row in mach['full_commb_mach_contexts']:
    name = row['symbol_with_callers']
    if P + 'cbPenalty' in name:
        label = 'BDS60 score penalty'
    elif P + 'decodeBDS' in name:
        label = 'BDS60 accepted-record validity recheck'
    else:
        assert P + 'commBCoreEligible' in name
        label = 'BDS60 candidate hard-validity check'
    count = sum(v['calls'] for v in row['incoming'])
    inclusive = sum(v['inclusive_events'].get('Ir', 0) for v in row['incoming'])
    own = row['self_events'].get('Ir', 0)
    assert f'| {label} | {count:,} | {own:,} | {inclusive:,} |' in report
for row in mach['register_probes']:
    grouped = {v['symbol']: v for v in row['observed_symbol_rows']}
    m = grouped.get(P + 'cbMach64', {}); p = grouped.get(P + 'cbPenalty', {})
    values = [row['root_entries'], m.get('native_entries', 0),
              m.get('incoming_inclusive_events_non_additive', {}).get('Ir', 0),
              p.get('native_entries', 0), p.get('incoming_inclusive_events_non_additive', {}).get('Ir', 0)]
    assert f"| BDS{row['register']} {row['kind']} | " + ' | '.join(f'{v:,}' for v in values) + ' |' in report
assert f"{100 * 3606158963 / checks['exclusive_stages']['commb_inference']:.2f}%" in report
assert f"{100 * 3606158963 / checks['total_ir']:.2f}%" in report
assert mach['analysis_sha256'] == sha(B / 'analysis/analysis.json')
assert mach['extractor_sha256'] == sha(B / 'extract_mach_costs.py')
assert mach['raw_profile_sha256'] == sha(B / 'callgrind/commb/callgrind.out.1.gz')

# Actual recursive inventory: every primary archive member, the named derived
# finalizer outputs and five supplemental files; only this review is excluded.
derived = {'analysis/ANALYSIS.md', 'analysis/analysis.json', 'analyze.stderr', 'analyze.stdout',
           'archive-manifest.json', 'archive.stderr', 'archive.stdout', 'context-notes.md',
           'payload-call-edges.json', 'payload-helper-comparison.json', 'report.stderr',
           'report.stdout', 'validation.json'}
expected = set(manifest['files']) | derived | {str(Path(p).relative_to(B)) for p in supplement_files}
actual = {str(p.relative_to(B)) for p in B.rglob('*') if p.is_file()
          and not p.is_relative_to(R) and p != B / 'independent-review.json'}
assert actual == expected, (sorted(actual - expected), sorted(expected - actual))
assert not any(p.is_symlink() for p in B.rglob('*'))

# Counts remain population checks; included/probe costs are never added to the
# self-only partition. These rows independently verify the report's probe tables.
native_rows = [json.loads(x) for x in (B / 'native/all.jsonl').read_text().splitlines() if x]
interval = next(x for x in native_rows if x.get('kind') == 'post_decode_interval_census')
for row in interval['registers']:
    reg = f"{row['register_decimal']:02x}"
    score = analysis['non_additive_register_score_probes'][reg]
    candidate = analysis['non_additive_register_candidate_probes'][reg]
    passed = row['fast_accept'] + row['fallback_accept']
    assert f"| BDS{reg} | {candidate['root_incoming_calls']:,} | {row['reached']:,} | {passed:,} | {candidate['total_events'].get('Ir', 0):,} | {score['total_events'].get('Ir', 0):,} |" in report
    n = row['reached']; a = row['fast_accept']; r = row['fast_reject']
    fa = row['fallback_accept']; fr = row['fallback_reject']; f = fa + fr
    assert f'| BDS{reg} | {n:,} | {a:,} | {r:,} | {fa:,} / {fr:,} | {n:,} / {n:,} | {f:,} / {f:,} |' in report

for mode in analysis['families']:
    run = read(B / 'callgrind' / mode / 'run.json')
    assert sum(x['digest']['count'] for x in run['result']['per_df']) == run['prepared']['selected']
    actual_df = next(x for x in native_rows if x.get('phase') == 'result')['per_df']
    allowed = {17, 18} if mode == 'adsb' else {20, 21} if mode == 'commb' else set(range(32)) - {17, 18, 20, 21}
    for item in run['result']['per_df']:
        if item['df'] in allowed: assert item == actual_df[item['df']]
        else: assert item['digest']['count'] == 0

# Explicitly retained loss-counter wording, not an inference from parser success.
for name in ('report-self.txt', 'report-children.txt'):
    assert (B / 'perf' / name).read_text().splitlines()[3] == '# Total Lost Samples: 0'
fixture = read(R / 'helper-fixture.json')
assert fixture['status'] == 'passed' and fixture['analyzer_sha256'] == sha('review/diagnostics/analyze_callgrind.py')

# Recheck held production/native inputs last, before parent releases the hold.
for name, digest in campaign['protected_inputs'].items(): assert sha(name) == digest, name
for name, record in manifest['omitted_binaries'].items():
    assert sha(name) == record['sha256'] and Path(name).stat().st_size == record['bytes']

result = dict(checks)
result.update({
    'review_kind': 'independent read-only source, raw-counter, archive, report and provenance review',
    'completed_utc': datetime.now(timezone.utc).isoformat(),
    'findings': [],
    'live_input_check_scope': 'All 231 protected source/proof/frozen/C/object/binary inputs matched at review time, before diagnostic hold release. No assertion about later authorized optimization changes.',
    'primary_archive_sources_checked': len(manifest['files']),
    'retained_omitted_binaries_checked': len(manifest['omitted_binaries']),
    'non_review_evidence_membership_count': len(expected),
    'supplement_files': supplement_files,
    'reproduction_commands': [
        'python3 tests/evidence/diagnostics/gen4/independent-review/check_final.py',
        'python3 tests/evidence/diagnostics/gen4/independent-review/check_helper_fixture.py > tests/evidence/diagnostics/gen4/independent-review/helper-fixture.json',
        'python3 tests/evidence/diagnostics/gen4/independent-review/finalize_review.py'],
    'review_artifacts': {str(p): sha(p) for p in sorted(R.iterdir()) if p.is_file()},
    'source_review_sha256': sha(B / 'source-review.json'),
    'independent_methods': [
        'An independent raw Callgrind parser sums self records, counts native calls and incoming inclusive edges, and derives stages from full caller-name chains instead of production graph propagation. All 13 profiles and all 2,713 grouped helper rows, including context counts, match.',
        'Every profile root count, controller state/command, full retained-output digest and DF population matches native evidence and the complete corpus. Interval and actual choose/fallback counts agree: 45,510 and zero.',
        'Recounted prior gen3 raw family profiles and current profiles validate payloadBits old/new observations and zero positive-cost outgoing native calls in 100 current payload contexts. This is not a claim of zero inlined work.',
        'Reconstructed all three raw Mach contexts, including their incoming/outgoing edges, self costs and native entries. All Mach/penalty stage and probe rows match; the supplemental report preserves earlier final report/validation bytes.',
        'All 437 primary archive files match stored/decompressed hashes and original sources. The actual recursive non-review inventory exactly matches primary, derived and five authorized supplemental files; all four retained omitted binaries/raw files match.',
        'All 22 committed source and fresh native sets, 21 reused diagnostic objects and 231 protected inputs match. All 2,039 historical snapshot files, 1,990 committed historical files and four prior raw perf files remain unchanged; exactly the explicitly authorized gen4 benchmark-review addition is allowed.',
        'All 48 archived gen4 benchmark files match their original run. Report family/stage/comparison/helper/allocation/probe/Mach tables agree with recounted evidence.',
        'Perf raw hash and 450 records match, including 281 visible decoder samples and 444 samples with unknown frames. Capture preceded native diagnostic runs; both reports explicitly retain Total Lost Samples: 0.',
        'The pure synthetic stage-crossing fixture confirms that raw incoming inclusive costs can contain later-stage work while self costs remain an exact partition.'
    ],
    'review_tooling_notes': [
        'The first checker passed before the parent-requested Mach addendum. Its exact source, log and result remain as check_final_01.py, check-final-01.log and final-checks-01.json.',
        'The expanded checker initially assumed every prepared event had corpus_rows; score/candidate events instead record nonempty_commb. This reviewer schema error is retained in check-final-02.log and check_final_02.py. The corrected full run passes in check-final-03.log. No decoder/evidence failure was observed.'
    ],
    'limits': [
        'Instruction and small-allocation counts are diagnostics, not elapsed time, cycles, byte allocations or predicted throughput.',
        'Incoming inclusive costs overlap symbols, recursive contexts and later stages. Only self totals form the exact partition. Candidate/score probes are separate overlapping executions.',
        'Six instruction profiles intentionally overlapped. Perf attribution is conditional on visible ancestry; unknown frames and startup/preparation exclusions preclude an unbiased whole-decoder timing split. Host-wide isolation is not established.',
        'Density tables initialize eagerly before main; decoder-root profiles exclude that startup and differ from warmed benchmarks in lazy constants/allocator state. No unmeasured correction is made.',
        'This review made no production or frozen changes and ran no compiler, decoder, test suite, benchmark or profiler; it executed only read-only evidence parsers and a tiny synthetic Python parser fixture.'
    ],
    'hold_release_recommendation': 'Independent gen4 diagnostic review complete; no remaining review blocker to parent-controlled hold release.'
})
(B / 'independent-review.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'output': str(B / 'independent-review.json'),
                  'sha256': sha(B / 'independent-review.json'), 'findings': [],
                  'report_sha256': result['report_sha256'], 'validation_sha256': result['validation_sha256'],
                  'non_review_membership': len(expected)}, indent=2))
