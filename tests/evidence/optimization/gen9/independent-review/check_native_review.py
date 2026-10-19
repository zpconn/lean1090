#!/usr/bin/env python3
"""Independent static replay of gen9 retained native evidence; no native execution."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re
B=Path('tests/evidence/optimization/gen9');R=B/'independent-review';N=B/'native-review';P='lp_lean1090_Lean1090_Impl_'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def cbody(text,name):
 m=re.search(r'\b'+re.escape(name)+r'\([^;{}]*\)\s*\{',text);assert m,name
 n=0
 for j in range(m.end()-1,len(text)):
  n+=(text[j]=='{')-(text[j]=='}')
  if n==0:return text[m.start():j+1]
 raise AssertionError(name)
def calls(text):return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>',text)
def alpha(text):
 names={}
 return re.sub(r'\bv_\w+_\b',lambda m:names.setdefault(m[0],'v'+str(len(names))),text)
review=load(N/'review.json');inspection=load(N/'inspection-inputs.json')
# Stable final producer hashes are written after the owner's completion signal.
bind=load(R/'native-final-bindings.json')
assert sha(N/'review.json')==bind['review_sha256']
assert sha(N/'inspection-inputs.json')==bind['inspection_sha256']
assert review['status']=='passed' and len(review['checks'])==38 and all(review['checks'].values())
assert review['all_captured_inputs_unchanged'] and inspection['all_captured_inputs_unchanged']
assert len(inspection['inputs'])==138 and len(review['files'])==bind['file_count']
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'] and Path(path).stat().st_size==row['bytes'],path
for path,row in review['files'].items():assert sha(N/path)==row['sha256'] and (N/path).stat().st_size==row['bytes'],path
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()}==set(review['files'])|{'review.json'}
for orig,retained in inspection['retained'].items():assert sha(N/retained)==sha(orig),orig
for command in inspection['commands']:
 assert command['exit_code']==0 and command['argv'][0] in ['git','nm','objdump']
 assert (N/command['stderr']).read_bytes()==b''
assert len(inspection['linked_project_objects'])==21
prior={r['source']:r for r in load('bench/runs/gen8/fresh-native-inputs.json')};unchanged=[]
for row in inspection['linked_project_objects']:
 if row['source'] in ['CLI/Main.lean','Impl/Bits.lean']:continue
 old=prior[row['source']];assert sha(row['source'])==old['source_sha256']
 for key in ['c','object','trace']:assert sha(row[key])==old['artifacts'][row[key]]['sha256'],row[key]
 unchanged.append(row['source'])
assert sorted(unchanged)==sorted(review['unchanged_native_sources']) and len(unchanged)==19
integrated=load(R/'integration-review.json')
assert sha(B/'integration/targeted-build.json')==integrated['successful_integrated_build']['manifest_sha256']
for path,digest in integrated['final_source_sha256'].items():assert inspection['inputs'][path]['sha256']==digest
c=(N/'retained/.lake/build/ir/Impl/Bits.c').read_text();body=cbody(c,P+'field')
assert 'v___x_23_ = lean_unsigned_to_nat(64u);' in body
assert 'v___x_24_ = lean_nat_dec_lt(v_width_21_, v___x_23_);' in body
wide,narrow=body.split('if (v___x_24_ == 0)\n{',1)[1].split('\nelse\n{',1)
assert wide.count('lean_nat_pow(')==wide.count('lean_nat_div(')==wide.count('l_BitVec_ofNat(')==1
assert all(x not in narrow for x in ['lean_nat_pow(', 'lean_nat_div(', 'lean_nat_mod(', 'l_BitVec_ofNat('])
expected_lines=['v___x_31_ = lean_nat_sub(v_total_19_, v_start_20_);','v___x_32_ = lean_nat_sub(v___x_31_, v_width_21_);','v___x_33_ = lean_nat_shiftr(v_word_22_, v___x_32_);','v___x_34_ = lean_uint64_of_nat(v___x_33_);','v___x_35_ = 1ULL;','v___x_36_ = lean_uint64_of_nat(v_width_21_);','v___x_37_ = lean_uint64_shift_left(v___x_35_, v___x_36_);','v___x_38_ = lean_uint64_sub(v___x_37_, v___x_35_);','v___x_39_ = lean_uint64_land(v___x_34_, v___x_38_);','v___x_40_ = lean_uint64_to_nat(v___x_39_);','return v___x_40_;']
assert all(line in narrow for line in expected_lines)
assert [narrow.index(line) for line in expected_lines]==sorted(narrow.index(line) for line in expected_lines)
assert P+'payloadWordBits(' not in body
old_c=(N/'retained/tests/evidence/diagnostics/gen8/generated-c/Impl/Bits.c').read_text()
for name in [P+'bytesValue',P+'packFields',P+'frameBytes','lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0','lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0']:
 assert alpha(cbody(c,name))==alpha(cbody(old_c,name)),name
# Independently derive the actual width-guard successors and explore their CFG.
asm=(N/'binary-field.txt').read_text();rows=[]
for line in asm.splitlines():
 m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
 if m:rows.append((int(m[1],16),m[2],m[3]))
index={a:i for i,(a,_,_) in enumerate(rows)}
assert len(index)==len(rows)
assert 'mov    %rdx,%rbx' in asm and 'mov    %rcx,%r14' in asm
assert 'mov    $0x81,%esi' in asm and '<lean_nat_big_lt>' in asm
positions=[i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('cmp','$0x81,%rbx')]
assert len(positions)==1;guard=positions[0];assert rows[guard+1][1]=='jae'
wide_entry=index[int(rows[guard+1][2].split()[0],16)];narrow_entry=guard+2
assert rows[wide_entry][1:]==('test','$0x1,%dil') and rows[narrow_entry][1:]==('test','$0x1,%dil')
shift_index=[i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('shr','%cl,%r14')];assert len(shift_index)==1
assert rows[shift_index[0]+1][1:]==('cmp','$0x80,%r15')
assert rows[shift_index[0]+4][1:]==('cmovb','%rax,%r14')
mask_index=[i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('and','%rax,%r15')];assert len(mask_index)==1
mi=mask_index[0];assert [r[1:] for r in rows[mi-2:mi+2]]==[('shl','%cl,%rax'),('not','%rax'),('and','%rax,%r15'),('lea','0x1(,%r15,2),%rax')]
branches={}
for name,entry in [('narrow',narrow_entry),('wide',wide_entry)]:
 todo=[(entry,False,False)];seen=set();terminal=set();observed=set();ops=set()
 while todo:
  i,shifted,masked=todo.pop()
  if (i,shifted,masked) in seen:continue
  seen.add((i,shifted,masked));address,op,arg=rows[i];ops.add(op)
  if i==shift_index[0]:shifted=True
  if op=='call':
   target=re.search(r'<([^>]+)>',arg)[1];observed.add(target)
   if target=='lean_nat_big_shiftr':shifted=True
   if name=='narrow' and target=='lean_uint64_of_big_nat':assert shifted
  if i==mi:assert shifted;masked=True
  if op.startswith('ret'):terminal.add((shifted,masked));continue
  if op.startswith('j'):
   target=int(re.match(r'([0-9a-f]+) <',arg)[1],16);assert target in index
   todo.append((index[target],shifted,masked))
   if op=='jmp':continue
  assert i+1<len(rows);todo.append((i+1,shifted,masked))
 if name=='narrow':
  assert terminal=={(True,True)}
  assert not observed & {'lean_nat_pow','lean_nat_big_div','lean_nat_big_mod','l_BitVec_ofNat'}
  assert not ops & {'div','idiv'}
  assert {'lean_nat_big_shiftr','lean_uint64_of_big_nat'}<=observed
 else:
  assert terminal=={(False,False)} and {'lean_nat_pow','lean_nat_big_div','l_BitVec_ofNat'}<=observed
  assert 'div' in ops and 'lean_nat_big_shiftr' not in observed
 branches[name]={'entry':hex(rows[entry][0]),'reachable_instructions':len({i for i,_,_ in seen}),'calls':sorted(observed),'return_shift_and_mask_flags':[list(t) for t in sorted(terminal)]}
producer=load(N/'field-control-flow.json')['branches']
for name,row in branches.items():
 assert row['entry']==producer[name]['entry'] and row['reachable_instructions']==producer[name]['reachable_instructions']
 assert row['calls']==producer[name]['calls']
assert calls((N/'binary-decodeFrame.txt').read_text()).count(P+'field')==26
for name in ['decodeFrame','frameSyndrome','reportWithSyndrome']:
 assert calls((N/'binary-decode.txt').read_text()).count(P+name)==1
assert P+'ScoreGate_choose' in calls((N/'binary-cbScorePasses.txt').read_text())
fallback=calls((N/'binary-cbScorePasses___lam__0___boxed.txt').read_text())
assert all(name in fallback for name in [P+'cbDensity',P+'cbPenalty',P+'Binary64_add','l_Rat_instDecidableLe'])
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'],path
out={'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),'integration_review_sha256':sha(R/'integration-review.json'),
 'native_checks':len(review['checks']),'native_inputs':len(inspection['inputs']),'native_files':len(review['files']),'linked_project_sets':21,'other_unchanged_native_sets':19,
 'field_branch_analysis_verified':True,'independently_derived_native_branches':branches,'live_decodeFrame_field_call_sites':26,
 'cli_sha256':inspection['inputs']['.lake/build/bin/lean1090']['sha256'],'review_script_sha256':sha(__file__),'all_reviewed_input_hashes_match':True,'findings':[],
 'conclusions':['The actual width guard selects a narrow Nat-shift-before-conversion and native mask path, or the unchanged power/division/BitVec fallback. Every conservatively explored narrow return follows both the shift and mask, and never reaches division, power or generic BitVec construction.','Small-Nat native shift code masks machine shift counts only transiently: its explicit count comparison and conditional move give zero for large counts. Big-Nat shifts use the runtime helper before conversion. Width masking follows the proved below-64 guard.','All 26 retained decodeFrame field callsites use the same live field symbol; decode still calls the same decodeFrame and one shared frameSyndrome. No adapter-only or corpus-specific copy exists.','The 19 other production source/C/object/trace sets equal gen8. bytesValue, packFields, frameBytes and their folds remain equivalent generated C modulo local names; score and software fallback paths remain live.'],
 'limits':['Static retained C and integrated CLI assembly inspection only; the future freshly built timed worker must be rebound independently.','Intraprocedural branch traversal derives width-guard successors and conservatively explores other branches, assuming calls return. It supports compiler review and does not replace the universal Lean proof.','No compiler, test, decoder, profiler or benchmark was run, and no performance claim follows from this static review.']}
p=R/'native-binding-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'native_inputs':out['native_inputs'],'native_files':out['native_files'],'branches':branches},indent=2))
