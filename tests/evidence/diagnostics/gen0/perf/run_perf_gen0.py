from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,os,shutil,subprocess,time
root=Path.cwd();out=root/'tests/evidence/diagnostics/gen0/perf';cache=root/'.cache/gen1-planning/perf-gen0';worker=root/'.lake/build/bin/lean1090-bench';perf=root/'.cache/profiling-tools/bin/perf'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def snapshot():
 paths=[worker,root/'Bench/WholeDecoder.lean',root/'Impl.lean',root/'spec.lock',root/'.lake/build/ir/Bench/WholeDecoder.c',root/'vendor/rs1090/crates/rs1090/data/long_flight.csv']
 paths+=sorted((root/'Impl').glob('*.lean'))
 paths+=sorted((root/'.lake/build/ir/Impl').glob('*.c.o.export'))
 return {str(p.relative_to(root)):sha(p) for p in paths}
metadata={'classification':'one-pass native diagnostic sampling; not a benchmark or throughput measurement','started_utc':datetime.now(timezone.utc).isoformat(),'before_hashes':snapshot(),'git_head':subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),'git_status':subprocess.check_output(['git','status','--porcelain=v1','--untracked-files=no'],text=True),'concurrent_work_note':'Root allowed a possible small diagnostic-driver compilation; no benchmark isolation claim.','affinity_requested':[0],'affinity_available':sorted(os.sched_getaffinity(0))}
# Preserve the unmodified image for reproducible later symbol lookup; never execute the copy.
saved=cache/'lean1090-bench';shutil.copyfile(worker,saved);metadata['preserved_binary']={'path':str(saved.relative_to(root)),'sha256':sha(saved)}
command=[str(perf),'record','--no-buildid-cache','-o',str(cache/'perf.data'),'-e','cpu-clock:u','-F','199','--call-graph','dwarf,16384','--','taskset','-c','0',str(worker),'--worker-decode',str(root/'vendor/rs1090/crates/rs1090/data/long_flight.csv')]
metadata['command']=command;metadata['stdin']='run\nquit\n';(out/'capture-start.json').write_text(json.dumps(metadata,indent=2)+'\n')
with (out/'worker-stdout.txt').open('w') as stdout,(out/'record-stderr.txt').open('w') as stderr:
 p=subprocess.run(command,input='run\nquit\n',text=True,cwd=root,stdout=stdout,stderr=stderr,check=False)
metadata['record_exit_code']=p.returncode
metadata['completed_utc']=datetime.now(timezone.utc).isoformat();metadata['after_hashes']=snapshot();metadata['all_input_hashes_unchanged']=metadata['before_hashes']==metadata['after_hashes'];metadata['raw_data']={'path':str((cache/'perf.data').relative_to(root)),'sha256':sha(cache/'perf.data'),'bytes':(cache/'perf.data').stat().st_size}
(out/'capture.json').write_text(json.dumps(metadata,indent=2)+'\n')
assert p.returncode==0
assert metadata['all_input_hashes_unchanged']
for name,args in [('script.txt',['script','-i',str(cache/'perf.data')]),('report-self.txt',['report','-i',str(cache/'perf.data'),'--stdio','--no-children','--sort','symbol','--percent-limit','0']),('report-children.txt',['report','-i',str(cache/'perf.data'),'--stdio','--children','--sort','symbol','--percent-limit','0'])]:
 with (out/name).open('w') as stdout,(out/(name+'.stderr')).open('w') as stderr:
  r=subprocess.run([str(perf),*args],cwd=root,stdout=stdout,stderr=stderr,check=False)
 assert r.returncode==0,(name,r.returncode)
print(json.dumps({'record_exit_code':p.returncode,'all_input_hashes_unchanged':metadata['all_input_hashes_unchanged'],'raw_data':metadata['raw_data'],'output':str(out.relative_to(root))}))
