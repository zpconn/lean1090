"""Read-only timed-worker disassembly capture after explicit perf completion."""
from pathlib import Path
import json,hashlib,subprocess
D=Path(__file__).parent;P='lp_lean1090_Lean1090_Impl_';worker='.lake/build/bin/lean1090-bench'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
build=json.loads(Path('.cache/gen9-planning/driver/driver-build.json').read_text())
held={**build['unchanged_native_inputs'],**build['production_sources']}
for p,h in held.items():assert sha(p)==h,p
assert sha(worker)=='da5ebfa685b052a3b534001fc2a1d4ead02995e40f2ea077e6f8d6328b4dde31'
commands=json.loads(Path('tests/evidence/diagnostics/gen7/source-inspection/inspection-commands.json').read_text())
for command in commands:command['output']=str(D/Path(command['output']).name)
for name in [P+'payloadValue',P+'affineValue',P+'Semantics_adsb',P+'Semantics_commB','lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0']:
 commands.append({'argv':['objdump','-d','--no-show-raw-insn','--disassemble='+name,worker],'output':str(D/(name+'.assembly.txt'))})
commands.append({'argv':['objdump','-dr','--no-show-raw-insn','--disassemble='+P+'affineValue','.lake/build/ir/Impl/PayloadBits.c.o.export'],'output':str(D/'object-affineValue.assembly.txt')})
for command in commands:
 p=Path(command['output']);assert not p.exists()
 r=subprocess.run(command['argv'],capture_output=True);assert r.returncode==0 and not r.stderr
 p.write_bytes(r.stdout);command['sha256']=sha(p);command['exit_code']=r.returncode
symbols=D/'symbols.txt';assert not symbols.exists()
r=subprocess.run(['nm','-g','--defined-only',worker],capture_output=True);assert r.returncode==0 and not r.stderr;symbols.write_bytes(r.stdout)
(D/'inspection-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
for p,h in held.items():assert sha(p)==h,p
print(json.dumps({'status':'captured','commands':len(commands),'worker_sha256':sha(worker),'held_inputs_unchanged':len(held),'script_sha256':sha(__file__)},indent=2))
