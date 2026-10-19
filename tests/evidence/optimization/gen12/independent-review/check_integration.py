#!/usr/bin/env python3
"""Read completed integration evidence without building or executing a decoder."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen12');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['status']=='passed' and build['exit_code']==0
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']
assert build['inputs_before']==build['inputs_after'] and build['finished_monotonic_ns']>build['started_monotonic_ns']
assert set(build['inputs_before'])=={'Impl/Bits.lean','Proofs/ByteWords.lean','Proofs/Decoder.lean'}
for p,d in build['inputs_before'].items():assert sha(p)==d,p
text=log.read_text();assert 'error:' not in text
jobs=re.findall(r'Build completed successfully \((\d+) jobs\)\.',text);assert jobs==['3520']
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in re.findall(r"'([^']+)' does not depend on any axioms",text):facts[name]=[]
for name in ['Lean1090.Proofs.ByteWords.bytesWord_eq','Lean1090.Proofs.ByteWords.bytesWordPrefix_eq','Lean1090.Proofs.ByteWords.bytesValue_eq','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:assert name in facts,name
before=old('Proofs/Decoder.lean');after=Path('Proofs/Decoder.lean').read_text()
assert after.count('import Proofs.ByteWords\n')==1
without=after.replace('import Proofs.ByteWords\n','')
a='private theorem decoder_bytesValue_eq : @Impl.bytesValue = @Spec.bytesValue := by\n  rfl'
b='private theorem decoder_bytesValue_eq : @Impl.bytesValue = @Spec.bytesValue := by\n  funext bytes\n  exact ByteWords.bytesValue_eq bytes'
assert before.count(a)==1 and without==before.replace(a,b)
proof=load(B/'proof/summary.json');assert proof['status']=='passed'
assert proof['source_sha256']=={p:sha(p) for p in ['Impl/Bits.lean','Proofs/ByteWords.lean']}
assert proof['public_refinement_has_no_hypotheses'] and len(proof['axiom_checks'])==11
assert proof['witness_lengths']==[0,7,8,9,14,16,17]
for fact in proof['axiom_checks']:assert set(fact['axioms'])<={'propext','Classical.choice','Quot.sound'}
for attempt in proof['attempts']:
 assert sha(attempt['record'])==attempt['sha256'];record=load(attempt['record']);assert record['exit_code']==attempt['exit_code']
assert [a['exit_code'] for a in proof['attempts']]==[1,0]
assert sha(B/'proof/build-02.log')==proof['final_build_log_sha256']
assert sha(B/'proof/build-02.json')==proof['final_build_record_sha256']
source=Path('Impl/Bits.lean').read_text();previous=old('Impl/Bits.lean')
marker='-- Initial algorithm: Spec/Bits.lean:17.'
assert source.split(marker,1)[1]==previous.split(marker,1)[1]
assert source.startswith('import Impl.PayloadBits\n')
assert 'def bytesValue (bytes : List UInt8) : Nat :=' in source
assert 'if count ≤ 8 then' in source and 'else if count ≤ 16 then' in source
assert 'bytesWordPrefix count rest (256 * word + byte.toUInt64)' in source
assert 'bytes.foldl (fun n b => 256 * n + b.toNat) 0' in source
assert not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|@\[(?:extern|implemented_by)',source+Path('Proofs/ByteWords.lean').read_text())
unchanged={}
for p in ['Proofs/CommBTables.lean','Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Proofs/CommBMach.lean','Proofs/CommBQNH.lean','Proofs/ParityBits.lean','Proofs/ParityWord.lean','Proofs/FrameBits.lean','Impl/CommB.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/Parity.lean','Impl/Semantics.lean','Impl/Message.lean']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
out={'status':'passed_integrated_build_and_refinement_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'final_source_sha256':build['inputs_before'],'unchanged_sources':unchanged,'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':3520,'record':build},'helper_proof_summary_sha256':sha(B/'proof/summary.json'),'all_successful_printed_axioms':facts,'retained_build_warnings':[s for s in text.splitlines() if s.startswith('warning:')],'integration_change':'Only the ByteWords import and private bytesValue equality proof changed. The public all-list equality and whole-decoder refinement retain their exact types. Runtime field/packFields/frameBytes bodies are unchanged.','findings':[],'review_script_sha256':sha(__file__),'limits':'Read-only source/proof/integration binding check; no compiler, decoder or test execution. Separate cost_analysis source/proof/native review is also retained.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':3520},indent=2))
