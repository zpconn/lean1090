"""Source-only fresh preparation review; does not import producer controllers."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,difflib,hashlib,io,json
E=Path('tests/evidence/optimization/gen26');sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
prep=load(E/'preparation.json');checks=[];bindings={}
def check(value,label):
 assert value,label
 checks.append(label)
def bind(path,expected=None):
 digest=sha(path)
 if expected is not None:check(digest==expected,'hash '+str(path))
 bindings[str(path)]=digest
bind(E/'preparation.json','779c8f7fd2c05fa2a3805dee7b50cbb880d73ad654ca021430718d25a2c6fbf4')
bind(E/'independent-review/integration-gate-preparation-review.json')
bind(E/'independent-review/scope-correction-review.json')
bind(E/'independent-review/fresh-preparation-runner-refusal.json')
bind(E/'independent-review/fresh-preparation-before-scope.py')
check(len(prep['adaptations'])==7,'seven fresh adapters')
for name,row in prep['adaptations'].items():
 for key,digest in [('path','sha256'),('prior_path','prior_sha256'),('diff_path','diff_sha256')]:bind(row[key],row[digest])
 old=Path(row['prior_path']).read_text();new=Path(row['path']).read_text();ast.parse(new);checks.append('syntax '+name)
 expected=''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile=row['prior_path'],tofile=row['path']))
 check(Path(row['diff_path']).read_text()==expected,'exact diff '+name)
 normalized=old.replace('gen25','__CURRENT__').replace('gen24','gen25').replace('__CURRENT__','gen26').replace('score_scaling_identity_live_path_verified','binary64_round_identity_live_path_verified')
 check(new==normalized,'generation and flag only '+name)
for group in ['history_bindings','unchanged_generator_inputs','existing_fixed_preparation_preserved']:
 for name,h in prep[group].items():bind(name,h)
bind(prep['reporting_helper']['path'],prep['reporting_helper']['sha256'])
check(prep['reporting_helper']['used_by_fresh_campaign'] is False,'reporting helper not used by campaign')
check(prep['expected_fresh_source_count']==127 and prep['expected_gate_input_count']==202 and prep['expected_binaries']==3,'127 sources, 202 inputs, three binaries')
bind(prep['source_inventory_prior']['path'],prep['source_inventory_prior']['sha256'])
prior=load(prep['source_inventory_prior']['path']);names=set(prior['source_sha256_before'])
for directory in ['Impl','Model','Spec','Proofs','CLI','Tests']:names.update(str(p) for p in Path(directory).rglob('*.lean'))
names.update(['lakefile.toml','lake-manifest.json','lean-toolchain','Capstones.lean']);check(len(names)==127,'actual source-name union')
raw=Path('bench/results.csv').read_bytes();check(len(list(csv.DictReader(io.StringIO(raw.decode()))))==prep['prior_csv_rows']==52,'52 prior CSV rows');bind('bench/results.csv',prep['prior_csv_sha256'])
seed=load(E/'seed-selection.json');check(seed['status']=='recorded_before_generation','seeds precede generation');check((seed['message_seed'],seed['commb_seed'])==(748317927,713274074),'exact selected seeds');bind(E/'seed-selection.json',prep['seed_selection']['sha256'])
seen=set()
for n,h in seed['historical_seed_records_sha256'].items():
 bind(n,h);seen.update(v for k,v in load(n).items() if 'seed' in k and isinstance(v,int))
check(len(seen)==seed['historical_seed_values_checked']==86,'86 historical seeds');check(seed['message_seed'] not in seen and seed['commb_seed'] not in seen and seed['message_seed']!=seed['commb_seed'],'no seed collision')
check(all(0<=seed[k]<2**32 for k in ['message_seed','commb_seed']),'32-bit seeds')
check(seed['generator_source_sha256']==prep['unchanged_generator_inputs'],'seed generator binding')
bind(prep['preparer']['path'],prep['preparer']['sha256']);check(seed['preparer_sha256']==prep['preparer']['sha256'],'seed preparer binding')
finish=(E/'finish_campaign.py').read_text();unlink=finish.index('run=subprocess.run(cmd')
for text in ["replay_run['status']=='passed'", "replay_run['script_sha256']==sha(R/'replay_comparison.py')", "replay_run['stdout_sha256']==sha(R/'comparison-attempt-01/stdout.log')==sha(R/'comparison-replay.json')", "replay_run['stderr_sha256']==sha(R/'comparison-attempt-01/stderr.log')"]:check(finish.index(text)<unlink,'replay check precedes cleanup '+text)
check("native_review['binary64_round_identity_live_path_verified']" in finish,'current native flag')
previous=load('tests/evidence/optimization/gen25/independent-review/comparison-attempt-01/execution.json');check(previous['stdout_sha256']==sha('tests/evidence/optimization/gen25/independent-review/comparison-replay.json'),'actual prior replay contract')
check("len(manifest['files'])==33" in finish and "len(row['files'])==8" in finish,'exact retention and selected scratch membership')
check(not (E/'fresh-execution.json').exists(),'no campaign executed at review')
bind(__file__)
result={'status':'passed_read_only_preparation_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'checks':len(checks),'check_labels':checks,'findings':[],'bindings':bindings,'assessment':['All seven fresh helpers are byte-exact generation/native-flag adaptations of the reviewed executed generation 25 helpers. Full fixed strata, 10M random campaign, direct coverage, output comparisons and exact 33-member retention remain.','Recorded 32-bit seeds are distinct and absent from all 86 bound historical values. Preflight consumes this selection without resampling, requires explicit release and complete combined-build/source/binary binding.','Finisher retains actual successful comparison-attempt-01 execution, source, stdout/result and stderr checks before invoking strict selected cleanup. Native flag, gzip EOF/content/identity, durable receipts and protected-root guards remain.','Previously passed integration/gate preparation is bound without rerunning it. No producer controller import, build, decoder, oracle, profiler or cleanup was executed by this review.']}
out=E/'independent-review/preparation-review.json'
with out.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':result['status'],'checks':len(checks),'sha256':sha(out)}))
