#!/usr/bin/env python3
"""Read-only binding of gen9 all-Nat extraction proof to the completed decoder build."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen9');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
review=load(R/'source-proof-review.json')
assert review['status']=='passed_source_and_universal_helper_proof_review'
for p,d in review['source_sha256'].items():assert sha(p)==d,p
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['exit_code']==0 and build['status']=='passed'
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']=='73bd82ef883e2ee0e5834b02b132d9ac73c57df1d9a2a433ca5644676dc2b6d5'
assert build['inputs_before']==build['inputs_after']
for p,d in build['inputs_before'].items():assert sha(p)==d,p
text=log.read_text();assert 'error:' not in text
jobs=re.findall(r'Build completed successfully \((\d+) jobs\)\.',text);assert len(jobs)==1
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in ['Lean1090.Proofs.FrameBits.field_eq','Lean1090.Proofs.FrameBits.field_eq_old','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:
 assert name in facts,name
prior=old('Proofs/Decoder.lean');expected=prior.replace('import Proofs.AffineValue\n','import Proofs.AffineValue\nimport Proofs.FrameBits\n')
a='''private theorem decoder_field_eq : @Impl.field = @Spec.field := by
  rfl'''
b='''private theorem decoder_field_eq : @Impl.field = @Spec.field := by
  funext total start width word
  exact FrameBits.field_eq total start width word'''
assert expected.count(a)==1 and Path('Proofs/Decoder.lean').read_text()==expected.replace(a,b)
unchanged={}
for p in ['Proofs/CommBTables.lean','Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/CommB.lean','Impl/Semantics.lean','Impl/Message.lean','Impl/Parity.lean']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
final={p:sha(p) for p in ['Impl/Bits.lean','Proofs/FrameBits.lean','Proofs/Decoder.lean']};assert final==build['inputs_before']
out={'status':'passed_integrated_build_and_universal_refinement_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'prior_source_review_sha256':sha(R/'source-proof-review.json'),'final_source_sha256':final,'unchanged_sources':unchanged,
 'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':int(jobs[0]),'record':build},
 'all_successful_printed_axioms':facts,'integration_change':'Only the FrameBits import and private all-parameter field equality proof changed in Decoder. The unchanged readACAS/readSurveillance/decodeFrame component proofs rewrite this equality; the same final Refinement and PrefixRefinement statements compile. No theorem statement, hypothesis or runtime callsite changed.',
 'findings':[],'review_script_sha256':sha(__file__),
 'limits':'Read-only source and completed-build evidence review. No compiler, decoder or test run by this reviewer. Fixed/fresh full gate and native C/assembly binding are separate checks.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':int(jobs[0])},indent=2))
