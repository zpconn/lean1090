#!/usr/bin/env python3
"""Seal independent CPR raw/evidence/report review after producer correction."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
from collections import Counter
import gzip,hashlib,json
B=Path('tests/evidence/diagnostics/gen15-cpr');R=B/'independent-review'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for x in iter(lambda:f.read(1<<20),b''):h.update(x)
 return h.hexdigest()
def read(p):
 p=Path(p);return json.loads(gzip.decompress(p.read_bytes()) if p.suffix=='.gz' else p.read_bytes())
v=read(B/'validation.json');m=read(B/'archive-manifest.json');raw=read(R/'raw-recount.json');ev=read(R/'evidence-checks.json');a=read(B/'analysis-reviewed/analysis.json.gz');d=read(B/'decoder-stages.json.gz');reportpath=Path('docs/GEN15-CPR-COST-BREAKDOWN.md');report=reportpath.read_text()
assert v['status']==raw['status']==ev['status']=='passed'
assert v['report_sha256']==sha(reportpath)
assert v['archive_manifest_sha256']==ev['archive_manifest_sha256']==sha(B/'archive-manifest.json')
assert v['source_review_sha256']==ev['source_review_sha256']==sha(B/'source-review.json')
assert v['analysis_raw_sha256']==raw['profile_raw_sha256']==a['raw_sha256']
assert v['total_Ir']==raw['total_ir']==a['total_Ir']==18463254211
assert Counter(v['exclusive_stages'])==Counter(raw['exclusive_stages'])==Counter(a['exclusive_stages'])
assert v['decoder_stages']==raw['exclusive_decoder_stages']==d['exclusive_decoder_stages']
assert sha(B/'analysis-reviewed/analysis.json.gz')==raw['analysis_container_sha256']
assert sha(B/'retained/callgrind/callgrind.out.1.gz')==raw['profile_container_sha256']
# Closed producer inventory and separately retained orchestration logs.
for n,h in v['files'].items():assert sha(B/n)==h,n
producer_actual={str(p.relative_to(B)) for p in B.rglob('*') if p.is_file() and not p.is_relative_to(R) and p!=B/'independent-review.json'}
completion=read(B/'finalization-completion.json')
assert completion['validation_sha256']==sha(B/'validation.json') and completion['report_sha256']==sha(reportpath)
for n,h in completion['files'].items():assert sha(B/n)==h,n
known_extra={'validation.json','finalize-execution.log','finalize-sealed-execution.log','finalization-completion.json','before-chain-clarification/finalize-execution.log','before-chain-clarification/validation.json','before-log-binding/validation.json'}
assert sha(B/'before-chain-clarification/finalize-execution.log')==sha(B/'finalize-execution.log')
assert producer_actual==set(v['files'])|known_extra,sorted(producer_actual-set(v['files'])-known_extra)
assert set(m['files'])=={str(p.relative_to(B)) for folder in ['retained','tooling'] for p in (B/folder).rglob('*') if p.is_file()}
assert len(m['files'])==67
# Bind every exact reported row to independently recounted self or helper data.
label={'numeric_geography':'Numeric geography and conversion','motion_policy':'Motion policy, excluding numeric geography','airborne_pairing_policy':'Airborne pairing policy, excluding motion/geography','tracking_projection':'Tracking projection','state_tracking_control':'Remaining state/tracking control','surface_reference_policy':'Surface reference policy, excluding geography','loop_output_control':'Loop/output/retained-return control'}
labeldec={'frame_crc':'Decoder: frame/CRC','commb_inference':'Decoder: Comm-B inference','semantic_oracle_values':'Decoder: semantic/oracle values','adsb_fields':'Decoder: ADS-B fields','output_model_control':'Decoder: output/model control'}
for source,labels in [(raw['exclusive_stages'],label),(raw['exclusive_decoder_stages'],labeldec)]:
 for key,name in labels.items():
  n=source[key];assert f'| {name} | {n:,} | {n/raw["total_ir"]*100:.4f}% |' in report
P='lp_lean1090_Lean1090_Impl_';POL=P+'CPR_Policy_'
anchors=raw['native_anchors']
for name,labelname in [('streamStep','`streamStep`'),('toFloat','`toFloat`'),('haversineFloat','`haversineFloat`'),('stepAirborne','`stepAirborne`'),('stepSurface','`stepSurface`'),('validMotion','`validMotion`'),('nearestAirport','`nearestAirport`'),('speedGT','`speedGT`'),('decodeGlobalFloat','`decodeGlobalFloat` (unboxed)'),('distanceFromFloat','`distanceFromFloat`'),('positionFromFloats','`positionFromFloats`'),('decodeLocalFloat','`decodeLocalFloat` (unboxed)')]:
 r=anchors[POL+name];assert f'| {labelname} | {r["native_entries"]:,} | {r["inclusive_Ir_non_additive"]:,} |' in report
for helper in ['round','powerTwo']:
 r=next(r for r in a['helper_observations_non_additive'] if r['stage']=='numeric_geography' and r['symbol']==P+'Binary64_'+helper)
 assert f'| Numeric-geography `Binary64.{helper}` | {r["native_entries"]:,} | {r["inclusive_Ir_non_additive"]:,} |' in report
assert raw['direct_power_groups']==27
for text in ['not throughput estimates','first-use lazy','two have\npositions','1e-9-degree','13 included samples','306 samples: 164','142 are excluded','303 stacks','no positive incoming path from the collection root']:
 assert ' '.join(text.split()) in ' '.join(report.split()),text
# Preserve and bind the corrected wording without changing original analyses.
clar=read(B/'caller-chain-clarification.json')
assert clar['after_report_sha256']==sha(reportpath) and clar['no_algorithm_or_count_change'] and clar['no_native_rerun']
prior=B/'before-chain-clarification/GEN15-CPR-COST-BREAKDOWN.md'
assert sha(prior)==clar['before_report_sha256']
before=prior.read_text()
assert before.replace('253 self instructions because they had no positive incoming graph edge.', '253 self instructions because they had no positive incoming path from the\ncollection root. Two nodes do have incoming edges from other unreachable\nnodes; these do not establish root reachability.')==report
chain=read(R/'chain-recovery-review.json');assert chain['status']=='passed'
# The original decode review was sealed before authorized cache cleanup.
decbase=Path('tests/evidence/diagnostics/gen15');decreview=read(decbase/'independent-review.json');cleanup=read(decbase/'cache-cleanup.json');beforeclean=read(decbase/'cache-cleanup-before.json')
assert sha(decbase/'independent-review.json')=='97333e1b8672ddd31bc926d0571ee5949f7e2aff000ab4b3daf13d9a26c2249e'
assert cleanup['status']=='completed' and cleanup['independent_review_sha256']==sha(decbase/'independent-review.json')
assert cleanup['archive_manifest_sha256']==decreview['manifest_sha256']==sha(decbase/'archive-manifest.json')
assert cleanup['selected']==beforeclean['selected'] and cleanup['allocated_bytes']==277389312
assert len(cleanup['selected'])==335 and all(not Path(x['source']).exists() for x in cleanup['selected'])
assert sha(cleanup['raw_perf_retained'])==cleanup['raw_perf_sha256']
assert sha('bench/results.csv')==sha(decbase/'independent-review/results-prefix-before-next-generation.csv')
assert sha('bench/runs/gen15/results-review.json')=='370f5df1a6abd6717b18652fd61709f85764524cd4eca7ec61d0de3dc271af43'
# Full held-input and frozen rehash is deliberately the final substantive step.
assert len(v['protected_inputs'])==v['protected_input_count']==203
for p,h in v['protected_inputs'].items():assert sha(p)==h,p
lock=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()]
assert len(lock)==104 and sha('spec.lock')=='5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
for h,p in lock:assert sha(p)==h,p
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'report_sha256':sha(reportpath),'validation_sha256':sha(B/'validation.json'),'archive_manifest_sha256':sha(B/'archive-manifest.json'),'source_review_sha256':sha(B/'source-review.json'),'independent_raw_recount_sha256':sha(R/'raw-recount.json'),'independent_evidence_checks_sha256':sha(R/'evidence-checks.json'),'chain_recovery_independent_review_sha256':sha(R/'chain-recovery-review.json'),'primary_archive_members':67,'non_review_evidence_membership_count':len(producer_actual),'producer_inventory':{n:sha(B/n) for n in sorted(producer_actual)},'protected_inputs_unchanged':203,'locked_entries_unchanged':104,'fresh_native_sets':22,'reused_native_objects':21,'total_ir':raw['total_ir'],'exclusive_stages':raw['exclusive_stages'],'decoder_subpartition':raw['exclusive_decoder_stages'],'helper_groups_recounted':raw['helper_groups'],'self_contexts_recounted':raw['positive_self_contexts'],'direct_power_groups':raw['direct_power_groups'],'direct_power_edge_contexts':raw['direct_power_edge_contexts'],'graph_unreachable_recovered_contexts':6,'recovered_self_ir':253,'tracking_rows_exact':172432,'resolved_positions_exact':11347,'airport_rows_exact':6903,'complete_batch_state_and_positions_check_bound':True,'profile_output_matches_native_audit':True,'perf':{k:ev[k] for k in ['perf_samples','perf_included','perf_excluded','perf_unknown_stacks','perf_included_unknown_leaves','perf_lost_samples']},'decode_review_sha256':sha(decbase/'independent-review.json'),'authorized_post_decode_review_cleanup_receipt_sha256':sha(decbase/'cache-cleanup.json'),'benchmark_rows_unchanged':32,'reviewer_attempts':[{'path':'independent-review/raw-01.log','status':'passed'},{'path':'independent-review/evidence-01.log','status':'failed','reason':'The immutable archived analyzer intentionally differs from current source by the preserved eager/lazy limitation correction; reviewer was adjusted to bind both exact versions.'},{'path':'independent-review/evidence-02.log','status':'failed','reason':'Reviewer expected events list rather than retained run schema string Ir.'},{'path':'independent-review/evidence-03.log','status':'passed'}],'reviewer_files':{str(p.relative_to(B)):sha(p) for p in R.rglob('*') if p.is_file() and p.name!='finalize-review-01.log'},'findings':[],'resolved_findings':['Recovered-context prose corrected from absent incoming edge to absent positive path from root. Exact analyses and failed first report/validation retained; no counts changed.'],'limits':['Untimed instruction diagnostics are not elapsed benchmark results or speed predictions.','Inclusive helper observations overlap each other and exclusive stages; all self costs are exactly partitioned.','The CPR collection root mirrors the frozen immediate decode/tracking/streamStep path but includes its diagnostic retained-return packaging; preallocation, preparation and post-collection audits are outside.','Six positive-self contexts missing graph-root reachability are recovered solely from exact retained root caller chains. Two have internal edges; no cost dropped.','The corpus resolves two aircraft only. Its bit-identical rows do not replace the broader frozen tracking differential suite or the 1e-9-degree acceptance rule.','CPR perf includes 164 of 306 samples, with 303 unknown-frame stacks and 13 included unknown leaves; no lost samples reported.','Ordinary descendant source binding and independent source/generated-C/native review tie the unchanged production code to both diagnostics and the prior benchmark.']}
assert not (B/'independent-review.json').exists();(B/'independent-review.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','review_sha256':sha(B/'independent-review.json'),'total_ir':result['total_ir'],'non_review_members':len(producer_actual),'held_inputs':203},indent=2))
