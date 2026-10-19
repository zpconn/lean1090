"""Independently bind/review the retained byte-CRC native assessment; no build/run."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib
import json
import re
import subprocess

B = Path('tests/evidence/optimization/gen20')
N = B / 'native-review'
R = B / 'independent-review'
OUT = R / 'native-assessment-review.json'
checks, bindings = [], {}

def check(condition, description):
    assert condition, description
    checks.append(description)

def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()

def bind(path, expected=None):
    digest = sha(path)
    check(expected is None or digest == expected, 'bound ' + str(path))
    bindings[str(path)] = digest
    return digest

def load(path):
    return json.loads(Path(path).read_text())

def instructions(path):
    return [dict(address=int(m[1], 16), mnemonic=m[2], operands=m[3])
            for line in Path(path).read_text().splitlines()
            if (m := re.match(r'\s*([0-9a-f]+):\s+(\S+)\s*(.*)', line))]

check(not OUT.exists(), 'refuse prior review overwrite')
bind(N / 'review.json', 'cac79d5e06b440b76a801859088720a8c31edb7c6dbc062c5f89a838dc0f2537')
bind(N / 'native-inputs.json', '0f033acdcae3cf7900c0101ae5c1ff41cd8ad9e9665a829eaae3a7dc56e28254')
review, captured = load(N / 'review.json'), load(N / 'native-inputs.json')
check(review['status'] == 'passed' and not review['findings'], 'producer assessment passed')
check(review['byte_crc_live_path_verified'] and captured['all_inputs_unchanged'], 'declared live path and held inputs')
check(len(captured['held_inputs']) == review['held_input_count'] == 267, '267 held bindings')
check(len(captured['linked_inventory']) == review['linked_native_sets'] == 22, '22 linked native sets')
for name, digest in captured['held_inputs'].items():
    check(sha(name) == digest, 'current held input ' + name)
for name, digest in review['bindings'].items():
    bind(name, digest)
for name, row in review['files'].items():
    check(sha(name) == row['sha256'] and Path(name).stat().st_size == row['bytes'], 'retained evidence ' + name)
integration = load(B / 'integration/targeted-build.json')
check(integration['status'] == 'passed' and integration['exit_code'] == 0, 'integrated build passed')
check(integration['all_inputs_before'] == integration['all_inputs_after'] and len(integration['all_inputs_after']) == 195,
      '195 integrated inputs unchanged')
check(integration['binary_hashes']['lean1090-bench'] == captured['worker_sha256'] == sha(captured['worker']),
      'actual current worker matches integrated executable')
old_path = Path('tests/evidence/optimization/gen19/native-review/native-inputs-complete.json')
bind(old_path)
old = {row['source']: row for row in load(old_path)['linked_inventory']}
differences = {}
for row in captured['linked_inventory']:
    differences[row['source']] = [key for key in ['source_sha256', 'c_sha256', 'object_sha256', 'trace_sha256']
                                  if row[key] != old[row['source']][key]]
check([name for name, delta in differences.items() if delta] == ['Impl/Parity.lean'], 'exactly Parity changes among native siblings')

# Reconstruct every numbered excerpt from its actual generated source.
for symbol, row in captured['generated_c_excerpts'].items():
    actual = Path(row['source']).read_text().splitlines()
    expected = ''.join(f'{i + 1}: {actual[i]}\n' for i in range(row['start_line'] - 1, row['end_line']))
    check(Path(row['path']).read_text() == expected, 'exact generated C excerpt ' + symbol)
check(len(captured['generated_c_excerpts']) == 20 and len(captured['commands']) == 13,
      '20 C excerpts and 12 bounded disassemblies plus filtered symbols')
for command in captured['commands']:
    check(command['exit_code'] == 0 and not command['stderr'] and sha(command['output']) == command['sha256'],
          'successful retained inspection ' + command['output'])

context = load(N / 'byte-native-context.json')
bind(N / 'byte-native-context.json', 'e73033191ddae0f57c1c334bdfa6ced47be772729ad7a3af0c7d2aa217ad4a43')
P = 'lp_lean1090_Lean1090_Impl_'
byte_loop, bit_loop = context['byte_loop_anchor'], context['bit_loop_anchor']
loop = instructions(N / 'native-inspection' / (byte_loop + '.txt'))
block = context['unrolled_instructions']
start = next(i for i, row in enumerate(loop) if row['address'] == block[0]['address'])
check(loop[start:start + len(block)] == block, 'retained unrolled context is actual contiguous assembly')
check(loop[start - 1]['mnemonic'] == 'mov' and loop[start - 1]['operands'] == '%eax,%ecx',
      'first bit starts from selected byte register')
check(not any(row['mnemonic'].startswith('j') or row['mnemonic'] == 'call' for row in block),
      'eight-update block has no per-bit branches or calls')
check([row['operands'].split(',')[0] for row in block if row['mnemonic'] == 'shr']
      == ['$0x7', '$0x6', '$0x5', '$0x4', '$0x3', '$0x2', '$1'], 'MSB-first bit order 7 through 1')
check(any(row['mnemonic'] == 'and' and row['operands'] == '$0x1,%eax' for row in block),
      'last update reads unshifted bit zero')
for mnemonic, prefix in [('xor', '$0xfff409,'), ('test', '$0x800000,'), ('and', '$0xffffff,')]:
    check(sum(row['mnemonic'] == mnemonic and row['operands'].startswith(prefix) for row in block) == 8,
          'eight exact polynomial/state operations ' + mnemonic)
check(sum(row['mnemonic'] == 'cmove' for row in block) == 8
      and sum(row['mnemonic'] == 'lea' for row in block) == 8, 'eight feedback choices and remainder doublings')

# Independently traverse wrapper control flow, distinguishing two ownership sites.
wrapper = instructions(N / 'native-inspection' / (P + 'Parity_syndromeBytes.txt'))
addresses = {row['address']: i for i, row in enumerate(wrapper)}
todo, seen, endings, sites = [(0, 0)], set(), set(), set()
while todo:
    i, count = todo.pop()
    if (i, count) in seen:
        continue
    seen.add((i, count))
    row = wrapper[i]
    if row['mnemonic'] == 'call' and '<' + byte_loop + '>' in row['operands']:
        count += 1
        sites.add(row['address'])
    assert count <= 1
    target = re.match(r'([0-9a-f]+)\s', row['operands']) if row['mnemonic'].startswith('j') else None
    address = int(target[1], 16) if target else None
    if row['mnemonic'] == 'ret' or (row['mnemonic'] == 'jmp' and address not in addresses):
        endings.add(count)
        continue
    if row['mnemonic'].startswith('j'):
        assert address in addresses
        todo.append((addresses[address], count))
        if row['mnemonic'] == 'jmp':
            continue
    assert i + 1 < len(wrapper)
    todo.append((i + 1, count))
check(endings == {1} and len(sites) == 2, 'every terminal ownership path enters one fold exactly once')
check(sorted(hex(address) for address in sites) == context['wrapper_call_sites'], 'producer wrapper sites agree')

# Fresh bounded reinspection binds the three critical bodies to this exact worker;
# no binary is executed and no duplicate native dump is stored.
reinspection = {}
for symbol in [P + 'Parity_syndrome', P + 'Parity_syndromeBytes', byte_loop]:
    command = ['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol, captured['worker']]
    run = subprocess.run(command, capture_output=True)
    retained = N / 'native-inspection' / (symbol + '.txt')
    check(run.returncode == 0 and not run.stderr and run.stdout == retained.read_bytes(), 'actual linked reinspection ' + symbol)
    reinspection[symbol] = {'command': command, 'sha256': hashlib.sha256(run.stdout).hexdigest()}

def c(symbol):
    return Path(captured['generated_c_excerpts'][symbol]['path']).read_text()

guard = c(P + 'Parity_syndrome')
check('lean_unsigned_to_nat(128u)' in guard and 'lean_nat_dec_le(' in guard
      and 'lean_unsigned_to_nat(8u)' in guard and 'lean_nat_mod(' in guard, 'exact inclusive width and divisibility guard')
check(guard.count(P + 'Parity_syndromeBits(') == 2 and guard.count(P + 'Parity_syndromeBytes(') == 1,
      'failed guard branches retain live bit-loop fallback')
check('lean_unsigned_to_nat(3u)' in guard and 'lean_nat_shiftr(' in guard, 'accepted width divides by eight exactly')
check('l_Nat_testBit(' in c(bit_loop) and 'l_Nat_testBit(' not in c(byte_loop), 'arbitrary-index fallback retained and byte path uses cache')
check(c(byte_loop).count('lean_uint32_shift_left(') == c(byte_loop).count('lean_uint32_xor(') == 8,
      'generated byte core has eight word updates')
check('lean_nat_mul(' in c(byte_loop) and 'lean_unsigned_to_nat(8u)' in c(byte_loop), 'descending byte offsets remain general natural arithmetic')
for caller, callee in [('decode', 'frameSyndrome'), ('frameSyndrome', 'Parity_checksum'), ('Parity_checksum', 'Parity_syndrome')]:
    check(c(P + caller).count(P + callee + '(') == 1, 'generated live chain ' + caller + ' to ' + callee)
    text = (N / 'native-inspection' / (P + caller + '.txt')).read_text()
    check('<' + P + callee + '>' in text, 'linked live chain ' + caller + ' to ' + callee)
check('Impl.Parity.syndrome' in Path('Tests/Upstream.lean').read_text(), 'frozen CRC adapter uses live public function')
check(Path('Bench/WholeDecoder.lean').read_text().count('let some message := Impl.decode input.bytes') == 3,
      'both frozen timed modes and audit use live complete decoder')
check(not any(word in c('initialize_lean1090_Impl_Parity') for word in ['Array', 'array', 'byteStep', 'syndromeBytes']),
      'no new CRC table or eager loop initialization')

source = load(R / 'source-proof-review.json')
root = load(R / 'byte-bit-proof-review.json')
check(source['status'] == 'passed_independent_source_and_build_evidence_review' and not source['findings'], 'independent composition/fold assessment passed')
check(root['status'] == 'passed' and not root['findings'], 'separate independent byte-bit assessment passed')
check(len(source['fold_facts']) == 3 and len(source['composition_and_existing_facts']) == 17,
      'all fold/composition/existing refinement facts independently assessed')
for axioms in list(source['fold_facts'].values()) + list(source['composition_and_existing_facts'].values()):
    check(set(axioms) <= {'propext', 'Classical.choice', 'Quot.sound'}, 'permitted proof axioms')
for name, digest in source['bindings'].items():
    check(sha(name) == digest, 'independent source assessment input ' + name)
for name, digest in captured['held_inputs'].items():
    check(sha(name) == digest, 'final held input ' + name)
bind(__file__)
result = {'status': 'passed', 'findings': [], 'reviewed_utc': datetime.now(timezone.utc).isoformat(),
          'checks_passed': len(checks), 'checks': checks, 'bindings': bindings,
          'worker_sha256': captured['worker_sha256'], 'held_inputs': 267, 'linked_native_sets': 22,
          'unchanged_siblings': 21, 'retained_native_files': len(review['files']),
          'byte_loop_anchor': byte_loop, 'bit_loop_anchor': bit_loop,
          'bounded_reinspection': reinspection,
          'assessment': ['Eight bit updates are straight-line in the actual byte loop, with exact polynomial feedback and low-24-bit masking.',
                         'Widths through 128 divisible by eight take the byte path; other widths retain the original bit loop and arbitrary-natural testBit fallback.',
                         'Wrapper ownership variants have two textual call sites but one fold entry on every terminal path.',
                         'Native index arithmetic and ownership slow paths remain; no allocation-free or corpus-frequency claim follows from this inspection.'],
          'proof_independence': 'This reviewer authored ParityByte/ParityWord integration. Their mathematical assessment is independently supplied by cost_analysis; the root separately reviews the byte-bit helper authored by cost_analysis. This record independently reviews the native assessment and binds those proof reviews.',
          'no_build_decoder_benchmark_or_profile_executed': True}
OUT.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'checks': len(checks), 'review_sha256': sha(OUT), 'held_inputs': 267}))
