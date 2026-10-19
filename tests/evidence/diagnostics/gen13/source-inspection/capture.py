"""Read-only timed-worker disassembly capture after explicit perf completion."""
from pathlib import Path
import json,hashlib,subprocess,sys
sys.dont_write_bytecode=True
D=Path(__file__).parent;P='lp_lean1090_Lean1090_Impl_';worker='.lake/build/bin/lean1090-bench'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
build=json.loads(Path('.cache/gen13-costs/driver/driver-build.json').read_text())
held={**build['unchanged_native_inputs'],**build['production_sources']}
for p,h in held.items():assert sha(p)==h,p
assert sha(worker)==json.loads(Path('bench/runs/gen13/summary.json').read_text())['binary_sha256']
commands=json.loads(Path('tests/evidence/diagnostics/gen12/source-inspection/inspection-commands.json').read_text())
for command in commands:command['output']=str(D/Path(command['output']).name)
extra=[P+'cbWindPenalty50',P+'cbWindPenaltyTable___lam__0','_init_'+P+'cbWindPenaltyTable___closed__1']
for symbol in extra:
 output=str(D/(symbol+'.assembly.txt'))
 if not any(c['output']==output for c in commands):commands.append({'argv':['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,worker],'output':output})
assert len({c['output'] for c in commands})==len(commands)
for command in commands:
 p=Path(command['output']);assert not p.exists()
 r=subprocess.run(command['argv'],capture_output=True);assert r.returncode==0 and not r.stderr
 p.write_bytes(r.stdout);command['sha256']=sha(p);command['exit_code']=r.returncode
symbols=D/'symbols.txt';assert not symbols.exists()
r=subprocess.run(['nm','-g','--defined-only',worker],capture_output=True);assert r.returncode==0 and not r.stderr;symbols.write_bytes(r.stdout)
(D/'inspection-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
for p,h in held.items():assert sha(p)==h,p
print(json.dumps({'status':'captured','commands':len(commands),'worker_sha256':sha(worker),'held_inputs_unchanged':len(held),'script_sha256':sha(__file__)},indent=2))
