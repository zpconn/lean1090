#!/usr/bin/env python3
"""Independent retained-byte/source replay; no build, generator or decoder."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import gzip, hashlib, json

G = Path('tests/evidence/optimization/gen23')
B = G
O = B / 'independent-review/fresh-retention-review.json'


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for chunk in iter(lambda: f.read(1 << 22), b''):
            h.update(chunk)
    return h.hexdigest()


def load(p):
    return json.loads(Path(p).read_text())


def unpack(p):
    h, size, rows = hashlib.sha256(), 0, 0
    with gzip.open(p, 'rb') as f:
        for chunk in iter(lambda: f.read(1 << 22), b''):
            h.update(chunk)
            size += len(chunk)
            rows += chunk.count(b'\n')
    return {'sha256': h.hexdigest(), 'bytes': size, 'rows': rows}


def main():
    assert not O.exists()
    manifest = load(B / 'fresh-retained-hashes.json')
    execution = load(B / 'fresh-execution.json')
    run = load(B / 'fresh-message-run.json')
    verify = load(B / 'fresh-final-verification.json')
    pre = load(B / 'fresh-preflight.json')
    seeds = load(B / 'fresh-seeds.json')
    commb = load(B / 'fresh-commb-run.json')
    summary = load(B / 'fresh-message/summary.json')
    assert all(j['status'] == 'passed' for j in [manifest, execution, run, verify, pre, commb])
    assert execution['exit_code'] == run['exit_code'] == verify['exit_code'] == 0
    actual = {str(p) for p in B.glob('fresh*') if p.is_file() and p.name != 'fresh-retained-hashes.json'}
    actual |= {str(p) for p in (B / 'fresh-message').rglob('*') if p.is_file()}
    assert actual == set(manifest['files']) and len(actual) == 33
    for name, row in manifest['files'].items():
        assert sha(name) == row['sha256'] and Path(name).stat().st_size == row['bytes']
    for kind, count in [('source_sha256', 125), ('binary_sha256', 3)]:
        assert run[kind + '_before'] == run[kind + '_after'] == pre[kind]
        assert len(pre[kind]) == count
        commb_before = kind if kind == 'source_sha256' else kind + '_before'
        assert commb[commb_before] == commb[kind + '_after'] == pre[kind]
        for name, digest in pre[kind].items():
            assert sha(name) == digest
    assert execution['final_source_hash_count'] == manifest['final_source_hash_count'] == verify['source_hash_count'] == 125
    assert execution['final_binary_hash_count'] == manifest['final_binary_hash_count'] == verify['binary_hash_count'] == 3
    assert execution['final_source_binary_hashes_match'] and manifest['final_source_binary_hashes_match']
    assert execution['retained_file_count'] == manifest['exact_membership_count'] == 33
    assert execution['verification_sha256'] == manifest['existing_raw_verification']['sha256'] == sha(B / 'fresh-final-verification.json')
    assert execution['retention_execution_sha256'] == manifest['retention_execution_sha256'] == sha(B / 'fresh-retention-execution.json')
    assert execution['preflight_sha256'] == sha(B / 'fresh-preflight.json')
    assert execution['seed_record_sha256'] == run['seed_record_sha256'] == commb['seed_record_sha256'] == pre['seed_record_sha256'] == sha(B / 'fresh-seeds.json')
    assert pre['authorized_by'] == '/root'
    assert len(pre['gate_inputs']) == pre['gate_input_count'] == 200
    assert pre['gate_inputs'] == load(G / 'integration/targeted-build.json')['all_inputs_after']
    assert pre['integrated_build_record_sha256'] == sha(G / 'integration/targeted-build.json')
    assert pre['integrated_build_log_sha256'] == sha(G / 'integration/targeted-build.log')
    for name, digest in pre['helpers'].items():
        assert sha(name) == digest
    for command in execution['commands']:
        assert command['exit_code'] == 0 and sha(command['log']) == command['log_sha256']
        assert command['helper_sha256'] == command['helper_sha256_after'] == sha(command['command'][1])
        assert command['started_monotonic_ns'] <= command['finished_monotonic_ns']
    assert run['summary_sha256'] == verify['summary_sha256'] == sha(B / 'fresh-message/summary.json')
    assert verify['run_record_sha256'] == sha(B / 'fresh-message-run.json')
    assert verify['verifier_sha256'] == sha(B / 'fresh-verify.py')
    assert seeds['recorded_utc'] < execution['started_utc']
    assert seeds['message_seed'] == summary['seed'] == verify['message_seed'] == 1958132729
    assert seeds['commb_seed'] == verify['commb_seed'] == 972156822
    for name, digest in seeds['historical_seed_records_sha256'].items():
        assert sha(name) == digest
        previous = load(name)
        assert seeds['message_seed'] not in [previous.get('message_seed'), previous.get('commb_seed')]
        assert seeds['commb_seed'] not in [previous.get('message_seed'), previous.get('commb_seed')]
    assert summary['status'] == 'PASS' and summary['generated_messages'] == 10000000
    counts = summary['message']['counts']
    assert counts == verify['message_counts']
    assert counts['messages'] == counts['exact_matches'] + counts['D001'] == 10476164
    assert not summary['message']['coverage_errors'] and not summary['message']['mismatch_fields']
    assert tuple(len(summary['message'][k]) for k in ['df', 'adsb', 'commb']) == (32, 70, 14)
    assert summary['direct_registers']['counts'] == verify['direct_counts'] == {'cases': 101244, 'exact_matches': 101244}
    assert verify['retained_raw_artifact_count'] == 9 and len(verify['verified_artifacts']) == 11
    decoded = {}
    for name, row in verify['verified_artifacts'].items():
        assert sha(name) == row['compressed_sha256']
        got = unpack(name)
        assert got['sha256'] == row['uncompressed_sha256'] and got['bytes'] == row['uncompressed_bytes']
        decoded[name] = got
    streams = {}
    expected_rows = {'mismatches.jsonl.gz': counts['D001'],
                     'standard-differences.jsonl.gz': counts['standard_view_differences'],
                     'direct-mismatches.jsonl.gz': 0}
    assert {Path(p).name for p in manifest['diagnostic_streams']} == set(expected_rows)
    for name, row in manifest['diagnostic_streams'].items():
        assert sha(name) == row['compressed_sha256']
        got = unpack(name)
        assert got == {'sha256': row['decompressed_sha256'], 'bytes': row['decompressed_bytes'], 'rows': row['rows']}
        assert got['rows'] == row['expected_rows'] == expected_rows[Path(name).name]
        streams[name] = got
    native = load(G / 'native-review/review.json')
    native_inputs = load(G / 'native-review/native-inputs.json')
    assert native_inputs['all_inputs_unchanged']
    assert native_inputs['integration_record_sha256'] == sha(G / 'integration/targeted-build.json')
    assert sha(native_inputs['worker']) == native_inputs['worker_sha256']
    assert native['status'] == 'passed' and not native['findings']
    assert native['commb_validity_tables_live_path_verified'] and native['linked_native_sets'] == 22
    for name, digest in native_inputs['held_inputs'].items():
        assert sha(name) == digest
    for name, digest in native['bindings'].items():
        assert sha(name) == digest
    for name, row in native['files'].items():
        assert sha(name) == row['sha256'] and Path(name).stat().st_size == row['bytes']
    for kind in ['source_sha256', 'binary_sha256']:
        for name, digest in pre[kind].items():
            assert sha(name) == digest
    result = {'status': 'passed', 'reviewed_utc': datetime.now(timezone.utc).isoformat(),
              'script_sha256': sha(__file__), 'source_hashes': 125, 'binary_hashes': 3, 'exact_retained_members': 33,
              'raw_and_standalone_decompressed': decoded, 'diagnostic_streams_decompressed': streams,
              'message_counts': counts, 'coverage': [32, 70, 14], 'direct_counts': verify['direct_counts'],
              'seeds': {'message': seeds['message_seed'], 'commb': seeds['commb_seed']},
              'bindings': {str(B / p): sha(B / p) for p in ['fresh-retained-hashes.json', 'fresh-final-verification.json',
                  'fresh-execution.json', 'fresh-preflight.json', 'fresh-seeds.json', 'fresh-message/summary.json',
                  'independent-review/preparation-review.json']} | {str(G / p): sha(G / p) for p in ['native-review/review.json', 'native-review/native-inputs.json', 'integration/targeted-build.json']},
              'findings': [], 'limits': 'Complete gzip byte/hash/cardinality replay and source/execution bindings; no decoder or generation rerun. Separate frozen-comparison replay checks classifications.'}
    O.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'review_sha256': sha(O), 'counts': counts}))


if __name__ == '__main__':
    main()
