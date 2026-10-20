"""Verify the exact third-proof scope addition without executing controllers."""
from pathlib import Path
import ast,difflib,hashlib,json
from datetime import datetime,timezone
G=Path('tests/evidence/optimization/gen26');R=G/'independent-review';C=G/'integration/scope-correction-01'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 v=sha(p);check(h is None or v==h,'hash '+str(p));bindings[str(p)]=v
record=load(C/'correction.json');bind(C/'correction.json','8fc13d97d70c0a3a309c8df5e37422d3601d686d3f06656fe0d67b445027b150')
for p,row in record['before'].items():bind(row['retained'],row['sha256'])
for p,row in record['script_changes'].items():
 bind(p,row['after_sha256']);bind(row['diff'],row['diff_sha256']);old=Path(row['before']['retained']).read_text();new=Path(p).read_text();ast.parse(new)
 check(Path(row['diff']).read_text()==''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile=row['before']['retained'],tofile=p)),'exact scope diff '+p)
 expected=old.replace("'Impl/Binary64.lean', 'Proofs/Binary64Runtime.lean'","'Impl/Binary64.lean', 'Proofs/Binary64Runtime.lean', 'Proofs/BDS50.lean'").replace("'Proofs.Decoder', 'Proofs.CPRTracking',","'Proofs.Decoder', 'Proofs.CPRTracking', 'Proofs.BDS50',")
 if p.endswith('validate_build.py'):
  expected=expected.replace("'Lean1090.Proofs.Binary64Runtime.round_small_dyadic'}","'Lean1090.Proofs.Binary64Runtime.round_small_dyadic',\n                'Lean1090.Proofs.BDS50.refinement',\n                'Lean1090.Proofs.BDS50.pilot_nonvacuous',\n                'Lean1090.Proofs.BDS50.exact_threshold_nonvacuous'}")
 check(new==expected,'only explicit BDS50 source, target and required facts '+p)
for p,h in record['current_preparations'].items():bind(p,h)
oldprep=load(C/'before/preparation.json');prep=load(G/'preparation.json')
for key in ['helpers','adaptations','seed_selection','expected_fresh_source_count','expected_gate_input_count','source_inventory_check','history_bindings','unchanged_generator_inputs']:
 check(prep[key]==oldprep[key],'unchanged fresh '+key)
for name,row in prep['adaptations'].items():bind(row['path'],row['sha256'])
check(prep['selected_scope']['existing_proofs']==['Proofs/Binary64Runtime.lean','Proofs/BDS50.lean'],'strict three-file fresh scope')
bind(G/'seed-selection.json',record['unchanged_seed_selection_sha256'])
for p,h in prep['existing_fixed_preparation_preserved'].items():bind(p,h)
bind(record['root_retained_attempts'],record['root_retention_sha256'])
repair=load(R/'bds50-repair-review.json');bind(R/'bds50-repair-review.json');check(repair['status']=='passed' and not repair['findings'],'independent exact proof-body repair review')
result={'status':'passed_read_only_preparation_review','checked_utc':datetime.now(timezone.utc).isoformat(),'checks':len(checks),'check_labels':checks,'findings':[],'bindings':bindings,'assessment':'Executed attempt-1 records and first full-gate failure remain preserved. The combined command now explicitly compiles BDS50, binds all three actual changed sources and requires all three BDS50 printed contracts. Every other controller byte, all counts and the seven fresh helpers/seeds are unchanged. No controller or workload executed by reviewer.'}
p=R/'scope-correction-review.json'
with p.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':result['status'],'checks':len(checks),'sha256':sha(p)}))
