"""Focused read-only controller/diff review; no build, gate or cleanup."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,difflib,hashlib,json
G=Path('tests/evidence/optimization/gen26');R=G/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 p=Path(p);actual=sha(p);check(h is None or actual==h,'Hash '+str(p));bindings[str(p)]=actual
prep=read(G/'integration/preparation.json');fixed=read(G/'fixed-finishing-preparation.json')
for path in [G/'integration/preparation.json',G/'fixed-finishing-preparation.json']:bind(path)
records={**prep['adaptations'],**fixed['adaptations']}
check(set(records)=={'integration/run_production_build.py','integration/validate_build.py','run_full_gate.py','select_finish_gate.py'},'Exact four controller adaptations')
for name,row in records.items():
 for p,h in [(row['path'],row['sha256']),(row['prior_path'],row['prior_sha256']),(row['diff_path'],row['diff_sha256'])]:bind(p,h)
 old=Path(row['prior_path']).read_text();new=Path(row['path']).read_text();ast.parse(new)
 check(Path(row['diff_path']).read_text()==''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile=row['prior_path'],tofile=row['path'])),'Exact retained diff '+name)
 expected=old.replace('gen25','gen26')
 if name=='select_finish_gate.py':expected=expected.replace("'--generation', '25'","'--generation', '26'")
 if name.startswith('integration/'):
  expected=expected.replace("'Impl/ScoreGate.lean', 'Proofs/ScoreGateInteger.lean'","'Impl/Binary64.lean', 'Proofs/Binary64Runtime.lean'")
  if name.endswith('validate_build.py'):
   expected=expected.replace('optimization/gen24/','optimization/gen25/')
   expected=expected.replace("'Lean1090.Proofs.ScoreGateInteger.scaledNumerator_eq_old'", "'Lean1090.Proofs.Binary64Runtime.round_eq',\n                'Lean1090.Proofs.Binary64Runtime.round_function_eq',\n                'Lean1090.Proofs.Binary64Runtime.roundFallback_eq',\n                'Lean1090.Proofs.Binary64Runtime.round_small_dyadic'")
 check(new==expected,'Only approved generation/source/fact substitutions '+name)
for path,h in {**prep['generic_helpers'],**fixed['generic_helpers']}.items():bind(path,h)
check(prep['sources']==['Impl/Binary64.lean','Proofs/Binary64Runtime.lean'] and prep['new_modules']==[],'Only existing runtime/proof files, no new modules')
check(prep['expected_correctness_inputs']==fixed['expected_gate_input_count']==202 and prep['expected_audited_sources']==fixed['expected_fresh_source_count']==127 and prep['expected_native_sets']==22,'Unchanged input/source/native cardinalities')
check(prep['command']==['lake','build','Proofs.Decoder','Proofs.CPRTracking','lean1090','messageGenerator','commbDifferential','lean1090-bench'],'Unchanged combined build command and four production binaries')
check(set(prep['required_facts'])=={'Lean1090.Proofs.Refinement','Lean1090.Proofs.CPRTrackingRefinement',*['Lean1090.Proofs.Binary64Runtime.'+n for n in ['round_eq','round_function_eq','roundFallback_eq','round_small_dyadic']]},'Both full refinements and exact round bridge interfaces required')
controls=read(G/'integration/preparation-checks.json');bind(G/'integration/preparation-checks.json')
check(controls['parser_control_exit_code']==0 and controls['parser_controls']=={'multiline_empty_and_axiom_free':'passed','rejected_controls':3},'Producer pure parser controls passed, unchanged parser algorithm independently diff-verified')
for stem,key in [('stdout','parser_stdout_sha256'),('stderr','parser_stderr_sha256')]:bind(G/f'integration/parser-controls.{stem}',controls[key])
check(controls['integration_preparation_sha256']==sha(G/'integration/preparation.json') and controls['fixed_finishing_preparation_sha256']==sha(G/'fixed-finishing-preparation.json'),'Preparation metadata and completed pure-control log bindings exact')
selector=(G/'select_finish_gate.py').read_text()
for marker in ["fresh['raw_scratch_deleted']", "selected['message'] == fresh['fixed_gate_scratch_preserved']",'reserved-velocity-proposal','gen15-interrupted-gate',"assert all(len(paths) == 1",'start <= birth <= end',"if not args.execute:","os.fsync(out.fileno())"]:check(marker in selector,'Retained exact selection/protection/durability guard '+marker)
result=dict(status='passed_read_only_preparation_review',findings=[],recorded_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,reviewer_sha256=sha(__file__),assessments=['Algorithms unchanged outside generation/source/fact membership. All cardinalities, output-preservation and retained-attempt guards remain.','Complete multiline and axiom-free announcement parsing rejects malformed, duplicate or unapproved facts. No parser logic changed.','Exact five-prefix scratch selection, fresh/historical protections and archive-first byte verification remain; no selector or cleanup executed.'],limits=['Preparation-only review. Actual required proof APIs, completed build, source inventory and binaries must pass execution validators after root release. No build, executable, gate or cleanup invoked by reviewer.'])
p=R/'integration-gate-preparation-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':result['status'],'checks':len(checks),'sha256':sha(p)}))
