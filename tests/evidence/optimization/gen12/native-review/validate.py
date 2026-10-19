#!/usr/bin/env python3
"""Independently check retained gen12 proof/native evidence; no decoder execution."""
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


def main():
    assert not (OUT / 'review.json').exists()
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    assert all((OUT / dest).read_bytes() == Path(p).read_bytes() for p, dest in inspection['retained'].items())
    assert all(r['exit_code'] == 0 and (OUT / r['stderr']).read_bytes() == b'' for r in inspection['commands'])
    retained = OUT / 'retained'
    c = (retained / '.lake/build/ir/Impl/Bits.c').read_text()
    old_c = (retained / 'tests/evidence/diagnostics/gen11/generated-c/Impl/Bits.c').read_text()
    source = (retained / 'Impl/Bits.lean').read_text()
    old_source = (OUT / 'prior-Bits-source.txt').read_text()
    proof = (retained / 'Proofs/ByteWords.lean').read_text()
    decoder = (retained / 'Proofs/Decoder.lean').read_text()
    build = inspection['successful_integrated_build']
    log = (retained / inspection['successful_integrated_build_path']).with_suffix('.log').read_text()
    checks = {}
    checks['integrated_build_passed_3520_jobs'] = 'Build completed successfully (3520 jobs).' in log
    checks['all_three_integrated_source_bindings_match'] = len(build['inputs_after']) == 3 and build['inputs_before'] == build['inputs_after'] and all(sha(p) == h for p, h in build['inputs_after'].items())
    checks['only_Bits_runtime_source_changed'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/Bits.lean'
    marker = '-- Initial algorithm: Spec/Bits.lean:17.'
    checks['field_packFields_frameBytes_source_unchanged'] = source.split(marker, 1)[1] == old_source.split(marker, 1)[1]
    checks['length_guards_are_8_and_16_with_original_unbounded_fallback'] = all(x in source for x in ('let count := bytes.length', 'if count ≤ 8 then', 'else if count ≤ 16 then', 'bytes.foldl (fun n b => 256 * n + b.toNat) 0'))
    checks['prefix_recursion_returns_directly_without_pair_per_byte'] = '| count + 1, byte :: rest, word =>\n      bytesWordPrefix count rest (256 * word + byte.toUInt64)' in source
    checks['no_new_trust_or_message_cache'] = not re.search(r'IO\.Ref|ST\.Ref|@\[(?:extern|implemented_by)|\b(?:unsafe|partial|axiom|sorry|admit|native_decide)\b|panic!|get!|unreachable!', source)
    prefix_c = body(c, P + 'bytesWordPrefix')
    fold_c, fallback_c, public_c = body(c, WORD), body(c, FALLBACK), body(c, P + 'bytesValue')
    checks['word_fold_C_is_unboxed_shift_add_tail_loop'] = all(x in fold_c for x in ('uint64_t', 'lean_uint64_shift_left(', 'lean_uint64_add(', 'goto _start;')) and not any(x in fold_c for x in ('lean_alloc_', 'lean_box_', 'lean_nat_', 'to_nat', 'List_take', 'List_drop'))
    recursive_c = prefix_c[prefix_c.index('v_head_33_ ='):]
    checks['prefix_recursive_C_has_no_pair_allocation_or_Nat_word_conversion'] = 'goto _start;' in recursive_c and not any(x in recursive_c for x in ('lean_alloc_', 'lean_box_', 'lean_uint64_to_nat', 'return '))
    checks['prefix_endpoint_C_boxes_once_and_returns_original_suffix'] = prefix_c.count('lean_alloc_ctor(0, 2, 0)') == 2 and prefix_c.count('lean_box_uint64(') == 2 and prefix_c.count('1, v_x_25_);') == 2 and not any(x in prefix_c for x in ('List_take', 'List_drop', 'List_reverse'))
    checks['public_C_calls_prefix_once_and_one_word_fold_per_bounded_branch'] = public_c.count(P + 'bytesWordPrefix(') == 1 and public_c.count(WORD + '(') == 2 and public_c.count(FALLBACK + '(') == 1
    checks['two_word_combination_occurs_once_after_prefix'] = public_c.count('lean_nat_shiftl(') == 1 and public_c.count('lean_nat_add(') == 1 and public_c.index(P + 'bytesWordPrefix(') < public_c.index('lean_nat_shiftl(') < public_c.index('lean_nat_add(')
    checks['C_original_fallback_retains_Nat_multiply_add'] = all(x in fallback_c for x in ('lean_unsigned_to_nat(256u)', 'lean_nat_mul(', 'lean_nat_add(', 'goto _start;'))
    normalize = lambda s: re.sub(r'(?<=_)\d+(?=_)', 'N', s)
    checks['other_Bits_C_bodies_unchanged_modulo_local_identifier_numbers'] = all(normalize(body(c, P + n)) == normalize(body(old_c, P + n)) for n in ('field', 'packFields', 'frameBytes'))

    prefix_asm = (OUT / 'binary-bytesWordPrefix.txt').read_text()
    prefix_rows, _, _ = graph(prefix_asm)
    prefix_paths = counted_paths(prefix_asm, prefix_rows[0]['address'], ['lean_alloc_small_object_core'])
    checks['every_prefix_native_exit_allocates_only_endpoint_box_and_pair'] = all(row['counts'] == [2] and row['target'] == 'ret' for row in prefix_paths['normal_exits'])
    checks['native_prefix_update_is_shift_and_byte_or'] = all(x in prefix_asm for x in ('shl    $0x8,%rbx', 'movzbl %r15b,%eax', 'or     %rax,%rbx'))
    checks['native_prefix_is_loop_not_recursive_call'] = P + 'bytesWordPrefix' not in calls(prefix_asm)
    public_asm = (OUT / 'binary-bytesValue.txt').read_text()
    rows = instructions(public_asm)
    starts = {}
    for label, constant in [('short', '$0x11,%rax'), ('medium', '$0x21,%rax')]:
        i = next(i for i, row in enumerate(rows) if row['op'] == 'cmp' and row['args'] == constant)
        assert rows[i + 1]['op'] == 'jbe'
        starts[label] = int(rows[i + 1]['args'].split()[0], 16)
        if label == 'medium':
            starts['long'] = rows[i + 2]['address']
    tracked = [P + 'bytesWordPrefix', FALLBACK, 'lean_nat_shiftl']
    branches = {name: counted_paths(public_asm, start, tracked) for name, start in starts.items()}
    expected = {'short': [0, 0, 0], 'medium': [1, 0, 1], 'long': [0, 1, 0]}
    checks['native_guards_route_to_exact_short_medium_long_calls'] = all(all(row['counts'] == expected[name] for row in result['normal_exits']) for name, result in branches.items())
    native_symbols = {line.split()[-1] for line in (OUT / 'binary-symbols.txt').read_text().splitlines() if line.split()}
    object_symbols = {line.split()[-1] for line in (OUT / 'object-symbols.txt').read_text().splitlines() if line.split()}
    checks['native_public_word_folds_are_inlined_shift_or_loops'] = sum(row['op'] == 'shl' and row['args'].startswith('$0x8,') for row in rows) == 2 and WORD not in native_symbols and WORD in object_symbols
    checks['native_fallback_boundary_retains_arbitrary_precision_arithmetic'] = all(x in (OUT / ('binary-' + FALLBACK + '.txt')).read_text() for x in ('lean_nat_big_mul', 'lean_nat_big_add'))
    (OUT / 'byte-native-cfg.json').write_text(json.dumps({'prefix': prefix_paths, 'public_branches': branches,
        'tagged_length_constants': {'8': '0x11', '16': '0x21'},
        'limits': 'Static normal-return CFG traversal treats calls as returning and follows both unknown branch successors. It proves selected direct call counts per path, not runtime frequency or absence of allocations inside arbitrary-Nat/ownership callees. UInt64 folds inline into the public function.'}, indent=2) + '\n')
    checks['actual_decodeFrame_calls_public_bytesValue'] = P + 'bytesValue' in calls((OUT / 'binary-decodeFrame.txt').read_text())
    checks['live_decode_keeps_shared_CRC_and_complete_report'] = all(calls((OUT / 'binary-decode.txt').read_text()).count(P + n) == 1 for n in ('decodeFrame', 'frameSyndrome', 'reportWithSyndrome'))
    checks['score_and_lazy_software_fallback_boundaries_remain'] = all(P + n in calls((OUT / 'binary-cbScorePasses.txt').read_text()) for n in ('cbDensityTermsFast', 'cbPenalty', 'ScoreGate_choose')) and calls((OUT / 'binary-ScoreGate_choose.txt').read_text()).count('lean_apply_1') == 1
    checks['frozen_benchmark_and_units_use_live_entrypoints'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3 and 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    prior = {r['source']: r for r in json.loads((retained / 'bench/runs/gen11/fresh-native-inputs.json').read_text())}
    unchanged, ownership_changes = [], []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/Bits.lean'):
            continue
        old = prior[row['source']]
        assert sha(row['source']) == old['source_sha256']
        if row['source'] in ('Impl/Frame.lean', 'Impl/Message.lean'):
            ownership_changes.append(row['source'])
            continue
        assert all(sha(row[k]) == old['artifacts'][row[k]]['sha256'] for k in ('c', 'object', 'trace'))
        unchanged.append(row['source'])
    checks['other_17_production_source_C_object_trace_sets_unchanged'] = len(unchanged) == 17
    checks['Frame_and_Message_sources_unchanged_with_native_ownership_changes'] = ownership_changes == ['Impl/Frame.lean', 'Impl/Message.lean']
    ownership_report = {}
    for name, removed, changed in [('Frame', 'decodeFrame___boxed', 'decodeFrame'), ('Message', 'decode___boxed', 'decodePrefix')]:
        old_path = Path(f'tests/evidence/diagnostics/gen11/generated-c/Impl/{name}.c')
        assert sha(old_path) == prior[f'Impl/{name}.lean']['artifacts'][f'.lake/build/ir/Impl/{name}.c']['sha256']
        old = (retained / old_path).read_text()
        new = (retained / f'.lake/build/ir/Impl/{name}.c').read_text()
        symbols = lambda text: set(re.findall(r'^(?:LEAN_EXPORT )?(?:lean_object\*|uint\d+_t|void|size_t)\s+(\w+)\([^;\n{}]*\)\{', text, re.M))
        old_symbols, new_symbols = symbols(old), symbols(new)
        assert old_symbols - new_symbols == {P + removed} and not new_symbols - old_symbols
        deltas = {}
        for symbol in sorted(new_symbols):
            a, b = normalize(body(old, symbol)), normalize(body(new, symbol))
            if a != b:
                deltas[symbol] = ''.join(difflib.unified_diff(a.splitlines(True), b.splitlines(True), fromfile='gen11 normalized C', tofile='gen12 normalized C'))
                if name == 'Frame':
                    assert b.count('lean_dec(v_bytes_N_);\n') == 2
                    assert a == b.replace('lean_dec(v_bytes_N_);\n', '')
                else:
                    boundary = '= lp_lean1090_Lean1090_Impl_decode(v___x_N_);\n'
                    assert a.count(boundary + 'lean_dec(v___x_N_);\n') == 1
                    assert b == a.replace(boundary + 'lean_dec(v___x_N_);\n', boundary)
        assert set(deltas) == {P + changed}
        removed_body = normalize(body(old, P + removed))
        assert 'lean_dec(v_bytes_N_);' in removed_body and P + removed.removesuffix('___boxed') + '(v_bytes_N_);' in removed_body
        ownership_report[name] = {'old_source_sha256': prior[f'Impl/{name}.lean']['source_sha256'], 'old_c_sha256': sha(old_path), 'new_c_sha256': sha(retained / f'.lake/build/ir/Impl/{name}.c'), 'removed_wrapper': P + removed, 'common_body_deltas_modulo_generated_local_numbers': deltas}
    (OUT / 'dependent-native-ownership.json').write_text(json.dumps(ownership_report, indent=2) + '\n')
    checks['dependent_C_changes_are_exact_list_ownership_transfer_only'] = True
    for path in ('spec.lock', 'lakefile.toml', 'TRUSTED.md'):
        checks[path + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + path]) == (retained / path).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == h for h, p in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/Bits.c.o.export.trace').read_text())
    compiler = next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_remain_O3_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler
    proof_paths = [Path('tests/evidence/optimization/gen12/proof') / n for n in ('summary.json', 'build-02.json', 'build-02.log', 'build-01.json', 'build-01.log')]
    supplementary = {}
    for path in proof_paths:
        destination = retained / path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(path.read_bytes())
        supplementary[str(path)] = {'sha256': sha(path), 'bytes': path.stat().st_size}
    summary, helper = (json.loads(p.read_text()) for p in proof_paths[:2])
    checks['helper_passed_2042_jobs_with_exact_source_and_log_binding'] = helper['exit_code'] == 0 and helper['source_sha256_before'] == helper['source_sha256_after'] == summary['source_sha256'] and all(sha(p) == h for p, h in summary['source_sha256'].items()) and sha(proof_paths[2]) == helper['log_sha256'] == summary['final_build_log_sha256'] and 'Build completed successfully (2042 jobs).' in proof_paths[2].read_text()
    helper_facts = [f for f in facts(proof_paths[2].read_text()) if f['name'].startswith('Lean1090.Proofs.ByteWords.')]
    expected_facts = [{'name': f['name'], 'axioms': sorted(f['axioms'])} for f in summary['axiom_checks']]
    integrated_facts = facts(log)
    checks['all_eleven_helper_facts_have_only_permitted_axioms'] = len(helper_facts) == 11 and helper_facts == expected_facts and all(set(f['axioms']) <= ALLOWED for f in helper_facts)
    checks['all_integrated_printed_facts_have_only_permitted_axioms'] = bool(integrated_facts) and all(set(f['axioms']) <= ALLOWED for f in integrated_facts)
    checks['final_proof_has_no_placeholders_or_native_reflection'] = not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)', proof)
    checks['modular_word_and_prefix_theorems_are_unrestricted'] = 'theorem bytesWord_eq (bytes : List UInt8) :' in proof and 'theorem bytesWordPrefix_eq (count : Nat) (bytes : List UInt8) (initial : UInt64) :' in proof and 'List.foldl_hom UInt64.ofNat' in proof
    checks['public_refinement_has_no_length_or_validity_hypothesis'] = 'theorem bytesValue_eq (bytes : List UInt8) :\n    Impl.bytesValue bytes = Spec.bytesValue bytes := by' in proof
    checks['bounds_and_radix_composition_use_existing_reference_facts'] = all(x in proof for x in ('WireBytes.bytesValue_lt bytes', 'Nat.mod_eq_of_lt', 'List.take_append_drop', '← WireBytes.byte_radix'))
    checks['decoder_refinement_uses_new_universal_theorem'] = 'import Proofs.ByteWords' in decoder and 'exact ByteWords.bytesValue_eq bytes' in decoder and any(f['name'] == 'Lean1090.Proofs.Refinement' for f in integrated_facts)
    checks['failed_first_elaboration_is_retained_not_counted_as_proof'] = json.loads(proof_paths[3].read_text())['exit_code'] == 1 and summary['attempts'][0]['exit_code'] == 1
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    proof_review = {
        'status': 'passed', 'findings': [], 'reviewer': '/root/cost_analysis; did not author runtime or proof',
        'sources': {p: sha(p) for p in build['inputs_after']}, 'helper_facts': helper_facts,
        'integrated_allowed_axiom_facts': len(integrated_facts), 'supplementary_inputs': supplementary,
        'assessment': [
            'fold_word proves the UInt64 cast is a fold homomorphism for arbitrary lists and initial naturals; it does not assume that intermediate values fit.',
            'bytesWord_toNat discharges the modulus only under length <=8, using the independently proved Spec byte bound and 256^8=2^64. Both bounded chunks meet this condition.',
            'bytesWordPrefix_eq quantifies arbitrary count, byte list and UInt64 accumulator. Structural induction returns the exact take-fold and drop suffix, including exhausted lists and count zero.',
            'bytesValue_append proves exact radix concatenation for arbitrary lists. The public proof splits actual <=8 and <=16 guards, uses the prefix theorem and shift/radix identity, and retains the original all-Nat fallback definitionally for longer lists. No validity, corpus or length premise is added to the public equality.',
            'Seven kernel witnesses include empty, maximum 7/8-byte words, the ninth-byte crossing, 14/16-byte maxima and a 17-byte fallback. They supplement the universal proof.',
            'The helper build and integrated whole-decoder refinement have only permitted axioms. Failed attempt 1 and its recovery output are retained separately and not counted as a proof. Final proof source has no placeholder or native-reflection tactic.'
        ],
        'limits': 'Independent mathematical source assessment and replay of existing build/log/source bindings; no independent Lean build or native decoder execution.'
    }
    (OUT / 'source-proof-review.json').write_text(json.dumps(proof_review, indent=2) + '\n')
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    assert all(sha(p) == r['sha256'] for p, r in supplementary.items())
    result = {
        'status': 'passed', 'findings': [], 'checks': checks, 'byte_words_live_path_verified': True,
        'source_proof_review_sha256': sha(OUT / 'source-proof-review.json'), 'all_captured_inputs_unchanged': True,
        'unchanged_native_sources': unchanged, 'ownership_changed_native_sources': ownership_changes, 'source_proof_inputs': supplementary,
        'scope': 'Static source/C/object/linked CLI inspection and existing proof build records only. No build, decoder, profile, test suite or benchmark execution by this reviewer.',
        'limits': [
            'Actual <=8 and second-word UInt64 loops inline into bytesValue; missing helper symbols do not mean zero byte-fold work.',
            'The prefix helper allocates one UInt64 box and one result pair at its endpoint, with no pair carried through its byte loop. Existing reference-count releases and arbitrary-Nat count fallback remain; this is not a claim that every path performs no allocation.',
            'The 9–16-byte branch combines two words with one Nat shift/add after the prefix. The original arbitrary-Nat byte fold remains live only beyond 16 bytes.',
            'This inspection binds the integrated CLI, not the future freshly built timed worker; no throughput claim is made.'
            , 'Frame and Message Lean sources are unchanged but their C/object/trace bytes differ because bytesValue now consumes its list. The exact changes are removed borrowing wrappers, two rejection-path decrements in decodeFrame and removal of the caller decrement in decodePrefix; retained normalized diffs enumerate them. The other 17 production native sets are byte-identical.'
        ],
        'future_diagnostic': 'Bind the freshly timed worker, retain public bytesValue and prefix anchors, and distinguish inlined word loops from the live >16-byte Nat fallback. Never infer zero field work from absent standalone symbols.',
        'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ('review.json', 'validate.stdout', 'validate.stderr')}
    }
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'files': len(result['files']), 'source_proof_review_sha256': result['source_proof_review_sha256'], 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()


