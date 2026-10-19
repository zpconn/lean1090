#!/usr/bin/env python3
"""Bind the reviewed sequential perf controller to completed gen22 builds only."""
import sys
sys.dont_write_bytecode = True
import ast
import difflib
import hashlib
import json
import subprocess
from pathlib import Path

R = Path(__file__).resolve().parents[4]
E = Path(__file__).resolve().parent
prior = R / 'tests/evidence/diagnostics/gen21-cpr/run_isolated_perf.py'
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=R, text=True).strip()
assert head == '59685cd27e65fa8250934daf165a0a74a1dc2ace'
summary = load(R / 'bench/runs/gen22/summary.json')
binding_path = R / 'tests/evidence/diagnostics/gen22/benchmark-source-binding.json'
binding = load(binding_path)
assert binding['status'] == 'passed' and binding['diagnostic_commit'] == head
assert binding['timed_original_commit'] == summary['commit']
builds = [R / '.cache/gen22-costs/driver/driver-build.json',
          R / '.cache/gen22-cpr-costs/driver-final/driver-build.json']
for p in builds:
    assert load(p)['status'] == 'passed'
execution = load(E / 'build-execution.json')
assert execution['status'] == 'passed' and execution['all_inputs_unchanged']
assert execution['artifact_commit'] == head
assert execution['build_manifest_sha256'] == sha(builds[1])
assert len(load(R / 'bench/runs/gen22/correctness-inputs.json')) == 197
replacements = {
    'gen21': 'gen22',
    'acdfde75c5c3776ad98286f87ddac07470a0a185': head,
    '11fbf4e0c8c196d70cd838dd2a14516f586fc4c5': summary['commit'],
    '861d722aee03c73147893797c9876bac3ee1337120516e2a45d2bd3c664d34f5': summary['binary_sha256'],
    '704d7e92fb09bfca36ba12c46445e512c54c586f9828a54e3b083548a404d931': sha(binding_path),
    '3c5a2c6a76fe5af19b6341a68302984ced55231a843386e33b2f9037a3ec2fdd': sha(builds[0]),
    '087c42a4e959aa565512bd30ac6492817eed3df7e89c635db29e84e8fe8d79a9': sha(builds[1]),
    '==195': '==197', "'correctness_inputs':195": "'correctness_inputs':197",
}
before = prior.read_text()
after = before
for old, new in replacements.items():
    assert old in after, old
    after = after.replace(old, new)
prepared_helpers = {str((E / 'perf' / name).relative_to(R)): sha(E / 'perf' / name)
                    for name in ['analyze_cpr_perf.py', 'seal_perf.py']}
needle = 'def snapshot():return {str(p.relative_to(root)):sha(p) for p in sorted(paths)}'
assert after.count(needle) == 1
after = after.replace(needle,
    'prepared_perf_helpers=' + repr(prepared_helpers) + '\n'
    'for name,digest in prepared_perf_helpers.items():assert sha(root/name)==digest;paths.add(root/name)\n'
    + needle)
needle = " assert not out.exists() and not cache.exists(), 'Retain earlier perf attempt; refuse overwrite'\n out.mkdir(parents=True);cache.mkdir(parents=True)"
assert after.count(needle) == 1
after = after.replace(needle,
    " assert not cache.exists(), 'Retain earlier perf attempt; refuse overwrite'\n"
    " if out.exists():\n"
    "  assert mode=='cpr' and out.is_dir(), 'Only the prepared CPR sample-helper directory may preexist'\n"
    "  assert {str(p.relative_to(root)) for p in out.iterdir()}==set(prepared_perf_helpers), 'Retain earlier perf artifacts; refuse overwrite'\n"
    "  for name,digest in prepared_perf_helpers.items():assert sha(root/name)==digest\n"
    " out.mkdir(parents=True,exist_ok=True);cache.mkdir(parents=True)")
destination = E / 'run_isolated_perf.py'
ast.parse(after, filename=str(destination))
assert not destination.exists()
destination.write_text(after)
diff = E / 'run_isolated_perf.diff'
with diff.open('x') as f:
    f.writelines(difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                 fromfile=str(prior.relative_to(R)), tofile=str(destination.relative_to(R))))
record = {'status': 'prepared_not_executed', 'prior_source_sha256': sha(prior),
          'source_sha256': sha(destination), 'diff_sha256': sha(diff),
          'replacements': replacements, 'prepared_perf_helpers': prepared_helpers,
          'builds': {str(p.relative_to(R)): sha(p) for p in builds},
          'source_binding_sha256': sha(binding_path), 'artifact_commit': head,
          'timed_commit': summary['commit'], 'worker_sha256': summary['binary_sha256'],
          'correctness_inputs': 197,
          'changes': 'Generation/count and exact completed source/build identities. CPR perf directory may contain exactly its two already-reviewed prepared sample helpers, hash-checked and included in protected inputs; any other prior capture/output or cache still rejects. All sampling protocol, sequential order, worker/output checks, collection limits and overwrite guards retained.',
          'execution': 'Only this preparation script ran; sequential controller AST parsed, never imported or executed. Root explicit release and all-other-jobs-stop confirmation required before root executes.'}
with (E / 'run_isolated_perf.preparation.json').open('x') as f:
    json.dump(record, f, indent=2);f.write('\n')
print(json.dumps({'status': 'prepared_not_executed', 'source_sha256': sha(destination),
                  'preparation_sha256': sha(E / 'run_isolated_perf.preparation.json')}))
