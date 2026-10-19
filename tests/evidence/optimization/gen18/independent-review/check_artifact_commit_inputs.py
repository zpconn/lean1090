#!/usr/bin/env python3
"""Bind gen18 result artifacts to the passing gate; no commit or native work."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
import os
from datetime import datetime, timezone
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import run_generation_benchmark as provenance

BASE = ROOT / 'tests/evidence/optimization/gen18'
OUT = BASE / 'independent-review'
BENCH = ROOT / 'bench/runs/gen18'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def git(*args):
    return subprocess.check_output(['git', *args], cwd=ROOT,
                                   env=dict(os.environ, GIT_OPTIONAL_LOCKS='0'))


def main():
    output = OUT / 'artifact-commit-source-binding.json'
    assert not output.exists(), 'refuse to overwrite an earlier artifact binding'
    review = load(BENCH / 'results-review.json')
    assert review['status'] == 'passed' and review['findings'] == []
    assert sha(BENCH / 'results-review.json') == '26224c15327d4378b3aeba5d3885057ed93b95896e8f2b5c333ae47e58ff0bb8'
    assert review['total_samples'] == 96 and review['checks_passed'] == 679
    assert review['decode_target_ratio'] == review['cpr_target_ratio'] == {'numerator': 2, 'denominator': 1}
    commit = review['commit']
    assert git('rev-parse', 'HEAD').decode().strip() == commit == 'c19e00dd6bd45c89e4d6238d4ea9973947625449'
    gate = load(BASE / 'gate-evidence.json')
    inputs = provenance.gate_input_hashes()
    assert len(inputs) == 190
    assert inputs == gate['input_hashes_before'] == gate['input_hashes_after']
    assert inputs == review['current_gate_input_sha256'] == load(BENCH / 'correctness-inputs.json')
    gate_validation = provenance.verify_gate_evidence(gate, sha(BASE / 'gate-full.log'), inputs)
    for path, expected in inputs.items():
        assert sha(ROOT / path) == expected == hashlib.sha256(git('cat-file', 'blob', commit + ':' + path)).hexdigest(), path
    assert sha(ROOT / '.lake/build/bin/lean1090-bench') == review['binary_sha256']
    assert git('config', 'user.name').decode().strip() == 'zpconn'
    assert git('config', 'user.email').decode().strip() == 'zpconn@gmail.com'
    assert git('show', '-s', '--format=%an <%ae>%n%cn <%ce>', commit).decode().splitlines() == ['zpconn <zpconn@gmail.com>'] * 2
    decisions = {r['mode']: r['medians_nanoseconds']['rs1090'] >= 2 * r['medians_nanoseconds']['lean1090']
                 for r in review['results']}
    assert decisions == {'decode': review['decode_threshold_reached'], 'cpr': review['cpr_threshold_reached']}
    assert all(decisions.values()) == review['all_mode_thresholds_reached']
    assert sha(ROOT / 'bench/GEN18.md') == review['report_sha256']
    assert sha(ROOT / 'bench/results.csv') == review['csv_after_sha256']
    paths = [BENCH / name for name in ('results-review.json', 'archive-verification.json', 'report-verification.json',
                                     'correctness-inputs.json', 'binary-built.json')]
    paths += [BASE / name for name in ('gate-evidence.json', 'gate-full.log', 'gate-archive.json', 'fresh/fresh-final-verification.json')]
    paths += [OUT / name for name in ('gate-review.json', 'check_benchmark_result.py',
                                     'benchmark-result-01.log', 'benchmark-result-02.log', 'check_benchmark_result-attempt-01.py', 'check_artifact_commit_inputs.py')]
    paths += [ROOT / 'bench/GEN18.md', ROOT / 'bench/results.csv']
    paths += [BASE / 'fresh/independent-review/fresh-completion.json', BASE / 'benchmark-preparation/plan.json']
    files = {str(p.relative_to(ROOT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in paths}
    status = git('status', '--porcelain=v1', '--untracked-files=all').decode()
    assert provenance.gate_input_hashes() == inputs
    record = {
        'status': 'passed_unchanged_gate_input_binding_for_artifact_commit',
        'recorded_utc': datetime.now(timezone.utc).isoformat(), 'timed_commit': commit,
        'correctness_input_count': len(inputs), 'gate_validation': gate_validation,
        'all_inputs_match_passed_full_gate_current_tree_and_timed_commit': True,
        'correctness_inventory': 'bench/runs/gen18/correctness-inputs.json',
        'correctness_inventory_sha256': sha(BENCH / 'correctness-inputs.json'),
        'files': files, 'current_git_status': status,
        'configured_identity': 'zpconn <zpconn@gmail.com>', 'target_ratio_each_mode': {'numerator': 2, 'denominator': 1},
        'exact_target_decisions': decisions, 'both_targets_reached': all(decisions.values()),
        'build_test_benchmark_or_git_mutation_performed': False, 'findings': [],
        'scope': 'The existing passing full gate covers every unchanged correctness input. This record binds the already-reviewed result artifacts for the parent-controlled artifact commit, without copying historical trees or running a replacement gate. Concurrent parent documentation updates are outside this correctness inventory.'}
    with output.open('x') as stream:
        json.dump(record, stream, indent=2)
        stream.write('\n')
    print(json.dumps({'status': record['status'], 'sha256': sha(output), 'correctness_inputs': len(inputs),
                      'bound_artifacts': len(files), 'both_targets_reached': all(decisions.values())}, indent=2))


if __name__ == '__main__':
    main()
