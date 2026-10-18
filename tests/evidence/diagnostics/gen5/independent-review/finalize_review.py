#!/usr/bin/env python3
"""Read-only final evidence checks; writes this review's result JSON only."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

B = Path('tests/evidence/diagnostics/gen5')
R = B / 'independent-review'
def read(path): return json.loads(Path(path).read_text())
def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()
checks = read(R / 'final-checks.json')
assert checks['status'] == 'passed'
validation = read(B / 'validation.json')
manifest = read(B / 'archive-manifest.json')
analysis = read(B / 'analysis/analysis.json')
campaign = read(B / 'campaign.json')
report = Path('docs/GEN5-COST-BREAKDOWN.md').read_text()
assert checks['report_sha256'] == sha('docs/GEN5-COST-BREAKDOWN.md') == validation['report_sha256']
assert checks['validation_sha256'] == sha(B / 'validation.json')
assert checks['analysis_sha256'] == sha(B / 'analysis/analysis.json')
assert checks['manifest_sha256'] == sha(B / 'archive-manifest.json')
assert sha(B / 'source-review.json') == '9893949eae950f67a499b9007e23cc276f7fe24f54895df5eb8c4e67fd4b4885'

# Check the current actual recursive inventory; supplemental membership is
# checked once the existing-profile-only CRC caller addendum is finalized.
P = 'lp_lean1090_Lean1090_Impl_'
derived = {'analysis/ANALYSIS.md', 'analysis/analysis.json', 'analyze.stderr', 'analyze.stdout',
           'archive-manifest.json', 'archive.stderr', 'archive.stdout', 'context-notes.md',
           'helper-comparison.json', 'report.stderr', 'report.stdout', 'validation.json'}
expected = set(manifest['files']) | derived
supplement = read(B / 'crc-caller-contexts.json')
files = validation['crc_caller_addendum']['files']
assert {str(Path(name).resolve().relative_to(Path.cwd())) for name in files} == {str(B / name) for name in ['extract_crc_contexts.py', 'crc-caller-contexts.json', 'report-before-crc-addendum.md', 'validation-before-crc-addendum.json']}
for name,item in files.items():
    assert sha(name)==item['sha256'] and Path(name).stat().st_size==item['bytes']
expected |= {str(Path(name).resolve().relative_to(B.resolve())) for name in files}
assert sha(B / 'report-before-crc-addendum.md') == '99de483216fc54ff95a5491bf35906cf9d00cb218580e69eeadde057998a36db'
assert sha(B / 'validation-before-crc-addendum.json') == '3f9d6b34e1ca7665379a3d7bcd9581f4ac8237cf150e65342bd01e5f96eebfdd'
assert report.startswith((B / 'report-before-crc-addendum.md').read_text())
old = read(B / 'validation-before-crc-addendum.json')
assert {k:v for k,v in validation.items() if k not in ['report_sha256','crc_caller_addendum']} == {k:v for k,v in old.items() if k!='report_sha256'}
assert checks['crc_caller_supplement_sha256'] == sha(B / 'crc-caller-contexts.json')
for role,label in [('acceptance','DF17 acceptance'),('report_syndrome','Report syndrome'),('address_recovery','AP address recovery')]:
    for family in analysis['families']:
        rows={r['symbol'].removeprefix(P):r for r in supplement['records'] if r['role']==role and r['family']==family}
        if 'frameSyndrome' not in rows:continue
        a,b=rows['frameSyndrome'],rows['Parity_checksum']
        assert f"| {label} / {family} | {a['native_entries']:,} | {a['inclusive_ir_non_additive']:,} | {b['native_entries']:,} | {b['inclusive_ir_non_additive']:,} |" in report
    a,b=supplement['totals'][role+'/frameSyndrome'],supplement['totals'][role+'/Parity_checksum']
    assert f"| **{label} total** | **{a['native_entries']:,}** | **{a['inclusive_ir_non_additive']:,}** | **{b['native_entries']:,}** | **{b['inclusive_ir_non_additive']:,}** |" in report
# Inspect the exact retained C lines as well as full report function body.
c_path = Path(supplement['generated_C_evidence']['path'])
c = c_path.read_text();lines=c.splitlines()
assert 'v___x_220_ = '+P+'frameSyndrome(v_f_218_);' in lines[supplement['generated_C_evidence']['report_syndrome_line']-1]
assert P+'Parity_interrogator(v___x_220_)' in lines[supplement['generated_C_evidence']['interrogator_reuse_line']-1]
body=c[c.index('LEAN_EXPORT lean_object* '+P+'report(lean_object* v_f_218_){'):]
body=body[:body.index('LEAN_EXPORT lean_object* '+P+'decode(')]
assert body.count(P+'frameSyndrome(')==1
assert supplement['df11_reuses_report_syndrome'] and supplement['df11_additional_checksum_calls']==0
assert 'no separate DF11 CRC instruction cost is assigned' in report
assert 'whose exact subpopulation instruction cost is not isolated here' in report

actual = {str(p.relative_to(B)) for p in B.rglob('*') if p.is_file()
          and not p.is_relative_to(R) and p != B / 'independent-review.json'}
assert actual == expected, (sorted(actual - expected), sorted(expected - actual))
assert not any(p.is_symlink() for p in B.rglob('*'))

# The native standalone Mach boundary disappeared; retained live callers must
# still reference the table and actual field extractor in the measured binary.
source = read(B / 'source-review.json')
assert not source['mach_native_context']['native_standalone_present']
assert source['mach_native_context']['object_definition_present']
assert source['mach_native_context']['immutable_code_count'] == 1024
assert source['mach_native_context']['table_eager_initialized']
for symbol in source['mach_native_context']['actual_caller_anchors']:
    command = next(v for v in source['commands'] if '--disassemble=' + symbol in v['argv'])
    assembly = Path(command['output']).read_text()
    assert sha(command['output']) == command['sha256']
    assert P + 'cbMachValueTable' in assembly and P + 'payloadBits' in assembly
assert 'This does not mean zero Mach work.' in report
assert 'does not subtract its former inclusive cost as a measured saving' in report

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
    'live_input_check_scope': 'All 232 protected source/proof/frozen/C/object/binary inputs matched at review time, before diagnostic hold release. No assertion about later authorized optimization changes.',
    'primary_archive_sources_checked': len(manifest['files']),
    'retained_omitted_binaries_checked': len(manifest['omitted_binaries']),
    'non_review_evidence_membership_count': len(expected),
    'reproduction_commands': [
        'python3 tests/evidence/diagnostics/gen5/independent-review/check_final.py',
        'python3 tests/evidence/diagnostics/gen5/independent-review/check_helper_fixture.py > tests/evidence/diagnostics/gen5/independent-review/helper-fixture.json',
        'python3 tests/evidence/diagnostics/gen5/independent-review/finalize_review.py'],
    'crc_caller_addendum_files': files,
    'review_artifacts': {str(p): sha(p) for p in sorted(R.iterdir()) if p.is_file()},
    'source_review_sha256': sha(B / 'source-review.json'),
    'independent_methods': [
        'An independent raw Callgrind parser sums self records, counts native calls and incoming inclusive edges, and derives stages from full caller-name chains instead of production graph propagation. All 13 profiles and all 2,690 grouped helper rows, including context counts, match.',
        'Every profile root count, controller state/command, full retained-output digest and DF population matches native evidence and the complete corpus. Interval and actual choose/fallback counts agree: 45,510 and zero.',
        'Recounted prior gen4 raw family profiles and current profiles validate every helper comparison. No standalone Mach context appears in any of the 13 current profiles; retained actual-worker disassembly confirms live table accesses in all three callers. Absence is not zero work.',
        'All 446 primary archive files match stored/decompressed hashes and original sources. Actual recursive membership is exact; all retained omitted binaries/raw files match.',
        'All 22 committed source and fresh native sets, 21 reused diagnostic objects and 232 protected inputs match. All 2,557 historical snapshot files, 2,508 committed historical files and five prior raw perf files remain unchanged; only the explicitly authorized gen5 benchmark-review addition is allowed.',
        'All 48 archived gen5 benchmark files match their original run. Report family/stage/comparison/helper/allocation/probe tables agree with recounted evidence.',
        'Perf raw hash and 420 records match, including 259 visible decoder samples and 416 samples with unknown frames. Capture preceded native diagnostic runs; both reports explicitly retain Total Lost Samples: 0.',
        'All 25 CRC caller records and their exact incoming edges are independently recounted: 172,432 report, 31,395 acceptance, and 83,591 address-recovery calls. The actual generated C shares the DF11 report syndrome with 38,456 interrogator operations; mixed-family instruction costs are deliberately unassigned.',
        'The pure synthetic stage-crossing fixture confirms that raw incoming inclusive costs can contain later-stage work while self costs remain an exact partition.'
    ],
    'review_tooling_notes': [
        'The first checker passed before the parent-requested CRC caller-context addendum; its source, log and result are retained with 01 suffixes. The finalizer initially retained the uppercase GEN4 report path; this reviewer-tool adaptation error is retained in finalize_review_01.py and finalizer-attempt-01.json. A second inventory check required normalizing the extractor absolute path against its repository-relative equivalent; that attempt is retained in finalize_review_02.py and finalizer-attempt-02.json. The corrected finalizer passes. No decoder or evidence failure was observed.'
    ],
    'limits': [
        'Instruction and small-allocation counts are diagnostics, not elapsed time, cycles, byte allocations or predicted throughput.',
        'Incoming inclusive costs overlap symbols, recursive contexts and later stages. Only self totals form the exact partition. Candidate/score probes are separate overlapping executions.',
        'Six instruction profiles intentionally overlapped. Perf attribution is conditional on visible ancestry; unknown frames and startup/preparation exclusions preclude an unbiased whole-decoder timing split. Host-wide isolation is not established.',
        'Density tables initialize eagerly before main; decoder-root profiles exclude that startup and differ from warmed benchmarks in lazy constants/allocator state. No unmeasured correction is made.',
        'This review made no production or frozen changes and ran no compiler, decoder, test suite, benchmark or profiler; it executed only read-only evidence parsers and a tiny synthetic Python parser fixture.'
    ],
    'hold_release_recommendation': 'Independent gen5 diagnostic review complete; no remaining review blocker to parent-controlled hold release.'
})
(B / 'independent-review.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'output': str(B / 'independent-review.json'),
                  'sha256': sha(B / 'independent-review.json'), 'findings': [],
                  'report_sha256': result['report_sha256'], 'validation_sha256': result['validation_sha256'],
                  'non_review_membership': len(expected)}, indent=2))
