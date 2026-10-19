#!/usr/bin/env python3
"""Validate retained gen10 compiled QNH paths without executing decoder code."""
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


def calls(text):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', text)


def lookup_path(text):
    """Retain the actual straight-line table/address/index-load sequence."""
    rows = []
    for line in text.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            rows.append({'address': '0x' + match[1], 'op': match[2], 'args': match[3]})
    start = next(i for i, r in enumerate(rows) if '<' + P + 'cbQNHValueTable>' in r['args'])
    end = next(i for i in range(start + 1, len(rows)) if rows[i]['op'] == 'mov'
               and re.match(r'0x18\([^\n]+,4\),', rows[i]['args']))
    path = rows[start:end + 1]
    assert sum(r['op'] == 'call' and '<' + P + 'payloadBits>' in r['args'] for r in path) == 1
    assert any(r['args'] == '$0x39,%esi' for r in path)
    assert any(r['args'] == '$0x19,%edx' for r in path)
    assert not any(r['op'].startswith('j') or 'Binary64_' in r['args'] or 'lean_obj_once' in r['args'] for r in path)
    return path


def main():
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert not (OUT / 'review.json').exists()
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    retained = OUT / 'retained'
    c = (retained / '.lake/build/ir/Impl/CommB.c').read_text()
    source = (retained / 'Impl/CommB.lean').read_text()
    old_source = (OUT / 'prior-CommB-source.txt').read_text()
    log = (retained / inspection['successful_integrated_build_path']).with_suffix('.log').read_text()
    checks = {}
    checks['integrated_build_passed_3515_jobs'] = 'Build completed successfully (3515 jobs).' in log
    build = inspection['successful_integrated_build']
    checks['all_four_integrated_source_bindings_match'] = build['inputs_before'] == build['inputs_after'] and all(sha(p) == h for p, h in build['inputs_after'].items()) and len(build['inputs_after']) == 4
    checks['only_CommB_runtime_source_changed'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/CommB.lean'
    prefix, suffix = '-- Initial algorithm: Spec/CommB.lean:48.', '-- Initial algorithm: Spec/CommB.lean:53.'
    checks['all_other_CommB_source_bytes_unchanged'] = source.split(prefix)[0] == old_source.split(prefix)[0] and source.split(suffix, 1)[1] == old_source.split(suffix, 1)[1]
    checks['immutable_table_is_complete_and_field_code_only'] = 'def cbQNHValueTable : Array Rat := Array.ofFn fun code : Fin 4096 =>\n  Binary64.add (Binary64.mul (code.val : Rat)\n    (Binary64.literal (1 / 10))) 800' in source
    checks['lookup_has_unconditional_all_word_bound_proof'] = "cbQNHValueTable[payloadBits word 28 12]'(by\n    simpa only [cbQNHValueTable, Array.size_ofFn] using payloadBits_lt word 28 12)" in source
    entry = body(c, P + 'cbQNHValueTable___lam__0')
    table = body(c, '_init_' + P + 'cbQNHValueTable___closed__1')
    lookup = body(c, P + 'cbQNH64')
    initializer = body(c, 'initialize_lean1090_Impl_CommB')
    checks['C_constructor_has_4096_entries_and_exact_entry_closure'] = all(x in table for x in ('lean_unsigned_to_nat(4096u)', 'l_Array_ofFn___redArg(', P + 'cbQNHValueTable___closed__0')) and '.m_fun = (void*)' + P + 'cbQNHValueTable___lam__0' in c
    checks['C_entry_preserves_mul_then_add'] = entry.count(P + 'Binary64_mul(') == entry.count(P + 'Binary64_add(') == 1 and entry.index(P + 'Binary64_mul(') < entry.index(P + 'Binary64_add(')
    checks['C_literal_has_original_rational_1_over_10_then_software_round'] = all('lean_unsigned_to_nat(' + n + 'u)' in body(c, '_init_' + P + 'cbQNHValueTable___lam__0___closed__' + i) for n, i in [('1', '0'), ('10', '1'), ('800', '4')]) and 'l_Rat_div(' in body(c, '_init_' + P + 'cbQNHValueTable___lam__0___closed__2') and P + 'Binary64_round(' in body(c, '_init_' + P + 'cbQNHValueTable___lam__0___closed__3')
    checks['C_lookup_is_field_28_width_12_then_borrowed_array_load'] = all(x in lookup for x in (P + 'cbQNHValueTable;', 'lean_unsigned_to_nat(28u)', 'lean_unsigned_to_nat(12u)', P + 'payloadBits(', 'lean_array_fget_borrowed(')) and lookup.index(P + 'payloadBits(') < lookup.index('lean_array_fget_borrowed(')
    checks['lookup_has_no_software_math_or_initialization'] = not any(x in lookup for x in ('Binary64_', 'l_Rat_', 'lean_obj_once', 'Array_ofFn'))
    assignment = P + 'cbQNHValueTable = _init_' + P + 'cbQNHValueTable();'
    persistent = 'lean_mark_persistent(' + P + 'cbQNHValueTable);'
    checks['eager_module_assignment_then_persistent_marker'] = assignment in initializer and persistent in initializer and initializer.index(assignment) < initializer.index(persistent)
    checks['QNH_table_has_one_global_assignment_no_runtime_write'] = c.count(P + 'cbQNHValueTable =') == 1
    cli = (retained / '.lake/build/ir/CLI/Main.c').read_text()
    json_c = (retained / '.lake/build/ir/Impl/JSON.c').read_text()
    message_c = (retained / '.lake/build/ir/Impl/Message.c').read_text()
    checks['CLI_initialization_reaches_CommB_before_main_loop'] = body(cli, 'main').index('initialize_lean1090_CLI_Main(') < body(cli, 'main').index('lean_run_main(') and 'initialize_lean1090_Impl_JSON(' in body(cli, 'initialize_lean1090_CLI_Main') and 'initialize_lean1090_Impl_Message(' in body(json_c, 'initialize_lean1090_Impl_JSON') and 'initialize_lean1090_Impl_CommB(' in body(message_c, 'initialize_lean1090_Impl_Message')
    for caller in ('cbValid40', 'cbDensityTerms'):
        checks[caller + '_C_calls_live_QNH_lookup'] = P + 'cbQNH64(' in body(c, P + caller)
    checks['accepted_decodeBDS_recheck_uses_current_validity'] = P + 'bdsWireValid(' in body(c, P + 'decodeBDS') and P + 'cbValid40(' in body(c, P + 'bdsWireValid')
    checks['candidate_inference_calls_current_validity_and_score'] = all(P + x in calls((OUT / 'binary-commBCoreEligible.txt').read_text()) for x in ('bdsWireValid', 'cbScorePasses'))
    obj = (OUT / 'object-cbQNH64.txt').read_text()
    native_obj = re.search(r'<' + P + r'cbQNH64>:\n(.*?)(?:\nDisassembly|\Z)', obj, re.S)[1]
    checks['object_lookup_is_field_extraction_and_indexed_load'] = all(x in native_obj for x in (P + 'cbQNHValueTable', P + 'payloadBits', '$0x39,%esi', '$0x19,%edx', '0x18(%rbx,%rax,4)')) and 'Binary64_' not in native_obj
    checks['standalone_lookup_is_inlined_from_linked_CLI'] = not inspection['requested_binary_symbols'][P + 'cbQNH64'] and '<' + P + 'cbQNH64>:' in obj
    paths = {name: lookup_path((OUT / ('binary-' + name + '.txt')).read_text()) for name in ('cbValid40', 'cbDensityTerms')}
    (OUT / 'qnh-native-paths.json').write_text(json.dumps({
        'kind': 'actual_inlined_QNH_lookup_sequences', 'paths': paths,
        'tagged_constants': {'field_start_28': '0x39', 'field_width_12': '0x19', 'table_size_4096': '0x2001'},
        'limits': 'Static straight-line native sequences from the QNH table address load through its indexed entry load. Caller conditions and other arithmetic remain live; no runtime counts or timing are inferred.',
    }, indent=2) + '\n')
    checks['both_native_callers_inline_actual_field_code_lookup'] = len(paths) == 2
    checks['native_constructor_passes_tagged_4096_to_Array_ofFn'] = '$0x2001,%edi' in (OUT / 'binary-table-constructor.txt').read_text() and 'l_Array_ofFn___redArg' in calls((OUT / 'binary-table-constructor.txt').read_text())
    entry_calls = calls((OUT / 'binary-cbQNHValueTable___lam__0.txt').read_text())
    checks['native_entry_preserves_mul_before_add'] = P + 'Binary64_mul' in entry_calls and P + 'Binary64_add' in entry_calls and entry_calls.index(P + 'Binary64_mul') < entry_calls.index(P + 'Binary64_add')
    checks['native_literal_uses_full_software_round'] = P + 'Binary64_round' in calls((OUT / 'binary-literal-round.txt').read_text())
    init_asm = (OUT / 'binary-initialize_lean1090_Impl_CommB.txt').read_text()
    checks['native_initializer_links_QNH_constructor_and_persistent_table'] = all(x in init_asm for x in ('<' + P + 'cbQNHValueTable>', '<_init_' + P + 'cbQNHValueTable___closed__1>', '<lean_mark_persistent>'))
    checks['current_decode_retains_single_shared_CRC'] = all(calls((OUT / 'binary-decode.txt').read_text()).count(P + x) == 1 for x in ('decodeFrame', 'frameSyndrome', 'reportWithSyndrome'))
    score_calls = calls((OUT / 'binary-cbScorePasses.txt').read_text())
    checks['score_keeps_fast_density_penalty_and_integer_gate'] = all(P + x in score_calls for x in ('cbDensityTermsFast', 'cbPenalty', 'ScoreGate_choose'))
    gate_calls = calls((OUT / 'binary-ScoreGate_choose.txt').read_text())
    checks['integer_gate_retains_one_conditional_lazy_callback'] = gate_calls.count('lean_apply_1') == 1 and P + 'ScoreGate_commonDenominator' in gate_calls
    fallback = calls((OUT / 'binary-cbScorePasses___lam__0___boxed.txt').read_text())
    checks['full_software_fallback_retains_current_density_penalty_add_comparison'] = all(x in fallback for x in (P + 'cbDensity', P + 'cbPenalty', P + 'Binary64_add', 'l_Rat_instDecidableLe'))
    checks['fallback_density_reaches_current_density_terms'] = P + 'cbDensityTerms' in calls((OUT / 'binary-cbDensity.txt').read_text())
    checks['frozen_direct_adapter_calls_live_public_paths'] = all(x in (retained / 'Tests/CommBDifferential.lean').read_text() for x in ('Impl.decodeBDS', 'Impl.Semantics.commB'))
    checks['frozen_whole_message_adapter_calls_live_decode'] = 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    checks['frozen_benchmark_keeps_complete_decode_calls'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3
    proof = (retained / 'Proofs/CommBQNH.lean').read_text()
    checks['all_word_QNH_equality_has_no_validity_or_corpus_hypothesis'] = 'theorem cbQNH64_eq (word : Nat) : Impl.cbQNH64 word = Spec.cbQNH64 word := by' in proof
    names = ('table_size', 'table_get', 'cbQNH64_eq_runtime', 'cbQNH64_eq', 'zero_witness', 'fractional_witness', 'plausibility_boundary_witness', 'maximal_witness', 'maximal_wide_witness')
    checks['nine_table_facts_and_witnesses_checked_by_integrated_build'] = all("Lean1090.Proofs.CommBQNH." + n + "' depends on axioms:" in log for n in names)
    decoder = (retained / 'Proofs/Decoder.lean').read_text()
    checks['complete_refinement_uses_universal_QNH_equality'] = 'import Proofs.CommBQNH' in decoder and 'exact CommBQNH.cbQNH64_eq word' in decoder and "'Lean1090.Proofs.Refinement' depends on axioms: [propext, Classical.choice, Quot.sound]" in log
    prior = {r['source']: r for r in json.loads((retained / 'bench/runs/gen9/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/CommB.lean'):
            continue
        old = prior[row['source']]
        assert sha(row['source']) == old['source_sha256']
        assert all(sha(row[k]) == old['artifacts'][row[k]]['sha256'] for k in ('c', 'object', 'trace'))
        unchanged.append(row['source'])
    checks['other_19_production_source_C_object_trace_sets_equal_gen9'] = len(unchanged) == 19
    checks['unchanged_parity_field_payload_semantics_integer_and_software_modules_included'] = all(s in unchanged for s in ('Impl/Parity.lean', 'Impl/Bits.lean', 'Impl/PayloadBits.lean', 'Impl/Message.lean', 'Impl/Semantics.lean', 'Impl/ScoreGate.lean', 'Impl/Binary64.lean'))
    diff = (OUT / 'runtime-diff.txt').read_text()
    checks['no_new_FFI_or_mutable_cache'] = not any(x in diff for x in ('@[extern', '@[implemented_by', 'IO.Ref', 'ST.Ref', 'initialize '))
    for name in ('TRUSTED.md', 'lakefile.toml', 'spec.lock'):
        checks[name + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + name]) == (retained / name).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == h for h, p in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/CommB.c.o.export.trace').read_text())
    compiler = next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_keep_O3_and_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    result = {'status': 'passed', 'checks': checks, 'qnh_table_live_path_verified': True,
              'all_captured_inputs_unchanged': True, 'unchanged_native_sources': unchanged,
              'native_cbQNH64_symbol_inlined': True,
              'scope': 'Static inspection of already-built source/C/object/linked CLI only. No build, decoder, profile, differential suite or benchmark execution.',
              'future_diagnostic': 'Bind the freshly timed worker again. An absent standalone cbQNH64 symbol means inlining, not zero QNH computation. Observe caller stages and register probes, retain actual table loads and distinguish eager table startup from decode costs.',
              'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name != 'review.json'}}
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
