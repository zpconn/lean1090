#!/usr/bin/env python3
"""Retain an append-only combined production/proof build attempt."""
import sys
sys.dont_write_bytecode = True
import argparse
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import time

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
SOURCES = ['Impl/Frame.lean', 'Impl/Message.lean', 'Proofs/FrameWord.lean',
           'Proofs/RawSyndromeSpec.lean', 'Proofs/SyndromeReuse.lean', 'Proofs/Decoder.lean']
COMMAND = ['lake', 'build', 'Proofs.Decoder', 'Proofs.CPRTracking', 'lean1090',
           'messageGenerator', 'commbDifferential', 'lean1090-bench']
BINARIES = ('lean1090', 'messageGenerator', 'commbDifferential', 'lean1090-bench')


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def save(path, value):
    with path.open('x') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


def utc():
    return datetime.now(timezone.utc).isoformat()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--attempt', required=True)
    args = parser.parse_args()
    assert re.fullmatch(r'production-\d{2}', args.attempt), args.attempt
    assert not (OUT / 'targeted-build.json').exists()
    assert not (OUT / 'targeted-build.log').exists()
    spec = importlib.util.spec_from_file_location('gen22_build_inventory',
        ROOT / 'review/diagnostics/run_generation_benchmark.py')
    inventory = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(inventory)
    before = inventory.gate_input_hashes()
    assert len(before) == 197, len(before)
    assert set(SOURCES) <= set(before), set(SOURCES) - set(before)
    attempt = OUT / args.attempt
    attempt.mkdir()
    for name in SOURCES:
        target = attempt / 'sources' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        with target.open('xb') as stream:
            stream.write((ROOT / name).read_bytes())
    record = {'command': COMMAND, 'attempt': args.attempt, 'started_utc': utc(),
        'started_monotonic_ns': time.monotonic_ns(),
        'inputs_before': {name: before[name] for name in SOURCES},
        'all_inputs_before': before, 'gate_input_count': len(before),
        'runner_sha256': sha(Path(__file__)),
        'inventory_tool_sha256': sha(ROOT / 'review/diagnostics/run_generation_benchmark.py')}
    save(attempt / 'started.json', record)
    with (attempt / 'build.log').open('x') as log:
        result = subprocess.run(COMMAND, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
    after = inventory.gate_input_hashes()
    record.update(exit_code=result.returncode, finished_utc=utc(),
        finished_monotonic_ns=time.monotonic_ns(),
        inputs_after={name: sha(ROOT / name) for name in SOURCES},
        all_inputs_after=after, log_sha256=sha(attempt / 'build.log'),
        binary_hashes={name: sha(ROOT / '.lake/build/bin' / name) for name in BINARIES
                       if (ROOT / '.lake/build/bin' / name).is_file()},
        attempt_started_sha256=sha(attempt / 'started.json'))
    record['status'] = 'passed' if (result.returncode == 0 and before == after
        and record['inputs_before'] == record['inputs_after']
        and set(record['binary_hashes']) == set(BINARIES)) else 'failed'
    save(attempt / 'execution.json', record)
    if record['status'] == 'passed':
        with (OUT / 'targeted-build.log').open('xb') as stream:
            stream.write((attempt / 'build.log').read_bytes())
        save(OUT / 'targeted-build.json', record)
    print(json.dumps({key: record[key] for key in
        ('status', 'attempt', 'exit_code', 'gate_input_count', 'log_sha256')}), flush=True)
    raise SystemExit(0 if record['status'] == 'passed' else 1)


if __name__ == '__main__':
    main()
