#!/usr/bin/env python3
"""Independent retained-raw recount of the separate post-seal power supplement."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import Counter,defaultdict
import ast,gzip,hashlib,json,re
B=Path('tests/evidence/diagnostics/gen18');R=B/'independent-review';S=B/'post-review-power-edges';P='lp_lean1090_Lean1090_Impl_'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
record=read(S/'contexts.json');completion=read(S/'completion.json');analysis=read(B/'analysis/analysis.json')
assert record['status']==completion['status']=='passed'
assert {p.name for p in S.iterdir()}==set(completion['files'])|{'completion.json'}
for name,h in completion['files'].items():assert sha(S/name)==h
for name,h in record['sealed_producer_artifacts_unchanged'].items():assert sha(name)==h
assert completion['sealed_artifacts_unchanged']==record['sealed_producer_artifacts_unchanged']
for name,h in record['runtime_source_sha256'].items():assert sha(name)==h
assert sha(S/'extract.py')==record['script_sha256'] and sha('review/diagnostics/analyze_callgrind.py')==record['parser_sha256']
assert sha(B/'analysis/analysis.json')==record['analysis_sha256']
selected={P+n for n in ['Altitude_bit','Altitude_grayDecode','identityCode','identityCode___lam__0','payloadInteger']}|{'lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0'}
# Reuse only the function AST from our already-sealed independent raw parser.
# Its top-level cache/source checks and result-writing code are not executed.
tree=ast.parse((R/'check_final.py').read_text());fun=next(n for n in tree.body if isinstance(n,ast.FunctionDef) and n.name=='recount')
ns=dict(Counter=Counter,re=re,gzip=gzip,priority_selected=selected,power_anchors={});exec(compile(ast.Module(body=[fun],type_ignores=[]),str(R/'check_final.py'),'exec'),ns)
contexts=[];groups=defaultdict(Counter)
for family,info in analysis['families'].items():
 path=B/'callgrind'/family/'callgrind.out.1.gz';assert sha(path)==record['profile_sha256'][str(path)]
 captured={};total,entries,stages,helper,_=ns['recount'](path,P+'decode',captured)
 assert total==info['total_events']['Ir']
 for name,node in captured.items():
  symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0]
  if symbol not in selected or node['stage'] is None:continue
  incoming=[dict(caller=caller,calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_events']['Ir']) for caller,edge in node['incoming'].items()]
  outgoing=[dict(context=callee,symbol=re.split(r"'| \[clone ",callee,maxsplit=1)[0],calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_events']['Ir']) for callee,edge in node['outgoing'].items()]
  contexts.append(dict(family=family,stage=node['stage'],symbol=symbol,context=name,self_ir=node['self_events']['Ir'],incoming=incoming,outgoing=outgoing))
  for edge in outgoing:groups[node['stage'],symbol,edge['symbol']].update(calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
 for stage,rows in info['stage_helper_observations_non_additive'].items():
  for row in rows:
   if row['symbol'] in selected:assert dict(helper[stage,row['symbol']])==dict(self=row['self_events'].get('Ir',0),entries=row['native_entries'],inclusive=row['incoming_inclusive_events_non_additive'].get('Ir',0),contexts=row['contexts'])
def canonical(rows):
 result=[]
 for row in rows:
  row=dict(row)
  for k in ['incoming','outgoing']:
   if k in row:row[k]=sorted(row[k],key=lambda x:json.dumps(x,sort_keys=True))
  result.append(row)
 return sorted(result,key=lambda x:json.dumps(x,sort_keys=True))
assert canonical(contexts)==canonical(record['contexts'])
rows=[dict(stage=k[0],caller=k[1],callee=k[2],**v) for k,v in sorted(groups.items())]
assert rows==record['all_selected_direct_edges']
power=[row for row in rows if row['callee']=='lean_nat_pow'];assert power==record['direct_power_edges']
totals=dict(calls=sum(r['calls'] for r in power),inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in power));assert totals==record['summed_direct_power_edge_observations']==completion['summed_direct_power_edge_observations']
assert len(power)==completion['power_edge_groups']==8 and len(contexts)==completion['caller_contexts']==81
assert (S/'extract.stderr').read_bytes()==b''
assert read(S/'extract.stdout')==dict(status='passed',power_rows=len(power),contexts=len(contexts),totals=totals,sha256=sha(S/'contexts.json'))
result=dict(status='passed',script_sha256=sha(__file__),independent_parser_sha256=sha(R/'check_final.py'),completion_sha256=sha(S/'completion.json'),contexts_sha256=sha(S/'contexts.json'),producer_supplement_members=5,profile_count=3,raw_contexts=len(contexts),power_groups=len(power),direct_power_edges=power,totals=totals,sealed_artifacts_unchanged=record['sealed_producer_artifacts_unchanged'],findings=[],limits=record['limits'])
p=R/'post-power-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',sha256=sha(p),contexts=len(contexts),power_groups=len(power),totals=totals)))
