#!/usr/bin/env python3
"""Archive an already completed full gate before another differential run.

Never runs a gate, build, test, or benchmark. Correctness inputs must still
match both snapshots of a passed full-gate record. The complete fixed-message
directory and all six other component directories are independently copied to
new ignored cache directories. Small summaries/logs/coverage and full archive
manifests are also retained under versioned publication evidence. Originals are
never changed. Invoke only after the gate has exited and before another suite
can overwrite its generic evidence directories.
"""
from __future__ import annotations

import argparse
import ast
import csv
from datetime import datetime, timezone
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import sys

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]
EXPECTED_COMPONENTS = ('altitude', 'reserved_velocity', 'dte', 'numeric', 'cpr', 'tracking', 'message')
SMALL_EVIDENCE = {'summary.json', 'commands.log', 'commands.json', 'coverage.csv',
                  'coverage-catalog.json', 'generation.json', 'targeted-witnesses.json',
                  'differences.json', 'exact-differences.json', 'contract-failures.json',
                  'mismatches.jsonl'}


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def digest(path):
    value = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            value.update(block)
    return value.hexdigest()


def relative(path):
    return str(path.relative_to(ROOT))


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


def provenance_helper():
    path = ROOT / 'review/diagnostics/run_generation_benchmark.py'
    spec = importlib.util.spec_from_file_location('generation_gate_provenance', path)
    require(spec is not None and spec.loader is not None, 'cannot load existing provenance helper')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def literal_path(node):
    """Evaluate only the path-literal subset used by the frozen checkers."""
    if isinstance(node, ast.Constant) and isinstance(node.value, str):
        return Path(node.value)
    if isinstance(node, ast.Name) and node.id == 'ROOT':
        return ROOT
    if isinstance(node, ast.BinOp) and isinstance(node.op, ast.Div):
        return literal_path(node.left) / literal_path(node.right)
    if (isinstance(node, ast.Call) and isinstance(node.func, ast.Name)
            and node.func.id == 'Path' and len(node.args) == 1 and not node.keywords):
        return literal_path(node.args[0])
    raise ValueError('unsupported nonliteral path expression')


def checker_output(script):
    tree = ast.parse(script.read_text(), filename=str(script))
    defaults = []
    for node in ast.walk(tree):
        if (isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute)
                and node.func.attr == 'add_argument' and any(
                    isinstance(arg, ast.Constant) and arg.value == '--output' for arg in node.args)):
            defaults += [literal_path(item.value) for item in node.keywords if item.arg == 'default']
    if not defaults:
        # check_numeric.py has one fixed `out = ROOT / ...` assignment.
        for node in ast.walk(tree):
            if isinstance(node, ast.Assign) and any(
                    isinstance(target, ast.Name) and target.id == 'out' for target in node.targets):
                try:
                    defaults.append(literal_path(node.value))
                except ValueError:
                    pass
    require(len(defaults) == 1, f'expected exactly one literal output path in {script}')
    path = Path(defaults[0])
    if not path.is_absolute():
        path = ROOT / path
    require(path.resolve().is_relative_to(ROOT / 'tests/evidence'), 'component evidence escaped repository')
    require(path.resolve() == path, 'component output path uses a symlink or alias')
    return path


def discover_components():
    runner = ROOT / 'scripts/run_differential.sh'
    text = runner.read_text()
    found = []
    for line in text.splitlines():
        if line.startswith('run_component '):
            argv = shlex.split(line)
            require(len(argv) >= 4 and argv[2] == 'python3', 'unexpected frozen component command')
            require('--output' not in argv, 'runner overrides default output; review discovery')
            script = ROOT / argv[3]
            found.append((argv[1], script, checker_output(script), argv))
    require(tuple(row[0] for row in found) == EXPECTED_COMPONENTS, 'integrated component membership/order changed')
    match = re.search(r'^status_file=([^\s]+)$', text, re.MULTILINE)
    require(match is not None, 'missing frozen component status path')
    status_path = ROOT / match.group(1)
    return runner, found, status_path


def inventory(directory):
    require(directory.is_dir() and not directory.is_symlink(), f'missing or symlinked evidence directory: {directory}')
    result = {}
    for path in sorted(directory.rglob('*')):
        require(not path.is_symlink(), f'symlinked evidence member: {path}')
        if path.is_dir():
            continue
        require(path.is_file(), f'unsupported evidence member: {path}')
        result[str(path.relative_to(directory))] = {
            'path': relative(path), 'sha256': digest(path), 'bytes': path.stat().st_size}
    require('summary.json' in result, f'component lacks summary: {directory}')
    return result


def copy_checked(source, destination, expected):
    require(not destination.exists(), f'refusing to overwrite retained evidence: {destination}')
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(source, destination)
    require(destination.stat().st_size == expected['bytes'] and digest(destination) == expected['sha256'],
            f'copied evidence differs: {destination}')
    return {'path': relative(destination), 'sha256': expected['sha256'], 'bytes': expected['bytes']}


def check_summary(name, summary, inputs):
    if name not in ('cpr', 'tracking'):
        require(summary.get('status') == 'PASS', f'{name} summary did not pass')
    if name == 'cpr':
        counts = summary.get('counts', {})
        require(summary.get('contract_failures') == 0 and counts.get('unclassified', 0) == 0
                and counts.get('unclassified_exact_difference', 0) == 0, 'CPR summary contains failures')
        require(summary.get('random_positions') == 65536, 'expected full CPR stratum')
    if name == 'tracking':
        require(summary.get('mismatches') == 0, 'tracking summary contains mismatches')
    if name == 'message':
        require(summary.get('generated_messages') == 10000000, 'fixed message archive is not the full 10M run')
        require(not summary['message']['coverage_errors'], 'fixed message coverage has gaps')
    sources = summary.get('source_sha256')
    require(isinstance(sources, dict) and 'spec.lock' in sources, f'{name} lacks source provenance')
    for path, expected in sources.items():
        require(digest(ROOT / path) == expected, f'{name} source provenance differs: {path}')
        if path in inputs:
            require(inputs[path] == expected, f'{name} differs from full-gate inputs: {path}')


def bind_printed_summary(name, summary, gate_text, printed_objects):
    """Use the frozen checkers' printed outputs, without relying on timestamps.

    In particular this rejects a later fresh-seed message run that overwrote
    the generic output directory while leaving correctness inputs unchanged.
    """
    if name == 'numeric':
        line = f"Numerical presentation: {summary['exact_comparisons']:,} exact pinned-libm comparisons passed."
        require(line in gate_text.splitlines(), 'numeric completion count is absent from the full gate log')
        return 'exact completion line; exhaustive deterministic domain and source hashes'
    if name == 'cpr':
        expected = summary
    elif name == 'tracking':
        omitted = {'per_stream_branch_counts', 'generation', 'source_sha256', 'label_catalog'}
        expected = {key: value for key, value in summary.items() if key not in omitted}
    else:
        expected = {key: value for key, value in summary.items() if key not in {'artifacts', 'source_sha256'}}
    require(any(value == expected for value in printed_objects),
            f'{name} summary does not match its emitted full-gate JSON; generic evidence may have been overwritten')
    return 'exact parsed emitted summary in the verified full gate log'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--gate-evidence', required=True, type=Path)
    parser.add_argument('--gate-log', required=True, type=Path)
    args = parser.parse_args()
    evidence_path = (ROOT / args.gate_evidence).resolve()
    log_path = (ROOT / args.gate_log).resolve()
    require(evidence_path.is_relative_to(ROOT) and log_path.is_relative_to(ROOT), 'gate evidence must be local')
    helper = provenance_helper()
    gate_bytes = evidence_path.read_bytes()
    gate = json.loads(gate_bytes)
    log_hash = digest(log_path)
    inputs = helper.gate_input_hashes()
    verification = helper.verify_gate_evidence(gate, log_hash, inputs)
    runner, components, status_path = discover_components()
    status_bytes = status_path.read_bytes()
    rows = list(csv.DictReader(io.StringIO(status_bytes.decode()), delimiter='\t'))
    require([row['component'] for row in rows] == list(EXPECTED_COMPONENTS)
            and all(row['exit_code'] == '0' for row in rows), 'not all seven integrated components passed')
    gate_text = log_path.read_text()
    require('Complete differential campaign passed all mandatory strata.' in gate_text,
            'full gate log lacks completed integrated campaign')
    printed_objects = []
    decoder = json.JSONDecoder()
    for match in re.finditer(r'^\{', gate_text, re.MULTILINE):
        try:
            value, _ = decoder.raw_decode(gate_text, match.start())
        except ValueError:
            continue
        if isinstance(value, dict):
            printed_objects.append(value)

    destination = ROOT / 'tests/evidence/publication'
    fixed = destination / 'fixed-message'
    component_dest = destination / 'components'
    cache = ROOT / '.cache/publication-gate/fixed-message-archive'
    component_cache = ROOT / '.cache/publication-gate/component-archives'
    manifest_path = destination / 'gate-archive.json'
    for path in (fixed, component_dest, cache, component_cache, manifest_path, destination / 'components.tsv'):
        require(not path.exists(), f'archive destination already exists: {path}')
    for path in (cache, component_cache):
        ignored = subprocess.run(['git', 'check-ignore', '-q', str(path)], cwd=ROOT)
        require(ignored.returncode == 0, 'complete component archives must be ignored')
    snapshots, summaries, log_bindings = {}, {}, {}
    for name, script, directory, argv in components:
        snapshots[name] = inventory(directory)
        summaries[name] = json.loads((directory / 'summary.json').read_text())
        check_summary(name, summaries[name], inputs)
        log_bindings[name] = bind_printed_summary(name, summaries[name], gate_text, printed_objects)
    destination.mkdir(parents=True, exist_ok=True)
    record = {'schema': 1, 'status': 'copying', 'milestone': 'publication',
              'started_at': datetime.now(timezone.utc).isoformat(),
              'gate_verification': verification, 'gate_evidence': relative(evidence_path),
              'gate_evidence_sha256': hashlib.sha256(gate_bytes).hexdigest(),
              'gate_log': relative(log_path), 'gate_log_sha256': log_hash,
              'helper_sha256': digest(Path(__file__)),
              'provenance_helper_sha256': digest(ROOT / 'review/diagnostics/run_generation_benchmark.py'),
              'runner_sha256': digest(runner), 'components': {},
              'raw_retention_note': 'Every file in all seven component trees is independently copied into a new publication cache archive. Copies are verified by SHA-256 and size; existing archives are never overwritten. Versioned small evidence and manifests identify every retained path. Originals remain unchanged.'}
    write_json(manifest_path, record)
    try:
        for name, script, directory, argv in components:
            original = snapshots[name]
            retained = {}
            metadata = {}
            if name == 'message':
                for member, entry in original.items():
                    retained[member] = copy_checked(directory / member, cache / member, entry)
                for member in ('summary.json', 'commands.log', 'coverage.csv'):
                    require(member in original, f'missing fixed-message metadata: {member}')
                    metadata[member] = copy_checked(directory / member, fixed / member, original[member])
                write_json(fixed / 'retained-archive.json', retained)
            else:
                for member, entry in original.items():
                    retained[member] = copy_checked(directory / member, component_cache / name / member, entry)
                    if member in SMALL_EVIDENCE:
                        require(entry['bytes'] <= 8 * 1024 * 1024, f'unexpectedly large metadata: {member}')
                        metadata[member] = copy_checked(directory / member, component_dest / name / member, entry)
                write_json(component_dest / name / 'original-artifacts.json', original)
                write_json(component_dest / name / 'retained-archive.json', retained)
            record['components'][name] = {
                'script': relative(script), 'script_sha256': digest(script),
                'runner_command_tokens': argv, 'source_directory': relative(directory),
                'original_files': original, 'retained_files': retained,
                'versioned_metadata': metadata,
                'full_gate_log_binding': log_bindings[name],
                'command_evidence': [v['path'] for k, v in metadata.items() if k in ('commands.log', 'commands.json')],
                'complete_gate_log': relative(log_path)}
            write_json(manifest_path, record)
        copy_checked(status_path, destination / 'components.tsv', {
            'sha256': hashlib.sha256(status_bytes).hexdigest(), 'bytes': len(status_bytes)})
        for name, _, directory, _ in components:
            require(inventory(directory) == snapshots[name], f'{name} evidence changed during retention')
        require(evidence_path.read_bytes() == gate_bytes and digest(log_path) == log_hash,
                'gate evidence/log changed during retention')
        require(status_path.read_bytes() == status_bytes, 'component results changed during retention')
        require(helper.gate_input_hashes() == inputs, 'correctness inputs changed during retention')
        record.update(status='passed', finished_at=datetime.now(timezone.utc).isoformat(),
                      originals_unchanged=True, correctness_inputs_unchanged=True,
                      copied_fixed_message_files=len(snapshots['message']))
        write_json(manifest_path, record)
    except BaseException as error:
        record.update(status='failed', error=repr(error), finished_at=datetime.now(timezone.utc).isoformat())
        write_json(manifest_path, record)
        raise
    print(json.dumps({'status': 'passed', 'manifest': relative(manifest_path),
                      'fixed_message_archive': relative(cache),
                      'other_component_archives': relative(component_cache), 'components': len(components)}))


if __name__ == '__main__':
    main()
