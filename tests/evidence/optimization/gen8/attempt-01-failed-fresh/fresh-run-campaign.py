from pathlib import Path
import json,hashlib,datetime,subprocess,gzip,sys,time
P=Path('tests/evidence/optimization/gen8'); ROOT=Path.cwd()
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
S=json.loads((P/'fresh-seeds.json').read_text())
names=set(json.loads(Path('tests/evidence/optimization/gen7/fresh-message-run.json').read_text())['source_sha256_before'])
for directory in ['Impl','Model','Spec','Proofs','CLI','Tests']:
 names.update(str(p) for p in Path(directory).rglob('*.lean'))
names.update(['lakefile.toml','lake-manifest.json','lean-toolchain','Capstones.lean'])
source_hashes=lambda:{p:sha(p) for p in sorted(names)}
BINS=['.lake/build/bin/lean1090','.lake/build/bin/messageGenerator','.lake/build/bin/commbDifferential']
binary_hashes=lambda:{p:sha(p) for p in BINS}
def write(name,data):(P/name).write_text(json.dumps(data,indent=2)+'\n')
def command(argv,log):
 item={'argv':argv,'started_utc':now(),'started_monotonic_ns':time.monotonic_ns()}
 with (P/log).open('w') as stream:r=subprocess.run(argv,stdout=stream,stderr=subprocess.STDOUT)
 item.update(finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),exit_code=r.returncode,log=log)
 return item
record={'stage':'fresh_commb_generation_and_coverage','status':'running','commands':[],'started_utc':now(),'seed_record_sha256':sha(P/'fresh-seeds.json'),'source_sha256':source_hashes(),'binary_sha256_before':binary_hashes()}
write('fresh-commb-run.json',record)
for argv,log in zip(S['commands'][:2],['fresh-commb-generate.log','fresh-commb-check.log']):
 item=command(argv,log);record['commands'].append(item);write('fresh-commb-run.json',record)
 if item['exit_code']:
  record.update(status='failed',finished_utc=now());write('fresh-commb-run.json',record);sys.exit(item['exit_code'])
record['artifacts']={}
for name in ['fresh-commb.csv','fresh-commb.csv.coverage.csv']:
 src=Path('.cache/gen8-gate')/name;dst=P/(name+'.gz');data=src.read_bytes()
 with dst.open('wb') as stream:
  with gzip.GzipFile(fileobj=stream,mode='wb',filename='',mtime=0) as out:out.write(data)
 record['artifacts'][str(src)]={'sha256':sha(src),'bytes':len(data),'retained':str(dst),'compressed_sha256':sha(dst)}
record.update(source_sha256_after=source_hashes(),binary_sha256_after=binary_hashes(),finished_utc=now())
assert record['source_sha256']==record['source_sha256_after'];assert record['binary_sha256_before']==record['binary_sha256_after']
record['status']='passed';write('fresh-commb-run.json',record)
print(json.dumps({'stage':'fresh_commb','status':'passed','coverage':str(P/'fresh-commb-coverage.json')}),flush=True)
argv=S['commands'][2]
run={'stage':'gen8_fresh_direct_10m_milestone','status':'running','started_utc':now(),'started_monotonic_ns':time.monotonic_ns(),'argv':argv,'seed_record_sha256':sha(P/'fresh-seeds.json'),'fresh_commb_csv_sha256':sha('.cache/gen8-gate/fresh-commb.csv'),'build_authorization':'Parent explicitly signaled integrated targeted build passed and sources stable, authorizing native campaign without extra builds.','source_sha256_before':source_hashes(),'binary_sha256_before':binary_hashes()}
write('fresh-message-run.json',run)
item=command(argv,'fresh-message.log');run.update(finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),exit_code=item['exit_code'],source_sha256_after=source_hashes(),binary_sha256_after=binary_hashes())
run['source_hashes_unchanged']=run['source_sha256_before']==run['source_sha256_after'];run['binary_hashes_unchanged']=run['binary_sha256_before']==run['binary_sha256_after']
summary=P/'fresh-message/summary.json'
if summary.exists():run['summary_sha256']=sha(summary);run['summary_status']=json.loads(summary.read_text()).get('status')
run['status']='passed' if item['exit_code']==0 and run['source_hashes_unchanged'] and run['binary_hashes_unchanged'] else 'failed'
write('fresh-message-run.json',run);print(json.dumps({k:v for k,v in run.items() if k not in ['source_sha256_before','source_sha256_after','binary_sha256_before','binary_sha256_after']},indent=2),flush=True)
sys.exit(0 if run['status']=='passed' else 1)
