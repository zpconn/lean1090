#!/usr/bin/env python3
"""Focused independent source/proof review; no build or decoder execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen21/independent-review');A=R.parent/'affine'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
bindings={};checks=[]
def bind(p,h=None):
 d=sha(p);assert h is None or d==h,str(p);bindings[str(p)]=d;return d
def check(ok,n):assert ok,n;checks.append(n)
s=load(A/'summary.json');bind(A/'summary.json','259ca448bda0b4917dbee9df5495a18ec503d8df58d44e66bb99d97b2f341fe3')
check(s['status']=='passed' and s['first_attempt_passed'] and s['build_jobs']==7,'first targeted proof build passed')
for p,h in s['sources'].items():bind(p,h)
for p,h in s['files'].items():bind(A/p,h)
runtime=Path('Impl/PayloadBits.lean').read_text();proof=Path('Proofs/AffineValue.lean').read_text()
oldruntime=(A/'before/Impl/PayloadBits.lean').read_text();oldproof=(A/'before/Proofs/AffineValue.lean').read_text()
for name,old in [('Impl/PayloadBits.lean',oldruntime),('Proofs/AffineValue.lean',oldproof)]:check(subprocess.check_output(['git','show','HEAD:'+name],text=True)==old,'before source exact committed '+name)
helper='/-- Exact scaling of an integer by a rational, normalizing its numerator\nproduct directly without constructing an intermediate integer rational. -/\n@[inline] def integerScale (value : Int) (scale : Rat) : Rat :=\n  Rat.normalize (value * scale.num) scale.den scale.den_nz\n\n'
restored=runtime.replace(helper,'').replace('offset need no rational multiplication or addition; other cases scale exactly\nbefore adding the offset. -/','offset need no rational multiplication or addition; every other case keeps\nthe original exact operations in their original order. -/').replace('else integerScale value scale','else (value : Rat) * scale')
check(restored==oldruntime,'only exact helper/nonunit branch and descriptive comment changed')
headers=lambda text:dict(re.findall(r'theorem (\w+)([\s\S]*?) := by',text))
oldheaders=headers(oldproof);newheaders=headers(proof)
check(len(oldheaders)==10 and all(newheaders[n]==h for n,h in oldheaders.items()),'all ten existing theorem statements unchanged')
check(set(newheaders)-set(oldheaders)=={'integerScale_eq','cancellation_witness','large_negative_witness','negative_fraction_witness'},'only universal helper theorem and three kernel witnesses added')
check('(Rat.mul_def (value : Rat) scale).symm' in proof and 'Rat.num_intCast, Rat.den_intCast, Nat.one_mul' in proof,'unrestricted exact multiplication refinement')
check(newheaders['integerScale_eq']==' (value : Int) (scale : Rat) :\n    Impl.integerScale value scale = (value : Rat) * scale','no sign, denominator, magnitude or field-validity premise')
log=(A/'attempt-01/build.log').read_text();facts=[]
for name,axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",log):
 xs=[x.strip() for x in axioms.split(',') if x.strip()];check(set(xs)<= {'propext','Classical.choice','Quot.sound'},'allowed axioms '+name)
 if name.startswith('Lean1090.Proofs.AffineValue.'):facts.append(dict(theorem=name,axioms=xs))
check(facts==s['printed_axiom_facts'] and len(facts)==14,'all fourteen affine printed facts independently parsed')
check(proof.count('decide +kernel')==10,'ten pure kernel witnesses, including cancellation and values beyond 64 bits')
for p in ['Proofs/Decoder.lean','Proofs/CommBTables.lean','Tests/CommBDifferential.lean','Tests/UpstreamCorpus.lean','CLI/Main.lean','Bench/WholeDecoder.lean']:
 bind(p);check(Path(p).read_bytes()==subprocess.check_output(['git','show','HEAD:'+p]),'unchanged live bridge/adapter '+p)
check('exact AffineValue.payloadValue_eq column word' in Path('Proofs/Decoder.lean').read_text(),'decoder equality delegates to live affine refinement')
check(Path('Proofs/CommBTables.lean').read_text().count('AffineValue.affineValue_eq')==5,'five density bridges retain live affine equality')
for token in ['sorry','admit','axiom','native_decide','unsafe','partial','panic!','get!','unreachable!','@[extern','@[implemented_by']:
 check(not re.search(r'(?<![A-Za-z_])'+re.escape(token)+r'(?![A-Za-z_])',runtime),'no forbidden runtime construct '+token)
lock=Path('spec.lock');bind(lock);entries=[line.split('  ',1) for line in lock.read_text().splitlines()];check(len(entries)==104,'104 locked files')
for h,p in entries:check(sha(p)==h,'locked '+p)
stdlib=Path('/home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat')
for name in ['Basic.lean','Lemmas.lean']:bind(stdlib/name)
record=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks=checks,checks_passed=len(checks),bindings=bindings,source_hashes=s['sources'],old_theorem_statements_preserved=sorted(oldheaders),printed_axiom_facts=facts,kernel_witnesses=10,integer_scale_all_input_refinement_verified=True,source_delta=['Impl/PayloadBits.lean','Proofs/AffineValue.lean'],reviewer_sha256=sha(__file__),assessment=['Rat.mul_def and integer-cast numerator/denominator identities establish equality for arbitrary Int and Rat; normalization handles all signs and nonzero canonical denominators internally.','Identity-scale and zero-offset branch order is unchanged. Status rejection, extraction, signed interpretation and all downstream frozen adapters remain live.','Exact normalizing numerator multiplication may have a larger temporary for huge cancelling inputs than cross-cancellation; no universal performance claim.','No Float, trusted primitive, frozen change, source edit or build by reviewer. Actual generated/native path remains a separate post-integration check.'])
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),sha256=sha(p))))
