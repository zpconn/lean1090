"""Independent reporting-only review; reads old data and writes this scratch tree."""
import sys
sys.dont_write_bytecode = True
import ast
import csv
import hashlib
import json
from pathlib import Path
from fractions import Fraction
from datetime import datetime, timezone

E = Path(__file__).resolve().parent
ROOT = E.parents[1]

def sha(p):
    with p.open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()

def load(p):
    return json.loads(p.read_text())

candidate = E / 'archive_generation_benchmark_target.py'
original = ROOT / 'review/diagnostics/archive_generation_benchmark_target.py'
preparation, validation, render = [load(E / n) for n in
    ['preparation.json', 'validation.json', 'render-check.json']]
assert sha(candidate) == preparation['candidate_sha256'] == validation['helper_sha256'] == render['candidate_sha256']
assert sha(original) == preparation['source_sha256']
before = {str(original.relative_to(ROOT)): sha(original),
          'bench/GEN19.md': sha(ROOT / 'bench/GEN19.md'),
          'bench/results.csv': sha(ROOT / 'bench/results.csv'),
          'bench/interleave.py': sha(ROOT / 'bench/interleave.py'),
          'bench/BENCHMARK.md': sha(ROOT / 'bench/BENCHMARK.md'),
          'Bench/WholeDecoder.lean': sha(ROOT / 'Bench/WholeDecoder.lean'),
          **validation['source_sha256']}
s = candidate.read_text()
start, end = s.index('def cpr_overhead('), s.index('def report_text(')
restored = s[:start] + s[end:]
restored = restored.replace("    overhead = cpr_overhead(results)['implementations']\n", '')
paragraph = next(line for line in restored.splitlines(True) if line.startswith('CPR overhead is **'))
restored = restored.replace('\n' + paragraph, '')
restored = restored.replace("'cpr_overhead':cpr_overhead(data['results']),", '')
assert restored == original.read_text(), 'Every other validation/archive/target byte must remain exact'

# Execute only the isolated pure arithmetic function, not the reporting helper,
# its imports, main, archive operations, or the author's test code.
tree = ast.parse(s)
function = next(node for node in tree.body if isinstance(node, ast.FunctionDef) and node.name == 'cpr_overhead')
def require(condition, message):
    if not condition:
        raise RuntimeError(message)
namespace = {'COUNT': 172432, 'require': require}
exec(compile(ast.Module(body=[function], type_ignores=[]), str(candidate), 'exec'), namespace)
calculate = namespace['cpr_overhead']
def rows(a, b, c, d):
    return [{'mode': 'cpr', 'medians_nanoseconds': {'lean1090': b, 'rs1090': d}},
            {'mode': 'decode', 'medians_nanoseconds': {'lean1090': a, 'rs1090': c}}]

synthetic = []
for magnitude in [1, 2, 10**9, 2**53, 2**60, 2**100, 10**100]:
    for delta in [-1, 0, 1, 127]:
        a = magnitude + 2
        b = a + delta
        result = calculate(rows(a, b, b, a))
        for name, expected in [('lean1090', delta), ('rs1090', -delta)]:
            r = result['implementations'][name]
            exact = Fraction(expected, 172432000)
            assert r['difference_nanoseconds'] == expected
            assert r['microseconds_per_message_divisor'] == exact.denominator * (172432000 // exact.denominator)
            assert r['microseconds_per_message'] == float(exact)
        synthetic.append({'magnitude': magnitude, 'delta': delta})
rejections = []
cases = {'missing_mode': rows(1,2,1,2)[:1], 'duplicate_mode': [rows(1,2,1,2)[0]] * 2,
         'third_row': rows(1,2,1,2) + [rows(1,2,1,2)[0]],
         'unknown_mode': [{'mode':'wrong','medians_nanoseconds':{'lean1090':1,'rs1090':1}},rows(1,2,1,2)[1]]}
for value in [0, -1, 1.0, True, '1', None]:
    cases['bad_median_' + repr(value)] = rows(value, 1, 1, 1)
for label, data in cases.items():
    try:
        calculate(data)
    except RuntimeError:
        rejections.append(label)
    else:
        raise AssertionError(label)

structured = load(E / 'cpr-overhead.json')
assert len(structured['generations']) == 20
assert structured['source_sha256'] == validation['source_sha256']
total_rows, medians, negatives = 0, 0, []
for record in structured['generations']:
    generation = record['generation']
    base = ROOT / 'bench/runs' / ('baseline-FC006' if generation == 0 else f'gen{generation}')
    summary = load(base / 'summary.json')
    assert record['summary_sha256'] == sha(base / 'summary.json')
    assert record['recorded_commit'] == summary['commit']
    recomputed = {}
    for mode in ['decode', 'cpr']:
        with (base / mode / 'samples.csv').open() as f:
            sample_rows = list(csv.DictReader(f))
        assert len(sample_rows) == 48
        total_rows += len(sample_rows)
        result = next(row for row in summary['results'] if row['mode'] == mode)
        assert sha(base / mode / 'samples.csv') == result['samples_sha256']
        assert all(int(row['messages']) == 172432 and int(row['nanoseconds']) > 0 for row in sample_rows)
        for name in ['lean1090', 'rs1090']:
            values = sorted(int(row['nanoseconds']) for row in sample_rows
                            if row['phase'] == 'measured' and row['implementation'] == name)
            assert len(values) == 21
            assert len([r for r in sample_rows if r['phase'] == 'warmup' and r['implementation'] == name]) == 3
            recomputed[mode, name] = values[10]
            assert values[10] == result['medians_nanoseconds'][name]
            medians += 1
    calculated = calculate(summary['results'])
    assert record['overhead'] == calculated
    for name in ['lean1090', 'rs1090']:
        difference = recomputed['cpr', name] - recomputed['decode', name]
        actual = record['overhead']['implementations'][name]
        assert actual['difference_nanoseconds'] == difference
        assert actual['microseconds_per_message'] == float(Fraction(difference, 172432000))
        if difference < 0:
            negatives.append({'generation': generation, 'implementation': name, 'difference_ns': difference})
assert total_rows == 1920 and medians == 80 and negatives
preview = (E / 'GEN19-with-overhead-preview.md').read_text()
paragraphs = [p for p in preview.split('\n\n') if p.startswith('CPR overhead is **')]
assert len(paragraphs) == 1
assert preview.replace('\n\n' + paragraphs[0], '') == (ROOT / 'bench/GEN19.md').read_text()
assert sha(E / 'GEN19-with-overhead-preview.md') == render['preview_sha256']
assert sha(ROOT / 'bench/GEN19.md') == render['old_report_sha256']
for name, digest in validation['drafts'].items():
    assert sha(E / name) == digest
for name, digest in before.items():
    assert sha(ROOT / name) == digest, name

record = {'status': 'passed_independent_reporting_candidate_review',
          'recorded_utc': datetime.now(timezone.utc).isoformat(), 'findings': [],
          'bindings': {str(p.relative_to(ROOT)): sha(p) for p in E.iterdir() if p.is_file()
                       and p.name not in {'independent-review.json', 'independent-review.log'}},
          'original_live_and_historical_inputs': before,
          'exact_reverse_diff_reconstructs_live_helper': True,
          'positive_zero_negative_precision_cases': synthetic, 'malformed_inputs_rejected': rejections,
          'raw_rows_checked': total_rows, 'mode_implementation_medians_recomputed': medians,
          'negative_differences_retained': negatives,
          'latest': structured['generations'][-1]['overhead'],
          'checks': ['Only the new pure arithmetic function was executed; no candidate main, archive or renderer ran.',
                     'Signed integer nanoseconds are subtracted before conversion; exact difference and divisor remain in structured output.',
                     'All existing validation, CSV-prefix preservation, target decisions, source/native checks and archive behavior reconstruct byte-for-byte.',
                     'Removing one new paragraph reproduces the sealed GEN19 report exactly.',
                     'Mode measurements are independent: their difference includes noise and is explicitly not a separately timed CPR stage.'],
          'drafts_only_not_applied': True, 'history_runtime_frozen_and_harness_unchanged': True}
with (E / 'independent-review.json').open('x') as f:
    json.dump(record, f, indent=2)
    f.write('\n')
print(json.dumps({'status': record['status'], 'review_sha256': sha(E / 'independent-review.json'),
                  'raw_rows': total_rows, 'medians': medians, 'synthetic_cases': len(synthetic),
                  'rejections': len(rejections)}))
