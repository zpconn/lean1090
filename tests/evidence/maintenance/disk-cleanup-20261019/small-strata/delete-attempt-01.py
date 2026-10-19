#!/usr/bin/env python3
"""Delete only the exact scratch copies already verified and durably recorded."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
import os
from pathlib import Path
import shutil
import stat
from verify import ROOT, OUT, FAMILIES, digest, identity, now, relative, save

def main():
    verification_path = OUT / 'verification.json'
    verification = json.loads(verification_path.read_text())
    assert verification['status'] == 'passed'
    assert not verification['retained_unmatched_directories']
    assert not (OUT / 'deletion-plan.json').exists()
    refs = verification['verified_archives']
    retained = OUT / 'retained-counterparts'
    retained.mkdir(exist_ok=False)
    durable = {}
    copies = {}
    for name, entry in refs.items():
        archive = ROOT / name
        summary = ROOT / entry['summary']
        assert digest(archive) == entry['compressed']
        assert digest(summary) == entry['summary_digest']
        if entry['requires_durable_copy']:
            # Names are content-addressed, so repeated archives/summaries are copied only once.
            for src, expected, suffix in ((archive, entry['compressed'], '.gz'),
                                          (summary, entry['summary_digest'], '.json')):
                target = retained / (expected['sha256'] + suffix)
                if not target.exists():
                    with src.open('rb') as source, target.open('xb') as dest:
                        shutil.copyfileobj(source, dest, 1024 * 1024)
                        dest.flush()
                        os.fsync(dest.fileno())
                assert digest(target) == expected
                copies[relative(target)] = {'original': relative(src), **expected}
            archive = retained / (entry['compressed']['sha256'] + '.gz')
            summary = retained / (entry['summary_digest']['sha256'] + '.json')
        else:
            assert '/component-archives/' in name and name.startswith('.cache/gen')
        assert digest(archive, compressed=True) == entry['raw']
        durable[name] = {'archive': relative(archive), 'summary': relative(summary),
                         'compressed': entry['compressed'], 'raw': entry['raw'],
                         'summary_digest': entry['summary_digest']}
    preflight = json.loads((ROOT / 'tests/evidence/optimization/gen15/fresh-preflight.json').read_text())
    protected = {name: digest(ROOT / name) for name in preflight['binary_sha256']}
    for name, h in preflight['binary_sha256'].items():
        assert protected[name]['sha256'] == h
    protected['spec.lock'] = digest(ROOT / 'spec.lock')
    active = ROOT / '.cache/message-differential-0gzplfih'
    assert active.is_dir()
    active_before = {p.name: identity(p) for p in active.iterdir()}
    states = {}
    for pid in (1126929, 1126930, 1132708):
        proc = Path('/proc') / str(pid)
        if proc.exists():
            state = (proc / 'status').read_text().split('State:', 1)[1].splitlines()[0].strip()
            assert state.startswith('T'), (pid, state)
            states[str(pid)] = {'state': state, 'process_group': os.getpgid(pid)}
    assert '1132708' in states and states['1132708']['process_group'] == 1126929
    # Rehash every raw file after the durable archive binding and before any deletion.
    for directory in verification['candidate_directories']:
        path = ROOT / directory['path']
        assert path.parent == ROOT / '.cache' and not path.is_symlink()
        assert path.name != 'reserved-velocity-proposal'
        assert {p.name for p in path.iterdir()} == FAMILIES[directory['family']]
        for file in directory['files']:
            p = path / file['name']
            assert identity(p) == file['identity'], p
            assert digest(p) == {k: file[k] for k in ('sha256', 'bytes')}, p
    plan = {
        'status': 'verified_before_deletion', 'created_utc': now(),
        'authorization': 'Parent relayed user authorization to delete complete old small-stratum temporary directories only after every file matches retained evidence; unmatched files, archives and active work are protected.',
        'verification': digest(verification_path), 'script': digest(Path(__file__).resolve()),
        'durable_counterparts': durable, 'durable_copies': copies,
        'directories': verification['candidate_directories'],
        'protected_hashes': protected, 'active_scratch': active_before,
        'suspended_processes': states,
        'rechecked_raw_file_count': verification['candidate_file_count'],
        'binding_scope': verification['binding_scope'],
    }
    save(OUT / 'deletion-plan.json', plan)
    deleted = []
    with (OUT / 'deletion-journal.jsonl').open('x') as journal:
        for directory in verification['candidate_directories']:
            path = ROOT / directory['path']
            assert {p.name for p in path.iterdir()} == {f['name'] for f in directory['files']}
            for file in directory['files']:
                p = path / file['name']
                assert identity(p) == file['identity'], p
                p.unlink()
                journal.write(json.dumps({'utc': now(), 'action': 'unlink', 'path': relative(p),
                                          'sha256': file['sha256'], 'bytes': file['bytes']}) + '\n')
                journal.flush()
            path.rmdir()
            journal.write(json.dumps({'utc': now(), 'action': 'rmdir', 'path': relative(path)}) + '\n')
            journal.flush()
            os.fsync(journal.fileno())
            deleted.append(directory['path'])
            if len(deleted) % 10 == 0:
                print('Deleted verified directories:', len(deleted), flush=True)
    for entry in durable.values():
        assert digest(ROOT / entry['archive']) == entry['compressed']
        assert digest(ROOT / entry['summary']) == entry['summary_digest']
    for name, expected in protected.items():
        assert digest(ROOT / name) == expected
    assert {p.name: identity(p) for p in active.iterdir()} == active_before
    for pid, value in states.items():
        state = (Path('/proc') / pid / 'status').read_text().split('State:', 1)[1].splitlines()[0].strip()
        assert state.startswith('T') and os.getpgid(int(pid)) == value['process_group']
    assert all(not (ROOT / d).exists() for d in deleted)
    result = {
        'status': 'passed', 'finished_utc': now(), 'deletion_plan': digest(OUT / 'deletion-plan.json'),
        'verification': digest(verification_path), 'journal': digest(OUT / 'deletion-journal.jsonl'),
        'deleted_directory_count': len(deleted), 'deleted_file_count': verification['candidate_file_count'],
        'deleted_logical_bytes': verification['candidate_logical_bytes'],
        'deleted_allocated_bytes': verification['candidate_allocated_bytes'],
        'durable_copy_bytes': sum(v['bytes'] for v in copies.values()),
        'deleted_directories': deleted, 'excluded': verification['excluded'],
        'retained_counterparts_unchanged': True, 'protected_hashes_unchanged': True,
        'active_scratch_unchanged': True, 'suspended_processes_still_stopped': True,
        'limitations': 'Allocated bytes are the sum of original st_blocks; global free-space changes also include concurrent authorized cleanup by other agents.',
    }
    save(OUT / 'deletion-result.json', result)
    print(json.dumps({k: result[k] for k in ('status', 'deleted_directory_count', 'deleted_file_count',
                                           'deleted_logical_bytes', 'deleted_allocated_bytes', 'durable_copy_bytes')}), flush=True)

if __name__ == '__main__':
    main()
