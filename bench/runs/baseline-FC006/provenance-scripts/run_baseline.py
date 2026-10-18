#!/usr/bin/env python3
"""Record clean-commit provenance around the unchanged frozen interleaver.

Run only after all correctness work has exited and the FC006 commit is clean.
All initial evidence is ignored so both benchmark modes see a clean tree.
Copy this script and its complete output into bench/runs after timing finishes.
"""
import csv
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shlex
import statistics
import subprocess

ROOT = Path.cwd().resolve()
OUT = ROOT / '.cache/baseline-FC006'
BIN = ROOT / '.lake/build/bin/lean1090-bench'
LOCK = '5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
COMMANDS = []


def now():
    return datetime.now(timezone.utc).isoformat()


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def write(name, data):
    (OUT / name).write_text(json.dumps(data, indent=2) + '\n')


def command(args, name):
    item = {'argv': args, 'started_at': now(), 'log': name}
    COMMANDS.append(item)
    write('commands.json', COMMANDS)
    with (OUT / name).open('w') as f:
        result = subprocess.run(args, cwd=ROOT, stdout=f, stderr=subprocess.STDOUT)
    item.update(finished_at=now(), exit_code=result.returncode)
    write('commands.json', COMMANDS)
    result.check_returncode()


def clean(label, expected=None):
    head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip()
    status = subprocess.check_output(['git', 'status', '--porcelain=v1', '--untracked-files=all'], text=True)
    write(label + '-git.json', {'at': now(), 'commit': head, 'command':
          ['git', 'status', '--porcelain=v1', '--untracked-files=all'],
          'stdout': status, 'clean': status == ''})
    assert status == '', status
    assert expected is None or head == expected
    assert sha(ROOT / 'spec.lock') == LOCK
    command(['python3', 'scripts/check_lock.py'], label + '-lock.log')
    return head


def observe(label):
    command(['python3', str(ROOT / '.cache/baseline-prep/capture_host.py'),
             '--output', str(OUT / (label + '-host.json'))], label + '-host.log')
    command(['python3', 'bench/check_worker.py', '--capture-environment-only',
             '--output', str(OUT / (label + '-environment'))], label + '-environment.log')
    host = json.loads((OUT / (label + '-host.json')).read_text())
    assert all(v in (None, '') for v in host['compilation_environment'].values()), 'inspect compilation overrides before timing'
    assert all(v['status'] == 'unavailable' and v.get('errno') == 2 for v in host['cargo_config_candidates']), 'inspect Cargo configuration before timing'
    fingerprints = host['dist_oracle_fingerprints']['records']
    assert fingerprints and all(v['fields']['rustflags'] == [] for v in fingerprints)
    env = json.loads((OUT / (label + '-environment/environment.json')).read_text())
    traces = [ROOT / p for p in env['compiled_c_traces']]
    traces.append(Path(str(BIN) + '.trace'))
    drivers = []
    for trace in traces:
        for entry in json.loads(trace.read_text())['log']:
            if not entry['message'].startswith('.> '):
                continue
            args = shlex.split(entry['message'][3:])
            assert Path(args[0]).name == 'clang'
            normal = subprocess.run(args + ['-###'], capture_output=True, text=True, check=True)
            disabled = subprocess.run(args + ['-###', '--no-default-config'], capture_output=True, text=True, check=True)
            drivers.append({'trace': str(trace.relative_to(ROOT)), 'argv': args,
                            'normal_stdout': normal.stdout, 'normal_stderr': normal.stderr,
                            'no_default_config_stdout': disabled.stdout, 'no_default_config_stderr': disabled.stderr})
            write(label + '-effective-clang-drivers.json', drivers)
            assert normal.stdout == disabled.stdout and normal.stderr == disabled.stderr, 'Clang default configuration changes effective driver'
            if '-c' in args:
                assert '"-target-cpu" "x86-64"' in normal.stderr and '"-tune-cpu" "generic"' in normal.stderr
                assert '"-O3"' in normal.stderr and '"-ffp-contract=off"' in normal.stderr


def validate_mode(mode, expected_binary):
    folder = OUT / mode
    meta = json.loads((folder / 'metadata.json').read_text())
    rows = list(csv.DictReader((folder / 'samples.csv').open()))
    assert meta['status'] == 'complete'
    assert len(rows) == 48
    assert meta['lean_binary_sha256'] == expected_binary == sha(BIN)
    assert meta['windows_power_plan_before']['status'] == 'queried'
    assert meta['windows_power_plan_after']['status'] == 'queried'
    assert meta['windows_power_plan_before']['scheme_guid'] == meta['windows_power_plan_after']['scheme_guid']
    for index, row in enumerate(rows):
        assert int(row['order']) == index + 1
        assert row['implementation'] == ('rs1090' if index % 2 == 0 else 'lean1090')
        assert row['phase'] == ('warmup' if index < 6 else 'measured')
        assert int(row['pair']) == (index // 2 + 1 if index < 6 else (index - 6) // 2 + 1)
        assert int(row['messages']) == 172432
        assert int(row['positions']) == (0 if mode == 'decode' else 11347)
    for side in ('rs1090', 'lean1090'):
        samples = [int(r['nanoseconds']) for r in rows if r['phase'] == 'measured' and r['implementation'] == side]
        assert len(samples) == 21
        assert statistics.median(samples) == meta['medians_nanoseconds'][side]
    assert meta['lean_over_rust'] == meta['medians_nanoseconds']['rs1090'] / meta['medians_nanoseconds']['lean1090']
    return {'mode': mode, 'samples': len(rows), 'medians_nanoseconds': meta['medians_nanoseconds'],
            'messages_per_second': meta['messages_per_second'], 'lean_over_rust': meta['lean_over_rust'],
            'samples_sha256': sha(folder / 'samples.csv'), 'metadata_sha256': sha(folder / 'metadata.json')}


def main():
    OUT.mkdir(exist_ok=False)
    commit = clean('before-build')
    write('authorization.json', {'at': now(), 'scope': 'Approved FC006 baseline only; stop before gen1',
          'operator_precondition': 'All project correctness commands completed and all collaborating agents idle before this script starts.'})
    command(['bench/run_oracle.sh', '--build-only'], 'oracle-prebuild.log')
    objects = [Path(x) for x in shlex.split((BIN.with_suffix('.rsp')).read_text()) if x.endswith('.c.o.export')]
    assert len(objects) == 21
    remove = []
    for obj in objects:
        relative = obj.relative_to(ROOT / '.lake/build/ir')
        source = ROOT / str(relative).removesuffix('.c.o.export')
        source = source.with_suffix('.lean')
        assert source.is_file()
        committed = subprocess.check_output(['git', 'show', commit + ':' + str(source.relative_to(ROOT))])
        assert committed == source.read_bytes()
        cfile = Path(str(obj).removesuffix('.o.export'))
        remove.extend([cfile, Path(str(cfile) + '.hash'), obj,
                       Path(str(obj) + '.hash'), Path(str(obj) + '.trace')])
    remove.extend([BIN, Path(str(BIN) + '.hash'), Path(str(BIN) + '.trace')])
    write('fresh-build-removals.json', [{'path': str(p.relative_to(ROOT)), 'sha256': sha(p)} for p in remove if p.is_file()])
    for p in remove:
        assert p.is_relative_to(ROOT / '.lake/build')
        p.unlink(missing_ok=True)
    command(['lake', '--no-cache', '--rehash', '-v', 'build', 'lean1090-bench'], 'lean-fresh-build.log')
    rebuilt = [Path(x) for x in shlex.split((BIN.with_suffix('.rsp')).read_text()) if x.endswith('.c.o.export')]
    assert set(rebuilt) == set(objects) and len(rebuilt) == 21
    build_started = datetime.fromisoformat(COMMANDS[-1]['started_at']).timestamp()
    native_inputs = []
    for obj in rebuilt:
        cfile = Path(str(obj).removesuffix('.o.export'))
        trace = Path(str(obj) + '.trace')
        assert all(p.is_file() and p.stat().st_mtime >= build_started for p in (cfile, obj, trace))
        native_inputs.append({str(p.relative_to(ROOT)): sha(p) for p in (cfile, obj, trace)})
    write('fresh-native-inputs.json', native_inputs)
    binary_sha = sha(BIN)
    write('binary-built.json', {'at': now(), 'commit': commit, 'sha256': binary_sha,
          'path': str(BIN.relative_to(ROOT)), 'spec_lock_sha256': sha(ROOT / 'spec.lock'),
          'build_command': COMMANDS[-1], 'project_c_objects_regenerated': len(objects),
          'worker_source_sha256': sha(ROOT / 'Bench/WholeDecoder.lean')})
    observe('before')
    results = []
    for mode in ('decode', 'cpr'):
        clean('before-' + mode, commit)
        assert sha(BIN) == binary_sha
        command(['python3', 'bench/interleave.py', '--mode', mode,
                 '--lean-worker', str(BIN), '--output', str(OUT / mode)], mode + '-interleave.log')
        results.append(validate_mode(mode, binary_sha))
    observe('after')
    clean('after-timing', commit)
    assert sha(BIN) == binary_sha
    write('summary.json', {'status': 'complete', 'commit': commit, 'binary_sha256': binary_sha,
          'spec_lock_sha256': LOCK, 'results': results, 'completed_at': now(),
          'next': 'Stop for user review before optimization gen1.'})
    print(json.dumps(results, indent=2), flush=True)


if __name__ == '__main__':
    main()
