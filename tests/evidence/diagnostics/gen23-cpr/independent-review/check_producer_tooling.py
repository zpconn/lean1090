import sys
sys.dont_write_bytecode=True
import ast,datetime,hashlib,json,pathlib
R=pathlib.Path.cwd();E=R/'tests/evidence/diagnostics/gen23-cpr';P=R/'tests/evidence/diagnostics/gen22-cpr'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
prep=json.loads((E/'preparation.json').read_text());checks=[];bindings={}
def check(test,name):
 assert test,name
 checks.append(name)
for p,h in prep['helpers'].items():check(sha(R/p)==h,'bound '+p);bindings[p]=h
for n,row in prep['prior_controller_bindings'].items():
 p=R/row['prior_path'];q=R/row['prepared_path'];a=p.read_text();b=q.read_text();ast.parse(b)
 check(sha(p)==row['prior_sha256'] and sha(q)==row['prepared_sha256'],'prior/current/AST '+n)
 if n in ['extract_numeric_contexts.py','perf/analyze_cpr_perf.py']:check(a==b,'unchanged numeric/sample algorithm '+n)
 if n in ['extract_table_contexts.py','extract_remaining_contexts.py','cleanup_cache.py']:check(a.replace('gen22','gen23').replace('GEN22','GEN23')==b,'path-only '+n)
 if n in ['analyze_and_archive.py','finalize.py']:
  expected=a.replace('gen22','gen23').replace('GEN22','GEN23')
  expected=expected.replace("assert source_review['decode_frame_with_word_anchor']","assert source_review['decode_frame_with_word_anchor']\n"+('    ' if n=='finalize.py' else '')+"assert source_review['commb_validity_tables_live_path_verified']")
  check(expected==b,'exact source requirement only '+n)
 if n=='write_report.py':
  check("assert source['commb_validity_tables_live_path_verified']" in b and "docs/GEN23-CPR-COST-BREAKDOWN.md" in b,'current source gate/report destination')
  check('inclusive instruction costs do not establish lookup' in b and 'numerical callback' in b,'validity observability limits')
 if n=='perf/seal_perf.py':
  check(a.replace('gen22','GEN_CURRENT').replace('gen21','gen22').replace('GEN_CURRENT','gen23').replace('Generation 22','Generation 23')==b,'correct saved-perf generation key only')
 if n=='run_prepared.py':check('len(correctness)==200' in b and all('Proofs/CommBValidity'+s+'.lean' in b for s in ['40','50','60']),'complete current proof inventory')
for p in [E/'preparation.json',E/'preparation.diff',pathlib.Path(__file__)]:bindings[str(p.relative_to(R) if p.is_absolute() else p)]=sha(p)
result={'status':'passed','reviewed_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks,'bindings':bindings,'assessments':['Ten scripts retain reviewed methods. New source/native validity-table requirement and accurately limited narrative are the only semantic delta beyond generation/count/guard pins.','Shared algorithms and numeric/perf parsers are byte-identical; actual raw/helper and complete output/state checks remain intact.','Cleanup is exactly prior path-only adaptation, retaining exact decompressed counterparts, durable records, strict identities and unique perf preservation.','No native table-hit frequency, initialization population or speedup is inferred from inclusive costs.'],'authorship':'Independent current producer-delta review; no current CPR runtime, analyzer or accounting authorship.','limits':['Read-only source/hash/AST check; no producer import/execution, build, collection or cleanup. FC independently recounts raw/current evidence.']}
out=E/'independent-review/producer-tooling-review.json'
with out.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','checks':len(checks),'sha256':sha(out)}))
