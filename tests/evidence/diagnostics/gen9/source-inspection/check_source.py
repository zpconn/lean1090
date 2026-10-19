"""Read-only source/native binding review; no decoder/build execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,re,shlex,subprocess
E=Path('tests/evidence/diagnostics/gen9'); D=E/'source-inspection'; P='lp_lean1090_Lean1090_Impl_'
load=lambda p:json.loads(Path(p).read_text())
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
bench=load('bench/runs/gen9/summary.json');commit=bench['commit'];native_path=Path('bench/runs/gen9/fresh-native-inputs.json');native=load(native_path)
worker='.lake/build/bin/lean1090-bench';build_path=Path('.cache/gen10-planning/driver/driver-build.json');build=load(build_path)
assert build['status']=='passed' and build['commit']==commit and sha(worker)==bench['binary_sha256']
assert build['fresh_benchmark_native_binding']['sha256']==sha(native_path)
assert build['fresh_benchmark_native_binding']['sources_generated_c_objects_and_traces_match']
assert len(native)==build['fresh_benchmark_native_binding']['linked_project_objects']==22
bindings={};objects={}
for row in native:
 source=row['source'];digest=row['source_sha256']
 assert sha(source)==digest==hashlib.sha256(subprocess.check_output(['git','cat-file','blob',commit+':'+source])).hexdigest()
 assert build['linked_project_inventory']['sources'][source]==digest
 artifacts={}
 for name,record in row['artifacts'].items():
  assert sha(name)==record['sha256']==build['unchanged_native_inputs'][name]
  artifacts[name]=record['sha256']
  if name.endswith('.c.o.export'):objects[name]=record['sha256']
 bindings[source]={'source_sha256':digest,'artifacts':artifacts}
assert objects==build['linked_project_inventory']['objects']
assert build['reused_production_object_count']==len(build['reused_production_objects'])==21
assert build['reused_production_objects']=={k:v for k,v in objects.items() if k!=build['linked_project_inventory']['worker_object']}
for name,digest in build['unchanged_native_inputs'].items():assert sha(name)==digest,name
for name,digest in build['artifacts'].items():assert sha(name)==digest,name
assert all(sha(name)==digest for name,digest in build['production_sources'].items())
for name,record in load('bench/runs/gen9/binary-built.json')['native_hashes'].items():assert sha(name)==record,name
oldbuild=load('tests/evidence/diagnostics/gen8/driver/driver-build.json')
assert objects['.lake/build/ir/Impl/Bits.c.o.export'] != oldbuild['reused_production_objects']['.lake/build/ir/Impl/Bits.c.o.export']
for path, digest in objects.items():
 if path not in [build['linked_project_inventory']['worker_object'], '.lake/build/ir/Impl/Bits.c.o.export']:
  assert digest == oldbuild['reused_production_objects'][path], path
# Inspect generated bodies and the preserved disassembly from this exact worker.
def body(c,name):
 pattern=r'LEAN_EXPORT [^\n]+ '+re.escape(name)+r'\([^\n]*\)\{'
 m=re.search(pattern,c);assert m,name
 start=m.end()-1;depth=0
 for end in range(start,len(c)):
  depth+=(c[end]=='{')-(c[end]=='}')
  if depth==0:return c[start:end+1]
 raise AssertionError(name)
payload=Path('.lake/build/ir/Impl/PayloadBits.c').read_text();pb=body(payload,P+'payloadBits')
assert pb.count('lean_nat_pow(')==2 and 'lean_nat_div(' in pb and 'lean_nat_mod(' in pb
fast=pb.split('\nelse\n',1)[1]
assert not any(x in fast for x in ['lean_nat_pow(', 'lean_nat_div(', 'lean_nat_mod('])
assert all(x in fast for x in ['lean_uint64_of_nat(', 'lean_uint64_shift_right(', 'lean_uint64_shift_left(', 'lean_uint64_sub(', 'lean_uint64_land(', 'lean_uint64_to_nat('])
symbols=(D/'symbols.txt').read_text();names={x.split()[-1] for x in symbols.splitlines() if x.split()}
anchors=[P+'Parity_syndrome','lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0',P+'Parity_checksum',P+'ScoreGate_choose',P+'cbScorePasses___lam__0___boxed',P+'payloadBits']
commands=[]
for anchor in anchors:
 assert anchor in names
 path=D/(anchor+'.assembly.txt');assembly=path.read_text();assert '<'+anchor+'>:' in assembly
 commands.append({'argv':['objdump','-d','--no-show-raw-insn','--disassemble='+anchor,worker],'output':str(path),'sha256':sha(path)})
assert P+'payloadWordBits' not in names and P+'Parity_wordBit' not in names and P+'Parity_cachedBit' not in names
pa=(D/(P+'payloadBits.assembly.txt')).read_text()
assert len(re.findall(r'call\s+[0-9a-f]+ <lean_nat_pow>',pa))==2
assert all(re.search(r'\t'+op+r'\s',pa) for op in ['shr','shl','not','and'])
assert 'lean_uint64_of_big_nat' in pa and 'lean_nat_big_div' in pa and 'lean_nat_big_mod' in pa
fa=(D/(anchors[1]+'.assembly.txt')).read_text();assert '\tbt ' in fa and '<l_Nat_testBit>' in fa
assert '<lean_apply_1>' in (D/(P+'ScoreGate_choose.assembly.txt')).read_text()
fb=(D/(P+'cbScorePasses___lam__0___boxed.assembly.txt')).read_text()
assert all('<'+P+x+'>' in fb for x in ['cbDensity','cbPenalty','Binary64_add'])
commb=Path('.lake/build/ir/Impl/CommB.c').read_text();score=body(commb,P+'cbScorePasses')
assert P+'cbDensityTermsFast(' in score and P+'ScoreGate_choose(' in score
assert 'lean_alloc_closure((void*)('+P+'cbScorePasses___lam__0___boxed)' in score
assert P+'cbCombinedScore(' in body(commb,P+'cbScorePasses___lam__0')
init=commb.split('LEAN_EXPORT lean_object* initialize_lean1090_Impl_CommB(uint8_t builtin) {')[1]
tables=re.findall(r'lp_lean1090_Lean1090_Impl_(cb\w+ScoreTable) = _init_',init)
assert len(tables)==13
for table in tables:assert 'lean_mark_persistent('+P+table+');' in init
old=load('tests/evidence/diagnostics/gen8/source-review.json')
assert tables==old['eager_table_initializers']
assert P+'cbMach64' not in names
mach=body(commb,P+'cbMach64')
assert P+'payloadBits(' in mach and 'lean_array_fget_borrowed(' in mach
assert 'lean_unsigned_to_nat(25u)' in mach and 'lean_unsigned_to_nat(10u)' in mach
assert not any(x in mach for x in ['Binary64_', 'lean_obj_once(', 'lean_alloc_', 'l_Array_ofFn'])
entry=body(commb,P+'cbMachValueTable___lam__0')
assert entry.index(P+'Binary64_mul(')<entry.index(P+'Binary64_div(')
assert P+'cbMachValueTable = _init_'+P+'cbMachValueTable();' in init
assert 'lean_mark_persistent('+P+'cbMachValueTable);' in init
for local in ['cbValid60','cbPenalty','cbDensityTerms']:
 assert P+'cbMach64(' in body(commb,P+local)
 assembly=(D/(P+local+'.assembly.txt')).read_text()
 assert '<'+P+'cbMachValueTable>' in assembly and '<'+P+'payloadBits>' in assembly
 assert '$0x33' in assembly and '$0x15' in assembly
 assert P+'cbMach64' not in assembly
extra=load(D/'inspection-commands.json');commands=extra
for record in extra:assert sha(record['output'])==record['sha256']
assert '<'+P+'Binary64_mul>' in (D/(P+'cbMachValueTable___lam__0.assembly.txt')).read_text()
assert '<'+P+'Binary64_div>' in (D/(P+'cbMachValueTable___lam__0.assembly.txt')).read_text()
assert '$0x801' in (D/('_init_'+P+'cbMachValueTable___closed__1.assembly.txt')).read_text()
assert P+'cbMachValueTable' in (D/'initialize_lean1090_Impl_CommB.assembly.txt').read_text()
assert 'lean_mark_persistent' in (D/'initialize_lean1090_Impl_CommB.assembly.txt').read_text()
object_mach=(D/'object-cbMach64.assembly.txt').read_text()
assert P+'cbMach64>:' in object_mach and P+'payloadBits' in object_mach and P+'cbMachValueTable' in object_mach
assert 'Binary64_' not in object_mach
for p in ['.lake/build/ir/Impl/Parity.c','.lake/build/ir/Impl/Message.c','.lake/build/ir/Impl/CommB.c','.lake/build/ir/Impl/ScoreGate.c']:
 assert sha(p)==old['live_generated_C'][p]
# Complete raw-profile attribution remains a separate final review.
out={'status':'passed_read_only_source_and_native_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'commit':commit,'binary_sha256':sha(worker),'fresh_native_inputs':str(native_path),'fresh_native_inputs_sha256':sha(native_path),'fresh_project_modules_verified':22,'source_C_object_trace_bindings':bindings,'exact_fallback_anchor':P+'cbScorePasses___lam__0___boxed','eager_table_initializers':tables,'live_generated_C':{'.lake/build/ir/Impl/'+name+'.c':sha('.lake/build/ir/Impl/'+name+'.c') for name in ['CommB','ScoreGate','Parity','PayloadBits','Message','Bits']},'driver_build_manifest':str(build_path),'driver_build_manifest_sha256':sha(build_path),'driver_binary_sha256':sha('.cache/gen10-planning/driver/decode-costs'),'reused_production_objects_verified':21,'unchanged_driver_input_hashes_verified':len(build['unchanged_native_inputs']),'commands':commands,'symbol_inventory':{'path':str(D/'symbols.txt'),'sha256':sha(D/'symbols.txt')},'crc_native_context':old['crc_native_context'],'parity_fold_anchor':anchors[1],'payload_bits_anchor':P+'payloadBits','payload_native_context':{'payloadBits_standalone_present':True,'payloadWordBits_standalone_present':False,'wide_fallback_native_pow_call_sites':2,'source_observations':['For width<64, generated C contains UInt64 conversion, right shift, left-shift mask construction, subtraction and AND; no natural power/division/remainder call occurs in that branch.','Machine code implements mask as shl/not/and, retains the width comparison and returns a tagged natural. Arbitrary large natural inputs retain conversion/helper paths.','Width>=64 retains both callable lean_nat_pow sites and natural division/remainder, including big-natural branches. Observed fallback call counts require actual profile data; this static review makes no corpus reachability claim.','The inline helper has no final standalone symbol. Its arithmetic remains in live payloadBits; absent helper symbol is not zero extraction work.','All original live callers still target payloadBits. Its extraction algorithm and enclosing PayloadBits native object are unchanged from gen8; only generic Bits.field changed in this generation.','Source/C and native object hashes match the actual clean gen9 timed build; the diagnostic links those unchanged production objects.']},'score_native_context':['The interval choose function retains conditional lean_apply_1 for the boxed callback; that callback calls actual software cbDensity, cbPenalty and Binary64.add.','All 13 table initializers are eager and persistent in initialize_Impl_CommB, before main. Table construction is outside decoder-root collection and warmed timing.','No fallback-count claim is derived from the static symbol presence; final raw-profile/census accounting remains required.'],'review_script':str(Path(__file__)),'review_script_sha256':sha(__file__),'limits':'Static source, C, symbols, disassembly and hash inspection only. No decoder, test, native profile, build or benchmark execution. Complete raw-profile/accounting/archive review remains assigned to independent final reviewer.'}
out['mach_native_context']={'public_function':'Impl.cbMach64','native_standalone_present':False,'object_definition_present':True,'immutable_code_count':1024,'table_eager_initialized':True,'actual_caller_anchors':[P+x for x in ['cbValid60','cbPenalty','cbDensityTerms']], 'observations':['The generated C cbMach64 body is precisely payloadBits(word,25,10) and a borrowed lookup into the persistent global table; no software conversion arithmetic or table construction remains in this body.','The table closure preserves software literal rounding, multiplication, then division for all 1024 codes. Module initialization constructs and marks the value table persistent before message processing.','The live timed worker inlines cbMach64 in cbValid60, cbPenalty and cbDensityTerms. Retained assembly includes the global table address, actual field extraction call with tagged 25/10 arguments and indexed loads. The standalone linked cbMach64 symbol is absent, while its object definition remains.','A missing cbMach64 call context cannot mean zero Mach computation: the table lookup work is now part of caller self/runtime cost. Native caller stages and independent candidate/score probes remain the attribution boundaries.','Other binary64 work remains live, including penalty division and the exact score fallback. No rate claim or unobserved fallback count follows from this static inspection.']}

# Recheck the unchanged shared-syndrome path in the fresh gen9 worker.

message_path=Path('.lake/build/ir/Impl/Message.c');message=message_path.read_text()
source=Path('Impl/Message.lean').read_text()
dec=body(message,P+'decode');rep=body(message,P+'reportWithSyndrome');addr=body(message,P+'frameAddressWithSyndrome');accept=body(message,P+'frameAcceptedWithSyndrome')
assert dec.count(P+'frameSyndrome(')==1
m=re.search(r'(v_\w+) = '+P+r'frameSyndrome\((v_\w+)\);',dec);assert m
syndrome,frame=m.groups()
assert P+'frameAcceptedWithSyndrome('+frame+', '+syndrome+');' in dec
assert P+'reportWithSyndrome('+frame+', '+syndrome+');' in dec
assert dec.index(P+'decodeFrame(')<dec.index('return ' )<dec.index(P+'frameSyndrome(')
assert not any(P+x+'(' in rep+addr+accept for x in ['frameSyndrome','Parity_checksum'])
parameter=re.search(r'LEAN_EXPORT lean_object\* '+P+r'reportWithSyndrome\(lean_object\* \w+, lean_object\* (\w+)\)',message).group(1)
assert re.search(P+r'frameAddressWithSyndrome\(\w+, '+parameter+r'\)',rep)
assert P+'Parity_interrogator('+parameter+')' in rep
assert re.search(r'lean_ctor_set\(\w+, 0, '+parameter+r'\);',rep)
for local in ['frameAccepted','frameAddress','report']:
 b=body(message,P+local)
 assert b.count(P+'frameSyndrome(')==1 and b.count(P+local+'WithSyndrome(')==1
 assert '<'+P+local+'>:' in (D/('object-'+local+'.assembly.txt')).read_text()
assert not any(P+x in names for x in ['frameAccepted','frameAddress','report','frameAcceptedWithSyndrome'])
da=(D/(P+'decode.assembly.txt')).read_text();ra=(D/(P+'reportWithSyndrome.assembly.txt')).read_text();aa=(D/(P+'frameAddressWithSyndrome.assembly.txt')).read_text()
call=lambda a,n:len(re.findall(r'call\s+[0-9a-f]+ <'+re.escape(P+n)+r'>',a))
assert call(da,'frameSyndrome')==call(da,'decodeFrame')==call(da,'reportWithSyndrome')==1
assert call(da,'frameAcceptedWithSyndrome')==0 and call(da,'adsbHardValid')==1
assert re.search(r'call\s+[0-9a-f]+ <'+P+r'frameSyndrome>\n[^\n]*mov\s+%rax,%r12',da)
assert re.search(r'mov\s+%r12,%rsi\n[^\n]*call\s+[0-9a-f]+ <'+P+r'reportWithSyndrome>',da)
assert 'cmp    %rsi,%r12' in da and '<lean_nat_big_eq>' in da
assert call(ra,'frameAddressWithSyndrome')==call(ra,'Parity_interrogator')==1
assert all(call(ra,x)==0 and call(aa,x)==0 for x in ['frameSyndrome','Parity_checksum'])
assert 'mov    %rsi,%rbx' in ra and 'mov    %rbx,%rsi' in ra and 'mov    %rbx,%rdi' in ra
assert all(P+x+'(' in rep for x in ['frameAltitude','frameIdentity','frameADSB','frameCommB','Semantics_adsb'])
assert 'Lean1090_Impl_reportWithSyndrome_spec__0' in rep
assert 'let syndrome := frameSyndrome f' in source
excerpts={}
for local in ['decode','frameSyndrome','frameAcceptedWithSyndrome','frameAddressWithSyndrome','reportWithSyndrome','frameAccepted','frameAddress','report']:
 b=body(message,P+local);start=message.index(b);first=message[:start].count('\n')+1
 path=D/(local+'.generated-C.txt');assert not path.exists();path.write_text(b+'\n')
 excerpts[local]={'source':str(message_path),'source_sha256':sha(message_path),'first_body_line':first,'last_body_line':first+b.count('\n'),'path':str(path),'sha256':sha(path)}
out['shared_syndrome_decode_verified']=True
out['shared_syndrome_native_context']={
 'decode_anchor':P+'decode','report_anchor':P+'reportWithSyndrome','address_anchor':P+'frameAddressWithSyndrome',
 'native_syndrome_call_sites_in_decode':1,'syndrome_storage_register':'r12','native_acceptance_boundary_present':False,
 'public_wrappers_object_present_linked_absent':['frameAccepted','frameAddress','report'],
 'generated_C_excerpts':excerpts,
 'observations':[
 'decodeFrame returns none before syndrome computation. After a parsed frame, generated C binds one local syndrome and passes that same local to acceptance and report helpers.',
 'The timed-worker decode disassembly has one frameSyndrome call site. Its result is retained in r12, tested by the inlined DF17 acceptance logic, and passed in rsi to reportWithSyndrome. adsbHardValid is still called before deciding acceptance.',
 'The linked report helper passes its supplied syndrome to frameAddressWithSyndrome, Parity.interrogator for DF11, and the Report crc field. Neither report nor address computes another CRC.',
 'Public standalone wrappers remain real delegates to these same helpers in the generated C/object. Link-time removal/inlining means they lack standalone symbols in this worker; this is not a dead-test-only implementation.',
 'A later payload-plausibility rejection may now calculate a CRC before returning none. All accepted-corpus counts must be checked separately against native entries; the static call site alone does not establish corpus cardinality.',
 'No cross-message state or cache is added. Production native objects outside Bits match generation 8. Existing tables and score fallback remain unchanged.',
 'Under operational attribution, inlined acceptance self work stays in decode residual control. Its explicit adsbHardValid calls retain ADS-B attribution; frameAddressWithSyndrome retains frame/CRC. Report list bookkeeping stays residual control, with explicit semantic callees transitioning to semantics.'
 ]}
out['limits']='Static source, generated C, symbols, disassembly and hashes only. No build, decoder, test, benchmark or profiler execution. The separate accepted-corpus census and actual profile entries still require independent complete diagnostic review.'


# Reconstruct the local generated-C reference closure from this exact build.
gate_path=Path('.lake/build/ir/Impl/ScoreGate.c');gate=gate_path.read_text();functions={}
for match in re.finditer(r'^(?:LEAN_EXPORT|static) [^\n]*?\b([A-Za-z_]\w*)\([^\n]*\)\{',gate,re.M):
 name=match.group(1);start=match.end()-1;depth=0
 for end in range(start,len(gate)):
  depth+=(gate[end]=='{')-(gate[end]=='}')
  if depth==0:break
 functions[name]=gate[start:end+1]
root=P+'ScoreGate_choose';todo=[root];seen=set();references={};external=set()
while todo:
 name=todo.pop()
 if name in seen:continue
 seen.add(name);b=functions[name];tokens=set(re.findall(r'\b[A-Za-z_]\w*\b',b))
 refs=(tokens & set(functions))-{name};references[name]=sorted(refs);todo.extend(refs-seen)
 calls=set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',b))-{'if','switch','sizeof'}
 external.update(calls-set(functions))
assert len(seen)==15
assert not any('Rat_' in name or 'Binary64' in name or 'gcd' in name.lower() for name in external|seen)
assert not any(P+'ScoreGate_'+local in seen for local in ['mass','center','envelope'])
choose_c=functions[root]
assert choose_c.count('lean_apply_1(')==1
assert choose_c.count('lean_int_dec_le(')==choose_c.count('lean_int_dec_lt(')==1
assert choose_c.index('lean_int_dec_le(')<choose_c.index('lean_int_dec_lt(')<choose_c.index('lean_apply_1(')
assert 'if (v___x_240_ == 0)' in choose_c and 'if (v___x_242_ == 0)' in choose_c
common=P+'ScoreGate_commonDenominator'
totals='lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0'
assert common in names and totals in names
assert 'List_prod' in functions[common] and 'List_all' in functions[common]
assert 'lean_nat_mod(' in '\n'.join(functions[n] for n in seen)
assert 'lean_nat_div(' in '\n'.join(functions[n] for n in seen)
choose_asm=(D/(root+'.assembly.txt')).read_text()
for symbol in [common,totals]:assert len(re.findall(r'call\s+[0-9a-f]+ <'+re.escape(symbol)+'>',choose_asm))==1,symbol
assert len(re.findall(r'call\s+[0-9a-f]+ <lean_apply_1>',choose_asm))==1
assert not any('l_Rat_' in line or '_Binary64_' in line or 'gcd' in line.lower() for line in choose_asm.splitlines())
reference_names=[P+'ScoreGate_'+n for n in ['mass','center','envelope','scaledNumerator','scaledTotals']]
assert not any(n in names for n in reference_names)
for name in reference_names:
 assert name in functions
 assert '<'+name+'>:' in (D/('object-'+name.removeprefix(P)+'.assembly.txt')).read_text()
score_asm=(D/(P+'cbScorePasses.assembly.txt')).read_text()
assert '<'+root+'>' in score_asm and '<'+P+'cbDensityTermsFast>' in score_asm and '<'+P+'cbPenalty>' in score_asm
assert P+'cbScorePasses___lam__0___boxed' in score_asm
closure_excerpts={}
for name in sorted(seen):
 path=D/(name+'.generated-C.txt');assert not path.exists();path.write_text(functions[name]+'\n')
 start=gate.index(functions[name]);first=gate[:start].count('\n')+1
 closure_excerpts[name]={'path':str(path),'sha256':sha(path),'source':str(gate_path),'source_sha256':sha(gate_path),'first_body_line':first,'last_body_line':first+functions[name].count('\n')}
closure={'root':root,'reachable_local_functions':sorted(seen),'local_references':references,'external_C_calls':sorted(external),'excerpts':closure_excerpts,'limits':'Static local C references include literal initializers and the dynamic fallback application. The software callback is verified separately; no executed branch counts or speed claim follow from this closure.'}
closure_path=D/'integer-C-reference-closure.json';assert not closure_path.exists();closure_path.write_text(json.dumps(closure,indent=2)+'\n')
out['integer_score_gate_verified']=True
out['integer_score_gate_anchors']={'common_denominator':common,'totals_entry':totals}
out['integer_score_gate_native_context']={
 'reference_closure':str(closure_path),'reference_closure_sha256':sha(closure_path),
 'local_functions':len(seen),'native_choose_static_fallback_call_sites':1,
 'native_reference_and_inline_wrappers_absent':reference_names,
 'observations':[
 'The actual timed worker retains commonDenominator and the first scaledTotals pair-fold symbol; choose calls each once at a distinct native site. Full profile entries still require reconciliation against the population census.',
 'Generated C follows the maximum-divisibility test with an exact denominator-product fallback. Raw rational fields feed exact Nat division and Int signed/absolute numerator accumulation. No normalized Rat, GCD or software-Binary64 operation occurs in the 15-function local C reference closure.',
 'The integer lower-inclusive and upper-strict comparisons precede the only dynamic Unit callback application. Actual native choose has one lean_apply_1 site; software fallback remains live through the unchanged boxed cbScorePasses callback.',
 'mass, center and envelope remain unchanged mathematical reference APIs. They are present in the object and after-collection diagnostic census, but absent as standalone symbols and absent from the choose C reference closure in the timed worker.',
 'scaledNumerator and the scaledTotals wrapper are inlined; the first pair-fold entry is the retained boundary. A missing standalone wrapper is not zero computation.',
 'Production/Model C and objects outside Bits match generation 8; the immutable density/Mach tables, payload extractor and shared frame syndrome path remain live. No mutable corpus or per-message cache is introduced.',
 'Literal constants and the zero accumulator pair retain scalar lazy cells. Table construction remains eager before main. Cold constants/allocator state may differ in single-pass diagnostics and warmed benchmarks; no unmeasured correction is made.'
 ]}
out['score_native_context']=[
 'The live interval decision uses exact integer common-denominator arithmetic, with one conditional lean_apply_1 for the same boxed software callback.',
 'All 13 density tables and the 1024-entry Mach table remain eager/persistent before main; no initialization cost is inferred from missing native symbols.',
 'Native fallback-count and integer-helper entry claims require actual profile/census reconciliation; this review establishes the live boundaries only.'
]

# Inspect the exact affine guards in the freshly timed payloadValue.
from collections import deque
payload_path=Path('.lake/build/ir/Impl/PayloadBits.c')
pv=body(payload,P+'payloadValue');av=body(payload,P+'affineValue')
assert sha(payload_path)==old['live_generated_C'][str(payload_path)]
assert P+'affineValue(' not in pv
assert pv.count('l_Rat_mul(')==pv.count('l_Rat_add(')==1
assert av.count('l_instDecidableEqRat_decEq(')==2
assert 'v_scale_133_ = lean_ctor_get(v_column_120_, 3);' in pv
assert 'v_offset_134_ = lean_ctor_get(v_column_120_, 4);' in pv
assert 'l_instDecidableEqRat_decEq(v_scale_133_, v___x_139_)' in pv
assert 'l_instDecidableEqRat_decEq(v___y_123_, v___x_125_)' in pv
assert pv.index('return v___x_149_;')<pv.index(P+'payloadInteger(')
assert 'v___y_123_ = v_offset_134_;' in pv
assert 'lean_ctor_set(v___x_129_, 0, v___y_124_);' in pv
assert P+'affineValue' not in names
assert '<'+P+'affineValue>:' in (D/'object-affineValue.assembly.txt').read_text()
# Initializers are source-backed exact identity literals; no message-keyed state.
for label,literal in [('0','0'),('1','1')]:
 m=re.search(r'static lean_object\* _init_'+P+r'payloadValue___closed__'+label+r'\(void\)\{(.*?)\n\}',payload,re.S)
 assert m and 'lean_unsigned_to_nat('+literal+'u)' in m[1]
asm=(D/(P+'payloadValue.assembly.txt')).read_text();rows=[]
for line in asm.splitlines():
 m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
 if m:rows.append((int(m[1],16),m[2],m[3]))
index={a:i for i,(a,_,_) in enumerate(rows)}
conditions={}
for i,(address,op,arg) in enumerate(rows):
 if op=='call' and '<l_instDecidableEqRat_decEq>' in arg:
  bindings=[a for _,o,a in rows[max(0,i-4):i] if o=='mov' and a.endswith(',%rdi')]
  kind={'%r14,%rdi':0,'%rbx,%rdi':1}[bindings[-1]]
  assert rows[i+1][1:]==('test','%al,%al')
  assert rows[i+2][1] in ['je','jne'];conditions[i+2]=kind
assert list(conditions.values()).count(0)==list(conditions.values()).count(1)==2
assert 'mov    0x20(%rdi),%r14' in asm and 'mov    0x28(%rdi),%rbx' in asm
paths=[]
for one in [False,True]:
 for zero in [False,True]:
  todo=[(0,())];seen=set();returns=set()
  while todo:
   i,events=todo.pop()
   if (i,events) in seen:continue
   seen.add((i,events));address,op,arg=rows[i]
   if op=='call':
    target=re.search(r'<([^>]+)>',arg)[1]
    if target in [P+'payloadInteger','l_Rat_ofInt','l_Rat_mul','l_Rat_add']:events+= (target,)
    assert len(events)<=4
   if op.startswith('ret'):returns.add(events);continue
   if op.startswith('j'):
    target=int(re.match(r'([0-9a-f]+) <',arg)[1],16);assert target in index
    if i in conditions:
     yes=(one,zero)[conditions[i]];jump=yes if op=='jne' else not yes
     todo.append((index[target] if jump else i+1,events));continue
    todo.append((index[target],events))
    if op=='jmp':continue
   assert i+1<len(rows);todo.append((i+1,events))
  accepted=(P+'payloadInteger','l_Rat_ofInt')+(() if one else ('l_Rat_mul',))+(() if zero else ('l_Rat_add',))
  assert returns=={(),accepted},(one,zero,returns)
  paths.append({'scale_equals_one':one,'offset_equals_zero':zero,'present_call_sequence':list(accepted),'rejected_call_sequence':[],'visited_states':len(seen)})

calls=lambda text:re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>',text)
assert calls(asm).count('l_Rat_mul')==calls(asm).count('l_Rat_add')==1
mapname='lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0'
assert P+'payloadValue' in calls((D/(mapname+'.assembly.txt')).read_text())
for local in ['adsb','commB']:assert mapname in calls((D/(P+'Semantics_'+local+'.assembly.txt')).read_text())
affine_excerpts={}
for name,b in [('payloadValue',pv),('affineValue',av)]:
 path=D/(name+'.generated-C.txt');assert not path.exists();path.write_text(b+'\n')
 start=payload.index(b);first=payload[:start].count('\n')+1
 affine_excerpts[name]={'path':str(path),'sha256':sha(path),'source':str(payload_path),'source_sha256':sha(payload_path),'first_body_line':first,'last_body_line':first+b.count('\n')}
branch_path=D/'affine-native-branch-sequences.json';assert not branch_path.exists()
branch_path.write_text(json.dumps({'cases':paths,'guard_addresses':{hex(rows[i][0]):['scale_equals_one','offset_equals_zero'][kind] for i,kind in conditions.items()},'assembly_path':str(D/(P+'payloadValue.assembly.txt')),'assembly_sha256':sha(D/(P+'payloadValue.assembly.txt')),'limits':'Static direct-branch traversal fixes only actual rational equality outcomes; ordinary calls are assumed to return. All other branches conservatively explored. No execution or observed branch count is inferred.'},indent=2)+'\n')
out['affine_payload_value_verified']=True
out['affine_payload_value_anchor']=P+'payloadValue'
out['affine_payload_native_context']={'helper_standalone_present':False,'helper_object_definition_present':True,'native_direct_mul_sites':1,'native_direct_add_sites':1,'native_branch_sequences':str(branch_path),'native_branch_sequences_sha256':sha(branch_path),'generated_C_excerpts':affine_excerpts,'observations':[
 'The fresh timed worker inlines affineValue into public payloadValue. Exact rational equality to one guards multiplication; exact equality to zero guards addition. Rat.ofInt remains once on every present-value path.',
 'All four guarded present paths have the source/proof operation order: conversion, optional multiply, optional add. Rejected status returns before payloadInteger, Rat.ofInt or either affine arithmetic call.',
 'The actual ADS-B and Comm-B table-map path calls this same live payloadValue. Frozen adapters still use the public decoder and semantic paths. No legacy copy is introduced.',
 'The affine wrapper has an object definition but no standalone worker symbol. Its inlining does not mean zero affine work. Direct payloadValue-to-Rat.mul/add edges must be counted from the collected raw contexts, and are overlapping observations rather than an additional stage partition.',
 'Identity literals zero and one retain compiler scalar once cells. There is no corpus/message cache, trusted primitive, float arithmetic or changed nonidentity expression.',
 'The unchanged stage algorithm attributes payloadValue and its descendants according to actual callers: semantic projections remain semantics and inference callers remain Comm-B. No helper cost is reassigned by source intention.'
 ]}
# New gen9 generic frame-field extraction, bound to the actual timed worker.
bits_path=Path('.lake/build/ir/Impl/Bits.c');bits_c=bits_path.read_text();field_c=body(bits_c,P+'field')
assert 'lean_unsigned_to_nat(64u)' in field_c and 'lean_nat_dec_lt(v_width_21_, v___x_23_)' in field_c
wide_c,narrow_c=field_c.split('if (v___x_24_ == 0)\n{',1)[1].split('\nelse\n{',1)
assert wide_c.count('lean_nat_pow(')==wide_c.count('lean_nat_div(')==wide_c.count('l_BitVec_ofNat(')==1
assert not any(x in narrow_c for x in ['lean_nat_pow(', 'lean_nat_div(', 'lean_nat_mod(', 'l_BitVec_ofNat('])
assert 'v___x_31_ = lean_nat_sub(v_total_19_, v_start_20_);' in narrow_c
assert 'v___x_32_ = lean_nat_sub(v___x_31_, v_width_21_);' in narrow_c
assert 'v___x_33_ = lean_nat_shiftr(v_word_22_, v___x_32_);' in narrow_c
assert 'v___x_34_ = lean_uint64_of_nat(v___x_33_);' in narrow_c
assert narrow_c.index('lean_nat_shiftr(')<narrow_c.index('lean_uint64_of_nat(')<narrow_c.index('lean_uint64_land(')<narrow_c.index('lean_uint64_to_nat(')
assert 'v___x_36_ = lean_uint64_of_nat(v_width_21_);' in narrow_c
assert 'v___x_37_ = lean_uint64_shift_left(v___x_35_, v___x_36_);' in narrow_c
assert 'v___x_38_ = lean_uint64_sub(v___x_37_, v___x_35_);' in narrow_c
assert 'v___x_39_ = lean_uint64_land(v___x_34_, v___x_38_);' in narrow_c
assert P+'field' in names and P+'payloadWordBits(' not in field_c
old_bits=Path('tests/evidence/diagnostics/gen8/generated-c/Impl/Bits.c').read_text()
def alpha(text):
 table={}
 return re.sub(r'\bv_\w+_\b',lambda m:table.setdefault(m[0],'v'+str(len(table))),text)
for name in [P+'bytesValue',P+'packFields',P+'frameBytes','lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0','lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0']:
 assert alpha(body(bits_c,name))==alpha(body(old_bits,name)),name
# Independently derive the actual width-guard successors and explore their CFG.
asm=(D/(P+'field.assembly.txt')).read_text();rows=[]
for line in asm.splitlines():
 m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
 if m:rows.append((int(m[1],16),m[2],m[3]))
index={a:i for i,(a,_,_) in enumerate(rows)}
assert len(index)==len(rows)
assert 'mov    %rdx,%rbx' in asm and 'mov    %rcx,%r14' in asm
assert 'mov    $0x81,%esi' in asm and '<lean_nat_big_lt>' in asm
positions=[i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('cmp','$0x81,%rbx')]
assert len(positions)==1;guard=positions[0];assert rows[guard+1][1]=='jae'
wide_entry=index[int(rows[guard+1][2].split()[0],16)];narrow_entry=guard+2
assert rows[wide_entry][1:]==('test','$0x1,%dil') and rows[narrow_entry][1:]==('test','$0x1,%dil')
shift_index=[i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('shr','%cl,%r14')];assert len(shift_index)==1
assert rows[shift_index[0]+1][1:]==('cmp','$0x80,%r15')
assert rows[shift_index[0]+4][1:]==('cmovb','%rax,%r14')
mask_index=[i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('and','%rax,%r15')];assert len(mask_index)==1
mi=mask_index[0];assert [r[1:] for r in rows[mi-2:mi+2]]==[('shl','%cl,%rax'),('not','%rax'),('and','%rax,%r15'),('lea','0x1(,%r15,2),%rax')]
branches={}
for name,entry in [('narrow',narrow_entry),('wide',wide_entry)]:
 todo=[(entry,False,False)];seen=set();terminal=set();observed=set();ops=set()
 while todo:
  i,shifted,masked=todo.pop()
  if (i,shifted,masked) in seen:continue
  seen.add((i,shifted,masked));address,op,arg=rows[i];ops.add(op)
  if i==shift_index[0]:shifted=True
  if op=='call':
   target=re.search(r'<([^>]+)>',arg)[1];observed.add(target)
   if target=='lean_nat_big_shiftr':shifted=True
   if name=='narrow' and target=='lean_uint64_of_big_nat':assert shifted
  if i==mi:assert shifted;masked=True
  if op.startswith('ret'):terminal.add((shifted,masked));continue
  if op.startswith('j'):
   target=int(re.match(r'([0-9a-f]+) <',arg)[1],16);assert target in index
   todo.append((index[target],shifted,masked))
   if op=='jmp':continue
  assert i+1<len(rows);todo.append((i+1,shifted,masked))
 if name=='narrow':
  assert terminal=={(True,True)}
  assert not observed & {'lean_nat_pow','lean_nat_big_div','lean_nat_big_mod','l_BitVec_ofNat'}
  assert not ops & {'div','idiv'}
  assert {'lean_nat_big_shiftr','lean_uint64_of_big_nat'}<=observed
 else:
  assert terminal=={(False,False)} and {'lean_nat_pow','lean_nat_big_div','l_BitVec_ofNat'}<=observed
  assert 'div' in ops and 'lean_nat_big_shiftr' not in observed
 branches[name]={'entry':hex(rows[entry][0]),'reachable_instructions':len({i for i,_,_ in seen}),'calls':sorted(observed),'return_shift_and_mask_flags':[list(t) for t in sorted(terminal)]}

assert calls((D/(P+'decodeFrame.assembly.txt')).read_text()).count(P+'field')==26
assert calls((D/(P+'decode.assembly.txt')).read_text()).count(P+'decodeFrame')==1
field_excerpts={}
for name,cfile in [('field',bits_path),('bytesValue',bits_path),('packFields',bits_path),('frameBytes',bits_path),('readACAS',Path('.lake/build/ir/Impl/Frame.c')),('readSurveillance',Path('.lake/build/ir/Impl/Frame.c')),('decodeFrame',Path('.lake/build/ir/Impl/Frame.c'))]:
 text=cfile.read_text();piece=body(text,P+name);path=D/(name+'.generated-C.txt');assert not path.exists();path.write_text(piece+'\n')
 start=text.index(piece);first=text[:start].count('\n')+1
 field_excerpts[name]={'path':str(path),'sha256':sha(path),'source':str(cfile),'source_sha256':sha(cfile),'first_body_line':first,'last_body_line':first+piece.count('\n')}
field_branches=D/'field-native-branches.json';assert not field_branches.exists()
field_branches.write_text(json.dumps({'branches':branches,'assembly':str(D/(P+'field.assembly.txt')),'assembly_sha256':sha(D/(P+'field.assembly.txt')),'limits':'Conservative direct-branch traversal from actual width-guard successors, assuming ordinary calls return. No runtime branch counts are inferred.'},indent=2)+'\n')
out['field_mask_verified']=True
out['field_mask_anchor']=P+'field'
out['field_mask_native_context']={'native_field_present':True,'decodeFrame_field_call_sites':26,'changed_native_module':'Impl/Bits.lean','width_cutoff_exclusive':64,'mask_helper_inlined':True,'native_branches':str(field_branches),'native_branches_sha256':sha(field_branches),'generated_C_excerpts':field_excerpts,'observations':[
 'The fresh timed field function keeps both width branches. Below 64 it shifts the arbitrary Nat before UInt64 conversion, masks and returns the bounded Nat directly. Powers, division and generic BitVec.ofNat occur only in the wide fallback.',
 'All conservatively explored narrow returns follow an exact shift and mask. Small-Nat shift counts have the explicit large-count zero guard; big-natural shifts call lean_nat_big_shiftr before low-word conversion. No modulo-count assumption is made for arbitrary shift values.',
 'The actual decodeFrame contains 26 static calls to this same field symbol. readACAS/readSurveillance may inline into decodeFrame, but their field work is retained. No adapter-specific legacy copy or message cache exists.',
 'bytesValue, packFields and frameBytes and both relevant fold bodies have unchanged generated C modulo local variable numbering. Every other production native object matches gen8. CRC, integer score and affine payload paths are retained and separately rebound.',
 'Field/helper inclusive observations overlap caller costs; the unchanged stage partition still assigns actual frame extraction descendants to frame/CRC. Static fallback presence says nothing about observed corpus fallback counts; raw call contexts are required.',
 'Widths at least 64 retain the generic formula, including 80-bit military/Comm-D fields. No unbounded word or position premise is introduced by the universal Lean proof.'
 ]}
for name,digest in build['unchanged_native_inputs'].items():assert sha(name)==digest,name
for name,digest in build['production_sources'].items():assert sha(name)==digest,name

p=E/'source-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(sha(p))
