#!/usr/bin/env python3
"""Retain one narrow proof-build attempt without changing production inputs."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import datetime
import hashlib
import json
import subprocess

base = Path(__file__).parent
attempt = base / sys.argv[1]
attempt.mkdir()
paths = ['Proofs/BitExtraction.lean', 'Impl/Altitude.lean', 'Impl/Frame.lean',
         'Impl/PayloadBits.lean', 'Spec/Altitude.lean', 'Spec/Frame.lean',
         'spec.lock', 'lakefile.toml', 'lean-toolchain', 'lake-manifest.json']
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
before = {p: sha(p) for p in paths}
(attempt / 'BitExtraction.lean').write_bytes(Path(paths[0]).read_bytes())
(attempt / 'inputs.json').write_text(json.dumps(before, indent=2) + '\n')
command = ['lake', 'build', 'Proofs.BitExtraction']
started = datetime.datetime.now(datetime.timezone.utc).isoformat()
with (attempt / 'build.log').open('xb') as log:
    result = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
after = {p: sha(p) for p in paths}
record = {'status': 'passed' if result.returncode == 0 and after == before else 'failed',
          'command': command, 'started_utc': started,
          'finished_utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
          'exit_code': result.returncode, 'before_hashes': before, 'after_hashes': after,
          'inputs_unchanged': after == before, 'log_sha256': sha(attempt / 'build.log'),
          'source_snapshot_sha256': sha(attempt / 'BitExtraction.lean'),
          'runner_sha256': sha(__file__)}
(attempt / 'execution.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record))
raise SystemExit(result.returncode if result.returncode else int(after != before))
