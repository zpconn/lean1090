"""Two bounded current caller captures completing the frozen CPR loop chain."""
from pathlib import Path
import hashlib,json,re,subprocess
from datetime import datetime,timezone
R=Path('tests/evidence/optimization/gen26/native-review');O=R/'native-inspection';sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();c=json.loads((R/'native-inputs.json').read_text());rows=[]
for p,h in c['held_inputs'].items():assert sha(p)==h
for symbol,source in [('lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance','Bench/WholeDecoder'),('lp_lean1090_Lean1090_Impl_CPR_Policy_step','Impl/CPRPolicy')]:
 path=Path('.lake/build/ir')/(source+'.c');lines=path.read_text().splitlines();start=next(i for i,l in enumerate(lines) if re.search(r'\b'+re.escape(symbol)+r'\(',l) and l.endswith('{'));depth=0
 for end in range(start,len(lines)):
  depth+=lines[end].count('{')-lines[end].count('}')
  if depth==0:break
 cp=O/(symbol+'.c.txt');ap=O/(symbol+'.txt');assert not cp.exists() and not ap.exists()
 cp.write_text('\n'.join(lines[start:end+1])+'\n');cmd=['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,c['worker']];run=subprocess.run(cmd,capture_output=True,text=True);assert run.returncode==0 and not run.stderr and '<'+symbol+'>:' in run.stdout;ap.write_text(run.stdout)
 rows.append({'symbol':symbol,'c_source':str(path),'c_source_sha256':sha(path),'c_excerpt':str(cp),'c_excerpt_sha256':sha(cp),'assembly':str(ap),'assembly_sha256':sha(ap),'command':cmd,'exit_code':0})
for p,h in c['held_inputs'].items():assert sha(p)==h
out={'status':'captured_read_only','recorded_utc':datetime.now(timezone.utc).isoformat(),'parent_capture_sha256':sha(R/'native-inputs.json'),'worker_sha256':c['worker_sha256'],'caller_rows':rows,'all_inputs_unchanged':True}
p=R/'caller-bindings.json'
with p.open('x') as f:f.write(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'callers':len(rows)}))
