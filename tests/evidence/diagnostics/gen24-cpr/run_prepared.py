#!/usr/bin/env python3
"""Prepared CPR diagnostic only; execute after parent release and artifact commit.

Uses the unchanged reviewed live-stream driver, validator and Callgrind protocol.
Build replaces only the frozen worker object. Collection requires both completed
isolated actual-worker perf captures. No throughput claim or cleanup occurs here.
"""
import sys
sys.dont_write_bytecode=True
import argparse,hashlib,importlib.util,json,os,subprocess,time,traceback
from pathlib import Path
from datetime import datetime,timezone
ROOT=Path(__file__).resolve().parents[4]
E=ROOT/'tests/evidence/diagnostics/gen24-cpr';C=ROOT/'.cache/gen24-cpr-costs';B=ROOT/'bench/runs/gen24'
os.environ['PYTHONDONTWRITEBYTECODE']='1';os.environ['GIT_OPTIONAL_LOCKS']='0'
def sha(p):
 with Path(p).open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def read(p):return json.loads(Path(p).read_text())
def rel(p):return str(p.relative_to(ROOT))
def now():return datetime.now(timezone.utc).isoformat()
def verify(hashes):
 for name,digest in hashes.items():assert sha(ROOT/name)==digest,name

def guard():
 plan=read(E/'preparation.json')
 for name,digest in plan['helpers'].items():assert sha(ROOT/name)==digest,name
 spec=importlib.util.spec_from_file_location('gen24_decode_preflight',ROOT/'tests/evidence/diagnostics/gen24/run_prepared.py')
 module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
 summary=module.guard()  # Reviewed benchmark, six clean checks, full inputs/native/lock binding.
 assert summary['generation']==24
 assert summary['commit']==plan['benchmark_bindings']['timed_commit']
 assert summary['binary_sha256']==plan['benchmark_bindings']['worker_sha256']
 assert sha(B/'summary.json')==plan['benchmark_bindings']['summary_sha256']
 assert sha(B/'results-review.json')==plan['benchmark_bindings']['result_review_sha256']
 correctness=read(B/'correctness-inputs.json')
 assert len(correctness)==202
 assert {'Proofs/ParityByteBits.lean','Proofs/FoldBlocks.lean','Proofs/ParityByte.lean','Proofs/FrameWord.lean','Proofs/RawSyndromeSpec.lean','Proofs/CommBValidity40.lean','Proofs/CommBValidity50.lean','Proofs/CommBValidity60.lean','Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean','Impl/CommB.lean','Impl/Semantics.lean'} <= set(correctness)
 head=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()
 assert head!=summary['commit'],'Await the reviewed artifact commit after timing.'
 built=read(B/'binary-built.json');fresh=read(B/'fresh-native-inputs.json')
 assert len(fresh)==built['project_c_objects_regenerated']==22
 for row in fresh:
  assert sha(ROOT/row['source'])==row['source_sha256']
  for name,item in row['artifacts'].items():assert sha(ROOT/name)==item['sha256']==built['native_hashes'][name]
 held=dict(read(B/'correctness-inputs.json'));held.update(built['native_hashes'])
 held['.lake/build/bin/lean1090-bench']=summary['binary_sha256']
 for p in [B/'results-review.json',B/'summary.json',B/'binary-built.json',B/'fresh-native-inputs.json',ROOT/'vendor/rs1090/crates/rs1090/data/long_flight.csv',ROOT/'vendor/rs1090/crates/rs1090/data/airports.json']:
  held[rel(p)]=sha(p)
 verify(held)
 return summary,head,held

def verify_build():
 p=C/'driver-final/driver-build.json';build=read(p)
 assert build['status']=='passed' and build['lock_sha256']==sha(ROOT/'spec.lock')
 assert build['fresh_benchmark_native_binding']['path']=='bench/runs/gen24/fresh-native-inputs.json'
 verify(build['unchanged_native_inputs']);verify(build['artifacts'])
 return build

def require_perf(summary):
 p=E/'isolated-perf-completion.json';done=read(p)
 assert done['status']=='passed' and done['all_jobs_stopped']
 assert done['sequential_modes']==['decode','cpr'] and [r['mode'] for r in done['results']]==['decode','cpr']
 for row in done['results']:
  path=ROOT/row['capture'];capture=read(path)
  assert sha(path)==row['capture_sha256'] and row['inputs_unchanged']
  assert capture['record_exit_code']==0 and capture['all_input_hashes_unchanged']
  assert capture['before_hashes']==capture['after_hashes']
  assert capture['before_hashes']['.lake/build/bin/lean1090-bench']==summary['binary_sha256']
  verify(capture['before_hashes'])
  assert sha(ROOT/row['raw']['path'])==row['raw']['sha256']
 return sha(p)

def execute(argv,label):
 path=E/(label+'-command.json');assert not path.exists(),'Preserve earlier attempts; do not overwrite.'
 row={'argv':argv,'started_utc':now(),'started_monotonic_ns':time.monotonic_ns()}
 path.write_text(json.dumps(row,indent=2)+'\n')
 with (E/(label+'.stdout')).open('x') as out,(E/(label+'.stderr')).open('x') as err:
  result=subprocess.run(argv,cwd=ROOT,stdout=out,stderr=err)
 row.update(exit_code=result.returncode,finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),stdout_sha256=sha(E/(label+'.stdout')),stderr_sha256=sha(E/(label+'.stderr')))
 path.write_text(json.dumps(row,indent=2)+'\n');assert result.returncode==0,(label,result.returncode)
 return row

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('phase',choices=['build','collect']);p.add_argument('--execute',action='store_true');p.add_argument('--artifact-commit',help='Exact published artifact commit supplied by root');args=p.parse_args();os.chdir(ROOT)
 summary,head,held=guard();perf=None
 if args.execute:assert args.artifact_commit==head, 'Root must supply the exact published artifact commit before execution.'
 elif args.artifact_commit is not None:assert args.artifact_commit==head
 if args.phase=='build':
  assert not (C/'driver-final').exists(),'Retain previous driver attempt.'
  commands=[([sys.executable,'-B','review/diagnostics/build_cpr_costs.py','--output',rel(C/'driver-final'),'--fresh-native-inputs',rel(B/'fresh-native-inputs.json')],'driver-build')]
 else:
  build=verify_build();assert read(ROOT/'.cache/gen24-costs/driver/driver-build.json')['status']=='passed'
  perf=require_perf(summary)
  assert not (C/'validation').exists() and not (C/'callgrind').exists(),'Retain previous native/profile attempt.'
  commands=[([sys.executable,'-B','review/diagnostics/validate_cpr_costs.py','--build',rel(C/'driver-final/driver-build.json'),'--output',rel(C/'validation')],'native-validation'),([sys.executable,'-B','review/diagnostics/profile_cpr_costs.py','all','--binary',rel(C/'driver-final/cpr-costs'),'--output',rel(C/'callgrind')],'callgrind')]
 print(json.dumps({'status':'guarded_not_executed' if not args.execute else 'authorized_execution_requested','phase':args.phase,'timed_commit':summary['commit'],'artifact_commit':head,'commands':commands}),flush=True)
 if not args.execute:return
 record=E/(args.phase+'-execution.json');assert not record.exists()
 result={'status':'running','phase':args.phase,'started_utc':now(),'timed_commit':summary['commit'],'artifact_commit':head,'worker_sha256':summary['binary_sha256'],'benchmark_review_sha256':sha(B/'results-review.json'),'before_hashes':held,'perf_completion_sha256':perf,'controller_sha256':sha(__file__),'decode_controller_sha256':sha(ROOT/'tests/evidence/diagnostics/gen24/run_prepared.py'),'commands':[]}
 def save():record.write_text(json.dumps(result,indent=2)+'\n')
 save()
 try:
  for argv,label in commands:result['commands'].append(execute(argv,label));verify(held);save()
  build=verify_build()
  if args.phase=='collect':
   v=read(C/'validation/summary.json');r=read(C/'callgrind/run.json')
   assert v['status']==r['status']=='passed' and v['complete_batch_StreamState_and_routed_positions_equal']
   assert v['result']['batch_state_check'] is True and r['result']['batch_state_check'] is False
   assert {k:x for k,x in v['result'].items() if k!='batch_state_check'}=={k:x for k,x in r['result'].items() if k!='batch_state_check'}
   assert r['result']['digest']['count']==v['tracking_rows']==172432
   result.update(primary_profile_sha256=r['profile_files'][r['primary_profile']],primary_ir=r['primary_ir'],validation_sha256=sha(C/'validation/summary.json'),profile_record_sha256=sha(C/'callgrind/run.json'))
  verify(held);result.update(status='passed',finished_utc=now(),after_hashes=held,all_inputs_unchanged=True,build_manifest_sha256=sha(C/'driver-final/driver-build.json'));save()
 except BaseException as error:
  result.update(status='failed',finished_utc=now(),error=repr(error),traceback=traceback.format_exc());save();raise
 print(json.dumps({'status':'passed','phase':args.phase,'record':rel(record),'sha256':sha(record)}))
if __name__=='__main__':main()
