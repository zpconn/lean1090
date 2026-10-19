#!/usr/bin/env python3
"""Prepare pinned dependencies in ignored directories; never install system tools.

--check only inspects files and Git metadata. --prepare may download dependencies
and build Mathlib's cache helper, but does not build or test the project decoder.
"""
from __future__ import annotations

import argparse
import hashlib
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tomllib

ROOT = Path(__file__).resolve().parents[2]
ORACLE_URL = 'https://github.com/xoolive/rs1090.git'
ORACLE_PIN = '685dfaa34c5ab186c691bca3cfe2a22e12517d30'
CORPUS_SHA = '3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505'
AIRPORTS_SHA = '978b1f95b88769ca5b3b26d3ccc48362116191bb08740eb2c0e0e2f1d82fc760'
MANIFESTS = (
    'differential/message-oracle/Cargo.toml',
    'differential/cpr-oracle/Cargo.toml',
    'differential/tracking-oracle/Cargo.toml',
    'bench/oracle/Cargo.toml',
    'bench/bds50/Cargo.toml',
)


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def git(*args: str, directory: Path = ROOT) -> str:
    return subprocess.check_output(['git', '-C', str(directory), *args], text=True).strip()


def run(args: list[str], *, env: dict[str, str] | None = None) -> None:
    print('+ ' + ' '.join(args), flush=True)
    subprocess.run(args, cwd=ROOT, env=env, check=True)


def snapshot() -> dict[str, str]:
    """Bind existing frozen members and dependency manifests, without changing them."""
    paths = {'spec.lock', 'lean-toolchain', 'lakefile.toml', 'lake-manifest.json'}
    for line in (ROOT / 'spec.lock').read_text().splitlines():
        expected, name = line.split('  ', 1)
        if digest(ROOT / name) != expected:
            raise RuntimeError(f'frozen file differs: {name}')
        paths.add(name)
    paths.update(str(Path(p).with_name('Cargo.lock')) for p in MANIFESTS)
    return {p: digest(ROOT / p) for p in sorted(paths)}


def validate_vendor() -> None:
    vendor = ROOT / 'vendor/rs1090'
    if not vendor.is_dir():
        raise RuntimeError('vendor/rs1090 is missing; use --prepare')
    if git('rev-parse', 'HEAD', directory=vendor) != ORACLE_PIN:
        raise RuntimeError('existing vendor/rs1090 has a different commit; inspect it manually')
    if git('status', '--porcelain=v1', '--untracked-files=all', directory=vendor):
        raise RuntimeError('existing vendor/rs1090 is dirty; preserve and resolve it manually')
    for name, expected in [('long_flight.csv', CORPUS_SHA), ('airports.json', AIRPORTS_SHA)]:
        if digest(vendor / 'crates/rs1090/data' / name) != expected:
            raise RuntimeError(f'pinned oracle data differs: {name}')


def validate_lean_packages() -> int:
    import json
    manifest = json.loads((ROOT / 'lake-manifest.json').read_text())
    for package in manifest['packages']:
        checkout = ROOT / manifest['packagesDir'] / package['name']
        if not checkout.is_dir() or git('rev-parse', 'HEAD', directory=checkout) != package['rev']:
            raise RuntimeError(f"missing or wrong Lean dependency: {package['name']}; use --prepare")
    return len(manifest['packages'])


def registry_packages() -> set[tuple[str, str]]:
    packages = set()
    for manifest in MANIFESTS:
        lock = tomllib.loads((ROOT / Path(manifest).with_name('Cargo.lock')).read_text())
        for package in lock['package']:
            source = package.get('source', '')
            if source.startswith('registry+'):
                packages.add((package['name'], package['version']))
            elif source.startswith('git+'):
                raise RuntimeError('new Git Cargo dependency needs bootstrap review: ' + source)
    return packages


def validate_cargo_cache() -> int:
    registry = ROOT / '.cache/cargo/registry'
    missing = []
    packages = registry_packages()
    for name, version in sorted(packages):
        archive = list((registry / 'cache').glob(f'*/{name}-{version}.crate'))
        source = list((registry / 'src').glob(f'*/{name}-{version}/Cargo.toml'))
        if not archive and not source:
            missing.append(f'{name}@{version}')
    if missing:
        raise RuntimeError('project-local Cargo cache is incomplete; use --prepare: ' + ', '.join(missing[:8]))
    if not (registry / 'index').is_dir():
        raise RuntimeError('project-local Cargo registry index is missing; use --prepare')
    return len(packages)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument('--check', action='store_true', help='read-only pin/cache readiness inspection; no network')
    mode.add_argument('--prepare', action='store_true', help='fetch locked Lean/Rust dependencies and pinned oracle')
    parser.add_argument('--lean-only', action='store_true', help='skip Rust/oracle setup for library and CLI use')
    args = parser.parse_args()
    os.chdir(ROOT)
    required = ['git', 'lean', 'lake'] + ([] if args.lean_only else ['cargo'])
    missing = [name for name in required if shutil.which(name) is None]
    if missing:
        raise RuntimeError('install these tools first: ' + ', '.join(missing) + '; see docs/DEVELOPING.md')
    before = snapshot()
    if args.prepare:
        # Fail on an existing unrelated/dirty checkout before doing other work.
        vendor = ROOT / 'vendor/rs1090'
        if not args.lean_only and vendor.exists():
            validate_vendor()
        if not args.lean_only and not vendor.exists():
            vendor.parent.mkdir(parents=True, exist_ok=True)
            run(['git', 'clone', '--no-checkout', ORACLE_URL, str(vendor)])
            run(['git', '-C', str(vendor), 'checkout', '--detach', ORACLE_PIN])
            validate_vendor()
        # Lake honors the checked-in manifest; never run lake update here.
        run(['lake', 'exe', 'cache', 'get'],
            env={**os.environ, 'MATHLIB_CACHE_DIR': str(ROOT / '.cache/mathlib')})
        if not args.lean_only:
            (ROOT / '.cache/cargo').mkdir(parents=True, exist_ok=True)
            env = {**os.environ, 'CARGO_HOME': str(ROOT / '.cache/cargo')}
            for manifest in MANIFESTS:
                run(['cargo', 'fetch', '--locked', '--manifest-path', manifest], env=env)
    lean_count = validate_lean_packages()
    print(f'Lean dependency pins: {lean_count} checkouts match lake-manifest.json.')
    print('Required Lean toolchain: ' + (ROOT / 'lean-toolchain').read_text().strip())
    if not args.lean_only:
        validate_vendor()
        print(f'rs1090 pin and corpus/airport hashes match {ORACLE_PIN}.')
        print(f'Cargo cache: {validate_cargo_cache()} locked registry packages are present.')
    if snapshot() != before:
        raise RuntimeError('a source lock or dependency manifest changed; inspect the diff')
    print('Readiness check passed. No decoder build, proof gate or benchmark was run.')
    print('Tool names/pins and cache files were checked; compilation is verified by lake build and the gate.')
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, RuntimeError, subprocess.CalledProcessError) as error:
        print(f'bootstrap: {error}', file=sys.stderr)
        raise SystemExit(1)
