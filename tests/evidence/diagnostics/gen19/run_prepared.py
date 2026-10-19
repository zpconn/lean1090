#!/usr/bin/env python3
"""Guarded reuse of the existing gen19 decode build/campaign tools.

Preparation only until the parent releases work after both benchmark modes.
Default is validation and command display; --execute performs the selected
phase. Campaign additionally requires both isolated actual-worker captures.
No production build, benchmark, runtime edit or cleanup is performed here.
"""
import sys
sys.dont_write_bytecode = True
import argparse
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[4]
E = ROOT / 'tests/evidence/diagnostics/gen19'
B = ROOT / 'bench/runs/gen19'
C = ROOT / '.cache/gen19-costs'
os.environ['PYTHONDONTWRITEBYTECODE'] = '1'
os.environ['GIT_OPTIONAL_LOCKS'] = '0'

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def read(path):
    return json.loads(path.read_text())

def rel(path):
    return str(path.relative_to(ROOT))

def guard():
    summary, review, built = (read(B / name) for name in
                              ('summary.json', 'results-review.json', 'binary-built.json'))
    assert summary['status'] == 'complete' and summary['generation'] == 19
    assert review['status'] == 'passed' and review['generation'] == 19 and not review['findings']
    assert review['commit'] == built['commit'] == summary['commit']
    assert review['binary_sha256'] == built['sha256'] == summary['binary_sha256']
    assert review['results'] == summary['results']
    assert {r['mode'] for r in summary['results']} == {'decode', 'cpr'}
    for row in summary['results']:
        assert row['samples'] == 48
        assert sha(B / row['mode'] / 'samples.csv') == row['samples_sha256']
        assert sha(B / row['mode'] / 'metadata.json') == row['metadata_sha256']
    for name in ('before-build', 'before-decode', 'after-decode',
                 'before-cpr', 'after-cpr', 'after-timing'):
        clean = read(B / (name + '-git.json'))
        assert clean['clean'] and not clean['stdout'] and clean['commit'] == summary['commit']
    assert built['build_command']['exit_code'] == 0
    assert sha(ROOT / '.lake/build/bin/lean1090-bench') == summary['binary_sha256']
    assert sha(ROOT / 'spec.lock') == built['spec_lock_sha256'] == summary['spec_lock_sha256']
    for name, digest in built['native_hashes'].items():
        assert sha(ROOT / name) == digest, name
    subprocess.run(['git', 'merge-base', '--is-ancestor', summary['commit'], 'HEAD'], cwd=ROOT, check=True)
    spec = importlib.util.spec_from_file_location(
        'gen19_inventory', ROOT / 'review/diagnostics/run_generation_benchmark.py')
    tool = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(tool)
    assert tool.gate_input_hashes() == read(B / 'correctness-inputs.json')
    return summary

def run(argv, label):
    path = E / (label + '-command.json')
    assert not path.exists()
    record = {'argv': argv, 'started_utc': datetime.now(timezone.utc).isoformat()}
    path.write_text(json.dumps(record, indent=2) + '\n')
    with (E / (label + '.stdout')).open('x') as out, (E / (label + '.stderr')).open('x') as err:
        result = subprocess.run(argv, cwd=ROOT, stdout=out, stderr=err)
    record.update(exit_code=result.returncode, completed_utc=datetime.now(timezone.utc).isoformat())
    path.write_text(json.dumps(record, indent=2) + '\n')
    assert result.returncode == 0, (label, result.returncode)

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('phase', choices=('build', 'campaign'))
    parser.add_argument('--execute', action='store_true')
    args = parser.parse_args()
    os.chdir(ROOT)
    summary = guard()
    if args.phase == 'build':
        assert not (C / 'driver').exists(), 'retain any earlier driver attempt'
        commands = [([sys.executable, '-B', 'review/diagnostics/build_decode_costs.py',
                      '--output', rel(C / 'driver'), '--fresh-native-inputs',
                      rel(B / 'fresh-native-inputs.json')], 'driver-build'),
                    ([sys.executable, '-B', 'review/diagnostics/bind_benchmark_history.py',
                      '--build', rel(C / 'driver/driver-build.json'),
                      '--benchmark', rel(B / 'summary.json'),
                      '--correctness-inputs', rel(B / 'correctness-inputs.json'),
                      '--output', rel(E / 'benchmark-source-binding.json')], 'source-binding')]
    else:
        complete = read(ROOT / 'tests/evidence/diagnostics/gen19-cpr/isolated-perf-completion.json')
        assert complete['status'] == 'passed' and complete['all_jobs_stopped']
        assert complete['sequential_modes'] == ['decode', 'cpr']
        assert [r['mode'] for r in complete['results']] == ['decode', 'cpr']
        for row in complete['results']:
            capture_path = ROOT / row['capture']
            capture = read(capture_path)
            assert sha(capture_path) == row['capture_sha256'] and row['inputs_unchanged']
            assert capture['all_input_hashes_unchanged'] and capture['record_exit_code'] == 0
            assert capture['before_hashes']['.lake/build/bin/lean1090-bench'] == summary['binary_sha256']
        assert (E / 'historical-inputs.json').is_file(), 'seal compact history after benchmark review'
        assert read(C / 'driver/driver-build.json')['status'] == 'passed'
        commands = [([sys.executable, '-B', 'review/diagnostics/run_cost_campaign.py',
                      '--cache', rel(C), '--jobs', '6', '--perf-capture',
                      rel(E / 'perf/capture.json')], 'campaign')]
    print(json.dumps({'status': 'guarded', 'execute': args.execute,
                      'timed_commit': summary['commit'], 'commands': commands}), flush=True)
    if args.execute:
        for argv, label in commands:
            run(argv, label)

if __name__ == '__main__':
    main()
