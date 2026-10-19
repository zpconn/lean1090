#!/usr/bin/env python3
"""Verify explicit completed scratch sets against sealed generation archives.

Default is a dry run. --apply requires --quiescent: the caller must first stop
all producers touching the selected scratch/archive trees. This program does
not inspect processes or infer quiescence. Explicitly protect active, paused,
interrupted or otherwise valuable scratch. Unknown files keep the entire set.
Only gzip-backed raw temporary files are supported; never a recursive delete.
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
import re
import stat

ROOT = Path(__file__).resolve().parents[2]
SCRATCH = re.compile(r'(message-differential|altitude-exhaustive|reserved-velocity|dte-exhaustive|cpr-synthetic)-(?!proposal$|baseline$|snapshot$|retained$)[a-z0-9_]{8}')
BLOCK = 4 * 1024 * 1024


def require(ok, message):
    if not ok:
        raise ValueError(message)


def local(value):
    path = Path(value)
    path = path if path.is_absolute() else ROOT / path
    require('..' not in path.parts and path.is_relative_to(ROOT) and path != ROOT,
            f'path is not a strict repository descendant: {path}')
    require(path.resolve() == path, f'symlink or alias in path: {path}')
    return path


def overlaps(a, b):
    return a == b or a.is_relative_to(b) or b.is_relative_to(a)


def relative(path):
    return str(path.relative_to(ROOT))


def identity(path):
    local(path)
    s = path.lstat()
    require(stat.S_ISREG(s.st_mode), f'not a regular file: {path}')
    return dict(device=s.st_dev, inode=s.st_ino, bytes=s.st_size,
                mtime_ns=s.st_mtime_ns, ctime_ns=s.st_ctime_ns,
                links=s.st_nlink, allocated_bytes=s.st_blocks * 512)


def digest(path):
    before = identity(path)
    h = hashlib.sha256()
    fd = os.open(path, os.O_RDONLY | os.O_NOFOLLOW)
    with os.fdopen(fd, 'rb') as stream:
        require(os.fstat(stream.fileno()).st_ino == before['inode'], 'inode changed at open')
        for chunk in iter(lambda: stream.read(BLOCK), b''):
            h.update(chunk)
    require(identity(path) == before, f'file changed during hashing: {path}')
    return h.hexdigest(), before


def durable(path, data):
    with path.open('x') as stream:
        json.dump(data, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    sync_dir(path.parent)


def sync_dir(path):
    fd = os.open(path, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def mkdir_durable(path):
    """Durably link each newly created receipt ancestor before any unlink."""
    missing = []
    parent = path
    while not parent.exists():
        missing.append(parent)
        parent = parent.parent
    for item in reversed(missing):
        item.mkdir()
        sync_dir(item.parent)


def read_bound(path, expected=None):
    actual, before = digest(path)
    require(expected is None or actual == expected, f'retained SHA mismatch: {path}')
    value = json.loads(path.read_text())
    require(identity(path) == before, f'JSON changed while reading: {path}')
    return value, actual, before


def seal_for(root):
    """Accept only named immutable per-generation archives with a passed seal."""
    parts = root.relative_to(ROOT).parts
    if (len(parts) in (3, 4) and parts[0] == '.cache'
            and re.fullmatch(r'gen[1-9][0-9]*-gate', parts[1])):
        generation = parts[1][3:-5]
        component = 'message' if parts[2:] == ('fixed-message-archive',) else None
        if len(parts) == 4 and parts[2] == 'component-archives':
            component = parts[3] if parts[3] in ('altitude', 'reserved_velocity', 'dte', 'cpr') else None
        require(component is not None, 'not a supported complete component archive')
        seal = ROOT / f'tests/evidence/optimization/gen{generation}/gate-archive.json'
        document, sha, signature = read_bound(seal)
        require(document.get('status') == 'passed', 'gate archive is not sealed/pass')
        rows = document['components'][component]['retained_files']
        expected = {row['path']: row for row in rows.values()}
    elif (len(parts) in (5, 6) and parts[:3] == ('tests', 'evidence', 'optimization')
          and re.fullmatch(r'gen[1-9][0-9]*', parts[3])
          and parts[4:] in (('fresh-message',), ('fresh', 'fresh-message'))):
        seal = root.parent / 'fresh-retained-hashes.json'
        document, sha, signature = read_bound(seal)
        require(document.get('status') == 'passed', 'fresh archive is not sealed/pass')
        expected = {name: row for name, row in document['files'].items()
                    if Path(name).parent == Path(relative(root))}
    else:
        raise ValueError(f'mutable, broad or unsupported archive root: {root}')
    actual = {relative(path): identity(path) for path in root.iterdir()}
    require(set(actual) == set(expected) and actual, 'archive membership differs from its seal')
    for name, row in expected.items():
        require((ROOT / name).parent == root, 'seal member is not a direct archive child')
        require(actual[name]['bytes'] == row['bytes'], f'archive size differs: {name}')
    return dict(path=relative(seal), sha256=sha, identity=signature), expected


def archive_index(roots):
    result = {}
    seals = []
    for root in roots:
        seal, members = seal_for(root)
        summary = root / 'summary.json'
        data, summary_sha, summary_id = read_bound(summary, members[relative(summary)]['sha256'])
        seals.append(seal)
        for name, raw in data.get('artifacts', {}).items():
            require(Path(name).name == name, 'artifact name has a path component')
            archive = root / (name + '.gz')
            if relative(archive) not in members:
                continue
            require(isinstance(raw['bytes'], int) and raw['bytes'] >= 0
                    and re.fullmatch('[0-9a-f]{64}', raw['sha256']), 'invalid raw metadata')
            compressed_sha = members[relative(archive)]['sha256']
            require(raw.get('compressed_sha256', compressed_sha) == compressed_sha,
                    'summary and seal disagree on compressed SHA')
            entry = dict(path=relative(archive), compressed_sha256=compressed_sha,
                         identity=identity(archive), summary=relative(summary),
                         summary_sha256=summary_sha, summary_identity=summary_id,
                         raw_bytes=raw['bytes'], raw_sha256=raw['sha256'], seal=seal)
            result.setdefault((name, raw['bytes'], raw['sha256']), []).append(entry)
    return result, seals


def inventory(directory):
    require(directory.is_dir() and not directory.is_symlink(), 'scratch is not a directory')
    result = {path.name: identity(path) for path in sorted(directory.iterdir())}
    require(result and all(row['links'] == 1 for row in result.values()),
            'scratch is empty or shares file inodes')
    return result


def verify_archive(entry, cache):
    path = ROOT / entry['path']
    require(identity(path) == entry['identity'], 'archive identity changed')
    require(identity(ROOT / entry['summary']) == entry['summary_identity'], 'summary changed')
    require(identity(ROOT / entry['seal']['path']) == entry['seal']['identity'], 'archive seal changed')
    key = (entry['path'], entry['compressed_sha256'], entry['raw_sha256'], entry['raw_bytes'])
    if key not in cache:
        require(digest(path)[0] == entry['compressed_sha256'], 'compressed SHA mismatch')
        h = hashlib.sha256()
        count = 0
        fd = os.open(path, os.O_RDONLY | os.O_NOFOLLOW)
        with os.fdopen(fd, 'rb') as source, gzip.GzipFile(fileobj=source) as stream:
            for chunk in iter(lambda: stream.read(BLOCK), b''):
                count += len(chunk)
                h.update(chunk)
        require(count == entry['raw_bytes'] and h.hexdigest() == entry['raw_sha256'],
                'gzip decompressed size/SHA mismatch')
        require(identity(path) == entry['identity'], 'archive changed while decompressing')
        cache.add(key)


def cleanup(scratch, archives, protected, receipt, apply=False, quiescent=False):
    require(not apply or quiescent, '--apply requires explicit --quiescent caller attestation')
    scratch = [local(p) for p in scratch]
    archives = [local(p) for p in archives]
    protected = [local(p) for p in protected]
    receipt = local(receipt)
    require(len(set(scratch)) == len(scratch) and scratch, 'duplicate/empty scratch selection')
    require(archives and len(set(archives)) == len(archives), 'duplicate/empty archive selection')
    for path in scratch:
        require(path.parent == ROOT / '.cache' and SCRATCH.fullmatch(path.name),
                f'not a generated top-level scratch directory: {path}')
    require(not receipt.exists(), 'receipt already exists; never overwrite earlier evidence')
    parts = receipt.relative_to(ROOT).parts
    require(len(parts) >= 3 and (parts[:2] == ('tests', 'evidence') or parts[0] == '.cache'),
            'receipt must be a new evidence/cache descendant')
    require(not any(overlaps(receipt, p) for p in scratch + archives + protected), 'receipt overlaps inputs')
    require(not any(overlaps(a, s) for a in archives for s in scratch), 'archive overlaps scratch')
    index, seals = archive_index(archives)
    mkdir_durable(receipt)
    durable(receipt / 'start.json', dict(mode='apply' if apply else 'dry-run',
            started_utc=datetime.now(timezone.utc).isoformat(),
            script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            scratch=[relative(p) for p in scratch], archives=[relative(p) for p in archives],
            protected=[relative(p) for p in protected], seals=seals,
            caller_attests_quiescence=quiescent,
            process_detection='Not performed; caller must stop producers and explicitly protect valuable scratch.'))
    results, verified = [], set()
    for directory in scratch:
        row = dict(directory=relative(directory), status='retained', files=[])
        if any(overlaps(directory, p) for p in protected):
            row['reason'] = 'explicit protection overlaps this directory'
        else:
            try:
                before = inventory(directory)
                for name, signature in before.items():
                    raw_sha, current = digest(directory / name)
                    require(current == signature, 'raw identity changed')
                    matches = index.get((name, signature['bytes'], raw_sha), [])
                    require(matches, f'no sealed exact counterpart for {name}')
                    # A damaged selected counterpart keeps the set; never silently weakens verification.
                    kept = matches[0]
                    verify_archive(kept, verified)
                    row['files'].append(dict(name=name, identity=signature,
                                             sha256=raw_sha, retained=kept, gzip_eof_verified=True))
                require(inventory(directory) == before, 'scratch membership/identity changed')
                row.update(status='verified', allocated_bytes=sum(x['allocated_bytes'] for x in before.values()))
                durable(receipt / (directory.name + '.verified.json'), row)
                if apply:
                    require(inventory(directory) == before, 'scratch changed after durable receipt')
                    for item in row['files']:
                        verify_archive(item['retained'], verified)
                    # No recursive deletion. Every selected name was recorded before the first unlink.
                    for name, signature in before.items():
                        require(identity(directory / name) == signature, 'raw changed immediately before unlink')
                        (directory / name).unlink()
                    directory.rmdir()
                    sync_dir(directory.parent)
                    row['status'] = 'deleted'
                else:
                    row['status'] = 'would_delete'
            except (ValueError, OSError, EOFError, KeyError) as error:
                row.update(status='retained_or_interrupted', reason=str(error))
        durable(receipt / (directory.name + '.result.json'), row)
        results.append(row)
    result = dict(status='completed', mode='apply' if apply else 'dry-run',
                  finished_utc=datetime.now(timezone.utc).isoformat(), results=results,
                  deleted_allocated_bytes=sum(r.get('allocated_bytes', 0) for r in results if r['status'] == 'deleted'),
                  verified_gzip_archives=len(verified))
    durable(receipt / 'result.json', result)
    return result


def arguments(parser):
    parser.add_argument('--scratch', required=True, action='append', type=Path)
    parser.add_argument('--archive-root', required=True, action='append', type=Path)
    protect = parser.add_mutually_exclusive_group(required=True)
    protect.add_argument('--protect', action='append', type=Path)
    protect.add_argument('--no-protected-scratch', action='store_true')
    parser.add_argument('--receipt', required=True, type=Path)
    parser.add_argument('--quiescent', action='store_true', help='Caller attests all selected producers are stopped.')
    parser.add_argument('--apply', action='store_true', help='Delete only complete verified sets; default is dry-run.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    arguments(parser)
    args = parser.parse_args()
    result = cleanup(args.scratch, args.archive_root, args.protect or [], args.receipt, args.apply, args.quiescent)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
