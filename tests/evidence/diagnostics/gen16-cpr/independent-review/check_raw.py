#!/usr/bin/env python3
"""Independent full-context CPR Callgrind recount, no producer parser imports."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import Counter,defaultdict,deque
import gzip,hashlib,json,re
B=Path('tests/evidence/diagnostics/gen16-cpr');R=B/'independent-review'
ROOT='l_Lean1090_Diagnostics_CPRCosts_runCPR';P='lp_lean1090_Lean1090_Impl_';POL=P+'CPR_Policy_'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):
 p=Path(p);return json.loads(gzip.decompress(p.read_bytes()) if p.suffix=='.gz' else p.read_bytes())
def base(n):return re.split(r"'| \[clone ",n,maxsplit=1)[0]
raw=B/'retained/callgrind/callgrind.out.1.gz';a=read(B/'analysis/analysis.json.gz');d=read(B/'decoder-stages.json.gz');powers=read(B/'power-contexts.json')
names={};own=Counter();inc=Counter();calls=Counter();edges=Counter();edgecalls=Counter();allkeys=set();current=callee=None;isedge=False;summary={};pos=0
with gzip.open(raw,'rt') as f:
 def key(v):
  m=re.fullmatch(r'\((\d+)\)(?: (.*))?',v)
  if m:
   k=('id',m[1])
   if m[2] is not None:
    assert k not in names or names[k]==m[2];names[k]=m[2]
   return k
  return ('name',v)
 for line in f:
  line=line.strip()
  if line.startswith('positions:'):pos=len(line.split()[1:])
  elif line.startswith('events:'):assert line.split()[1:]==['Ir']
  elif line.startswith(('summary:','totals:')):
   k,v=line.split(':');summary[k]=int(v)
  elif line.startswith('fn='):current=key(line[3:]);allkeys.add(current)
  elif line.startswith('cfn='):callee=key(line[4:]);allkeys.add(callee)
  elif line.startswith('calls='):
   n=int(line.split('=',1)[1].split()[0]);calls[callee]+=n;edgecalls[(current,callee)]+=n;isedge=True
  elif line and (line[0].isdigit() or line[0] in '+-*'):
   fields=line.split();assert len(fields)==pos+1;cost=int(fields[-1])
   if isedge:inc[callee]+=cost;edges[(current,callee)]+=cost;isedge=False
   else:own[current]+=cost
assert not isedge
full=lambda k:names[k] if k[0]=='id' else k[1]
assert sum(own.values())==summary['summary']==summary['totals']==a['total_Ir']
assert hashlib.sha256(gzip.decompress(raw.read_bytes())).hexdigest()==a['raw_sha256']==powers['profile_sha256']==d['profile_sha256']
# Reachability is computed without propagating stage labels. Each complete raw
# caller string independently determines the stage from its root-to-leaf chain.
adj=defaultdict(set)
for (x,y),n in edges.items():
 if n:adj[x].add(y)
roots={k for k in allkeys if base(full(k))==ROOT};reachable=set(roots);q=deque(roots)
while q:
 x=q.popleft()
 for y in adj[x]:
  if y not in reachable:reachable.add(y);q.append(y)
num={'toFloat','haversineFloat','distanceFromFloat','positionFromFloats','nlFloat','moduloFloat','decodeLocalFloat','decodeGlobalFloat','numericalGeography'}
def chainstage(name):
 chain=name.split("'")
 if ROOT not in chain:return None
 path=[base(x) for x in reversed(chain[:chain.index(ROOT)])]
 stage='loop_output_control'
 for symbol in path:
  if symbol==P+'decode' or stage=='decoder':stage='decoder';continue
  if stage=='numeric_geography':continue
  if symbol.startswith(POL) and any(symbol==POL+n or symbol.startswith(POL+n+'___') for n in num):stage='numeric_geography';continue
  if symbol==POL+'validMotion':stage='motion_policy';continue
  if stage=='motion_policy':continue
  if symbol==POL+'stepAirborne':stage='airborne_pairing_policy';continue
  if symbol==POL+'stepSurface':stage='surface_reference_policy';continue
  if stage in {'airborne_pairing_policy','surface_reference_policy'}:continue
  if symbol==POL+'streamStep':stage='state_tracking_control';continue
  if 'CPRCosts_trackingReport' in symbol or 'CPRCosts_advance' in symbol:stage='tracking_projection'
 return stage
buckets=Counter();groups=defaultdict(Counter);selfcontexts={};recovered={};tagged={}
for k in allkeys:
 n=full(k);stage=chainstage(n)
 if k not in reachable:
  if own[k]:assert stage is not None,(n,own[k]);recovered[n]=(own[k],stage)
  else:continue
 assert stage is not None,(n,own[k])
 tagged[k]=stage
 buckets[stage]+=own[k]
 g=groups[(stage,base(n))];g['contexts']+=1;g['native_entries']+=calls[k];g['self_Ir']+=own[k];g['inclusive_Ir_non_additive']+=inc[k]
 if own[k]:selfcontexts[n]={'symbol':n,'stages':[stage],'bucket':stage,'self_Ir':own[k]}
assert buckets==Counter(a['exclusive_stages']),(buckets,a['exclusive_stages'])
assert not a['ambiguous_contexts']
assert selfcontexts=={r['symbol']:r for r in a['self_cost_contexts']}
assert recovered=={r['symbol']:(r['self_Ir'],r['stage']) for r in a['explicit_chain_recoveries']}
assert sum(v[0] for v in recovered.values())==sum(r['self_Ir'] for r in a['explicit_chain_recoveries'])
expected={(r['stage'],r['symbol']):{k:v for k,v in r.items() if k not in ['stage','symbol']} for r in a['helper_observations_non_additive']}
assert set(groups)==set(expected)
for key,g in groups.items():assert dict(g)==expected[key],(key,dict(g),expected[key])
assert sum(calls[k] for k in roots)==a['root_calls']==1
anchors=defaultdict(lambda:dict(native_entries=0,self_Ir=0,inclusive_Ir_non_additive=0,stages=set()))
for (stage,symbol),g in groups.items():
 if symbol.startswith(POL) or symbol in [ROOT,P+'decode']:
  t=anchors[symbol];t['stages'].add(stage)
  for key in ['native_entries','self_Ir','inclusive_Ir_non_additive']:t[key]+=g[key]
for t in anchors.values():t['stages']=sorted(t['stages'])
assert dict(anchors)==a['native_anchor_counts_and_non_additive_inclusive']
# Independently refine decoder nodes using retained root-to-leaf context order.
def decode_stage(n):
 chain=n.split("'");assert P+'decode' in chain
 stage='output_model_control'
 for symbol in reversed(chain[:chain.index(P+'decode')]):
  local=symbol.removeprefix(P)
  if 'Lean1090_Impl_Semantics_' in symbol or 'Lean1090_Impl_Presentation_' in symbol:stage='semantic_oracle_values'
  elif stage in ['commb_inference','semantic_oracle_values']:pass
  elif local in ['frameCommB','inferCommB','commBEligible','commBCoreEligible']:stage='commb_inference'
  elif local in ['frameADSB','decodeADSB','adsbHardValid']:stage='adsb_fields'
  elif local in ['frameAltitude','frameOracleAltitude','frameIdentity']:stage='semantic_oracle_values'
  elif local in ['decodeFrame','frameSyndrome','frameAddress','frameAccepted','frameAddressWithSyndrome','frameAcceptedWithSyndrome'] or symbol.startswith(P+'Parity_'):stage='frame_crc'
 return stage
dec=Counter();deccontexts={}
for n,r in selfcontexts.items():
 if r['bucket']=='decoder':
  st=decode_stage(n);dec[st]+=r['self_Ir'];deccontexts[n]={'symbol':n,'stage':st,'self_Ir':r['self_Ir']}
assert dec==Counter(d['exclusive_decoder_stages']) and sum(dec.values())==d['total_decoder_Ir']==buckets['decoder']
assert deccontexts=={r['symbol']:r for r in d['self_contexts']}
# Every actual direct powerTwo/pow edge and grouped total, no transitive summing.
prows=[];pgroups=defaultdict(Counter)
for (x,y),n in edges.items():
 if n and base(full(y)) in ['lean_nat_pow',P+'Binary64_powerTwo']:
  st=tagged[y];row={'stage':st,'caller':full(x),'callee':full(y),'calls':edgecalls[x,y],'inclusive_Ir_non_additive':n};prows.append(row)
  g=pgroups[st,base(full(y)),base(full(x))];g['calls']+=edgecalls[x,y];g['inclusive_Ir_non_additive']+=n
sortrows=lambda rs:sorted(rs,key=lambda x:json.dumps(x,sort_keys=True))
assert sortrows(prows)==sortrows(powers['full_context_edges'])
assert {(r['stage'],r['target'],r['direct_caller']):{'calls':r['calls'],'inclusive_Ir_non_additive':r['inclusive_Ir_non_additive']} for r in powers['grouped_direct_edges']}==dict(pgroups)
numeric=read(B/'numeric-contexts.json.gz')
wanted={'lean_nat_pow','lean_nat_gcd','l_Rat_mul','l_Rat_div','l_Rat_inv',POL+'toFloat',P+'Binary64_round',P+'Binary64_exponent',P+'Binary64_powerTwo'}
nrows=[];ngroups=defaultdict(Counter)
for (x,y),n in edges.items():
 if n and base(full(y)) in wanted:
  stage=tagged[y];row={'stage':stage,'caller':full(x),'callee':full(y),'calls':edgecalls[x,y],'inclusive_Ir_non_additive':n};nrows.append(row)
  ngroups[stage,base(full(y)),base(full(x))].update(calls=edgecalls[x,y],inclusive_Ir_non_additive=n)
assert sortrows(nrows)==sortrows(numeric['full_context_edges'])
assert {(r['stage'],r['target'],r['direct_caller']):{'calls':r['calls'],'inclusive_Ir_non_additive':r['inclusive_Ir_non_additive']} for r in numeric['grouped_direct_edges']}==dict(ngroups)
assert numeric['profile_sha256']==a['raw_sha256']
assert numeric['analysis_sha256']==hashlib.sha256(gzip.decompress((B/'analysis/analysis.json.gz').read_bytes())).hexdigest()
result={'status':'passed','profile_raw_sha256':a['raw_sha256'],'profile_container_sha256':sha(raw),'analysis_raw_sha256':hashlib.sha256(gzip.decompress((B/'analysis/analysis.json.gz').read_bytes())).hexdigest(),'analysis_container_sha256':sha(B/'analysis/analysis.json.gz'),'total_ir':sum(own.values()),'exclusive_stages':dict(buckets),'exclusive_decoder_stages':dict(dec),'positive_self_contexts':len(selfcontexts),'helper_groups':len(groups),'native_anchors':dict(anchors),'explicit_chain_recoveries':recovered,'recovery_total_ir':sum(v[0] for v in recovered.values()),'numeric_direct_edge_contexts':len(nrows),'numeric_direct_edge_groups':len(ngroups),'numeric_container_sha256':sha(B/'numeric-contexts.json.gz'),'direct_power_edge_contexts':len(prows),'direct_power_groups':len(pgroups),'power_group_rows':powers['grouped_direct_edges'],'script_sha256':sha(__file__),'limitations':['Independent parser and raw full caller strings; no production parser/analyzer imported.','Raw inclusive edge observations overlap and are not additive.','Root-unreachable positive-self nodes require the exact recorded root chain; their costs remain included, no cost dropped.']}
(R/'raw-recount.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items() if k not in ['native_anchors','power_group_rows','explicit_chain_recoveries']},indent=2))
