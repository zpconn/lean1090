"""Recheck retained independent native/proof evidence; no native execution."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
N=Path('tests/evidence/optimization/gen12/native-review');R=N.parent/'independent-review';P='lp_lean1090_Lean1090_Impl_'
load=lambda p:json.loads(Path(p).read_text())
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
review=load(N/'review.json');inspection=load(N/'inspection-inputs.json');proof=load(N/'source-proof-review.json');integration=load(R/'integration-review.json')
assert review['status']==proof['status']=='passed' and review['findings']==proof['findings']==[]
assert len(review['checks'])==41 and all(review['checks'].values()) and review['byte_words_live_path_verified']
assert len(inspection['inputs'])==141 and len(review['files'])==221
for path,item in inspection['inputs'].items():assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
for path,relative in inspection['retained'].items():assert (N/relative).read_bytes()==Path(path).read_bytes()
for path,item in review['files'].items():assert sha(N/path)==item['sha256'] and (N/path).stat().st_size==item['bytes'],path
extras={'review.json','validate.stdout','validate.stderr','attempt-01/validate.stdout','attempt-01/validate.stderr','attempt-02/validate.stdout','attempt-02/validate.stderr'}
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()}==set(review['files'])|extras
assert (N/'validate.stderr').read_bytes()==b''
for n in ['attempt-01','attempt-02']:assert 'AssertionError' in (N/n/'validate.stderr').read_text()
assert review['source_proof_review_sha256']==sha(N/'source-proof-review.json')
assert proof['sources']==integration['final_source_sha256']
for p,item in proof['supplementary_inputs'].items():assert sha(p)==item['sha256'] and Path(p).stat().st_size==item['bytes']
for item in proof['helper_facts']+proof['integrated_allowed_axiom_facts']:assert set(item['axioms'])<={'propext','Classical.choice','Quot.sound'}
assert len(proof['helper_facts'])==11
for cmd in inspection['commands']:assert cmd['exit_code']==0 and (N/cmd['stderr']).read_bytes()==b''
# Reconstruct the native CFG independently using direct instructions and a
# state consisting only of selected call counts; explore all branch choices.
def parse(text):
 return [(int(m[1],16),m[2],m[3]) for line in text.splitlines() if (m:=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line))]
def explore(text,start,tracked):
 rows=parse(text);index={x[0]:i for i,x in enumerate(rows)};pending=[(index[start],(0,)*len(tracked))];seen=set();ends=set()
 while pending:
  i,counts=pending.pop()
  if (i,counts) in seen:continue
  seen.add((i,counts));addr,op,arg=rows[i];counts=list(counts)
  if op=='call':
   for k,name in enumerate(tracked):counts[k]+=int('<'+name+'>' in arg)
  counts=tuple(counts);assert max(counts,default=0)<=2
  if op=='ret':ends.add((counts,'ret'));continue
  if op.startswith('j'):
   m=re.fullmatch(r'([0-9a-f]+) <([^>]+)>',arg);assert m,arg;target=int(m[1],16)
   if target in index:pending.append((index[target],counts))
   else:assert op=='jmp';ends.add((counts,m[2]))
   if op=='jmp':continue
  assert i+1<len(rows);pending.append((i+1,counts))
 return {'start':hex(start),'reachable_instruction_count':len({i for i,_ in seen}),'tracked':tracked,'normal_exits':[{'counts':list(c),'target':t} for c,t in sorted(ends)]}
prefix=(N/'binary-bytesWordPrefix.txt').read_text();public=(N/'binary-bytesValue.txt').read_text();cfg=load(N/'byte-native-cfg.json')
prefix_result=explore(prefix,parse(prefix)[0][0],['lean_alloc_small_object_core']);assert prefix_result==cfg['prefix']
assert all(x['counts']==[2] for x in prefix_result['normal_exits'])
rows=parse(public);starts={}
for label,const in [('short','$0x11,%rax'),('medium','$0x21,%rax')]:
 i=next(i for i,(_,op,arg) in enumerate(rows) if (op,arg)==('cmp',const));assert rows[i+1][1]=='jbe';starts[label]=int(rows[i+1][2].split()[0],16)
 if label=='medium':starts['long']=rows[i+2][0]
tracked=[P+'bytesWordPrefix','lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0','lean_nat_shiftl'];branches={k:explore(public,v,tracked) for k,v in starts.items()}
assert branches==cfg['public_branches']
for k,want in [('short',[0,0,0]),('medium',[1,0,1]),('long',[0,1,0])]:assert all(r['counts']==want for r in branches[k]['normal_exits'])
assert len(review['unchanged_native_sources'])==17 and review['ownership_changed_native_sources']==['Impl/Frame.lean','Impl/Message.lean']
ownership=load(N/'dependent-native-ownership.json')
for module,data in ownership.items():
 source='Impl/'+module+'.lean';assert sha(source)==data['old_source_sha256']
 assert sha('.lake/build/ir/Impl/'+module+'.c')==data['new_c_sha256']
 assert sha('tests/evidence/diagnostics/gen11/generated-c/Impl/'+module+'.c')==data['old_c_sha256']
 deltas=data['common_body_deltas_modulo_generated_local_numbers'];assert len(deltas)==1
 changes=[line for line in next(iter(deltas.values())).splitlines() if line[:1] in '+-' and not line.startswith(('+++','---'))]
 if module=='Frame':assert changes==['+lean_dec(v_bytes_N_);']*2
 else:assert changes==['-lean_dec(v___x_N_);']
for p,item in inspection['inputs'].items():assert sha(p)==item['sha256']
out={'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),'integration_review_sha256':sha(R/'integration-review.json'),'independent_source_proof_review_sha256':sha(N/'source-proof-review.json'),'native_checks':41,'native_inputs':141,'native_files':221,'exact_native_evidence_membership':228,'byte_words_live_path_verified':True,'independent_cfg':{'prefix':prefix_result,'public_branches':branches},'dependent_native_ownership_sha256':sha(N/'dependent-native-ownership.json'),'other_unchanged_native_sets':17,'execution_log_bindings':{str(N/n):sha(N/n) for n in extras if n!='review.json'},'review_script_sha256':sha(__file__),'limits':['Read-only replay of retained source/proof/native evidence. No compiler or decoder execution.','The prefix endpoint allocates its UInt64 box and pair; conservative CFG finds no repeated endpoint allocation per consumed byte. Callee allocations and actual runtime branch populations are not inferred.','Frame/Message Lean sources are unchanged; explicit retained C ownership changes are preserved rather than incorrectly claiming identical native objects.']}
p=R/'native-binding-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'inputs':141,'files':221,'membership':228},indent=2))
