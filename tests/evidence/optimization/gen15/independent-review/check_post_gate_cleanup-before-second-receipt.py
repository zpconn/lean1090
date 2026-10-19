#!/usr/bin/env python3
"""Read-only binding review of archive-then-cleanup execution receipts."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

BASE = Path('tests/evidence/optimization/gen15')
OUT = BASE / 'independent-review'
RECEIPT = BASE / 'post-gate-archive-cleanup'
TOOLING = Path('tests/evidence/maintenance/scratch-cleanup-tooling-20261019')

def load(path):
    return json.loads(Path(path).read_text())

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        while chunk := stream.read(4 * 1024 * 1024):
            h.update(chunk)
    return h.hexdigest()

def check_files(files):
    for path, item in files.items():
        assert sha(path) == item['sha256'] and Path(path).stat().st_size == item['bytes'], path

bound = load(OUT / 'cleanup-tooling-bindings.json')
check_files(bound['evidence_files'])
for path, expected in bound['helpers'].items():
    assert sha(path) == expected, path
review = load(TOOLING / 'independent-review.json')
completion = load(TOOLING / 'completion.json')
assert review['status'] == completion['status'] == 'passed'
assert not review['blocking_findings']
assert completion['independent_review_sha256'] == sha(TOOLING / 'independent-review.json')
assert review['helpers'] == bound['helpers']
check_files(review['artifacts'])

gate = load(BASE / 'gate-evidence.json')
archive = load(BASE / 'gate-archive.json')
assert gate['status'] == archive['status'] == 'passed' and gate['exit_code'] == 0
assert archive['generation'] == 15 and archive['gate_evidence_sha256'] == sha(BASE / 'gate-evidence.json')
assert archive['gate_log_sha256'] == sha(BASE / 'gate-full.log')
start = load(RECEIPT / 'start.json')
archive_result = load(RECEIPT / 'archive-result.json')
finish = load(RECEIPT / 'result.json')
clean_start = load(RECEIPT / 'cleanup/start.json')
clean_result = load(RECEIPT / 'cleanup/result.json')
assert start['cleanup_mode'] == clean_start['mode'] == clean_result['mode'] == 'apply'
assert start['caller_attests_quiescence'] and clean_start['caller_attests_quiescence']
assert start['archive_helper_sha256'] == sha('review/diagnostics/archive_generation_gate.py')
assert start['wrapper_sha256'] == sha('review/diagnostics/finish_generation_gate.py')
assert start['cleanup_helper_sha256'] == clean_start['script_sha256'] == sha('review/diagnostics/cleanup_verified_scratch.py')
assert archive_result['archive_exit_code'] == 0 and archive_result['archive_helper_unchanged']
assert archive_result['archive_stdout_sha256'] == sha(RECEIPT / 'archive.stdout')
assert archive_result['archive_stderr_sha256'] == sha(RECEIPT / 'archive.stderr')
assert finish['status'] == clean_result['status'] == 'completed'
assert finish['gate_archive_sha256'] == sha(BASE / 'gate-archive.json')
assert finish['cleanup_result_sha256'] == sha(RECEIPT / 'cleanup/result.json')
assert datetime.fromisoformat(gate['finished_at']) <= datetime.fromisoformat(clean_start['started_utc'])
assert clean_start['started_utc'] <= clean_result['finished_utc']
assert [row['directory'] for row in clean_result['results']] == clean_start['scratch']
assert not clean_start['protected']  # Root explicitly checked quiescence; old interrupted raw may be deduplicated.
assert '.cache/gen15-interrupted-gate' not in clean_start['scratch']
expected_files = {str(RECEIPT / name) for name in ('start.json', 'archive-result.json', 'archive.stdout', 'archive.stderr', 'result.json')}
expected_files |= {str(RECEIPT / 'cleanup' / name) for name in ('start.json', 'result.json')}
deleted = []
retained = []
counterparts = {}
raw_files = 0
for row in clean_result['results']:
    directory = Path(row['directory'])
    result_path = RECEIPT / 'cleanup' / (directory.name + '.result.json')
    expected_files.add(str(result_path))
    assert load(result_path) == row
    verified_path = RECEIPT / 'cleanup' / (directory.name + '.verified.json')
    assert directory.parent == Path('.cache')
    if verified_path.exists():
        expected_files.add(str(verified_path))
        verified = load(verified_path)
        assert verified['status'] == 'verified'
        assert {k:v for k,v in verified.items() if k != 'status'} == {k:v for k,v in row.items() if k != 'status'}
    if row['status'] == 'deleted':
        assert verified_path.is_file() and not directory.exists()
        assert row['allocated_bytes'] == sum(f['identity']['allocated_bytes'] for f in row['files'])
        deleted.append(row['directory'])
    else:
        # Unknown/unmatched input keeps the complete set. A partial deletion cannot pass this review.
        assert row['status'] in ('retained', 'retained_or_interrupted') and directory.is_dir()
        assert 'reason' in row
        if verified_path.exists():
            assert {p.name for p in directory.iterdir()} == {f['name'] for f in row['files']}
        for file in row['files']:
            raw = directory / file['name']
            assert sha(raw) == file['sha256'] and raw.stat().st_size == file['identity']['bytes']
        retained.append({'directory': row['directory'], 'reason': row['reason']})
    for file in row['files']:
        entry = file['retained']
        assert file['gzip_eof_verified']
        assert file['sha256'] == entry['raw_sha256'] and file['identity']['bytes'] == entry['raw_bytes']
        seal = load(entry['seal']['path'])
        assert sha(entry['seal']['path']) == entry['seal']['sha256'] and seal['status'] == 'passed'
        if entry['seal']['path'].endswith('/gate-archive.json'):
            memberships = {r['path']:r for component in seal['components'].values() for r in component['retained_files'].values()}
        else:
            assert entry['seal']['path'].endswith('/fresh-retained-hashes.json')
            memberships = seal['files']
        assert entry['path'] in memberships and entry['summary'] in memberships
        assert memberships[entry['path']]['sha256'] == entry['compressed_sha256']
        assert memberships[entry['summary']]['sha256'] == entry['summary_sha256']
        if entry['path'] not in counterparts:
            assert sha(entry['path']) == entry['compressed_sha256']
            assert Path(entry['path']).stat().st_size == memberships[entry['path']]['bytes']
            assert sha(entry['summary']) == entry['summary_sha256']
            raw = load(entry['summary'])['artifacts'][file['name']]
            assert raw['sha256'] == entry['raw_sha256'] and raw['bytes'] == entry['raw_bytes']
            counterparts[entry['path']] = {'sha256': entry['compressed_sha256'], 'raw_sha256': entry['raw_sha256'], 'raw_bytes': entry['raw_bytes']}
        raw_files += 1
assert {str(p) for p in RECEIPT.rglob('*') if p.is_file()} == expected_files
assert clean_result['deleted_allocated_bytes'] == finish['deleted_allocated_bytes'] == sum(row.get('allocated_bytes',0) for row in clean_result['results'] if row['status']=='deleted')
assert clean_result['verified_gzip_archives'] == len(counterparts)
interruption = load(OUT / 'interruption-review.json')
check_files(interruption['attempt_files'])
check_files(interruption['snapshot_files'])
inputs = load(OUT / 'resume-readiness.json')['current_gate_input_hashes']
assert gate['input_hashes_before'] == gate['input_hashes_after'] == inputs
for path, expected in inputs.items():
    assert sha(path) == expected, path
receipts = {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(RECEIPT.rglob('*')) if p.is_file()}
result = {
    'status': 'passed', 'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'receipt_files': receipts, 'deleted_directories': deleted, 'retained_directories': retained,
    'recorded_raw_file_checks': raw_files, 'retained_compressed_counterparts_rehashed': len(counterparts),
    'deleted_allocated_bytes': finish['deleted_allocated_bytes'],
    'tooling_bindings_sha256': sha(OUT / 'cleanup-tooling-bindings.json'),
    'gate_archive_sha256': sha(BASE / 'gate-archive.json'),
    'interrupted_snapshot_files_unchanged': len(interruption['snapshot_files']),
    'correctness_inputs_unchanged': len(inputs), 'script_sha256': sha(__file__), 'findings': [],
    'limitations': ['Quiescence is the explicit caller attestation; this checker does not inspect processes.',
                   'Deleted raw files are bound through the reviewed helper pre-deletion raw/gzip EOF checks and retained SHA/size receipts. The review rehashes their remaining compressed counterparts; it does not claim to re-read deleted raw files.',
                   'Interrupted generic-output snapshots remain unsuccessful/mixed historical evidence.'],
}
path = OUT / 'post-gate-cleanup-review.json'
assert not path.exists()
path.write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
print(json.dumps({'status': result['status'], 'sha256': sha(path), 'deleted_directories': len(deleted), 'retained_directories': len(retained)}, indent=2))
