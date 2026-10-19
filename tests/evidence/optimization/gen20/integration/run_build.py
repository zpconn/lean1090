import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import time

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
SOURCES = [
    'Impl/Parity.lean', 'Proofs/ParityByteBits.lean', 'Proofs/FoldBlocks.lean',
    'Proofs/ParityByte.lean', 'Proofs/ParityWord.lean',
]

COMMAND = ['lake', 'build', 'Proofs.Decoder', 'Proofs.CPRTracking', 'lean1090',
           'messageGenerator', 'commbDifferential', 'lean1090-bench']

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def hashes():
    return {name: sha(ROOT / name) for name in SOURCES}

def utc():
    return datetime.now(timezone.utc).isoformat()

def main():
    spec = importlib.util.spec_from_file_location(
        'gen20_gate_inventory', ROOT / 'review/diagnostics/run_generation_benchmark.py')
    inventory = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(inventory)
    path = OUT / 'targeted-build.json'
    assert not path.exists() and not (OUT / 'targeted-build.log').exists()
    all_before = inventory.gate_input_hashes()
    assert len(all_before) == 195, len(all_before)
    assert set(SOURCES) <= set(all_before), set(SOURCES) - set(all_before)
    record = {
        'command': COMMAND, 'started_utc': utc(),
        'started_monotonic_ns': time.monotonic_ns(), 'inputs_before': hashes(),
        'all_inputs_before': all_before, 'gate_input_count': len(all_before),
        'runner_sha256': sha(Path(__file__)),
        'inventory_tool_sha256': sha(ROOT / 'review/diagnostics/run_generation_benchmark.py'),
    }
    for name in SOURCES:
        target = OUT / 'sources' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        with target.open('xb') as stream:
            stream.write((ROOT / name).read_bytes())
    with path.open('x') as stream:
        json.dump(record, stream, indent=2)
        stream.write('\n')
    with (OUT / 'targeted-build.log').open('x') as log:
        run = subprocess.run(COMMAND, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT)
    record.update(
        exit_code=run.returncode, finished_utc=utc(),
        finished_monotonic_ns=time.monotonic_ns(), inputs_after=hashes(),
        all_inputs_after=inventory.gate_input_hashes(),
        log_sha256=sha(OUT / 'targeted-build.log'),
        binary_hashes={name: sha(ROOT / '.lake/build/bin' / name)
                       for name in ('lean1090', 'messageGenerator', 'commbDifferential',
                                    'lean1090-bench')
                       if (ROOT / '.lake/build/bin' / name).is_file()},
    )
    record['status'] = 'passed' if (
        run.returncode == 0 and record['inputs_before'] == record['inputs_after']
        and record['all_inputs_before'] == record['all_inputs_after']) else 'failed'
    path.write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({key: record[key] for key in
                      ('status', 'exit_code', 'gate_input_count', 'log_sha256')}), flush=True)
    raise SystemExit(0 if record['status'] == 'passed' else 1)

if __name__ == '__main__':
    main()
