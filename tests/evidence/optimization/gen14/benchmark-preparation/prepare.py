from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, sys
root=Path.cwd(); out=Path(__file__).resolve().parent
sys.path.insert(0,str(root/'review/diagnostics'))
import archive_generation_benchmark_target as archive
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
assert sha(root/'review/diagnostics/archive_generation_benchmark_target.py')=='9cb02d8f8ba5603538b29b8944546538de3c9f75b5b3a40733aaeae7478e8ebb'
assert sha(root/'tests/evidence/optimization/target-reporting/independent-review.json')=='e993d52ea17ca5b7793fadca7cfce550ff5f2320a6a830b1f251821ee1b12f09'
fresh=root/'tests/evidence/optimization/gen14/fresh-final-verification.json'
assert json.loads(fresh.read_text())['status']=='passed'
prior=root/'bench/results.csv'; raw=prior.read_bytes()
assert len(archive.parse_prior_csv(raw,14))==28
for name in ['results-before.csv','plan.json','preparation-verification.json']: assert not (out/name).exists()
assert not (root/'bench/runs/gen14').exists() and not (root/'bench/GEN14.md').exists()
(out/'results-before.csv').write_bytes(raw)
plan={'generation':14,'prepared_utc':datetime.now(timezone.utc).isoformat(),'prior_csv_snapshot':str((out/'results-before.csv').relative_to(root)),'prior_csv_sha256':sha(prior),'prior_csv_rows':28,'fresh_verification':str(fresh.relative_to(root)),'fresh_verification_sha256':sha(fresh),'title':'exact BDS60 ratio enclosure','change_description':'The live BDS60 IAS/Mach ratio gate uses exact integer bounds on the software binary64 rounding error. It decides only when the entire interval proves an outside or inside result; the original rounded comparison remains the lazy fallback near either boundary. An unconditional theorem covers every rational input. [Implementation and proof evidence](../docs/GEN14-BDS60-RATIO.md).','row_note':'Exact BDS60 ratio enclosure with software fallback; full fixed/fresh 10M validation; clean fresh build; CPU 0; 3+21 ABAB','decode_target_ratio':{'numerator':3,'denominator':2},'decode_review_threshold':'3/2; exact integer comparison of the measured medians; stop for user review if reached','note':'Prepared before timing. Contains no speculative measurement. The reviewed reporting helper only archives a completed run.'}
assert archive.target_ratio(plan)==(3,2) and archive.target_label(plan)=='1.50'
(out/'plan.json').write_text(json.dumps(plan,indent=2)+'\n')
v={'status':'passed','prepared_utc':datetime.now(timezone.utc).isoformat(),'plan_sha256':sha(out/'plan.json'),'helper_sha256':sha(root/'review/diagnostics/archive_generation_benchmark_target.py'),'helper_independent_review_sha256':sha(root/'tests/evidence/optimization/target-reporting/independent-review.json'),'prior_csv_sha256':sha(prior),'prior_rows':28,'fresh_status':'passed','decode_target_ratio':plan['decode_target_ratio'],'measurement_started':False}
(out/'preparation-verification.json').write_text(json.dumps(v,indent=2)+'\n');print(json.dumps(v,indent=2))
