#!/usr/bin/env python3
"""Bind the reviewed result artifact to the already-passed unchanged gate inputs."""
import sys
sys.dont_write_bytecode = True
import hashlib, importlib.util, json, os, subprocess
from datetime import datetime, timezone
from pathlib import Path

BASE = Path('tests/evidence/optimization/gen15')
OUT = BASE / 'independent-review'
BENCH = Path('bench/runs/gen15')
def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for data in iter(lambda: stream.read(4 * 1024 * 1024), b''): h.update(data)
    return h.hexdigest()
def load(path): return json.loads(Path(path).read_text())
env = dict(os.environ, GIT_OPTIONAL_LOCKS='0', PYTHONDONTWRITEBYTECODE='1')
def git(*args): return subprocess.check_output(['git', *args], env=env)
spec = importlib.util.spec_from_file_location('artifact_commit_provenance', 'review/diagnostics/run_generation_benchmark.py')
provenance = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = provenance
spec.loader.exec_module(provenance)
review = load(BENCH / 'results-review.json')
assert review['status'] == 'passed_with_documented_clock_and_host_limitations' and review['findings'] == []
assert review['threshold']['reached'] and review['threshold']['ratio'] == {'numerator':3, 'denominator':2}
assert review['checks_passed'] == 2026 and review['protocol']['samples_reviewed'] == 96
commit = review['timed_commit']
assert git('rev-parse', 'HEAD').decode().strip() == commit == 'e659220307538f2aee5398efdb0a9182bff1d778'
gate = load(BASE / 'gate-evidence.json')
inputs = provenance.gate_input_hashes()
assert gate['status'] == 'passed' and gate['exit_code'] == 0
assert gate['input_hashes_before'] == gate['input_hashes_after'] == inputs and len(inputs) == 186
assert provenance.verify_gate_evidence(gate, sha(BASE/'gate-full.log'), inputs)
for path, expected in inputs.items():
    assert sha(path) == expected == hashlib.sha256(git('cat-file','blob',commit+':'+path)).hexdigest(), path
assert sha('.lake/build/bin/lean1090-bench') == review['binary_sha256']
assert sha('spec.lock') == review['spec_lock_sha256']
assert git('config','user.name').decode().strip() == 'zpconn'
assert git('config','user.email').decode().strip() == 'zpconn@gmail.com'
assert git('show','-s','--format=%an <%ae>',commit).decode().strip() == 'zpconn <zpconn@gmail.com>'
status = git('status','--porcelain=v1','--untracked-files=all').decode()
assert provenance.gate_input_hashes() == inputs
paths = [BENCH/'results-review.json', BENCH/'archive-verification.json', BENCH/'report-verification.json',
         Path('bench/GEN15.md'),Path('bench/results.csv'), BASE/'gate-evidence.json', BASE/'gate-full.log',
         OUT/'gate-review.json',OUT/'gate-review-completion.json',OUT/'benchmark-bindings.json',
         OUT/'benchmark-review-01.log',OUT/'benchmark-history-01.log',OUT/'results-review-before-history.json',
         OUT/'check_benchmark_review.py',OUT/'check_benchmark_history.py',Path(__file__)]
record = {'status':'passed_unchanged_gate_input_binding_for_artifact_commit',
          'recorded_utc':datetime.now(timezone.utc).isoformat(), 'timed_commit':commit,
          'correctness_input_count':len(inputs), 'correctness_inputs':inputs,
          'all_inputs_match_passed_full_gate_current_tree_and_timed_commit':True,
          'benchmark_review_sha256':sha(BENCH/'results-review.json'),
          'files':{str(path):{'sha256':sha(path),'bytes':path.stat().st_size} for path in paths},
          'current_git_status':status, 'configured_identity':'zpconn <zpconn@gmail.com>',
          'target_reached_exactly':review['threshold'], 'build_test_benchmark_or_git_mutation_performed':False,
          'scope':'The existing full gate covers every unchanged correctness input. This read-only record binds the result/documentation artifacts for the parent-controlled artifact commit; it does not create a commit or run a replacement gate.',
          'findings':[]}
path = OUT/'artifact-commit-source-binding.json'
assert not path.exists()
path.write_text(json.dumps(record,indent=2,sort_keys=True)+'\n')
print(json.dumps({'status':record['status'],'sha256':sha(path),'review_sha256':record['benchmark_review_sha256'],'correctness_inputs':len(inputs)},indent=2))
