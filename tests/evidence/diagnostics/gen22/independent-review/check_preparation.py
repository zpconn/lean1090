#!/usr/bin/env python3
"""Read-only source/hash review; never import or execute prepared controllers."""
import sys
sys.dont_write_bytecode=True
import ast,difflib,hashlib,json,subprocess
from datetime import datetime,timezone
from pathlib import Path
R=Path(__file__).resolve().parents[5]
E=R/'tests/evidence/diagnostics/gen22'
O=E/'independent-review/preparation-review.json'
assert not O.exists()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
checks=[]
def require(ok,label):
    assert ok,label
    checks.append(label)
p=load(E/'preparation.json')
require(sha(E/'preparation.json')=='a5b4eb4e2e5df12a32ff5f3f8a0b1ebfa33f7d64054b65b5a0590cec7d224c5b','exact prepared metadata')
require(p['artifact_commit'] is None and p['status']=='prepared_not_executed','future artifact unresolved')
require(p['expected_correctness_input_count']==197 and p['expected_prior_csv_rows']==46,'actual input and row counts')
diff=''
texts={}
for name,row in p['files'].items():
    current=R/name;prior=R/row['adapted_from']
    require(sha(current)==row['sha256'],'current hash '+name)
    require(sha(prior)==row['prior_sha256'],'prior hash '+name)
    ast.parse(current.read_text())
    texts[current.name]=current.read_text()
    diff+=''.join(difflib.unified_diff(prior.read_text().splitlines(True),current.read_text().splitlines(True),fromfile=str(prior.relative_to(R)),tofile=name))
require((E/'preparation.diff').read_text()==diff and sha(E/'preparation.diff')==p['diff_sha256'],'exact retained diff')
require(texts['snapshot_history.py']==(R/'tests/evidence/diagnostics/gen21/snapshot_history.py').read_text().replace('gen21','gen22').replace('GEN21','GEN22'),'history is exact generation-only adaptation')
prior=(R/'tests/evidence/diagnostics/gen21/run_prepared.py').read_text().replace('gen21','gen22').replace("== 21","== 22")
prior=prior.replace('len(correctness) == 195','len(correctness) == 197')
prior=prior.replace("'Proofs/ParityByte.lean'}", "'Proofs/ParityByte.lean',\n            'Proofs/FrameWord.lean', 'Proofs/RawSyndromeSpec.lean'}")
added="""    preparation = read(E / 'preparation.json')
    assert summary['commit'] == preparation['timed_commit']
    assert summary['binary_sha256'] == preparation['worker_sha256']
    for name, digest in preparation['generic_helpers'].items():
        assert sha(ROOT / name) == digest, name
    for name, digest in preparation['updated_committed_helpers'].items():
        committed = subprocess.check_output(['git', 'show', summary['commit'] + ':' + name], cwd=ROOT)
        assert hashlib.sha256(committed).hexdigest() == digest, name
"""
require(texts['run_prepared.py']==prior.replace('    return summary\n',added+'    return summary\n'),'controller changes exactly paths/count/new proof guards and additional immutable pins')
for name,digest in p['generic_helpers'].items():
    require(sha(R/name)==digest,'generic helper '+name)
for name,digest in p['updated_committed_helpers'].items():
    data=subprocess.check_output(['git','cat-file','blob',p['timed_commit']+':'+name],cwd=R)
    require(hashlib.sha256(data).hexdigest()==digest,'updated helper committed '+name)
for key,name in [('benchmark_summary_sha256','summary.json'),('benchmark_result_review_sha256','results-review.json')]:
    require(sha(R/'bench/runs/gen22'/name)==p[key],'measured '+name)
summary=load(R/'bench/runs/gen22/summary.json')
require(summary['commit']==p['timed_commit'] and summary['binary_sha256']==p['worker_sha256'],'actual measured pins')
require(sha(R/'tests/evidence/optimization/gen22/independent-review/benchmark-relocation-review.json')==p['benchmark_relocation_review_sha256'],'relocation review binding')
v=p['diagnostic_tooling_validation'];require(sha(R/v['path'])==v['sha256'],'tooling validation binding')
require(load(R/v['path'])['changed_helpers']==p['updated_committed_helpers'],'updated helper validation scope exact')
inputs=load(R/'bench/runs/gen22/correctness-inputs.json')
require(len(inputs)==197 and all(sha(R/k)==v for k,v in inputs.items()),'197 correctness inputs unchanged')
bindings={str(x.relative_to(R)):sha(x) for x in [E/'preparation.json',E/'preparation.diff',E/'run_prepared.py',E/'snapshot_history.py',Path(__file__),R/v['path'],R/'bench/runs/gen22/results-review.json',R/'bench/runs/gen22/summary.json']}
record={'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks,'bindings':bindings,'assessments':['Prior full-source/native/lock/six clean checkpoints and measured result checks retained. Exact root-supplied artifact must be a distinct descendant HEAD before execution.','Build remains isolated to diagnostic driver using all 22 fresh measured native sets; no production rebuild command added.','Campaign retains both sequential perf seals, exact timed worker/input checks, completed driver and history prerequisites; no guessed native populations.','Snapshot history algorithm unchanged, with only the two current diagnostic roots and two exact report names excluded.','Updated census validates returned wire word/raw CRC and retained standalone syndrome outside collection, as separately committed fixture evidence records. Actual future source/native flag and parser/CRC anchors still required.','All per-DF and scored-register profiles/full output checks remain in unchanged campaign helpers; actual root accounting and table/fallback observations await fresh collection.'],'controller_import_execution_build_profile_or_history_snapshot_performed':False,'scope':'Preparation only; not acceptance of future build, sampling, collection, output counts, report or cleanup.'}
O.write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'status':record['status'],'checks_passed':len(checks),'sha256':sha(O)},indent=2))
