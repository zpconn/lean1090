#!/usr/bin/env python3
"""Direct live packFields context comparison; existing profiles only."""
import sys
sys.dont_write_bytecode = True
from collections import Counter
import hashlib,importlib.util,json
from pathlib import Path
E=Path('tests/evidence/diagnostics/gen23')
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p): return json.loads(Path(p).read_text())
source=read(E/'independent-review/source-review.json')
assert source['pack_fields_shift_mask_verified']
assert source['raw_word_syndrome_live_path_verified'] and source['pack_fields_fold_anchor'] is None
HISTORICAL_ANCHOR=Path('tests/evidence/diagnostics/gen21/independent-review/source-review.json')
SYMBOL=read(HISTORICAL_ANCHOR)['pack_fields_fold_anchor']
p=Path('review/diagnostics/analyze_callgrind.py')
spec=importlib.util.spec_from_file_location('gen23_pack_parser',p);m=importlib.util.module_from_spec(spec);sys.modules[spec.name]=m;spec.loader.exec_module(m)
generations=[]
for generation in (22,23):
 root=Path(f'tests/evidence/diagnostics/gen{generation}'); rows=[];combined={};total=Counter(entry_calls=0,self_ir=0,incoming_inclusive_ir=0)
 for family in ('adsb','commb','other'):
  path=root/'callgrind'/family/'callgrind.out.1.gz';profile=m.parse(path);contexts=[];children={};counts=Counter(entry_calls=0,self_ir=0,incoming_inclusive_ir=0)
  for name,node in profile.nodes.items():
   if m.base_name(name)!=SYMBOL:continue
   own=node.own.get('Ir',0)
   incoming_calls=sum(n.calls.get(name,0) for n in profile.nodes.values())
   incoming_ir=sum(n.edges.get(name,{}).get('Ir',0) for n in profile.nodes.values())
   direct=[]
   for child,events in node.edges.items():
    symbol=m.base_name(child);calls=node.calls.get(child,0);ir=events.get('Ir',0)
    direct.append({'context':child,'symbol':symbol,'calls':calls,'inclusive_ir':ir})
    children.setdefault(symbol,Counter()).update(calls=calls,inclusive_ir=ir)
    combined.setdefault(symbol,Counter()).update(calls=calls,inclusive_ir=ir)
   assert own+sum(row['inclusive_ir'] for row in direct)==incoming_ir
   contexts.append({'context':name,'entry_calls':incoming_calls,'self_ir':own,'incoming_inclusive_ir':incoming_ir,'direct_children':direct})
   counts.update(entry_calls=incoming_calls,self_ir=own,incoming_inclusive_ir=incoming_ir)
  native=next(json.loads(line) for line in (root/'native'/f'{family}.jsonl').read_text().splitlines() if json.loads(line).get('phase')=='result')
  assert counts['entry_calls']==0
  total.update(counts);rows.append({'family':family,**counts,'direct_children':children,'contexts':contexts,'profile_sha256':sha(path)})
 assert total['entry_calls']==0
 c=root/'generated-c/Impl/Bits.c';lines=c.read_text().splitlines();start=next(i for i,line in enumerate(lines) if line.startswith('LEAN_EXPORT lean_object* '+SYMBOL+'(') and line.endswith('{'));end=next(i for i in range(start+1,len(lines)) if lines[i].startswith('LEAN_EXPORT '))
 generations.append({'generation':generation,'rows':rows,'total':dict(total),'direct_children_total':combined,'generated_c':{'path':str(c),'sha256':sha(c),'start_line':start+1,'end_line':end,'source':'\n'.join(lines[start:end])+'\n'}})
output={'status':'passed','kind':'existing_profile_pack_fields_direct_native_context_comparison','generations':generations,'symbol':SYMBOL,'same_fold_entry_populations':True,'historical_anchor_source_sha256':sha(HISTORICAL_ANCHOR),'raw_word_path_zero_collected_packing_entries':True,'source_review_sha256':sha(E/'independent-review/source-review.json'),'analysis_sha256':sha(E/'analysis/analysis.json'),'extractor_sha256':sha(__file__),'parser_sha256':sha(p),'limits':['Each direct-child inclusive sum plus self reconciles to this nonrecursive loop entry. It overlaps exclusive stages and other nested costs.','Native helper calls observe only actual non-inlined boundaries, not all semantic operations. Narrow machine masks and small shifts may inline.','The symbol name is bound to the historical generation21 linked fold; both current compared generated-C definitions preserve generic power/modulus. Both raw-word decoders have no collected packing entries and no linked standalone pack fold; absence alone is not a zero-inlined-work proof, so the source review must independently establish the direct path.','Only the three disjoint family profiles are summed within each generation. No timing or speedup prediction is made.']}
out=E/'pack-fields-direct-costs.json';assert not out.exists();out.write_text(json.dumps(output,indent=2)+'\n')
print(json.dumps({'status':'passed','generations':[{'generation':g['generation'],'total':g['total'],'direct_children_total':g['direct_children_total']} for g in generations],'sha256':sha(out)}))
