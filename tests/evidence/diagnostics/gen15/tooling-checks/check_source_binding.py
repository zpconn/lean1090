#!/usr/bin/env python3
"""Pure/read-only negative controls for the ordinary descendant binding."""
import sys
sys.dont_write_bytecode = True
import hashlib
import importlib.util
import json
from pathlib import Path
import tempfile
from unittest.mock import patch

ROOT = Path.cwd()
OUT = ROOT / 'tests/evidence/diagnostics/gen15/tooling-checks/source-binding-tests.json'
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import bind_benchmark_history as binder

build = Path('.cache/gen15-costs/driver/driver-build.json')
benchmark = Path('bench/runs/gen15/summary.json')
inputs = Path('bench/runs/gen15/correctness-inputs.json')
record = binder.inspect(build, benchmark, None, inputs)
assert record == json.loads(Path('tests/evidence/diagnostics/gen15/benchmark-source-binding.json').read_text())
cases = ['actual ordinary descendant binding matches retained record']

def rejects(label, action):
    try:
        action()
    except AssertionError:
        cases.append(label)
        return
    raise AssertionError('negative control unexpectedly passed: ' + label)

inventory = binder.gate_input_hashes()
lean_name = next(name for name in inventory if name.endswith('.lean'))
with patch.object(binder, 'gate_input_hashes', return_value={name: value for name, value in inventory.items() if name != lean_name}):
    rejects('missing audited Lean source rejected', lambda: binder.inspect(build, benchmark, None, inputs))
wrong = dict(inventory)
wrong[lean_name] = '0' * 64
with patch.object(binder, 'gate_input_hashes', return_value=wrong):
    rejects('changed audited Lean source digest rejected', lambda: binder.inspect(build, benchmark, None, inputs))
real_sha = binder.sha
with patch.object(binder, 'sha', side_effect=lambda path: '0' * 64 if str(path) == '.lake/build/bin/lean1090-bench' else real_sha(path)):
    rejects('changed actual benchmark worker rejected', lambda: binder.inspect(build, benchmark, None, inputs))
with tempfile.TemporaryDirectory(prefix='gen15-binder-') as temp:
    altered = json.loads(build.read_text())
    altered['lock_sha256'] = '0' * 64
    path = Path(temp) / 'build.json'
    path.write_text(json.dumps(altered))
    rejects('changed lock binding rejected', lambda: binder.inspect(path, benchmark, None, inputs))
assert not OUT.exists()
result = {'status': 'passed', 'cases': cases, 'case_count': len(cases),
          'binder_sha256': binder.sha(Path(binder.__file__)),
          'binding_sha256': binder.sha(Path('tests/evidence/diagnostics/gen15/benchmark-source-binding.json')),
          'scope': 'Read-only source/metadata checks with temporary manifests and in-process mocks; no build, decoder, profiler, source or historical artifact mutation.'}
OUT.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result))
