#!/usr/bin/env python3
"""Independent preparation review only; no generator/build/decoder execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,hashlib,json
B=Path('tests/evidence/optimization/gen18/fresh');R=B/'independent-review';OLD=Path('tests/evidence/optimization/gen17')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
prep=load(B/'preparation.json');seed=load(B/'fresh-seeds.json');bindings={str(B/'preparation.json'):sha(B/'preparation.json'),str(B/'fresh-seeds.json'):sha(B/'fresh-seeds.json')}
assert prep['expected_fresh_source_count']==115 and prep['expected_gate_input_count']==190 and prep['expected_binaries']==3
assert prep['seed_record_sha256']==sha(B/'fresh-seeds.json')
for p,row in prep['helpers'].items():
 assert sha(p)==row['sha256'] and sha(row['reused_from'])==row['prior_sha256']
 expected=Path(row['reused_from']).read_text().replace('gen17','__CURRENT__').replace('gen16','gen17').replace('__CURRENT__','gen18').replace("Path('tests/evidence/optimization/gen18')","Path('tests/evidence/optimization/gen18/fresh')").replace('==113','==115')
 if Path(p).name=='fresh-orchestrate.py':
  expected=expected.replace("build=p/'integration/targeted-build.json'","build=p.parent/'integration/targeted-build.json'").replace("sha(p/'integration/targeted-build.log')","sha(p.parent/'integration/targeted-build.log')")
 assert Path(p).read_text()==expected
 ast.parse(expected);bindings[p]=sha(p);bindings[row['reused_from']]=sha(row['reused_from'])
parsed=ast.parse((B/'fresh-orchestrate.py').read_text());retention=next(ast.literal_eval(x.value) for x in parsed.body if isinstance(x,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='EXPECTED_RETENTION' for t in x.targets))
assert len(retention)==len(set(retention))==33
for name in ['mismatches','direct-mismatches','standard-differences']:assert f'fresh-message/{name}.jsonl.gz' in retention
seen=set()
for p,h in seed['historical_seed_records_sha256'].items():
 assert sha(p)==h;bindings[p]=h
 for key,value in load(p).items():
  if 'seed' in key and isinstance(value,int):seen.add(value)
assert len(seen)==seed['historical_seed_values_checked']==62
assert seed['message_seed']==22240697 and seed['commb_seed']==2968091489
assert seed['message_seed']!=seed['commb_seed'] and all(x not in seen for x in [seed['message_seed'],seed['commb_seed']])
for p,h in seed['source_sha256'].items():assert sha(p)==h;bindings[p]=h
assert seed['generated_messages']==10000000 and seed['random_commb_assignments']==100000
assert seed['commands'][0][-2:]==['100000','2968091489']
assert seed['commands'][2]==['python3','-B','scripts/check_message_differential.py','--corpus','--generated','10000000','--seed','22240697','--commb-boundaries','.cache/gen18-gate/fresh-commb.csv','--diagnostic','--output',str(B/'fresh-message')]
assert seed['cache_prepared_before_generation']['previously_absent'] and seed['cache_prepared_before_generation']['initial_entries']==[]
for p,h in prep['history_bindings'].items():assert sha(p)==h;bindings[p]=h
assert sha('bench/results.csv')==prep['prior_csv_sha256'] and prep['prior_csv_rows']==36
r={'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'checker_sha256':sha(__file__),'bindings':bindings,'exact_retention_members':33,'expected_source_count':115,'expected_binary_count':3,'seed_values':{'message':seed['message_seed'],'commb':seed['commb_seed']},'checks':['Four controller sources differ from reviewed gen17 only in generation paths, new nested evidence path, integration parent and expected source count.','Exact 33 success members, full gzip EOF/raw hashes, all three diagnostic streams and post-campaign source/binary rechecks preserved.','New seeds reject every numeric historical seed field and one another; all frozen generators are hash-bound.','No decoder or comparison runner was executed by this preparation review.'],'packaging_followup':'Root informed that the nested fresh/fresh-message path is outside the previous .gitignore glob; this must be excluded before staging without changing an active gate input.','findings':[]}
p=R/'preparation-review.json';assert not p.exists();p.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({'status':r['status'],'sha256':sha(p)}))
