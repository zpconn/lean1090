#!/usr/bin/env python3
"""Review retained generated C/linked dyadic paths without running the worker."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
from collections import deque
import hashlib,json,re
R=Path.cwd();E=R/'tests/evidence/optimization/gen18/independent-review';B=E.parent;N=E/'native-inspection'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
checks=[]
def check(ok,label):
 assert ok,label
 checks.append(label)
n=read(E/'native-inputs.json');b=read(B/'integration/targeted-build.json');sp=read(E/'source-proof-review.json')
check(b['status']=='passed' and b['exit_code']==0,'combined integration passed')
check(n['integration_record_sha256']==sha(B/'integration/targeted-build.json'),'capture binds combined build')
check(b['inputs_before']==b['inputs_after'] and b['all_inputs_before']==b['all_inputs_after'],'combined source inventories unchanged')
check(len(b['all_inputs_after'])==190,'190 complete gate inputs')
check(sha(B/'integration/targeted-build.log')==b['log_sha256'],'integration log binding')
check(sp['status']=='passed' and not sp['findings'],'independent runtime and packing proof assessment passed')
for p,h in sp['bindings'].items():check(sha(R/p)==h,'source proof binding '+p)
for p,h in n['held_inputs'].items():assert sha(R/p)==h,p
for row in n['commands']:check(row['exit_code']==0 and not row['stderr'] and sha(row['output'])==row['sha256'],'captured command '+row['output'])
for row in n['generated_c_excerpts'].values():check(sha(row['path'])==row['sha256'] and sha(row['source'])==row['source_sha256'],'C binding '+row['function'])
old={r['source']:r for r in read(R/'bench/runs/gen17/fresh-native-inputs.json')}; changes={}
check({r['source'] for r in n['linked_inventory']}==set(old),'same complete linked source inventory')
for row in n['linked_inventory']:
 before=old[row['source']];delta=[key for key in ['c','object','trace'] if row[key+'_sha256']!=before['artifacts'][row[key]]['sha256']]
 if delta:changes[row['source']]=delta
 else:check(row['source_sha256']==before['source_sha256'],'unchanged sibling '+row['source'])
check(changes=={'Impl/CPRFloat.lean':['c','object','trace']},'only CPRFloat native set changed')
facts={}
for name,ax,empty in re.findall(r"'([^']+)' (?:depends on axioms: \[([^\]]*)\]|(does not depend on any axioms))",(B/'integration/targeted-build.log').read_text()):
 vals=[] if empty else [v.strip() for v in ax.split(',') if v.strip()];check(set(vals)<={'propext','Classical.choice','Quot.sound'},'integrated allowed axioms '+name);facts[name]=vals
P='lp_lean1090_Lean1090_Impl_';T=P+'CPR_Policy_toFloat';F=T+'Fallback'
ct=lambda symbol:(N/(symbol+'.c.txt')).read_text()
asm=lambda symbol:(N/(symbol+'.txt')).read_text()
c=ct(T);a=asm(T)
check(c.count(F+'(')==3,'all three rejected guards delegate unchanged fallback')
check('"9007199254740992"' in c and '1074u' in c and 'lean_nat_dec_eq' in c,'explicit numerator/exponent/dyadic denominator guards remain')
check(c.count('lean_nat_log2(')==2 and c.count('lean_nat_shiftl(')==3,'two logs and guard/subnormal/normal shift sites remain')
check('lean_float_of_bits' in c and 'lean_uint64_of_nat' in c,'exact Nat bit packing crosses UInt64 then ofBits')
check('l_Rat_' not in c and P+'Binary64_' not in c,'fast wrapper contains no direct rational arithmetic or binary64 call')
check(n['missing_requested_symbols']==[P+'CPR_Policy_smallDyadicBits'],'packing wrapper inlined; no absent-work inference')
check('lean_float_of_bits' in ct(P+'CPR_Policy_smallDyadicBits') or 'lean_nat_shiftl' in ct(P+'CPR_Policy_smallDyadicBits'),'generated helper retained as proof of inline source shape')
for symbol in [P+'Binary64_round',P+'Binary64_exponent',P+'Binary64_powerTwo']:
 check(symbol+'(' in ct(F) and '<'+symbol+'>' in asm(F),'fallback preserves '+symbol)
check('l_Rat_div' in ct(F) and '<l_Rat_div>' in asm(F),'fallback preserves exact rational divisions')
for name in ['haversineFloat','decodeLocalFloat','decodeGlobalFloat']:
 symbol=P+'CPR_Policy_'+name
 check(T+'(' in ct(symbol) and '<'+T+'>' in asm(symbol),'actual geography caller '+name)
# Explore the actual linked wrapper CFG, preserving both sides of every branch.
ins={}
for line in a.splitlines():
 m=re.match(r'^\s*([0-9a-f]+):\s+(\S+)(?:\s+(.*))?$',line)
 if m:ins[int(m[1],16)]=(m[2],m[3] or '')
addresses=sorted(ins);nextpc=dict(zip(addresses,addresses[1:]));start=addresses[0]
queue=deque([(start,0,0,0)]);seen=set();terminals=[];calls=set()
while queue:
 state=queue.popleft()
 if state in seen:continue
 seen.add(state);pc,logs,shifts,parsers=state;op,arg=ins[pc]
 symbolmatch=re.search(r'<([^>]+)>',arg);symbol=symbolmatch[1] if symbolmatch else None
 if op.startswith('call'):
  calls.add(symbol)
  logs+=symbol=='lean_nat_log2';shifts+=symbol=='lean_nat_shiftl';parsers+=symbol=='lean_cstr_to_nat'
 check(logs<=2 and shifts<=2 and parsers<=2,'bounded acyclic wrapper counts at '+hex(pc))
 if op.startswith('ret'):
  terminals.append({'address':hex(pc),'kind':'zero_return','logs':logs,'shifts':shifts,'decimal_parsers':parsers});continue
 if op.startswith('j'):
  target=re.match(r'^([0-9a-f]+)\s+<',arg);check(target is not None,'resolved jump '+hex(pc));dest=int(target[1],16)
  if dest in ins:queue.append((dest,logs,shifts,parsers))
  else:
   check(op=='jmp' and symbol in [F,'lean_float_of_bits'],'only known wrapper tail targets')
   if symbol=='lean_float_of_bits':check(logs==2 and shifts==2 and parsers in [1,2],'all bit returns have guard and packing shifts')
   terminals.append({'address':hex(pc),'kind':symbol,'logs':logs,'shifts':shifts,'decimal_parsers':parsers})
  if op=='jmp':continue
 if pc in nextpc:queue.append((nextpc[pc],logs,shifts,parsers))
check({r['kind'] for r in terminals}=={'zero_return',F,'lean_float_of_bits'},'zero, fallback and direct-bit exits all present')
check(not any(s and ('l_Rat_' in s or 'Impl_Binary64_' in s) for s in calls),'no wrapper direct Rat/software calls')
branch={'status':'passed','assembly_sha256':sha(N/(T+'.txt')),'instructions':len(ins),'reachable_instruction_count':len({s[0] for s in seen}),'abstract_states':len(seen),'terminal_states':terminals,'direct_call_symbols':sorted(s for s in calls if s),'limits':['CFG overapproximates branch outcomes; counts describe structural paths, not measured input frequencies.','Scalar once-cell initialization and GMP-backed Nat/Int work remain; conversion is not allocation-free.']}
p=E/'dyadic-native-branches.json';check(not p.exists(),'branch evidence does not overwrite');p.write_text(json.dumps(branch,indent=2)+'\n')
for p,h in n['held_inputs'].items():assert sha(R/p)==h,p
bindings={str(p.relative_to(R)):sha(p) for p in [E/'native-inputs.json',E/'source-proof-review.json',E/'preparation-source-review.json',E/'dyadic-native-branches.json',E/'capture_native.py',E/'native-capture-01.log',Path(__file__),B/'integration/targeted-build.json',B/'integration/targeted-build.log',R/'bench/runs/gen17/fresh-native-inputs.json']}
files={str(p.relative_to(R)):{'sha256':sha(p),'bytes':p.stat().st_size} for p in sorted(N.glob('*')) if p.is_file()}
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks,'bindings':bindings,'files':files,'held_input_count':len(n['held_inputs']),'all_captured_inputs_unchanged':True,'linked_native_sets':len(n['linked_inventory']),'unchanged_native_sets_vs_gen17':len(old)-len(changes),'changed_native_sets':changes,'printed_integrated_axiom_facts':facts,'dyadic_to_float_live_path_verified':True,'dyadic_to_float_anchor':T,'fallback_anchor':F,'native_cfg_sha256':sha(E/'dyadic-native-branches.json'),'notes':['Packing helper is inlined into live toFloat. Guard rejection preserves original rounding and exponent calls; zero returns positive zero.','Actual wrapper retains decimal parsing for 2^53 and (normal path) 2^52, scalar once cells and generic Nat/Int machinery. No allocation-free or throughput claim.','All other linked production sets match prior measured generation by exact source/C/object/trace content.','Source-review attempt1/2 failures were reviewer-only lowercase fact filtering; corrected checker and all failed sources/logs are retained.','Central dyadic proof is independently reviewed by root; this reviewer authored it and claims independent assessment only of runtime/packing/tracking and native paths.'],'limits':['Static source/C/native evidence, no native execution or build by review. Full gates, boundary probe and timing are separate.']}
p=E/'native-review.json';check(not p.exists(),'no review overwrite');p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(p),'checks':len(checks),'held':len(n['held_inputs']),'facts':len(facts),'cfg_instructions':len(ins)}))
