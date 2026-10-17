#!/usr/bin/env python3
"""Run the frozen 3-warmup/21-measurement paired ABAB protocol.

Workers preload one corpus, print 'ready 172432', and wait for stdin commands.
For each 'run', print '<elapsed nanoseconds> <resolved positions>' and flush.
'quit' ends the worker. All timing is inside each worker's decode/store loop.
"""
from __future__ import annotations

import argparse
import csv
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import platform
import re
import selectors
import shutil
import statistics
import subprocess
import sys

ROOT = Path(__file__).resolve().parent.parent
CORPUS = ROOT / 'vendor/rs1090/crates/rs1090/data/long_flight.csv'
CORPUS_SHA256 = '3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505'
COUNT = 172_432
WARMUPS = 3
RUNS = 21
GUID = re.compile(r'\b[0-9a-fA-F]{8}(?:-[0-9a-fA-F]{4}){3}-[0-9a-fA-F]{12}\b')


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def command_output(command: list[str]) -> str:
    completed = subprocess.run(command, cwd=ROOT, capture_output=True, check=True, timeout=15)
    return completed.stdout.decode('utf-8', errors='replace').strip()


def is_wsl() -> bool:
    return 'microsoft' in platform.release().lower() or bool(os.environ.get('WSL_INTEROP'))


def windows_power_plan(documented: Path | None) -> dict:
    """Record a real query, or explicit user-supplied manual capture if blocked."""
    if not is_wsl():
        return {'status': 'not-wsl', 'captured_at': utc_now()}
    executable = shutil.which('powercfg.exe')
    if not executable:
        standard = Path('/mnt/c/Windows/System32/powercfg.exe')
        if standard.is_file():
            executable = str(standard)
    failure = 'powercfg.exe was not found'
    if executable:
        try:
            completed = subprocess.run([executable, '/getactivescheme'], cwd=ROOT,
                                       capture_output=True, check=True, timeout=15)
            raw = completed.stdout
            output = raw.decode('utf-16-le' if b'\x00' in raw else 'utf-8', errors='replace').strip()
            match = GUID.search(output)
            if not match:
                raise ValueError('powercfg output contained no active-scheme GUID')
            return {'status': 'queried', 'command': [executable, '/getactivescheme'],
                    'output': output, 'scheme_guid': match.group(0).lower(), 'captured_at': utc_now()}
        except (OSError, subprocess.SubprocessError, ValueError) as exc:
            failure = str(exc)
            if isinstance(exc, subprocess.CalledProcessError) and exc.stderr:
                failure += ': ' + exc.stderr.decode('utf-8', errors='replace').strip()
    if documented is None:
        raise RuntimeError('WSL2 Windows power-plan query failed: ' + failure + '. '
                           'Provide --windows-power-plan-file with a documented manual capture; '
                           'do not assume the Linux CPU governor records the Windows plan.')
    data = json.loads(documented.read_text())
    if not isinstance(data, dict):
        raise ValueError(f'{documented}: manual capture must be a JSON object')
    for key in ('active_scheme', 'captured_at', 'source', 'reason'):
        if not isinstance(data.get(key), str) or not data[key].strip():
            raise ValueError(f'{documented}: manual capture requires nonempty {key!r}')
    match = GUID.search(data['active_scheme'])
    if not match:
        raise ValueError(f'{documented}: active_scheme must contain the real Windows plan GUID')
    return {'status': 'documented-manual-capture', 'document': str(documented.resolve()),
            'document_sha256': hashlib.sha256(documented.read_bytes()).hexdigest(),
            'scheme_guid': match.group(0).lower(), 'query_failure': failure, 'capture': data,
            'read_at': utc_now()}


def cpu_model() -> str:
    path = Path('/proc/cpuinfo')
    if path.exists():
        for line in path.read_text().splitlines():
            if line.startswith('model name'):
                return line.partition(':')[2].strip()
    return platform.processor()


class Worker:
    def __init__(self, name: str, binary: Path, mode: str, log: Path, timeout: float):
        self.name = name
        self.timeout = timeout
        self.log = log.open('w')
        self.process = subprocess.Popen([str(binary), '--worker-' + mode, str(CORPUS)],
                                        cwd=ROOT, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                        stderr=self.log, text=True, bufsize=1)
        self.selector = selectors.DefaultSelector()
        self.selector.register(self.process.stdout, selectors.EVENT_READ)
        try:
            line = self.read_line()
            if line != f'ready {COUNT}':
                raise RuntimeError(f'{name}: expected ready {COUNT}, got {line!r}; see {log}')
        except BaseException:
            self.close()
            raise

    def read_line(self) -> str:
        if not self.selector.select(self.timeout):
            raise TimeoutError(f'{self.name}: worker timed out after {self.timeout}s')
        line = self.process.stdout.readline()
        if not line:
            raise RuntimeError(f'{self.name}: worker exited unexpectedly (status {self.process.poll()})')
        return line.rstrip('\n')

    def run(self) -> tuple[int, int]:
        self.process.stdin.write('run\n')
        self.process.stdin.flush()
        fields = self.read_line().split()
        if len(fields) != 2 or not all(x.isdecimal() for x in fields):
            raise RuntimeError(f'{self.name}: malformed timing response {fields!r}')
        ns, positions = map(int, fields)
        if ns <= 0 or not 0 <= positions <= COUNT:
            raise RuntimeError(f'{self.name}: invalid elapsed time or position count')
        return ns, positions

    def close(self) -> None:
        try:
            if self.process.poll() is None:
                try:
                    self.process.stdin.write('quit\n')
                    self.process.stdin.flush()
                    self.process.wait(timeout=5)
                except (BrokenPipeError, subprocess.TimeoutExpired):
                    self.process.kill()
                    self.process.wait()
        finally:
            self.selector.close()
            for pipe in (self.process.stdin, self.process.stdout):
                if pipe:
                    pipe.close()
            self.log.close()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--mode', choices=['decode', 'cpr'], default='decode')
    parser.add_argument('--lean-worker', type=Path, default=ROOT / '.lake/build/bin/lean1090-bench')
    parser.add_argument('--output', type=Path, required=True, help='New directory for all samples and metadata')
    parser.add_argument('--cpu', type=int, default=None)
    parser.add_argument('--windows-power-plan-file', type=Path,
                        help='JSON manual Windows capture: active_scheme, captured_at, source, reason')
    parser.add_argument('--worker-timeout', type=float, default=300)
    args = parser.parse_args()
    lean = args.lean_worker.resolve()
    if not lean.is_file() or not os.access(lean, os.X_OK):
        parser.error(f'Lean benchmark worker is absent or not executable: {lean}. '
                     'Implement the worker timing Impl.decode before claiming comparative results.')
    if args.output.exists():
        parser.error('--output must be a new directory; existing evidence is never overwritten')
    if args.worker_timeout <= 0:
        parser.error('--worker-timeout must be positive')
    data = CORPUS.read_bytes()
    if hashlib.sha256(data).hexdigest() != CORPUS_SHA256 or len(data.splitlines()) != COUNT:
        raise RuntimeError('pinned corpus hash/count mismatch')
    subprocess.run([str(ROOT / 'bench/run_oracle.sh'), '--build-only'], cwd=ROOT, check=True)
    oracle = ROOT / '.cache/rs1090-target/dist/lean1090-oracle-bench'
    allowed = sorted(os.sched_getaffinity(0)) if hasattr(os, 'sched_getaffinity') else None
    cpu = args.cpu
    if allowed is not None:
        if cpu is None:
            cpu = int(os.environ.get('BENCH_CPU', allowed[0]))
        if cpu not in allowed:
            parser.error(f'CPU{cpu} not in allowed set {allowed}')
        os.sched_setaffinity(0, {cpu})
    elif cpu is not None:
        parser.error('explicit CPU affinity is unavailable on this OS')
    before = windows_power_plan(args.windows_power_plan_file)
    args.output.mkdir(parents=True)
    metadata = {
        'started_at': utc_now(), 'mode': args.mode,
        'workload': 'Impl.decode including projection; oracle Message::from_bytes',
        'messages': COUNT, 'corpus': str(CORPUS), 'corpus_sha256': CORPUS_SHA256,
        'ordering': 'ABAB; A=rs1090, B=lean1090; 3 warmup pairs then 21 measured pairs',
        'cpu': cpu, 'affinity': [cpu] if allowed is not None else 'unavailable',
        'allowed_cpus_before_pinning': allowed, 'cpu_model': cpu_model(),
        'platform': platform.platform(), 'uname': list(platform.uname()), 'wsl': is_wsl(),
        'windows_power_plan_before': before,
        'oracle_binary': str(oracle), 'oracle_binary_sha256': hashlib.sha256(oracle.read_bytes()).hexdigest(),
        'lean_binary': str(lean), 'lean_binary_sha256': hashlib.sha256(lean.read_bytes()).hexdigest(),
        'lean_version': command_output(['lean', '--version']),
        'rust_version': command_output(['rustc', '--version']),
        'oracle_commit': command_output(['git', '-C', 'vendor/rs1090', 'rev-parse', 'HEAD']),
        'status': 'in-progress',
    }
    metadata_path = args.output / 'metadata.json'
    metadata_path.write_text(json.dumps(metadata, indent=2) + '\n')
    workers = []
    samples = {'rs1090': [], 'lean1090': []}
    position_counts = {'rs1090': set(), 'lean1090': set()}
    try:
        for name, binary in [('rs1090', oracle), ('lean1090', lean)]:
            workers.append(Worker(name, binary, args.mode, args.output / (name + '.stderr.log'), args.worker_timeout))
        with (args.output / 'samples.csv').open('w', newline='') as stream:
            writer = csv.writer(stream)
            writer.writerow(['phase', 'pair', 'order', 'implementation', 'messages',
                             'nanoseconds', 'messages_per_second', 'positions', 'recorded_at'])
            order = 0
            for phase, count in [('warmup', WARMUPS), ('measured', RUNS)]:
                for pair in range(1, count + 1):
                    for worker in workers:
                        ns, positions = worker.run()
                        order += 1
                        writer.writerow([phase, pair, order, worker.name, COUNT, ns,
                                         COUNT * 1e9 / ns, positions, utc_now()])
                        stream.flush()
                        position_counts[worker.name].add(positions)
                        if phase == 'measured':
                            samples[worker.name].append(ns)
                    print(f'{phase} pair {pair}/{count} complete', file=sys.stderr, flush=True)
        after = windows_power_plan(args.windows_power_plan_file)
        metadata['windows_power_plan_after'] = after
        if before.get('scheme_guid') != after.get('scheme_guid'):
            raise RuntimeError('Windows active power plan changed between runs; result invalid')
        if any(len(counts) != 1 for counts in position_counts.values()):
            raise RuntimeError('resolved-position count changed between runs; result invalid')
        if args.mode == 'decode' and any(counts != {0} for counts in position_counts.values()):
            raise RuntimeError('decode-only worker reported resolved positions; workload mismatch')
        medians = {name: statistics.median(times) for name, times in samples.items()}
        metadata['medians_nanoseconds'] = medians
        metadata['messages_per_second'] = {name: COUNT * 1e9 / ns for name, ns in medians.items()}
        metadata['lean_over_rust'] = medians['rs1090'] / medians['lean1090']
        metadata['resolved_positions'] = {name: next(iter(counts)) for name, counts in position_counts.items()}
        metadata['status'] = 'complete'
        print(json.dumps({'mode': args.mode, 'messages_per_second': metadata['messages_per_second'],
                          'lean_over_rust': metadata['lean_over_rust'], 'evidence': str(args.output)}, indent=2))
        return 0
    except BaseException as exc:
        metadata['status'] = 'invalid'
        metadata['error'] = f'{type(exc).__name__}: {exc}'
        raise
    finally:
        for worker in reversed(workers):
            worker.close()
        metadata['finished_at'] = utc_now()
        metadata_path.write_text(json.dumps(metadata, indent=2) + '\n')


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as exc:
        print(f'benchmark failed: {exc}', file=sys.stderr)
        raise SystemExit(1)
