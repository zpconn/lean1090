#!/usr/bin/env python3
"""Independent static replay of retained gen8 native evidence; no native process."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re,shlex
B=Path('tests/evidence/optimization/gen8');R=B/'independent-review';N=B/'native-review'
P='lp_lean1090_Lean1090_Impl_'
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
review=load(N/'review.json');inspection=load(N/'inspection-inputs.json')
assert sha(N/'review.json')=='a89a67583bb893a88aa7fb624cc83e5143e6af423e8556a15d9e9126eab3ac0a'
assert sha(N/'inspection-inputs.json')=='5d362fb08135c52d7256f76082fd5c8b9e07ef56001ee486039aece887a3ac56'
assert review['status']=='passed' and len(review['checks'])==39 and all(review['checks'].values())
assert review['all_captured_inputs_unchanged'] and inspection['all_captured_inputs_unchanged']
assert len(inspection['inputs'])==137 and len(review['files'])==170
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'] and Path(path).stat().st_size==row['bytes'],path
for path,row in review['files'].items():assert sha(N/path)==row['sha256'] and (N/path).stat().st_size==row['bytes'],path
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()}==set(review['files'])|{'review.json'}
for orig,retained in inspection['retained'].items():assert sha(N/retained)==sha(orig),orig
for command in inspection['commands']:
 assert command['exit_code']==0
 assert command['argv'][0] in ['git','nm','objdump']
 assert (N/command['stderr']).read_bytes()==b''
assert len(inspection['linked_project_objects'])==21
prior={r['source']:r for r in load('bench/runs/gen7/fresh-native-inputs.json')}
unchanged=[]
for row in inspection['linked_project_objects']:
 if row['source'] in ['CLI/Main.lean','Impl/PayloadBits.lean']:continue
 old=prior[row['source']];assert sha(row['source'])==old['source_sha256']
 for key in ['c','object','trace']:assert sha(row[key])==old['artifacts'][row[key]]['sha256'],row[key]
 unchanged.append(row['source'])
assert sorted(unchanged)==sorted(review['unchanged_native_sources']) and len(unchanged)==19
integrated=load(R/'integration-review.json')
assert sha(B/'integration/targeted-build.json')==integrated['successful_integrated_build']['manifest_sha256']
for path,digest in integrated['final_source_sha256'].items():assert inspection['inputs'][path]['sha256']==digest
c=(N/'retained/.lake/build/ir/Impl/PayloadBits.c').read_text();body=cbody(c,P+'payloadValue')
assert P+'affineValue(' not in body
assert body.count('l_Rat_mul(')==body.count('l_Rat_add(')==1
assert 'v_scale_133_ = lean_ctor_get(v_column_120_, 3);' in body
assert 'v_offset_134_ = lean_ctor_get(v_column_120_, 4);' in body
assert 'l_instDecidableEqRat_decEq(v_scale_133_, v___x_139_)' in body
assert 'l_instDecidableEqRat_decEq(v___y_123_, v___x_125_)' in body
assert 'v___y_123_ = v_offset_134_;' in body
assert 'lean_unsigned_to_nat(0u)' in cbody(c,'_init_'+P+'payloadValue___closed__0')
assert 'lean_unsigned_to_nat(1u)' in cbody(c,'_init_'+P+'payloadValue___closed__1')
assert 'lean_ctor_set(v___x_129_, 0, v___y_124_);' in body
assert body.index('return v___x_149_;')<body.index(P+'payloadInteger(')
# Independently explore native branch addresses, recording only affine calls.
asm=(N/'binary-payloadValue.txt').read_text();rows=[]
for line in asm.splitlines():
 m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
 if m:rows.append((int(m[1],16),m[2],m[3]))
index={a:i for i,(a,_,_) in enumerate(rows)}
conditions={}
for i,(address,op,arg) in enumerate(rows):
 if op=='call' and '<l_instDecidableEqRat_decEq>' in arg:
  bindings=[a for _,o,a in rows[max(0,i-4):i] if o=='mov' and a.endswith(',%rdi')]
  kind={'%r14,%rdi':0,'%rbx,%rdi':1}[bindings[-1]]
  assert rows[i+1][1:]==('test','%al,%al')
  assert rows[i+2][1] in ['je','jne'];conditions[i+2]=kind
assert list(conditions.values()).count(0)==list(conditions.values()).count(1)==2
assert 'mov    0x20(%rdi),%r14' in asm and 'mov    0x28(%rdi),%rbx' in asm
paths=[]
for one in [False,True]:
 for zero in [False,True]:
  todo=[(0,())];seen=set();returns=set()
  while todo:
   i,events=todo.pop()
   if (i,events) in seen:continue
   seen.add((i,events));address,op,arg=rows[i]
   if op=='call':
    target=re.search(r'<([^>]+)>',arg)[1]
    if target in [P+'payloadInteger','l_Rat_ofInt','l_Rat_mul','l_Rat_add']:events+= (target,)
    assert len(events)<=4
   if op.startswith('ret'):returns.add(events);continue
   if op.startswith('j'):
    target=int(re.match(r'([0-9a-f]+) <',arg)[1],16);assert target in index
    if i in conditions:
     yes=(one,zero)[conditions[i]];jump=yes if op=='jne' else not yes
     todo.append((index[target] if jump else i+1,events));continue
    todo.append((index[target],events))
    if op=='jmp':continue
   assert i+1<len(rows);todo.append((i+1,events))
  accepted=(P+'payloadInteger','l_Rat_ofInt')+(() if one else ('l_Rat_mul',))+(() if zero else ('l_Rat_add',))
  assert returns=={(),accepted},(one,zero,returns)
  paths.append({'scale_equals_one':one,'offset_equals_zero':zero,'present_call_sequence':list(accepted),'rejected_call_sequence':[],'visited_states':len(seen)})
assert calls(asm).count('l_Rat_mul')==calls(asm).count('l_Rat_add')==1
assert not inspection['requested_binary_symbols'][P+'affineValue']
assert '<'+P+'affineValue>:' in (N/'object-affineValue.txt').read_text()
mapname='lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0'
assert P+'payloadValue' in calls((N/('binary-'+mapname+'.txt')).read_text())
for name in ['adsb','commB']:assert mapname in calls((N/('binary-Semantics_'+name+'.txt')).read_text())
assert P+'reportWithSyndrome' in calls((N/'binary-decode.txt').read_text())
assert P+'Semantics_adsb' in calls((N/'binary-reportWithSyndrome.txt').read_text())
assert P+'ScoreGate_choose' in calls((N/'binary-cbScorePasses.txt').read_text())
fallback=calls((N/'binary-cbScorePasses___lam__0___boxed.txt').read_text())
assert all(name in fallback for name in [P+'cbDensity',P+'cbPenalty',P+'Binary64_add','l_Rat_instDecidableLe'])
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'],path
out={'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),
 'integration_review_sha256':sha(R/'integration-review.json'),'native_checks':39,'native_inputs':137,'native_files':170,
 'linked_project_sets':21,'other_unchanged_native_sets':19,'independently_recounted_native_sequences':paths,
 'cli_sha256':inspection['inputs']['.lake/build/bin/lean1090']['sha256'],
 'review_script_sha256':sha(__file__),'all_reviewed_input_hashes_match':True,'findings':[],
 'conclusions':['The exact one/zero guards are inlined into live payloadValue, with arithmetic skipped only on their identity branches. Both general operations retain multiplication-before-addition order.','The status-rejected path reaches neither payloadInteger, Rat.ofInt, Rat.mul nor Rat.add. Present paths retain integer conversion exactly once and the four proved arithmetic combinations.','Actual ADS-B and Comm-B semantic map calls reach the same payloadValue. Frozen whole/direct adapters and benchmark remain linked through their live public entrypoints.','All 19 other production source/C/object/trace sets match gen7. Software fallback, table constants and integer inference gate are unchanged.'],
 'limits':['Static retained C and linked CLI assembly review only; the later fresh timed worker must be rebound independently.','Branch traversal fixes only inspected scale/offset equality outcomes and conservatively explores other direct branches, assuming ordinary calls return. It is supporting compiler inspection, not a replacement for the universal Lean proof.','No build, test, decoder, profiler or benchmark was run; no timing or instruction-count improvement is claimed.']}
p=R/'native-binding-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'native_inputs':137,'native_files':170,'branch_cases':len(paths)},indent=2))
