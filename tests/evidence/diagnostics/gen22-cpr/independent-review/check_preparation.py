#!/usr/bin/env python3
"""Read source only: no controller imports, workloads, build or profile."""
import sys
sys.dont_write_bytecode=True
import ast,difflib,hashlib,json,subprocess
from datetime import datetime,timezone
from pathlib import Path
R=Path(__file__).resolve().parents[5];E=R/'tests/evidence/diagnostics/gen22-cpr';O=E/'independent-review/preparation-review.json'
assert not O.exists()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
p=load(E/'preparation.json');checks=[]
def require(ok,msg):
 assert ok,msg
 checks.append(msg)
require(sha(E/'preparation.json')=='d7dcbc32491dab5b2c0fc6022a9bc631e3a23c489c0e974e57babd78cd375678','exact preparation hash')
require(p['status']=='prepared_not_executed' and p['benchmark_bindings']['artifact_commit'] is None,'future artifact unresolved')
require(p['expected_correctness_inputs']==197 and p['expected_prior_csv_rows']==46,'correct input/CSV counts')
all_diff=''
for name,row in p['prior_controller_bindings'].items():
 old=R/row['prior_path'];new=R/row['prepared_path']
 require(sha(old)==row['prior_sha256'] and sha(new)==row['prepared_sha256'],'prior/current hash '+name)
 actual=new.read_text();ast.parse(actual)
 all_diff+=''.join(difflib.unified_diff(old.read_text().splitlines(True),actual.splitlines(True),fromfile=row['prior_path'],tofile=row['prepared_path']))
 expected=old.read_text().replace('gen21','gen22').replace('GEN21','GEN22').replace('Generation 21','Generation 22')
 if name=='run_prepared.py':
  expected=expected.replace("summary['generation']==21","summary['generation']==22").replace('len(correctness)==195','len(correctness)==197')
  expected=expected.replace("'Proofs/ParityByte.lean'}","'Proofs/ParityByte.lean','Proofs/FrameWord.lean','Proofs/RawSyndromeSpec.lean'}")
  expected=expected.replace(" assert summary['generation']==22\n", " assert summary['generation']==22\n assert summary['commit']==plan['benchmark_bindings']['timed_commit']\n assert summary['binary_sha256']==plan['benchmark_bindings']['worker_sha256']\n assert sha(B/'summary.json')==plan['benchmark_bindings']['summary_sha256']\n assert sha(B/'results-review.json')==plan['benchmark_bindings']['result_review_sha256']\n")
 elif name=='analyze_and_archive.py':
  expected=expected.replace("assert source_review['worker_sha256'] == collection['worker_sha256']\n", "assert source_review['worker_sha256'] == collection['worker_sha256']\nassert source_review['raw_word_syndrome_live_path_verified']\nassert source_review['decode_frame_with_word_anchor']\n")
 elif name=='finalize.py':
  expected=expected.replace("    assert source_review['status'] == 'passed_read_only_source_and_native_review'\n", "    assert source_review['status'] == 'passed_read_only_source_and_native_review'\n    assert source_review['raw_word_syndrome_live_path_verified']\n    assert source_review['decode_frame_with_word_anchor']\n")
 elif name=='write_report.py':
  expected=expected.replace("source = load(B/'independent-review/source-review.json')\n", "source = load(B/'independent-review/source-review.json')\nassert source['raw_word_syndrome_live_path_verified']\nassert source['decode_frame_with_word_anchor']\n")
  paragraph="""
The current decoder calls the paired parser `{source['decode_frame_with_word_anchor']}`
and reuses its returned wire word for CRC. The independent current native
review verifies that live path and the byte/general-bit fallback loops. The
committed decoder subpartition recognizes this parser as frame/CRC; the full
CPR partition and numeric extraction are unchanged. Absent standalone parser,
frame-syndrome or packing entries are not interpreted as absent inlined work.
"""
  expected=expected.replace('frozen files or build configuration changed during diagnosis.\n','frozen files or build configuration changed during diagnosis.\n'+paragraph)
  expected=expected.replace('attribution algorithm is used unchanged. [Complete compressed analysis]', 'CPR attribution algorithm is used unchanged, with the current paired-parser\nclassification in the decoder subpartition. [Complete compressed analysis]')
 elif name=='perf/seal_perf.py':
  expected=expected.replace('gen20-cpr/perf/analyze_cpr_perf.py','gen21-cpr/perf/analyze_cpr_perf.py')
 require(actual==expected,'exact permitted source adaptation '+name)
require((E/'preparation.diff').read_text()==all_diff and sha(E/'preparation.diff')==p['diff']['sha256'],'complete exact ten-file diff')
prior=load(R/'tests/evidence/diagnostics/gen21-cpr/preparation.json')
for name,digest in p['helpers'].items():
 require(sha(R/name)==digest,'helper binding '+name)
 if name.startswith('review/'):
  require(hashlib.sha256(subprocess.check_output(['git','cat-file','blob',p['benchmark_bindings']['timed_commit']+':'+name],cwd=R)).hexdigest()==digest,'committed generic helper '+name)
  if name!='review/diagnostics/analyze_callgrind.py':
   require(prior['helpers'][name]==digest,'unchanged shared helper '+name)
for key in ['prior_successful_build','prior_final_review','diagnostic_tooling_validation']:
 item=p[key];require(sha(R/item['path'])==item['sha256'],'prior/current receipt '+key)
b=p['benchmark_bindings'];summary=load(R/'bench/runs/gen22/summary.json')
require(sha(R/'bench/runs/gen22/summary.json')==b['summary_sha256'] and sha(R/'bench/runs/gen22/results-review.json')==b['result_review_sha256'],'benchmark receipt hashes')
require(summary['commit']==b['timed_commit'] and summary['binary_sha256']==b['worker_sha256'],'actual measured source and worker')
require(load(R/'tests/evidence/diagnostics/gen22/independent-review/preparation-review.json')['status']=='passed_read_only_preparation_review','decode guard independently reviewed')
inputs=load(R/'bench/runs/gen22/correctness-inputs.json');require(len(inputs)==197 and all(sha(R/k)==v for k,v in inputs.items()),'all 197 current correctness inputs unchanged')
files=[E/'preparation.json',E/'preparation.diff',Path(__file__),R/'tests/evidence/diagnostics/gen22/independent-review/preparation-review.json']+[R/n for n in p['helpers']]
record={'status':'passed_read_only_preparation_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks,'bindings':{str(x.relative_to(R)):sha(x) for x in files},'assessments':['Ten current controllers are exact generation/path adaptations plus the explicitly checked input/pin guards, paired-parser flag requirements and accurate report explanation.','Unchanged live immediate decode/streamStep driver, all outputs/state audits, preallocation/initial-state boundary, native validation before collection and sequential actual-worker perf guards retained.','The updated committed decoder stage classifier is separately fixture-bound; shared CPR exclusive accounting, numeric/table/fallback extraction and EOF/hash archive/cleanup checks remain unchanged.','Current linked source/native review remains mandatory. No speculative observed entries, branch hits, cost shares, future artifact commit or performance claim accepted.','Original corrected gen21 saved-sample sealer is the adaptation baseline; exact gen22 fresh-binding dictionary key and current report destinations checked.','Cleanup remains post-review/authorization only, bounded to exact archived duplicates and bound rebuildables, with unique raw perf protected.'],'controller_import_build_execution_profile_history_snapshot_or_cleanup_performed':False,'scope':'Preparation source validation only; actual build/current native review, full output/state, raw accounting, sampling and complete archives require later evidence.'}
O.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':record['status'],'checks':len(checks),'sha256':sha(O)},indent=2))
