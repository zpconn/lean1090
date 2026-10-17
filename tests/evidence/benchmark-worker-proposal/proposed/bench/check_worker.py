#!/usr/bin/env python3
"""Validate the frozen whole-decoder worker; diagnostic timings are not a baseline.

Build the worker, check every prepared byte/timestamp/airport, compare its actual
CPR route against a fresh pinned tracking oracle, and exercise worker protocol.
--capture-environment-only records supplementary benchmark build/machine metadata.
"""
from __future__ import annotations
import argparse
from datetime import datetime, timezone
import gzip
import hashlib
import json
import math
import os
from pathlib import Path
import platform
import selectors
import shutil
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
CORPUS = ROOT / 'vendor/rs1090/crates/rs1090/data/long_flight.csv'
AIRPORTS = ROOT / 'vendor/rs1090/crates/rs1090/data/airports.json'
PIN = '685dfaa34c5ab186c691bca3cfe2a22e12517d30'
CORPUS_SHA = '3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505'
AIRPORTS_SHA = '978b1f95b88769ca5b3b26d3ccc48362116191bb08740eb2c0e0e2f1d82fc760'
COUNT = 172432
POSITION_TOLERANCE = 1e-9
BINARY = ROOT / '.lake/build/bin/lean1090-bench'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def bits(value):
    return struct.unpack('>Q', struct.pack('>d', value))[0]


def floating(value):
    return struct.unpack('>d', int(value).to_bytes(8, 'big'))[0]


def output(command):
    return subprocess.check_output(command, cwd=ROOT, text=True).strip()


def environment():
    """Supplement frozen interleave.py's affinity/Windows-power-plan record."""
    prefix = Path(output(['lean', '--print-prefix']))
    trace_paths = sorted((ROOT / '.lake/build/ir/Impl').glob('*.c.o.export.trace'))
    trace_paths += [ROOT / '.lake/build/ir/Model/Types.c.o.export.trace',
                    ROOT / '.lake/build/ir/Impl.c.o.export.trace',
                    ROOT / '.lake/build/ir/Bench/WholeDecoder.c.o.export.trace']
    traces = {}
    for path in trace_paths:
        data = json.loads(path.read_text())
        commands = [entry['message'] for entry in data.get('log', []) if entry['message'].startswith('.> ')]
        if not commands or any(' -O3 ' not in c or ' -ffp-contract=off ' not in c for c in commands):
            raise AssertionError(f'{path}: missing required -O3/-ffp-contract=off')
        if any(flag in c for c in commands for flag in ('-march=', '-mcpu=', '-mtune=', '-mavx', '-mfma')):
            raise AssertionError(f'{path}: CPU-specific flag')
        traces[str(path.relative_to(ROOT))] = {'sha256': sha(path), 'commands': commands}
    governors = {}
    for path in sorted(Path('/sys/devices/system/cpu').glob('cpu[0-9]*/cpufreq/scaling_governor')):
        governors[str(path)] = path.read_text().strip()
    return {'captured_at': datetime.now(timezone.utc).isoformat(), 'platform': platform.platform(),
            'lean': output(['lean', '--version']), 'c_compiler': output([str(prefix / 'bin/clang'), '--version']),
            'c_compiler_sha256': sha(prefix / 'bin/clang'),
            'cpu_governors': governors or {'status': 'unavailable; WSL host power plan is separately required'},
            'affinity': sorted(os.sched_getaffinity(0)) if hasattr(os, 'sched_getaffinity') else 'unavailable',
            'build_environment': {key: os.environ.get(key) for key in
                                  ('LEAN_CC', 'CC', 'CFLAGS', 'CPPFLAGS', 'LDFLAGS', 'RUSTFLAGS', 'CARGO_ENCODED_RUSTFLAGS')},
            'compiled_c_traces': traces,
            'worker_source_sha256': sha(ROOT / 'Bench/WholeDecoder.lean'),
            'worker_generated_c_sha256': sha(ROOT / '.lake/build/ir/Bench/WholeDecoder.c'),
            'worker_binary_sha256': sha(BINARY),
            'worker_link_response_sha256': sha(ROOT / '.lake/build/bin/lean1090-bench.rsp'),
            'spec_lock_sha256': sha(ROOT / 'spec.lock')}


def compare_position(actual, expected):
    if actual is None or expected is None:
        return actual == expected, actual == expected, 0.0
    if len(actual) != 2 or len(expected) != 2:
        return False, False, None
    a, b = list(map(floating, actual)), list(map(floating, expected))
    if not all(math.isfinite(x) for x in a + b):
        return False, False, None
    error = max(abs(x-y) for x, y in zip(a, b))
    return error <= POSITION_TOLERANCE, actual == expected, error


def tracking_comparison(actual_path, oracle_path):
    actual = [json.loads(line) for line in actual_path.read_text().splitlines()]
    expected = [json.loads(line) for line in oracle_path.read_text().splitlines()]
    if len(actual) != COUNT + 1 or len(expected) != COUNT + 1:
        raise AssertionError('tracking output cardinality differs from corpus plus final state')
    errors = []
    counts = {'messages': COUNT, 'resolved': 0, 'unresolved': 0,
              'resolved_bit_identical': 0, 'routed': 0, 'max_error_degrees': 0.0}
    for index, (a, b) in enumerate(zip(actual[:-1], expected[:-1])):
        if a['id'] != index or b['id'] != index or a['routed'] != b['routed']:
            errors.append({'row': index, 'reason': 'row identity/routing', 'lean': a, 'oracle': b})
        accepted, identical, error = compare_position(a['position'], b['position'])
        if not accepted:
            errors.append({'row': index, 'reason': 'position', 'lean': a, 'oracle': b})
        counts['routed'] += int(a['routed'])
        counts['resolved' if a['position'] is not None else 'unresolved'] += 1
        if a['position'] is not None and identical:
            counts['resolved_bit_identical'] += 1
        if error is not None:
            counts['max_error_degrees'] = max(counts['max_error_degrees'], error)
    a, b = actual[-1], expected[-1]
    if not a.get('final') or not b.get('final'):
        errors.append({'reason': 'missing final state'})
    if not compare_position(a['reference'], b['reference'])[0]:
        errors.append({'reason': 'final reference', 'lean': a['reference'], 'oracle': b['reference']})
    aa, bb = a['aircraft'], b['aircraft']
    if len(aa) != len(bb):
        errors.append({'reason': 'aircraft cardinality', 'lean': len(aa), 'oracle': len(bb)})
    for left, right in zip(aa, bb):
        if any(left[k] != right[k] for k in ('address', 'altitude', 'airport', 'seen')) or not compare_position(left['position'], right['position'])[0]:
            errors.append({'reason': 'aircraft state', 'lean': left, 'oracle': right})
    counts['aircraft'] = len(aa)
    counts['tolerance_degrees'] = POSITION_TOLERANCE
    return counts, errors


def read_line(process, timeout=300):
    with selectors.DefaultSelector() as selector:
        selector.register(process.stdout, selectors.EVENT_READ)
        if not selector.select(timeout):
            raise TimeoutError('worker did not respond')
        return process.stdout.readline().rstrip('\n')


def protocol(mode, corpus, log, commands, expected_positions):
    """One isolated worker; two runs check reset behavior, not performance."""
    with log.open('w') as stderr:
        p = subprocess.Popen([str(BINARY), '--worker-'+mode, str(corpus)], cwd=ROOT,
                             text=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=stderr, bufsize=1)
        responses = []
        try:
            if read_line(p) != f'ready {COUNT}':
                raise AssertionError('incorrect ready response')
            for command in commands:
                p.stdin.write(command+'\n'); p.stdin.flush()
                if command == 'quit':
                    break
                line = read_line(p)
                if command == 'run' and expected_positions is not None:
                    fields = line.split()
                    if len(fields) != 2 or not all(x.isdecimal() for x in fields):
                        raise AssertionError('malformed timing response: '+repr(line))
                    ns, count = map(int, fields)
                    if ns <= 0 or count != expected_positions:
                        raise AssertionError('incorrect elapsed/count response: '+repr(line))
                responses.append(line)
            p.stdin.close()
            code = p.wait(timeout=30)
            extra = p.stdout.read()
            if extra:
                raise AssertionError('unexpected extra worker output')
            should_fail = expected_positions is None
            if (code != 0) != should_fail:
                raise AssertionError(f'worker exit {code}, expected failure={should_fail}')
            return {'mode': mode, 'commands': commands, 'responses': responses,
                    'exit_code': code, 'classification': 'protocol smoke only; not a baseline'}
        finally:
            if p.poll() is None:
                p.kill(); p.wait()
            p.stdout.close()
            if not p.stdin.closed:
                p.stdin.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--lakefile', type=Path, help='review-only alternate config; live config is the default')
    parser.add_argument('--capture-environment-only', action='store_true')
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    if args.capture_environment_only:
        (out/'environment.json').write_text(json.dumps(environment(), indent=2)+'\n')
        return
    result = {'status': 'in-progress', 'claim': 'correctness/protocol validation; no benchmark baseline'}
    commands = []
    def run(command, name, **kwargs):
        commands.append(command)
        with (out/(name+'.log')).open('w') as stream:
            subprocess.run(command, cwd=ROOT, check=True, stdout=stream, stderr=subprocess.STDOUT, **kwargs)
    try:
        assert output(['git', '-C', 'vendor/rs1090', 'rev-parse', 'HEAD']) == PIN
        assert not output(['git', '-C', 'vendor/rs1090', 'status', '--porcelain', '--untracked-files=no'])
        assert sha(CORPUS) == CORPUS_SHA and sha(AIRPORTS) == AIRPORTS_SHA
        lake = ['lake'] + (['-f', str(args.lakefile.resolve())] if args.lakefile else [])
        run(lake+['build', 'lean1090-bench'], 'build')
        (out/'environment.json').write_text(json.dumps(environment(), indent=2)+'\n')
        for mode in ('inputs', 'airports', 'tracking'):
            run([str(BINARY), '--audit-'+mode, str(CORPUS)], 'audit-'+mode)
        rows = [line.split(',') for line in CORPUS.read_text().splitlines()]
        observed = (out/'audit-inputs.log').read_text().splitlines()
        assert len(rows) == len(observed) == COUNT
        for (timestamp, beast), line in zip(rows, observed):
            values = list(map(int, line.split()))
            assert values[0] == bits(float(timestamp))
            assert bytes(values[1:]) == bytes.fromhex(beast[18:])
        airports = json.loads(AIRPORTS.read_text())
        observed = (out/'audit-airports.log').read_text().splitlines()
        assert len(airports) == len(observed) == 6903
        for airport, line in zip(airports, observed):
            icao, latitude, longitude = line.split()
            assert (icao, int(latitude), int(longitude)) == (airport['icao'], bits(airport['lat']), bits(airport['lon']))
        result['preparation'] = {'messages': COUNT, 'timestamps_bit_identical': COUNT,
                                 'prepared_bytes_identical': COUNT, 'airports_bit_identical_in_order': 6903}
        env = os.environ.copy()
        env.update(CARGO_HOME=str(ROOT/'.cache/cargo'), CARGO_TARGET_DIR=str(ROOT/'.cache/rs1090-target'))
        run(['cargo', 'build', '--offline', '--locked', '--manifest-path',
             'differential/tracking-oracle/Cargo.toml', '--profile', 'dist'], 'oracle-build', env=env)
        with (out/'oracle-input.jsonl').open('w') as stream:
            stream.write(json.dumps({'kind': 'header', 'stream': 'full_corpus', 'reference': None, 'update': 0})+'\n')
            for index, (timestamp, beast) in enumerate(rows):
                stream.write(json.dumps({'kind': 'message', 'id': index, 'timestamp_bits': bits(float(timestamp)), 'hex': beast[18:]})+'\n')
        with (out/'oracle-input.jsonl').open() as stream:
            run([str(ROOT/'.cache/rs1090-target/dist/lean1090-tracking-oracle')], 'oracle-output', stdin=stream)
        counts, errors = tracking_comparison(out/'audit-tracking.log', out/'oracle-output.log')
        (out/'tracking-errors.json').write_text(json.dumps(errors, indent=2)+'\n')
        result['tracking'] = counts
        result['tracking_errors'] = len(errors)
        if errors:
            raise AssertionError(f'{len(errors)} worker tracking mismatches; see tracking-errors.json')
        result['protocol'] = []
        for mode, positions in [('decode',0), ('cpr',counts['resolved'])]:
            result['protocol'].append(protocol(mode, CORPUS, out/(mode+'-protocol.stderr.log'), ['run','run','quit'], positions))
        result['protocol'].append(protocol('decode', CORPUS, out/'invalid-command.stderr.log', ['unknown'], None))
        bad = out/'rejected-message.csv'
        altered = rows.copy(); altered[0] = [altered[0][0], altered[0][1][:18]+'8800000000000000000000000000']
        bad.write_text(''.join(','.join(row)+'\n' for row in altered))
        result['protocol'].append(protocol('decode', bad, out/'rejected-message.stderr.log', ['run'], None))
        bad.unlink()
        for label, text in [('empty',''), ('bad-hex', rows[0][0]+','+rows[0][1][:18]+'z'*14+'\n'),
                            ('short-prefix','1,0123\n'), ('nan','NaN,'+rows[0][1]+'\n')]:
            path = out/(label+'.csv'); path.write_text(text)
            p = subprocess.run([str(BINARY), '--worker-decode', str(path)], cwd=ROOT, text=True,
                               capture_output=True, input='quit\n', timeout=30)
            assert p.returncode != 0 and not p.stdout
            (out/(label+'.stderr.log')).write_text(p.stderr)
            path.unlink()
        result['malformed_inputs_rejected'] = 4
        # Enforce the intended tolerance rule with a non-bit-identical positive control.
        a=[bits(1.0),bits(2.0)]
        assert compare_position([bits(1.0+5e-10),a[1]],a)[:2] == (True,False)
        assert not compare_position([bits(1.0+2e-9),a[1]],a)[0]
        assert not compare_position(None,a)[0]
        result['position_comparator_controls'] = 3
        for source in ['Bench/WholeDecoder.lean','bench/check_worker.py', 'spec.lock']:
            result.setdefault('source_sha256',{})[source] = sha(ROOT/source)
        for source in ['.lake/build/ir/Bench/WholeDecoder.c', '.lake/build/ir/Bench/WholeDecoder.c.o.export.trace',
                       '.lake/build/bin/lean1090-bench.rsp']:
            shutil.copyfile(ROOT/source, out/Path(source).name)
        result['status']='passed'
    except BaseException as exc:
        result['status']='failed'; result['error']=f'{type(exc).__name__}: {exc}'
        raise
    finally:
        result['commands']=commands
        (out/'summary.json').write_text(json.dumps(result,indent=2)+'\n')
    for name in ['audit-inputs.log','audit-airports.log','audit-tracking.log','oracle-input.jsonl','oracle-output.log']:
        path=out/name
        with path.open('rb') as src, gzip.open(str(path)+'.gz','wb') as dst:
            shutil.copyfileobj(src,dst)
        path.unlink()
    print(json.dumps({k:v for k,v in result.items() if k not in ('commands','protocol')},indent=2))

if __name__ == '__main__':
    main()
