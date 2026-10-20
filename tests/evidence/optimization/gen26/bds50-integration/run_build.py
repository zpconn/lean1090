#!/usr/bin/env python3
"""Retain one targeted BDS50 proof normalization proof build and its exact inputs."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, subprocess
base = Path(__file__).parent
attempt = base / sys.argv[1]
attempt.mkdir()
paths = ['Proofs/BDS50.lean', 'Proofs/Binary64Runtime.lean',
         'Impl/Binary64.lean', 'Proofs/Binary64Dyadic.lean',
         'Proofs/Binary64Bounds.lean', 'spec.lock', 'lakefile.toml',
         'lean-toolchain', 'lake-manifest.json']
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
before = {p: sha(p) for p in paths}
for name in paths[:2]:
    (attempt / Path(name).name).write_bytes(Path(name).read_bytes())
(attempt / 'inputs.json').write_text(json.dumps(before, indent=2) + '\n')
command = ['lake', 'build', 'Proofs.BDS50']
started = datetime.now(timezone.utc).isoformat()
with (attempt / 'build.log').open('xb') as log:
    result = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
after = {p: sha(p) for p in paths}
record = {'status': 'passed' if result.returncode == 0 and before == after else 'failed',
          'command': command, 'started_utc': started,
          'finished_utc': datetime.now(timezone.utc).isoformat(),
          'exit_code': result.returncode, 'before_hashes': before, 'after_hashes': after,
          'inputs_unchanged': before == after, 'log_sha256': sha(attempt / 'build.log'),
          'runner_sha256': sha(__file__)}
(attempt / 'execution.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record))
raise SystemExit(result.returncode if result.returncode else int(before != after))
