from datetime import datetime, timezone
import hashlib, importlib.util, json, subprocess
from pathlib import Path
import sys
sys.dont_write_bytecode=True
root=Path.cwd()
path=root/'review/diagnostics/run_generation_benchmark.py'
spec=importlib.util.spec_from_file_location('benchmark_provenance',path)
module=importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
out=root/'tests/evidence/optimization/gen20'
assert not (out/'gate-evidence.json').exists() and not (out/'gate-full.log').exists()
record={'schema':1,'status':'running','command':['scripts/check_all.sh','--full'],'generated_messages':10000000,
        'started_at':datetime.now(timezone.utc).isoformat(),'input_hashes_before':module.gate_input_hashes()}
(out/'gate-evidence.json').write_text(json.dumps(record,indent=2)+'\n')
with (out/'gate-full.log').open('w') as stream:
    result=subprocess.run(record['command'],stdout=stream,stderr=subprocess.STDOUT)
record.update(exit_code=result.returncode,finished_at=datetime.now(timezone.utc).isoformat(),
              input_hashes_after=module.gate_input_hashes(),
              gate_log_sha256=hashlib.sha256((out/'gate-full.log').read_bytes()).hexdigest())
record['input_hashes_equal']=record['input_hashes_before']==record['input_hashes_after']
record['status']='passed' if result.returncode==0 and record['input_hashes_equal'] else 'failed'
(out/'gate-evidence.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'status':record['status'],'exit_code':result.returncode,'inputs_equal':record['input_hashes_equal']}),flush=True)
raise SystemExit(0 if record['status']=='passed' else 1)
