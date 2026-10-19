#!/usr/bin/env python3
"""Refresh presentation from the reviewed gen23 result; no native execution."""
import sys
sys.dont_write_bytecode = True
import argparse
import csv
from datetime import datetime, timezone
from decimal import Decimal
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import traceback

ROOT = Path(__file__).resolve().parents[5]
E = Path(__file__).resolve().parent
os.environ['PYTHONDONTWRITEBYTECODE'] = '1'
os.environ['GIT_OPTIONAL_LOCKS'] = '0'
os.chdir(ROOT)

def sha(path):
    with Path(path).open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()

def load(path):
    return json.loads(Path(path).read_text())

def now():
    return datetime.now(timezone.utc).isoformat()

def save(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')

def verify(held):
    for name, digest in held.items():
        assert sha(ROOT / name) == digest, name

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--execute', action='store_true')
parser.add_argument('--expected-review-sha256', required=True)
args = parser.parse_args()
assert args.execute, 'Preparation only: execute after root release and independent result PASS.'
assert re.fullmatch('[0-9a-f]{64}', args.expected_review_sha256)
summary = load(ROOT / 'bench/runs/gen23/summary.json')
review = load(ROOT / 'bench/runs/gen23/results-review.json')
assert review['status'] == 'passed' and not review['findings']
assert review['generation'] == 23 and review['commit'] == summary['commit']
assert review['binary_sha256'] == summary['binary_sha256']
assert sha(ROOT / 'bench/runs/gen23/results-review.json') == args.expected_review_sha256
held = dict(load(ROOT / 'bench/runs/gen23/correctness-inputs.json'))
assert len(held) == 200
built = load(ROOT / 'bench/runs/gen23/binary-built.json')
held.update(built['native_hashes'])
held['.lake/build/bin/lean1090-bench'] = summary['binary_sha256']
for name in ['bench/results.csv', 'bench/GEN23.md', 'bench/runs/gen23/summary.json',
             'bench/runs/gen23/results-review.json', 'bench/runs/gen23/archive-verification.json', 'bench/runs/gen23/report-verification.json',
             'review/presentation/render_throughput.py', 'review/presentation/verify_throughput.py',
             'review/packaging/check_presentation.py', 'bench/CPR-OVERHEAD.md', 'bench/cpr-overhead.json']:
    held[name] = sha(ROOT / name)
verify(held)
assert not (E / 'execution.json').exists()
before_paths = ['README.md'] + ['docs/images/' + n for n in
    ['throughput-data.json', 'throughput.png', 'throughput.svg', 'throughput.gif']]
prior = {}
for name in before_paths:
    blob = subprocess.check_output(['git', 'show', 'HEAD:' + name], cwd=ROOT)
    assert hashlib.sha256(blob).hexdigest() == sha(ROOT / name), name
    prior[name] = {'sha256': sha(ROOT / name), 'git_blob': subprocess.check_output(
        ['git', 'rev-parse', 'HEAD:' + name], cwd=ROOT, text=True).strip()}
record = {'status': 'running', 'started_utc': now(), 'generation': 23,
          'timed_commit': summary['commit'], 'review_sha256': sha(ROOT / 'bench/runs/gen23/results-review.json'),
          'before_hashes': held, 'prior_presentation': prior,
          'prior_presentation_commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip(),
          'controller_sha256': sha(__file__), 'commands': []}
save(E / 'execution.json', record)
try:
    with (ROOT / 'bench/results.csv').open(newline='') as f:
        rows = list(csv.DictReader(f))
    assert len(rows) == 48
    latest = {row['mode']: row for row in rows if row['generation'] == '23'}
    previous = {row['mode']: row for row in rows if row['generation'] == '22'}
    assert set(latest) == {'decode', 'cpr'}
    ratios = {mode: Decimal(row['lean1090_msg_s']) / Decimal(row['rs1090_msg_s'])
              for mode, row in latest.items()}
    assert review['results'] == summary['results']
    measured = {row['mode']: row for row in summary['results']}
    assert set(measured) == {'decode', 'cpr'}
    reached = {}
    for mode in ('decode', 'cpr'):
        medians = measured[mode]['medians_nanoseconds']
        assert all(type(medians[name]) is int and medians[name] > 0 for name in ('rs1090', 'lean1090'))
        assert review[mode + '_target_ratio'] == {'numerator': 2, 'denominator': 1}
        reached[mode] = medians['rs1090'] >= 2 * medians['lean1090']
        assert review[mode + '_threshold_reached'] is reached[mode]
    assert review['all_mode_thresholds_reached'] is all(reached.values())
    status_text = ('both targets are reached.' if all(reached.values()) else
                   'decode has reached its target; CPR remains below target.' if reached['decode'] else
                   'CPR has reached its target; decode remains below target.' if reached['cpr'] else
                   'neither target is reached.')
    record['exact_target_status'] = {'target': {'numerator': 2, 'denominator': 1},
        'mode_reached': reached, 'all_modes_reached': all(reached.values()),
        'medians_nanoseconds': {mode: row['medians_nanoseconds'] for mode, row in measured.items()},
        'README_status_text': status_text}
    original = (ROOT / 'README.md').read_text()
    assert '[CPR overhead history](bench/CPR-OVERHEAD.md)' in original
    prefix, capstones = original.split('<!-- CAPSTONES:BEGIN -->', 1)
    prefix = prefix.replace('generation 22', 'generation 23').replace('Generation 22', 'Generation 23')
    prefix = prefix.replace('bench/GEN22.md', 'bench/GEN23.md').replace('bench/runs/gen22/', 'bench/runs/gen23/')
    prefix = prefix.replace(load(ROOT / 'bench/runs/gen22/summary.json')['commit'], summary['commit'])
    previous_statuses = ('both targets are reached.',
                         'decode has reached its target; CPR remains below target.',
                         'CPR has reached its target; decode remains below target.',
                         'neither target is reached.')
    found_statuses = [text for text in previous_statuses if text in prefix]
    assert len(found_statuses) == 1 and prefix.count(found_statuses[0]) == 1
    prefix = prefix.replace(found_statuses[0], status_text)
    for mode in ('decode', 'cpr'):
        old_ratio = Decimal(previous[mode]['lean1090_msg_s']) / Decimal(previous[mode]['rs1090_msg_s'])
        prefix = prefix.replace(f'{old_ratio:.5f}×', f'{ratios[mode]:.5f}×')
    for mode, label in [('decode', 'Decode'), ('cpr', 'Decode + CPR')]:
        row = latest[mode]
        line = (f"| {label} | **{Decimal(row['lean1090_msg_s']):,.0f} msg/s** | "
                f"{Decimal(row['rs1090_msg_s']):,.0f} msg/s | **{ratios[mode]:.5f}×** |")
        prefix, count = re.subn(r'(?m)^\| ' + re.escape(label) + r' \|.*$', lambda _: line, prefix)
        assert count == 1, label
    reporting = load(ROOT / 'bench/runs/gen23/report-verification.json')
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
    assert prefix.count(marker) == 1 and prefix.count('CPR overhead is **') == 1
    paragraph = (f"CPR overhead is **{displayed['lean1090']} µs/message for Lean** and "
                 f"**{displayed['rs1090']} µs/message for rs1090**. It is the difference "
                 "between independently measured mode medians, includes measurement noise, "
                 "and is not an isolated timing of CPR work.\n\n")
    prefix, overhead_replacements = re.subn(r'(?m)^CPR overhead is \*\*[^\n]*\n\n', lambda _: paragraph, prefix)
    assert overhead_replacements == 1
    record['signed_cpr_overhead'] = {'source_sha256': sha(ROOT / 'bench/runs/gen23/report-verification.json'),
        'exact_inputs': overhead, 'displayed_microseconds_per_message': displayed}
    (ROOT / 'README.md').write_text(prefix + '<!-- CAPSTONES:BEGIN -->' + capstones)
    assert '[CPR overhead history](bench/CPR-OVERHEAD.md)' in (ROOT / 'README.md').read_text()
    assert (ROOT / 'README.md').read_text().split('<!-- CAPSTONES:BEGIN -->', 1)[1] == capstones
    commands = [
        ('render', ['.cache/venv/bin/python', '-B', 'review/presentation/render_throughput.py', '--expected-generations', '24']),
        ('verify', ['.cache/venv/bin/python', '-B', 'review/presentation/verify_throughput.py', '--expected-generations', '24', '--output', str((E/'verification.json').relative_to(ROOT)), '--preview-dir', '.cache/presentation-gen23']),
        ('readme', ['python3', '-B', str((E/'check_presentation.py').relative_to(ROOT)), '--generation', '23', '--output', str((E/'readme-verification.json').relative_to(ROOT))])]
    for label, argv in commands:
        item = {'label': label, 'argv': argv, 'started_utc': now(), 'environment': {'PYTHONDONTWRITEBYTECODE': '1'}}
        with (E / (label + '.stdout')).open('x') as out, (E / (label + '.stderr')).open('x') as err:
            result = subprocess.run(argv, cwd=ROOT, stdout=out, stderr=err)
        item.update(exit_code=result.returncode, finished_utc=now(), stdout_sha256=sha(E/(label+'.stdout')), stderr_sha256=sha(E/(label+'.stderr')))
        record['commands'].append(item)
        save(E / 'execution.json', record)
        assert result.returncode == 0, label
        verify(held)
    record.update(status='passed', finished_utc=now(), all_held_inputs_unchanged=True,
                  capstone_section_unchanged=True, outputs={name:sha(ROOT/name) for name in before_paths})
    save(E / 'execution.json', record)
except BaseException as error:
    record.update(status='failed', finished_utc=now(), error=repr(error), traceback=traceback.format_exc())
    save(E / 'execution.json', record)
    raise
print(json.dumps({'status':'passed', 'execution_sha256':sha(E/'execution.json'), 'generation':23}))
