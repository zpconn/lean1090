import os, sys
sys.dont_write_bytecode = True
os.environ["PYTHONDONTWRITEBYTECODE"] = "1"
from pathlib import Path
import json,gzip,hashlib,datetime
P=Path('tests/evidence/optimization/gen19'); Q=P/'fresh-message'
load=lambda p:json.loads(Path(p).read_text())
def digest(path):
 h=hashlib.sha256()
 with Path(path).open('rb') as source:
  for block in iter(lambda:source.read(1<<20),b''):h.update(block)
 return h.hexdigest()
def unpacked_digest(path):
 h=hashlib.sha256();n=0
 with gzip.open(path,'rb') as source:
  for block in iter(lambda:source.read(1<<20),b''):h.update(block);n+=len(block)
 return h.hexdigest(),n
run=load(P/'fresh-message-run.json');s=load(Q/'summary.json');seeds=load(P/'fresh-seeds.json');commb=load(P/'fresh-commb-run.json');coverage=load(P/'fresh-commb-coverage.json')
assert run['status']=='passed' and run['exit_code']==0 and s['status']=='PASS'
assert run['seed_record_sha256']==digest(P/'fresh-seeds.json')
assert s['seed']==seeds['message_seed'] and s['generated_messages']==10000000
assert coverage['seed']==seeds['commb_seed'] and coverage['random_assignments']==100000 and coverage['total_rows']==101244
for key in ('source_sha256','binary_sha256'):
 assert run[key+'_before']==run[key+'_after']
 for p,h in run[key+'_before'].items():assert digest(p)==h,p
assert len(run['source_sha256_before'])==117 and len(run['binary_sha256_before'])==3
assert commb['source_sha256']==commb['source_sha256_after']
assert commb['binary_sha256_before']==commb['binary_sha256_after']
for p,h in s['source_sha256'].items():assert digest(p)==h,p
assert not s['message']['coverage_errors']
assert len(s['message']['df'])==32 and len(s['message']['adsb'])==70 and len(s['message']['commb'])==14
counts=s['message']['counts'];direct=s['direct_registers']['counts']
assert counts['messages']==10476164==counts['exact_matches']+counts.get('D001',0)
assert not counts.get('unclassified',0) and not counts.get('fixture_candidate_mismatches',0)
assert direct=={'cases':101244,'exact_matches':101244}
verified={}
for name,info in s['artifacts'].items():
 p=Q/(name+'.gz');h,n=unpacked_digest(p)
 assert digest(p)==info['compressed_sha256'] and h==info['sha256'] and n==info['bytes'],name
 verified[str(p)]={'compressed_sha256':digest(p),'uncompressed_sha256':h,'uncompressed_bytes':n}
for raw,info in commb['artifacts'].items():
 p=Path(info['retained']);h,n=unpacked_digest(p)
 assert digest(p)==info['compressed_sha256'] and h==info['sha256'] and n==info['bytes'],str(p)
 assert digest(raw)==h
 verified[str(p)]={'compressed_sha256':digest(p),'uncompressed_sha256':h,'uncompressed_bytes':n}
with gzip.open(Q/'direct-mismatches.jsonl.gz','rb') as f:assert f.read(1)==b''
result={'status':'passed','exit_code':run['exit_code'],'verified_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'started_utc':run['started_utc'],'finished_utc':run['finished_utc'],'message_seed':seeds['message_seed'],'commb_seed':seeds['commb_seed'],'message_counts':counts,'direct_counts':direct,'df_attempts':len(s['message']['df']),'adsb_branches':len(s['message']['adsb']),'commb_registers':len(s['message']['commb']),'coverage_errors':s['message']['coverage_errors'],'sources_unchanged':True,'binaries_unchanged':True,'source_hash_count':len(run['source_sha256_before']),'binary_hash_count':len(run['binary_sha256_before']),'retained_raw_artifact_count':len(s['artifacts']),'retained_compressed_and_uncompressed_hashes_verified':True,'standalone_commb_gzip_snapshots_verified':True,'direct_mismatch_stream_empty':True,'summary_sha256':digest(Q/'summary.json'),'run_record_sha256':digest(P/'fresh-message-run.json'),'verifier_sha256':digest(__file__),'verified_artifacts':verified,'note':'Every difference is retained; only exact documented D001 whole-message exceptions occur. Standard/oracle view differences are separate observations, not oracle compatibility exemptions.'}
(P/'fresh-final-verification.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:v for k,v in result.items() if k!='verified_artifacts'},indent=2))
