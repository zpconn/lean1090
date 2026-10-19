"""Compact readout of already retained semantic caller contexts; no native execution."""
import sys
sys.dont_write_bytecode=True
import collections,hashlib,json,pathlib,re
E=pathlib.Path('tests/evidence/diagnostics/gen23');P='lp_lean1090_Lean1090_Impl_'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
base=lambda s:re.split(r"'| \[clone ",s,maxsplit=1)[0]
a=json.loads((E/'analysis/analysis.json').read_text());p=json.loads((E/'priority-helper-contexts.json').read_text())
selected=[r for r in p['contexts'] if r['stage']=='semantic_oracle_values' and r['symbol']==P+'payloadValue']
groups={}
for r in selected:
 for edge in r['incoming']:
  key=(base(edge['caller']),'Semantics_commB' if P+'Semantics_commB' in edge['caller'] else 'Semantics_adsb' if P+'Semantics_adsb' in edge['caller'] else 'other')
  groups.setdefault(key,collections.Counter()).update(calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
rows=[{'direct_caller':k[0],'semantic_ancestor':k[1],**v} for k,v in sorted(groups.items())]
whole=next(r for r in p['rows'] if r['stage']=='semantic_oracle_values' and r['symbol']==P+'payloadValue')
assert sum(r['calls'] for r in rows)==whole['native_entries']
assert sum(r['inclusive_ir_non_additive'] for r in rows)==whole['incoming_inclusive_ir_non_additive']
commb=next(r for r in p['rows'] if r['stage']=='semantic_oracle_values' and r['symbol']==P+'Semantics_commB')
floats=[]
for family,profile in a['families'].items():
 for stage,helpers in profile['stage_helper_observations_non_additive'].items():
  for row in helpers:
   if 'oracleCommBFloats' in row['symbol'] or 'commBStandardFloats' in row['symbol']:
    floats.append({'family':family,'stage':stage,**row})
out={'status':'passed','kind':'retained_semantic_payload_callers_and_constructor_boundaries','bindings':{str(E/'analysis/analysis.json'):sha(E/'analysis/analysis.json'),str(E/'priority-helper-contexts.json'):sha(E/'priority-helper-contexts.json'),str(E/'independent-review/source-review.json'):sha(E/'independent-review/source-review.json'),'Impl/Semantics.lean':sha(pathlib.Path('Impl/Semantics.lean')),'Impl/Presentation.lean':sha(pathlib.Path('Impl/Presentation.lean')),str(pathlib.Path(__file__)):sha(pathlib.Path(__file__))},'payload_value_direct_callers':rows,'payload_value_total':{k:whole[k] for k in ('native_entries','self_ir','incoming_inclusive_ir_non_additive')},'semantic_commb':commb,'actual_float_constructor_helper_rows':floats,'contexts':selected,'limits':['Existing generated C shares standard tableValues and labels; the distinct oracle-value map remains a separate field lookup/decoding path. These observations do not claim duplicate standard value or label evaluation.','Actual Float-constructor symbol is Presentation_oracleCommBFloats. The extra unnamespaced oracleCommBFloats anchor is absent; the actual parent edges and complete helper records above are used instead. Standard Floats wrapper is inlined into its map loop.','These helpers construct exact numeric expressions, not newly introduced or separately executed hardware Float operations. The prior tested-only callback boundary is unchanged.','Rows retain exact native incoming edges. Ancestors and direct descendants overlap: do not add inclusive rows or claim all of an observed parent cost is removable. Only exclusive stage self totals are additive.','The full input equality and exception/correction semantics constrain any future reuse design. No optimization or timing prediction follows solely from this extraction.']}
target=E/'semantic-caller-contexts.json'
with target.open('x') as f:f.write(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(target),'direct_caller_rows':rows,'float_constructor_groups':len(floats)},indent=2))
