"""Build only the generic fold proof, preserving every attempt and its source."""
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
number = int(sys.argv[1])
A = E / f'attempt-{number:02d}'
A.mkdir(exist_ok=False)

def sha(p):
    with p.open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()

source = ROOT / 'Proofs/FoldBlocks.lean'
(A / 'FoldBlocks.lean').write_bytes(source.read_bytes())
held = {'Proofs/FoldBlocks.lean': sha(source), 'spec.lock': sha(ROOT / 'spec.lock'),
        'lean-toolchain': sha(ROOT / 'lean-toolchain'), 'lakefile.toml': sha(ROOT / 'lakefile.toml')}
for line in (ROOT / 'spec.lock').read_text().splitlines():
    digest, name = line.split('  ', 1)
    assert sha(ROOT / name) == digest, name
    held[name] = digest
command = ['lake', 'build', 'Proofs.FoldBlocks']
record = {'status': 'running', 'attempt': number, 'command': command,
          'started_utc': datetime.now(timezone.utc).isoformat(),
          'started_monotonic_ns': time.monotonic_ns(), 'before_hashes': held,
          'runner_sha256': sha(Path(__file__))}

def save():
    (A / 'execution.json').write_text(json.dumps(record, indent=2) + '\n')

save()
with (A / 'build.log').open('x') as f:
    result = subprocess.run(command, cwd=ROOT, stdout=f, stderr=subprocess.STDOUT)
record.update(exit_code=result.returncode, finished_utc=datetime.now(timezone.utc).isoformat(),
              finished_monotonic_ns=time.monotonic_ns(), log_sha256=sha(A / 'build.log'))
record['after_hashes'] = {name: sha(ROOT / name) for name in held}
record['inputs_unchanged'] = record['after_hashes'] == held
record['status'] = 'passed' if result.returncode == 0 and record['inputs_unchanged'] else 'failed'
save()
assert record['inputs_unchanged']
if result.returncode == 0:
    log = (A / 'build.log').read_text()
    names = ['fold_blocks', 'ordered_blocks_witness', 'empty_blocks_witness']
    facts = {}
    for name in names:
        full = 'Lean1090.Proofs.FoldBlocks.' + name
        match = re.search(re.escape("'" + full + "'") + r' depends on axioms: \[(.*?)\]', log, re.S)
        if match:
            axioms = [x.strip() for x in match[1].split(',') if x.strip()]
        else:
            assert f"'{full}' does not depend on any axioms" in log, name
            axioms = []
        assert set(axioms) <= {'propext', 'Classical.choice', 'Quot.sound'}, (name, axioms)
        facts[full] = axioms
    record['printed_axioms'] = facts
    save()
print(json.dumps({'status': record['status'], 'attempt': number,
                  'execution_sha256': sha(A / 'execution.json'),
                  'source_sha256': sha(source), 'log_sha256': sha(A / 'build.log')}))
sys.exit(result.returncode)
