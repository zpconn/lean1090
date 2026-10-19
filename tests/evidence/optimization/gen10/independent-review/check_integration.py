#!/usr/bin/env python3
"""Read-only gen10 universal QNH helper to final-refinement integration review."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen10');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
review=load(R/'source-proof-review.json')
assert review['status']=='passed_source_and_universal_helper_proof_review'
for p,d in review['source_sha256'].items():assert sha(p)==d,p
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['exit_code']==0 and build['status']=='passed'
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']=='3b4acf159a2f3d3d2e8b553f4d18924bfbab1b48eb710162c6313c5142c11547'
assert build['inputs_before']==build['inputs_after'] and build['finished_monotonic_ns']>build['started_monotonic_ns']
for p,d in build['inputs_before'].items():assert sha(p)==d,p
text=log.read_text();assert 'error:' not in text
warnings=[line for line in text.splitlines() if line.startswith('warning:')]
assert len(warnings)==5 and all('which is designed for use with the module system' in line for line in warnings)
assert all(line.startswith(('warning: Spec/Parity.lean:', 'warning: Spec/CPRFormula.lean:', 'warning: Proofs/ScoreGateInteger.lean:')) for line in warnings)
jobs=re.findall(r'Build completed successfully \((\d+) jobs\)\.',text);assert jobs==['3515']
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in ['Lean1090.Proofs.CommBQNH.cbQNH64_eq','Lean1090.Proofs.CommBQNH.cbQNH64_eq_runtime','Lean1090.Proofs.CommBTables.density_terms_eq','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:
 assert name in facts,name
prior=old('Proofs/Decoder.lean');expected=prior.replace('import Proofs.FrameBits\n','import Proofs.FrameBits\nimport Proofs.CommBQNH\n')
a='''private theorem decoder_cbQNH64_eq : @Impl.cbQNH64 = @Spec.cbQNH64 := by
  unfold Impl.cbQNH64 Spec.cbQNH64
  simp only [decoder_Binary64_add_eq, decoder_Binary64_literal_eq, decoder_Binary64_mul_eq,
    decoder_payloadBits_eq]'''
b='''private theorem decoder_cbQNH64_eq : @Impl.cbQNH64 = @Spec.cbQNH64 := by
  funext word
  exact CommBQNH.cbQNH64_eq word'''
assert expected.count(a)==1 and Path('Proofs/Decoder.lean').read_text()==expected.replace(a,b)
prior=old('Proofs/CommBTables.lean');expected=prior.replace('import Proofs.AffineValue\n','import Proofs.AffineValue\nimport Proofs.CommBQNH\n')
a='''    bds40Layout, cbColumn, payloadValue, AffineValue.affineValue_eq, cbScoreField, cbQNH64]'''
b='''    bds40Layout, cbColumn, payloadValue, AffineValue.affineValue_eq, cbScoreField,
    CommBQNH.cbQNH64_eq_runtime]'''
assert expected.count(a)==1 and Path('Proofs/CommBTables.lean').read_text()==expected.replace(a,b)
unchanged={}
for p in ['Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Proofs/CommBMach.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/Semantics.lean','Impl/Message.lean','Impl/Parity.lean']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
final={p:sha(p) for p in ['Impl/CommB.lean','Proofs/CommBQNH.lean','Proofs/Decoder.lean','Proofs/CommBTables.lean']};assert final==build['inputs_before']
out={'status':'passed_integrated_build_and_universal_refinement_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'prior_source_review_sha256':sha(R/'source-proof-review.json'),'final_source_sha256':final,'unchanged_sources':unchanged,
 'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':int(jobs[0]),'record':build},
 'reviewer_attempt':{'attempt':2,'failed_script_sha256':sha(R/'check_integration_01.py'),'failed_log_sha256':sha(R/'integration-review-01.log'),'correction':'The first reviewer incorrectly rejected every warning. The completed integration contains five pre-existing module-system import advisories in unchanged Spec/Parity, Spec/CPRFormula and Proofs/ScoreGateInteger; the corrected review explicitly checks exactly those warnings. No source, proof or build artifact changed.'},'retained_build_warnings':warnings,'all_successful_printed_axioms':facts,
 'integration_change':'Only helper imports and proof bodies changed: Decoder uses funext and the unconditional frozen-reference QNH equality, while the unchanged density40 table-equality proof rewrites the unconditional runtime QNH equality instead of unfolding the former arithmetic body. Every theorem type and hypothesis is unchanged. The existing final Refinement and PrefixRefinement compile against the live table.',
 'findings':[],'review_script_sha256':sha(__file__),
 'limits':'Read-only source and completed-build evidence review. No compiler, decoder or test run by this reviewer. Fixed/fresh full gate and generated C/native binding are separate checks.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':int(jobs[0])},indent=2))
