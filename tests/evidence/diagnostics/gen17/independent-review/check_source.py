"""Read-only source/native association; no build or decoder execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, importlib.util, json, re, subprocess

E = Path('tests/evidence/diagnostics/gen17')
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

build_path=Path('.cache/gen17-costs/driver/driver-build.json')
build=read(build_path); bench=read('bench/runs/gen17/summary.json')
native_path=Path('bench/runs/gen17/fresh-native-inputs.json'); native=read(native_path)
oldpath=Path('tests/evidence/diagnostics/gen16/independent-review/source-review.json'); old=read(oldpath)
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
assert bind_benchmark_history.inspect(build_path,Path('bench/runs/gen17/summary.json'),None,
    Path('bench/runs/gen17/correctness-inputs.json'))==read(binding_path)

old_native={r['source']:r for r in read('bench/runs/gen16/fresh-native-inputs.json')}
unchanged=[]
for row in native:
    if row['source']=='Impl/Binary64.lean':continue
    before=old_native[row['source']]
    assert row['source_sha256']==before['source_sha256'],row['source']
    assert {p:r['sha256'] for p,r in row['artifacts'].items()}=={p:r['sha256'] for p,r in before['artifacts'].items()},row['source']
    unchanged.append(row['source'])
assert len(unchanged)==21
# Only Binary64 source/native changed; all sibling modules retain prior reviewed paths.
oldbinary=subprocess.check_output(['git','cat-file','blob',read('bench/runs/gen16/summary.json')['commit']+':Impl/Binary64.lean'],text=True)
newbinary=Path('Impl/Binary64.lean').read_text()
assert oldbinary[oldbinary.index('def nearestEven'):]==newbinary[newbinary.index('def nearestEven'):]
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

anchors={old[k] for k in old if k.endswith('_anchor')}
anchors.update(old['integer_score_gate_anchors'].values())
anchors.update([fold,P+'packFields',P+'decode',P+'frameSyndrome',S+'powerTwo',S+'powerTwoFormula',S+'powerTwoTable___lam__0',ctor,init])
symbol_rows=[]
proc=subprocess.Popen(['nm','--defined-only',WORKER],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
for line in proc.stdout:
    if line.split() and line.split()[-1] in anchors:symbol_rows.append(line)
assert proc.wait()==0 and not proc.stderr.read()
present={line.split()[-1] for line in symbol_rows}
assert anchors-{old['byte_word_fallback_anchor']}<=present,anchors-present
symbols=D/'selected-symbols.txt';retain(symbols,''.join(symbol_rows).encode())
commands=[];excerpts={};assemblies={}
for name,path,text in [(fold,cpath,c),(P+'packFields',cpath,c),
                       (P+'frameSyndrome',message_path,message),(P+'decode',message_path,message),
                       *[(name,binarycpath,binaryc) for name in [S+'powerTwo',S+'powerTwoFormula',S+'powerTwoTable___lam__0',ctor,init]]]:
    value,line=body(text,name);p=D/(name+'.generated-C.txt');retain(p,(value+'\n').encode())
    excerpts[name]={'source':str(path),'source_sha256':sha(path),'first_body_line':line,'path':str(p),'sha256':sha(p)}
    target=D/(name+'.assembly.txt');argv=['objdump','-d','--no-show-raw-insn','--disassemble='+name,WORKER]
    r=subprocess.run(argv,capture_output=True);assert r.returncode==0 and not r.stderr
    retain(target,r.stdout);assemblies[name]=r.stdout.decode()
    assert '<'+name+'>:' in assemblies[name]
    commands.append({'argv':argv,'output':str(target),'sha256':sha(target),'exit_code':0})
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
implementation=Path('tests/evidence/optimization/gen17/independent-review/native-review.json')
ir=read(implementation);assert ir['status']=='passed' and ir['findings']==[] and ir['power_two_table_live_path_verified']
ni=read('tests/evidence/optimization/gen17/independent-review/native-inputs.json')
assert ni['worker_sha256']==sha(WORKER)==bench['binary_sha256']
for name,digest in ni['held_inputs'].items():assert sha(name)==digest,name
for name,digest in ir['bindings'].items():assert sha(name)==digest,name
for name,row in ir['files'].items():assert sha(name)==row['sha256'] and Path(name).stat().st_size==row['bytes']

out={k:old[k] for k in old if k.endswith('_verified') or k.endswith('_anchor') or k=='integer_score_gate_anchors'}
out.update(status='passed_read_only_source_and_native_review',recorded_utc=datetime.now(timezone.utc).isoformat(),
    commit=build['commit'],timed_commit=bench['commit'],binary_sha256=sha(WORKER),
    benchmark_source_binding_sha256=sha(binding_path),fresh_native_inputs=str(native_path),
    fresh_native_inputs_sha256=sha(native_path),fresh_project_modules_verified=22,
    source_C_object_trace_bindings=bindings,driver_build_manifest=str(build_path),
    driver_build_manifest_sha256=sha(build_path),driver_binary_sha256=sha('.cache/gen17-costs/driver/decode-costs'),
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
        'basis':'All 21 sibling source/C/object/trace sets match generation16 byte-for-byte. Binary64 definitions after powerTwo are verbatim; unconditional central equalities and current linked initialization/lookup/fallback are separately checked. Existing anchor symbols remain linked.'},
    implementation_native_review={'path':str(implementation),'sha256':sha(implementation)},
    review_script=str(Path(__file__)),review_script_sha256=sha(__file__),findings=[],
    reviewer_attempts=[],
    observations=['The live inclusive [-1074,1023] guard selects one immutable indexed table read; both outside-range branches call the exact original formula.',
        'The table entry constructor calls only powerTwoFormula, and the complete2098-entry array is forced/persisted during module initialization before worker execution.',
        'The prior complete initialization-chain disassembly is rebound to the same actual worker hash; no timing, exponent distribution or table hit rate is inferred.',
        'All prior decoder paths are still linked; packFields retains its exact Nat-shift and bounded machine-mask/fallback branches.',
        'Only Binary64 source/native changed among22linkedsets; existing eager field-score tables remain unchanged.'],
    limits='Read-only source/generated-C/native inspection; no builds, decoder executions, timing or profiles. Actual branch populations and instruction costs require the later raw recount. Historical content is referenced by existing hashes rather than recopied.')
for name,digest in held.items():assert sha(name)==digest,name
assert sha(WORKER)==bench['binary_sha256']
save(E/'independent-review/source-review.json',out)
print(json.dumps({'status':'passed','source_review_sha256':sha(E/'independent-review/source-review.json'),
                  'native_sets':22,'unchanged_other_sets':len(unchanged),'targeted_assembly_commands':len(commands)}))

