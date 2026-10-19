"""Read-only independent target reporting checks; no measurement or build."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,hashlib,importlib.util,json,subprocess

E=Path('tests/evidence/optimization/dual-target-reporting')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def load(name,path):
    spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m);return m
sys.path.insert(0,str(Path('review/diagnostics').resolve()))
current=Path('review/diagnostics/archive_generation_benchmark_target.py')
before=E/'before.py';m=load('dual_current',current);old=load('dual_previous',before)
validation=read(E/'validation-final.json')
for path,digest in validation['files'].items():assert sha(path)==digest,path
old_ast={n.name:ast.dump(n,include_attributes=False) for n in ast.parse(before.read_text()).body if isinstance(n,ast.FunctionDef)}
new_ast={n.name:ast.dump(n,include_attributes=False) for n in ast.parse(current.read_text()).body if isinstance(n,ast.FunctionDef)}
changed={'target_ratio','target_label','decode_threshold_reached','report_text','main'}
unchanged=[]
for name,node in old_ast.items():
    if name not in changed:assert new_ast[name]==node,name;unchanged.append(name)
assert set(new_ast)-set(old_ast)=={'mode_threshold_reached','target_decisions','reporting_targets'}
assert {'validate_source','inventory','parse_prior_csv'}<=set(unchanged)
checks=0
targets=[(1,1),(11,10),(3,2),(2,1),(7,3),(2**100+3,2**99+1)]
values=[1,3,7,100,2**100+7]
for dn,dd in targets:
    for cn,cd in targets:
        plan={'decode_target_ratio':{'numerator':dn,'denominator':dd},'cpr_target_ratio':{'numerator':cn,'denominator':cd}}
        for lean in values:
            for ddelta in [-1,0,1]:
                for cdelta in [-1,0,1]:
                    dr=max(1,lean*dn//dd+ddelta);cr=max(1,lean*cn//cd+cdelta)
                    rows=[{'mode':'decode','medians_nanoseconds':{'rs1090':dr,'lean1090':lean}},
                          {'mode':'cpr','medians_nanoseconds':{'rs1090':cr,'lean1090':lean}}]
                    decisions={'decode':dr*dd>=lean*dn,'cpr':cr*cd>=lean*cn}
                    for order in [rows,rows[::-1]]:
                        fields,reached=m.reporting_targets(plan,order)
                        assert fields['decode_threshold_reached']==decisions['decode']
                        assert fields['cpr_threshold_reached']==decisions['cpr']
                        assert reached==fields['all_mode_thresholds_reached']==all(decisions.values())
                        checks+=1
for plan in [{},{'decode_target_ratio':{'numerator':3,'denominator':2}}]:
    for lean in values:
        for rust in values:
            rows=[{'mode':'decode','medians_nanoseconds':{'rs1090':rust,'lean1090':lean}},
                  {'mode':'cpr','medians_nanoseconds':{'rs1090':1,'lean1090':10**100}}]
            fields,reached=m.reporting_targets(plan,rows)
            assert reached==old.decode_threshold_reached(plan,rows[0])
            assert set(fields)=={'decode_target_ratio','decode_threshold_reached'}
            checks+=1
for bad in [True,False,0,-1,1.0,'2',None]:
    for mode in ['decode','cpr']:
        for side in ['numerator','denominator']:
            plan={name+'_target_ratio':{'numerator':2,'denominator':1} for name in ['decode','cpr']}
            plan[mode+'_target_ratio'][side]=bad
            try:m.reporting_targets(plan,[{'mode':name,'medians_nanoseconds':{'rs1090':200,'lean1090':100}} for name in ['decode','cpr']])
            except RuntimeError:pass
            else:raise AssertionError((mode,side,bad))
            checks+=1
test=Path('review/diagnostics/test_benchmark_targets.py')
assert '.cache/bench-runs/gen15-e659220' not in test.read_text()
log=E/'independent-tests.log';assert not log.exists()
r=subprocess.run([sys.executable,'-B',str(test)],capture_output=True);log.write_bytes(r.stdout+r.stderr)
assert r.returncode==0
gate=read('tests/evidence/optimization/gen15/gate-evidence.json')
before_inputs=gate['source_hashes_before'] if 'source_hashes_before' in gate else None
# Use the benchmark's exact correctness inventory, already bound to the gate.
inputs=read('bench/runs/gen15/correctness-inputs.json')
assert len(inputs)==186
for path,digest in inputs.items():assert sha(path)==digest,path
assert sha('bench/GEN15.md')=='64b40fc4a9f18233dfba5b20ae1165c5f74bd9cc47f3ba5bc4568491fdbd031c'
assert sha(before)==read('bench/runs/gen15/report-verification.json')['helper_sha256']
result={'status':'passed','checked_utc':datetime.now(timezone.utc).isoformat(),'findings':[],
    'independent_exact_decision_cases':checks,'author_fixture_replay_exit_code':r.returncode,
    'unchanged_original_function_ASTs':unchanged,'unchanged_correctness_inputs':len(inputs),
    'helper_sha256':sha(current),'previous_helper_sha256':sha(before),'test_sha256':sha(test),
    'validation_final_sha256':sha(E/'validation-final.json'),'independent_test_log_sha256':sha(log),
    'historical_report_sha256':sha('bench/GEN15.md'),'review_script_sha256':sha(__file__),
    'assessment':['Both thresholds use inclusive exact integer cross multiplication independently; the joint decision is a conjunction, never an average.',
        'Only the presence of an explicit CPR target enables the second requirement; historical decode-only decisions and report bytes remain unchanged.',
        'Measurement, validation, hashing, archive-copy and CSV-prefix checks outside reporting functions retain identical ASTs.',
        'Durable fixture reconstructs the original 48 files from the committed archive in a temporary directory, without requiring ignored benchmark caches.'],
    'limits':'Reporting/fixture execution only; no benchmark, compiler, decoder, profiler or frozen-file change.'}
out=E/'independent-review.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','checks':checks,'sha256':sha(out)}))
