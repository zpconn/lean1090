#!/usr/bin/env python3
"""Read-only gen8 universal affine proof review; consumes completed owner evidence."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib, json, re, subprocess
B=Path('tests/evidence/optimization/gen8'); R=B/'independent-review'
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p): return json.loads(Path(p).read_text())
def old(p): return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
summary=load(B/'proof/summary.json')
assert summary['status']=='passed'
expected=summary['source_sha256']
assert expected=={'Impl/PayloadBits.lean':'e37853173fc238d6b379be89bc5606c33088f7fdf25e3e8be8103efa9f8bb8cb','Proofs/AffineValue.lean':'c40af9b160755314d417d2d88a9038163cc80aaf38798f13fb6da6e2ad3debc5'}
assert summary['successful_attempt']==2
assert set(expected)=={'Impl/PayloadBits.lean','Proofs/AffineValue.lean'}
for path,digest in expected.items(): assert sha(path)==digest,path
runtime=Path('Impl/PayloadBits.lean').read_text(); proof=Path('Proofs/AffineValue.lean').read_text()
prior=old('Impl/PayloadBits.lean')
start=runtime.index('/-- Exact affine interpretation')
end=runtime.index('-- Initial algorithm: Spec/PayloadBits.lean:46.')
assert runtime[:start]==prior[:prior.index('-- Initial algorithm: Spec/PayloadBits.lean:46.')]
helper=runtime[start:end]
assert '@[inline] def affineValue (value : Int) (scale offset : Rat) : Rat :=' in helper
assert 'let scaled := if scale == 1 then (value : Rat) else (value : Rat) * scale' in helper
assert 'if offset == 0 then scaled else scaled + offset' in helper
previous_body='''else some ((payloadInteger column.coding column.width
    (payloadBits word column.start column.width) : Rat) * column.scale + column.offset)'''
new_body='''else some (affineValue (payloadInteger column.coding column.width
    (payloadBits word column.start column.width)) column.scale column.offset)'''
assert prior.count(previous_body)==1
assert runtime[:start]+runtime[end:]==prior.replace(previous_body,new_body)
assert re.findall(r'^import (.+)$',runtime,re.M)==['Model.Types']
assert re.findall(r'^import (.+)$',proof,re.M)==['Proofs.PayloadBits']
statements={}
for name in ['affineValue_eq','payloadValue_eq_old','payloadValue_eq']:
 a=proof.index('theorem '+name+' ');z=proof.index(' := by',a);statements[name]=proof[a:z]
assert statements['affineValue_eq']=='''theorem affineValue_eq (value : Int) (scale offset : Rat) :
    Impl.affineValue value scale offset = (value : Rat) * scale + offset'''
assert statements['payloadValue_eq']=='''theorem payloadValue_eq (column : Spec.PayloadColumn) (word : Nat) :
    Impl.payloadValue column word = Spec.payloadValue column word'''
assert 'by_cases unit : scale = 1 <;> by_cases zero : offset = 0' in proof
assert 'simp [Impl.affineValue, unit, zero, Rat.mul_one, Rat.add_zero]' in proof
assert 'simp only [Impl.payloadValue, affineValue_eq]' in proof
assert 'PayloadBits.payloadBits_eq' in proof
for path in expected:
 code=re.sub(r'/\-.*?\-/','',Path(path).read_text(),flags=re.S)
 code=re.sub(r'--[^\n]*','',code)
 assert not re.search(r'\b(sorry|admit|native_decide|unsafe|partial)\b|\b(panic|get|unreachable)!|@\[(implemented_by|extern)',code),path
 assert not re.search(r'^\s*axiom\s',code,re.M)
log=Path(summary['successful_log']);text=log.read_text()
assert sha(log)==summary['successful_log_sha256']=='93b253f1b889b086c79ab4e0eb0ae32f4be632b319b2f33fc4ea5a22b49ec077'
assert 'Build completed successfully' in text and 'error:' not in text
facts={}
for name,axioms in re.findall(r"'Lean1090.Proofs.AffineValue\.([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip())
 assert set(actual)<={'propext','Classical.choice','Quot.sound'}
 facts[name]=actual
assert len(facts)==10
for name in statements: assert name in facts
witnesses=sorted(n for n in facts if n.endswith('_witness'))
for name in ['identity_witness','scaled_witness','offset_witness','both_witness','negative_witness','missing_status_witness']:
 assert name in witnesses
assert len(witnesses)==7 and 'zero_scale_witness' in witnesses
failed_log=B/'proof/build-01.log'
failed_text=failed_log.read_text()
assert failed_text.count("unexpected identifier; expected '}'")==3
assert 'error: build failed' in failed_text
unchanged={}
for path in ['Impl/CommB.lean','Impl/Semantics.lean','Impl/Message.lean','TRUSTED.md']:
 assert Path(path).read_text()==old(path),path
 unchanged[path]=sha(path)
assert 'let value ← payloadValue c word' in Path('Impl/CommB.lean').read_text()
assert 'layout.map fun c => (c.name, payloadValue c word)' in Path('Impl/Semantics.lean').read_text()
locked={};adapter_refs=[]
for line in Path('spec.lock').read_text().splitlines():
 match=re.fullmatch(r'([0-9a-f]{64})\s+(.+)',line)
 if match:
  digest,path=match.groups();assert sha(path)==digest,path;locked[path]=digest
  if path.endswith('.lean') and 'Impl.' in Path(path).read_text(): adapter_refs.append(path)
assert len(locked)==104
out={'status':'passed_source_and_universal_helper_proof_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'source_sha256':expected,'unchanged_live_source_sha256':unchanged,'proof_summary_sha256':sha(B/'proof/summary.json'),
 'retained_failed_helper_log':{'path':str(failed_log),'sha256':sha(failed_log),'cause':'Three malformed multiline witness literals; their absent declarations caused subsequent print-axiom errors. Universal equalities compiled in that attempt. The passed attempt fixes witness formatting and adds a zero-scale witness.'},
 'successful_helper_log':str(log),'successful_helper_log_sha256':sha(log),'printed_axioms':facts,
 'universal_statements':statements,'witnesses':witnesses,'frozen_file_hashes_checked':len(locked),
 'frozen_adapter_sources_checked':adapter_refs,'review_script_sha256':sha(__file__),'findings':[],
 'reasoning':[
 'The helper quantifies every Int and Rat scale/offset. Exact Rat equality selects scale=1 and offset=0; four cases close by multiplication and addition identities, with no validity, range, sign, denominator, or acceptance hypotheses.',
 'The general branch preserves integer-to-rational conversion followed by multiplication then addition. Unit scale skips only multiplication by one; zero offset skips only addition by zero. Negative, fractional and zero values are within the same universal equality.',
 'payloadValue preserves the complete status predicate and none result before computing the helper. Existing natural-width extraction and signed interpretation are byte-identical, including unrestricted word/start/width/status arguments.',
 'The old-body equality rewrites only the helper; the frozen reference equality then invokes the existing all-Nat payloadBits refinement. No new decoder-dependent validity premise or frozen statement is introduced.',
 'Semantics.tableValues and commBValue remain byte-identical and call the same public live payloadValue. Frozen adapters reach those actual semantic/inference paths rather than a retained legacy copy.',
 'Runtime imports only Model.Types. There is no new table, corpus condition, cross-message state, binary64 operation, extern, trusted primitive or arithmetic approximation.'
 ],'limits':[
 'This review consumes completed helper build/axiom evidence and reads sources; it runs no Lean build, test, decoder, profiler or benchmark.',
 'Integrated refinement, actual generated-C/native branch binding and complete fixed/fresh gate evidence are separate checks.',
 'Exact equivalence does not establish any speedup; general nonidentity fields still execute the original rational operations.'
 ]}
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'axiom_facts':len(facts),'witnesses':len(witnesses)},indent=2))
