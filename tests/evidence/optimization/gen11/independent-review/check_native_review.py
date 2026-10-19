#!/usr/bin/env python3
"""Read-only binding and control-flow replay of gen11's independent native review."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
B=Path('tests/evidence/optimization/gen11');R=B/'independent-review';N=B/'native-review';P='lp_lean1090_Lean1090_Impl_'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def body(text,name):
 m=re.search(r'\b'+re.escape(name)+r'\([^;{}]*\)\s*\{',text);assert m,name
 n=0
 for j in range(m.end()-1,len(text)):
  n+=(text[j]=='{')-(text[j]=='}')
  if n==0:return text[m.start():j+1]
 raise AssertionError(name)
def calls(text):return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>',text)
review=load(N/'review.json');inspection=load(N/'inspection-inputs.json');proof=load(N/'source-proof-review.json')
assert sha(N/'review.json')=='304cfb14237662c8f65a4f1c02bba2d6b32b981cb164f241c24333f56e0e5ac2'
assert sha(N/'inspection-inputs.json')=='3b7a895081ec0c531f76f716c66e64ff0a935af35d279f8749beea7851a04647'
assert sha(N/'source-proof-review.json')==review['source_proof_review_sha256']=='8dabd29ffffcd75af3f7ef959c244f13ea4a0fba67993e28f4134d8800a1c753'
assert review['status']==proof['status']=='passed' and review['findings']==proof['findings']==[]
assert len(review['checks'])==42 and all(review['checks'].values()) and review['all_captured_inputs_unchanged']
assert len(inspection['inputs'])==140 and len(review['files'])==189
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'] and Path(path).stat().st_size==row['bytes'],path
for path,row in review['files'].items():assert sha(N/path)==row['sha256'] and (N/path).stat().st_size==row['bytes'],path
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()}==set(review['files'])|{'review.json','validate.stdout','validate.stderr'}
printed=load(N/'validate.stdout');assert printed=={'status':'passed','checks':42,'inputs':140,'files':189,'source_proof_review_sha256':sha(N/'source-proof-review.json'),'review_sha256':sha(N/'review.json')}
assert (N/'validate.stderr').read_bytes()==b''
for original,retained in inspection['retained'].items():assert sha(N/retained)==sha(original),original
for command in inspection['commands']:
 assert command['exit_code']==0 and command['argv'][0] in ['git','nm','objdump'] and (N/command['stderr']).read_bytes()==b''
assert len(inspection['linked_project_objects'])==21
prior={r['source']:r for r in load('bench/runs/gen10/fresh-native-inputs.json')};unchanged=[]
for row in inspection['linked_project_objects']:
 if row['source'] in ['CLI/Main.lean','Impl/Parity.lean']:continue
 old=prior[row['source']];assert sha(row['source'])==old['source_sha256']
 for key in ['c','object','trace']:assert sha(row[key])==old['artifacts'][row[key]]['sha256'],row[key]
 unchanged.append(row['source'])
assert sorted(unchanged)==sorted(review['unchanged_native_sources']) and len(unchanged)==19
integration=load(R/'integration-review.json');assert integration['final_source_sha256']==proof['sources']
assert proof['integrated_allowed_axiom_facts']==len(integration['all_successful_printed_axioms'])==112
assert proof['helper_facts']==load(B/'proof/summary.json')['facts'] and len(proof['helper_facts'])==11
for row in proof['helper_facts']:assert set(row['axioms'])<={'propext','Classical.choice','Quot.sound'}
assert proof['supplementary_inputs']==review['source_proof_inputs'] and len(proof['supplementary_inputs'])==5
for path,row in proof['supplementary_inputs'].items():assert sha(path)==sha(N/'retained'/path)==row['sha256'] and Path(path).stat().st_size==row['bytes']
for path,digest in integration['final_source_sha256'].items():assert sha(path)==inspection['inputs'][path]['sha256']==digest
c=(N/'retained/.lake/build/ir/Impl/Parity.c').read_text();loop=review['loop_anchor'];loop_c=body(c,loop);syn=body(c,P+'Parity_syndrome')
assert 'uint32_t v_a_' in loop_c.split('{')[0] and 'goto _start;' in loop_c
assert not any(x in loop_c for x in ['List_', 'lean_alloc_', 'lean_box_', 'BitVec_', 'lean_uint32_to_nat', 'lean_nat_mod', 'lean_nat_pow'])
for name in ['Parity_wordStep','Parity_step']:
 assert all(x in body(c,P+name) for x in ['lean_uint32_shift_left','lean_uint32_lor','lean_uint32_xor','lean_uint32_land','8388608','33551369','16777215'])
assert all(x in loop_c for x in ['lean_uint32_shift_left','lean_uint32_lor','lean_uint32_xor','lean_uint32_land','8388608','33551369','16777215','lean_unsigned_to_nat(64u)','lean_unsigned_to_nat(128u)','l_Nat_testBit('])
assert syn.count(loop+'(')==syn.count('lean_uint32_to_nat(')==syn.count('l_BitVec_ofNat(')==1
assert syn.count('lean_uint64_of_nat(')==2 and syn.index(loop+'(')<syn.index('lean_uint32_to_nat(')<syn.index('l_BitVec_ofNat(')
asm=(N/f'binary-{loop}.txt').read_text();assert asm.count('\tbt ')==2
for x in ['test   $0x800000,%ebx','xor    $0xfff409,%edx','and    $0xffffff,%edx','cmove  %eax,%edx','mov    %edx,%ebx']:assert x in asm,x
assert 'l_Nat_testBit' in calls(asm) and 'lean_nat_big_sub' in calls(asm)
assert not any(re.search(r'List_|BitVec_|lean_alloc|lean_box|uint32_to_nat|lean_nat_(?:pow|mod|div)',name) for name in calls(asm))
# Independently derive actual syndrome branch successors and propagate possible
# loop-call counts. This is static normal-return reachability, not sampled use.
rows=[]
for line in (N/'binary-Parity_syndrome.txt').read_text().splitlines():
 m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
 if m:rows.append((int(m[1],16),m[2],m[3]))
byaddr={r[0]:i for i,r in enumerate(rows)};seen=set();pending=[(0,0)];exits=[]
while pending:
 i,n=pending.pop()
 if (i,n) in seen:continue
 seen.add((i,n));addr,op,arg=rows[i]
 n+=int(op=='call' and '<'+loop+'>' in arg);assert n<=1
 if op.startswith('j'):
  m=re.fullmatch(r'([0-9a-f]+) <([^>]+)>',arg);assert m,arg
  destination=int(m[1],16)
  if destination in byaddr:pending.append((byaddr[destination],n))
  else:
   assert op=='jmp' and m[2]=='l_BitVec_ofNat';exits.append({'address':hex(addr),'loop_calls':n,'target':m[2]})
  if op=='jmp':continue
 assert op!='ret' and i+1<len(rows);pending.append((i+1,n))
assert len(rows)==len(seen)==87 and exits and all(x['loop_calls']==1 for x in exits)
cfg=load(N/'syndrome-native-cfg.json');assert cfg['instruction_count']==87 and cfg['reachable_states']==87 and cfg['exits']==exits
assert cfg['static_loop_calls']==sum(op=='call' and '<'+loop+'>' in arg for _,op,arg in rows)==2
for name in ['wordStep','step']:
 assert not inspection['requested_binary_symbols'][P+'Parity_'+name]
 assert '<'+P+'Parity_'+name+'>:' in (N/f'object-{name}.txt').read_text()
assert not calls((N/'object-wordStep.txt').read_text())
assert P+'Parity_checksum' in calls((N/'binary-frameSyndrome.txt').read_text())
assert P+'Parity_syndrome' in calls((N/'binary-Parity_checksum.txt').read_text())
for name in ['decodeFrame','frameSyndrome','reportWithSyndrome']:assert calls((N/'binary-decode.txt').read_text()).count(P+name)==1
assert all(P+n in calls((N/'binary-cbScorePasses.txt').read_text()) for n in ['cbDensityTermsFast','cbPenalty','ScoreGate_choose'])
assert calls((N/'binary-ScoreGate_choose.txt').read_text()).count('lean_apply_1')==1
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'],path
out={'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],
 'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),'integration_review_sha256':sha(R/'integration-review.json'),
 'independent_source_proof_review_sha256':sha(N/'source-proof-review.json'),'native_checks':42,'native_inputs':140,'native_files':189,'exact_native_evidence_membership':192,
 'linked_project_sets':21,'other_unchanged_native_sets':19,'word_crc_live_path_verified':True,'independent_cfg':{'instructions':87,'reachable_states':87,'static_loop_sites':2,'normal_exits':exits},
 'execution_log_bindings':{str(N/n):sha(N/n) for n in ['validate.stdout','validate.stderr']},'review_script_sha256':sha(__file__),
 'limits':['Independent replay of retained source/C/object/linked CLI evidence only, with no compiler or decoder run. The separate independent mathematical proof assessment is authored by cost_analysis; this reviewer authored ParityWord.','The UInt32 state update is allocation-free, but arbitrary Nat index bookkeeping retains big-number operations. Static call sites do not establish dynamic call populations or timing gains.','The future freshly built benchmark worker must be independently rebound.']}
p=R/'native-binding-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'inputs':140,'files':189,'membership':192},indent=2))
