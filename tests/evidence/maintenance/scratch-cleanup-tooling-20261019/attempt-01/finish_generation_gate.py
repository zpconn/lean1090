#!/usr/bin/env python3
"""Archive a completed full gate, then preview (or explicitly apply) cleanup.

The existing archive_generation_gate.py is invoked unchanged. Even default
dry-run mode creates the immutable gate archive and receipt; --apply controls
scratch deletion only. Use cleanup_verified_scratch.py directly for a gate
already archived. No build, test, benchmark or process signalling is performed.
"""
import sys
sys.dont_write_bytecode = True
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import cleanup_verified_scratch as clean


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--generation', required=True, type=int)
    parser.add_argument('--gate-evidence', required=True, type=Path)
    parser.add_argument('--gate-log', required=True, type=Path)
    clean.arguments(parser)
    args = parser.parse_args()
    clean.require(args.generation > 0 and args.quiescent,
                  'positive generation and explicit --quiescent are required before archival')
    receipt = clean.local(args.receipt)
    clean.require(not receipt.exists(), 'receipt already exists')
    clean.require(receipt.is_relative_to(clean.ROOT / 'tests/evidence'), 'wrapper receipt must be evidence')
    inputs = [clean.local(p) for p in args.scratch + args.archive_root + (args.protect or [])]
    clean.require(not any(clean.overlaps(receipt, p) for p in inputs), 'receipt overlaps selected inputs')
    for path in args.scratch:
        path = clean.local(path)
        clean.require(path.parent == clean.ROOT / '.cache' and clean.SCRATCH.fullmatch(path.name),
                      'not an approved temporary directory')
    generation_cache = clean.ROOT / f'.cache/gen{args.generation}-gate'
    fresh = clean.ROOT / f'tests/evidence/optimization/gen{args.generation}/fresh-message'
    for path in args.archive_root:
        path = clean.local(path)
        clean.require(path.is_relative_to(generation_cache) or path == fresh,
                      'wrapper accepts only the current generation archive/fresh roots')
    helper = clean.ROOT / 'review/diagnostics/archive_generation_gate.py'
    helper_sha = clean.digest(helper)[0]
    command = [sys.executable, '-B', str(helper), '--generation', str(args.generation),
               '--gate-evidence', str(clean.local(args.gate_evidence)),
               '--gate-log', str(clean.local(args.gate_log))]
    clean.mkdir_durable(receipt)
    clean.durable(receipt / 'start.json', dict(command=command, archive_helper_sha256=helper_sha,
                  wrapper_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                  cleanup_helper_sha256=clean.digest(Path(clean.__file__).resolve())[0],
                  cleanup_mode='apply' if args.apply else 'dry-run', caller_attests_quiescence=True))
    env = dict(os.environ, PYTHONDONTWRITEBYTECODE='1')
    with (receipt / 'archive.stdout').open('x') as out, (receipt / 'archive.stderr').open('x') as err:
        completed = subprocess.run(command, cwd=clean.ROOT, env=env, stdout=out, stderr=err)
        out.flush(); os.fsync(out.fileno())
        err.flush(); os.fsync(err.fileno())
    record = dict(archive_exit_code=completed.returncode,
                  archive_helper_unchanged=clean.digest(helper)[0] == helper_sha,
                  archive_stdout_sha256=clean.digest(receipt / 'archive.stdout')[0],
                  archive_stderr_sha256=clean.digest(receipt / 'archive.stderr')[0])
    clean.durable(receipt / 'archive-result.json', record)
    clean.require(completed.returncode == 0 and record['archive_helper_unchanged'],
                  'archival failed or helper changed; cleanup was not invoked')
    manifest = clean.ROOT / f'tests/evidence/optimization/gen{args.generation}/gate-archive.json'
    data, digest, _ = clean.read_bound(manifest)
    clean.require(data.get('status') == 'passed' and data.get('generation') == args.generation,
                  'archive result lacks passed generation seal')
    result = clean.cleanup(args.scratch, args.archive_root, args.protect or [],
                           receipt / 'cleanup', args.apply, args.quiescent)
    clean.durable(receipt / 'result.json', dict(status='completed', gate_archive_sha256=digest,
                  cleanup_result_sha256=clean.digest(receipt / 'cleanup/result.json')[0],
                  deleted_allocated_bytes=result['deleted_allocated_bytes']))
    print(json.dumps({'status': 'completed', 'receipt': clean.relative(receipt),
                      'cleanup_mode': result['mode'],
                      'deleted_allocated_bytes': result['deleted_allocated_bytes']}))


if __name__ == '__main__':
    main()
