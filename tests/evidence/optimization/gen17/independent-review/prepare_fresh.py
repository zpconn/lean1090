#!/usr/bin/env python3
"""Prepare only fresh campaign metadata; no native command or helper import."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,hashlib,json,secrets,subprocess
P=Path('tests/evidence/optimization/gen17');R=P/'independent-review';C=Path('.cache/gen17-gate');previous=Path('tests/evidence/optimization/gen16')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
now=lambda:datetime.now(timezone.utc).isoformat()
assert not (P/'fresh-seeds.json').exists() and not (R/'preparation.json').exists()
assert not C.exists()
old=json.loads((previous/'fresh-seeds.json').read_text());seed_paths=set(old['historical_seed_records_sha256'])|{str(previous/'fresh-seeds.json')};seen=set();seed_hashes={}
for name in sorted(seed_paths):
 value=json.loads(Path(name).read_text());seed_hashes[name]=sha(name)
 for k,v in value.items():
  if 'seed' in k and isinstance(v,int):seen.add(v)
def draw():
 while True:
  n=secrets.randbits(32)
  if n not in seen:seen.add(n);return n
message,commb=draw(),draw();C.mkdir(parents=True)
commands=[['lake','env','lean','--run','scripts/FuzzCommB.lean',str(C/'fresh-commb.csv'),'100000',str(commb)],['python3','-B','scripts/check_commb_fuzz.py',str(C/'fresh-commb.csv'),str(P/'fresh-commb-coverage.json')],['python3','-B','scripts/check_message_differential.py','--corpus','--generated','10000000','--seed',str(message),'--commb-boundaries',str(C/'fresh-commb.csv'),'--diagnostic','--output',str(P/'fresh-message')]]
seeds={'recorded_utc':now(),'message_seed':message,'commb_seed':commb,'sampling':'Separate secrets.randbits(32) draws before fixture generation; all recorded historical seed values and mutual collisions rejected.','historical_seed_values_checked':len(seen)-2,'historical_seed_records_sha256':seed_hashes,'generated_messages':10000000,'random_commb_assignments':100000,'additional_commb_strata':old['additional_commb_strata'],'head_before_run':subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),'source_sha256':{p:sha(p) for p in old['source_sha256']},'commands':commands,'authorization_note':'Root selected generation17 only after both gen16 diagnostic reviews passed. Preparation only: campaign requires completed integrated build, current source/binary/helper preflight and explicit root launch release.','cache_prepared_before_generation':{'path':str(C),'prepared_utc':now(),'previously_absent':True,'initial_entries':[]},'selected_scope':{'runtime':'Impl/Binary64.lean','new_proof':'Proofs/Binary64Runtime.lean','integration':'Existing Decoder, BDS50/Comm-B and CPRTracking proof bridges','concept':'Complete immutable exact powerTwo table −1074..1023 with original all-Int formula fallback.'}}
(P/'fresh-seeds.json').write_text(json.dumps(seeds,indent=2)+'\n');helpers={}
for name in ['fresh-orchestrate.py','fresh-run-campaign.py','fresh-verify.py','fresh-retained-hashes.py']:
 source=previous/name;destination=P/name;assert not destination.exists();text=source.read_text().replace('gen16','__CUR__').replace('gen15','gen16').replace('__CUR__','gen17').replace('==112','==113');ast.parse(text);destination.write_text(text);helpers[str(destination)]={'sha256':sha(destination),'reused_from':str(source),'prior_sha256':sha(source)}
bindings={}
for key,name in [('decode_review','tests/evidence/diagnostics/gen16/independent-review/independent-review.json'),('cpr_review','tests/evidence/diagnostics/gen16-cpr/independent-review/independent-review.json'),('benchmark_review','bench/runs/gen16/results-review.json')]:bindings[key]={'path':name,'sha256':sha(name)}
prep={'status':'prepared_not_executed','prepared_utc':now(),'seed_record_sha256':sha(P/'fresh-seeds.json'),'helpers':helpers,'expected_fresh_source_count':113,'expected_native_binaries':3,'expected_gate_inputs':188,'pending_new_proof':'Proofs/Binary64Runtime.lean','source_inventory_basis':'Prior sealed source membership plus exactly Binary64Runtime.lean; launcher derives current Lean files and must match root preflight.','source_inventory_prior':{'path':str(previous/'fresh-message-run.json'),'sha256':sha(previous/'fresh-message-run.json')},'history_bindings':bindings,'prior_csv_rows':len(list(csv.DictReader(Path('bench/results.csv').open()))),'prior_csv_sha256':sha('bench/results.csv'),'syntax_validation':'Four adapted helpers parsed with ast.parse, no helper imported/executed.','changes':'Generation paths and expected source count only. Python bytecode disabled before imports. Frozen generators/checkers unchanged.','cleanup_policy':'Seal all33 compressed artifacts, comparison replay and independent retention review first. Then only exact raw duplicates via reviewed bounded cleanup, preserving unique failures and active fixed gate.','preparation_attempts':[{'attempt':1,'status':'stopped_before_writes','reason':'Inline preparation unnecessarily required entire shared gen17 directory absent; implementation owner already created its own evidence. No seed draw, fixture, directory creation or helper execution occurred. Corrected guard checks only owned fresh artifacts.'},{'attempt':2,'status':'metadata_prepared'}],'no_campaign_started':True,'preparer_sha256':sha(__file__)}
assert prep['prior_csv_rows']==34;(R/'preparation.json').write_text(json.dumps(prep,indent=2)+'\n')
print(json.dumps({'status':'prepared_not_executed','message_seed':message,'commb_seed':commb,'seed_sha256':sha(P/'fresh-seeds.json'),'preparation_sha256':sha(R/'preparation.json'),'expected_sources':113,'expected_gate_inputs':188}))
