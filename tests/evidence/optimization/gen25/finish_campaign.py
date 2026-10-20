#!/usr/bin/env python3
"""Seal successful replays and invoke bounded cleanup only for this fresh scratch."""
import sys,os
sys.dont_write_bytecode=True
os.environ['PYTHONDONTWRITEBYTECODE']='1'
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,subprocess
G=Path('tests/evidence/optimization/gen25');B=G;R=B/'independent-review';Q=B/'fresh-message'
sha=lambda p:hashlib.file_digest(Path(p).open('rb'),'sha256').hexdigest()
load=lambda p:json.loads(Path(p).read_text())
now=lambda:datetime.now(timezone.utc).isoformat()
assert len(sys.argv)>=3, 'Pass exact completed fresh scratch, active fixed scratch, and other protected roots.'
selected=Path(sys.argv[1]);protected_paths=[Path(p) for p in sys.argv[2:]];protected=protected_paths[0]
assert len(set(protected_paths))==len(protected_paths) and all(p.is_dir() for p in protected_paths)
assert selected.is_dir() and protected.is_dir() and selected!=protected
assert not (B/'post-fresh-cleanup').exists() and not (R/'fresh-completion.json').exists()
execution=load(B/'fresh-execution.json');replay=load(R/'comparison-replay.json');independent=load(R/'fresh-retention-review.json');manifest=load(B/'fresh-retained-hashes.json');pre=load(B/'fresh-preflight.json');summary=load(Q/'summary.json');native=load(G/'native-review/native-inputs.json');prep=load(B/'preparation.json')
native_review=load(G/'native-review/review.json')
assert native_review['status']=='passed' and not native_review['findings']
assert native_review['score_scaling_identity_live_path_verified'] and native_review['linked_native_sets']==22
assert all(x['status']=='passed' for x in [execution,replay,independent,manifest])
assert execution['exit_code']==0 and replay['temporary_duplicate_outputs_removed'] and not independent['findings']
# Bind the completed generic reviewer execution and both logs before any unlink.
replay_run=load(R/'comparison-attempt-01/execution.json')
assert replay_run['status']=='passed' and replay_run['exit_code']==0
assert replay_run['script']==str(R/'replay_comparison.py')
assert replay_run['script_sha256']==sha(R/'replay_comparison.py')
assert replay_run['stdout_sha256']==sha(R/'comparison-attempt-01/stdout.log')==sha(R/'comparison-replay.json')
assert replay_run['stderr_sha256']==sha(R/'comparison-attempt-01/stderr.log')
assert len(manifest['files'])==33 and replay['retention_manifest_sha256']==sha(B/'fresh-retained-hashes.json')==independent['bindings'][str(B/'fresh-retained-hashes.json')]
assert str(selected.resolve()) in (Q/'commands.log').read_text()
assert str(protected.resolve()) in (G/'gate-full.log').read_text()
for p,row in manifest['files'].items():assert sha(p)==row['sha256'] and Path(p).stat().st_size==row['bytes']
for group in ['source_sha256','binary_sha256']:
 for p,h in pre[group].items():assert sha(p)==h
for p,h in native['held_inputs'].items():assert sha(p)==h
assert sha('bench/results.csv')==prep['prior_csv_sha256']
cleanup_review_path=Path('tests/evidence/optimization/gen18/independent-review/cleanup-tooling-review.json')
cleanup_review=load(cleanup_review_path)
assert cleanup_review['status']=='passed' and not cleanup_review['findings']
for p,h in cleanup_review['bindings'].items():assert sha(p)==h,p
helper=Path('review/diagnostics/cleanup_verified_scratch.py');assert sha(helper)=='cb115045f0743cce197d1d9af1d66678dd76a9a96b1babb5eca4d3d519dc31ce'
# Force complete retained file allocation before the existing strict identity guards.
for p in [Path(x) for x in manifest['files']]+[B/'fresh-retained-hashes.json']:
 with p.open('rb') as f:os.fsync(f.fileno())
for p in [Q,B,B.parent,R]:
 fd=os.open(p,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
record={'status':'passed','recorded_utc':now(),'selected_scratch':str(selected),'protected_scratch':[str(p) for p in protected_paths],'selected_producers_stopped':True,'basis':'Fresh controller passed and wrote final retained seal; frozen comparison-only replay completed successfully; independent retention reviewer reports all jobs stopped. Root confirmed active fixed scratch separately.','manifest_sha256':sha(B/'fresh-retained-hashes.json'),'producer_execution_sha256':sha(B/'fresh-execution.json'),'comparison_replay_sha256':sha(R/'comparison-replay.json'),'independent_retention_sha256':sha(R/'fresh-retention-review.json'),'cleanup_helper_sha256':sha(helper),'cleanup_tooling_review_sha256':sha(cleanup_review_path),'flushed_files':{p:row['sha256'] for p,row in manifest['files'].items() if Path(p).parent==Q},'ordering':'Retained archive files and parent directories synchronized before strict cleanup inventories identities. No retained bytes changed.','selection':'Only the exact fresh scratch is selected; old proposal/interrupted archives and every other scratch path are outside selection.'}
flush=B/'post-fresh-archive-flush.json';assert not flush.exists();flush.write_text(json.dumps(record,indent=2)+'\n')
with flush.open('rb') as f:os.fsync(f.fileno())
fd=os.open(B,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
cmd=['python3','-B',str(helper),'--scratch',str(selected),'--archive-root',str(Q),*[arg for p in protected_paths for arg in ['--protect',str(p)]],'--receipt',str(B/'post-fresh-cleanup'),'--apply','--quiescent']
with (B/'post-fresh-cleanup.log').open('x') as f:run=subprocess.run(cmd,stdout=f,stderr=subprocess.STDOUT)
assert run.returncode==0
cleanup=load(B/'post-fresh-cleanup/result.json');assert cleanup['status']=='completed' and cleanup['mode']=='apply' and len(cleanup['results'])==1
row=cleanup['results'][0];assert row['status']=='deleted' and len(row['files'])==8
assert not selected.exists() and all(p.is_dir() for p in protected_paths)
for p,info in manifest['files'].items():assert sha(p)==info['sha256'] and Path(p).stat().st_size==info['bytes']
for group in ['source_sha256','binary_sha256']:
 for p,h in pre[group].items():assert sha(p)==h
for p,h in native['held_inputs'].items():assert sha(p)==h
assert sha('bench/results.csv')==prep['prior_csv_sha256']
paths=[cleanup_review_path,B/'fresh-final-verification.json',B/'fresh-retained-hashes.json',B/'fresh-execution.json',Q/'summary.json',R/'fresh-retention-review.json',R/'comparison-replay.json',R/'replay_comparison.py',R/'comparison-attempt-01/execution.json',R/'comparison-attempt-01/stdout.log',R/'comparison-attempt-01/stderr.log',G/'native-review/review.json',G/'native-review/native-inputs.json',flush,B/'post-fresh-cleanup/result.json',B/'post-fresh-cleanup/start.json',B/'post-fresh-cleanup.log',B/'controller-fresh.log',Path(__file__)]
out={'status':'passed','completed_utc':now(),'producer_first_execution_passed':True,'fresh_retention_first_review_passed':True,'comparison_replay_first_execution_passed':True,'message_seed':load(B/'fresh-seeds.json')['message_seed'],'commb_seed':load(B/'fresh-seeds.json')['commb_seed'],'source_count':pre['source_count'],'binary_count':3,'retained_members':33,'message_counts':summary['message']['counts'],'direct_counts':summary['direct_registers']['counts'],'full_coverage_reproduced':True,'decompressed_diagnostic_streams_reproduced':True,'source_and_binary_hashes_rechecked_after_cleanup':True,'native_held_inputs_rechecked':len(native['held_inputs']),'prior_benchmark_rows_unchanged':prep['prior_csv_rows'],'raw_scratch_deleted':str(selected),'raw_files_deleted':8,'allocated_bytes_reclaimed':cleanup['deleted_allocated_bytes'],'fixed_gate_scratch_preserved':str(protected),'all_protected_roots_preserved':[str(p) for p in protected_paths],'bindings':{str(p):sha(p) for p in paths},'limitations':['Replay executes only frozen comparison functions on retained gzip transcripts; no decoder rerun or independent semantic specification.','Fixed-seed full gate remains separate and active; no passing fixed gate is claimed here.','Only eight exact duplicate fresh raw scratch files were removed; compressed transcripts, differences, unique failures and active fixed scratch remain.']}
p=R/'fresh-completion.json';p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':'passed','completion_sha256':sha(p),'allocated_bytes_reclaimed':cleanup['deleted_allocated_bytes'],'cleanup_sha256':sha(B/'post-fresh-cleanup/result.json')}))
