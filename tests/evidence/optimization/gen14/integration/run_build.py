from datetime import datetime, timezone
import hashlib, json, subprocess, time
from pathlib import Path
out=Path(__file__).resolve().parent
sources=['Impl/CommB.lean','Proofs/CommBRatio.lean','Proofs/Decoder.lean']
def hashes():
    return {name:hashlib.sha256(Path(name).read_bytes()).hexdigest() for name in sources}
assert not (out/'targeted-build.json').exists()
record={'command':['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential'],
        'started_utc':datetime.now(timezone.utc).isoformat(),'started_monotonic_ns':time.monotonic_ns(),
        'inputs_before':hashes()}
for name in sources:
    target=out/'sources'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(Path(name).read_bytes())
(out/'targeted-build.json').write_text(json.dumps(record,indent=2)+'\n')
with (out/'targeted-build.log').open('w') as log:
    run=subprocess.run(record['command'],stdout=log,stderr=subprocess.STDOUT)
record.update(exit_code=run.returncode,finished_utc=datetime.now(timezone.utc).isoformat(),
    finished_monotonic_ns=time.monotonic_ns(),inputs_after=hashes(),
    log_sha256=hashlib.sha256((out/'targeted-build.log').read_bytes()).hexdigest())
record['status']='passed' if run.returncode==0 and record['inputs_before']==record['inputs_after'] else 'failed'
(out/'targeted-build.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({key:record[key] for key in ('status','exit_code','log_sha256')}),flush=True)
raise SystemExit(0 if record['status']=='passed' else 1)
