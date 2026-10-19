import sys
sys.dont_write_bytecode=True
from pathlib import Path
import hashlib,json
P=Path('tests/evidence/optimization/gen18/fresh')
def sha(p):
 with p.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
r=json.loads((P/'fresh-execution.json').read_text());m=json.loads((P/'fresh-retained-hashes.json').read_text());v=json.loads((P/'fresh-final-verification.json').read_text());assert r['status']==m['status']==v['status']=='passed'
for n,x in m['files'].items():assert sha(n)==x['sha256'] and Path(n).stat().st_size==x['bytes']
assert len(m['files'])==33
print(json.dumps({'status':'passed','execution_sha256':sha(P/'fresh-execution.json'),'retention_sha256':sha(P/'fresh-retained-hashes.json'),'verification_sha256':sha(P/'fresh-final-verification.json'),'summary_sha256':sha(P/'fresh-message/summary.json'),'counts':v['message_counts'],'direct':v['direct_counts'],'sources':v['source_hash_count'],'binaries':v['binary_hash_count'],'coverage':[v['df_attempts'],v['adsb_branches'],v['commb_registers']]}))
