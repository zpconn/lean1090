"""Read-only source/native association; no build or decoder execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, importlib.util, json, re, subprocess

E = Path('tests/evidence/diagnostics/gen16')
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

build_path=Path('.cache/gen16-costs/driver/driver-build.json')
build=read(build_path); bench=read('bench/runs/gen16/summary.json')
native_path=Path('bench/runs/gen16/fresh-native-inputs.json'); native=read(native_path)
oldpath=Path('tests/evidence/diagnostics/gen15/source-review.json'); old=read(oldpath)
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
assert bind_benchmark_history.inspect(build_path,Path('bench/runs/gen16/summary.json'),None,
    Path('bench/runs/gen16/correctness-inputs.json'))==read(binding_path)

old_native={r['source']:r for r in read('bench/runs/gen15/fresh-native-inputs.json')}
unchanged=[]
for row in native:
    if row['source']=='Impl/Bits.lean':continue
    assert row==old_native[row['source']],row['source']
    unchanged.append(row['source'])
assert len(unchanged)==21
# Changed module retains all non-packing definitions verbatim in Lean.
oldbits=Path('tests/evidence/diagnostics/gen15/production-source/Impl/Bits.lean').read_text()
newbits=Path('Impl/Bits.lean').read_text()
assert oldbits[:oldbits.index('def packFields')]==newbits[:newbits.index('def packFields')]
assert oldbits[oldbits.index('-- Initial algorithm: Spec/Bits.lean:31.'):]==newbits[newbits.index('-- Initial algorithm: Spec/Bits.lean:31.'):]
oldc=Path('tests/evidence/diagnostics/gen15/generated-c/Impl/Bits.c').read_text()
cpath=Path('.lake/build/ir/Impl/Bits.c'); c=cpath.read_text()
for name in re.findall(r'LEAN_EXPORT [^\n]+ (\w+)\([^\n]*\)\{',oldc):
    if 'packFields' in name:continue
    before=body(oldc,name)[0];after=body(c,name)[0]
    assert re.sub(r'v_\w+','V',before)==re.sub(r'v_\w+','V',after),name

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
anchors.update([fold,P+'packFields',P+'decode',P+'frameSyndrome'])
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
                       (P+'frameSyndrome',message_path,message),(P+'decode',message_path,message)]:
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
implementation=Path('tests/evidence/optimization/gen16/native-review/review.json')
ir=read(implementation);assert ir['status']=='passed' and ir['findings']==[]
assert ir['inputs']['.lake/build/bin/lean1090-bench']==bench['binary_sha256']
for name,digest in ir['inputs'].items():assert sha(name)==digest,name

out={k:old[k] for k in old if k.endswith('_verified') or k.endswith('_anchor') or k=='integer_score_gate_anchors'}
out.update(status='passed_read_only_source_and_native_review',recorded_utc=datetime.now(timezone.utc).isoformat(),
    commit=build['commit'],timed_commit=bench['commit'],binary_sha256=sha(WORKER),
    benchmark_source_binding_sha256=sha(binding_path),fresh_native_inputs=str(native_path),
    fresh_native_inputs_sha256=sha(native_path),fresh_project_modules_verified=22,
    source_C_object_trace_bindings=bindings,driver_build_manifest=str(build_path),
    driver_build_manifest_sha256=sha(build_path),driver_binary_sha256=sha('.cache/gen16-costs/driver/decode-costs'),
    reused_production_objects_verified=21,unchanged_driver_input_hashes_verified=len(held),
    eager_table_initializers=old['eager_table_initializers'],
    live_generated_C={path:sha(path) for path in old['live_generated_C']},
    pack_fields_shift_mask_verified=True,pack_fields_fold_anchor=fold,
    commands=commands,generated_C_excerpts=excerpts,
    symbol_inventory={'path':str(symbols),'sha256':sha(symbols),'filtered':True},
    unchanged_native_modules=unchanged,
    previous_source_review={'path':str(oldpath),'sha256':sha(oldpath),
        'basis':'All 21 sibling source/C/object/trace sets match the prior reviewed generation byte-for-byte. Non-packing Bits Lean definitions are verbatim and their generated C bodies match modulo local variable identifiers; prior path assessments therefore apply. Current linked anchor symbols are separately checked.'},
    implementation_native_review={'path':str(implementation),'sha256':sha(implementation)},
    review_script=str(Path(__file__)),review_script_sha256=sha(__file__),findings=[],
    observations=['The accumulator uses arbitrary Nat shift in both branches. Width<64 value reduction uses UInt64 shift/mask; the wide branch retains Nat pow/mod.',
        'Actual decode -> frameSyndrome -> packFields -> specialized fold remains live. No alternate adapter-only path was added.',
        'Packing keeps Nat additions and ownership operations; absence of named helper edges cannot imply zero inlined work. Eager field-code tables and the Comm-B payload-limit initializer remain unchanged.'],
    limits='Read-only source/generated-C/native inspection; no builds, decoder executions, timing or profiles. Actual branch populations and instruction costs require the later raw recount. Historical content is referenced by existing hashes rather than recopied.')
for name,digest in held.items():assert sha(name)==digest,name
assert sha(WORKER)==bench['binary_sha256']
save(E/'independent-review/source-review.json',out)
print(json.dumps({'status':'passed','source_review_sha256':sha(E/'independent-review/source-review.json'),
                  'native_sets':22,'unchanged_other_sets':len(unchanged),'targeted_assembly_commands':len(commands)}))

