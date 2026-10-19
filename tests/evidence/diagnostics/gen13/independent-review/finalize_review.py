#!/usr/bin/env python3
"""Complete the independent gen13 review after raw recount; no native execution."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib
import json
import sys
sys.dont_write_bytecode = True

B = Path('tests/evidence/diagnostics/gen13')
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
report = Path('docs/GEN13-COST-BREAKDOWN.md').read_text()
assert checks['status'] == validation['status'] == campaign['status'] == 'passed'
for name, path in [('report', 'docs/GEN13-COST-BREAKDOWN.md'),
                   ('analysis', B / 'analysis/analysis.json'),
                   ('manifest', B / 'archive-manifest.json'),
                   ('validation', B / 'validation.json')]:
    assert checks[name + '_sha256'] == sha(path)
assert sha(B / 'source-review.json') == '87ccca63ded2511dc3e92248c1e85698c16bd5c20c968706581b7a5445290da3'
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
           'campaign.stdout', 'campaign.stderr', 'finalize.stdout', 'finalize.stderr', 'helper-comparison.json', 'report.stderr', 'report.stdout', 'validation.json', 'byte-native-counts.json', 'penalty-probe-costs.json', 'wind-native-counts.json'}
expected = set(manifest['files']) | derived
actual = {str(p.relative_to(B)) for p in B.rglob('*') if p.is_file()
          and not p.is_relative_to(R) and p != B / 'independent-review.json'}
assert actual == expected, (sorted(actual - expected), sorted(expected - actual))
membership_count=len(expected)
assert not any(p.is_symlink() for p in B.rglob('*'))
assert (B/'campaign.stderr').read_bytes()==b''
assert (B/'report.stderr').read_bytes()==(B/'finalize.stderr').read_bytes()==b''
assert read(B/'finalize.stdout')==validation
printed_campaign=[json.loads(line) for line in (B/'campaign.stdout').read_text().splitlines() if line]
assert len(printed_campaign)==13
assert sorted(printed_campaign,key=lambda x:x['mode'])==sorted(campaign['profiles'],key=lambda x:x['mode'])
assert read(B/'finalize.stdout')==validation
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
    assert f'| {mode} | {old:,} | {new:,} | {new:,} / {new:,} | {new:,} |' in report

assert 'accepted corpus only' in report
assert 'inlined into `decode` remains' in report
assert 'does not measure malformed frames or frames rejected after parsing' in report
assert 'This accepted corpus does not measure rejection paths or arbitrary huge widths' in report
assert 'shared frame syndrome' in report or 'Shared-syndrome census' in report
assert 'Missing standalone or inlined helper boundaries do not imply zero computation.' in report
assert 'recursive or re-entrant visits can overlap within one row' in report
assert 'descendants can cross a later stage boundary' in report
for name in ('report-self.txt', 'report-children.txt'):
    assert '# Total Lost Samples: 0' in (B / 'perf' / name).read_text().splitlines()
fixture = read(R / 'helper-fixture.json')
assert fixture['status'] == 'passed' and fixture['analyzer_sha256'] == sha('review/diagnostics/analyze_callgrind.py')
assert read('bench/runs/gen13/results-review.json')['checks_passed'] == 1981

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
unknown_leaves=checks['perf_included_unknown_leaves']
assert f'{unknown_leaves} included leaf positions' in (B/'perf/README.md').read_text()
assert 'unknown' in report.lower() and f'{unknown_leaves:,} included leaves are unknown' in report

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


# Hold all twenty-eight already-recorded benchmark rows and the final independent
# benchmark review, including the two separately bound archival records.
preparation=read(R/'preparation.json')
prefix=R/'results-prefix-before-next-generation.csv'
assert sha(prefix)==preparation['result_prefix_sha256']==sha('bench/results.csv')
assert preparation['expected_result_rows']==28
assert sha('bench/runs/gen13/results-review.json')==preparation['benchmark_review_sha256']=='d6e766e6758fc853194fc6687302bef33c26731ccaff3bea417488fb44df92d3'
archive_bench=read('bench/runs/gen13/archive-verification.json')
for path,digest in archive_bench['added_artifacts'].items():assert sha(path)==digest,path
assert sha(B/'source-review.json')==preparation['expected_source_review_sha256']

# The new QNH source binding retains actual inlined caller loads.
assert source['qnh_table_live_path_verified']
qnh=source['qnh_native_context']
assert not qnh['native_standalone_present'] and qnh['object_definition_present']
assert qnh['immutable_code_count']==4096 and qnh['table_eager_initialized']
assert sha(qnh['native_paths'])==qnh['native_paths_sha256']
assert set(read(qnh['native_paths'])['paths'])=={'cbValid40','cbDensityTerms'}
for item in qnh['generated_C_excerpts'].values():
    assert sha(item['path'])==item['sha256'] and sha(item['source'])==item['source_sha256']
    lines=Path(item['source']).read_text().splitlines()
    excerpt='\n'.join(lines[item['first_body_line']-1:item['last_body_line']])+'\n'
    assert excerpt[excerpt.index('{'):]==Path(item['path']).read_text()
assert len(checks['qnh_live_caller_contexts_independently_recounted'])==13
assert 'inlined' in report and 'All immutable density, Mach, QNH and wind-penalty tables initialize before main.' in report

assert source['word_crc_live_path_verified']
crc_context=source['crc_native_context']
assert not crc_context['standalone_step_present'] and not crc_context['standalone_wordStep_present']
assert crc_context['object_step_and_wordStep_present'] and crc_context['high_index_Nat_testBit_fallback_present']
assert crc_context['state_width_bits']==32 and crc_context['output_width_bits']==24 and crc_context['cached_native_bt_sites']==2
assert sha(crc_context['syndrome_cfg'])==crc_context['syndrome_cfg_sha256']
cfg=read(crc_context['syndrome_cfg'])
assert cfg['instruction_count']==cfg['reachable_states']==87 and cfg['static_loop_sites']==2
assert all(row['loop_calls']==1 for row in cfg['exits'])
for item in crc_context['generated_C_excerpts'].values():
    assert sha(item['path'])==item['sha256'] and sha(item['source'])==item['source_sha256']
    lines=Path(item['source']).read_text().splitlines()
    excerpt='\n'.join(lines[item['first_body_line']-1:item['last_body_line']])+'\n'
    assert excerpt[excerpt.index('{'):]==Path(item['path']).read_text()
assert checks['crc_observed_UInt32_loop_entries']==172432 and checks['crc_observed_standalone_step_entries']==0
assert checks['crc_predicted_bit_iterations']==sum(row['crc_step_predictions'] for row in crc['per_df'])
assert 'Observed UInt32 loop entries' in report and 'mathematical iteration prediction, not an observed function-entry count' in report
assert f"{checks['crc_predicted_bit_iterations']:,} bit updates" in report

assert source['byte_words_live_path_verified']
byte_context=source['byte_words_native_context']
assert byte_context['public_standalone_present'] and byte_context['prefix_standalone_present'] and byte_context['fallback_standalone_present']
assert byte_context['word_fold_inlined_into_public'] and not byte_context['word_wrapper_standalone_present'] and not byte_context['specialized_word_fold_standalone_present']
assert byte_context['decodeFrame_calls_public'] and byte_context['unchanged_native_sets_including_model']==20
for label in ['native_cfg','ownership_deltas']:
    assert sha(byte_context[label])==byte_context[label+'_sha256']
byte_cfg=read(byte_context['native_cfg'])
assert all(row['counts']==[2] for row in byte_cfg['prefix']['normal_exits'])
for name,n in [('short',[0,0,0]),('medium',[1,0,1]),('long',[0,1,0])]:
    assert all(row['counts']==n for row in byte_cfg['public_branches'][name]['normal_exits'])
for item in byte_context['generated_C_excerpts'].values():
    assert sha(item['path'])==item['sha256'] and sha(item['source'])==item['source_sha256']
    lines=Path(item['source']).read_text().splitlines()
    excerpt='\n'.join(lines[item['first_body_line']-1:item['last_body_line']])+'\n'
    assert excerpt[excerpt.index('{'):]==Path(item['path']).read_text()
assert checks['byte_native_boundaries_independently_recounted']==read(B/'byte-native-counts.json')['rows']
assert checks['penalty_probe_costs_independently_recounted']==read(B/'penalty-probe-costs.json')['rows']
assert len(checks['penalty_probe_costs_independently_recounted'])==10
assert 'Candidate and score probes are overlapping views, not additive stages.' in report
assert 'All other production source/C/object/trace sets are unchanged from generation 12' in report
assert 'Missing standalone or inlined helper boundaries do not imply zero computation.' in report
assert 'These boundary counts do not measure the inlined byte-update iterations' in report

assert source['bds50_wind_penalty_live_path_verified']
wind=source['wind_penalty_native_context']
assert wind['immutable_entries']==2047 and wind['eager_initialized_before_main']
assert wind['lookup_standalone_present'] and wind['entry_standalone_present']
assert wind['unchanged_other_linked_native_sets']==20
assert sha(wind['native_cfg'])==wind['native_cfg_sha256']
wcfg=read(wind['native_cfg']);assert wcfg['instruction_count']==wcfg['reachable_instructions']==197
assert {tuple(x['events']) for x in wcfg['normal_exits']}=={('status46',),('status46','status24'),('status46','status24','tas47','gs25','table_load')}
for item in wind['generated_C_excerpts'].values():
    assert sha(item['path'])==item['sha256'] and sha(item['source'])==item['source_sha256']
    lines=Path(item['source']).read_text().splitlines()
    excerpt='\n'.join(lines[item['first_body_line']-1:item['last_body_line']])+'\n'
    assert excerpt[excerpt.index('{'):]==Path(item['path']).read_text()
assert checks['wind_lookup_and_constructor_counts_independently_recounted']==read(B/'wind-native-counts.json')['rows']
assert len(checks['wind_lookup_and_constructor_counts_independently_recounted'])==13
assert 'zero observed root entries are not a zero startup-cost claim' in report
assert 'All other production source/C/object/trace sets are unchanged from generation 12' in report

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
    'non_review_evidence_membership_count': membership_count,'prior_result_rows_preserved':28,'prior_result_csv_sha256':sha(prefix),
    'source_review_sha256': sha(B / 'source-review.json'),
    'review_artifacts': {str(p): sha(p) for p in sorted(R.iterdir()) if p.is_file() and not p.name.startswith('finalize-review-')},
    'retained_reviewer_attempts': [
        {'attempt': 1, 'reason': 'Reviewer used the prior generation benchmark-review hash; corrected to the existing gen13 artifact without changing producer data.', 'script_sha256': sha(R/'finalize_review-attempt-01.py'), 'log_sha256': sha(R/'finalize-review-01.log')},
        {'attempt': 2, 'reason': 'Reviewer used source_review_sha256 instead of the actual preparation schema key expected_source_review_sha256; corrected without changing preparation or producer data.', 'script_sha256': sha(R/'finalize_review-attempt-02.py'), 'log_sha256': sha(R/'finalize-review-02.log')}],
    'reproduction_commands': [
        'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/diagnostics/gen13/independent-review/check_final.py',
        'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/diagnostics/gen13/independent-review/check_helper_fixture.py > tests/evidence/diagnostics/gen13/independent-review/helper-fixture.json',
        'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/diagnostics/gen13/independent-review/finalize_review.py'],
    'independent_methods': [
        'An independent raw Callgrind parser sums self records, counts native entries and incoming inclusive edges, and derives stages from complete caller chains instead of production graph propagation. Every profile and grouped helper is checked.',
        'All complete-output digests and DF populations match native evidence and generation 0. The historical shadow census is unchanged; a separate accepted-only CRC census agrees with actual syndrome/checksum/UInt32 loop entries; bit-update iterations remain predictions and obsolete standalone step entries are absent.',
        'Each observed syndrome call originates directly in decode, with its checksum/packing descendants retained. The DF11 interrogator uses reportWithSyndrome. Static timed-worker C and assembly independently establish the shared value path.',
        'Every primary archive member is checked against stored and decompressed hashes, retained source bytes and exact recursive membership. All historical files and raw perf captures remain unchanged; only the explicitly bound benchmark-review addition is allowed.',
        'Current sources match timed committed blobs and all fresh native object/C/trace identities. The diagnostic substitutes only its driver object and reuses the held production objects.',
        'Family, stage, comparison, helper, allocation, candidate, score and interval report rows are recalculated. Prior generation family profiles are independently recounted for helper comparisons and all observed QNH caller contexts, without assigning zero work to inlined lookup symbols.',
        'Perf records, visible stacks, periods and stage labels are independently parsed, including every visible or unknown leaf and stack; the retained raw capture is unchanged.',
        'The retained byte converter native calls are independently counted against accepted 7/14-byte frame lengths. UInt64 word loops remain inlined, and Frame/Message ownership shifts are explicitly bounded; no stage reassignment or zero-work inference is made.',
        'All 13 raw roots independently reconcile exact BDS50 wind lookup entries with reached-score plus fallback counts, including zero table-constructor entries only inside collected roots; startup work is explicitly excluded.',
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
    'hold_release_recommendation': 'Independent gen13 diagnostic review complete; no remaining review blocker to parent-controlled hold release.'
})
path = B / 'independent-review.json'
assert not path.exists()
path.write_text(json.dumps(out, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'output': str(path), 'sha256': sha(path),
                  'report_sha256': out['report_sha256'], 'findings': []}, indent=2))
