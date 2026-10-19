#!/usr/bin/env python3
"""Capture one actual specialized semantic caller without invoking a decoder."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import json, hashlib, subprocess, re
R=Path('tests/evidence/optimization/gen21/native-review')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
n=json.loads((R/'native-inputs.json').read_text())
for p,h in n['held_inputs'].items():assert sha(p)==h,p
s='lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0'
c=Path('.lake/build/ir/Impl/Semantics.c'); lines=c.read_text().splitlines()
start=next(i for i,l in enumerate(lines) if s+'(' in l and l.endswith('{'))
depth=0
for end in range(start,len(lines)):
 depth+=lines[end].count('{')-lines[end].count('}')
 if depth==0:break
cp=R/'native-inspection'/(s+'.c.txt');assert not cp.exists()
cp.write_text('\n'.join(f'{i+1}: {lines[i]}' for i in range(start,end+1))+'\n')
cmd=['objdump','-d','--no-show-raw-insn','--disassemble='+s,n['worker']]
r=subprocess.run(cmd,capture_output=True,text=True);assert r.returncode==0 and not r.stderr
assert '<'+s+'>:' in r.stdout and '<lp_lean1090_Lean1090_Impl_payloadValue>' in r.stdout
ap=R/'native-inspection'/(s+'.txt');assert not ap.exists();ap.write_text(r.stdout)
for p,h in n['held_inputs'].items():assert sha(p)==h,p
out={'status':'captured_read_only','parent_capture_sha256':sha(R/'native-inputs.json'),'worker_sha256':sha(n['worker']),'symbol':s,'c_source':str(c),'c_sha256':sha(c),'c_excerpt':str(cp),'c_excerpt_sha256':sha(cp),'command':cmd,'exit_code':r.returncode,'stderr':r.stderr,'assembly':str(ap),'assembly_sha256':sha(ap),'all_inputs_unchanged':True,'script_sha256':sha(__file__)}
p=R/'semantic-caller.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':'passed','record_sha256':sha(p)}))
