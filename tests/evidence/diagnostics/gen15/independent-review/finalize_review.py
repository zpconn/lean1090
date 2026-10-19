#!/usr/bin/env python3
"""Seal the independent gen15 decode recount; no native execution or mutation."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json
B=Path('tests/evidence/diagnostics/gen15'); R=B/'independent-review'
def read(p): return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for x in iter(lambda:f.read(1<<20),b''):h.update(x)
 return h.hexdigest()
checks=read(R/'final-checks.json'); v=read(B/'validation.json'); m=read(B/'archive-manifest.json'); c=read(B/'campaign.json'); s=read(B/'source-review.json')
assert checks['status']==v['status']==c['status']=='passed'
for name,path in [('report','docs/GEN15-COST-BREAKDOWN.md'),('analysis',B/'analysis/analysis.json'),('manifest',B/'archive-manifest.json'),('validation',B/'validation.json')]: assert checks[name+'_sha256']==sha(path)
assert sha(B/'source-review.json')=='1cfa669ca710fc718c92483364e5d5625fc4f727fa3f27db8fa84b7d2f7b0799'
derived={'analysis/ANALYSIS.md','analysis/analysis.json','analyze.stderr','analyze.stdout','archive-manifest.json','archive.stderr','archive.stdout','byte-native-counts.json','campaign.stderr','campaign.stdout','constant-contexts.stderr','constant-contexts.stdout','constant-native-contexts.json','context-notes.md','extract_pack_fields.py','finalize.stderr','finalize.stdout','helper-comparison.json','pack-fields-direct-costs.json','pack-fields.stderr','pack-fields.stdout','penalty-probe-costs.json','ratio-contexts.stderr','ratio-contexts.stdout','ratio-native-contexts.json','report.stderr','report.stdout','validation.json','wind-native-counts.json'}
expected=set(m['files'])|derived
actual={str(p.relative_to(B)) for p in B.rglob('*') if p.is_file() and not p.is_relative_to(R) and p!=B/'independent-review.json'}
assert actual==expected,(sorted(actual-expected),sorted(expected-actual)); membership_count=len(expected)
assert len(m['files'])==500 and len(derived)==29 and membership_count==529
assert not any(p.is_symlink() for p in B.rglob('*'))
for name in ['campaign','finalize','report','pack-fields','constant-contexts','ratio-contexts','analyze','archive']: assert (B/(name+'.stderr')).read_bytes()==b'',name
assert read(B/'finalize.stdout')==v
printed=[json.loads(line) for line in (B/'campaign.stdout').read_text().splitlines() if line]
assert len(printed)==13 and sorted(printed,key=lambda x:x['mode'])==sorted(c['profiles'],key=lambda x:x['mode'])
for record in s['commands']: assert record['exit_code']==0 and sha(record['output'])==record['sha256']
assert s['fresh_project_modules_verified']==22 and s['reused_production_objects_verified']==21
for path,record in s['source_C_object_trace_bindings'].items():
 assert sha(path)==record['source_sha256']
 for artifact,digest in record['artifacts'].items(): assert sha(artifact)==digest,artifact
for key in ['previous_source_review','gen15_implementation_native_review']:
 row=s[key];assert sha(row['path'])==row['sha256']
old=read(s['previous_source_review']['path']); previous=old['source_C_object_trace_bindings']
assert len(s['unchanged_native_modules'])==19
for path in s['unchanged_native_modules']:
 current=s['source_C_object_trace_bindings'][path]; before=previous[path]
 assert current['source_sha256']==before['source_sha256']
 for artifact,digest in current['artifacts'].items():
  if not artifact.endswith('.trace'): assert before['artifacts'][artifact]==digest
for key in ['shared_syndrome_decode_verified','integer_score_gate_verified','affine_payload_value_verified','field_mask_verified','qnh_table_live_path_verified','word_crc_live_path_verified','byte_words_live_path_verified','bds50_wind_penalty_live_path_verified','bds60_ratio_enclosure_live_path_verified','commb_payload_limit_live_path_verified']: assert s[key] is True,key
assert s['constant_native_context']['literal_ascii']=='72057594037927936'
for item in s['constant_native_context']['generated_C_excerpts'].values():
 assert sha(item['path'])==item['sha256'] and sha(item['source'])==item['source_sha256']
 assert Path(item['path']).read_text() in Path(item['source']).read_text()
for path,digest in c['protected_inputs'].items(): assert sha(path)==digest,path
assert len(c['protected_inputs'])==242
prep=read(R/'preparation.json')
assert sha(R/'results-prefix-before-next-generation.csv')==prep['result_prefix_sha256']==sha('bench/results.csv')
assert prep['expected_result_rows']==32
assert sha('bench/runs/gen15/results-review.json')==prep['benchmark_review_sha256']=='370f5df1a6abd6717b18652fd61709f85764524cd4eca7ec61d0de3dc271af43'
assert checks['historical_snapshot_files_checked']==12964 and len(checks['profiles_independently_recounted'])==13
assert checks['total_ir']==11213423773 and checks['exclusive_stages']['frame_crc']==3961737590
assert checks['perf_raw_samples']==257 and checks['perf_visible_decoder_samples']==68 and checks['perf_unknown_frame_samples']==246 and checks['perf_included_unknown_leaves']==0
fixture=read(R/'helper-fixture.json');assert fixture['status']=='passed' and fixture['analyzer_sha256']==sha('review/diagnostics/analyze_callgrind.py')
pack=read(B/'pack-fields-direct-costs.json')
assert pack['total']==checks['pack_fields_totals']
for k,p in [('main_report_sha256','docs/GEN15-COST-BREAKDOWN.md'),('validation_sha256',B/'validation.json'),('archive_manifest_sha256',B/'archive-manifest.json'),('extractor_sha256',B/'extract_pack_fields.py')]:assert pack[k]==sha(p)
assert pack['total']=={'entry_calls':172432,'self_ir':52319321,'incoming_inclusive_ir':1280682876}
report=Path('docs/GEN15-COST-BREAKDOWN.md').read_text()
for text in ['11,213,423,773','3,961,737,590','627,880','257','68','189','246','instruction','non-additive']:
 assert text in report,text
assert 'Missing standalone or inlined helper boundaries do not imply zero computation.' in report
cleanup=B/'cleanup_cache.py';assert m['files']['cleanup_cache.py']['stored_sha256']==sha(cleanup)
# Preserve original measured target reporting identity despite its authorized
# later dual-target extension: no comparison against the mutable live helper.
plan=read('tests/evidence/optimization/gen15/benchmark-preparation/plan.json')
legacy=Path('tests/evidence/optimization/dual-target-reporting/before.py')
assert sha(legacy)==read('tests/evidence/optimization/gen15/benchmark-preparation/preparation-verification.json')['helper_sha256']
result={
 'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'reviewer':'Independent source/native and raw-accounting reviewer',
 'manifest_sha256':sha(B/'archive-manifest.json'),'report_sha256':sha('docs/GEN15-COST-BREAKDOWN.md'),'validation_sha256':sha(B/'validation.json'),
 'analysis_sha256':sha(B/'analysis/analysis.json'),'source_review_sha256':sha(B/'source-review.json'),'raw_recount_sha256':sha(R/'final-checks.json'),
 'primary_archive_members':len(m['files']),'non_review_evidence_membership_count':membership_count,'supplement_members':sorted(derived),
 'supplement_hashes':{name:sha(B/name) for name in sorted(derived)},
 'profiles_independently_recounted':13,'protected_inputs_unchanged':242,'historical_snapshot_files_checked':12964,
 'fresh_native_sets':22,'reused_production_objects':21,'benchmark_rows_unchanged':32,
 'exclusive_stage_ir':checks['exclusive_stages'],'total_ir':checks['total_ir'],'pack_fields_totals':checks['pack_fields_totals'],
 'reviewed_source_and_accounting': ['Complete independent raw Callgrind self sums, context stage assignments, helper self/entry/inclusive groups, native census and whole-message digest checks.', 'All 500 archived files and 29 explicit supplements, all 13 current profile roots, all prior raw perf, 12,964 historical files and 22 fresh native sets.', 'Actual constant guard global load and eager initializer; source-identical other native paths retain their independent earlier assessment.', 'Direct packFields children, integer/ratio/wind/byte/CRC native populations independently recounted, with overlapping costs kept non-additive.', 'Ordinary descendant benchmark source binding requires exact complete audited Lean inventory and committed blobs plus native/lock identity.', 'Cleanup source reviewed statically: exact retained duplicate verification, explicit own-cache omitted artifact list, quiescent caller assertion, durable before-delete receipts, strict identity guards and raw perf preservation. It was not executed by this reviewer.'],
 'retained_final_sealer_attempts':[{'path':'independent-review/finalize-review-01.log','status':'failed','reason':'Reviewer expected a profile count scalar; retained raw recount correctly stores a 13-mode dictionary. Corrected to its length and bound legacy helper through its actual preparation-verification record.'},{'path':'independent-review/finalize-review-02.log','status':'passed_checks_receipt_superseded','reason':'All checks passed, but the sealer inventoried its still-open stdout. Preserve the record and exclude only the active third-attempt log from the reviewer-file inventory.'},{'path':'independent-review/finalize-review-03.log','status':'passed'}],
 'retained_reviewer_attempts':[{'path':'independent-review/final-checks-01.log','status':'failed','reason':'Reviewer expected older README wording for zero unknown leaves; all raw/profile/history checks had passed. Corrected only wording assertion.'},{'path':'independent-review/final-checks-02.log','status':'passed'}],
 'reviewer_files':{str(p.relative_to(B)):sha(p) for p in sorted(R.rglob('*')) if p.is_file() and p.name!='finalize-review-03.log'},
 'findings':[],
 'limits':['Instruction counts are diagnostic, not elapsed performance or benchmark predictions.','Perf has 257 samples, 68 decode-visible, 189 excluded, 246 stacks containing unknown frames and zero included unknown leaves; no lost samples were reported.','Native inlining and ownership boundaries affect attribution. Inclusive helper observations overlap parents/descendants and are not added to stage totals.','Corpus coverage and accepted-frame census do not establish arbitrary rejected-input populations. Correctness remains bound to the proved implementation and separate differential gate.','This review precedes optional authorized cache cleanup; any subsequent omissions require a separate durable receipt. All archived sources, raw profiles, evidence and raw perf remain protected.','Overall production hold remains controlled by root pending the separate CPR diagnostic review.']}
assert sha(B/'independent-review.json')==sha(R/'seal-attempt-02.json')
(B/'independent-review.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','review_sha256':sha(B/'independent-review.json'),'primary_members':len(m['files']),'non_review_members':membership_count,'profiles':13,'total_ir':checks['total_ir']},indent=2))
