"""Read-only source/native association; no build or decoder execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, importlib.util, json, re, subprocess

E = Path('tests/evidence/diagnostics/gen15')
D = E / 'source-inspection'
P = 'lp_lean1090_Lean1090_Impl_'
WORKER = '.lake/build/bin/lean1090-bench'
def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, value):
    assert not p.exists(), p
    p.write_text(json.dumps(value, indent=2) + '\n')
def body(text, name):
    m = re.search(r'(?:LEAN_EXPORT|static) [^\n]+ '+re.escape(name)+r'\([^\n]*\)\s*\{', text)
    assert m, name
    start=m.end()-1; depth=0
    for end in range(start,len(text)):
        depth += (text[end]=='{')-(text[end]=='}')
        if depth==0: return text[start:end+1], text[:start].count('\n')+1
    raise AssertionError(name)

build_path=Path('.cache/gen15-costs/driver/driver-build.json')
build=read(build_path); bench=read('bench/runs/gen15/summary.json')
native_path=Path('bench/runs/gen15/fresh-native-inputs.json'); native=read(native_path)
old=read('tests/evidence/diagnostics/gen14/source-review.json')
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
assert bind_benchmark_history.inspect(build_path,Path('bench/runs/gen15/summary.json'),None,
    Path('bench/runs/gen15/correctness-inputs.json'))==read(binding_path)

old_native=read('bench/runs/gen14/fresh-native-inputs.json')
old_native={row['source']:row for row in old_native}
unchanged=[]
for row in native:
    if row['source'] in ['Impl/CommB.lean','Impl.lean','Bench/WholeDecoder.lean']: continue
    oldrow=old_native[row['source']]
    assert row['source_sha256']==oldrow['source_sha256']
    assert {k:v['sha256'] for k,v in row['artifacts'].items() if not k.endswith('.trace')}=={
        k:v['sha256'] for k,v in oldrow['artifacts'].items() if not k.endswith('.trace')},row['source']
    unchanged.append(row['source'])
assert len(unchanged)==19

commb_path=Path('.lake/build/ir/Impl/CommB.c'); commb=commb_path.read_text()
guard,_=body(commb,P+'bdsWireValid'); init,_=body(commb,'initialize_lean1090_Impl_CommB')
constant,_=body(commb,'_init_'+P+'commBPayloadLimit')
assert P+'commBPayloadLimit' in guard and 'lean_cstr_to_nat' not in guard
assert constant.count('lean_cstr_to_nat("72057594037927936")')==1
assert init.count(P+'commBPayloadLimit = _init_'+P+'commBPayloadLimit();')==1
assert 'lean_mark_persistent('+P+'commBPayloadLimit);' in init
assert init.index(P+'commBPayloadLimit =') < init.index('lean_mark_persistent('+P+'commBPayloadLimit)')
for local in ['decodeBDS','commBCoreEligible','commBPositionEligible']:
    assert P+'bdsWireValid(' in body(commb,P+local)[0]
score=body(commb,P+'cbScorePasses')[0]
assert P+'cbDensityTermsFast(' in score and P+'ScoreGate_choose(' in score
assert P+'cbScorePasses___lam__0___boxed' in score
assert P+'cbCombinedScore(' in body(commb,P+'cbScorePasses___lam__0')[0]
tables=re.findall(P+r'(cb\w+ScoreTable) = _init_',init)
assert tables==old['eager_table_initializers'] and len(tables)==13
for table in [*tables,'cbMachValueTable','cbQNHValueTable','cbWindPenaltyTable']:
    assert P+table+' = _init_'+P+table+'();' in init
    assert 'lean_mark_persistent('+P+table+');' in init

# Preserve only selected symbol rows and bounded per-function disassemblies.
anchors={old[k] for k in ['exact_fallback_anchor','parity_fold_anchor','payload_bits_anchor',
    'affine_payload_value_anchor','field_mask_anchor','byte_word_prefix_anchor','byte_word_fallback_anchor',
    'wind_penalty_anchor','wind_penalty_table_entry_anchor','ratio_enclosure_anchor']}
anchors.update(old['integer_score_gate_anchors'].values())
anchors.update(P+x for x in ['decode','frameSyndrome','reportWithSyndrome','ScoreGate_choose','cbScorePasses',
    'cbDensityTermsFast','cbDensityTerms','cbValid40','cbValid60','cbPenalty','bdsWireValid','commBCoreEligible',
    'commBEligible','commBPositionEligible','decodeBDS','commBPayloadLimit','cbMachValueTable___lam__0','cbQNHValueTable___lam__0'])
anchors.add('initialize_lean1090_Impl_CommB')
symbol_rows=[]
proc=subprocess.Popen(['nm','--defined-only',WORKER],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
for line in proc.stdout:
    if line.split() and line.split()[-1] in anchors: symbol_rows.append(line)
assert proc.wait()==0 and not proc.stderr.read()
names={line.split()[-1] for line in symbol_rows}
assert anchors-{old['byte_word_fallback_anchor']} <= names,anchors-names
symbols=D/'selected-symbols.txt'; assert not symbols.exists();symbols.write_text(''.join(symbol_rows))
commands=[];assemblies={};excerpts={}
for anchor in sorted(anchors):
    if anchor==P+'commBPayloadLimit':continue
    target=D/(anchor+'.assembly.txt');assert not target.exists()
    argv=['objdump','-d','--no-show-raw-insn','--disassemble='+anchor,WORKER]
    result=subprocess.run(argv,capture_output=True);assert result.returncode==0 and not result.stderr
    target.write_bytes(result.stdout)
    assemblies[anchor]=result.stdout.decode()
    commands.append({'argv':argv,'output':str(target),'sha256':sha(target),'exit_code':0})
for local in ['bdsWireValid','cbScorePasses','cbScorePasses___lam__0','cbMach64','cbQNH64',
              'cbWindPenalty50','cbRatioOutside250800','decodeBDS','commBCoreEligible','commBEligible','commBPositionEligible']:
    value,line=body(commb,P+local);p=D/(local+'.generated-C.txt');assert not p.exists();p.write_text(value+'\n')
    excerpts[local]={'source':str(commb_path),'source_sha256':sha(commb_path),'first_body_line':line,
                     'path':str(p),'sha256':sha(p)}
for name in ['_init_'+P+'commBPayloadLimit','initialize_lean1090_Impl_CommB']:
    value,line=body(commb,name);p=D/(name+'.generated-C.txt');assert not p.exists();p.write_text(value+'\n')
    excerpts[name]={'source':str(commb_path),'source_sha256':sha(commb_path),'first_body_line':line,
                    'path':str(p),'sha256':sha(p)}
ga=assemblies[P+'bdsWireValid']; ia=assemblies['initialize_lean1090_Impl_CommB']
assert '<'+P+'commBPayloadLimit>' in ga and '<lean_cstr_to_nat>' not in ga
for local in ['decodeBDS','commBCoreEligible','commBPositionEligible']:
    assert '<'+P+'bdsWireValid>' in assemblies[P+local],local
lines=ia.splitlines();ix=next(i for i,s in enumerate(lines) if '<'+P+'commBPayloadLimit>' in s)
window=lines[max(0,ix-3):ix+5]
assert any('<lean_cstr_to_nat>' in s for s in window)
assert any('<lean_mark_persistent>' in s for s in window)
assert any('mov' in s and '%rax,(' in s for s in window)
# Read the actual initializer literal from ELF section bytes, not just source.
literal_line=next(s for s in reversed(lines[:ix]) if re.search(r'\blea\s+.*%rdi.*# [0-9a-f]+',s))
address=int(re.search(r'# ([0-9a-f]+)',literal_line)[1],16)
argv=['objdump','-s','--start-address='+str(address),'--stop-address='+str(address+18),WORKER]
r=subprocess.run(argv,capture_output=True);assert r.returncode==0 and not r.stderr
literal=D/'constant-rodata.txt';assert not literal.exists();literal.write_bytes(r.stdout)
chunks=[]
for line in r.stdout.decode().splitlines():
    m=re.match(r'\s*[0-9a-f]+\s+((?:[0-9a-f]{2,8}\s+){1,4})',line)
    if m:chunks.extend(m[1].split())
assert bytes.fromhex(''.join(chunks))==b'72057594037927936\0'
commands.append({'argv':argv,'output':str(literal),'sha256':sha(literal),'exit_code':0})
save(D/'inspection-commands.json',commands)

out={k:old[k] for k in old if k.endswith('_verified') or k.endswith('_anchor') or k=='integer_score_gate_anchors'}
out.update(status='passed_read_only_source_and_native_review',recorded_utc=datetime.now(timezone.utc).isoformat(),
    commit=build['commit'],timed_commit=bench['commit'],binary_sha256=sha(WORKER),
    benchmark_source_binding_sha256=sha(binding_path),fresh_native_inputs=str(native_path),
    fresh_native_inputs_sha256=sha(native_path),fresh_project_modules_verified=22,
    source_C_object_trace_bindings=bindings,driver_build_manifest=str(build_path),
    driver_build_manifest_sha256=sha(build_path),driver_binary_sha256=sha('.cache/gen15-costs/driver/decode-costs'),
    reused_production_objects_verified=21,unchanged_driver_input_hashes_verified=len(held),
    eager_table_initializers=tables,live_generated_C={'.lake/build/ir/Impl/'+n+'.c':sha('.lake/build/ir/Impl/'+n+'.c')
        for n in ['CommB','ScoreGate','Parity','PayloadBits','Message','Bits']},commands=commands,
    symbol_inventory={'path':str(symbols),'sha256':sha(symbols),'filtered':True},
    unchanged_native_modules=unchanged,previous_source_review={'path':'tests/evidence/diagnostics/gen14/source-review.json',
        'sha256':sha('tests/evidence/diagnostics/gen14/source-review.json'),
        'basis':'The 19 listed production source/C/object sets are byte-identical; old path assessments remain applicable. Comm-B is additionally inspected here and bound to its independent gen15 implementation review.'},
    gen15_implementation_native_review={'path':'tests/evidence/optimization/gen15/native-review/review.json',
        'sha256':sha('tests/evidence/optimization/gen15/native-review/review.json')},
    commb_payload_limit_live_path_verified=True,commb_payload_guard_anchor=P+'bdsWireValid',
    commb_payload_limit_initializer_anchor='initialize_lean1090_Impl_CommB',
    constant_native_context={'literal_ascii':'72057594037927936','literal_address':hex(address),
        'initialization_window':window,'generated_C_excerpts':excerpts,
        'observations':['The exact literal is parsed once in eager module initialization, stored globally and marked persistent.',
            'The live guard loads that global; it has no direct decimal-parser call. Actual decodeBDS, eligibility and inference paths retain calls to this guard.',
            'Existing score/table/ratio paths remain live. Startup work is excluded from decoder collection; missing per-call parser edges do not mean zero initialization cost.']},
    review_script=str(Path(__file__)),review_script_sha256=sha(__file__),findings=[],
    limits='Static source/generated-C/native inspection and hashes only. No build, decoder, benchmark or profile execution. Actual profile populations and costs require the later independent raw recount. Targeted assembly and selected symbol rows avoid whole-binary symbol dumps.')
assert read('tests/evidence/optimization/gen15/native-review/review.json')['commb_payload_limit_live_path_verified']
for name,digest in held.items():assert sha(name)==digest,name
assert sha(WORKER)==bench['binary_sha256']
save(E/'source-review.json',out)
print(json.dumps({'status':'passed','source_review_sha256':sha(E/'source-review.json'),
    'native_sets':22,'unchanged_other_sets':len(unchanged),'targeted_assembly_commands':len(commands)}))
