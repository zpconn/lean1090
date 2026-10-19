#!/usr/bin/env python3
"""Independent read-only/disposable-input review; never archive or time a run."""
import copy
import csv
from datetime import datetime, timezone
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import shutil
import sys
import tempfile

sys.dont_write_bytecode = True
ROOT = Path.cwd()
OUT = ROOT/'tests/evidence/optimization/gen9/benchmark-archiver-review'
TOOL = ROOT/'review/diagnostics/archive_generation_benchmark.py'
PLAN = ROOT/'tests/evidence/optimization/gen9/benchmark-preparation/plan.json'
SOURCE = ROOT/'.cache/bench-runs/gen8-78286f1'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    sys.path.insert(0, str(TOOL.parent))
    spec = importlib.util.spec_from_file_location('archive_review_final', TOOL)
    mod = importlib.util.module_from_spec(spec); spec.loader.exec_module(mod)
    initial = mod.inventory(SOURCE)
    preserved = {str(p): sha(p) for p in (TOOL, PLAN, ROOT/'bench/results.csv', ROOT/'spec.lock')}
    plan = json.loads(PLAN.read_text())
    prior = ROOT/plan['prior_csv_snapshot']
    assert sha(prior) == plan['prior_csv_sha256'] == sha(ROOT/'bench/results.csv')
    rows = mod.parse_prior_csv(prior.read_bytes(), 9)
    assert len(rows) == plan['prior_csv_rows'] == 18
    assert sha(ROOT/plan['fresh_verification']) == plan['fresh_verification_sha256']
    data = mod.validate_source(SOURCE, 8)
    assert len(data['source_files']) == 48 and len(mod.COMMAND_LOGS) == 14
    cases = []
    with tempfile.TemporaryDirectory(prefix='lean1090-archive-review-final-') as temp:
        target = Path(temp)/'run'

        def reset():
            if target.exists(): shutil.rmtree(target)
            shutil.copytree(SOURCE, target)

        def reject(name, mutate):
            reset(); mutate(target)
            try:
                mod.validate_source(target, 8)
            except (RuntimeError, KeyError, ValueError) as error:
                cases.append({'case':name,'rejected':True,'error':str(error)})
            else:
                raise AssertionError('accepted invalid fixture: '+name)

        def change_json(base, name, edit):
            path=base/name; value=json.loads(path.read_text());edit(value);path.write_text(json.dumps(value))

        for name in sorted(mod.ORIGINAL_FILES):
            reject('missing:'+name, lambda base,n=name:(base/n).unlink())
        reject('reserved archive-verification addition', lambda p:(p/'archive-verification.json').write_text('{}'))
        reject('wrong fresh source digest', lambda p:change_json(p,'fresh-native-inputs.json',lambda v:v[0].update(source_sha256='0'*64)))
        reject('duplicate fresh source row', lambda p:change_json(p,'fresh-native-inputs.json',lambda v:v.__setitem__(1,copy.deepcopy(v[0]))))
        reject('foreign native artifact', lambda p:change_json(p,'fresh-native-inputs.json',lambda v:v[0]['artifacts'].update({'foreign.o':{'sha256':'0'*64}})))
        reject('wrong build lock', lambda p:change_json(p,'binary-built.json',lambda v:v.update(spec_lock_sha256='0'*64)))
        reject('changed provenance script', lambda p:(p/'provenance-scripts/run_generation_benchmark.py').write_text('# changed\n'))
        reject('failed command', lambda p:change_json(p,'commands.json',lambda v:v[0].update(exit_code=1)))
        reject('duplicate command', lambda p:change_json(p,'commands.json',lambda v:v.__setitem__(1,copy.deepcopy(v[0]))))
        reject('incomplete status', lambda p:change_json(p,'status.json',lambda v:v.update(status='in-progress')))
        reject('wrong summary ratio', lambda p:change_json(p,'summary.json',lambda v:v['results'][0].update(lean_over_rust=9)))
        reject('missing measured sample', lambda p:(p/'decode/samples.csv').write_text('\n'.join((p/'decode/samples.csv').read_text().splitlines()[:-1])+'\n'))
        reject('wrong power plan', lambda p:change_json(p,'decode/metadata.json',lambda v:v['windows_power_plan_after'].update(scheme_guid='changed')))
    raw=prior.read_bytes()
    csv_cases=[]
    for name,value in [('header order',raw.replace(b'commit,generation',b'generation,commit',1)),('missing final newline',raw.rstrip(b'\r\n')),('missing row',b'\n'.join(raw.split(b'\n')[:-2])+b'\n')]:
        try:mod.parse_prior_csv(value,9)
        except (RuntimeError,ValueError,KeyError) as error:csv_cases.append({'case':name,'rejected':True,'error':str(error)})
        else:raise AssertionError(name)
    # Exercise the actual report's stop branch using synthetic median values.
    # These cases are not measurements and no rendered text is saved as a result.
    threshold=[]
    old_rows=[r for r in rows if int(r['generation'])<8]
    fresh=json.loads((ROOT/plan['fresh_verification']).read_text())
    fixture_plan={**plan,'generation':8}
    for label,rust,lean,expected in [('below',1099,1000,False),('exact',1100,1000,True),('above',1101,1000,True)]:
        fixture=copy.deepcopy(data)
        fixture['results'][0]['medians_nanoseconds']={'rs1090':rust,'lean1090':lean}
        fixture['results'][0]['lean_over_rust']=rust/lean
        text=mod.report_text(fixture_plan,fixture,SOURCE,old_rows,fresh)
        actual='The 1.10× decode threshold is reached.' in text
        assert actual==expected
        threshold.append({'synthetic_case':label,'rust_ns':rust,'lean_ns':lean,'stop':actual})
    assert mod.inventory(SOURCE)==initial
    assert all(sha(p)==digest for p,digest in preserved.items())
    assert not (ROOT/'bench/runs/gen9').exists() and not (ROOT/'bench/GEN9.md').exists()
    report={'status':'passed','completed_utc':datetime.now(timezone.utc).isoformat(),
            'helper_sha256':sha(TOOL),'plan_sha256':sha(PLAN),'checker_sha256':sha(__file__),
            'read_only_real_run':{'generation':8,'original_files':48,'results':data['results']},
            'negative_controls':cases,'csv_negative_controls':csv_cases,'threshold_synthetic_controls':threshold,
            'prior_csv':{'bytes':len(raw),'rows':18,'sha256':sha(prior),'current_exact_byte_match':True},
            'source_originals_and_csv_lock_unchanged':True,'no_gen9_results_created':True,
            'static_review':{'writes_only_after_validation':True,'all_48_originals_copied_and_rehashed':True,
                            'exact_old_CSV_bytes_retained_and_two_rows_appended':True,
                            'integer_median_threshold_correct':True,'partial_failure_policy':'Partial output is retained; existing archive/report reject retries. Final success is emitted only after source/copy/CSV/report checks. A failure after copy can leave partial output and requires manual review.',
                            'no_runtime_frozen_edits_build_or_decoder_execution':True},
            'findings_remaining':[]}
    (OUT/'review.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'status':'passed','negative_controls':len(cases)+len(csv_cases),'threshold_cases':len(threshold),'helper_sha256':sha(TOOL),'review_sha256':sha(OUT/'review.json')}))


if __name__=='__main__':main()
