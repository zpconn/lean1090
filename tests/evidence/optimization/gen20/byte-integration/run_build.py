"""Retain every targeted byte-composition build and check its printed axioms."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib
import json
import re
import subprocess
import time

ROOT = Path(__file__).resolve().parents[5]
E = Path(__file__).resolve().parent
attempt = int(sys.argv[1])
A = E / f'attempt-{attempt:02d}'
A.mkdir(exist_ok=False)

def sha(path):
    with path.open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()

sources = ['Impl/Parity.lean', 'Proofs/ParityByteBits.lean', 'Proofs/FoldBlocks.lean',
           'Proofs/ParityByte.lean', 'Proofs/ParityWord.lean']
held = {p: sha(ROOT / p) for p in sources + ['spec.lock', 'lean-toolchain', 'lakefile.toml']}
for line in (ROOT / 'spec.lock').read_text().splitlines():
    digest, name = line.split('  ', 1)
    assert sha(ROOT / name) == digest, name
    held[name] = digest
for name in sources:
    destination = A / name
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_bytes((ROOT / name).read_bytes())
command = ['lake', 'build', 'Proofs.ParityByte', 'Proofs.ParityWord']
record = {'status': 'running', 'attempt': attempt, 'command': command,
          'started_utc': datetime.now(timezone.utc).isoformat(),
          'started_monotonic_ns': time.monotonic_ns(), 'before_hashes': held,
          'runner_sha256': sha(Path(__file__))}

def save():
    (A / 'execution.json').write_text(json.dumps(record, indent=2) + '\n')

save()
with (A / 'build.log').open('x') as log:
    result = subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
record.update(exit_code=result.returncode, finished_utc=datetime.now(timezone.utc).isoformat(),
              finished_monotonic_ns=time.monotonic_ns(), log_sha256=sha(A / 'build.log'))
record['after_hashes'] = {name: sha(ROOT / name) for name in held}
record['inputs_unchanged'] = record['after_hashes'] == held
record['status'] = 'passed' if result.returncode == 0 and record['inputs_unchanged'] else 'failed'
save()
assert record['inputs_unchanged']
if result.returncode == 0:
    log = (A / 'build.log').read_text()
    facts = {}
    for source in sources[-2:]:
        namespace = 'Lean1090.Proofs.' + Path(source).stem
        for name in re.findall(r'^#print axioms (\w+)$', (ROOT / source).read_text(), re.M):
            full = namespace + '.' + name
            match = re.search(re.escape("'" + full + "'") + r' depends on axioms: \[(.*?)\]', log, re.S)
            if match:
                axioms = [x.strip() for x in match[1].split(',') if x.strip()]
            else:
                assert f"'{full}' does not depend on any axioms" in log, full
                axioms = []
            assert set(axioms) <= {'propext', 'Classical.choice', 'Quot.sound'}, (full, axioms)
            facts[full] = axioms
    record['printed_axioms'] = facts
    save()
print(json.dumps({'status': record['status'], 'attempt': attempt,
                  'execution_sha256': sha(A / 'execution.json'),
                  'log_sha256': sha(A / 'build.log')}))
sys.exit(result.returncode)
