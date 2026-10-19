#!/usr/bin/env python3
"""Execute the prepared diagnostic probe once against held built dependencies."""
import sys
sys.dont_write_bytecode=True
import os
os.environ['PYTHONDONTWRITEBYTECODE']='1'
from pathlib import Path
from datetime import datetime,timezone
import hashlib,importlib.util,json,subprocess,time
R=Path.cwd();P=R/'tests/evidence/optimization/gen18/runtime-review/probe';A=P/'attempt-01'
def sha(p):
 with Path(p).open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def load(p):return json.loads(Path(p).read_text())
assert not A.exists();A.mkdir()
source=R/'review/diagnostics/Gen18FloatProbe.lean';m=load(P/'inputs.json')
assert sha(source)==m['probe_source_sha256'] and sha(R/m['raw_path'])==m['raw_sha256']
build=load(R/'tests/evidence/optimization/gen18/integration/targeted-build.json');assert build['status']=='passed' and build['exit_code']==0
spec=importlib.util.spec_from_file_location('probe_gate_inputs',R/'review/diagnostics/run_generation_benchmark.py');module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
held=module.gate_input_hashes();assert held==build['all_inputs_after'] and len(held)==190
held.update({'.lake/build/bin/'+name:digest for name,digest in build['binary_hashes'].items()})
for name,digest in held.items():assert sha(R/name)==digest,name
(A/'probe.lean').write_bytes(source.read_bytes())
argv=['lake','env','lean','--run',str(source.relative_to(R)),m['raw_path'],str((A/'failures.jsonl').relative_to(R))]
r={'status':'running','command':argv,'started_utc':datetime.now(timezone.utc).isoformat(),'started_monotonic_ns':time.monotonic_ns(),'source_sha256':sha(source),'inputs_manifest_sha256':sha(P/'inputs.json'),'integration_sha256':sha(R/'tests/evidence/optimization/gen18/integration/targeted-build.json'),'held_inputs_before':held,'runner_sha256':sha(__file__)}
def save():(A/'execution.json').write_text(json.dumps(r,indent=2)+'\n')
save()
with (A/'stdout.log').open('x') as out,(A/'stderr.log').open('x') as err:result=subprocess.run(argv,cwd=R,stdout=out,stderr=err)
after={n:sha(R/n) for n in held};r.update(exit_code=result.returncode,finished_utc=datetime.now(timezone.utc).isoformat(),finished_monotonic_ns=time.monotonic_ns(),held_inputs_after=after,held_inputs_unchanged=after==held,stdout_sha256=sha(A/'stdout.log'),stderr_sha256=sha(A/'stderr.log'))
r['status']='passed' if result.returncode==0 and after==held else 'failed';save();assert r['status']=='passed'
summary=json.loads((A/'stdout.log').read_text().splitlines()[-1]);assert summary['status']=='passed' and summary['mismatches']==0
assert summary['cases']==m['cases'] and summary['finite_bit_checks']==m['finite_bit_checks']
for name in ['zero','fast','fallback']:assert summary[name+'_cases']==m['expected_branches'][name]
assert (A/'failures.jsonl').read_bytes()==b''
record={'status':'passed','recorded_utc':datetime.now(timezone.utc).isoformat(),'first_probe_execution_passed':True,'summary':summary,'input_manifest_sha256':sha(P/'inputs.json'),'source_sha256':sha(source),'execution_sha256':sha(A/'execution.json'),'all_held_inputs_unchanged':True,'held_input_count':len(held),'files':{str(p.relative_to(R)):sha(p) for p in sorted(A.iterdir()) if p.is_file()},'limitations':'Boundary and seeded bit checks supplement the unconditional kernel proof; no timing or corpus fast-path population claim.'}
assert not (P/'completion.json').exists();(P/'completion.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':'passed','cases':summary['cases'],'completion_sha256':sha(P/'completion.json')}))
