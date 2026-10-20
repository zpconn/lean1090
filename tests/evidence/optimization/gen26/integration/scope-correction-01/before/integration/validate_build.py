#!/usr/bin/env python3
"""Validate the completed combined build without rebuilding or running a binary."""
import sys
sys.dont_write_bytecode = True
import argparse
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import traceback

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
ALLOWED = {'propext', 'Classical.choice', 'Quot.sound'}
SOURCES = {'Impl/Binary64.lean', 'Proofs/Binary64Runtime.lean'}
NEW = set()
BINARIES = {'lean1090', 'messageGenerator', 'commbDifferential', 'lean1090-bench'}


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    with path.open('x') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


def parse_axioms(text):
    # Bracket contents deliberately include newlines. Match every announcement,
    # so a truncated/malformed record cannot silently lower the printed count.
    pattern = r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)"
    rows = []
    for match in re.finditer(pattern, text):
        axioms = [] if match[2] is None else [s.strip() for s in match[2].split(',') if s.strip()]
        assert set(axioms) <= ALLOWED, (match[1], axioms)
        rows.append({'name': match[1], 'axioms': axioms})
    announcements = re.findall(r'depends on axioms:|does not depend on any axioms', text)
    assert len(rows) == len(announcements), 'unparsed or truncated printed-axiom announcement'
    assert len({row['name'] for row in rows}) == len(rows), 'duplicate printed declaration'
    return rows


def parser_controls():
    text = "'a' depends on axioms: [propext,\n Classical.choice,\n Quot.sound]\n" + \
           "'b' depends on axioms: []\n'c' does not depend on any axioms"
    assert parse_axioms(text) == [
        {'name': 'a', 'axioms': ['propext', 'Classical.choice', 'Quot.sound']},
        {'name': 'b', 'axioms': []}, {'name': 'c', 'axioms': []}]
    rejected = ["'bad' depends on axioms: [unexpected_axiom]",
                "'bad' depends on axioms: [propext,\n",
                "'a' does not depend on any axioms\n'a' does not depend on any axioms"]
    for candidate in rejected:
        try:
            parse_axioms(candidate)
        except AssertionError:
            continue
        raise AssertionError('negative parser control accepted')
    return {'multiline_empty_and_axiom_free': 'passed', 'rejected_controls': len(rejected)}


def validate():
    controls = parser_controls()
    record_path, log_path = OUT / 'targeted-build.json', OUT / 'targeted-build.log'
    record = load(record_path)
    assert record['status'] == 'passed' and record['exit_code'] == 0
    assert record['command'] == ['lake', 'build', 'Proofs.Decoder', 'Proofs.CPRTracking',
                                 'lean1090', 'messageGenerator', 'commbDifferential', 'lean1090-bench']
    assert record['log_sha256'] == sha(log_path)
    attempt = OUT / record['attempt']
    assert re.fullmatch(r'production-\d{2}', record['attempt'])
    assert (attempt / 'execution.json').read_bytes() == record_path.read_bytes()
    assert (attempt / 'build.log').read_bytes() == log_path.read_bytes()
    assert record['attempt_started_sha256'] == sha(attempt / 'started.json')
    assert record['runner_sha256'] == sha(OUT / 'run_production_build.py')
    spec = importlib.util.spec_from_file_location('gen26_validation_inventory',
        ROOT / 'review/diagnostics/run_generation_benchmark.py')
    inventory = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(inventory)
    assert record['inventory_tool_sha256'] == sha(ROOT / 'review/diagnostics/run_generation_benchmark.py')
    current = inventory.gate_input_hashes()
    assert len(current) == record['gate_input_count'] == 202
    assert current == record['all_inputs_before'] == record['all_inputs_after']
    assert set(record['inputs_before']) == set(record['inputs_after']) == SOURCES
    assert record['inputs_before'] == record['inputs_after'] == {name: current[name] for name in SOURCES}
    for name, digest in record['inputs_before'].items():
        assert sha(attempt / 'sources' / name) == digest, name
    previous = load(ROOT / 'tests/evidence/optimization/gen25/gate-evidence.json')['input_hashes_after']
    assert set(current) - set(previous) == NEW and not set(previous) - set(current)
    assert {name for name in previous if previous[name] != current[name]} == SOURCES - NEW
    assert set(record['binary_hashes']) == BINARIES
    assert {name: sha(ROOT / '.lake/build/bin' / name) for name in BINARIES} == record['binary_hashes']
    names = set(load(ROOT / 'tests/evidence/optimization/gen25/fresh-message-run.json')['source_sha256_before'])
    for directory in ('Impl', 'Model', 'Spec', 'Proofs', 'CLI', 'Tests'):
        names.update(str(path.relative_to(ROOT)) for path in (ROOT / directory).rglob('*.lean'))
    names.update(('lakefile.toml', 'lake-manifest.json', 'lean-toolchain', 'Capstones.lean'))
    assert len(names) == 127 and names <= current.keys(), (len(names), names - current.keys())
    audited = {name: current[name] for name in sorted(names)}
    log = log_path.read_text()
    assert not re.search(r'(?m)^error:|\bsorryAx\b', log)
    jobs = re.findall(r'Build completed successfully \((\d+) jobs\)\.', log)
    assert len(jobs) == 1
    facts = parse_axioms(log)
    required = {'Lean1090.Proofs.Refinement', 'Lean1090.Proofs.CPRTrackingRefinement',
                'Lean1090.Proofs.Binary64Runtime.round_eq',
                'Lean1090.Proofs.Binary64Runtime.round_function_eq',
                'Lean1090.Proofs.Binary64Runtime.roundFallback_eq',
                'Lean1090.Proofs.Binary64Runtime.round_small_dyadic'}
    assert required <= {row['name'] for row in facts}, required - {row['name'] for row in facts}
    return {'status': 'passed', 'checked_utc': datetime.now(timezone.utc).isoformat(),
            'build_record_sha256': sha(record_path), 'build_log_sha256': sha(log_path),
            'all_correctness_inputs_unchanged': len(current), 'source_hashes': record['inputs_after'],
            'binary_hashes': record['binary_hashes'], 'jobs': int(jobs[0]),
            'printed_axiom_facts': facts, 'printed_fact_count': len(facts),
            'all_printed_axioms_permitted': True, 'all_jobs_stopped': True,
            'audited_source_count': len(audited), 'audited_source_hashes': audited,
            'parser_controls': controls, 'validator_sha256': sha(Path(__file__)),
            'notes': ['The printed count is derived from the complete multiline log, including axiom-free declarations.',
                      'all_jobs_stopped refers to the completed combined production/proof build subprocess; this validator starts no build or executable.',
                      'Existing validation fields are preserved; audited-source inventory and parser controls are additional explicit bindings.']}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument('--execute-after-completed-build', action='store_true')
    mode.add_argument('--parser-controls-only', action='store_true')
    args = parser.parse_args()
    if args.parser_controls_only:
        print(json.dumps(parser_controls()))
        return
    assert not (OUT / 'validation.json').exists()
    number = 1
    while (OUT / f'validation-attempt-{number:02d}').exists():
        number += 1
    attempt = OUT / f'validation-attempt-{number:02d}'
    attempt.mkdir()
    (attempt / Path(__file__).name).write_bytes(Path(__file__).read_bytes())
    save(attempt / 'command.json', {'command': ['python3', '-B', str(Path(__file__).relative_to(ROOT)),
         '--execute-after-completed-build'], 'started_utc': datetime.now(timezone.utc).isoformat()})
    try:
        result = validate()
    except Exception as error:
        save(attempt / 'result.json', {'status': 'failed', 'error': str(error), 'traceback': traceback.format_exc()})
        raise
    save(attempt / 'result.json', result)
    save(OUT / 'validation.json', result)
    print(json.dumps({'status': 'passed', 'sha256': sha(OUT / 'validation.json'),
                     'inputs': result['all_correctness_inputs_unchanged'],
                     'sources': result['audited_source_count'], 'facts': result['printed_fact_count']}))


if __name__ == '__main__':
    main()
