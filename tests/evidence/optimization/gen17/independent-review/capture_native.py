#!/usr/bin/env python3
"""Bounded static capture of linked gen17 table paths; never runs a decoder."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,shlex,subprocess
ROOT=Path.cwd();R=Path('tests/evidence/optimization/gen17/independent-review');O=R/'native-inspection';assert not O.exists();O.mkdir()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
b=read(R.parent/'integration/targeted-build.json');assert b['status']=='passed' and b['exit_code']==0
worker=Path('.lake/build/bin/lean1090-bench');held=dict(b['all_inputs_after']);inventory=[]
for token in shlex.split(Path(str(worker)+'.rsp').read_text()):
 p=Path(token)
 if p.is_absolute():
  if not p.is_relative_to(ROOT):continue
  p=p.relative_to(ROOT)
 if not str(p).startswith('.lake/build/ir/') or not str(p).endswith('.c.o.export'):continue
 stem=str(p).removeprefix('.lake/build/ir/').removesuffix('.c.o.export');source=Path(stem+'.lean');c=Path('.lake/build/ir/'+stem+'.c');trace=Path(str(p)+'.trace')
 row={'source':str(source),'source_sha256':sha(source),'c':str(c),'c_sha256':sha(c),'object':str(p),'object_sha256':sha(p),'trace':str(trace),'trace_sha256':sha(trace)}
 for x in [source,c,p,trace]:held[str(x)]=sha(x)
 messages='\n'.join(x['message'] for x in read(trace)['log']);assert ' -O3 ' in messages and '-ffp-contract=off' in messages and not re.search(r'-(?:march|mcpu|mtune)=',messages)
 row['compile_command']=messages;inventory.append(row)
assert len(inventory)==22
for n in ['lean1090-bench','lean1090','messageGenerator','commbDifferential']:
 p=Path('.lake/build/bin')/n;held[str(p)]=sha(p);assert b['binary_hashes'][n]==sha(p)
for p in [Path(str(worker)+'.rsp'),Path(str(worker)+'.trace')]:held[str(p)]=sha(p)
for p,h in held.items():assert sha(p)==h,p
commands=[]
def cmd(argv,label,filtered=None):
 run=subprocess.run(argv,capture_output=True,text=True);assert run.returncode==0,(argv,run.stderr)
 text=run.stdout
 if filtered:text='\n'.join(x for x in text.splitlines() if filtered(x))+'\n'
 path=O/(label+'.txt');assert not path.exists();path.write_text(text);commands.append({'argv':argv,'exit_code':run.returncode,'output':str(path),'sha256':sha(path),'stderr':run.stderr});return text
P='lp_lean1090_Lean1090_Impl_'
requested=[P+'Binary64_'+n for n in ['powerTwo','powerTwoFormula','powerTwoTable___lam__0','exponent','round','fromBits']]+[P+'CPR_Policy_toFloat',P+'Numeric_toFloat32',P+'cbGaussian',P+'cbLaplace']
requested+=['main','initialize_lean1090_Bench_WholeDecoder','initialize_lean1090_Impl','initialize_lean1090_Impl_Message','initialize_lean1090_Impl_CommB','initialize_lean1090_Impl_Binary64','_init_'+P+'Binary64_powerTwoTable___closed__1']
selected=set(requested)
syms=cmd(['nm','--defined-only',str(worker)],'selected-symbols',lambda line:line.split() and (line.split()[-1] in selected or 'Binary64_powerTwoTable' in line.split()[-1]))
present={line.split()[-1] for line in syms.splitlines()}
for symbol in requested:
 if symbol in present:cmd(['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,str(worker)],symbol)
def extract(path,symbol):
 lines=path.read_text().splitlines();starts=[i for i,l in enumerate(lines) if re.search(r'\b'+re.escape(symbol)+r'\(',l) and l.rstrip().endswith('{')]
 assert len(starts)==1,(str(path),symbol,starts);start=starts[0];depth=0
 for end in range(start,len(lines)):
  depth+=lines[end].count('{')-lines[end].count('}')
  if depth==0:break
 assert depth==0
 out=O/(symbol+'.c.txt');out.write_text('\n'.join(f'{i+1}: {lines[i]}' for i in range(start,end+1))+'\n')
 return {'source':str(path),'source_sha256':sha(path),'start_line':start+1,'end_line':end+1,'path':str(out),'sha256':sha(out),'function':symbol,'calls':re.findall(r'\b((?:initialize_lean1090_|lp_lean1090_|_init_lp_lean1090_|lean_|l_)[A-Za-z0-9_]+)\(', '\n'.join(lines[start+1:end]))}
cs={};initgraph={}
for row in inventory:
 path=Path(row['c']);stem=row['source'].removesuffix('.lean').replace('/','_');symbol='initialize_lean1090_'+stem
 if symbol in path.read_text():
  # Save only chain needed to show table initialization before main loop.
  if symbol in selected:cs[symbol]=extract(path,symbol)
  lines=path.read_text().splitlines();start=next(i for i,l in enumerate(lines) if symbol+'(' in l and l.endswith('{'));tail='\n'.join(lines[start:]);initgraph[symbol]=sorted(set(re.findall(r'res = (initialize_lean1090_\w+)\(',tail)))
for symbol in requested:
 if symbol in cs:continue
 for row in inventory:
  path=Path(row['c']);pattern=re.compile(r'\b'+re.escape(symbol)+r'\([^;]*\)\s*\{')
  if pattern.search(path.read_text()):cs[symbol]=extract(path,symbol);break
for p,h in held.items():assert sha(p)==h,p
out={'status':'captured_read_only','captured_utc':datetime.now(timezone.utc).isoformat(),'worker':str(worker),'worker_sha256':sha(worker),'integration_record_sha256':sha(R.parent/'integration/targeted-build.json'),'held_inputs':held,'linked_inventory':inventory,'commands':commands,'requested_symbols':requested,'present_symbols':sorted(present),'missing_requested_symbols':sorted(set(requested)-present),'generated_c_excerpts':cs,'initialization_graph':initgraph,'all_inputs_unchanged':True,'capture_script_sha256':sha(__file__),'notes':['Only selected symbols are retained; no full binary symbol dump.','No executable or benchmark invoked. Actual generated C and linked disassembly are retained for separate review.']}
p=R/'native-inputs.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'held':len(held),'linked_sets':len(inventory),'selected_disassemblies':len(commands)-1,'missing_symbols':out['missing_requested_symbols']}))
