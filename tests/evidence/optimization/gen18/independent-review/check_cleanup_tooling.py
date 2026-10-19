#!/usr/bin/env python3
"""Independently bind the exact nested-archive extension and isolated test run."""
import sys
sys.dont_write_bytecode = True
import ast
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

R = Path.cwd()
E = R / 'tests/evidence/optimization/gen18/independent-review'
T = E.parent / 'fresh/cleanup-tooling'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
read = lambda p: json.loads(p.read_text())
v = read(T / 'validation.json')
assert v['status'] == 'passed' and v['exit_code'] == 0 and v['tests'] == 31
for name, expected in v['files'].items():
    assert sha(R / name) == expected, name
for name, expected in v['source_after'].items():
    assert sha(R / name) == expected, name
for name, expected in v['source_before'].items():
    assert sha(T / 'before' / Path(name).name) == expected, name
old = (T / 'before/cleanup_verified_scratch.py').read_text()
new = (R / 'review/diagnostics/cleanup_verified_scratch.py').read_text()
before = """    elif (len(parts) == 5 and parts[:3] == ('tests', 'evidence', 'optimization')
          and re.fullmatch(r'gen[1-9][0-9]*', parts[3]) and parts[4] == 'fresh-message'):"""
after = """    elif (len(parts) in (5, 6) and parts[:3] == ('tests', 'evidence', 'optimization')
          and re.fullmatch(r'gen[1-9][0-9]*', parts[3])
          and parts[4:] in (('fresh-message',), ('fresh', 'fresh-message'))):"""
assert old.count(before) == 1 and old.replace(before, after) == new
assert v['source_before']['review/diagnostics/finish_generation_gate.py'] == v['source_after']['review/diagnostics/finish_generation_gate.py']

def methods(path):
    tree = ast.parse(path.read_text())
    return {n.name: ast.dump(n, include_attributes=False)
            for node in tree.body if isinstance(node, ast.ClassDef)
            for n in node.body if isinstance(n, ast.FunctionDef)}

old_tests = methods(T / 'before/test_cleanup_verified_scratch.py')
new_tests = methods(R / 'review/diagnostics/test_cleanup_verified_scratch.py')
assert all(new_tests[n] == body for n, body in old_tests.items())
added = set(new_tests) - set(old_tests)
assert len([n for n in added if n.startswith('test_')]) == 6
log = E / 'cleanup-tests-01.log'
assert 'Ran 31 tests' in log.read_text() and '\nOK\n' in log.read_text()
integration = E.parent / 'integration/targeted-build.json'
held = read(integration)['all_inputs_after']
assert len(held) == 190
for name, expected in held.items():
    assert sha(R / name) == expected, name

bindings = {str(p.relative_to(R)): sha(p) for p in
            [Path(__file__), log, integration, T / 'validation.json',
             T / 'cleanup_verified_scratch.diff', T / 'test_cleanup_verified_scratch.diff']}
bindings.update(v['source_after'])
result = {
    'status': 'passed', 'findings': [], 'reviewed_utc': datetime.now(timezone.utc).isoformat(),
    'bindings': bindings, 'producer_evidence_hashes_verified': v['files'],
    'independently_reexecuted_isolated_tests': 31,
    'command': ['python3', '-B', 'review/diagnostics/test_cleanup_verified_scratch.py'],
    'environment': {'PYTHONDONTWRITEBYTECODE': '1'},
    'all_190_gate_inputs_unchanged': True, 'no_live_cleanup': True,
    'assessment': [
        'The sole helper change admits exact genN/fresh/fresh-message beside the original genN/fresh-message shape, with positive nonzero generation syntax.',
        'Both forms use their own sibling fresh-retained-hashes.json; a parent seal cannot authorize the nested root.',
        'All existing safety code is byte-identical: complete direct membership, gzip EOF/size/SHA, regular-file and alias protections, explicit quiescence/protection, durable pre-unlink receipts and exact identity rechecks.',
        'All prior test method ASTs are unchanged; six new tests cover positive dry-run/apply, eight malformed paths, missing/failed/changed seals and extra unsealed members.',
        'finish_generation_gate.py is unchanged. Quiescence remains a caller precondition; this helper does not claim active-process detection.'
    ],
}
out = E / 'cleanup-tooling-review.json'
assert not out.exists()
out.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'sha256': sha(out), 'tests': 31}))
