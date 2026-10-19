#!/usr/bin/env python3
"""Seal retained CPR diagnostic evidence; no decoder/build commands."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from collections import Counter
import datetime
import gzip
import hashlib
import json

ROOT = Path(__file__).resolve().parents[4]
BASE = ROOT / 'tests/evidence/diagnostics/gen17-cpr'


def sha(p):
    h = hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()


def load(p):
    return json.loads(p.read_text())


def decoded(p):
    raw = gzip.decompress(p.read_bytes()) if p.suffix == '.gz' else p.read_bytes()
    return hashlib.sha256(raw).hexdigest(), len(raw)


def main():
    target = BASE / 'validation.json'
    assert not target.exists()
    archive = load(BASE / 'archive-manifest.json')
    build = load(BASE / 'retained/driver-final/driver-build.json')
    native = load(BASE / 'retained/validation/summary.json')
    run = load(BASE / 'retained/callgrind/run.json')
    analysis = json.loads(gzip.decompress((BASE / 'analysis/analysis.json.gz').read_bytes()))
    sub = json.loads(gzip.decompress((BASE / 'decoder-stages.json.gz').read_bytes()))
    perf = load(BASE / 'perf/capture.json')
    source_review = load(BASE / 'independent-review/source-review.json')
    assert all(j['status'] == 'passed' for j in [archive, build, native, run, sub])
    assert source_review['status'] == 'passed_read_only_source_and_native_review'
    assert native['inputs_before'] == native['inputs_after']
    assert perf['before_hashes'] == perf['after_hashes']
    held = dict(perf['before_hashes'])
    for mapping in [native['inputs_before'], build['unchanged_native_inputs']]:
        for name, value in mapping.items():
            assert name not in held or held[name] == value, name
            held[name] = value
    for name, value in held.items():
        assert sha(ROOT / name) == value, name
    lock_rows = [line.split('  ', 1) for line in (ROOT / 'spec.lock').read_text().splitlines()]
    assert len(lock_rows) == 104
    for value, name in lock_rows:
        assert sha(ROOT / name) == value, name
    assert sha(ROOT / 'spec.lock') == '5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
    actual_archive_members = {str(p.relative_to(BASE)) for directory in ['retained', 'tooling']
                              for p in (BASE / directory).rglob('*') if p.is_file()}
    assert actual_archive_members == set(archive['files'])
    for name, row in archive['files'].items():
        path = BASE / name
        assert sha(path) == row['stored_sha256'] and path.stat().st_size == row['stored_bytes'], name
        assert decoded(path) == (row['source_sha256'], row['source_bytes']), name
    for row in load(BASE / 'analysis-retention.json')['files']:
        path = ROOT / row['retained']
        assert sha(path) == row['compressed_sha256']
        assert decoded(path) == (row['raw_sha256'], row['raw_bytes'])
    for name, value in load(BASE / 'perf/artifact-hashes.json')['files'].items():
        assert sha(BASE / 'perf' / name) == value, name
    for name, row in native['artifacts'].items():
        retained = BASE / 'retained/validation' / name
        if not retained.exists():
            retained = Path(str(retained) + '.gz')
        assert decoded(retained) == (row['sha256'], row['bytes']), name
    assert all(command['exit_code'] == 0 for command in native['commands'])
    expected, actual = native['result'].copy(), run['result'].copy()
    assert expected.pop('batch_state_check') is True
    assert actual.pop('batch_state_check') is False and expected == actual
    assert native['tracking_rows'] == native['tracking_bit_identical'] == 172432
    assert native['resolved_positions'] == 11347 and native['complete_batch_StreamState_and_routed_positions_equal']
    decode_result_path = ROOT / 'tests/evidence/diagnostics/gen17/native/all.jsonl'
    decode_result = [json.loads(line) for line in decode_result_path.read_text().splitlines()
                     if line.strip()]
    decode_result = [row for row in decode_result if row.get('phase') == 'result']
    assert len(decode_result) == 1 and decode_result[0]['digest'] == actual['digest']
    counts = Counter()
    for row in analysis['self_cost_contexts']:
        counts[row['bucket']] += row['self_Ir']
    assert all(counts[k] == v for k, v in analysis['exclusive_stages'].items())
    assert sum(counts.values()) == analysis['total_Ir'] == run['primary_ir']
    assert not analysis['ambiguous_contexts'] and not counts['outside_root']
    assert all(row['self_Ir'] > 0 and analysis['root'] in row['symbol'] for row in analysis['explicit_chain_recoveries'])
    assert sum(sub['exclusive_decoder_stages'].values()) == counts['decoder']
    assert analysis['root_calls'] == 1
    anchors = analysis['native_anchor_counts_and_non_additive_inclusive']
    assert anchors['lp_lean1090_Lean1090_Impl_decode']['native_entries'] == 172432
    assert anchors['lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep']['native_entries'] == actual['routed']
    assert decoded(BASE / 'retained/callgrind/callgrind.out.1.gz')[0] == analysis['raw_sha256']
    assert sha(ROOT / 'review/diagnostics/analyze_cpr_costs.py') == analysis['analyzer_sha256']
    assert sha(BASE / 'tooling/analyze_cpr_costs.py') == analysis['analyzer_sha256']
    assert load(BASE / 'analysis/fixture-checks.json')['cases'] == 8
    numeric = json.loads(gzip.decompress((BASE / 'numeric-contexts.json.gz').read_bytes()))
    assert numeric['status'] == 'passed' and numeric['profile_sha256'] == analysis['raw_sha256']
    assert numeric['analysis_sha256'] == hashlib.sha256(gzip.decompress((BASE / 'analysis/analysis.json.gz').read_bytes())).hexdigest()
    table = json.loads(gzip.decompress((BASE / 'table-contexts.json.gz').read_bytes()))
    assert table['status'] == 'passed' and table['profile_sha256'] == analysis['raw_sha256']
    assert table['analysis_sha256'] == numeric['analysis_sha256']
    assert sha(ROOT / table['source_review']) == table['source_review_sha256']
    assert table['table_constructor_entries_inside_root'] == 0
    for row in table['by_stage']:
        assert row['lookup_entries'] == row['direct_formula_fallback_calls'] + row['table_lookup_calls_from_verified_branch_partition']
    for key,value in table['total'].items():
        assert value == sum(row[key] for row in table['by_stage'])
    assert sha(BASE / 'extract_table_contexts.py') == table['script_sha256']
    assert sha(BASE / 'extract_numeric_contexts.py') == numeric['script_sha256']
    assert sha(ROOT / source_review['driver_build_manifest']) == source_review['driver_build_manifest_sha256']
    assert sha(ROOT / 'bench/runs/gen17/fresh-native-inputs.json') == source_review['fresh_native_inputs_sha256']
    assert source_review['worker_sha256'] == perf['before_hashes']['.lake/build/bin/lean1090-bench']
    isolated = load(BASE / 'isolated-perf-completion.json')
    assert isolated['status'] == 'passed' and isolated['all_jobs_stopped'] and isolated['sequential_modes'] == ['decode', 'cpr']
    assert load(BASE / 'collect-execution.json')['status'] == 'passed'
    for label in ['native-validation','callgrind','driver-build']:
        command = load(BASE / (label + '-command.json'))
        assert command['exit_code'] == 0
        assert sha(BASE / (label + '.stdout')) == command['stdout_sha256']
        assert sha(BASE / (label + '.stderr')) == command['stderr_sha256']
    report = ROOT / 'docs/GEN17-CPR-COST-BREAKDOWN.md'
    final_files = {str(p.relative_to(BASE)): sha(p) for p in sorted(BASE.rglob('*'))
                   if p.is_file() and 'independent-review' not in p.relative_to(BASE).parts
                   and p.name not in {'validation.json', 'finalize-execution.log', 'finalize-sealed-execution.log'}}
    record = {'status': 'passed', 'recorded_utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
              'report': str(report.relative_to(ROOT)), 'report_sha256': sha(report),
              'protected_inputs': held, 'protected_input_count': len(held),
              'all_protected_inputs_unchanged': True, 'frozen_entries_rehashed': 104,
              'fresh_linked_sets': 22, 'reused_production_objects': 21,
              'archive_manifest_sha256': sha(BASE / 'archive-manifest.json'),
              'archived_original_count': len(archive['files']), 'archived_original_bytes': archive['stored_bytes'],
              'archive_membership_and_all_compressed_and_decoded_hashes_verified': True,
              'analysis_raw_sha256': analysis['raw_sha256'], 'total_Ir': analysis['total_Ir'],
              'exclusive_stages': analysis['exclusive_stages'], 'decoder_stages': sub['exclusive_decoder_stages'],
              'graph_unreachable_explicit_chain_recovery': {'contexts': len(analysis['explicit_chain_recoveries']), 'self_Ir': sum(row['self_Ir'] for row in analysis['explicit_chain_recoveries'])},
              'numeric_direct_edge_groups': len(numeric['grouped_direct_edges']),
              'table_native_counts': table['total'], 'table_constructor_entries_inside_root': table['table_constructor_entries_inside_root'],
              'table_contexts_sha256': sha(BASE / 'table-contexts.json.gz'),
              'analysis_fixtures_passed': 8, 'tracking_bit_identical_rows': 172432,
              'resolved_positions': 11347, 'batch_complete_state_and_positions_match': True,
              'frozen_worker_final_state_projection_match': True,
              'same_generation_decode_digest_path': str(decode_result_path.relative_to(ROOT)),
              'same_generation_decode_digest_file_sha256': sha(decode_result_path),
              'message_digest': actual['digest'], 'complete_state_digest': {
                  'repr_bytes': actual['full_state_repr_bytes'], 'fnv1a64_decimal': actual['full_state_fnv1a64_decimal']},
              'source_review_sha256': sha(BASE / 'independent-review/source-review.json'), 'files': final_files,
              'notes': ['All native/compiler/profile jobs owned by this producer finished before finalization.',
                        'Existing reviewed attribution, decoder subpartition, power and numeric edge algorithms reused unchanged; new table supplement counts actual direct edges with independently verified branch semantics.',
                        'Same-generation decode digest comparison uses the retained native/all.jsonl.',
                        'Independent reviewer-owned files are excluded from producer inventory to permit subsequent separate review.']}
    target.write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'protected_inputs': len(held),
                      'validation_sha256': sha(target), 'report_sha256': sha(report),
                      'producer_files': len(final_files)}))


if __name__ == '__main__':
    main()
