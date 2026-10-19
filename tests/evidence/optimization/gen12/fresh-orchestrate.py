from pathlib import Path
import datetime,hashlib,json,subprocess,sys,time,traceback
p=Path('tests/evidence/optimization/gen12')
sha=lambda f:hashlib.sha256(Path(f).read_bytes()).hexdigest()
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()
EXPECTED_RETENTION = ['fresh-commb-check.log', 'fresh-commb-coverage.json', 'fresh-commb-generate.log', 'fresh-commb-run.json', 'fresh-commb.csv.coverage.csv.gz', 'fresh-commb.csv.gz', 'fresh-execution.json', 'fresh-final-verification.json', 'fresh-message-run.json', 'fresh-message.log', 'fresh-message/commands.log', 'fresh-message/direct-input.txt.gz', 'fresh-message/direct-lean.jsonl.gz', 'fresh-message/direct-mismatches.jsonl.gz', 'fresh-message/direct-oracle.jsonl.gz', 'fresh-message/fresh-commb.csv.gz', 'fresh-message/generated.tsv.gz', 'fresh-message/input.hex.gz', 'fresh-message/lean.jsonl.gz', 'fresh-message/metadata.jsonl.gz', 'fresh-message/mismatches.jsonl.gz', 'fresh-message/oracle.jsonl.gz', 'fresh-message/standard-differences.jsonl.gz', 'fresh-message/summary.json', 'fresh-orchestrate.py', 'fresh-orchestration.log', 'fresh-preflight.json', 'fresh-retained-hashes.py', 'fresh-retention-execution.json', 'fresh-run-campaign.py', 'fresh-seeds.json', 'fresh-verification.log', 'fresh-verify.py']
# This file may be prepared during a diagnostic hold; execution needs a later
# explicit root release, checked integrated build and exact helper identities.
pre=json.loads((p/'fresh-preflight.json').read_text())
assert pre['status']=='passed' and pre['authorized_by']=='/root'
assert pre['seed_record_sha256']==sha(p/'fresh-seeds.json')
for f,h in pre['helpers'].items():assert sha(f)==h,f
build=p/'integration/targeted-build.json'
assert sha(build)==pre['integrated_build_record_sha256']
b=json.loads(build.read_text());assert b['exit_code']==0
assert sha(p/'integration/targeted-build.log')==pre['integrated_build_log_sha256']==b['log_sha256']
for f,h in json.loads((p/'fresh-seeds.json').read_text())['source_sha256'].items():assert sha(f)==h,f
assert not (p/'fresh-execution.json').exists(), 'Refuse to overwrite a campaign.'
assert not (p/'fresh-commb-run.json').exists() and not (p/'fresh-message-run.json').exists()
assert not any((p/'fresh-message').glob('*'))
cache=Path('.cache/gen12-gate')
assert cache.is_dir(), 'Prepared cache directory is required before generation.'
assert not any((cache/name).exists() for name in ['fresh-commb.csv','fresh-commb.csv.coverage.csv']), 'Refuse to overwrite previous fixture artifacts.'
r={'status':'running','started_utc':now(),'started_monotonic_ns':time.monotonic_ns(),'preflight_sha256':sha(p/'fresh-preflight.json'),'seed_record_sha256':sha(p/'fresh-seeds.json'),'orchestrator_sha256':sha(__file__),'commands':[]}
def write():(p/'fresh-execution.json').write_text(json.dumps(r,indent=2)+'\n')
write()
try:
 for helper,log in [('fresh-run-campaign.py','fresh-orchestration.log'),('fresh-verify.py','fresh-verification.log')]:
  item={'command':['python3',str(p/helper)],'helper_sha256':sha(p/helper),'started_utc':now(),'started_monotonic_ns':time.monotonic_ns(),'log':str(p/log)}
  r['commands'].append(item);write()
  with (p/log).open('w') as stream:result=subprocess.run(item['command'],stdout=stream,stderr=subprocess.STDOUT)
  item.update(exit_code=result.returncode,finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),log_sha256=sha(p/log),helper_sha256_after=sha(p/helper));write()
  assert result.returncode==0, (helper,result.returncode)
  assert item['helper_sha256']==item['helper_sha256_after']
 assert sha(p/'fresh-seeds.json')==r['seed_record_sha256']
 r.update(status='primary_verified',verification_sha256=sha(p/'fresh-final-verification.json'));write()
 helper=p/'fresh-retained-hashes.py'
 retained={'command':['python3',str(helper)],'helper_sha256':sha(helper),'started_utc':now(),'started_monotonic_ns':time.monotonic_ns()}
 retention_record=p/'fresh-retention-execution.json'
 retention_record.write_text(json.dumps(retained,indent=2)+'\n')
 result=subprocess.run(retained['command'],capture_output=True,text=True)
 retained.update(finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr,helper_sha256_after=sha(helper))
 retention_record.write_text(json.dumps(retained,indent=2)+'\n')
 assert result.returncode==0, (str(helper),result.returncode)
 assert retained['helper_sha256']==retained['helper_sha256_after']
 manifest_path=p/'fresh-retained-hashes.json';manifest=json.loads(manifest_path.read_text())
 assert manifest['status']=='passed'
 expected={str(p/name) for name in EXPECTED_RETENTION}
 actual={str(f) for f in p.glob('fresh*') if f.is_file() and f.name!='fresh-retained-hashes.json'}|{str(f) for f in (p/'fresh-message').rglob('*') if f.is_file()}
 assert len(expected)==33 and actual==expected==set(manifest['files'])
 # These two execution records are deliberately completed after the retention
 # helper reads them; every other hash must still equal its recorded value.
 mutable_records={str(p/'fresh-execution.json'),str(retention_record)}
 for f,info in manifest['files'].items():
  if f not in mutable_records:assert sha(f)==info['sha256'] and Path(f).stat().st_size==info['bytes'],f
 run=json.loads((p/'fresh-message-run.json').read_text())
 assert len(run['source_sha256_after'])==108 and len(run['binary_sha256_after'])==3
 for group in ['source_sha256','binary_sha256']:
  assert run[group+'_before']==run[group+'_after']
  for f,h in run[group+'_after'].items():assert sha(f)==h,f
 r.update(status='passed',finished_utc=now(),finished_monotonic_ns=time.monotonic_ns(),exit_code=0,retention_execution_sha256=sha(retention_record),retained_manifest_path=str(manifest_path),retained_file_count=33,final_source_hash_count=len(run['source_sha256_after']),final_binary_hash_count=len(run['binary_sha256_after']),final_source_binary_hashes_match=True);write()
 for f in mutable_records:manifest['files'][f]={'sha256':sha(f),'bytes':Path(f).stat().st_size}
 for f,info in manifest['files'].items():assert sha(f)==info['sha256'] and Path(f).stat().st_size==info['bytes'],f
 manifest.update(verified_utc=now(),retention_execution_sha256=sha(retention_record),exact_membership_count=33,final_source_hash_count=len(run['source_sha256_after']),final_binary_hash_count=len(run['binary_sha256_after']),final_source_binary_hashes_match=True)
 manifest_path.write_text(json.dumps(manifest,indent=2)+'\n')
 print(json.dumps(r,indent=2));print('Retained manifest SHA-256:',sha(manifest_path))
except BaseException as error:
 r.update(status='failed',finished_utc=now(),exit_code=1,error=repr(error),traceback=traceback.format_exc());write()
 manifest_path=p/'fresh-retained-hashes.json'
 if manifest_path.exists():
  failed=json.loads(manifest_path.read_text());failed.update(status='failed',orchestration_error=repr(error));manifest_path.write_text(json.dumps(failed,indent=2)+'\n')
 raise
