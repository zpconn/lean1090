import sys
sys.dont_write_bytecode=True
from pathlib import Path
import ast,hashlib,json
from datetime import datetime,timezone
E=Path('tests/evidence/diagnostics/gen23');sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();load=lambda p:json.loads(p.read_text());checks=[]
def check(label,value):
 assert value,label
 checks.append(label)
t=load(E/'producer-tooling.json');p=load(E/'producer-preparation.json')
check('tooling preparation binding',t['preparation_sha256']==sha(E/'producer-preparation.json'))
check('exact declared 12 producer files',len(t['files'])==len(p['files'])==12 and set(t['files'])==set(p['files']))
check('retained exact adaptation diff',p['diff_sha256']==sha(E/'producer-preparation.diff'))
for name,r in p['files'].items():
 path=Path(name);old=Path(r['from'])
 check(name+' current hash',sha(path)==r['sha256']==t['files'][name])
 check(name+' prior retained source hash',sha(old)==r['prior_sha256'])
 ast.parse(path.read_text(),filename=name);checks.append(name+' AST syntax')
old=Path('tests/evidence/diagnostics/gen22/cleanup_cache.py').read_text()
check('cleanup exact generation-only adaptation',old.replace('gen22','gen23')==(E/'cleanup_cache.py').read_text())
f=(E/'finalize.py').read_text();priority=(E/'extract_priority_contexts.py').read_text();pack=(E/'extract_pack_fields.py').read_text()
for marker in ["assert source['commb_validity_tables_live_path_verified']","assert source['pack_fields_fold_anchor'] is None","--previous-generation', '22'","'--generation', '23'","'build-controller.stdout', 'build-controller.stderr'"]:
 check('finalizer '+marker,marker in f)
check('removed only absent outer build wrappers',"'build-start.json'" not in f and "'build-execution.json'" not in f and all((E/n).exists() for n in ['driver-build-command.json','source-binding-command.json','build-controller.stdout','build-controller.stderr']))
for marker in ['Semantics_commBStandardFloats','oracleCommBFloats','commBValue','findPayloadField','cbSelectedValid40','cbQNHValid40','cbRollValid50','cbMachValid60','cbVerticalValid60']:
 check('current callable/inlined boundary selector '+marker,marker in priority and marker in f)
for marker in ['diagnostics/gen21/independent-review/source-review.json','for generation in (22,23)',"assert counts['entry_calls']==0","assert total['entry_calls']==0","'historical_anchor_source_sha256':sha(HISTORICAL_ANCHOR)"]:
 check('packing retained historical anchor/zero current entries '+marker,marker in pack)
perf=(E/'perf/analyze_perf_gen23.py').read_text()
check('restored intended top20 display before execution','allleaf.most_common(20)' in perf and 'allleaf.most_common(21)' not in perf)
check('per-sample/count classification unchanged from gen22',perf[:perf.index('summary=')].replace('gen23','gen22')==Path('tests/evidence/diagnostics/gen22/perf/analyze_perf_gen22.py').read_text().split('summary=',1)[0])
check('parser/partition shared source remains preparation-bound',sha(Path('review/diagnostics/analyze_callgrind.py'))==load(E/'preparation.json')['generic_helpers']['review/diagnostics/analyze_callgrind.py'])
record={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'reviewer':'payload_roundtrips; independent of decode producer authorship','checks_passed':len(checks),'checks':checks,'findings':[],'producer_tooling_sha256':sha(E/'producer-tooling.json'),'producer_preparation_sha256':sha(E/'producer-preparation.json'),'files':t['files'],'scope':'Read-only source/hash/AST/diff review; no producer import, raw parser rerun, native execution or cleanup. FC independently recounts final raw evidence.','retained_reviewer_attempts':[{'attempt':1,'status':'failed','path':'producer-tooling-attempt01/execution.json'},{'attempt':2,'status':'passed'}],'assessment':['All 12 current/prior source hashes and complete exact diff reviewed. Existing all-profile/full-output/census/exclusive-stage reconciliation remains; generation pairs advance 22/23 without changing field-code constants.','Five validity helpers and semantic/oracle construction helpers are extra observed boundaries/direct-child selectors only. Source flag gates reporting; absent inline boundaries are not zero work or a hit-rate estimate. Inclusive rows remain overlapping.','Both raw-word generations have zero observed generic packing entries; the historical gen21 callable name and generated-C excerpts remain explicitly bound, not fabricated from current absent symbols.','Archive uses actual build command records and outer completed logs; absent gen22-specific build-start/execution wrappers are omitted rather than invented.','Saved perf top20 display restored to20 before first execution; complete per-sample classification and totals unchanged. Prior gen22 display21 evidence remains untouched.','Cleanup is byte-identical after generation path substitution: requires final independent seal and exact durable retained counterparts, bounded own-cache paths, raw perf protection and identity checks.']}
out=E/'independent-review/producer-tooling-review.json'
with out.open('x') as f:json.dump(record,f,indent=2);f.write('\n')
print(json.dumps({'status':'passed','checks':len(checks),'sha256':sha(out)}))
