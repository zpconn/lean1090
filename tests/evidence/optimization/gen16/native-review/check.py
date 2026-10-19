#!/usr/bin/env python3
"""Independent read-only source/proof and linked-native review of generation 16."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import hashlib
import json
import re
import shlex
import subprocess
import datetime

ROOT = Path.cwd()
OUT = ROOT / 'tests/evidence/optimization/gen16/native-review'
PREFIX = 'lp_lean1090_Lean1090_Impl_'
FOLD = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text())


def body(path, symbol):
    text = path.read_text()
    match = re.search(r'^LEAN_EXPORT [^\n]*\b' + re.escape(symbol) + r'\([^\n]*\)\{', text, re.M)
    assert match, (path, symbol)
    start = text.index('{', match.start())
    depth = 1
    pos = start + 1
    while depth:
        depth += (text[pos] == '{') - (text[pos] == '}')
        pos += 1
    return text[match.start():pos], text[:match.start()].count('\n') + 1


def main():
    final = OUT / 'review.json'
    assert not final.exists()
    integrated = load(ROOT / 'tests/evidence/optimization/gen16/integration/targeted-build.json')
    assert integrated['status'] == 'passed' and integrated['exit_code'] == 0
    assert integrated['inputs_before'] == integrated['inputs_after']
    for name, digest in integrated['inputs_after'].items():
        assert sha(ROOT / name) == digest
    assert set(integrated['inputs_after']) == {'Impl/Bits.lean', 'Proofs/PackFields.lean', 'Proofs/Decoder.lean'}
    changed = subprocess.check_output(['git', 'diff', '--name-only', 'HEAD', '--', 'Impl', 'Proofs'], text=True).splitlines()
    assert set(changed) == set(integrated['inputs_after'])
    log = ROOT / 'tests/evidence/optimization/gen16/integration/targeted-build.log'
    assert sha(log) == integrated['log_sha256']
    facts = re.findall(r"'Lean1090.Proofs.PackFields\.([^']+)' depends on axioms: \[([^\]]*)\]", log.read_text(), re.S)
    assert len(facts) == 9
    allowed = {'propext', 'Classical.choice', 'Quot.sound'}
    assert all(set(a.replace('\n', '').replace(' ', '').split(',')) <= allowed for _, a in facts)
    proof = (ROOT / 'Proofs/PackFields.lean').read_text()
    assert 'theorem step_eq (acc width value : Nat)' in proof
    assert 'theorem fold_eq (fields : List (Nat × Nat)) (acc : Nat)' in proof
    assert 'theorem packFields_eq (fields : List (Nat × Nat))' in proof
    assert proof.count('decide +kernel') == 6
    assert 'exact PackFields.packFields_eq fields' in (ROOT / 'Proofs/Decoder.lean').read_text()
    frozen = [line.split('  ', 1) for line in (ROOT / 'spec.lock').read_text().splitlines()]
    assert len(frozen) == 104
    assert all(sha(ROOT / name) == digest for digest, name in frozen)
    old = load(ROOT / 'bench/runs/gen15/fresh-native-inputs.json')
    assert len(old) == 22
    inventory = []
    protected = dict(integrated['inputs_after'])
    for row in old:
        current = {'source': row['source'], 'source_sha256': sha(ROOT / row['source']), 'artifacts': {}}
        for name, expected in row['artifacts'].items():
            current['artifacts'][name] = sha(ROOT / name)
            protected[name] = current['artifacts'][name]
            if row['source'] != 'Impl/Bits.lean':
                assert current['artifacts'][name] == expected['sha256'], name
        if row['source'] != 'Impl/Bits.lean':
            assert current['source_sha256'] == row['source_sha256']
        inventory.append(current)
    worker = ROOT / '.lake/build/bin/lean1090-bench'
    protected[str(worker.relative_to(ROOT))] = sha(worker)
    rsp = ROOT / '.lake/build/bin/lean1090-bench.rsp'
    objects = [str(Path(s).relative_to(ROOT)) for s in shlex.split(rsp.read_text()) if s.endswith('.o.export')]
    expected_objects = [name for row in old for name in row['artifacts'] if name.endswith('.o.export')]
    assert len(objects) == len(set(objects)) == 22 and set(objects) == set(expected_objects)
    snippets = {}
    for symbol, source in [(FOLD, '.lake/build/ir/Impl/Bits.c'),
                           (PREFIX + 'packFields', '.lake/build/ir/Impl/Bits.c'),
                           (PREFIX + 'frameSyndrome', '.lake/build/ir/Impl/Message.c'),
                           (PREFIX + 'decode', '.lake/build/ir/Impl/Message.c')]:
        value, line = body(ROOT / source, symbol)
        path = OUT / (symbol + '.generated-C.txt')
        assert not path.exists()
        path.write_text(value + '\n')
        snippets[symbol] = {'source': source, 'line': line, 'source_sha256': sha(ROOT / source),
                            'excerpt': str(path.relative_to(ROOT)), 'excerpt_sha256': sha(path)}
    fold = (OUT / (FOLD + '.generated-C.txt')).read_text()
    assert fold.count('lean_nat_shiftl(') == fold.count('lean_nat_pow(') == fold.count('lean_nat_mod(') == 1
    assert 'lean_nat_mul(' not in fold and 'lean_uint64_shift_left(' in fold and 'lean_uint64_land(' in fold
    assert fold.index('lean_nat_dec_lt') < fold.index('lean_nat_pow(') < fold.index('lean_uint64_shift_left(')
    assert 'lean_unsigned_to_nat(64u)' in fold
    assert PREFIX + 'packFields(' in (OUT / (PREFIX + 'frameSyndrome.generated-C.txt')).read_text()
    assert PREFIX + 'frameSyndrome(' in (OUT / (PREFIX + 'decode.generated-C.txt')).read_text()
    assembly = {}
    for symbol in snippets:
        path = OUT / (symbol + '.assembly.txt')
        argv = ['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol, str(worker)]
        run = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True)
        assert b'<' + symbol.encode() + b'>:' in run.stdout
        assert not path.exists()
        path.write_bytes(run.stdout)
        assert not run.stderr
        assembly[symbol] = {'command': argv, 'exit_code': run.returncode, 'path': str(path.relative_to(ROOT)), 'sha256': sha(path)}
    asm = (OUT / (FOLD + '.assembly.txt')).read_text()
    assert '<lean_nat_shiftl>' in asm and '<lean_nat_pow>' in asm
    assert re.search(r'\bshl\b', asm) and re.search(r'\band\b', asm)
    assert '<lean_nat_mul>' not in asm
    assert all(sha(ROOT / name) == digest for name, digest in protected.items())
    result = {'status': 'passed', 'reviewed_utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
              'inputs': protected, 'linked_native_sets': inventory, 'unchanged_sibling_native_sets': 21,
              'integration_sha256': sha(ROOT / 'tests/evidence/optimization/gen16/integration/targeted-build.json'),
              'benchmark_target_build_sha256': sha(OUT / 'bench-build.json'), 'script_sha256': sha(Path(__file__)),
              'frozen_entries_verified': 104, 'printed_axioms': dict(facts), 'generated_C': snippets, 'assembly': assembly,
              'findings': [], 'review': [
                  'All-input step, fold and public equalities have no valid-layout, width or value hypothesis.',
                  'Arbitrary-size accumulators use Nat shift; only the width<64 value reduction uses UInt64.',
                  'Width 0 produces zero payload; width 63 is fast; width 64 and above keep the original exact modulus.',
                  'Six kernel witnesses exercise empty input, zero/63/64/80 widths, over-wide values and multiword accumulator.',
                  'The sole runtime diff is packFields; Decoder delegates its prior equality to the new public proof.',
                  'Generated C and actual linked assembly retain pow/mod only in the width>=64 branch; fast path uses shift/mask.',
                  'Actual decode calls frameSyndrome, which calls the live packFields. Frozen benchmark and test adapters are unchanged.',
                  'This inspection executes no decoder, test corpus or profiler, and makes no performance claim.'],
              'checks': {'source_change_scope': True, 'unconditional_equality': True, 'allowed_axioms': True,
                         'actual_linked_shift_mask_and_wide_fallback': True, 'production_inputs_unchanged_during_review': True}}
    final.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'review_sha256': sha(final), 'worker_sha256': sha(worker)}))


if __name__ == '__main__':
    main()
