"""Focused gen26 round refinement, fixed liveness and pending plan review."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,csv,difflib,hashlib,io,json,re,subprocess
G=Path('tests/evidence/optimization/gen26');R=G/'independent-review';S=G/'round-proof'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();read=lambda p:json.loads(Path(p).read_text())
checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 p=Path(p);actual=sha(p);check(h is None or actual==h,'Hash '+str(p));bindings[str(p)]=actual
before=read(S/'before.json');bind(S/'before.json');head=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()
old={}
for path,h in before['files'].items():
 p=S/'before'/Path(path).name;bind(p,h);old[path]=p.read_text()
 check(hashlib.sha256(subprocess.check_output(['git','show',head+':'+path])).hexdigest()==h,'Exact committed predecessor '+path);bind(path)
runtime=Path('Impl/Binary64.lean').read_text();proof=Path('Proofs/Binary64Runtime.lean').read_text()
a=runtime.index('/-- Small dyadics are already exact');b=runtime.index('/-- Rust f64 `MAX`',a)
check((runtime[:a]+runtime[b:]).replace('def roundFallback (value : Rat)', 'def round (value : Rat)')==old['Impl/Binary64.lean'],'Original total round body renamed verbatim, all remaining runtime declarations unchanged')
expected='''def round (value : Rat) : Rat :=
  if value.num.natAbs < 2^53 then
    let denominatorExponent := value.den.log2
    if denominatorExponent ≤ 1074 ∧ value.den = 1 <<< denominatorExponent then
      value
    else roundFallback value
  else roundFallback value
'''
check(runtime[runtime.index('def round (value : Rat)'):b].rstrip()==expected.rstrip(),'Exact numerator-first dyadic guard; both rejected paths call live original fallback')
headers=lambda text:dict(re.findall(r'(?m)^(?:private )?theorem (\w+)([\s\S]*?)\s*:=',text))
prior=headers(old['Proofs/Binary64Runtime.lean']);now=headers(proof)
check(len(prior)==32 and all(now.get(k)==v for k,v in prior.items()),'All 32 old theorem statements byte-identical, including unconditional round and function equality')
new=set(now)-set(prior);witnesses={'round_guard_'+x+'_witness' for x in ['zero_sign','numerator_boundary','min_subnormal','rejected_inputs','underflow_ties','normal_ties']}
check(new==witnesses|{'roundFallback_eq','round_small_dyadic'},'Only fallback/dyadic bridges and six kernel witness groups added')
check(now['roundFallback_eq']==' (x : Rat) :\n    Impl.Binary64.roundFallback x = Spec.Binary64.round x','Fallback bridge unconditional for every rational')
check('simpa only [Nat.shiftLeft_eq, one_mul] using guard.2' in proof and '(Binary64Dyadic.round_eq x x.den.log2 denominator numeratorBound guard.1).symm' in proof,'Accepted guard derives exact denominator power and reuses proved frozen-model identity')
check(proof.count('next => exact roundFallback_eq x')==2,'Both rejected guards refine through original total formula')
check('theorem round_function_eq : Impl.Binary64.round = Spec.Binary64.round := funext round_eq' in proof,'Higher-order whole-model equality remains unrestricted')
for name in witnesses:check('decide +kernel' in proof[proof.index('theorem '+name):proof.find('\n#print axioms',proof.index('theorem '+name))],'Kernel witness group '+name)
# The new dependency remains on the frozen rational model, never on Impl or this bridge.
pending=['Proofs/Binary64Dyadic.lean'];closure=set()
while pending:
 p=pending.pop()
 if p in closure:continue
 closure.add(p);bind(p)
 for mod in re.findall(r'^import ([A-Za-z0-9_.]+)',Path(p).read_text(),re.M):
  target=mod.replace('.','/')+'.lean'
  if Path(target).is_file():pending.append(target)
check(not any(p.startswith('Impl/') or p=='Proofs/Binary64Runtime.lean' for p in closure),'Dyadic theorem dependency graph contains no Impl or cyclic runtime bridge')
for path,text in [('Impl/Binary64.lean',runtime),('Proofs/Binary64Runtime.lean',proof)]:
 stripped=re.sub(r'/\-.*?\-/','',text,flags=re.S);stripped=re.sub(r'--[^\n]*|#print axioms[^\n]*','',stripped)
 check(not re.search(r'\b(?:sorry|admit|axiom|native_decide|unsafe|partial)\b|@\[(?:extern|implemented_by)',stripped),'No bypass or trusted primitive '+path)
 d=R/(Path(path).stem+'.diff');assert not d.exists();d.write_text(''.join(difflib.unified_diff(old[path].splitlines(True),text.splitlines(True),fromfile=head+':'+path,tofile=path)));bind(d)
summary=read(S/'summary.json');bind(S/'summary.json');record=read(S/'attempt-01/execution.json')
for p,h in [(S/'attempt-01/execution.json',summary['attempts'][0]['execution_sha256']),(S/'attempt-01/build.log',record['log_sha256']),(S/'run_build.py',record['runner_sha256']),(S/'source.diff',summary['source_diff_sha256'])]:bind(p,h)
check(len(summary['attempts'])==1 and record['status']=='passed' and record['exit_code']==0 and record['before_hashes']==record['after_hashes'] and record['inputs_unchanged'],'Targeted first attempt passed with all exact inputs held')
check(record['command']==['lake','build','Proofs.Binary64Runtime'],'Narrow targeted build command')
for p,h in record['after_hashes'].items():bind(p,h)
for p in before['files']:bind(S/'attempt-01'/Path(p).name,sha(p))
log=(S/'attempt-01/build.log').read_text();rows=re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)",log)
check(len(rows)==len(re.findall(r'depends on axioms:|does not depend on any axioms',log)),'Every multiline and axiom-free announcement parsed')
facts=[{'name':n,'axioms':[v.strip() for v in a.split(',') if v.strip()]} for n,a in rows]
check(len(facts)==45 and len({x['name'] for x in facts})==45 and all(set(x['axioms'])<={'propext','Classical.choice','Quot.sound'} for x in facts),'All 45 printed facts distinct and permitted')
check(facts==summary['printed_axiom_facts'],'Independent fact inventory matches retained summary')
printed=re.findall(r'^#print axioms (\w+)',proof,re.M);check(len(printed)==40 and all('Lean1090.Proofs.Binary64Runtime.'+n in {x['name'] for x in facts} for n in printed),'Every current target theorem printed, including all kernel witnesses')
# Exact current source delta across the previous gate, including frozen adapters and Float boundaries.
gate=read('tests/evidence/optimization/gen25/gate-evidence.json')['input_hashes_after']
check(len(gate)==202 and {p for p,h in gate.items() if sha(p)!=h}==set(before['files']),'Exactly two authorized correctness inputs change; no frozen or Float source delta')
for path,marker in [('Tests/Tracking.lean','Impl.decodePositions'),('Tests/CommBDifferential.lean','Impl.decodeBDS register word'),('Tests/UpstreamCorpus.lean','Impl.decode bytes'),('Impl/CPRPolicy.lean','Binary64.div dt 3600'),('Proofs/CPRFloatFast.lean','Binary64Runtime.round_eq'),('Proofs/CommBRatio.lean','Binary64Runtime.round_eq')]:bind(path);check(marker in Path(path).read_text(),'Live unchanged production/refinement path '+path)
bind('spec.lock','5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8');locked=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()];check(len(locked)==104,'Exact frozen membership')
for h,p in locked:bind(p,h)
prep=read(R/'integration-gate-preparation-review.json');bind(R/'integration-gate-preparation-review.json');check(prep['status']=='passed_read_only_preparation_review' and not prep['findings'],'Reviewed four-controller preparation')
for p,h in prep['bindings'].items():bind(p,h)
required=read(G/'integration/preparation.json')['required_facts'];check({n.rsplit('.',1)[1] for n in required if '.Binary64Runtime.' in n}<=set(now),'Actual compiled proof APIs match prepared combined validator')
# Pending plan only; corrected uppercase output guard is bound without execution.
B=G/'benchmark-preparation';plan=read(B/'plan-pending.json');bind(B/'plan-pending.json','3f310cf397465865d73f217ff6815cfd54dee51c15b97c5eee37eb5788b60f68')
script=(B/'prepare.py').read_text();ast.parse(script);bind(B/'prepare.py');check("assert not (root / 'bench/GEN26.md').exists()" in script and 'GEN25' not in script,'Final output guard names only current report')
initial=B/'unexecuted-guard-correction/prepare.py';bind(initial);check(script==initial.read_text().replace('bench/GEN25.md','bench/GEN26.md'),'Only one uppercase output guard corrected before execution')
for p in sorted((B/'unexecuted-guard-correction').rglob('*')):
 if p.is_file():bind(p)
for p in [B/'guard-correction.diff',B/'guard-correction.json']:bind(p)
check(plan['generation']==26 and plan['status']=='pending_validation_not_ready_for_timing' and all(v is None for v in plan['pending_bindings'].values()),'No measurement or readiness fabricated in pending plan')
raw=Path(plan['prior_csv_snapshot']).read_bytes();bind(plan['prior_csv_snapshot'],plan['prior_csv_sha256']);check(raw==Path('bench/results.csv').read_bytes() and len(list(csv.DictReader(io.StringIO(raw.decode()))))==plan['prior_csv_rows']==52,'Exact 52-row historical prefix preserved')
check(all(plan[k]=={'numerator':2,'denominator':1} for k in ['decode_target_ratio','cpr_target_ratio']),'Both exact 2/1 targets retained')
for path,h in [(plan['reporting_helper']['path'],plan['reporting_helper']['sha256']),(plan['reporting_helper']['independent_review'],plan['reporting_helper']['independent_review_sha256'])]:bind(path,h)
check("native['binary64_round_identity_live_path_verified']" in script and "requirements['correctness_inputs'] == 202" in script,'Current native flag and actual held correctness inputs required before final plan')
out=dict(status='passed',findings=[],recorded_utc=datetime.now(timezone.utc).isoformat(),check_count=len(checks),checks=checks,bindings=bindings,source_delta=summary['source_hashes'],preserved_theorem_count=len(prior),new_theorems=sorted(new),printed_axiom_facts=facts,printed_fact_count=len(facts),all_input_refinement_verified=True,reviewer_sha256=sha(__file__),spec_only_dyadic_dependency_closure=sorted(closure),targeted_build_attempts=summary['attempts'],assessments=['The original total software rounding formula is byte-identical in a live fallback, called by both rejected guard branches.','The numerator bound precedes denominator log2 and shift work; accepted values are exactly representable by the existing frozen-model dyadic theorem, including zero and negative values.','Unconditional round equality and every existing higher-order consumer bridge retain their statements. Underflow ties and rejected non-dyadics use the original model.','No Float callback, trusted primitive, frozen source, test or benchmark changed. Pending benchmark output guard correction is retained and was not executed.'],limitations=['Static source/proof and successful kernel-log review; no compilation, test or native workload executed by reviewer. Linked branch inspection follows the combined build.','No guard-hit frequency or elapsed-time gain is inferred from earlier nested instruction costs.'])
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':'passed','checks':len(checks),'facts':len(facts),'sha256':sha(p)}))
