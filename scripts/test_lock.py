#!/usr/bin/env python3
"""Test lock guards in a disposable copy; never modify project frozen files."""
from pathlib import Path
import hashlib
import shutil
import subprocess
import tempfile
from frozen_paths import frozen_paths


def run(directory, command, expected=None):
    result = subprocess.run(command, cwd=directory, text=True, capture_output=True)
    output = result.stdout + result.stderr
    if expected is None:
        if result.returncode != 0:
            raise SystemExit('Lock positive self-test failed:\n' + output)
    elif result.returncode == 0 or expected not in output:
        raise SystemExit('Lock rejection self-test failed:\n' + output)
    return output


with tempfile.TemporaryDirectory(prefix='lean1090-lock-audit-') as temp:
    directory = Path(temp)
    paths = frozen_paths()
    for path in paths:
        target = directory / path
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
    lock = ''.join(f'{hashlib.sha256((directory / p).read_bytes()).hexdigest()}  {p}\n'
                   for p in paths)
    (directory / 'spec.lock').write_text(lock)
    run(directory, ['python3', 'scripts/check_lock.py'])
    for name in ['Spec/Parity.lean', 'scripts/audit_source.py',
                 'scripts/frozen_paths.py', 'scripts/check_lock.py',
                 'scripts/check_all.sh']:
        target = directory / name
        original = target.read_bytes()
        target.write_bytes(original + b'\n')
        expected = 'FAIL: frozen file changed or missing: ' + name
        run(directory, ['python3', 'scripts/check_lock.py'], expected)
        if name == 'Spec/Parity.lean':
            output = run(directory, ['bash', 'scripts/check_all.sh', '--quick'], expected)
            if output.strip() != expected:
                raise SystemExit('Full gate did work before rejecting the changed lock input')
        target.write_bytes(original)
    for filename in ['Spec/Unapproved.lean', 'Spec/unapproved-data.txt']:
        added = directory / filename
        added.write_text('unapproved new file\n')
        run(directory, ['python3', 'scripts/check_lock.py'], 'FAIL: frozen inventory changed:')
        added.unlink()
    (directory / 'spec.lock').write_text(lock + lock.splitlines(keepends=True)[0])
    run(directory, ['python3', 'scripts/check_lock.py'], 'FAIL: duplicate lock path:')
    (directory / 'spec.lock').write_text(lock)
    run(directory, ['python3', 'scripts/check_lock.py'])
print('Lock self-tests: intact copy passes; five frozen-file changes, added Spec code/data files, '
      'and duplicate entry rejected; check_all rejects the lock before other work.')
