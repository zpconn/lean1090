"""Capture only the remaining actual report map caller, without mutation/build."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen24/native-review'); O=R/'native-inspection'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
c=json.loads((R/'native-inputs.json').read_text())
for p,h in c['held_inputs'].items():assert sha(p)==h,p
symbol='lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0'
p=Path('.lake/build/ir/Impl/Message.c');text=p.read_text();lines=text.splitlines()
m=re.search(r'^LEAN_EXPORT lean_object\* '+re.escape(symbol)+r'\([^\n]*\)\{',text,re.M);assert m
start=text[:m.start()].count('\n');depth=0
for end in range(start,len(lines)):
 depth+=lines[end].count('{')-lines[end].count('}')
 if depth==0:break
cp=O/'report-map-caller.c.txt';assert not cp.exists();cp.write_text('\n'.join(f'{i+1}: {lines[i]}' for i in range(start,end+1))+'\n')
argv=['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,c['worker']]
r=subprocess.run(argv,capture_output=True,text=True);assert r.returncode==0 and not r.stderr and '<'+symbol+'>:' in r.stdout
ap=O/'report-map-caller.asm.txt';assert not ap.exists();ap.write_text(r.stdout)
for p,h in c['held_inputs'].items():assert sha(p)==h,p
record=dict(status='captured_read_only',symbol=symbol,parent_capture_sha256=sha(R/'native-inputs.json'),worker_sha256=c['worker_sha256'],source=str(p),source_sha256=sha(p),c_excerpt=str(cp),c_excerpt_sha256=sha(cp),assembly=str(ap),assembly_sha256=sha(ap),argv=argv,exit_code=r.returncode,all_inputs_unchanged=True,script_sha256=sha(__file__))
# The final rehash loop uses p; bind the intended C source explicitly.
record['source']='.lake/build/ir/Impl/Message.c';record['source_sha256']=sha(record['source'])
out=R/'report-map-bindings.json';assert not out.exists();out.write_text(json.dumps(record,indent=2)+'\n');print(sha(out))
