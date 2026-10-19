#!/usr/bin/env python3
"""Compact post-gate/archive/plan verification using reviewed generic APIs."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import csv, gzip, hashlib, json, re, subprocess
sys.path.insert(0, 'review/diagnostics')
import run_generation_benchmark as provenance
import archive_generation_gate as archive_api
import archive_generation_benchmark_target as reporting

B = Path('tests/evidence/optimization/gen16')
OUT = B / 'independent-review/gate-review.json'


def sha(p):
    return archive_api.digest(Path(p))


def load(p):
    return json.loads(Path(p).read_text())


def main():
    assert not OUT.exists()
    current = provenance.gate_input_hashes()
    gate = load(B / 'gate-evidence.json')
    archive = load(B / 'gate-archive.json')
    verified = provenance.verify_gate_evidence(gate, sha(B / 'gate-full.log'), current)
    assert len(current) == 187 and archive['status'] == 'passed' and archive['generation'] == 16
    previous = load('tests/evidence/optimization/gen15/gate-evidence.json')['input_hashes_after']
    assert set(current) - set(previous) == {'Proofs/PackFields.lean'} and not set(previous) - set(current)
    assert {p for p in previous if previous[p] != current[p]} == {'Impl/Bits.lean', 'Proofs/Decoder.lean'}
    assert archive['gate_evidence_sha256'] == sha(B / 'gate-evidence.json')
    assert archive['gate_log_sha256'] == sha(B / 'gate-full.log')
    assert archive['helper_sha256'] == sha('review/diagnostics/archive_generation_gate.py')
    assert archive['provenance_helper_sha256'] == sha('review/diagnostics/run_generation_benchmark.py')
    runner, components, status_path = archive_api.discover_components()
    assert archive['runner_sha256'] == sha(runner)
    names = [name for name, *_ in components]
    assert len(names) == 7 and set(names) == set(archive['components'])
    statuses = list(csv.DictReader((B / 'components.tsv').open(), delimiter='\t'))
    assert [r['component'] for r in statuses] == names and all(r['exit_code'] == '0' for r in statuses)
    assert (B / 'components.tsv').read_bytes() == status_path.read_bytes()
    text = (B / 'gate-full.log').read_text()
    for line in ['Final manifest: 23 exact theorem types and permitted axioms.',
                 'Witness axiom audit: 152 proofs; only the three permitted axioms (or fewer).',
                 'Hypothesis dependency audit: all seven required predicates and assigned are independent of decoder entry points/helpers.',
                 'Complete differential campaign passed all mandatory strata.']:
        assert line in text
    objects = []
    decoder = json.JSONDecoder()
    for match in re.finditer(r'^\{', text, re.M):
        try:
            value, _ = decoder.raw_decode(text, match.start())
        except ValueError:
            continue
        if isinstance(value, dict):
            objects.append(value)
    assert any(r.get('assertions') == 1011 and r.get('assertion_failures') == 0 for r in objects)
    for raw in re.findall(r'depends on axioms:\s*\[([^\]]*)\]', text):
        assert {x.strip() for x in raw.split(',') if x.strip()} <= {'propext', 'Classical.choice', 'Quot.sound'}
    summaries, file_count = {}, 0
    for name, script, source, argv in components:
        row = archive['components'][name]
        assert row['script_sha256'] == sha(script) and row['runner_command_tokens'] == argv
        original, retained = row['original_files'], row['retained_files']
        assert set(original) == set(retained)
        assert archive_api.inventory(source) == original
        directory = Path(retained['summary.json']['path']).resolve().parent
        assert archive_api.inventory(directory) == retained
        for member in retained:
            assert original[member]['sha256'] == retained[member]['sha256']
            assert original[member]['bytes'] == retained[member]['bytes']
        for item in row['versioned_metadata'].values():
            assert sha(item['path']) == item['sha256'] and Path(item['path']).stat().st_size == item['bytes']
        summary = load(retained['summary.json']['path'])
        archive_api.check_summary(name, summary, current)
        assert archive_api.bind_printed_summary(name, summary, text, objects) == row['full_gate_log_binding']
        summaries[name] = summary
        file_count += len(retained)
    assert file_count == 62 and archive['copied_fixed_message_files'] == 15
    assert sum(summaries['altitude']['counts'][k] for k in ['ac12_cases', 'ac13_cases']) == 12288
    assert summaries['reserved_velocity']['comparisons'] == 16480
    assert summaries['dte']['comparisons'] == 65536
    assert summaries['numeric']['exact_comparisons'] == 20936723
    assert summaries['cpr']['counts']['calls'] == 535748 and summaries['cpr']['counts']['D009'] == 204
    assert summaries['tracking']['messages'] == 178297 and summaries['tracking']['resolved_positions'] == 16460
    assert summaries['tracking']['mismatches'] == 0
    fixed_cleanup_dir = B / 'post-gate-archive-cleanup'
    wrapper = load(fixed_cleanup_dir / 'result.json')
    wrapper_start = load(fixed_cleanup_dir / 'start.json')
    flush = load(fixed_cleanup_dir / 'archive-flush.json')
    fixed_cleanup = load(fixed_cleanup_dir / 'cleanup/result.json')
    fixed_start = load(fixed_cleanup_dir / 'cleanup/start.json')
    assert wrapper['status'] == fixed_cleanup['status'] == 'completed'
    assert wrapper['gate_archive_sha256'] == sha(B / 'gate-archive.json')
    assert wrapper['archive_flush_sha256'] == sha(fixed_cleanup_dir / 'archive-flush.json')
    assert wrapper['cleanup_result_sha256'] == sha(fixed_cleanup_dir / 'cleanup/result.json')
    assert flush['status'] == 'passed' and not flush['archive_content_rewritten']
    assert flush['ordering'] == 'All file and directory fsync calls completed before cleanup/archive_index.'
    assert wrapper_start['wrapper_sha256'] == sha('review/diagnostics/finish_generation_gate.py')
    assert wrapper_start['archive_helper_sha256'] == sha('review/diagnostics/archive_generation_gate.py')
    assert wrapper_start['cleanup_helper_sha256'] == fixed_start['script_sha256'] == sha('review/diagnostics/cleanup_verified_scratch.py')
    assert wrapper_start['caller_attests_quiescence'] and fixed_start['caller_attests_quiescence']
    assert wrapper_start['cleanup_mode'] == fixed_cleanup['mode'] == fixed_start['mode'] == 'apply'
    assert fixed_start['protected'] == ['.cache/reserved-velocity-proposal', '.cache/gen15-interrupted-gate']
    fixed_roots = ['.cache/altitude-exhaustive-m2hicg3_', '.cache/reserved-velocity-l00atsz2',
                   '.cache/dte-exhaustive-ks5pfc7r', '.cache/cpr-synthetic-nurmg7zu', '.cache/message-differential-3cywh4gj']
    assert fixed_start['scratch'] == fixed_roots == [r['directory'] for r in fixed_cleanup['results']]
    assert fixed_cleanup['deleted_allocated_bytes'] == wrapper['deleted_allocated_bytes'] == 5733335040
    fixed_raw = {}
    for row in fixed_cleanup['results']:
        assert row['status'] == 'deleted' and not Path(row['directory']).exists()
        for f in row['files']:
            kept = f['retained']
            assert f['gzip_eof_verified'] and kept['path'] in flush['files']
            assert sha(kept['path']) == kept['compressed_sha256']
            assert sha(kept['seal']['path']) == kept['seal']['sha256'] == sha(B / 'gate-archive.json')
            assert sha(kept['summary']) == kept['summary_sha256']
            digest, size = hashlib.sha256(), 0
            with gzip.open(kept['path'], 'rb') as stream:
                while chunk := stream.read(1 << 20):
                    digest.update(chunk)
                    size += len(chunk)
            assert digest.hexdigest() == kept['raw_sha256'] == f['sha256']
            assert size == kept['raw_bytes'] == f['identity']['bytes']
            fixed_raw[kept['path']] = {'sha256': digest.hexdigest(), 'bytes': size}
    assert len(fixed_raw) == fixed_cleanup['verified_gzip_archives'] == 26
    fresh = load(B / 'fresh-message/summary.json')
    fresh_review = load(B / 'independent-review/fresh-retention-review.json')
    replay = load(B / 'independent-review/comparison-replay.json')
    assert fresh_review['status'] == replay['status'] == 'passed' and not fresh_review['findings']
    for name, digest in fresh_review['bindings'].items():
        assert sha(name) == digest
    assert replay['summary_sha256'] == sha(B / 'fresh-message/summary.json')
    assert replay['retention_manifest_sha256'] == sha(B / 'fresh-retained-hashes.json')
    assert replay['full_coverage_and_counts_equal'] and replay['temporary_duplicate_outputs_removed']
    assert replay['message_counts'] == fresh_review['message_counts'] == fresh['message']['counts']
    completion = load(B / 'independent-review/fresh-completion.json')
    assert completion['status'] == 'passed' and completion['raw_files_deleted'] == 8
    for name, digest in completion['bindings'].items():
        assert sha(name) == digest
    cleanup = load(B / 'post-fresh-cleanup/result.json')
    cleanup_start = load(B / 'post-fresh-cleanup/start.json')
    assert cleanup['status'] == 'completed' and cleanup['mode'] == 'apply'
    assert cleanup_start['caller_attests_quiescence'] and cleanup_start['mode'] == 'apply'
    assert cleanup_start['script_sha256'] == sha('review/diagnostics/cleanup_verified_scratch.py')
    assert cleanup_start['scratch'] == [completion['raw_scratch_deleted']]
    assert cleanup_start['protected'] == [completion['fixed_gate_scratch_preserved']]
    assert len(cleanup['results']) == 1 and cleanup['verified_gzip_archives'] == 8
    removed = cleanup['results'][0]
    assert removed['status'] == 'deleted' and removed['directory'] == completion['raw_scratch_deleted']
    assert not Path(removed['directory']).exists() and len(removed['files']) == 8
    assert cleanup['deleted_allocated_bytes'] == completion['allocated_bytes_reclaimed'] == 5359882240
    for row in removed['files']:
        kept = row['retained']
        independently_read = fresh_review['raw_and_standalone_decompressed'][kept['path']]
        assert row['gzip_eof_verified'] and row['sha256'] == kept['raw_sha256'] == independently_read['sha256']
        assert row['identity']['bytes'] == kept['raw_bytes'] == independently_read['bytes']
        assert sha(kept['path']) == kept['compressed_sha256']
    for name, row in load(B / 'fresh-retained-hashes.json')['files'].items():
        assert sha(name) == row['sha256'] and Path(name).stat().st_size == row['bytes']
    for summary in [summaries['message'], fresh]:
        assert summary['status'] == 'PASS' and summary['generated_messages'] == 10000000
        counts = summary['message']['counts']
        assert counts['messages'] == counts['exact_matches'] + counts['D001'] == 10476164
        assert not summary['message']['mismatch_fields'] and not summary['message']['coverage_errors']
        assert tuple(len(summary['message'][k]) for k in ['df', 'adsb', 'commb']) == (32, 70, 14)
        assert summary['direct_registers']['counts'] == {'cases': 101244, 'exact_matches': 101244}
    assert summaries['message']['seed'] != fresh['seed']
    assert summaries['message']['message']['counts']['exact_matches'] == 9542689
    assert summaries['message']['message']['counts']['D001'] == 933475
    prep = load(B / 'benchmark-preparation/preparation-verification.json')
    plan = load(B / 'benchmark-preparation/plan.json')
    prepared_review = load(B / 'independent-review/benchmark-preparation-source-review.json')
    assert prep['status'] == 'passed' and prep['plan_sha256'] == sha(B / 'benchmark-preparation/plan.json')
    assert prep['fresh_verification_sha256'] == sha(B / 'fresh-final-verification.json')
    assert prep['gate_evidence_sha256'] == sha(B / 'gate-evidence.json')
    assert prep['helper_sha256'] == prepared_review['helper_sha256'] == sha('review/diagnostics/archive_generation_benchmark_target.py')
    assert prep['helper_independent_review_sha256'] == prepared_review['helper_independent_review_sha256']
    assert prepared_review['prepare_sha256'] == sha(B / 'benchmark-preparation/prepare.py')
    prior = Path(plan['prior_csv_snapshot']).read_bytes()
    assert prior == Path('bench/results.csv').read_bytes() == subprocess.check_output(['git', 'show', 'HEAD:bench/results.csv'])
    assert len(reporting.parse_prior_csv(prior, 16)) == plan['prior_csv_rows'] == 32
    assert hashlib.sha256(prior).hexdigest() == plan['prior_csv_sha256'] == prepared_review['prior_csv_sha256']
    assert all(reporting.target_ratio(plan, mode) == (2, 1) for mode in ['decode', 'cpr'])
    assert not prep['measurement_started'] and not Path('bench/runs/gen16').exists()
    native = load(B / 'native-review/review.json')
    assert native['status'] == 'passed' and native['findings'] == []
    for name, digest in native['inputs'].items():
        assert sha(name) == digest
    for digest, name in [line.split('  ', 1) for line in Path('spec.lock').read_text().splitlines()]:
        assert sha(name) == digest
    history = load(B / 'independent-review/preparation.json')
    for row in history['history_bindings'].values():
        assert sha(row['path']) == row['sha256']
    assert provenance.gate_input_hashes() == current
    result = {'status': 'passed', 'reviewed_utc': datetime.now(timezone.utc).isoformat(), 'findings': [],
              'script_sha256': sha(__file__), 'gate_verification': verified, 'gate_inputs': 187,
              'contracts': 23, 'kernel_witnesses': 152, 'unit_assertions': 1011,
              'components': names, 'retained_component_files': file_count,
              'fixed_counts': summaries['message']['message']['counts'], 'fresh_counts': fresh['message']['counts'],
              'fixed_seed': summaries['message']['seed'], 'fresh_seed': fresh['seed'], 'coverage_each': [32, 70, 14],
              'prior_csv_rows': 32, 'target_ratios': {'decode': [2, 1], 'cpr': [2, 1]},
              'fresh_cleanup': {'files': 8, 'allocated_bytes': 5359882240,
                                'complete_retained_copies_rechecked': True},
              'fixed_cleanup': {'roots': fixed_roots, 'files': 26, 'allocated_bytes': 5733335040,
                                'archive_flush_before_cleanup': True, 'decompressed_retained_copies': fixed_raw},
              'bindings': {str(B / p): sha(B / p) for p in ['gate-evidence.json', 'gate-full.log', 'gate-archive.json',
                  'fresh-retained-hashes.json', 'fresh-final-verification.json', 'native-review/review.json',
                  'independent-review/fresh-retention-review.json', 'independent-review/comparison-replay.json',
                  'independent-review/fresh-completion.json', 'post-fresh-cleanup/result.json',
                  'post-gate-archive-cleanup/result.json', 'post-gate-archive-cleanup/archive-flush.json',
                  'benchmark-preparation/plan.json', 'benchmark-preparation/preparation-verification.json']},
              'limits': 'Read-only review; prior generation evidence is bound through its sealed reviews and exact CSV prefix, without recopying historical files. Raw scratch cleanup is separately authorized and receipted after archival.'}
    OUT.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'review_sha256': sha(OUT), 'gate_inputs': 187, 'components': 7}))


if __name__ == '__main__':
    main()
