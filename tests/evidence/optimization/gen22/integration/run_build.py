import sys
sys.dont_write_bytecode = True
import json, hashlib, subprocess, os
from pathlib import Path
from datetime import datetime, timezone
os.environ['PYTHONDONTWRITEBYTECODE'] = '1'
root = Path.cwd()
base = root / 'tests/evidence/optimization/gen22/integration'
number = 1
while (base / f'attempt-{number:02d}').exists(): number += 1
out = base / f'attempt-{number:02d}'
out.mkdir()
paths = ['Impl/Frame.lean', 'Impl/Message.lean', 'Proofs/FrameWord.lean', 'Proofs/RawSyndromeSpec.lean', 'Proofs/SyndromeReuse.lean', 'Proofs/Decoder.lean', 'spec.lock']
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
before = {p: sha(root/p) for p in paths}
for p in paths:
 dest=out/p;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((root/p).read_bytes())
command = ['lake', 'build', 'Proofs.SyndromeReuse', 'Proofs.Decoder']
record = {'status':'running', 'started_utc': datetime.now(timezone.utc).isoformat(), 'command':command, 'before':before, 'runner_sha256':sha(Path(__file__))}
record_path=out/'execution.json'
record_path.write_text(json.dumps(record,indent=2)+'\n')
with (out/'build.log').open('x') as stream:
 result=subprocess.run(command,stdout=stream,stderr=subprocess.STDOUT,cwd=root)
after={p:sha(root/p) for p in paths}
record.update(status='passed' if result.returncode==0 and after==before else 'failed', exit_code=result.returncode, finished_utc=datetime.now(timezone.utc).isoformat(), after=after, inputs_unchanged=after==before, log_sha256=sha(out/'build.log'))
record_path.write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'attempt':number, 'status':record['status'], 'log':str((out/'build.log').relative_to(root)), 'sha256':sha(record_path)}),flush=True)
assert after==before
sys.exit(result.returncode)
