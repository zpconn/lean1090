#!/usr/bin/env python3
"""Read-only duplicate-scratch verification; never deletes any source file."""
import sys
sys.dont_write_bytecode = True
import datetime
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import stat

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
FAMILIES = {
    'dte-exhaustive': {'lean.jsonl', 'input.hex', 'cases.json', 'direct-input.txt',
                       'oracle.jsonl', 'words.txt', 'direct-oracle.jsonl'},
    'cpr-synthetic': {'input.csv', 'lean.csv', 'oracle.csv'},
    'altitude-exhaustive': {'input.hex', 'lean.csv', 'oracle.jsonl'},
    'reserved-velocity': {'lean.jsonl', 'input.hex', 'cases.json', 'oracle.jsonl', 'words.txt'},
}

def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()

def digest(path, compressed=False):
    h = hashlib.sha256()
    size = 0
    with (gzip.open(path, 'rb') if compressed else path.open('rb')) as stream:
        while data := stream.read(1024 * 1024):
            h.update(data)
            size += len(data)
    return {'sha256': h.hexdigest(), 'bytes': size}

def relative(path):
    return str(path.relative_to(ROOT))

def identity(path):
    s = path.lstat()
    return {'device': s.st_dev, 'inode': s.st_ino, 'mode': s.st_mode,
            'bytes': s.st_size, 'mtime_ns': s.st_mtime_ns, 'ctime_ns': s.st_ctime_ns,
            'allocated_bytes': s.st_blocks * 512, 'links': s.st_nlink}

def save(path, data):
    with path.open('x') as stream:
        json.dump(data, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())

def main():
    assert ROOT.name == 'lean1090' and (ROOT / 'spec.lock').is_file(), ROOT
    assert not (OUT / 'verification.json').exists()
    started = now()
    candidates = []
    excluded = []
    for family, names in FAMILIES.items():
        for path in sorted((ROOT / '.cache').glob(family + '-*')):
            if not re.fullmatch(re.escape(family) + '-[a-z0-9_]{8}', path.name):
                excluded.append({'path': relative(path), 'reason': 'not generated temporary-directory suffix'})
                continue
            assert path.is_dir() and not path.is_symlink(), path
            entries = list(path.iterdir())
            assert {p.name for p in entries} == names, path
            assert all(stat.S_ISREG(p.lstat().st_mode) for p in entries), path
            candidates.append({'path': relative(path), 'family': family,
                               'files': [{'name': p.name, 'identity': identity(p), **digest(p)}
                                         for p in sorted(entries)]})
    # Only inventory expected, complete scratch directories; never traverse other cache trees.
    save(OUT / 'inventory.json', {'started_utc': started, 'finished_utc': now(),
                                'candidates': candidates, 'excluded': excluded})
    print('Inventoried', len(candidates), 'directories; identifying retained evidence.', flush=True)
    summaries = set((ROOT / 'tests/evidence').rglob('summary.json'))
    summaries.update((ROOT / '.cache').glob('gen*-gate/component-archives/*/summary.json'))
    summaries.update((ROOT / '.cache').glob('publication-gate/component-archives/*/summary.json'))
    # This clean-clone evidence is retained; if used it must be copied durably before deletion.
    clone_summary = ROOT / '.cache/release-checkout/tests/evidence/cpr-synthetic/summary.json'
    if clone_summary.is_file():
        summaries.add(clone_summary)
    index = {}
    for path in sorted(summaries, key=lambda p: (not str(p).startswith(str(ROOT / 'tests/evidence')), str(p))):
        try:
            data = json.loads(path.read_text())
        except (ValueError, OSError):
            continue
        for name, entry in data.get('artifacts', {}).items():
            if not isinstance(entry, dict) or not {'bytes', 'sha256'} <= entry.keys():
                continue
            archive = path.parent / (name + '.gz')
            if archive.is_file() and not archive.is_symlink():
                index.setdefault((name, entry['bytes'], entry['sha256']),
                                 {'summary': path, 'archive': archive, 'expected': entry})
    verified = {}
    matched = []
    unmatched = []
    for directory in candidates:
        missing = []
        for file in directory['files']:
            key = file['name'], file['bytes'], file['sha256']
            reference = index.get(key)
            if reference is None:
                missing.append(file['name'])
                continue
            archive_path = relative(reference['archive'])
            if archive_path not in verified:
                archive_before = digest(reference['archive'])
                actual = digest(reference['archive'], compressed=True)
                assert actual == {'bytes': key[1], 'sha256': key[2]}, archive_path
                assert digest(reference['archive']) == archive_before, archive_path
                verified[archive_path] = {
                    'archive': archive_path, 'compressed': archive_before, 'raw': actual,
                    'summary': relative(reference['summary']), 'summary_digest': digest(reference['summary']),
                    'requires_durable_copy': archive_path.startswith('.cache/release-checkout/'),
                }
            file['retained_counterpart'] = archive_path
        directory['missing_counterparts'] = missing
        (unmatched if missing else matched).append(directory)
    # Inspect only process target paths, not arguments or environment. A permission denial is explicit.
    active_references = []
    denied = 0
    prefixes = tuple(str(ROOT / d['path']) + '/' for d in candidates)
    for proc in Path('/proc').glob('[0-9]*'):
        try:
            links = [proc / 'cwd', *list((proc / 'fd').iterdir())]
        except PermissionError:
            denied += 1
            continue
        except FileNotFoundError:
            continue
        for link in links:
            try:
                target = os.readlink(link)
            except (OSError, PermissionError):
                continue
            if target.startswith(prefixes) or any(target == p[:-1] for p in prefixes):
                active_references.append({'pid': int(proc.name), 'link': str(link), 'target': target})
    assert not active_references, active_references
    for directory in candidates:
        assert {p.name for p in (ROOT / directory['path']).iterdir()} == {f['name'] for f in directory['files']}
        for file in directory['files']:
            assert identity(ROOT / directory['path'] / file['name']) == file['identity']
    result = {
        'status': 'passed', 'purpose': 'exact duplicate scratch verification; no deletions performed',
        'started_utc': started, 'finished_utc': now(), 'script': digest(Path(__file__).resolve()),
        'inventory': digest(OUT / 'inventory.json'), 'verified_archives': verified,
        'candidate_directories': matched, 'retained_unmatched_directories': unmatched, 'excluded': excluded,
        'candidate_count': len(matched), 'candidate_file_count': sum(len(d['files']) for d in matched),
        'candidate_logical_bytes': sum(f['bytes'] for d in matched for f in d['files']),
        'candidate_allocated_bytes': sum(f['identity']['allocated_bytes'] for d in matched for f in d['files']),
        'process_inspection': {'active_candidate_references': active_references, 'inaccessible_processes': denied,
                               'limitations': 'Unprivileged /proc visibility only; suspended active work uses an excluded message-differential directory.'},
        'protected': ['.cache/gen*-gate', 'tests/evidence existing files', '.cache/message-differential-0gzplfih',
                      'all native binaries', 'suspended process group 1126929'],
        'binding_scope': 'Exact content duplicates; no assertion that a chosen retained archive originated in that scratch directory.',
    }
    save(OUT / 'verification.json', result)
    print(json.dumps({k: result[k] for k in ('status', 'candidate_count', 'candidate_file_count',
                                           'candidate_logical_bytes', 'candidate_allocated_bytes')}), flush=True)
    print('Unmatched:', [d['path'] for d in unmatched], flush=True)
    print('Archives requiring durable copies:', [k for k,v in verified.items() if v['requires_durable_copy']], flush=True)

if __name__ == '__main__':
    main()
