#!/usr/bin/env python3
"""Independent read-only review binding for payload interpretation and bridges."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib
import json
import os
import re
import subprocess

B = Path('tests/evidence/optimization/gen19')
P = B / 'payload-proof'
OUT = B / 'independent-review/source-proof-review.json'
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())


def reverse(text, new, old, count=1):
    assert text.count(new) == count, (new, text.count(new))
    return text.replace(new, old)


def main():
    assert not OUT.exists()
    summary = load(P / 'summary.json')
    execution = load(summary['targeted_build'])
    assert summary['status'] == execution['status'] == 'passed'
    assert sha(summary['targeted_build']) == summary['targeted_build_sha256']
    log_path = Path(summary['targeted_build']).with_name('build.log')
    assert sha(log_path) == summary['log_sha256'] == execution['log_sha256']
    assert execution['exit_code'] == 0 and execution['inputs_unchanged']
    assert execution['before_hashes'] == execution['after_hashes']
    for path, digest in execution['after_hashes'].items():
        assert sha(path) == digest, path
    for path, digest in summary['sources'].items():
        assert sha(path) == digest
    facts = []
    for match in re.finditer(r"'([^']+)'\s+(depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)", log_path.read_text()):
        axioms = [a.strip() for a in (match[3] or '').split(',') if a.strip()]
        assert set(axioms) <= {'propext', 'Classical.choice', 'Quot.sound'}
        facts.append({'name': match[1], 'axioms': axioms})
    assert facts == summary['printed_facts'] and len(facts) == 214
    own = [f for f in facts if f['name'].startswith('Lean1090.Proofs.PayloadIntegerShift.')]
    assert len(own) == 9 and sum(not f['axioms'] for f in own) == 6
    for attempt in summary['attempts']:
        assert sha(attempt['path']) == attempt['sha256']
        record = load(attempt['path'])
        assert record['status'] == attempt['status']
        assert sha(Path(attempt['path']).with_name('build.log')) == record['log_sha256']
    checked = {}
    for name in ('AffineValue', 'CommBTables', 'Decoder'):
        path = Path('Proofs') / (name + '.lean')
        before = P / ('before-Proofs__' + name + '.lean')
        committed = subprocess.check_output(['git', 'show', 'HEAD:' + str(path)],
            env=dict(os.environ, GIT_OPTIONAL_LOCKS='0'))
        assert before.read_bytes() == committed
        text = path.read_text()
        if name == 'AffineValue':
            text = reverse(text, 'import Proofs.PayloadIntegerShift\n', '')
            text = reverse(text, 'PayloadIntegerShift.payloadInteger_eq]',
                           'Impl.payloadInteger, Spec.payloadInteger]')
        elif name == 'CommBTables':
            text = reverse(text, 'PayloadIntegerShift.payloadInteger_eq_old', 'payloadInteger', 4)
        else:
            text = reverse(text, 'import Proofs.BitExtraction\nimport Proofs.PayloadIntegerShift\n', '')
            for new in ('BitExtraction.bit_function_eq', 'BitExtraction.grayDecode_function_eq',
                        'BitExtraction.identityCode_function_eq', 'PayloadIntegerShift.payloadInteger_function_eq'):
                text = reverse(text, '  exact ' + new, '  rfl')
            text = reverse(text, 'simp only [decoder_Altitude_bit_eq, decoder_Altitude_decodeAC12_eq]',
                           'simp only [decoder_Altitude_decodeAC12_eq]')
        assert text.encode() == committed, name
        checked[str(path)] = {'before_sha256': sha(before), 'after_sha256': sha(path)}
    helper = Path('Proofs/PayloadIntegerShift.lean').read_text()
    assert 'simp only [Impl.payloadInteger, Nat.one_shiftLeft]' in helper
    assert 'exact payloadInteger_eq_old coding width code' in helper
    assert 'funext coding width code' in helper
    assert not re.search(r'\b(sorry|admit|axiom|native_decide|unsafe)\b', helper)
    paths = [Path(p) for p in execution['after_hashes']] + [P / 'summary.json',
        Path(summary['targeted_build']), log_path, Path(__file__),
        B / 'independent-review/bit-proof-review.json',
        B / 'independent-review/check_source-attempt-01.py',
        B / 'independent-review/source-review-01.log']
    for attempt in summary['attempts']:
        paths += [Path(attempt['path']), Path(attempt['path']).with_name('build.log')]
    record = {'status': 'passed', 'reviewed_utc': datetime.now(timezone.utc).isoformat(),
              'findings': [], 'reviewer': 'cost_analysis',
              'bindings': {str(p): sha(p) for p in paths},
              'existing_bridge_sources_reconstructed_exactly': checked,
              'printed_fact_count': len(facts), 'new_payload_facts': own,
              'retained_failed_builds': 2,
              'reviewer_correction': 'First read-only attempt parsed axiom records one line at a time and missed four wrapped facts; corrected to whitespace-aware whole-log parsing, with the failed script/log retained. All 214 source requirements are unchanged.',
              'assessment': [
                  'The old-body equality quantifies every PayloadCoding and all natural widths/codes without hypotheses; Nat.one_shiftLeft replaces both exact powers, preserving truncated width subtraction and one-modulus signed subtraction.',
                  'The Spec equality uses the complete unchanged reference body, and the function equality is extensional over all three unrestricted arguments.',
                  'Six kernel witnesses retain width zero, unsigned over-wide codes, signed transition, one-bit signed inputs, codes beyond their field width and 80-bit widths.',
                  'AffineValue, CommBTables and Decoder changes are only the checked imports and proof-body rewrites. Reversing those exact edits reconstructs each committed source byte-for-byte, so existing theorem statements remain unchanged.',
                  'The successful retained targeted build checks all three requested targets and 214 printed facts with permitted axioms. Both failed proof-bridge attempts and logs remain bound.'
              ],
              'independence': 'BitExtraction was authored by this reviewer and is excluded from independent mathematical assessment here; its separate root-authored review is bound.',
              'limits': 'No build, native execution or source edit by this review. Combined integration, full gates, native inspection and measurement remain separate requirements.'}
    OUT.write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'review_sha256': sha(OUT), 'facts': len(facts)}))


if __name__ == '__main__':
    main()
