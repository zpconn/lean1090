"""Review the actual linked equal-denominator arm; no workload or build."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen25/native-review');O=R/'native-inspection'
P='lp_lean1090_Lean1090_Impl_';F='lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0';I='lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
c=load(R/'native-inputs.json');b=load(R.parent/'integration/targeted-build.json');checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 actual=sha(p);assert h is None or actual==h,str(p);bindings[str(p)]=actual
def targets(text):return re.findall(r'(?:call|jmp)\s+[^<]*<([^>+]+)>',text)
def body(symbol):
 row=c['generated_c_excerpts'][symbol];bind(row['path'],row['sha256']);bind(row['source'],row['source_sha256'])
 return '\n'.join(re.sub(r'^\d+: ','',s) for s in Path(row['path']).read_text().splitlines())
def assembly(symbol):
 p=O/(symbol+'.txt');bind(p);text=p.read_text();check('<'+symbol+'>:' in text,'Actual linked symbol '+symbol);return text
bind(R/'native-inputs.json');bind(R.parent/'integration/targeted-build.json',c['integration_record_sha256']);bind(R.parent/'integration/targeted-build.log',b['log_sha256'])
check(b['status']=='passed' and b['exit_code']==0 and b['all_inputs_before']==b['all_inputs_after'] and len(b['all_inputs_after'])==202,'Combined build exact 202-input binding')
check(set(b['inputs_after'])=={'Impl/ScoreGate.lean','Proofs/ScoreGateInteger.lean'},'Only authorized two sources changed')
for p,h in c['held_inputs'].items():bind(p,h)
check(c['all_inputs_unchanged'] and c['worker_sha256']==b['binary_hashes']['lean1090-bench'],'Captured actual worker matches combined build')
for row in c['commands']:
 check(row['exit_code']==0 and not row['stderr'],'Successful bounded static capture '+row['output']);bind(row['output'],row['sha256'])
oldpath=Path('tests/evidence/optimization/gen24/native-review/native-inputs.json');bind(oldpath)
old={r['source']:r for r in load(oldpath)['linked_inventory']};delta={}
for row in c['linked_inventory']:
 delta[row['source']]=[k for k in ['source_sha256','c_sha256','object_sha256','trace_sha256'] if row[k]!=old[row['source']][k]]
 check(' -O3 ' in row['compile_command'] and '-ffp-contract=off' in row['compile_command'] and not re.search(r'-(?:march|mcpu|mtune)=',row['compile_command']),'Retained standard native flags '+row['source'])
check(len(delta)==22 and {p for p,d in delta.items() if d}=={'Impl/ScoreGate.lean'},'Exactly ScoreGate native set changed; 21 siblings byte-identical')
# Capture only the four missing intermediate callers; the original capture is
# immutable. All four sources/objects are in the unchanged sibling inventory.
extra={}
for symbol,source in [(P+'reportWithSyndrome','Impl/Message'),(P+'commBEligible','Impl/CommB'),('lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0','Impl/CommB'),(P+'cbScorePasses___lam__0___boxed','Impl/CommB')]:
 path=Path('.lake/build/ir')/(source+'.c');lines=path.read_text().splitlines();start=next(i for i,l in enumerate(lines) if re.search(r'\b'+symbol+r'\(',l) and l.endswith('{'));depth=0
 for end in range(start,len(lines)):
  depth+=lines[end].count('{')-lines[end].count('}')
  if depth==0:break
 text='\n'.join(lines[start:end+1]);cp=O/(symbol+'.c.txt');ap=O/(symbol+'.txt')
 command=['objdump','-d','--no-show-raw-insn','--disassemble='+symbol,c['worker']]
 run=subprocess.run(command,text=True,capture_output=True);check(run.returncode==0 and not run.stderr and '<'+symbol+'>:' in run.stdout,'Extra actual caller '+symbol)
 for dest,data in [(cp,text+'\n'),(ap,run.stdout)]:
  if dest.exists():assert dest.read_text()==data
  else:dest.write_text(data)
 bind(cp);bind(ap);bind(path);extra[symbol]=dict(source=str(path),source_sha256=sha(path),c_excerpt=str(cp),c_excerpt_sha256=sha(cp),assembly=str(ap),assembly_sha256=sha(ap),command=command,exit_code=0)
def fullbody(symbol):return Path(extra[symbol]['c_excerpt']).read_text() if symbol in extra else body(symbol)
callers=load(R/'caller-bindings.json');bind(R/'caller-bindings.json')
check(callers['parent_capture_sha256']==sha(R/'native-inputs.json') and callers['worker_sha256']==c['worker_sha256'] and callers['all_inputs_unchanged'],'Both frozen benchmark modes use this same worker')
for row in callers['benchmark_callers']:
 for p,h in [(row['c_source'],row['c_sha256']),(row['c_excerpt'],row['c_excerpt_sha256']),(row['assembly'],row['assembly_sha256'])]:bind(p,h)
 check(Path(row['c_excerpt']).read_text().count(P+'decode(')==1 and targets(Path(row['assembly']).read_text()).count(P+'decode')==1,'Live decoder call in '+row['mode'])
chain=[P+'decode',P+'reportWithSyndrome',P+'frameCommB',P+'inferCommB','lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0',P+'commBEligible',P+'commBCoreEligible',P+'cbScorePasses',P+'ScoreGate_choose',F,I]
cchain=chain[:-2]+[P+'ScoreGate_scaledTotals',F,I]
for caller,callee in zip(cchain,cchain[1:]):
 check(callee+'(' in fullbody(caller),'Live generated-C call '+caller+' -> '+callee)
native_edges={symbol:set(targets(assembly(symbol))) for symbol in chain}
reached=set();pending=[chain[0]]
while pending:
 symbol=pending.pop()
 if symbol in reached:continue
 reached.add(symbol);pending.extend(native_edges.get(symbol,set()) & set(chain))
check(set([P+'ScoreGate_choose',F,I]) <= reached,'Actual linked call graph reaches choose and both folds, allowing positive direct edges through inlined C callers')
# The helper and wrapper inline, but positive C and linked CFG evidence retains
# the identity arm in the penalty calculation and both term-list loops.
check(P+'ScoreGate_scaledNumerator' in c['missing_requested_symbols'] and P+'ScoreGate_scaledTotals' in c['missing_requested_symbols'],'Absent helper/wrapper boundaries explicitly identified as inline after caller inspection')
for symbol in [P+'ScoreGate_scaledNumerator',P+'ScoreGate_choose',F,I]:
 text=body(symbol)
 m=re.search(r'(v_\w+_) = lean_nat_dec_eq\((v_\w+_), (v_\w+_)\);\nif \(\1 == 0\)\n\{(.*?)\n\}\nelse\n\{(.*?)\n\}',text,re.S)
 check(m is not None,'Exact generic Nat equality branch in C '+symbol)
 unequal,equal=m[4],m[5]
 check(f'lean_nat_div({m[2]}, {m[3]})' in unequal and 'lean_nat_to_int(' in unequal and 'lean_int_mul(' in unequal,'Unequal branch retains total divide/cast/multiply '+symbol)
 check(not any(x in equal for x in ['lean_nat_div','lean_nat_to_int','lean_int_mul']) and re.search(r'(?:return|=) v_num_\d+_;',equal),'Equal C branch reuses existing numerator '+symbol)
 check(not re.search(r'Float|toFloat|Numeric_eval',text),'No Float/evaluator move in '+symbol)
# Check every local control-flow alternative from the known equal branch to
# its merge. Reference-count cold paths are retained; none does scaling work.
arms=[]
for symbol,eqoffset,mergeoffset,numerator in [(P+'ScoreGate_choose',0x189,0x1a0,'%rbp,%r12'),(F,0x229,0x243,'%r15,%r12'),(I,0x260,0x27a,'%r14,%r12')]:
 text=assembly(symbol);instructions={int(m[1],16):(m[2],m[3]) for m in re.finditer(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*?)\s*$',text,re.M)}
 addresses=sorted(instructions);base=addresses[0];following={a:b for a,b in zip(addresses,addresses[1:])};start=base+eqoffset;merge=base+mergeoffset
 check(start in instructions and merge in instructions,'Identified equal/merge offsets '+symbol)
 seen=set();pending=[start];reaches=False
 while pending:
  addr=pending.pop()
  if addr==merge:reaches=True;continue
  if addr in seen:continue
  seen.add(addr);op,args=instructions[addr]
  check(not re.search(r'^(?:i?div|i?mul)',op) and not any(x in args for x in ['lean_nat_big_div','lean_int_big_mul','lean_big_size_t_to_int']),'Identity CFG avoids scaling arithmetic '+symbol+'+'+hex(addr-base))
  check(op not in ['ret','ud2'],'Identity CFG returns to common continuation '+symbol)
  if op.startswith('j'):
   target=int(re.match(r'([0-9a-f]+)',args)[1],16);check(target in instructions,'Local identity branch target '+symbol);pending.append(target)
   if op=='jmp':continue
  pending.append(following[addr])
 check(reaches and any(op=='mov' and args==numerator for a,(op,args) in instructions.items() if a in seen),'Linked equal arm passes original numerator into common continuation '+symbol)
 calls=targets(text)
 check(all(x in calls for x in ['lean_nat_big_eq','lean_nat_big_div','lean_int_big_mul']) and re.search(r'\bdiv\s',text),'Generic large-Nat equality and small/large unequal arithmetic remain live '+symbol)
 check(re.search(r'cmp\s+[^\n]+\n\s*[0-9a-f]+:\s+je\s+'+format(start,'x')+r'\b',text),'Small-Nat equality jumps directly to identity arm '+symbol)
 before=text[:text.index(format(start,'x')+':')]
 check('lean_nat_big_eq' in before and re.search(r'test\s+%al,%al\n\s*[0-9a-f]+:\s+je\s+',before),'Big-Nat equality result branches before the same identity arm '+symbol)
 arms.append(dict(symbol=symbol,equal_offset=eqoffset,merge_offset=mergeoffset,identity_cfg_instruction_count=len(seen),numerator_transfer=numerator,arithmetic_bypassed_only_in_equal_arm=True))
choose=body(P+'ScoreGate_choose');check(choose.count('lean_apply_1(')==1 and 'lean_apply_1' in targets(assembly(P+'ScoreGate_choose')),'Original uncertain decision retains one lazy fallback application')
fallback_calls=targets(assembly(P+'cbScorePasses___lam__0___boxed'))
check(P+'cbScorePasses___lam__0___boxed' in body(P+'cbScorePasses') and P+'cbCombinedScore(' in body(P+'cbScorePasses___lam__0') and {P+'cbDensity',P+'cbPenalty',P+'Binary64_add'} <= set(fallback_calls),'Unchanged complete software score C formula inlines into actual boxed thunk with live density, penalty and Binary64 arithmetic')
proof=R.parent/'independent-review/source-proof-review.json';bind(proof);check(load(proof)['status']=='passed' and load(proof)['all_input_refinement_verified'],'Unconditional old-formula proof and frozen source review bound')
v=R.parent/'integration/validation.json';bind(v);validation=load(v)
check(validation['status']=='passed' and validation['audited_source_count']==127 and validation['all_correctness_inputs_unchanged']==202 and validation['printed_fact_count']==354,'Combined all-input source and kernel inventory exact')
for p,h in c['held_inputs'].items():bind(p,h)
context=dict(source_native_differences=delta,extra_callers=extra,live_call_chain=chain,identity_arms=arms,missing_requested_symbols=c['missing_requested_symbols'],limitations=['Static branches do not measure equal-denominator frequency or predicted throughput.','Unequal arithmetic, other score multiplications, allocation and reference management remain; no allocation-free claim.'])
cp=R/'score-scaling-native-context.json';assert not cp.exists();cp.write_text(json.dumps(context,indent=2)+'\n');bind(cp)
files={str(p):dict(sha256=sha(p),bytes=p.stat().st_size) for p in sorted(R.rglob('*')) if p.is_file() and 'review-attempt-' not in str(p) and p.name!='review.json'}
result=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,files=files,held_inputs=c['held_inputs'],held_input_count=len(c['held_inputs']),linked_native_sets=22,all_inputs_unchanged=True,score_scaling_identity_live_path_verified=True,worker=c['worker'],worker_sha256=c['worker_sha256'],integration_record_sha256=c['integration_record_sha256'],unchanged_sibling_native_sets=21,source_delta=['Impl/ScoreGate.lean'],native_context_sha256=sha(cp),limitations=context['limitations']+['No compiler, native workload, profiler or benchmark was executed by this review. No Float boundary or frozen source changed.'])
out=R/'review.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),held=len(c['held_inputs']),sha256=sha(out))))
