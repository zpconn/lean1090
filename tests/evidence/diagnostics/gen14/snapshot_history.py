#!/usr/bin/env python3
"""Record immutable prior results before the new untimed campaign."""
import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

E = Path('tests/evidence/diagnostics/gen14')
roots = [f'tests/evidence/diagnostics/gen{i}' for i in range(14)]
roots += ['bench/runs', 'docs/images']
roots += [str(p) for p in sorted(Path('tests/evidence/optimization').glob('gen*'))
          if p.is_dir() and p.name[3:].isdigit() and int(p.name[3:]) <= 14]
individual = [f'docs/GEN{i}-COST-BREAKDOWN.md' for i in range(14)] + ['bench/results.csv']
paths = {p for root in roots for p in Path(root).rglob('*') if p.is_file()}
paths.update(map(Path, individual))
record = {'captured_utc': datetime.now(timezone.utc).isoformat(), 'roots': roots,
          'individual_paths': individual, 'files': {},
          'notes': ['All existing benchmark reviews are complete before this snapshot; no pending membership addition is permitted.',
                    'Current authorization prose in AGENTS.md, PROGRESS.md and docs/OPTIMIZATION.md is outside this measured-evidence inventory.']}
for path in sorted(paths):
    raw = path.read_bytes()
    record['files'][str(path)] = {'sha256': hashlib.sha256(raw).hexdigest(), 'bytes': len(raw)}
out = E / 'historical-inputs.json'
assert not out.exists()
out.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps({'files': len(paths), 'bytes': sum(row['bytes'] for row in record['files'].values()),
                  'sha256': hashlib.sha256(out.read_bytes()).hexdigest()}))
