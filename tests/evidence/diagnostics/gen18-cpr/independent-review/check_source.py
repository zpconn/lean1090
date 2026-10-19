"""Independent static CPR-driver/workload review; no decoder or build execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, re, shlex, subprocess

E=Path('tests/evidence/diagnostics/gen18-cpr');D=E/'independent-review/source-inspection'
D.mkdir(parents=True,exist_ok=True)
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,x):
    assert not p.exists(),p
    p.write_text(json.dumps(x,indent=2)+'\n')
def body(text,name):
    m=re.search(r'(?:LEAN_EXPORT|static) [^\n]+ '+re.escape(name)+r'\([^\n]*\)\s*\{',text);assert m,name
    start=m.end()-1;depth=0
    for end in range(start,len(text)):
        depth+=(text[end]=='{')-(text[end]=='}')
        if depth==0:return text[start:end+1],text[:start].count('\n')+1
    raise AssertionError(name)

buildpath=Path('.cache/gen18-cpr-costs/driver-final/driver-build.json');build=read(buildpath)
sourcepath=Path('review/diagnostics/CPRCosts.lean');source=sourcepath.read_text()
frozenpath=Path('Bench/WholeDecoder.lean');frozen=frozenpath.read_text()
nativepath=Path('bench/runs/gen18/fresh-native-inputs.json');native=read(nativepath)
bench=read('bench/runs/gen18/summary.json');worker='.lake/build/bin/lean1090-bench'
binary='.cache/gen18-cpr-costs/driver-final/cpr-costs';cpath=Path('.cache/gen18-cpr-costs/driver-final/CPRCosts.c');c=cpath.read_text()
assert build['status']=='passed' and sha(worker)==bench['binary_sha256']
assert len(native)==build['fresh_benchmark_native_binding']['linked_project_objects']==22
assert build['fresh_benchmark_native_binding']['sha256']==sha(nativepath)
assert subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()==build['commit']
held={**build['unchanged_native_inputs'],**build['production_sources'],**build['artifacts']}
for name,digest in held.items():assert sha(name)==digest,name
for row in native:
    assert row['source_sha256']==build['linked_project_inventory']['sources'][row['source']]
    for commit in [build['commit'],bench['commit']]:
        assert hashlib.sha256(subprocess.check_output(['git','cat-file','blob',commit+':'+row['source']])).hexdigest()==row['source_sha256']
    for path,record in row['artifacts'].items():assert sha(path)==record['sha256']==held[path]
assert build['reused_production_object_count']==len(build['reused_production_objects'])==21
rsp=shlex.split(Path('.cache/gen18-cpr-costs/driver-final/cpr-costs.rsp').read_text())
original=shlex.split(Path('.lake/build/bin/lean1090-bench.rsp').read_text())
oldobject=str(Path('.lake/build/ir/Bench/WholeDecoder.c.o.export').resolve())
newobject=str(Path('.cache/gen18-cpr-costs/driver-final/CPRCosts.c.o').resolve())
assert original.count(oldobject)==1 and rsp==[newobject if s==oldobject else s for s in original]
compilecmd=next(x['argv'] for x in build['commands'] if x['label']=='driver-clang')
assert '-O3' in compilecmd and '-ffp-contract=off' in compilecmd

# All input/preparation and routing bodies are literal copies of frozen source.
start='private def expectedMessages';stop='private def floatBits'
worker_prefix=frozen[frozen.index(start):frozen.index('/-- Observable post-clock consumer.')]
driver_prefix=source[source.index(start):source.index(stop)]
assert worker_prefix.rstrip()==driver_prefix.rstrip()
looptext=source[source.index('@[noinline] def runCPR'):source.index('private def hashBytes')]
assert 'IO.mono' not in source and 'Array.mkEmpty' not in looptext
assert looptext.count('Impl.decode input.bytes')==1 and looptext.count('advance geo state input.timestamp message')==1
assert 'output := output.push ⟨message, next.2⟩' in looptext
execute_text=source[source.index('private def execute'):source.index('end Lean1090.Diagnostics.CPRCosts')]
assert execute_text.index('Array.mkEmpty')<execute_text.index('command wait "run"')<execute_text.index('runCPR inputs')
assert 'let initialState : StreamState := ⟨[], none⟩' in execute_text
assert execute_text.index('runCPR inputs')<execute_text.index('command wait "consume"')<execute_text.index('consume inputs output state geo audit')
consumer=source[source.index('@[noinline] private def consume'):source.index('private def execute')]
assert 'reprStr entry.message' in consumer and 'reprStr state' in consumer
assert 'decide (batch.1 = state)' in consumer and 'decide (batch.2 = positions.reverse)' in consumer
assert 'Impl.decodePositions geo (fun _ => false) none reports.reverse' in consumer

names=re.findall(r'LEAN_EXPORT [^\n]+ (\w+)\([^\n]*\)\{',c)
root='l_Lean1090_Diagnostics_CPRCosts_runCPR'
loop=next(n for n in names if 'Array_forIn_x27Unsafe_loop' in n and n.endswith('CPRCosts_runCPR_spec__0'))
prefix='l___private_review_diagnostics_CPRCosts_0__Lean1090_Diagnostics_CPRCosts_'
execute=prefix+'execute';advance=prefix+'advance';track=prefix+'trackingReport';consume=prefix+'consume'
bodies={n:body(c,n) for n in [root,loop,execute,advance,track,consume]}
rb=bodies[root][0];lb=bodies[loop][0];eb=bodies[execute][0];ab=bodies[advance][0]
assert 'lean_mk_empty_array_with_capacity' not in rb+lb
assert lb.count('lp_lean1090_Lean1090_Impl_decode(')==1
assert lb.count(advance+'(')==1 and lb.count('lean_array_push(')==1
assert lb.index('Impl_decode(')<lb.index(advance+'(')<lb.index('lean_array_push(')
assert 'lean_ctor_set' in lb and 'goto _start;' in lb
assert ab.count('lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep(')==1
assert ab.count(track+'(')==1
assert not any(s in rb+lb+ab for s in ['monoNanos','CPRCosts_consume(','CPRCosts_emit(','CPRCosts_loadInputs(','CPRCosts_loadAirports('])
allocation=re.search(r'(v_\w+) = lean_mk_empty_array_with_capacity\(',eb)[1]
assert eb.index('lean_mk_empty_array_with_capacity(')<eb.index(root+'(')
call=re.search(re.escape(root)+r'\(([^;]+)\);',eb)[1].split(', ')
assert len(call)==4 and call[2]==allocation
assert eb.index(root+'(')<eb.index(consume+'(')
rootret=re.search(r'(v_\w+) = '+re.escape(root)+r'\(',eb)[1]
assert re.search(r'lean_ctor_get\('+rootret+r', 0\)',eb)
assert 'lean_ctor_get' in rb and loop+'(' in rb

commands=[];excerpts={};assemblies={}
for name,(value,line) in bodies.items():
    p=D/(name+'.generated-C.txt');assert not p.exists();p.write_text(value+'\n')
    excerpts[name]={'source':str(cpath),'source_sha256':sha(cpath),'first_body_line':line,'path':str(p),'sha256':sha(p)}
    target=D/(name+'.assembly.txt');assert not target.exists()
    argv=['objdump','-d','--no-show-raw-insn','--disassemble='+name,binary]
    r=subprocess.run(argv,capture_output=True);assert r.returncode==0 and not r.stderr
    target.write_bytes(r.stdout);assemblies[name]=r.stdout.decode()
    commands.append({'argv':argv,'output':str(target),'sha256':sha(target),'exit_code':0})
assert '<'+root+'>:' in assemblies[root]
assert '<lp_lean1090_Lean1090_Impl_decode>' in assemblies[loop]
assert '<lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep>' in assemblies[advance]
assert '<lean_array_push>' in assemblies[loop]
assert '<'+consume+'>' in assemblies[execute]
assert '<'+root+'>' in assemblies[execute]
# Production callbacks are reused objects, not copies imported from Spec.
policy=Path('.lake/build/ir/Impl/CPRPolicy.c');floatc=Path('.lake/build/ir/Impl/CPRFloat.c')
assert sha(policy)==held[str(policy)] and sha(floatc)==held[str(floatc)]
for name,digest in held.items():assert sha(name)==digest,name
assert sha(worker)==bench['binary_sha256']
table_review_path=Path('tests/evidence/diagnostics/gen18/independent-review/source-review.json')
table_review=read(table_review_path)
assert table_review['dyadic_to_float_live_path_verified'] and table_review['dyadic_to_float_at_most_one_fallback_per_entry']
assert table_review['power_two_table_live_path_verified'] and table_review['binary_sha256']==sha(worker)
for row in table_review['commands']:assert row['exit_code']==0 and sha(row['output'])==row['sha256']
for row in table_review['generated_C_excerpts'].values():assert sha(row['source'])==row['source_sha256'] and sha(row['path'])==row['sha256']
out={'status':'passed_read_only_source_and_native_review','recorded_utc':datetime.now(timezone.utc).isoformat(),
    'commit':build['commit'],'timed_commit':bench['commit'],'worker_sha256':sha(worker),'driver_sha256':sha(binary),
    'driver_build_manifest':str(buildpath),'driver_build_manifest_sha256':sha(buildpath),
    'driver_source':str(sourcepath),'driver_source_sha256':sha(sourcepath),'frozen_worker_sha256':sha(frozenpath),
    'fresh_native_inputs_sha256':sha(nativepath),'fresh_project_sets':22,'reused_production_objects':21,
    'held_inputs_verified':len(held),'root':root,'loop_anchor':loop,'advance_anchor':advance,
    'tracking_projection_anchor':track,'actual_frozen_preparation_and_routing_text_equal':True,
    'output_capacity_and_empty_state_before_root':True,'complete_outputs_and_state_retained':True,
    'live_decode_then_immediate_streamStep':True,'post_collection_consumer_and_batch_audit':True,
    'generated_C_excerpts':excerpts,'commands':commands,'findings':[],
    'workload_continuity':'Unchanged reviewed CPRCosts source; fresh gen18 native sets and generated loop are independently rebound.',
    'limits':['This is static inspection only; the native corpus/input/airport audits and raw profile accounting remain separate checks.',
        'The driver shares all 21 production/model objects but has its own noinline root and compiler-generated loop/result wrapper. Its instructions are diagnostic, not benchmark time.',
        'The root includes diagnostic loop/result packaging overhead; capacity allocation, startup, clock/protocol traffic, audits and output consumption are outside collection.',
        'The frozen worker projects final state in its audit. The additional exact whole-state check is against the live batch fold and occurs only after collection.',
        'Any later implementation change must retain refinement for arbitrary geography/callback/input streams, beyond this corpus.'],
    'power_two_table_review':{'path':str(table_review_path),'sha256':sha(table_review_path)},
    'power_two_table_live_path_verified':True,
    'power_two_anchors':{k:v for k,v in table_review.items() if k.startswith('power_two_') and k.endswith('_anchor')},
    'power_two_limit':'Static lookup/formula/eager initialization association only; no table hit frequency inferred.',
    'dyadic_to_float_live_path_verified':table_review['dyadic_to_float_live_path_verified'],
    'dyadic_to_float_anchor':table_review['dyadic_to_float_anchor'],
    'dyadic_to_float_fallback_anchor':table_review['dyadic_to_float_fallback_anchor'],
    'dyadic_to_float_at_most_one_fallback_per_entry':table_review['dyadic_to_float_at_most_one_fallback_per_entry'],
    'dyadic_to_float_zero_case_verified':table_review['dyadic_to_float_zero_case_verified'],
    'dyadic_to_float_limit':'Wrapper-minus-fallback includes zero and accepted dyadics. No pure fast-path rate inferred; full descendants remain in collected caller contexts.',
    'review_script_sha256':sha(__file__)}
save(E/'independent-review/source-review.json',out)
print(json.dumps({'status':'passed','source_review_sha256':sha(E/'independent-review/source-review.json'),
    'held_inputs_verified':len(held),'native_sets':22,'targeted_assembly_commands':len(commands)}))
