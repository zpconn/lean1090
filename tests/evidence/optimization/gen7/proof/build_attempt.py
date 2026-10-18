from pathlib import Path
import datetime,hashlib,json,subprocess,time,sys
p=Path('tests/evidence/optimization/gen7/proof');p.mkdir(parents=True,exist_ok=True)
n=1
while (p/f'build-{n:02}-start.json').exists():n+=1
sha=lambda f:hashlib.sha256(Path(f).read_bytes()).hexdigest()
files=['Impl/ScoreGate.lean','Proofs/ScoreGateInteger.lean']
r={'started_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'started_monotonic_ns':time.monotonic_ns(),'command':['lake','build','Proofs.ScoreGateInteger'],'source_sha256':{f:sha(f) for f in files}}
(p/f'build-{n:02}-start.json').write_text(json.dumps(r,indent=2)+'\n')
with (p/f'build-{n:02}.log').open('w') as log:x=subprocess.run(r['command'],stdout=log,stderr=subprocess.STDOUT)
r.update(finished_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),finished_monotonic_ns=time.monotonic_ns(),exit_code=x.returncode,log_sha256=sha(p/f'build-{n:02}.log'),source_sha256_after={f:sha(f) for f in files})
(p/f'build-{n:02}-result.json').write_text(json.dumps(r,indent=2)+'\n');print('attempt',n,'exit',x.returncode);print((p/f'build-{n:02}.log').read_text());sys.exit(x.returncode)
