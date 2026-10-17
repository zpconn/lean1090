#!/usr/bin/env python3
"""Checkpoint completeness/statement consistency, not the post-approval gate."""
from pathlib import Path
import re

required = ['GOAL.md','AGENTS.md','CLAUDE.md','PROGRESS.md','SCOPE.md','THEOREMS.md',
            'Capstones.lean','bench/BENCHMARK.md','TRUSTED.md','docs/SOURCES.md',
            'Spec/Message.lean','Spec/ADSB.lean','Spec/CommB.lean','Spec/Parity.lean',
            'Spec/Altitude.lean','Spec/CPR.lean','Spec/CPRContracts.lean',
            'Spec/CPRFormula.lean','Spec/CPRPolicy.lean','Spec/CPRFloat.lean',
            'bench/oracle/Cargo.toml','bench/oracle/Cargo.lock','bench/oracle/src/main.rs',
            'scripts/Final.lean','scripts/CheckHypotheses.lean','Model/Types.lean',
            'Spec/StandardExamples.lean','Spec/StandardFullExamples.lean',
            'Spec/Assignment.lean','Spec/AssignmentAltitude.lean','scripts/CheckAssignment.lean',
            'docs/STANDARD-EXAMPLES.md','Spec/BDS50.lean',
            'Proofs/BDS50.lean','bench/interleave.py','docs/BDS50-PILOT.md','docs/FUZZING.md']
for name in required:
    if not Path(name).is_file() or not Path(name).stat().st_size:
        raise SystemExit(f'Missing checkpoint artifact: {name}')
source = Path('Capstones.lean').read_text()
document = Path('THEOREMS.md').read_text()
statements = re.findall(r'^def (\w+)\b(.*?)(?=\n/--|\nend Lean1090.Capstones)', source, re.M|re.S)
for name, rest in statements:
    statement = 'def ' + name + rest.rstrip()
    if f'```lean\n{statement}\n```' not in document:
        raise SystemExit(f'THEOREMS.md does not quote {name} verbatim')
# This remains a document consistency check after freezing, not the full gate.
if 'rs1090-derived' not in document or 'rs1090-derived' not in Path('SCOPE.md').read_text():
    raise SystemExit('Missing explicit oracle-derived source boundary')
print(f'Document audit: {len(required)} required artifacts; {len(statements)} exact capstone statements.')
