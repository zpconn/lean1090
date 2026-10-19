"""Read-only source/native binding review; no decoder/build execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,re,shlex,subprocess,sys
sys.dont_write_bytecode=True
E=Path('tests/evidence/diagnostics/gen13'); D=E/'source-inspection'; P='lp_lean1090_Lean1090_Impl_'
load=lambda p:json.loads(Path(p).read_text())
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
bench=load('bench/runs/gen13/summary.json');commit=bench['commit'];native_path=Path('bench/runs/gen13/fresh-native-inputs.json');native=load(native_path)
assert subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()==commit
worker='.lake/build/bin/lean1090-bench';build_path=Path('.cache/gen13-costs/driver/driver-build.json');build=load(build_path)
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
for name,record in load('bench/runs/gen13/binary-built.json')['native_hashes'].items():assert sha(name)==record,name
oldbuild=load('tests/evidence/diagnostics/gen12/driver/driver-build.json')
changed_objects={'.lake/build/ir/Impl/'+n+'.c.o.export' for n in ['CommB']}
for path in changed_objects:assert objects[path] != oldbuild['reused_production_objects'][path]
for path, digest in objects.items():
 if path != build['linked_project_inventory']['worker_object'] and path not in changed_objects:
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
anchors=[P+'Parity_syndrome','lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg',P+'Parity_checksum',P+'ScoreGate_choose',P+'cbScorePasses___lam__0___boxed',P+'payloadBits']
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
old=load('tests/evidence/diagnostics/gen12/source-review.json')
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
for p in ['.lake/build/ir/Impl/Parity.c','.lake/build/ir/Impl/ScoreGate.c']:
 assert sha(p)==old['live_generated_C'][p]
# Complete raw-profile attribution remains a separate final review.
out={'status':'passed_read_only_source_and_native_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'commit':commit,'binary_sha256':sha(worker),'fresh_native_inputs':str(native_path),'fresh_native_inputs_sha256':sha(native_path),'fresh_project_modules_verified':22,'source_C_object_trace_bindings':bindings,'exact_fallback_anchor':P+'cbScorePasses___lam__0___boxed','eager_table_initializers':tables,'live_generated_C':{'.lake/build/ir/Impl/'+name+'.c':sha('.lake/build/ir/Impl/'+name+'.c') for name in ['CommB','ScoreGate','Parity','PayloadBits','Message','Bits']},'driver_build_manifest':str(build_path),'driver_build_manifest_sha256':sha(build_path),'driver_binary_sha256':sha('.cache/gen13-costs/driver/decode-costs'),'reused_production_objects_verified':21,'unchanged_driver_input_hashes_verified':len(build['unchanged_native_inputs']),'commands':commands,'symbol_inventory':{'path':str(D/'symbols.txt'),'sha256':sha(D/'symbols.txt')},'crc_native_context':{},'parity_fold_anchor':anchors[1],'payload_bits_anchor':P+'payloadBits','payload_native_context':{'payloadBits_standalone_present':True,'payloadWordBits_standalone_present':False,'wide_fallback_native_pow_call_sites':2,'source_observations':['For width<64, generated C contains UInt64 conversion, right shift, left-shift mask construction, subtraction and AND; no natural power/division/remainder call occurs in that branch.','Machine code implements mask as shl/not/and, retains the width comparison and returns a tagged natural. Arbitrary large natural inputs retain conversion/helper paths.','Width>=64 retains both callable lean_nat_pow sites and natural division/remainder, including big-natural branches. Observed fallback call counts require actual profile data; this static review makes no corpus reachability claim.','The inline helper has no final standalone symbol. Its arithmetic remains in live payloadBits; absent helper symbol is not zero extraction work.','All original live callers still target payloadBits. Its extraction algorithm and enclosing PayloadBits native object are unchanged from gen8; those paths remain unchanged in gen13; only the BDS50 wind penalty changed.','Source/C and native object hashes match the actual clean gen12 timed build; the diagnostic links those unchanged production objects.']},'score_native_context':['The interval choose function retains conditional lean_apply_1 for the boxed callback; that callback calls actual software cbDensity, cbPenalty and Binary64.add.','All 13 table initializers are eager and persistent in initialize_Impl_CommB, before main. Table construction is outside decoder-root collection and warmed timing.','No fallback-count claim is derived from the static symbol presence; final raw-profile/census accounting remains required.'],'review_script':str(Path(__file__)),'review_script_sha256':sha(__file__),'limits':'Static source, C, symbols, disassembly and hash inspection only. No decoder, test, native profile, build or benchmark execution. Complete raw-profile/accounting/archive review remains assigned to independent final reviewer.'}
out['mach_native_context']={'public_function':'Impl.cbMach64','native_standalone_present':False,'object_definition_present':True,'immutable_code_count':1024,'table_eager_initialized':True,'actual_caller_anchors':[P+x for x in ['cbValid60','cbPenalty','cbDensityTerms']], 'observations':['The generated C cbMach64 body is precisely payloadBits(word,25,10) and a borrowed lookup into the persistent global table; no software conversion arithmetic or table construction remains in this body.','The table closure preserves software literal rounding, multiplication, then division for all 1024 codes. Module initialization constructs and marks the value table persistent before message processing.','The live timed worker inlines cbMach64 in cbValid60, cbPenalty and cbDensityTerms. Retained assembly includes the global table address, actual field extraction call with tagged 25/10 arguments and indexed loads. The standalone linked cbMach64 symbol is absent, while its object definition remains.','A missing cbMach64 call context cannot mean zero Mach computation: the table lookup work is now part of caller self/runtime cost. Native caller stages and independent candidate/score probes remain the attribution boundaries.','Other binary64 work remains live, including penalty division and the exact score fallback. No rate claim or unobserved fallback count follows from this static inspection.']}

# Recheck the unchanged shared-syndrome path in the fresh gen12 worker.

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
 'No cross-message state or cache is added. The byte converter and downstream Frame/Message ownership conventions remain unchanged from gen12. The new exact BDS50 wind table is the sole CommB runtime change; existing tables and score fallback remain live.',
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
 'Production C and objects outside CommB match generation 12; the immutable density/Mach tables, payload extractor and shared frame syndrome path remain live. No mutable corpus or per-message cache is introduced.',
 'Literal constants and the zero accumulator pair retain scalar lazy cells. Table construction remains eager before main. Cold constants/allocator state may differ in single-pass diagnostics and warmed benchmarks; no unmeasured correction is made.'
 ]}
out['score_native_context']=[
 'The live interval decision uses exact integer common-denominator arithmetic, with one conditional lean_apply_1 for the same boxed software callback.',
 'All 13 density tables, the 1024-entry Mach table and the 4096-entry QNH table remain eager/persistent before main; no initialization cost is inferred from missing native symbols.',
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
# Recheck unchanged generic frame-field extraction against the actual timed worker.
bits_path=Path('.lake/build/ir/Impl/Bits.c');bits_c=bits_path.read_text();field_c=body(bits_c,P+'field')
old_bits=Path('tests/evidence/diagnostics/gen11/generated-c/Impl/Bits.c').read_text()
def alpha(text):
 table={}
 return re.sub(r'\bv_\w+_\b',lambda m:table.setdefault(m[0],'v'+str(len(table))),text)
for name in [P+'field',P+'packFields',P+'frameBytes','lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0','lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0']:
 assert alpha(body(bits_c,name))==alpha(body(old_bits,name)),name
assert 'lean_unsigned_to_nat(64u)' in field_c
assert P+'field' in names and P+'payloadWordBits(' not in field_c
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
out['field_mask_native_context']={'native_field_present':True,'decodeFrame_field_call_sites':26,'original_optimization_module':'Impl/Bits.lean','width_cutoff_exclusive':64,'mask_helper_inlined':True,'native_branches':str(field_branches),'native_branches_sha256':sha(field_branches),'generated_C_excerpts':field_excerpts,'observations':[
 'The fresh timed field function keeps both width branches. Below 64 it shifts the arbitrary Nat before UInt64 conversion, masks and returns the bounded Nat directly. Powers, division and generic BitVec.ofNat occur only in the wide fallback.',
 'All conservatively explored narrow returns follow an exact shift and mask. Small-Nat shift counts have the explicit large-count zero guard; big-natural shifts call lean_nat_big_shiftr before low-word conversion. No modulo-count assumption is made for arbitrary shift values.',
 'The actual decodeFrame contains 26 static calls to this same field symbol. readACAS/readSurveillance may inline into decodeFrame, but their field work is retained. No adapter-specific legacy copy or message cache exists.',
 'The public byte conversion, field, packFields, frameBytes and original wide byte-fold fallback remain unchanged from gen12. The earlier gen11-to-gen12 Frame/Message ownership differences are retained as historical context. CRC, integer score and affine payload paths are retained and separately rebound.',
 'Field/helper inclusive observations overlap caller costs; the unchanged stage partition still assigns actual frame extraction descendants to frame/CRC. Static fallback presence says nothing about observed corpus fallback counts; raw call contexts are required.',
 'Widths at least 64 retain the generic formula, including 80-bit military/Comm-D fields. No unbounded word or position premise is introduced by the universal Lean proof.'
 ]}

def qbody(text,symbol):
 m=re.search(r'\b'+re.escape(symbol)+r'\([^;{}]*\)\s*\{',text);assert m,symbol
 start=m.end()-1;depth=0
 for end in range(start,len(text)):
  depth+=(text[end]=='{')-(text[end]=='}')
  if depth==0:return text[start:end+1]
 raise AssertionError(symbol)
qnh=body(commb,P+'cbQNH64');qentry=body(commb,P+'cbQNHValueTable___lam__0')
qconstructor=qbody(commb,'_init_'+P+'cbQNHValueTable___closed__1')
assert P+'cbQNH64' not in names
assert all(x in qnh for x in [P+'cbQNHValueTable;',P+'payloadBits(', 'lean_unsigned_to_nat(28u)', 'lean_unsigned_to_nat(12u)','lean_array_fget_borrowed('])
assert qnh.index(P+'payloadBits(')<qnh.index('lean_array_fget_borrowed(')
assert not any(x in qnh for x in ['Binary64_', 'l_Rat_', 'lean_obj_once', 'Array_ofFn'])
assert qentry.count(P+'Binary64_mul(')==qentry.count(P+'Binary64_add(')==1
assert qentry.index(P+'Binary64_mul(')<qentry.index(P+'Binary64_add(')
assert all(x in qconstructor for x in ['lean_unsigned_to_nat(4096u)','l_Array_ofFn___redArg(',P+'cbQNHValueTable___closed__0'])
assert '.m_fun = (void*)'+P+'cbQNHValueTable___lam__0' in commb
for i,n in [('0','1'),('1','10'),('4','800')]:
 assert 'lean_unsigned_to_nat('+n+'u)' in qbody(commb,'_init_'+P+'cbQNHValueTable___lam__0___closed__'+i)
assert 'l_Rat_div(' in qbody(commb,'_init_'+P+'cbQNHValueTable___lam__0___closed__2')
assert P+'Binary64_round(' in qbody(commb,'_init_'+P+'cbQNHValueTable___lam__0___closed__3')
assignment=P+'cbQNHValueTable = _init_'+P+'cbQNHValueTable();'
persistent='lean_mark_persistent('+P+'cbQNHValueTable);'
assert commb.count(P+'cbQNHValueTable =')==1
assert assignment in init and persistent in init and init.index(assignment)<init.index(persistent)
whole=Path('.lake/build/ir/Bench/WholeDecoder.c').read_text()
json_c=Path('.lake/build/ir/Impl/JSON.c').read_text()
assert qbody(whole,'main').index('initialize_lean1090_Bench_WholeDecoder(')<qbody(whole,'main').index('lean_run_main(')
assert 'initialize_lean1090_Impl_JSON(' in qbody(whole,'initialize_lean1090_Bench_WholeDecoder')
assert 'initialize_lean1090_Impl_Message(' in qbody(json_c,'initialize_lean1090_Impl_JSON')
assert 'initialize_lean1090_Impl_CommB(' in qbody(message,'initialize_lean1090_Impl_Message')
qpaths={}
for local in ['cbValid40','cbDensityTerms']:
 assert P+'cbQNH64(' in body(commb,P+local)
 assembly=(D/(P+local+'.assembly.txt')).read_text();items=[]
 for line in assembly.splitlines():
  m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
  if m:items.append({'address':'0x'+m[1],'op':m[2],'args':m[3]})
 start=next(i for i,r in enumerate(items) if '<'+P+'cbQNHValueTable>' in r['args'])
 end=next(i for i in range(start+1,len(items)) if items[i]['op']=='mov' and re.match(r'0x18\([^\n]+,4\),',items[i]['args']))
 path=items[start:end+1]
 assert sum(r['op']=='call' and '<'+P+'payloadBits>' in r['args'] for r in path)==1
 assert any(r['args']=='$0x39,%esi' for r in path) and any(r['args']=='$0x19,%edx' for r in path)
 assert not any(r['op'].startswith('j') or 'Binary64_' in r['args'] or 'lean_obj_once' in r['args'] for r in path)
 qpaths[local]=path
object_qnh=(D/'object-cbQNH64.assembly.txt').read_text()
assert P+'cbQNH64>:' in object_qnh and P+'cbQNHValueTable' in object_qnh and P+'payloadBits' in object_qnh
assert 'Binary64_' not in object_qnh
entry_calls=calls((D/(P+'cbQNHValueTable___lam__0.assembly.txt')).read_text())
assert entry_calls.index(P+'Binary64_mul')<entry_calls.index(P+'Binary64_add')
assert P+'Binary64_round' in calls((D/('_init_'+P+'cbQNHValueTable___lam__0___closed__3.assembly.txt')).read_text())
constructor_asm=(D/('_init_'+P+'cbQNHValueTable___closed__1.assembly.txt')).read_text()
assert '$0x2001,%edi' in constructor_asm and 'l_Array_ofFn___redArg' in calls(constructor_asm)
init_asm=(D/'initialize_lean1090_Impl_CommB.assembly.txt').read_text()
assert all(x in init_asm for x in ['<'+P+'cbQNHValueTable>', '<_init_'+P+'cbQNHValueTable___closed__1>', '<lean_mark_persistent>'])
qpath=D/'qnh-native-paths.json';assert not qpath.exists()
qpath.write_text(json.dumps({'paths':qpaths,'limits':'Actual straight-line QNH table load, exact field extraction and indexed lookup in each live caller. No executed population or timing claim follows.'},indent=2)+'\n')
qexcerpts={}
for name in [P+'cbQNH64',P+'cbQNHValueTable___lam__0','_init_'+P+'cbQNHValueTable___closed__1','_init_'+P+'cbQNHValueTable___lam__0___closed__2','_init_'+P+'cbQNHValueTable___lam__0___closed__3',P+'cbValid40',P+'cbDensityTerms','initialize_lean1090_Impl_CommB']:
 piece=qbody(commb,name);path=D/(name+'.generated-C.txt');assert not path.exists();path.write_text(piece+'\n')
 start=commb.index(piece);first=commb[:start].count('\n')+1
 qexcerpts[name]={'path':str(path),'sha256':sha(path),'source':'.lake/build/ir/Impl/CommB.c','source_sha256':sha('.lake/build/ir/Impl/CommB.c'),'first_body_line':first,'last_body_line':first+piece.count('\n')}
out['qnh_table_live_path_verified']=True
out['qnh_native_context']={'public_function':'Impl.cbQNH64','native_standalone_present':False,'object_definition_present':True,'immutable_code_count':4096,'table_eager_initialized':True,'actual_caller_anchors':[P+x for x in ['cbValid40','cbDensityTerms']],'native_paths':str(qpath),'native_paths_sha256':sha(qpath),'generated_C_excerpts':qexcerpts,'observations':[
 'All 4096 exact entries use software-rounded 1/10, multiplication, then addition of 800; no field plausibility or corpus membership filters table construction.',
 'The actual benchmark worker initializes the complete immutable persistent table before lean_run_main. Lookup uses only raw field start28/width12, with the proved bound erased from native code.',
 'cbQNH64 has an object body but is inlined in the linked worker. Retained cbValid40 and cbDensityTerms machine sequences load the same table, call live payloadBits with tagged28/12 and index the entry. No table construction or binary64 operation occurs in those sequences.',
 'Candidate validity, repeated accepted-record validity and lazy software-score fallback use these current callers. Missing standalone QNH call contexts mean inlining, not zero QNH work or an inferred speedup.',
 'All22 native sets and their source blobs match the exact current/timed gen13 commit; no attribution remapping is involved.'
]}


# Current UInt32 CRC loop checks are added here before final source evidence.
# Bind the actual freshly timed UInt32 CRC loop, rather than the prior CLI.
parity_path=Path('.lake/build/ir/Impl/Parity.c');parity=parity_path.read_text()
loop=anchors[1]
loop_c=body(parity,loop);syndrome_c=body(parity,P+'Parity_syndrome')
for local in ['Parity_wordStep','Parity_step']:
 piece=body(parity,P+local)
 assert all(token in piece for token in ['lean_uint32_shift_left(', 'lean_uint32_lor(', 'lean_uint32_xor(', 'lean_uint32_land(', '8388608', '33551369', '16777215'])
 assert P+local not in names
 assert '<'+P+local+'>:' in (D/('object-'+local+'.assembly.txt')).read_text()
assert all(token in loop_c for token in ['lean_uint32_shift_left(', 'lean_uint32_lor(', 'lean_uint32_xor(', 'lean_uint32_land(', '8388608', '33551369', '16777215','goto _start;'])
assert not any(token in loop_c for token in ['List_', 'lean_alloc_', 'lean_box_', 'BitVec_', 'lean_uint32_to_nat', 'lean_nat_mod', 'lean_nat_pow'])
assert all(token in loop_c for token in ['lean_unsigned_to_nat(64u)','lean_unsigned_to_nat(128u)','lean_uint64_shift_right(v_low_', 'lean_uint64_shift_right(v_high_', 'l_Nat_testBit('])
assert syndrome_c.count('lean_uint64_of_nat(')==2 and syndrome_c.count('lean_nat_shiftr(')==1
assert syndrome_c.index('v_high_162_ =')<syndrome_c.index(loop+'(')
assert syndrome_c.count(loop+'(')==syndrome_c.count('lean_uint32_to_nat(')==syndrome_c.count('l_BitVec_ofNat(')==1
assert syndrome_c.index(loop+'(')<syndrome_c.index('lean_uint32_to_nat(')<syndrome_c.index('l_BitVec_ofNat(')
loop_asm=(D/(loop+'.assembly.txt')).read_text()
assert all(x in loop_asm for x in ['lea    (%rdx,%rbx,2),%eax','xor    $0xfff409,%edx','test   $0x800000,%ebx','cmove  %eax,%edx','and    $0xffffff,%edx','mov    %edx,%ebx'])
assert loop_asm.count('\tbt ')==2
assert 'l_Nat_testBit' in calls(loop_asm) and 'lean_nat_big_sub' in calls(loop_asm)
assert not any(re.search(r'List_|BitVec_|lean_alloc|lean_box|uint32_to_nat|lean_nat_(?:pow|mod|div)',n) for n in calls(loop_asm))
assert not calls((D/'object-Parity_wordStep.assembly.txt').read_text())
assembly=(D/(P+'Parity_syndrome.assembly.txt')).read_text();rows=[]
for line in assembly.splitlines():
 m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
 if m:rows.append((int(m[1],16),m[2],m[3]))
byaddr={r[0]:i for i,r in enumerate(rows)};seen=set();pending=[(0,0)];exits=[]
while pending:
 i,n=pending.pop()
 if (i,n) in seen:continue
 seen.add((i,n));address,op,arg=rows[i]
 n+=int(op=='call' and '<'+loop+'>' in arg);assert n<=1
 if op.startswith('j'):
  m=re.fullmatch(r'([0-9a-f]+) <([^>]+)>',arg);assert m,arg
  destination=int(m[1],16)
  if destination in byaddr:pending.append((byaddr[destination],n))
  else:
   assert op=='jmp' and m[2]=='l_BitVec_ofNat';exits.append({'address':hex(address),'loop_calls':n,'target':m[2]})
  if op=='jmp':continue
 assert op!='ret' and i+1<len(rows);pending.append((i+1,n))
assert len(rows)==len(seen)==87 and exits and all(x['loop_calls']==1 for x in exits)
assert sum(op=='call' and '<'+loop+'>' in arg for _,op,arg in rows)==2
cfgpath=D/'word-crc-syndrome-native-cfg.json';assert not cfgpath.exists()
cfgpath.write_text(json.dumps({'instruction_count':len(rows),'reachable_states':len(seen),'static_loop_sites':2,'exits':exits,'assembly':str(D/(P+'Parity_syndrome.assembly.txt')),'assembly_sha256':sha(D/(P+'Parity_syndrome.assembly.txt')),'limits':'Conservative intraprocedural traversal assuming ordinary calls return. Two static ownership call sites are exclusive; no iteration frequency is inferred.'},indent=2)+'\n')
crc_excerpts={}
for symbol in [P+'Parity_wordStep',P+'Parity_step',loop,P+'Parity_syndrome',P+'Parity_checksum']:
 piece=body(parity,symbol);path=D/(symbol+'.generated-C.txt');assert not path.exists();path.write_text(piece+'\n')
 start=parity.index(piece);first=parity[:start].count('\n')+1
 crc_excerpts[symbol]={'path':str(path),'sha256':sha(path),'source':str(parity_path),'source_sha256':sha(parity_path),'first_body_line':first,'last_body_line':first+piece.count('\n')}
assert P+'Parity_checksum' in calls((D/(P+'frameSyndrome.assembly.txt')).read_text())
assert P+'Parity_syndrome' in calls((D/(P+'Parity_checksum.assembly.txt')).read_text())
assert 'Impl.Parity.syndrome (bs.length*8) (word bs)' in Path('Tests/Upstream.lean').read_text()
assert 'BitVec.ofNat 24 (wordStep remainder.toNat.toUInt32 bit).toNat' in Path('Impl/Parity.lean').read_text()
out['word_crc_live_path_verified']=True
out['crc_native_context']={
 'loop_anchor':loop,'state_width_bits':32,'output_width_bits':24,'standalone_step_present':False,
 'standalone_wordStep_present':False,'object_step_and_wordStep_present':True,
 'cached_native_bt_sites':2,'high_index_Nat_testBit_fallback_present':True,
 'syndrome_cfg':str(cfgpath),'syndrome_cfg_sha256':sha(cfgpath),'generated_C_excerpts':crc_excerpts,
 'observations':[
 'The freshly timed worker carries an unboxed UInt32 remainder through a specialized tail loop. Generated C has no range list, per-iteration constructor or BitVec projection; machine arithmetic implements shift/input bit, feedback selected by bit23, and low24 mask.',
 'Both cached UInt64 halves are prepared before loop entry. The live loop retains two machine bit-test sites and arbitrary-precision Nat.testBit for indices beyond127, including big index bookkeeping. Only remainder-update allocation removal is established; unrestricted indices can still allocate.',
 'Public step and wordStep object bodies remain delegates to the same update, but their standalone worker symbols are absent due to inlining. Absence means no observable function boundary, not zero bit-update work.',
 'The syndrome assembly has two exclusive ownership call sites. Independent conservative CFG traversal verifies one loop invocation on every normal path and one final BitVec projection.',
 'The accepted-corpus post-collection census may predict loop iterations from width. Only actual loop entries, syndrome and checksum counts are measured at retained native boundaries; arbitrary widths and rejection populations are not inferred from that census.',
 'All21 reused production objects match the fresh benchmark inventory. Bits and downstream Frame/Message ownership conventions retain the gen12 code; shared syndrome, semantic fields, immutable density/Mach/QNH tables and exact integer score fallback remain live.'
 ]}

# Independently inspect the timed worker's byte paths and compiler ownership deltas.
import difflib
prefix=P+'bytesWordPrefix';word='lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1';fallback='lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0'
public_c=body(bits_c,P+'bytesValue');prefix_c=body(bits_c,prefix);word_c=body(bits_c,word)
assert prefix in names and fallback in names and P+'bytesValue' in names
assert word not in names and P+'bytesWord' not in names
assert '<'+word+'>:' in (D/('object-'+word+'.assembly.txt')).read_text()
assert all(x in word_c for x in ['uint64_t','lean_uint64_shift_left(', 'lean_uint64_add(', 'goto _start;'])
assert not any(x in word_c for x in ['lean_alloc_', 'lean_box_', 'lean_nat_', 'to_nat'])
assert prefix_c.count('lean_box_uint64(')==prefix_c.count('lean_alloc_ctor(0, 2, 0)')==2
assert prefix_c.count('1, v_x_25_);')==2
recursive=prefix_c[prefix_c.index('v_head_33_ ='):]
assert 'goto _start;' in recursive and not any(x in recursive for x in ['lean_alloc_', 'lean_box_', 'return ', 'lean_uint64_to_nat'])
assert public_c.count(prefix+'(')==public_c.count(fallback+'(')==1 and public_c.count(word+'(')==2
assert public_c.count('lean_nat_shiftl(')==public_c.count('lean_nat_add(')==1
assert public_c.index(prefix+'(')<public_c.index('lean_nat_shiftl(')<public_c.index('lean_nat_add(')
assert 'lean_unsigned_to_nat(8u)' in public_c and 'lean_unsigned_to_nat(16u)' in public_c

def byte_graph(assembly):
 result=[]
 for line in assembly.splitlines():
  m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
  if m:result.append((int(m[1],16),m[2],m[3]))
 return result,{a:i for i,(a,_,_) in enumerate(result)}
def byte_paths(assembly,start,tracked):
 instructions,indices=byte_graph(assembly);pending=[(indices[start],(0,)*len(tracked))];seen=set();exits=set()
 while pending:
  i,counts=pending.pop()
  if (i,counts) in seen:continue
  seen.add((i,counts));address,op,arg=instructions[i]
  if op=='call':counts=tuple(n+int('<'+name+'>' in arg) for n,name in zip(counts,tracked))
  assert max(counts,default=0)<=2
  if op.startswith('ret'):exits.add((counts,'ret'));continue
  if op.startswith('j'):
   m=re.fullmatch(r'([0-9a-f]+) <([^>]+)>',arg);assert m,arg;destination=int(m[1],16)
   if destination in indices:pending.append((indices[destination],counts))
   else:assert op=='jmp';exits.add((counts,m[2]))
   if op=='jmp':continue
  assert i+1<len(instructions);pending.append((i+1,counts))
 assert exits
 return {'start':hex(start),'reachable_instruction_count':len({i for i,_ in seen}),'tracked':tracked,'normal_exits':[{'counts':list(n),'target':t} for n,t in sorted(exits)]}
prefix_asm=(D/(prefix+'.assembly.txt')).read_text();prefix_rows,_=byte_graph(prefix_asm)
prefix_paths=byte_paths(prefix_asm,prefix_rows[0][0],['lean_alloc_small_object_core'])
assert all(x['counts']==[2] and x['target']=='ret' for x in prefix_paths['normal_exits'])
assert prefix not in calls(prefix_asm)
assert all(x in prefix_asm for x in ['shl    $0x8,%rbx','movzbl %r15b,%eax','or     %rax,%rbx'])
public_asm=(D/(P+'bytesValue.assembly.txt')).read_text();byte_rows,_=byte_graph(public_asm);starts={}
for label,constant in [('short','$0x11,%rax'),('medium','$0x21,%rax')]:
 ix=[i for i,(_,op,arg) in enumerate(byte_rows) if (op,arg)==('cmp',constant)];assert len(ix)==1;i=ix[0]
 assert byte_rows[i+1][1]=='jbe';starts[label]=int(byte_rows[i+1][2].split()[0],16)
 if label=='medium':starts['long']=byte_rows[i+2][0]
tracked=[prefix,fallback,'lean_nat_shiftl'];byte_branches={name:byte_paths(public_asm,start,tracked) for name,start in starts.items()}
for name,expected in [('short',[0,0,0]),('medium',[1,0,1]),('long',[0,1,0])]:assert all(x['counts']==expected for x in byte_branches[name]['normal_exits'])
assert sum(op=='shl' and arg.startswith('$0x8,') for _,op,arg in byte_rows)==2
assert P+'bytesValue' in calls((D/(P+'decodeFrame.assembly.txt')).read_text())
assert all(x in (D/(fallback+'.assembly.txt')).read_text() for x in ['lean_nat_big_mul','lean_nat_big_add'])
byte_cfg=D/'byte-native-cfg.json';assert not byte_cfg.exists();byte_cfg.write_text(json.dumps({'prefix':prefix_paths,'public_branches':byte_branches,'limits':'Conservative normal-return CFG traversal assumes ordinary calls return. Counts are static paths, not corpus frequencies. Inlined word arithmetic remains live.'},indent=2)+'\n')
normalize=lambda text:re.sub(r'(?<=_)\d+(?=_)','N',text)
ownership={}
for module,removed,changed in [('Frame','decodeFrame___boxed','decodeFrame'),('Message','decode___boxed','decodePrefix')]:
 old_path=Path('tests/evidence/diagnostics/gen11/generated-c/Impl/'+module+'.c');new_path=Path('.lake/build/ir/Impl/'+module+'.c');a=old_path.read_text();b=new_path.read_text()
 previous_native=next(x for x in load('bench/runs/gen11/fresh-native-inputs.json') if x['source']=='Impl/'+module+'.lean')
 assert sha('Impl/'+module+'.lean')==previous_native['source_sha256']
 assert sha(old_path)==previous_native['artifacts'][str(new_path)]['sha256']
 symbols=lambda text:set(re.findall(r'^(?:LEAN_EXPORT )?(?:lean_object\*|uint\d+_t|void|size_t)\s+(\w+)\([^;\n{}]*\)\{',text,re.M))
 prior_symbols,new_symbols=symbols(a),symbols(b)
 assert prior_symbols-new_symbols=={P+removed} and not new_symbols-prior_symbols
 deltas={}
 for symbol in sorted(new_symbols):
  x,y=normalize(qbody(a,symbol)),normalize(qbody(b,symbol))
  if x==y:continue
  deltas[symbol]=''.join(difflib.unified_diff(x.splitlines(True),y.splitlines(True),fromfile='gen11 normalized C',tofile='gen12 normalized C'))
  if module=='Frame':assert y.count('lean_dec(v_bytes_N_);\n')==2 and x==y.replace('lean_dec(v_bytes_N_);\n','')
  else:
   boundary='= '+P+'decode(v___x_N_);\n';assert x.count(boundary+'lean_dec(v___x_N_);\n')==1
   assert y==x.replace(boundary+'lean_dec(v___x_N_);\n',boundary)
 assert set(deltas)=={P+changed}
 ownership[module]={'source_unchanged_sha256':sha('Impl/'+module+'.lean'),'old_C_sha256':sha(old_path),'new_C_sha256':sha(new_path),'removed_wrapper':P+removed,'normalized_body_deltas':deltas}
ownership_path=D/'dependent-native-ownership.json';assert not ownership_path.exists();ownership_path.write_text(json.dumps(ownership,indent=2)+'\n')
byte_excerpts={}
for symbol in [prefix,word,fallback,P+'bytesWord']:
 piece=body(bits_c,symbol);path=D/(symbol+'.generated-C.txt');assert not path.exists();path.write_text(piece+'\n')
 start=bits_c.index(piece);first=bits_c[:start].count('\n')+1
 byte_excerpts[symbol]={'path':str(path),'sha256':sha(path),'source':str(bits_path),'source_sha256':sha(bits_path),'first_body_line':first,'last_body_line':first+piece.count('\n')}
out['byte_words_live_path_verified']=True
out['byte_word_prefix_anchor']=prefix;out['byte_word_fallback_anchor']=fallback
out['byte_words_native_context']={'public_anchor':P+'bytesValue','public_standalone_present':True,'prefix_standalone_present':True,'fallback_standalone_present':True,'word_wrapper_standalone_present':False,'specialized_word_fold_standalone_present':False,'word_fold_inlined_into_public':True,'decodeFrame_calls_public':True,'native_cfg':str(byte_cfg),'native_cfg_sha256':sha(byte_cfg),'ownership_delta_generation_pair':[11,12],'ownership_deltas':str(ownership_path),'ownership_deltas_sha256':sha(ownership_path),'generated_C_excerpts':byte_excerpts,'unchanged_native_sets_including_model':len(objects)-len(changed_objects)-1,'observations':[
 'The actual public bytesValue remains a native boundary called from decodeFrame. Its specialized UInt64 folds inline into that public function: two shift/byte-OR loop sites implement the short and suffix paths. Missing word-fold symbols do not mean zero arithmetic.',
 'The length guards select <=8, 9..16 and >16 branches. Every normal medium path calls the eight-byte prefix helper once and performs one exact natural shift. The wide branch retains the arbitrary-precision Nat fold; runtime reachability requires raw profile entries, not this static inspection.',
 'The prefix loop returns the existing suffix and allocates its UInt64 box/pair only on exit. Conservative CFG traversal finds exactly two direct small-object allocation calls per normal return; arbitrary count arithmetic and ownership callees are not asserted allocation-free.',
 'Frame and Message Lean sources are unchanged, but generated borrowing wrappers disappeared and list decrements moved with ownership. Exact normalized C deltas are retained. In gen13, every native set except CommB remains unchanged from gen12; the actual fresh benchmark inventory binds all 22 linked modules.',
 'No exclusive attribution rule changes. Bookkeeping can move across compiler caller boundaries, so small stage differences are not automatically semantic changes. Helper inclusive costs overlap callers and each other; missing wrappers cannot establish zero work or savings.',
 'The proof is unconditional on every byte list. This static review runs no decoder, test, build or benchmark and makes no observed corpus count claim. Frozen entrypoints remain live delegates.'
]}


# Independently bind the new wind penalty to the freshly timed worker.
wind=P+'cbWindPenalty50';wtable=P+'cbWindPenaltyTable';wentry=wtable+'___lam__0'
wind_c=body(commb,wind);wentry_c=body(commb,wentry);wconstruct=qbody(commb,'_init_'+wtable+'___closed__1')
assert wind in names and wentry in names and wtable in names
assert wind_c.count(P+'payloadBits(')==4
assert all('lean_unsigned_to_nat('+str(n)+'u)' in wind_c for n in [46,24,1,47,25,10,1023])
assert wind_c.count('lean_nat_dec_eq(')==2 and wind_c.count('lean_nat_add(')==wind_c.count('lean_nat_sub(')==wind_c.count('lean_array_fget_borrowed(')==1
assert not any(x in wind_c for x in ['Binary64_','l_Rat_','Array_ofFn','lean_array_set'])
ordered=['l_Rat_sub','l_Rat_mul',P+'Binary64_round','l_Rat_abs',P+'Binary64_div',P+'Binary64_sub']
assert all(wentry_c.count(n+'(')==1 for n in ordered)
assert [wentry_c.index(n+'(') for n in ordered]==sorted(wentry_c.index(n+'(') for n in ordered)
for name,n in [('cbVertical60___closed__1',0),('cbGaussian___closed__1',2),('cbWindPenaltyTable___lam__0___closed__0',1023),('cbDensityTerms___lam__3___closed__1',100)]:
 assert 'lean_unsigned_to_nat('+str(n)+'u)' in qbody(commb,'_init_'+P+name)
assert all(x in wconstruct for x in ['lean_unsigned_to_nat(2047u)','l_Array_ofFn___redArg(',wtable+'___closed__0'])
assert '.m_fun = (void*)'+wentry in commb
assert wtable+' = _init_'+wtable+'();\nlean_mark_persistent('+wtable+');' in init
assert commb.count(wtable+' =')==1
# main initialization chain was checked above for QNH and reaches the same
# eager CommB module initialization before any run request.
wassembly=(D/(wind+'.assembly.txt')).read_text();wrows,windex=byte_graph(wassembly)
field_sites=[i for i,(_,op,arg) in enumerate(wrows) if op=='call' and '<'+P+'payloadBits>' in arg]
assert len(field_sites)==4
wevents={}
for i,label,start,width in zip(field_sites,['status46','status24','tas47','gs25'],[46,24,47,25],[1,1,10,10]):
 context=[(op,arg) for _,op,arg in wrows[max(0,i-4):i]]
 assert ('mov',f'$0x{start*2+1:x},%esi') in context and ('mov',f'$0x{width*2+1:x},%edx') in context
 wevents[wrows[i][0]]=label
loads=[a for a,op,arg in wrows if op=='mov' and arg.startswith('0x18(%r15,%rcx,4),')]
assert len(loads)==1;wevents[loads[0]]='table_load'
todo=[(0,())];visited=set();wexits=set()
while todo:
 i,events=todo.pop()
 if (i,events) in visited:continue
 visited.add((i,events));addr,op,arg=wrows[i]
 if addr in wevents:events+=(wevents[addr],)
 assert len(events)<=5
 if op=='ret':wexits.add((events,'ret'));continue
 if op.startswith('j'):
  m=re.fullmatch(r'([0-9a-f]+) <([^>]+)>',arg);assert m,arg;target=int(m[1],16)
  if target in windex:todo.append((windex[target],events))
  else:assert op=='jmp';wexits.add((events,m[2]))
  if op=='jmp':continue
 assert i+1<len(wrows);todo.append((i+1,events))
assert len(wrows)==len({i for i,_ in visited})==197
assert {x for x,_ in wexits}=={('status46',),('status46','status24'),('status46','status24','tas47','gs25','table_load')}
assert not any(any(x in n for x in ['Binary64_','Rat_','Array_ofFn']) for n in calls(wassembly))
assert [x for x in calls((D/(wentry+'.assembly.txt')).read_text()) if x in ordered]==ordered
assert '$0xfff,%edi' in (D/('_init_'+wtable+'___closed__1.assembly.txt')).read_text()
assert 'l_Array_ofFn___redArg' in calls((D/('_init_'+wtable+'___closed__1.assembly.txt')).read_text())
assert all(x in init_asm for x in ['<'+wtable+'>','<_init_'+wtable+'___closed__1>','<lean_mark_persistent>'])
assert calls((D/(P+'cbPenalty.assembly.txt')).read_text()).count(wind)==1
assert P+'Binary64_sub' in calls((D/(P+'cbPenalty.assembly.txt')).read_text()) and P+'Binary64_div' in calls((D/(P+'cbPenalty.assembly.txt')).read_text())
for name in ['cbScorePasses','cbScorePasses___lam__0___boxed']:
 assert calls((D/(P+name+'.assembly.txt')).read_text()).count(P+'cbPenalty')==1
wcfg=D/'wind-native-cfg.json';assert not wcfg.exists()
wcfg.write_text(json.dumps({'instruction_count':len(wrows),'reachable_instructions':len({i for i,_ in visited}),'event_sites':{hex(a):n for a,n in wevents.items()},'normal_exits':[{'events':list(events),'target':target} for events,target in sorted(wexits)],'assembly':str(D/(wind+'.assembly.txt')),'assembly_sha256':sha(D/(wind+'.assembly.txt')),'limits':'Conservative native branch traversal assumes calls return; it does not measure per-message populations or callee work.'},indent=2)+'\n')
wexcerpts={}
for name in [wind,wentry,'_init_'+wtable+'___closed__1',P+'cbPenalty']:
 piece=qbody(commb,name);path=D/(name+'.generated-C.txt');assert not path.exists();path.write_text(piece+'\n')
 first=commb[:commb.index(piece)].count('\n')+1
 wexcerpts[name]={'path':str(path),'sha256':sha(path),'source':'.lake/build/ir/Impl/CommB.c','source_sha256':sha('.lake/build/ir/Impl/CommB.c'),'first_body_line':first,'last_body_line':first+piece.count('\n')}
helper_review=Path('tests/evidence/optimization/gen13/native-review/source-proof-review.json')
integration_review=Path('tests/evidence/optimization/gen13/native-review/integration-proof-review.json')
assert load(helper_review)['all_Nat_runtime_equality_verified'] and load(helper_review)['status']=='passed'
assert load(integration_review)['status']=='passed' and load(integration_review)['sources']==load('tests/evidence/optimization/gen13/integration/targeted-build.json')['inputs_after']
for source,digest in load(integration_review)['sources'].items():assert sha(source)==digest
out['bds50_wind_penalty_live_path_verified']=True
out['wind_penalty_anchor']=wind;out['wind_penalty_table_entry_anchor']=wentry
out['wind_penalty_native_context']={'immutable_entries':2047,'eager_initialized_before_main':True,'lookup_standalone_present':True,'entry_standalone_present':True,'native_cfg':str(wcfg),'native_cfg_sha256':sha(wcfg),'generated_C_excerpts':wexcerpts,'independent_helper_review':str(helper_review),'independent_helper_review_sha256':sha(helper_review),'independent_integration_review':str(integration_review),'independent_integration_review_sha256':sha(integration_review),'unchanged_other_linked_native_sets':20,'observations':[
 'All signed TAS-minus-ground-speed differences from -1023 through 1023 have an exact entry. The full table body preserves rational difference and scale, software round, absolute value, software division and subtraction in the original order.',
 'The actual timed worker eagerly constructs and marks the complete 2047-entry table persistent before main. Initialization is outside decoder-root instruction collection and warmed benchmark samples; no initialization cost is assigned to a missing call context.',
 'The live public cbWindPenalty50 retains both status tests and exact raw code extraction. Its native CFG has only the missing-status returns or the ordered status46/status24/TAS47/GS25/table-load path. No Rat or Binary64 operation appears in its direct lookup calls.',
 'Both fast interval scoring and the conditional full software fallback still call the same cbPenalty, which calls the table helper at its BDS50 wind site. Turn adjustment and BDS60 software division remain live and unchanged.',
 'All 22 timed source/C/object/trace sets and 21 reused driver objects are bound. All linked native sets except CommB match gen12; earlier byte/ownership, CRC, affine, field, Mach/QNH and integer paths are independently rechecked.',
 'Actual lookup and constructor entries require the raw-profile recount against BDS50 reached scores and fallback populations. Inclusive helper observations overlap parent/probe costs; no branch frequency, zero work or speed gain is inferred from static structure.'
]}
out['byte_words_native_context']['observations'][3]='The gen11-to-gen12 ownership change is retained explicitly as historical context. Gen13 Frame/Message and byte-conversion sources, C and objects match gen12 exactly; only CommB changes. The fresh benchmark inventory binds every linked module.'



for name,digest in build['unchanged_native_inputs'].items():assert sha(name)==digest,name
for name,digest in build['production_sources'].items():assert sha(name)==digest,name

p=E/'source-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(sha(p))
