#!/usr/bin/env python3
"""Read-only CPR bridge type, proof-source and executed-build review."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, re, subprocess

B=Path('tests/evidence/optimization/gen17')
OUT=B/'independent-review/cpr-bridge-review.json'
assert not OUT.exists()
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
source=Path('Proofs/CPRTracking.lean').read_text()
before=(B/'cpr-proof/before.lean').read_text()
assert before.encode()==subprocess.check_output(['git','show','HEAD:Proofs/CPRTracking.lean'])
def declarations(s):
    return {n:re.sub(r'\s+',' ',ty).strip() for n,ty in
            re.findall(r'^theorem (\w+)([\s\S]*?):=',s,re.M)}
old,new=declarations(before),declarations(source)
assert len(old)==5 and len(new)==10
assert all(new[n]==ty for n,ty in old.items())
expected={'cprStreamStepRefinement','CPRTrackingRefinement','cprUpdateGlobalReferenceRefinement',
          'cprLocalRefinement','cprGlobalRefinement','cprToFloatRefinement',
          'cprDistanceFromFloatRefinement','cprLocalFloatRefinement',
          'cprGlobalFloatRefinement','cprNumericalGeographyRefinement'}
assert set(new)==expected==set(re.findall(r'^#print axioms (\w+)$',source,re.M))
assert new['CPRTrackingRefinement']==': Capstones.CPRTrackingRefinement Impl.decodePositions'
assert new['cprNumericalGeographyRefinement']==': @Impl.CPR.Policy.numericalGeography = @Spec.CPR.Policy.numericalGeography'
assert 'intro geography update reference reports' in source
assert 'This adds no real-arithmetic guarantee for opaque Float operations.' in source
assert 'sorry' not in source and 'native_decide' not in source and 'axiom ' not in source
passed=load(B/'cpr-proof/attempt-02/result.json')
failed=load(B/'cpr-proof/attempt-01/result.json')
assert passed['status']=='passed' and passed['exit_code']==0
assert failed['status']=='failed' and failed['exit_code']!=0
for attempt,record in [('attempt-01',failed),('attempt-02',passed)]:
    folder=B/'cpr-proof'/attempt
    assert sha(folder/'build.log')==record['log_sha256']
    assert record['inputs_before']==record['inputs_after'] and record['inputs_unchanged']
    for n,h in record['inputs_before'].items():
        assert sha(folder/n.replace('/','__'))==h
for n,h in passed['inputs_after'].items(): assert sha(n)==h
log=(B/'cpr-proof/attempt-02/build.log').read_text()
printed={n:sorted(x.strip() for x in v.split(',') if x.strip()) for n,v in
         re.findall(r"'Lean1090.Proofs.([^']+)' depends on axioms:\s*\[([^\]]*)\]",log)}
facts={n:printed[n] for n in expected}
assert all(set(v)<={'propext','Classical.choice','Quot.sound'} for v in facts.values())
assert facts['cprLocalRefinement']==facts['cprGlobalRefinement']==[]
integration=load(B/'integration/targeted-build.json')
assert integration['status']=='passed' and integration['exit_code']==0
assert integration['inputs_before']==integration['inputs_after']
assert integration['inputs_after']['Proofs/CPRTracking.lean']==sha('Proofs/CPRTracking.lean')
assert sha(B/'integration/targeted-build.log')==integration['log_sha256']
for n in ['Impl/CPRPolicy.lean','Impl/CPRFloat.lean']:
    assert Path(n).read_bytes()==subprocess.check_output(['git','show','HEAD:'+n])
for h,n in [line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()]:assert sha(n)==h
bindings={str(p):sha(p) for p in [Path('Proofs/CPRTracking.lean'),Path('Proofs/Binary64Runtime.lean'),
    Path('Impl/Binary64.lean'),Path('Impl/CPRPolicy.lean'),Path('Impl/CPRFloat.lean'),Path('Capstones.lean'),Path('spec.lock'),
    B/'cpr-proof/before.lean',B/'cpr-proof/attempt-01/result.json',B/'cpr-proof/attempt-01/build.log',
    B/'cpr-proof/attempt-02/result.json',B/'cpr-proof/attempt-02/build.log',B/'integration/targeted-build.json',
    B/'integration/targeted-build.log',B/'independent-review/central-source-proof-review.json']}
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],
    'script_sha256':sha(__file__),'preserved_existing_statements':old,'all_public_statements':new,
    'printed_axioms':facts,'all_ten_facts_allowed':True,'locked_files_unchanged':104,'bindings':bindings,
    'review':[
      'Exact speed/motion/airborne/step/streamStep equalities substitute unconditional binary64 bridges. No geography, callback, reference, report, state or numeric range hypothesis was added.',
      'The frozen tracking contract still compares complete final StreamState and complete position list for every geography and callback.',
      'toFloat, Float-distance interpretation and position conversion preserve the same Float programs, including exceptional-value branches; Float arithmetic receives no mathematical interpretation.',
      'Whole numericalGeography equality follows component function congruence and unchanged haversine Float expressions. It proves program equality, not geographic accuracy of opaque Float operations.',
      'Initial CPR helper build failure is preserved. Final source only resolves definitional record/constructor equality; final targeted and combined builds pass.'],
    'limits':'Source/type and retained build/axiom review only; no build, native decoder, Float validation or test rerun.'}
OUT.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','review_sha256':sha(OUT),'printed_facts':len(facts)}))
