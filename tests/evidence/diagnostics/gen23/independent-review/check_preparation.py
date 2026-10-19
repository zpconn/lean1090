#!/usr/bin/env python3
"""Read-only review of prepared controllers; never import or execute them."""
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
def exact_diff(old,new):
 return ''.join(difflib.unified_diff(old.read_text().splitlines(True),new.read_text().splitlines(True),fromfile=str(old.relative_to(R)),tofile=str(new.relative_to(R))))
def seal(e,files,assessments):
 out=e/'independent-review/preparation-review.json';assert not out.exists()
 record={'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks[:],'bindings':{str(p.relative_to(R)):sha(p) for p in files+[Path(__file__)]},'assessments':assessments,'controller_import_execution_build_profile_history_snapshot_or_cleanup_performed':False,'scope':'Source preparation only; actual published artifact, builds, current source/native anchors, full output/state/raw accounting and final archives remain required.'}
 out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'path':str(out.relative_to(R)),'checks':len(checks),'sha256':sha(out)}))
E=R/'tests/evidence/diagnostics/gen23';P=R/'tests/evidence/diagnostics/gen22';p=load(E/'preparation.json');oldp=load(P/'preparation.json')
req(sha(E/'preparation.json')=='4b26823acc413a5fd795a65d91e6de59c416ad9e9a73b5ab883be7b5f7659a9f','exact decode preparation')
req(p['status']=='prepared_not_executed' and p['artifact_commit'] is None,'decode artifact unresolved')
req(p['expected_correctness_input_count']==200 and p['expected_prior_csv_rows']==48,'decode current counts')
files=[E/'preparation.json',E/'preparation.diff'];diff=''
for name,row in p['files'].items():
 n=R/name;o=R/row['adapted_from'];req(sha(n)==row['sha256'] and sha(o)==row['prior_sha256'],'decode source identities '+name)
 ast.parse(n.read_text());diff+=exact_diff(o,n);files += [n,o]
req(diff==(E/'preparation.diff').read_text() and sha(E/'preparation.diff')==p['diff_sha256'],'exact decode retained diff')
req((E/'snapshot_history.py').read_text()==(P/'snapshot_history.py').read_text().replace('gen22','gen23').replace('GEN22','GEN23'),'history exact paths only')
expected=(P/'run_prepared.py').read_text().replace('gen22','gen23').replace('== 22','== 23').replace('len(correctness) == 197','len(correctness) == 200')
expected=expected.replace("'Proofs/RawSyndromeSpec.lean'}", "'Proofs/RawSyndromeSpec.lean',\n            'Proofs/CommBValidity40.lean', 'Proofs/CommBValidity50.lean',\n            'Proofs/CommBValidity60.lean'}")
req(expected==(E/'run_prepared.py').read_text(),'decode exact generation/input/three-proof adaptation')
req(p['generic_helpers']==oldp['generic_helpers'] and len(p['generic_helpers'])==9,'nine generic helpers unchanged')
for name,digest in p['generic_helpers'].items():
 req(sha(R/name)==digest,'decode shared helper '+name);files.append(R/name)
for name,digest in p['updated_committed_helpers'].items():
 req(hashlib.sha256(subprocess.check_output(['git','cat-file','blob',p['timed_commit']+':'+name],cwd=R)).hexdigest()==digest,'committed shared helper '+name)
summary=load(R/'bench/runs/gen23/summary.json');review=load(R/'bench/runs/gen23/results-review.json')
req(summary['commit']==p['timed_commit'] and summary['binary_sha256']==p['worker_sha256'],'decode measured source/worker')
for key,name in [('benchmark_summary_sha256','summary.json'),('benchmark_result_review_sha256','results-review.json')]:
 q=R/'bench/runs/gen23'/name;req(sha(q)==p[key],'decode measured '+name);files.append(q)
req(review['status']=='passed' and not review['findings'],'measured review passed')
v=p['diagnostic_tooling_validation'];req(sha(R/v['path'])==v['sha256'] and v==oldp['diagnostic_tooling_validation'],'retained prior diagnostic tooling receipt');files.append(R/v['path'])
inputs=load(R/'bench/runs/gen23/correctness-inputs.json');req(len(inputs)==200 and all(sha(R/k)==v for k,v in inputs.items()),'all 200 correctness inputs unchanged')
seal(E,files,['All measured/source/native/lock/six-clean-check guards, 13 profiles, complete per-DF/scored-register census and output digests remain unchanged.','Build only replaces diagnostic driver; explicit artifact must equal descendant HEAD. Campaign requires both isolated worker captures and compact history.','Fresh source/native review must verify current Bool validity tables, parsed raw-word CRC, exact arithmetic and fallback paths; no assumed table-hit or initialization counts.'])
checks.clear()
E=R/'tests/evidence/diagnostics/gen23-cpr';P=R/'tests/evidence/diagnostics/gen22-cpr';p=load(E/'preparation.json');oldp=load(P/'preparation.json')
req(sha(E/'preparation.json')=='b9dea34e71578cfd4e9793615823404c97811f076550d46a11f1a9a5803c1aec','exact CPR preparation')
req(p['status']=='prepared_not_executed' and p['benchmark_bindings']['artifact_commit'] is None,'CPR artifact unresolved')
req(p['expected_correctness_inputs']==200 and p['expected_prior_csv_rows']==48,'CPR current counts')
files=[E/'preparation.json',E/'preparation.diff'];diff=''
for name,row in p['prior_controller_bindings'].items():
 o=R/row['prior_path'];n=R/row['prepared_path'];req(sha(o)==row['prior_sha256'] and sha(n)==row['prepared_sha256'],'CPR source identities '+name)
 actual=n.read_text();ast.parse(actual);diff+=exact_diff(o,n);files += [o,n]
 expected=o.read_text().replace('gen22','gen23').replace('GEN22','GEN23').replace('Generation 22','Generation 23')
 if name=='run_prepared.py':
  expected=expected.replace("summary['generation']==22","summary['generation']==23").replace('len(correctness)==197','len(correctness)==200')
  expected=expected.replace("'Proofs/RawSyndromeSpec.lean'}","'Proofs/RawSyndromeSpec.lean','Proofs/CommBValidity40.lean','Proofs/CommBValidity50.lean','Proofs/CommBValidity60.lean'}")
 elif name in ('analyze_and_archive.py','finalize.py'):
  indent='    ' if name=='finalize.py' else ''
  needle=indent+"assert source_review['decode_frame_with_word_anchor']\n"
  expected=expected.replace(needle,needle+indent+"assert source_review['commb_validity_tables_live_path_verified']\n")
 elif name=='write_report.py':
  needle="assert source['decode_frame_with_word_anchor']\n";expected=expected.replace(needle,needle+"assert source['commb_validity_tables_live_path_verified']\n")
  paragraph="\nThe current source/native review also verifies the immutable Bool field-code\ntables used by BDS40, BDS50 and BDS60 validity checks, including the live lookup\nand initialization paths. Their actual descendants remain in the same complete\ncaller-context accounting; inclusive instruction costs do not establish lookup\nhit rates or separate initialization populations. The numerical callback\nboundary and its tested-only operations remain unchanged.\n"
  expected=expected.replace('frame-syndrome or packing entries are not interpreted as absent inlined work.\n','frame-syndrome or packing entries are not interpreted as absent inlined work.\n'+paragraph)
 elif name=='perf/seal_perf.py':
  expected=expected.replace('gen21-cpr/perf/analyze_cpr_perf.py','gen22-cpr/perf/analyze_cpr_perf.py')
 req(actual==expected,'exact CPR permitted adaptation '+name)
req(diff==(E/'preparation.diff').read_text() and sha(E/'preparation.diff')==p['diff']['sha256'],'exact full CPR ten-file diff')
req(len(p['prior_controller_bindings'])==10,'ten CPR local sources')
for name,digest in p['helpers'].items():
 req(sha(R/name)==digest,'CPR helper '+name);files.append(R/name)
 if name.startswith('review/'):
  req(oldp['helpers'][name]==digest,'unchanged CPR shared helper '+name)
  req(hashlib.sha256(subprocess.check_output(['git','cat-file','blob',p['benchmark_bindings']['timed_commit']+':'+name],cwd=R)).hexdigest()==digest,'committed CPR helper '+name)
for key in ['prior_successful_build','prior_final_review','diagnostic_tooling_validation']:
 item=p[key];req(sha(R/item['path'])==item['sha256'],'CPR retained '+key);files.append(R/item['path'])
b=p['benchmark_bindings'];req(b['timed_commit']==summary['commit'] and b['worker_sha256']==summary['binary_sha256'],'CPR measured identities')
req(sha(R/'bench/runs/gen23/summary.json')==b['summary_sha256'] and sha(R/'bench/runs/gen23/results-review.json')==b['result_review_sha256'],'CPR measured receipt hashes')
q=R/'tests/evidence/diagnostics/gen23/independent-review/preparation-review.json';req(load(q)['status']=='passed_read_only_preparation_review','decode guard independently reviewed');files.append(q)
req(len(inputs)==200 and all(sha(R/k)==v for k,v in inputs.items()),'200 current correctness inputs unchanged after both source reviews')
# Isolated-controller preparer is inspected as source only; concrete outputs remain absent.
ip=load(E/'isolated-perf-pending.json');prep=E/'prepare_isolated_perf.py';ast.parse(prep.read_text())
req(sha(prep)==ip['preparer_sha256']=='166db43c56b1196fad34df9f4aee2c658516b889f8042f64837d3f78f8dc718e','isolated preparer exact read source')
req(sha(E/'prepare_isolated_perf.diff')==ip['preparer_diff_sha256'] and exact_diff(P/'prepare_isolated_perf.py',prep)==(E/'prepare_isolated_perf.diff').read_text(),'isolated preparer exact retained delta')
for key in ['prior_controller','prior_bindings']:
 req(sha(R/ip[key])==ip[key+'_sha256'],'isolated '+key);files.append(R/ip[key])
req(all(ip[k] is None for k in ['artifact_commit','source_binding_sha256','driver_build_hashes']) and ip['correctness_inputs']==200 and ip['cpr_preparation_sha256']==sha(E/'preparation.json'),'isolated unresolved hashes and actual preparation')
req(not (E/'run_isolated_perf.py').exists() and not ip['capture_started'] and not ip['build_started'],'isolated controller not yet generated or run')
files += [prep,E/'prepare_isolated_perf.diff',E/'isolated-perf-pending.json']
seal(E,files,['Exact ten-source delta retains immediate live decode/streamStep, initial allocation outside root, all message consumption, tracking rows, complete final StreamState and routed audit.','The unchanged shared accounting keeps exclusive stages separate from inclusive numeric/table/fallback contexts. Current Bool-table verification is newly mandatory; no work moves into tested-only callbacks.','Cleanup remains exact archived duplicates and bound rebuildables only after final reviews; unique raw perf, unmatched scratch and failures remain protected.','Isolated-perf preparer inspected fully: root-supplied descendant artifact, completed source/driver/200-input hashes required; only fixed generation/count/identity substitutions and prepared helper hashes enter the prior controller. Sequential protocol and strict overwrite guards remain; generated concrete script still requires actual binding review.'])
