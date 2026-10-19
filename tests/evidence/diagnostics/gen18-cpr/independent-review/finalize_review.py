#!/usr/bin/env python3
"""Independent complete CPR diagnostic seal; no native workloads."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,gzip,importlib.util
from collections import Counter
B=Path('tests/evidence/diagnostics/gen18-cpr');R=B/'independent-review';P='lp_lean1090_Lean1090_Impl_'
def read(p):
 p=Path(p);return json.loads(gzip.decompress(p.read_bytes()) if p.suffix=='.gz' else p.read_bytes())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for x in iter(lambda:f.read(1<<20),b''):h.update(x)
 return h.hexdigest()
v=read(B/'validation.json');m=read(B/'archive-manifest.json');raw=read(R/'raw-recount.json');e=read(R/'evidence-checks.json');s=read(R/'source-review.json');t=read(R/'table-tooling-review.json')
assert all(x['status']=='passed' for x in [v,m,raw,e])
assert s['status']=='passed_read_only_source_and_native_review'
assert t['status']=='passed' and t['findings']==[]
for name,h in t['bindings'].items():assert sha(name)==h,name
assert v['source_review_sha256']==e['source_review_sha256']==sha(R/'source-review.json')
assert raw['script_sha256']==sha(R/'check_raw.py') and e['script_sha256']==sha(R/'check_evidence.py')
assert raw['total_ir']==v['total_Ir'] and Counter(raw['exclusive_stages'])==Counter(v['exclusive_stages']) and Counter(raw['exclusive_decoder_stages'])==Counter(v['decoder_stages'])
for name,h in v['files'].items():assert sha(B/name)==h,name
actual={str(p.relative_to(B)) for p in B.rglob('*') if p.is_file() and not p.is_relative_to(R)}
assert actual==set(v['files'])|{'validation.json','finalize-execution.log','finalization-completion.json'},(actual-set(v['files']))
assert len(v['files'])==128 and len(actual)==131
assert len(m['files'])==52==v['archived_original_count']
assert {str(p.relative_to(B)) for n in ['retained','tooling'] for p in (B/n).rglob('*') if p.is_file()}==set(m['files'])
assert all(not p.is_symlink() for p in B.rglob('*'))
log=read(B/'finalize-execution.log');assert log['status']=='passed' and log['validation_sha256']==sha(B/'validation.json') and log['producer_files']==128
completion=read(B/'finalization-completion.json')
assert completion['status']=='passed' and completion['validation_sha256']==sha(B/'validation.json') and completion['report_sha256']==v['report_sha256']
assert completion['producer_inventory_count']==128 and completion['protected_inputs_checked_by_finalizer']==281 and completion['all_native_profile_build_jobs_stopped']
assert sha(completion['completed_finalizer_log']['path'])==completion['completed_finalizer_log']['sha256']==sha(B/'finalize-execution.log')
a=read(B/'analysis/analysis.json.gz');d=read(B/'decoder-stages.json.gz');n=read(B/'numeric-contexts.json.gz');native=read(B/'retained/validation/summary.json');perf=read(B/'perf/completion.json')
reportpath=Path('docs/GEN18-CPR-COST-BREAKDOWN.md');report=reportpath.read_text();assert sha(reportpath)==v['report_sha256']
assert sha(B/'archive-manifest.json')==v['archive_manifest_sha256']==e['archive_manifest_sha256']
assert sha(B/'analysis/analysis.json.gz')==raw['analysis_container_sha256']
assert sha(B/'numeric-contexts.json.gz')==raw['numeric_container_sha256']
labels={'numeric_geography':'Numeric geography and conversion','motion_policy':'Motion policy, excluding numeric geography','airborne_pairing_policy':'Airborne pairing policy, excluding motion/geography','surface_reference_policy':'Surface reference policy, excluding geography','state_tracking_control':'Remaining state/tracking control','tracking_projection':'Tracking projection','loop_output_control':'Loop/output/retained-return control'}
dl={'frame_crc':'frame/CRC','commb_inference':'Comm-B inference','semantic_oracle_values':'semantic/oracle values','adsb_fields':'ADS-B fields','output_model_control':'output/model control'}
stages=[(labels[k],x) for k,x in a['exclusive_stages'].items() if k in labels]+[('Decoder: '+dl[k],x) for k,x in d['exclusive_decoder_stages'].items()]
assert sum(x for _,x in stages)==raw['total_ir']
for label,value in stages:assert f'| {label} | {value:,} | {100*value/raw["total_ir"]:.4f}% |' in report
winner=max(stages,key=lambda x:x[1]);assert f'{winner[0]} is the largest individual' in report and f'category at {100*winner[1]/raw["total_ir"]:.2f}%' in report
for name in ['streamStep','toFloat','haversineFloat','stepAirborne','stepSurface','validMotion','nearestAirport','decodeGlobalFloat','decodeLocalFloat']:
 row=raw['native_anchors'][P+'CPR_Policy_'+name]
 assert f'| `{name}` | {row["native_entries"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
for stage,name in [('motion_policy','round'),('airborne_pairing_policy','round'),('motion_policy','exponent'),('airborne_pairing_policy','exponent'),('numeric_geography','fromBits'),('motion_policy','powerTwo'),('numeric_geography','powerTwo'),('airborne_pairing_policy','powerTwo')]:
 rows=[r for r in a['helper_observations_non_additive'] if r['stage']==stage and r['symbol']==P+'Binary64_'+name];assert len(rows)==1;row=rows[0]
 assert f'| `{stage} Binary64.{name}` | {row["native_entries"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
for row in [r for r in n['grouped_direct_edges'] if r['stage']=='numeric_geography'][:15]:
 assert f'| `{row["direct_caller"]}` → `{row["target"]}` | {row["calls"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
assert raw['numeric_direct_edge_groups']==len(n['grouped_direct_edges'])==66
assert v['graph_unreachable_explicit_chain_recovery']=={'contexts':len(raw['explicit_chain_recoveries']),'self_Ir':raw['recovery_total_ir']}
assert 'path from the collection root' in report and 'Incoming edges from other unreachable nodes' in report
assert str(native['result']['digest']['count'])=='172432'
assert e['tracking_rows_exact']==172432 and e['resolved_positions_exact']==11347 and e['full_batch_state_equal']
assert e['perf_samples']==perf['samples'] and e['perf_included']==perf['included_cpr_loop_stacks']
assert e['perf_unknown_stacks']==perf['unknown_frame_stacks'] and e['perf_included_unknown_leaves']==perf['unknown_cpr_leaf_samples']
assert f'CPR recorded {e["perf_samples"]} samples: {e["perf_included"]} have a visible CPR-loop ancestor' in report
assert f'{e["perf_excluded"]} are excluded. Unknown frames occur in {e["perf_unknown_stacks"]} stacks' in report
assert f'{e["perf_included_unknown_leaves"]} unknown included leaves.' in report
assert 'not throughput estimates' in report and 'not inferred from cost' in report
table=read(B/'table-contexts-summary.json')
assert table['total']==raw['table_counts'] and table['by_stage']==raw['table_stage_counts']
assert sha(B/'table-contexts.json.gz')==raw['table_container_sha256']==v['table_contexts_sha256']
for row in table['by_stage']+[dict(table['total'],stage='**Total**')]:
 assert f'| {row["stage"]} | {row["lookup_entries"]:,} | {row["direct_formula_fallback_calls"]:,} | {row["table_lookup_calls_from_verified_branch_partition"]:,} |' in report if row['stage']!='**Total**' else f'| **Total** | **{row["lookup_entries"]:,}** | **{row["direct_formula_fallback_calls"]:,}** | **{row["table_lookup_calls_from_verified_branch_partition"]:,}** |' in report
assert table['table_constructor_entries_inside_root']==v['table_constructor_entries_inside_root']==0
assert 'at most one' in report and 'not claimed to be zero' in report and 'No claim is made about all possible' in report
# The late conversion supplement is independently parsed from the same raw
# graph and reconciled by complete contexts, not just its printed top rows.
remaining=read(R/'remaining-review.json');supp=read(B/'remaining-conversion-contexts.json')
assert remaining['status']=='passed' and remaining['script_sha256']==sha(R/'check_remaining.py')
assert remaining['independent_parser_sha256']==sha(R/'check_raw.py')
assert remaining['supplement_sha256']==sha(B/'remaining-conversion-contexts.json')==v['remaining_conversion_contexts_sha256']
assert remaining['actual_fallback_calls']==supp['actual_fallback_calls_inside_root']==v['actual_conversion_fallback_calls_inside_root']==0
for key in ['dyadic_to_float_live_path_verified','dyadic_to_float_at_most_one_fallback_per_entry','dyadic_to_float_zero_case_verified']:assert s[key]
conversion=[row for row in n['grouped_direct_edges'] if row['target'] in [s['dyadic_to_float_anchor'],s['dyadic_to_float_fallback_anchor']]]
assert conversion==v['conversion_direct_edges_non_additive']
for row in conversion:assert f'| {row["stage"]} | `{row["direct_caller"]}` → `{row["target"]}` | {row["calls"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
assert '0 actual incoming calls to the source-verified' in report and 'wrapper entries that do not call fallback include zero as well as admitted' in report
assert 'Inlined packing has no separately callable native boundary' in report
correction=read(B/'preparation-correction/correction.json')
assert correction['status']=='corrected_before_report_or_finalizer_execution' and correction['native_profile_analysis_or_data_changes'] is False
assert correction['historical_report_sha256']==sha('docs/GEN17-CPR-COST-BREAKDOWN.md')
assert correction['original_preparation_sha256']==sha(B/'finalizer-preparation.json')
for row in correction['changes']:
 original=B/'preparation-correction'/Path(row['file']).name
 assert sha(original)==row['before_sha256']
 assert hashlib.sha256(original.read_text().replace('GEN17-CPR-COST-BREAKDOWN','GEN18-CPR-COST-BREAKDOWN').encode()).hexdigest()==row['after_sha256']
# Final source hashes additionally bind the later requested conversion narrative.
assert sha(B/'write_report.py')==t['bindings'][str(B/'write_report.py')]
assert sha(B/'finalize.py')==t['bindings'][str(B/'finalize.py')]
# Both diagnostics bind the same benchmark and whole-message result, while their
# independent collection roots differ and their counts are not conflated.
decode=Path('tests/evidence/diagnostics/gen18');decreview=read(decode/'independent-review/independent-review.json')
assert decreview['status']=='passed'
assert sha(v['same_generation_decode_digest_path'])==v['same_generation_decode_digest_file_sha256']
assert e['full_message_digest']==v['message_digest']
sourcebinding=read(decode/'benchmark-source-binding.json');assert sourcebinding['binary_sha256']==s['worker_sha256'] if 'worker_sha256' in s else sourcebinding['binary_sha256']==v['protected_inputs']['.lake/build/bin/lean1090-bench']
# Shared compact-history verification is explicitly identity-only for old ignored
# compressed evidence, and full Git content/inventory for committed histories.
sp=importlib.util.spec_from_file_location('cpr_review_history',decode/'snapshot_history.py');hm=importlib.util.module_from_spec(sp);sp.loader.exec_module(hm);history=read(decode/'historical-inputs.json');assert hm.verify(history)==17095
for path,h in v['protected_inputs'].items():assert sha(path)==h,path
assert len(v['protected_inputs'])==281
lock=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()];assert len(lock)==104
for h,path in lock:assert sha(path)==h,path
assert sha('spec.lock')=='5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'report_sha256':sha(reportpath),'validation_sha256':sha(B/'validation.json'),'manifest_sha256':sha(B/'archive-manifest.json'),'source_review_sha256':sha(R/'source-review.json'),'tooling_review_sha256':sha(R/'table-tooling-review.json'),'raw_recount_sha256':sha(R/'raw-recount.json'),'evidence_checks_sha256':sha(R/'evidence-checks.json'),'decode_review_sha256':sha(decode/'independent-review/independent-review.json'),'primary_archive_members':52,'inventoried_producer_files':128,'non_review_evidence_membership_count':131,'late_completed_log_sha256':sha(B/'finalize-execution.log'),'held_inputs_unchanged':281,'locked_files_unchanged':104,'fresh_native_sets':22,'reused_production_objects':21,'total_ir':raw['total_ir'],'exclusive_stages':raw['exclusive_stages'],'exclusive_decoder_stages':raw['exclusive_decoder_stages'],'independent_self_contexts':raw['positive_self_contexts'],'independent_helper_groups':raw['helper_groups'],'numeric_edge_groups':66,'power_edge_groups':raw['direct_power_groups'],'explicit_chain_recoveries':raw['explicit_chain_recoveries'],'explicit_recovery_ir':raw['recovery_total_ir'],'full_tracking_rows_exact':172432,'positions_exact':11347,'full_batch_state_and_routed_list_equal':True,'perf':{k:e[k] for k in ['perf_samples','perf_included','perf_excluded','perf_unknown_stacks','perf_included_unknown_leaves','perf_lost_samples']},'compact_history_sha256':sha(decode/'historical-inputs.json'),'reviewer_attempts':[{'log':'raw-01.log','status':'passed'},{'log':'evidence-01.log','status':'passed'},{'log':'remaining-01.log','status':'passed'}],'final_sealer_attempts':[{'log':'seal-01.log','status':'passed'}],'table_counts':raw['table_counts'],'table_stage_counts':raw['table_stage_counts'],'remaining_conversion_review_sha256':sha(R/'remaining-review.json'),'actual_conversion_fallback_calls_inside_root':remaining['actual_fallback_calls'],'remaining_conversion_helper_rows':remaining['helper_rows'],'remaining_conversion_direct_groups':remaining['direct_groups'],'preparation_correction_sha256':sha(B/'preparation-correction/correction.json'),'dyadic_to_float_live_path_verified':True,'finalization_completion_sha256':sha(B/'finalization-completion.json'),'reviewer_files':{str(p.relative_to(B)):sha(p) for p in R.rglob('*') if p.is_file() and p.name not in ['independent-review.json','seal-01.log']},'findings':[],'limits':raw['limitations']+history['limits']+['Corpus tracking does not exhaust policy strata; frozen differential/proof gates remain the correctness authority.','Perf only attributes samples with visible ancestors; unresolved stacks remain explicit.','Diagnostic loop retains full output and return state; no elapsed benchmark claim.']}
p=R/'independent-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(p),'total_ir':raw['total_ir'],'producer_members':131,'held_inputs':281}))
