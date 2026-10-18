#!/usr/bin/env python3
"""Read-only validation of already-built gen7 C and linked assembly."""
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


def functions(text):
    result = {}
    for match in re.finditer(r'(?:LEAN_EXPORT |static )[^;{}\n]+?\b([A-Za-z_]\w*)\([^;{}]*\)\s*\{', text):
        depth = 0
        for index in range(match.end() - 1, len(text)):
            depth += (text[index] == '{') - (text[index] == '}')
            if depth == 0:
                result[match[1]] = text[match.start():index + 1]
                break
        else:
            raise AssertionError(match[1])
    return result


def callees(text):
    return set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', text)) - {'if', 'return', 'sizeof', 'while'}


def native_calls(text):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', text)


def fallback_cfg(asm):
    """Syntactic paths, with each ordinary callee assumed to return.

    This bounds callback call-site visits; it does not interpret arithmetic.
    The exact predicate nesting is checked independently in generated C.
    """
    insns = []
    for line in asm.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            insns.append((int(match[1], 16), match[2], match[3]))
    indices = {row[0]: i for i, row in enumerate(insns)}
    todo, seen, returns = deque([(0, 0)]), set(), set()
    sites = set()
    while todo:
        i, count = todo.popleft()
        if (i, count) in seen:
            continue
        seen.add((i, count))
        address, op, args = insns[i]
        if op == 'call':
            target = re.search(r'<([^>]+)>', args)
            assert target, (address, args)
            if target[1] == 'lean_apply_1':
                sites.add(address)
                count += 1
                assert count == 1
        if op.startswith('ret'):
            returns.add(count)
            continue
        if op.startswith('j'):
            target = re.match(r'([0-9a-f]+) <', args)
            assert target and int(target[1], 16) in indices, (address, args)
            todo.append((indices[int(target[1], 16)], count))
            if op == 'jmp':
                continue
        assert i + 1 < len(insns)
        todo.append((i + 1, count))
    assert returns == {0, 1} and len(sites) == 1
    return {'instruction_count': len(insns), 'syntactic_states': len(seen),
            'fallback_sites': [hex(x) for x in sorted(sites)],
            'fallback_counts_at_returns': sorted(returns),
            'limit': 'Intraprocedural direct-branch paths only; arithmetic conditions are established by retained C and the proved all-input equality.'}


def main():
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(p) == row['sha256'] for p, row in inspection['inputs'].items())
    retained = OUT / 'retained'
    score_source = (retained / 'Impl/ScoreGate.lean').read_text()
    score_c = (retained / '.lake/build/ir/Impl/ScoreGate.c').read_text()
    commb_c = (retained / '.lake/build/ir/Impl/CommB.c').read_text()
    defs = functions(score_c)
    commb_defs = functions(commb_c)
    choose = defs[P + 'ScoreGate_choose']
    # Retain every project-local function referenced from choose, including
    # cold literal initializers passed as function pointers to lean_obj_once.
    todo, closure = [P + 'ScoreGate_choose'], set()
    while todo:
        name = todo.pop()
        if name in closure:
            continue
        closure.add(name)
        refs = {token for token in re.findall(r'\b[A-Za-z_]\w*\b', defs[name]) if token in defs}
        todo.extend(refs - closure)
    foreign = sorted(set().union(*(callees(defs[n]) for n in closure)) - set(defs))
    graph = {'root': P + 'ScoreGate_choose', 'reachable_local_functions': sorted(closure),
             'external_C_calls': foreign,
             'local_references': {name: sorted({token for token in re.findall(r'\b[A-Za-z_]\w*\b', defs[name]) if token in defs} - {name}) for name in sorted(closure)},
             'limits': 'C symbol references include cold literal initializers. Runtime primitives are not recursively disassembled; no throughput or executed branch-count claim.'}
    (OUT / 'choose-C-reference-closure.json').write_text(json.dumps(graph, indent=2) + '\n')
    (OUT / 'choose-C-reference-closure.c').write_text('\n\n'.join(defs[n] for n in sorted(closure)) + '\n')
    commands = []
    symbols = ['_init_' + P + 'ScoreGate_' + suffix for suffix in
               ('scaledTotals___closed__0', 'scaledTotals___closed__1',
                'choose___closed__0', 'choose___closed__1', 'choose___closed__2')]
    symbols.extend([P + 'frameCommB',
                    'lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0'])
    for symbol in symbols:
        argv = ['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol, '.lake/build/bin/lean1090']
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        assert result.returncode == 0
        name = 'extra-' + symbol
        (OUT / (name + '.txt')).write_bytes(result.stdout)
        (OUT / (name + '.stderr')).write_bytes(result.stderr)
        commands.append({'argv': argv, 'stdout': name + '.txt', 'stderr': name + '.stderr', 'exit_code': 0})
    (OUT / 'additional-inspection.json').write_text(json.dumps({'commands': commands, 'no_decoder_execution': True}, indent=2) + '\n')
    checks = {}
    checks['integrated_build_passed_3512_jobs'] = 'Build completed successfully (3512 jobs).' in (retained / inspection['successful_integrated_build_path']).with_suffix('.log').read_text()
    checks['live_choose_C_has_one_common_denominator_and_pair_sum'] = all(choose.count(P + 'ScoreGate_' + n + '(') == 1 for n in ('commonDenominator', 'scaledTotals'))
    checks['C_reference_closure_has_no_normalized_Rat_Binary64_or_gcd_calls'] = not any('Rat_' in f or 'Binary64' in f or 'gcd' in f.lower() for f in foreign)
    checks['C_reference_closure_uses_only_known_integer_list_and_runtime_operations'] = all(f.startswith(('lean_', 'l_List_lengthTR', 'l_List_reverse')) for f in foreign)
    checks['old_mass_center_envelope_not_in_live_C_closure'] = all(P + 'ScoreGate_' + n not in closure for n in ('mass', 'center', 'envelope'))
    checks['semantic_reference_apis_retained_in_source_and_C'] = all('def ' + n + ' ' in score_source and P + 'ScoreGate_' + n in defs for n in ('mass', 'center', 'envelope'))
    checks['common_denominator_max_divisibility_and_product_fallback_remain'] = all(fragment in score_source for fragment in ('denominators.foldl max 1', 'largest % d == 0', 'else denominators.prod')) and all(any(token in defs[n] for n in closure) for token in ('lean_nat_mod(', 'lean_nat_mul(', 'lean_nat_dec_le('))
    checks['scaled_pair_fold_uses_raw_numerator_denominator_and_integer_sum_abs'] = all(any(token in defs[n] for n in closure if 'scaledTotals' in n) for token in ('lean_ctor_get(', 'lean_nat_div(', 'lean_int_mul(', 'lean_int_add(', 'lean_nat_abs('))
    checks['positive_count_is_Nat_max_before_Int_conversion'] = 'let n : Int := (max terms.length 1 : Nat)' in score_source and 'lean_nat_dec_le(' in choose and 'lean_nat_to_int(v___y_221_)' in choose
    checks['exact_constant_and_integer_cross_comparisons_retained'] = '1099511627776' in ''.join(defs[n] for n in closure) and all(token in choose for token in ('lean_int_sub(v_scaledCenter_233_, v_scaledError_234_)', 'lean_int_dec_le(v_threshold_238_, v___x_239_)', 'lean_int_add(v_scaledCenter_233_, v_scaledError_234_)', 'lean_int_dec_lt(v___x_241_, v_threshold_238_)'))
    checks['C_fallback_is_only_inside_both_uncertain_comparison_branches'] = re.search(r'if \(v___x_240_ == 0\).*?lean_int_dec_lt.*?if \(v___x_242_ == 0\).*?lean_apply_1\(v_fallback_212_', choose, re.S) is not None and choose.count('lean_apply_1(') == 1 and choose.count('lean_dec_ref(v_fallback_212_)') == 2
    caller = commb_defs[P + 'cbScorePasses']
    checks['C_cbScorePasses_preserves_lazy_capture_and_live_choose_call'] = P + 'cbScorePasses___lam__0___boxed' in caller and all(caller.count(P + s + '(') == 1 for s in ('cbDensityTermsFast', 'cbPenalty', 'ScoreGate_choose')) and 'cbCombinedScore(' not in caller
    checks['CommB_generated_C_byte_identical_to_gen6'] = commb_c == (retained / 'tests/evidence/diagnostics/gen6/generated-c/Impl/CommB.c').read_text()
    choose_asm = (OUT / 'binary-ScoreGate_choose.txt').read_text()
    native = native_calls(choose_asm)
    checks['linked_choose_has_live_common_denominator_integer_pair_fold_and_fallback'] = P + 'ScoreGate_commonDenominator' in native and any('ScoreGate_scaledTotals_spec' in f for f in native) and native.count('lean_apply_1') == 1
    checks['linked_choose_retains_large_integer_add_mul_sub_and_signed_comparisons'] = all(name in native for name in ('lean_int_big_add', 'lean_int_big_mul', 'lean_int_big_sub', 'lean_int_big_le', 'lean_int_big_lt', 'lean_nat_big_div'))
    checks['linked_choose_direct_calls_exclude_normalized_rational_functions'] = not any('Rat_' in f or 'Binary64' in f or 'gcd' in f.lower() for f in native)
    cfg = fallback_cfg(choose_asm)
    (OUT / 'choose-control-flow.json').write_text(json.dumps(cfg, indent=2) + '\n')
    checks['linked_choose_syntactic_paths_call_fallback_zero_or_once'] = cfg['fallback_counts_at_returns'] == [0, 1]
    all_score_asm = '\n'.join(p.read_text() for p in OUT.glob('binary-*.txt') if 'ScoreGate' in p.name)
    checks['captured_live_ScoreGate_helper_calls_exclude_Rat_Binary64_gcd'] = not any('Rat_' in f or 'Binary64' in f or 'gcd' in f.lower() for f in native_calls(all_score_asm))
    caller_asm = (OUT / 'binary-cbScorePasses.txt').read_text()
    checks['linked_cbScorePasses_constructs_callback_and_tail_calls_actual_choose'] = P + 'cbScorePasses___lam__0___boxed' in caller_asm and P + 'ScoreGate_choose' in native_calls(caller_asm)
    fallback_calls = native_calls((OUT / 'binary-cbScorePasses___lam__0___boxed.txt').read_text())
    checks['linked_lazy_callback_retains_complete_software_model_and_Rat_threshold'] = all(f in fallback_calls for f in (P + 'cbDensity', P + 'cbPenalty', P + 'Binary64_add', 'l_Rat_instDecidableLe'))
    checks['linked_core_candidate_uses_live_score_entrypoint'] = P + 'cbScorePasses' in native_calls((OUT / 'binary-commBCoreEligible.txt').read_text())
    checks['linked_candidate_wrapper_delegates_same_core'] = P + 'commBCoreEligible' in native_calls((OUT / 'binary-commBEligible.txt').read_text())
    infer_asm = (OUT / ('extra-lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0.txt')).read_text()
    checks['linked_inference_iteration_reaches_candidate_and_decodeBDS'] = all(f in native_calls(infer_asm) for f in (P + 'commBEligible', P + 'decodeBDS'))
    frame_asm = (OUT / ('extra-' + P + 'frameCommB.txt')).read_text()
    checks['linked_message_frameCommB_reaches_inference'] = any('inferCommB' in f for f in native_calls(frame_asm))
    checks['linked_decode_report_reaches_live_frameCommB'] = P + 'reportWithSyndrome' in native_calls((OUT / 'binary-decode.txt').read_text()) and P + 'frameCommB' in native_calls((OUT / 'binary-reportWithSyndrome.txt').read_text())
    checks['frozen_direct_BDS_adapter_reaches_live_decode_and_semantic_helpers'] = all(token in (retained / 'Tests/CommBDifferential.lean').read_text() for token in ('Impl.Semantics.commB', 'Impl.decodeBDS'))
    checks['frozen_whole_message_unit_adapter_reaches_actual_decode'] = 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    checks['frozen_benchmark_still_calls_Impl_decode'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3
    prior = {row['source']: row for row in json.loads((retained / 'bench/runs/gen6/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/ScoreGate.lean'):
            continue
        old = prior[row['source']]
        assert all(sha(row[key]) == old['artifacts'][row[key]]['sha256'] for key in ('c', 'object', 'trace')), row['source']
        assert sha(row['source']) == old['source_sha256'], row['source']
        unchanged.append(row['source'])
    checks['all_19_other_reused_native_sets_and_sources_match_gen6'] = len(unchanged) == 19
    checks['runtime_change_is_only_ScoreGate'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/ScoreGate.lean'
    checks['no_new_user_FFI_or_message_state'] = not any(token in (OUT / 'runtime-diff.txt').read_text() for token in ('@[extern', '@[implemented_by', 'IO.Ref', 'ST.Ref', 'initialize '))
    for name in ('TRUSTED.md', 'lakefile.toml', 'spec.lock'):
        checks[name + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + name]) == (retained / name).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == digest for digest, p in locked)
    checks['no_frozen_Lean_module_directly_uses_old_ScoreGate_reference_APIs'] = all(not re.search(r'ScoreGate\.(?:mass|center|envelope)\b', Path(p).read_text()) for _, p in locked if p.endswith('.lean'))
    trace = json.loads((retained / '.lake/build/ir/Impl/ScoreGate.c.o.export.trace').read_text())
    compilation = next(row['message'] for row in trace['log'] if row['message'].startswith('.> '))
    checks['native_flags_preserve_O3_and_ffp_contract_off'] = '-O3' in compilation and '-ffp-contract=off' in compilation
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    assert all(sha(p) == row['sha256'] for p, row in inspection['inputs'].items())
    result = {'status': 'passed', 'checks': checks, 'all_captured_inputs_unchanged': True,
              'scope': 'Static review of integrated CLI and generated C/object/source. No build, decoder execution, profiling or timing; future fresh worker needs its own binding.',
              'unchanged_native_sources': unchanged,
              'reference_API_status': 'mass/center/envelope remain pure mathematical reference APIs, also used in the after-collection diagnostic shadow census. They are not called by live choose; no frozen adapter directly refers to them. Their missing linked CLI boundaries do not imply zero logical enclosure computation.',
              'inlining': 'scaledNumerator and scaledTotals wrappers are inlined; live integer pair-fold and denominator helper remain native anchors. Arbitrary-precision integer arithmetic and allocations remain.',
              'constants': 'Compiler lazy cells store only format constants 0, 2^40 and -3 plus the immutable zero accumulator pair. No message-dependent cache or new trusted primitive.',
              'next_diagnostic_requirements': ['Bind the freshly built timed worker to committed sources.', 'Add commonDenominator and scaledTotals pair-fold anchors; retain overlapping inclusive-cost caveats.', 'Keep center/envelope/mass shadow census after root collection, and reconcile actual choose/fallback counts.', 'Do not interpret absent old normalized-rational boundaries or inlined wrappers as zero enclosure work.'],
              'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name != 'review.json'}}
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'local_C_functions': len(closure), 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
