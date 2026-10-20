#!/usr/bin/env python3
"""Independent source-only controller review; never import or execute producers."""
import sys
sys.dont_write_bytecode=True
import ast,difflib,hashlib,json,subprocess
from datetime import datetime,timezone
from pathlib import Path
R=Path(__file__).resolve().parents[5]
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
checks=[]
def req(ok,label):
 assert ok,label
 checks.append(label)
def delta(o,n):
 return ''.join(difflib.unified_diff(o.read_text().splitlines(True),n.read_text().splitlines(True),fromfile=str(o.relative_to(R)),tofile=str(n.relative_to(R))))
def seal(e,files,assessments):
 out=e/'independent-review/preparation-review.json';assert not out.exists()
 data={'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks[:],'bindings':{str(p.relative_to(R)):sha(p) for p in files+[Path(__file__)]},'assessments':assessments,'controller_import_execution_build_profile_history_snapshot_or_cleanup_performed':False,'scope':'Prepared source only. Exact published artifact, completed builds, resolved sequential controller and current native/source evidence remain required before respective later phases.'}
 out.write_text(json.dumps(data,indent=2)+'\n');print(json.dumps({'path':str(out.relative_to(R)),'checks':len(checks),'sha256':sha(out)}))
E=R/'tests/evidence/diagnostics/gen25';P=R/'tests/evidence/diagnostics/gen24';p=load(E/'preparation.json');prior=load(P/'preparation.json')
req(sha(E/'preparation.json')=='e52148834747867802d9cb50ed11edc6319be759ead8705377a39696c2fc139c','exact decode preparation')
req(p['status']=='prepared_not_executed' and p['artifact_commit'] is None,'decode future artifact unresolved')
req(p['expected_correctness_input_count']==202 and p['expected_prior_csv_rows']==52,'decode current counts')
files=[E/'preparation.json',E/'preparation.diff'];diff=''
for name,row in p['files'].items():
 n=R/name;o=R/row['adapted_from'];req(sha(n)==row['sha256'] and sha(o)==row['prior_sha256'],'decode source bindings '+name)
 ast.parse(n.read_text());diff+=delta(o,n);files += [n,o]
req(diff==(E/'preparation.diff').read_text() and sha(E/'preparation.diff')==p['diff_sha256'],'exact decode retained full diff')
req((E/'snapshot_history.py').read_text()==(P/'snapshot_history.py').read_text().replace('gen24','gen25').replace('GEN24','GEN25'),'history path-only adaptation')
expected=(P/'run_prepared.py').read_text().replace('gen24','gen25').replace('== 24','== 25')
req(expected==(E/'run_prepared.py').read_text(),'decode only generation/path adaptation; source/count guards unchanged')
req(p['generic_helpers']==prior['generic_helpers'] and len(p['generic_helpers'])==9,'nine shared decode helpers unchanged')
for name,digest in p['generic_helpers'].items():
 req(sha(R/name)==digest,'decode helper '+name);files.append(R/name)
for name,digest in p['updated_committed_helpers'].items():
 req(hashlib.sha256(subprocess.check_output(['git','cat-file','blob',p['timed_commit']+':'+name],cwd=R)).hexdigest()==digest,'measured committed helper '+name)
summary=load(R/'bench/runs/gen25/summary.json');review=load(R/'bench/runs/gen25/results-review.json')
req(summary['commit']==p['timed_commit'] and summary['binary_sha256']==p['worker_sha256'],'measured decode source and worker')
for key,name in [('benchmark_summary_sha256','summary.json'),('benchmark_result_review_sha256','results-review.json')]:
 q=R/'bench/runs/gen25'/name;req(sha(q)==p[key],'measured receipt '+name);files.append(q)
req(review['status']=='passed' and not review['findings'],'independent measured result passed')
v=p['diagnostic_tooling_validation'];req(v==prior['diagnostic_tooling_validation'] and sha(R/v['path'])==v['sha256'],'retained shared tooling validation');files.append(R/v['path'])
inputs=load(R/'bench/runs/gen25/correctness-inputs.json');req(len(inputs)==202 and all(sha(R/k)==v for k,v in inputs.items()),'all 202 timed correctness inputs unchanged')
seal(E,files,['Unchanged guard binds exact measured worker, six clean checks, all correctness/native/locked inputs and descendant published artifact; only diagnostic driver builds may differ.','Full per-DF/scored-register census and 13 profiles require sequential isolated capture completion and history hold. Complete output digests and stage accounting remain unchanged.','Current native inspection must establish the actual equal-denominator numerator identity in choose and both scaledTotals folds, with 21 unchanged sibling sets. Retain prior semantic/validity/raw-word/CRC/affine/conversion/fallback anchors. Direct-child observations do not infer branch hit rates or presume timing benefit; the measured regression remains recorded.'])
