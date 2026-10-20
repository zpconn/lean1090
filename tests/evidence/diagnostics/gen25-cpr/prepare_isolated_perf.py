#!/usr/bin/env python3
"""Bind the prior sequential perf controller after both gen25 builds complete.

This preparation script does not execute the generated controller. Root supplies
the published artifact commit and separately releases isolated capture afterward.
"""
import sys
sys.dont_write_bytecode = True
import argparse
import ast
import difflib
import hashlib
import json
import subprocess
from pathlib import Path

R = Path(__file__).resolve().parents[4]
E = Path(__file__).resolve().parent
OLD = R / 'tests/evidence/diagnostics/gen24-cpr'
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--artifact-commit', required=True)
args = p.parse_args()
head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=R, text=True).strip()
assert head == args.artifact_commit
summary = load(R / 'bench/runs/gen25/summary.json')
review = load(R / 'bench/runs/gen25/results-review.json')
assert summary['status'] == 'complete' and review['status'] == 'passed' and not review['findings']
assert summary['commit'] == review['commit'] == 'eaa7b36225b0d3ae29720a319295b0fac34e995b'
assert summary['binary_sha256'] == review['binary_sha256'] == '0383b0488863b837ebae02e78b00c86bba11eea96916ee0816b8db2dcb0ba189'
assert head != summary['commit'], 'Root must supply the published artifact commit after timing.'
binding_path = R / 'tests/evidence/diagnostics/gen25/benchmark-source-binding.json'
binding = load(binding_path)
assert binding['status'] == 'passed' and binding['diagnostic_commit'] == head
assert binding['timed_original_commit'] == summary['commit']
builds = [R / '.cache/gen25-costs/driver/driver-build.json',
          R / '.cache/gen25-cpr-costs/driver-final/driver-build.json']
for path in builds:
    driver = load(path)
    assert driver['status'] == 'passed'
    for group in ['unchanged_native_inputs', 'artifacts']:
        for name, digest in driver[group].items():
            assert sha(R / name) == digest, name
execution = load(E / 'build-execution.json')
assert execution['status'] == 'passed' and execution['all_inputs_unchanged']
assert execution['artifact_commit'] == head
assert execution['build_manifest_sha256'] == sha(builds[1])
correctness = load(R / 'bench/runs/gen25/correctness-inputs.json')
assert len(correctness) == 202
for name, digest in correctness.items():
    assert sha(R / name) == digest, name

prior = OLD / 'run_isolated_perf.py'
prior_binding = load(OLD / 'run_isolated_perf.preparation.json')
assert sha(prior) == prior_binding['source_sha256']
replacements = {
    'gen24': 'gen25',
    prior_binding['artifact_commit']: head,
    prior_binding['timed_commit']: summary['commit'],
    prior_binding['worker_sha256']: summary['binary_sha256'],
    prior_binding['source_binding_sha256']: sha(binding_path),
    prior_binding['builds']['.cache/gen24-costs/driver/driver-build.json']: sha(builds[0]),
    prior_binding['builds']['.cache/gen24-cpr-costs/driver-final/driver-build.json']: sha(builds[1]),
}
before = prior.read_text()
after = before
for old, new in replacements.items():
    assert old in after, old
    after = after.replace(old, new)
prepared_helpers = {str((E / 'perf' / name).relative_to(R)): sha(E / 'perf' / name)
                    for name in ['analyze_cpr_perf.py', 'seal_perf.py']}
old_helpers = {name.replace('gen24', 'gen25'): digest
               for name, digest in prior_binding['prepared_perf_helpers'].items()}
needle = 'prepared_perf_helpers=' + repr(old_helpers)
assert after.count(needle) == 1
after = after.replace(needle, 'prepared_perf_helpers=' + repr(prepared_helpers))
destination = E / 'run_isolated_perf.py'
ast.parse(after, filename=str(destination))
assert not destination.exists()
with destination.open('x') as stream:
    stream.write(after)
diff = E / 'run_isolated_perf.diff'
with diff.open('x') as stream:
    stream.writelines(difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                     fromfile=str(prior.relative_to(R)), tofile=str(destination.relative_to(R))))
record = {'status': 'prepared_not_executed', 'prior_source_sha256': sha(prior),
          'source_sha256': sha(destination), 'diff_sha256': sha(diff),
          'preparer_sha256': sha(__file__), 'replacements': replacements,
          'prepared_perf_helpers': prepared_helpers,
          'builds': {str(path.relative_to(R)): sha(path) for path in builds},
          'source_binding_sha256': sha(binding_path), 'artifact_commit': head,
          'timed_commit': summary['commit'], 'worker_sha256': summary['binary_sha256'],
          'correctness_inputs': 202,
          'changes': 'Only generation/count and exact completed source/build/helper identities. Sequential decode then CPR, CPU 0, cpu-clock:u at 199 Hz, full input/output checks and overwrite guards are unchanged. Only the exact two prepared CPR helper files may preexist in its output directory.',
          'execution': 'Only source binding/preparation ran; generated controller AST parsed, never imported or executed. Root explicit capture release and all-other-jobs-stop confirmation required.'}
with (E / 'run_isolated_perf.preparation.json').open('x') as stream:
    json.dump(record, stream, indent=2)
    stream.write('\n')
print(json.dumps({'status': 'prepared_not_executed', 'source_sha256': sha(destination),
                  'preparation_sha256': sha(E / 'run_isolated_perf.preparation.json')}))
