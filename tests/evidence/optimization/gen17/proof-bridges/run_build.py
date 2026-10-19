#!/usr/bin/env python3
"""Retain each proof-only bridge build, including failed source snapshots."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import argparse, hashlib, json, os, subprocess, time

p=argparse.ArgumentParser();p.add_argument('attempt',type=int);a=p.parse_args()
base=Path(__file__).resolve().parent
out=base/f'attempt-{a.attempt:02d}';out.mkdir()
paths=['Impl/Binary64.lean','Proofs/Binary64Runtime.lean','Proofs/Decoder.lean',
       'Proofs/BDS50.lean','Proofs/CommBMach.lean','Proofs/CommBQNH.lean',
       'Proofs/CommBRatio.lean','Proofs/CommBPenalty.lean']
sha=lambda path:hashlib.sha256(Path(path).read_bytes()).hexdigest()
before={name:sha(name) for name in paths}
for name in paths:
    target=out/name;target.parent.mkdir(parents=True,exist_ok=True)
    target.write_bytes(Path(name).read_bytes())
command=['lake','build','Proofs.Decoder','Proofs.BDS50']
r={'status':'running','started_utc':datetime.now(timezone.utc).isoformat(),
   'started_monotonic_ns':time.monotonic_ns(),'command':command,'sources_before':before,
   'runner_sha256':sha(__file__),'spec_lock_sha256':sha('spec.lock')}
(out/'record.json').write_text(json.dumps(r,indent=2)+'\n')
with (out/'build.log').open('x') as log:
    result=subprocess.run(command,stdout=log,stderr=subprocess.STDOUT,
                          env={**os.environ,'PYTHONDONTWRITEBYTECODE':'1'})
r.update(exit_code=result.returncode,finished_utc=datetime.now(timezone.utc).isoformat(),
         finished_monotonic_ns=time.monotonic_ns(),sources_after={name:sha(name) for name in paths},
         log_sha256=sha(out/'build.log'))
r['sources_unchanged']=r['sources_after']==before
r['status']='passed' if result.returncode==0 and r['sources_unchanged'] else 'failed'
assert sha('spec.lock')==r['spec_lock_sha256']
(out/'record.json').write_text(json.dumps(r,indent=2)+'\n')
print(json.dumps({'status':r['status'],'exit_code':result.returncode,'record':str(out/'record.json'),
                  'log_sha256':r['log_sha256']}),flush=True)
sys.exit(result.returncode if result.returncode else int(not r['sources_unchanged']))
