"""Independent static review of the actual linked validity table paths."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
R=Path('tests/evidence/optimization/gen23/native-review');P='lp_lean1090_Lean1090_Impl_'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
c=load(R/'native-inputs.json');b=load(R.parent/'integration/targeted-build.json');checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 actual=sha(p);assert h is None or h==actual,str(p);bindings[str(p)]=actual;return actual
def body(s):
 row=c['generated_c_excerpts'][s];bind(row['path'],row['sha256']);bind(row['source'],row['source_sha256'])
 return '\n'.join(re.sub(r'^\d+: ','',l) for l in Path(row['path']).read_text().splitlines())
def asm(s):
 p=R/'native-inspection'/(s+'.txt');bind(p);t=p.read_text();check('<'+s+'>:' in t,'nonempty actual assembly '+s);return t
def targets(t):return re.findall(r'(?:call|jmp)\s+[^<]*<([^>+]+)>',t)
bind(R/'native-inputs.json','bd41649c30d4af16eb95015faa99ff186288e11f1e0becba8847dbd2ef785d26');bind(R.parent/'integration/targeted-build.json',c['integration_record_sha256']);bind(R.parent/'integration/targeted-build.log',b['log_sha256'])
check(b['status']=='passed' and b['exit_code']==0 and b['all_inputs_before']==b['all_inputs_after'] and len(b['all_inputs_after'])==200,'Passed combined build binds 200 unchanged correctness inputs')
for p,h in c['held_inputs'].items():bind(p,h)
check(c['all_inputs_unchanged'] and c['worker_sha256']==b['binary_hashes']['lean1090-bench'],'Actual current worker matches completed combined build')
for command in c['commands']:
 check(command['exit_code']==0 and not command['stderr'],'Static capture command succeeded '+command['output']);bind(command['output'],command['sha256'])
oldpath=Path('tests/evidence/optimization/gen22/native-review/native-inputs.json');bind(oldpath);old={r['source']:r for r in load(oldpath)['linked_inventory']};differences={}
for row in c['linked_inventory']:
 differences[row['source']]=[k for k in ['source_sha256','c_sha256','object_sha256','trace_sha256'] if row[k]!=old[row['source']][k]]
 check(' -O3 ' in row['compile_command'] and '-ffp-contract=off' in row['compile_command'] and not re.search(r'-(?:march|mcpu|mtune)=',row['compile_command']),'Exact native flags '+row['source'])
check(len(differences)==22 and {p for p,d in differences.items() if d}=={'Impl/CommB.lean'},'Only CommB native set changed; 21 sibling source/C/object/trace sets are byte-identical')
helpers=['cbSelectedValid40','cbQNHValid40','cbRollValid50','cbMachValid60','cbVerticalValid60'];tables=[n+'Table' for n in helpers]
for n in helpers:
 s=body(P+n);check(s.count(P+'payloadBits(')==1 and s.count('lean_array_fget_borrowed(')==1 and 'lean_unbox(' in s and P+n+'Table' in s,'Checked C field lookup returns original table Boolean '+n)
 check(not any(x in s for x in ['l_Rat_','Binary64_','lean_alloc_ctor','lean_obj_once']),'No rational calculation/table initialization in C lookup '+n)
 check(P+n in c['missing_requested_symbols'],'Lookup helper is inlined in actual worker '+n)
validity={};layout={40:['cbSelectedValid40Table','cbQNHValid40Table'],50:['cbRollValid50Table'],60:['cbMachValid60Table','cbVerticalValid60Table']}
for r in [40,50,60]:
 symbol=P+f'cbValid{r}';s=body(symbol);a=asm(symbol);calls=targets(a)
 for t in layout[r]:check('<'+P+t+'>' in a,f'Actual BDS{r} loads persistent {t}')
 expected={40:3,50:1,60:2}[r]
 check(len(re.findall(r'mov\s+0x18\([^\n]*,4\)',a))==expected,f'Actual BDS{r} has {expected} indexed Boolean load sites')
 check(not any('Rat_' in x or 'Binary64_' in x for x in calls),f'Actual BDS{r} direct calls contain no Rat/software Binary64 operation')
 check(calls.count(P+'cbStatus')=={40:3,50:5,60:5}[r],f'Actual BDS{r} retains all status guard sites')
 check(P+'payloadBits' in calls and 'lean_nat_big_' in a,f'Actual BDS{r} retains general Nat extraction/comparison paths')
 validity[str(r)]=dict(anchor=symbol,tables=[P+t for t in layout[r]],boolean_load_sites=expected,direct_calls=sorted(set(calls)))
for caller,callees in {'bdsWireValid':['cbValid40','cbValid50','cbValid60'],'decodeBDS':['bdsWireValid'],'commBCoreEligible':['bdsWireValid','cbScorePasses'],'commBEligible':['commBCoreEligible'],'commBValue':['cbSelected','cbVertical60','payloadValue'],'cbPenalty':['commBValue','cbRatioOutside250800','cbWindPenalty50']}.items():
 s=body(P+caller);calls=targets(asm(P+caller))
 for target in callees:check(P+target in calls,'Actual live caller '+caller+' reaches '+target)
check(P+'cbQNHValueTable' in body(P+'cbQNH64') and P+'cbMachValueTable' in body(P+'cbMach64'),'Original numerical QNH and Mach projections continue using unchanged exact value tables')
init=body('initialize_lean1090_Impl_CommB');ia=asm('initialize_lean1090_Impl_CommB')
for table in tables:
 symbol=P+table;constructor='_init_'+symbol
 check(symbol+' = '+constructor+'();' in init and 'lean_mark_persistent('+symbol+');' in init,'C module initialization eagerly constructs and persists '+table)
 check('<'+symbol+'>' in ia and '<'+constructor+'___closed__1>' in ia,'Actual initializer binds table global and constructor '+table)
 check(P+table+'___closed__1' in body(constructor),'Table initializer forces complete constructor '+table)
for table,count in [('cbSelectedValid40Table',4096),('cbRollValid50Table',1024),('cbVerticalValid60Table',1024)]:
 s=body('_init_'+P+table+'___closed__1');a=asm('_init_'+P+table+'___closed__1')
 check(f'lean_unsigned_to_nat({count}u)' in s and 'l_Array_ofFn___redArg(' in s,'Exact full ofFn cardinality '+table)
 check('l_Array_ofFn___redArg' in targets(a) and hex(2*count+1) in a,'Actual constructor passes tagged complete cardinality '+table)
 entry=asm(P+table+'___lam__0___boxed')
 if table=='cbSelectedValid40Table':check(P+'cbSelected' in targets(entry) and 'l_Rat_instDecidableLe' in targets(entry),'Actual selected table entry uses original projected value and comparison')
 if table=='cbRollValid50Table':
  lam=asm(P+table+'___lam__0');check(all(x in targets(lam) for x in [P+'payloadInteger','l_Rat_mul','l_Rat_div','l_Rat_abs','l_Rat_instDecidableLe']),'Actual roll table entry preserves signed cast/mul/div/abs/comparison order')
 if table=='cbVerticalValid60Table':check(P+'cbVertical60' in targets(entry) and 'l_Rat_abs' in targets(entry) and 'l_Rat_instDecidableLe' in targets(entry),'Actual vertical table entry uses original sentinel-aware value and bound')
for table,values in [('cbQNHValid40Table','cbQNHValueTable'),('cbMachValid60Table','cbMachValueTable')]:
 check(init.index('lean_mark_persistent('+P+values+');')<init.index(P+table+' ='),'Original numerical values initialized and persistent before Boolean map '+table)
 size=body('_init_'+P+table+'___closed__0');s=body('_init_'+P+table+'___closed__1')
 check(P+values in size and 'lean_array_size' in size and P+values in s and '((size_t)0ULL)' in s,'Boolean map traverses complete original value array '+table)
 mapper=next(n for n in c['generated_c_excerpts'] if n.startswith('lp_lean1090___private_') and table+'_spec__0' in n and not n.startswith('_init_'))
 m=body(mapper);ma=asm(mapper)
 check(all(x in m for x in ['lean_usize_dec_lt','lean_array_uget','lean_array_uset','lean_usize_add','goto _start;','l_Rat_instDecidableLe']),'Complete map iterates all entries and writes exact comparisons '+table)
 check('l_Rat_instDecidableLe' in targets(ma),'Actual Boolean map calls exact rational comparator '+table)
# Initialization graph and actual frozen worker loops precede all corpus decoding.
graph=c['initialization_graph'];seen=set();todo=['initialize_lean1090_Bench_WholeDecoder']
while todo:
 n=todo.pop()
 if n in seen:continue
 seen.add(n);todo.extend(graph.get(n,[]))
check('initialize_lean1090_Impl_CommB' in seen,'Frozen benchmark module initialization reaches CommB tables')
main=body('main');check(main.index('initialize_lean1090_Bench_WholeDecoder(')<main.index('lean_run_main('),'Main initializes all modules before entering the benchmark program')
callers=load(R/'caller-bindings.json');bind(R/'caller-bindings.json');check(callers['parent_capture_sha256']==sha(R/'native-inputs.json') and callers['worker_sha256']==c['worker_sha256'] and callers['all_inputs_unchanged'],'Supplement binds identical actual worker and held inputs')
for row in callers['benchmark_callers']:
 for key,hkey in [('c_source','c_sha256'),('c_excerpt','c_excerpt_sha256'),('assembly','assembly_sha256')]:bind(row[key],row[hkey])
 check(Path(row['c_excerpt']).read_text().count(P+'decode(')==1 and targets(Path(row['assembly']).read_text()).count(P+'decode')==1,'Frozen '+row['mode']+' loop executes actual complete decoder')
for row in callers['additional_table_functions']:bind(row['assembly'],row['assembly_sha256'])
proof=R.parent/'independent-review/source-proof-review.json';bind(proof,'c3f3f5c487e4ec84d0fc842e7f2da48c3f475f226d54e42c1d71197c1dc989d1');check(load(proof)['status']=='passed' and not load(proof)['findings'],'Unrestricted table/old predicate proof and unchanged frozen adapter review passed')
v=R.parent/'integration/validation.json';bind(v);check(load(v)['printed_fact_count']==325,'Combined validator binds all 325 permitted-axiom facts')
for p,h in c['held_inputs'].items():bind(p,h)
context=dict(validity=validity,table_entries=[4096,4096,1024,1024,1024],total_boolean_entries=11264,source_native_differences=differences,initialization_reachable_modules=sorted(seen),missing_requested_symbols=c['missing_requested_symbols'],helpers_inlined_into_validity=[P+n for n in helpers],startup_boundary='All five complete arrays initialized and marked persistent in CommB module initialization, before main benchmark program; not charged per message.',semantic_boundary='Original value projections and score/penalty formulas remain live; only selected field-level plausibility predicates now use Boolean entries.')
p=R/'validity-table-native-context.json';assert not p.exists();p.write_text(json.dumps(context,indent=2)+'\n');bind(p)
record=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,files={str(p):dict(sha256=sha(p),bytes=p.stat().st_size) for p in sorted(R.rglob('*')) if p.is_file() and p.name not in ['review.json','review-02.log']},held_inputs=c['held_inputs'],held_input_count=len(c['held_inputs']),linked_native_sets=22,all_inputs_unchanged=True,commb_validity_tables_live_path_verified=True,worker=c['worker'],worker_sha256=c['worker_sha256'],integration_record_sha256=c['integration_record_sha256'],unchanged_sibling_native_sets=21,source_delta=['Impl/CommB.lean'],native_context_sha256=sha(p),limitations=['Static linked-path checks establish initialization, call sites and indexed loads, not invocation frequencies, measured speedups or a table hit-rate.', 'Five lookup helpers are inlined into actual callable cbValid40/50/60; actual table loads, not absence of helper symbols, establish the path.', 'General Nat extraction, unchanged checks and ownership/reference-count operations remain. No allocation-free claim.', 'Tables contain format field-code decisions only; all 11,264 entries are initialized before decoding. Original numerical projections, score arithmetic, Float callbacks and frozen adapter source remain unchanged.'])
out=R/'review.json';assert not out.exists();out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),held=len(c['held_inputs']),review_sha256=sha(out))))
