#!/usr/bin/env python3
"""Independent all-Rat proof/source review; no Lean or decoder execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import hashlib,json,re,subprocess
O=Path(__file__).resolve().parent;B=O.parent/'proof'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
assert not (O/'source-proof-review.json').exists()
s=load(B/'summary.json');b=load(B/'build-03.json');log=(B/'build-03.log').read_text()
assert s['status']=='passed' and [a['exit_code'] for a in s['attempts']]==[1,1,0]
assert b['sources_before']==b['sources_after']==s['sources'] and b['exit_code']==0
assert all(sha(p)==h for p,h in s['sources'].items())
for a in s['attempts']:
 p=B/a['record'];j=load(p);assert sha(p)==a['sha256'] and sha(p.with_suffix('.log'))==a['log_sha256']==j['log_sha256']
 assert j['exit_code']==a['exit_code'] and j['sources_before']['Impl/CommB.lean']==s['sources']['Impl/CommB.lean']
assert 'Build completed successfully (2050 jobs).' in log
source=Path('Impl/CommB.lean').read_text();proof=Path('Proofs/CommBRatio.lean').read_text();old=(B/'before-Impl-CommB.lean').read_text()
assert subprocess.check_output(['git','show','HEAD:Impl/CommB.lean']).decode()==old
start=source.index('/-- Exact decision for a software-binary64 rounded ratio outside [250,800].')
end=source.index('-- Initial algorithm: Spec/CommB.lean:409.',start)
recovered=source[:start]+source[end:]
old_gate='let ratio := Binary64.div ias mach\n        if ratio < 250 || ratio > 800 then -3 else 0'
new_gate='if cbRatioOutside250800 (ias / mach) then -3 else 0'
assert recovered.count(new_gate)==1 and recovered.replace(new_gate,old_gate)==old
helper=source[start:end]
assert all(x in helper for x in ['def cbRatioOutside250800 (q : Rat) : Bool :=','let d : Int := q.den','let k : Int := 2251799813685248','let e : Int := (q.num.natAbs : Int) + d','let c := k * n','let lower := 250 * k * d','let upper := 800 * k * d','if c + e < lower || upper < c - e then true','else if lower ≤ c - e && c + e ≤ upper then false','else\n    let rounded := Binary64.round q\n    rounded < 250 || rounded > 800'])
assert helper.count('Binary64.round')==1 and 2251799813685248==2**51
assert not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)',proof)
assert 'theorem cbRatioOutside250800_eq (q : Rat) :' in proof
assert 'exact_mod_cast q.den_pos' in proof and 'Binary64Error.round_error_of_bound q (|q| + 1)' in proof
assert all(x in proof for x in ['have fp : 0 < factor := mul_pos kp dp','have ec : (e : Rat) = factor * error','have outside (h : c + e < lower ∨ upper < c - e)','have inside (h : lower ≤ c - e ∧ c + e ≤ upper)','· rfl'])
assert sha(s['rounding_error_source']['path'])==s['rounding_error_source']['sha256']
error_source=Path(s['rounding_error_source']['path']).read_text()
assert 'theorem round_error_of_bound (value bound : Rat) (one : 1 ≤ bound)' in error_source and '(bounded : |value| ≤ bound)' in error_source
facts=[{'theorem':name,'axioms':[x.strip() for x in ax.split(',') if x.strip()]} for name,ax in re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^]]*)\]|does not depend on any axioms)",log,re.S)]
assert facts and all(set(f['axioms'])<= {'propext','Classical.choice','Quot.sound'} for f in facts)
facts=[f for f in facts if f['theorem'].startswith('Lean1090.Proofs.CommBRatio.')]
assert len(facts)==7 and facts==s['axiom_facts']
assert proof.count('decide +kernel')==6 and s['kernel_witness_theorems']==6
paths=[Path(p) for p in s['sources']]+[Path(s['rounding_error_source']['path'])]+sorted(p for p in B.rglob('*') if p.is_file())
paths=sorted({p.resolve().relative_to(Path.cwd()) for p in paths})
inputs={str(p):{'sha256':sha(p),'bytes':p.stat().st_size} for p in paths}
for p in paths:
 d=O/'proof-inputs'/p;d.parent.mkdir(parents=True,exist_ok=True);assert not d.exists();d.write_bytes(p.read_bytes())
result={'status':'passed','findings':[],'reviewer':'/root/cost_analysis; not the runtime/proof author','sources':s['sources'],'inputs':inputs,'helper_facts':facts,'kernel_witness_theorems':6,'all_Rat_runtime_equality_verified':True,'BDS50_and_BDS60_guards_source_unchanged':True,'assessment':[
'Rat denominator positivity is discharged internally. The proof derives numerator = denominator*q and absolute numerator = denominator*abs(q), then scales by the strictly positive factor K*D; it imposes no sign, magnitude, denominator or corpus premise on q.',
'The existing generic round_error_of_bound theorem is instantiated at abs(q)+1, whose two premises hold for every rational. Its bound 2*(abs(q)+1)/2^52 is exactly (abs(q)+1)/2^51. Integer E=abs(N)+D represents that error after scaling by K*D.',
'The outside test is strict at both edges. The inside test is inclusive. Positive-factor scaling and the closed rounding enclosure prove each shortcut agrees with the original rounded predicate. The uncertain case is definitionally the original predicate, not an approximation.',
'All arithmetic C+E, C-E, lower and upper is Int arithmetic, so subtraction cannot truncate at zero. The software round call occurs only inside the final else branch. Native laziness and live call sites are checked separately after integration.',
'Removing only the new helper and reversing the exact BDS60 gate replacement reproduces the entire previous CommB source byte-for-byte. BDS50 tables/turn penalty, BDS60 semantic availability and positive-Mach guards and the exact rational ias/mach input are preserved.',
'Six kernel witnesses cover definite inside/outside, both exact inclusive thresholds, rational values just outside that round back onto the thresholds, larger neighboring offsets and actual shortcut-false branch checks. They supplement the all-Rat theorem.',
'Helper attempt 3 passes with all seven printed facts using only allowed axioms. Two cast-normalization failures and their source/log snapshots are retained. No placeholder or native-reflection tactic appears in the final proof. The author runtime.diff artifact is empty after staging and is not used as scope evidence; the exact before/source reconstruction above is independently checked.'
],'script_sha256':sha(__file__),'limits':'Independent mathematical source assessment and replay of existing build/log/source bindings; no independent Lean build or native decoder execution. Integrated refinement and actual native path are checked separately.'}
(O/'source-proof-review.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(O/'source-proof-review.json'),'facts':len(facts),'witnesses':6}))
