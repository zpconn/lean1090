"""Independent completion-only recovery review; do not repeat cleanup."""
import sys
sys.dont_write_bytecode=True
import ast,json,hashlib
from pathlib import Path
from datetime import datetime,timezone
B=Path('tests/evidence/optimization/gen24');R=B/'independent-review';checks=[];bindings={}
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 actual=sha(p);assert h is None or actual==h,str(p);bindings[str(p)]=actual;return actual
source=B/'complete_after_cleanup.py';bind(source,'e0bdef6a7363f9bec2bdcb422b223bdd3f9a97d276ceb85c8c60e64fd4210199');s=source.read_text();tree=ast.parse(s)
imports=[n.names[0].name.split('.')[0] for n in ast.walk(tree) if isinstance(n,ast.Import)]+[n.module.split('.')[0] for n in ast.walk(tree) if isinstance(n,ast.ImportFrom)]
check(set(imports)<= {'sys','pathlib','datetime','hashlib','json'},'Recovery imports no process/workload/deletion tool')
calls=[ast.unparse(n.func) for n in ast.walk(tree) if isinstance(n,ast.Call)]
check(not any(any(x in name for x in ['unlink','rmtree','rmdir','subprocess','exec','eval']) for name in calls),'Recovery contains no native invocation, code execution or deletion call')
opens=[n for n in ast.walk(tree) if isinstance(n,ast.Call) and isinstance(n.func,ast.Attribute) and n.func.attr=='open']
check(len(opens)==2 and {ast.literal_eval(n.args[0]) for n in opens}=={'rb','x'},'Only read-open and exclusive new completion write')
completion=load(R/'fresh-completion.json');bind(R/'fresh-completion.json','da713cf8be524ce2ecea8b42aac115c6edc22126f43b20aacaed372cf0799717')
for p,h in completion['bindings'].items():bind(p,h)
failed=load(B/'finish-execution-01.json');old=(B/'finish_campaign.py').read_text();log=(B/'finish-controller-01.log').read_text()
check(failed['exit_code']==1 and failed['status']=='failed' and failed['helper_sha256']==sha(B/'finish_campaign.py'),'Original failed finisher source/execution preserved')
check(failed['log_sha256']==sha(B/'finish-controller-01.log') and "FileNotFoundError: [Errno 2] No such file or directory: 'tests/evidence/optimization/gen24/independent-review/comparison-replay-01.log'" in log,'Failure confined to obsolete final replay-log binding')
check(old.index('subprocess.run(cmd')<old.index("paths=[cleanup_review_path")<old.index("out={'status':'passed'"),'Original cleanup and checks precede failed completion construction')
cleanup=load(B/'post-fresh-cleanup/result.json');start=load(B/'post-fresh-cleanup/start.json');retention=load(R/'fresh-retention-review.json');replay=load(R/'comparison-replay.json')
check(cleanup['status']=='completed' and cleanup['mode']=='apply' and len(cleanup['results'])==1,'One completed strict fresh cleanup receipt')
check(cleanup['finished_utc']<failed['finished_utc']<completion['completed_utc'],'Cleanup completed before original reporting failure and later recovery')
check(start['scratch']==['.cache/message-differential-bex6yqlv'] and start['protected']==['.cache/message-differential-zbrfml4s','.cache/reserved-velocity-proposal','.cache/gen15-interrupted-gate'],'Exact selected root and all three required protections')
row=cleanup['results'][0]
check(row['status']=='deleted' and not Path(row['directory']).exists() and len(row['files'])==8,'Only eight selected raw duplicates removed')
for file in row['files']:
 kept=file['retained'];prior=retention['raw_and_standalone_decompressed'][kept['path']]
 check(file['gzip_eof_verified'] and file['sha256']==kept['raw_sha256']==prior['sha256'] and file['identity']['bytes']==kept['raw_bytes']==prior['bytes'],'Independent prior byte equality '+file['name'])
check(sum(f['identity']['allocated_bytes'] for f in row['files'])==cleanup['deleted_allocated_bytes']==completion['allocated_bytes_reclaimed']==5359480832,'Exact allocated byte total')
execution=load(R/'comparison-attempt-01/execution.json');bind(B/'completion-recovery-01.log')
printed=json.loads((B/'completion-recovery-01.log').read_text())
check(printed['status']=='passed' and printed['completion_sha256']==sha(R/'fresh-completion.json') and printed['cleanup_sha256']==sha(B/'post-fresh-cleanup/result.json'),'Completed recovery log binds exact final records')
check(execution['status']=='passed' and execution['exit_code']==0 and execution['stdout_sha256']==sha(R/'comparison-attempt-01/stdout.log') and execution['stderr_sha256']==sha(R/'comparison-attempt-01/stderr.log'),'Actual first replay attempt/logs bound')
check(completion['message_counts']==replay['message_counts']==retention['message_counts'] and completion['direct_counts']==replay['direct_counts'],'No counts/classifications changed by recovery')
check(completion['source_count']==127 and completion['correctness_inputs_rechecked']==202 and completion['native_held_inputs_rechecked']==274 and completion['retained_members']==33,'Complete source/native/retention recheck scope preserved')
fix=completion['completion_reporting_correction'];check(fix['cleanup_executions']==1 and not fix['producer_or_replay_rerun'] and fix['original_source_and_logs_preserved'],'Recovery explicitly discloses one cleanup and no producer/replay rerun')
check(completion['producer_first_execution_passed'] and completion['fresh_retention_first_review_passed'] and completion['comparison_replay_first_execution_passed'],'First-pass claims refer to actual passed producer/reviews, separately disclosing finisher reporting failure')
for name in ['.cache/reserved-velocity-proposal','.cache/gen15-interrupted-gate']:check(Path(name).is_dir(),'Unique historical evidence remains '+name)
out=R/'fresh-recovery-review.json';assert not out.exists();out.write_text(json.dumps(dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,reviewer_sha256=sha(__file__),no_cleanup_or_workload_executed=True,limitations=['The later separately authorized fixed cleanup can remove its own completed zbrfml4s root; fresh protection is established at fresh execution, not asserted after fixed cleanup.','Complete retained compressed bytes and source/native rehash are included again in the consolidated gate review, without repeating producers or comparisons.']),indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),sha256=sha(out))))
