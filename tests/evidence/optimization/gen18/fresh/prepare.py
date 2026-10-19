#!/usr/bin/env python3
"""Record fresh seeds and adapt reviewed campaign controllers, without running them."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,hashlib,json,secrets,subprocess
G=Path('tests/evidence/optimization/gen18');P=G/'fresh';C=Path('.cache/gen18-gate');old=Path('tests/evidence/optimization/gen17')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def write(p,x):
 assert not p.exists();p.write_text(json.dumps(x,indent=2)+'\n')
now=lambda:datetime.now(timezone.utc).isoformat()
assert not (P/'fresh-seeds.json').exists() and not C.exists()
prior=json.loads((old/'fresh-seeds.json').read_text());seed_paths=set(prior['historical_seed_records_sha256'])|{str(old/'fresh-seeds.json')};seen=set();bindings={}
for name in sorted(seed_paths):
 j=json.loads(Path(name).read_text());bindings[name]=sha(name)
 for k,v in j.items():
  if 'seed' in k and isinstance(v,int):seen.add(v)
def draw():
 while True:
  n=secrets.randbits(32)
  if n not in seen:seen.add(n);return n
m,c=draw(),draw();C.mkdir()
commands=[['lake','env','lean','--run','scripts/FuzzCommB.lean',str(C/'fresh-commb.csv'),'100000',str(c)],['python3','-B','scripts/check_commb_fuzz.py',str(C/'fresh-commb.csv'),str(P/'fresh-commb-coverage.json')],['python3','-B','scripts/check_message_differential.py','--corpus','--generated','10000000','--seed',str(m),'--commb-boundaries',str(C/'fresh-commb.csv'),'--diagnostic','--output',str(P/'fresh-message')]]
seed={'recorded_utc':now(),'message_seed':m,'commb_seed':c,'sampling':'Independent secrets.randbits(32) draws before fixture generation; prior recorded seeds and mutual collisions rejected.','historical_seed_values_checked':len(seen)-2,'historical_seed_records_sha256':bindings,'generated_messages':10000000,'random_commb_assignments':100000,'additional_commb_strata':prior['additional_commb_strata'],'head_before_run':subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),'source_sha256':{n:sha(n) for n in prior['source_sha256']},'commands':commands,'authorization_note':'Gen18 selected only after reviewed gen17 decode and CPR diagnostics. Preparation is not launch authorization: integrated build, current source/binary/helper preflight and explicit root release required.','cache_prepared_before_generation':{'path':str(C),'prepared_utc':now(),'previously_absent':True,'initial_entries':[]},'selected_scope':{'runtime':'Impl/CPRFloat.lean','new_proofs':['Proofs/Binary64Dyadic.lean','Proofs/CPRFloatFast.lean'],'integration':'Proofs/CPRTracking.lean','concept':'Exact guarded small-dyadic bit packing with unchanged software-binary64 conversion fallback.'}}
write(P/'fresh-seeds.json',seed)
helpers={}
for name in ['fresh-orchestrate.py','fresh-run-campaign.py','fresh-verify.py','fresh-retained-hashes.py']:
 src=old/name;dst=P/name;assert not dst.exists();s=src.read_text().replace('gen17','__CURRENT__').replace('gen16','gen17').replace('__CURRENT__','gen18').replace("Path('tests/evidence/optimization/gen18')","Path('tests/evidence/optimization/gen18/fresh')").replace('==113','==115')
 if name=='fresh-orchestrate.py':s=s.replace("build=p/'integration/targeted-build.json'","build=p.parent/'integration/targeted-build.json'").replace("sha(p/'integration/targeted-build.log')","sha(p.parent/'integration/targeted-build.log')")
 ast.parse(s);dst.write_text(s);helpers[str(dst)]={'sha256':sha(dst),'reused_from':str(src),'prior_sha256':sha(src)}
prep={'status':'prepared_not_executed','recorded_utc':now(),'seed_record_sha256':sha(P/'fresh-seeds.json'),'helpers':helpers,'expected_fresh_source_count':115,'expected_gate_input_count':190,'expected_binaries':3,'new_source_modules':seed['selected_scope']['new_proofs'],'inventory_policy':'Launcher unions prior sealed membership with all current Impl/Model/Spec/Proofs/CLI/Tests Lean files, then requires exact root preflight equality. New modules must be staged before gate inventory.','prior_csv_rows':len(list(csv.DictReader(Path('bench/results.csv').open()))),'prior_csv_sha256':sha('bench/results.csv'),'history_bindings':{str(p):sha(p) for p in [old/'fresh-retained-hashes.json',Path('bench/runs/gen17/results-review.json'),Path('tests/evidence/diagnostics/gen17/independent-review/independent-review.json'),Path('tests/evidence/diagnostics/gen17-cpr/independent-review/independent-review.json')]},'source_inventory_prior':{'path':str(old/'fresh-message-run.json'),'sha256':sha(old/'fresh-message-run.json')},'syntax_validation':'Four adapted helpers parsed with ast.parse; no import or execution.','adaptations':['Generation/count/path bindings only.','Successful 33-member retention is wholly within gen18/fresh/. Integration proof record remains at gen18/integration/.'],'cleanup_policy':'Seal compressed evidence, independent retention replay and frozen compare-only replay before exact selected fresh scratch cleanup. Protect active fixed gate, preserve unique failures; no broad scratch scan.','no_campaign_started':True,'preparer_sha256':sha(__file__)}
assert prep['prior_csv_rows']==36;write(P/'preparation.json',prep)
print(json.dumps({'status':'prepared_not_executed','message_seed':m,'commb_seed':c,'seed_record_sha256':sha(P/'fresh-seeds.json'),'preparation_sha256':sha(P/'preparation.json'),'expected_fresh_sources':115,'expected_gate_inputs':190}))
