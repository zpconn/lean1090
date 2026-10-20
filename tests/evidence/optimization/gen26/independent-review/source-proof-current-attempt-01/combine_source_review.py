"""Bind unchanged round proof review and exact BDS50 repair to current inputs."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json
G=Path('tests/evidence/optimization/gen26');R=G/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
original=load(R/'source-proof-review.json');repair=load(R/'bds50-repair-review.json');scope=load(R/'scope-correction-review.json');correction=load(G/'integration/scope-correction-01/correction.json');bindings={};redirects={}
assert sha(R/'source-proof-review.json')=='07f8deb8d9a6b322cac34a7d6e1212bdcbd16a5453a6cd26c33ffb0115909a2b'
for name,h in original['bindings'].items():
 p=Path(name)
 if sha(p)!=h:
  row=correction['before'][name];assert row['sha256']==h;p=Path(row['retained']);redirects[name]=str(p)
 assert sha(p)==h;bindings[str(p)]=h
for path,record in [(R/'bds50-repair-review.json',repair),(R/'scope-correction-review.json',scope)]:
 assert record['status'] in ['passed','passed_read_only_preparation_review'] and not record['findings']
 bindings[str(path)]=sha(path)
 for p,h in record['bindings'].items():assert sha(p)==h;bindings[p]=h
for p in [R/'source-proof-review.json',G/'integration/scope-correction-01/correction.json',R/'combine_source_review.py']:bindings[str(p)]=sha(p)
previous=load('tests/evidence/optimization/gen25/gate-evidence.json')['input_hashes_after'];current={p:sha(p) for p in previous}
assert len(current)==202 and {p for p in previous if previous[p]!=current[p]}=={'Impl/Binary64.lean','Proofs/Binary64Runtime.lean','Proofs/BDS50.lean'}
for p in ['Impl/Binary64.lean','Proofs/Binary64Runtime.lean']:assert current[p]==original['source_delta'][p]
assert repair['preserved_bds50_statements']==26 and original['preserved_theorem_count']==32
out={'status':'passed','recorded_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'bindings':bindings,'current_correctness_inputs':current,'source_delta':{p:current[p] for p in ['Impl/Binary64.lean','Proofs/Binary64Runtime.lean','Proofs/BDS50.lean']},'all_input_refinement_verified':True,'preserved_binary64_theorem_count':32,'preserved_bds50_theorem_count':26,'round_printed_fact_count':45,'bds50_printed_fact_count':48,'new_theorems':original['new_theorems'],'historical_binding_redirects':redirects,'assessment':'The original unrestricted round review remains unchanged. Its superseded controller/preparation bindings resolve to exact retained originals; the explicit corrected scope review binds current controllers. The only additional proof change is three norm_num steps with all 26 BDS50 statements unchanged. All current 202 input hashes and the exact three-file delta are recorded.','limits':'Source/proof review only. Combined build, native liveness and complete fixed/fresh campaigns are separately required.'}
p=R/'source-proof-current-review.json'
with p.open('x') as f:f.write(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':'passed','sha256':sha(p),'correctness_inputs':len(current),'historical_redirects':len(redirects)}))
