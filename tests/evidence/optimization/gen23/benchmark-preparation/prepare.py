"""Finalize a pre-timing plan only after existing validation records pass.

Never builds, runs or archives a benchmark. The pending plan and exact CSV
prefix remain immutable; completed validation bindings go into new files.
"""
import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
from pathlib import Path
import hashlib
import json

root = Path.cwd()
out = Path(__file__).resolve().parent
sys.path.insert(0, str(root / 'review/diagnostics'))
import archive_generation_benchmark_target as archive


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


pending = out / 'plan-pending.json'
assert sha(pending) == '07ef4d93ce00a5a265adfbe38ab483675fd3d3d989601ff854ace85e5f96e49c'
plan = read(pending)
assert plan['status'] == 'pending_validation_not_ready_for_timing'
assert plan['generation'] == 23
reporting = plan['reporting_helper']
assert sha(root / reporting['path']) == reporting['sha256']
assert sha(root / reporting['independent_review']) == reporting['independent_review_sha256']
raw = (root / 'bench/results.csv').read_bytes()
assert raw == (root / plan['prior_csv_snapshot']).read_bytes()
assert sha(root / 'bench/results.csv') == plan['prior_csv_sha256']
assert len(archive.parse_prior_csv(raw, 23)) == plan['prior_csv_rows'] == 46
requirements = plan['requirements']
gate = read(root / requirements['full_gate'])
fresh = read(root / plan['fresh_verification'])
completion = read(root / requirements['fresh_completion'])
native = read(root / requirements['native_review'])
build = read(root / requirements['combined_build'])
assert all(record['status'] == 'passed' for record in (gate, fresh, completion, native, build))
assert gate['command'] == requirements['fixed_gate_command']
assert gate['generated_messages'] == requirements['fixed_generated_messages'] == 10_000_000
assert gate['exit_code'] == 0 and gate['input_hashes_equal']
assert gate['input_hashes_before'] == gate['input_hashes_after']
assert len(gate['input_hashes_after']) == requirements['correctness_inputs'] == 200
for name, digest in gate['input_hashes_after'].items():
    assert sha(root / name) == digest, name
assert not native['findings'] and native['all_inputs_unchanged']
assert native['commb_validity_tables_live_path_verified']
assert native['linked_native_sets'] == requirements['native_sets'] == 22
assert native['integration_record_sha256'] == sha(root / requirements['combined_build'])
for name, digest in native['held_inputs'].items():
    assert sha(root / name) == digest, name
assert completion['source_count'] == requirements['fresh_source_count'] == 125
assert completion['binary_count'] == requirements['fresh_binary_count'] == 3
assert completion['retained_members'] == requirements['fresh_retained_members'] == 33
assert completion['full_coverage_reproduced'] and completion['decompressed_diagnostic_streams_reproduced']
assert completion['source_and_binary_hashes_rechecked_after_cleanup']
assert completion['native_held_inputs_rechecked']
for name in ('plan.json', 'preparation-verification.json'):
    assert not (out / name).exists(), 'Preserve prior preparation attempts.'
assert not (root / 'bench/runs/gen23').exists()
assert not (root / 'bench/GEN23.md').exists()
plan.update(status='prepared_validation_passed_not_measured',
            prepared_utc=datetime.now(timezone.utc).isoformat(),
            pending_plan_sha256=sha(pending),
            fresh_verification_sha256=sha(root / plan['fresh_verification']),
            validation_bindings={key: {'path': requirements[key], 'sha256': sha(root / requirements[key])}
                                 for key in ('full_gate', 'fresh_completion', 'native_review', 'combined_build')},
            note='Prepared after completed fixed/fresh/native validation and before timing. Contains no speculative measurement. The unchanged reviewed reporting helper archives only completed measurements.')
del plan['pending_bindings']
for mode in ('decode', 'cpr'):
    assert archive.target_ratio(plan, mode) == (2, 1)
    assert archive.target_label(plan, mode) == '2.00'
(out / 'plan.json').write_text(json.dumps(plan, indent=2) + '\n')
verification = {'status': 'passed', 'prepared_utc': plan['prepared_utc'],
                'plan_sha256': sha(out / 'plan.json'), 'pending_plan_sha256': sha(pending),
                'helper_sha256': reporting['sha256'],
                'helper_independent_review_sha256': reporting['independent_review_sha256'],
                'prior_csv_sha256': plan['prior_csv_sha256'], 'prior_rows': 46,
                'fresh_status': 'passed', 'fresh_verification_sha256': plan['fresh_verification_sha256'],
                'gate_evidence_sha256': sha(root / requirements['full_gate']),
                'validation_bindings': plan['validation_bindings'],
                'decode_target_ratio': plan['decode_target_ratio'],
                'cpr_target_ratio': plan['cpr_target_ratio'], 'measurement_started': False}
(out / 'preparation-verification.json').write_text(json.dumps(verification, indent=2) + '\n')
print(json.dumps(verification, indent=2))
