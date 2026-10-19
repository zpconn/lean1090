import sys
sys.dont_write_bytecode=True
from pathlib import Path
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen23/native-review');O=R/'native-inspection';sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
c=json.loads((R/'native-inputs.json').read_text());held=c['held_inputs'];worker=Path(c['worker']);out=[]
for p,h in held.items():assert sha(p)==h,p
source=Path('.lake/build/ir/Bench/WholeDecoder.c');text=source.read_text();lines=text.splitlines()
for mode in ['runDecodeOnce','runCPROnce']:
 matches=list(re.finditer(r'^LEAN_EXPORT lean_object\* (\w*'+mode+r'_spec__0)\([^\n]*\)\{',text,re.M));assert len(matches)==1,(mode,len(matches));symbol=matches[0][1]
 start=text[:matches[0].start()].count('\n');depth=0
 for end in range(start,len(lines)):
  depth+=lines[end].count('{')-lines[end].count('}')
  if depth==0:break
 body='\n'.join(lines[start:end+1]);assert body.count('lp_lean1090_Lean1090_Impl_decode(')==1
 cp=O/(mode+'-caller.c.txt');assert not cp.exists();cp.write_text('\n'.join(f'{i+1}: {lines[i]}' for i in range(start,end+1))+'\n')
 argv=['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,str(worker)];r=subprocess.run(argv,text=True,capture_output=True);assert r.returncode==0 and '<lp_lean1090_Lean1090_Impl_decode>' in r.stdout
 ap=O/(mode+'-caller.asm.txt');assert not ap.exists();ap.write_text(r.stdout)
 out.append(dict(symbol=symbol,mode=mode,c_source=str(source),c_sha256=sha(source),c_excerpt=str(cp),c_excerpt_sha256=sha(cp),assembly=str(ap),assembly_sha256=sha(ap),argv=argv,exit_code=r.returncode))
extra=[]
for symbol in ['lp_lean1090_Lean1090_Impl_'+n+'Table___lam__0___boxed' for n in ['cbSelectedValid40','cbRollValid50','cbVerticalValid60']]+['l_Array_ofFn___redArg']:
 argv=['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,str(worker)];r=subprocess.run(argv,text=True,capture_output=True);assert r.returncode==0 and '<'+symbol+'>:' in r.stdout
 ap=O/(symbol+'.txt');assert not ap.exists();ap.write_text(r.stdout)
 extra.append(dict(symbol=symbol,assembly=str(ap),assembly_sha256=sha(ap),argv=argv,exit_code=r.returncode))
for p,h in held.items():assert sha(p)==h,p
result=dict(status='captured_read_only',parent_capture_sha256=sha(R/'native-inputs.json'),worker_sha256=c['worker_sha256'],benchmark_callers=out,additional_table_functions=extra,all_inputs_unchanged=True,script_sha256=sha(__file__))
p=R/'caller-bindings.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(sha(p))
