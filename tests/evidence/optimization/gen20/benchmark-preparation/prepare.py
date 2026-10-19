from datetime import datetime, timezone
from pathlib import Path
import hashlib
import json
import sys

sys.dont_write_bytecode = True
root = Path.cwd()
out = Path(__file__).resolve().parent
sys.path.insert(0, str(root / 'review/diagnostics'))
import archive_generation_benchmark_target as archive

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

helper = root / 'review/diagnostics/archive_generation_benchmark_target.py'
review = root / 'tests/evidence/optimization/cpr-overhead-reporting/independent-review.json'
assert sha(helper) == 'c180278ec4c561b48a03d4932dcd3c4576ce350da0673b93184a9403a50f2312'
assert sha(review) == '8318ed72d9250268730c26883efa711ac10a6b79d7faff173c30366ab558c231'
fresh = root / 'tests/evidence/optimization/gen20/fresh-final-verification.json'
gate = root / 'tests/evidence/optimization/gen20/gate-evidence.json'
assert json.loads(fresh.read_text())['status'] == 'passed'
assert json.loads(gate.read_text())['status'] == 'passed'
prior = root / 'bench/results.csv'
raw = prior.read_bytes()
assert len(archive.parse_prior_csv(raw, 20)) == 40
for name in ('results-before.csv', 'plan.json', 'preparation-verification.json'):
    assert not (out / name).exists()
assert not (root / 'bench/runs/gen20').exists()
assert not (root / 'bench/GEN20.md').exists()
(out / 'results-before.csv').write_bytes(raw)
plan = {
    'generation': 20,
    'prepared_utc': datetime.now(timezone.utc).isoformat(),
    'prior_csv_snapshot': str((out / 'results-before.csv').relative_to(root)),
    'prior_csv_sha256': sha(prior),
    'prior_csv_rows': 40,
    'fresh_verification': str(fresh.relative_to(root)),
    'fresh_verification_sha256': sha(fresh),
    'title': 'eight-bit CRC loop batching',
    'change_description': 'The live CRC path groups eight exact UInt32 updates per iteration for aligned widths through 128. Unconditional proofs preserve the original syndrome for every natural width and word, with the original bit loop as the live fallback. No lookup table, Float code, trusted primitive or corpus-specific branch is added. [Implementation and proof evidence](../docs/GEN20-BYTE-CRC.md).',
    'row_note': 'Proved eight-bit CRC loop batching; full fixed/fresh 10M validation; clean fresh build; CPU 0; 3+21 ABAB',
    'decode_target_ratio': {'numerator': 2, 'denominator': 1},
    'cpr_target_ratio': {'numerator': 2, 'denominator': 1},
    'review_threshold': 'Both decode and CPR must independently reach 2/1; exact integer comparisons of measured medians; stop for user review only when both hold.',
    'note': 'Prepared before timing. Contains no speculative measurement. The reviewed reporting helper only archives a completed run.',
}
for mode in ('decode', 'cpr'):
    assert archive.target_ratio(plan, mode) == (2, 1)
    assert archive.target_label(plan, mode) == '2.00'
(out / 'plan.json').write_text(json.dumps(plan, indent=2) + '\n')
verification = {
    'status': 'passed',
    'prepared_utc': datetime.now(timezone.utc).isoformat(),
    'plan_sha256': sha(out / 'plan.json'),
    'helper_sha256': sha(helper),
    'helper_independent_review_sha256': sha(review),
    'prior_csv_sha256': sha(prior),
    'prior_rows': 40,
    'fresh_status': 'passed',
    'fresh_verification_sha256': sha(fresh),
    'gate_evidence_sha256': sha(gate),
    'decode_target_ratio': plan['decode_target_ratio'],
    'cpr_target_ratio': plan['cpr_target_ratio'],
    'measurement_started': False,
}
(out / 'preparation-verification.json').write_text(json.dumps(verification, indent=2) + '\n')
print(json.dumps(verification, indent=2))
