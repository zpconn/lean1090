"""Read-only source/native association; no build or decoder execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
from collections import deque
import hashlib, importlib.util, json, re, subprocess

E = Path('tests/evidence/diagnostics/gen20')
D = E / 'independent-review/source-inspection'
D.mkdir(parents=True,exist_ok=True)
P = 'lp_lean1090_Lean1090_Impl_'
WORKER = '.lake/build/bin/lean1090-bench'
def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, value):
    assert not p.exists(), p
    p.write_text(json.dumps(value, indent=2) + '\n')
def retain(p, data):
    if p.exists(): assert p.read_bytes()==data, ('retained output changed',p)
    else: p.write_bytes(data)
def body(text, name):
    m = re.search(r'(?:LEAN_EXPORT|static) [^\n]+ '+re.escape(name)+r'\([^\n]*\)\s*\{', text)
    assert m, name
    start=m.end()-1; depth=0
    for end in range(start,len(text)):
        depth += (text[end]=='{')-(text[end]=='}')
        if depth==0: return text[start:end+1], text[:start].count('\n')+1
    raise AssertionError(name)

build_path=Path('.cache/gen20-costs/driver/driver-build.json')
build=read(build_path); bench=read('bench/runs/gen20/summary.json')
native_path=Path('bench/runs/gen20/fresh-native-inputs.json'); native=read(native_path)
oldpath=Path('tests/evidence/diagnostics/gen19/independent-review/source-review.json'); old=read(oldpath)
assert build['status']=='passed' and len(native)==22
assert subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()==build['commit']
assert sha(WORKER)==bench['binary_sha256']
assert build['fresh_benchmark_native_binding']['sha256']==sha(native_path)
held={**build['unchanged_native_inputs'], **build['production_sources']}
for name,digest in held.items(): assert sha(name)==digest,name
for name,digest in build['artifacts'].items(): assert sha(name)==digest,name
bindings={}
for row in native:
    name=row['source']; digest=row['source_sha256']
    assert sha(name)==digest==build['linked_project_inventory']['sources'][name]
    for commit in [build['commit'],bench['commit']]:
        assert hashlib.sha256(subprocess.check_output(['git','cat-file','blob',commit+':'+name])).hexdigest()==digest
    artifacts={}
    for path,record in row['artifacts'].items():
        assert sha(path)==record['sha256']==held[path]
        artifacts[path]=record['sha256']
    bindings[name]={'source_sha256':digest,'artifacts':artifacts}
assert len(build['reused_production_objects'])==build['reused_production_object_count']==21

# Re-execute the read-only descendant association, not a hard-coded commit alias.
sys.path.insert(0,str(Path('review/diagnostics').resolve()))
import bind_benchmark_history
binding_path=E/'benchmark-source-binding.json'
assert bind_benchmark_history.inspect(build_path,Path('bench/runs/gen20/summary.json'),None,
    Path('bench/runs/gen20/correctness-inputs.json'))==read(binding_path)

old_native={r['source']:r for r in read('bench/runs/gen19/fresh-native-inputs.json')}
unchanged=[]
for row in native:
    if row['source']=='Impl/Parity.lean':continue
    before=old_native[row['source']]
    assert row['source_sha256']==before['source_sha256'],row['source']
    assert {p:r['sha256'] for p,r in row['artifacts'].items()}=={p:r['sha256'] for p,r in before['artifacts'].items()},row['source']
    unchanged.append(row['source'])
assert len(unchanged)==21
# CPRFloat source and native artifacts are unchanged since generation18.
oldfloat=subprocess.check_output(['git','cat-file','blob',read('bench/runs/gen19/summary.json')['commit']+':Impl/CPRFloat.lean'],text=True)
assert oldfloat==Path('Impl/CPRFloat.lean').read_text()
floatpath=Path('.lake/build/ir/Impl/CPRFloat.c');floatc=floatpath.read_text()
T=P+'CPR_Policy_toFloat';F=T+'Fallback';Z='_init_'+T+'___closed__1';FI='initialize_lean1090_Impl_CPRFloat'
tf=body(floatc,T)[0];fallback=body(floatc,F)[0]
assert tf.count(F+'(')==3 and '"9007199254740992"' in tf and '1074u' in tf and 'lean_nat_dec_eq' in tf
assert tf.count('lean_nat_log2(')==2 and tf.count('lean_nat_shiftl(')==3
assert 'lean_float_of_bits' in tf and 'lean_uint64_of_nat' in tf
assert 'l_Rat_' not in tf and P+'Binary64_' not in tf
assert 'lean_float_once' in tf and 'lean_float_of_bits' in body(floatc,Z)[0]
assert T+'___closed__1 =' not in body(floatc,FI)[0] and Z+'(' not in body(floatc,FI)[0]
for name in ['round','exponent','powerTwo']:assert P+'Binary64_'+name+'(' in fallback
assert 'l_Rat_div(' in fallback
for name in ['haversineFloat','decodeLocalFloat']:assert T+'(' in body(floatc,P+'CPR_Policy_'+name)[0]
assert T+'(' not in body(floatc,P+'CPR_Policy_decodeGlobalFloat')[0]
cpath=Path('.lake/build/ir/Impl/Bits.c'); c=cpath.read_text()
S=P+'Binary64_';binarycpath=Path('.lake/build/ir/Impl/Binary64.c');binaryc=binarycpath.read_text()
power=body(binaryc,S+'powerTwo')[0]
assert power.count('lean_int_dec_le(')==2 and power.count(S+'powerTwoFormula(')==2
assert 'lean_array_fget_borrowed' in power and 'lean_int_add' in power and 'l_Int_toNat' in power
entry=body(binaryc,S+'powerTwoTable___lam__0')[0]
assert S+'powerTwoFormula(' in entry and not re.search(r'\b'+S+r'powerTwo\(',entry)
ctor='_init_'+S+'powerTwoTable___closed__1'
assert '2098u' in body(binaryc,ctor)[0]
init='initialize_lean1090_Impl_Binary64'
initbody=body(binaryc,init)[0]
assert initbody.index(S+'powerTwoTable =')<initbody.index(S+'maxFinite =')
fold='lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0'
fb=body(c,fold)[0]
assert fb.count('lean_nat_shiftl(')==fb.count('lean_nat_pow(')==fb.count('lean_nat_mod(')==1
assert 'lean_nat_mul(' not in fb and 'lean_unsigned_to_nat(64u)' in fb
guard=re.search(r'(v_\w+) = lean_nat_dec_lt\([^;]+;',fb)[1]
wide_start=fb.index('if ('+guard+' == 0)')
wide=fb[wide_start:fb.index('\nelse\n',wide_start)]
narrow=fb[fb.index('\nelse\n',wide_start):]
assert 'lean_nat_pow(' in wide and 'lean_nat_mod(' in wide
assert not any(x in narrow for x in ['lean_nat_pow(', 'lean_nat_mod(', 'lean_nat_mul('])
assert all(x in narrow for x in ['lean_uint64_of_nat(', 'lean_uint64_shift_left(', 'lean_uint64_land(', 'lean_uint64_to_nat('])
assert fb.index('lean_nat_shiftl(')<wide_start and 'goto _start;' in wide and 'goto _start;' in narrow
assert fold+'(' in body(c,P+'packFields')[0]
message_path=Path('.lake/build/ir/Impl/Message.c'); message=message_path.read_text()
assert P+'packFields(' in body(message,P+'frameSyndrome')[0]
assert P+'frameSyndrome(' in body(message,P+'decode')[0]

# Earlier shift/mask definitions remain live and byte-identical to generation 19.
altpath=Path('.lake/build/ir/Impl/Altitude.c');alt=altpath.read_text()
framepath=Path('.lake/build/ir/Impl/Frame.c');frame=framepath.read_text()
payloadpath=Path('.lake/build/ir/Impl/PayloadBits.c');payload=payloadpath.read_text()
bit=P+'Altitude_bit';gray=P+'Altitude_grayDecode'
grayfold='lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0'
identity=P+'identityCode';identitylambda=identity+'___lam__0';integer=P+'payloadInteger'
bitb=body(alt,bit)[0];grayb=body(alt,grayfold)[0];identityb=body(frame,identitylambda)[0];integerb=body(payload,integer)[0]
for value in [bitb,grayb,identityb,integerb,body(alt,gray)[0],body(frame,identity)[0]]:
    assert not any(x in value for x in ['lean_nat_pow(', 'lean_nat_div(', 'lean_nat_mod('])
assert bitb.index('lean_nat_shiftr(')<bitb.index('lean_nat_land(')
assert grayb.index('lean_nat_shiftr(')<grayb.index('lean_nat_lxor(') and 'goto _start;' in grayb
assert 'l_List_range(' in body(alt,gray)[0] and grayfold+'(' in body(alt,gray)[0]
assert identityb.index('lean_nat_shiftr(')<identityb.index('lean_nat_land(')
assert body(frame,identity)[0].count(identitylambda+'(')==12
assert integerb.count('lean_nat_shiftl(')==2 and 'lean_nat_sub(' in integerb and 'lean_int_sub(' in integerb
assert integer+'(' in body(payload,P+'payloadValue')[0]
bit_targets=[(bit,altpath,alt),(gray,altpath,alt),(grayfold,altpath,alt),(identity,framepath,frame),(integer,payloadpath,payload),(P+'payloadValue',payloadpath,payload)]

# Current exact byte batching and retained all-width fallback, inspected separately.
paritypath=Path('.lake/build/ir/Impl/Parity.c');parityc=paritypath.read_text()
parity_names=re.findall(r'LEAN_EXPORT [^\n]+ (\w+)\([^\n]*\)\{',parityc)
bytefold=next(n for n in parity_names if 'Nat_foldTR_loop' in n and n.endswith('Parity_syndromeBytes_spec__0___redArg'))
bitfold=next(n for n in parity_names if 'Nat_foldTR_loop' in n and n.endswith('Parity_syndromeBits_spec__0___redArg'))
ps=body(parityc,P+'Parity_syndrome')[0];pb=body(parityc,bytefold)[0];pf=body(parityc,bitfold)[0]
assert 'lean_unsigned_to_nat(128u)' in ps and 'lean_unsigned_to_nat(8u)' in ps
assert ps.count('lean_nat_dec_le(')==ps.count('lean_nat_mod(')==ps.count('lean_nat_dec_eq(')==1
assert ps.count(P+'Parity_syndromeBits(')==2 and ps.count(P+'Parity_syndromeBytes(')==1
assert ps.index('lean_nat_dec_le(')<ps.index('lean_nat_mod(')<ps.index(P+'Parity_syndromeBytes(')
assert 'lean_nat_shiftr(' in ps and 'lean_unsigned_to_nat(3u)' in ps
assert pb.count('lean_uint32_shift_left(')==pb.count('lean_uint32_xor(')==8 and pb.count('goto _start;')==1
assert pf.count('lean_uint32_shift_left(')==pf.count('lean_uint32_xor(')==1 and pf.count('goto _start;')==1
assert 'l_Nat_testBit(' in pf and 'l_Nat_testBit(' not in pb
for value in [pb,pf]:assert not any(x in value for x in ['l_List_range(', 'lean_box_uint32(', P+'Parity_wordStep('])
assert bytefold+'(' in body(parityc,P+'Parity_syndromeBytes')[0]
assert bitfold+'(' in body(parityc,P+'Parity_syndromeBits')[0]
parity_targets=[(P+'Parity_syndrome',paritypath,parityc),(P+'Parity_syndromeBytes',paritypath,parityc),(P+'Parity_syndromeBits',paritypath,parityc),(bytefold,paritypath,parityc),(bitfold,paritypath,parityc)]

anchors={old[k] for k in old if k.endswith('_anchor') and k!='parity_fold_anchor'}
anchors.update(old['integer_score_gate_anchors'].values())
anchors.update([bytefold,bitfold,P+'Parity_syndromeBytes',P+'Parity_syndromeBits'])
anchors.update([bit,gray,grayfold,identity,integer,T,F,Z,FI,fold,P+'packFields',P+'decode',P+'frameSyndrome',S+'powerTwo',S+'powerTwoFormula',S+'powerTwoTable___lam__0',ctor,init])
symbol_rows=[]
proc=subprocess.Popen(['nm','--defined-only',WORKER],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
for line in proc.stdout:
    if line.split() and line.split()[-1] in anchors:symbol_rows.append(line)
assert proc.wait()==0 and not proc.stderr.read()
present={line.split()[-1] for line in symbol_rows}
assert anchors-{old['byte_word_fallback_anchor']}<=present,anchors-present
symbols=D/'selected-symbols.txt';retain(symbols,''.join(symbol_rows).encode())
commands=[];excerpts={};assemblies={}
for name,path,text in [*parity_targets,*bit_targets,(fold,cpath,c),(P+'packFields',cpath,c),
                       (P+'frameSyndrome',message_path,message),(P+'decode',message_path,message),
                       *[(name,binarycpath,binaryc) for name in [S+'powerTwo',S+'powerTwoFormula',S+'powerTwoTable___lam__0',ctor,init]],
                       *[(name,floatpath,floatc) for name in [T,F,Z,FI,P+'CPR_Policy_haversineFloat',P+'CPR_Policy_decodeLocalFloat',P+'CPR_Policy_decodeGlobalFloat']]]:
    value,line=body(text,name);p=D/(name+'.generated-C.txt');retain(p,(value+'\n').encode())
    excerpts[name]={'source':str(path),'source_sha256':sha(path),'first_body_line':line,'path':str(p),'sha256':sha(p)}
    target=D/(name+'.assembly.txt');argv=['objdump','-d','--no-show-raw-insn','--disassemble='+name,WORKER]
    r=subprocess.run(argv,capture_output=True);assert r.returncode==0 and not r.stderr
    retain(target,r.stdout);assemblies[name]=r.stdout.decode()
    assert '<'+name+'>:' in assemblies[name]
    commands.append({'argv':argv,'output':str(target),'sha256':sha(target),'exit_code':0})
for symbol in [bit,gray,grayfold,identity,integer]:
    assert not any('<'+x+'>' in assemblies[symbol] for x in ['lean_nat_pow','lean_nat_div','lean_nat_mod'])
for symbol in [bit,grayfold,identity]:
    assert 'lean_nat_big_shiftr' in assemblies[symbol] and re.search(r'\bshr\b',assemblies[symbol])
assert '<lean_nat_shiftl>' in assemblies[integer]
assert '<'+integer+'>' in assemblies[P+'payloadValue']
assert '<'+identitylambda+'>' not in assemblies[identity]
fa=assemblies[fold]
assert '<lean_nat_shiftl>' in fa and '<lean_nat_pow>' in fa and '<lean_nat_mul>' not in fa
assert re.search(r'\bshl\b',fa) and re.search(r'\band\b',fa)
assert '<'+P+'packFields>' in assemblies[P+'frameSyndrome']
assert '<'+P+'frameSyndrome>' in assemblies[P+'decode']
assert '<'+S+'powerTwoFormula>' in assemblies[S+'powerTwo'] and '<'+S+'powerTwoTable>' in assemblies[S+'powerTwo']
assert re.search(r'mov\s+0x18\(%r14,%rcx,4\)',assemblies[S+'powerTwo'])
assert '<'+S+'powerTwoFormula>' in assemblies[S+'powerTwoTable___lam__0']
assert '<l_Array_ofFn___redArg>' in assemblies[ctor]
assert assemblies[init].index('<'+S+'powerTwoTable>')<assemblies[init].index('<lean_mark_persistent>')<assemblies[init].index('<'+S+'maxFinite___closed__3_once>')
assert '<'+ctor+'>' in assemblies[init] and '<lean_obj_once_cold>' in assemblies[init]
implementation=Path('tests/evidence/optimization/gen20/native-review/review.json')
ir=read(implementation);assert ir['status']=='passed' and ir['findings']==[] and ir['byte_crc_live_path_verified']
ni=read('tests/evidence/optimization/gen20/native-review/native-inputs.json')
assert ni['worker_sha256']==sha(WORKER)==bench['binary_sha256']
for name,digest in ni['held_inputs'].items():assert sha(name)==digest,name
for name,digest in ir['bindings'].items():assert sha(name)==digest,name
for name,row in ir['files'].items():assert sha(name)==row['sha256'] and Path(name).stat().st_size==row['bytes']

# Independently enumerate the linked wrapper's finite control graph. External
# tails are terminal; internal conditional branches keep both possible outcomes.
ins={}
for line in assemblies[T].splitlines():
    m=re.match(r'^\s*([0-9a-f]+):\s+(\S+)(?:\s+(.*))?$',line)
    if m:ins[int(m[1],16)]=(m[2],m[3] or '')
pcs=sorted(ins);successor=dict(zip(pcs,pcs[1:]));todo=[(pcs[0],0)];seen=set();terminal=[]
while todo:
    pc,n=todo.pop()
    if (pc,n) in seen:continue
    seen.add((pc,n));op,arg=ins[pc];symbol=re.search(r'<([^>]+)>',arg)
    symbol=symbol[1] if symbol else None
    if op.startswith('call') and symbol==F:n+=1
    assert n<=1
    if op.startswith('ret'):
        terminal.append({'address':hex(pc),'kind':'cached_zero_return','fallback_calls':n});continue
    if op.startswith('j'):
        target=re.match(r'^([0-9a-f]+)\s+<',arg);assert target,(pc,arg)
        target=int(target[1],16)
        if target in ins:todo.append((target,n))
        else:
            assert op=='jmp' and symbol in [F,'lean_float_of_bits','lean_float_once_cold'],(pc,symbol)
            terminal.append({'address':hex(pc),'kind':symbol,'fallback_calls':n+int(symbol==F)})
        if op=='jmp':continue
    if pc in successor:todo.append((successor[pc],n))
assert {r['kind'] for r in terminal}=={'cached_zero_return',F,'lean_float_of_bits','lean_float_once_cold'}
assert all(r['fallback_calls']==int(r['kind']==F) for r in terminal)
assert '<'+F+'>' in assemblies[T] and '<lean_float_once_cold>' in assemblies[T]
assert not any('<'+x in assemblies[T] for x in ['l_Rat_',P+'Binary64_'])
for name in ['round','exponent','powerTwo']:assert '<'+P+'Binary64_'+name+'>' in assemblies[F]
assert '<'+P+'Parity_syndromeBytes>' in assemblies[P+'Parity_syndrome'] and '<'+P+'Parity_syndromeBits>' in assemblies[P+'Parity_syndrome']
assert '<'+bytefold+'>' in assemblies[P+'Parity_syndromeBytes'] and '<'+bitfold+'>' in assemblies[P+'Parity_syndromeBits']
assert '<l_Nat_testBit>' not in assemblies[bytefold] and '<l_Nat_testBit>' in assemblies[bitfold]
for name in ['haversineFloat','decodeLocalFloat']:assert '<'+T+'>' in assemblies[P+'CPR_Policy_'+name]
assert '<'+T+'>' not in assemblies[P+'CPR_Policy_decodeGlobalFloat']
# A linked scalar once cell is lazy; the power table is independently forced at startup.
assert '<'+Z+'>' not in assemblies[FI] and '<lean_float_of_bits>' in assemblies[Z]
cfg={'status':'passed','wrapper':T,'assembly_sha256':sha(D/(T+'.assembly.txt')),'instruction_count':len(ins),'reachable_instruction_count':len({p for p,n in seen}),'terminal_states':terminal,'at_most_one_fallback_per_entry':True,'zero_case':'Cached positive zero or its lazy scalar initialization; neither executes fallback.','limits':'Static branch partition only. Wrapper minus observed direct fallback calls includes both zero and accepted dyadics, not a measured pure fast-path population.'}
save(E/'independent-review/tofloat-control-flow.json',cfg)

out={k:old[k] for k in old if k.endswith('_verified') or k.endswith('_anchor') or k=='integer_score_gate_anchors'}
out.update(status='passed_read_only_source_and_native_review',recorded_utc=datetime.now(timezone.utc).isoformat(),
    commit=build['commit'],timed_commit=bench['commit'],binary_sha256=sha(WORKER),
    benchmark_source_binding_sha256=sha(binding_path),fresh_native_inputs=str(native_path),
    fresh_native_inputs_sha256=sha(native_path),fresh_project_modules_verified=22,
    source_C_object_trace_bindings=bindings,driver_build_manifest=str(build_path),
    driver_build_manifest_sha256=sha(build_path),driver_binary_sha256=sha('.cache/gen20-costs/driver/decode-costs'),
    reused_production_objects_verified=21,unchanged_driver_input_hashes_verified=len(held),
    eager_table_initializers=old['eager_table_initializers'],
    live_generated_C={path:sha(path) for path in old['live_generated_C']},
    pack_fields_shift_mask_verified=True,pack_fields_fold_anchor=fold,
    power_two_table_live_path_verified=True,power_two_lookup_anchor=S+'powerTwo',
    power_two_formula_anchor=S+'powerTwoFormula',power_two_table_entry_anchor=S+'powerTwoTable___lam__0',
    power_two_table_initializer_anchor=ctor,power_two_module_initializer_anchor=init,
    commands=commands,generated_C_excerpts=excerpts,
    symbol_inventory={'path':str(symbols),'sha256':sha(symbols),'filtered':True},
    unchanged_native_modules=unchanged,
    previous_source_review={'path':str(oldpath),'sha256':sha(oldpath),
        'basis':'All 21 sibling source/C/object/trace sets match generation 19 byte-for-byte. Only Parity changes; current byte and fallback loops plus unchanged conversion/power paths are independently rebound.'},
    implementation_native_review={'path':str(implementation),'sha256':sha(implementation)},
    byte_crc_live_path_verified=True,parity_fold_anchor=bytefold,parity_byte_fold_anchor=bytefold,parity_bit_fold_anchor=bitfold,
    parity_byte_wrapper_anchor=P+'Parity_syndromeBytes',parity_bit_wrapper_anchor=P+'Parity_syndromeBits',
    parity_loop_observation_limit='Both loop anchors are callable. Native entries are measured separately; equivalent bit-update counts and byte-iteration counts are census predictions, not standalone unrolled step calls.',
    systematic_bit_extraction_verified=True,altitude_bit_anchor=bit,altitude_gray_anchor=gray,altitude_gray_fold_anchor=grayfold,identity_code_anchor=identity,payload_integer_anchor=integer,identity_lambda_inlined=True,
    dyadic_to_float_live_path_verified=True,dyadic_to_float_anchor=T,dyadic_to_float_fallback_anchor=F,
    dyadic_to_float_at_most_one_fallback_per_entry=True,dyadic_to_float_zero_case_verified=True,
    dyadic_to_float_control_flow={'path':str(E/'independent-review/tofloat-control-flow.json'),'sha256':sha(E/'independent-review/tofloat-control-flow.json')},
    review_script=str(Path(__file__)),review_script_sha256=sha(__file__),findings=[],
    reviewer_attempts=[{'path':str(E/'independent-review/source-attempt-01/execution.json'),'sha256':sha(E/'independent-review/source-attempt-01/execution.json'),'finding':'Reviewer expected wrappers to inline into syndrome. Actual native code retains callable syndromeBytes/syndromeBits, each tail-calling its correct fold; checker now captures and verifies both edges. Producer/native sources were unchanged.'}],
    observations=['The live inclusive [-1074,1023] guard selects one immutable indexed table read; both outside-range branches call the exact original formula.',
        'The table entry constructor calls only powerTwoFormula, and the complete2098-entry array is forced/persisted during module initialization before worker execution.',
        'The prior complete initialization-chain disassembly is rebound to the same actual worker hash; no timing, exponent distribution or table hit rate is inferred.',
        'The current bit/Gray/identity/signed-field bodies have no direct power/division calls; arbitrary-size Nat fallbacks and unchanged caller routing remain. Inlined identity-lambda work is not treated as zero work.',
        'All prior decoder paths are still linked; packFields retains its exact Nat-shift and bounded machine-mask/fallback branches.',
        'Only Parity changed among the 22 linked sets; all 21 sibling sets, including CPRFloat, remain byte-identical to generation 19.',
        'toFloat packs exact bits on accepted dyadics, delegates at most once to the unchanged fallback on rejection, and returns cached or lazily initialized positive zero on zero input.',
        'smallDyadicBits is inlined. The wrapper retains decimal parsing and generic Nat/Int allocation; no allocation-free or measured fast-path-frequency claim is made.'],
    limits='Read-only source/generated-C/native inspection; no builds, decoder executions, timing or profiles. Actual branch populations and instruction costs require the later raw recount. Historical content is referenced by existing hashes rather than recopied.')
for name,digest in held.items():assert sha(name)==digest,name
assert sha(WORKER)==bench['binary_sha256']
save(E/'independent-review/source-review.json',out)
print(json.dumps({'status':'passed','source_review_sha256':sha(E/'independent-review/source-review.json'),
                  'native_sets':22,'unchanged_other_sets':len(unchanged),'targeted_assembly_commands':len(commands)}))

