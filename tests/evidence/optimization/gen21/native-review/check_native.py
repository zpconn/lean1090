#!/usr/bin/env python3
"""Inspect retained generation 21 C and linked assembly; no native execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
from collections import Counter
import hashlib, json, re

R = Path('tests/evidence/optimization/gen21/native-review')
P = 'lp_lean1090_Lean1090_Impl_'
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
capture = load(R / 'native-inputs.json')
build = load(R.parent / 'integration/targeted-build.json')
checks = []
bindings = {}
def check(ok, note):
    assert ok, note
    checks.append(note)
def bind(p, expected=None):
    h = sha(p)
    check(expected is None or h == expected, 'bound ' + str(p))
    bindings[str(p)] = h
    return h
def cbody(symbol):
    row = capture['generated_c_excerpts'][symbol]
    bind(row['path'], row['sha256']); bind(row['source'], row['source_sha256'])
    return '\n'.join(re.sub(r'^\d+: ', '', l) for l in Path(row['path']).read_text().splitlines())
def asm(symbol):
    path = R / 'native-inspection' / (symbol + '.txt')
    bind(path)
    rows = []
    for line in path.read_text().splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+(\S+)\s*(.*)', line)
        if m:
            rows.append(dict(address=int(m[1],16), mnemonic=m[2], operands=m[3]))
    check(bool(rows), 'actual linked body ' + symbol)
    return rows
def targets(rows):
    return [m[1] for r in rows if r['mnemonic'] in ('call','jmp') and (m := re.search(r'<([^>]+)>', r['operands']))]
def text(rows):
    return '\n'.join(r['mnemonic'] + ' ' + r['operands'] for r in rows)

bind(R / 'native-inputs.json')
bind(R.parent / 'integration/targeted-build.json', capture['integration_record_sha256'])
bind(R.parent / 'integration/targeted-build.log', build['log_sha256'])
check(build['status']=='passed' and build['exit_code']==0, 'combined build passed')
check(len(build['all_inputs_after'])==195 and build['all_inputs_before']==build['all_inputs_after'], '195 unchanged correctness inputs')
for path,h in capture['held_inputs'].items(): check(sha(path)==h, 'held ' + path)
check(capture['worker_sha256']==build['binary_hashes']['lean1090-bench'], 'actual linked worker equals integrated worker')
for row in capture['commands']:
    check(row['exit_code']==0 and not row['stderr'], 'static command succeeded: ' + row['output'])
    bind(row['output'], row['sha256'])
oldpath = Path('tests/evidence/optimization/gen20/native-review/native-inputs.json')
bind(oldpath)
old = {r['source']:r for r in load(oldpath)['linked_inventory']}
differences = {}
for row in capture['linked_inventory']:
    differences[row['source']] = [key for key in ('source_sha256','c_sha256','object_sha256','trace_sha256') if row[key] != old[row['source']][key]]
check(len(differences)==22 and [s for s,d in differences.items() if d]==['Impl/PayloadBits.lean'], 'only PayloadBits differs across 22 source/C/object/trace sets')

# Independent reading of exact generated guards and their actual linked bodies.
helper=cbody(P+'integerScale')
payload=cbody(P+'payloadValue')
for name,body in [('integerScale',helper),('payloadValue',payload)]:
    check(body.count('lean_int_mul(')==1 and body.count('lean_nat_gcd(')==1, name+' has one exact product/normalization site')
    check('lean_nat_abs(' in body and 'lean_int_div_exact(' in body and 'lean_nat_div_exact(' in body, name+' retains exact numerator/denominator reduction')
    check('l_Rat_mul(' not in body and 'lean_float' not in body, name+' does not call generic Rat multiplication or Float operations')
    check('goto _start;' not in body, name+' normalization is not inside a source recurrence')
check('lean_ctor_get(v_scale_99_, 0)' in helper and 'lean_ctor_get(v_scale_99_, 1)' in helper, 'helper reads arbitrary Rat numerator and positive canonical denominator')
check('lean_nat_dec_eq(v___x_107_, v___x_108_)' in helper and 'lean_unsigned_to_nat(1u)' in helper, 'gcd one bypass preserves the already reduced product')
check('l_instDecidableEqRat_decEq(v_scale_175_, v___x_182_)' in payload and 'if (v___x_183_ == 0)' in payload, 'unit-scale test precedes product branch')
check('v___x_203_ = l_Rat_ofInt(v___x_180_);' in payload and payload.index('v___x_203_ = l_Rat_ofInt')>payload.index('lean_nat_gcd('), 'unit branch returns integer cast and rejoins offset handling')
check('l_instDecidableEqRat_decEq(v___y_165_, v___x_167_)' in payload and payload.count('l_Rat_add(')==1, 'zero-offset test retains one conditional addition')
check('v___x_169_ = l_Rat_add(v___y_166_, v___y_165_);' in payload and 'lean_ctor_set(v___x_171_, 0, v___y_166_);' in payload, 'offset branches return addition or unchanged scaled value')
check(payload.index('return v___x_209_;')<payload.index('v___jp_178_:'), 'missing status exits before value extraction and normalization')
check(payload.index(P+'payloadBits(v_word_163_, v_start_172_, v_width_173_)')<payload.index(P+'payloadInteger(v_coding_174_, v_width_173_, v___x_179_)')<payload.index('lean_int_mul('), 'live extraction then signed interpretation precede normalization')
check(P+'integerScale' in capture['missing_requested_symbols'] and P+'affineValue' in capture['missing_requested_symbols'], 'small wrappers are absent/inlined in actual linked worker')
rows=asm(P+'payloadValue');calls=targets(rows)
for symbol in ['lean_nat_gcd','lean_int_big_mul','lean_int_big_div_exact','lean_nat_big_div_exact','l_Rat_ofInt','l_Rat_add',P+'payloadBits',P+'payloadInteger']:
    check(symbol in calls, 'actual payload caller retains '+symbol)
check('l_Rat_mul' not in calls and P+'integerScale' not in calls and P+'affineValue' not in calls, 'actual payload body inlines normalization instead of calling Rat.mul/wrappers')
check(sum(t=='lean_nat_gcd' for t in calls)==1, 'one actual linked gcd call site in payloadValue')
# Conservative control-flow traversal treats unknown conditions as both branches.
# No dynamic inputs or decoder executions are used.
by_addr={r['address']:i for i,r in enumerate(rows)}; todo=[(0,0)]; seen=set(); terminal_counts=set()
while todo:
    i,n=todo.pop()
    if (i,n) in seen:continue
    seen.add((i,n));r=rows[i]
    if r['mnemonic']=='call' and '<lean_nat_gcd>' in r['operands']:n+=1
    assert n<=1, 'more than one gcd on a possible payloadValue control-flow path'
    m=re.match(r'([0-9a-f]+) ',r['operands']) if r['mnemonic'].startswith('j') else None
    target=int(m[1],16) if m else None
    if r['mnemonic'].startswith('ret') or (r['mnemonic']=='jmp' and target not in by_addr):
        terminal_counts.add(n);continue
    if r['mnemonic'].startswith('j'):
        assert target in by_addr, ('unresolved internal target',r)
        todo.append((by_addr[target],n))
        if r['mnemonic']=='jmp':continue
    if i+1<len(rows):todo.append((i+1,n))
check(terminal_counts=={0,1}, 'linked payload paths traverse zero or one normalization call site')
check('lean_alloc_small_object_core' in calls, 'allocation remains; no allocation-free claim')
check(P+'payloadValue' in cbody(P+'commBValue') and P+'payloadValue' in targets(asm(P+'commBValue')), 'actual Comm-B caller reaches optimized payloadValue')
sem=load(R/'semantic-caller.json');bind(R/'semantic-caller.json')
check(sem['parent_capture_sha256']==sha(R/'native-inputs.json') and sem['worker_sha256']==capture['worker_sha256'] and sem['all_inputs_unchanged'], 'supplemental semantic caller binds same capture/worker')
for field,hkey in [('c_source','c_sha256'),('c_excerpt','c_excerpt_sha256'),('assembly','assembly_sha256')]:bind(sem[field],sem[hkey])
check(P+'payloadValue'+'(' in Path(sem['c_excerpt']).read_text() and P+'payloadValue' in targets(asm(sem['symbol'])), 'actual specialized semantic map reaches optimized payloadValue')
check(P+'Semantics_tableValues' in capture['missing_requested_symbols'], 'standalone semantic table wrapper is inlined, with callable map retained')
check('payloadValue c word' in Path('Impl/Semantics.lean').read_text(), 'semantic source still maps live payloadValue')
check('Rat' not in cbody('initialize_lean1090_Impl_PayloadBits') and 'integerScale' not in cbody('initialize_lean1090_Impl_PayloadBits'), 'no new eager normalization/table initialization')
source_review=R.parent/'independent-review/source-proof-review.json';bind(source_review,'1a12b01eada8fcef91957c6489ec32bfa26f25c0b3ce1ef96d050972e10e42fa')
check(load(source_review)['status']=='passed' and not load(source_review)['findings'], 'independent universal proof and frozen adapter assessment passed')
context=dict(worker_sha256=capture['worker_sha256'],payload_value_anchor=P+'payloadValue',semantic_caller_anchor=sem['symbol'],absent_inline_wrappers=[P+'integerScale',P+'affineValue'],generated_c_product_and_gcd_sites=1,native_gcd_call_sites=1,possible_terminal_gcd_counts=sorted(terminal_counts),native_cfg_states=len(seen),source_native_differences=differences)
cp=R/'affine-native-context.json';assert not cp.exists();cp.write_text(json.dumps(context,indent=2)+'\n');bind(cp)
for path,h in capture['held_inputs'].items():check(sha(path)==h,'final held '+path)
files={str(p):dict(sha256=sha(p),bytes=p.stat().st_size) for p in sorted(R.rglob('*')) if p.is_file() and p.name not in ['review.json','review-02.log']}
out=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,files=files,held_inputs=capture['held_inputs'],held_input_count=len(capture['held_inputs']),linked_native_sets=len(capture['linked_inventory']),all_inputs_unchanged=True,integer_affine_normalization_live_path_verified=True,worker=capture['worker'],worker_sha256=capture['worker_sha256'],integration_record_sha256=capture['integration_record_sha256'],unchanged_sibling_native_sets=21,source_delta=['Impl/PayloadBits.lean'],native_context_sha256=sha(cp),limitations=['Static source and linked-path review is not a throughput or dynamic corpus-frequency measurement.','integerScale and affineValue are inlined in payloadValue; absence of standalone symbols does not mean zero work.','Exact Int arithmetic, gcd reduction and ownership/allocation paths remain; huge cancelling inputs may create larger intermediate integers than cross-cancelling Rat.mul.','Only the changed nonunit affine multiplication is replaced; unrelated rational operations in Comm-B and other paths remain.','Unit scale, zero offset, missing status and all-input frozen refinement are preserved; no Float or trusted boundary changed.'])
p=R/'review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps(dict(status='passed',checks=len(checks),held=len(capture['held_inputs']),linked_sets=len(capture['linked_inventory']),review_sha256=sha(p),context_sha256=sha(cp))))
