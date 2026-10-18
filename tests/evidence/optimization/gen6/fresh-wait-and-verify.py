from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,subprocess,sys,time
P=Path('tests/evidence/optimization/gen6')
now=lambda:datetime.now(timezone.utc).isoformat()
record={'status':'waiting_for_existing_campaign','started_utc':now(),'campaign_session':68537,'command':['python3','.cache/gen6-gate/fresh-verify.py'],'watcher_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}
output=P/'fresh-verifier-run.json'
def save():output.write_text(json.dumps(record,indent=2)+'\n')
save()
while True:
 p=P/'fresh-message-run.json'
 if p.exists():
  run=json.loads(p.read_text())
  if run['status']!='running':break
 q=P/'fresh-commb-run.json'
 if q.exists() and json.loads(q.read_text())['status']=='failed':
  record.update(status='upstream_failed',finished_utc=now());save();sys.exit(1)
 time.sleep(5)
record.update(status='verifying',verification_started_utc=now(),campaign_status=run['status']);save()
if run['status']!='passed':
 record.update(status='upstream_failed',finished_utc=now());save();sys.exit(1)
with (P/'fresh-verification.log').open('w') as stream:
 r=subprocess.run(record['command'],stdout=stream,stderr=subprocess.STDOUT)
record.update(status='passed' if r.returncode==0 else 'failed',exit_code=r.returncode,finished_utc=now(),log_sha256=hashlib.sha256((P/'fresh-verification.log').read_bytes()).hexdigest());save()
print(json.dumps(record,indent=2));sys.exit(r.returncode)
