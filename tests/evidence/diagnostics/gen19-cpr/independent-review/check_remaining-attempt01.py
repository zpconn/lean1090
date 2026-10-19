#!/usr/bin/env python3
"""Additional independent raw recount for the late conversion supplement."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import ast,json,hashlib
from collections import defaultdict,Counter
R=Path('tests/evidence/diagnostics/gen19-cpr/independent-review');B=R.parent
source=(R/'check_raw.py').read_text();tree=ast.parse(source)
# Reuse our independent parser/checks, stopping before its sealed output write.
stop=next(i for i,n in enumerate(tree.body) if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='result' for t in n.targets))
ns={'__file__':str(R/'check_raw.py')};exec(compile(ast.Module(body=tree.body[:stop],type_ignores=[]),str(R/'check_raw.py'),'exec'),ns)
sha=ns['sha'];read=ns['read'];base=ns['base'];full=ns['full'];P=ns['P'];rec=read(B/'remaining-conversion-contexts.json');s=read(R/'source-review.json')
selected={P+n for n in ['Binary64_fromBits','Binary64_round','Binary64_exponent','CPR_Policy_toFloat','CPR_Policy_toFloatFallback']}
rows=[];groups=defaultdict(Counter)
for x,y in set(ns['edges'])|set(ns['edgecalls']):
 cost=ns['edges'][x,y];calls=ns['edgecalls'][x,y];target=base(full(y))
 if target not in selected or not(cost or calls):continue
 stage=ns['tagged'][y];under=s['dyadic_to_float_fallback_anchor'] in [base(z) for z in full(x).split("'")]
 row=dict(stage=stage,target=target,caller=full(x),callee=full(y),direct_caller=base(full(x)),under_fallback=under,calls=calls,inclusive_Ir_non_additive=cost);rows.append(row)
 groups[stage,target,base(full(x)),under].update(calls=calls,inclusive_Ir_non_additive=cost)
canonical=lambda xs:sorted(xs,key=lambda x:json.dumps(x,sort_keys=True))
assert canonical(rows)==canonical(rec['full_context_edges'])
assert dict(groups)=={(r['stage'],r['target'],r['direct_caller'],r['under_fallback']):Counter(calls=r['calls'],inclusive_Ir_non_additive=r['inclusive_Ir_non_additive']) for r in rec['grouped_direct_edges']}
helpers=[dict(stage=key[0],symbol=key[1],**g) for key,g in ns['groups'].items() if key[1] in selected]
assert canonical(helpers)==canonical(rec['helper_rows_non_additive'])
fallback=sum(r['calls'] for r in rows if r['target']==s['dyadic_to_float_fallback_anchor']);assert fallback==rec['actual_fallback_calls_inside_root']==0
assert all(r['direct_caller']==s['dyadic_to_float_anchor'] for r in rows if r['target']==s['dyadic_to_float_fallback_anchor'])
assert s['dyadic_to_float_live_path_verified'] and s['dyadic_to_float_at_most_one_fallback_per_entry'] and s['dyadic_to_float_zero_case_verified']
for name,path in [('profile',B/'retained/callgrind/callgrind.out.1.gz'),('analysis',B/'analysis/analysis.json.gz'),('source_review',R/'source-review.json'),('extractor',B/'extract_remaining_contexts.py'),('parser',Path('review/diagnostics/analyze_callgrind.py'))]:assert sha(path)==rec[name+'_sha256']
assert rec['raw_profile_sha256']==ns['a']['raw_sha256']
assert read(B/'remaining-conversion-contexts.log')==dict(status='passed',helper_rows=len(helpers),direct_groups=len(groups),fallback_calls=fallback,sha256=sha(B/'remaining-conversion-contexts.json'))
result=dict(status='passed',script_sha256=sha(__file__),independent_parser_sha256=sha(R/'check_raw.py'),supplement_sha256=sha(B/'remaining-conversion-contexts.json'),raw_profile_sha256=ns['a']['raw_sha256'],helper_rows=len(helpers),direct_groups=len(groups),raw_context_edges=len(rows),actual_fallback_calls=fallback,helper_rows_non_additive=helpers,limits=['Wrapper-minus-fallback includes zero and admitted dyadics; no separate population claim.','Complete actual direct edges and helper groups independently recounted; inclusive costs overlap.'])
p=R/'remaining-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items() if k!='helper_rows_non_additive'},indent=2))
