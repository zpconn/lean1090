#!/usr/bin/env python3
"""Bind gen24 result artifacts to the passing gate; no commit or native work."""
import sys
sys.dont_write_bytecode = True
import argparse
import hashlib
import json
import os
from datetime import datetime, timezone
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import run_generation_benchmark as provenance

BASE = ROOT / 'tests/evidence/optimization/gen24'
OUT = BASE / 'independent-review'
BENCH = ROOT / 'bench/runs/gen24'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def git(*args):
    return subprocess.check_output(['git', *args], cwd=ROOT,
                                   env=dict(os.environ, GIT_OPTIONAL_LOCKS='0'))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--timed-commit', required=True)
    parser.add_argument('--results-review-sha256', required=True)
    parser.add_argument('--results-review-checks', type=int, required=True)
    args = parser.parse_args()
    assert len(args.timed_commit) == 40 and all(c in '0123456789abcdef' for c in args.timed_commit)
    assert len(args.results_review_sha256) == 64
    output = OUT / 'artifact-commit-source-binding.json'
    assert not output.exists(), 'refuse to overwrite an earlier artifact binding'
    review = load(BENCH / 'results-review.json')
    assert review['status'] == 'passed' and review['findings'] == []
    assert sha(BENCH / 'results-review.json') == args.results_review_sha256
    assert review['total_samples'] == 96 and review['checks_passed'] == args.results_review_checks
    assert review['decode_target_ratio'] == review['cpr_target_ratio'] == {'numerator': 2, 'denominator': 1}
    commit = review['commit']
    assert git('rev-parse', 'HEAD').decode().strip() == commit == args.timed_commit
    gate = load(BASE / 'gate-evidence.json')
    inputs = provenance.gate_input_hashes()
    assert len(inputs) == 202
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
    assert sha(ROOT / 'bench/GEN24.md') == review['report_sha256']
    assert sha(ROOT / 'bench/results.csv') == review['csv_after_sha256']
    assert review['cpr_overhead'] == load(BENCH / 'report-verification.json')['cpr_overhead']
    for name, digest in review['clean_checkpoint_sha256'].items():
        assert sha(BENCH / (name + '-git.json')) == digest
        checkpoint = load(BENCH / (name + '-git.json'))
        assert checkpoint['commit'] == commit and checkpoint['clean'] and not checkpoint['stdout']
    precommit = load(BASE / 'precommit-verification.json')
    assert precommit['status'] == 'passed' and precommit['correctness_inputs'] == 202
    assert precommit['gate_evidence_sha256'] == sha(BASE / 'gate-evidence.json')
    assert precommit['gate_review_sha256'] == sha(OUT / 'gate-review.json')
    assert precommit['current_head'] == git('rev-parse', commit + '^').decode().strip()
    assert sha(BASE / 'precommit-verification.json') == hashlib.sha256(git('cat-file', 'blob', commit + ':' + str((BASE / 'precommit-verification.json').relative_to(ROOT)))).hexdigest()
    archive = load(BENCH / 'archive-verification.json')
    assert archive['status'] == 'passed' and archive['file_count'] == 48
    assert archive['source'] == '.cache/bench-runs/gen24-' + commit[:7]
    assert not (BASE / 'benchmark-archival/relocation.json').exists()
    protocol = load(BASE / 'benchmark-preparation/execution-protocol.json')
    assert protocol['output_resolution']['source_parent'] == '.cache/bench-runs'
    assert protocol['output_resolution']['source_basename'] == 'gen24-<actual committed HEAD first 7 hex characters>'
    paths = [BENCH / name for name in ('results-review.json', 'archive-verification.json', 'report-verification.json',
                                     'correctness-inputs.json', 'binary-built.json')]
    paths += [BASE / name for name in ('gate-evidence.json', 'gate-full.log', 'gate-archive.json', 'fresh-final-verification.json')]
    paths += [OUT / name for name in ('gate-review.json', 'check_benchmark_result.py',
                                     'benchmark-result-review-01.log', 'check_artifact_commit_inputs.py')]
    paths += [ROOT / 'bench/GEN24.md', ROOT / 'bench/results.csv']
    paths += [BASE / 'independent-review/fresh-completion.json', BASE / 'benchmark-preparation/plan.json']
    paths += [OUT / 'benchmark-result-review-preparation.json', OUT / 'benchmark-result-reviewer.diff', OUT / 'artifact-binding-preparation.json']
    paths += [BASE / 'precommit-verification.json', BASE / 'benchmark-preparation/execution-protocol.json']
    assert all(p.is_file() for p in paths)
    files = {str(p.relative_to(ROOT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in paths}
    status = git('status', '--porcelain=v1', '--untracked-files=all').decode()
    assert provenance.gate_input_hashes() == inputs
    record = {
        'status': 'passed_unchanged_gate_input_binding_for_artifact_commit',
        'recorded_utc': datetime.now(timezone.utc).isoformat(), 'timed_commit': commit,
        'correctness_input_count': len(inputs), 'gate_validation': gate_validation,
        'all_inputs_match_passed_full_gate_current_tree_and_timed_commit': True,
        'correctness_inventory': 'bench/runs/gen24/correctness-inputs.json',
        'correctness_inventory_sha256': sha(BENCH / 'correctness-inputs.json'),
        'files': files, 'current_git_status': status,
        'configured_identity': 'zpconn <zpconn@gmail.com>', 'target_ratio_each_mode': {'numerator': 2, 'denominator': 1},
        'exact_target_decisions': decisions, 'both_targets_reached': all(decisions.values()),
        'cpr_overhead': review['cpr_overhead'],
        'clean_checkpoint_sha256': review['clean_checkpoint_sha256'],
        'canonical_source_path_matches_actual_timed_commit': True,
        'canonical_archive_source': archive['source'],
        'results_review_check_count': review['checks_passed'],
        'build_test_benchmark_or_git_mutation_performed': False, 'findings': [],
        'scope': 'The existing passing full gate covers every unchanged correctness input. This record binds the already-reviewed result artifacts for the parent-controlled artifact commit, without copying historical trees or running a replacement gate. Concurrent parent documentation updates are outside this correctness inventory.'}
    with output.open('x') as stream:
        json.dump(record, stream, indent=2)
        stream.write('\n')
    print(json.dumps({'status': record['status'], 'sha256': sha(output), 'correctness_inputs': len(inputs),
                      'bound_artifacts': len(files), 'both_targets_reached': all(decisions.values())}, indent=2))


if __name__ == '__main__':
    main()
