"""Read completed gen15 integration evidence; no compiler or decoder execution."""
import os,sys
sys.dont_write_bytecode=True
os.environ['PYTHONDONTWRITEBYTECODE']='1'
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen15');R=B/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
old=lambda p:subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['status']=='passed' and build['exit_code']==0
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']=='b7b1429a9048ebfbcff88eaa0a3ef215512ba693504bed8d3749752fe700de54'
assert build['inputs_before']==build['inputs_after'] and build['finished_monotonic_ns']>build['started_monotonic_ns']
assert set(build['inputs_before'])=={'Impl/CommB.lean','Proofs/CommBConstant.lean','Proofs/Decoder.lean'}
for p,h in build['inputs_before'].items():assert sha(p)==h,p
text=log.read_text();assert 'error:' not in text
assert re.findall(r'Build completed successfully \((\d+) jobs\)\.',text)==['3523']
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in re.findall(r"'([^']+)' does not depend on any axioms",text):facts[name]=[]
for name in ['Lean1090.Proofs.CommBConstant.bdsWireValid_eq_old','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:assert name in facts,name
before=old('Proofs/Decoder.lean');after=Path('Proofs/Decoder.lean').read_text()
assert after.count('import Proofs.CommBConstant\n')==1
assert after.replace('import Proofs.CommBConstant\n','')==before
proof=load(B/'proof/summary.json');assert proof['status']=='passed'
assert proof['sources']=={p:sha(p) for p in ['Impl/CommB.lean','Proofs/CommBConstant.lean']}
assert proof['kernel_witness_theorems']==3 and len(proof['axiom_facts'])==6
for fact in proof['axiom_facts']:assert set(fact['axioms'])<={'propext','Classical.choice','Quot.sound'}
assert [a['exit_code'] for a in proof['attempts']]==[0]
for attempt in proof['attempts']:
 p=B/'proof'/attempt['record'];assert sha(p)==attempt['sha256'];r=load(p)
 assert r['exit_code']==attempt['exit_code'] and sha(p.with_suffix('.log'))==attempt['log_sha256']
 assert r['sources_before']==r['sources_after']==proof['sources']
for p,h in proof['files'].items():assert sha(p)==h
source=Path('Impl/CommB.lean').read_text();previous=old('Impl/CommB.lean');helper=Path('Proofs/CommBConstant.lean').read_text()
constant='''/-- The exclusive upper bound for a 56-bit Comm-B payload. Keeping this exact
format constant outside the call body avoids reparsing its large Nat literal
at every register check; it contains no per-message or corpus-derived state. -/
@[noinline] def commBPayloadLimit : Nat := 2^56

'''
assert source.count(constant)==1
assert source.replace(constant,'').replace('word < commBPayloadLimit && match register with','word < 2^56 && match register with')==previous
assert source.count('word < commBPayloadLimit && match register with')==1
assert 'theorem payload_limit_eq : Impl.commBPayloadLimit = 2^56 := rfl' in helper
assert 'theorem bdsWireValid_eq_old (register word : Nat) :' in helper
start=helper.index('      (word < 2^56 && match register with')
end=helper.index(' := rfl',start)
statement=helper[start:end]
original_start=previous.index('  word < 2^56 && match register with')
original_end=previous.index('\n\n',original_start)
original_body=previous[original_start:original_end].strip()
normalized='\n'.join(line[6:] if line.startswith('      ') else line for line in statement.splitlines())
assert normalized.removeprefix('(').removesuffix(')').replace('Impl.','')==original_body
assert not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|@\[(?:extern|implemented_by)',source+helper)
unchanged={}
for p in ['Proofs/CommBTables.lean','Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Proofs/CommBMach.lean','Proofs/CommBQNH.lean','Proofs/CommBPenalty.lean','Proofs/CommBRatio.lean','Proofs/Binary64Error.lean','Proofs/ParityBits.lean','Proofs/ParityWord.lean','Proofs/FrameBits.lean','Proofs/ByteWords.lean','Impl/Binary64.lean','Impl/Bits.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/Parity.lean','Impl/Semantics.lean','Impl/Message.lean']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
assert (B/'proof/before-Impl-CommB.lean').read_text()==previous
out={'status':'passed_integrated_build_and_refinement_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'final_source_sha256':build['inputs_before'],'unchanged_sources':unchanged,'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':3523,'record':build},'helper_proof_summary_sha256':sha(B/'proof/summary.json'),'all_successful_printed_axioms':facts,'retained_build_warnings':[s for s in text.splitlines() if s.startswith('warning:')],'integration_change':'Decoder adds only the CommBConstant import. Runtime adds exactly the non-inlined immutable 2^56 constant and replaces the single bdsWireValid bound expression; every register-specific body is byte-identical.','mathematical_review':['The constant is definitionally exactly 2^56; no decimal approximation, finite input restriction or alternative numeric representation enters the proof.','The universal theorem quantifies arbitrary Nat register and word and reproduces the entire original body by rfl. Its branch text independently matches the previous committed implementation after namespace qualification.','All unsupported registers, boundary payloads and over-wide arbitrary Nat words are preserved. Three kernel witnesses cover zero/maximum in-range, exact and much larger rejection bounds, and accepted/unsupported headers.','The implementation contains no message memoization or mutable state. Existing public bdsWireValid remains the live entrypoint, and the existing whole-decoder refinement compiles unchanged through definitional reduction.'],'findings':[],'review_script_sha256':sha(__file__),'limits':'Read-only source/proof/integration binding check; no compiler, decoder or test execution. Separate cost_analysis native review follows. The retained proof/runtime.diff is empty; this review instead checks exact previous committed source and retained before-source against the final body, so an empty diff is not treated as evidence of no change.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':3523},indent=2))
