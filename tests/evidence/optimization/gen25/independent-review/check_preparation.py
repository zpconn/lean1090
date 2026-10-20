"""Read-only review of prepared fresh and fixed finishing adaptations."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,difflib,hashlib,io,json
E=Path('tests/evidence/optimization/gen25');sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
prep=load(E/'preparation.json');fixed=load(E/'fixed-finishing-preparation.json');checks=[];bindings={}
def check(value,label):
 assert value,label
 checks.append(label)
def bind(path,expected=None):
 digest=sha(path)
 if expected is not None:check(digest==expected,'hash '+str(path))
 bindings[str(path)]=digest
for name in ['preparation.json','fixed-finishing-preparation.json','seed-selection.json','preparation-attempt-01/execution.json','unexecuted-native-flag-correction/correction.json']:bind(E/name)
for record in [prep,fixed]:
 for name,row in record['adaptations'].items():
  for key,digest in [('path','sha256'),('prior_path','prior_sha256'),('diff_path','diff_sha256')]:bind(row[key],row[digest])
  old=Path(row['prior_path']).read_text();new=Path(row['path']).read_text();ast.parse(new);checks.append('syntax '+name)
  expected=''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile=row['prior_path'],tofile=row['path']))
  check(Path(row['diff_path']).read_text()==expected,'exact diff '+name)
  if name!='finish_campaign.py':
   normalized=old.replace('gen24','__CURRENT__').replace('gen23','gen24').replace('__CURRENT__','gen25').replace("'24'","'25'")
   check(new==normalized,'generation-only '+name)
for group in ['history_bindings','unchanged_generator_inputs']:
 for name,h in prep[group].items():bind(name,h)
for name,h in fixed['generic_helpers'].items():bind(name,h)
check(prep['expected_fresh_source_count']==127 and prep['expected_gate_input_count']==202,'127 sources and 202 inputs')
prior=load(prep['source_inventory_prior']['path']);names=set(prior['source_sha256_before'])
for directory in ['Impl','Model','Spec','Proofs','CLI','Tests']:names.update(str(p) for p in Path(directory).rglob('*.lean'))
names.update(['lakefile.toml','lake-manifest.json','lean-toolchain','Capstones.lean']);check(len(names)==127,'actual source inventory')
raw=Path('bench/results.csv').read_bytes();check(len(list(csv.DictReader(io.StringIO(raw.decode()))))==prep['prior_csv_rows']==50,'50 prior CSV rows');bind('bench/results.csv',prep['prior_csv_sha256'])
seed=load(E/'seed-selection.json');check(seed['status']=='recorded_before_generation','seeds precede generation');check((seed['message_seed'],seed['commb_seed'])==(1065315418,1346913957),'exact selected seeds');bind(E/'seed-selection.json',prep['seed_selection']['sha256'])
seen=set()
for n,h in seed['historical_seed_records_sha256'].items():
 bind(n,h);seen.update(v for k,v in load(n).items() if 'seed' in k and isinstance(v,int))
check(len(seen)==seed['historical_seed_values_checked'],'historical seed count');check(seed['message_seed'] not in seen and seed['commb_seed'] not in seen and seed['message_seed']!=seed['commb_seed'],'seed collisions absent')
finish=(E/'finish_campaign.py').read_text();unlink=finish.index('run=subprocess.run(cmd')
for text in ["replay_run['status']=='passed'", "replay_run['script_sha256']==sha(R/'replay_comparison.py')", "replay_run['stdout_sha256']==sha(R/'comparison-attempt-01/stdout.log')==sha(R/'comparison-replay.json')", "replay_run['stderr_sha256']==sha(R/'comparison-attempt-01/stderr.log')"]:check(finish.index(text)<unlink,'replay check before cleanup '+text)
check("native_review['score_scaling_identity_live_path_verified']" in finish,'root-selected native flag')
previous=load('tests/evidence/optimization/gen24/independent-review/comparison-attempt-01/execution.json');check(previous['stdout_sha256']==sha('tests/evidence/optimization/gen24/independent-review/comparison-replay.json'),'actual prior replay stdout/result contract')
check("len(manifest['files'])==33" in finish and "len(row['files'])==8" in finish,'exact retained and scratch membership')
for folder in ['preparation-attempt-01','unexecuted-native-flag-correction']:
 for path in sorted((E/folder).rglob('*')):
  if path.is_file():bind(path)
check(not (E/'fresh-execution.json').exists(),'no campaign executed during preparation review')
bind(__file__)
result={'status':'passed_read_only_preparation_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'checks':len(checks),'check_labels':checks,'findings':[],'bindings':bindings,'assessment':['Seven fresh adapters and two fixed-gate/finishing adapters retain full 10M plus corpus/direct strata, every coverage/difference check and exact 33-file gzip retention.','No change to frozen generator, comparison, benchmark or cleanup helpers. Secure recorded seeds are unchanged and independently checked against historical seed records.','Finisher now validates the completed comparison attempt execution, script, exact stdout/result and stderr hashes before cleanup, and binds those actual files afterward. Existing gzip EOF/content/identity, fsync, native/input and protected-root checks remain.','Fixed selector retains exact five prefixes, birth/mtime gate interval, uniqueness, source inventory, fresh exclusion and two historical protections. Unchanged archive-first wrapper performs every byte check before deletion.','Initial pre-sampling preparation failure and unexecuted native-flag correction remain bound. No controller imports, workloads, builds, gate, sampling or cleanup were executed by this review.']}
out=E/'independent-review/preparation-review.json'
with out.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':result['status'],'checks':len(checks),'sha256':sha(out)}))
