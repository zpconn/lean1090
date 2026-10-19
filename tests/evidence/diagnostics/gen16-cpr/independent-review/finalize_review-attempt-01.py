#!/usr/bin/env python3
"""Independent complete CPR diagnostic seal; no native workloads."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,gzip,importlib.util
B=Path('tests/evidence/diagnostics/gen16-cpr');R=B/'independent-review';P='lp_lean1090_Lean1090_Impl_'
def read(p):
 p=Path(p);return json.loads(gzip.decompress(p.read_bytes()) if p.suffix=='.gz' else p.read_bytes())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for x in iter(lambda:f.read(1<<20),b''):h.update(x)
 return h.hexdigest()
v=read(B/'validation.json');m=read(B/'archive-manifest.json');raw=read(R/'raw-recount.json');e=read(R/'evidence-checks.json');s=read(R/'source-review.json');t=read(R/'tooling-review.json')
assert all(x['status']=='passed' for x in [v,m,raw,e,t])
assert s['status']=='passed_read_only_source_and_native_review'
assert v['source_review_sha256']==e['source_review_sha256']==sha(R/'source-review.json')
assert raw['script_sha256']==sha(R/'check_raw.py') and e['script_sha256']==sha(R/'check_evidence.py')
assert raw['total_ir']==v['total_Ir'] and raw['exclusive_stages']==v['exclusive_stages'] and raw['exclusive_decoder_stages']==v['decoder_stages']
for name,h in v['files'].items():assert sha(B/name)==h,name
actual={str(p.relative_to(B)) for p in B.rglob('*') if p.is_file() and not p.is_relative_to(R)}
assert actual==set(v['files'])|{'validation.json','finalize-execution.log'},(actual-set(v['files']))
assert len(v['files'])==107 and len(actual)==109
assert len(m['files'])==52==v['archived_original_count']
assert {str(p.relative_to(B)) for n in ['retained','tooling'] for p in (B/n).rglob('*') if p.is_file()}==set(m['files'])
assert all(not p.is_symlink() for p in B.rglob('*'))
log=read(B/'finalize-execution.log');assert log['status']=='passed' and log['validation_sha256']==sha(B/'validation.json') and log['producer_files']==107
assert sha(B/'finalize-execution.log')=='7df77a51f1d791cb725ab4a4c49c4ad4b9735325699daacc04a4efdbb406ab4b'
a=read(B/'analysis/analysis.json.gz');d=read(B/'decoder-stages.json.gz');n=read(B/'numeric-contexts.json.gz');native=read(B/'retained/validation/summary.json');perf=read(B/'perf/completion.json')
reportpath=Path('docs/GEN16-CPR-COST-BREAKDOWN.md');report=reportpath.read_text();assert sha(reportpath)==v['report_sha256']
assert sha(B/'archive-manifest.json')==v['archive_manifest_sha256']==e['archive_manifest_sha256']
assert sha(B/'analysis/analysis.json.gz')==raw['analysis_container_sha256']
assert sha(B/'numeric-contexts.json.gz')==raw['numeric_container_sha256']
labels={'numeric_geography':'Numeric geography and conversion','motion_policy':'Motion policy, excluding numeric geography','airborne_pairing_policy':'Airborne pairing policy, excluding motion/geography','surface_reference_policy':'Surface reference policy, excluding geography','state_tracking_control':'Remaining state/tracking control','tracking_projection':'Tracking projection','loop_output_control':'Loop/output/retained-return control'}
dl={'frame_crc':'frame/CRC','commb_inference':'Comm-B inference','semantic_oracle_values':'semantic/oracle values','adsb_fields':'ADS-B fields','output_model_control':'output/model control'}
stages=[(labels[k],x) for k,x in a['exclusive_stages'].items() if k in labels]+[('Decoder: '+dl[k],x) for k,x in d['exclusive_decoder_stages'].items()]
assert sum(x for _,x in stages)==raw['total_ir']
for label,value in stages:assert f'| {label} | {value:,} | {100*value/raw["total_ir"]:.4f}% |' in report
assert max(stages,key=lambda x:x[1])[0]=='Numeric geography and conversion'
for name in ['streamStep','toFloat','haversineFloat','stepAirborne','stepSurface','validMotion','nearestAirport','decodeGlobalFloat','decodeLocalFloat']:
 row=raw['native_anchors'][P+'CPR_Policy_'+name]
 assert f'| `{name}` | {row["native_entries"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
for name in ['round','exponent','powerTwo']:
 rows=[r for r in a['helper_observations_non_additive'] if r['stage']=='numeric_geography' and r['symbol']==P+'Binary64_'+name];assert len(rows)==1;row=rows[0]
 assert f'| `Numeric-geography Binary64.{name}` | {row["native_entries"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
for row in [r for r in n['grouped_direct_edges'] if r['stage']=='numeric_geography'][:15]:
 assert f'| `{row["direct_caller"]}` → `{row["target"]}` | {row["calls"]:,} | {row["inclusive_Ir_non_additive"]:,} |' in report
assert raw['numeric_direct_edge_groups']==len(n['grouped_direct_edges'])==85
assert v['graph_unreachable_explicit_chain_recovery']=={'contexts':len(raw['explicit_chain_recoveries']),'self_Ir':raw['recovery_total_ir']}
assert 'path from the collection root' in report and 'Incoming edges from other unreachable nodes' in report
assert str(native['result']['digest']['count'])=='172432'
assert e['tracking_rows_exact']==172432 and e['resolved_positions_exact']==11347 and e['full_batch_state_equal']
assert e['perf_samples']==perf['samples'] and e['perf_included']==perf['included_cpr_loop_stacks']
assert e['perf_unknown_stacks']==perf['unknown_frame_stacks'] and e['perf_included_unknown_leaves']==perf['unknown_cpr_leaf_samples']
assert f'CPR recorded {e["perf_samples"]} samples: {e["perf_included"]} have a visible CPR-loop ancestor' in report
assert f'{e["perf_excluded"]} are excluded. Unknown frames occur in {e["perf_unknown_stacks"]} stacks' in report
assert f'{e["perf_included_unknown_leaves"]} unknown included leaves.' in report
assert 'not throughput estimates' in report and 'future table-hit coverage' in report
# Both diagnostics bind the same benchmark and whole-message result, while their
# independent collection roots differ and their counts are not conflated.
decode=Path('tests/evidence/diagnostics/gen16');decreview=read(decode/'independent-review/independent-review.json')
assert decreview['status']=='passed'
assert sha(v['same_generation_decode_digest_path'])==v['same_generation_decode_digest_file_sha256']
assert e['full_message_digest']==v['message_digest']
sourcebinding=read(decode/'benchmark-source-binding.json');assert sourcebinding['binary_sha256']==s['worker_sha256'] if 'worker_sha256' in s else sourcebinding['binary_sha256']==v['protected_inputs']['.lake/build/bin/lean1090-bench']
# Shared compact-history verification is explicitly identity-only for old ignored
# compressed evidence, and full Git content/inventory for committed histories.
sp=importlib.util.spec_from_file_location('cpr_review_history',decode/'snapshot_history.py');hm=importlib.util.module_from_spec(sp);sp.loader.exec_module(hm);history=read(decode/'historical-inputs.json');assert hm.verify(history)==15122
for path,h in v['protected_inputs'].items():assert sha(path)==h,path
assert len(v['protected_inputs'])==204
lock=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()];assert len(lock)==104
for h,path in lock:assert sha(path)==h,path
assert sha('spec.lock')=='5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'report_sha256':sha(reportpath),'validation_sha256':sha(B/'validation.json'),'manifest_sha256':sha(B/'archive-manifest.json'),'source_review_sha256':sha(R/'source-review.json'),'tooling_review_sha256':sha(R/'tooling-review.json'),'raw_recount_sha256':sha(R/'raw-recount.json'),'evidence_checks_sha256':sha(R/'evidence-checks.json'),'decode_review_sha256':sha(decode/'independent-review/independent-review.json'),'primary_archive_members':52,'inventoried_producer_files':107,'non_review_evidence_membership_count':109,'late_completed_log_sha256':sha(B/'finalize-execution.log'),'held_inputs_unchanged':204,'locked_files_unchanged':104,'fresh_native_sets':22,'reused_production_objects':21,'total_ir':raw['total_ir'],'exclusive_stages':raw['exclusive_stages'],'exclusive_decoder_stages':raw['exclusive_decoder_stages'],'independent_self_contexts':raw['positive_self_contexts'],'independent_helper_groups':raw['helper_groups'],'numeric_edge_groups':85,'power_edge_groups':raw['direct_power_groups'],'explicit_chain_recoveries':raw['explicit_chain_recoveries'],'explicit_recovery_ir':raw['recovery_total_ir'],'full_tracking_rows_exact':172432,'positions_exact':11347,'full_batch_state_and_routed_list_equal':True,'perf':{k:e[k] for k in ['perf_samples','perf_included','perf_excluded','perf_unknown_stacks','perf_included_unknown_leaves','perf_lost_samples']},'compact_history_sha256':sha(decode/'historical-inputs.json'),'reviewer_attempts':[{'log':'raw-01.log','status':'passed_raw_accounting_before_additional_numeric_recount'},{'log':'raw-02.log','status':'passed_all_numeric_and_raw_checks'},{'log':'evidence-01.log','status':'failed_reviewer_schema','reason':'Prior retention schema called original analysis path raw_cache; current explicit field is source. Original script/log retained; no producer changes.'},{'log':'evidence-02.log','status':'passed'}],'reviewer_files':{str(p.relative_to(B)):sha(p) for p in R.rglob('*') if p.is_file() and p.name not in ['independent-review.json','seal-01.log']},'findings':[],'limits':raw['limitations']+history['limits']+['Corpus tracking does not exhaust policy strata; frozen differential/proof gates remain the correctness authority.','Perf only attributes samples with visible ancestors; unresolved stacks remain explicit.','Diagnostic loop retains full output and return state; no elapsed benchmark claim.']}
p=R/'independent-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(p),'total_ir':raw['total_ir'],'producer_members':109,'held_inputs':204}))
