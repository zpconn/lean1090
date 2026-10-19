#!/usr/bin/env python3
"""Verify a committed local clone with reused external dependencies and a fresh project build.

Only run after the packaging commit. This runs the quick gate; it does not repeat
or replace the separately recorded full fixed/fresh 10M publication campaigns.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
ORACLE_PIN = '685dfaa34c5ab186c691bca3cfe2a22e12517d30'


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for chunk in iter(lambda: stream.read(4 * 1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def utc() -> str:
    return datetime.now(timezone.utc).isoformat()


def require(value: bool, reason: str) -> None:
    if not value:
        raise RuntimeError(reason)


def git(directory: Path, *args: str) -> str:
    return subprocess.check_output(['git', '-C', str(directory), *args], text=True,
                                   env={**os.environ, 'GIT_OPTIONAL_LOCKS': '0'}).strip()


def status(directory: Path) -> dict:
    raw = subprocess.check_output(['git', '-C', str(directory), 'status', '--porcelain=v1',
                                   '--untracked-files=all'], text=True,
                                  env={**os.environ, 'GIT_OPTIONAL_LOCKS': '0'})
    return {'commit': git(directory, 'rev-parse', 'HEAD'), 'clean': raw == '', 'porcelain': raw}


def inventory(root: Path) -> dict:
    """Inventory exact copied files; reject external symlinks and Git alternates."""
    rows = {}
    require(root.is_dir() and not root.is_symlink(), f'not a real directory: {root}')
    for path in sorted(root.rglob('*')):
        relative = str(path.relative_to(root))
        if path.is_symlink():
            target = path.readlink()
            require(not target.is_absolute() and path.resolve().is_relative_to(root.resolve()),
                    f'cache symlink escapes copied directory: {path}')
            rows[relative] = {'type': 'symlink', 'target': str(target)}
        elif path.is_file():
            require(not (path.name == 'alternates' and path.parent.name == 'info'
                         and path.parent.parent.name == 'objects'), f'Git alternates escape cache: {path}')
            rows[relative] = {'type': 'file', 'bytes': path.stat().st_size, 'sha256': sha(path)}
        else:
            require(path.is_dir(), f'unsupported cache member: {path}')
            rows[relative] = {'type': 'directory'}
    return rows


def tracked_non_evidence(directory: Path) -> dict[str, str]:
    names = subprocess.check_output(['git', '-C', str(directory), 'ls-files', '-z']).split(b'\0')
    return {os.fsdecode(p): sha(directory / os.fsdecode(p)) for p in names
            if p and not os.fsdecode(p).startswith('tests/evidence/')}


def require_evidence_changes_only(directory: Path) -> None:
    changed = subprocess.check_output(
        ['git', '-C', str(directory), 'diff', 'HEAD', '--name-only', '-z']).split(b'\0')
    added = subprocess.check_output(
        ['git', '-C', str(directory), 'ls-files', '--others', '--exclude-standard', '-z']).split(b'\0')
    require(all(os.fsdecode(p).startswith('tests/evidence/') for p in changed + added if p),
            'non-evidence tracked/untracked change in ' + str(directory))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--commit', required=True, help='full packaging commit SHA')
    parser.add_argument('--checkout', type=Path, default=Path('.cache/release-checkout'))
    parser.add_argument('--output', type=Path, required=True,
                        help='new directory below tests/evidence/publication')
    args = parser.parse_args()
    os.chdir(ROOT)
    checkout = (ROOT / args.checkout).resolve()
    output = (ROOT / args.output).resolve()
    require(re.fullmatch(r'[0-9a-f]{40}', args.commit) is not None, 'full commit SHA required')
    require(checkout.is_relative_to((ROOT / '.cache').resolve()) and checkout != ROOT / '.cache',
            'checkout must be a fresh child of project .cache')
    require(output.is_relative_to((ROOT / 'tests/evidence/publication').resolve()),
            'output must be below tests/evidence/publication')
    source_caches = [('lean_packages', '.lake/packages'), ('cargo_registry', '.cache/cargo/registry')]
    for destination in (checkout, output):
        for _, relative in source_caches:
            source_cache = (ROOT / relative).resolve()
            require(not destination.is_relative_to(source_cache)
                    and not source_cache.is_relative_to(destination),
                    f'checkout/evidence path overlaps source cache: {destination}, {source_cache}')
    require(not checkout.is_relative_to(output) and not output.is_relative_to(checkout),
            'checkout and evidence output must not overlap')
    require(not checkout.exists() and not output.exists(), 'never overwrite an existing checkout or evidence')
    initial = status(ROOT)
    require(initial['clean'] and initial['commit'] == args.commit,
            'source must be the clean packaging commit before creating evidence')
    own_path = str(Path(__file__).resolve().relative_to(ROOT))
    require(subprocess.check_output(['git', '-C', str(ROOT), 'show', args.commit + ':' + own_path])
            == Path(__file__).read_bytes(), 'verification helper must match committed source')
    vendor = ROOT / 'vendor/rs1090'
    require(git(vendor, 'rev-parse', 'HEAD') == ORACLE_PIN and status(vendor)['clean'],
            'source oracle checkout must be clean and pinned')
    source_non_evidence = tracked_non_evidence(ROOT)
    output.mkdir(parents=True)
    env = {**os.environ, 'PYTHONDONTWRITEBYTECODE': '1', 'CARGO_NET_OFFLINE': 'true'}
    commands = []
    record = {'status': 'in-progress', 'started_utc': utc(), 'commit': args.commit,
              'checkout': str(checkout.relative_to(ROOT)), 'source_initial_git': initial,
              'helper_sha256': sha(Path(__file__)), 'gate_mode': '--quick',
              'generated_messages': 100000,
              'scope': 'Fresh committed project checkout and project build, reusing pinned external dependency caches only. Full fixed/fresh 10M campaigns are separate main-checkout evidence.',
              'cache_reuse': {}, 'commands': commands}

    def write(name: str, value: object) -> None:
        (output / name).write_text(json.dumps(value, indent=2) + '\n')

    def command(argv: list[str], name: str, *, cwd: Path = ROOT) -> str:
        before = time.monotonic_ns()
        row = {'argv': argv, 'cwd': str(cwd), 'started_utc': utc(), 'started_monotonic_ns': before,
               'log': str((output / name).relative_to(ROOT))}
        with (output / name).open('wb') as stream:
            result = subprocess.run(argv, cwd=cwd, env=env, stdout=stream, stderr=subprocess.STDOUT)
        row.update(exit_code=result.returncode, finished_utc=utc(), finished_monotonic_ns=time.monotonic_ns(),
                   log_sha256=sha(output / name))
        commands.append(row)
        write('commands.json', commands)
        require(result.returncode == 0, f'command failed ({result.returncode}): {argv}; see {name}')
        return (output / name).read_text()

    def source_inputs(directory: Path, name: str) -> dict[str, str]:
        text = command([sys.executable, '-B', 'review/diagnostics/run_generation_benchmark.py',
                        '--print-gate-inputs'], name, cwd=directory)
        return json.loads(text)

    try:
        source_hashes = source_inputs(ROOT, 'source-correctness-inputs.json')
        record['source_correctness_inputs'] = len(source_hashes)
        command(['git', '-c', 'core.autocrlf=false', 'clone', '--no-hardlinks', '--no-checkout',
                 str(ROOT), str(checkout)], 'clone.log')
        command(['git', '-C', str(checkout), '-c', 'core.autocrlf=false',
                 'checkout', '--detach', args.commit], 'checkout.log')
        clone_initial = status(checkout)
        require(clone_initial['clean'] and clone_initial['commit'] == args.commit, 'clone is not clean at requested commit')
        require(tracked_non_evidence(checkout) == source_non_evidence, 'clone tracked sources differ')
        record['clone_initial_git'] = clone_initial
        write('initial-git.json', {'source': initial, 'clone': clone_initial})
        # Copy only external Lean packages and Cargo registry download/source data.
        # Independent files/reflinks avoid writes through hardlinks to the original cache.
        for name, relative in source_caches:
            source = ROOT / relative
            destination = checkout / relative
            before = inventory(source)
            if name == 'lean_packages':
                manifest = json.loads((checkout / 'lake-manifest.json').read_text())
                for package in manifest['packages']:
                    package_path = source / package['name']
                    require((package_path / '.git').is_dir(), 'external Lean package needs a self-contained Git checkout')
                    require(git(package_path, 'rev-parse', 'HEAD') == package['rev'], 'Lean dependency pin differs')
                    require(not git(package_path, 'status', '--porcelain=v1', '--untracked-files=no'),
                            'external Lean dependency has tracked source changes')
            destination.parent.mkdir(parents=True, exist_ok=True)
            command(['cp', '-a', '--reflink=auto', '--', str(source), str(destination)], f'copy-{name}.log')
            require(inventory(destination) == before == inventory(source), 'cache copy changed bytes or source: ' + name)
            raw = (json.dumps(before, sort_keys=True, separators=(',', ':')) + '\n').encode()
            packed = gzip.compress(raw, mtime=0)
            manifest_path = output / f'{name}-cache-manifest.json.gz'
            manifest_path.write_bytes(packed)
            record['cache_reuse'][name] = {'source': relative, 'destination': str(destination.relative_to(ROOT)),
                'copy_mode': 'cp -a --reflink=auto; independent files or copy-on-write extents, no source hardlinks',
                'members': len(before), 'files': sum(r['type'] == 'file' for r in before.values()),
                'file_bytes': sum(r.get('bytes', 0) for r in before.values()),
                'manifest': str(manifest_path.relative_to(ROOT)), 'manifest_sha256': sha(manifest_path),
                'manifest_uncompressed_sha256': hashlib.sha256(raw).hexdigest(),
                'source_and_copy_exactly_equal_before_gate': True}
        (checkout / 'vendor').mkdir()
        command(['git', '-c', 'core.autocrlf=false', 'clone', '--no-hardlinks', '--no-checkout',
                 str(vendor), str(checkout / 'vendor/rs1090')], 'oracle-clone.log')
        command(['git', '-C', str(checkout / 'vendor/rs1090'), '-c', 'core.autocrlf=false',
                 'checkout', '--detach', ORACLE_PIN], 'oracle-checkout.log')
        require(not (checkout / '.lake/build').exists(), 'project Lean build artifacts were copied')
        require(not (checkout / '.cache/rs1090-target').exists(), 'compiled Rust oracle artifacts were copied')
        record['project_build_directory_absent_before_gate'] = True
        record['rust_target_directory_absent_before_gate'] = True
        record['oracle_initial_git'] = status(checkout / 'vendor/rs1090')
        command([sys.executable, '-B', 'review/packaging/bootstrap.py', '--check'], 'bootstrap-check.log', cwd=checkout)
        command([sys.executable, '-B', 'scripts/check_lock.py'], 'lock-before.log', cwd=checkout)
        before_gate = source_inputs(checkout, 'clone-correctness-before.json')
        require(before_gate == source_hashes, 'clone correctness inputs differ before gate')
        require(status(checkout)['clean'], 'checkout is dirty before quick gate')
        record['gate_started_utc'] = utc()
        command(['scripts/check_all.sh', '--quick'], 'quick-gate.log', cwd=checkout)
        record['gate_finished_utc'] = utc()
        command([sys.executable, '-B', 'scripts/check_lock.py'], 'lock-after.log', cwd=checkout)
        after_gate = source_inputs(checkout, 'clone-correctness-after.json')
        require(after_gate == before_gate == source_hashes, 'clone correctness inputs changed during gate')
        require(source_inputs(ROOT, 'source-correctness-after.json') == source_hashes,
                'main checkout correctness inputs changed during clone verification')
        require(tracked_non_evidence(checkout) == tracked_non_evidence(ROOT) == source_non_evidence,
                'tracked non-evidence files changed during verification')
        for name, row in record['cache_reuse'].items():
            raw = gzip.decompress((ROOT / row['manifest']).read_bytes())
            require(json.loads(raw) == inventory(ROOT / row['source']), 'original shared dependency cache changed: ' + name)
            row['original_cache_unchanged_after_gate'] = True
        final = status(checkout)
        require(final['commit'] == args.commit and git(ROOT, 'rev-parse', 'HEAD') == args.commit, 'HEAD changed')
        # Gate evidence is intentionally regenerated; source changes are forbidden.
        require_evidence_changes_only(checkout)
        require_evidence_changes_only(ROOT)
        record['clone_final_git'] = final
        record['source_final_git'] = status(ROOT)
        record['oracle_final_git'] = status(checkout / 'vendor/rs1090')
        require(record['oracle_final_git']['clean'] and record['oracle_final_git']['commit'] == ORACLE_PIN,
                'clone oracle checkout changed')
        write('final-git.json', {'source': record['source_final_git'], 'clone': final,
                                'note': 'Only generated tests/evidence outputs may differ in the clone; publication records are new in the source checkout.'})
        components = (checkout / 'tests/evidence/differential-campaign/components.tsv').read_bytes()
        (output / 'components.tsv').write_bytes(components)
        lines = components.decode().splitlines()
        expected_components = ['altitude', 'reserved_velocity', 'dte', 'numeric', 'cpr', 'tracking', 'message']
        require(lines == ['component\texit_code'] + [name + '\t0' for name in expected_components],
                'component names, order, header or successful exits differ from the frozen runner')
        record.update(status='passed', gate_exit_code=0, gate_log_sha256=sha(output / 'quick-gate.log'),
                      correctness_inputs=len(before_gate), correctness_hashes_unchanged=True,
                      all_tracked_non_evidence_files_unchanged=True,
                      generated_evidence_changes_only=True, independent_oracle_checkout=True,
                      limitations=['External Lean dependency compiled caches are reused, not built from scratch.',
                                   'Cargo registry packages are reused; project Rust targets and root Lean build were initially absent.',
                                   'This is a quick clean-clone gate. Full fixed/fresh 10M campaigns are separate evidence.',
                                   'Local cloning and cache copy are tested here; network bootstrap is recorded separately.'])
    except BaseException as error:
        record.update(status='failed', error=type(error).__name__ + ': ' + str(error))
        if checkout.is_dir() and (checkout / '.git').exists():
            record['clone_status_at_failure'] = status(checkout)
        raise
    finally:
        record['finished_utc'] = utc()
        write('summary.json', record)
    print(json.dumps({'status': record['status'], 'commit': args.commit,
                      'correctness_inputs': record['correctness_inputs'], 'summary': str(output / 'summary.json'),
                      'summary_sha256': sha(output / 'summary.json')}, indent=2))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
