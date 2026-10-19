#!/usr/bin/env python3
"""Complete reporting after successful strict cleanup; never execute cleanup."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json
B=Path('tests/evidence/optimization/gen24');R=B/'independent-review';Q=B/'fresh-message'
def sha(p):
 with Path(p).open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
load=lambda p:json.loads(Path(p).read_text())
now=lambda:datetime.now(timezone.utc).isoformat()
selected=Path('.cache/message-differential-bex6yqlv')
protected_paths=[Path('.cache/message-differential-zbrfml4s'),Path('.cache/reserved-velocity-proposal'),Path('.cache/gen15-interrupted-gate')]
assert not selected.exists() and all(p.is_dir() for p in protected_paths)
assert not (R/'fresh-completion.json').exists()
prep=load(B/'preparation.json');pre=load(B/'fresh-preflight.json')
assert sha(B/'finish_campaign.py')==prep['adaptations']['finish_campaign.py']['sha256']=='e9d5b6386cc3541d65248409470f3937b720f2d36b0599b2d60f6f789c1442aa'
failed=load(B/'finish-execution-01.json')
assert failed['status']=='failed' and failed['exit_code']==1
assert failed['log_sha256']==sha(B/'finish-controller-01.log')
assert "FileNotFoundError: [Errno 2] No such file or directory: 'tests/evidence/optimization/gen24/independent-review/comparison-replay-01.log'" in (B/'finish-controller-01.log').read_text()
execution=load(B/'fresh-execution.json');replay=load(R/'comparison-replay.json');independent=load(R/'fresh-retention-review.json');manifest=load(B/'fresh-retained-hashes.json');summary=load(Q/'summary.json');native=load(B/'native-review/native-inputs.json');native_review=load(B/'native-review/review.json')
assert all(x['status']=='passed' for x in [execution,replay,independent,manifest,native_review])
assert execution['exit_code']==0 and replay['temporary_duplicate_outputs_removed'] and not independent['findings'] and not native_review['findings']
assert native_review['commb_semantic_reuse_live_path_verified'] and native_review['linked_native_sets']==22
assert replay['message_counts']==summary['message']['counts'] and replay['direct_counts']==summary['direct_registers']['counts']
assert len(manifest['files'])==33 and replay['retention_manifest_sha256']==sha(B/'fresh-retained-hashes.json')==independent['bindings'][str(B/'fresh-retained-hashes.json')]
for p,row in manifest['files'].items():assert sha(p)==row['sha256'] and Path(p).stat().st_size==row['bytes'],p
for group in ['source_sha256','binary_sha256']:
 for p,h in pre[group].items():assert sha(p)==h,p
assert len(pre['source_sha256'])==127 and len(pre['binary_sha256'])==3 and len(pre['gate_inputs'])==202
for p,h in pre['gate_inputs'].items():assert sha(p)==h,p
for p,h in native['held_inputs'].items():assert sha(p)==h,p
assert sha('bench/results.csv')==prep['prior_csv_sha256']
cleanup=load(B/'post-fresh-cleanup/result.json')
assert cleanup['status']=='completed' and cleanup['mode']=='apply' and len(cleanup['results'])==1
row=cleanup['results'][0]
assert row['status']=='deleted' and row['directory']==str(selected) and len(row['files'])==8
expected={'direct-input.txt','direct-lean.jsonl','direct-oracle.jsonl','generated.tsv','input.hex','lean.jsonl','metadata.jsonl','oracle.jsonl'}
assert {f['name'] for f in row['files']}==expected
assert cleanup['deleted_allocated_bytes']==sum(f['identity']['allocated_bytes'] for f in row['files'])==5359480832
for f in row['files']:
 retained=f['retained'];p=Path(retained['path']);info=summary['artifacts'][f['name']]
 assert f['gzip_eof_verified'] and p==Q/(f['name']+'.gz') and not (selected/f['name']).exists()
 assert sha(p)==retained['compressed_sha256']==info['compressed_sha256']==manifest['files'][str(p)]['sha256']
 assert retained['raw_sha256']==f['sha256']==info['sha256'] and retained['raw_bytes']==f['identity']['bytes']==info['bytes']
 assert retained['seal']['sha256']==sha(B/'fresh-retained-hashes.json')
flush=B/'post-fresh-archive-flush.json';flushed=load(flush)
assert flushed['selected_scratch']==str(selected) and flushed['protected_scratch']==[str(p) for p in protected_paths]
assert flushed['manifest_sha256']==sha(B/'fresh-retained-hashes.json')
actual=R/'comparison-attempt-01'
replay_execution=load(actual/'execution.json')
assert replay_execution['exit_code']==0
assert sha(actual/'replay_comparison.py')==sha(R/'replay_comparison.py')
for name in ['stdout','stderr']:
 assert replay_execution[name+'_sha256']==sha(actual/(name+'.log'))
assert not (actual/'stderr.log').read_bytes()
cleanup_review_path=Path('tests/evidence/optimization/gen18/independent-review/cleanup-tooling-review.json')
cleanup_review=load(cleanup_review_path);assert cleanup_review['status']=='passed' and not cleanup_review['findings']
for p,h in cleanup_review['bindings'].items():assert sha(p)==h,p
paths=[cleanup_review_path,B/'fresh-final-verification.json',B/'fresh-retained-hashes.json',B/'fresh-execution.json',Q/'summary.json',R/'fresh-retention-review.json',R/'comparison-replay.json',R/'replay_comparison.py',actual/'start.json',actual/'execution.json',actual/'stdout.log',actual/'stderr.log',actual/'replay_comparison.py',B/'native-review/review.json',B/'native-review/native-inputs.json',flush,B/'post-fresh-cleanup/result.json',B/'post-fresh-cleanup/start.json',B/'post-fresh-cleanup.log',B/'controller-fresh.log',B/'finish_campaign.py',B/'finish-execution-01.json',B/'finish-controller-01.log',Path(__file__)]
out={'status':'passed','completed_utc':now(),'producer_first_execution_passed':True,'fresh_retention_first_review_passed':True,'comparison_replay_first_execution_passed':True,'message_seed':load(B/'fresh-seeds.json')['message_seed'],'commb_seed':load(B/'fresh-seeds.json')['commb_seed'],'source_count':pre['source_count'],'binary_count':3,'retained_members':33,'message_counts':summary['message']['counts'],'direct_counts':summary['direct_registers']['counts'],'full_coverage_reproduced':True,'decompressed_diagnostic_streams_reproduced':True,'source_and_binary_hashes_rechecked_after_cleanup':True,'native_held_inputs_rechecked':len(native['held_inputs']),'correctness_inputs_rechecked':len(pre['gate_inputs']),'prior_benchmark_rows_unchanged':prep['prior_csv_rows'],'raw_scratch_deleted':str(selected),'raw_files_deleted':8,'allocated_bytes_reclaimed':cleanup['deleted_allocated_bytes'],'fixed_gate_scratch_preserved':str(protected_paths[0]),'all_protected_roots_preserved':[str(p) for p in protected_paths],'bindings':{str(p):sha(p) for p in paths},'completion_reporting_correction':{'initial_finisher_exit_code':1,'cause':'After successful cleanup and post-cleanup checks, final receipt construction referenced obsolete comparison-replay-01.log instead of actual comparison-attempt-01 logs.','original_source_and_logs_preserved':True,'actual_replay_log':str(actual/'stdout.log'),'cleanup_executions':1,'producer_or_replay_rerun':False,'recovery_scope':'Recheck completed deletion receipt, all retained members, source/native/correctness bindings and protected roots; write completion only.'},'limitations':['Replay executes only frozen comparison functions on retained gzip transcripts; no decoder rerun or independent semantic specification.','Fixed-seed gate is separately recorded and its scratch is preserved for root archival.','Only eight exact duplicate fresh raw files were removed; compressed transcripts, differences, unique failures and fixed scratch remain.']}
with (R/'fresh-completion.json').open('x') as f:json.dump(out,f,indent=2);f.write('\n')
print(json.dumps({'status':'passed','completion_sha256':sha(R/'fresh-completion.json'),'allocated_bytes_reclaimed':cleanup['deleted_allocated_bytes'],'cleanup_sha256':sha(B/'post-fresh-cleanup/result.json')}))
