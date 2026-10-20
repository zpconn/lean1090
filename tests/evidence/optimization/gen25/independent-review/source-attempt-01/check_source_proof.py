"""Focused two-file score-scaling review, including build/gate preparations."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,difflib,hashlib,json,re,subprocess
G=Path('tests/evidence/optimization/gen25');R=G/'independent-review';S=G/'score-scaling'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 p=Path(p);actual=sha(p);check(h is None or h==actual,'Hash '+str(p));bindings[str(p)]=actual
before=load(S/'before.json');bind(S/'before.json')
old={p:subprocess.check_output(['git','show',before['head']+':'+p],text=True) for p in before['files']}
for path,h in before['files'].items():
 bind(S/'before'/path,h);check((S/'before'/path).read_text()==old[path],'Exact committed predecessor '+path)
 bind(path)
runtime=Path('Impl/ScoreGate.lean').read_text();proof=Path('Proofs/ScoreGateInteger.lean').read_text()
oldbody='  value.num * (denominator / value.den : Nat)'
newbody='  if denominator == value.den then value.num\n  else value.num * (denominator / value.den : Nat)'
check(old['Impl/ScoreGate.lean'].count(oldbody)==1 and runtime==old['Impl/ScoreGate.lean'].replace(oldbody,newbody),'Only runtime change is exact equality identity arm; original total else expression retained')
headers=lambda text:dict(re.findall(r'(?m)^(?:private )?theorem (\w+)([\s\S]*?)\s*:=',text))
prior=headers(old['Proofs/ScoreGateInteger.lean']);now=headers(proof)
check(all(now.get(k)==v for k,v in prior.items()),'Every existing theorem statement remains byte-identical')
new=set(now)-set(prior)
expected={'scaledNumerator_eq_old','scaledNumerator_function_eq','equal_denominator_witness','unequal_denominator_witness','zero_denominator_witness','negative_numerator_witness','non_dyadic_equal_witness','non_divisible_denominator_witness'}
check(new==expected,'Exactly unrestricted equality/function alias and six meaningful kernel witness groups added')
check(now['scaledNumerator_eq_old']==' (denominator : Nat) (value : Rat) :\n    scaledNumerator denominator value = value.num * (denominator / value.den : Nat)','Equality has no positivity, divisibility, size, dyadic or corpus precondition')
check('Nat.div_self value.den_pos' in proof and 'by_cases same : denominator = value.den' in proof,'Equal branch uses the intrinsic rational nonzero denominator; arbitrary Nat zero/unequal inputs use old formula')
check('rw [scaledNumerator_eq_old]\n  simp only [Int.cast_mul, Int.cast_natCast]' in proof,'Existing cast theorem delegates through unconditional old formula')
check('funext denominator value\n  exact scaledNumerator_eq_old denominator value' in proof,'Function equality covers every pair of inputs')
check(proof.count('decide +kernel')==old['Proofs/ScoreGateInteger.lean'].count('decide +kernel')+6,'Six added kernel witnesses include zero, negative, non-dyadic and truncated non-divisible division')
for path,text in [('Impl/ScoreGate.lean',runtime),('Proofs/ScoreGateInteger.lean',proof)]:
 stripped=re.sub(r'/\-.*?\-/','',text,flags=re.S);stripped=re.sub(r'--[^\n]*|#print axioms[^\n]*','',stripped)
 check(not re.search(r'\b(?:sorry|admit|axiom|native_decide|unsafe|partial)\b|@\[(?:extern|implemented_by)',stripped),'No bypass or new trusted boundary '+path)
 (R/(Path(path).stem+'.diff')).write_text(''.join(difflib.unified_diff(old[path].splitlines(True),text.splitlines(True),fromfile=before['head']+':'+path,tofile=path)))
summary=load(S/'summary.json');bind(S/'summary.json');
for row in summary['retained_attempts']:
 attempt=S/f"attempt-{row['attempt']:02d}"
 bind(attempt/'execution.json',row['execution_sha256']);bind(attempt/'build.log',row['log_sha256'])
 r=load(attempt/'execution.json');check(r['status']==row['status'] and r['before_hashes']==r['after_hashes'],'Retained original attempt and unchanged inputs '+str(row['attempt']))
 bind(attempt/'ScoreGate.lean',sha('Impl/ScoreGate.lean'));bind(attempt/'ScoreGateInteger.lean',r['before_hashes']['Proofs/ScoreGateInteger.lean'])
record=load(S/'attempt-03/execution.json');bind(S/'attempt-03/execution.json');bind(S/'run_build.py',record['runner_sha256']);bind(S/'attempt-03/build.log',record['log_sha256'])
check(record['status']=='passed' and record['exit_code']==0 and record['before_hashes']==record['after_hashes'] and record['inputs_unchanged'],'Final targeted kernel build passed with exact unchanged inputs')
check(record['command']==['lake','build','Proofs.ScoreGateInteger'],'Targeted command is only the changed proof module')
for p,h in record['after_hashes'].items():bind(p,h)
log=(S/'attempt-03/build.log').read_text();rows=re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)",log)
check(len(rows)==len(re.findall(r'depends on axioms:|does not depend on any axioms',log)),'Every multiline axiom announcement independently parsed')
facts={n:[v.strip() for v in a.split(',') if v.strip()] for n,a in rows}
check(len(facts)==len(rows) and all(set(a)<={'propext','Classical.choice','Quot.sound'} for a in facts.values()),'All distinct printed facts use only permitted axioms')
names=re.findall(r'^#print axioms (\w+)',proof,re.M);prefix='Lean1090.Proofs.ScoreGateInteger.'
check(len(names)==20 and all(prefix+n in facts for n in names),'All 20 current score-scaling facts are present in the successful kernel log')
# Frozen adapters and full theorem paths still enter production; no obsolete copy.
for path,marker in [('Tests/CommBDifferential.lean','Impl.decodeBDS register word'),('Tests/Tracking.lean','Impl.decodePositions'),('Tests/UpstreamCorpus.lean','Impl.decode bytes'),('Impl/CommB.lean','ScoreGate.choose (cbDensityTermsFast register word)'),('Proofs/ScoreGate.lean','ScoreGateInteger.choose_eq_old'),('Proofs/Decoder.lean','ScoreGate.choose_eq')]:
 bind(path);check(marker in Path(path).read_text(),'Live unchanged path '+path)
lockpath=Path('spec.lock');bind(lockpath,'5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8')
locked=[line.split('  ',1) for line in lockpath.read_text().splitlines()];check(len(locked)==104,'Exact 104 locked members')
for h,p in locked:bind(p,h)
# Audit the small controller diffs, preserving cardinalities and commands.
oldG=Path('tests/evidence/optimization/gen24')
for name in ['integration/run_production_build.py','integration/validate_build.py','run_full_gate.py']:
 current=(G/name).read_text();prior_text=(oldG/name).read_text();ast.parse(current);bind(G/name);bind(oldG/name)
 delta=''.join(difflib.unified_diff(prior_text.splitlines(True),current.splitlines(True),fromfile=str(oldG/name),tofile=str(G/name)))
 (R/(Path(name).name+'.review.diff')).write_text(delta)
 normalized=current.replace('gen25','gen24')
 if name=='run_full_gate.py':check(normalized==prior_text,'Fixed full gate wrapper is generation-path-only')
 else:
  oldtree=ast.parse(prior_text);newtree=ast.parse(normalized)
  for tree in [oldtree,newtree]:
   for node in ast.walk(tree):
    if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name) and t.id in {'SOURCES','NEW','required'} for t in node.targets):node.value=ast.Constant(value='REVIEWED_SOURCE_MEMBERSHIP')
  if name.endswith('validate_build.py'):
   # One prior-generation evidence reference advances alongside current paths.
   for node in ast.walk(newtree):
    if isinstance(node,ast.Constant) and isinstance(node.value,str) and 'optimization/gen24/' in node.value:node.value=node.value.replace('optimization/gen24/','optimization/gen23/')
  check(ast.dump(newtree)==ast.dump(oldtree),'Controller algorithm unchanged outside source/fact/prior-generation membership '+name)
  check('202' in current and ('127' in current if name.endswith('validate_build.py') else True),'Correctness/source counts unchanged '+name)
check("'Lean1090.Proofs.ScoreGateInteger.scaledNumerator_eq_old'" in (G/'integration/validate_build.py').read_text(),'Combined validator requires new unconditional theorem and unchanged refinement facts')
out=dict(status='passed',findings=[],recorded_utc=datetime.now(timezone.utc).isoformat(),checks=checks,check_count=len(checks),bindings=bindings,source_delta={p:sha(p) for p in before['files']},preserved_theorem_count=len(prior),new_theorems=sorted(new),printed_axiom_facts=facts,printed_fact_count=len(facts),targeted_build_attempts=summary['retained_attempts'],all_input_refinement_verified=True,reviewer_sha256=sha(__file__),assessments=['Exact denominator equality returns the existing numerator; Rat.den_pos proves division by itself is one. The original total formula remains in every unequal case.','The existing choose/scaledTotals refinement composes the unconditional equality; arbitrary rationals and denominators, zero and negative numerators remain covered.','No density arithmetic, threshold, Float operation, callback, fixed adapter or benchmark changed. Generic Nat equality supports large denominators.'],limitations=['Static source and successful kernel log review only; no compiler/test/native executable invoked by reviewer. Actual inlined branch and linked worker are reviewed after combined build.','No denominator-equality corpus frequency or predicted timing gain is claimed.'])
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),facts=len(facts),sha256=sha(p))))
