#!/usr/bin/env python3
"""Independent runtime and packing proof review; no compilation or execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
R=Path.cwd();E=R/'tests/evidence/optimization/gen18/independent-review';B=E.parent
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
checks=[]
def check(ok,label):
 assert ok,label
 checks.append(label)
summary=read(B/'packing-proof/summary.json');check(summary['status']=='passed','packing targeted build passed')
for p,h in summary['sources'].items():check(sha(R/p)==h,'stable '+p)
log=B/'packing-proof/attempt-02/build.log';check(sha(log)==summary['build_log_sha256'],'successful packing build log')
record=read(B/'packing-proof/attempt-02/result.json');check(record['exit_code']==0 and record['inputs_before']==record['inputs_after'],'packing build preserved inputs')
facts={}
for name,ax,empty in re.findall(r"'([^']+)' (?:depends on axioms: \[([^\]]*)\]|(does not depend on any axioms))",log.read_text()):
 vals=[] if empty else [v.strip() for v in ax.split(',') if v.strip()];check(set(vals)<={'propext','Classical.choice','Quot.sound'},'allowed axioms '+name);facts[name]=vals
check(sum('CPRFloatFast.' in p for p in facts)==10,'ten packing facts printed')
check(sum('cpr' in p.rsplit('.',1)[-1] for p in facts)>=10,'tracking facts printed')
old=subprocess.check_output(['git','show','HEAD:Impl/CPRFloat.lean'],text=True)
new=(R/'Impl/CPRFloat.lean').read_text()
start=old.index('def toFloat ');end=old.index('/-- rs1090 cpr.rs `haversine`')
new_start=new.index('def toFloatFallback ');new_end=new.index('/-- Exact bit assembly')
check(new[new_start:new_end].replace('def toFloatFallback ','def toFloat ',1)==old[start:end],'original conversion body unchanged after rename')
check(new[:new_start]==old[:start] and new[new.index('/-- rs1090 cpr.rs `haversine`'):]==old[end:],'all other runtime source bytes unchanged')
proof=(R/'Proofs/CPRFloatFast.lean').read_text();tracking=(R/'Proofs/CPRTracking.lean').read_text();prior=(B/'packing-proof/before-CPRTracking.lean').read_text()
def statements(text):return {name:re.sub(r'\s+',' ',typ).strip() for name,typ in re.findall(r'^(?:private )?theorem (\w+)([\s\S]*?):=',text,re.M)}
a,z=statements(prior),statements(tracking);check(a==z,'all existing tracking theorem signatures unchanged')
check('CPRFloatFast.toFloat_function_eq' in tracking,'tracking uses unconditional live conversion theorem')
check('theorem toFloat_eq (value : Rat)' in proof and 'Impl.CPR.Policy.toFloat value = Spec.CPR.Policy.toFloat value' in proof,'public refinement has only arbitrary Rat parameter')
check('theorem toFloat_function_eq : Impl.CPR.Policy.toFloat = Spec.CPR.Policy.toFloat' in proof,'function equality is universal')
check(proof.count('decide +kernel')==5,'five nonzero boundary/rejection/underflow kernel groups')
for name in ['zero_witness','min_subnormal_witness','subnormal_normal_boundary_witness','largest_small_numerator_witness','guard_rejection_witness','underflow_witness']:check(name in z or name in statements(proof),'boundary '+name)
locked=[l.split('  ',1) for l in (R/'spec.lock').read_text().splitlines()];check(len(locked)==104 and all(sha(R/p)==h for h,p in locked),'all frozen members unchanged')
central=B/'dyadic-proof/root-independent-review.json';check(read(central)['status'].startswith('passed'),'parent independently reviewed central authored theorem')
paths=[R/'Impl/CPRFloat.lean',R/'Proofs/CPRFloatFast.lean',R/'Proofs/CPRTracking.lean',R/'Proofs/Binary64Dyadic.lean',R/'Spec/CPRFloat.lean',R/'Spec/Binary64.lean',B/'packing-proof/summary.json',B/'packing-proof/attempt-02/result.json',log,B/'packing-proof/attempt-01/result.json',B/'packing-proof/attempt-01/build.log',central,Path(__file__),E/'check_source-attempt-01.py',E/'source-review-01.log']
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'bindings':{str(p.relative_to(R)):sha(p) for p in paths},'checks':checks,'printed_facts':facts,'tracking_statement_count':len(a),'mathematical_review':[
'Guard zero is separated before magnitude/log computation and returns positive zero. Nonzero numerator magnitude below 2^53 implies high at most52; exact denominator2^k and k at most1074 bound all shifts.',
'Packing proof replaces software rounding by the central exact-round theorem, derives exact binade from numerator log2 minus denominator exponent, and uses integer scaled quantum with floor to justify both subnormal and normal bit formulas.',
'Sign equality follows canonical Rat numerator sign. Unbounded Nat arithmetic preserves exact sign/exponent/fraction additions and saturating subtraction in the same order as the reference before UInt64 conversion.',
'Outside the guard, fallback_eq preserves the complete original software round/exponent/quantum program, including signed underflow collapsing to positive zero. No hardware Float arithmetic or new semantic axiom is introduced.',
'Public equality is for every Rat. It proves the same Float program result by equal bit construction and unchanged fallback, not real-number accuracy of transcendental geography.'],
'authorship_limit':'Binary64Dyadic was authored by this reviewer and is not independently assessed here; parent root-independent-review.json supplies its independent review.',
'limits':['Native inspection and full fixed/fresh gates are separate pending steps. No build or decoder invoked by this checker.']}
p=E/'source-proof-review.json';check(not p.exists(),'no prior source review overwritten');p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(p),'checks':len(checks)}))
