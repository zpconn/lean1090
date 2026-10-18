from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,subprocess,time
p=Path("tests/evidence/optimization/gen8/integration")
sha=lambda f:hashlib.sha256(Path(f).read_bytes()).hexdigest()
inputs=["Impl/PayloadBits.lean","Proofs/AffineValue.lean","Proofs/CommBTables.lean","Proofs/Decoder.lean"]
r={"command":["lake","build","Proofs.Decoder","lean1090","messageGenerator","commbDifferential"],"started_utc":datetime.now(timezone.utc).isoformat(),"started_monotonic_ns":time.monotonic_ns(),"inputs_before":{f:sha(f) for f in inputs}}
record=p/"targeted-build.json";log=p/"targeted-build.log"
assert not record.exists() and not log.exists()
record.write_text(json.dumps(r,indent=2)+"\n")
with log.open("w") as stream: result=subprocess.run(r["command"],stdout=stream,stderr=subprocess.STDOUT)
r.update(exit_code=result.returncode,finished_utc=datetime.now(timezone.utc).isoformat(),finished_monotonic_ns=time.monotonic_ns(),log_sha256=sha(log),inputs_after={f:sha(f) for f in inputs})
r["status"]="passed" if result.returncode==0 and r["inputs_before"]==r["inputs_after"] else "failed"
record.write_text(json.dumps(r,indent=2)+"\n");print(json.dumps(r,indent=2))
raise SystemExit(0 if r["status"]=="passed" else 1)
