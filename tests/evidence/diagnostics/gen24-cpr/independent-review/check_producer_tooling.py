import sys
sys.dont_write_bytecode=True
from pathlib import Path
import ast,hashlib,json
from datetime import datetime,timezone
E=Path('tests/evidence/diagnostics/gen24-cpr');sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
p=json.loads((E/'preparation.json').read_text());checks=[]
def check(condition,label):
 assert condition,label
 checks.append(label)
for name,digest in p['helpers'].items():check(sha(name)==digest,'prepared hash '+name)
for name,r in p['prior_controller_bindings'].items():
 before=Path(r['prior_path']);after=Path(r['prepared_path'])
 check(sha(before)==r['prior_sha256'],'prior '+name)
 check(sha(after)==r['prepared_sha256'],'current '+name)
 ast.parse(after.read_text());checks.append('syntax '+name)
for name in ['cleanup_cache.py','extract_remaining_contexts.py','extract_table_contexts.py']:
 check((E/name).read_text()==Path('tests/evidence/diagnostics/gen23-cpr',name).read_text().replace('gen23','gen24'),'path-only '+name)
for name in ['extract_numeric_contexts.py','perf/analyze_cpr_perf.py']:
 check((E/name).read_bytes()==Path('tests/evidence/diagnostics/gen23-cpr',name).read_bytes(),'algorithm unchanged '+name)
for name in ['analyze_and_archive.py','finalize.py','write_report.py']:
 check("assert source" in (E/name).read_text() and "['commb_semantic_reuse_live_path_verified']" in (E/name).read_text(),'new source guard '+name)
check("ROOT / 'docs/GEN24-CPR-COST-BREAKDOWN.md'" in (E/'finalize.py').read_text(),'correct final report')
check("ROOT/'docs/GEN24-CPR-COST-BREAKDOWN.md'" in (E/'write_report.py').read_text(),'correct report writer')
check(sha(E/'preparation.diff')==p['diff']['sha256'],'exact adaptation diff')
result={'status':'passed','kind':'read_only_producer_tooling_cross_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'checks':len(checks),'check_labels':checks,'findings':[],
'bindings':{**p['helpers'],str(E/'preparation.json'):sha(E/'preparation.json'),str(E/'preparation.diff'):sha(E/'preparation.diff'),__file__:sha(__file__)},
'assessment':['Read exact ten-source diff and current archive, report and finalizer logic. Generation/count/pins and source-native sharing requirement retain prior algorithms.','Whole output/state equality, same-generation decode digest, full stages/helper context reconciliation, 104 locks and fresh native input hashes remain required.','New report prose distinguishes shared pure expression construction, preserved register30/44/status behavior and unchanged Float callback boundaries. No inference of hit frequency from inclusive costs.','Saved perf parser and numeric extractor are byte-identical. Sealer updates generation source/binding keys only and rechecks all recorded inputs.','Cleanup is exactly the prior generation-only adaptation: complete retained compressed/raw identities, gzip EOF, durable pre-unlink receipts and strict identity checks; unique raw perf and unmatched files remain protected.','This review executes no producer/controller/native/profile/cleanup job. Independent raw/evidence recount is owned by FC.']}
out=E/'independent-review/producer-tooling-review.json'
with out.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','checks':len(checks),'sha256':sha(out)}))
