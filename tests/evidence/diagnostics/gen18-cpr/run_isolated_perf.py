import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,os,shutil,subprocess,csv
os.environ['PYTHONDONTWRITEBYTECODE']='1';os.environ['GIT_OPTIONAL_LOCKS']='0'
root=Path.cwd();worker=root/'.lake/build/bin/lean1090-bench';perf=root/'.cache/profiling-tools/bin/perf'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
head='9c2745732de1626418b77b468069b12ab8a1e5c1';timed='c19e00dd6bd45c89e4d6238d4ea9973947625449';expected='60f7c3a9b63468db3d65565e59760eba1f10f58b5cc2fc69ee2c6dc283eebe4d'
binding_path=root/'tests/evidence/diagnostics/gen18/benchmark-source-binding.json';binding=json.loads(binding_path.read_text())
assert sha(binding_path)=='44afab5ef807aba9f5626407478f5a120255b1ef3e64493419f73de1965e5188'
assert binding['diagnostic_commit']==head and binding['timed_original_commit']==timed and binding['status']=='passed'
assert subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()==head
buildpath=root/'bench/runs/gen18/binary-built.json';freshpath=root/'bench/runs/gen18/fresh-native-inputs.json'
build=json.loads(buildpath.read_text());fresh=json.loads(freshpath.read_text());assert build['commit']==timed and build['sha256']==sha(worker)==expected and len(fresh)==22
for row in fresh:
 p=root/row['source'];assert sha(p)==row['source_sha256']
 assert subprocess.check_output(['git','show',head+':'+row['source']])==p.read_bytes()
 for n,v in row['artifacts'].items():assert sha(root/n)==v['sha256']==build['native_hashes'][n]
for n,h in binding['all_audited_lean_sources'].items():assert sha(root/n)==h
for p,h in [('.cache/gen18-costs/driver/driver-build.json','1e35d1b96b9e1d5ac730d9fe789ff18d0050d21f3dfb176fc8077b9efc94b35a'),('.cache/gen18-cpr-costs/driver-final/driver-build.json','0899a2841fad5e4a2c752ddf6300a6f9b8c1ada2dde438dd1431f93a7723bf9e')]:assert sha(root/p)==h
review_path=root/'bench/runs/gen18/results-review.json';review=json.loads(review_path.read_text());assert review['status']=='passed' and not review['findings'] and review['commit']==timed and review['binary_sha256']==expected
correctness_path=root/'bench/runs/gen18/correctness-inputs.json';correctness=json.loads(correctness_path.read_text());assert len(correctness)==190
for name,digest in correctness.items():assert sha(root/name)==digest
paths={review_path,correctness_path,Path(__file__).resolve(),worker,root/'spec.lock',buildpath,freshpath,binding_path,root/'vendor/rs1090/crates/rs1090/data/long_flight.csv',root/'vendor/rs1090/crates/rs1090/data/airports.json'}
paths.update(root/n for n in build['native_hashes']);paths.update(root/n for n in binding['all_audited_lean_sources']);paths.update(root/n for n in correctness)
for name in ['.cache/gen18-costs/driver/driver-build.json','.cache/gen18-cpr-costs/driver-final/driver-build.json']:
 p=root/name;driver=json.loads(p.read_text());assert driver['status']=='passed';paths.add(p)
 for group in ['unchanged_native_inputs','artifacts']:
  for name,digest in driver[group].items():assert sha(root/name)==digest;paths.add(root/name)
def snapshot():return {str(p.relative_to(root)):sha(p) for p in sorted(paths)}
initial=snapshot();results=[]
for mode in ['decode','cpr']:
 out=root/('tests/evidence/diagnostics/gen18/perf' if mode=='decode' else 'tests/evidence/diagnostics/gen18-cpr/perf')
 cache=root/('.cache/gen18-costs/perf-gen18' if mode=='decode' else '.cache/gen18-cpr-costs/perf-gen18-cpr')
 assert not out.exists() and not cache.exists(), 'Retain earlier perf attempt; refuse overwrite'
 out.mkdir(parents=True);cache.mkdir(parents=True)
 before=snapshot();assert before==initial
 saved=root/'.cache/gen18-costs/perf-gen18/lean1090-bench'
 if mode=='decode':assert not saved.exists();shutil.copyfile(worker,saved)
 assert sha(saved)==expected
 readiness={'status':'authorized','authorizer':'/root','authorization':'Both diagnostic builds completed; root approved sequential isolated actual-worker decode then CPR captures. All other agents hold native/build/profile jobs.','driver_builds':[{'path':p,'sha256':sha(root/p)} for p in ['.cache/gen18-costs/driver/driver-build.json','.cache/gen18-cpr-costs/driver-final/driver-build.json']],'diagnostic_commit':head,'timed_commit':timed,'mode':mode}
 (out/'readiness.json').write_text(json.dumps(readiness,indent=2)+'\n')
 cmd=[str(perf),'record','--no-buildid-cache','-o',str(cache/'perf.data'),'-e','cpu-clock:u','-F','199','--call-graph','dwarf,16384','--','taskset','-c','0',str(worker),'--worker-'+mode,str(root/'vendor/rs1090/crates/rs1090/data/long_flight.csv')]
 record={'classification':'One-pass native diagnostic sampling; not a benchmark or throughput measurement','mode':mode,'started_utc':datetime.now(timezone.utc).isoformat(),'before_hashes':before,'git_head':head,'timed_commit':timed,'fresh_gen18_binding':{'linked_project_objects':22,'build_record':str(buildpath.relative_to(root)),'build_record_sha256':sha(buildpath),'fresh_native_record':str(freshpath.relative_to(root)),'fresh_native_record_sha256':sha(freshpath),'source_equivalence':str(binding_path.relative_to(root)),'source_equivalence_sha256':sha(binding_path)},'helper_source_sha256':sha(Path(__file__)),'readiness':readiness,'preserved_binary':{'path':str(saved.relative_to(root)),'sha256':sha(saved)},'command':cmd,'stdin':'run\nquit\n','affinity_requested':[0],'affinity_available':sorted(os.sched_getaffinity(0)),'concurrent_work_note':'Both diagnostic builds completed. All other native, build and profiler jobs held. Lightweight prose-only work allowed. No benchmark measurement claimed.'}
 (out/'capture-start.json').write_text(json.dumps(record,indent=2)+'\n')
 print('starting '+mode,flush=True)
 with (out/'worker-stdout.txt').open('w') as stdout,(out/'record-stderr.txt').open('w') as stderr:r=subprocess.run(cmd,input='run\nquit\n',text=True,stdout=stdout,stderr=stderr,cwd=root)
 record.update(record_exit_code=r.returncode,completed_utc=datetime.now(timezone.utc).isoformat(),worker_stdout=(out/'worker-stdout.txt').read_text(),after_hashes=snapshot(),raw_data={'path':str((cache/'perf.data').relative_to(root)),'sha256':sha(cache/'perf.data'),'bytes':(cache/'perf.data').stat().st_size})
 record['all_input_hashes_unchanged']=record['after_hashes']==before
 (out/'capture.json').write_text(json.dumps(record,indent=2)+'\n')
 assert r.returncode==0 and record['all_input_hashes_unchanged']
 lines=record['worker_stdout'].splitlines();assert len(lines)==2 and lines[0]=='ready 172432'
 parts=lines[1].split();assert len(parts)==2 and int(parts[0])>0
 expected_positions={row['positions'] for row in csv.DictReader((root/f'bench/runs/gen18/{mode}/samples.csv').open()) if row['implementation']=='lean1090'}
 assert expected_positions=={parts[1]}
 for name,args in [('script.txt',['script','-i',str(cache/'perf.data')]),('report-self.txt',['report','-i',str(cache/'perf.data'),'--stdio','--no-children','--sort','symbol','--percent-limit','0']),('report-children.txt',['report','-i',str(cache/'perf.data'),'--stdio','--children','--sort','symbol','--percent-limit','0'])]:
  with (out/name).open('w') as stdout,(out/(name+'.stderr')).open('w') as stderr:q=subprocess.run([str(perf),*args],stdout=stdout,stderr=stderr,cwd=root)
  assert q.returncode==0
 results.append({'mode':mode,'capture':str((out/'capture.json').relative_to(root)),'capture_sha256':sha(out/'capture.json'),'raw':record['raw_data'],'positions':int(parts[1]),'inputs_unchanged':True})
 print('completed '+mode,flush=True)
summary={'status':'passed','finished_utc':datetime.now(timezone.utc).isoformat(),'sequential_modes':['decode','cpr'],'results':results,'protected_inputs':len(initial),'correctness_inputs':190,'benchmark_review_sha256':sha(review_path),'all_jobs_stopped':True}
p=root/'tests/evidence/diagnostics/gen18-cpr/isolated-perf-completion.json';p.write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary),flush=True)
