#!/usr/bin/env python3
"""Remove only complete raw temporary sets with independently verified gzip copies.

No test or optimization is run. A failed historical test is not a deletion veto:
its bytes must be preserved just as exactly as successful test evidence.
"""
import sys
sys.dont_write_bytecode = True

import argparse
import datetime
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import stat

ROOT = Path(__file__).resolve().parents[5]
HERE = Path(__file__).resolve().parent
ACTIVE = ROOT / '.cache/message-differential-0gzplfih'
HEX = re.compile(r'[0-9a-f]{64}')
BLOCK = 4 * 1024 * 1024


def utc():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def rel(path):
    return str(path.relative_to(ROOT))


def signature(st):
    return dict(device=st.st_dev, inode=st.st_ino, mode=st.st_mode,
                bytes=st.st_size, mtime_ns=st.st_mtime_ns,
                ctime_ns=st.st_ctime_ns, nlink=st.st_nlink,
                allocated_bytes=st.st_blocks * 512)


def sync_directory(path):
    fd = os.open(path, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def save_new(path, data):
    """Never replace evidence; durably write before proceeding to deletion."""
    with path.open('x') as output:
        json.dump(data, output, indent=2, sort_keys=True)
        output.write('\n')
        output.flush()
        os.fsync(output.fileno())
    sync_directory(path.parent)


def regular(path):
    st = path.lstat()
    if not stat.S_ISREG(st.st_mode):
        raise ValueError(f'not a regular file: {path}')
    # Reject symlinks in every ancestor as well as the actual file.
    for parent in path.parents:
        if parent == ROOT:
            break
        if parent.is_symlink():
            raise ValueError(f'symlink ancestor: {parent}')
    return signature(st)


def hash_file(path, expected=None):
    before = regular(path)
    if expected is not None and before != expected:
        raise ValueError(f'file changed before read: {path}')
    fd = os.open(path, os.O_RDONLY | os.O_NOFOLLOW)
    digest = hashlib.sha256()
    count = 0
    with os.fdopen(fd, 'rb') as handle:
        if signature(os.fstat(handle.fileno())) != before:
            raise ValueError(f'file changed while opening: {path}')
        while chunk := handle.read(BLOCK):
            count += len(chunk)
            digest.update(chunk)
        if signature(os.fstat(handle.fileno())) != before:
            raise ValueError(f'file changed while reading: {path}')
    if regular(path) != before or count != before['bytes']:
        raise ValueError(f'file changed after read: {path}')
    return digest.hexdigest(), before


def allowed_archive(path):
    parts = path.relative_to(ROOT).parts
    return (parts[:2] == ('tests', 'evidence') or
            (len(parts) > 2 and parts[0] == '.cache' and
             re.fullmatch(r'gen\d+-gate', parts[1]) is not None))


def inventories():
    roots = [ROOT / 'tests/evidence']
    roots.extend(sorted((ROOT / '.cache').glob('gen*-gate')))
    for root in roots:
        if root.is_symlink() or not root.is_dir():
            continue
        for base, dirs, files in os.walk(root, followlinks=False):
            dirs[:] = sorted(d for d in dirs
                             if not (Path(base) / d).is_symlink()
                             and Path(base) / d != HERE.parent)
            for name in sorted(files):
                if 'summary' in name and name.endswith('.json'):
                    yield Path(base) / name


def candidate_inventory(directory):
    if directory == ACTIVE or directory.parent != ROOT / '.cache':
        raise ValueError('active or out-of-scope directory')
    ds = directory.lstat()
    if not stat.S_ISDIR(ds.st_mode) or directory.is_symlink():
        raise ValueError('not a normal directory')
    files = {}
    for path in sorted(directory.iterdir()):
        info = regular(path)  # Any nested directory/symlink rejects whole set.
        if info['nlink'] != 1:
            raise ValueError(f'non-exclusive raw inode: {path}')
        files[path.name] = info
    if not files:
        raise ValueError('empty directory is not a complete retained raw set')
    return dict(path=rel(directory), signature=signature(ds), files=files)


def plan():
    if (HERE / 'plan.json').exists():
        raise ValueError('plan already exists')
    index, rejected, summaries = [], [], []
    for source in inventories():
        try:
            source_sha, source_sig = hash_file(source)
            document = json.loads(source.read_bytes())
            if regular(source) != source_sig:
                raise ValueError('summary changed during parse')
            if not isinstance(document, dict):
                continue
            artifacts = document.get('artifacts')
            if not isinstance(artifacts, dict):
                continue
            summaries.append(dict(path=rel(source), sha256=source_sha,
                                  signature=source_sig))
            for name, item in artifacts.items():
                if not isinstance(item, dict) or Path(name).name != name:
                    continue
                if not (isinstance(item.get('bytes'), int) and item['bytes'] >= 0
                        and HEX.fullmatch(str(item.get('sha256', '')))
                        and HEX.fullmatch(str(item.get('compressed_sha256', '')))):
                    continue
                archive = source.parent / (name + '.gz')
                if not allowed_archive(archive):
                    continue
                try:
                    archive_sig = regular(archive)
                except (ValueError, OSError):
                    continue
                index.append(dict(name=name, bytes=item['bytes'],
                                  sha256=item['sha256'],
                                  compressed_sha256=item['compressed_sha256'],
                                  archive=rel(archive), signature=archive_sig,
                                  summary=rel(source), summary_sha256=source_sha))
        except (ValueError, OSError, json.JSONDecodeError) as error:
            rejected.append(dict(path=rel(source), error=str(error)))
    candidates, skipped = [], []
    for directory in sorted((ROOT / '.cache').glob('message-differential-*')):
        if directory == ACTIVE:
            skipped.append(dict(path=rel(directory), reason='active suspended gen15 gate'))
            continue
        try:
            candidates.append(candidate_inventory(directory))
        except (ValueError, OSError) as error:
            skipped.append(dict(path=rel(directory), reason=str(error)))
    script_sha, _ = hash_file(Path(__file__).resolve())
    save_new(HERE / 'archive-index.json', dict(entries=index, summaries=summaries,
                                               unreadable_or_invalid=rejected))
    index_sha, _ = hash_file(HERE / 'archive-index.json')
    record = dict(status='planned', created_utc=utc(), root=str(ROOT),
                  script_sha256=script_sha, archive_index_sha256=index_sha,
                  excluded_active=rel(ACTIVE), candidates=candidates, skipped=skipped,
                  candidate_allocated_bytes=sum(f['allocated_bytes'] for d in candidates
                                                for f in d['files'].values()))
    save_new(HERE / 'plan.json', record)
    print(json.dumps(dict(status='planned', candidates=len(candidates),
                          index_entries=len(index), skipped=skipped,
                          candidate_allocated_bytes=record['candidate_allocated_bytes'])), flush=True)


def execute():
    if (HERE / 'execution-start.json').exists():
        raise ValueError('execution already started; inspect journal before any recovery')
    plan_path = HERE / 'plan.json'
    plan_sha, _ = hash_file(plan_path)
    specification = json.loads(plan_path.read_text())
    if specification['root'] != str(ROOT) or specification['excluded_active'] != rel(ACTIVE):
        raise ValueError('wrong root or active exclusion')
    if hash_file(Path(__file__).resolve())[0] != specification['script_sha256']:
        raise ValueError('script changed since plan')
    index_path = HERE / 'archive-index.json'
    if hash_file(index_path)[0] != specification['archive_index_sha256']:
        raise ValueError('archive index changed')
    index = json.loads(index_path.read_text())
    lookup = {}
    for entry in index['entries']:
        lookup.setdefault((entry['name'], entry['bytes'], entry['sha256']), []).append(entry)
    for entries in lookup.values():
        entries.sort(key=lambda entry: (not entry['archive'].startswith('tests/evidence/'),
                                        entry['archive']))
    (HERE / 'directories').mkdir()
    (HERE / 'archives').mkdir()
    save_new(HERE / 'execution-start.json', dict(started_utc=utc(), plan_sha256=plan_sha,
                                                optimization_remains_paused=True))
    verified = {}
    deleted = []
    retained = []

    def verify_archive(entry):
        archive = ROOT / entry['archive']
        key = entry['archive']
        if key in verified:
            previous = verified[key]
            if (regular(archive) != previous['signature'] or
                    entry['sha256'] != previous['raw_sha256'] or
                    entry['bytes'] != previous['raw_bytes'] or
                    entry['compressed_sha256'] != previous['compressed_sha256']):
                raise ValueError('cached archive identity changed')
            return previous
        if not allowed_archive(archive):
            raise ValueError('archive outside retained evidence roots')
        source = ROOT / entry['summary']
        if hash_file(source)[0] != entry['summary_sha256']:
            raise ValueError('summary changed since index')
        compressed_sha, before = hash_file(archive, entry['signature'])
        if compressed_sha != entry['compressed_sha256']:
            raise ValueError('compressed SHA mismatch')
        raw_hash = hashlib.sha256()
        raw_count = 0
        fd = os.open(archive, os.O_RDONLY | os.O_NOFOLLOW)
        with os.fdopen(fd, 'rb') as handle:
            if signature(os.fstat(handle.fileno())) != before:
                raise ValueError('archive changed while opening gzip')
            with gzip.GzipFile(fileobj=handle, mode='rb') as stream:
                while chunk := stream.read(BLOCK):
                    raw_count += len(chunk)
                    raw_hash.update(chunk)
            if signature(os.fstat(handle.fileno())) != before:
                raise ValueError('archive changed during gzip read')
        if regular(archive) != before:
            raise ValueError('archive changed after gzip read')
        if raw_count != entry['bytes'] or raw_hash.hexdigest() != entry['sha256']:
            raise ValueError('decompressed SHA or byte count mismatch')
        result = dict(archive=entry['archive'], compressed_sha256=compressed_sha,
                      raw_sha256=raw_hash.hexdigest(), raw_bytes=raw_count,
                      signature=before, gzip_read_to_eof=True,
                      summary=entry['summary'], summary_sha256=entry['summary_sha256'],
                      verified_utc=utc())
        result_path = HERE / 'archives' / (hashlib.sha256(key.encode()).hexdigest() + '.json')
        save_new(result_path, result)
        result['verification_record'] = rel(result_path)
        verified[key] = result
        return result

    for candidate in specification['candidates']:
        directory = ROOT / candidate['path']
        label = directory.name
        records = []
        print(json.dumps(dict(status='verifying', directory=rel(directory), utc=utc())), flush=True)
        try:
            if candidate_inventory(directory) != candidate:
                raise ValueError('directory changed since plan')
            for name, expected in candidate['files'].items():
                raw_sha, raw_signature = hash_file(directory / name, expected)
                matches = lookup.get((name, raw_signature['bytes'], raw_sha), [])
                errors = []
                counterpart = None
                for entry in matches:
                    try:
                        counterpart = verify_archive(entry)
                        break
                    except (ValueError, OSError, EOFError, gzip.BadGzipFile) as error:
                        errors.append(dict(archive=entry['archive'], error=str(error)))
                if counterpart is None:
                    raise ValueError(f'no verified gzip counterpart for {name}: {errors}')
                records.append(dict(name=name, raw_sha256=raw_sha,
                                    raw_signature=raw_signature, retained=counterpart))
            if candidate_inventory(directory) != candidate:
                raise ValueError('directory changed during verification')
            for record in records:
                if regular(ROOT / record['retained']['archive']) != record['retained']['signature']:
                    raise ValueError('retained archive changed before deletion')
            authorization = dict(status='verified_before_deletion', verified_utc=utc(),
                                 directory=rel(directory), plan_sha256=plan_sha,
                                 files=records, all_regular_files_have_exact_retained_gzip=True,
                                 allocated_bytes=sum(r['raw_signature']['allocated_bytes'] for r in records))
            authorization_path = HERE / 'directories' / (label + '.verified.json')
            save_new(authorization_path, authorization)
            # Recheck every name and inode after the durable authorization record.
            if candidate_inventory(directory) != candidate:
                raise ValueError('directory changed after durable verification')
            for record in records:
                (directory / record['name']).unlink()
            directory.rmdir()
            sync_directory(directory.parent)
            completion = dict(status='deleted', deleted_utc=utc(), directory=rel(directory),
                              verification_sha256=hash_file(authorization_path)[0],
                              reclaimed_allocated_bytes=authorization['allocated_bytes'])
            save_new(HERE / 'directories' / (label + '.deleted.json'), completion)
            deleted.append(completion)
            print(json.dumps(completion), flush=True)
        except (ValueError, OSError, EOFError, gzip.BadGzipFile) as error:
            # No unlink begins until all files are verified. A filesystem error during
            # deletion is exceptional and must be reported, never silently retried.
            remaining = directory.exists()
            result = dict(status='retained_or_interrupted', directory=rel(directory),
                          error=str(error), remaining=remaining, verified_files=records,
                          recorded_utc=utc())
            save_new(HERE / 'directories' / (label + '.retained.json'), result)
            retained.append(result)
            print(json.dumps(dict(status=result['status'], directory=rel(directory), error=str(error))), flush=True)
    result = dict(status='completed', completed_utc=utc(), plan_sha256=plan_sha,
                  excluded_active=rel(ACTIVE), active_directory_exists=ACTIVE.is_dir(),
                  deleted_directories=deleted, retained_directories=retained,
                  verified_archives=len(verified),
                  reclaimed_allocated_bytes=sum(item['reclaimed_allocated_bytes'] for item in deleted),
                  optimization_remains_paused=True)
    save_new(HERE / 'result.json', result)
    print(json.dumps({key: value for key, value in result.items()
                      if key not in ('deleted_directories', 'retained_directories')}), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('plan', 'execute'))
    args = parser.parse_args()
    (plan if args.action == 'plan' else execute)()
