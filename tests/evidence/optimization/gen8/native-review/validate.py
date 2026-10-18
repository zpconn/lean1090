#!/usr/bin/env python3
"""Inspect retained gen8 C and assembly; never execute decoder code."""
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


def native_calls(text):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', text)


def check_paths(asm):
    """Traverse direct branches, fixing only actual Rat equality results.

    The saved assembly and generated C establish the two argument bindings.
    Ordinary callees are treated as returns, not recursively interpreted.
    """
    insns = []
    for line in asm.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            insns.append((int(match[1], 16), match[2], match[3]))
    positions = {row[0]: i for i, row in enumerate(insns)}
    guards = {}
    for i, (address, op, args) in enumerate(insns):
        if op == 'call' and '<l_instDecidableEqRat_decEq>' in args:
            preceding = [row[2] for row in insns[max(0, i - 4):i] if row[1] == 'mov' and row[2].endswith(',%rdi')]
            assert preceding and preceding[-1] in ('%r14,%rdi', '%rbx,%rdi'), (address, preceding)
            kind = 'scale_is_one' if preceding[-1] == '%r14,%rdi' else 'offset_is_zero'
            assert insns[i + 1][1:] == ('test', '%al,%al') and insns[i + 2][1] in ('je', 'jne')
            guards[i + 2] = kind
    assert list(guards.values()).count('scale_is_one') == list(guards.values()).count('offset_is_zero') == 2
    results = []
    for scale_one in (False, True):
        for offset_zero in (False, True):
            truths = {'scale_is_one': scale_one, 'offset_is_zero': offset_zero}
            todo, seen, returns = deque([(0, 0, 0, 0)]), set(), set()
            while todo:
                state = todo.popleft()
                if state in seen:
                    continue
                seen.add(state)
                i, values, muls, adds = state
                address, op, args = insns[i]
                if op == 'call':
                    target = re.search(r'<([^>]+)>', args)
                    assert target, (address, args)
                    target = target[1]
                    if target == P + 'payloadInteger':
                        values += 1
                    elif target == 'l_Rat_mul':
                        muls += 1
                        assert values == 1
                    elif target == 'l_Rat_add':
                        adds += 1
                        assert values == 1
                    assert max(values, muls, adds) <= 1
                if op.startswith('ret'):
                    returns.add((values, muls, adds))
                    continue
                if op.startswith('j'):
                    target = re.match(r'([0-9a-f]+) <', args)
                    assert target and int(target[1], 16) in positions, (address, args)
                    jump = positions[int(target[1], 16)]
                    if i in guards:
                        zero = not truths[guards[i]]
                        taken = zero if op == 'je' else not zero
                        todo.append((jump if taken else i + 1, values, muls, adds))
                        continue
                    todo.append((jump, values, muls, adds))
                    if op == 'jmp':
                        continue
                assert i + 1 < len(insns)
                todo.append((i + 1, values, muls, adds))
            expected = {(0, 0, 0), (1, int(not scale_one), int(not offset_zero))}
            assert returns == expected, (truths, returns, expected)
            results.append({**truths, 'return_states_value_mul_add': sorted(returns), 'syntactic_states': len(seen)})
    return {'guard_branches': {hex(insns[i][0]): name for i, name in guards.items()},
            'cases': results,
            'limits': 'Static intraprocedural traversal with actual scale/offset equality outcomes fixed; all other branches conservatively explored and ordinary callees assumed to return. Not a native execution or a substitute for refinement proof.'}


def main():
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(path) == row['sha256'] for path, row in inspection['inputs'].items())
    retained = OUT / 'retained'
    c = (retained / '.lake/build/ir/Impl/PayloadBits.c').read_text()
    old_c = (retained / 'tests/evidence/diagnostics/gen7/generated-c/Impl/PayloadBits.c').read_text()
    source = (retained / 'Impl/PayloadBits.lean').read_text()
    old_source = (OUT / 'prior-PayloadBits-source.txt').read_text()
    value, affine = (body(c, P + s) for s in ('payloadValue', 'affineValue'))
    checks = {}
    log = (retained / inspection['successful_integrated_build_path']).with_suffix('.log').read_text()
    checks['integrated_build_passed'] = 'Build completed successfully' in log
    checks['runtime_change_is_only_PayloadBits'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/PayloadBits.lean'
    checks['source_has_both_identity_guards_and_original_nonidentity_order'] = 'let scaled := if scale == 1 then (value : Rat) else (value : Rat) * scale\n  if offset == 0 then scaled else scaled + offset' in source
    checks['payloadValue_status_predicate_source_unchanged'] = 'if column.status != 0 && payloadBits word column.status 1 == 0 then none' in source and 'if column.status != 0 && payloadBits word column.status 1 == 0 then none' in old_source
    checks['bit_and_integer_source_definitions_unchanged'] = source[:source.index('/-- Exact affine interpretation')] == old_source[:old_source.index('-- Initial algorithm: Spec/PayloadBits.lean:46.')]
    checks['live_payloadValue_C_inlines_affine_helper'] = P + 'affineValue(' not in value and value.count('l_Rat_mul(') == value.count('l_Rat_add(') == 1
    checks['standalone_affine_C_preserves_the_same_two_guards'] = affine.count('l_instDecidableEqRat_decEq(') == 2 and affine.count('l_Rat_mul(') == affine.count('l_Rat_add(') == 1
    checks['C_mul_guard_is_exact_scale_equality_to_one'] = 'l_instDecidableEqRat_decEq(v_scale_133_, v___x_139_)' in value and re.search(r'if \(v___x_140_ == 0\)\s*\{[^{}]*l_Rat_mul\(', value) is not None
    checks['C_add_guard_is_exact_offset_equality_to_zero'] = 'l_instDecidableEqRat_decEq(v___y_123_, v___x_125_)' in value and re.search(r'if \(v___x_126_ == 0\)\s*\{[^{}]*l_Rat_add\(', value) is not None
    checks['C_identity_constants_are_zero_and_one'] = 'lean_unsigned_to_nat(0u)' in body(c, '_init_' + P + 'payloadValue___closed__0') and 'lean_unsigned_to_nat(1u)' in body(c, '_init_' + P + 'payloadValue___closed__1')
    checks['C_scale_identity_branch_keeps_direct_integer_Rat_conversion'] = 'v___x_143_ = l_Rat_ofInt(v___x_138_);' in value and 'v___y_124_ = v___x_143_;' in value
    checks['C_zero_offset_branch_wraps_existing_scaled_value'] = 'lean_ctor_set(v___x_129_, 0, v___y_124_);' in value
    checks['C_status_rejection_precedes_field_integer_and_affine_work'] = value.index('return v___x_149_;') < value.index(P + 'payloadInteger(') and P + 'payloadBits(v_word_121_, v_status_135_, v___x_146_)' in value
    checks['C_present_branch_keeps_exact_start_width_and_coding'] = P + 'payloadBits(v_word_121_, v_start_130_, v_width_131_)' in value and P + 'payloadInteger(v_coding_132_, v_width_131_, v___x_137_)' in value
    for name in ('payloadBits', 'payloadInteger', 'decodePayloadFields'):
        checks[name + '_C_identical_modulo_bijective_local_renaming'] = alpha(body(c, P + name)) == alpha(body(old_c, P + name))
    assembly = (OUT / 'binary-payloadValue.txt').read_text()
    call_names = native_calls(assembly)
    checks['linked_payloadValue_has_one_mul_one_add_and_no_affine_call'] = call_names.count('l_Rat_mul') == call_names.count('l_Rat_add') == 1 and P + 'affineValue' not in call_names
    checks['linked_field_scale_offset_bindings_match_C'] = 'mov    0x20(%rdi),%r14' in assembly and 'mov    0x28(%rdi),%rbx' in assembly
    graph = check_paths(assembly)
    (OUT / 'payloadValue-control-flow.json').write_text(json.dumps(graph, indent=2) + '\n')
    checks['linked_all_four_guard_combinations_have_exact_arithmetic_call_counts'] = len(graph['cases']) == 4
    checks['affine_helper_object_exists_but_linked_wrapper_is_inlined'] = '<' + P + 'affineValue>:' in (OUT / 'object-affineValue.txt').read_text() and not inspection['requested_binary_symbols'][P + 'affineValue']
    table_map = 'lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0'
    checks['linked_semantic_table_map_calls_live_payloadValue'] = P + 'payloadValue' in native_calls((OUT / ('binary-' + table_map)).with_suffix('.txt').read_text())
    checks['linked_ADSB_and_CommB_semantics_call_actual_table_map'] = all(table_map in native_calls((OUT / ('binary-Semantics_' + name + '.txt')).read_text()) for name in ('adsb', 'commB'))
    checks['linked_report_calls_live_semantic_projection'] = P + 'Semantics_adsb' in native_calls((OUT / 'binary-reportWithSyndrome.txt').read_text())
    checks['linked_decode_calls_live_report'] = P + 'reportWithSyndrome' in native_calls((OUT / 'binary-decode.txt').read_text())
    checks['frozen_direct_adapter_keeps_live_decode_and_semantics'] = all(token in (retained / 'Tests/CommBDifferential.lean').read_text() for token in ('Impl.decodeBDS', 'Impl.Semantics.commB'))
    checks['frozen_whole_message_adapter_keeps_Impl_decode'] = 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    checks['frozen_benchmark_keeps_complete_Impl_decode'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3
    prior = {row['source']: row for row in json.loads((retained / 'bench/runs/gen7/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/PayloadBits.lean'):
            continue
        old = prior[row['source']]
        assert sha(row['source']) == old['source_sha256'], row['source']
        assert all(sha(row[key]) == old['artifacts'][row[key]]['sha256'] for key in ('c', 'object', 'trace')), row['source']
        unchanged.append(row['source'])
    checks['other_19_production_sources_C_objects_traces_equal_gen7'] = len(unchanged) == 19
    checks['unchanged_tables_integer_gate_and_binary64_objects_included'] = all(s in unchanged for s in ('Impl/CommB.lean', 'Impl/ScoreGate.lean', 'Impl/Binary64.lean'))
    checks['CommB_C_byte_identical_to_gen7'] = (retained / '.lake/build/ir/Impl/CommB.c').read_bytes() == (retained / 'tests/evidence/diagnostics/gen7/generated-c/Impl/CommB.c').read_bytes()
    checks['unchanged_live_score_entrypoint_uses_integer_gate'] = P + 'ScoreGate_choose' in native_calls((OUT / 'binary-cbScorePasses.txt').read_text())
    fallback = native_calls((OUT / 'binary-cbScorePasses___lam__0___boxed.txt').read_text())
    checks['unchanged_live_software_fallback_retains_density_penalty_add_comparison'] = all(n in fallback for n in (P + 'cbDensity', P + 'cbPenalty', P + 'Binary64_add', 'l_Rat_instDecidableLe'))
    checks['no_new_FFI_mutable_cache_or_runtime_import'] = not any(token in (OUT / 'runtime-diff.txt').read_text() for token in ('@[extern', '@[implemented_by', 'IO.Ref', 'ST.Ref', 'initialize ', '+import '))
    for name in ('TRUSTED.md', 'lakefile.toml', 'spec.lock'):
        checks[name + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + name]) == (retained / name).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(path) == digest for digest, path in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/PayloadBits.c.o.export.trace').read_text())
    compiler = next(row['message'] for row in trace['log'] if row['message'].startswith('.> '))
    checks['native_flags_preserve_O3_and_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler
    assert all(checks.values()), {name: result for name, result in checks.items() if not result}
    assert all(sha(path) == row['sha256'] for path, row in inspection['inputs'].items())
    review = {'status': 'passed', 'checks': checks, 'all_captured_inputs_unchanged': True,
              'scope': 'Static source/generated-C/object/linked integrated CLI inspection only. No build, native decoder, profiler or benchmark execution.',
              'unchanged_native_sources': unchanged,
              'inlining': 'affineValue and tableValues wrappers are inlined/absent as linked standalone symbols. Actual payloadValue guard branches and table-map calls remain live. Missing wrappers are not zero logical work.',
              'future_diagnostic': ['Bind the freshly timed worker again.', 'Measure payloadValue and its guarded Rat.mul/add descendants by actual caller context.', 'Separate inlined affine decisions from native entry counts; keep complete output/census checks.'],
              'files': {str(path.relative_to(OUT)): {'sha256': sha(path), 'bytes': path.stat().st_size} for path in sorted(OUT.rglob('*')) if path.is_file() and path.name != 'review.json'}}
    (OUT / 'review.json').write_text(json.dumps(review, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
