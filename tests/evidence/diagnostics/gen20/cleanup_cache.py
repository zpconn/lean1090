#!/usr/bin/env python3
"""Remove only reviewed, hash-bound gen20 diagnostic cache duplicates.

Run after independent review and with all diagnostic producers stopped. Raw
perf.data and every unbound cache file remain. No other cache root is allowed.
"""
import sys
sys.dont_write_bytecode = True
import argparse
from datetime import datetime, timezone
import gzip
import hashlib
import json
import os
from pathlib import Path
import stat

ROOT = Path.cwd().resolve()
E = ROOT / 'tests/evidence/diagnostics/gen20'
C = ROOT / '.cache/gen20-costs'


def sha(path, compressed=False):
    h, size = hashlib.sha256(), 0
    with (gzip.open(path, 'rb') if compressed else path.open('rb')) as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(chunk)
            size += len(chunk)
    return h.hexdigest(), size


def identity(path):
    assert path.resolve() == path and not path.is_symlink(), path
    s = path.lstat()
    assert stat.S_ISREG(s.st_mode) and s.st_nlink == 1, path
    return [s.st_dev, s.st_ino, s.st_size, s.st_mtime_ns, s.st_ctime_ns, s.st_blocks]


def durable(path, record):
    with path.open('x') as stream:
        json.dump(record, stream, indent=2)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--apply', action='store_true')
    parser.add_argument('--quiescent', action='store_true')
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    assert not args.apply or args.quiescent, 'caller must confirm all producers stopped'
    output = (ROOT / args.output).absolute()
    assert output.parent == E and not output.exists()
    review_path, manifest_path = E / 'independent-review/independent-review.json', E / 'archive-manifest.json'
    review, manifest = [json.loads(p.read_text()) for p in (review_path, manifest_path)]
    assert review['status'] == 'passed'
    assert review['manifest_sha256'] == sha(manifest_path)[0]
    assert json.loads((E / 'validation.json').read_text())['status'] == 'passed'
    assert C.resolve() == C and C.is_dir()
    selected, seen = [], set()
    for name, binding in manifest['files'].items():
        source = (ROOT / binding['source']).absolute()
        if not source.is_relative_to(C):
            continue
        target = E / name
        assert source not in seen and target.resolve() == target
        seen.add(source)
        assert sha(target) == (binding['stored_sha256'], binding['stored_bytes'])
        expected = (binding['source_sha256'], binding['source_bytes'])
        assert sha(target, compressed=binding['encoding'] != 'identity') == expected
        assert sha(source) == expected
        # Settle delayed allocation before recording identities; no file bytes
        # are changed. Strict identity checks remain exact until unlink.
        if args.apply:
            with target.open('rb') as stream:
                os.fsync(stream.fileno())
        selected.append({'source': str(source.relative_to(ROOT)), 'sha256': expected[0],
                         'bytes': expected[1], 'identity': identity(source),
                         'archive': str(target.relative_to(ROOT)), 'archive_identity': identity(target),
                         'classification': 'byte_exact_retained_duplicate'})
    for name, binding in manifest['omitted_binaries'].items():
        source = (ROOT / name).absolute()
        if source.name not in ('decode-costs', 'DecodeCosts.c.o', 'driver-symbols.log'):
            continue
        assert source.is_relative_to(C / 'driver') and source not in seen
        seen.add(source)
        assert sha(source) == (binding['sha256'], binding['bytes'])
        selected.append({'source': str(source.relative_to(ROOT)), 'sha256': binding['sha256'],
                         'bytes': binding['bytes'], 'identity': identity(source),
                         'classification': 'explicitly_bound_rebuildable_diagnostic_artifact'})
    raw = C / 'perf-gen20/perf.data'
    capture = json.loads((E / 'perf/capture.json').read_text())
    assert sha(raw) == (capture['raw_data']['sha256'], capture['raw_data']['bytes'])
    preserved = capture['preserved_binary']
    worker_copy = ROOT / preserved['path']
    assert worker_copy == C / 'perf-gen20/lean1090-bench' and worker_copy not in seen
    assert sha(worker_copy)[0] == preserved['sha256'] == capture['before_hashes']['.lake/build/bin/lean1090-bench']
    assert sha(ROOT / '.lake/build/bin/lean1090-bench')[0] == preserved['sha256']
    seen.add(worker_copy)
    selected.append({'source': str(worker_copy.relative_to(ROOT)), 'sha256': preserved['sha256'],
                     'bytes': worker_copy.stat().st_size, 'identity': identity(worker_copy),
                     'classification': 'bound_duplicate_timed_worker_copy',
                     'capture_sha256': sha(E / 'perf/capture.json')[0]})
    kept = [str(p.relative_to(ROOT)) for p in sorted(C.rglob('*')) if p.is_file() and p not in seen]
    if args.apply:
        directories = set()
        for row in selected:
            if 'archive' not in row:
                continue
            parent = (ROOT / row['archive']).parent
            while parent.is_relative_to(ROOT):
                directories.add(parent)
                if parent == ROOT:
                    break
                parent = parent.parent
        for parent in sorted(directories, key=lambda p: len(p.parts), reverse=True):
            fd = os.open(parent, os.O_RDONLY | os.O_DIRECTORY)
            try:
                os.fsync(fd)
            finally:
                os.close(fd)
    record = {'status': 'verified_before_unlink' if args.apply else 'verified_dry_run',
              'time': datetime.now(timezone.utc).isoformat(), 'selected': selected, 'kept': kept,
              'archive_manifest_sha256': sha(manifest_path)[0], 'independent_review_sha256': sha(review_path)[0],
              'raw_perf_retained': str(raw.relative_to(ROOT)), 'raw_perf_sha256': sha(raw)[0],
              'allocated_bytes': sum(row['identity'][5] * 512 for row in selected),
              'notes': ['Only explicit manifest source duplicates, three diagnostic build artifact names and the capture-bound timed worker copy are eligible.',
                        'No recursive directory removal. All unique/unbound files, including original raw perf, remain.',
                        'The independent review records the pre-cleanup state; this receipt explicitly accounts for later cache omissions.']}
    pre = output.with_name(output.stem + '-before.json') if args.apply else output
    durable(pre, record)
    if not args.apply:
        print(json.dumps({'status': record['status'], 'files': len(selected)}))
        return
    # Recheck the entire set before the first deletion. If any input changed,
    # keep all files; a later external race also fails before the affected file.
    for row in selected:
        assert identity(ROOT / row['source']) == row['identity']
        if 'archive' in row:
            assert identity(ROOT / row['archive']) == row['archive_identity']
    for row in selected:
        path = ROOT / row['source']
        assert identity(path) == row['identity']
        if 'archive' in row:
            assert identity(ROOT / row['archive']) == row['archive_identity']
        path.unlink()
    for parent in {Path(ROOT / row['source']).parent for row in selected}:
        fd = os.open(parent, os.O_RDONLY | os.O_DIRECTORY)
        try:
            os.fsync(fd)
        finally:
            os.close(fd)
    assert sha(raw) == (capture['raw_data']['sha256'], capture['raw_data']['bytes'])
    record.update(status='completed', completed_utc=datetime.now(timezone.utc).isoformat(),
                  all_selected_absent=all(not (ROOT / row['source']).exists() for row in selected))
    durable(output, record)
    print(json.dumps({'status': 'completed', 'files': len(selected), 'allocated_bytes': record['allocated_bytes'],
                      'receipt_sha256': sha(output)[0]}))


if __name__ == '__main__':
    main()
