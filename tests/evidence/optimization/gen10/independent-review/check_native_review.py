#!/usr/bin/env python3
"""Independent static replay of retained gen10 QNH evidence; no native execution."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re
B=Path('tests/evidence/optimization/gen10');R=B/'independent-review';N=B/'native-review';P='lp_lean1090_Lean1090_Impl_'
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
review=load(N/'review.json');inspection=load(N/'inspection-inputs.json');bind=load(R/'native-final-bindings.json')
assert sha(N/'review.json')==bind['review_sha256'] and sha(N/'inspection-inputs.json')==bind['inspection_sha256']
assert review['status']=='passed' and len(review['checks'])==bind['check_count'] and all(review['checks'].values())
assert review['all_captured_inputs_unchanged'] and inspection['all_captured_inputs_unchanged']
assert len(inspection['inputs'])==139 and len(review['files'])==bind['file_count']
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'] and Path(path).stat().st_size==row['bytes'],path
for path,row in review['files'].items():assert sha(N/path)==row['sha256'] and (N/path).stat().st_size==row['bytes'],path
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()}==set(review['files'])|{'review.json'}
for orig,retained in inspection['retained'].items():assert sha(N/retained)==sha(orig),orig
additional=load(N/'additional-inspection.json');assert additional['inspection_sha256']==sha(N/'inspection-inputs.json') and additional['all_captured_inputs_unchanged']
for command in inspection['commands']+additional['commands']:
 assert command['exit_code']==0 and command['argv'][0] in ['git','nm','objdump']
 assert (N/command['stderr']).read_bytes()==b''
for row in additional['excerpts'].values():
 assert sha(row['source'])==row['source_sha256'] and sha(N/row['path'])==row['sha256']
 lines=Path(row['source']).read_text().splitlines();expected=''.join(f'{n}: {lines[n-1]}\n' for n in range(row['first_line'],row['last_line']+1))
 assert (N/row['path']).read_text()==expected
assert len(inspection['linked_project_objects'])==21
prior={r['source']:r for r in load('bench/runs/gen9/fresh-native-inputs.json')};unchanged=[]
for row in inspection['linked_project_objects']:
 if row['source'] in ['CLI/Main.lean','Impl/CommB.lean']:continue
 old=prior[row['source']];assert sha(row['source'])==old['source_sha256']
 for key in ['c','object','trace']:assert sha(row[key])==old['artifacts'][row[key]]['sha256'],row[key]
 unchanged.append(row['source'])
assert sorted(unchanged)==sorted(review['unchanged_native_sources']) and len(unchanged)==19
integrated=load(R/'integration-review.json')
assert sha(B/'integration/targeted-build.json')==integrated['successful_integrated_build']['manifest_sha256']
for path,digest in integrated['final_source_sha256'].items():assert inspection['inputs'][path]['sha256']==digest
c=(N/'retained/.lake/build/ir/Impl/CommB.c').read_text();lookup=cbody(c,P+'cbQNH64');entry=cbody(c,P+'cbQNHValueTable___lam__0')
expected_lines=['v___x_105_ = '+P+'cbQNHValueTable;','v___x_106_ = lean_unsigned_to_nat(28u);','v___x_107_ = lean_unsigned_to_nat(12u);','v___x_108_ = '+P+'payloadBits(v_word_104_, v___x_106_, v___x_107_);','v___x_109_ = lean_array_fget_borrowed(v___x_105_, v___x_108_);']
assert all(line in lookup for line in expected_lines) and [lookup.index(x) for x in expected_lines]==sorted(lookup.index(x) for x in expected_lines)
assert not any(x in lookup for x in ['Binary64_', 'l_Rat_', 'lean_obj_once', 'Array_ofFn', 'lean_alloc'])
assert entry.count(P+'Binary64_mul(')==entry.count(P+'Binary64_add(')==1
assert entry.index(P+'Binary64_mul(')<entry.index(P+'Binary64_add(')
assert 'v___x_96_ = '+P+'Binary64_mul(v___x_94_, v___x_95_);' in entry
assert 'v___x_98_ = '+P+'Binary64_add(v___x_96_, v___x_97_);' in entry
for number,suffix in [('1','0'),('10','1'),('800','4')]:assert 'lean_unsigned_to_nat('+number+'u)' in cbody(c,'_init_'+P+'cbQNHValueTable___lam__0___closed__'+suffix)
assert 'l_Rat_div(v___x_87_, v___x_86_)' in cbody(c,'_init_'+P+'cbQNHValueTable___lam__0___closed__2')
assert P+'Binary64_round(' in cbody(c,'_init_'+P+'cbQNHValueTable___lam__0___closed__3')
constructor=cbody(c,'_init_'+P+'cbQNHValueTable___closed__1')
assert 'lean_unsigned_to_nat(4096u)' in constructor and 'l_Array_ofFn___redArg(v___x_101_, v___f_100_)' in constructor
assert '.m_fun = (void*)'+P+'cbQNHValueTable___lam__0' in c
initializer=cbody(c,'initialize_lean1090_Impl_CommB')
a=P+'cbQNHValueTable = _init_'+P+'cbQNHValueTable();';b='lean_mark_persistent('+P+'cbQNHValueTable);'
assert c.count(P+'cbQNHValueTable =')==1 and initializer.index(a)<initializer.index(b)
cli=(N/'retained/.lake/build/ir/CLI/Main.c').read_text();jc=(N/'retained/.lake/build/ir/Impl/JSON.c').read_text();mc=(N/'retained/.lake/build/ir/Impl/Message.c').read_text()
assert cbody(cli,'main').index('initialize_lean1090_CLI_Main(')<cbody(cli,'main').index('lean_run_main(')
assert 'initialize_lean1090_Impl_JSON(' in cbody(cli,'initialize_lean1090_CLI_Main')
assert 'initialize_lean1090_Impl_Message(' in cbody(jc,'initialize_lean1090_Impl_JSON')
assert 'initialize_lean1090_Impl_CommB(' in cbody(mc,'initialize_lean1090_Impl_Message')
assert '$0x2001,%edi' in (N/'binary-table-constructor.txt').read_text() and 'l_Array_ofFn___redArg' in calls((N/'binary-table-constructor.txt').read_text())
entry_calls=calls((N/'binary-cbQNHValueTable___lam__0.txt').read_text())
assert entry_calls.index(P+'Binary64_mul')<entry_calls.index(P+'Binary64_add')
assert P+'Binary64_round' in calls((N/'binary-literal-round.txt').read_text())
assert 'l_Rat_div' in calls((N/'binary-literal-ratio.txt').read_text())
assert not inspection['requested_binary_symbols'][P+'cbQNH64']
assert '<'+P+'cbQNH64>:' in (N/'object-cbQNH64.txt').read_text()
# Derive the linked inlined lookup from its own instructions, not a missing wrapper.
paths={}
for caller in ['cbValid40','cbDensityTerms']:
 assert P+'cbQNH64(' in cbody(c,P+caller)
 asm=(N/f'binary-{caller}.txt').read_text();rows=[]
 for line in asm.splitlines():
  m=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line)
  if m:rows.append({'address':'0x'+m[1],'op':m[2],'args':m[3]})
 starts=[i for i,r in enumerate(rows) if '<'+P+'cbQNHValueTable>' in r['args']];assert len(starts)==1
 start=starts[0];ends=[i for i in range(start+1,len(rows)) if rows[i]['op']=='mov' and re.match(r'0x18\([^\n]+,4\),',rows[i]['args'])];assert ends
 path=rows[start:ends[0]+1];paths[caller]=path
 assert path[0]['op']=='lea' and path[1]['op']=='mov'
 assert [r['args'] for r in path if r['op']=='call']==[next(r['args'] for r in path if '<'+P+'payloadBits>' in r['args'])]
 assert any(r['args']=='$0x39,%esi' for r in path) and any(r['args']=='$0x19,%edx' for r in path)
 assert any(r['op']=='and' and r['args']=='$0xfffffffffffffffe,%rcx' for r in path)
 assert not any(r['op'].startswith('j') or 'Binary64_' in r['args'] or 'lean_obj_once' in r['args'] for r in path)
assert paths==load(N/'qnh-native-paths.json')['paths']
assert P+'bdsWireValid(' in cbody(c,P+'decodeBDS') and P+'cbValid40(' in cbody(c,P+'bdsWireValid')
assert all(P+n in calls((N/'binary-commBCoreEligible.txt').read_text()) for n in ['bdsWireValid','cbScorePasses'])
for n in ['decodeFrame','frameSyndrome','reportWithSyndrome']:assert calls((N/'binary-decode.txt').read_text()).count(P+n)==1
assert all(P+n in calls((N/'binary-cbScorePasses.txt').read_text()) for n in ['cbDensityTermsFast','cbPenalty','ScoreGate_choose'])
fallback=calls((N/'binary-cbScorePasses___lam__0___boxed.txt').read_text())
assert all(n in fallback for n in [P+'cbDensity',P+'cbPenalty',P+'Binary64_add','l_Rat_instDecidableLe'])
assert P+'cbDensityTerms' in calls((N/'binary-cbDensity.txt').read_text())
for path,row in inspection['inputs'].items():assert sha(path)==row['sha256'],path
out={'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),'integration_review_sha256':sha(R/'integration-review.json'),
 'native_checks':len(review['checks']),'native_inputs':len(inspection['inputs']),'native_files':len(review['files']),'linked_project_sets':21,'other_unchanged_native_sets':19,
 'qnh_table_live_path_verified':True,'independently_derived_native_lookup_paths':paths,'standalone_QNH_wrapper_inlined':True,
 'cli_sha256':inspection['inputs']['.lake/build/bin/lean1090']['sha256'],'review_script_sha256':sha(__file__),'all_reviewed_input_hashes_match':True,'findings':[],
 'conclusions':['The actual complete table constructor has 4096 entries; its entry closure preserves rounded literal 1/10, software multiplication and software addition of 800 in that order. Module initialization builds and marks it persistent before CLI main.', 'The public lookup C/object body performs only the unchanged field extraction and proved-bounded borrowed array read. Its standalone CLI symbol is inlined, and both live hard-validity and full-software density callers contain the actual field-code table load.', 'Each independently reconstructed native lookup sequence uses tagged start 28 and width 12, the live payloadBits function, tag-bit removal and an indexed entry load, with no intervening branch or software binary64 operation.', 'The candidate/accepted-record validation and exact software fallback retain their live paths. The shared CRC and integer score gate remain live; the other 19 production source/C/object/trace sets match gen9. No adapter-only copy or corpus cache is present.'],
 'limits':['Static retained generated C/object/linked CLI evidence only; the future freshly built timed worker must be rebound independently.', 'Table startup precedes message processing; absence of the standalone wrapper means inlining, not zero QNH work. No runtime call populations or throughput are inferred.', 'No compiler, decoder, test, profiler or benchmark was executed by this reviewer.']}
p=R/'native-binding-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'native_inputs':out['native_inputs'],'native_files':out['native_files'],'lookup_callers':list(paths)},indent=2))
