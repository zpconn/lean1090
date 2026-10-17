#!/usr/bin/env python3
"""Permanent unit gate. Batch every assertion, retain failures, fail on any gap."""
import copy,hashlib,json,os,subprocess,sys,tempfile
sys.dont_write_bytecode=True
from pathlib import Path
from inventory import ROOT,VENDOR,GENERATED

OUT=ROOT/'tests/evidence/upstream-unit-tests'
COMMANDS=[]
def command(args, *, output=None, input=None, expected=0):
 env={**os.environ,"CARGO_HOME":str(ROOT/".cache/cargo"),"PYTHONDONTWRITEBYTECODE":"1"}
 p=subprocess.run(args,cwd=ROOT,text=True,input=input,stdout=subprocess.PIPE,stderr=subprocess.PIPE,env=env)
 COMMANDS.append({'argv':args,'exit_code':p.returncode,'stdout':p.stdout if output is None else str(output),'stderr':p.stderr})
 if output:Path(output).write_text(p.stdout)
 if p.returncode not in (expected if isinstance(expected,tuple)else (expected,)):raise RuntimeError(f'command exit {p.returncode}, expected {expected}: {args}\n{p.stderr}')
 return p

def rejection_selftests():
 from port import expr,get,lit,sub
 good={'id':'selftest','observations':[{'op':'frame','hex':'8D406B902015A678D4D220AA4BDA'}], 'assertions':[]}
 checks=[expr('eq',sub(get(0),'callsign'),lit('WRONG')),
  expr('not',sub(get(0),'absent_boolean')),
  expr('null',get(999)),
  expr('null',dict(sub(sub(get(0),'missing_parent'),'leaf'),allow_missing=True)),
  {'op':'unrecognized','args':[lit(0),lit(0)]},
  expr('eq',get(0),lit(None))]
 deep=lit(True)
 for _ in range(55):deep=expr('not',deep)
 checks.append(deep)
 # All seven must fail in one run; diagnostics must retain every one.
 with tempfile.TemporaryDirectory(dir=ROOT/'.cache',prefix='upstream-selftest-')as temp:
  path=Path(temp)/'tests.jsonl';f=copy.deepcopy(good);f['assertions']=[{'line':i,'expression':e}for i,e in enumerate(checks)]
  path.write_text(json.dumps(f)+'\n')
  p=command(['lake','env','lean','--run','Tests/Upstream.lean',str(path)],expected=1)
  results=[json.loads(l)for l in p.stdout.splitlines()];assert len(results)==7 and all(not r['passed']for r in results)
  (OUT/'rejection-assertions.jsonl').write_text(p.stdout)
  bad=[{'op':'unrecognized','hex':''},{'op':'frame','hex':'garbage'},{'op':'local','hex':'8D406B902015A678D4D220AA4BDA'}, {'hex':''}]
  for i,o in enumerate(bad):
   f=copy.deepcopy(good);f['observations']=[o];f['assertions']=[{'line':0,'expression':expr('null',get(0))}]
   path.write_text(json.dumps(f)+'\n')
   p=command(['lake','env','lean','--run','Tests/Upstream.lean',str(path)],expected=1)
   assert 'uncaught exception'in p.stderr
  return {'assertion_rejections':7,'schema_rejections':4}

def oracle_check(fixtures,results):
 # Fresh cargo rebuild is mandatory; a stale executable is never accepted.
 env=os.environ.copy()
 command(['cargo','build','--offline','--locked','--manifest-path','differential/message-oracle/Cargo.toml','--profile','dist','--target-dir','.cache/rs1090-target','--bin','lean1090-message-oracle','--bin','commb-oracle'])
 byid={r['test']:r['observations']for r in results};frames={};registers={}
 for f in fixtures:
  if not f['assertions']:continue
  actuals=byid[f['id']]
  for o,a in zip(f['observations'],actuals):
   if o['op']=='frame':frames[o['hex'].lower()]=a
   if o['op']=='register':
    h=o['hex'];w=int(h if len(h)==14 else h[8:22],16);registers[(o['register'],w)]=a
 hs=list(frames);text=''.join(h+'\n'for h in hs)
 (OUT/'fresh-frames.input').write_text(text)
 p=command(['.cache/rs1090-target/dist/lean1090-message-oracle'],input=text,output=OUT/'fresh-frames.jsonl')
 oracle=[json.loads(l)for l in p.stdout.splitlines()];assert len(oracle)==len(hs)
 failures=[]
 for h,reference in zip(hs,oracle):
  expected=reference['oracle']if reference else None
  actual=frames[h]
  if actual is not None:actual={k:v for k,v in actual.items()if not k.startswith('_')}
  if actual!=expected:failures.append(dict(hex=h,actual=actual,oracle=expected))
 keys=list(registers);text=''.join(f'{r} {w}\n'for r,w in keys);(OUT/'fresh-registers.input').write_text(text)
 p=command(['.cache/rs1090-target/dist/commb-oracle'],input=text,output=OUT/'fresh-registers.jsonl')
 oracle=[json.loads(l)for l in p.stdout.splitlines()];assert len(oracle)==len(keys)
 for key,expected in zip(keys,oracle):
  actual=registers[key]
  if actual is not None:actual={k:v for k,v in actual.items()if not k.startswith('_')}
  if actual!=expected:failures.append(dict(register=key,actual=actual,oracle=expected))
 (OUT/'fresh-oracle-mismatches.json').write_text(json.dumps(failures,indent=2)+'\n')
 assert not failures,failures
 return dict(unique_frames=len(hs),direct_registers=len(keys),mismatches=0)

def main():
 OUT.mkdir(parents=True,exist_ok=True);(ROOT/'.cache').mkdir(exist_ok=True)
 status=[];summary={}
 try:
  for name in ['inventory','port','rust_port','manual','assemble']:
   command(['python3',f'review/upstream-units/{name}.py'])
  command(['lake','build','Impl.JSON','Impl.CPRPolicy'])
  result=command(['lake','env','lean','--run','Tests/Upstream.lean',str(GENERATED/'fixtures.jsonl')],output=OUT/'assertions.jsonl',expected=(0,1))
  results=[json.loads(l)for l in result.stdout.splitlines()]
  coverage=json.loads((OUT/'coverage.json').read_text())
  assert len(results)==coverage['expanded_checks']
  summary['assertions']=len(results);summary['assertion_failures']=sum(not r['passed']for r in results)
  fixtures=[json.loads(l)for l in (GENERATED/'fixtures.jsonl').read_text().splitlines()]
  # Run every independent component even after assertion/oracle failures.
  errors=[]
  for name,run in [('fresh_oracle',lambda:oracle_check(fixtures,results)),('selftests',rejection_selftests)]:
   try:summary[name]=run()
   except Exception as error:errors.append({'component':name,'error':str(error)})
  try:
   command(['python3','review/upstream-units/run_corpus.py'])
   summary['corpus']=json.loads((OUT/'corpus/summary.json').read_text())
  except Exception as error:errors.append({'component':'corpus','error':str(error)})
  summary['component_errors']=errors
  summary['coverage']={k:v for k,v in coverage.items()if k!='tests'}
  summary['status']='pass' if not errors and summary['assertion_failures']==0 else 'fail'
 except Exception as e:
  summary['status']='fail';summary['error']=str(e)
 finally:
  (OUT/'commands.json').write_text(json.dumps(COMMANDS,indent=2)+'\n')
  inputs=['Tests/Upstream.lean','Tests/UpstreamCorpus.lean','scripts/run_unit_tests.sh']+[str(p.relative_to(ROOT))for p in sorted((ROOT/'review/upstream-units').rglob('*')) if p.is_file()]
  summary['inputs']={p:hashlib.sha256((ROOT/p).read_bytes()).hexdigest()for p in inputs if(ROOT/p).exists()}
  (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
 print(json.dumps(summary,indent=2))
 return 0 if summary['status']=='pass' else 1
if __name__=='__main__':sys.exit(main())
