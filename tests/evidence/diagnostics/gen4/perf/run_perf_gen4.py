from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,os,shutil,subprocess,time
root=Path.cwd();out=root/'tests/evidence/diagnostics/gen4/perf';cache=root/'.cache/gen5-planning/perf-gen4';worker=root/'.lake/build/bin/lean1090-bench';perf=root/'.cache/profiling-tools/bin/perf'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
build_record=root/'bench/runs/gen4/binary-built.json'
fresh_record=root/'bench/runs/gen4/fresh-native-inputs.json'
build=json.loads(build_record.read_text());fresh=json.loads(fresh_record.read_text())
expected_commit='275329a2efd269dc44e549e4b6538d36277aaa3f'
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip()==expected_commit
assert build['commit']==expected_commit and build['sha256']=='adec5d1a48a77a241c5d5bb526155910e94796a0d5526280870ae7e36beb8f57'
assert len(fresh)==build['project_c_objects_regenerated']==22
for record in fresh:
 source=root/record['source'];data=source.read_bytes()
 assert hashlib.sha256(data).hexdigest()==record['source_sha256']
 assert subprocess.check_output(['git','show',expected_commit+':'+record['source']],cwd=root)==data
 for name,artifact in record['artifacts'].items():assert sha(root/name)==artifact['sha256']==build['native_hashes'][name]
for name,digest in build['native_hashes'].items():assert sha(root/name)==digest
def snapshot():
 paths={worker,root/'Bench/WholeDecoder.lean',root/'Impl.lean',root/'spec.lock',root/'vendor/rs1090/crates/rs1090/data/long_flight.csv',build_record,fresh_record}
 paths.update(root/name for name in build['native_hashes'])
 paths.update(root/record['source'] for record in fresh)
 paths.update((root/'Impl').glob('*.lean'))
 return {str(p.relative_to(root)):sha(p) for p in sorted(paths)}
metadata={'classification':'one-pass native diagnostic sampling; not a benchmark or throughput measurement','started_utc':datetime.now(timezone.utc).isoformat(),'before_hashes':snapshot(),'git_head':subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),'git_status':subprocess.check_output(['git','status','--porcelain=v1','--untracked-files=no'],text=True),'concurrent_work_note':'All compilation completed; Callgrind/native diagnostics held pending this capture. Other agents may read timing evidence or prepare orchestration. This remains a one-pass diagnostic, not a benchmark isolation claim.','affinity_requested':[0],'affinity_available':sorted(os.sched_getaffinity(0))}
metadata['fresh_gen4_binding']={'commit':expected_commit,'binary_sha256':build['sha256'],'linked_project_objects':len(fresh),'build_record':str(build_record.relative_to(root)),'build_record_sha256':sha(build_record),'fresh_native_record':str(fresh_record.relative_to(root)),'fresh_native_record_sha256':sha(fresh_record),'all_native_and_source_hashes_verified':True}
metadata['helper_source_sha256']=sha(Path(__file__))
# Preserve the unmodified image for reproducible later symbol lookup; never execute the copy.
saved=cache/'lean1090-bench';shutil.copyfile(worker,saved);metadata['preserved_binary']={'path':str(saved.relative_to(root)),'sha256':sha(saved)}
command=[str(perf),'record','--no-buildid-cache','-o',str(cache/'perf.data'),'-e','cpu-clock:u','-F','199','--call-graph','dwarf,16384','--','taskset','-c','0',str(worker),'--worker-decode',str(root/'vendor/rs1090/crates/rs1090/data/long_flight.csv')]
metadata['command']=command;metadata['stdin']='run\nquit\n';(out/'capture-start.json').write_text(json.dumps(metadata,indent=2)+'\n')
with (out/'worker-stdout.txt').open('w') as stdout,(out/'record-stderr.txt').open('w') as stderr:
 p=subprocess.run(command,input='run\nquit\n',text=True,cwd=root,stdout=stdout,stderr=stderr,check=False)
metadata['record_exit_code']=p.returncode
metadata['worker_stdout']=(out/'worker-stdout.txt').read_text()
metadata['completed_utc']=datetime.now(timezone.utc).isoformat();metadata['after_hashes']=snapshot();metadata['all_input_hashes_unchanged']=metadata['before_hashes']==metadata['after_hashes'];metadata['raw_data']={'path':str((cache/'perf.data').relative_to(root)),'sha256':sha(cache/'perf.data'),'bytes':(cache/'perf.data').stat().st_size}
(out/'capture.json').write_text(json.dumps(metadata,indent=2)+'\n')
assert p.returncode==0
lines=metadata['worker_stdout'].splitlines();assert len(lines)==2 and lines[0]=='ready 172432' and len(lines[1].split())==2 and int(lines[1].split()[0])>0 and lines[1].split()[1]=='0'
assert metadata['all_input_hashes_unchanged']
for name,args in [('script.txt',['script','-i',str(cache/'perf.data')]),('report-self.txt',['report','-i',str(cache/'perf.data'),'--stdio','--no-children','--sort','symbol','--percent-limit','0']),('report-children.txt',['report','-i',str(cache/'perf.data'),'--stdio','--children','--sort','symbol','--percent-limit','0'])]:
 with (out/name).open('w') as stdout,(out/(name+'.stderr')).open('w') as stderr:
  r=subprocess.run([str(perf),*args],cwd=root,stdout=stdout,stderr=stderr,check=False)
 assert r.returncode==0,(name,r.returncode)
print(json.dumps({'record_exit_code':p.returncode,'all_input_hashes_unchanged':metadata['all_input_hashes_unchanged'],'raw_data':metadata['raw_data'],'output':str(out.relative_to(root))}))
