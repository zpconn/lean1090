#!/usr/bin/env python3
"""Refresh presentation from the reviewed gen19 result; no native execution."""
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
summary = load(ROOT / 'bench/runs/gen19/summary.json')
review = load(ROOT / 'bench/runs/gen19/results-review.json')
assert review['status'] == 'passed' and not review['findings']
assert review['generation'] == 19 and review['commit'] == summary['commit']
assert review['binary_sha256'] == summary['binary_sha256']
assert sha(ROOT / 'bench/runs/gen19/results-review.json') == args.expected_review_sha256
held = dict(load(ROOT / 'bench/runs/gen19/correctness-inputs.json'))
assert len(held) == 192
built = load(ROOT / 'bench/runs/gen19/binary-built.json')
held.update(built['native_hashes'])
held['.lake/build/bin/lean1090-bench'] = summary['binary_sha256']
for name in ['bench/results.csv', 'bench/GEN19.md', 'bench/runs/gen19/summary.json',
             'bench/runs/gen19/results-review.json', 'bench/runs/gen19/archive-verification.json',
             'review/presentation/render_throughput.py', 'review/presentation/verify_throughput.py',
             'review/packaging/check_presentation.py']:
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
record = {'status': 'running', 'started_utc': now(), 'generation': 19,
          'timed_commit': summary['commit'], 'review_sha256': sha(ROOT / 'bench/runs/gen19/results-review.json'),
          'before_hashes': held, 'prior_presentation': prior,
          'prior_presentation_commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip(),
          'controller_sha256': sha(__file__), 'commands': []}
save(E / 'execution.json', record)
try:
    with (ROOT / 'bench/results.csv').open(newline='') as f:
        rows = list(csv.DictReader(f))
    assert len(rows) == 40
    latest = {row['mode']: row for row in rows if row['generation'] == '19'}
    previous = {row['mode']: row for row in rows if row['generation'] == '18'}
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
    prefix, capstones = original.split('<!-- CAPSTONES:BEGIN -->', 1)
    prefix = prefix.replace('generation 18', 'generation 19').replace('Generation 18', 'Generation 19')
    prefix = prefix.replace('bench/GEN18.md', 'bench/GEN19.md').replace('bench/runs/gen18/', 'bench/runs/gen19/')
    prefix = prefix.replace(load(ROOT / 'bench/runs/gen18/summary.json')['commit'], summary['commit'])
    assert prefix.count('neither target is reached.') == 1
    prefix = prefix.replace('neither target is reached.', status_text)
    for mode in ('decode', 'cpr'):
        old_ratio = Decimal(previous[mode]['lean1090_msg_s']) / Decimal(previous[mode]['rs1090_msg_s'])
        prefix = prefix.replace(f'{old_ratio:.5f}×', f'{ratios[mode]:.5f}×')
    for mode, label in [('decode', 'Decode'), ('cpr', 'Decode + CPR')]:
        row = latest[mode]
        line = (f"| {label} | **{Decimal(row['lean1090_msg_s']):,.0f} msg/s** | "
                f"{Decimal(row['rs1090_msg_s']):,.0f} msg/s | **{ratios[mode]:.5f}×** |")
        prefix, count = re.subn(r'(?m)^\| ' + re.escape(label) + r' \|.*$', lambda _: line, prefix)
        assert count == 1, label
    (ROOT / 'README.md').write_text(prefix + '<!-- CAPSTONES:BEGIN -->' + capstones)
    assert (ROOT / 'README.md').read_text().split('<!-- CAPSTONES:BEGIN -->', 1)[1] == capstones
    commands = [
        ('render', ['.cache/venv/bin/python', '-B', 'review/presentation/render_throughput.py', '--expected-generations', '20']),
        ('verify', ['.cache/venv/bin/python', '-B', 'review/presentation/verify_throughput.py', '--expected-generations', '20', '--output', str((E/'verification.json').relative_to(ROOT)), '--preview-dir', '.cache/presentation-gen19']),
        ('readme', ['python3', '-B', str((E/'check_presentation.py').relative_to(ROOT)), '--generation', '19', '--output', str((E/'readme-verification.json').relative_to(ROOT))])]
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
print(json.dumps({'status':'passed', 'execution_sha256':sha(E/'execution.json'), 'generation':19}))
