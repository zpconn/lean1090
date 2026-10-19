"""Read-only source/native association; no build or decoder execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
from collections import deque
import hashlib, importlib.util, json, re, subprocess

E = Path('tests/evidence/diagnostics/gen23')
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

build_path=Path('.cache/gen23-costs/driver/driver-build.json')
build=read(build_path); bench=read('bench/runs/gen23/summary.json')
native_path=Path('bench/runs/gen23/fresh-native-inputs.json'); native=read(native_path)
oldpath=Path('tests/evidence/diagnostics/gen22/independent-review/source-review.json'); old=read(oldpath)
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
assert bind_benchmark_history.inspect(build_path,Path('bench/runs/gen23/summary.json'),None,
    Path('bench/runs/gen23/correctness-inputs.json'))==read(binding_path)

old_native={r['source']:r for r in read('bench/runs/gen22/fresh-native-inputs.json')}
unchanged=[]
for row in native:
    if row['source'] in {'Impl/CommB.lean'}:continue
    before=old_native[row['source']]
    assert row['source_sha256']==before['source_sha256'],row['source']
    assert {p:r['sha256'] for p,r in row['artifacts'].items()}=={p:r['sha256'] for p,r in before['artifacts'].items()},row['source']
    unchanged.append(row['source'])
assert len(unchanged)==21
# CPRFloat source and native artifacts are unchanged since generation18.
oldfloat=subprocess.check_output(['git','cat-file','blob',read('bench/runs/gen22/summary.json')['commit']+':Impl/CPRFloat.lean'],text=True)
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
decodebody=body(message,P+'decode')[0]
assert decodebody.count(P+'decodeFrameWithWord(')==decodebody.count(P+'Parity_syndrome(')==decodebody.count(P+'reportWithSyndrome(')==1
assert not any(P+n+'(' in decodebody for n in ['frameSyndrome','Parity_checksum','frameParts','packFields','bytesValue','decodeFrame'])

# Earlier shift/mask definitions remain live and byte-identical to generation 19.
altpath=Path('.lake/build/ir/Impl/Altitude.c');alt=altpath.read_text()
framepath=Path('.lake/build/ir/Impl/Frame.c');frame=framepath.read_text()
payloadpath=Path('.lake/build/ir/Impl/PayloadBits.c');payload=payloadpath.read_text()
parser=body(frame,P+'decodeFrameWithWord')[0];projection=body(frame,P+'decodeFrame')[0]
info=body(frame,P+'informationBits')[0]
assert parser.count(P+'bytesValue(')==1
assert parser.index('l_List_head_x3f___redArg')<parser.index('l_List_lengthTR___redArg')<parser.index(P+'bytesValue(')
assert 'v___x_60_ = '+P+'bytesValue(v_bytes_43_);' in parser and 'lean_ctor_set(v___x_67_, 1, v___x_60_);' in parser
assert 'v_snd_271_ = lean_ctor_get(v_val_266_, 1);' in decodebody and P+'Parity_syndrome(v___x_278_, v_snd_271_)' in decodebody
assert P+'informationBits(v_body_275_)' in decodebody and 'lean_unsigned_to_nat(24u)' in decodebody and 'lean_nat_add(v___x_276_, v___x_277_)' in decodebody
assert info.count('lean_unsigned_to_nat(32u)')==3 and info.count('lean_unsigned_to_nat(88u)')==1
assert decodebody.index(P+'Parity_syndrome(')<decodebody.index(P+'frameAcceptedWithSyndrome(')<decodebody.index(P+'reportWithSyndrome(')
assert projection.count(P+'decodeFrameWithWord(')==1 and 'lean_ctor_get(v_val_145_, 0)' in projection
raw_targets=[(P+'decodeFrameWithWord',framepath,frame),(P+'decodeFrame',framepath,frame),(P+'informationBits',framepath,frame),(P+'reportWithSyndrome',message_path,message)]

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

# Current integer affine normalization is inlined in the actual payloadValue.
pv=body(payload,P+'payloadValue')[0]
assert pv.count('lean_int_mul(')==pv.count('lean_nat_gcd(')==1
assert 'lean_nat_abs(' in pv and 'lean_int_div_exact(' in pv and 'lean_nat_div_exact(' in pv
assert 'l_Rat_mul(' not in pv and 'lean_float' not in pv
assert pv.count('l_instDecidableEqRat_decEq(')==2 and pv.count('l_Rat_ofInt(')==pv.count('l_Rat_add(')==1
assert pv.count(P+'payloadBits(')==2 and 'lean_box(0)' in pv and P+'payloadInteger(' in pv
assert P+'integerScale(' not in pv and P+'affineValue(' not in pv
integer_scale_c=body(payload,P+'integerScale')[0]
assert integer_scale_c.count('lean_int_mul(')==integer_scale_c.count('lean_nat_gcd(')==1

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

# Fresh current CommB C and actual linked bodies; historical capture is only a
# bounded symbol selection, never evidence for a missing current symbol.
commb_path=Path('.lake/build/ir/Impl/CommB.c');commb_c=commb_path.read_text()
validity_helpers=['cbSelectedValid40','cbQNHValid40','cbRollValid50','cbMachValid60','cbVerticalValid60']
validity_tables=[n+'Table' for n in validity_helpers]
prior_validity_capture=read('tests/evidence/optimization/gen23/native-review/native-inputs.json')
validity_target_names={n for n,row in prior_validity_capture['generated_c_excerpts'].items() if row['source']==str(commb_path)}
assert {P+'cbValid'+str(n) for n in [40,50,60]} <= validity_target_names
validity_targets=[(n,commb_path,commb_c) for n in sorted(validity_target_names)]

anchors={old[k] for k in old if k.endswith('_anchor') and k!='parity_fold_anchor' and old[k] is not None}
anchors.update(old['integer_score_gate_anchors'].values())
anchors.update([bytefold,bitfold,P+'Parity_syndromeBytes',P+'Parity_syndromeBits'])
anchors.update([P+'CPR_Policy_haversineFloat',P+'CPR_Policy_decodeLocalFloat',P+'CPR_Policy_decodeGlobalFloat'])
anchors.update([P+'decodeFrameWithWord',P+'decodeFrame',P+'Parity_syndrome',P+'informationBits',P+'reportWithSyndrome',P+'Parity_checksum',P+'frameParts'])
anchors.update([bit,gray,grayfold,identity,integer,T,F,Z,FI,fold,P+'packFields',P+'decode',P+'frameSyndrome',S+'powerTwo',S+'powerTwoFormula',S+'powerTwoTable___lam__0',ctor,init])
anchors.update(validity_target_names)
symbol_rows=[]
proc=subprocess.Popen(['nm','--defined-only',WORKER],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
for line in proc.stdout:
    if line.split() and line.split()[-1] in anchors:symbol_rows.append(line)
assert proc.wait()==0 and not proc.stderr.read()
present={line.split()[-1] for line in symbol_rows}
removed_main_boundaries={fold,P+'packFields',P+'frameSyndrome',P+'Parity_checksum',P+'frameParts',P+'decodeFrame'}
assert anchors-removed_main_boundaries-validity_target_names-{old['byte_word_fallback_anchor']}<=present,anchors-present
assert not (removed_main_boundaries & present),removed_main_boundaries & present
symbols=D/'selected-symbols-complete.txt';retain(symbols,''.join(symbol_rows).encode())
commands=[];excerpts={};assemblies={}
for name,path,text in [*validity_targets,*raw_targets,*parity_targets,*bit_targets,(fold,cpath,c),(P+'packFields',cpath,c),
                       (P+'frameSyndrome',message_path,message),(P+'decode',message_path,message),
                       *[(name,binarycpath,binaryc) for name in [S+'powerTwo',S+'powerTwoFormula',S+'powerTwoTable___lam__0',ctor,init]],
                       *[(name,floatpath,floatc) for name in [T,F,Z,FI,P+'CPR_Policy_haversineFloat',P+'CPR_Policy_decodeLocalFloat',P+'CPR_Policy_decodeGlobalFloat']]]:
    value,line=body(text,name);p=D/(name+'.generated-C.txt');retain(p,(value+'\n').encode())
    excerpts[name]={'source':str(path),'source_sha256':sha(path),'first_body_line':line,'path':str(p),'sha256':sha(p)}
    if name in removed_main_boundaries or (name in validity_target_names and name not in present):continue  # Explicit current symbol absence is retained; C bodies still captured.
    target=D/(name+'.assembly.txt');argv=['objdump','-d','--no-show-raw-insn','--disassemble='+name,WORKER]
    r=subprocess.run(argv,capture_output=True);assert r.returncode==0 and not r.stderr
    retain(target,r.stdout);assemblies[name]=r.stdout.decode()
    assert '<'+name+'>:' in assemblies[name]
    commands.append({'argv':argv,'output':str(target),'sha256':sha(target),'exit_code':0})
# Five immutable field-code arrays replace only the selected validity predicates.
validity_required={P+'cbValid'+str(n) for n in [40,50,60]}|{P+n for n in ['bdsWireValid','decodeBDS','commBCoreEligible','commBEligible','commBValue','cbPenalty']}|{'initialize_lean1090_Impl_CommB'}
assert validity_required<=present
assert not ({P+n for n in validity_helpers}&present)
for n in validity_helpers:
    v=body(commb_c,P+n)[0]
    assert v.count(P+'payloadBits(')==v.count('lean_array_fget_borrowed(')==1
    assert 'lean_unbox(' in v and P+n+'Table' in v
    assert not any(x in v for x in ['l_Rat_','Binary64_','lean_alloc_ctor','lean_obj_once'])
def validity_calls(text):return re.findall(r'(?:call|jmp)\s+[^<]*<([^>+]+)>',text)
validity_layout={40:['cbSelectedValid40Table','cbQNHValid40Table'],50:['cbRollValid50Table'],60:['cbMachValid60Table','cbVerticalValid60Table']}
validity_observations={}
for r in [40,50,60]:
    n=P+'cbValid'+str(r);v=body(commb_c,n)[0];a=assemblies[n];calls=validity_calls(a)
    for table in validity_layout[r]:assert '<'+P+table+'>' in a
    expected={40:3,50:1,60:2}[r]
    assert len(re.findall(r'mov\s+0x18\([^\n]*,4\)',a))==expected
    assert not any('Rat_' in x or 'Binary64_' in x for x in calls)
    assert calls.count(P+'cbStatus')=={40:3,50:5,60:5}[r]
    assert P+'payloadBits' in calls and 'lean_nat_big_' in a
    validity_observations[str(r)]={'anchor':n,'tables':[P+t for t in validity_layout[r]],'indexed_boolean_load_sites':expected,'direct_call_targets':sorted(set(calls))}
for caller,callees in {'bdsWireValid':['cbValid40','cbValid50','cbValid60'],'decodeBDS':['bdsWireValid'],'commBCoreEligible':['bdsWireValid','cbScorePasses'],'commBEligible':['commBCoreEligible'],'commBValue':['cbSelected','cbVertical60','payloadValue'],'cbPenalty':['commBValue','cbRatioOutside250800','cbWindPenalty50']}.items():
    calls=validity_calls(assemblies[P+caller])
    assert all(P+n in calls for n in callees)
validity_init='initialize_lean1090_Impl_CommB';vinit=body(commb_c,validity_init)[0];vainit=assemblies[validity_init]
for table in validity_tables:
    n=P+table;constructor='_init_'+n
    assert n+' = '+constructor+'();' in vinit and 'lean_mark_persistent('+n+');' in vinit
    assert '<'+n+'>' in vainit and '<'+constructor+'___closed__1>' in vainit
    assert n+'___closed__1' in body(commb_c,constructor)[0]
for table,count in [('cbSelectedValid40Table',4096),('cbRollValid50Table',1024),('cbVerticalValid60Table',1024)]:
    n='_init_'+P+table+'___closed__1';v=body(commb_c,n)[0];a=assemblies[n]
    assert f'lean_unsigned_to_nat({count}u)' in v and 'l_Array_ofFn___redArg(' in v
    assert 'l_Array_ofFn___redArg' in validity_calls(a) and hex(2*count+1) in a
for table,values in [('cbQNHValid40Table','cbQNHValueTable'),('cbMachValid60Table','cbMachValueTable')]:
    assert vinit.index('lean_mark_persistent('+P+values+');')<vinit.index(P+table+' =')
    size=body(commb_c,'_init_'+P+table+'___closed__0')[0];construct=body(commb_c,'_init_'+P+table+'___closed__1')[0]
    assert P+values in size and 'lean_array_size' in size and P+values in construct and '((size_t)0ULL)' in construct
    mapper=next(n for n in validity_target_names if n.startswith('lp_lean1090___private_') and table+'_spec__0' in n)
    v=body(commb_c,mapper)[0]
    assert all(x in v for x in ['lean_usize_dec_lt','lean_array_uget','lean_array_uset','lean_usize_add','goto _start;','l_Rat_instDecidableLe'])
    assert 'l_Rat_instDecidableLe' in validity_calls(assemblies[mapper])
validity_context={'status':'passed','worker_sha256':sha(WORKER),'validity':validity_observations,'lookup_helpers':{P+n:None for n in validity_helpers},'table_entries':[4096,4096,1024,1024,1024],'total_boolean_entries':11264,'table_constructor_anchors':{n:'_init_'+P+n+'___closed__1' for n in validity_tables},'module_initializer_anchor':validity_init,'current_symbol_boundaries':{n:n if n in present else None for n in sorted(validity_target_names)},'limits':'Static indexed loads, callable boundaries and eager construction only. Helpers inline into cbValid40/50/60; no corpus hit rate, entry count, startup cost or allocation-free claim. Original numerical projection and score/penalty paths remain live.'}
save(E/'independent-review/validity-table-native-context.json',validity_context)

for symbol in [bit,gray,grayfold,identity,integer]:
    assert not any('<'+x+'>' in assemblies[symbol] for x in ['lean_nat_pow','lean_nat_div','lean_nat_mod'])
for symbol in [bit,grayfold,identity]:
    assert 'lean_nat_big_shiftr' in assemblies[symbol] and re.search(r'\bshr\b',assemblies[symbol])
assert '<lean_nat_shiftl>' in assemblies[integer]
assert '<'+integer+'>' in assemblies[P+'payloadValue']
assert '<l_Rat_mul>' not in assemblies[P+'payloadValue']
for target in ['lean_nat_gcd','lean_int_big_mul','lean_int_big_div_exact','lean_nat_big_div_exact','l_Rat_ofInt','l_Rat_add']:
    assert '<'+target+'>' in assemblies[P+'payloadValue']
assert '<'+identitylambda+'>' not in assemblies[identity]
# Current linked main directly consumes the parser pair; old reconstruction
# definitions remain in C/object but are absent as timed callable boundaries.
def asm_rows(text):
    rows=[]
    for line in text.splitlines():
        m=re.match(r'\s*([0-9a-f]+):\s+(\S+)\s*(.*)',line)
        if m:rows.append(dict(address=int(m[1],16),op=m[2],arg=m[3]))
    assert rows
    return rows

def call_targets(rows):
    return [m[1] for r in rows if r['op'] in ('call','jmp') and (m:=re.search(r'<([^>]+)>',r['arg']))]

def cfg_counts(rows,symbols):
    by={r['address']:i for i,r in enumerate(rows)};todo=[(0,(0,)*len(symbols))];seen=set();term=set()
    while todo:
        i,counts=todo.pop()
        if (i,counts) in seen:continue
        seen.add((i,counts));r=rows[i]
        counts=tuple(n+int(r['op']=='call' and '<'+symbol+'>' in r['arg']) for n,symbol in zip(counts,symbols))
        assert max(counts,default=0)<=1
        m=re.match(r'([0-9a-f]+) ',r['arg']) if r['op'].startswith('j') else None;target=int(m[1],16) if m else None
        if r['op'].startswith('ret') or (r['op']=='jmp' and target not in by):term.add(counts);continue
        if r['op'].startswith('j'):
            assert target in by
            todo.append((by[target],counts))
            if r['op']=='jmp':continue
        if i+1<len(rows):todo.append((i+1,counts))
    return sorted(term),len(seen)

main_rows=asm_rows(assemblies[P+'decode']);parser_rows=asm_rows(assemblies[P+'decodeFrameWithWord'])
main_calls=call_targets(main_rows);parser_calls=call_targets(parser_rows)
assert all(main_calls.count(P+n)==1 for n in ['decodeFrameWithWord','Parity_syndrome','reportWithSyndrome'])
assert parser_calls.count(P+'bytesValue')==1
assert not any(P+n in main_calls for n in ['frameSyndrome','Parity_checksum','frameParts','packFields','bytesValue','decodeFrame'])
assert P+'adsbHardValid' in main_calls
ma='\n'.join(r['op']+' '+r['arg'] for r in main_rows);pa='\n'.join(r['op']+' '+r['arg'] for r in parser_rows)
assert 'mov 0x10(%r13),%r12' in ma and 'mov %r12,%rsi' in ma
assert 'mov %rax,%r14' in pa and 'mov %r14,0x10(%rax)' in pa
main_counts,main_states=cfg_counts(main_rows,[P+'decodeFrameWithWord',P+'Parity_syndrome',P+'reportWithSyndrome'])
parser_counts,parser_states=cfg_counts(parser_rows,[P+'bytesValue'])
assert main_counts==[(1,0,0),(1,1,0),(1,1,1)] and parser_counts==[(0,),(1,)]
obj=Path('.lake/build/ir/Impl/Frame.c.o.export');argv=['objdump','-dr','--no-show-raw-insn','--disassemble='+P+'decodeFrame',str(obj)]
r=subprocess.run(argv,capture_output=True);assert r.returncode==0 and not r.stderr
objout=D/'public-parser-object.assembly.txt';retain(objout,r.stdout)
assert 'R_X86_64_PLT32\t'+P+'decodeFrameWithWord-0x4' in r.stdout.decode()
commands.append({'argv':argv,'output':str(objout),'sha256':sha(objout),'exit_code':0})
raw_context={'status':'passed','decode_frame_with_word_anchor':P+'decodeFrameWithWord','raw_syndrome_anchor':P+'Parity_syndrome','possible_main_call_counts':main_counts,'possible_parser_byte_fold_counts':parser_counts,'main_cfg_states':main_states,'parser_cfg_states':parser_states,'old_timed_boundaries_absent':sorted(removed_main_boundaries),'public_parser_object_sha256':sha(obj),'public_parser_object_assembly_sha256':sha(objout),'limits':'Actual static call sites/data flow, not observed corpus entry populations. Pair/frame/message allocation and ownership reuse remain.'}
raw_context_path=E/'independent-review/raw-word-control-flow.json'
if raw_context_path.exists():assert read(raw_context_path)==json.loads(json.dumps(raw_context))  # Preserve exact successful partial capture from retained reviewer attempt.
else:save(raw_context_path,raw_context)
assert '<'+S+'powerTwoFormula>' in assemblies[S+'powerTwo'] and '<'+S+'powerTwoTable>' in assemblies[S+'powerTwo']
assert re.search(r'mov\s+0x18\(%r14,%rcx,4\)',assemblies[S+'powerTwo'])
assert '<'+S+'powerTwoFormula>' in assemblies[S+'powerTwoTable___lam__0']
assert '<l_Array_ofFn___redArg>' in assemblies[ctor]
assert assemblies[init].index('<'+S+'powerTwoTable>')<assemblies[init].index('<lean_mark_persistent>')<assemblies[init].index('<'+S+'maxFinite___closed__3_once>')
assert '<'+ctor+'>' in assemblies[init] and '<lean_obj_once_cold>' in assemblies[init]
implementation=Path('tests/evidence/optimization/gen23/native-review/review.json')
ir=read(implementation);assert ir['status']=='passed' and ir['findings']==[] and ir['commb_validity_tables_live_path_verified']
ni=read('tests/evidence/optimization/gen23/native-review/native-inputs.json')
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
    driver_build_manifest_sha256=sha(build_path),driver_binary_sha256=sha('.cache/gen23-costs/driver/decode-costs'),
    reused_production_objects_verified=21,unchanged_driver_input_hashes_verified=len(held),
    eager_table_initializers=old['eager_table_initializers']+validity_tables,
    live_generated_C={path:sha(path) for path in old['live_generated_C']},
    pack_fields_shift_mask_verified=True,pack_fields_fold_anchor=None,
    power_two_table_live_path_verified=True,power_two_lookup_anchor=S+'powerTwo',
    power_two_formula_anchor=S+'powerTwoFormula',power_two_table_entry_anchor=S+'powerTwoTable___lam__0',
    power_two_table_initializer_anchor=ctor,power_two_module_initializer_anchor=init,
    commands=commands,generated_C_excerpts=excerpts,
    symbol_inventory={'path':str(symbols),'sha256':sha(symbols),'filtered':True},
    unchanged_native_modules=unchanged,
    previous_source_review={'path':str(oldpath),'sha256':sha(oldpath),
        'basis':'All 21 sibling source/C/object/trace sets match generation 22 byte-for-byte. Only CommB changes; its five validity tables and current callable paths are inspected from current C and linked worker, while parser/arithmetic/CRC/conversion paths are rebound.'},
    implementation_native_review={'path':str(implementation),'sha256':sha(implementation)},
    byte_crc_live_path_verified=True,parity_fold_anchor=bytefold,parity_byte_fold_anchor=bytefold,parity_bit_fold_anchor=bitfold,
    parity_byte_wrapper_anchor=P+'Parity_syndromeBytes',parity_bit_wrapper_anchor=P+'Parity_syndromeBits',
    parity_loop_observation_limit='Both loop anchors are callable. Native entries are measured separately; equivalent bit-update counts and byte-iteration counts are census predictions, not standalone unrolled step calls.',
    systematic_bit_extraction_verified=True,altitude_bit_anchor=bit,altitude_gray_anchor=gray,altitude_gray_fold_anchor=grayfold,identity_code_anchor=identity,payload_integer_anchor=integer,identity_lambda_inlined=True,
    dyadic_to_float_live_path_verified=True,dyadic_to_float_anchor=T,dyadic_to_float_fallback_anchor=F,
    dyadic_to_float_at_most_one_fallback_per_entry=True,dyadic_to_float_zero_case_verified=True,
    dyadic_to_float_control_flow={'path':str(E/'independent-review/tofloat-control-flow.json'),'sha256':sha(E/'independent-review/tofloat-control-flow.json')},
    commb_validity_tables_live_path_verified=True,
    commb_validity_anchors={k:v['anchor'] for k,v in validity_observations.items()},
    commb_validity_lookup_anchors=validity_context['lookup_helpers'],
    commb_validity_table_constructor_anchors=validity_context['table_constructor_anchors'],
    commb_validity_module_initializer_anchor=validity_init,
    commb_validity_context={'path':str(E/'independent-review/validity-table-native-context.json'),'sha256':sha(E/'independent-review/validity-table-native-context.json')},
    review_script=str(Path(__file__)),review_script_sha256=sha(__file__),findings=[],
    reviewer_attempts=[{'path':str(p),'sha256':sha(p),**read(p)} for p in sorted((E/'independent-review').glob('source-attempt-*/execution.json'))],
    raw_word_syndrome_live_path_verified=True,decode_frame_with_word_anchor=P+'decodeFrameWithWord',
    raw_syndrome_anchor=P+'Parity_syndrome',raw_word_control_flow={'path':str(E/'independent-review/raw-word-control-flow.json'),'sha256':sha(E/'independent-review/raw-word-control-flow.json')},
    absent_old_timed_boundaries=sorted(removed_main_boundaries),
    integer_affine_normalization_live_path_verified=True,payload_value_anchor=P+'payloadValue',
    integer_affine_normalization_anchors={'payloadValue':P+'payloadValue','integerScale':None,'affineValue':None,'gcd':'lean_nat_gcd','big_product':'lean_int_big_mul'},
    integer_affine_normalization_limit='integerScale and affineValue inline into payloadValue. Actual payloadValue entries and direct children are separately observable; absent wrappers do not imply zero cost. Status/unit/offset branches remain. Generic big-integer and ownership paths remain.',
    observations=['The live inclusive [-1074,1023] guard selects one immutable indexed table read; both outside-range branches call the exact original formula.',
        'The table entry constructor calls only powerTwoFormula, and the complete 2098-entry array is forced/persisted during module initialization before worker execution.',
        'The prior complete initialization-chain disassembly is rebound to the same actual worker hash; no timing, exponent distribution or table hit rate is inferred.',
        'The current bit/Gray/identity/signed-field bodies have no direct power/division calls; arbitrary-size Nat fallbacks and unchanged caller routing remain. Inlined identity-lambda work is not treated as zero work.',
        'The current main calls the paired parser once and uses its returned full Nat word for CRC, with no reread or reconstruction. Public decodeFrame remains a projection in its object; standalone reconstruction definitions remain available but are absent from the timed linked symbols. Absence alone is not an inlining claim.',
        'Only CommB changed among the 22 linked sets; all 21 siblings, including Frame, Message, PayloadBits, Parity and CPRFloat, remain byte-identical to generation 22.',
        'toFloat packs exact bits on accepted dyadics, delegates at most once to the unchanged fallback on rejection, and returns cached or lazily initialized positive zero on zero input.',
        'payloadValue retains one exact numerator-product/gcd normalization site in the nonunit branch, with no Rat.mul call; unit scale and zero offset still bypass their identity operations.',
        'smallDyadicBits is inlined. The wrapper retains decimal parsing and generic Nat/Int allocation; no allocation-free or measured fast-path-frequency claim is made.'],
    limits='Read-only source/generated-C/native inspection; no builds, decoder executions, timing or profiles. Actual branch populations and instruction costs require the later raw recount. Historical content is referenced by existing hashes rather than recopied.')
for name,digest in held.items():assert sha(name)==digest,name
assert sha(WORKER)==bench['binary_sha256']
save(E/'independent-review/source-review.json',out)
print(json.dumps({'status':'passed','source_review_sha256':sha(E/'independent-review/source-review.json'),
                  'native_sets':22,'unchanged_other_sets':len(unchanged),'targeted_assembly_commands':len(commands)}))

