#!/usr/bin/env python3
"""Seal independent generation-21 review; no builds or native execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,importlib.util,subprocess
B=Path('tests/evidence/diagnostics/gen21');R=B/'independent-review'
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for x in iter(lambda:f.read(1<<20),b''):h.update(x)
 return h.hexdigest()
checks=read(R/'final-checks.json');v=read(B/'validation.json');m=read(B/'archive-manifest.json');c=read(B/'campaign.json');s=read(R/'source-review.json')
assert checks['status']==v['status']==c['status']=='passed'
for key,path in [('report',Path('docs/GEN21-COST-BREAKDOWN.md')),('analysis',B/'analysis/analysis.json'),('manifest',B/'archive-manifest.json'),('validation',B/'validation.json'),('source_review',R/'source-review.json')]:assert checks[key+'_sha256']==sha(path)
assert checks['checker_sha256']==sha(R/'check_final.py')
derived=set('analysis/ANALYSIS.md analysis/analysis.json analyze.stderr analyze.stdout archive-manifest.json archive.stderr archive.stdout bit-contexts.stderr bit-contexts.stdout bit-extraction-contexts.json byte-native-counts.json campaign-command.json campaign-controller.stderr campaign-controller.stdout campaign.stderr campaign.stdout constant-contexts.stderr constant-contexts.stdout constant-native-contexts.json context-notes.md crc-byte-contexts.json crc-contexts.stderr crc-contexts.stdout finalize.stderr finalize.stdout helper-comparison.json pack-contexts.stderr pack-contexts.stdout pack-fields-direct-costs.json penalty-probe-costs.json power-contexts.stderr power-contexts.stdout power-native-contexts.json priority-contexts.stderr priority-contexts.stdout priority-helper-contexts.json ratio-contexts.stderr ratio-contexts.stdout ratio-native-contexts.json report.stderr report.stdout validation.json wind-native-counts.json'.split())
derived.update('affine-contexts.stderr affine-contexts.stdout affine-native-contexts.json extract_ratio_contexts_corrected.py finalizer-correction.json finalizer-correction-02.json resume_finalize.py resume_finalize_02.py resume-finalize.stderr resume-finalize.stdout resume-finalize-02.stderr resume-finalize-02.stdout ratio-contexts-02.stderr ratio-contexts-02.stdout'.split())
expected=set(m['files'])|derived
actual={str(p.relative_to(B)) for p in B.rglob('*') if p.is_file() and (not p.is_relative_to(R) or str(p.relative_to(B)) in m['files'])}
assert actual==expected,(actual-expected,expected-actual)
assert len(m['files'])==517 and len(derived)==57 and len(expected)==574
assert all(not p.is_symlink() for p in B.rglob('*'))
for name in ['campaign','resume-finalize-02','report','pack-contexts','constant-contexts','ratio-contexts-02','power-contexts','priority-contexts','bit-contexts','crc-contexts','affine-contexts','campaign-controller','analyze','archive']:assert (B/(name+'.stderr')).read_bytes()==b'',name
assert read(B/'resume-finalize-02.stdout')==v
for name,needle in [('finalize','CalledProcessError'),('ratio-contexts','AssertionError'),('resume-finalize','NameError')]:assert needle in (B/(name+'.stderr')).read_text() and (B/(name+'.stdout')).read_bytes()==b''
for name in ['finalizer-correction.json','finalizer-correction-02.json']:
 correction=read(B/name)
 assert correction['report_previously_written'] is False
 for path,h in correction['preserved_bindings'].items():assert sha(path)==h,path
 for path,h in correction.get('corrected_bindings',{}).items():assert sha(path)==h,path
assert read(B/'finalizer-correction-02.json')['corrected_script_sha256']==sha(B/'resume_finalize_02.py')
printed=[json.loads(x) for x in (B/'campaign.stdout').read_text().splitlines() if x]
assert len(printed)==13 and sorted(printed,key=lambda x:x['mode'])==sorted(c['profiles'],key=lambda x:x['mode'])
for name,row in m['files'].items():assert sha(B/name)==row['stored_sha256'],name
for command in s['commands']:assert command['exit_code']==0 and sha(command['output'])==command['sha256']
for path,row in s['source_C_object_trace_bindings'].items():
 assert sha(path)==row['source_sha256']
 for path,h in row['artifacts'].items():assert sha(path)==h
for key in ['previous_source_review','implementation_native_review']:
 row=s[key];assert sha(row['path'])==row['sha256']
assert len(s['unchanged_native_modules'])==21
for key in ['pack_fields_shift_mask_verified','shared_syndrome_decode_verified','integer_score_gate_verified','affine_payload_value_verified','field_mask_verified','qnh_table_live_path_verified','word_crc_live_path_verified','byte_words_live_path_verified','bds50_wind_penalty_live_path_verified','bds60_ratio_enclosure_live_path_verified','commb_payload_limit_live_path_verified','power_two_table_live_path_verified','dyadic_to_float_live_path_verified','systematic_bit_extraction_verified','byte_crc_live_path_verified','integer_affine_normalization_live_path_verified']:assert s[key] is True
report=Path('docs/GEN21-COST-BREAKDOWN.md').read_text();crc=read(B/'crc-byte-contexts.json')
assert checks['crc_supplement_sha256']==sha(B/'crc-byte-contexts.json')==v['crc_byte_contexts_sha256']
assert checks['crc_native_counts']==crc['native_counts']
assert 'Comm-B candidate inference / raw records' in report and 'Frame / CRC' in report
assert checks['affine_supplement_sha256']==sha(B/'affine-native-contexts.json')==v['affine_native_contexts_sha256']
assert checks['integer_affine_normalization_live_path_verified']
assert f"predicts {checks['predicted_byte_iterations']:,} byte iterations and {checks['predicted_crc_iterations']:,} equivalent bit updates" in report
for row in crc['native_counts']:
 o=row['observed_native_entries']
 assert f"| {row['profile']} | {row['expected_crc_calls_from_checked_census']:,} | {o['parity_byte_wrapper_anchor']:,} / {o['parity_byte_fold_anchor']:,} | {o['parity_bit_wrapper_anchor']:,} / {o['parity_bit_fold_anchor']:,} | {row['predicted_byte_iterations_not_native_entries']:,} | {row['predicted_bit_updates_not_native_entries']:,} |" in report
# Newly added report tables are all reconciled to already independently recounted raw groups.
P='lp_lean1090_Lean1090_Impl_'
for generation in read(B/'affine-native-contexts.json')['generations']:
 for row in generation['rows']:
  assert f"| {generation['generation']} | {row['stage']} | `{row['symbol'].removeprefix(P)}` | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} |" in report
  if row['symbol']==P+'payloadValue':
   for child in row['direct_children']:assert f"| {generation['generation']} | {row['stage']} | `{child['symbol'].removeprefix(P)}` | {child['calls']:,} | {child['inclusive_ir_non_additive']:,} |" in report
for row in read(B/'priority-helper-contexts.json')['rows']:
 assert f"| {row['stage']} | `{row['symbol'].removeprefix(P)}` | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} |" in report
assert 'not exclusive savings' in report and 'no standalone native entry count' in report
history=read(B/'historical-inputs.json')
correction_review=read(R/'producer-tooling-correction-review.json');assert correction_review['status']=='passed_read_only_correction_review' and correction_review['findings']==[] and correction_review['check_count']==84
for p,h in correction_review['bindings'].items():assert sha(p)==h,p
tooling=read(R/'producer-tooling-review.json');assert tooling['status']=='passed_read_only_producer_tooling_review' and tooling['findings']==[]
for p,h in tooling['bindings'].items():assert sha(p)==h,p
sp=importlib.util.spec_from_file_location('review_final_history',B/'snapshot_history.py');hm=importlib.util.module_from_spec(sp);sp.loader.exec_module(hm);assert hm.verify(history)==20338
assert len(history['binding']['untracked_and_ignored_file_identities'])==311 and len(history['binding']['retained_historical_perf_identities'])==27
assert len(checks['profiles_independently_recounted'])==13 and checks['total_ir']==v['total_ir']
assert checks['exclusive_stages']==v['exclusive_stage_ir']
assert checks['pack_comparisons'][1]['total']==read(B/'pack-fields-direct-costs.json')['generations'][1]['total']
cleanup=B/'cleanup_cache.py';assert sha(cleanup)==m['files']['cleanup_cache.py']['stored_sha256']
# Source-reviewed cleanup cannot touch production or archived evidence: own-cache
# duplicates need decompressed hash+size equality; omitted names are explicit;
# fsync and strict identities precede unlink; raw perf remains protected.
assert checks['source_review_sha256']==sha(R/'source-review.json')
for path,h in c['protected_inputs'].items():assert sha(path)==h,path
assert len(c['protected_inputs'])==251
lock=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()];assert len(lock)==104
for h,path in lock:assert sha(path)==h
assert sha('spec.lock')=='5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
review_files={str(p.relative_to(B)):sha(p) for p in R.rglob('*') if p.is_file() and p.name!='independent-review.json' and str(p.relative_to(R)) not in ['seal-attempt-01/stdout.log','seal-attempt-01/stderr.log']}
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'manifest_sha256':sha(B/'archive-manifest.json'),'report_sha256':checks['report_sha256'],'validation_sha256':checks['validation_sha256'],'analysis_sha256':checks['analysis_sha256'],'source_review_sha256':checks['source_review_sha256'],'raw_recount_sha256':sha(R/'final-checks.json'),'primary_archive_members':517,'non_review_evidence_membership_count':len(expected),'supplement_members':sorted(derived),'supplement_hashes':{n:sha(B/n) for n in sorted(derived)},'profiles_independently_recounted':13,'protected_inputs_unchanged':251,'locked_files_unchanged':104,'fresh_native_sets':22,'reused_production_objects':21,'total_ir':checks['total_ir'],'exclusive_stage_ir':checks['exclusive_stages'],'pack_fields_comparisons':checks['pack_comparisons'],'historical_binding_sha256':sha(B/'historical-inputs.json'),'historical_committed_files':20338,'historical_ignored_identities':311,'historical_raw_perf_identities':27,'perf':{k:checks[k] for k in ['perf_raw_samples','perf_visible_decoder_samples','perf_unknown_frame_samples','perf_included_unknown_leaves']},'cleanup_source_sha256':sha(cleanup),'cleanup_source_review':'Passed read-only: exact retained duplicate validation and explicit own-cache rebuildable names; durable pre-unlink receipts; no recursion, raw perf and unbound files preserved. No cleanup executed by reviewer.','reviewer_attempts':[{'record':'source-attempt-01/execution.json','status':'passed'},{'record':'final-attempt-01/execution.json','status':'passed'},{'record':'seal-attempt-01/execution.json','status':'passed'}],'power_tooling_review_sha256':sha(R/'producer-tooling-review.json'),'power_rows_independently_recounted':checks['power_rows_independently_recounted'],'power_contexts_recounted':checks['power_contexts_recounted'],'priority_helper_rows_independently_recounted':checks['priority_helper_rows_independently_recounted'],'priority_contexts_independently_recounted':checks['priority_contexts_independently_recounted'],'producer_correction_tooling_review_sha256':sha(R/'producer-tooling-correction-review.json'),'producer_corrections':[{'path':str(B/n),'sha256':sha(B/n)} for n in ['finalizer-correction.json','finalizer-correction-02.json']],'integer_affine_normalization_live_path_verified':True,'affine_comparisons_independently_recounted':checks['affine_comparisons_independently_recounted'],'affine_supplement_sha256':checks['affine_supplement_sha256'],'byte_crc_live_path_verified':True,'observed_crc_paths':checks['observed_crc_paths'],'predicted_byte_iterations':checks['predicted_byte_iterations'],'equivalent_bit_update_predictions':checks['predicted_crc_iterations'],'crc_context_comparisons':checks['crc_context_comparisons'],'systematic_bit_extraction_verified':True,'bit_extraction_comparisons_independently_recounted':checks['bit_extraction_comparisons_independently_recounted'],'dyadic_to_float_live_path_verified':True,'reviewer_files':review_files,'findings':[],'limits':history['limits']+['Instruction costs are diagnostic, not throughput predictions. Inclusive groups overlap and compiler inlining changes observed boundaries.','Current archives and raw profiles were freshly hash-checked; old ignored transcript identities are not a new full-content integrity audit.','Review records pre-cleanup state; a later authorized cleanup requires its own receipt. Parent controls hold release pending CPR review.']}
p=R/'independent-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(p),'primary_members':517,'complete_producer_members':len(expected),'total_ir':checks['total_ir']}))
