"""Retained-profile direct arithmetic in choose and both scaledTotals loops."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import defaultdict,deque,Counter
import hashlib,json
sys.path.insert(0,str(Path.cwd()/'review/diagnostics'))
import analyze_callgrind as parser
E=Path('tests/evidence/diagnostics/gen24');P='lp_lean1090_Lean1090_Impl_'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
analysis=read(E/'analysis/analysis.json');groups={};contexts=[];bindings={}
for family,info in analysis['families'].items():
 raw=E/'callgrind'/family/'callgrind.out.1.gz';bindings[str(raw)]=sha(raw);profile=parser.parse(raw)
 labels=defaultdict(set);pending=deque((name,'output_model_control') for name in profile.nodes if parser.base_name(name)==parser.DECODE)
 while pending:
  name,inherited=pending.popleft();stage=parser.stage_for(name,inherited)
  if stage in labels[name]:continue
  labels[name].add(stage);pending.extend((child,stage) for child,events in profile.nodes[name].edges.items() if any(events.values()))
 for name,node in profile.nodes.items():
  symbol=parser.base_name(name)
  if not ('ScoreGate_scaledTotals' in symbol or symbol in [P+'ScoreGate_choose',P+'ScoreGate_scaledNumerator']):continue
  if len(labels[name])!=1:continue
  stage=next(iter(labels[name]));incoming=[{'caller':caller,'calls':parent.calls.get(name,0),'inclusive_ir_non_additive':parent.edges[name].get('Ir',0)} for caller,parent in profile.nodes.items() if name in parent.edges]
  outgoing=[{'context':child,'symbol':parser.base_name(child),'calls':node.calls.get(child,0),'inclusive_ir_non_additive':events.get('Ir',0)} for child,events in node.edges.items() if any(events.values())]
  values=Counter(contexts=1,native_entries=sum(r['calls'] for r in incoming),self_ir=node.own.get('Ir',0),incoming_inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in incoming))
  g=groups.setdefault((stage,symbol),{'values':Counter(),'children':defaultdict(Counter)});g['values'].update(values)
  for edge in outgoing:g['children'][edge['symbol']].update(calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
  contexts.append({'family':family,'stage':stage,'symbol':symbol,'context':name,'self_ir':node.own.get('Ir',0),'incoming':incoming,'outgoing':outgoing})
rows=[{'stage':stage,'symbol':symbol,**group['values'],'direct_children':[{'symbol':child,**values} for child,values in sorted(group['children'].items())]} for (stage,symbol),group in sorted(groups.items())]
priority=read(E/'priority-helper-contexts.json')
for row in rows:
 existing=next((r for r in priority['rows'] if r['stage']==row['stage'] and r['symbol']==row['symbol']),None)
 if existing:
  assert all(row[k]==existing[k] for k in ['contexts','native_entries','self_ir','incoming_inclusive_ir_non_additive'])
  assert sorted(row['direct_children'],key=lambda r:r['symbol'])==sorted(existing['direct_children'],key=lambda r:r['symbol'])
for p in [E/'analysis/analysis.json',E/'priority-helper-contexts.json',E/'independent-review/source-review.json',Path('Impl/ScoreGate.lean'),Path('review/diagnostics/analyze_callgrind.py'),Path(__file__)]:bindings[str(p)]=sha(p)
out={'status':'passed','kind':'same_profile_nested_score_scaling_direct_edges','bindings':bindings,'rows':rows,'contexts':contexts,'limits':['Only disjoint whole-decode family profiles are summed; unchanged exclusive stage propagation selects root descendants.','Both actual fold contexts are retained; scaledNumerator is inlined, so no standalone helper hit count or denominator-equality frequency is inferred.','Direct native division/multiplication edges count surviving callable boundaries, not small inline arithmetic. Costs overlap choose/folds and other descendants; no timing or removable-cost prediction is made.','No source or native work executed; this compact supplement leaves the finalized report, validation and earlier evidence unchanged.']}
p=E/'score-scale-contexts.json'
with p.open('x') as f:f.write(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(p),'rows':rows},indent=2))
