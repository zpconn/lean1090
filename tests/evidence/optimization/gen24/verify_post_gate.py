#!/usr/bin/env python3
"""Read-only post-archive bindings; writes only a new producer verification."""
import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[4]
BASE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import run_generation_benchmark as provenance


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(4 * 1024 * 1024), b''):
            digest.update(chunk)
    return digest.hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def main():
    output = BASE / 'post-gate-verification.json'
    assert not output.exists()
    gate, archive = load(BASE / 'gate-evidence.json'), load(BASE / 'gate-archive.json')
    inputs = provenance.gate_input_hashes()
    assert len(inputs) == 202 and gate['input_hashes_before'] == gate['input_hashes_after'] == inputs
    provenance.verify_gate_evidence(gate, sha(BASE / 'gate-full.log'), inputs)
    build = load(BASE / 'integration/targeted-build.json')
    assert build['status'] == 'passed' and len(build['binary_hashes']) == 4
    for name, digest in build['binary_hashes'].items():
        assert sha(ROOT / '.lake/build/bin' / name) == digest, name
    assert archive['status'] == 'passed' and archive['generation'] == 24
    assert archive['correctness_inputs_unchanged'] and archive['originals_unchanged']
    assert archive['gate_evidence_sha256'] == sha(BASE / 'gate-evidence.json')
    assert archive['gate_log_sha256'] == sha(BASE / 'gate-full.log')
    assert set(archive['components']) == {'altitude', 'reserved_velocity', 'dte', 'cpr', 'message', 'numeric', 'tracking'}
    files, byte_count = 0, 0
    for component in archive['components'].values():
        for row in component['retained_files'].values():
            p = ROOT / row['path']
            assert p.is_file() and p.stat().st_size == row['bytes'] and sha(p) == row['sha256'], p
            files += 1; byte_count += row['bytes']
        for row in component['versioned_metadata'].values():
            p = ROOT / row['path']
            assert p.is_file() and p.stat().st_size == row['bytes'] and sha(p) == row['sha256'], p
    assert files == 62
    selection = load(BASE / 'gate-cleanup-selection.json')
    result_path = BASE / 'post-gate-archive-cleanup/result.json'
    result = load(result_path)
    cleanup_path = BASE / 'post-gate-archive-cleanup/cleanup/result.json'
    cleanup = load(cleanup_path)
    assert result['status'] == cleanup['status'] == 'completed' and cleanup['mode'] == 'apply'
    assert result['gate_archive_sha256'] == sha(BASE / 'gate-archive.json')
    assert result['cleanup_result_sha256'] == sha(cleanup_path)
    assert len(cleanup['results']) == 5
    assert {row['directory'] for row in cleanup['results']} == set(selection['selected'].values())
    for row in cleanup['results']:
        assert row['status'] == 'deleted' and not (ROOT / row['directory']).exists()
        for file in row['files']:
            assert file['gzip_eof_verified'] and file['sha256'] == file['retained']['raw_sha256']
            assert file['identity']['bytes'] == file['retained']['raw_bytes']
    assert result['deleted_allocated_bytes'] == cleanup['deleted_allocated_bytes']
    for name, record in selection['protected'].items():
        assert (ROOT / name).exists() == record['exists'], name
    fresh_path = BASE / 'independent-review/fresh-completion.json'
    fresh = load(fresh_path)
    assert fresh['status'] == 'passed' and sha(fresh_path) == selection['fresh_completion_sha256']
    plan_path = BASE / 'benchmark-preparation/plan.json'
    plan, verification = load(plan_path), load(BASE / 'benchmark-preparation/preparation-verification.json')
    assert plan['status'] == 'prepared_validation_passed_not_measured' and plan['generation'] == 24
    assert verification['status'] == 'passed' and verification['plan_sha256'] == sha(plan_path)
    assert plan['prior_csv_rows'] == 48 and sha(ROOT / 'bench/results.csv') == plan['prior_csv_sha256']
    for mode in ('decode', 'cpr'):
        assert plan[mode + '_target_ratio'] == {'numerator': 2, 'denominator': 1}
    for row in plan['validation_bindings'].values():
        assert sha(ROOT / row['path']) == row['sha256']
    assert not (ROOT / 'bench/runs/gen24').exists() and not (ROOT / 'bench/GEN24.md').exists()
    assert provenance.gate_input_hashes() == inputs
    record = dict(status='passed_after_fixed_archive_and_plan', verified_utc=datetime.now(timezone.utc).isoformat(),
        all_correctness_inputs_unchanged=len(inputs), all_four_binaries_unchanged=True,
        gate_evidence_sha256=sha(BASE / 'gate-evidence.json'), gate_log_sha256=sha(BASE / 'gate-full.log'),
        gate_archive_sha256=sha(BASE / 'gate-archive.json'), archive_components=7, archive_files=files, archive_bytes=byte_count,
        cleanup_selection_sha256=sha(BASE / 'gate-cleanup-selection.json'), cleanup_result_sha256=sha(result_path),
        deleted_allocated_bytes=cleanup['deleted_allocated_bytes'], all_five_selected_roots_absent=True,
        both_historical_unique_roots_present=True, fresh_completion_sha256=sha(fresh_path),
        benchmark_plan_sha256=sha(plan_path),
        benchmark_preparation_verification_sha256=sha(BASE / 'benchmark-preparation/preparation-verification.json'),
        native_review_sha256=sha(BASE / 'native-review/review.json'),
        all_gate_archive_preparation_jobs_stopped=True, benchmark_executed=False,
        verifier_sha256=sha(__file__), final_independent_review='Pending FC review; this producer record does not claim independent approval.')
    with output.open('x') as stream:
        json.dump(record, stream, indent=2); stream.write('\n')
    print(json.dumps({'status': record['status'], 'sha256': sha(output), 'archive_files': files,
                      'deleted_allocated_bytes': cleanup['deleted_allocated_bytes']}))


if __name__ == '__main__':
    main()
