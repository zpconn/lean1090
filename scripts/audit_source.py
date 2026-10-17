#!/usr/bin/env python3
"""Reject forbidden Lean constructs, ignoring strings and nested comments."""
import re
from pathlib import Path

def code_only(s):
    out = []
    i = depth = 0
    while i < len(s):
        if depth:
            if s.startswith('/-', i):
                depth += 1
                i += 2
            elif s.startswith('-/', i):
                depth -= 1
                i += 2
            else:
                out.append('\n' if s[i] == '\n' else ' ')
                i += 1
        elif s.startswith('/-', i):
            depth = 1
            i += 2
            out.append(' ')
        elif s.startswith('--', i):
            end = s.find('\n', i)
            i = len(s) if end < 0 else end
        elif s[i] == '"':
            out.append(' ')
            i += 1
            while i < len(s):
                c = s[i]
                i += 1
                if c == '\\':
                    i += 1
                elif c == '"':
                    break
        else:
            out.append(s[i])
            i += 1
    if depth:
        raise ValueError('unclosed comment')
    return ''.join(out)

paths = []
for directory in ('Spec', 'Model', 'Impl', 'Proofs'):
    paths += sorted(Path(directory).rglob('*.lean'))
    root = Path(directory + '.lean')
    if root.exists():
        paths.append(root)
paths += [Path('Capstones.lean'), Path('scripts/Final.lean')]
paths += [p for p in sorted(Path('scripts').glob('*.lean')) if p not in paths]
pattern = re.compile(r'\b(?:sorry|admit|axiom|native_decide|unsafe|partial)\b|\b(?:panic|get|unreachable)!|\b(?:implemented_by|extern)\b|\]!')
errors = []
for path in paths:
    for m in pattern.finditer(code_only(path.read_text())):
        errors.append(f'{path}: forbidden token {m.group()}')
if errors:
    raise SystemExit('\n'.join(errors))
print(f'Source audit: {len(paths)} Lean files, no forbidden constructs.')
