#!/usr/bin/env python3
"""Review-only runner orchestration checks in a disposable tree.

The copied candidate runner calls a logging python3 stub, not decoder tests.
These checks validate mandatory placement, argument preservation, component-only
messaging and failure handling. They do not claim another differential campaign.
"""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[4]
EVIDENCE = Path(__file__).resolve().parent
CANDIDATE = ROOT / '.cache/fc005-proposal/scripts/run_differential.sh'


def main():
    candidate = CANDIDATE.read_text()
    reports = []
    with tempfile.TemporaryDirectory(prefix='lean1090-tracking-integration-') as temporary:
        root = Path(temporary)
        (root / 'scripts').mkdir()
        (root / 'bin').mkdir()
        (root / 'scripts/run_differential.sh').write_text(candidate)
        (root / 'commb.csv').write_text('fixture\n')
        fake = root / 'bin/python3'
        fake.write_text(
            '#!/bin/sh\n'
            'printf "%s\\n" "$*" >> "$CALLS"\n'
            'case "$*" in\n'
            '  *scripts/check_tracking.py*) exit "${FAIL_TRACKING:-0}";;\n'
            'esac\n'
        )
        fake.chmod(0o755)
        complete = ['--corpus', '--generated', '100000', '--commb-boundaries', 'commb.csv']
        cases = [
            ('quick', complete, 0),
            ('full', ['--corpus', '--generated', '10000000', '--commb-boundaries', 'commb.csv'], 0),
            ('component', ['--cpr-only'], 0),
            ('tracking_failure', complete, 7),
            ('diagnostic_failure', ['--diagnostic', *complete], 7),
        ]
        for name, args, failure in cases:
            calls = root / (name + '.calls')
            env = {
                **os.environ,
                'PATH': str(root / 'bin') + os.pathsep + os.environ['PATH'],
                'CALLS': str(calls),
                'FAIL_TRACKING': str(failure),
            }
            run = subprocess.run(
                ['bash', str(root / 'scripts/run_differential.sh'), *args],
                cwd=root, env=env, capture_output=True, text=True,
            )
            commands = calls.read_text().splitlines()
            tracking = [c for c in commands if 'check_tracking.py' in c]
            message = [c for c in commands if 'check_message_differential.py' in c]
            if name in ('quick', 'full'):
                assert run.returncode == 0
                assert tracking == ['scripts/check_tracking.py --diagnostic']
                assert len(message) == 1
                generated = '100000' if name == 'quick' else '10000000'
                assert '--generated ' + generated in message[0]
                assert '--corpus' in message[0]
                assert '--commb-boundaries commb.csv' in message[0]
                assert commands.index(tracking[0]) > next(
                    i for i, command in enumerate(commands)
                    if command.startswith('scripts/check_cpr_differential.py ')
                )
                assert commands.index(tracking[0]) < commands.index(message[0])
            elif name == 'component':
                assert run.returncode == 0 and not tracking and not message
                assert 'whole-message differential suite was not requested' in run.stdout
            elif name == 'tracking_failure':
                assert run.returncode == 7 and len(tracking) == 1 and not message
            else:
                assert run.returncode == 1 and len(tracking) == 1 and len(message) == 1
                assert '--diagnostic' in message[0]
            reports.append({
                'case': name,
                'runner_arguments': args,
                'simulated_tracking_exit': failure,
                'exit': run.returncode,
                'commands': commands,
                'stdout': run.stdout,
                'stderr': run.stderr,
                'tracking_calls': len(tracking),
                'message_calls': len(message),
                'passed': True,
            })
    result = {
        'method': 'Temporary-copy orchestration test with logging python3 stub; component tests not rerun.',
        'candidate_path': str(CANDIDATE.relative_to(ROOT)),
        'candidate_sha256': hashlib.sha256(CANDIDATE.read_bytes()).hexdigest(),
        'test_script_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        'cases': reports,
    }
    output = EVIDENCE / 'tracking-orchestration-review.json'
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(f'PASS: {len(reports)} orchestration cases; evidence: {output.relative_to(ROOT)}')


if __name__ == '__main__':
    main()
