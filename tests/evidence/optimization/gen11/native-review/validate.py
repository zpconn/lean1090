#!/usr/bin/env python3
"""Independently check retained gen11 proof/native evidence; no decoder execution."""
import hashlib
import json
from pathlib import Path
import re
import subprocess

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'
LOOP = 'lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg'
ALLOWED = {'propext', 'Classical.choice', 'Quot.sound'}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def body(text, symbol):
    match = re.search(r'\b' + re.escape(symbol) + r'\([^;{}]*\)\s*\{', text)
    assert match, symbol
    depth = 0
    for i in range(match.end() - 1, len(text)):
        depth += (text[i] == '{') - (text[i] == '}')
        if depth == 0:
            return text[match.start():i + 1]
    raise AssertionError(symbol)


def calls(text):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', text)


def instructions(text):
    rows = []
    for line in text.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            rows.append({'address': int(match[1], 16), 'op': match[2], 'args': match[3]})
    return rows


def syndrome_cfg(text):
    """Explore actual intraprocedural branch alternatives, counting loop calls."""
    rows = instructions(text)
    by_address = {r['address']: i for i, r in enumerate(rows)}
    pending = [(0, 0)]
    seen = set()
    exits = []
    while pending:
        i, count = pending.pop()
        if (i, count) in seen:
            continue
        seen.add((i, count))
        r = rows[i]
        if r['op'] == 'call' and '<' + LOOP + '>' in r['args']:
            count += 1
        assert count <= 1, ('multiple loop calls on one possible path', r)
        if r['op'].startswith('j'):
            match = re.match(r'([0-9a-f]+) <([^>]+)>', r['args'])
            assert match, r
            target = int(match[1], 16)
            if target in by_address:
                pending.append((by_address[target], count))
            else:
                assert r['op'] == 'jmp' and match[2] == 'l_BitVec_ofNat', r
                exits.append({'address': hex(r['address']), 'loop_calls': count, 'target': match[2]})
            if r['op'] == 'jmp':
                continue
        assert r['op'] != 'ret', ('unexpected direct return without projection', r)
        assert i + 1 < len(rows)
        pending.append((i + 1, count))
    assert exits and all(r['loop_calls'] == 1 for r in exits)
    return {'instruction_count': len(rows), 'reachable_states': len(seen),
            'static_loop_calls': sum(r['op'] == 'call' and '<' + LOOP + '>' in r['args'] for r in rows),
            'exits': exits, 'scope': 'Static branch traversal; external calls return normally. No runtime execution or frequency inference.'}


def facts(text):
    found = re.findall(r"'([^']+)' depends on axioms:\s*\[([^]]*)\]", text, re.S)
    return [{'name': name, 'axioms': sorted(x.strip() for x in ax.split(',') if x.strip())}
            for name, ax in found]


def main():
    assert not (OUT / 'review.json').exists()
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    assert all((OUT / dest).read_bytes() == Path(p).read_bytes() for p, dest in inspection['retained'].items())
    assert all(r['exit_code'] == 0 and (OUT / r['stderr']).read_bytes() == b'' for r in inspection['commands'])
    retained = OUT / 'retained'
    c = (retained / '.lake/build/ir/Impl/Parity.c').read_text()
    source = (retained / 'Impl/Parity.lean').read_text()
    prior_source = (OUT / 'prior-Parity-source.txt').read_text()
    proof = (retained / 'Proofs/ParityWord.lean').read_text()
    decoder = (retained / 'Proofs/Decoder.lean').read_text()
    build = inspection['successful_integrated_build']
    log = (retained / inspection['successful_integrated_build_path']).with_suffix('.log').read_text()
    checks = {}
    checks['integrated_build_passed_3518_jobs'] = 'Build completed successfully (3518 jobs).' in log
    checks['all_three_integrated_source_bindings_match'] = len(build['inputs_after']) == 3 and build['inputs_before'] == build['inputs_after'] and all(sha(p) == h for p, h in build['inputs_after'].items())
    checks['only_Parity_runtime_source_changed'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/Parity.lean'
    checks['unrelated_Parity_definitions_unchanged'] = re.search(r'def generator[^\n]+', source)[0] == re.search(r'def generator[^\n]+', prior_source)[0] and all(
        source.split(start, 1)[1].split(end, 1)[0] == prior_source.split(start, 1)[1].split(end, 1)[0]
        for start, end in [('@[inline] def wordBit', '-- Initial algorithm: Spec/Parity.lean:25.'), ('def checksum', 'end Lean1090.Impl.Parity')])
    checks['public_step_delegates_same_wordStep'] = 'BitVec.ofNat 24 (wordStep remainder.toNat.toUInt32 bit).toNat' in source
    checks['syndrome_uses_unrestricted_Nat_fold_and_same_wordStep'] = 'def syndrome (width word : Nat) : BitVec 24 :=' in source and '(fun i _ rem => wordStep rem (cachedBit word low high (width - 1 - i))) 0' in source and 'List.range' not in source
    checks['no_corpus_keys_or_state_or_new_FFI'] = not re.search(r'IO\.Ref|ST\.Ref|@\[(?:extern|implemented_by)|\b(?:unsafe|partial|axiom|sorry|admit|native_decide)\b|panic!|get!|unreachable!', source)
    step_c = body(c, P + 'Parity_step')
    core_c = body(c, P + 'Parity_wordStep')
    loop_c = body(c, LOOP)
    syndrome_c = body(c, P + 'Parity_syndrome')
    for name, part in [('wordStep', core_c), ('step', step_c), ('loop', loop_c)]:
        checks[name + '_C_has_identical_machine_word_update'] = all(x in part for x in ('lean_uint32_shift_left(', 'lean_uint32_lor(', 'lean_uint32_xor(', 'lean_uint32_land(', '8388608', '33551369', '16777215'))
    checks['loop_C_unboxed_UInt32_state_and_tail_jump'] = 'uint32_t v_a_' in loop_c.split('{', 1)[0] and 'goto _start;' in loop_c and loop_c.count(LOOP + '(') == 1
    checks['loop_C_has_no_range_or_constructor_or_remainder_projection'] = not any(x in loop_c for x in ('List_', 'lean_alloc_', 'lean_box_', 'BitVec_', 'lean_uint32_to_nat', 'lean_nat_mod', 'lean_nat_pow'))
    checks['loop_C_cached_bit_and_arbitrary_Nat_fallback_retained'] = all(x in loop_c for x in ('lean_unsigned_to_nat(64u)', 'lean_unsigned_to_nat(128u)', 'lean_uint64_shift_right(v_high_', 'lean_uint64_shift_right(v_low_', 'l_Nat_testBit('))
    checks['cached_halves_C_constructed_before_one_loop_call'] = syndrome_c.count('lean_uint64_of_nat(') == 2 and syndrome_c.index('v_high_162_ =') < syndrome_c.index(LOOP + '(') and syndrome_c.count(LOOP + '(') == 1 and syndrome_c.count('lean_nat_shiftr(') == 1
    checks['C_projects_UInt32_once_after_loop'] = syndrome_c.count('lean_uint32_to_nat(') == 1 and syndrome_c.count('l_BitVec_ofNat(') == 1 and syndrome_c.index(LOOP + '(') < syndrome_c.index('lean_uint32_to_nat(') < syndrome_c.index('l_BitVec_ofNat(')
    loop_asm = (OUT / ('binary-' + LOOP + '.txt')).read_text()
    loop_calls = calls(loop_asm)
    checks['native_loop_register_update_and_feedback'] = all(x in loop_asm for x in ('lea    (%rdx,%rbx,2),%eax', 'xor    $0xfff409,%edx', 'test   $0x800000,%ebx', 'cmove  %eax,%edx', 'and    $0xffffff,%edx', 'mov    %edx,%ebx'))
    checks['native_loop_inlines_two_cached_bit_extractions'] = loop_asm.count('\tbt ') == 2
    checks['native_loop_retains_Nat_testBit_and_big_index_operations'] = 'l_Nat_testBit' in loop_calls and 'lean_nat_big_sub' in loop_calls
    checks['native_loop_has_no_remainder_conversion_allocation_or_list_calls'] = not any(re.search(r'List_|BitVec_|lean_alloc|lean_box|uint32_to_nat|lean_nat_(?:pow|mod|div)', name) for name in loop_calls)
    cfg = syndrome_cfg((OUT / 'binary-Parity_syndrome.txt').read_text())
    checks['native_syndrome_one_dynamic_loop_despite_two_ownership_callsites'] = cfg['static_loop_calls'] == 2 and all(r['loop_calls'] == 1 for r in cfg['exits'])
    (OUT / 'syndrome-native-cfg.json').write_text(json.dumps(cfg, indent=2) + '\n')
    checks['wordStep_and_step_object_bodies_survive_linker_inlining_elimination'] = all('<' + P + 'Parity_' + n + '>:' in (OUT / ('object-' + n + '.txt')).read_text() and not inspection['requested_binary_symbols'][P + 'Parity_' + n] for n in ('wordStep', 'step'))
    checks['standalone_wordStep_object_is_only_register_arithmetic'] = not calls((OUT / 'object-wordStep.txt').read_text()) and all(x in (OUT / 'object-wordStep.txt').read_text() for x in ('$0xfff409,%eax', '$0x800000,%edi', '$0xffffff,%eax'))
    checks['standalone_step_object_projects_current_core_result'] = all(x in (OUT / 'object-step.txt').read_text() for x in ('l_BitVec_ofNat', '$0x800000,%edi', '$0x1fffffe,%esi'))
    checks['live_decode_keeps_one_shared_syndrome'] = all(calls((OUT / 'binary-decode.txt').read_text()).count(P + n) == 1 for n in ('decodeFrame', 'frameSyndrome', 'reportWithSyndrome'))
    checks['frameSyndrome_checksum_and_syndrome_chain_live'] = P + 'Parity_checksum' in calls((OUT / 'binary-frameSyndrome.txt').read_text()) and P + 'Parity_syndrome' in calls((OUT / 'binary-Parity_checksum.txt').read_text())
    checks['frozen_unit_adapter_reaches_live_syndrome'] = 'Impl.Parity.syndrome (bs.length*8) (word bs)' in (retained / 'Tests/Upstream.lean').read_text()
    checks['frozen_benchmark_calls_complete_live_decode'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3
    checks['score_and_software_gate_paths_retained'] = all(P + n in calls((OUT / 'binary-cbScorePasses.txt').read_text()) for n in ('cbDensityTermsFast', 'cbPenalty', 'ScoreGate_choose')) and calls((OUT / 'binary-ScoreGate_choose.txt').read_text()).count('lean_apply_1') == 1
    old = {r['source']: r for r in json.loads((retained / 'bench/runs/gen10/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/Parity.lean'):
            continue
        before = old[row['source']]
        assert sha(row['source']) == before['source_sha256']
        assert all(sha(row[k]) == before['artifacts'][row[k]]['sha256'] for k in ('c', 'object', 'trace'))
        unchanged.append(row['source'])
    checks['other_19_production_source_C_object_trace_sets_unchanged'] = len(unchanged) == 19
    for p in ('spec.lock', 'lakefile.toml', 'TRUSTED.md'):
        checks[p + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + p]) == (retained / p).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == h for h, p in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/Parity.c.o.export.trace').read_text())
    compiler = next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_remain_O3_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler

    proof_paths = [Path('tests/evidence/optimization/gen11/proof') / n for n in ('summary.json', 'build-11.json', 'build-11.log', 'build-06.json', 'build-06.log')]
    supplementary = {}
    for path in proof_paths:
        destination = retained / path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(path.read_bytes())
        supplementary[str(path)] = {'sha256': sha(path), 'bytes': path.stat().st_size}
    proof_summary = json.loads(proof_paths[0].read_text())
    helper_build = json.loads(proof_paths[1].read_text())
    helper_log = proof_paths[2].read_text()
    checks['final_helper_build_passes_and_matches_stable_sources'] = helper_build['exit_code'] == 0 and helper_build['log_sha256'] == sha(proof_paths[2]) == proof_summary['log_sha256'] and all(sha(p) == h for p, h in proof_summary['sources'].items()) and 'Build completed successfully (2045 jobs).' in helper_log
    helper_facts = [f for f in facts(helper_log) if f['name'].startswith('Lean1090.Proofs.ParityWord.')]
    all_facts = facts(log)
    checks['all_eleven_final_helper_facts_have_only_permitted_axioms'] = len(helper_facts) == 11 and helper_facts == proof_summary['facts'] and all(set(f['axioms']) <= ALLOWED for f in helper_facts)
    checks['all_integrated_printed_facts_have_only_permitted_axioms'] = bool(all_facts) and all(set(f['axioms']) <= ALLOWED for f in all_facts)
    checks['final_proof_symbolic_no_native_reflection_or_placeholders'] = not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)', proof) and all(x in proof for x in ('BitVec.eq_of_getLsbD_eq', 'interval_cases i', 'List.foldl_hom', 'Nat.fold_succ', 'ParityBits.cachedBit_eq'))
    checks['step_theorems_are_unconditional_all_state_and_bit'] = 'theorem wordStep_eq (remainder : UInt32) (bit : Bool) :' in proof and 'theorem step_eq (remainder : BitVec 24) (bit : Bool) :' in proof
    checks['syndrome_theorem_is_unconditional_all_Nat_width_and_word'] = 'theorem syndrome_eq (width word : Nat) :\n    Impl.Parity.syndrome width word = Spec.Parity.syndrome width word := by' in proof
    checks['decoder_refinement_uses_new_universal_proofs'] = all(x in decoder for x in ('import Proofs.ParityWord', 'exact ParityWord.step_eq remainder bit', 'exact ParityWord.syndrome_eq width word')) and any(f['name'] == 'Lean1090.Proofs.Refinement' for f in all_facts)
    rejected = facts(proof_paths[4].read_text())
    checks['rejected_native_reflection_attempt_retained_and_excluded'] = any(set(f['axioms']) - ALLOWED for f in rejected) and 'rejected' in proof_summary['retained_attempt_notes']['06']
    proof_assessment = {
        'status': 'passed', 'findings': [], 'reviewer': '/root/cost_analysis; did not author runtime or proof',
        'sources': {p: sha(p) for p in build['inputs_after']}, 'helper_facts': helper_facts,
        'integrated_allowed_axiom_facts': len(all_facts), 'supplementary_inputs': supplementary,
        'assessment': [
            'wordStep_bits proves each of the 24 output bit positions symbolically for arbitrary 32-bit input and Bool, reducing mask feedback to original bit 23. High incoming bits cannot affect projected output.',
            'wordStep_eq converts the UInt32 operations to BitVec semantics and the frozen polynomial-step characterization. step_eq supplies the public BitVec24 conversion bound; neither adds a state-validity hypothesis.',
            'fold_range inducts on arbitrary Nat length and equates ascending Nat.fold with range.foldl. syndrome_eq applies the existing unconditional cachedBit equality and List.foldl_hom; zero widths, huge words and indices beyond 127 remain covered.',
            'Seven additional kernel-evaluated witnesses cover high input state, feedback, zero width, 56/112-bit frames, the >=128 fallback and overwide words. These supplement the universal proof rather than replace it.',
            'The final proof imports no native-reflection tactic and all eleven printed facts have only permitted axioms. The exploratory build-06 proof had forbidden native axioms, is explicitly rejected, and is not used as evidence of correctness.',
            'Decoder integration changes only proof bodies/import to use the new equalities. Whole-decoder and prefix refinement statements are unchanged and compile with permitted axioms.'
        ],
        'limits': 'Independent source assessment and validation of executed build evidence, not a second build. The kernel and existing trusted compiler/runtime remain the same trust boundary.'
    }
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    (OUT / 'source-proof-review.json').write_text(json.dumps(proof_assessment, indent=2) + '\n')
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    assert all(sha(p) == r['sha256'] for p, r in supplementary.items())
    result = {
        'status': 'passed', 'findings': [], 'checks': checks, 'word_crc_live_path_verified': True,
        'source_proof_review_sha256': sha(OUT / 'source-proof-review.json'),
        'all_captured_inputs_unchanged': True, 'unchanged_native_sources': unchanged,
        'loop_anchor': LOOP, 'source_proof_inputs': supplementary,
        'scope': 'Static inspection of retained source/C/object/linked CLI and existing proof build logs only. No decoder, build, profile, differential or benchmark execution by this reviewer.',
        'limits': [
            'The new per-bit remainder is a UInt32 and no range list, constructor or BitVec projection exists in the loop. Nat index bookkeeping retains arbitrary-precision fallback branches; do not claim absence of every allocation for every mathematical width.',
            'The low/high cached halves are prepared before the loop. The native loop has two bit-test sites and keeps Nat.testBit for indices >=128.',
            'The standalone wordStep and step symbols are absent from the linked CLI but present in the object. Their arithmetic is inlined into the live loop; absence is not zero work.',
            'Two static loop callsites in syndrome are mutually exclusive ownership branches; independent CFG traversal finds exactly one on every normal path, followed by one final BitVec projection.',
            'This is the integrated CLI, not the future freshly built benchmark worker. No timing or throughput claim is made.'
        ],
        'future_diagnostic': 'Rebind the freshly timed worker. Replace the obsolete per-bit step-call expectation with the actual UInt32 loop anchor and retained source proof. Keep shared syndrome/checksum counts, accepted-corpus-only census, complete outputs and all stage/register probes; absent step anchor is inlining, not omitted CRC work.',
        'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ('review.json', 'validate.stdout', 'validate.stderr')}
    }
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'files': len(result['files']), 'source_proof_review_sha256': result['source_proof_review_sha256'], 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
