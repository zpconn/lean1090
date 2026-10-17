from pathlib import Path
import hashlib
import importlib.util
import json
import shutil
import subprocess
import tempfile

ROOT = Path.cwd()
PROPOSAL = ROOT / '.cache/fc004-proposal'

def module(path, name):
    specification = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(specification)
    specification.loader.exec_module(result)
    return result

original = set(module(ROOT / 'scripts/frozen_paths.py', 'original').frozen_paths())
proposed = set(module(PROPOSAL / 'scripts/frozen_paths.py', 'proposed').frozen_paths())
assert original <= proposed
assert len(original) == 61 and len(proposed) == 86
assert len(proposed - original) == 25
checks = []

def run(directory, command, expected=None):
    result = subprocess.run(command, cwd=directory, text=True, capture_output=True)
    output = result.stdout + result.stderr
    if expected is None:
        assert result.returncode == 0, output
    else:
        assert result.returncode != 0 and expected in output, output
    return output

with tempfile.TemporaryDirectory(prefix='lean1090-fc004-lock-review-') as temp:
    directory = Path(temp)
    for path in proposed:
        target = directory / path
        target.parent.mkdir(parents=True, exist_ok=True)
        source = PROPOSAL / path if (PROPOSAL / path).exists() else ROOT / path
        shutil.copyfile(source, target)
    lock = ''.join(f'{hashlib.sha256((directory / path).read_bytes()).hexdigest()}  {path}\n'
                   for path in sorted(proposed))
    (directory / 'spec.lock').write_text(lock)
    run(directory, ['python3', 'scripts/check_lock.py'])
    checks.append('intact candidate inventory passes')
    for path in sorted(proposed):
        target = directory / path
        before = target.read_bytes()
        target.write_bytes(before + b'\n')
        expected = f'FAIL: frozen file changed or missing: {path}'
        run(directory, ['python3', 'scripts/check_lock.py'], expected)
        if path == Path('Spec/Parity.lean'):
            output = run(directory, ['bash', 'scripts/check_all.sh', '--quick'], expected)
            assert output.strip() == expected, output
        target.write_bytes(before)
    checks.append('each of 86 frozen-file mutations rejected; full gate checks lock first')
    for path in sorted(proposed - original):
        target = directory / path
        before = target.read_bytes()
        target.unlink()
        run(directory, ['python3', 'scripts/check_lock.py'],
            f'FAIL: frozen file changed or missing: {path}')
        target.write_bytes(before)
    checks.append('each of 25 newly frozen-file deletions rejected')
    for name in ['Spec/Unapproved.lean', 'Spec/unapproved-data.txt',
                 'scripts/check_unapproved_differential.py', 'scripts/FuzzUnapproved.lean',
                 'Tests/UnapprovedDifferential.lean', 'Tests/UnapprovedGenerator.lean',
                 'differential/message-oracle/src/unapproved.rs',
                 'differential/cpr-oracle/src/unapproved.rs']:
        target = directory / name
        target.write_text('unapproved new file\n')
        run(directory, ['python3', 'scripts/check_lock.py'], 'FAIL: frozen inventory changed:')
        target.unlink()
    checks.append('eight added-file inventory mutations rejected')
    (directory / 'spec.lock').write_text(lock + lock.splitlines(keepends=True)[0])
    run(directory, ['python3', 'scripts/check_lock.py'], 'FAIL: duplicate lock path:')
    checks.append('duplicate lock record rejected')
    (directory / 'spec.lock').write_text(lock)
    run(directory, ['python3', 'scripts/test_lock.py'])
    checks.append('unchanged existing test_lock.py passes against proposed inventory')

summary = {'status': 'PASS', 'old_paths': len(original), 'proposed_paths': len(proposed),
           'new_paths': list(map(str, sorted(proposed - original))), 'checks': checks}
(PROPOSAL / 'lock-review.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary, indent=2))
