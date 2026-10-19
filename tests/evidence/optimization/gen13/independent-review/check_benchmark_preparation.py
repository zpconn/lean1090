#!/usr/bin/env python3
"""Read-only benchmark plan and reporting-target binding check; no timing."""
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,hashlib,io,json
B=Path('tests/evidence/optimization/gen13');P=B/'benchmark-preparation';R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
plan=load(P/'plan.json');prep=load(P/'preparation-verification.json')
assert sha(P/'plan.json')==prep['plan_sha256']=='16749993a24f86c86a753b086bf082b1f7d63887d5e16a7673bcb669871b0867'
assert plan['generation']==13 and plan['decode_target_ratio']==prep['decode_target_ratio']=={'numerator':3,'denominator':2}
assert plan['prior_csv_rows']==prep['prior_rows']==26
prior=Path(plan['prior_csv_snapshot']);assert prior==P/'results-before.csv'
assert prior.read_bytes()==Path('bench/results.csv').read_bytes()==(R/'results-prefix-before-gen13.csv').read_bytes()
assert sha(prior)==plan['prior_csv_sha256']==prep['prior_csv_sha256']=='2e5de9220727d5b15ccb78f37c5630ffa119a343c5e9fd978e946c0064e38c14'
assert len(list(csv.DictReader(io.StringIO(prior.read_text()))))==26
fresh=Path(plan['fresh_verification']);assert fresh==B/'fresh-final-verification.json'
assert sha(fresh)==plan['fresh_verification_sha256']==load(B/'fresh-execution.json')['verification_sha256']
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
failure=load(P/'attempt-01.json')
assert failure['exit_code']==1 and failure['source_sha256']==sha(P/'prepare-attempt-01.py')
old=(P/'prepare-attempt-01.py').read_text();new=(P/'prepare.py').read_text()
assert new==old.replace("not (root/'bench/GEN12.md').exists()","not (root/'bench/GEN13.md').exists()")
assert old.index("not (root/'bench/GEN12.md').exists()")<old.index('.write_bytes(')
assert load(P/'attempt-02.log')==prep
assert {p.name for p in P.iterdir()}=={'attempt-01.json','attempt-02.log','plan.json','preparation-verification.json','prepare-attempt-01.py','prepare.py','results-before.csv'}
out={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'files':{str(p):sha(p) for p in [P/'plan.json',P/'preparation-verification.json',prior,fresh,helper,review,Path(__file__),P/'attempt-01.json',P/'attempt-02.log',P/'prepare-attempt-01.py',P/'prepare.py']},'prior_result_rows':26,'exact_target':{'numerator':3,'denominator':2},'threshold':'2 * rs1090 median ns >= 3 * Lean median ns, inclusive equality','retained_preparation_failure':True,'preparation_failure_scope':'Output existence guard copied the prior generation report path; the retained first attempt stopped before writing plan/snapshot/verification. The retry changes only GEN12 to GEN13 in that assertion. No correctness or benchmark execution failed or was retried.','measurement_started_by_reviewer':False,'scope':'Only plan/source/hash inspection and three pure threshold comparisons. No build, test, native decoder, profiler, interleaver or archival helper execution.'}
p=R/'benchmark-preparation-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'target':out['exact_target']},indent=2))
