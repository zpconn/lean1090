#!/usr/bin/env python3
"""Validate existing gen6 C and assembly; no native decoder execution."""
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


def calls(asm):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', asm)


def decode_cfg(asm):
    """Conservative direct-branch traversal, treating ordinary calls as returns.

    It checks syntactic paths through this compiled function, not data-dependent
    reachability or callee semantics. Shared helper C/assembly is checked apart.
    """
    insns = []
    for line in asm.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            insns.append((int(match[1], 16), match[2], match[3]))
    assert insns
    addresses = {row[0]: i for i, row in enumerate(insns)}
    states, visited, returns = deque([(0, 0)]), set(), set()
    calls_seen = {}
    while states:
        i, syndrome_count = states.popleft()
        if (i, syndrome_count) in visited:
            continue
        visited.add((i, syndrome_count))
        address, op, args = insns[i]
        if op == 'call':
            assert '<' in args, ('unexpected indirect call', address, args)
            target = args.split('<', 1)[1].split('>', 1)[0]
            calls_seen.setdefault(target, set()).add(syndrome_count)
            if target == P + 'frameSyndrome':
                syndrome_count += 1
                assert syndrome_count == 1, 'syntactic path repeats syndrome'
            if target in (P + 'reportWithSyndrome', P + 'adsbHardValid'):
                assert syndrome_count == 1
        if op.startswith('ret'):
            returns.add(syndrome_count)
            continue
        if op.startswith('j'):
            target = re.match(r'([0-9a-f]+) <', args)
            assert target and int(target[1], 16) in addresses, ('unexpected branch', address, args)
            states.append((addresses[int(target[1], 16)], syndrome_count))
            if op == 'jmp':
                continue
        assert i + 1 < len(insns), ('falls outside function', address)
        states.append((i + 1, syndrome_count))
    assert returns == {0, 1}
    assert calls_seen[P + 'decodeFrame'] == {0}
    assert calls_seen[P + 'frameSyndrome'] == {0}
    return {'instruction_count': len(insns), 'reachable_syntactic_states': len(visited),
            'syndrome_counts_at_returns': sorted(returns),
            'syndrome_counts_before_calls': {k: sorted(v) for k, v in calls_seen.items()},
            'limit': 'Conservative intraprocedural branch graph. Callee behavior is established separately by retained C, assembly and refinement proofs.'}


def main():
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    commands = []
    for name, path, symbol, mode in [
        ('binary-cli-emit', '.lake/build/bin/lean1090', 'lp_lean1090___private_CLI_Main_0__emit', '-d'),
        *[(f'object-{s}', '.lake/build/ir/Impl/Message.c.o.export', P + s, '-dr') for s in
          ('frameAccepted', 'frameAcceptedWithSyndrome', 'frameAddress', 'report')]]:
        argv = ['objdump', mode, '--no-show-raw-insn', '--disassemble=' + symbol, path]
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        assert result.returncode == 0
        (OUT / (name + '.txt')).write_bytes(result.stdout)
        (OUT / (name + '.stderr')).write_bytes(result.stderr)
        commands.append({'argv': argv, 'stdout': name + '.txt', 'stderr': name + '.stderr', 'exit_code': 0})
    old_source = subprocess.check_output(['git', 'show', inspection['commit'] + ':Impl/Message.lean'], text=True)
    (OUT / 'gen5-Message.lean').write_text(old_source)
    commands.append({'argv': ['git', 'show', inspection['commit'] + ':Impl/Message.lean'],
                     'stdout': 'gen5-Message.lean', 'exit_code': 0})
    (OUT / 'additional-inspection.json').write_text(json.dumps({'commands': commands, 'no_decoder_execution': True}, indent=2) + '\n')
    source = (OUT / 'retained/Impl/Message.lean').read_text()
    c = (OUT / 'retained/.lake/build/ir/Impl/Message.c').read_text()
    old_c = (OUT / 'retained/tests/evidence/diagnostics/gen5/generated-c/Impl/Message.c').read_text()
    get = lambda s: body(c, P + s)
    decode, report, acceptance, address = map(get, ('decode', 'reportWithSyndrome', 'frameAcceptedWithSyndrome', 'frameAddressWithSyndrome'))
    checks = {}
    checks['integrated_build_passed_3511_jobs'] = 'Build completed successfully (3511 jobs).' in (OUT / 'retained/tests/evidence/optimization/gen6/integration/targeted-build.log').read_text()
    checks['decode_C_parses_before_one_syndrome_and_returns_early_on_parse_failure'] = decode.count(P + 'frameSyndrome(') == 1 and decode.index('return v___x_265_;') < decode.index(P + 'frameSyndrome(') and decode.index(P + 'decodeFrame(') < decode.index(P + 'frameSyndrome(')
    checks['decode_C_passes_one_value_to_acceptance_and_report'] = 'v___x_270_ = ' + P + 'frameSyndrome(v_val_266_);' in decode and all(P + name + '(v_val_266_, v___x_270_)' in decode for name in ('frameAcceptedWithSyndrome', 'reportWithSyndrome'))
    checks['decode_C_avoids_public_recomputing_wrappers'] = not any(P + s + '(' in decode for s in ('frameAccepted', 'frameAddress', 'report'))
    for name, value in [('acceptance', acceptance), ('address', address), ('report', report)]:
        checks[name + '_shared_helper_has_no_syndrome_or_checksum_call'] = not any(P + s + '(' in value for s in ('frameSyndrome', 'Parity_checksum', 'frameAccepted', 'frameAddress', 'report'))
    checks['acceptance_C_uses_provided_syndrome_and_existing_ADSB_checks'] = P + 'adsbHardValid(' in acceptance and 'lean_nat_dec_eq(v_syndrome_13_' in acceptance
    checks['address_C_uses_provided_syndrome_in_AP_branch'] = 'lean_ctor_set(v___x_39_, 0, v_syndrome_32_);' in address
    checks['report_C_shares_argument_for_address_interrogator_and_crc_field'] = P + 'frameAddressWithSyndrome(v_f_231_, v_syndrome_232_)' in report and P + 'Parity_interrogator(v_syndrome_232_)' in report and re.search(r'lean_ctor_set\([^,]+, 0, v_syndrome_232_\)', report) is not None
    for public, helper in [('frameAccepted', 'frameAcceptedWithSyndrome'), ('frameAddress', 'frameAddressWithSyndrome'), ('report', 'reportWithSyndrome')]:
        value = get(public)
        checks[public + '_standalone_C_computes_once_and_delegates_live_helper'] = value.count(P + 'frameSyndrome(') == 1 and value.count(P + helper + '(') == 1
        checks[public + '_object_definition_retained'] = '<' + P + public + '>:' in (OUT / ('object-' + public + '.txt')).read_text()
    asm = (OUT / 'binary-decode.txt').read_text()
    graph = decode_cfg(asm)
    (OUT / 'decode-control-flow.json').write_text(json.dumps(graph, indent=2) + '\n')
    native_calls = calls(asm)
    checks['linked_decode_has_one_syndrome_site_and_one_report_site'] = native_calls.count(P + 'frameSyndrome') == native_calls.count(P + 'reportWithSyndrome') == 1
    checks['linked_decode_conservative_CFG_never_repeats_syndrome'] = graph['syndrome_counts_at_returns'] == [0, 1]
    checks['linked_decode_reuses_r12_for_acceptance_and_report'] = all(token in asm for token in ('mov    %rax,%r12', 'mov    %r12,%rsi', 'cmp    %rsi,%r12', '<' + P + 'adsbHardValid>'))
    report_asm = (OUT / 'binary-reportWithSyndrome.txt').read_text()
    checks['linked_report_reuses_argument_for_address_and_DF11'] = all(token in report_asm for token in ('mov    %rsi,%rbx', 'mov    %rbx,%rsi', 'mov    %rbx,%rdi', '<' + P + 'frameAddressWithSyndrome>', '<' + P + 'Parity_interrogator>'))
    checks['linked_shared_report_address_and_interrogator_have_no_CRC_call'] = all(not any(P + s in calls((OUT / ('binary-' + name + '.txt')).read_text()) for s in ('frameSyndrome', 'Parity_checksum', 'report', 'frameAddress')) for name in ('reportWithSyndrome', 'frameAddressWithSyndrome', 'Parity_interrogator'))
    checks['linked_address_default_passes_input_to_Option_some'] = 'mov    %rsi,%rbx' in (OUT / 'binary-frameAddressWithSyndrome.txt').read_text() and 'mov    %rbx,0x8(%rax)' in (OUT / 'binary-frameAddressWithSyndrome.txt').read_text()
    checks['acceptance_is_inlined_not_a_missing_computation'] = P + 'frameAcceptedWithSyndrome' not in native_calls and P + 'adsbHardValid' in native_calls and 'frameAcceptedWithSyndrome___closed__0' in asm
    for helper in ('frameSyndrome', 'frameAltitude', 'frameOracleAltitude', 'frameIdentity', 'frameADSB', 'frameCommB'):
        checks[helper + '_generated_C_unchanged_modulo_local_names'] = alpha(get(helper)) == alpha(body(old_c, P + helper))
    start, end = '-- Initial algorithm: Spec/Message.lean:45.', '-- Initial algorithm: Spec/Message.lean:100.'
    checks['all_non_CRC_frame_helpers_source_byte_identical'] = source[source.index(start):source.index(end)] == old_source[old_source.index(start):old_source.index(end)]
    noncrc = lambda text: re.search(r'   frameAltitude f,.*?\| _ => \[\]\)⟩', text, re.S)[0]
    checks['report_non_CRC_fields_source_byte_identical'] = noncrc(source) == noncrc(old_source)
    checks['report_non_CRC_C_calls_preserved'] = all(report.count(P + s + '(') == body(old_c, P + 'report').count(P + s + '(') for s in ('frameAltitude', 'frameIdentity', 'frameADSB', 'frameCommB', 'Semantics_adsb'))
    gen5 = json.loads((OUT / 'retained/bench/runs/gen5/fresh-native-inputs.json').read_text())
    for module in ('Impl/Frame', 'Impl/Parity', 'Impl/CommB', 'Impl/Semantics'):
        row = next(x for x in gen5 if x['source'] == module + '.lean')
        checks[module + '_native_object_unchanged_from_gen5'] = sha('.lake/build/ir/' + module + '.c.o.export') == row['artifacts']['.lake/build/ir/' + module + '.c.o.export']['sha256']
    static = lambda text: '\n'.join(line for line in text.splitlines() if line.startswith('static '))
    checks['no_new_Message_globals_except_helper_constant_rename'] = static(c).replace('frameAcceptedWithSyndrome', 'frameAccepted') == static(old_c)
    checks['runtime_change_is_only_Message'] = (OUT / 'runtime-changed-files.txt').read_text().strip() == 'Impl/Message.lean'
    checks['no_new_runtime_FFI_or_mutable_cache'] = not any(token in (OUT / 'runtime-diff.txt').read_text() for token in ('@[extern', '@[implemented_by', 'IO.Ref', 'ST.Ref', 'initialize '))
    checks['prefix_C_and_linked_path_delegate_actual_decode'] = get('decodePrefix').count(P + 'decode(') == 1 and calls((OUT / 'binary-decodePrefix.txt').read_text()).count(P + 'decode') == 1
    cli = (OUT / 'retained/.lake/build/ir/CLI/Main.c').read_text()
    checks['CLI_source_C_and_linked_paths_use_actual_decode_and_prefix'] = all(P + s + '(' in cli and P + s in calls((OUT / 'binary-cli-emit.txt').read_text()) for s in ('decode', 'decodePrefix'))
    checks['frozen_benchmark_still_calls_Impl_decode'] = (OUT / 'retained/Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes') == 3
    checks['frozen_whole_message_adapters_still_call_actual_decode'] = all('Impl.decode' in (OUT / 'retained' / p).read_text() for p in ('Tests/Tracking.lean', 'Tests/Upstream.lean', 'Tests/ReservedVelocityDifferential.lean', 'Tests/AltitudeDifferential.lean', 'Tests/DTEDifferential.lean', 'Tests/UpstreamCorpus.lean'))
    for name in ('TRUSTED.md', 'lakefile.toml', 'spec.lock'):
        checks[name + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', 'HEAD:' + name]) == Path(name).read_bytes()
    locked = [line.split(None, 1) for line in Path('spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match'] = len(locked) == 104 and all(sha(p) == digest for digest, p in locked)
    trace = json.loads((OUT / 'retained/.lake/build/ir/Impl/Message.c.o.export.trace').read_text())
    compilation = next(row['message'] for row in trace['log'] if row['message'].startswith('.> '))
    checks['native_flags_preserve_O3_and_ffp_contract_off'] = '-O3' in compilation and '-ffp-contract=off' in compilation
    assert all(checks.values()), {k: v for k, v in checks.items() if not v}
    assert all(sha(p) == r['sha256'] for p, r in inspection['inputs'].items())
    result = {'status': 'passed', 'checks': checks, 'all_captured_inputs_unchanged': True,
              'scope': 'Static review of integration CLI and object/C/source. No benchmark-worker freshness or throughput claim; no decoder run or build.',
              'evaluation_order': 'One syndrome after successful parsing, including later payload rejection. Parse failures return first. Standalone public wrappers eagerly calculate once and delegate the same helpers.',
              'next_diagnostic_requirements': ['Recheck the freshly built timed worker path.', 'Use one CRC per successfully parsed frame for the new native-count check; retain old repeated-call predictions as historical, not live expectations.', 'Acceptance is inlined in decode; preserve stage attribution to frame/CRC around the direct frameSyndrome call and treat reportWithSyndrome as the live report. Keep all non-CRC census/output checks unchanged.'],
              'files': {str(p.relative_to(OUT)): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name != 'review.json'}}
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'inputs': len(inspection['inputs']), 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
