#!/usr/bin/env python3
"""Bind a later diagnostic checkout to unchanged, historically timed sources.

This does not run code, build artifacts, restore Git objects or change refs. It
keeps the original benchmark and attribution records unchanged.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
from run_generation_benchmark import gate_input_hashes


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def git_bytes(*args):
    return subprocess.check_output(['git', *args])


def git_oid(raw):
    return hashlib.sha1(b'commit ' + str(len(raw)).encode() + b'\0' + raw).hexdigest()


def inspect(build_path, benchmark_path, history_path, correctness_path):
    build, benchmark = map(read, (build_path, benchmark_path))
    assert build['status'] == 'passed'
    assert benchmark['status'] == 'complete'
    current, original = build['commit'], benchmark['commit']
    assert git_bytes('rev-parse', 'HEAD').decode().strip() == current
    if history_path is None:
        # Later result/documentation commits need no attribution rewrite. Bind
        # the actual timed commit and still require ancestry and every audited
        # Lean source, native set, lock and worker hash below.
        before = git_bytes('cat-file', 'commit', original)
        assert git_oid(before) == original
        row = {'new': original, 'tree': before.split(b'\n', 1)[0].removeprefix(b'tree ').decode()}
    else:
        history = read(history_path)
        assert history['status'] == 'passed'
        rows = [row for row in history['commits'] if row['old'] == original]
        assert len(rows) == 1
        row = rows[0]
        before, after = row['raw_commit'].encode(), row['raw_commit_after'].encode()
        assert git_oid(before) == original and git_oid(after) == row['new']
        assert git_bytes('cat-file', 'commit', row['new']) == after
        assert before.split(b'\n', 1)[0] == after.split(b'\n', 1)[0] == b'tree ' + row['tree'].encode()
        assert before.split(b'\n\n', 1)[1] == after.split(b'\n\n', 1)[1]
        mapping = {entry['old']: entry['new'] for entry in history['commits']}
        assert len(mapping) == len(history['commits']) == len(set(mapping.values()))
        identity = (history['identity']['name'] + ' <' + history['identity']['email'] + '> ').encode()
        expected_headers = []
        for line in before.split(b'\n\n', 1)[0].splitlines():
            if line.startswith(b'parent '):
                line = b'parent ' + mapping[line[7:].decode()].encode()
            elif line.startswith((b'author ', b'committer ')):
                line = line.split(b' ', 1)[0] + b' ' + identity + line.rsplit(b'> ', 1)[1]
            expected_headers.append(line)
        assert b'\n'.join(expected_headers) == after.split(b'\n\n', 1)[0]
    # The mapped commit is an ancestor, not an arbitrary substitute checkout.
    subprocess.run(['git', 'merge-base', '--is-ancestor', row['new'], current], check=True)
    assert Path(correctness_path).resolve() == (Path(benchmark_path).parent / 'correctness-inputs.json').resolve()
    inputs = read(correctness_path)
    # All audited Lean code is bound, including proofs and frozen test adapters.
    expected = {name: digest for name, digest in inputs.items() if name.endswith('.lean')}
    current_audited = {name: digest for name, digest in gate_input_hashes().items()
                       if name.endswith('.lean')}
    assert current_audited == expected, 'current complete audited Lean inventory differs from the timed inventory'
    assert expected and set(build['linked_project_inventory']['sources']) <= set(expected)
    for name, digest in expected.items():
        assert hashlib.sha256(git_bytes('cat-file', 'blob', row['new'] + ':' + name)).hexdigest() == digest, name
        assert hashlib.sha256(git_bytes('cat-file', 'blob', current + ':' + name)).hexdigest() == digest, name
        assert sha(name) == digest, name
    for name, digest in build['linked_project_inventory']['sources'].items():
        assert expected[name] == digest, name
    assert build['lock_sha256'] == benchmark['spec_lock_sha256'] == sha('spec.lock')
    assert sha('.lake/build/bin/lean1090-bench') == benchmark['binary_sha256']
    return {
        'kind': ('unchanged_timed_sources_after_attribution_and_documentation_commits' if history_path is not None
                 else 'unchanged_timed_sources_after_documentation_commits'),
        'status': 'passed', 'diagnostic_commit': current, 'timed_original_commit': original,
        'timed_mapped_commit': row['new'], 'timed_tree': row['tree'],
        'build_manifest': str(build_path), 'build_manifest_sha256': sha(build_path),
        'benchmark': str(benchmark_path), 'benchmark_sha256': sha(benchmark_path),
        'history': str(history_path) if history_path is not None else None,
        'history_sha256': sha(history_path) if history_path is not None else None,
        'correctness_inputs': str(correctness_path), 'correctness_inputs_sha256': sha(correctness_path),
        'all_audited_lean_sources': expected,
        'linked_project_sources': build['linked_project_inventory']['sources'],
        'fresh_native_inputs_sha256': build['fresh_benchmark_native_binding']['sha256'],
        'binary_sha256': benchmark['binary_sha256'], 'spec_lock_sha256': sha('spec.lock'),
        'limits': 'This establishes identical audited Lean source blobs and exact original native inventory/binary association. It records a new diagnostic on unchanged code; it does not claim a new benchmark or rewrite historical commit IDs.'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'benchmark', 'correctness-inputs', 'output'):
        parser.add_argument('--' + name, required=True, type=Path)
    parser.add_argument('--history', type=Path,
                        help='attribution mapping only when the original timed commit was rewritten')
    args = parser.parse_args()
    record = inspect(args.build, args.benchmark, args.history, args.correctness_inputs)
    assert not args.output.exists(), 'preserve existing binding'
    args.output.write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'audited_lean_sources': len(record['all_audited_lean_sources']),
                      'binding_sha256': sha(args.output)}))


if __name__ == '__main__':
    main()
