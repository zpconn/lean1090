#!/usr/bin/env python3
"""Isolated safety tests; no production fixtures, gates or decoder executions."""
import sys
sys.dont_write_bytecode = True
import gzip
import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import cleanup_verified_scratch as tool
import finish_generation_gate as wrapper


def sha(data):
    return hashlib.sha256(data).hexdigest()


def write(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)


class CleanupSafety(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix='lean1090-cleanup-safety-')
        self.root = Path(self.temp.name)
        self.patch = patch.object(tool, 'ROOT', self.root)
        self.patch.start()
        self.raw = b'complete generated transcript\n' * 4
        self.scratch = self.root / '.cache/message-differential-a1b2c3d4'
        self.archive = self.root / '.cache/gen1-gate/fixed-message-archive'
        self.receipt = self.root / 'tests/evidence/cleanup-test'
        write(self.scratch / 'input.hex', self.raw)
        write(self.archive / 'input.hex.gz', gzip.compress(self.raw, mtime=0))
        self.seal()

    def tearDown(self):
        self.patch.stop()
        self.temp.cleanup()

    def seal(self, fresh=False):
        summary = {'artifacts': {'input.hex': {'bytes': len(self.raw), 'sha256': sha(self.raw)}}}
        write(self.archive / 'summary.json', json.dumps(summary).encode())
        members = {p.name: {'path': tool.relative(p), 'bytes': p.stat().st_size,
                           'sha256': sha(p.read_bytes())} for p in self.archive.iterdir()}
        if fresh:
            data = {'status': 'passed', 'files': {v['path']: v for v in members.values()}}
            path = self.archive.parent / 'fresh-retained-hashes.json'
        else:
            component = 'message' if self.archive.name == 'fixed-message-archive' else self.archive.name
            data = {'status': 'passed', 'generation': 1,
                    'components': {component: {'retained_files': members}}}
            path = self.root / 'tests/evidence/optimization/gen1/gate-archive.json'
        write(path, json.dumps(data).encode())

    def run_cleanup(self, apply=False, protected=None, quiet=True):
        return tool.cleanup([self.scratch], [self.archive], protected or [],
                            self.receipt, apply=apply, quiescent=quiet)

    def test_dry_run_default_keeps_every_byte(self):
        result = self.run_cleanup()
        self.assertEqual(result['results'][0]['status'], 'would_delete')
        self.assertEqual((self.scratch / 'input.hex').read_bytes(), self.raw)
        self.assertEqual(result['deleted_allocated_bytes'], 0)

    def test_apply_preserves_archive_and_records_before_unlink(self):
        old = (self.archive / 'input.hex.gz').read_bytes()
        original = Path.unlink
        def guarded_unlink(path, *args, **kwargs):
            self.assertTrue((self.receipt / (self.scratch.name + '.verified.json')).exists())
            return original(path, *args, **kwargs)
        with patch.object(Path, 'unlink', guarded_unlink):
            result = self.run_cleanup(True)
        self.assertEqual(result['results'][0]['status'], 'deleted')
        self.assertFalse(self.scratch.exists())
        self.assertEqual((self.archive / 'input.hex.gz').read_bytes(), old)

    def test_mismatch_keeps_whole_set(self):
        write(self.scratch / 'input.hex', b'x' * len(self.raw))
        self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'retained_or_interrupted')
        self.assertTrue((self.scratch / 'input.hex').exists())

    def test_unknown_file_keeps_known_files_too(self):
        write(self.scratch / 'unarchived-failure.log', b'unique failure')
        result = self.run_cleanup(True)
        self.assertEqual(result['results'][0]['status'], 'retained_or_interrupted')
        self.assertEqual(len(list(self.scratch.iterdir())), 2)

    def test_truncated_gzip_with_matching_compressed_hash_is_rejected(self):
        p = self.archive / 'input.hex.gz'
        p.write_bytes(p.read_bytes()[:-5])
        self.seal()
        self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'retained_or_interrupted')
        self.assertTrue(self.scratch.exists())

    def test_symlink_member_and_nested_directory_rejected(self):
        (self.scratch / 'extra').symlink_to(self.archive / 'summary.json')
        self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'retained_or_interrupted')
        self.assertTrue((self.archive / 'summary.json').exists())

    def test_symlink_ancestor_rejected(self):
        alias = self.root / 'alias'
        alias.symlink_to(self.root / '.cache', target_is_directory=True)
        with self.assertRaises(ValueError):
            tool.cleanup([alias / self.scratch.name], [self.archive], [], self.receipt, True, True)

    def test_protected_exact_parent_and_child(self):
        for i, path in enumerate((self.scratch, self.scratch.parent, self.scratch / 'input.hex')):
            self.receipt = self.root / f'tests/evidence/protected-{i}'
            self.assertEqual(self.run_cleanup(True, [path])['results'][0]['status'], 'retained')
            self.assertTrue((self.scratch / 'input.hex').exists())

    def test_mutable_archive_and_broad_scratch_rejected(self):
        for path in (self.root / 'tests/evidence/message-differential', self.root / '.cache/gen1-gate'):
            with self.assertRaises(ValueError):
                tool.cleanup([self.scratch], [path], [], self.receipt, True, True)
        for path in (self.root / '.cache', self.scratch / 'child', self.root / '.cache/message-differential-proposal'):
            with self.assertRaises(ValueError):
                tool.cleanup([path], [self.archive], [], self.receipt, True, True)

    def test_apply_requires_quiescence(self):
        with self.assertRaises(ValueError):
            self.run_cleanup(True, quiet=False)
        self.assertTrue(self.scratch.exists())

    def test_change_after_durable_verification_prevents_unlink(self):
        original = tool.durable
        def change(path, data):
            original(path, data)
            if path.name.endswith('.verified.json'):
                write(self.scratch / 'input.hex', b'changed')
        with patch.object(tool, 'durable', change):
            self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'retained_or_interrupted')
        self.assertTrue((self.scratch / 'input.hex').exists())

    def test_archive_change_after_verification_prevents_unlink(self):
        original = tool.durable
        def change(path, data):
            original(path, data)
            if path.name.endswith('.verified.json'):
                write(self.archive / 'input.hex.gz', b'changed')
        with patch.object(tool, 'durable', change):
            self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'retained_or_interrupted')
        self.assertTrue(self.scratch.exists())

    def test_fresh_archive_requires_passed_seal(self):
        self.archive = self.root / 'tests/evidence/optimization/gen1/fresh-message'
        write(self.archive / 'input.hex.gz', gzip.compress(self.raw, mtime=0))
        self.seal(fresh=True)
        self.assertEqual(self.run_cleanup()['results'][0]['status'], 'would_delete')

    def test_all_supported_small_strata_without_compressed_summary_hash(self):
        for i, (prefix, component) in enumerate((('altitude-exhaustive', 'altitude'),
                ('reserved-velocity', 'reserved_velocity'), ('dte-exhaustive', 'dte'), ('cpr-synthetic', 'cpr'))):
            self.scratch = self.root / f'.cache/{prefix}-a1b2c3d4'
            self.archive = self.root / f'.cache/gen1-gate/component-archives/{component}'
            self.receipt = self.root / f'tests/evidence/small-{i}'
            write(self.scratch / 'input.hex', self.raw)
            write(self.archive / 'input.hex.gz', gzip.compress(self.raw, mtime=0))
            self.seal()
            self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'deleted')

    def test_existing_receipt_never_overwritten(self):
        self.run_cleanup()
        with self.assertRaises(ValueError):
            self.run_cleanup(True)
        self.assertTrue(self.scratch.exists())

    def test_receipt_parent_links_are_synced(self):
        self.receipt = self.root / 'tests/evidence/new-parent/new-child/receipt'
        original = tool.sync_dir
        synced = []
        def record(path):
            synced.append(path)
            original(path)
        with patch.object(tool, 'sync_dir', record):
            self.run_cleanup()
        for path in (self.root / 'tests/evidence', self.receipt.parent.parent, self.receipt.parent):
            self.assertIn(path, synced)

    def test_shared_raw_inode_is_not_deleted(self):
        import os
        os.link(self.scratch / 'input.hex', self.root / 'keep-hardlink')
        self.assertEqual(self.run_cleanup(True)['results'][0]['status'], 'retained_or_interrupted')
        self.assertTrue((self.scratch / 'input.hex').exists())

    def test_failed_seal_rejected(self):
        path = self.root / 'tests/evidence/optimization/gen1/gate-archive.json'
        data = json.loads(path.read_text()); data['status'] = 'failed'
        path.write_text(json.dumps(data))
        with self.assertRaises(ValueError):
            self.run_cleanup(True)
        self.assertTrue(self.scratch.exists())

    def test_wrapper_default_archives_then_only_previews(self):
        write(self.root / 'review/diagnostics/archive_generation_gate.py', b'# fixture only\n')
        args = ['finish_generation_gate.py', '--generation', '1', '--gate-evidence', 'gate.json',
                '--gate-log', 'gate.log', '--scratch', str(self.scratch), '--archive-root', str(self.archive),
                '--no-protected-scratch', '--receipt', str(self.receipt), '--quiescent']
        with patch.object(sys, 'argv', args), patch.object(wrapper.subprocess, 'run') as run:
            run.return_value.returncode = 0
            wrapper.main()
            self.assertIn('archive_generation_gate.py', run.call_args.args[0][2])
        self.assertTrue(self.scratch.exists())
        result = json.loads((self.receipt / 'cleanup/result.json').read_text())
        self.assertEqual(result['mode'], 'dry-run')
        self.assertEqual(result['results'][0]['status'], 'would_delete')

    def test_wrapper_never_cleans_after_failed_archival(self):
        write(self.root / 'review/diagnostics/archive_generation_gate.py', b'# fixture only\n')
        args = ['finish_generation_gate.py', '--generation', '1', '--gate-evidence', 'gate.json',
                '--gate-log', 'gate.log', '--scratch', str(self.scratch), '--archive-root', str(self.archive),
                '--no-protected-scratch', '--receipt', str(self.receipt), '--quiescent', '--apply']
        with patch.object(sys, 'argv', args), patch.object(wrapper.subprocess, 'run') as run:
            run.return_value.returncode = 1
            with self.assertRaises(ValueError):
                wrapper.main()
        self.assertTrue(self.scratch.exists())
        self.assertFalse((self.receipt / 'cleanup').exists())

    def wrapper_args(self):
        write(self.root / 'review/diagnostics/archive_generation_gate.py', b'# fixture only\n')
        return ['finish_generation_gate.py', '--generation', '1', '--gate-evidence', 'gate.json',
                '--gate-log', 'gate.log', '--scratch', str(self.scratch), '--archive-root', str(self.archive),
                '--no-protected-scratch', '--receipt', str(self.receipt), '--quiescent']

    def test_archive_files_and_directory_links_synced_before_inventory(self):
        events = []
        original_file, original_dir, original_index = wrapper.sync_file, tool.sync_dir, tool.archive_index
        original_bytes = {p: p.read_bytes() for p in self.archive.iterdir()}
        def file(path):
            original_file(path); events.append(('file', path))
        def directory(path):
            original_dir(path); events.append(('directory', path))
        def index(roots):
            last_file = max(i for i, item in enumerate(events) if item[0] == 'file')
            for path in original_bytes:
                self.assertIn(('file', path), events)
                self.assertTrue(any(i > last_file and e == ('directory', path.parent)
                                    for i, e in enumerate(events)))
            self.assertIn(('directory', self.root), events[last_file + 1:])
            self.assertTrue((self.receipt / 'archive-flush.json').exists())
            events.append(('inventory', None))
            return original_index(roots)
        with patch.object(sys, 'argv', self.wrapper_args()), patch.object(wrapper.subprocess, 'run') as run, \
                patch.object(wrapper, 'sync_file', file), patch.object(tool, 'sync_dir', directory), \
                patch.object(tool, 'archive_index', index):
            run.return_value.returncode = 0
            wrapper.main()
        self.assertEqual({p: p.read_bytes() for p in original_bytes}, original_bytes)
        self.assertEqual(sum(e[0] == 'inventory' for e in events), 1)

    def check_sync_failure(self, target):
        import os
        original_sync = os.fsync
        inode = target.stat().st_ino
        def fail(fd):
            if os.fstat(fd).st_ino == inode:
                raise OSError('injected archive fsync failure')
            original_sync(fd)
        with patch.object(sys, 'argv', self.wrapper_args()), patch.object(wrapper.subprocess, 'run') as run, \
                patch.object(os, 'fsync', fail), patch.object(tool, 'cleanup') as cleanup:
            run.return_value.returncode = 0
            with self.assertRaisesRegex(OSError, 'injected archive fsync failure'):
                wrapper.main()
            cleanup.assert_not_called()
        self.assertTrue((self.scratch / 'input.hex').exists())

    def test_archive_file_fsync_failure_prevents_cleanup(self):
        self.check_sync_failure(self.archive / 'input.hex.gz')

    def test_archive_directory_fsync_failure_prevents_cleanup(self):
        self.check_sync_failure(self.archive)


if __name__ == '__main__':
    unittest.main()
