#!/usr/bin/env python3
"""Check exact frozen inventory and SHA-256 values without modifying anything."""
from pathlib import Path
import hashlib
from frozen_paths import frozen_paths

lock = Path('spec.lock')
if not lock.is_file():
    raise SystemExit('FAIL: approved spec.lock is absent.')
recorded = {}
for line in lock.read_text().splitlines():
    digest, separator, name = line.partition('  ')
    if not separator or len(digest) != 64 or any(c not in '0123456789abcdef' for c in digest):
        raise SystemExit(f'FAIL: malformed SHA-256 lock line: {line!r}')
    if name in recorded:
        raise SystemExit(f'FAIL: duplicate lock path: {name}')
    recorded[name] = digest
expected = {str(path) for path in frozen_paths()}
if set(recorded) != expected:
    raise SystemExit(f'FAIL: frozen inventory changed: {set(recorded) ^ expected}')
for name, digest in recorded.items():
    if not Path(name).is_file() or hashlib.sha256(Path(name).read_bytes()).hexdigest() != digest:
        raise SystemExit(f'FAIL: frozen file changed or missing: {name}')
print(f'Lock audit: {len(recorded)} frozen files match SHA-256.')
