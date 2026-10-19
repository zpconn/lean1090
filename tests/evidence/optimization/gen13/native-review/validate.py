#!/usr/bin/env python3
"""Independently check retained gen13 proof/native evidence; no decoder execution."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import difflib

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'
WORD = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1'
FALLBACK = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0'
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


def facts(text):
    pattern = r"'([^']+)' (?:depends on axioms:\s*\[([^]]*)\]|does not depend on any axioms)"
    return [{'name': name, 'axioms': sorted(x.strip() for x in ax.split(',') if x.strip())}
            for name, ax in re.findall(pattern, text, re.S)]


def graph(text):
    rows = instructions(text)
    indices = {r['address']: i for i, r in enumerate(rows)}
    edges, exits = {}, {}
    for i, r in enumerate(rows):
        edges[i] = []
        if r['op'] == 'ret':
            exits[i] = 'ret'
            continue
        if r['op'].startswith('j'):
            m = re.match(r'([0-9a-f]+) <([^>]+)>', r['args'])
            assert m, r
            target = int(m[1], 16)
            if target in indices:
                edges[i].append(indices[target])
            else:
                assert r['op'] == 'jmp', r
                exits[i] = m[2]
            if r['op'] == 'jmp':
                continue
        assert i + 1 < len(rows), r
        edges[i].append(i + 1)
    return rows, edges, exits


def counted_paths(text, start, tracked):
    """Count selected external calls on every static normal-exit path."""
    rows, edges, exits = graph(text)
    begin = next(i for i, row in enumerate(rows) if row['address'] == start)
    pending, seen, ended = [(begin, (0,) * len(tracked))], set(), set()
    while pending:
        i, counters = pending.pop()
        if (i, counters) in seen:
            continue
        seen.add((i, counters))
        row = rows[i]
        updated = list(counters)
        if row['op'] == 'call':
            for j, name in enumerate(tracked):
                if '<' + name + '>' in row['args']:
                    updated[j] += 1
        assert max(updated, default=0) <= 2, ('selected call repeated in a loop', row)
        if i in exits:
            ended.add((tuple(updated), exits[i]))
        pending.extend((j, tuple(updated)) for j in edges[i])
    assert ended
    return {'start': hex(start), 'reachable_instruction_count': len({i for i, _ in seen}),
            'tracked': tracked, 'normal_exits': [{'counts': list(c), 'target': t} for c, t in sorted(ended)]}


def event_paths(text, events):
    """Follow all CFG successors and retain selected call/load event sequences."""
    rows, edges, exits = graph(text)
    pending, seen, ended = [(0, ())], set(), set()
    while pending:
        i, sequence = pending.pop()
        if (i, sequence) in seen:
            continue
        seen.add((i, sequence))
        sequence += (events[rows[i]['address']],) if rows[i]['address'] in events else ()
        assert len(sequence) <= 8
        if i in exits:
            ended.add((sequence, exits[i]))
        pending.extend((j, sequence) for j in edges[i])
    return {'instruction_count': len(rows), 'reachable_instructions': len({i for i, _ in seen}),
            'event_sites': {hex(k): v for k, v in events.items()},
            'normal_exits': [{'events': list(s), 'target': t} for s, t in sorted(ended)]}


def main():
    assert not (OUT / 'review.json').exists()
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    assert all((OUT / dest).read_bytes() == Path(p).read_bytes() for p, dest in inspection['retained'].items())
    assert all(r['exit_code'] == 0 and not (OUT / r['stderr']).read_bytes() for r in inspection['commands'])
    retained = OUT / 'retained'
    c = (retained / '.lake/build/ir/Impl/CommB.c').read_text()
    old_c = (retained / 'tests/evidence/diagnostics/gen12/generated-c/Impl/CommB.c').read_text()
    source = (retained / 'Impl/CommB.lean').read_text()
    old_source = (OUT / 'prior-CommB-source.txt').read_text()
    proof = (retained / 'Proofs/CommBPenalty.lean').read_text()
    decoder = (retained / 'Proofs/Decoder.lean').read_text()
    build = inspection['successful_integrated_build']
    logpath = Path(inspection['successful_integrated_build_path']).with_suffix('.log')
    log = (retained / logpath).read_text()
    checks = {}
    checks['integrated_build_passed_3521_jobs'] = build['status'] == 'passed' and build['exit_code'] == 0 and 'Build completed successfully (3521 jobs).' in log and sha(logpath) == build['log_sha256']
    checks['all_three_integrated_source_bindings_match'] = len(build['inputs_after']) == 3 and build['inputs_before'] == build['inputs_after'] and all(sha(p) == h for p, h in build['inputs_after'].items())
    helper_review = json.loads((OUT / 'source-proof-review.json').read_text())
    checks['independent_helper_review_remains_bound'] = helper_review['status'] == 'passed' and not helper_review['findings'] and helper_review['all_Nat_runtime_equality_verified'] and all(sha(p) == r['sha256'] for p, r in helper_review['inputs'].items())
    checks['only_CommB_runtime_source_changed'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/CommB.lean'
    checks['turn_penalty_and_BDS60_suffix_source_unchanged'] = source.split('    match value "roll", value "track_rate" with', 1)[1] == old_source.split('    match value "roll", value "track_rate" with', 1)[1]
    checks['no_new_trust_or_cross_message_state'] = not re.search(r'IO\.Ref|ST\.Ref|@\[(?:extern|implemented_by)|\b(?:unsafe|partial|axiom|sorry|admit|native_decide)\b|panic!|get!|unreachable!', source)

    table = P + 'cbWindPenaltyTable'
    entry, construct, public, penalty = [body(c, n) for n in (table + '___lam__0', '_init_' + table + '___closed__1', P + 'cbWindPenalty50', P + 'cbPenalty')]
    ordered = ['l_Rat_sub(', 'l_Rat_mul(', P + 'Binary64_round(', 'l_Rat_abs(', P + 'Binary64_div(', P + 'Binary64_sub(']
    checks['table_entry_C_retains_ordered_exact_and_rounded_operations'] = all(entry.count(n) == 1 for n in ordered) and [entry.index(n) for n in ordered] == sorted(entry.index(n) for n in ordered)
    checks['table_constructor_covers_all_2047_codes'] = 'lean_unsigned_to_nat(2047u)' in construct and 'l_Array_ofFn___redArg(' in construct and table + '___closed__0' in construct and re.search(r'm_fun\s*=\s*\(void\*\)' + re.escape(table) + '___lam__0', c) is not None
    constants = {'zero': ('cbVertical60___closed__1', 'lean_unsigned_to_nat(0u)'), 'two': ('cbGaussian___closed__1', 'lean_unsigned_to_nat(2u)'), 'bias': ('cbWindPenaltyTable___lam__0___closed__0', 'lean_unsigned_to_nat(1023u)'), 'hundred': ('cbDensityTerms___lam__3___closed__1', 'lean_unsigned_to_nat(100u)')}
    checks['table_entry_constants_match_original_formula'] = all(value in body(c, '_init_' + P + name) for name, value in constants.values())
    checks['lookup_C_has_status_guards_and_four_exact_fields'] = public.count(P + 'payloadBits(') == 4 and all('lean_unsigned_to_nat(' + str(n) + 'u)' in public for n in (46, 24, 1, 47, 25, 10, 1023)) and public.count('lean_nat_dec_eq(') == 2
    checks['lookup_C_only_integer_index_and_immutable_array_read'] = public.count('lean_nat_add(') == 1 and public.count('lean_nat_sub(') == 1 and public.count('lean_array_fget_borrowed(') == 1 and not any(x in public for x in ('Binary64_', 'l_Rat_', 'Array_ofFn', 'lean_array_set'))
    checks['full_table_initialized_and_persisted_in_module_init'] = table + ' = _init_' + table + '();\nlean_mark_persistent(' + table + ');' in c
    main_c = (retained / '.lake/build/ir/CLI/Main.c').read_text()
    json_c = (retained / '.lake/build/ir/Impl/JSON.c').read_text()
    message_c = (retained / '.lake/build/ir/Impl/Message.c').read_text()
    checks['normal_CLI_initialization_reaches_table_before_main'] = main_c.index('res = initialize_lean1090_CLI_Main(1') < main_c.index('res = lean_run_main(') and 'res = initialize_lean1090_Impl_JSON(builtin);' in main_c and 'res = initialize_lean1090_Impl_Message(builtin);' in json_c and 'res = initialize_lean1090_Impl_CommB(builtin);' in message_c

    public_asm = (OUT / 'binary-cbWindPenalty50.txt').read_text()
    rows = instructions(public_asm)
    fields = [r for r in rows if r['op'] == 'call' and '<' + P + 'payloadBits>' in r['args']]
    assert len(fields) == 4
    events = {r['address']: name for r, name in zip(fields, ['status46', 'status24', 'tas47', 'gs25'])}
    loads = [r for r in rows if r['op'] == 'mov' and r['args'].startswith('0x18(%r15,%rcx,4),')]
    assert len(loads) == 1
    events[loads[0]['address']] = 'table_load'
    cfg = event_paths(public_asm, events)
    expected = {('status46',), ('status46', 'status24'), ('status46', 'status24', 'tas47', 'gs25', 'table_load')}
    checks['native_every_normal_exit_has_correct_status_lookup_sequence'] = {tuple(r['events']) for r in cfg['normal_exits']} == expected
    checks['native_field_code_and_integer_index_constants_are_exact'] = all(s in public_asm for s in ('$0x5d,%esi', '$0x31,%esi', '$0x5f,%esi', '$0x33,%esi', '$0x3,%edx', '$0x15,%edx', 'add    $0x3ff,%r14', 'sub    %rsi,%rbx'))
    checks['native_lookup_has_no_software_numeric_operations_or_array_constructor'] = not any('Binary64_' in n or 'Rat_' in n or 'Array_ofFn' in n for n in calls(public_asm))
    entry_asm = (OUT / 'binary-cbWindPenaltyTable___lam__0.txt').read_text()
    operations = [n for n in calls(entry_asm) if n in ['l_Rat_sub', 'l_Rat_mul', P + 'Binary64_round', 'l_Rat_abs', P + 'Binary64_div', P + 'Binary64_sub']]
    checks['native_table_entry_preserves_all_software_rounding'] = operations == [n.removesuffix('(') for n in ordered]
    ctor_asm = (OUT / ('binary-_init_' + table + '___closed__1.txt')).read_text()
    checks['native_table_constructor_uses_tagged_2047_and_full_ofFn'] = '$0xfff,%edi' in ctor_asm and 'l_Array_ofFn___redArg' in calls(ctor_asm)
    init_asm = (OUT / 'binary-initialize_lean1090_Impl_CommB.txt').read_text()
    checks['native_init_stores_table_and_marks_it_persistent'] = '<' + table + '>' in init_asm and '<_init_' + table + '___closed__1>' in init_asm and 'lean_mark_persistent' in calls(init_asm)
    penalty_asm = (OUT / 'binary-cbPenalty.txt').read_text()
    checks['actual_cbPenalty_calls_live_lookup_once_at_BDS50_site'] = calls(penalty_asm).count(P + 'cbWindPenalty50') == 1 and penalty.count(P + 'cbWindPenalty50(') == 1
    checks['turn_subtraction_and_BDS60_division_remain_native'] = P + 'Binary64_sub' in calls(penalty_asm) and P + 'Binary64_div' in calls(penalty_asm) and P + 'cbMachValueTable' in penalty_asm
    checks['fast_and_full_score_paths_call_same_live_penalty'] = all(calls((OUT / f).read_text()).count(P + 'cbPenalty') == 1 for f in ('binary-cbScorePasses.txt', 'binary-cbScorePasses___lam__0___boxed.txt'))
    checks['score_fallback_remains_conditional_full_software_path'] = calls((OUT / 'binary-ScoreGate_choose.txt').read_text()).count('lean_apply_1') == 1 and all(P + n in calls((OUT / 'binary-cbScorePasses___lam__0___boxed.txt').read_text()) for n in ('cbDensity', 'cbPenalty', 'Binary64_add'))
    checks['decode_still_uses_public_frame_single_syndrome_complete_report'] = all(calls((OUT / 'binary-decode.txt').read_text()).count(P + n) == 1 for n in ('decodeFrame', 'frameSyndrome', 'reportWithSyndrome'))
    checks['frozen_adapters_still_call_live_public_entrypoints'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3 and 'Impl.decodeBDS' in (retained / 'Tests/CommBDifferential.lean').read_text() and 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    cfg['limits'] = 'Static CFG traversal follows both unknown branch successors and treats external calls as returning. It verifies direct field/load event sequences, not measured frequencies. Existing reference counting and generic Nat representation paths remain. Missing statuses may initialize the existing scalar zero; no table is initialized during lookup.'
    (OUT / 'wind-native-cfg.json').write_text(json.dumps(cfg, indent=2) + '\n')

    prior = {r['source']: r for r in json.loads((retained / 'bench/runs/gen12/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/CommB.lean'):
            continue
        old = prior[row['source']]
        assert sha(row['source']) == old['source_sha256']
        assert all(sha(row[k]) == old['artifacts'][row[k]]['sha256'] for k in ('c', 'object', 'trace'))
        unchanged.append(row['source'])
    checks['other_19_native_source_C_object_trace_sets_unchanged'] = len(unchanged) == 19
    normalize = lambda s: re.sub(r'(?<=_)\d+(?=_)', 'N', s)
    protected = ('cbValid50', 'cbValid60', 'cbDensityTerms', 'cbDensityTermsFast', 'cbCombinedScore', 'cbScorePasses', 'commBCoreEligible', 'cbQNH64', 'cbMach64')
    checks['other_live_CommB_C_functions_unchanged_modulo_local_numbers'] = all(normalize(body(c, P + n)) == normalize(body(old_c, P + n)) for n in protected)
    for path in ('spec.lock', 'lakefile.toml', 'TRUSTED.md'):
        checks[path + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + path]) == (retained / path).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == h for h, p in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/CommB.c.o.export.trace').read_text())
    compiler = next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_remain_O3_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler
    integrated_facts = facts(log)
    checks['all_136_integrated_printed_facts_have_only_permitted_axioms'] = len(integrated_facts) == 136 and all(set(f['axioms']) <= ALLOWED for f in integrated_facts)
    checks['Decoder_uses_unconditional_new_helper_and_preserves_refinement'] = 'import Proofs.CommBPenalty' in decoder and 'simp only [CommBPenalty.cbWindPenalty50_eq_runtime,' in decoder and 'private theorem decoder_cbPenalty_eq : @Impl.cbPenalty = @Spec.cbPenalty := by\n  funext register word\n  unfold Impl.cbPenalty Spec.cbPenalty\n  split <;>' in decoder and any(f['name'] == 'Lean1090.Proofs.Refinement' for f in integrated_facts)
    checks['new_helper_proof_is_unconditional_and_contains_no_native_reflection'] = 'theorem cbWindPenalty50_eq_runtime (word : Nat) :' in proof and not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)', proof)
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    integration = {'status': 'passed', 'findings': [], 'reviewer': '/root/cost_analysis; independent of runtime/helper/integration authors', 'sources': build['inputs_after'], 'source_proof_review_sha256': sha(OUT / 'source-proof-review.json'), 'integrated_build_path': inspection['successful_integrated_build_path'], 'integrated_build_sha256': sha(inspection['successful_integrated_build_path']), 'integrated_log_sha256': sha(logpath), 'integrated_allowed_axiom_facts': len(integrated_facts), 'integrated_facts': integrated_facts, 'assessment': 'Decoder imports the new universal equality and splits the existing register branch before rewriting. It adds no hypothesis to cbPenalty equality or whole-decoder refinement. All three stable sources match the successful integrated build; every printed fact has permitted axioms only.', 'limits': 'Review of retained build evidence and mathematical source; no independent build or native execution.'}
    (OUT / 'integration-proof-review.json').write_text(json.dumps(integration, indent=2) + '\n')
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    result = {'status': 'passed', 'findings': [], 'checks': checks, 'bds50_wind_penalty_live_path_verified': True,
        'source_proof_review_sha256': sha(OUT / 'source-proof-review.json'), 'integration_proof_review_sha256': sha(OUT / 'integration-proof-review.json'),
        'all_captured_inputs_unchanged': True, 'unchanged_native_sources': unchanged,
        'scope': 'Static source/C/object/linked CLI inspection and existing proof build records only. No build, decoder, profile, test suite or benchmark execution by this reviewer.',
        'limits': ['This is the integrated CLI, not the future freshly built timed worker. No performance claim is made.', 'The exact 2,047-entry immutable table is eagerly created and marked persistent during module initialization. Entry construction retains software rounding, absolute value, division and subtraction. Per-message lookup has no corresponding software arithmetic.', 'The original turn penalty can still call software subtraction; BDS60 retains software division. Both score gate and lazy full-model fallback call the live cbPenalty. This change does not eliminate all software Binary64 work.', 'Status-zero lookup paths may lazily initialize an existing scalar zero constant. Generic Nat representation and reference-counting branches remain. Missing/inlined symbols elsewhere are not interpreted as zero work.'],
        'future_diagnostic': 'Bind the newly timed worker and retain cbWindPenalty50, cbPenalty and candidate/score roots. Attribute startup table construction separately from per-message lookup; nested helper costs overlap.',
        'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ('review.json', 'validate.stdout', 'validate.stderr')}}
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'files': len(result['files']), 'source_proof_review_sha256': result['source_proof_review_sha256'], 'integration_proof_review_sha256': result['integration_proof_review_sha256'], 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()


