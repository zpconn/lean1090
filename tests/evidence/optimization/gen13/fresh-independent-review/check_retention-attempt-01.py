#!/usr/bin/env python3
"""Read-only gen13 fresh provenance review before fixed gate/archive completion."""
from pathlib import Path
from datetime import datetime,timezone
import json,hashlib,csv,io,gzip
B=Path('tests/evidence/optimization/gen13');R=B/'fresh-independent-review';I=B/'independent-review'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for chunk in iter(lambda:f.read(4*1024*1024),b''):h.update(chunk)
 return h.hexdigest()
def load(p):return json.loads(Path(p).read_text())
expected=load(R/'handoff-bindings.json')
for f,key in [('fresh-final-verification.json','fresh_final_verification_sha256'),('fresh-message/summary.json','fresh_summary_sha256'),('fresh-retained-hashes.json','fresh_retention_sha256'),('fresh-execution.json','fresh_execution_sha256')]:assert sha(B/f)==expected[key]
retention=load(B/'fresh-retained-hashes.json');execution=load(B/'fresh-execution.json');run=load(B/'fresh-message-run.json');verify=load(B/'fresh-final-verification.json');preflight=load(B/'fresh-preflight.json');seeds=load(B/'fresh-seeds.json');commb=load(B/'fresh-commb-run.json')
assert retention['status']==execution['status']==run['status']==verify['status']==commb['status']==preflight['status']=='passed'
assert execution['exit_code']==run['exit_code']==verify['exit_code']==0
actual={str(p) for p in B.glob('fresh*') if p.is_file() and p.name!='fresh-retained-hashes.json'}|{str(p) for p in (B/'fresh-message').rglob('*') if p.is_file()}
assert actual==set(retention['files']) and len(actual)==33
for f,row in retention['files'].items():assert sha(f)==row['sha256'] and Path(f).stat().st_size==row['bytes'],f
for kind,count in [('source_sha256',109),('binary_sha256',3)]:
 assert run[kind+'_before']==run[kind+'_after'] and len(run[kind+'_after'])==count
 for f,d in run[kind+'_after'].items():assert sha(f)==d,f
 before=kind if kind=='source_sha256' else kind+'_before'
 assert commb[before]==commb[kind+'_after']==run[kind+'_before']
assert execution['final_source_hash_count']==retention['final_source_hash_count']==verify['source_hash_count']==109
assert execution['final_binary_hash_count']==retention['final_binary_hash_count']==verify['binary_hash_count']==3
assert execution['final_source_binary_hashes_match'] and retention['final_source_binary_hashes_match']
assert execution['retained_file_count']==retention['exact_membership_count']==33
assert run['summary_sha256']==verify['summary_sha256']==sha(B/'fresh-message/summary.json')
assert verify['run_record_sha256']==sha(B/'fresh-message-run.json') and verify['verifier_sha256']==sha(B/'fresh-verify.py')
assert execution['verification_sha256']==retention['existing_raw_verification']['sha256']==sha(B/'fresh-final-verification.json')
assert execution['retention_execution_sha256']==retention['retention_execution_sha256']==sha(B/'fresh-retention-execution.json')
assert execution['preflight_sha256']==sha(B/'fresh-preflight.json')
assert execution['seed_record_sha256']==run['seed_record_sha256']==commb['seed_record_sha256']==preflight['seed_record_sha256']==sha(B/'fresh-seeds.json')
assert preflight['authorized_by']=='/root'
assert preflight['integrated_build_record_sha256']==sha(B/'integration/targeted-build.json')
assert preflight['integrated_build_log_sha256']==sha(B/'integration/targeted-build.log')
for path,digest in preflight['helpers'].items():assert sha(path)==digest
for command in execution['commands']:
 assert command['exit_code']==0 and sha(command['log'])==command['log_sha256']
 assert command['helper_sha256']==command['helper_sha256_after']==sha(command['command'][1])
 assert command['started_monotonic_ns']<=command['finished_monotonic_ns']
assert execution['commands'][0]['finished_monotonic_ns']<=execution['commands'][1]['started_monotonic_ns']
assert execution['commands'][1]['finished_monotonic_ns']<=execution['finished_monotonic_ns']
assert run['started_monotonic_ns']<=run['finished_monotonic_ns']
assert not list(B.glob('attempt-*-failed-fresh'))
prep=load(B/'preparation-fresh.json')
assert prep['cache_initial_state']['previously_absent'] and prep['cache_initial_state']['initial_entries']==[]
assert prep['helpers']==preflight['helpers'] and prep['seed_record_sha256']==sha(B/'fresh-seeds.json')
summary=load(B/'fresh-message/summary.json');counts=summary['message']['counts']
assert summary['status']=='PASS' and summary['generated_messages']==10000000
assert counts==verify['message_counts']==expected['message_counts']
assert counts['messages']==counts['exact_matches']+counts['D001']
assert summary['direct_registers']['counts']==verify['direct_counts']=={'cases':101244,'exact_matches':101244}
assert (len(summary['message']['df']),len(summary['message']['adsb']),len(summary['message']['commb']))==(32,70,14)
assert not summary['message']['coverage_errors'] and not summary['message']['mismatch_fields']
assert summary['seed']==verify['message_seed']==seeds['message_seed']==expected['message_seed']
assert verify['commb_seed']==seeds['commb_seed']==expected['commb_seed']
assert seeds['recorded_utc']<execution['started_utc']
assert verify['retained_raw_artifact_count']==9 and len(verify['verified_artifacts'])==11
assert verify['retained_compressed_and_uncompressed_hashes_verified'] and verify['standalone_commb_gzip_snapshots_verified']
artifact_records={str(B/'fresh-message'/(name+'.gz')):row for name,row in summary['artifacts'].items()}
artifact_records.update({row['retained']:row for row in commb['artifacts'].values()})
assert set(artifact_records)==set(verify['verified_artifacts']) and len(artifact_records)==11
for path,row in artifact_records.items():
 verified=verify['verified_artifacts'][path]
 assert row['compressed_sha256']==verified['compressed_sha256'] and row['sha256']==verified['uncompressed_sha256'] and row['bytes']==verified['uncompressed_bytes']
for path,row in verify['verified_artifacts'].items():assert sha(path)==row['compressed_sha256']
assert len(retention['diagnostic_streams'])==3
for path,row in retention['diagnostic_streams'].items():assert sha(path)==row['compressed_sha256'] and row['rows']==row['expected_rows']
# Bind our independent proof/native review and successful integrated source records.
integration=load(I/'integration-review.json');native=load(B/'native-review/review.json');inspection=load(B/'native-review/inspection-inputs.json');proof=load(B/'native-review/source-proof-review.json')
independent_integration=load(B/'native-review/integration-proof-review.json')
assert sha(B/'native-review/source-proof-review.json')==expected['independent_proof_review_sha256']
assert sha(B/'native-review/integration-proof-review.json')==expected['independent_integration_review_sha256']==native['integration_proof_review_sha256']
assert independent_integration['status']=='passed' and not independent_integration['findings']
assert independent_integration['source_proof_review_sha256']==sha(B/'native-review/source-proof-review.json')
assert len(independent_integration['sources'])==3 and all(independent_integration['sources'][p]==d for p,d in proof['sources'].items())
assert independent_integration['integrated_build_sha256']==sha(B/'integration/targeted-build.json') and independent_integration['integrated_log_sha256']==sha(B/'integration/targeted-build.log')
assert independent_integration['integrated_allowed_axiom_facts']==136 and all(set(f['axioms'])<= {'propext','Classical.choice','Quot.sound'} for f in independent_integration['integrated_facts'])
assert sha(I/'integration-review.json')==expected['integration_review_sha256']
assert native['status']==proof['status']=='passed' and native['bds50_wind_penalty_live_path_verified']
assert native['findings']==proof['findings']==[] and all(native['checks'].values())
assert all(sha(B/'native-review'/p)==row['sha256'] for p,row in native['files'].items())
assert all(sha(p)==row['sha256'] for p,row in inspection['inputs'].items())
for path,digest in integration['final_source_sha256'].items():assert run['source_sha256_before'][path]==digest
for path,digest in independent_integration['sources'].items():assert run['source_sha256_before'][path]==digest
assert sha(B/'native-review/review.json')==expected['native_review_sha256']
assert sha(B/'native-review/inspection-inputs.json')==expected['native_inspection_sha256']
# Independently stream every retained gzip transcript and diagnostic stream.
unpacked={}
for path,row in verify['verified_artifacts'].items():
 h=hashlib.sha256();size=0
 with gzip.open(path,'rb') as source:
  for block in iter(lambda:source.read(4*1024*1024),b''):h.update(block);size+=len(block)
 assert h.hexdigest()==row['uncompressed_sha256'] and size==row['uncompressed_bytes'],path
 unpacked[path]={'sha256':h.hexdigest(),'bytes':size}
for path,row in commb['artifacts'].items():assert sha(path)==row['sha256']
streams={}
for path,row in retention['diagnostic_streams'].items():
 h=hashlib.sha256();size=lines=0
 with gzip.open(path,'rb') as source:
  for block in iter(lambda:source.read(4*1024*1024),b''):h.update(block);size+=len(block);lines+=block.count(b'\n')
 assert h.hexdigest()==row['decompressed_sha256'] and size==row['decompressed_bytes'] and lines==row['rows']==row['expected_rows'],path
 streams[path]={'sha256':h.hexdigest(),'bytes':size,'rows':lines}
# Preserve complete prior generation snapshots and all twenty-six old result rows.
history=load(I/'gen12-complete-history.json')
assert {str(p) for root in history['roots'] for p in Path(root).rglob('*') if p.is_file()}==set(history['files'])
for path,row in history['files'].items():assert sha(path)==row['sha256'] and Path(path).stat().st_size==row['bytes'],path
prefix=I/'results-prefix-before-gen13.csv'
assert sha(prefix)==load(I/'preparation.json')['result_prefix_sha256']
assert Path('bench/results.csv').read_bytes()==prefix.read_bytes()
assert len(list(csv.DictReader(io.StringIO(prefix.read_text()))))==26
out={'status':'passed_fresh_retention_and_source_binding','reviewed_utc':datetime.now(timezone.utc).isoformat(),'successful_retained_members':33,'failed_fresh_attempts':0,'unchanged_source_hashes':109,'unchanged_binary_hashes':3,'counts':counts,'direct_counts':verify['direct_counts'],'coverage':[32,70,14],'retention_sha256':sha(B/'fresh-retained-hashes.json'),'verifier_sha256':sha(B/'fresh-final-verification.json'),'execution_sha256':sha(B/'fresh-execution.json'),'review_bindings':{str(I/'integration-review.json'):sha(I/'integration-review.json'),str(B/'native-review/review.json'):sha(B/'native-review/review.json'),str(B/'native-review/source-proof-review.json'):sha(B/'native-review/source-proof-review.json')},'independently_decompressed_raw':unpacked,'independently_decompressed_diagnostic_streams':streams,'raw_transcripts':9,'standalone_snapshots':2,'extra_difference_streams':3,'gen12_complete_history_files_unchanged':len(history['files']),'prior_result_rows_unchanged':26,'script_sha256':sha(__file__),'findings':[],'limits':'Independent hash/membership/execution/source binding plus complete gzip decompression, raw SHA/size and diagnostic row recount. No decoder, build or campaign rerun; fixed gate/archive review remains separate.'}
p=R/'fresh-retention-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'members':33,'sources':109,'binaries':3,'counts':counts},indent=2))
