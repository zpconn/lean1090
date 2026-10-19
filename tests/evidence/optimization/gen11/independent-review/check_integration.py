#!/usr/bin/env python3
"""Review completed integration evidence; no build or decoder execution.
The reviewer authored the helper proof, so its independent substantive review
is separately supplied by cost_analysis and bound by the final gate reviewer.
"""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen11');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
manifest=B/'integration/targeted-build.json';log=B/'integration/targeted-build.log';build=load(manifest)
assert build['status']=='passed' and build['exit_code']==0
assert build['command']==['lake','build','Proofs.Decoder','lean1090','messageGenerator','commbDifferential']
assert sha(log)==build['log_sha256']=='28517eb63be4a67a149eda85f866cd3eea6f39136f35592c65fb845e8aed824a'
assert build['inputs_before']==build['inputs_after'] and build['finished_monotonic_ns']>build['started_monotonic_ns']
assert set(build['inputs_before'])=={'Impl/Parity.lean','Proofs/ParityWord.lean','Proofs/Decoder.lean'}
for path,digest in build['inputs_before'].items():assert sha(path)==digest,path
text=log.read_text();assert 'error:' not in text
warnings=[line for line in text.splitlines() if line.startswith('warning:')]
assert all('which is designed for use with the module system' in line for line in warnings)
assert all(line.startswith(('warning: Spec/Parity.lean:','warning: Spec/CPRFormula.lean:','warning: Proofs/ScoreGateInteger.lean:','warning: Proofs/ParityWord.lean:')) for line in warnings)
jobs=re.findall(r'Build completed successfully \((\d+) jobs\)\.',text);assert jobs==['3518']
facts={}
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=actual
for name in ['Lean1090.Proofs.ParityWord.wordStep_eq','Lean1090.Proofs.ParityWord.step_eq','Lean1090.Proofs.ParityWord.syndrome_eq','Lean1090.Proofs.Refinement','Lean1090.Proofs.PrefixRefinement']:
 assert name in facts,name
before=old('Proofs/Decoder.lean')
expected=before.replace('import Proofs.ParityBits\n','import Proofs.ParityBits\nimport Proofs.ParityWord\n')
a='private theorem decoder_Parity_step_eq : @Impl.Parity.step = @Spec.Parity.step := by\n  unfold Impl.Parity.step Spec.Parity.step\n  simp only [decoder_Parity_generator_eq]\n  rfl'
b='private theorem decoder_Parity_step_eq : @Impl.Parity.step = @Spec.Parity.step := by\n  funext remainder bit\n  exact ParityWord.step_eq remainder bit'
assert expected.count(a)==1;expected=expected.replace(a,b)
a='private theorem decoder_Parity_syndrome_eq : @Impl.Parity.syndrome = @Spec.Parity.syndrome := by\n  funext width word\n  unfold Impl.Parity.syndrome Spec.Parity.syndrome\n  simp only [ParityBits.cachedBit_eq, decoder_Parity_step_eq]'
b='private theorem decoder_Parity_syndrome_eq : @Impl.Parity.syndrome = @Spec.Parity.syndrome := by\n  funext width word\n  exact ParityWord.syndrome_eq width word'
assert expected.count(a)==1 and Path('Proofs/Decoder.lean').read_text()==expected.replace(a,b)
proof=load(B/'proof/summary.json');assert proof['status']=='passed' and proof['sources']=={p:sha(p) for p in ['Impl/Parity.lean','Proofs/ParityWord.lean']}
assert len(proof['facts'])==11 and proof['kernel_witnesses']==7 and proof['attempts']==11
for fact in proof['facts']:assert set(fact['axioms'])<={'propext','Classical.choice','Quot.sound'}
assert sha(B/'proof/build-11.log')==proof['log_sha256']
assert load(B/'proof/build-06.json')['exit_code']==0 and '._native.bv_decide.ax_' in (B/'proof/build-06.log').read_text()
assert 'bv_decide' not in Path('Proofs/ParityWord.lean').read_text()
assert all((B/f'proof/build-{i:02d}.log').is_file() and (B/f'proof/build-{i:02d}.json').is_file() for i in range(1,12))
unchanged={}
for path in ['Proofs/CommBTables.lean','Proofs/ScoreGate.lean','Proofs/ScoreGateInteger.lean','Proofs/AffineValue.lean','Proofs/CommBMach.lean','Proofs/CommBQNH.lean','Proofs/ParityBits.lean','Impl/CommB.lean','Impl/PayloadBits.lean','Impl/Frame.lean','Impl/Bits.lean','Impl/Semantics.lean','Impl/Message.lean']:
 assert Path(path).read_text()==old(path),path;unchanged[path]=sha(path)
out={'status':'passed_integrated_build_and_refinement_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'final_source_sha256':build['inputs_before'],'unchanged_sources':unchanged,
 'successful_integrated_build':{'manifest':str(manifest),'manifest_sha256':sha(manifest),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':3518,'record':build},
 'helper_proof_summary_sha256':sha(B/'proof/summary.json'),'retained_build_warnings':warnings,'all_successful_printed_axioms':facts,
 'integration_change':'Only one helper import and two private proof bodies changed. Exact theorem types and all hypotheses remain unchanged; live CRC refinement compiles through the final whole-message Refinement.',
 'findings':[],'review_script_sha256':sha(__file__),
 'limits':'Read-only completed integration evidence check. This reviewer authored ParityWord; cost_analysis provides the separate independent source/proof assessment. No compiler, decoder or test was run by this check.'}
p=R/'integration-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'printed_facts':len(facts),'jobs':3518},indent=2))
