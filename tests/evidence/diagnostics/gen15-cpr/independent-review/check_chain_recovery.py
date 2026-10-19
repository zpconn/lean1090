#!/usr/bin/env python3
"""Independent read-only assessment of the CPR explicit-chain correction."""
import sys
sys.dont_write_bytecode = True
from collections import Counter, deque
from datetime import datetime, timezone
import gzip
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT=Path.cwd()
E=ROOT/'tests/evidence/diagnostics/gen15-cpr'
OUT=E/'independent-review/chain-recovery-review.json'
sys.path.insert(0,str(ROOT/'review/diagnostics'))

def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()
def load(path,name):
    spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);sys.modules[name]=m;spec.loader.exec_module(m);return m

source=ROOT/'review/diagnostics/analyze_cpr_costs.py'
m=load(source,'independent_cpr_chain_current')
oldpath=E/'analysis-attempt01/analyze_cpr_costs.py'
old=load(oldpath,'independent_cpr_chain_old')
assert sha(oldpath)==json.loads((E/'analysis-attempt01/failure.json').read_text())['source_sha256']
fixture=m.fixtures();assert fixture['status']=='passed' and fixture['cases']==8
extra=[]
for foreign in (m.ROOT_SYMBOL+'_suffix','prefix_'+m.ROOT_SYMBOL,'foreign_root'):
    assert m.explicit_chain_stage("libm'"+foreign) is None
    extra.append('reject explicit non-exact root atom '+foreign)

def node(name,cost):
    n=m.parser.Node(name);n.own['Ir']=cost;return n
r=node(m.ROOT_SYMBOL,1);d=node(m.PREFIX+'decode',2);s=node(m.POLICY+'streamStep',3);a=node("allocator'"+m.ROOT_SYMBOL,7)
for parent,child,cost in [(r,d,9),(r,s,10),(d,a,7),(s,a,7)]:
    parent.edges[child.name]['Ir']=cost;parent.calls[child.name]=1
p=m.parser.Profile(Path('independent-ambiguous-chain'),['Ir'],{n.name:n for n in (r,d,s,a)},Counter(Ir=13),{})
result=m.analyze(p)
assert result['exclusive_stages']['shared_ambiguous']==7 and not result['explicit_chain_recoveries']
extra.append('explicit chain cannot override an existing ambiguous graph attribution')
profile_path=E/'retained/callgrind/callgrind.out.1.gz'
profile=m.parser.parse(profile_path)
root_names={name for name in profile.nodes if m.parser.base_name(name)==m.ROOT_SYMBOL}
reachable=set();queue=deque(root_names)
while queue:
    name=queue.popleft()
    if name in reachable:continue
    reachable.add(name)
    queue.extend(child for child,cost in profile.nodes[name].edges.items() if any(cost.values()))
orphan={name:node.own['Ir'] for name,node in profile.nodes.items() if name not in reachable and node.own['Ir']}
assert len(orphan)==6 and sum(orphan.values())==253
saved=json.loads(gzip.decompress((E/'analysis-reviewed/analysis.json.gz').read_bytes()))
assert orphan=={row['symbol']:row['self_Ir'] for row in saved['explicit_chain_recoveries']}
for name in orphan:
    chain=name.split("'")
    assert m.ROOT_SYMBOL in chain
    assert m.PREFIX+'decode' not in chain
    assert any(part in (m.POLICY+'haversineFloat',m.POLICY+'decodeGlobalFloat') for part in chain)
    assert all(not profile.nodes[parent].edges.get(name,{}).get('Ir',0) for parent in reachable)
    assert m.explicit_chain_stage(name)=='numeric_geography'
internal_edges=[{'caller':parent,'callee':name,'calls':node.calls.get(name,0),'inclusive_Ir':node.edges[name]['Ir']} for name in orphan for parent,node in profile.nodes.items() if node.edges.get(name,{}).get('Ir',0)]
assert len(internal_edges)==2 and sorted(row['inclusive_Ir'] for row in internal_edges)==[109,111]
try:old.analyze(profile)
except ValueError as error:assert str(error)=='nonzero events outside collected root'
else:raise AssertionError('retained original analyzer did not reproduce its rejected outside-root costs')
checked=m.analyze(profile)
assert checked['exclusive_stages']==saved['exclusive_stages']
assert checked['total_Ir']==saved['total_Ir']==sum(n.own['Ir'] for n in profile.nodes.values())
assert checked['explicit_chain_recoveries']==saved['explicit_chain_recoveries']
assert checked['exclusive_stages'].get('outside_root',0)==0
bindings=[source,oldpath,E/'analysis-attempt01/execution.log',E/'analysis-attempt01/failure.json',E/'analysis-reviewed/analyzer-used.py',E/'analysis-reviewed/analysis.json.gz',E/'analysis-reviewed/fixture-checks.json',profile_path,Path(__file__),E/'independent-review/chain-recovery-attempt01/check_chain_recovery.py',E/'independent-review/chain-recovery-attempt01/chain-recovery-review.stdout',E/'independent-review/chain-recovery-attempt01/chain-recovery-review.stderr']
assert sha(source)==sha(E/'analysis-reviewed/analyzer-used.py')
assert not OUT.exists()
record={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],
        'author_fixtures_reexecuted':8,'independent_extra_controls':extra,
        'unreachable_self_contexts':6,'recovered_self_Ir':253,'total_self_Ir':checked['total_Ir'],
        'raw_graph_unreachable_contexts':orphan,'positive_edges_between_unreachable_contexts':internal_edges,
        'wording_clarification': 'The archived basis phrase no positive incoming graph edge is too strong for two contexts. The exact checked condition is no positive incoming path from the collection root. Two internal positive edges among unreachable nodes are retained below; all six stages and 253 self Ir remain unchanged. This record clarifies the preserved producer evidence without rewriting it.',
        'checks':['The root match is an exact retained caller-chain atom, not a substring or inferred function-name similarity.',
                  'Positive-edge graph propagation runs first; existing unique/ambiguous labels are never overwritten.',
                  'Only previously unlabeled nonzero self costs can recover; root-to-leaf transitions are the same as the ordinary propagation.',
                  'Independent graph reachability found exactly the six retained raw contexts; every one explicitly includes the root plus a geographic kernel and has no positive incoming path from the collection root.',
                  'The original analyzer reproduces the retained outside-root failure; the corrected self total/stages match the sealed result without changing raw counts.',
                  'Foreign explicit roots and other unassigned self costs continue to reject; ambiguity remains visible.'],
        'limits':['This is a read-only source/fixture/retained-profile check, not a native execution or timing result.',
                  'Recovery assigns existing self events only. Missing call edges are not synthesized; absent observed entry/inclusive counts where no edge was recorded are missing observations, not absence of executed work.',
                  'The complete independent raw/archive/report review remains owned by payload_roundtrips.'],
        'bindings':{str(p.relative_to(ROOT)):{'sha256':sha(p),'bytes':p.stat().st_size} for p in bindings}}
OUT.write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'status':'passed','author_fixtures':8,'independent_controls':len(extra),'orphan_contexts':6,'self_Ir':253,'sha256':sha(OUT)}))
