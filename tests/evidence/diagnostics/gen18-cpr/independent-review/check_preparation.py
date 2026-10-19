#!/usr/bin/env python3
"""Read-only source comparison. Never import or execute a diagnostic controller."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,hashlib,json
D=Path('tests/evidence/diagnostics/gen18');C=Path('tests/evidence/diagnostics/gen18-cpr');R=C/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
bindings={};checks=[]
def bind(p):bindings[str(p)]=sha(p)
def normalized_old(new):
 old=Path(str(new).replace('gen18','gen17'));bind(old);bind(new)
 return old.read_text().replace('gen17','gen18').replace('GEN17','GEN18')
d=load(D/'preparation.json');c=load(C/'preparation.json');bind(D/'preparation.json');bind(C/'preparation.json')
assert d['status']==c['status']=='prepared_not_executed' and c['generation']==18
for p,row in d['files'].items():assert sha(p)==row['sha256'] and sha(row['adapted_from'])==row['prior_sha256']
for p,h in c['helpers'].items():assert sha(p)==h;bind(p);ast.parse(Path(p).read_text()) if p.endswith('.py') else None
for name,row in c['prior_controller_bindings'].items():
 assert sha(row['prior_path'])==row['prior_sha256'] and sha(row['prepared_path'])==row['prepared_sha256']
for p in [D/'run_prepared.py',D/'snapshot_history.py']:
 expected=normalized_old(p)
 if p.name=='run_prepared.py':expected=expected.replace("summary['generation'] == 17","summary['generation'] == 18").replace("review['generation'] == 17","review['generation'] == 18")
 assert p.read_text()==expected,p;ast.parse(expected)
checks.append('Decode controller/history source is byte-exact after generation path and expected generation-number substitutions.')
p=C/'run_prepared.py';expected=normalized_old(p)
anchor=" summary=module.guard()  # Reviewed benchmark, six clean checks, full inputs/native/lock binding.\n"
assert expected.count(anchor)==1;expected=expected.replace(anchor,anchor+" assert summary['generation']==18\n")
old="'controller_sha256':sha(__file__),'commands':[]}";new="'controller_sha256':sha(__file__),'decode_controller_sha256':sha(ROOT/'tests/evidence/diagnostics/gen18/run_prepared.py'),'commands':[]}"
assert expected.count(old)==1;expected=expected.replace(old,new);assert p.read_text()==expected
checks.append('CPR controller adds only explicit generation assertion and retained execution-time decode-controller hash beyond path substitutions.')
p=C/'analyze_and_archive.py';expected=normalized_old(p)
extra="""# Preparation never executes this file. Collection, source review and parent release
# must already have completed before any analysis/archive writes.
collection = load(BASE / 'collect-execution.json')
assert collection['status'] == 'passed' and collection['all_inputs_unchanged']
source_review = load(BASE / 'independent-review/source-review.json')
assert source_review['status'] == 'passed_read_only_source_and_native_review'
assert source_review['worker_sha256'] == collection['worker_sha256']
"""
anchor="run = load(CACHE / 'callgrind/run.json')";assert expected.count(anchor)==1;expected=expected.replace(anchor,extra+anchor);assert p.read_text()==expected
checks.append('Analysis/archive adds passed collection and independent same-worker source review checks before any writes; existing full raw/analysis/gzip/archival guards remain exact.')
p=C/'extract_table_contexts.py';assert p.read_text()==normalized_old(p)
p=C/'extract_numeric_contexts.py';expected=normalized_old(p)
anchor="              'lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat',\n";assert expected.count(anchor)==1;expected=expected.replace(anchor,anchor+"              'lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback',\n")
old='No exponent-frequency or future-table-hit claim is inferred from these call counts.'
new='The guarded toFloat wrapper and its original fallback are observed separately where their native boundaries remain. Inlined packing and scalar zero paths remain in the full contexts; no fast-path population, exponent frequency or table-hit claim is inferred from instruction costs or an absent wrapper.'
assert expected.count(old)==1;expected=expected.replace(old,new);assert p.read_text()==expected
checks.append('Numeric extractor adds only the toFloatFallback direct-edge target and explicit overlap/population caveats; parser, all-context reconciliation and exclusive stage logic unchanged.')
prior=load('tests/evidence/diagnostics/gen17-cpr/preparation.json')
for p,h in c['helpers'].items():
 if p.startswith('review/'):
  assert prior['helpers'][p]==h,p
checks.append('All shared live driver/build/validation/profiling/accounting/archive tools are unchanged from the reviewed gen17 preparation.')
assert c['benchmark_bindings']['status']=='unresolved_until_reviewed_gen18_benchmark'
assert all(c['benchmark_bindings'][key] is None for key in ['timed_commit','artifact_commit','worker_sha256','fresh_native_inputs_sha256','results_review_sha256'])
assert not c['native_work_started'] and not c['profile_or_capture_started'] and d['no_generation19_change_selected']
for p in [C/'build-execution.json',C/'collect-execution.json',D/'driver-build-command.json',D/'campaign-command.json']:
 assert not p.exists(),p
checks.extend([
 'Execution requires actual complete two-mode benchmark summary, matching independent review/commit/worker, 48 samples each, six clean checks, frozen lock, native object hashes and current correctness inventory; CPR additionally verifies every one of 22 fresh native sets and a later descendant artifact commit.',
 'No diagnostic command runs without explicit --execute. Both completed isolated actual-worker captures precede collection, with matching worker/raw hashes and unchanged inputs; root release is an additional orchestration requirement.',
 'Unchanged CPR driver/validator retain exact full-corpus timestamp and airport comparisons, every tracking row, final projection, full StreamState/routed-position batch equality and all message outputs; collected result must equal validated result apart from the deliberately excluded batch audit flag.',
 'Full self-event stage/root accounting remains unchanged; selected helper and direct-edge observations overlap. Subtracting fallback from wrapper alone does not separate scalar zero from fast dyadic inputs.',
 'Current native initialization/packing/fallback anchors, same-generation decoded-message digest, final raw/archive review and cleanup receipts remain execution-time obligations, not prepared success claims.'
])
result={'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'checker_sha256':sha(__file__),'bindings':bindings,'checks':checks,'findings':[],'controllers_executed':False,'native_build_or_profile_started_by_reviewer':False,'limits':['Preparation source review only; future worker identities, outputs, counters and reports are deliberately unresolved.','Root authorizes execution after reviewed timing and artifact publication; no generation19 optimization is selected by this review.']}
p=R/'preparation-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':result['status'],'sha256':sha(p),'bound_files':len(bindings),'checks':len(checks)}))
