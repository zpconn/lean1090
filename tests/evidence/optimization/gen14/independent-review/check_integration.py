"""Read completed gen14 integration evidence; no build or decoder execution."""
import os,sys
sys.dont_write_bytecode=True
os.environ['PYTHONDONTWRITEBYTECODE']='1'
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen14');R=B/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
old=lambda p:subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['status']=='passed' and build['exit_code']==0
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']=='5af1ef908ba00a6a42b69d54fdb1d42b980457e2f5a0277899a1452334e5d867'
assert build['inputs_before']==build['inputs_after'] and build['finished_monotonic_ns']>build['started_monotonic_ns']
assert set(build['inputs_before'])=={'Impl/CommB.lean','Proofs/CommBRatio.lean','Proofs/Decoder.lean'}
for p,h in build['inputs_before'].items():assert sha(p)==h,p
text=log.read_text();assert 'error:' not in text
assert re.findall(r'Build completed successfully \((\d+) jobs\)\.',text)==['3522']
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in re.findall(r"'([^']+)' does not depend on any axioms",text):facts[name]=[]
for name in ['Lean1090.Proofs.CommBRatio.cbRatioOutside250800_eq','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:assert name in facts,name
before=old('Proofs/Decoder.lean');after=Path('Proofs/Decoder.lean').read_text()
assert after.count('import Proofs.CommBRatio\n')==1
without=after.replace('import Proofs.CommBRatio\n','')
a='    simp only [CommBPenalty.cbWindPenalty50_eq_runtime, decoder_Binary64_div_eq,\n'
b='    simp only [CommBPenalty.cbWindPenalty50_eq_runtime, CommBRatio.cbRatioOutside250800_eq,\n      decoder_Binary64_round_eq, decoder_Binary64_div_eq,\n'
assert before.count(a)==1 and without==before.replace(a,b)
proof=load(B/'proof/summary.json');assert proof['status']=='passed'
assert proof['sources']=={p:sha(p) for p in ['Impl/CommB.lean','Proofs/CommBRatio.lean']}
assert proof['kernel_witness_theorems']==6 and len(proof['axiom_facts'])==7
for fact in proof['axiom_facts']:assert set(fact['axioms'])<={'propext','Classical.choice','Quot.sound'}
assert [a['exit_code'] for a in proof['attempts']]==[1,1,0]
for attempt in proof['attempts']:
 p=B/'proof'/attempt['record'];assert sha(p)==attempt['sha256'];r=load(p)
 assert r['exit_code']==attempt['exit_code'] and sha(p.with_suffix('.log'))==attempt['log_sha256']
 assert r['sources_before']['Impl/CommB.lean']==r['sources_after']['Impl/CommB.lean']==sha('Impl/CommB.lean')
 if r['exit_code']==0:assert r['sources_before']==r['sources_after']==proof['sources']
for p,h in proof['files'].items():assert sha(p)==h
source=Path('Impl/CommB.lean').read_text();previous=old('Impl/CommB.lean');helper=Path('Proofs/CommBRatio.lean').read_text()
start=source.index('/-- Exact decision for a software-binary64 rounded ratio outside [250,800].')
end=source.index('-- Initial algorithm: Spec/CommB.lean:409.',start)
stripped=source[:start]+source[end:]
a='''        let ratio := Binary64.div ias mach
        if ratio < 250 || ratio > 800 then -3 else 0'''
assert previous.count(a)==1 and stripped==previous.replace(a,'        if cbRatioOutside250800 (ias / mach) then -3 else 0')
expected='''def cbRatioOutside250800 (q : Rat) : Bool :=
  let n := q.num
  let d : Int := q.den
  let k : Int := 2251799813685248
  let e : Int := (q.num.natAbs : Int) + d
  let c := k * n
  let lower := 250 * k * d
  let upper := 800 * k * d
  if c + e < lower || upper < c - e then true
  else if lower ≤ c - e && c + e ≤ upper then false
  else
    let rounded := Binary64.round q
    rounded < 250 || rounded > 800
'''
assert expected in source[start:end]
assert 'theorem cbRatioOutside250800_eq (q : Rat) :' in helper
assert '(Impl.Binary64.round q < 250 || Impl.Binary64.round q > 800) := by' in helper
assert 'Binary64Error.round_error_of_bound q (|q| + 1)' in helper and 'exact_mod_cast q.den_pos' in helper
assert not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|@\[(?:extern|implemented_by)',source+helper)
unchanged={}
for p in ['Proofs/CommBTables.lean','Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Proofs/CommBMach.lean','Proofs/CommBQNH.lean','Proofs/CommBPenalty.lean','Proofs/Binary64Error.lean','Proofs/ParityBits.lean','Proofs/ParityWord.lean','Proofs/FrameBits.lean','Proofs/ByteWords.lean','Impl/Binary64.lean','Impl/Bits.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/Parity.lean','Impl/Semantics.lean','Impl/Message.lean']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
out={'status':'passed_integrated_build_and_refinement_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'final_source_sha256':build['inputs_before'],'unchanged_sources':unchanged,'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':3522,'record':build},'helper_proof_summary_sha256':sha(B/'proof/summary.json'),'all_successful_printed_axioms':facts,'retained_build_warnings':[s for s in text.splitlines() if s.startswith('warning:')],'integration_change':'Only the CommBRatio import and private cbPenalty equality proof changed. The unconditional equality replaces the BDS60 rounded ratio predicate; exact IAS/Mach division, positive-Mach/status guards, all BDS50 behavior and other runtime/proof code examined are unchanged.','mathematical_review':['For arbitrary Rat q, canonical denominator D is positive; K*D scales the exact q center without sign reversal. E=abs(N)+D represents (abs(q)+1)/K after division by this positive factor.','The existing universal software-rounding error bound with bound abs(q)+1 gives at most this enclosure. Strict outside tests cannot change inclusive endpoint decisions; inside tests include equality.','Only uncertain cases invoke the identical Binary64.round predicate. Every sign/magnitude/denominator is covered, including both sides that round back to 250 or 800. No field-validity, acceptance or corpus hypothesis is used.','The original Binary64.div body is exactly round(a/b), so preserving exact IAS/Mach formation and rewriting the universal helper equality preserves the live cbPenalty in both fast score and full software fallback paths.'],'findings':[],'review_script_sha256':sha(__file__),'limits':'Read-only source/proof/integration binding check; no compiler, decoder or test execution. Separate cost_analysis mathematical source/proof/native review is retained. Two failed proof elaboration attempts are preserved; final compiled source and seven facts use only permitted axioms.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':3522},indent=2))
