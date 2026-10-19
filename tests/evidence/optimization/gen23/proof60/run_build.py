#!/usr/bin/env python3
"""Retain each independent BDS60 proof build without overwriting an attempt."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib
import json
import subprocess

E = Path('tests/evidence/optimization/gen23/proof60')
S = Path('Proofs/CommBValidity60.lean')
R = Path('Impl/CommB.lean')

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def save(p, value):
    with p.open('x') as stream:
        stream.write(json.dumps(value, indent=2) + '\n')

n = 1
while (E / f'attempt-{n:02d}').exists():
    n += 1
A = E / f'attempt-{n:02d}'
A.mkdir()
(A / S.name).write_bytes(S.read_bytes())
command = ['lake', 'build', 'Proofs.CommBValidity60']
record = {'status': 'running', 'started_utc': datetime.now(timezone.utc).isoformat(),
          'command': command, 'source': str(S), 'source_before_sha256': sha(S),
          'runtime': str(R), 'runtime_before_sha256': sha(R),
          'spec_lock_before_sha256': sha('spec.lock')}
save(A / 'command.json', record)
with (A / 'build.log').open('xb') as log:
    result = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
record.update(status='passed' if result.returncode == 0 else 'failed',
              exit_code=result.returncode, completed_utc=datetime.now(timezone.utc).isoformat(),
              source_after_sha256=sha(S), runtime_after_sha256=sha(R),
              spec_lock_after_sha256=sha('spec.lock'), log_sha256=sha(A / 'build.log'))
assert record['source_before_sha256'] == record['source_after_sha256']
assert record['runtime_before_sha256'] == record['runtime_after_sha256']
assert record['spec_lock_before_sha256'] == record['spec_lock_after_sha256']
save(A / 'result.json', record)
print(json.dumps(record))
sys.exit(result.returncode)
