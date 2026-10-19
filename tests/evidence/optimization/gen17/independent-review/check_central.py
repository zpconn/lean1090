#!/usr/bin/env python3
"""Independent read-only source/proof assessment of central powerTwo table."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen17/independent-review');I=R.parent/'implementation'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
summary=read(I/'summary.json');build=read(I/'build-02.json');before=read(I/'before.json')
assert summary['status']=='passed' and build['exit_code']==0 and build['sources_before']==build['sources_after']==summary['sources']
assert sha(I/'build-02.json')==summary['build_record_sha256'] and sha(I/'build-02.log')==summary['log_sha256']==build['log_sha256']
for p,h in summary['sources'].items():assert sha(p)==h
for p,item in before['files'].items():
 assert sha(item['snapshot'])==item['sha256']
 if p!='Impl/Binary64.lean':assert sha(p)==item['sha256']
source=Path('Impl/Binary64.lean').read_text();old=Path(before['files']['Impl/Binary64.lean']['snapshot']).read_text();proof=Path('Proofs/Binary64Runtime.lean').read_text()
marker='/-- Rust f64, arithmetic nearest/ties-even:'
assert source[source.index(marker):]==old[old.index(marker):]
formula='  if exponent < 0 then 1 / (2 ^ exponent.natAbs : Nat)\n  else (2 ^ exponent.toNat : Nat)'
assert formula in source and formula in old
assert re.findall(r'^import (.*)$',source,re.M)==['Std']
assert 'Array.ofFn fun code : Fin 2098 =>' in source and 'powerTwoFormula ((code.val : Int) - 1074)' in source
constructor=source[source.index('def powerTwoTable'):source.index('/-- Rust f64, `MANTISSA_DIGITS`, `MIN_EXP`: exact integer powers of two.',source.index('def powerTwoTable'))]
assert constructor.count('powerTwoFormula')==1 and not re.search(r'\b(powerTwo|round|literal|add|mul|div|sub)\s*\(',constructor)
assert 'if h : -1074 ≤ exponent ∧ exponent ≤ 1023 then' in source
assert "powerTwoTable[(exponent + 1074).toNat]'" in source and 'else powerTwoFormula exponent' in source
assert 'theorem powerTwo_eq (e : Int) :' in proof and 'Impl.Binary64.powerTwo e = Spec.Binary64.powerTwo e' in proof
assert 'have index : ((e + 1074).toNat : Int) - 1074 = e := by omega' in proof
assert 'Array.getElem_ofFn, powerTwoFormula_eq, index' in proof
facts=[]
for name,ax,empty in re.findall(r"'(Lean1090\.Proofs\.Binary64Runtime\.[^']+)' (?:depends on axioms: \[([^\]]*)\]|(does not depend on any axioms))",(I/'build-02.log').read_text()):
 axioms=[] if empty else [s.strip() for s in ax.split(',') if s.strip()];assert set(axioms)<={'propext','Classical.choice','Quot.sound'};facts.append({'name':name,'axioms':axioms})
assert facts==summary['printed_axiom_facts'] and len(facts)==32
assert {x['name'].split('.')[-1] for x in facts}==set(re.findall(r'^#print axioms (\w+)$',proof,re.M))
assert proof.count('decide +kernel')==5
for token in ['sorry','admit','native_decide','unsafe','partial','panic!','get!','unreachable!','@[implemented_by]','@[extern]']:
 assert not re.search(r'\b'+re.escape(token)+r'\b',source+'\n'+proof),token
for row in summary['retained_attempts']:
 assert sha(I/row['record'])==row['sha256'];attempt=read(I/row['record']);assert attempt['exit_code']!=0 and attempt['sources_before']['Impl/Binary64.lean']==summary['sources']['Impl/Binary64.lean']
 assert sha(I/(row['record'].removesuffix('.json')+'.log'))==row['log_sha256']
# All frozen adapters remain byte-bound; actual native paths await final build.
lock=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()];assert len(lock)==104
for h,p in lock:assert sha(p)==h
paths=['Tests/Numeric.lean','Tests/Tracking.lean','Tests/CommBDifferential.lean','Impl/Numeric.lean','Impl/CPRFloat.lean']
for p in paths:assert Path(p).read_bytes()==subprocess.check_output(['git','show','HEAD:'+p])
result={'status':'passed_source_and_helper_proof','recorded_utc':datetime.now(timezone.utc).isoformat(),'sources':summary['sources'],'build_record_sha256':sha(I/'build-02.json'),'build_log_sha256':sha(I/'build-02.log'),'implementation_summary_sha256':sha(I/'summary.json'),'printed_axiom_fact_count':32,'facts':facts,'all_integer_exponents':True,'table_entries':2098,'kernel_witnesses':5,'witness_exponents':[-1075,-1074,-1,0,1,1023,1024],'locked_files_unchanged':104,'unchanged_live_adapter_source_hashes':{p:sha(p) for p in paths},'mathematical_assessment':['Within the guard, e+1074 is nonnegative and below2098; converting to Nat then back and subtracting1074 recovers arbitrary e. Array.ofFn lookup therefore reduces to the exact original formula.','The false guard directly uses the original total formula. No bounded-word, finite-range, acceptance or corpus hypothesis appears in the universal equality.','Every remaining Binary64 definition is byte-identical; operation/function equalities propagate exact power equality without reassociation or weakened domains.','Constructor depends only on the original exact formula and Rat arithmetic, so it cannot recurse through the lookup. The raw formula is live construction/fallback code.'],'findings':[],'pending':['Integrated dependent proof build/axioms.','Actual linked table startup mode and live lookup/fallback callsites after final native build.','Full fixed/fresh gates and subsequent isolated benchmarks.'],'limits':['This is source and successful helper-proof log review, not execution or a claim of eager linked initialization.','No build, test, generator or decoder workload was run by reviewer.'],'checker_sha256':sha(__file__)}
p=R/'central-source-proof-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':result['status'],'sha256':sha(p),'facts':32,'findings':[]}))
