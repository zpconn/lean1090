#!/usr/bin/env python3
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,subprocess
E=Path('tests/evidence/optimization/gen22/raw-syndrome')
S=Path('Proofs/RawSyndromeSpec.lean')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,v):
 with p.open('x') as f:f.write(json.dumps(v,indent=2)+'\n')
n=1
while (E/f'attempt-{n:02d}').exists():n+=1
A=E/f'attempt-{n:02d}';A.mkdir()
(A/S.name).write_bytes(S.read_bytes())
command=['lake','build','Proofs.RawSyndromeSpec']
record={'status':'running','started_utc':datetime.now(timezone.utc).isoformat(),'command':command,'source':str(S),'source_before_sha256':sha(S),'spec_lock_before_sha256':sha('spec.lock')}
save(A/'command.json',record)
with (A/'build.log').open('xb') as log:r=subprocess.run(command,stdout=log,stderr=subprocess.STDOUT)
record.update(status='passed' if r.returncode==0 else 'failed',exit_code=r.returncode,completed_utc=datetime.now(timezone.utc).isoformat(),source_after_sha256=sha(S),spec_lock_after_sha256=sha('spec.lock'),log_sha256=sha(A/'build.log'))
assert record['source_before_sha256']==record['source_after_sha256']
assert record['spec_lock_before_sha256']==record['spec_lock_after_sha256']
save(A/'result.json',record)
print(json.dumps(record));sys.exit(r.returncode)
