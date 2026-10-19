import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import Counter
import hashlib,json,re
out=Path(__file__).parent;blocks=[b for b in (out/'script.txt').read_text().split('\n\n') if b.strip()]
stages=Counter();leaves=Counter();allleaves=Counter();excluded=Counter();nested=Counter();records=[];unknown=0
for i,block in enumerate(blocks):
 lines=block.splitlines();period=re.search(r':\s+(\d+) cpu-clock:u:',lines[0]);assert period
 frames=[]
 for line in lines[1:]:
  m=re.match(r'^\s*([0-9a-f]+)\s+(.*?)\s+\((.*?)\)\s*$',line)
  if m:frames.append({'ip':m[1],'symbol':re.sub(r'\+0x[0-9a-f]+$','',m[2]),'dso':m[3]})
 symbols=[f['symbol'] for f in frames];leaf=symbols[0] if symbols else 'no_frames';allleaves[leaf]+=1
 unknown+=int('[unknown]' in symbols)
 if not any('runCPROnce' in s for s in symbols):excluded['no visible frozen runCPROnce ancestor']+=1;continue
 if any('WholeDecoder_consume' in s for s in symbols):excluded['post-clock retained-output consumer']+=1;continue
 if 'lp_lean1090_Lean1090_Impl_decode' in symbols:stage='decoder'
 elif any('Lean1090_Impl_CPR_Policy_' in s for s in symbols):stage='CPR policy or numerical geography'
 elif any('trackingReport' in s or 'WholeDecoder_advance' in s for s in symbols):stage='tracking projection or unresolved advance'
 else:stage='loop, output control or erased ancestry'
 stages[stage]+=1;leaves[leaf]+=1
 for name,condition in [('software binary64',any('Impl_Binary64_' in s for s in symbols)),('rational arithmetic',any('Rat_' in s for s in symbols)),('haversine',any('haversineFloat' in s for s in symbols)),('global position',any('decodeGlobalFloat' in s for s in symbols)),('local position',any('decodeLocalFloat' in s for s in symbols)),('motion checks',any('validMotion' in s for s in symbols))]:
  if condition:nested[name]+=1
 records.append({'sample_index':i,'period':int(period.group(1)),'stage':stage,'leaf':leaf,'stack':frames})
header=(out/'report-self.txt').read_text();m=re.search(r'^# Total Lost Samples:\s*(\d+)',header,re.M);assert m
summary={'status':'passed','classification':'One-pass cpu-clock sampling of the actual frozen CPR worker; diagnostic, not benchmark','total_samples':len(blocks),'visible_CPR_loop_samples':len(records),'excluded_samples':sum(excluded.values()),'excluded_by_visible_context':dict(excluded),'all_samples_with_unknown_frame':unknown,'included_unknown_leaves':leaves['[unknown]'],'all_unknown_leaves':allleaves['[unknown]'],'reported_lost_samples':int(m.group(1)),'disjoint_visible_stages':dict(stages),'nested_overlapping_categories':dict(nested),'included_leaf_top30':leaves.most_common(30),'all_leaf_top30':allleaves.most_common(30),'limitations':['Inclusion requires a visible frozen runCPROnce ancestor; missing, truncated or tail-eliminated frames can exclude workload samples.','Post-clock consume frames are excluded when visible. Loop/control with erased ancestry remains explicit, not assigned by assumption.','Conditional sample shares are not whole-workload timing shares or instruction counts. Inclusive nested categories overlap.','Module startup, including exact field-code table initialization, happens before the loop and is outside its visible sample subset.','The actual worker executed one run on CPU0 after both diagnostic builds, with all other native/profile jobs held. No comparative timing claim.']}
assert len(records)==sum(stages.values()) and len(blocks)==len(records)+sum(excluded.values())
(out/'analysis.json').write_text(json.dumps(summary,indent=2)+'\n');(out/'loop-samples.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in records));print(json.dumps(summary,indent=2))
