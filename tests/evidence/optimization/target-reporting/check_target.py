#!/usr/bin/env python3
"""Pure/report validation only: never run a worker or write benchmark results."""
from pathlib import Path
from datetime import datetime, timezone
import ast
import copy
import hashlib
import importlib.util
import json
import sys

sys.dont_write_bytecode = True
ROOT = Path.cwd()
OUT = ROOT / 'tests/evidence/optimization/target-reporting'
OLD = ROOT / 'review/diagnostics/archive_generation_benchmark.py'
NEW = OLD.with_name('archive_generation_benchmark_target.py')
SOURCE = ROOT / '.cache/bench-runs/gen10-d51a304'
PLAN = ROOT / 'tests/evidence/optimization/gen10/benchmark-preparation/plan.json'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def main():
    sys.path.insert(0, str(OLD.parent))
    old, new = module(OLD, 'old_archiver'), module(NEW, 'new_archiver')
    preserved = {str(p): sha(p) for p in (OLD, ROOT/'bench/results.csv', ROOT/'spec.lock', PLAN)}
    assert preserved[str(OLD)] == '93b0baeb43c9ebaad442d9feae9a1d46b81b7de8552d98fac864d5e938fc43a7'
    trees = [{node.name: ast.dump(node, include_attributes=False) for node in ast.parse(p.read_text()).body if isinstance(node, ast.FunctionDef)} for p in (OLD, NEW)]
    unchanged = sorted(set(trees[0]) - {'report_text', 'main'})
    assert all(trees[0][name] == trees[1][name] for name in unchanged)
    assert old.ORIGINAL_FILES == new.ORIGINAL_FILES and old.COMMAND_LOGS == new.COMMAND_LOGS
    original_files = old.inventory(SOURCE)
    data = new.validate_source(SOURCE, 10)
    assert len(data['source_files']) == 48
    plan = json.loads(PLAN.read_text())
    rows = new.parse_prior_csv((ROOT/plan['prior_csv_snapshot']).read_bytes(), 10)
    fresh = json.loads((ROOT/plan['fresh_verification']).read_text())
    assert 'decode_target_ratio' not in plan
    default_text = new.report_text(plan, data, SOURCE, rows, fresh)
    assert default_text == old.report_text(plan, data, SOURCE, rows, fresh)
    threshold_cases = []
    for target, label, lean, center in [({}, '1.10', 1000, 1100), ({'numerator':3,'denominator':2}, '1.50', 1000, 1500), ({'numerator':6,'denominator':4}, '1.50', 1000, 1500), ({'numerator':1,'denominator':3}, '1/3', 3000, 1000), ({'numerator':3,'denominator':2}, '1.50', 2**100, 3*2**99)]:
        case_plan = copy.deepcopy(plan)
        if target:
            case_plan['decode_target_ratio'] = target
        for delta in [-1, 0, 1]:
            fixture = copy.deepcopy(data)
            fixture['results'][0]['medians_nanoseconds'] = {'rs1090': center+delta, 'lean1090': lean}
            fixture['results'][0]['lean_over_rust'] = (center+delta)/lean
            expected = delta >= 0
            assert new.decode_threshold_reached(case_plan, fixture['results'][0]) == expected
            text = new.report_text(case_plan, fixture, SOURCE, rows, fresh)
            assert (f'The {label}× decode threshold is reached.' in text) == expected
            assert (f'The {label}× decode threshold remains unmet.' in text) != expected
            threshold_cases.append({'target':target or {'numerator':11,'denominator':10},'lean_ns':lean,'rust_ns':center+delta,'reached':expected,'label':label})
    malformed = [None, 1, 1.5, True, '3/2', [], {}, {'numerator':3}, {'denominator':2}, {'numerator':3,'denominator':2,'extra':1}]
    malformed += [{'numerator':x,'denominator':2} for x in [True,False,0,-1,1.5,'3',None,[]]]
    malformed += [{'numerator':3,'denominator':x} for x in [True,False,0,-1,2.0,'2',None,{}]]
    rejected = []
    for ratio in malformed:
        try:
            new.target_ratio({'decode_target_ratio':ratio})
        except RuntimeError as error:
            rejected.append({'value':ratio,'error':str(error)})
        else:
            raise AssertionError(('malformed ratio accepted',ratio))
    median_rejections = []
    for medians in [{'rs1090':1.5,'lean1090':1},{'rs1090':1,'lean1090':True},{'rs1090':0,'lean1090':1},{'rs1090':1,'lean1090':-1}]:
        try:
            new.decode_threshold_reached({}, {'medians_nanoseconds':medians})
        except RuntimeError as error:
            median_rejections.append({'medians':medians,'error':str(error)})
        else:
            raise AssertionError(('invalid median accepted',medians))
    assert old.inventory(SOURCE) == original_files
    assert all(sha(p) == digest for p,digest in preserved.items())
    result = {'status':'passed','completed_utc':datetime.now(timezone.utc).isoformat(),'old_helper_sha256':sha(OLD),'new_helper_sha256':sha(NEW),'checker_sha256':sha(__file__),'unchanged_function_ASTs':unchanged,'original_48_file_inventory_and_command_guards_unchanged':True,'real_gen10_validation_passed':True,'historical_default_report_byte_identical':True,'threshold_cases':threshold_cases,'malformed_ratio_rejections':rejected,'invalid_median_rejections':median_rejections,'original_source_records_csv_lock_unchanged':True,'no_worker_build_profile_or_benchmark_execution':True,'no_results_written':True}
    (OUT/'checks.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'status':'passed','threshold_cases':len(threshold_cases),'malformed_ratio_rejections':len(rejected),'invalid_median_rejections':len(median_rejections),'new_helper_sha256':sha(NEW),'checks_sha256':sha(OUT/'checks.json')},indent=2))


if __name__ == '__main__':
    main()
