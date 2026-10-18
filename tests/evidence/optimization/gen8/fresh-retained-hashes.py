from pathlib import Path
import datetime,gzip,hashlib,json
p=Path('tests/evidence/optimization/gen8');q=p/'fresh-message'
sha=lambda f:hashlib.sha256(Path(f).read_bytes()).hexdigest()
s=json.loads((q/'summary.json').read_text());v=json.loads((p/'fresh-final-verification.json').read_text());e=json.loads((p/'fresh-execution.json').read_text());pre=json.loads((p/'fresh-preflight.json').read_text())
assert v['status']=='passed' and e['status']=='primary_verified' and s['status']=='PASS'
assert e['verification_sha256']==sha(p/'fresh-final-verification.json')
assert sha(p/'fresh-seeds.json')==pre['seed_record_sha256']==e['seed_record_sha256']
for f,h in pre['helpers'].items():assert sha(f)==h
expected={'mismatches.jsonl.gz':s['message']['counts'].get('D001',0),'standard-differences.jsonl.gz':s['message']['counts'].get('standard_view_differences',0),'direct-mismatches.jsonl.gz':0}
streams={}
for name,rows in expected.items():
 f=q/name;digest=hashlib.sha256();size=0;lines=0
 with gzip.open(f,'rb') as source:
  for chunk in iter(lambda:source.read(1<<20),b''):
   digest.update(chunk);size+=len(chunk);lines+=chunk.count(b'\n')
 assert lines==rows,(name,lines,rows)
 streams[str(f)]={'compressed_sha256':sha(f),'decompressed_sha256':digest.hexdigest(),'decompressed_bytes':size,'rows':lines,'expected_rows':rows,'note':'Diagnostic stream CRC/decompression and row cardinality verified; these streams have no original uncompressed digest in the frozen runner summary.'}
files=[f for f in p.glob('fresh*') if f.is_file() and f.name!='fresh-retained-hashes.json']+[f for f in q.rglob('*') if f.is_file()]
record={'status':'passed','verified_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'existing_raw_verification':{'path':str(p/'fresh-final-verification.json'),'sha256':sha(p/'fresh-final-verification.json'),'raw_transcripts':v['retained_raw_artifact_count'],'standalone_snapshots':2},'diagnostic_streams':streams,'helper_source_sha256':sha(__file__),'files':{str(f):{'sha256':sha(f),'bytes':f.stat().st_size} for f in sorted(files)}}
(p/'fresh-retained-hashes.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({k:value for k,value in record.items() if k!='files'},indent=2));print('Retained files:',len(files))
