from pathlib import Path
from datetime import datetime, timezone
import ast, difflib, hashlib, json, re
old = Path('tests/evidence/optimization/gen19/presentation')
p = Path('tests/evidence/optimization/gen20/presentation')
# The independent reviewer owns two files in this shared evidence directory.
assert p.is_dir()
sha = lambda q: hashlib.sha256(Path(q).read_bytes()).hexdigest()
created = []
for name in ['run_refresh.py', 'check_presentation.py', 'seal_presentation.py']:
    assert not (p / name).exists()
    a = (old / name).read_text()
    b = re.sub(r'(gen|GEN|generation |Generation )(18|19)\b', lambda m: m[1] + str(int(m[2]) + 1), a)
    if name == 'run_refresh.py':
        b = b.replace("review['generation'] == 19", "review['generation'] == 20").replace("'generation': 19", "'generation': 20").replace("'generation':19", "'generation':20").replace('len(held) == 192', 'len(held) == 195').replace('len(rows) == 40', 'len(rows) == 42')
        b = b.replace("row['generation'] == '19'", "row['generation'] == '20'").replace("row['generation'] == '18'", "row['generation'] == '19'")
        b = b.replace("'--expected-generations', '20'", "'--expected-generations', '21'").replace("'--generation', '19'", "'--generation', '20'")
        b = b.replace("'review/packaging/check_presentation.py']:", "'review/packaging/check_presentation.py', 'bench/CPR-OVERHEAD.md', 'bench/cpr-overhead.json']:")
        b = b.replace("original = (ROOT / 'README.md').read_text()", "original = (ROOT / 'README.md').read_text()\n    assert '[CPR overhead history](bench/CPR-OVERHEAD.md)' in original")
        b = b.replace("assert (ROOT / 'README.md').read_text().split", "assert '[CPR overhead history](bench/CPR-OVERHEAD.md)' in (ROOT / 'README.md').read_text()\n    assert (ROOT / 'README.md').read_text().split")
    elif name == 'seal_presentation.py':
        b = b.replace("assert execution['review_sha256'] == '7ce0ffac700b450d0b56284fd36c5c2829cc6a9cb5f2c874657dbca0a2a4e984'", "assert execution['review_sha256'] == sha(ROOT / 'bench/runs/gen20/results-review.json')")
        b = b.replace("verification['source_rows'] == 40 and verification['frames'] == 20", "verification['source_rows'] == 42 and verification['frames'] == 21").replace("verification['plotted_values_checked'] == 840", "verification['plotted_values_checked'] == 924")
        b = b.replace('generations 0, 10 and 19', 'generations 0, 10 and 20').replace("'generation': 19", "'generation': 20").replace("'correctness_inputs': 192", "'correctness_inputs': 195")
        b = b.replace("    'retained_read_only_inspection_error': 'inspection-01-error.json',\n", '')
    assert 'gen18' not in b and 'GEN18' not in b
    ast.parse(b)
    (p / name).write_text(b)
    delta = p / (name + '.diff')
    delta.write_text(''.join(difflib.unified_diff(a.splitlines(True), b.splitlines(True), fromfile=str(old / name), tofile=str(p / name))))
    created += [p / name, delta]
generic = Path('review/packaging/check_presentation.py').read_text()
local = (p / 'check_presentation.py').read_text()
(p / 'checker.diff').write_text(''.join(difflib.unified_diff(generic.splitlines(True), local.splitlines(True), fromfile='review/packaging/check_presentation.py', tofile=str(p / 'check_presentation.py'))))
(p / 'controller.diff').write_bytes((p / 'run_refresh.py.diff').read_bytes())
created += [p / 'checker.diff', p / 'controller.diff']
record = {
    'status': 'prepared_not_executed', 'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'generation': 20, 'expected_csv_rows': 42, 'expected_frames': 21, 'expected_correctness_inputs': 195,
    'inputs': {str(q): sha(q) for q in [old / 'run_refresh.py', old / 'seal_presentation.py', Path('review/packaging/check_presentation.py'), Path('review/presentation/render_throughput.py'), Path('review/presentation/verify_throughput.py')]},
    'files': {str(q): sha(q) for q in created},
    'changes': [
        'Generation/path/count updates only in the established controller, plus explicitly preserve and hash the CPR overhead history link/files.',
        'Evidence-local checker is byte-identical to gen19; generic renderer/verifier/packaging checker remain unchanged.',
        'Seal binds the actual reviewed result hash from controller execution instead of a stale generation-specific literal; no reused reviewer error record.',
        'Exact per-mode and conjunctive 2/1 decisions, prior capstones and all held source/native checks retained.'
    ],
    'release_command_template': 'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/optimization/gen20/presentation/run_refresh.py --execute --expected-review-sha256 <actual-passed-gen20-results-review-SHA256>',
    'syntax_validation': 'ast.parse only; no rendering, README edit, native workload or build executed.',
    'retained_preparation_failure': 'preparation-attempt-01.json',
}
(p / 'preparation.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps({'preparation_sha256': sha(p / 'preparation.json'), 'files': record['files']}, indent=2))
