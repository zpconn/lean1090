"""Current compiled round identity/fallback and frozen production caller review."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
R=Path('tests/evidence/optimization/gen26/native-review');O=R/'native-inspection';P='lp_lean1090_Lean1090_Impl_'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
c=load(R/'native-inputs.json');b=load(R.parent/'integration/targeted-build.json');checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 v=sha(p);check(h is None or v==h,'hash '+str(p));bindings[str(p)]=v
def targets(t):return re.findall(r'(?:call|jmp)\s+[^<]*<([^>+]+)>',t)
def body(symbol):
 row=c['generated_c_excerpts'][symbol];bind(row['path'],row['sha256']);bind(row['source'],row['source_sha256'])
 return '\n'.join(re.sub(r'^\d+: ','',s) for s in Path(row['path']).read_text().splitlines())
def assembly(symbol):
 p=O/(symbol+'.txt');bind(p);s=p.read_text();check('<'+symbol+'>:' in s,'actual linked symbol '+symbol);return s
bind(R/'native-inputs.json');bind(R.parent/'integration/targeted-build.json',c['integration_record_sha256']);bind(R.parent/'integration/targeted-build.log',b['log_sha256'])
check(b['status']=='passed' and b['exit_code']==0 and b['all_inputs_before']==b['all_inputs_after'] and len(b['all_inputs_after'])==202,'combined 202-input binding')
check(set(b['inputs_after'])=={'Impl/Binary64.lean','Proofs/Binary64Runtime.lean','Proofs/BDS50.lean'} and 'Proofs.BDS50' in b['command'],'current three-file scope and explicit BDS50 build')
for p,h in c['held_inputs'].items():bind(p,h)
check(c['all_inputs_unchanged'] and c['worker_sha256']==b['binary_hashes']['lean1090-bench'],'actual worker matches final combined build')
for row in c['commands']:check(row['exit_code']==0 and not row['stderr'],'bounded command passed');bind(row['output'],row['sha256'])
oldpath=Path('tests/evidence/optimization/gen25/native-review/native-inputs.json');bind(oldpath);old={x['source']:x for x in load(oldpath)['linked_inventory']};delta={}
for row in c['linked_inventory']:
 delta[row['source']]=[k for k in ['source_sha256','c_sha256','object_sha256','trace_sha256'] if row[k]!=old[row['source']][k]]
 check(' -O3 ' in row['compile_command'] and '-ffp-contract=off' in row['compile_command'] and not re.search(r'-(?:march|mcpu|mtune)=',row['compile_command']),'standard native flags '+row['source'])
check(len(delta)==22 and {p for p,d in delta.items() if d}=={'Impl/Binary64.lean'},'only Binary64 native set changes; 21 sibling sets identical')
round_symbol=P+'Binary64_round';fallback=P+'Binary64_roundFallback';text=body(round_symbol);asm=assembly(round_symbol)
check(text.count(fallback+'(')==3,'three source-generated rejection sites call original fallback')
check(text.index('lean_nat_abs(')<text.index('lean_nat_dec_lt(')<text.index('lean_nat_log2(')<text.index('lean_nat_dec_le(')<text.index('lean_nat_shiftl(')<text.index('lean_nat_dec_eq('),'numerator-first guard and short-circuit denominator work')
check('lean_cstr_to_nat("9007199254740992")' in text and 'lean_unsigned_to_nat(1074u)' in text and 'lean_unsigned_to_nat(1u)' in text,'exact 2^53, 1074 and shift-one constants')
arg=re.search(r'Binary64_round\(lean_object\* (v_\w+_)\)',text)[1]
check(re.search(r'else\n\{\nreturn '+arg+r';\n\}',text) is not None and all(call+'('+arg+')' in text for call in [fallback]),'identity returns original Rat; rejected guards pass the same Rat to fallback')
check(not re.search(r'lean_ctor_set|lean_float_|l_Rat_',text),'identity guard neither mutates Rat fields nor moves rational/Float evaluation')
ins={int(m[1],16):(m[2],m[3]) for m in re.finditer(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*?)\s*$',asm,re.M)};base=min(ins);at=lambda off:ins[base+off]
check(at(8)==('mov','%rdi,%rbx') and at(0xd5)==('mov','%rbx,%rax') and at(0xe0)[0]=='ret','linked identity returns saved original pointer')
check(all(ins[a][0] in ['mov','pop','ret'] for a in ins if base+0xd5<=a<=base+0xe0),'accepted return arm contains only pointer transfer and epilogue')
check(at(0x134)==('mov','%rbx,%rdi') and fallback in at(0x13f)[1] and at(0x13f)[0]=='jmp','all rejects merge at live fallback tail call with original pointer')
for off,op,target in [(0x72,'jae',0x134),(0x8e,'ja',0x134),(0xd3,'je',0x134),(0x12e,'jne',0x78),(0x210,'jmp',0x134),(0x1df,'jmp',0x134),(0x250,'jmp',0x134)]:
 check(at(off)[0]==op and int(at(off)[1].split()[0],16)==base+target,'actual scalar/generic guard branch '+hex(off))
check('lean_nat_log2' in at(0x7b)[1] and 'lean_nat_shiftl' in at(0x9c)[1] and at(0x88)==('cmp','$0x865,%rax'),'compiled denominator checks follow numerator test, exact tagged 1074 bound')
callset=set(targets(asm));check({'lean_nat_big_lt','lean_nat_big_le','lean_nat_big_eq','lean_nat_log2','lean_nat_shiftl','lean_int_big_lt','lean_int_big_neg'}<=callset,'generic large integer/Nat and negative-input operations remain')
check([x for x in callset if x.startswith(P)]==[fallback],'round wrapper sole production callee is live fallback')
fb=body(fallback);fa=assembly(fallback)
for name in ['Binary64_exponent','Binary64_powerTwo','Binary64_nearestEven']:
 check(P+name+'(' in fb and P+name in targets(fa),'original software fallback retains '+name)
for name in ['l_Rat_abs','l_Rat_div','l_Rat_mul','l_Rat_blt','l_Rat_neg','l_instDecidableEqRat_decEq']:check(name+'(' in fb,'original fallback retains '+name)
check(not re.search(r'lean_float_|Float',fb),'fallback remains pure rational software')
for name,rat in [('add','l_Rat_add'),('sub','l_Rat_sub'),('mul','l_Rat_mul'),('div','l_Rat_div')]:
 s=P+'Binary64_'+name;bt=body(s);a=assembly(s)
 check(rat+'(' in bt and round_symbol+'(' in bt and round_symbol in targets(a),'live exact arithmetic feeds round: '+name)
# Frozen benchmark loops and the actual immediate policy chain are fresh captures.
callers=load(R/'caller-bindings.json');bind(R/'caller-bindings.json')
check(callers['parent_capture_sha256']==sha(R/'native-inputs.json') and callers['worker_sha256']==c['worker_sha256'] and callers['all_inputs_unchanged'],'extra callers bind same current worker')
extra={}
for row in callers['caller_rows']:
 for k,h in [('c_source','c_source_sha256'),('c_excerpt','c_excerpt_sha256'),('assembly','assembly_sha256')]:bind(row[k],row[h])
 extra[row['symbol']]=Path(row['c_excerpt']).read_text()
loops=[s for s in c['requested_symbols'] if 'runDecodeOnce_spec__0' in s or 'runCPROnce_spec__0' in s];check(len(loops)==2,'both frozen benchmark loop symbols')
for s in loops:check(body(s).count(P+'decode(')==1 and targets(assembly(s)).count(P+'decode')==1,'each benchmark loop calls live decoder once per element')
cpr=next(s for s in loops if 'runCPROnce' in s);advance='lp_lean1090___private_Bench_WholeDecoder_0__Lean1090_Bench_WholeDecoder_advance'
chain=[cpr,advance,P+'CPR_Policy_streamStep',P+'CPR_Policy_step',P+'CPR_Policy_stepAirborne',P+'CPR_Policy_validMotion',P+'Binary64_div',round_symbol,fallback]
for a,z in zip(chain,chain[1:]):
 bt=extra[a] if a in extra else body(a)
 check(z+'(' in bt and z in targets(assembly(a)),'positive current C and linked edge '+a+' -> '+z)
for a,z in [(P+'CPR_Policy_stepAirborne',P+'Binary64_sub'),(P+'CPR_Policy_validMotion',P+'Binary64_sub'),(P+'cbPenalty',P+'Binary64_sub'),(P+'CPR_Policy_toFloatFallback',round_symbol)]:
 check(z+'(' in body(a) and z in targets(assembly(a)),'unchanged production consumer reaches guarded round '+a)
proof=R.parent/'independent-review/source-proof-current-review.json';bind(proof);pr=load(proof)
check(pr['status']=='passed' and not pr['findings'] and pr['all_input_refinement_verified'] and pr['current_correctness_inputs']==b['all_inputs_after'],'current proof review includes all three source changes')
check(pr['preserved_binary64_theorem_count']==32 and pr['preserved_bds50_theorem_count']==26,'all 58 existing statements unchanged')
v=R.parent/'integration/validation.json';bind(v);vr=load(v)
check(vr['status']=='passed' and vr['build_record_sha256']==sha(R.parent/'integration/targeted-build.json') and vr['printed_fact_count']==365 and vr['audited_source_count']==127 and vr['all_correctness_inputs_unchanged']==202,'final 365-fact kernel and 127-source integration validator binding')
prior_build=load(R.parent/'integration/round-only-pass/targeted-build.json');check(prior_build['binary_hashes']==b['binary_hashes'],'proof-only repair leaves all four linked binaries identical')
for p,h in c['held_inputs'].items():check(sha(p)==h,'held input remains exact '+p)
context={'source_native_differences':delta,'live_cpr_chain':chain,'round_symbol':round_symbol,'fallback_symbol':fallback,'generated_rejection_sites':3,'linked_common_fallback_offset':'0x134','linked_identity_return_offset':'0xd5','generic_scalar_and_big_nat_paths_verified':True,'missing_requested_symbols':c['missing_requested_symbols'],'limits':['Static branch evidence gives no guard-hit frequency or predicted elapsed-time benefit.','Guard operations include the actual constant conversion, log2, shift, generic arithmetic and reference management. No allocation-free claim.','Existing tested-only toFloat fallback still consumes the same proved round interface; no Float callback or trusted boundary moved.']}
cp=R/'round-native-context.json'
with cp.open('x') as f:f.write(json.dumps(context,indent=2)+'\n')
bind(cp);bind(__file__)
files={str(p):{'sha256':sha(p),'bytes':p.stat().st_size} for p in sorted(R.rglob('*')) if p.is_file() and 'review-attempt-' not in str(p) and p.name!='review.json'}
result={'status':'passed','findings':[],'reviewed_utc':datetime.now(timezone.utc).isoformat(),'checks_passed':len(checks),'checks':checks,'bindings':bindings,'files':files,'held_inputs':c['held_inputs'],'held_input_count':len(c['held_inputs']),'linked_native_sets':22,'all_inputs_unchanged':True,'binary64_round_identity_live_path_verified':True,'worker':c['worker'],'worker_sha256':c['worker_sha256'],'integration_record_sha256':c['integration_record_sha256'],'unchanged_sibling_native_sets':21,'source_delta':['Impl/Binary64.lean'],'native_context_sha256':sha(cp),'limitations':context['limits']+['Only bounded static inspection executed; no compiler, workload, profiler or benchmark was run by this reviewer.']}
p=R/'review.json'
with p.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','checks':len(checks),'held':len(c['held_inputs']),'sha256':sha(p)}))
