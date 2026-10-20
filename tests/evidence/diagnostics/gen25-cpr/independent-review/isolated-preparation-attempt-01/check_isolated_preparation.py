"""Source-only concrete perf-controller review; does not execute its code."""
import sys
sys.dont_write_bytecode=True
import ast,difflib,hashlib,json,subprocess
from pathlib import Path
from datetime import datetime,timezone
R=Path.cwd();E=R/'tests/evidence/diagnostics/gen25-cpr';P=R/'tests/evidence/diagnostics/gen24-cpr'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();load=lambda p:json.loads(p.read_text())
checks=[]
def check(ok,label):
 assert ok,label
 checks.append(label)
p=load(E/'run_isolated_perf.preparation.json');old=load(P/'run_isolated_perf.preparation.json');summary=load(R/'bench/runs/gen25/summary.json')
check(p['source_sha256']==sha(E/'run_isolated_perf.py'),'actual generated controller')
check(p['prior_source_sha256']==sha(P/'run_isolated_perf.py')==old['source_sha256'],'prior reviewed controller')
head=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()
check(head==p['artifact_commit']=='240cc329f5334e8557687eddc56a854edd2720bc','published current artifact')
check(p['timed_commit']==summary['commit'] and p['worker_sha256']==summary['binary_sha256'] and p['correctness_inputs']==202,'actual measured identities and input count')
binding=R/'tests/evidence/diagnostics/gen25/benchmark-source-binding.json';b=load(binding)
check(sha(binding)==p['source_binding_sha256'] and b['status']=='passed' and b['diagnostic_commit']==head and b['timed_original_commit']==summary['commit'],'completed source equivalence')
expected={'gen24':'gen25',old['artifact_commit']:head,old['timed_commit']:summary['commit'],old['worker_sha256']:summary['binary_sha256'],old['source_binding_sha256']:sha(binding),old['builds']['.cache/gen24-costs/driver/driver-build.json']:sha(R/'.cache/gen25-costs/driver/driver-build.json'),old['builds']['.cache/gen24-cpr-costs/driver-final/driver-build.json']:sha(R/'.cache/gen25-cpr-costs/driver-final/driver-build.json')}
check(p['replacements']==expected,'exact allowed substitutions independently derived')
a=(P/'run_isolated_perf.py').read_text()
for k,v in expected.items():
 check(k in a,'declared replacement '+k);a=a.replace(k,v)
oldhelpers={k.replace('gen24','gen25'):v for k,v in old['prepared_perf_helpers'].items()}
needle='prepared_perf_helpers='+repr(oldhelpers);check(a.count(needle)==1,'exact original prepared helper dictionary')
a=a.replace(needle,'prepared_perf_helpers='+repr(p['prepared_perf_helpers']))
actual=(E/'run_isolated_perf.py').read_text();ast.parse(actual)
check(a==actual,'full source identical after only allowed binding substitutions')
diff=''.join(difflib.unified_diff((P/'run_isolated_perf.py').read_text().splitlines(True),actual.splitlines(True),fromfile=str((P/'run_isolated_perf.py').relative_to(R)),tofile=str((E/'run_isolated_perf.py').relative_to(R))))
check(diff==(E/'run_isolated_perf.diff').read_text() and sha(E/'run_isolated_perf.diff')==p['diff_sha256'],'retained exact source diff')
for name,digest in {**p['builds'],**p['prepared_perf_helpers']}.items():
 check(sha(R/name)==digest,'current completed or prepared binding '+name)
for name in p['builds']:check(load(R/name)['status']=='passed','completed diagnostic driver '+name)
check({str(q.relative_to(R)) for q in (E/'perf').iterdir()}==set(p['prepared_perf_helpers']),'only exact prepared helper files preexist')
check(all(not (R/q).exists() for q in ['.cache/gen25-costs/perf-gen25','.cache/gen25-cpr-costs/perf-gen25-cpr','tests/evidence/diagnostics/gen25/perf']),'both capture caches and decode output absent')
files=[E/'run_isolated_perf.py',E/'run_isolated_perf.preparation.json',E/'run_isolated_perf.diff',P/'run_isolated_perf.py',P/'run_isolated_perf.preparation.json',binding,Path(__file__).resolve()]+[R/k for k in {**p['builds'],**p['prepared_perf_helpers']}]
out=E/'independent-review/isolated-perf-preparation-review.json';assert not out.exists()
out.write_text(json.dumps({'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'checks_passed':len(checks),'checks':checks,'findings':[],'bindings':{str(q.relative_to(R)):sha(q) for q in files},'scope':'Exact source-only adaptation review. Sequential actual-worker decode then CPR, CPU 0, cpu-clock:u 199 Hz/dwarf16384, full input/output positions, prepared-helper-only directory exception and strict overwrite guards unchanged. No controller import, capture, native inspection, build, workload or profile execution.','all_jobs_stopped':True},indent=2)+'\n')
print(json.dumps({'status':'passed','checks':len(checks),'sha256':sha(out)}))
