#!/usr/bin/env python3
"""Independently check retained gen14 proof/native evidence; no decoder execution."""
import sys
sys.dont_write_bytecode=True
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
    old_c = (retained / 'tests/evidence/diagnostics/gen13/generated-c/Impl/CommB.c').read_text()
    source = (retained / 'Impl/CommB.lean').read_text()
    old_source = (OUT / 'prior-CommB-source.txt').read_text()
    proof = (retained / 'Proofs/CommBRatio.lean').read_text()
    decoder = (retained / 'Proofs/Decoder.lean').read_text()
    build = inspection['successful_integrated_build']
    logpath = Path(inspection['successful_integrated_build_path']).with_suffix('.log')
    log = (retained / logpath).read_text()
    checks = {}
    checks['integrated_build_passed_3522_jobs'] = build['status'] == 'passed' and build['exit_code'] == 0 and 'Build completed successfully (3522 jobs).' in log and sha(logpath) == build['log_sha256']
    checks['all_three_integrated_source_bindings_match'] = len(build['inputs_after']) == 3 and build['inputs_before'] == build['inputs_after'] and all(sha(p) == h for p, h in build['inputs_after'].items())
    helper_review = json.loads((OUT / 'source-proof-review.json').read_text())
    checks['independent_all_Rat_helper_review_remains_bound'] = helper_review['status'] == 'passed' and not helper_review['findings'] and helper_review['all_Rat_runtime_equality_verified'] and all(sha(p) == r['sha256'] for p, r in helper_review['inputs'].items())
    checks['only_CommB_runtime_source_changed'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/CommB.lean'
    start = source.index('/-- Exact decision for a software-binary64 rounded ratio outside [250,800].')
    end = source.index('-- Initial algorithm: Spec/CommB.lean:409.', start)
    recovered = source[:start] + source[end:]
    checks['only_BDS60_ratio_predicate_changed'] = recovered.replace('if cbRatioOutside250800 (ias / mach) then -3 else 0', 'let ratio := Binary64.div ias mach\n        if ratio < 250 || ratio > 800 then -3 else 0') == old_source
    checks['no_new_trust_or_cross_message_state'] = not re.search(r'IO\.Ref|ST\.Ref|@\[(?:extern|implemented_by)|\b(?:unsafe|partial|axiom|sorry|admit|native_decide)\b|panic!|get!|unreachable!', source)
    symbol = P + 'cbRatioOutside250800'
    ratio = body(c, symbol)
    penalty = body(c, P + 'cbPenalty')
    checks['ratio_C_uses_exact_Int_numerator_denominator_arithmetic'] = all(s in ratio for s in ('lean_ctor_get(v_q_', 'lean_nat_to_int(', 'lean_nat_abs(', 'lean_int_add(', 'lean_int_mul(', 'lean_int_sub(', 'lean_int_dec_lt(', 'lean_int_dec_le(')) and ratio.count('lean_int_dec_lt(') == 2 and ratio.count('lean_int_dec_le(') == 2
    checks['ratio_C_preserves_exact_K_and_threshold_constants'] = 'lean_cstr_to_nat("2251799813685248")' in body(c, '_init_' + symbol + '___closed__0') and 'lean_unsigned_to_nat(250u)' in body(c, '_init_' + symbol + '___closed__1') and 'lean_unsigned_to_nat(800u)' in body(c, '_init_' + symbol + '___closed__4')
    split = ratio.index('v_rounded_')
    # The first occurrence is the fallback block declaration, after both shortcut guards.
    checks['ratio_C_round_and_Rat_comparisons_occur_only_after_integer_guards'] = ratio.count(P + 'Binary64_round(') == 1 and ratio.count('l_Rat_blt(') == 2 and not any(s in ratio[:split] for s in (P + 'Binary64_round(', 'l_Rat_blt(', 'l_Rat_div(', 'l_Rat_mul(', 'l_Rat_add('))
    checks['ratio_C_has_no_Rat_arithmetic_in_enclosure'] = not any(s in ratio for s in ('l_Rat_add(', 'l_Rat_sub(', 'l_Rat_mul(', 'l_Rat_div('))
    checks['BDS60_C_forms_exact_ratio_once_then_calls_live_helper'] = penalty.count('l_Rat_div(') == 1 and penalty.count(symbol + '(') == 1 and penalty.index('l_Rat_div(') < penalty.index(symbol + '(') and P + 'Binary64_div(' not in penalty
    checks['BDS60_C_semantic_status_and_positive_Mach_guards_remain'] = all(s in penalty for s in ('lean_unsigned_to_nat(96u)', P + 'commBValue(', P + 'cbMach64(', 'l_Rat_blt(')) and penalty.index(P + 'cbMach64(') < penalty.index('l_Rat_div(')
    normalize = lambda s: re.sub(r'(?<=_)\d+(?=_)', 'N', s)
    protected = ('cbWindPenalty50', 'cbWindPenaltyTable___lam__0', 'cbValid50', 'cbValid60', 'cbDensityTerms', 'cbDensityTermsFast', 'cbCombinedScore', 'cbScorePasses', 'commBCoreEligible', 'cbQNH64', 'cbMach64')
    checks['other_live_CommB_C_bodies_unchanged_modulo_local_numbers'] = all(normalize(body(c, P + n)) == normalize(body(old_c, P + n)) for n in protected)
    checks['BDS50_native_wind_lookup_and_turn_subtraction_remain'] = P + 'cbWindPenalty50' in calls((OUT / 'binary-cbPenalty.txt').read_text()) and P + 'Binary64_sub' in calls((OUT / 'binary-cbPenalty.txt').read_text())
    asm = (OUT / 'binary-cbRatioOutside250800.txt').read_text()
    rows = instructions(asm)
    events = {}
    for row in rows:
        if row['op'] in ('call', 'jmp'):
            if '<' + P + 'Binary64_round>' in row['args']:
                events[row['address']] = 'software_round'
            if '<l_Rat_blt>' in row['args']:
                events[row['address']] = 'rounded_Rat_compare'
    cfg = event_paths(asm, events)
    expected = {(), ('software_round', 'rounded_Rat_compare'), ('software_round', 'rounded_Rat_compare', 'rounded_Rat_compare')}
    checks['native_fast_paths_skip_round_and_Rat_compare_fallback_preserves_order'] = {tuple(r['events']) for r in cfg['normal_exits']} == expected
    checks['native_helper_has_exact_big_Int_support_and_machine_integer_ops'] = all(name in calls(asm) for name in ('lean_int_big_add', 'lean_int_big_mul', 'lean_int_big_sub')) and any(r['op'] == 'imul' for r in rows)
    checks['native_helper_calls_round_at_one_conditional_site'] = calls(asm).count(P + 'Binary64_round') == 1 and calls(asm).count('l_Rat_blt') == 2
    penalty_calls = calls((OUT / 'binary-cbPenalty.txt').read_text())
    checks['actual_cbPenalty_forms_exact_Rat_ratio_and_calls_helper_once'] = penalty_calls.count(symbol) == 1 and penalty_calls.count('l_Rat_div') == 1 and penalty_calls.index('l_Rat_div') < penalty_calls.index(symbol) and P + 'Binary64_div' not in penalty_calls
    checks['fast_and_lazy_full_score_paths_share_live_penalty'] = all(calls((OUT / f).read_text()).count(P + 'cbPenalty') == 1 for f in ('binary-cbScorePasses.txt', 'binary-cbScorePasses___lam__0___boxed.txt'))
    checks['full_score_fallback_stays_conditional_and_software_based'] = calls((OUT / 'binary-ScoreGate_choose.txt').read_text()).count('lean_apply_1') == 1 and all(P + n in calls((OUT / 'binary-cbScorePasses___lam__0___boxed.txt').read_text()) for n in ('cbDensity', 'cbPenalty', 'Binary64_add'))
    checks['decode_retains_single_syndrome_and_complete_report'] = all(calls((OUT / 'binary-decode.txt').read_text()).count(P + n) == 1 for n in ('decodeFrame', 'frameSyndrome', 'reportWithSyndrome'))
    checks['frozen_adapters_use_live_entrypoints'] = (retained / 'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3 and 'Impl.decodeBDS' in (retained / 'Tests/CommBDifferential.lean').read_text() and 'Impl.decode' in (retained / 'Tests/Upstream.lean').read_text()
    cfg['limits'] = 'Static normal-return CFG traversal treats external calls as returning and follows both unknown successors. It distinguishes zero-round shortcut paths from one-round fallback paths, not their runtime frequencies. Exact Rat division in the caller, arbitrary-precision Int operations, allocations and lazy scalar constants remain; no speed claim is made.'
    (OUT / 'ratio-native-cfg.json').write_text(json.dumps(cfg, indent=2) + '\n')
    prior = {r['source']: r for r in json.loads((retained / 'bench/runs/gen13/fresh-native-inputs.json').read_text())}
    unchanged = []
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean', 'Impl/CommB.lean'):
            continue
        old = prior[row['source']]
        assert sha(row['source']) == old['source_sha256']
        assert all(sha(row[k]) == old['artifacts'][row[k]]['sha256'] for k in ('c', 'object', 'trace'))
        unchanged.append(row['source'])
    checks['other_19_native_source_C_object_trace_sets_unchanged'] = len(unchanged) == 19
    for path in ('spec.lock', 'lakefile.toml', 'TRUSTED.md'):
        checks[path + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', inspection['commit'] + ':' + path]) == (retained / path).read_bytes()
    locked = [line.split(None, 1) for line in (retained / 'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == h for h, p in locked)
    trace = json.loads((retained / '.lake/build/ir/Impl/CommB.c.o.export.trace').read_text())
    compiler = next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_remain_O3_ffp_contract_off'] = '-O3' in compiler and '-ffp-contract=off' in compiler
    integrated_facts = facts(log)
    checks['all_143_integrated_printed_facts_have_only_permitted_axioms'] = len(integrated_facts) == 143 and all(set(f['axioms']) <= ALLOWED for f in integrated_facts)
    checks['Decoder_uses_universal_helper_and_unchanged_refinement'] = 'import Proofs.CommBRatio' in decoder and 'CommBRatio.cbRatioOutside250800_eq' in decoder and 'decoder_Binary64_round_eq, decoder_Binary64_div_eq' in decoder and any(f['name'] == 'Lean1090.Proofs.Refinement' for f in integrated_facts)
    checks['all_Rat_theorem_has_no_hypothesis_or_native_reflection'] = 'theorem cbRatioOutside250800_eq (q : Rat) :' in proof and not re.search(r'\b(?:sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)', proof)
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    integration = {'status': 'passed', 'findings': [], 'reviewer': '/root/cost_analysis; independent of runtime/helper/integration authors', 'sources': build['inputs_after'], 'source_proof_review_sha256': sha(OUT / 'source-proof-review.json'), 'integrated_build_path': inspection['successful_integrated_build_path'], 'integrated_build_sha256': sha(inspection['successful_integrated_build_path']), 'integrated_log_sha256': sha(logpath), 'integrated_allowed_axiom_facts': len(integrated_facts), 'integrated_facts': integrated_facts, 'assessment': 'Decoder uses the unconditional all-Rat helper equality and the existing Binary64 round/divide refinements inside the unchanged cbPenalty equality. No extra hypothesis is added to that equality or whole-decoder refinement. All three sources match the passed integrated build.', 'limits': 'Review of retained build evidence and mathematical source, not an independent build.'}
    (OUT / 'integration-proof-review.json').write_text(json.dumps(integration, indent=2) + '\n')
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    result = {'status': 'passed', 'findings': [], 'checks': checks, 'bds60_ratio_enclosure_live_path_verified': True,
        'source_proof_review_sha256': sha(OUT / 'source-proof-review.json'), 'integration_proof_review_sha256': sha(OUT / 'integration-proof-review.json'),
        'all_captured_inputs_unchanged': True, 'unchanged_native_sources': unchanged,
        'scope': 'Static source/C/object/linked CLI inspection and existing proof build records only. No build, decoder, profile, test suite or benchmark execution by this reviewer.',
        'limits': ['This is the integrated CLI, not the future freshly built timed worker; no timing claim.', 'The enclosure uses exact integer arithmetic, but still allocates arbitrary-precision values where required and forms an exact normalized Rat ratio in its caller. It is not an allocation-free or purely fixed-width path.', 'The original software round and two strict threshold comparisons remain live only on uncertain inputs. Exact thresholds and round-back witnesses exercise this branch; source/proof witnesses are not measured runtime populations.', 'Existing BDS50 wind/turn logic, density tables, BDS60 statuses and positive-Mach guard remain unchanged. Both fast score inference and the full-model fallback call the same live penalty path. Lazy scalar constants may initialize during early calls.'],
        'future_diagnostic': 'Retain the actual cbRatioOutside250800 boundary and its Binary64.round descendant. Distinguish rational division in cbPenalty from the conditional software rounding fallback; do not infer populations from absent inlined wrappers or inclusive costs.',
        'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ('review.json', 'validate.stdout', 'validate.stderr')}}
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'files': len(result['files']), 'source_proof_review_sha256': result['source_proof_review_sha256'], 'integration_proof_review_sha256': result['integration_proof_review_sha256'], 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()


