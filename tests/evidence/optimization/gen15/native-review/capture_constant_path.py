#!/usr/bin/env python3
"""Retain actual linked constant bytes and live guard callers, without running it."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import hashlib,json,re,subprocess
O=Path(__file__).resolve().parent;P='lp_lean1090_Lean1090_Impl_';binary=Path('.lake/build/bin/lean1090')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
inspection=json.loads((O/'inspection-inputs.json').read_text());before=sha(binary)
assert before==inspection['inputs'][str(binary)]['sha256']
text=(O/'binary-initialize_lean1090_Impl_CommB.txt').read_text();lines=text.splitlines()
i=next(i for i,x in enumerate(lines) if '<'+P+'commBPayloadLimit>' in x)
assert 'lean_cstr_to_nat' in lines[i-1] and 'lea' in lines[i-2]
addr=int(re.search(r'# ([0-9a-f]+) ',lines[i-2]).group(1),16)
commands=[]
def run(args,name):
 r=subprocess.run(args,stdout=subprocess.PIPE,stderr=subprocess.PIPE);assert r.returncode==0 and not r.stderr
 (O/(name+'.txt')).write_bytes(r.stdout);(O/(name+'.stderr')).write_bytes(r.stderr)
 commands.append({'argv':args,'stdout':name+'.txt','stderr':name+'.stderr','exit_code':r.returncode})
 return r.stdout.decode()
raw=run(['objdump','-s',f'--start-address={addr}',f'--stop-address={addr+18}',str(binary)],'constant-rodata')
blocks=[]
for line in raw.splitlines():
 m=re.match(r'\s*[0-9a-f]+\s+((?:[0-9a-f]{2,8}\s+){1,4})',line)
 if m:blocks.append(bytes.fromhex(m[1]))
constant=b''.join(blocks);assert constant==b'72057594037927936\0'
for name in ['commBCoreEligible','decodeBDS','commBEligible']:
 run(['objdump','-d','--no-show-raw-insn','--disassemble='+P+name,str(binary)],'binary-'+name)
assert sha(binary)==before
out={'status':'passed','binary_sha256':before,'inspection_sha256':sha(O/'inspection-inputs.json'),'initialization_literal_virtual_address':hex(addr),'literal_bytes_hex':constant.hex(),'literal_ascii':constant.rstrip(b'\0').decode(),'initializer_window':lines[i-2:i+4],'commands':commands,'script_sha256':sha(__file__),'all_binary_bytes_unchanged':True,'scope':'Static ELF bytes and disassembly only; no execution, build or timing.'}
p=O/'constant-path-capture.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(p),'literal':out['literal_ascii'],'commands':len(commands)}))
