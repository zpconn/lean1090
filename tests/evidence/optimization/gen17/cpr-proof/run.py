#!/usr/bin/env python3
"""Retain each CPR proof build, its exact inputs, and its result."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time
from datetime import datetime, timezone

base = Path(__file__).resolve().parent
attempt = base / sys.argv[1]
attempt.mkdir()
paths = [Path(p) for p in (
    'Proofs/CPRTracking.lean', 'Proofs/Binary64Runtime.lean',
    'Impl/Binary64.lean', 'Impl/CPRPolicy.lean', 'Impl/CPRFloat.lean', 'spec.lock')]
def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()
before = {str(path): sha(path) for path in paths}
for path in paths:
    (attempt / str(path).replace('/', '__')).write_bytes(path.read_bytes())
record = {'command': ['lake', 'build', 'Proofs.CPRTracking'],
          'started_utc': datetime.now(timezone.utc).isoformat(),
          'inputs_before': before, 'runner_sha256': sha(Path(__file__))}
(attempt / 'started.json').write_text(json.dumps(record, indent=2) + '\n')
start = time.monotonic_ns()
with (attempt / 'build.log').open('wb') as log:
    result = subprocess.run(record['command'], stdout=log, stderr=subprocess.STDOUT,
                            env=dict(os.environ, PYTHONDONTWRITEBYTECODE='1'))
record.update(exit_code=result.returncode,
              finished_utc=datetime.now(timezone.utc).isoformat(),
              monotonic_elapsed_ns=time.monotonic_ns() - start,
              inputs_after={str(path): sha(path) for path in paths},
              log_sha256=sha(attempt / 'build.log'))
record['inputs_unchanged'] = record['inputs_before'] == record['inputs_after']
record['status'] = 'passed' if result.returncode == 0 and record['inputs_unchanged'] else 'failed'
(attempt / 'result.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps({'attempt': str(attempt), 'status': record['status'],
                  'result_sha256': sha(attempt / 'result.json')}))
raise SystemExit(0 if record['status'] == 'passed' else 1)
