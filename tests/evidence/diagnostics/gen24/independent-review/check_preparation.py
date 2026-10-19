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
E=R/'tests/evidence/diagnostics/gen24';P=R/'tests/evidence/diagnostics/gen23';p=load(E/'preparation.json');prior=load(P/'preparation.json')
req(sha(E/'preparation.json')=='8e98c01fea917d9bda9e5c44887141d4397306afb959403ea0738e190ef05a79','exact decode preparation')
req(p['status']=='prepared_not_executed' and p['artifact_commit'] is None,'decode future artifact unresolved')
req(p['expected_correctness_input_count']==202 and p['expected_prior_csv_rows']==50,'decode current counts')
files=[E/'preparation.json',E/'preparation.diff'];diff=''
for name,row in p['files'].items():
 n=R/name;o=R/row['adapted_from'];req(sha(n)==row['sha256'] and sha(o)==row['prior_sha256'],'decode source bindings '+name)
 ast.parse(n.read_text());diff+=delta(o,n);files += [n,o]
req(diff==(E/'preparation.diff').read_text() and sha(E/'preparation.diff')==p['diff_sha256'],'exact decode retained full diff')
req((E/'snapshot_history.py').read_text()==(P/'snapshot_history.py').read_text().replace('gen23','gen24').replace('GEN23','GEN24'),'history path-only adaptation')
expected=(P/'run_prepared.py').read_text().replace('gen23','gen24').replace('== 23','== 24').replace('len(correctness) == 200','len(correctness) == 202')
expected=expected.replace("'Proofs/CommBValidity60.lean'}", "'Proofs/CommBValidity60.lean', 'Proofs/CommBValueReuse.lean',\n            'Proofs/CommBSemanticReuse.lean'}")
req(expected==(E/'run_prepared.py').read_text(),'decode only generation/count/two-proof membership adaptation')
req(p['generic_helpers']==prior['generic_helpers'] and len(p['generic_helpers'])==9,'nine shared decode helpers unchanged')
for name,digest in p['generic_helpers'].items():
 req(sha(R/name)==digest,'decode helper '+name);files.append(R/name)
for name,digest in p['updated_committed_helpers'].items():
 req(hashlib.sha256(subprocess.check_output(['git','cat-file','blob',p['timed_commit']+':'+name],cwd=R)).hexdigest()==digest,'measured committed helper '+name)
summary=load(R/'bench/runs/gen24/summary.json');review=load(R/'bench/runs/gen24/results-review.json')
req(summary['commit']==p['timed_commit'] and summary['binary_sha256']==p['worker_sha256'],'measured decode source and worker')
for key,name in [('benchmark_summary_sha256','summary.json'),('benchmark_result_review_sha256','results-review.json')]:
 q=R/'bench/runs/gen24'/name;req(sha(q)==p[key],'measured receipt '+name);files.append(q)
req(review['status']=='passed' and not review['findings'],'independent measured result passed')
v=p['diagnostic_tooling_validation'];req(v==prior['diagnostic_tooling_validation'] and sha(R/v['path'])==v['sha256'],'retained shared tooling validation');files.append(R/v['path'])
inputs=load(R/'bench/runs/gen24/correctness-inputs.json');req(len(inputs)==202 and all(sha(R/k)==v for k,v in inputs.items()),'all 202 timed correctness inputs unchanged')
seal(E,files,['Unchanged guard binds exact measured worker, six clean checks, all correctness/native/locked inputs and descendant published artifact; only diagnostic driver builds may differ.','Full per-DF/scored-register census and 13 profiles require sequential isolated capture completion and history hold. Complete output digests and stage accounting remain unchanged.','Current native inspection must establish semantic sharing in CommB/Semantics, 20 unchanged siblings, and real scalar/numeric-map boundaries while retaining all previous validity/raw-word/CRC/affine/conversion/fallback anchors. Public commBValue remains live elsewhere; no global-zero or hit-rate inference.'])
checks.clear()
E=R/'tests/evidence/diagnostics/gen24-cpr';P=R/'tests/evidence/diagnostics/gen23-cpr';p=load(E/'preparation.json');prior=load(P/'preparation.json')
req(sha(E/'preparation.json')=='5778039be6f8502246160005910c36e9d15335bda651802b381ec931688b44ce','exact CPR preparation')
req(p['status']=='prepared_not_executed' and p['benchmark_bindings']['artifact_commit'] is None,'CPR future artifact unresolved')
req(p['expected_correctness_inputs']==202 and p['expected_prior_csv_rows']==50,'CPR current counts')
files=[E/'preparation.json',E/'preparation.diff'];diff=''
paragraph="\nThe source/native review also binds current Comm-B semantic sharing: scalar\nviews derive from the existing table values, while standard and oracle numeric\nviews share one pure NumericField expression list. Register 30/44 behavior,\nabsent statuses, expression structure and Float evaluation boundaries remain\nunchanged. Actual descendant calls stay in the full decoder partition; absent\nstandalone symbols do not imply absent inlined work or a measured hit rate.\n"
for name,row in p['prior_controller_bindings'].items():
 o=R/row['prior_path'];n=R/row['prepared_path'];req(sha(o)==row['prior_sha256'] and sha(n)==row['prepared_sha256'],'CPR source bindings '+name)
 actual=n.read_text();ast.parse(actual);diff+=delta(o,n);files += [o,n]
 expected=o.read_text().replace('gen23','gen24').replace('GEN23','GEN24').replace('Generation 23','Generation 24')
 if name=='run_prepared.py':
  expected=expected.replace("summary['generation']==23","summary['generation']==24").replace('len(correctness)==200','len(correctness)==202')
  expected=expected.replace("'Proofs/CommBValidity60.lean'}","'Proofs/CommBValidity60.lean','Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean','Impl/CommB.lean','Impl/Semantics.lean'}")
 elif name in ('analyze_and_archive.py','finalize.py'):
  indent='    ' if name=='finalize.py' else ''
  needle=indent+"assert source_review['commb_validity_tables_live_path_verified']\n"
  expected=expected.replace(needle,needle+indent+"assert source_review['commb_semantic_reuse_live_path_verified']\n")
 elif name=='write_report.py':
  needle="assert source['commb_validity_tables_live_path_verified']\n"
  expected=expected.replace(needle,needle+"assert source['commb_semantic_reuse_live_path_verified']\n")
  expected=expected.replace('boundary and its tested-only operations remain unchanged.\n','boundary and its tested-only operations remain unchanged.\n'+paragraph)
 elif name=='perf/seal_perf.py':expected=expected.replace('gen22-cpr/perf/analyze_cpr_perf.py','gen23-cpr/perf/analyze_cpr_perf.py')
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
req(sha(R/'bench/runs/gen24/summary.json')==b['summary_sha256'] and sha(R/'bench/runs/gen24/results-review.json')==b['result_review_sha256'],'CPR measured receipt hashes')
req(set(p['prepared_runtime_bindings'])=={'Impl/CommB.lean','Impl/Semantics.lean'} and all(sha(R/k)==v==inputs[k] for k,v in p['prepared_runtime_bindings'].items()),'exact changed runtime bindings are timed inputs')
q=R/'tests/evidence/diagnostics/gen24/independent-review/preparation-review.json';req(load(q)['status']=='passed_read_only_preparation_review','decode guard independently reviewed');files.append(q)
ip=load(E/'isolated-perf-pending.json');prep=E/'prepare_isolated_perf.py';ast.parse(prep.read_text())
req(sha(prep)==ip['preparer_sha256']=='96a817595c45334d45cf2c8a29aa2f4d2d07702e57a3ae88faaa9d7e65e34991','isolated preparer exact source')
req(sha(E/'prepare_isolated_perf.diff')==ip['preparer_diff_sha256'] and delta(P/'prepare_isolated_perf.py',prep)==(E/'prepare_isolated_perf.diff').read_text(),'isolated preparer retained exact diff')
expected=(P/'prepare_isolated_perf.py').read_text().replace('gen23','GENCURRENT').replace('gen22','gen23').replace('GENCURRENT','gen24')
old_summary=load(R/'bench/runs/gen23/summary.json')
expected=expected.replace(old_summary['commit'],summary['commit']).replace(old_summary['binary_sha256'],summary['binary_sha256'])
expected=expected.replace('len(correctness) == 200','len(correctness) == 202').replace("'correctness_inputs': 200","'correctness_inputs': 202")
expected=expected.replace("'==197': '==200', \"'correctness_inputs':197\": \"'correctness_inputs':200\",","'==200': '==202', \"'correctness_inputs':200\": \"'correctness_inputs':202\",")
req(expected==prep.read_text(),'isolated preparer generation/current counts/measured identities only')
for key in ['prior_controller','prior_bindings']:
 req(sha(R/ip[key])==ip[key+'_sha256'],'isolated '+key);files.append(R/ip[key])
req(all(ip[k] is None for k in ['artifact_commit','source_binding_sha256','driver_build_hashes']) and ip['correctness_inputs']==202 and ip['cpr_preparation_sha256']==sha(E/'preparation.json'),'isolated pending hashes intentionally unresolved')
req(not (E/'run_isolated_perf.py').exists() and not ip['capture_started'] and not ip['build_started'],'isolated controller not generated or run')
req(len(inputs)==202 and all(sha(R/k)==v for k,v in inputs.items()),'all 202 correctness inputs unchanged after source review')
files += [prep,E/'prepare_isolated_perf.diff',E/'isolated-perf-pending.json']
seal(E,files,['Exact ten-source adaptation preserves live immediate decode/streamStep, preallocation outside collection, all 172432 messages and tracking rows, complete final StreamState and routed positions, and same-generation full message digest.','New semantic-sharing flag is mandatory in analysis/report/finalizer. All prior CRC/table/affine/conversion keys remain; pure expression sharing makes no Float callback or tested-only boundary change.','Numeric/perf parsers and all nine generic helpers remain exact; costs are exclusive self partitions with separately overlapping caller/helper contexts. Rational arguments/dyadic eligibility are not observed by these call profiles.','The source-only sequential preparer retains exact artifact/driver/source checks, CPU0 decode-then-CPR protocol, all-input rehashes, protected prepared helper exception and output refusal. Actual builds/resolved controller still required.','Reviewed cleanup remains exact retained duplicates/bound rebuildables, only after final seals, preserving unique perf, failures and unmatched scratch.'])
