#!/usr/bin/env python3
"""Check the exact pilot capstone and the two concrete witnesses."""
from pathlib import Path
import re
from compile_fragment import compile_fragment

run = compile_fragment(Path('scripts/AuditBDS50.lean'), ['Capstones', 'Proofs.BDS50'])
if run.returncode:
    raise SystemExit(run.stdout + run.stderr)
expected = {'Lean1090.PilotAudit.fullRefinement',
            'Lean1090.Proofs.BDS50.pilot_nonvacuous',
            'Lean1090.Proofs.BDS50.exact_threshold_nonvacuous'}
allowed = {'propext', 'Classical.choice', 'Quot.sound'}
pattern = re.compile(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)")
seen = set()
for match in pattern.finditer(run.stdout):
    name, axioms = match.groups()
    forbidden = ({a.strip() for a in axioms.split(',')} - allowed) if axioms else set()
    if forbidden:
        raise SystemExit(f'FAIL: {name}: forbidden axioms {forbidden}')
    seen.add(name)
if seen != expected or pattern.sub('', run.stdout).strip():
    raise SystemExit('FAIL: incomplete or unexpected pilot proof audit:\n' + run.stdout)
print(run.stdout, end='')
print('Pilot audit: exact BDS50 refinement and both witnesses passed.')
