#!/usr/bin/env python3
"""Retain selected gen14 raw-call observations without rerunning any workload."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import Counter, defaultdict
import importlib.util, hashlib, json
O=Path(__file__).resolve().parent
parser=Path('review/diagnostics/analyze_callgrind.py')
spec=importlib.util.spec_from_file_location('gen15_selection_existing_raw',parser)
m=importlib.util.module_from_spec(spec);sys.modules[spec.name]=m;spec.loader.exec_module(m)
path=Path('tests/evidence/diagnostics/gen14/callgrind/commb/callgrind.out.1.gz')
p=m.parse(path);rows=[]
for suffix in ['bdsWireValid','cbValid50','cbValid60','cbValid18','cbValid19']:
 symbol=m.PREFIX+suffix;names={n for n in p.nodes if m.base_name(n)==symbol};direct=defaultdict(Counter)
 entries=own=inclusive=0
 for name in names:
  own+=p.nodes[name].own.get('Ir',0)
  for caller in p.nodes.values():
   entries+=caller.calls.get(name,0);inclusive+=caller.edges.get(name,{}).get('Ir',0)
  for callee,events in p.nodes[name].edges.items():
   if any(events.values()):direct[m.base_name(callee)].update(calls=p.nodes[name].calls[callee],incoming_inclusive_ir_non_additive=events.get('Ir',0))
 rows.append({'symbol':symbol,'native_entries':entries,'self_ir':own,'incoming_inclusive_ir_non_additive':inclusive,'direct_children':[{'symbol':k,**v} for k,v in sorted(direct.items(),key=lambda kv:kv[1]['incoming_inclusive_ir_non_additive'],reverse=True)]})
wire=rows[0];cstr=next(x for x in wire['direct_children'] if x['symbol']=='lean_cstr_to_nat')
assert wire['native_entries']==cstr['calls']==627880 and cstr['incoming_inclusive_ir_non_additive']==484723360
c=Path('tests/evidence/diagnostics/gen14/generated-c/Impl/CommB.c');text=c.read_text();needle='v___x_1048_ = lean_cstr_to_nat("72057594037927936");'
assert needle in text
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
r={'kind':'selection_observations_from_existing_gen14_raw_profile','profile':str(path),'profile_sha256':sha(path),'parser_sha256':sha(parser),'script_sha256':sha(__file__),'generated_C':str(c),'generated_C_sha256':sha(c),'literal_source_line':text[:text.index(needle)].count('\n')+1,'literal_source':needle,'rows':rows,'limits':'No new native execution or instruction measurement. Direct incoming inclusive costs overlap caller totals and nested calls; no timing gain is predicted. Literal cost is from one Comm-B family profile, whose bdsWireValid population is the complete retained scoped corpus population.'}
p=O/'selection-costs.json';assert not p.exists();p.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(p),'literal_calls':cstr['calls'],'literal_inclusive_ir':cstr['incoming_inclusive_ir_non_additive']}))
