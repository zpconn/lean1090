#!/usr/bin/env python3
"""Prepare generation 23 presentation controllers without rendering anything."""
import sys
sys.dont_write_bytecode = True
import ast
from datetime import datetime, timezone
import difflib
import hashlib
import json
from pathlib import Path
import re

OLD = Path('tests/evidence/optimization/gen22/presentation')
E = Path(__file__).parent
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
created = []
for name in ['run_refresh.py', 'check_presentation.py', 'seal_presentation.py']:
    before = (OLD / name).read_text()
    after = re.sub(r'(gen|GEN|generation |Generation )(21|22)\b',
                   lambda m: m[1] + str(int(m[2]) + 1), before)
    replacements = []
    if name == 'run_refresh.py':
        replacements = [
            ("review['generation'] == 22", "review['generation'] == 23"),
            ("'generation': 22", "'generation': 23"),
            ("'generation':22", "'generation':23"),
            ('len(held) == 197', 'len(held) == 200'),
            ('len(rows) == 46', 'len(rows) == 48'),
            ("row['generation'] == '22'", "row['generation'] == '__CURRENT__'"),
            ("row['generation'] == '21'", "row['generation'] == '22'"),
            ("row['generation'] == '__CURRENT__'", "row['generation'] == '23'"),
            ("'--expected-generations', '23'", "'--expected-generations', '24'"),
            ("'--generation', '22'", "'--generation', '23'"),
        ]
    elif name == 'seal_presentation.py':
        replacements = [
            ("verification['source_rows'] == 46 and verification['frames'] == 23",
             "verification['source_rows'] == 48 and verification['frames'] == 24"),
            ("verification['plotted_values_checked'] == 1104",
             "verification['plotted_values_checked'] == 1200"),
            ('generations 0, 11 and 22', 'generations 0, 12 and 23'),
            ("'generation': 22", "'generation': 23"),
            ("'correctness_inputs': 197", "'correctness_inputs': 200"),
        ]
    for old, new in replacements:
        assert old in after, (name, old)
        after = after.replace(old, new)
    ast.parse(after, filename=str(E / name))
    with (E / name).open('x') as stream:
        stream.write(after)
    diff = E / (name + '.diff')
    with diff.open('x') as stream:
        stream.write(''.join(difflib.unified_diff(
            before.splitlines(True), after.splitlines(True),
            fromfile=str(OLD / name), tofile=str(E / name))))
    created.extend([E / name, diff])

inputs = [OLD / name for name in ['run_refresh.py', 'check_presentation.py', 'seal_presentation.py']]
inputs += [Path(name) for name in ['review/packaging/check_presentation.py',
           'review/presentation/render_throughput.py', 'review/presentation/verify_throughput.py']]
record = {
    'status': 'prepared_not_executed',
    'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'generation': 23, 'expected_csv_rows': 48, 'expected_frames': 24,
    'expected_plotted_values': 1200, 'expected_correctness_inputs': 200,
    'inputs': {str(p): sha(p) for p in inputs},
    'files': {str(p): sha(p) for p in created},
    'changes': [
        'Generation/path/count adaptation only; the local documentation checker and shared renderer/verifier remain byte-identical.',
        'Preserve all 23 capstones verbatim and all source, native, link, artist, frame, pixel, target-line and signed-overhead checks.',
        'Derive each target and their conjunction from actual reviewed integer medians; no result, commit or worker identity is guessed.',
        'Inspect final PNG plus GIF generations 0, 12 and 23 at README width before sealing visual review.',
    ],
    'actual_results_review_sha256': None, 'actual_timed_commit': None,
    'actual_worker_sha256': None,
    'execution_prerequisites': [
        'Root release after both measured modes, canonical archive and independent result-review PASS.',
        'Root completes docs/OPTIMIZATION.md and other status documentation before presentation execution; those inputs remain stable through the final independent review.',
        'If both targets pass, finish the reviewed generation artifacts and stop for user review; no next-generation diagnostics.',
    ],
    'release_command_template': 'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/optimization/gen23/presentation/run_refresh.py --execute --expected-review-sha256 <actual-passed-gen23-results-review-SHA256>',
    'syntax_validation': 'ast.parse only; no controller import/execution, rendering, source-document edit or image mutation.',
    'preparer_sha256': sha(__file__),
}
with (E / 'preparation.json').open('x') as stream:
    stream.write(json.dumps(record, indent=2) + '\n')
print(json.dumps({'status': record['status'], 'preparation_sha256': sha(E / 'preparation.json')}))
