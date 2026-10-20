#!/usr/bin/env python3
"""Recount the late score supplement from retained raw profiles, without workloads."""
import sys
sys.dont_write_bytecode=True
import ast,gzip,hashlib,json,re
from pathlib import Path
from collections import Counter,defaultdict
from datetime import datetime,timezone
B=Path('tests/evidence/diagnostics/gen24');R=B/'independent-review'
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
record=read(B/'score-scale-contexts.json');analysis=read(B/'analysis/analysis.json')
assert record['status']=='passed'
for path,h in record['bindings'].items():assert sha(path)==h,path
# Reuse only the independently authored parser function, not its top-level
# campaign checks and never the producer parser. Select every raw score name,
# including lazy constants, rather than relying on the supplement's membership.
parser=R/'check_final.py';tree=ast.parse(parser.read_text())
fn=next(n for n in tree.body if isinstance(n,ast.FunctionDef) and n.name=='recount')
P='lp_lean1090_Lean1090_Impl_'
def selected(name):return 'ScoreGate_scaledTotals' in name or name in [P+'ScoreGate_choose',P+'ScoreGate_scaledNumerator']
profiles={};names=set()
for family,info in analysis['families'].items():
 p=B/'callgrind'/family/'callgrind.out.1.gz';profiles[family]=p
 with gzip.open(p,'rt') as f:
  for line in f:
   m=re.match(r'(?:c?fn)=\(\d+\) (.*)',line.strip())
   if m:
    base=re.split(r"'| \[clone ",m[1],maxsplit=1)[0]
    if selected(base):names.add(base)
env={'gzip':gzip,'re':re,'Counter':Counter,'priority_selected':names,
     'power_anchors':{},'bit_selected':set(),'crc_selected':set(),'affine_selected':set()}
exec(compile(ast.Module(body=[fn],type_ignores=[]),str(parser),'exec'),env)
groups={};contexts={};profile_bindings={}
for family,path in profiles.items():
 raw={};total,_,_,_,_=env['recount'](path,P+'decode',raw)
 assert total==analysis['families'][family]['total_events']['Ir']
 profile_bindings[str(path)]=sha(path)
 for name,node in raw.items():
  symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0]
  if not selected(symbol) or node['stage'] is None:continue
  incoming=[{'caller':caller,'calls':r['calls'],'inclusive_ir_non_additive':r['inclusive_events']['Ir']} for caller,r in node['incoming'].items()]
  outgoing=[{'context':child,'symbol':re.split(r"'| \[clone ",child,maxsplit=1)[0],'calls':r['calls'],'inclusive_ir_non_additive':r['inclusive_events']['Ir']} for child,r in node['outgoing'].items()]
  ctx={'family':family,'stage':node['stage'],'symbol':symbol,'context':name,'self_ir':node['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing}
  contexts[family,name]=ctx
  g=groups.setdefault((node['stage'],symbol),{'values':Counter(),'children':defaultdict(Counter)})
  g['values'].update(contexts=1,native_entries=sum(r['calls'] for r in incoming),self_ir=ctx['self_ir'],incoming_inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in incoming))
  for edge in outgoing:g['children'][edge['symbol']].update(calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
def normalized(ctx):
 return {**ctx,'incoming':sorted(ctx['incoming'],key=lambda r:r['caller']),'outgoing':sorted(ctx['outgoing'],key=lambda r:r['context'])}
assert len(record['contexts'])==len(contexts)
for ctx in record['contexts']:assert normalized(ctx)==normalized(contexts[ctx['family'],ctx['context']])
rows=[{'stage':stage,'symbol':symbol,**g['values'],'direct_children':[{'symbol':child,**values} for child,values in sorted(g['children'].items())]} for (stage,symbol),g in sorted(groups.items())]
assert rows==record['rows'] and len(rows)==5
priority=read(B/'priority-helper-contexts.json')
for row in rows:
 match=next((r for r in priority['rows'] if (r['stage'],r['symbol'])==(row['stage'],row['symbol'])),None)
 if match:
  assert all(match[k]==row[k] for k in ['contexts','native_entries','self_ir','incoming_inclusive_ir_non_additive'])
  assert sorted(match['direct_children'],key=lambda r:r['symbol'])==row['direct_children']
assert 'denominator-equality frequency' in ' '.join(record['limits'])
assert 'no timing or removable-cost prediction' in ' '.join(record['limits'])
out={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'checker_sha256':sha(__file__),'independent_parser_sha256':sha(parser),'supplement_sha256':sha(B/'score-scale-contexts.json'),'profile_bindings':profile_bindings,'raw_contexts':len(contexts),'rows':rows,'findings':[],'limits':record['limits']}
p=R/'score-scale-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(p),'rows':len(rows),'contexts':len(contexts)}))
