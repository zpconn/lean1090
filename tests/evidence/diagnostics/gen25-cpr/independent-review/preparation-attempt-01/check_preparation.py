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
E=R/'tests/evidence/diagnostics/gen25-cpr';P=R/'tests/evidence/diagnostics/gen24-cpr';p=load(E/'preparation.json');prior=load(P/'preparation.json')
summary=load(R/'bench/runs/gen25/summary.json');inputs=load(R/'bench/runs/gen25/correctness-inputs.json')
req(sha(E/'preparation.json')=='74070f0d26bfb56c3a7ffe02c1158e69361b4f7408e7a79392a304cd4c666a9d','exact CPR preparation')
req(p['status']=='prepared_not_executed' and p['benchmark_bindings']['artifact_commit'] is None,'CPR future artifact unresolved')
req(p['expected_correctness_inputs']==202 and p['expected_prior_csv_rows']==52,'CPR current counts')
files=[E/'preparation.json',E/'preparation.diff'];diff=''
paragraph="\nThe current score-scaling path returns the numerator directly when the exact\ncommon denominator equals the rational denominator, and preserves the original\ninteger division/product otherwise. Its unrestricted proof and actual native\nbranches are bound by the source review. Caller counts and inlined instruction\ntotals do not reveal the equal-denominator input frequency or elapsed savings.\n"
for name,row in p['prior_controller_bindings'].items():
 o=R/row['prior_path'];n=R/row['prepared_path'];req(sha(o)==row['prior_sha256'] and sha(n)==row['prepared_sha256'],'CPR source bindings '+name)
 actual=n.read_text();ast.parse(actual);diff+=delta(o,n);files += [o,n]
 expected=o.read_text().replace('gen24','gen25').replace('GEN24','GEN25').replace('Generation 24','Generation 25')
 if name=='run_prepared.py':
  expected=expected.replace("summary['generation']==24","summary['generation']==25")
  expected=expected.replace("'Impl/Semantics.lean'}","'Impl/Semantics.lean','Impl/ScoreGate.lean','Proofs/ScoreGateInteger.lean'}")
 elif name in ('analyze_and_archive.py','finalize.py'):
  indent='    ' if name=='finalize.py' else ''
  needle=indent+"assert source_review['commb_semantic_reuse_live_path_verified']\n"
  expected=expected.replace(needle,needle+indent+"assert source_review['score_scaling_identity_live_path_verified']\n")
 elif name=='write_report.py':
  needle="assert source['commb_semantic_reuse_live_path_verified']\n"
  expected=expected.replace(needle,needle+"assert source['score_scaling_identity_live_path_verified']\n")
  needle='standalone symbols do not imply absent inlined work or a measured hit rate.\n'
  assert expected.count(needle)==1
  expected=expected.replace(needle,needle+paragraph)
 elif name=='perf/seal_perf.py':expected=expected.replace('gen23-cpr/perf/analyze_cpr_perf.py','gen24-cpr/perf/analyze_cpr_perf.py')
 req(actual==expected,'exact CPR allowed delta '+name)
req(len(p['prior_controller_bindings'])==10 and diff==(E/'preparation.diff').read_text() and sha(E/'preparation.diff')==p['diff']['sha256'],'exact ten-source CPR retained diff')
for name,digest in p['helpers'].items():
 req(sha(R/name)==digest,'CPR bound helper '+name);files.append(R/name)
 if name.startswith('review/'):
  req(prior['helpers'][name]==digest,'unchanged shared CPR helper '+name)
  req(hashlib.sha256(subprocess.check_output(['git','cat-file','blob',p['benchmark_bindings']['timed_commit']+':'+name],cwd=R)).hexdigest()==digest,'measured committed CPR helper '+name)
for key in ['prior_successful_build','prior_final_review','diagnostic_tooling_validation']:
 item=p[key];req(sha(R/item['path'])==item['sha256'],'retained CPR '+key);files.append(R/item['path'])
b=p['benchmark_bindings'];req(b['timed_commit']==summary['commit'] and b['worker_sha256']==summary['binary_sha256'],'CPR measured identities')
req(sha(R/'bench/runs/gen25/summary.json')==b['summary_sha256'] and sha(R/'bench/runs/gen25/results-review.json')==b['result_review_sha256'],'CPR measured receipt hashes')
req(set(p['prepared_runtime_bindings'])=={'Impl/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Impl/CommB.lean','Impl/Semantics.lean'} and all(sha(R/k)==v==inputs[k] for k,v in p['prepared_runtime_bindings'].items()),'current score change and retained semantic bindings are timed inputs')
q=R/'tests/evidence/diagnostics/gen25/independent-review/preparation-review.json';req(load(q)['status']=='passed_read_only_preparation_review','decode guard independently reviewed');files.append(q)
ip=load(E/'isolated-perf-pending.json');prep=E/'prepare_isolated_perf.py';ast.parse(prep.read_text())
req(sha(prep)==ip['preparer_sha256']=='4ceaeee94c87de2d56e98a3c72521916124325a40fe474a9bc95cbffbcca58c1','isolated preparer exact source')
req(sha(E/'prepare_isolated_perf.diff')==ip['preparer_diff_sha256'] and delta(P/'prepare_isolated_perf.py',prep)==(E/'prepare_isolated_perf.diff').read_text(),'isolated preparer retained exact diff')
expected=(P/'prepare_isolated_perf.py').read_text().replace('gen24','GENCURRENT').replace('gen23','gen24').replace('GENCURRENT','gen25')
old_summary=load(R/'bench/runs/gen24/summary.json')
expected=expected.replace(old_summary['commit'],summary['commit']).replace(old_summary['binary_sha256'],summary['binary_sha256'])
expected=expected.replace("    '==200': '==202', \"'correctness_inputs':200\": \"'correctness_inputs':202\",\n",'')
req(expected==prep.read_text(),'isolated preparer generation/measured identities only; obsolete count substitution removed')
for key in ['prior_controller','prior_bindings']:
 req(sha(R/ip[key])==ip[key+'_sha256'],'isolated '+key);files.append(R/ip[key])
req(all(ip[k] is None for k in ['artifact_commit','source_binding_sha256','driver_build_hashes']) and ip['correctness_inputs']==202 and ip['cpr_preparation_sha256']==sha(E/'preparation.json'),'isolated pending hashes intentionally unresolved')
req(not (E/'run_isolated_perf.py').exists() and not ip['capture_started'] and not ip['build_started'],'isolated controller not generated or run')
req(len(inputs)==202 and all(sha(R/k)==v for k,v in inputs.items()),'all 202 correctness inputs unchanged after source review')
files += [prep,E/'prepare_isolated_perf.diff',E/'isolated-perf-pending.json']
seal(E,files,['Exact ten-source adaptation preserves live immediate decode/streamStep, preallocation outside collection, all 172432 messages and tracking rows, complete final StreamState and routed positions, and same-generation full message digest.','New score identity flag is mandatory in analysis/report/finalizer. Prior semantic/validity/CRC/table/affine/conversion keys remain; no Float callback or tested-only boundary change. Counts cannot infer equality-arm frequency or presumed savings.','Numeric/perf parsers and all nine generic helpers remain exact; costs are exclusive self partitions with separately overlapping caller/helper contexts. Rational arguments are not observed by these profiles.','Sequential preparer retains exact artifact/driver/source checks, CPU0 decode-then-CPR protocol, all-input rehashes, protected prepared helper exception and output refusal. Actual builds/resolved controller still required.','Cleanup remains exact retained duplicates/bound rebuildables only after final seals, preserving unique perf, failures and unmatched scratch.'])
