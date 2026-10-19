"""Read completed gen13 integration evidence; no build or decoder execution."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen13');R=B/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
old=lambda p:subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['status']=='passed' and build['exit_code']==0
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']=='80842080101e8967d46b1ef3aabe4fafee23b7d29e519a6dacaefba15b1e8b36'
assert build['inputs_before']==build['inputs_after'] and build['finished_monotonic_ns']>build['started_monotonic_ns']
assert set(build['inputs_before'])=={'Impl/CommB.lean','Proofs/CommBPenalty.lean','Proofs/Decoder.lean'}
for p,h in build['inputs_before'].items():assert sha(p)==h,p
text=log.read_text();assert 'error:' not in text
assert re.findall(r'Build completed successfully \((\d+) jobs\)\.',text)==['3521']
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in re.findall(r"'([^']+)' does not depend on any axioms",text):facts[name]=[]
for name in ['Lean1090.Proofs.CommBPenalty.cbWindPenalty50_eq_raw','Lean1090.Proofs.CommBPenalty.cbWindPenalty50_eq_runtime','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:assert name in facts,name
before=old('Proofs/Decoder.lean');after=Path('Proofs/Decoder.lean').read_text()
assert after.count('import Proofs.CommBPenalty\n')==1
without=after.replace('import Proofs.CommBPenalty\n','')
a='''private theorem decoder_cbPenalty_eq : @Impl.cbPenalty = @Spec.cbPenalty := by
  unfold Impl.cbPenalty Spec.cbPenalty
  simp only [decoder_Binary64_div_eq, decoder_Binary64_literal_eq, decoder_Binary64_sub_eq,
    decoder_cbMach64_eq, decoder_commBValue_eq]
  rfl'''
b='''private theorem decoder_cbPenalty_eq : @Impl.cbPenalty = @Spec.cbPenalty := by
  funext register word
  unfold Impl.cbPenalty Spec.cbPenalty
  split <;>
    simp only [CommBPenalty.cbWindPenalty50_eq_runtime, decoder_Binary64_div_eq,
      decoder_Binary64_literal_eq, decoder_Binary64_sub_eq, decoder_cbMach64_eq,
      decoder_commBValue_eq] <;> rfl'''
assert before.count(a)==1 and without==before.replace(a,b)
proof=load(B/'proof/summary.json');assert proof['status']=='passed'
assert proof['sources']=={p:sha(p) for p in ['Impl/CommB.lean','Proofs/CommBPenalty.lean']}
assert proof['table_entries']==2047 and proof['kernel_witness_theorems']==6 and len(proof['axiom_facts'])==11
for fact in proof['axiom_facts']:assert set(fact['axioms'])<={'propext','Classical.choice','Quot.sound'}
assert [a['exit_code'] for a in proof['attempts']]==[0]
for attempt in proof['attempts']:
 p=B/'proof'/attempt['record'];assert sha(p)==attempt['sha256'];r=load(p);assert r['exit_code']==0 and sha(p.with_suffix('.log'))==attempt['log_sha256']
source=Path('Impl/CommB.lean').read_text();previous=old('Impl/CommB.lean');helper=Path('Proofs/CommBPenalty.lean').read_text()
start=source.index('/-- Every signed difference of the two unsigned ten-bit BDS50 speed codes.')
end=source.index('-- Initial algorithm: Spec/CommB.lean:409.',start)
stripped=source[:start]+source[end:]
a='''    let p := match value "TAS", value "groundspeed" with
      | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
      | _, _ => 0'''
assert previous.count(a)==1 and stripped==previous.replace(a,'    let p := cbWindPenalty50 word')
assert 'Array.ofFn fun code : Fin 2047' in source[start:end]
assert 'Binary64.div (Binary64.round (2 * ((code.val : Rat) - 1023))).abs 100' in source[start:end]
assert 'payloadBits word 46 1 == 0 || payloadBits word 24 1 == 0' in source[start:end]
assert 'cbWindPenaltyTable[tas + 1023 - gs]' in source[start:end]
assert 'theorem cbWindPenalty50_eq_runtime (word : Nat) :' in helper
assert 'Nat.cast_sub (show gs ≤ tas + 1023 by omega)' in helper
assert not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|@\[(?:extern|implemented_by)',source+helper)
unchanged={}
for p in ['Proofs/CommBTables.lean','Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Proofs/CommBMach.lean','Proofs/CommBQNH.lean','Proofs/ParityBits.lean','Proofs/ParityWord.lean','Proofs/FrameBits.lean','Proofs/ByteWords.lean','Impl/Bits.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/Parity.lean','Impl/Semantics.lean','Impl/Message.lean']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
out={'status':'passed_integrated_build_and_refinement_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'final_source_sha256':build['inputs_before'],'unchanged_sources':unchanged,'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':3521,'record':build},'helper_proof_summary_sha256':sha(B/'proof/summary.json'),'all_successful_printed_axioms':facts,'retained_build_warnings':[s for s in text.splitlines() if s.startswith('warning:')],'integration_change':'Only the CommBPenalty import and private cbPenalty equality proof changed. The unconditional new helper equality replaces exactly the BDS50 wind expression; turn/BDS60 and all other runtime/proof code examined remains unchanged.','findings':[],'review_script_sha256':sha(__file__),'limits':'Read-only source/proof/integration binding check; no compiler, decoder or test execution. Separate cost_analysis mathematical source/proof/native review is retained.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':3521},indent=2))
