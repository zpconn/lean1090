#!/usr/bin/env python3
"""Retain local QNH startup functions and source excerpts; no decoder runs."""
import hashlib
import json
from pathlib import Path
import subprocess

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    record = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert not (OUT / 'additional-inspection.json').exists()
    assert all(sha(p) == r['sha256'] for p, r in record['inputs'].items())
    commands = []
    for suffix, name in [('cbQNHValueTable___closed__1', 'table-constructor'),
                         ('cbQNHValueTable___lam__0___closed__3', 'literal-round'),
                         ('cbQNHValueTable___lam__0___closed__2', 'literal-ratio')]:
        symbol = '_init_' + P + suffix
        argv = ['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol,
                '.lake/build/bin/lean1090']
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        (OUT / ('binary-' + name + '.txt')).write_bytes(result.stdout)
        (OUT / ('binary-' + name + '.stderr')).write_bytes(result.stderr)
        assert result.returncode == 0 and ('<' + symbol + '>:').encode() in result.stdout
        commands.append({'argv': argv, 'stdout': 'binary-' + name + '.txt',
                         'stderr': 'binary-' + name + '.stderr', 'exit_code': result.returncode})
    cpath = '.lake/build/ir/Impl/CommB.c'
    lines = (OUT / 'retained' / cpath).read_text().splitlines()
    excerpts = {}
    for name, first, last in [('qnh-constants-entry-lookup', 852, 947),
                              ('hard-validity-call', 3090, 3145),
                              ('density-call', 4800, 4855),
                              ('module-initializer', 6872, 6920)]:
        path = OUT / ('C-' + name + '.txt')
        path.write_text('\n'.join(f'{i + 1}: {lines[i]}' for i in range(first - 1, last)) + '\n')
        excerpts[name] = {'source': cpath, 'source_sha256': sha(OUT / 'retained' / cpath),
                          'first_line': first, 'last_line': last, 'path': path.name,
                          'sha256': sha(path)}
    assert all(sha(p) == r['sha256'] for p, r in record['inputs'].items())
    (OUT / 'additional-inspection.json').write_text(json.dumps({
        'scope': 'Read-only objdump and retained generated-C excerpts; no native decoder execution.',
        'inspection_sha256': sha(OUT / 'inspection-inputs.json'),
        'commands': commands, 'excerpts': excerpts, 'all_captured_inputs_unchanged': True,
    }, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'commands': len(commands), 'excerpts': len(excerpts)}))


if __name__ == '__main__':
    main()
