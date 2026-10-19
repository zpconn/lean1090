#!/usr/bin/env python3
"""Recount the existing combined build log, retaining the original metadata."""
import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
BUILD = HERE.parent
ROOT = BUILD.parents[4]
EXPECTED_MISSING = {
    'Lean1090.Proofs.CommBArithmeticFacts.field_arithmetic_bounds',
    'Lean1090.Proofs.CommBArithmeticFacts.mach_positive_lower_bound',
    'Lean1090.Proofs.CommBConstant.accepted_and_unsupported_witness',
    'Lean1090.Proofs.ScoreGateInteger.product_denominator_witness',
}
ALLOWED = {'propext', 'Classical.choice', 'Quot.sound'}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def parse(text):
    pattern = r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)"
    rows = []
    listed = 0
    for match in re.finditer(pattern, text):
        axioms = [] if match[2] is None else [a.strip() for a in match[2].split(',') if a.strip()]
        assert set(axioms) <= ALLOWED, (match[1], axioms)
        listed += match[2] is not None
        rows.append({'name': match[1], 'axioms': axioms})
    assert len({row['name'] for row in rows}) == len(rows), 'duplicate printed declaration'
    return rows, listed


def main():
    target = BUILD / 'validation.json'
    original = HERE / 'validation-before.json'
    receipt = HERE / 'correction.json'
    assert not original.exists() and not receipt.exists(), 'preserve prior recount attempts'
    before_bytes = target.read_bytes()
    before = json.loads(before_bytes)
    assert hashlib.sha256(before_bytes).hexdigest() == '8ce39e5bda3a1c8272c8199412d286a3c1e08538733a700d425b62bc5f5fed78'
    with original.open('xb') as stream:
        stream.write(before_bytes)
    # Exercise wrapped, single-line and axiom-free records, plus rejection.
    fixture, listed = parse("'a' depends on axioms: [propext,\n Classical.choice,\n Quot.sound]\n"
                            "'b' depends on axioms: []\n'c' does not depend on any axioms")
    assert listed == 2 and fixture == [
        {'name': 'a', 'axioms': ['propext', 'Classical.choice', 'Quot.sound']},
        {'name': 'b', 'axioms': []}, {'name': 'c', 'axioms': []}]
    try:
        parse("'bad' depends on axioms: [unexpected_axiom]")
    except AssertionError:
        pass
    else:
        raise AssertionError('unexpected axiom accepted')
    log = BUILD / 'targeted-build.log'
    record = BUILD / 'targeted-build.json'
    assert sha(log) == before['build_log_sha256']
    assert sha(record) == before['build_record_sha256']
    protected = [BUILD / name for name in (
        'targeted-build.log', 'targeted-build.json', 'run_production_build.py',
        'production-01/build.log', 'production-01/execution.json',
        'production-01/started.json', 'production-01.stdout', 'production-01.stderr')]
    protected += [ROOT / name for name in before['source_hashes']]
    protected += [ROOT / '.lake/build/bin' / name for name in before['binary_hashes']]
    held = {str(p.relative_to(ROOT)): sha(p) for p in protected}
    assert all(sha(ROOT / name) == digest for name, digest in before['source_hashes'].items())
    assert all(sha(ROOT / '.lake/build/bin' / name) == digest for name, digest in before['binary_hashes'].items())
    facts, lists = parse(log.read_text())
    old_facts = {row['name']: row['axioms'] for row in before['printed_axiom_facts']}
    new_facts = {row['name']: row['axioms'] for row in facts}
    assert before['printed_fact_count'] == len(old_facts) == 283
    assert all(new_facts[name] == axioms for name, axioms in old_facts.items())
    assert new_facts.keys() - old_facts.keys() == EXPECTED_MISSING
    assert len(facts) == 287 and lists == 278 and len(facts) - lists == 9
    updated = dict(before, printed_axiom_facts=facts, printed_fact_count=len(facts))
    target.write_text(json.dumps(updated, indent=2) + '\n')
    assert all(sha(ROOT / name) == digest for name, digest in held.items())
    correction = {
        'status': 'passed_existing_log_recount',
        'checked_utc': datetime.now(timezone.utc).isoformat(),
        'reason': 'Initial line-based metadata extraction omitted four wrapped axiom lists. Existing log and compiled proofs are unchanged.',
        'before_path': str(original.relative_to(ROOT)), 'before_sha256': sha(original),
        'after_path': str(target.relative_to(ROOT)), 'after_sha256': sha(target),
        'tool_sha256': sha(Path(__file__)),
        'changed_fields': ['printed_axiom_facts', 'printed_fact_count'],
        'previous_distinct_facts': 283, 'distinct_facts': len(facts),
        'axiom_list_records': lists, 'axiom_free_records': len(facts) - lists,
        'added_facts': {name: new_facts[name] for name in sorted(EXPECTED_MISSING)},
        'all_previous_facts_unchanged': True, 'all_axioms_permitted': True,
        'small_parser_fixtures_passed': True, 'unchanged_bindings': held,
        'command': ['python3', '-B', str(Path(__file__).relative_to(ROOT))],
        'no_build_or_gate_executed': True,
        'original_validator': 'The original inline metadata extraction has no standalone saved source; the original metadata and executed production runner/logs remain retained. This explicit recount is the corrected parser.',
    }
    with receipt.open('x') as stream:
        json.dump(correction, stream, indent=2)
        stream.write('\n')
    print(json.dumps({'status': correction['status'], 'validation_sha256': sha(target),
                      'correction_sha256': sha(receipt), 'distinct_facts': len(facts),
                      'axiom_lists': lists, 'axiom_free': len(facts) - lists}, indent=2))


if __name__ == '__main__':
    main()
