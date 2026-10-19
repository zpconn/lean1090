#!/usr/bin/env python3
"""Read-only source/evidence checks after the authorized disk cleanup."""
import sys
sys.dont_write_bytecode = True
import hashlib
import importlib.util
import json
from datetime import datetime, timezone
from pathlib import Path

BASE = Path('tests/evidence/optimization/gen15')
OUT = BASE / 'independent-review'
CLEANUP = Path('tests/evidence/maintenance/disk-cleanup-20261019')

def load(path):
    return json.loads(Path(path).read_text())

def sha(path):
    result = hashlib.sha256()
    with Path(path).open('rb') as stream:
        while block := stream.read(4 * 1024 * 1024):
            result.update(block)
    return result.hexdigest()

spec = importlib.util.spec_from_file_location('resume_benchmark_provenance', 'review/diagnostics/run_generation_benchmark.py')
provenance = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = provenance
spec.loader.exec_module(provenance)
inputs = provenance.gate_input_hashes()
assert len(inputs) == 186
fresh = load(BASE / 'fresh-message-run.json')
execution = load(BASE / 'fresh-execution.json')
retention = load(BASE / 'fresh-retained-hashes.json')
assert fresh['status'] == execution['status'] == 'passed'
assert fresh['exit_code'] == execution['exit_code'] == 0
assert fresh['source_sha256_before'] == fresh['source_sha256_after']
assert fresh['binary_sha256_before'] == fresh['binary_sha256_after']
assert len(fresh['source_sha256_before']) == 111
assert len(fresh['binary_sha256_before']) == 3
for record in (fresh['source_sha256_before'], fresh['binary_sha256_before']):
    for path, expected in record.items():
        assert sha(path) == expected, path
members = {str(p) for p in BASE.glob('fresh*') if p.is_file() and p.name != 'fresh-retained-hashes.json'}
members |= {str(p) for p in (BASE / 'fresh-message').rglob('*') if p.is_file()}
assert members == set(retention['files']) and len(members) == 33
for path, record in retention['files'].items():
    assert sha(path) == record['sha256'] and Path(path).stat().st_size == record['bytes'], path
independent = load(BASE / 'fresh-independent-review/completion.json')
assert independent['status'] == 'passed'
assert independent['held_input_hashes'] == inputs
assert len(independent['native_input_hashes']) == 144
for path, expected in independent['native_input_hashes'].items():
    assert sha(path) == expected, path
native = load(BASE / 'native-review/inspection-inputs.json')
for path, record in native['inputs'].items():
    assert sha(path) == record['sha256'] and Path(path).stat().st_size == record['bytes'], path
cleanup = load(CLEANUP / 'diagnostic-cache-cleanup.json')
assert cleanup['status'] == 'completed' and cleanup['all_selected_absent']
assert cleanup['all_keep_hashes_unchanged']
assert cleanup['selected_files'] == len(cleanup['selected']) == 5090
assert all(not Path(item['path']).exists() for item in cleanup['selected'])
assert sha(cleanup['review']) == cleanup['review_sha256']
assert sha(CLEANUP / 'diagnostic-cache-cleanup-events.jsonl') == cleanup['events_sha256']
small = load(CLEANUP / 'small-strata/completion.json')
assert small['status'] == 'passed' and small['deleted_directory_count'] == 93
for path, item in small['files'].items():
    p = CLEANUP / 'small-strata' / path
    assert sha(p) == item['sha256'] and p.stat().st_size == item['bytes'], p
raw_perf = {}
for generation in range(15):
    capture = load(f'tests/evidence/diagnostics/gen{generation}/perf/capture.json')
    raw = capture['raw_data']
    assert sha(raw['path']) == raw['sha256'] and Path(raw['path']).stat().st_size == raw['bytes']
    raw_perf[str(generation)] = raw
prefix = OUT / 'results-prefix-before-gen15.csv'
assert Path('bench/results.csv').read_bytes() == prefix.read_bytes()
cleanup_files = {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size}
                 for p in sorted(CLEANUP.rglob('*')) if p.is_file()}
assert provenance.gate_input_hashes() == inputs
result = {
    'status': 'passed_read_only_resume_readiness',
    'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'fresh_campaign_source_count': 111, 'fresh_campaign_binary_count': 3,
    'fresh_retained_members': 33, 'unchanged_gate_inputs': 186,
    'unchanged_native_inputs': 144, 'historical_raw_perf_captures_unchanged': 15,
    'current_gate_input_hashes': inputs, 'fresh_source_hashes': fresh['source_sha256_before'],
    'fresh_binary_hashes': fresh['binary_sha256_before'],
    'fresh_retention_sha256': sha(BASE / 'fresh-retained-hashes.json'),
    'fresh_final_verification_sha256': sha(BASE / 'fresh-final-verification.json'),
    'fresh_independent_completion_sha256': sha(BASE / 'fresh-independent-review/completion.json'),
    'cleanup_evidence_files': cleanup_files, 'historical_raw_perf': raw_perf,
    'historical_csv_sha256': sha(prefix), 'script_sha256': sha(__file__),
    'scope': 'Current source/binary and retained-evidence bindings only; no workload or gate was run.',
    'gate_status': 'The original full gate was interrupted after suspension; a new full-gate pass remains required.',
    'cleanup_effect_on_final_reviewer': 'No retained history or source check is waived. Removed diagnostic binaries were explicitly omitted cache artifacts; all existing retained-history, source/native and raw-perf checks remain in place.',
    'findings': [],
}
path = OUT / 'resume-readiness.json'
assert not path.exists()
path.write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
print(json.dumps({'status': result['status'], 'sha256': sha(path),
                  'cleanup_evidence_files': len(cleanup_files), 'fresh_reuse_bindings': '111 sources / 3 binaries / 33 retained files match'}, indent=2))
