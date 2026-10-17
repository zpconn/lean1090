#!/usr/bin/env python3
"""Compile the frozen manifest and audit its actual proof constants."""
from pathlib import Path
import re
from compile_fragment import compile_fragment

source = Path('scripts/Final.lean').read_text()
names = set(re.findall(r'^def (\w+)', Path('Capstones.lean').read_text(), re.M))
expected = {'Lean1090.Final.' + n for n in names}
declared = set(re.findall(r'^#print axioms (\S+)', source, re.M))
if declared != expected:
    raise SystemExit(f'FAIL: final manifest coverage differs: {declared ^ expected}')
run = compile_fragment(Path('scripts/Final.lean'),
                       ['Capstones', 'Impl', 'Proofs', 'Proofs.BDS50'])
if run.returncode:
    raise SystemExit('FAIL: required final theorem manifest does not compile:\n' + run.stdout + run.stderr)
allowed = {'propext', 'Classical.choice', 'Quot.sound'}
seen = set()
pattern = re.compile(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)")
for match in pattern.finditer(run.stdout):
    name, axioms = match.groups()
    forbidden = ({a.strip() for a in axioms.split(',')} - allowed) if axioms else set()
    if forbidden:
        raise SystemExit(f'FAIL: {name}: forbidden axioms {forbidden}')
    if name in expected:
        seen.add(name)
remaining = pattern.sub('', run.stdout).strip()
if remaining:
    raise SystemExit(f'FAIL: unexpected final axiom-audit output: {remaining}')
if seen != expected:
    raise SystemExit(f'FAIL: missing final proof audits: {expected - seen}')
print(f'Final manifest: {len(seen)} exact theorem types and permitted axioms.')
