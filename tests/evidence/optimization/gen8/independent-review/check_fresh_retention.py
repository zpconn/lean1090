#!/usr/bin/env python3
"""Read-only freshness and retained-failure binding before full gate completion."""
from pathlib import Path
from datetime import datetime,timezone
import json,hashlib
B=Path('tests/evidence/optimization/gen8');R=B/'independent-review'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for chunk in iter(lambda:f.read(4*1024*1024),b''):h.update(chunk)
 return h.hexdigest()
def load(p):return json.loads(Path(p).read_text())
expected=load(R/'final-bindings.json')
for f,key in [('fresh-final-verification.json','fresh_final_verification_sha256'),('fresh-message/summary.json','fresh_summary_sha256'),('fresh-retained-hashes.json','fresh_retention_sha256'),('attempt-01-failed-fresh/attempt-02-completion.json','fresh_retry_completion_sha256')]:assert sha(B/f)==expected[key]
retention=load(B/'fresh-retained-hashes.json');execution=load(B/'fresh-execution.json');run=load(B/'fresh-message-run.json')
assert retention['status']==execution['status']==run['status']=='passed'
assert execution['exit_code']==run['exit_code']==0
actual={str(p) for p in B.glob('fresh*') if p.is_file() and p.name!='fresh-retained-hashes.json'}|{str(p) for p in (B/'fresh-message').rglob('*') if p.is_file()}
assert actual==set(retention['files']) and len(actual)==33
for f,row in retention['files'].items():assert sha(f)==row['sha256'] and Path(f).stat().st_size==row['bytes'],f
for kind,count in [('source_sha256',104),('binary_sha256',3)]:
 assert run[kind+'_before']==run[kind+'_after'] and len(run[kind+'_after'])==count
 for f,d in run[kind+'_after'].items():assert sha(f)==d,f
A=B/'attempt-01-failed-fresh';completion=load(A/'attempt-02-completion.json');recovery=load(A/'recovery.json')
assert completion['status']=='passed' and completion['second_attempt_exit_code']==0
assert len(completion['first_attempt_archive_files'])==12
assert {str(p) for p in A.rglob('*') if p.is_file()}==set(completion['first_attempt_archive_files'])|{str(A/'attempt-02-completion.json')}
for f,row in completion['first_attempt_archive_files'].items():assert sha(f)==row['sha256'] and Path(f).stat().st_size==row['bytes'],f
for f,d in completion['success_artifacts'].items():assert sha(f)==d,f
for f,row in recovery['context_copies'].items():assert sha(f)==sha(row['archive'])==row['sha256'],f
failed=load(A/'fresh-commb-run.json')
assert failed['source_sha256']==run['source_sha256_before'] and failed['binary_sha256_before']==run['binary_sha256_before']
assert failed['commands'][0]['argv']==load(B/'fresh-commb-run.json')['commands'][0]['argv']
summary=load(B/'fresh-message/summary.json')
assert summary['message']['counts']==completion['message_counts']
assert summary['message']['counts']['messages']==10476164
assert summary['message']['counts']['exact_matches']==9542821
assert summary['message']['counts']['D001']==933343
assert summary['direct_registers']['counts']=={'cases':101244,'exact_matches':101244}
out={'status':'passed_fresh_retention_and_retry_binding','reviewed_utc':datetime.now(timezone.utc).isoformat(),'successful_retained_members':33,'failed_attempt_retained_members':13,'unchanged_source_hashes':104,'unchanged_binary_hashes':3,'counts':summary['message']['counts'],'retention_sha256':sha(B/'fresh-retained-hashes.json'),'retry_completion_sha256':sha(A/'attempt-02-completion.json'),'script_sha256':sha(__file__),'findings':[],'limits':'Hash/membership/record binding only. The completed raw verifier retains decompression results; this early check does not repeat decompression or run a decoder. Full fixed gate/archive review remains pending.'}
p=R/'fresh-retention-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'members':33,'failure_members':13},indent=2))
