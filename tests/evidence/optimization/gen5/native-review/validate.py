#!/usr/bin/env python3
"""Check retained gen5 compiled structure without running native decoder code."""
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
    start = match.end() - 1
    depth = 0
    for index in range(start, len(text)):
        if text[index] == '{':
            depth += 1
        elif text[index] == '}':
            depth -= 1
            if depth == 0:
                return text[match.start():index + 1]
    raise AssertionError(symbol)


def main():
    inspection = json.loads((OUT / 'inspection-inputs.json').read_text())
    assert all(sha(path) == row['sha256'] for path, row in inspection['inputs'].items())
    checks = {}
    c = (OUT / 'retained/.lake/build/ir/Impl/CommB.c').read_text()
    source = (OUT / 'retained/Impl/CommB.lean').read_text()
    mach = body(c, P + 'cbMach64')
    entry = body(c, P + 'cbMachValueTable___lam__0')
    table = body(c, '_init_' + P + 'cbMachValueTable___closed__1')
    initializer = body(c, 'initialize_lean1090_Impl_CommB')
    checks['integrated_build_passed_3510_jobs'] = inspection['successful_integrated_build']['exit_code'] == 0 and 'Build completed successfully (3510 jobs).' in (OUT / 'retained/tests/evidence/optimization/gen5/integration/targeted-build.log').read_text()
    checks['source_table_uses_all_1024_field_codes_only'] = 'def cbMachValueTable : Array Rat := Array.ofFn fun code : Fin 1024 =>' in source and '(code.val : Rat)' in source
    checks['C_table_constructor_is_1024_ofFn_with_entry_closure'] = all(token in table for token in ('lean_unsigned_to_nat(1024u)', 'l_Array_ofFn___redArg(', P + 'cbMachValueTable___closed__0')) and '.m_fun = (void*)' + P + 'cbMachValueTable___lam__0' in c
    checks['entry_preserves_software_mul_then_div'] = entry.count(P + 'Binary64_mul(') == entry.count(P + 'Binary64_div(') == 1 and entry.index(P + 'Binary64_mul(') < entry.index(P + 'Binary64_div(')
    checks['literal_round_remains_in_startup_closed_constant'] = P + 'Binary64_round(' in body(c, '_init_' + P + 'cbMachValueTable___lam__0___closed__2')
    checks['C_lookup_uses_exact_field_and_borrowed_array_access'] = all(token in mach for token in (P + 'cbMachValueTable;', 'lean_unsigned_to_nat(25u)', 'lean_unsigned_to_nat(10u)', P + 'payloadBits(', 'lean_array_fget_borrowed('))
    checks['C_lookup_has_no_software_math_or_table_construction'] = not any(token in mach for token in ('Binary64_', 'l_Rat_', 'lean_obj_once', 'Array_ofFn'))
    init_assignment = P + 'cbMachValueTable = _init_' + P + 'cbMachValueTable();'
    persist = 'lean_mark_persistent(' + P + 'cbMachValueTable);'
    checks['module_eagerly_initializes_and_marks_table_persistent'] = init_assignment in initializer and persist in initializer and initializer.index(init_assignment) < initializer.index(persist)
    checks['no_other_table_global_assignments'] = c.count(P + 'cbMachValueTable =') == 1
    for caller in ('cbValid60', 'cbPenalty', 'cbDensityTerms'):
        checks[caller + '_C_uses_live_cbMach64'] = P + 'cbMach64(' in body(c, P + caller)
    checks['accepted_record_recheck_remains_live'] = P + 'bdsWireValid(' in body(c, P + 'decodeBDS') and P + 'cbValid60(' in body(c, P + 'bdsWireValid')
    checks['score_uses_live_penalty_and_exact_interval_gate'] = all(P + name + '(' in body(c, P + 'cbScorePasses') for name in ('cbPenalty', 'ScoreGate_choose'))
    adapter = (OUT / 'retained/.lake/build/ir/Tests/CommBDifferential.c').read_text()
    checks['frozen_direct_register_adapter_calls_current_decodeBDS'] = re.search(r'v_actual_\w+ = ' + P + r'decodeBDS\(', adapter) is not None
    cli = (OUT / 'retained/.lake/build/ir/CLI/Main.c').read_text()
    main_c = body(cli, 'main')
    json_c = (OUT / 'retained/.lake/build/ir/Impl/JSON.c').read_text()
    message_c = (OUT / 'retained/.lake/build/ir/Impl/Message.c').read_text()
    checks['module_initialization_precedes_CLI_message_processing'] = main_c.index('initialize_lean1090_CLI_Main(') < main_c.index('lean_run_main(') and 'initialize_lean1090_Impl_JSON(' in body(cli, 'initialize_lean1090_CLI_Main') and 'initialize_lean1090_Impl_Message(' in body(json_c, 'initialize_lean1090_Impl_JSON') and 'initialize_lean1090_Impl_CommB(' in body(message_c, 'initialize_lean1090_Impl_Message')
    commands = []
    for name, symbol in (('adapter-valid60', P + 'cbValid60'), ('adapter-decode-bds', P + 'decodeBDS')):
        argv = ['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol, '.lake/build/bin/commbDifferential']
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        assert result.returncode == 0
        (OUT / (name + '.txt')).write_bytes(result.stdout)
        (OUT / (name + '.stderr')).write_bytes(result.stderr)
        commands.append({'argv': argv, 'stdout': name + '.txt', 'stderr': name + '.stderr', 'exit_code': result.returncode})
    (OUT / 'additional-inspection.json').write_text(json.dumps({'commands': commands, 'no_decoder_execution': True}, indent=2) + '\n')
    object_mach = (OUT / 'object-mach.txt').read_text()
    match = re.search(r'<'+re.escape(P+'cbMach64')+r'>:\n(.*?)(?:\nDisassembly|\Z)', object_mach, re.S)
    assert match
    machine_mach = match[1]
    checks['object_lookup_loads_field_index_without_binary64_calls'] = all(token in machine_mach for token in (P + 'cbMachValueTable', P + 'payloadBits', '$0x33,%esi', '$0x15,%edx', '0x18(%rbx,%rax,4)')) and 'Binary64_' not in machine_mach
    checks['linked_table_entry_preserves_binary64_operations'] = all('<' + P + name + '>' in (OUT / 'binary-table-entry.txt').read_text() for name in ('Binary64_mul', 'Binary64_div'))
    checks['linked_table_constructor_has_tagged_1024_count'] = '$0x801,%edi' in (OUT / 'binary-table-initializer.txt').read_text() and '<l_Array_ofFn___redArg>' in (OUT / 'binary-table-initializer.txt').read_text()
    checks['linked_initializer_stores_table_and_marks_persistent'] = '<' + P + 'cbMachValueTable>' in (OUT / 'binary-module-initializer.txt').read_text() and '<lean_mark_persistent>' in (OUT / 'binary-module-initializer.txt').read_text()
    for name in ('binary-valid60', 'binary-penalty', 'binary-density-terms', 'adapter-valid60'):
        asm = (OUT / (name + '.txt')).read_text()
        checks[name + '_inlines_live_table_lookup'] = '<' + P + 'cbMachValueTable>' in asm and '<' + P + 'payloadBits>' in asm and re.search(r'mov\s+0x18\([^\n]+,4\)', asm) is not None
    checks['cbMach64_standalone_object_exists_but_linked_wrappers_inlined'] = '<' + P + 'cbMach64>:' in object_mach and all(not any(line.endswith(' ' + P + 'cbMach64') for line in (OUT / (binary + '-symbols.txt')).read_text().splitlines()) for binary in ('lean1090', 'commbDifferential'))
    for name in ('TRUSTED.md', 'lakefile.toml', 'spec.lock'):
        checks[name + '_unchanged_from_HEAD'] = subprocess.check_output(['git', 'show', 'HEAD:' + name]) == Path(name).read_bytes()
    lock_count = 0
    for line in Path('spec.lock').read_text().splitlines():
        digest, name = line.split(None, 1)
        assert sha(name) == digest, name
        lock_count += 1
    checks['all_104_frozen_entries_match'] = lock_count == 104
    checks['runtime_diff_adds_no_FFI_override'] = not any(token in (OUT / 'runtime-diff.txt').read_text() for token in ('@[extern', '@[implemented_by'))
    trace = json.loads((OUT / 'retained/.lake/build/ir/Impl/CommB.c.o.export.trace').read_text())
    compilation = next(row['message'] for row in trace['log'] if row['message'].startswith('.> '))
    checks['native_compile_flags_retain_O3_and_ffp_contract_off'] = '-O3' in compilation and '-ffp-contract=off' in compilation
    assert all(checks.values()), {key: value for key, value in checks.items() if not value}
    assert all(sha(path) == row['sha256'] for path, row in inspection['inputs'].items())
    result = {'status': 'passed', 'checks': checks, 'all_captured_inputs_unchanged': True,
              'native_cbMach64_symbol_inlined': True,
              'next_diagnostic_requirement': 'Treat the missing cbMach64 linked symbol as compiler inlining, not zero Mach work. Use caller-context stages and candidate/score probes; verify actual table loads in cbValid60/cbPenalty.',
              'scope': 'Static inspection of existing compiled artifacts only; no build, native decoder execution, test campaign, profiler or timing.',
              'files': {str(path.relative_to(OUT)): {'sha256': sha(path), 'bytes': path.stat().st_size}
                        for path in sorted(OUT.rglob('*')) if path.is_file() and path.name != 'review.json'}}
    (OUT / 'review.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'checks': len(checks), 'review_sha256': sha(OUT / 'review.json')}))


if __name__ == '__main__':
    main()
