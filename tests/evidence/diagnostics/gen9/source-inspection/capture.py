"""Read-only timed-worker disassembly capture after explicit perf completion."""
from pathlib import Path
import json,hashlib,subprocess
D=Path(__file__).parent;P='lp_lean1090_Lean1090_Impl_';worker='.lake/build/bin/lean1090-bench'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
build=json.loads(Path('.cache/gen10-planning/driver/driver-build.json').read_text())
held={**build['unchanged_native_inputs'],**build['production_sources']}
for p,h in held.items():assert sha(p)==h,p
assert sha(worker)=='48dff3c83eebe85eaf857b3ce0c04e3b03e29a57cdb518f5c3d451532e16eccd'
commands=json.loads(Path('tests/evidence/diagnostics/gen8/source-inspection/inspection-commands.json').read_text())
for command in commands:command['output']=str(D/Path(command['output']).name)
for name in [P+x for x in ['field','decodeFrame','readACAS','readSurveillance','bytesValue','packFields']]:
 commands.append({'argv':['objdump','-d','--no-show-raw-insn','--disassemble='+name,worker],'output':str(D/(name+'.assembly.txt'))})
commands.append({'argv':['objdump','-dr','--no-show-raw-insn','--disassemble='+P+'field','.lake/build/ir/Impl/Bits.c.o.export'],'output':str(D/'object-field.assembly.txt')})
for command in commands:
 p=Path(command['output']);assert not p.exists()
 r=subprocess.run(command['argv'],capture_output=True);assert r.returncode==0 and not r.stderr
 p.write_bytes(r.stdout);command['sha256']=sha(p);command['exit_code']=r.returncode
symbols=D/'symbols.txt';assert not symbols.exists()
r=subprocess.run(['nm','-g','--defined-only',worker],capture_output=True);assert r.returncode==0 and not r.stderr;symbols.write_bytes(r.stdout)
(D/'inspection-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
for p,h in held.items():assert sha(p)==h,p
print(json.dumps({'status':'captured','commands':len(commands),'worker_sha256':sha(worker),'held_inputs_unchanged':len(held),'script_sha256':sha(__file__)},indent=2))
