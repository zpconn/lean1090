#!/usr/bin/env python3
"""Mechanical Python/WASM assertion port; manual Rust assertions are source audited."""
import ast,json,re,sys
from pathlib import Path
from inventory import ROOT,VENDOR,scan

def lit(x):return {'op':'literal','value':x}
def expr(op,*args,**kw):return {'op':op,'args':list(args),**kw}
def get(i,*path):return {'op':'get','observation':i,'path':list(path)}
def fixture(row):return {'id':row['id'],'file':row['file'],'line':row['line'],'source_sha256':row['source_sha256'],'observations':[],'assertions':[],'exclusions':[]}
def addobs(f,op,hex='',**kw):
 i=len(f['observations']);f['observations'].append(dict(op=op,hex=hex,**kw));return get(i)
def check(f,line,e):f['assertions'].append({'line':line,'expression':e})
def sub(e,key):
 assert e['op']=='get',e
 return dict(e,path=e['path']+[key])
def python_port(row):
 f=fixture(row); env={};body=ast.parse((VENDOR/row['file']).read_text());node=next(n for n in ast.walk(body) if isinstance(n,ast.FunctionDef) and n.lineno==row['line'])
 def ev(n):
  if isinstance(n,ast.Constant):return lit(n.value)
  if isinstance(n,ast.Name):return env[n.id]
  if isinstance(n,ast.Subscript):return sub(ev(n.value),ast.literal_eval(n.slice))
  if isinstance(n,ast.UnaryOp):return expr('not' if isinstance(n.op,ast.Not) else 'neg',ev(n.operand))
  if isinstance(n,ast.BoolOp):return expr('or' if isinstance(n.op,ast.Or) else 'and',*[ev(x) for x in n.values])
  if isinstance(n,ast.Call):
   name=ast.unparse(n.func)
   if name=='rs1090.decode':
    h=ast.literal_eval(n.args[0]);base=addobs(f,'frame',h)
    if n.keywords:
     ref=ast.literal_eval(n.keywords[0].value)
     local=addobs(f,'local',h,reference=dict(latitude=ref[0],longitude=ref[1]),surface=True)
     env['_position_for_'+str(base['observation'])]=local
    return base
   if name.startswith('rs1090.decode_bds'):
    return addobs(f,'register',ast.literal_eval(n.args[0]),register=int(name[-2:],16))
   if name.startswith('rs1090.is_df'):return expr('eq',sub(ev(n.args[0]),'df'),lit(name[12:]))
   if name.startswith('rs1090.is_bds'):return expr('eq',sub(ev(n.args[0]),'bds'),lit(name[-2:]))
   if name=='approx':
    val=ast.literal_eval(n.args[0]); opts={k.arg:ast.literal_eval(k.value) for k in n.keywords}
    if len(n.args)>1:opts['rel']=ast.literal_eval(n.args[1])
    return {'op':'approx-value','value':val,'relative':opts.get('rel',0 if 'abs'in opts else 1e-6),'absolute':opts.get('abs',1e-12)}
  if isinstance(n,ast.Compare):
   assert len(n.ops)==1
   a,b=ev(n.left),ev(n.comparators[0]);op=n.ops[0]
   if isinstance(op,(ast.In,ast.NotIn)):
    return expr('null' if isinstance(op,ast.NotIn) else 'present',sub(b,a['value']))
   if b.get('op')=='approx-value':return expr('approx',a,lit(b['value']),relative=b['relative'],absolute=b['absolute'])
   return expr({ast.Eq:'eq',ast.NotEq:'ne',ast.Is:'eq',ast.IsNot:'ne',ast.Lt:'lt',ast.Gt:'gt'}[type(op)],a,b)
  raise ValueError(ast.dump(n))
 for n in node.body:
  if isinstance(n,ast.Assign):env[n.targets[0].id]=ev(n.value)
  elif isinstance(n,ast.Assert):
   e=ev(n.test)
   # Position assertions use live local decoder; frame remains checked separately.
   def route(x):
    if x.get('op')=='get' and x['path'] and x['path'][0] in ['latitude','longitude']:
     p=env.get('_position_for_'+str(x['observation']))
     if p:return sub(p,x['path'][0])
    if 'args'in x:x['args']=[route(v)for v in x['args']]
    return x
   check(f,n.lineno,route(e))
 return f

def wasm_port(row):
 f=fixture(row);env={};body=row['body']
 token=re.compile(r'const\s+(\w+)\s*=\s*([^;]+);|expect\(([\s\S]*?)\)\.(not\.)?(toBeCloseTo|toBeNull|toBe|toThrow)\(([\s\S]*?)\);')
 def ev(s):
  s=s.strip()
  m=re.fullmatch(r'decode\(\s*"([0-9A-Fa-f]+)"\s*(?:,\s*new Float64Array\(\[([\d.]+),\s*([-\d.]+)\]\))?\s*\)(.*)',s,re.S)
  if m:
   a=addobs(f,'frame',m[1])
   if m[2]:
    p=addobs(f,'local',m[1],reference=dict(latitude=float(m[2]),longitude=float(m[3])),surface=True)
    env['_position_for_'+str(a['observation'])]=p
   for key in m[4].strip('.').split('.'):
    if key:a=sub(a,key)
   return a
  parts=s.split('.');a=env[parts[0]]
  for key in parts[1:]:
   if key in ['latitude','longitude'] and '_position_for_'+str(a['observation']) in env:a=sub(env['_position_for_'+str(a['observation'])],key)
   else:a=sub(a,key)
  return a
 for m in token.finditer(body):
  line=row['line']+body.count('\n',0,m.start())
  if m[1]:env[m[1]]=ev(m[2]);continue
  s,neg,method,value=m.groups()[2:]
  if method=='toThrow':
   a=ev(s.replace('() =>','').strip());check(f,line,expr('null',a));f['exclusions'].append({'line':line,'reason':'WASM exception string is wrapper presentation; decoder rejection is ported.'});continue
  a=ev(s)
  if method=='toBeNull':check(f,line,expr('present' if neg else 'null',a))
  elif method=='toBe':check(f,line,expr('eq',a,lit(json.loads(value))))
  else:
   vals=[float(v.strip())for v in value.split(',')];tol=0.5*10**(-vals[1] if len(vals)>1 else -2)
   check(f,line,expr('approx',a,lit(vals[0]),relative=0,absolute=tol,strict=True))
 return f

def main():
 rows=scan();out=[];excluded=[]
 for row in rows:
  p=row['file']
  if p in ['python/tests/test_aircraft.py','python/tests/test_flarm.py'] or p.endswith(('decode/cat48.rs','decode/flarm.rs','test_utils.test.ts')):
   excluded.append(dict(id=row['id'],reason='Aircraft/airport databases, FLARM and CAT48 are outside Message::from_bytes/CPR scope.',assertions=row['assertions']));continue
  if p.endswith('.py') and not p.endswith('test_full.py'):out.append(python_port(row))
  elif p.endswith('.ts'):out.append(wasm_port(row))
 Path('review/upstream-units/automatic.jsonl').write_text(''.join(json.dumps(x)+'\n'for x in out))
 Path('review/upstream-units/exclusions.json').write_text(json.dumps(excluded,indent=2)+'\n')
 print(len(out),'automatic test functions',sum(len(x['assertions'])for x in out),'assertions',len(excluded),'whole-test exclusions')
if __name__=='__main__':main()
