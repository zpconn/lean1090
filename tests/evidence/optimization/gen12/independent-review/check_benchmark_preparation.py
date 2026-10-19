#!/usr/bin/env python3
"""Read-only benchmark plan and reporting-target binding check; no timing."""
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,hashlib,io,json
B=Path('tests/evidence/optimization/gen12');P=B/'benchmark-preparation';R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
plan=load(P/'plan.json');prep=load(P/'preparation-verification.json')
assert sha(P/'plan.json')==prep['plan_sha256']=='bf19bcb28383db5cdbc3d5eb84535f39271f00730f39b3bfb36e93152e32bee6'
assert plan['generation']==12 and plan['decode_target_ratio']==prep['decode_target_ratio']=={'numerator':3,'denominator':2}
assert plan['prior_csv_rows']==prep['prior_rows']==24
prior=Path(plan['prior_csv_snapshot']);assert prior==P/'results-before.csv'
assert prior.read_bytes()==Path('bench/results.csv').read_bytes()==(R/'results-prefix-before-gen12.csv').read_bytes()
assert sha(prior)==plan['prior_csv_sha256']==prep['prior_csv_sha256']=='dc35efdb4318bb92d7d5a0a2a047e7d3fc159d2af982cb69887ec68a768d5bf4'
assert len(list(csv.DictReader(io.StringIO(prior.read_text()))))==24
fresh=Path(plan['fresh_verification']);assert fresh==B/'fresh-final-verification.json'
assert sha(fresh)==plan['fresh_verification_sha256']=='c39e9efb5c5508a1e7d36ce0388930cbbce06e85e56b7641459c6f9f4a5615ec'
assert load(fresh)['status']==prep['fresh_status']==prep['status']=='passed'
helper=Path('review/diagnostics/archive_generation_benchmark_target.py')
review=Path('tests/evidence/optimization/target-reporting/independent-review.json');review_data=load(review)
assert sha(helper)==prep['helper_sha256']==review_data['new_helper_sha256']=='9cb02d8f8ba5603538b29b8944546538de3c9f75b5b3a40733aaeae7478e8ebb'
assert sha(review)==prep['helper_independent_review_sha256']=='e993d52ea17ca5b7793fadca7cfce550ff5f2320a6a830b1f251821ee1b12f09'
assert review_data['status']=='passed' and review_data['findings']==[]
assert prep['measurement_started'] is False
assert plan['prepared_utc']<=prep['prepared_utc']
# Extract only the already-reviewed pure arithmetic functions; never execute
# imports, validator orchestration or archival main.
tree=ast.parse(helper.read_text());names={'require','target_ratio','target_label','decode_threshold_reached'}
ns={};module=ast.Module(body=[n for n in tree.body if isinstance(n,ast.FunctionDef) and n.name in names],type_ignores=[])
exec(compile(module,str(helper),'exec'),ns)
assert ns['target_ratio'](plan)==(3,2) and ns['target_label'](plan)=='1.50'
for rust,lean,want in [(299,200,False),(300,200,True),(301,200,True)]:
 assert ns['decode_threshold_reached'](plan,{'medians_nanoseconds':{'rs1090':rust,'lean1090':lean}}) is want
out={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'files':{str(p):sha(p) for p in [P/'plan.json',P/'preparation-verification.json',prior,fresh,helper,review,Path(__file__)]},'prior_result_rows':24,'exact_target':{'numerator':3,'denominator':2},'threshold':'2 * rs1090 median ns >= 3 * Lean median ns, inclusive equality','retained_preparation_failure':False,'measurement_started_by_reviewer':False,'scope':'Only plan/source/hash inspection and three pure threshold comparisons. No build, test, native decoder, profiler, interleaver or archival helper execution.'}
p=R/'benchmark-preparation-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'target':out['exact_target']},indent=2))
