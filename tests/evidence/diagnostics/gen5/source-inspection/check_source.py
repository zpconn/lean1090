"""Read-only source/native binding review; no decoder/build execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,re,shlex,subprocess
E=Path('tests/evidence/diagnostics/gen5'); D=E/'source-inspection'; P='lp_lean1090_Lean1090_Impl_'
load=lambda p:json.loads(Path(p).read_text())
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
bench=load('bench/runs/gen5/summary.json');commit=bench['commit'];native_path=Path('bench/runs/gen5/fresh-native-inputs.json');native=load(native_path)
worker='.lake/build/bin/lean1090-bench';build_path=Path('.cache/gen6-planning/driver/driver-build.json');build=load(build_path)
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
for name,record in load('bench/runs/gen5/binary-built.json')['native_hashes'].items():assert sha(name)==record,name
oldbuild=load('tests/evidence/diagnostics/gen4/driver/driver-build.json')
assert objects['.lake/build/ir/Impl/CommB.c.o.export']!=oldbuild['reused_production_objects']['.lake/build/ir/Impl/CommB.c.o.export']
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
old=load('tests/evidence/diagnostics/gen4/source-review.json')
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
extra=load(D/'mach-commands.json');commands.extend(extra)
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
out={'status':'passed_read_only_source_and_native_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'commit':commit,'binary_sha256':sha(worker),'fresh_native_inputs':str(native_path),'fresh_native_inputs_sha256':sha(native_path),'fresh_project_modules_verified':22,'source_C_object_trace_bindings':bindings,'exact_fallback_anchor':P+'cbScorePasses___lam__0___boxed','eager_table_initializers':tables,'live_generated_C':{'.lake/build/ir/Impl/'+name+'.c':sha('.lake/build/ir/Impl/'+name+'.c') for name in ['CommB','ScoreGate','Parity','PayloadBits']},'driver_build_manifest':str(build_path),'driver_build_manifest_sha256':sha(build_path),'driver_binary_sha256':sha('.cache/gen6-planning/driver/decode-costs'),'reused_production_objects_verified':21,'unchanged_driver_input_hashes_verified':len(build['unchanged_native_inputs']),'commands':commands,'symbol_inventory':{'path':str(D/'symbols.txt'),'sha256':sha(D/'symbols.txt')},'crc_native_context':old['crc_native_context'],'parity_fold_anchor':anchors[1],'payload_bits_anchor':P+'payloadBits','payload_native_context':{'payloadBits_standalone_present':True,'payloadWordBits_standalone_present':False,'wide_fallback_native_pow_call_sites':2,'source_observations':['For width<64, generated C contains UInt64 conversion, right shift, left-shift mask construction, subtraction and AND; no natural power/division/remainder call occurs in that branch.','Machine code implements mask as shl/not/and, retains the width comparison and returns a tagged natural. Arbitrary large natural inputs retain conversion/helper paths.','Width>=64 retains both callable lean_nat_pow sites and natural division/remainder, including big-natural branches. Observed fallback call counts require actual profile data; this static review makes no corpus reachability claim.','The inline helper has no final standalone symbol. Its arithmetic remains in live payloadBits; absent helper symbol is not zero extraction work.','All original live callers still target payloadBits. Its generated C and native object are unchanged from gen4.','Source/C and native object hashes match the actual clean gen5 timed build; the diagnostic links those unchanged production objects.']},'score_native_context':['The interval choose function retains conditional lean_apply_1 for the boxed callback; that callback calls actual software cbDensity, cbPenalty and Binary64.add.','All 13 table initializers are eager and persistent in initialize_Impl_CommB, before main. Table construction is outside decoder-root collection and warmed timing.','No fallback-count claim is derived from the static symbol presence; final raw-profile/census accounting remains required.'],'review_script':str(Path(__file__)),'review_script_sha256':sha(__file__),'limits':'Static source, C, symbols, disassembly and hash inspection only. No decoder, test, native profile, build or benchmark execution. Complete raw-profile/accounting/archive review remains assigned to independent final reviewer.'}
out['mach_native_context']={'public_function':'Impl.cbMach64','native_standalone_present':False,'object_definition_present':True,'immutable_code_count':1024,'table_eager_initialized':True,'actual_caller_anchors':[P+x for x in ['cbValid60','cbPenalty','cbDensityTerms']], 'observations':['The generated C cbMach64 body is precisely payloadBits(word,25,10) and a borrowed lookup into the persistent global table; no software conversion arithmetic or table construction remains in this body.','The table closure preserves software literal rounding, multiplication, then division for all 1024 codes. Module initialization constructs and marks the value table persistent before message processing.','The live timed worker inlines cbMach64 in cbValid60, cbPenalty and cbDensityTerms. Retained assembly includes the global table address, actual field extraction call with tagged 25/10 arguments and indexed loads. The standalone linked cbMach64 symbol is absent, while its object definition remains.','A missing cbMach64 call context cannot mean zero Mach computation: the table lookup work is now part of caller self/runtime cost. Native caller stages and independent candidate/score probes remain the attribution boundaries.','Other binary64 work remains live, including penalty division and the exact score fallback. No rate claim or unobserved fallback count follows from this static inspection.']}
p=E/'source-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(sha(p))
