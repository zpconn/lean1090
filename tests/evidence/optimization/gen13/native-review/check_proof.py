#!/usr/bin/env python3
"""Independent source/axiom/log binding; no Lean or decoder execution."""
from pathlib import Path
import hashlib,json,re,subprocess
O=Path(__file__).resolve().parent; B=O.parent/'proof'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
assert not (O/'source-proof-review.json').exists()
s=load(B/'summary.json');b=load(B/'build-01.json');log=(B/'build-01.log').read_text()
assert s['status']=='passed' and len(s['attempts'])==1 and b['exit_code']==0
assert b['sources_before']==b['sources_after']==s['sources']
assert all(sha(p)==h for p,h in s['sources'].items())
assert sha(B/'build-01.log')==b['log_sha256']==s['attempts'][0]['log_sha256']
assert sha(B/'build-01.json')==s['attempts'][0]['sha256']
assert 'Build completed successfully (777 jobs).' in log
source=Path('Impl/CommB.lean').read_text();proof=Path('Proofs/CommBPenalty.lean').read_text();old=(B/'before-Impl-CommB.lean').read_text()
assert subprocess.check_output(['git','show','HEAD:Impl/CommB.lean']).decode()==old
insertion='/-- Every signed difference of the two unsigned ten-bit BDS50 speed codes.'
old_boundary='-- Initial algorithm: Spec/CommB.lean:409.'
assert source.split(insertion)[0]==old.split(old_boundary)[0]
tail='    match value "roll", value "track_rate" with'
assert source.split(tail,1)[1]==old.split(tail,1)[1]
old_wind='''    let p := match value "TAS", value "groundspeed" with
      | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
      | _, _ => 0'''
new_tail=source.split(old_boundary,1)[1]
assert new_tail==old.split(old_boundary,1)[1].replace(old_wind,'    let p := cbWindPenalty50 word')
assert all(x in source for x in ['Array.ofFn fun code : Fin 2047 =>','Binary64.div (Binary64.round (2 * ((code.val : Rat) - 1023))).abs 100','if payloadBits word 46 1 == 0 || payloadBits word 24 1 == 0 then 0',"cbWindPenaltyTable[tas + 1023 - gs]'(by"])
assert not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)',proof)
assert 'theorem cbWindPenalty50_eq_runtime (word : Nat) :' in proof
assert 'theorem cbWindPenalty50_eq_raw (word : Nat) :' in proof
assert 'Nat.cast_sub (show gs ≤ tas + 1023 by omega)' in proof
assert 'Impl.payloadBits_lt word 47 10' in proof and 'Impl.payloadBits_lt word 25 10' in proof
assert 'AffineValue.affineValue_eq' in proof
facts=[{'theorem':name,'axioms':[x.strip() for x in ax.split(',') if x.strip()]} for name,ax in re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^]]*)\]|does not depend on any axioms)",log,re.S)]
allowed={'propext','Classical.choice','Quot.sound'}
assert facts and all(set(f['axioms'])<=allowed for f in facts)
facts=[f for f in facts if f['theorem'].startswith('Lean1090.Proofs.CommBPenalty.')]
assert len(facts)==11 and facts==s['axiom_facts']
assert proof.count('decide +kernel')==6 and s['kernel_witness_theorems']==6
paths=[Path(p) for p in s['sources']]+[B/n for n in ['summary.json','build-01.json','build-01.log','before-Impl-CommB.lean','runtime.diff']]
inputs={str(p):{'sha256':sha(p),'bytes':p.stat().st_size} for p in paths}
for p in paths:
 d=O/'proof-inputs'/p;d.parent.mkdir(parents=True,exist_ok=True);d.write_bytes(p.read_bytes())
out={'status':'passed','findings':[],'reviewer':'/root/cost_analysis; not the runtime/proof author','sources':s['sources'],'inputs':inputs,'helper_facts':facts,'kernel_witness_theorems':6,'all_Nat_runtime_equality_verified':True,'turn_penalty_and_BDS60_source_unchanged':True,'assessment':[
'The complete Array.ofFn table has 2,047 entries indexed by TAS code + 1,023 - ground-speed code. Each 10-bit extraction is bounded for every Nat word; signed_index establishes both the table bound and exact Rat difference, explicitly justifying Nat subtraction before casting.',
'The table retains round(2*(index-1023)), absolute value, software rounded division by 100 and software subtraction from zero. This is the original rounded TAS-minus-groundspeed expression after exact algebra, without assuming symmetry of rounding or replacing a rounded fraction with an exact rational.',
'The raw equality and semantic-field equality quantify every Nat word, with no validity, message-size, corpus or status hypothesis. The semantic proof unfolds the actual BDS50 layout, proves the affine field values through the existing universal affine theorem and checks both independent absent-status cases.',
'The only cbPenalty edit replaces the BDS50 local wind value with the live table helper. The entire turn-penalty and BDS60 suffix remains byte-for-byte unchanged; final Binary64.sub p 2 and IAS/Mach ratio operations remain.',
'Six kernel witness theorems cover both missing statuses, either missing status, equal speeds, a fractional result distinguishable from exact -1/50, both signed extreme code differences and an extra high bit at 130. They supplement the unconditional proof.',
'All eleven printed helper facts and all printed dependencies in the successful targeted log use only allowed axioms. This review binds that existing build and assesses its mathematical source; it does not claim an independent build or native execution.'
],'script_sha256':sha(__file__),'limits':'Static independent mathematical source assessment and replay of retained targeted-build evidence. Integrated refinement and actual native table initialization/call paths are checked separately after build release.'}
(O/'source-proof-review.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(O/'source-proof-review.json'),'facts':len(facts),'witnesses':6}))
