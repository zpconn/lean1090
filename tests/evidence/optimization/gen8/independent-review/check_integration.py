#!/usr/bin/env python3
"""Read-only binding of gen8 helper proof to completed decoder integration."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen8');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
review=load(R/'source-proof-review.json')
assert review['status']=='passed_source_and_universal_helper_proof_review'
for p,d in review['source_sha256'].items():assert sha(p)==d,p
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log'
build=load(manifest)
assert build['exit_code']==0
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']
for p,d in build['inputs_before'].items():assert sha(p)==d,p
assert build['inputs_before']==build['inputs_after']
text=log.read_text()
assert 'error:' not in text
jobs=re.findall(r'Build completed successfully \((\d+) jobs\)\.',text)
assert len(jobs)==1
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip())
 assert set(actual)<={'propext','Classical.choice','Quot.sound'},name
 facts[name]=actual
for name in ['Lean1090.Proofs.AffineValue.affineValue_eq','Lean1090.Proofs.AffineValue.payloadValue_eq_old','Lean1090.Proofs.AffineValue.payloadValue_eq','Lean1090.Proofs.CommBTables.density_terms_eq','Lean1090.Proofs.CommBTables.density_terms_length','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:
 assert name in facts,name
prior=old('Proofs/Decoder.lean')
expected=prior.replace('import Proofs.SyndromeReuse\n','import Proofs.SyndromeReuse\nimport Proofs.AffineValue\n')
a='''  unfold Impl.payloadValue Spec.payloadValue
  simp only [decoder_payloadBits_eq, decoder_payloadInteger_eq]'''
b='''  funext column word
  exact AffineValue.payloadValue_eq column word'''
assert expected.count(a)==1
assert Path('Proofs/Decoder.lean').read_text()==expected.replace(a,b)
prior=old('Proofs/CommBTables.lean')
expected=prior.replace('import Proofs.CommBMach\n','import Proofs.CommBMach\nimport Proofs.AffineValue\n')
assert expected.count('cbColumn, payloadValue,')==5
expected=expected.replace('cbColumn, payloadValue,','cbColumn, payloadValue, AffineValue.affineValue_eq,')
assert Path('Proofs/CommBTables.lean').read_text()==expected
for p in ['Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Impl/CommB.lean','Impl/Semantics.lean','Impl/Message.lean']:
 assert Path(p).read_text()==old(p),p
final={p:sha(p) for p in ['Impl/PayloadBits.lean','Proofs/AffineValue.lean','Proofs/CommBTables.lean','Proofs/Decoder.lean']}
assert final==build['inputs_before']
out={'status':'passed_integrated_build_and_universal_refinement_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'prior_source_review_sha256':sha(R/'source-proof-review.json'),'final_source_sha256':final,
 'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':int(jobs[0]),'record':build},
 'all_successful_printed_axioms':facts,'integration_change':'Decoder replaces only the private payloadValue equality proof with the universal helper theorem. CommBTables imports that theorem and rewrites the five expanded payloadValue branches. All theorem types and remaining proof bodies are unchanged.',
 'findings':[],'review_script_sha256':sha(__file__),
 'limits':'Read-only source and completed-build review. No compiler, decoder or test run by this reviewer. Fixed/fresh full gate and native C/assembly checks are separate.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':int(jobs[0])},indent=2))
