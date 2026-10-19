#!/usr/bin/env python3
"""Read-only gen21 result review; run only after both modes and archival finish.

Reuses reviewed validation APIs, independently derives medians and exact targets,
and binds current-generation inputs. Historical checks use sealed review hashes
and the pre-timing CSV prefix, not repeated copies of old evidence trees.
No builds, decoder runs, profiles, mutations of existing evidence, or retries.
"""
from __future__ import annotations
import sys
sys.dont_write_bytecode = True
import argparse
import csv
from datetime import datetime, timezone
from fractions import Fraction
import hashlib
import io
import json
import os
from pathlib import Path
import shlex
import statistics
import subprocess

ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import archive_generation_benchmark_target as archive
import run_generation_benchmark as runner

GEN = 21
EVIDENCE = ROOT / 'tests/evidence/optimization/gen21'
checks = 0


def require(condition, message):
    global checks
    if not condition:
        raise RuntimeError(message)
    checks += 1


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def git(*args):
    env = dict(os.environ, GIT_OPTIONAL_LOCKS='0')
    return subprocess.check_output(['git', *args], cwd=ROOT, env=env)


def independent_cpr_overhead(results):
    """Derive signed overhead from independently sorted raw integer medians."""
    modes = {row['mode']: row for row in results}
    require(len(results) == len(modes) == 2 and set(modes) == {'decode', 'cpr'},
            'overhead needs exactly the two measured modes')
    count = 172432
    require(archive.COUNT == count, 'overhead interval count differs')
    implementations = {}
    for implementation in ('lean1090', 'rs1090'):
        medians = {mode: modes[mode]['medians_nanoseconds'][implementation]
                   for mode in ('decode', 'cpr')}
        require(all(type(value) is int and value > 0 for value in medians.values()),
                'overhead medians must be exact positive integers')
        difference = medians['cpr'] - medians['decode']
        exact = Fraction(difference, count * 1000)
        reciprocal = (Fraction(1000000) / Fraction(count * 1000000000, medians['cpr'])
                      - Fraction(1000000) / Fraction(count * 1000000000, medians['decode']))
        require(exact == reciprocal, 'exact reciprocal-throughput formula differs')
        require((exact > 0) == (difference > 0) and (exact < 0) == (difference < 0),
                'signed overhead was clamped or changed')
        implementations[implementation] = {
            'median_nanoseconds': medians,
            'difference_nanoseconds': difference,
            'microseconds_per_message_divisor': count * 1000,
            'microseconds_per_message': difference / (count * 1000),
        }
    return {
        'messages_per_interval': count,
        'formula': '1e6 / cpr_messages_per_second - 1e6 / decode_messages_per_second',
        'interpretation': 'Difference of independently measured mode medians; includes measurement noise. Signed values are retained without clamping.',
        'implementations': implementations,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, required=True)
    parser.add_argument('--plan', type=Path, required=True)
    args = parser.parse_args()
    source, plan_path = args.source.resolve(), args.plan.resolve()
    destination = ROOT / 'bench/runs/gen21'
    output = destination / 'results-review.json'
    require(not output.exists(), 'refuse to overwrite previous review')
    plan = load(plan_path)
    require(plan['generation'] == GEN, 'wrong plan generation')
    require(all(archive.target_ratio(plan, mode) == (2, 1) for mode in ('decode', 'cpr')),
            'both exact 2/1 targets must be explicit')
    data = archive.validate_source(source, GEN)
    summary, build = data['summary'], data['build']
    commit = summary['commit']
    require(source == ROOT / '.cache/bench-runs' / ('gen21-' + commit[:7]), 'wrong source path')
    require(git('rev-parse', 'HEAD').decode().strip() == commit, 'HEAD differs from timed source')
    attribution = git('show', '-s', '--format=%an <%ae>%n%cn <%ce>', commit).decode().splitlines()
    require(attribution == ['zpconn <zpconn@gmail.com>'] * 2, 'wrong author or committer')
    require(data['fresh_native_sets'] == 22, 'expected 22 fresh linked native sets')

    original = data['source_files']
    require(len(original) == 48, 'exact original membership')
    archived = archive.inventory(destination)
    require(set(archived) == archive.ORIGINAL_FILES | {'archive-verification.json', 'report-verification.json'},
            'unexpected destination membership before independent review')
    for name, record in original.items():
        require(archived[name] == record, 'original archive differs: ' + name)
    archive_receipt = load(destination / 'archive-verification.json')
    report_receipt = load(destination / 'report-verification.json')
    require(archive_receipt['status'] == report_receipt['status'] == 'passed', 'archival did not pass')
    require(archive_receipt['files'] == original and archive_receipt['file_count'] == 48,
            'archive receipt inventory differs')
    for name, digest in archive_receipt['added_artifacts'].items():
        require(sha(ROOT / name) == digest, 'archival added-artifact binding differs: ' + name)
    helper = ROOT / 'review/diagnostics/archive_generation_benchmark_target.py'
    require(sha(helper) == report_receipt['helper_sha256'] == archive.committed_sha(commit, str(helper.relative_to(ROOT))),
            'report helper differs from timed committed helper')
    require(sha(plan_path) == report_receipt['plan_sha256'], 'report plan binding differs')

    inputs = load(source / 'correctness-inputs.json')
    require(len(inputs) == 195 and inputs == runner.gate_input_hashes(), 'current correctness inventory differs')
    for name, digest in inputs.items():
        require(archive.committed_sha(commit, name) == digest, 'gate input not committed: ' + name)
    # Gen20 had a separately retained commit-wrapper exception; gen21 does not.
    # Bind all six actual frozen-runner clean-tree checkpoints instead.
    clean_checkpoints = {}
    for name in ('before-build', 'before-decode', 'after-decode', 'before-cpr', 'after-cpr', 'after-timing'):
        path = source / (name + '-git.json')
        checkpoint = load(path)
        require(checkpoint['clean'] and not checkpoint['stdout'] and checkpoint['commit'] == commit,
                'nonclean or different timed checkpoint: ' + name)
        require(checkpoint['command'] == ['git', 'status', '--porcelain=v1', '--untracked-files=all'],
                'clean checkpoint command differs: ' + name)
        clean_checkpoints[name] = sha(path)
    frozen = dict((name, digest) for digest, name in
                  (line.split('  ', 1) for line in (ROOT / 'spec.lock').read_text().splitlines()))
    require(len(frozen) == 104, 'wrong frozen membership')
    for name, digest in frozen.items():
        require(inputs[name] == digest == sha(ROOT / name), 'locked source differs: ' + name)
    for name, digest in build['native_hashes'].items():
        require(sha(ROOT / name) == digest, 'current native artifact differs: ' + name)
    require(build['build_command']['argv'] == ['lake', '--no-cache', '--rehash', '-v', 'build', 'lean1090-bench'],
            'fresh build invocation differs')
    require(build['build_command']['exit_code'] == 0, 'fresh build failed')
    fresh_native = load(source / 'fresh-native-inputs.json')
    removals = load(source / 'fresh-build-removals.json')
    removed_names = [r['path'] for r in removals]
    require(len(removed_names) == len(set(removed_names)), 'duplicate fresh removal record')
    native_paths = {p for row in fresh_native for p in row['artifacts']}
    require(len(native_paths) == 66 and native_paths <= set(removed_names),
            'fresh linked artifacts were not all removed before recreation')
    require(build['old_project_object_count'] == 22 and not build['object_membership_added'] and not build['object_membership_removed'],
            'linked native object membership changed')
    require(build['build_command'] in load(source / 'commands.json'), 'fresh build command not in execution sequence')

    fresh = load(EVIDENCE / 'fresh-final-verification.json')
    require(sha(EVIDENCE / 'fresh-final-verification.json') == plan['fresh_verification_sha256'],
            'fresh verifier plan binding differs')
    require(fresh['status'] == 'passed' and fresh['exit_code'] == 0, 'fresh verifier failed')
    preflight, run = load(EVIDENCE / 'fresh-preflight.json'), load(EVIDENCE / 'fresh-message-run.json')
    require(len(preflight['source_sha256']) == 120 and len(preflight['binary_sha256']) == 3,
            'fresh source/binary cardinality differs')
    require(preflight['source_sha256'] == run['source_sha256_before'] == run['source_sha256_after'],
            'fresh source identity differs')
    require(preflight['binary_sha256'] == run['binary_sha256_before'] == run['binary_sha256_after'],
            'fresh binary identity differs')
    for name, digest in preflight['source_sha256'].items():
        require(inputs[name] == digest == archive.committed_sha(commit, name), 'fresh source not committed: ' + name)
    for name, digest in preflight['binary_sha256'].items():
        require(sha(ROOT / name) == digest, 'fresh tested binary changed: ' + name)
    completion_path = EVIDENCE / 'independent-review/fresh-completion.json'
    completion = load(completion_path)
    require(completion['status'] == 'passed' and completion['retained_members'] == 33,
            'fresh completion not sealed')
    gate_review_path = EVIDENCE / 'independent-review/gate-review.json'
    gate_review = load(gate_review_path)
    require(gate_review['status'] == 'passed' and not gate_review['findings'], 'final gate review failed')
    require(sha(gate_review_path) == archive.committed_sha(commit, str(gate_review_path.relative_to(ROOT))), 'gate review not committed')
    require(sha(completion_path) == gate_review['bindings'][str(completion_path.relative_to(ROOT))], 'fresh completion differs from sealed gate review')
    require(sha(plan_path) == gate_review['bindings'][str(plan_path.relative_to(ROOT))], 'plan differs from sealed gate review')

    prior = (ROOT / plan['prior_csv_snapshot']).read_bytes()
    preparation = load(EVIDENCE / 'preparation.json')
    prior_sha = hashlib.sha256(prior).hexdigest()
    require(prior_sha == plan['prior_csv_sha256'] == preparation['prior_csv_sha256'], 'prior CSV seal differs')
    old_rows = archive.parse_prior_csv(prior, GEN)
    require(len(old_rows) == plan['prior_csv_rows'] == 42, 'wrong prior row count')
    appended = io.StringIO(newline='')
    writer = csv.writer(appended, lineterminator='\n')
    decisions = {}
    for result in data['results']:
        mode = result['mode']
        rows = list(csv.DictReader(io.StringIO((source / mode / 'samples.csv').read_text())))
        require(len(rows) == 48, 'wrong sample count')
        for side in ('rs1090', 'lean1090'):
            values = [int(row['nanoseconds']) for row in rows if row['implementation'] == side and row['phase'] == 'measured']
            require(len(values) == 21 and sorted(values)[10] == result['medians_nanoseconds'][side],
                    'independent median differs')
        med = result['medians_nanoseconds']
        decisions[mode] = med['rs1090'] >= 2 * med['lean1090']
        require(result['lean_over_rust'] == med['rs1090'] / med['lean1090'], 'ratio differs')
        writer.writerow([commit, GEN, result['messages_per_second']['lean1090'], result['messages_per_second']['rs1090'],
                         plan['row_note'], mode, result['lean_over_rust']])
    require(archive.target_decisions(plan, data['results']) == decisions, 'dual target API differs')
    target_fields, reached = archive.reporting_targets(plan, data['results'])
    require(reached == all(decisions.values()), 'joint target must use AND')
    require(all(report_receipt[key] == value for key, value in target_fields.items()), 'report target fields differ')
    overhead = independent_cpr_overhead(data['results'])
    require(report_receipt['cpr_overhead'] == overhead, 'structured CPR overhead differs')
    require(archive.cpr_overhead(data['results']) == overhead, 'reporting overhead API differs')
    require((ROOT / 'bench/results.csv').read_bytes() == prior + appended.getvalue().encode(),
            'CSV prior bytes or two appended rows differ')
    report = ROOT / 'bench/GEN21.md'
    expected_report = archive.report_text(plan, data, source, old_rows, fresh)
    require(report.read_bytes() == expected_report.encode() and sha(report) == report_receipt['report_sha256'],
            'report reconstruction differs')
    report_text = report.read_text()
    for implementation, label in [('lean1090', 'Lean'), ('rs1090', 'rs1090')]:
        value = overhead['implementations'][implementation]['microseconds_per_message']
        require(f'{value:.12f} µs/message for {label}' in report_text,
                'displayed signed overhead differs: ' + implementation)
    require('1e6 / cpr_msg_s - 1e6 / decode_msg_s' in report_text
            and 'independently measured mode medians' in report_text
            and 'Negative differences are retained without clamping.' in report_text,
            'overhead formula or measurement-noise qualification missing')

    # Reuse immutable historical seals rather than re-copying/re-reading all old trees.
    for name, digest in preparation['history_bindings'].items():
        require(sha(ROOT / name) == digest == archive.committed_sha(commit, name),
                'prior sealed review changed: ' + name)
    commands = load(source / 'commands.json')
    for previous, current in zip(commands, commands[1:]):
        require(previous['finish']['monotonic_ns'] <= current['start']['monotonic_ns'],
                'recorded commands overlap')
    require(load(source / 'before-effective-clang-drivers.json') == load(source / 'after-effective-clang-drivers.json'),
            'effective compiler drivers changed')
    effective = load(source / 'before-effective-clang-drivers.json')
    for row in effective:
        require(row['normal_stdout'] == row['no_default_config_stdout'] and
                row['normal_stderr'] == row['no_default_config_stderr'], 'hidden compiler config differs')
        if '-c' in row['argv']:
            require('-O3' in row['argv'] and '-ffp-contract=off' in row['argv'], 'compile flags differ')
        require(not any(arg.startswith(('-march=', '-mcpu=', '-mtune=')) for arg in row['argv']),
                'CPU-specific explicit compile flags')
    environments = [load(source / (side + '-environment/environment.json')) for side in ('before', 'after')]
    for key in ('lean', 'c_compiler', 'c_compiler_sha256', 'build_environment', 'compiled_c_traces',
                'worker_source_sha256', 'worker_generated_c_sha256', 'worker_binary_sha256',
                'worker_link_response_sha256', 'spec_lock_sha256'):
        require(environments[0][key] == environments[1][key], 'build environment changed: ' + key)
    hosts = {side: load(source / (side + '-host.json')) for side in ('before', 'after')}
    for host in hosts.values():
        require(host['script_sha256'] == sha(source / 'provenance-scripts/capture_benchmark_host.py'),
                'host capture script binding differs')

    # Recheck compact current-generation source/metadata identities immediately before sealing.
    require(runner.gate_input_hashes() == inputs, 'correctness inputs changed during review')
    require(archive.inventory(source) == original, 'original run files changed during review')
    require(archive.inventory(destination) == archived, 'archive files changed during review')
    result = {
        'status': 'passed', 'generation': GEN,
        'reviewer_attempts': [{'attempt': 1, 'status': 'passed'}], 'verified_utc': datetime.now(timezone.utc).isoformat(),
        'checks_passed': checks, 'findings': [], 'commit': commit, 'attribution': attribution,
        'binary_sha256': summary['binary_sha256'], 'reviewer_sha256': sha(__file__),
        'source': str(source.relative_to(ROOT)), 'archive_original_files': 48, 'total_samples': 96,
        'gate_input_count': len(inputs), 'fresh_source_count': 120, 'fresh_binary_count': 3,
        'frozen_file_count': len(frozen), 'fresh_native_sets': data['fresh_native_sets'],
        'clean_tree_and_lock_checkpoints': 6, 'windows_power_plan_captures': 4,
        'cpu_affinity': [0], 'results': data['results'], **target_fields,
        'cpr_overhead': overhead,
        'clocks': data['clocks'], 'wrapper_backsteps': data['wrapper_backsteps'],
        'power_plan_guid': data['power_plan_guid'], 'prior_rows_preserved': 42, 'rows_appended': 2,
        'prior_csv_sha256': prior_sha, 'csv_after_sha256': sha(ROOT / 'bench/results.csv'),
        'report_sha256': sha(report), 'archive_verification_sha256': sha(destination / 'archive-verification.json'),
        'report_verification_sha256': sha(destination / 'report-verification.json'),
        'fresh_completion_sha256': sha(completion_path), 'gate_review_sha256': sha(gate_review_path), 'gate': data['gate'],
        'current_gate_input_sha256': inputs,
        'clean_checkpoint_sha256': clean_checkpoints,
        'history_scope': 'Prior sealed review hashes, their committed blobs, and exact 42-row CSV byte prefix; no new historical copies.',
        'environment': {'platform': environments[0]['platform'], 'compiler': environments[0]['c_compiler'],
                        'host_limits': {side: host['limitations'] for side, host in hosts.items()}},
        'limitations': ['Worker monotonic durations alone determine medians; raw UTC differences/backsteps are retained without correction.',
                        'Power-plan and guest observations cannot establish Windows host-wide workload, temperature, frequency or contention isolation.',
                        'This review executes no build, decoder, benchmark, test campaign or profiler.'],
    }
    with output.open('x') as stream:
        json.dump(result, stream, indent=2)
        stream.write('\n')
    print(json.dumps({'status': 'passed', 'checks_passed': checks, 'output': str(output.relative_to(ROOT)),
                      'sha256': sha(output), 'decisions': decisions, 'both_targets_reached': reached}, indent=2))


if __name__ == '__main__':
    main()
