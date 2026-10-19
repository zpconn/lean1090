#!/usr/bin/env python3
"""Bind the unsuccessful first gate attempt and its preserved output snapshot."""
import sys
sys.dont_write_bytecode = True
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

BASE = Path('tests/evidence/optimization/gen15')
REVIEW = BASE / 'independent-review'
ATTEMPT = BASE / 'attempt-01-interrupted-for-cleanup'

def load(path):
    return json.loads(Path(path).read_text())

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        while chunk := stream.read(4 * 1024 * 1024):
            h.update(chunk)
    return h.hexdigest()

readiness = load(REVIEW / 'resume-readiness.json')
assert readiness['status'] == 'passed_read_only_resume_readiness'
inputs = readiness['current_gate_input_hashes']
assert len(inputs) == 186
for path, expected in inputs.items():
    assert sha(path) == expected, path
record = load(ATTEMPT / 'interruption.json')
old = load(ATTEMPT / 'gate-evidence.json')
current = load(BASE / 'gate-evidence.json')
assert record['status'] == 'interrupted_not_passed'
assert record['old_process_group'] == 1126929 and record['host_process_probe_exit_code'] == 1
assert record['old_gate_record_sha256'] == sha(ATTEMPT / 'gate-evidence.json')
assert record['old_gate_log_sha256'] == sha(ATTEMPT / 'gate-full.log')
assert record['gate_inputs_unchanged'] and record['input_count'] == 186
assert old['status'] == 'running' and 'exit_code' not in old and 'finished_at' not in old
assert old['generated_messages'] == current['generated_messages'] == 10000000
assert old['input_hashes_before'] == current['input_hashes_before'] == inputs
assert old['command'] == current['command'] == ['bash', 'scripts/check_all.sh', '--full']
assert old['started_at'] < record['recorded_utc'] < current['started_at']
assert 'Complete differential campaign passed all mandatory strata.' not in (ATTEMPT / 'gate-full.log').read_text()
rows = list(csv.DictReader((ATTEMPT / 'components.tsv').open(), delimiter='\t'))
assert [r['component'] for r in rows] == ['altitude', 'reserved_velocity', 'dte', 'numeric', 'cpr', 'tracking']
assert all(r['exit_code'] == '0' for r in rows)
assert 'not a passing campaign' in record['snapshot_caveat']
snapshots = {}
for item in record['copied_files']:
    path = Path(item['retained'])
    assert path.is_relative_to('.cache/gen15-interrupted-gate')
    assert sha(path) == item['sha256'] and path.stat().st_size == item['bytes']
    assert str(path) not in snapshots
    snapshots[str(path)] = {'sha256': item['sha256'], 'bytes': item['bytes']}
assert {str(p) for p in Path('.cache/gen15-interrupted-gate').rglob('*') if p.is_file()} == set(snapshots)
attempt_files = {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size}
                 for p in sorted(ATTEMPT.rglob('*')) if p.is_file()}
assert {Path(p).name for p in attempt_files} == {'interruption.json', 'gate-evidence.json', 'gate-full.log', 'components.tsv', 'preserve.py', 'run_full_gate.py'}
for path, item in readiness['cleanup_evidence_files'].items():
    assert sha(path) == item['sha256'] and Path(path).stat().st_size == item['bytes'], path
for path, expected in readiness['fresh_source_hashes'].items():
    assert sha(path) == expected, path
for path, expected in readiness['fresh_binary_hashes'].items():
    assert sha(path) == expected, path
result = {
    'status': 'passed_interrupted_attempt_preservation_review',
    'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'original_gate_status': 'interrupted_not_passed',
    'original_gate_had_completed_components': 6,
    'original_gate_had_no_final_completion': True,
    'old_gate_started_at': old['started_at'], 'interruption_recorded_at': record['recorded_utc'],
    'restarted_gate_started_at': current['started_at'],
    'restarted_gate_command': current['command'], 'restarted_gate_result_required_separately': True,
    'all_186_correctness_inputs_identical_across_attempts': True,
    'fresh_campaign_111_sources_3_binaries_rechecked': True,
    'attempt_files': attempt_files, 'snapshot_files': snapshots,
    'snapshot_file_count': len(snapshots), 'snapshot_bytes': sum(x['bytes'] for x in snapshots.values()),
    'cleanup_receipt_files_rechecked': len(readiness['cleanup_evidence_files']),
    'readiness_sha256': sha(REVIEW / 'resume-readiness.json'), 'script_sha256': sha(__file__),
    'findings': [],
    'limitations': [record['snapshot_caveat'],
                   'The parent recorded the host process probe. This reviewer checks the retained probe assertion and preserves its not-passed conclusion; it does not infer success from generic output files.',
                   'No test, decoder, build or benchmark is run by this reviewer.'],
}
path = REVIEW / 'interruption-review.json'
assert not path.exists()
path.write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
print(json.dumps({'status': result['status'], 'sha256': sha(path),
                  'snapshots': len(snapshots), 'snapshot_bytes': result['snapshot_bytes']}, indent=2))
