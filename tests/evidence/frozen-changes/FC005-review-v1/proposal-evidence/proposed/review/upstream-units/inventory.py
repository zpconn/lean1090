#!/usr/bin/env python3
"""Reconstruct upstream source coverage; never obtain expected values from Impl."""
import ast, hashlib, json, re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
VENDOR=ROOT/'vendor/rs1090'
def scan():
 result=[]
 paths=sorted((VENDOR/'crates/rs1090/src/decode').rglob('*.rs'))+sorted((VENDOR/'python/tests').glob('*.py'))+sorted((VENDOR/'crates/rs1090-wasm/tests/src/tests').glob('*.ts'))
 for p in paths:
  source=p.read_text(); rel=str(p.relative_to(VENDOR)); sha=hashlib.sha256(p.read_bytes()).hexdigest(); tests=[]
  if p.suffix=='.py':
   for node in ast.walk(ast.parse(source)):
    if isinstance(node,(ast.FunctionDef,ast.AsyncFunctionDef)) and node.name.startswith('test_'):
     tests.append((node.name,node.lineno,node.end_lineno))
  else:
   # Blank comments without disturbing offsets. Rust multiline strings are preserved.
   cleaned=re.sub(r'(?m)^\s*//[^\n]*',lambda m:' '*len(m[0]),source)
   pat=r'#\[test\]\s*fn\s+(\w+)\([^)]*\)\s*\{' if p.suffix=='.rs' else r'\btest\("([^"]+)"[^\n]*=>\s*\{'
   for m in re.finditer(pat,cleaned):
    start=m.end()-1; depth=1; i=start+1; quote=None
    while depth and i<len(cleaned):
     c=cleaned[i]
     if quote:
      if c=='\\':i+=2;continue
      if c==quote:quote=None
     elif c=='"':quote=c
     elif c=='{':depth+=1
     elif c=='}':depth-=1
     i+=1
    tests.append((m[1],source.count('\n',0,m.start())+1,source.count('\n',0,i)+1))
  for name,start,end in tests:
   body='\n'.join(source.splitlines()[start-1:end]); assertions=[]
   for off,line in enumerate(body.splitlines()):
    if re.search(r'\b(?:assert(?:_eq|_ne|_relative_eq)?!|assert\s|expect\()',line) and not line.strip().startswith('//'):
     assertions.append({'line':start+off,'text':line.strip()})
   result.append({'id':f'{rel}::{name}', 'file':rel,'line':start,'end_line':end,'source_sha256':sha,'assertions':assertions,'body':body})
 return result
if __name__=='__main__':
 rows=scan(); (ROOT/'review/upstream-units/source-inventory.json').write_text(json.dumps(rows,indent=2)+'\n')
 print(len(rows),'tests',sum(len(r['assertions']) for r in rows),'assertion sites')
