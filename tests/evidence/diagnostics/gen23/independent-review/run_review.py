#!/usr/bin/env python3
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,os,subprocess
script=Path(sys.argv[1]);phase=sys.argv[2];number=int(sys.argv[3]);folder=script.parent/f'{phase}-attempt-{number:02d}'
folder.mkdir(exist_ok=False)
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
(folder/script.name).write_bytes(script.read_bytes())
start={'script':str(script),'script_sha256':sha(script),'argv':[sys.executable,'-B',str(script)],'started_utc':datetime.now(timezone.utc).isoformat()}
(folder/'start.json').write_text(json.dumps(start,indent=2)+'\n')
with (folder/'stdout.log').open('w') as out,(folder/'stderr.log').open('w') as err:
 proc=subprocess.run(start['argv'],stdout=out,stderr=err,env=dict(os.environ,PYTHONDONTWRITEBYTECODE='1'))
result={**start,'completed_utc':datetime.now(timezone.utc).isoformat(),'exit_code':proc.returncode,'status':'passed' if proc.returncode==0 else 'failed','stdout_sha256':sha(folder/'stdout.log'),'stderr_sha256':sha(folder/'stderr.log')}
(folder/'execution.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2));print((folder/'stderr.log').read_text());sys.exit(proc.returncode)
