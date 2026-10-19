#!/usr/bin/env python3
"""Review current generated C and linked natural-bit paths without running the worker."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,shlex
E=Path('tests/evidence/optimization/gen19/native-review');B=E.parent;N=E/'native-inspection-complete'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
checks=[]
def check(ok,label):
 assert ok,label
 checks.append(label)
n=read(E/'native-inputs-complete.json');first=read(E/'native-inputs.json');b=read(B/'integration/targeted-build.json')
check(n['held_inputs']==first['held_inputs'] and n['linked_inventory']==first['linked_inventory'],'both static captures bind identical live inputs')
check(b['status']=='passed' and b['exit_code']==0,'combined integration passed')
check(b['all_inputs_before']==b['all_inputs_after'] and len(b['all_inputs_after'])==192,'all 192 combined inputs unchanged')
check(b['inputs_before']==b['inputs_after'] and len(b['inputs_after'])==8,'all eight changed correctness sources unchanged')
check(n['integration_record_sha256']==sha(B/'integration/targeted-build.json'),'capture binds combined build')
check(sha(B/'integration/targeted-build.log')==b['log_sha256'],'complete build log bound')
for p,h in n['held_inputs'].items():check(sha(p)==h,'held '+p)
check(len(n['linked_inventory'])==len({r['source'] for r in n['linked_inventory']})==len({r['object'] for r in n['linked_inventory']})==22,'22 unique native source/object sets')
for cap in [first,n]:
 for r in cap['commands']:check(r['exit_code']==0 and not r['stderr'] and sha(r['output'])==r['sha256'],'successful bounded capture '+r['output'])
 for r in cap['generated_c_excerpts'].values():check(sha(r['path'])==r['sha256'] and sha(r['source'])==r['source_sha256'],'current generated C '+r['function'])
old={r['source']:r for r in read('bench/runs/gen18/fresh-native-inputs.json')}
check(set(old)=={r['source'] for r in n['linked_inventory']},'same complete native inventory as fresh generation18 worker')
changes={}
for row in n['linked_inventory']:
 before=old[row['source']];delta=[k for k in ['c','object','trace'] if row[k+'_sha256']!=before['artifacts'][row[k]]['sha256']]
 if delta:changes[row['source']]=delta
 else:check(row['source_sha256']==before['source_sha256'],'unchanged sibling source '+row['source'])
 check(' -O3 ' in row['compile_command'] and '-ffp-contract=off' in row['compile_command'] and not re.search(r'-(?:march|mcpu|mtune)=',row['compile_command']),'native flags '+row['source'])
check(changes=={p:['c','object','trace'] for p in ['Impl/Altitude.lean','Impl/Frame.lean','Impl/PayloadBits.lean']},'exactly three intended native sets changed')
log=(B/'integration/targeted-build.log').read_text()
for name in ['Altitude','Frame','PayloadBits']:check('Built Impl.'+name+':c.o' in log,'actual integration native rebuild '+name)
facts={}
for name,axes,empty in re.findall(r"'([^']+)' (?:depends on axioms: \[([^\]]*)\]|(does not depend on any axioms))",log):
 vals=[] if empty else [x.strip() for x in axes.split(',') if x.strip()]
 check(set(vals)<={'propext','Classical.choice','Quot.sound'},'allowed integrated axioms '+name);facts[name]=vals
for path in [B/'independent-review/source-proof-review.json',B/'independent-review/bit-proof-review.json',B/'runtime-review/source-initial.json']:
 r=read(path);check(r['status'].startswith('passed') and not r['findings'],'independent source/proof review '+str(path))
 for p,h in r.get('bindings',r.get('runtime_sha256',{})).items():check(sha(p)==h,'independent binding '+p)
P='lp_lean1090_Lean1090_Impl_';fold='lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0';lam=P+'identityCode___lam__0'
ct=lambda f:(N/(f+'.c.txt')).read_text();asm=lambda f:(N/(f+'.txt')).read_text()
for symbol in [P+'Altitude_bit',P+'Altitude_grayDecode',fold,P+'identityCode',lam,P+'payloadInteger']:
 c=ct(symbol);check('lean_nat_pow(' not in c and 'lean_nat_div(' not in c,'no direct power/division in C '+symbol)
 if symbol in n['present_symbols']:
  a=asm(symbol);check(not re.search(r'<lean_nat_(?:pow|div|big_div)>',a),'no direct linked power/division '+symbol)
check('lean_nat_shiftr(' in ct(P+'Altitude_bit') and 'lean_nat_land(' in ct(P+'Altitude_bit'),'bit exact shift then mask')
check('lean_nat_shiftr(' in ct(fold) and 'lean_nat_lxor(' in ct(fold) and 'goto _start;' in ct(fold),'Gray tail fold keeps shift XOR order')
check('l_List_range(' in ct(P+'Altitude_grayDecode') and fold+'(' in ct(P+'Altitude_grayDecode'),'Gray original range and fold remain')
check('lean_nat_shiftr(' in ct(lam) and 'lean_nat_land(' in ct(lam),'identity extracted lambda shifts before masking')
check(ct(P+'identityCode').count(lam+'(')==12,'all twelve identity bit positions use live lambda')
check(lam in n['missing_requested_symbols'] and asm(P+'identityCode').count('<lean_nat_big_shiftr>')==12 and asm(P+'identityCode').count('<lean_nat_big_land>')==12,'identity lambda inlined at all twelve native positions')
for symbol in [P+'Altitude_bit',fold]:
 a=asm(symbol);check('<lean_nat_big_shiftr>' in a and '$0x80' in a and re.search(r'\bshr\s+%cl,',a),'generic Nat and oversized scalar index branches '+symbol)
check(ct(P+'payloadInteger').count('lean_nat_shiftl(')==2 and 'lean_nat_sub(' in ct(P+'payloadInteger') and 'lean_nat_dec_le(' in ct(P+'payloadInteger') and 'lean_int_sub(' in ct(P+'payloadInteger'),'payload keeps width subtraction, inclusive sign threshold and exact Int subtraction')
check(asm(P+'payloadInteger').count('<lean_nat_shiftl>')==2 and '<lean_nat_big_sub>' in asm(P+'payloadInteger') and '<lean_int_big_sub>' in asm(P+'payloadInteger'),'payload uses exact generic Nat shifts and large arithmetic branches')
for caller,callee in [('payloadValue','payloadInteger'),('cbSigned','payloadInteger'),('frameIdentity','identityCode')]:
 check(P+callee+'(' in ct(P+caller) and '<'+P+callee+'>' in asm(P+caller),'live caller '+caller+' delegates '+callee)
check(P+'Altitude_bit(' in ct(P+'Altitude_gray100') and '<'+P+'Altitude_bit+' not in asm(P+'Altitude_gray100'),'gray100 uses source live bit helper')
# Runtime header explicitly guards scalar shifts >= pointer width and delegates heap inputs.
header=Path('/home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/include/lean/lean.h');h=header.read_text();start=h.index('static inline lean_obj_res lean_nat_shiftr(');end=h.index('\n}\n',start)+3
excerpt=h[start:end];check('(s2 < sizeof(size_t)*8) ? s1 >> s2 : 0' in excerpt and 'lean_nat_big_shiftr(a1, a2)' in excerpt,'installed generic shift guards large indices without wrapping')
hp=E/'lean-nat-shift-header.txt';check(not hp.exists(),'new bounded header excerpt');hp.write_text(excerpt)
# Current frozen adapters still invoke production entry points; source identity is part of the complete gate inventory.
for path,patterns in {'Bench/WholeDecoder.lean':['Impl.decode'], 'Tests/AltitudeDifferential.lean':['Impl.Altitude.oracleAC13','Impl.Altitude.oracleAC12','Impl.decode'], 'Tests/CommBDifferential.lean':['Impl.decodeBDS','Impl.Semantics.commB'], 'Tests/Upstream.lean':['Impl.Altitude.bit']}.items():
 text=Path(path).read_text();check(all(x in text for x in patterns),'frozen adapter live source '+path)
for p,h in n['held_inputs'].items():assert sha(p)==h,p
bindings={str(p):sha(p) for p in [E/'native-inputs.json',E/'native-inputs-complete.json',E/'capture_native.py',E/'capture_native-01.py',E/'capture-01.log',E/'capture-02.log',Path(__file__),hp,B/'integration/targeted-build.json',B/'integration/targeted-build.log',B/'independent-review/source-proof-review.json',B/'independent-review/bit-proof-review.json',B/'runtime-review/source-initial.json',Path('bench/runs/gen18/fresh-native-inputs.json'),header]}
files={str(p):{'sha256':sha(p),'bytes':p.stat().st_size} for folder in [E/'native-inspection',N] for p in sorted(folder.iterdir()) if p.is_file()}
result=dict(status='passed',reviewed_utc=datetime.now(timezone.utc).isoformat(),findings=[],checks_passed=len(checks),checks=checks,bindings=bindings,files=files,linked_native_sets=22,held_input_count=len(n['held_inputs']),all_inputs_unchanged=True,systematic_bit_extraction_verified=True,changed_native_sets=changes,unchanged_native_sets_vs_gen18=19,printed_integrated_axiom_facts=facts,source_delta=sorted(changes),worker=n['worker'],worker_sha256=n['worker_sha256'],notes=['All four optimized definitions reach current compiled code. identityCode bit lambda is inlined; actual native caller retains twelve shift/mask branches.','Initial static capture omitted helper bodies because its discovery regex required a space before the C opening brace. It is preserved, then a supplemental capture includes all specializations; both bind identical inputs.','Core scalar shifts guard oversized indices; non-scalar values delegate to existing generic Nat operations. No narrowing to UInt64 was introduced.','Six new payload witnesses are axiom-free. Their author is this reviewer; independent source/proof assessment is explicitly supplied by cost_analysis and root for the separate BitExtraction module.'],limits=['Static source/C/object/linked evidence only; no decoder execution, benchmark, throughput or allocation-free claim.','This is an incremental current integration build: exactly three native sets were rebuilt; nineteen match the previous fully fresh timed inventory. A new full fresh native build remains required before timing.','Gray range-list allocation, generic big Nat/Int arithmetic, reference counting and the payload coding once-cell remain.'])
p=E/'review.json';check(not p.exists(),'no review overwrite');p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(p),'checks':len(checks),'held':len(n['held_inputs']),'facts':len(facts),'native_sets':22}))
