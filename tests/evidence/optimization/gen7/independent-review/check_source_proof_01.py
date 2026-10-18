#!/usr/bin/env python3
"""Read-only gen7 source/proof review; consumes the owner's successful build."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib
import json
import re
import subprocess

B = Path('tests/evidence/optimization/gen7')
R = B / 'independent-review'
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p): return json.loads(Path(p).read_text())
def old(p): return subprocess.check_output(['git', 'cat-file', 'blob', 'HEAD:' + p]).decode()

summary = load(B / 'proof/summary.json')
assert summary['status'] == 'passed' and summary['successful_attempt'] == 4
expected = {
    'Impl/ScoreGate.lean': '471a48cecb1f4374dcced2adaec0bd5a639aa61d8f47ec80e9a23af9aafe7776',
    'Proofs/ScoreGateInteger.lean': '2927ea9e43a7fb539b96ef2624548177ff273862033d5963e7470e0b03631d9e',
}
assert summary['source_sha256'] == expected
for name, digest in expected.items(): assert sha(name) == digest
runtime = Path('Impl/ScoreGate.lean').read_text()
proof = Path('Proofs/ScoreGateInteger.lean').read_text()
prior = old('Impl/ScoreGate.lean')
assert runtime[:runtime.index('/-- A positive common denominator')] == prior[:prior.index('/-- Decide the inclusive -3 threshold')]
assert re.findall(r'^import (.+)$', runtime, re.M) == ['Std']
for name in expected:
    code = re.sub(r'/\-.*?\-/', '', Path(name).read_text(), flags=re.S)
    code = re.sub(r'--[^\n]*', '', code)
    assert not re.search(r'\b(sorry|admit|native_decide|unsafe|partial)\b|\b(panic|get|unreachable)!|@\[(implemented_by|extern)', code)
    assert not re.search(r'^\s*axiom\s', code, re.M)
statement = proof[proof.index('theorem choose_eq_old '):proof.index(' := by', proof.index('theorem choose_eq_old '))]
assert statement == '''theorem choose_eq_old (terms : List Rat) (penalty : Rat) (fallback : Unit → Bool) :
    choose terms penalty fallback =
      (if center terms penalty - envelope terms penalty ≥ -3 then true
       else if center terms penalty + envelope terms penalty < -3 then false
       else fallback ())'''
assert 'let largest := denominators.foldl max 1' in runtime
assert 'if denominators.all (fun d => largest % d == 0) then largest' in runtime
assert 'else denominators.prod' in runtime
assert 'value.num * (denominator / value.den : Nat)' in runtime
assert 'let n : Int := max terms.length 1' in runtime
assert 'let threshold := -3 * n * denominator * 1099511627776' in runtime
assert 'if scaledCenter - scaledError ≥ threshold then true' in runtime
assert 'else if scaledCenter + scaledError < threshold then false' in runtime
assert runtime.count('else fallback ()') == 1
assert '@[noinline] def choose ' in runtime

log_path = Path(summary['successful_log'])
log = log_path.read_text()
assert sha(log_path) == summary['successful_log_sha256'] == 'f71f4df962a0fa0d2e10153ea043bb59e64c5b250e1c69c8edf5ac1ab4d1ed37'
assert 'Build completed successfully (2041 jobs).' in log and 'error:' not in log
facts = {}
for name, axioms in re.findall(r"'Lean1090.Proofs.ScoreGateInteger\.([^']+)' depends on axioms:\s*\[([^\]]*)\]", log):
    actual = sorted(x.strip() for x in axioms.split(',') if x.strip())
    assert set(actual) <= {'propext', 'Classical.choice', 'Quot.sound'}
    facts[name] = actual
assert len(facts) == 12
assert set(summary['witnesses']) <= set(facts) and len(summary['witnesses']) == 7
assert 'choose_eq_old' in facts
commb = Path('Impl/CommB.lean').read_text()
assert commb == old('Impl/CommB.lean')
assert 'ScoreGate.choose' in commb and 'fun _ => cbCombinedScore' in commb
locked = {}
frozen_score_references = []
for line in Path('spec.lock').read_text().splitlines():
    match = re.fullmatch(r'([0-9a-f]{64})\s+(.+)', line)
    if match:
        digest, name = match.groups(); assert sha(name) == digest; locked[name] = digest
        if name.endswith('.lean') and 'Impl.ScoreGate' in Path(name).read_text(): frozen_score_references.append(name)
assert len(locked) == 104 and not frozen_score_references

out = {
    'status': 'passed_source_and_universal_helper_proof_review',
    'reviewed_utc': datetime.now(timezone.utc).isoformat(),
    'source_sha256': expected,
    'unchanged_live_commb_source_sha256': sha('Impl/CommB.lean'),
    'proof_summary_sha256': sha(B / 'proof/summary.json'),
    'successful_helper_log': str(log_path), 'successful_helper_log_sha256': sha(log_path),
    'printed_axioms': facts,
    'witnesses': summary['witnesses'],
    'universal_statement': statement,
    'frozen_file_hashes_checked': len(locked),
    'frozen_direct_ScoreGate_references': frozen_score_references,
    'review_script_sha256': sha(__file__),
    'findings': [],
    'reasoning': [
        'The maximum starts at one, so its branch is positive; the other branch multiplies positive canonical Rat denominators. Every denominator divides the selected value, by the checked remainder predicate or list-product membership.',
        'scaledNumerator uses an exact divisible Nat quotient. Rat.natCast_div and num_div_den prove that its integer cast is D times the original rational, including negative numerators. The absolute numerator identity uses nonnegative D.',
        'A universal fold lemma proves the two accumulated integers are D times the signed term sum and absolute term sum. It assumes divisibility only locally; commonDenominator establishes that for every input.',
        'n=max(length,1) is positive. The empty-list branch has zero mean; nonempty lists clear their actual positive length. Therefore C=n*D*center and E=D*K*envelope for K=2^40.',
        'The positive scale n*D*K preserves the exact lower >= -3 and upper < -3 comparisons, including equality. The universal theorem assumes neither short lists nor dyadic inputs nor a particular fallback result.',
        'The complete software fallback remains the same thunk at the sole uncertainty branch. Runtime source imports only Std and uses unbounded Nat/Int operations; no approximation, floating-point primitive, corpus condition or cross-message state is added.',
        'The original mass, center and envelope definitions remain byte-identical. Impl.CommB is byte-identical and still invokes live choose with cbCombinedScore as the fallback; no frozen adapter is redirected to a dead legacy implementation.'
    ],
    'limits': [
        'This review consumes the successful helper build and its printed axioms; it performs no compiler, test or native execution.',
        'The integrated decoder build, generated-C laziness review and complete fixed/fresh differential campaigns are separate pending checks.',
        'No performance claim follows from the source/proof review. The product denominator can be large for arbitrary non-dyadic lists; the theorem establishes exact behavior, not a universal speed bound.'
    ]
}
p = R / 'source-proof-review.json'
assert not p.exists()
p.write_text(json.dumps(out, indent=2) + '\n')
print(json.dumps({'status': out['status'], 'sha256': sha(p), 'axiom_facts': len(facts)}, indent=2))
