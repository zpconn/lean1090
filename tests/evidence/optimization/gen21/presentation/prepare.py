#!/usr/bin/env python3
"""Prepare the generation 21 presentation from the sealed generation 20 workflow."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import ast
import difflib
import hashlib
import json
import re

old = Path('tests/evidence/optimization/gen20/presentation')
p = Path('tests/evidence/optimization/gen21/presentation')
sha = lambda q: hashlib.sha256(Path(q).read_bytes()).hexdigest()
created = []
for name in ['run_refresh.py', 'check_presentation.py', 'seal_presentation.py']:
    assert not (p / name).exists()
    a = (old / name).read_text()
    b = re.sub(r'(gen|GEN|generation |Generation )(19|20)\b', lambda m: m[1] + str(int(m[2]) + 1), a)
    if name == 'run_refresh.py':
        b = b.replace("review['generation'] == 20", "review['generation'] == 21").replace("'generation': 20", "'generation': 21").replace("'generation':20", "'generation':21")
        b = b.replace('len(rows) == 42', 'len(rows) == 44')
        b = b.replace("row['generation'] == '20'", "row['generation'] == '21'").replace("row['generation'] == '19'", "row['generation'] == '20'")
        b = b.replace("'--expected-generations', '21'", "'--expected-generations', '22'").replace("'--generation', '20'", "'--generation', '21'")
        b = b.replace("'bench/runs/gen21/archive-verification.json',", "'bench/runs/gen21/archive-verification.json', 'bench/runs/gen21/report-verification.json',")
        needle = "    (ROOT / 'README.md').write_text(prefix + '<!-- CAPSTONES:BEGIN -->' + capstones)"
        assert b.count(needle) == 1
        addition = '''    reporting = load(ROOT / 'bench/runs/gen21/report-verification.json')
    overhead = reporting['cpr_overhead']
    assert overhead['messages_per_interval'] == 172432
    displayed = {}
    for implementation in ('lean1090', 'rs1090'):
        item = overhead['implementations'][implementation]
        decode_ns = measured['decode']['medians_nanoseconds'][implementation]
        cpr_ns = measured['cpr']['medians_nanoseconds'][implementation]
        assert item['median_nanoseconds'] == {'decode': decode_ns, 'cpr': cpr_ns}
        assert item['difference_nanoseconds'] == cpr_ns - decode_ns
        assert item['microseconds_per_message_divisor'] == 172432000
        displayed[implementation] = format(Decimal(cpr_ns - decode_ns) / Decimal(172432000), '+.12f')
    marker = '![Measured throughput across optimization generations]'
    assert prefix.count(marker) == 1 and 'CPR overhead is **' not in prefix
    paragraph = (f"CPR overhead is **{displayed['lean1090']} µs/message for Lean** and "
                 f"**{displayed['rs1090']} µs/message for rs1090**. It is the difference "
                 "between independently measured mode medians, includes measurement noise, "
                 "and is not an isolated timing of CPR work.\\n\\n")
    prefix = prefix.replace(marker, paragraph + marker)
    record['signed_cpr_overhead'] = {'source_sha256': sha(ROOT / 'bench/runs/gen21/report-verification.json'),
        'exact_inputs': overhead, 'displayed_microseconds_per_message': displayed}
'''
        b = b.replace(needle, addition + needle)
    elif name == 'check_presentation.py':
        b = b.replace("f'bench/runs/gen{generation}/summary.json',", "f'bench/runs/gen{generation}/summary.json', f'bench/runs/gen{generation}/report-verification.json',")
        needle = "    campaign_counts = {}"
        assert b.count(needle) == 1
        addition = '''    overhead = json.loads((ROOT / f'bench/runs/gen{generation}/report-verification.json').read_text())['cpr_overhead']
    modes = {row['mode']: row['medians_nanoseconds'] for row in summary['results']}
    expected = {}
    for implementation in ('lean1090', 'rs1090'):
        difference = modes['cpr'][implementation] - modes['decode'][implementation]
        item = overhead['implementations'][implementation]
        assert item['median_nanoseconds'] == {mode: modes[mode][implementation] for mode in ('decode', 'cpr')}
        assert item['difference_nanoseconds'] == difference and item['microseconds_per_message_divisor'] == 172432000
        expected[implementation] = format(Decimal(difference) / Decimal(172432000), '+.12f')
    check('README_signed_CPR_overheads_match_exact_medians', overhead['messages_per_interval'] == 172432
          and f"**{expected['lean1090']} µs/message for Lean**" in readme
          and f"**{expected['rs1090']} µs/message for rs1090**" in readme)
    check('README_CPR_overhead_scope_and_noise_disclosed', all(text in readme for text in
          ('difference between independently measured mode medians', 'includes measurement noise',
           'not an isolated timing of CPR work')))
'''
        b = b.replace(needle, addition + needle)
    else:
        b = b.replace("verification['source_rows'] == 42 and verification['frames'] == 21", "verification['source_rows'] == 44 and verification['frames'] == 22")
        b = b.replace("verification['plotted_values_checked'] == 924", "verification['plotted_values_checked'] == 1012")
        b = b.replace("len(readme['checks']) == 30", "len(readme['checks']) == 32")
        b = b.replace('generations 0, 10 and 20', 'generations 0, 11 and 21').replace("'generation': 20", "'generation': 21")
        b = b.replace("    'exact_target_status': execution['exact_target_status'],", "    'exact_target_status': execution['exact_target_status'],\n    'signed_cpr_overhead': execution['signed_cpr_overhead'],")
        b = b.replace('Evidence-local checker adds exact per-mode and conjunctive target status;', 'Evidence-local checker adds exact per-mode and conjunctive target status plus signed CPR overhead from exact medians;')
    ast.parse(b)
    (p / name).write_text(b)
    delta = p / (name + '.diff')
    delta.write_text(''.join(difflib.unified_diff(a.splitlines(True), b.splitlines(True), fromfile=str(old / name), tofile=str(p / name))))
    created += [p / name, delta]
record = {
    'status': 'prepared_not_executed', 'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'generation': 21, 'expected_csv_rows': 44, 'expected_frames': 22, 'expected_correctness_inputs': 195,
    'inputs': {str(q): sha(q) for q in [old / name for name in ('run_refresh.py', 'check_presentation.py', 'seal_presentation.py')] + [Path(name) for name in ('review/packaging/check_presentation.py', 'review/presentation/render_throughput.py', 'review/presentation/verify_throughput.py')]},
    'files': {str(q): sha(q) for q in created},
    'changes': [
        'Generation/path/count updates to the established workflow; shared renderer, verifier and packaging checker unchanged.',
        'README adds both signed CPR overheads derived from exact integer median differences with explicit independent-mode/noise limits.',
        'Two local documentation checks verify the signed values and interpretation; existing capstone, source, native, link and exact target checks remain.',
        'Historical presentation stays bound to its committed Git blobs; no historical benchmark or evidence bytes are overwritten.'
    ],
    'release_command_template': 'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/optimization/gen21/presentation/run_refresh.py --execute --expected-review-sha256 <actual-passed-gen21-results-review-SHA256>',
    'syntax_validation': 'ast.parse only; no rendering, README edit, native workload or build executed.',
    'preparer_sha256': sha(__file__),
}
(p / 'preparation.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps({'status': record['status'], 'preparation_sha256': sha(p / 'preparation.json')}, indent=2))
