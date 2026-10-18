from pathlib import Path
import datetime,hashlib,json,subprocess,sys,time
p=Path('tests/evidence/optimization/gen7')
sha=lambda f:hashlib.sha256(Path(f).read_bytes()).hexdigest()
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()
r={'status':'running','started_utc':now(),'started_monotonic_ns':time.monotonic_ns(),'preflight_sha256':sha(p/'fresh-preflight.json'),'seed_record_sha256':sha(p/'fresh-seeds.json'),'orchestrator_sha256':sha(__file__),'commands':[]}
def write():(p/'fresh-execution.json').write_text(json.dumps(r,indent=2)+'\n')
write()
for helper,log in [('fresh-run-campaign.py','fresh-orchestration.log'),('fresh-verify.py','fresh-verification.log')]:
 item={'command':['python3',str(p/helper)],'helper_sha256':sha(p/helper),'started_utc':now(),'started_monotonic_ns':time.monotonic_ns(),'log':str(p/log)}
 r['commands'].append(item);write()
 with (p/log).open('w') as stream:result=subprocess.run(item['command'],stdout=stream,stderr=subprocess.STDOUT)
 item.update(exit_code=result.returncode,finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),log_sha256=sha(p/log),helper_sha256_after=sha(p/helper))
 write()
 if result.returncode or item['helper_sha256']!=item['helper_sha256_after']:
  r.update(status='failed',finished_utc=now(),exit_code=result.returncode or 1);write();sys.exit(r['exit_code'])
assert sha(p/'fresh-seeds.json')==r['seed_record_sha256']
r.update(status='passed',finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),exit_code=0,verification_sha256=sha(p/'fresh-final-verification.json'));write();print(json.dumps(r,indent=2))
