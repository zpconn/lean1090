#!/usr/bin/env python3
"""Read-only consistency audit after verified temporary-file cleanup."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
import os
from pathlib import Path
import stat

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[4]


def sha(path):
    result = hashlib.sha256()
    with path.open('rb') as stream:
        while chunk := stream.read(4 * 1024 * 1024):
            result.update(chunk)
    return result.hexdigest()


def load(name):
    return json.loads((HERE / name).read_text())


def sig(st):
    return dict(device=st.st_dev, inode=st.st_ino, mode=st.st_mode,
                bytes=st.st_size, mtime_ns=st.st_mtime_ns, ctime_ns=st.st_ctime_ns,
                nlink=st.st_nlink, allocated_bytes=st.st_blocks * 512)


plan = load('plan.json')
result = load('result.json')
index = load('archive-index.json')
assert plan['root'] == str(ROOT)
assert sha(HERE / 'cleanup_message_temporaries.py') == plan['script_sha256']
assert sha(HERE / 'archive-index.json') == plan['archive_index_sha256']
assert result['plan_sha256'] == sha(HERE / 'plan.json')
assert result['excluded_active'] == '.cache/message-differential-0gzplfih'
active = ROOT / result['excluded_active']
assert active.is_dir() and not active.is_symlink()
assert result['optimization_remains_paused'] is True
assert not (HERE / 'execution.stderr').read_bytes()
planned = {item['path']: item for item in plan['candidates']}
deleted = {item['directory']: item for item in result['deleted_directories']}
retained = {item['directory']: item for item in result['retained_directories']}
assert not set(deleted) & set(retained)
assert set(deleted) | set(retained) == set(planned)
assert result['excluded_active'] not in planned
assert len(deleted) == len(result['deleted_directories'])
assert len(retained) == len(result['retained_directories'])
archive_checks = {}
total = 0
for directory, completion in deleted.items():
    raw_path = ROOT / directory
    assert not raw_path.exists()
    verified_path = HERE / 'directories' / (raw_path.name + '.verified.json')
    verified = json.loads(verified_path.read_text())
    assert sha(verified_path) == completion['verification_sha256']
    assert load('directories/' + raw_path.name + '.deleted.json') == completion
    expected = planned[directory]['files']
    assert {item['name'] for item in verified['files']} == set(expected)
    assert len(verified['files']) == len(expected)
    assert verified['all_regular_files_have_exact_retained_gzip'] is True
    for item in verified['files']:
        assert item['raw_signature'] == expected[item['name']]
        kept = item['retained']
        assert kept['raw_sha256'] == item['raw_sha256']
        assert kept['raw_bytes'] == expected[item['name']]['bytes']
        assert kept['gzip_read_to_eof'] is True
        archive = ROOT / kept['archive']
        assert not kept['archive'].startswith('tests/evidence/message-differential/')
        assert sig(archive.lstat()) == kept['signature']
        assert stat.S_ISREG(archive.lstat().st_mode)
        persisted = json.loads((ROOT / kept['verification_record']).read_text())
        assert {k: v for k, v in kept.items() if k != 'verification_record'} == persisted
        assert any(entry['name'] == item['name'] and entry['bytes'] == kept['raw_bytes']
                   and entry['sha256'] == kept['raw_sha256']
                   and entry['archive'] == kept['archive']
                   and entry['compressed_sha256'] == kept['compressed_sha256']
                   for entry in index['entries'])
        archive_checks[kept['archive']] = kept
    subtotal = sum(item['allocated_bytes'] for item in expected.values())
    assert subtotal == verified['allocated_bytes'] == completion['reclaimed_allocated_bytes']
    total += subtotal
for directory, record in retained.items():
    path = ROOT / directory
    assert path.is_dir() and not path.is_symlink()
    expected = planned[directory]['files']
    assert {item.name for item in path.iterdir()} == set(expected)
    assert all(sig((path / name).lstat()) == value for name, value in expected.items())
assert total == result['reclaimed_allocated_bytes']
for name, item in archive_checks.items():
    assert sha(ROOT / name) == item['compressed_sha256']
    assert sha(ROOT / item['summary']) == item['summary_sha256']
    assert sig((ROOT / name).lstat()) == item['signature']
print(json.dumps(dict(status='passed', deleted_directories=len(deleted),
                      retained_unchanged_directories=len(retained),
                      retained_gzip_archives_rehashed=len(archive_checks),
                      reclaimed_allocated_bytes=total,
                      reclaimed_GiB=total / 2**30,
                      active_directory_untouched_by_cleanup=True,
                      result_sha256=sha(HERE / 'result.json'),
                      checker_sha256=sha(Path(__file__).resolve())), indent=2))
