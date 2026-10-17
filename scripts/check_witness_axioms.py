#!/usr/bin/env python3
"""Audit actual checkpoint witness proofs, never proposition definitions."""
from pathlib import Path
import re
import subprocess

names = []
for path in sorted(Path('Spec').glob('*.lean')):
    text = path.read_text()
    namespace = re.search(r'^namespace (\S+)', text, re.M)
    if namespace:
        names.extend(namespace[1] + '.' + n for n in re.findall(r'^theorem (\w+)', text, re.M))
expected = set(names)
script = Path('scripts/AuditWitnesses.lean').read_text()
actual = set(re.findall(r'^#print axioms (\S+)', script, re.M))
if actual != expected:
    raise SystemExit(f'Stale witness audit: missing={expected-actual}, extra={actual-expected}')
run = subprocess.run(['lake', 'env', 'lean', 'scripts/AuditWitnesses.lean'], text=True, capture_output=True)
if run.returncode:
    raise SystemExit(run.stdout + run.stderr)
allowed = {'propext', 'Classical.choice', 'Quot.sound'}
seen = set()
pattern = re.compile(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)")
for match in pattern.finditer(run.stdout):
    name, axioms = match.groups()
    unexpected = ({a.strip() for a in axioms.split(',')} - allowed) if axioms else set()
    if unexpected:
        raise SystemExit(f'{name}: forbidden axioms {unexpected}')
    seen.add(name)
remaining = pattern.sub('', run.stdout).strip()
if remaining:
    raise SystemExit(f'Unexpected axiom-audit output: {remaining}')
if seen != expected:
    raise SystemExit(f'Incomplete proof audit: missing={expected-seen}')
print(f'Witness axiom audit: {len(seen)} proofs; only the three permitted axioms (or fewer).')
