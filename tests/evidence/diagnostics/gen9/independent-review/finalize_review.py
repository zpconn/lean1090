#!/usr/bin/env python3
"""Complete the independent gen9 review after raw recount; no native execution."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib
import json

B = Path('tests/evidence/diagnostics/gen9')
R = B / 'independent-review'
P = 'lp_lean1090_Lean1090_Impl_'
def read(path): return json.loads(Path(path).read_text())
def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()

checks = read(R / 'final-checks.json')
validation = read(B / 'validation.json')
manifest = read(B / 'archive-manifest.json')
analysis = read(B / 'analysis/analysis.json')
campaign = read(B / 'campaign.json')
source = read(B / 'source-review.json')
report = Path('docs/GEN9-COST-BREAKDOWN.md').read_text()
assert checks['status'] == validation['status'] == campaign['status'] == 'passed'
for name, path in [('report', 'docs/GEN9-COST-BREAKDOWN.md'),
                   ('analysis', B / 'analysis/analysis.json'),
                   ('manifest', B / 'archive-manifest.json'),
                   ('validation', B / 'validation.json')]:
    assert checks[name + '_sha256'] == sha(path)
assert sha(B / 'source-review.json') == 'da26615b77a4430da93bf50b3b00ef89b367cfeeb34685fe16739a4e8bcd2b7c'
assert source['shared_syndrome_decode_verified']
assert source['shared_syndrome_native_context']['native_syndrome_call_sites_in_decode'] == 1
assert not source['shared_syndrome_native_context']['native_acceptance_boundary_present']
for local, record in source['shared_syndrome_native_context']['generated_C_excerpts'].items():
    assert sha(record['path']) == record['sha256']
    assert sha(record['source']) == record['source_sha256']
    lines = Path(record['source']).read_text().splitlines()
    excerpt = '\n'.join(lines[record['first_body_line'] - 1:record['last_body_line']]) + '\n'
    # The first line starts at the opening brace, after the exported signature.
    excerpt = excerpt[excerpt.index('{'):]
    assert excerpt == Path(record['path']).read_text(), local

derived = {'analysis/ANALYSIS.md', 'analysis/analysis.json', 'analyze.stderr', 'analyze.stdout',
           'archive-manifest.json', 'archive.stderr', 'archive.stdout', 'context-notes.md',
           'campaign.stdout', 'campaign.stderr', 'finalize.stdout', 'finalize.stderr', 'helper-comparison.json', 'field-caller-contexts.json', 'field-caller-contexts.md', 'field-contexts.stdout', 'field-contexts.stderr', 'report.stderr', 'report.stdout', 'validation.json'}
expected = set(manifest['files']) | derived
actual = {str(p.relative_to(B)) for p in B.rglob('*') if p.is_file()
          and not p.is_relative_to(R) and p != B / 'independent-review.json'}
assert actual == expected, (sorted(actual - expected), sorted(expected - actual))
membership_count=len(expected)
assert not any(p.is_symlink() for p in B.rglob('*'))
assert (B/'campaign.stderr').read_bytes()==(B/'finalize.stderr').read_bytes()==b''
printed_campaign=[json.loads(line) for line in (B/'campaign.stdout').read_text().splitlines() if line]
assert len(printed_campaign)==13
assert sorted(printed_campaign,key=lambda x:x['mode'])==sorted(campaign['profiles'],key=lambda x:x['mode'])
assert json.loads((B/'finalize.stdout').read_text())==validation
execution_logs={str(B/name):sha(B/name) for name in ['campaign.stdout','campaign.stderr','finalize.stdout','finalize.stderr']}

# Static absence of cbMach64 must remain accompanied by retained actual loads.
assert not source['mach_native_context']['native_standalone_present']
assert source['mach_native_context']['object_definition_present']
assert source['mach_native_context']['immutable_code_count'] == 1024
assert source['mach_native_context']['table_eager_initialized']
for symbol in source['mach_native_context']['actual_caller_anchors']:
    command = next(v for v in source['commands'] if '--disassemble=' + symbol in v['argv'])
    assembly = Path(command['output']).read_text()
    assert sha(command['output']) == command['sha256']
    assert P + 'cbMachValueTable' in assembly and P + 'payloadBits' in assembly

native_rows = [json.loads(x) for x in (B / 'native/all.jsonl').read_text().splitlines() if x]
result = next(x for x in native_rows if x.get('phase') == 'result')
interval = next(x for x in native_rows if x.get('kind') == 'post_decode_interval_census')
historical = next(x for x in native_rows if x.get('kind') == 'post_decode_shadow_census')
crc = next(x for x in native_rows if x.get('kind') == 'post_decode_crc_census')
assert crc == checks['live_crc_census'] == validation['live_crc_census']
assert crc['population'] == 'accepted_corpus_only'
for row in interval['registers']:
    reg = f"{row['register_decimal']:02x}"
    score = analysis['non_additive_register_score_probes'][reg]
    candidate = analysis['non_additive_register_candidate_probes'][reg]
    passed = row['fast_accept'] + row['fallback_accept']
    assert f"| BDS{reg} | {candidate['root_incoming_calls']:,} | {row['reached']:,} | {passed:,} | {candidate['total_events'].get('Ir', 0):,} | {score['total_events'].get('Ir', 0):,} |" in report
    n, a, r, fa, fr = (row[k] for k in ['reached', 'fast_accept', 'fast_reject', 'fallback_accept', 'fallback_reject'])
    assert f'| BDS{reg} | {n:,} | {a:,} | {r:,} | {fa:,} / {fr:,} | {n:,} / {n:,} | {fa + fr:,} / {fa + fr:,} |' in report

for mode in analysis['families']:
    run = read(B / 'callgrind' / mode / 'run.json')
    assert sum(x['digest']['count'] for x in run['result']['per_df']) == run['prepared']['selected']
    allowed = {17, 18} if mode == 'adsb' else {20, 21} if mode == 'commb' else set(range(32)) - {17, 18, 20, 21}
    for item in run['result']['per_df']:
        if item['df'] in allowed: assert item == result['per_df'][item['df']]
        else: assert item['digest']['count'] == 0
    old = sum(row['crc_call_predictions'] for row in historical['per_df'] if row['df'] in allowed)
    new = sum(row['crc_call_predictions'] for row in crc['per_df'] if row['df'] in allowed)
    steps = sum(row['crc_step_predictions'] for row in crc['per_df'] if row['df'] in allowed)
    assert f'| {mode} | {old:,} | {new:,} | {new:,} / {new:,} | {steps:,} |' in report

assert 'accepted corpus only' in report
assert 'inlined into `decode` remains' in report
assert 'Rejected-input costs are not claimed' in report
assert 'shared frame syndrome' in report or 'Shared-syndrome census' in report
assert 'Missing native edges do not mean zero inlined work' in report
assert 'recursive or re-entrant visits can overlap within one row' in report
assert 'descendants can cross a later stage boundary' in report
for name in ('report-self.txt', 'report-children.txt'):
    assert '# Total Lost Samples: 0' in (B / 'perf' / name).read_text().splitlines()
fixture = read(R / 'helper-fixture.json')
assert fixture['status'] == 'passed' and fixture['analyzer_sha256'] == sha('review/diagnostics/analyze_callgrind.py')
assert read('bench/runs/gen9/results-review.json')['checks_passed'] == 1886

assert source['integer_score_gate_verified']
closure_path=Path(source['integer_score_gate_native_context']['reference_closure'])
assert sha(closure_path)==source['integer_score_gate_native_context']['reference_closure_sha256']
closure=read(closure_path)
assert len(closure['reachable_local_functions'])==15
for record in closure['excerpts'].values():
    assert sha(record['path'])==record['sha256'] and sha(record['source'])==record['source_sha256']
assert not any('Rat_' in name or 'Binary64' in name or 'gcd' in name.lower() for name in closure['external_C_calls'])
for mode,row in checks['integer_gate_observations'].items():
    assert f"| {mode} | {row['choose']:,} | {row['common_denominator']:,} | {row['totals_entry']:,} |" in report
assert checks['perf_included_unknown_leaves']==0
assert '0 included leaf positions' in (B/'perf/README.md').read_text()
assert 'unknown' in report.lower() and '0 included leaves are unknown' in report

assert source['affine_payload_value_verified']
ctx=source['affine_payload_native_context']
assert not ctx['helper_standalone_present'] and ctx['helper_object_definition_present']
assert ctx['native_direct_mul_sites']==ctx['native_direct_add_sites']==1
assert sha(ctx['native_branch_sequences'])==ctx['native_branch_sequences_sha256']
sequences=read(ctx['native_branch_sequences']);assert len(sequences['cases'])==4
for row in sequences['cases']:
    expected=[P+'payloadInteger','l_Rat_ofInt']+([] if row['scale_equals_one'] else ['l_Rat_mul'])+([] if row['offset_equals_zero'] else ['l_Rat_add'])
    assert row['present_call_sequence']==expected and row['rejected_call_sequence']==[]
for record in ctx['generated_C_excerpts'].values():
    assert sha(record['path'])==record['sha256'] and sha(record['source'])==record['source_sha256']
    lines=Path(record['source']).read_text().splitlines()
    excerpt='\n'.join(lines[record['first_body_line']-1:record['last_body_line']])+'\n'
    assert excerpt[excerpt.index('{'):]==Path(record['path']).read_text()
assert checks['field_contexts_sha256']==sha(B/'field-caller-contexts.json')
assert source['field_mask_verified'] and source['field_mask_anchor']==P+'field'
field_ctx=source['field_mask_native_context']
assert field_ctx['native_field_present'] and field_ctx['mask_helper_inlined'] and field_ctx['decodeFrame_field_call_sites']==26
assert sha(field_ctx['native_branches'])==field_ctx['native_branches_sha256']
branches=read(field_ctx['native_branches'])['branches']
assert branches['narrow']['return_shift_and_mask_flags']==[[True,True]]
assert branches['wide']['return_shift_and_mask_flags']==[[False,False]]
assert not set(branches['narrow']['calls']) & {'lean_nat_pow','lean_nat_big_div','l_BitVec_ofNat'}
assert {'lean_nat_pow','lean_nat_big_div','l_BitVec_ofNat'} <= set(branches['wide']['calls'])
for record in field_ctx['generated_C_excerpts'].values():
    assert sha(record['path'])==record['sha256'] and sha(record['source'])==record['source_sha256']
    lines=Path(record['source']).read_text().splitlines()
    excerpt='\n'.join(lines[record['first_body_line']-1:record['last_body_line']])+'\n'
    assert excerpt[excerpt.index('{'):]==Path(record['path']).read_text()


# Hold all twenty already-recorded benchmark rows and the final independent
# benchmark review, including the two separately bound archival records.
preparation=read(R/'preparation.json')
prefix=R/'results-prefix-before-next-generation.csv'
assert sha(prefix)==preparation['result_prefix_sha256']==sha('bench/results.csv')
assert preparation['expected_result_rows']==20
assert sha('bench/runs/gen9/results-review.json')==preparation['benchmark_review_sha256']=='afec245e169e80f2014e9232d30d7ae7345e8a8437bb31d4f1b45a71874123bc'
archive_bench=read('bench/runs/gen9/archive-verification.json')
for path,digest in archive_bench['added_artifacts'].items():assert sha(path)==digest,path
assert sha(B/'source-review.json')==preparation['source_review_sha256']

# Final held-input equality check is explicitly bounded to review time.
for name, digest in campaign['protected_inputs'].items(): assert sha(name) == digest, name
for name, record in manifest['omitted_binaries'].items():
    assert sha(name) == record['sha256'] and Path(name).stat().st_size == record['bytes']

out = dict(checks)
out.update({
    'review_kind': 'independent read-only source, native structure, raw-counter, archive, report and provenance review',
    'supplementary_execution_logs':execution_logs,
    'completed_utc': datetime.now(timezone.utc).isoformat(),
    'findings': [],
    'live_input_check_scope': f"All {len(campaign['protected_inputs'])} protected inputs match at review time, before diagnostic hold release. Later authorized changes are outside this assertion.",
    'primary_archive_sources_checked': len(manifest['files']),
    'retained_omitted_binaries_checked': len(manifest['omitted_binaries']),
    'non_review_evidence_membership_count': membership_count,'prior_result_rows_preserved':20,'prior_result_csv_sha256':sha(prefix),
    'source_review_sha256': sha(B / 'source-review.json'),
    'review_artifacts': {str(p): sha(p) for p in sorted(R.iterdir()) if p.is_file() and not p.name.startswith('finalize-review-')},
    'reproduction_commands': [
        'python3 tests/evidence/diagnostics/gen9/independent-review/check_final.py',
        'python3 tests/evidence/diagnostics/gen9/independent-review/check_helper_fixture.py > tests/evidence/diagnostics/gen9/independent-review/helper-fixture.json',
        'python3 tests/evidence/diagnostics/gen9/independent-review/finalize_review.py'],
    'independent_methods': [
        'An independent raw Callgrind parser sums self records, counts native entries and incoming inclusive edges, and derives stages from complete caller chains instead of production graph propagation. Every profile and grouped helper is checked.',
        'All complete-output digests and DF populations match native evidence and generation 0. The historical shadow census is unchanged; a separate accepted-only CRC census agrees with actual syndrome/checksum/fold/step counts.',
        'Each observed syndrome call originates directly in decode, with its checksum/packing descendants retained. The DF11 interrogator uses reportWithSyndrome. Static timed-worker C and assembly independently establish the shared value path.',
        'Every primary archive member is checked against stored and decompressed hashes, retained source bytes and exact recursive membership. All historical files and raw perf captures remain unchanged; only the explicitly bound benchmark-review addition is allowed.',
        'Current sources match timed committed blobs and all fresh native object/C/trace identities. The diagnostic substitutes only its driver object and reuses the held production objects.',
        'Family, stage, comparison, helper, allocation, candidate, score and interval report rows are recalculated. Prior generation family profiles are independently recounted for helper comparisons and every exact field incoming/outgoing caller context.',
        'Perf records, visible stacks, periods and stage labels are independently parsed, including the zero unknown leaves among 114 visible decoder stacks; the retained raw capture is unchanged.',
        'A pure synthetic stage-crossing fixture verifies that inclusive helper costs may include later-stage descendants while self costs remain an exact partition.'
    ],
    'limits': [
        'Instructions and small allocation counts are diagnostics, not elapsed time, cycles, allocated bytes or predicted throughput.',
        'The corpus contains accepted frames only. General malformed/rejected-input evaluation costs are not measured by these counts.',
        'Compiler inlining changes operational boundaries: acceptance self work stays in decode residual control, while retained called helpers retain their stages. No cost is reassigned by source intention.',
        'Incoming inclusive costs overlap symbols, recursive contexts and later stages. Only self costs partition the total; candidate/score probes are separate overlapping executions.',
        'Perf attribution is conditional on visible ancestry and retains unknown/unwound stacks. The six-way instruction campaign overlaps deliberately and does not establish host isolation.',
        'Table startup lies outside decoder-root collection. Single-pass allocator/lazy-constant conditions differ from warmed timing; no unmeasured correction is applied.',
        'This review ran only read-only evidence parsers, disassembly tools and a tiny synthetic Python fixture. It changed no production/frozen source and ran no decoder, compiler, test suite, benchmark or profiler.'
    ],
    'hold_release_recommendation': 'Independent gen9 diagnostic review complete; no remaining review blocker to parent-controlled hold release.'
})
path = B / 'independent-review.json'
assert not path.exists()
path.write_text(json.dumps(out, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'output': str(path), 'sha256': sha(path),
                  'report_sha256': out['report_sha256'], 'findings': []}, indent=2))
