#!/usr/bin/env python3
"""Validate retained gen9 native structure without executing decoder code."""
from collections import deque
import hashlib
import json
from pathlib import Path
import re
import subprocess

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def body(text, symbol):
    match = re.search(r'\b' + re.escape(symbol) + r'\([^;{}]*\)\s*\{', text)
    assert match, symbol
    depth = 0
    for index in range(match.end() - 1, len(text)):
        depth += (text[index] == '{') - (text[index] == '}')
        if depth == 0:
            return text[match.start():index + 1]
    raise AssertionError(symbol)


def alpha(text):
    names = {}
    return re.sub(r'\bv_\w+_\b', lambda m: names.setdefault(m[0], 'local' + str(len(names))), text)


def calls(text):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', text)


def native_paths(text):
    insns = []
    for line in text.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            insns.append((int(match[1], 16), match[2], match[3]))
    positions = {r[0]: i for i, r in enumerate(insns)}
    # The actual argument binding and guard are retained explicitly. Tagged 64
    # is 129 (0x81); the big-width comparison uses the same tagged constant.
    guard = next(i for i, r in enumerate(insns) if r[1:] == ('cmp', '$0x81,%rbx'))
    assert insns[guard + 1][1] == 'jae'
    wide = positions[int(insns[guard + 1][2].split()[0], 16)]
    fast = guard + 2
    assert insns[fast][0] == 0xb4b414 and insns[wide][0] == 0xb4b524
    assert 'mov    %rdx,%rbx' in text and 'mov    %rcx,%r14' in text
    assert 'mov    $0x81,%esi' in text and '<lean_nat_big_lt>' in text
    observations = {}
    for name, entry in [('narrow', fast), ('wide', wide)]:
        todo, seen, returns, observed_calls = deque([(entry, False)]), set(), set(), set()
        while todo:
            i, shifted = todo.popleft()
            if (i, shifted) in seen:
                continue
            seen.add((i, shifted))
            address, op, args = insns[i]
            if op == 'call':
                target = re.search(r'<([^>]+)>', args)
                assert target, (address, args)
                target = target[1]
                observed_calls.add(target)
                if target == 'lean_nat_big_shiftr':
                    shifted = True
                if name == 'narrow' and target == 'lean_uint64_of_big_nat':
                    assert shifted, (address, 'conversion before exact shift')
            if address == 0xb4b48c:
                assert (op, args) == ('shr', '%cl,%r14')
                shifted = True
            if name == 'narrow' and address == 0xb4b4f3:
                assert shifted and (op, args) == ('and', '%rax,%r15')
            if op.startswith('ret'):
                returns.add(shifted)
                continue
            if op.startswith('j'):
                target = re.match(r'([0-9a-f]+) <', args)
                assert target and int(target[1], 16) in positions, (address, args)
                todo.append((positions[int(target[1], 16)], shifted))
                if op == 'jmp':
                    continue
            assert i + 1 < len(insns)
            todo.append((i + 1, shifted))
        operators = {insns[i][1] for i, _ in seen}
        if name == 'narrow':
            assert returns == {True}
            assert not observed_calls.intersection({'lean_nat_pow', 'lean_nat_big_div', 'lean_nat_big_mod', 'l_BitVec_ofNat'})
            assert not operators.intersection({'div', 'idiv'})
            assert {'lean_nat_big_shiftr', 'lean_uint64_of_big_nat'} <= observed_calls
        else:
            assert returns == {False}
            assert {'lean_nat_pow', 'lean_nat_big_div', 'l_BitVec_ofNat'} <= observed_calls
            assert 'div' in operators and 'lean_nat_big_shiftr' not in observed_calls
        observations[name] = {'entry': hex(insns[entry][0]), 'reachable_instructions': len({i for i, _ in seen}),
                              'calls': sorted(observed_calls), 'returns_after_exact_shift': sorted(returns)}
    return {'branches': observations,
            'limits': 'Static intraprocedural reachability from the actual width-guard successors. Other conditional branches conservatively explored; callees assumed to return. Not runtime input testing or a replacement for the all-input equality theorem.'}


def main():
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(path) == row['sha256'] for path, row in inspection['inputs'].items())
    retained = OUT / 'retained'
    c = (retained / '.lake/build/ir/Impl/Bits.c').read_text()
    old_c = (retained / 'tests/evidence/diagnostics/gen8/generated-c/Impl/Bits.c').read_text()
    source = (retained / 'Impl/Bits.lean').read_text()
    field = body(c, P + 'field')
    fallback, narrow = field.split('if (v___x_24_ == 0)\n{', 1)[1].split('\nelse\n{', 1)
    checks = {}
    log = (retained / inspection['successful_integrated_build_path']).with_suffix('.log').read_text()
    checks['integrated_build_passed'] = 'Build completed successfully (3514 jobs).' in log
    checks['runtime_change_is_only_Bits'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/Bits.lean'
    checks['source_preserves_unrestricted_shift_before_conversion'] = '(word >>> (total - start - width)).toUInt64 0 width' in source
    checks['source_retains_original_wide_fallback'] = 'else BitVec.ofNat width (word / 2 ^ (total - start - width))' in source
    checks['C_guard_tests_width_below_64'] = 'lean_unsigned_to_nat(64u)' in field and 'lean_nat_dec_lt(v_width_21_, v___x_23_)' in field
    checks['C_fallback_preserves_original_power_division_and_checked_modulus'] = fallback.count('lean_nat_pow(') == fallback.count('lean_nat_div(') == fallback.count('l_BitVec_ofNat(') == 1
    checks['C_narrow_has_no_nat_power_division_modulus_or_generic_BitVec_constructor'] = not any(x in narrow for x in ('lean_nat_pow(', 'lean_nat_div(', 'lean_nat_mod(', 'l_BitVec_ofNat('))
    checks['C_narrow_preserves_truncating_position_subtraction'] = 'lean_nat_sub(v_total_19_, v_start_20_)' in narrow and 'lean_nat_sub(v___x_31_, v_width_21_)' in narrow
    checks['C_exact_shift_result_is_converted_before_mask'] = 'v___x_33_ = lean_nat_shiftr(v_word_22_, v___x_32_);' in narrow and 'v___x_34_ = lean_uint64_of_nat(v___x_33_);' in narrow and narrow.index('lean_nat_shiftr(') < narrow.index('lean_uint64_of_nat(') < narrow.index('lean_uint64_land(')
    checks['C_machine_mask_and_direct_Nat_result'] = all(x in narrow for x in ('lean_uint64_shift_left(', 'lean_uint64_sub(', 'lean_uint64_land(v___x_34_, v___x_38_)', 'lean_uint64_to_nat(v___x_39_)'))
    checks['C_mask_helper_inlined_and_proof_erased'] = P + 'payloadWordBits(' not in field and not any(x in c for x in ('payloadWordMask_toNat', 'Nat_lt_of_le_of_lt', 'FrameBits_field_eq'))
    for name in ('bytesValue', 'packFields', 'frameBytes'):
        checks[name + '_C_body_unchanged_modulo_local_names'] = alpha(body(c, P + name)) == alpha(body(old_c, P + name))
    for name in ('bytesValue', 'packFields'):
        symbol = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_' + name + '_spec__0'
        checks[name + '_fold_body_unchanged_modulo_local_names'] = alpha(body(c, symbol)) == alpha(body(old_c, symbol))
    asm = (OUT / 'binary-field.txt').read_text()
    graph = native_paths(asm)
    (OUT / 'field-control-flow.json').write_text(json.dumps(graph, indent=2) + '\n')
    checks['native_width_branches_separate_shift_mask_from_power_division'] = bool(graph['branches'])
    checks['native_mask_is_shl_not_and_then_tagged_Nat'] = all(x in asm for x in ('shl    %cl,%rax', 'not    %rax', 'and    %rax,%r15', 'lea    0x1(,%r15,2),%rax'))
    checks['native_small_Nat_shift_guards_large_count'] = 'cmp    $0x80,%r15' in asm and 'cmovb  %rax,%r14' in asm
    checks['actual_decodeFrame_calls_live_field_26_sites'] = calls((OUT / 'binary-decodeFrame.txt').read_text()).count(P + 'field') == 26
    checks['actual_decode_calls_live_decodeFrame_and_single_shared_syndrome'] = all(calls((OUT / 'binary-decode.txt').read_text()).count(P + x) == 1 for x in ('decodeFrame', 'frameSyndrome', 'reportWithSyndrome'))
    checks['frozen_whole_message_adapter_keeps_Impl_decode'] = 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    checks['frozen_direct_adapter_keeps_live_decode_and_semantics'] = all(x in (retained / 'Tests/CommBDifferential.lean').read_text() for x in ('Impl.decodeBDS', 'Impl.Semantics.commB'))
    checks['frozen_benchmark_keeps_complete_Impl_decode'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3
    proof = (retained / 'Proofs/FrameBits.lean').read_text()
    checks['universal_theorem_has_all_four_Nat_inputs_without_hypotheses'] = 'theorem field_eq (total start width word : Nat) :\n    Impl.field total start width word = Spec.field total start width word' in proof
    checks['universal_equality_and_eight_witnesses_checked_by_build'] = all("Lean1090.Proofs.FrameBits." + name + "' depends on axioms:" in log for name in ('field_eq', 'field_eq_old', 'zero_width_witness', 'last_fast_width_witness', 'first_fallback_width_witness', 'wide_fallback_witness', 'cross_word_witness', 'high_shift_witness', 'start_underflow_witness', 'width_underflow_witness'))
    decoder = (retained / 'Proofs/Decoder.lean').read_text()
    checks['all_input_decoder_refinement_uses_new_field_equality'] = 'import Proofs.FrameBits' in decoder and 'exact FrameBits.field_eq total start width word' in decoder and "'Lean1090.Proofs.Refinement' depends on axioms: [propext, Classical.choice, Quot.sound]" in log
    prior = {r['source']: r for r in json.loads((retained / 'bench/runs/gen8/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/Bits.lean'):
            continue
        old = prior[row['source']]
        assert sha(row['source']) == old['source_sha256']
        assert all(sha(row[k]) == old['artifacts'][row[k]]['sha256'] for k in ('c', 'object', 'trace'))
        unchanged.append(row['source'])
    checks['other_19_production_sources_C_objects_traces_equal_gen8'] = len(unchanged) == 19
    checks['unchanged_parity_semantics_payload_and_software_score_modules_included'] = all(s in unchanged for s in ('Impl/Parity.lean', 'Impl/Message.lean', 'Impl/Semantics.lean', 'Impl/PayloadBits.lean', 'Impl/CommB.lean', 'Impl/ScoreGate.lean', 'Impl/Binary64.lean'))
    checks['unchanged_live_score_uses_integer_gate'] = P + 'ScoreGate_choose' in calls((OUT / 'binary-cbScorePasses.txt').read_text())
    fallback_calls = calls((OUT / 'binary-cbScorePasses___lam__0___boxed.txt').read_text())
    checks['unchanged_full_software_fallback_is_live'] = all(n in fallback_calls for n in (P + 'cbDensity', P + 'cbPenalty', P + 'Binary64_add', 'l_Rat_instDecidableLe'))
    diff = (OUT / 'runtime-diff.txt').read_text()
    checks['no_new_FFI_or_mutable_cache'] = not any(x in diff for x in ('@[extern', '@[implemented_by', 'IO.Ref', 'ST.Ref', 'initialize '))
    checks['runtime_import_is_existing_pure_mask_module'] = source.startswith('import Impl.PayloadBits\n')
    for name in ('TRUSTED.md', 'lakefile.toml', 'spec.lock'):
        checks[name + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + name]) == (retained / name).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == digest for digest, p in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/Bits.c.o.export.trace').read_text())
    compiler = next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_keep_O3_and_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler
    assert all(checks.values()), {k:v for k,v in checks.items() if not v}
    assert all(sha(path) == row['sha256'] for path, row in inspection['inputs'].items())
    review = {'status': 'passed', 'checks': checks, 'all_captured_inputs_unchanged': True,
              'scope': 'Static source/generated-C/object/linked integrated CLI inspection only. No build, native decoder, test, profile or benchmark executed.',
              'unchanged_native_sources': unchanged,
              'inlining': 'payloadWordBits mask operations inline into live field; no extra runtime helper. Actual field remains callable from decodeFrame. Missing helper calls do not imply absent extraction work.',
              'future_diagnostic': ['Bind the freshly timed worker again.', 'Count actual field and Nat/GMP shift/convert descendants by retained caller context; original wide fallback remains live for arbitrary widths.', 'Keep shared syndrome, integer gate and complete output/census checks unchanged.'],
              'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name != 'review.json'}}
    (OUT / 'review.json').write_text(json.dumps(review, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
