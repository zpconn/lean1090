#!/usr/bin/env python3
"""Reproducible proof-visible BDS50 pilot, with persistent ABAB workers."""
from __future__ import annotations
import argparse
import csv
from fractions import Fraction
import hashlib
import json
import os
from pathlib import Path
import platform
import statistics
import struct
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
CORPUS = ROOT / 'vendor/rs1090/crates/rs1090/data/long_flight.csv'
SHA = '3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505'
LEAN = ROOT / '.lake/build/bin/bds50Pilot'
RUST = ROOT / '.cache/rs1090-target/dist/lean1090-bds50-pilot'
CACHE = ROOT / '.cache/bds50'


def corpus_words() -> Path:
    raw = CORPUS.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    rows = raw.decode().splitlines()
    assert len(rows) == 172432
    words = []
    for row in rows:
        message = bytes.fromhex(row.split(',')[1][18:])
        if message[0] >> 3 in (20, 21):
            assert len(message) == 14
            words.append(int.from_bytes(message[4:11], 'big'))
    assert len(words) == 47714
    CACHE.mkdir(parents=True, exist_ok=True)
    path = CACHE / 'corpus-words.txt'
    path.write_text(''.join(f'{word}\n' for word in words))
    return path


def number(s: str, rust: bool) -> Fraction | None:
    if s == 'none':
        return None
    if rust:
        return Fraction(struct.unpack('>d', int(s).to_bytes(8, 'big'))[0])
    return Fraction(s)


def differential(path: Path) -> dict:
    lean = subprocess.check_output([str(LEAN), '--audit', str(path)], text=True).splitlines()
    rust = subprocess.check_output([str(RUST), '--audit', str(path)], text=True).splitlines()
    words = path.read_text().splitlines()
    assert len(lean) == len(rust) == len(words)
    accepted = 0
    score_rejected = 0
    for i, (a, b) in enumerate(zip(lean, rust)):
        at, bt = a.split(), b.split()
        aa = [at[0]] + [number(x, False) for x in at[1:]]
        bb = [bt[0]] + [number(x, True) for x in bt[1:]]
        if aa != bb:
            raise AssertionError(f'row {i}, MB={int(words[i]):014x}, Lean={aa}, Rust={bb}')
        accepted += at[0] == 'accepted'
        score_rejected += at[0] == 'score-reject'
    return {'inputs': len(words), 'accepted': accepted, 'score_rejected': score_rejected,
            'hard_rejected': len(words)-accepted-score_rejected, 'matched': True,
            'fields': ['roll', 'track', 'groundspeed', 'track_rate', 'TAS', 'binary64_score']}


class Worker:
    def __init__(self, binary: Path, path: Path):
        self.p = subprocess.Popen([str(binary), '--worker', str(path)],
                                  stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
        assert self.p.stdout and self.p.stdin
        ready = self.p.stdout.readline().strip()
        if ready != 'ready 47714':
            raise RuntimeError(f'bad worker startup: {ready}')
    def run(self) -> tuple[int, int]:
        assert self.p.stdin and self.p.stdout
        self.p.stdin.write('run\n'); self.p.stdin.flush()
        line = self.p.stdout.readline().strip()
        nanos, accepted = map(int, line.split())
        return nanos, accepted
    def close(self):
        if self.p.stdin and self.p.poll() is None:
            self.p.stdin.write('quit\n'); self.p.stdin.flush()
        self.p.wait(timeout=30)


def power_plan() -> dict:
    commands = [['powercfg.exe', '/getactivescheme'],
                ['/mnt/c/Windows/System32/powercfg.exe', '/getactivescheme']]
    attempts = []
    for cmd in commands:
        try:
            p = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
            attempts.append({'command': cmd, 'returncode': p.returncode,
                             'stdout': p.stdout.strip(), 'stderr': p.stderr.strip()})
            if p.returncode == 0:
                return {'status': 'recorded', 'attempts': attempts}
        except (OSError, subprocess.TimeoutExpired) as e:
            attempts.append({'command': cmd, 'error': str(e)})
    return {'status': 'unavailable', 'attempts': attempts}


def fingerprints() -> dict:
    sources = ['Impl/BDS50.lean', 'Impl/Binary64.lean', 'Model/BDS50.lean',
               'Spec/BDS50.lean', 'Proofs/BDS50.lean', 'Bench/BDS50.lean',
               'bench/bds50/Cargo.toml', 'bench/bds50/Cargo.lock',
               'bench/bds50/src/main.rs']
    cpuinfo = Path('/proc/cpuinfo').read_text() if Path('/proc/cpuinfo').exists() else ''
    model = next((line.split(':',1)[1].strip() for line in cpuinfo.splitlines()
                  if line.startswith('model name')), 'unavailable')
    return {'source_sha256': {name: hashlib.sha256((ROOT/name).read_bytes()).hexdigest()
                              for name in sources},
            'binary_sha256': {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest()
                              for p in [LEAN, RUST]},
            'cpu_model': model,
            'lean_version': subprocess.check_output(['lake','env','lean','--version'],
                                                     cwd=ROOT, text=True).strip(),
            'rust_version': subprocess.check_output(['rustc','--version'], text=True).strip(),
            'RUSTFLAGS': os.environ.get('RUSTFLAGS'),
            'CARGO_ENCODED_RUSTFLAGS': os.environ.get('CARGO_ENCODED_RUSTFLAGS'),
            'lean_c_build_trace': json.loads((ROOT/'.lake/build/ir/Impl/BDS50.c.o.export.trace').read_text())}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, default=ROOT/'bench/evidence/bds50-pilot.json')
    parser.add_argument('--generated', type=Path)
    parser.add_argument('--check-only', action='store_true')
    args = parser.parse_args()
    path = corpus_words()
    affinity = sorted(os.sched_getaffinity(0)) if hasattr(os, 'sched_getaffinity') else []
    cpu = int(os.environ.get('BENCH_CPU', affinity[0])) if affinity else None
    if cpu is not None:
        assert cpu in affinity
        os.sched_setaffinity(0, {cpu})
    result = {'date_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
              'machine': platform.platform(), 'cpu': cpu, 'allowed_cpus_before_pin': affinity,
              'windows_power_plan': power_plan(), 'corpus_sha256': SHA,
              'rs1090_commit': subprocess.check_output(['git','-C',str(ROOT/'vendor/rs1090'),
                                                        'rev-parse','HEAD'], text=True).strip(),
              'lean_function': 'Lean1090.Impl.BDS50.decode',
              'proof': 'Lean1090.Proofs.BDS50.refinement',
              'protocol': '3 AB warmups, then 21 AB pairs; A=rs1090, B=Lean',
              'corpus_differential': differential(path)}
    if args.generated:
        rows = list(csv.reader(args.generated.open()))
        genpath = CACHE/'generated-words.txt'
        genpath.write_text(''.join(row[0]+'\n' for row in rows))
        result['generated_differential'] = differential(genpath)
        result['generated_families'] = {tag: sum(row[1] == tag for row in rows)
                                        for tag in sorted({row[1] for row in rows})}
    if not args.check_only:
        a, b = Worker(RUST, path), Worker(LEAN, path)
        samples = []
        try:
            for phase, runs in [('warmup',3),('measured',21)]:
                for i in range(runs):
                    an, ac = a.run()
                    bn, bc = b.run()
                    assert ac == bc == result['corpus_differential']['accepted']
                    samples.append({'phase':phase, 'pair':i, 'rs1090_ns':an, 'lean_ns':bn,
                                    'accepted':ac})
                    print(f'{phase} {i}: Rust {an/1e6:.3f} ms, Lean {bn/1e6:.3f} ms', flush=True)
        finally:
            a.close(); b.close()
        measured = [s for s in samples if s['phase'] == 'measured']
        am = statistics.median(s['rs1090_ns'] for s in measured)
        bm = statistics.median(s['lean_ns'] for s in measured)
        result['samples'] = samples
        result['median'] = {'rs1090_ns':am, 'lean_ns':bm,
                            'rs1090_messages_per_second':47714e9/am,
                            'lean_messages_per_second':47714e9/bm,
                            'lean_over_rs1090_throughput':am/bm}
    result['windows_power_plan_after'] = power_plan()
    if 'microsoft' in platform.release().lower():
        if (result['windows_power_plan']['status'] != 'recorded' or
                result['windows_power_plan_after']['status'] != 'recorded'):
            raise RuntimeError('WSL pilot requires successful Windows power-plan captures')
        before = result['windows_power_plan']['attempts'][-1]['stdout']
        after = result['windows_power_plan_after']['attempts'][-1]['stdout']
        if before != after:
            raise RuntimeError('Windows power plan changed during the pilot; run invalid')
    result['build'] = fingerprints()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k in
                      ['corpus_differential','generated_differential','median']}, indent=2))

if __name__ == '__main__':
    main()
