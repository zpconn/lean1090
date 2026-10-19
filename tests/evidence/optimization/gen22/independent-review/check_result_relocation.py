#!/usr/bin/env python3
"""Check the recorded archival path correction without repeating measurements."""
import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
B = ROOT / 'tests/evidence/optimization/gen22'
OUT = B / 'independent-review/benchmark-relocation-review.json'
checks = 0


def require(condition, message):
    global checks
    assert condition, message
    checks += 1


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text())


def main():
    require(not OUT.exists(), 'preserve prior review')
    relocation_path = B / 'benchmark-archival/relocation.json'
    failure_path = B / 'benchmark-archival/attempt-01.json'
    relocation, failure = load(relocation_path), load(failure_path)
    source = ROOT / '.cache/bench-runs/gen22-74db413'
    archive = ROOT / 'bench/runs/gen22'
    require(relocation['status'] == 'passed', 'relocation incomplete')
    require(relocation['old_directory'] == '.cache/gen22-benchmark', 'wrong original path')
    require(relocation['new_directory'] == str(source.relative_to(ROOT)), 'wrong canonical path')
    require(not (ROOT / relocation['old_directory']).exists(), 'original directory remains')
    require(relocation['files_before'] == relocation['files_after'], 'recorded byte inventories differ')
    require(relocation['files'] == len(relocation['files_before']) == 48, 'wrong original membership')
    require(relocation['all_file_bytes_unchanged'] and not relocation['measurement_repeated'], 'unexpected correction scope')
    actual_names = {str(p.relative_to(source)) for p in source.rglob('*') if p.is_file()}
    require(actual_names == set(relocation['files_before']), 'canonical source membership differs')
    require(all(not p.is_symlink() for p in source.rglob('*')), 'source symlink')
    for name, record in relocation['files_before'].items():
        for directory in (source, archive):
            path = directory / name
            require(path.is_file() and not path.is_symlink(), 'not a regular retained file: ' + name)
            require(path.stat().st_size == record['bytes'] and sha(path) == record['sha256'],
                    'retained bytes differ: ' + name)
    archive_receipt = load(archive / 'archive-verification.json')
    require(archive_receipt['files'] == relocation['files_before'], 'archive originals differ')
    require(failure['status'] == 'failed_before_any_archive_write' and failure['exit_code'] == 1,
            'missing initial archival failure')
    require(failure['error'] == 'RuntimeError: unexpected source location', 'wrong archival failure')
    require(not failure['measurement_repeated'] and not failure['existing_report_or_csv_changed'],
            'initial archival failure changed outputs')
    require(failure['command'] == ['python3', '-B', 'review/diagnostics/archive_generation_benchmark_target.py',
                                  '--source', '.cache/gen22-benchmark', '--plan',
                                  'tests/evidence/optimization/gen22/benchmark-preparation/plan.json'],
            'initial command differs')
    helper = ROOT / 'review/diagnostics/archive_generation_benchmark_target.py'
    helper_text = helper.read_text()
    require(helper_text.index("'unexpected source location'") < helper_text.index('shutil.copytree(source,destination)'),
            'location check must precede first archival write')
    require(sha(helper) == load(archive / 'report-verification.json')['helper_sha256'], 'executed helper differs')
    commands = load(source / 'commands.json')
    interleaves = [row for row in commands if 'bench/interleave.py' in row['argv']]
    require(len(interleaves) == 2, 'expected one recorded invocation per mode')
    argv_paths = []
    for mode in ('decode', 'cpr'):
        row, = [row for row in interleaves if row['log'] == mode + '-interleave.log']
        require(row['exit_code'] == 0, 'recorded interleaver failure')
        path = row['argv'][row['argv'].index('--output') + 1]
        require(Path(path) == ROOT / relocation['old_directory'] / mode, 'original execution output path rewritten')
        argv_paths.append(path)
    result_path = archive / 'results-review.json'
    result = load(result_path)
    require(result['status'] == 'passed' and not result['findings'] and result['checks_passed'] == 721,
            'independent result review incomplete')
    require(result['commit'] == '74db41344a9d721c600c554b7e2e0f37b65de938', 'wrong measured commit')
    require(result['prior_rows_preserved'] == 44 and result['rows_appended'] == 2, 'CSV prefix differs')
    require(sha(ROOT / 'bench/results.csv') == result['csv_after_sha256'], 'CSV changed after review')
    require(sha(ROOT / 'bench/GEN22.md') == result['report_sha256'], 'report changed after review')
    paths = [relocation_path, failure_path, helper, source / 'commands.json', result_path,
             archive / 'archive-verification.json', archive / 'report-verification.json',
             B / 'benchmark-archival/attempt-02.stdout', B / 'benchmark-archival/attempt-02.stderr',
             B / 'independent-review/benchmark-result-review-01.log',
             B / 'independent-review/benchmark-result-attempt-01/completion.json']
    report = {'status': 'passed', 'checked_utc': datetime.now(timezone.utc).isoformat(),
              'checks_passed': checks, 'findings': [], 'reviewer_sha256': sha(Path(__file__)),
              'original_members_verified': 48, 'original_recorded_interleaver_output_paths': argv_paths,
              'recorded_mode_invocations': 2, 'source_archive_bytes_match_before_and_after': True,
              'bindings': {str(p.relative_to(ROOT)): sha(p) for p in paths},
              'scope': 'The recorded same-filesystem rename preserves every original file byte. The unchanged archival helper rejects the old location before its writes. Existing execution arguments retain their original location; no measurement was rerun by this review.',
              'limitations': 'The filesystem syscall itself is operator-recorded; independent checks establish retained before/after/current/archive byte equality and the recorded single invocation of each mode.',
              'inspection_note': 'An initial rg command named nonexistent benchmark-execution alongside existing directories; actual records were located without writing to that path.'}
    with OUT.open('x') as stream:
        json.dump(report, stream, indent=2)
        stream.write('\n')
    print(json.dumps({'status': 'passed', 'checks_passed': checks, 'sha256': sha(OUT)}, indent=2))


if __name__ == '__main__':
    main()
