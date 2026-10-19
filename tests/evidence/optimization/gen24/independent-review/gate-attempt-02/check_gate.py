#!/usr/bin/env python3
"""Compact post-gate/archive/plan verification using reviewed generic APIs."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import argparse, csv, gzip, hashlib, json, re, subprocess
sys.path.insert(0, 'review/diagnostics')
import run_generation_benchmark as provenance
import archive_generation_gate as archive_api
import archive_generation_benchmark_target as reporting

B = Path('tests/evidence/optimization/gen24')
F = B
OUT = B / 'independent-review/gate-review.json'


def sha(p):
    return archive_api.digest(Path(p))


def load(p):
    return json.loads(Path(p).read_text())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--execute-after-root-ready', action='store_true', required=True)
    parser.parse_args()
    assert not OUT.exists()
    current = provenance.gate_input_hashes()
    gate = load(B / 'gate-evidence.json')
    archive = load(B / 'gate-archive.json')
    verified = provenance.verify_gate_evidence(gate, sha(B / 'gate-full.log'), current)
    assert len(current) == 202 and archive['status'] == 'passed' and archive['generation'] == 24
    previous = load('tests/evidence/optimization/gen23/gate-evidence.json')['input_hashes_after']
    assert set(previous) < set(current)
    assert set(current) - set(previous) == {'Proofs/CommBValueReuse.lean', 'Proofs/CommBSemanticReuse.lean'}
    assert {p for p in previous if previous[p] != current[p]} == {'Impl/CommB.lean', 'Impl/Semantics.lean', 'Proofs/Decoder.lean', 'Proofs/CommBTables.lean', 'Proofs/CommBPenalty.lean'}
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
    fresh_completion_path = F / 'independent-review/fresh-completion.json'
    assert fixed_start['protected'] == ['.cache/reserved-velocity-proposal', '.cache/gen15-interrupted-gate', load(fresh_completion_path)['raw_scratch_deleted']]
    selection = load(B / 'gate-cleanup-selection.json')
    assert selection['gate_evidence_sha256'] == sha(B / 'gate-evidence.json')
    assert selection['gate_log_sha256'] == sha(B / 'gate-full.log')
    assert selection['fresh_completion_sha256'] == sha(fresh_completion_path)
    assert list(selection['protected']) == fixed_start['protected']
    assert set(selection['selected'].values()) == set(fixed_start['scratch'])
    assert selection['selector_sha256']==sha(B/'select_finish_gate.py')
    assert selection['quiescence'].strip()
    for name,digest in selection['helper_hashes'].items():assert sha(name)==digest
    assert set(row['path'] for row in selection['inventory'] if row['within_gate_interval']) == set(fixed_start['scratch'])
    assert all(Path(row['path']).exists() and row['path'] not in fixed_start['scratch'] for row in selection['inventory'] if not row['within_gate_interval'])
    fixed_roots = fixed_start['scratch']
    assert len(fixed_roots) == len(set(fixed_roots)) == 5
    expected_prefixes = ['altitude-exhaustive-', 'reserved-velocity-', 'dte-exhaustive-', 'cpr-synthetic-', 'message-differential-']
    assert all(re.fullmatch(r'\.cache/' + prefix + r'[a-z0-9_]{8}', path) for path, prefix in zip(fixed_roots, expected_prefixes))
    assert fixed_roots == [r['directory'] for r in fixed_cleanup['results']]
    fixed_bytes = sum(f['identity']['allocated_bytes'] for row in fixed_cleanup['results'] for f in row['files'])
    assert fixed_cleanup['deleted_allocated_bytes'] == wrapper['deleted_allocated_bytes'] == fixed_bytes
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
    fresh = load(F / 'fresh-message/summary.json')
    fresh_review = load(F / 'independent-review/fresh-retention-review.json')
    replay = load(F / 'independent-review/comparison-replay.json')
    assert fresh_review['status'] == replay['status'] == 'passed' and not fresh_review['findings']
    for name, digest in fresh_review['bindings'].items():
        assert sha(name) == digest
    assert replay['summary_sha256'] == sha(F / 'fresh-message/summary.json')
    assert replay['retention_manifest_sha256'] == sha(F / 'fresh-retained-hashes.json')
    assert replay['full_coverage_and_counts_equal'] and replay['temporary_duplicate_outputs_removed']
    assert replay['message_counts'] == fresh_review['message_counts'] == fresh['message']['counts']
    completion = load(F / 'independent-review/fresh-completion.json')
    assert completion['status'] == 'passed' and completion['raw_files_deleted'] == 8
    recovery=load(B/'independent-review/fresh-recovery-review.json')
    assert recovery['status']=='passed' and not recovery['findings'] and recovery['no_cleanup_or_workload_executed']
    for name,digest in recovery['bindings'].items():assert sha(name)==digest
    assert completion['completion_reporting_correction']['cleanup_executions']==1
    assert not completion['completion_reporting_correction']['producer_or_replay_rerun']
    for name, digest in completion['bindings'].items():
        assert sha(name) == digest
    cleanup = load(F / 'post-fresh-cleanup/result.json')
    cleanup_start = load(F / 'post-fresh-cleanup/start.json')
    assert cleanup['status'] == 'completed' and cleanup['mode'] == 'apply'
    assert cleanup_start['caller_attests_quiescence'] and cleanup_start['mode'] == 'apply'
    assert cleanup_start['script_sha256'] == sha('review/diagnostics/cleanup_verified_scratch.py')
    assert cleanup_start['scratch'] == [completion['raw_scratch_deleted']]
    assert cleanup_start['protected'] == completion['all_protected_roots_preserved'] == [completion['fixed_gate_scratch_preserved'], '.cache/reserved-velocity-proposal', '.cache/gen15-interrupted-gate']
    assert completion['fixed_gate_scratch_preserved'] == fixed_roots[-1]
    assert datetime.fromisoformat(completion['completed_utc']) < datetime.fromisoformat(fixed_start['started_utc'])
    assert len(cleanup['results']) == 1 and cleanup['verified_gzip_archives'] == 8
    removed = cleanup['results'][0]
    assert removed['status'] == 'deleted' and removed['directory'] == completion['raw_scratch_deleted']
    assert not Path(removed['directory']).exists() and len(removed['files']) == 8
    fresh_bytes = sum(row['identity']['allocated_bytes'] for row in removed['files'])
    assert cleanup['deleted_allocated_bytes'] == completion['allocated_bytes_reclaimed'] == fresh_bytes
    for row in removed['files']:
        kept = row['retained']
        independently_read = fresh_review['raw_and_standalone_decompressed'][kept['path']]
        assert row['gzip_eof_verified'] and row['sha256'] == kept['raw_sha256'] == independently_read['sha256']
        assert row['identity']['bytes'] == kept['raw_bytes'] == independently_read['bytes']
        assert sha(kept['path']) == kept['compressed_sha256']
    retained_fresh = load(F / 'fresh-retained-hashes.json')['files']
    assert len(retained_fresh) == 33
    for name, row in retained_fresh.items():
        assert sha(name) == row['sha256'] and Path(name).stat().st_size == row['bytes']
    assert completion['source_count'] == 127 and completion['binary_count'] == 3 and completion['retained_members'] == 33
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
    # Bind the completed source-only finishing review, without reexecuting controllers.
    finishing_review=load(B/'independent-review/finishing-preparation-review.json')
    assert finishing_review['status']=='passed_read_only_preparation_review' and not finishing_review['findings']
    for name,digest in finishing_review['bindings'].items():assert sha(name)==digest
    preparation = load(B / 'benchmark-preparation/preparation.json')
    for path,h in preparation['files'].items(): assert sha(path) == h
    protocol = load(B / 'benchmark-preparation/execution-protocol.json')
    assert protocol['generation'] == 24 and protocol['commit'] is None and protocol['worker_sha256'] is None
    assert protocol['resolved_output'] is None and protocol['output_resolution']['source_parent'] == '.cache/bench-runs'
    assert protocol['output_resolution']['source_basename'] == 'gen24-<actual committed HEAD first 7 hex characters>'
    assert protocol['benchmark_command_template'][protocol['benchmark_command_template'].index('--output')+1] == '.cache/bench-runs/gen24-<ACTUAL_COMMIT_FIRST_7>'
    assert protocol['archive_command_template'][protocol['archive_command_template'].index('--source')+1] == '.cache/bench-runs/gen24-<ACTUAL_COMMIT_FIRST_7>'
    for path,h in protocol['helpers'].items(): assert sha(path) == h
    assert Path('bench/GEN23.md').is_file() and not Path('bench/GEN24.md').exists()
    assert prep['status'] == 'passed' and prep['plan_sha256'] == sha(B / 'benchmark-preparation/plan.json')
    assert prep['fresh_verification_sha256'] == sha(F / 'fresh-final-verification.json')
    assert prep['gate_evidence_sha256'] == sha(B / 'gate-evidence.json')
    assert prep['helper_sha256'] == sha('review/diagnostics/archive_generation_benchmark_target.py')
    assert prep['helper_independent_review_sha256'] == sha('tests/evidence/optimization/cpr-overhead-reporting/independent-review.json')
    prior = Path(plan['prior_csv_snapshot']).read_bytes()
    assert prior == Path('bench/results.csv').read_bytes() == subprocess.check_output(['git', 'show', 'HEAD:bench/results.csv'])
    assert len(reporting.parse_prior_csv(prior, 24)) == plan['prior_csv_rows'] == 48
    assert hashlib.sha256(prior).hexdigest() == plan['prior_csv_sha256'] == prep['prior_csv_sha256']
    assert all(reporting.target_ratio(plan, mode) == (2, 1) for mode in ['decode', 'cpr'])
    assert not prep['measurement_started'] and not Path('bench/runs/gen24').exists()
    integration = load(B / 'integration/targeted-build.json')
    assert integration['status'] == 'passed' and integration['exit_code'] == 0
    assert integration['all_inputs_before'] == integration['all_inputs_after'] == current
    assert integration['command'] == ['lake', 'build', 'Proofs.Decoder', 'Proofs.CPRTracking', 'lean1090', 'messageGenerator', 'commbDifferential', 'lean1090-bench']
    assert integration['runner_sha256'] == sha(B / 'integration/run_production_build.py')
    assert integration['inventory_tool_sha256'] == sha('review/diagnostics/run_generation_benchmark.py')
    assert integration['log_sha256'] == sha(B / 'integration/targeted-build.log')
    assert integration['inputs_before'] == integration['inputs_after']
    assert set(integration['inputs_after']) == {'Impl/CommB.lean','Impl/Semantics.lean','Proofs/Decoder.lean','Proofs/CommBTables.lean','Proofs/CommBPenalty.lean','Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean'}
    for name, digest in integration['inputs_after'].items():
        assert current[name] == digest == sha(B / 'integration' / integration['attempt'] / 'sources' / name)
    for name, digest in integration['binary_hashes'].items():
        assert sha(Path('.lake/build/bin') / name) == digest
    native = load(B / 'native-review/review.json')
    native_inputs = load(B / 'native-review/native-inputs.json')
    assert native_inputs['all_inputs_unchanged']
    assert native_inputs['integration_record_sha256'] == sha(B / 'integration/targeted-build.json')
    assert sha(native_inputs['worker']) == native_inputs['worker_sha256']
    assert native['status'] == 'passed' and native['findings'] == []
    for name, digest in native_inputs['held_inputs'].items():
        assert sha(name) == digest
    for name, digest in native['bindings'].items():
        assert sha(name) == digest
    for name, row in native['files'].items():
        assert sha(name) == row['sha256'] and Path(name).stat().st_size == row['bytes']
    for digest, name in [line.split('  ', 1) for line in Path('spec.lock').read_text().splitlines()]:
        assert sha(name) == digest
    history = load(F / 'preparation.json')
    pending_history = {
        'tests/evidence/diagnostics/gen23/independent-review/independent-review.json',
        'tests/evidence/diagnostics/gen23-cpr/independent-review/independent-review.json',
        'tests/evidence/diagnostics/gen23/cleanup-receipt.json',
        'tests/evidence/diagnostics/gen23-cpr/cleanup-receipt.json',
    }
    history_committed, history_pending = {}, {}
    for name, digest in history['history_bindings'].items():
        assert sha(name) == digest
        committed = subprocess.run(['git', 'show', 'HEAD:' + name], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if committed.returncode == 0:
            assert hashlib.sha256(committed.stdout).hexdigest() == digest
            history_committed[name] = digest
        else:
            assert name in pending_history and committed.returncode == 128
            assert b'not in' in committed.stderr
            assert load(name)['status'] == ('completed' if name.endswith('/cleanup-receipt.json') else 'passed')
            history_pending[name] = digest
    assert set(history_pending) == pending_history
    source_review = load(B / 'independent-review/source-proof-review.json')
    assert source_review['status'] == 'passed' and not source_review['findings']
    for name, digest in source_review['bindings'].items():
        assert sha(name) == digest
    assert source_review['all_input_refinement_verified']
    assert source_review['printed_fact_count'] == 21 and len(source_review['kernel_witnesses']) == 11
    assert native['commb_semantic_reuse_live_path_verified'] and native['linked_native_sets'] == 22
    assert native['unchanged_sibling_native_sets'] == 20 and native['source_delta'] == ['Impl/CommB.lean','Impl/Semantics.lean']
    integrated_log = (B / 'integration/targeted-build.log').read_text()
    integrated_facts = re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]", integrated_log)
    integrated_pure = re.findall(r"'([^']+)' does not depend on any axioms", integrated_log)
    assert len(integrated_facts) == 337 and len(integrated_pure) == 9
    assert all({x.strip() for x in raw.split(',') if x.strip()} <= {'propext','Classical.choice','Quot.sound'} for _,raw in integrated_facts)
    integrated_validation = load(B / 'integration/validation.json')
    assert integrated_validation['build_record_sha256'] == sha(B / 'integration/targeted-build.json')
    assert len({n for n,_ in integrated_facts} | set(integrated_pure)) == integrated_validation['printed_fact_count'] == 346
    actual_axioms = {n: [x.strip() for x in raw.split(',') if x.strip()] for n,raw in integrated_facts}
    actual_axioms.update({n: [] for n in integrated_pure})
    assert {row['name']:row['axioms'] for row in integrated_validation['printed_axiom_facts']} == actual_axioms
    assert integrated_validation['audited_source_count'] == 127
    assert integrated_validation['all_printed_axioms_permitted']
    for path,h in integrated_validation['audited_source_hashes'].items(): assert sha(path) == h

    assert current['.gitignore'] == previous['.gitignore']
    preflight = load(F / 'fresh-preflight.json')
    assert len(preflight['source_sha256']) == 127 and len(preflight['binary_sha256']) == 3
    assert all(current[name] == digest for name, digest in preflight['source_sha256'].items())
    assert len(Path('spec.lock').read_text().splitlines()) == 104
    post=load(B/'post-gate-verification.json')
    assert post['status']=='passed_after_fixed_archive_and_plan' and post['all_correctness_inputs_unchanged']==202
    assert post['all_four_binaries_unchanged'] and post['all_five_selected_roots_absent'] and post['both_historical_unique_roots_present']
    assert post['gate_archive_sha256']==sha(B/'gate-archive.json') and post['benchmark_plan_sha256']==sha(B/'benchmark-preparation/plan.json')
    assert post['verifier_sha256']==sha(B/'verify_post_gate.py')
    assert provenance.gate_input_hashes() == current
    result = {'status': 'passed', 'reviewed_utc': datetime.now(timezone.utc).isoformat(), 'findings': [],
              'script_sha256': sha(__file__), 'gate_verification': verified, 'gate_inputs': 202,
              'proof_review_independence': 'Root authored the two runtime files and existing proof bridges; cost_analysis authored scalar reuse and payload_roundtrips authored numeric/full semantic reuse. This reviewer independently assessed all seven sources, unrestricted old-body equalities, actual list-sharing native paths and frozen live adapters.',
              'history_committed_at_review': history_committed, 'history_pending_current_commit': history_pending,
              'contracts': 23, 'kernel_witnesses': 152, 'unit_assertions': 1011,
              'integrated_axiom_list_facts': len(integrated_facts), 'integrated_axiom_free_facts': len(integrated_pure),
              'components': names, 'retained_component_files': file_count,
              'fixed_counts': summaries['message']['message']['counts'], 'fresh_counts': fresh['message']['counts'],
              'fixed_seed': summaries['message']['seed'], 'fresh_seed': fresh['seed'], 'coverage_each': [32, 70, 14],
              'prior_csv_rows': 48, 'target_ratios': {'decode': [2, 1], 'cpr': [2, 1]},
              'fresh_cleanup': {'files': 8, 'allocated_bytes': fresh_bytes,
                                'complete_retained_copies_rechecked': True},
              'fixed_cleanup': {'roots': fixed_roots, 'files': 26, 'allocated_bytes': fixed_bytes,
                                'archive_flush_before_cleanup': True, 'decompressed_retained_copies': fixed_raw},
              'bindings': {str(B / p): sha(B / p) for p in [
                  'gate-evidence.json', 'gate-full.log', 'gate-archive.json',
                  'fresh-retained-hashes.json', 'fresh-final-verification.json',
                  'native-review/review.json', 'native-review/native-inputs.json',
                  'independent-review/fresh-retention-review.json', 'independent-review/comparison-replay.json',
                  'independent-review/fresh-completion.json', 'independent-review/fresh-recovery-review.json', 'complete_after_cleanup.py', 'completion-recovery-01.log', 'finish-execution-01.json', 'finish-controller-01.log', 'post-fresh-cleanup/result.json',
                  'post-gate-archive-cleanup/result.json', 'post-gate-archive-cleanup/archive-flush.json',
                  'benchmark-preparation/plan.json', 'benchmark-preparation/preparation-verification.json',
                  'independent-review/source-proof-review.json', 'proof-values/summary.json', 'proof-semantics/summary.json',
                  'benchmark-preparation/prepare.py', 'benchmark-preparation/prepare.adaptation.diff',
                  'benchmark-preparation/preparation.json', 'benchmark-preparation/execution-protocol.json',
                  'benchmark-preparation/plan-pending.json',
                  'integration/targeted-build.json', 'integration/targeted-build.log', 'integration/validation.json',
                  'integration/validate_build.py',
                  'independent-review/check_gate.py', 'independent-review/check_gate.py.adaptation.diff',
                  'independent-review/reviewer-preparation.json', 'independent-review/gate-ready-adaptation.json', 'independent-review/finishing-preparation-review.json', 'independent-review/build-preparation-review.json', 'select_finish_gate.py', 'verify_post_gate.py', 'gate-cleanup-preparation.json',
                  'gate-cleanup-selection.json', 'post-gate-verification.json', 'preparation.json']},
              'limits': 'Read-only review; prior generation evidence is bound through its sealed reviews and exact CSV prefix, without recopying historical files. Raw scratch cleanup is separately authorized and receipted after archival.'}
    OUT.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'review_sha256': sha(OUT), 'gate_inputs': 202, 'components': 7}))


if __name__ == '__main__':
    main()
