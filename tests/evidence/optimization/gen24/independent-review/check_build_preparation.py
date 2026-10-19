import sys
sys.dont_write_bytecode=True
from pathlib import Path
import ast,hashlib,json,re
from datetime import datetime,timezone
R=Path('tests/evidence/optimization/gen24/independent-review');checks=[];bindings={}
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
def check(ok,label):assert ok,label;checks.append(label)
for name in ['run_production_build.py','validate_build.py']:
 old=Path('tests/evidence/optimization/gen23/integration')/name;new=Path('tests/evidence/optimization/gen24/integration')/name
 a=old.read_text();b=new.read_text();ast.parse(b)
 expected=a.replace('gen23','GENCURRENT').replace('gen22','gen23').replace('GENCURRENT','gen24').replace('== 200','== 202').replace('== 125','== 127')
 for begin,end in [('SOURCES = ','\nCOMMAND' if name=='run_production_build.py' else '\nNEW'),*([('NEW = ','\nBINARIES'),('    required = ','\n    assert required')] if name=='validate_build.py' else [])]:
  original=expected[expected.index(begin):expected.index(end,expected.index(begin))]
  replacement=b[b.index(begin):b.index(end,b.index(begin))]
  expected=expected.replace(original,replacement)
 check(expected==b,name+' exact generation/count/source-set/required-fact adaptation only')
 assignments={n.targets[0].id:ast.literal_eval(n.value) for n in ast.parse(b).body if isinstance(n,ast.Assign) and isinstance(n.targets[0],ast.Name) and n.targets[0].id in ['SOURCES','NEW','COMMAND','BINARIES']}
 check(set(assignments['SOURCES'])=={'Impl/CommB.lean','Impl/Semantics.lean','Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean','Proofs/CommBTables.lean','Proofs/CommBPenalty.lean','Proofs/Decoder.lean'},name+' exact seven authorized sources')
 check(set(assignments['BINARIES'])=={'lean1090','messageGenerator','commbDifferential','lean1090-bench'},name+' all four production binaries')
 if name=='validate_build.py':
  check(set(assignments['NEW'])=={'Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean'},'Exactly two new proof modules')
  check(all(n in b for n in ['Lean1090.Proofs.Refinement','Lean1090.Proofs.CPRTrackingRefinement','Lean1090.Proofs.CommBValueReuse.oracleValues_eq','Lean1090.Proofs.CommBSemanticReuse.commB_eq_old']),'Validator requires both unchanged capstone bridges and both new complete equalities')
 else:check(assignments['COMMAND']==['lake','build','Proofs.Decoder','Proofs.CPRTracking','lean1090','messageGenerator','commbDifferential','lean1090-bench'],'Combined build command unchanged')
 for p in [old,new,Path(str(new)+'.adaptation.diff')]:bindings[str(p)]=sha(p)
old=Path('tests/evidence/optimization/gen23/run_full_gate.py');new=Path('tests/evidence/optimization/gen24/run_full_gate.py')
check(old.read_text().replace('gen23','gen24')==new.read_text(),'Full gate wrapper exact generation-only adaptation; frozen gate command unchanged')
for p in [old,new,'review/diagnostics/run_generation_benchmark.py','scripts/check_all.sh']:bindings[str(p)]=sha(p)
result=dict(status='passed_read_only_preparation_review',recorded_utc=datetime.now(timezone.utc).isoformat(),checks=checks,checks_passed=len(checks),bindings=bindings,findings=[],execution='No controller imports, builds, tests or producer execution. Actual inventories and binary/fact bindings remain guarded by the completed-build validator.',checker_sha256=sha(__file__))
p=R/'build-preparation-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status=result['status'],checks=len(checks),sha256=sha(p))))
