#!/usr/bin/env python3
"""Bind the read-only gen7 proof review to the completed integrated build."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib
import json
import re
import subprocess

B = Path('tests/evidence/optimization/gen7')
R = B / 'independent-review'
def load(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
review = load(R / 'source-proof-review.json')
assert review['status'] == 'passed_source_and_universal_helper_proof_review'
for name, digest in review['source_sha256'].items(): assert sha(name) == digest
manifest = B / 'integration/targeted-build.json'
log = B / 'integration/targeted-build.log'
build = load(manifest)
assert build['attempt'] == 2 and build['exit_code'] == 0
assert build['command'] == ['lake', 'build', 'Proofs.Decoder', 'lean1090', 'messageGenerator', 'commbDifferential']
assert sha(log) == build['log_sha256'] == 'bb400edeb8ea22769af21c322bf69d21d033b50baafb1e149b027ef4ba78befd'
text = log.read_text()
assert 'Build completed successfully (3512 jobs).' in text and 'error:' not in text
facts = {}
for name, axioms in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]", text):
    actual = sorted(x.strip() for x in axioms.split(',') if x.strip())
    assert set(actual) <= {'propext', 'Classical.choice', 'Quot.sound'}
    facts[name] = actual
for name in ['Lean1090.Proofs.ScoreGateInteger.choose_eq_old', 'Lean1090.Proofs.ScoreGate.choose_eq',
             'Lean1090.Proofs.ScoreGate.choose_at_threshold', 'Lean1090.Proofs.Refinement',
             'Lean1090.Proofs.PrefixRefinement']:
    assert name in facts
prior = subprocess.check_output(['git', 'cat-file', 'blob', 'HEAD:Proofs/ScoreGate.lean']).decode()
expected = prior.replace('import Impl.ScoreGate\n', 'import Impl.ScoreGate\nimport Proofs.ScoreGateInteger\n')
expected = expected.replace('  unfold Impl.ScoreGate.choose\n', '  rw [ScoreGateInteger.choose_eq_old]\n')
expected = expected.replace('  dsimp only\n', '')
assert Path('Proofs/ScoreGate.lean').read_text() == expected
assert Path('Proofs/Decoder.lean').read_bytes() == subprocess.check_output(['git', 'cat-file', 'blob', 'HEAD:Proofs/Decoder.lean'])
failed_manifest = B / 'integration/targeted-build-01-failed.json'
failed_log = B / 'integration/targeted-build-01-failed.log'
failed = load(failed_manifest)
assert failed['exit_code'] == 1 and sha(failed_log) == failed['log_sha256']
assert '`dsimp` made no progress' in failed_log.read_text()
errors = [x for x in failed_log.read_text().splitlines() if x.startswith('error:')]
assert errors == ['error: Proofs/ScoreGate.lean:32:2: `dsimp` made no progress', 'error: build failed']
final_sources = {p: sha(p) for p in ['Impl/ScoreGate.lean', 'Proofs/ScoreGateInteger.lean', 'Proofs/ScoreGate.lean', 'Proofs/Decoder.lean']}
out = {
    'status': 'passed_integrated_build_and_universal_refinement_review',
    'reviewed_utc': datetime.now(timezone.utc).isoformat(),
    'prior_source_review_sha256': sha(R / 'source-proof-review.json'),
    'final_source_sha256': final_sources,
    'successful_integrated_build': {'manifest': str(manifest), 'manifest_sha256': sha(manifest),
                                    'log': str(log), 'log_sha256': sha(log), 'exit_code': 0, 'jobs': 3512,
                                    'started_at': build['started_at'], 'finished_at': build['finished_at'], 'attempt': 2},
    'retained_failed_integration': {'manifest': str(failed_manifest), 'manifest_sha256': sha(failed_manifest),
                                  'log': str(failed_log), 'log_sha256': sha(failed_log),
                                  'cause': 'The helper rewrite already removed let bindings, so the old dsimp-only tactic made no progress. Removing that tactic changed no theorem statement or hypothesis. Error-recovery sorryAx entries belong only to the failed elaboration log.'},
    'all_successful_printed_axioms': facts,
    'integration_change': 'One import and rewrite through universal choose_eq_old; obsolete dsimp removed. Remaining binary64 error-bound argument and unchanged Decoder refinement continue through the same public choose entrypoint.',
    'findings': [],
    'review_script_sha256': sha(__file__),
    'limits': 'Read-only review of sources and completed build records; no compiler, decoder or tests run by this reviewer. Complete fixed/fresh gate and native-code checks remain separate.'
}
p = R / 'integration-review.json'
assert not p.exists()
p.write_text(json.dumps(out, indent=2) + '\n')
print(json.dumps({'status': out['status'], 'sha256': sha(p), 'successful_axiom_facts': len(facts)}, indent=2))
