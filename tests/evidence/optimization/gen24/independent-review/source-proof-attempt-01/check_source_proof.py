"""Independent integrated semantic-reuse proof review; no compiler execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess,difflib
G=Path('tests/evidence/optimization/gen24');R=G/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
bindings={};checks=[]
def bind(p,h=None):
 p=Path(p);actual=sha(p);assert h is None or h==actual,str(p);bindings[str(p)]=actual;return actual
def check(x,label):assert x,label;checks.append(label)
def axioms(p):
 text=Path(p).read_text();rows=re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)",text)
 check(len(rows)==len(re.findall(r'depends on axioms:|does not depend on any axioms',text)),'Complete multiline axiom announcements parsed '+str(p))
 facts={n:[v.strip() for v in a.split(',') if v.strip()] for n,a in rows}
 check(len(facts)==len(rows) and bool(facts) and all(set(v)<={'propext','Classical.choice','Quot.sound'} for v in facts.values()),'Every distinct printed fact uses only permitted axioms '+str(p))
 return facts
runtime=load(R/'runtime-design-review.json');bind(R/'runtime-design-review.json','8b6a842a883c3024de67fc1096ee9a3c4075d922f2ef351f1ce470d41a1e7ddf')
for p,h in runtime['bindings'].items():bind(p,h)
check(runtime['findings']==[],'Earlier exact runtime delta/status/correction and unchanged Float boundary review remains bound')
newfacts={};witnesses=[]
for mod,sub,attempt,count in [('CommBValueReuse','proof-values','attempt-01',13),('CommBSemanticReuse','proof-semantics','attempt-02',8)]:
 src=Path('Proofs')/(mod+'.lean');summary=load(G/sub/'summary.json');text=src.read_text();bind(src,summary['source_sha256']);bind(G/sub/'summary.json')
 check(summary['status']=='passed','Completed helper '+mod)
 log=G/sub/attempt/'build.log';bind(log,summary.get('build_log_sha256',summary.get('log_sha256')));parsed=axioms(log)
 names=re.findall(r'^#print axioms (\w+)',text,re.M);prefix='Lean1090.Proofs.'+mod+'.'
 own={prefix+n:parsed[prefix+n] for n in names}
 check(len(own)==count and own==summary['printed_facts'],'All printed helper facts match successful kernel log '+mod)
 newfacts.update(own);witnesses.extend(prefix+n for n in names if n.endswith('_witness'))
 stripped=re.sub(r'/\-.*?\-/','',text,flags=re.S);stripped=re.sub(r'--[^\n]*','',stripped);stripped=re.sub(r'#print axioms[^\n]*','',stripped)
 check(not re.search(r'\b(?:sorry|admit|axiom|native_decide|unsafe|partial)\b',stripped),'No prohibited proof bypass '+mod)
 for p in (G/sub).rglob('*'):
  if p.is_file():bind(p)
values=Path('Proofs/CommBValueReuse.lean').read_text();numeric=Path('Proofs/CommBSemanticReuse.lean').read_text()
check('theorem oracleValues_eq (register word : Nat) :' in values,'Complete ordered oracle-values equality has no register, word, status or validity precondition')
check('theorem commBValue_eq_old (register word : Nat) (name : String) :' in values,'Public commBValue full old body is unconditional for arbitrary name')
check('theorem layout_names_nodup (register : Nat)' in values and 'split <;> decide +kernel' in values,'All layouts including unsupported registers have kernel-checked distinct names')
check('find_name_of_mem PayloadColumn.name layout column unique member' in values and 'List.map_congr_left' in values,'Generic projected-name member lookup proves ordered map equality, including absent values')
check('theorem commBStandardFloatsFromOracle_eq_old (register word : Nat)\n    (fields : List NumericField) :' in numeric,'Numeric helper equivalence covers arbitrary supplied lists')
check('theorem commB_eq_old (register word : Nat) :' in numeric and 'CommBValueReuse.oracleValues_eq' in numeric and 'commBStandardFloatsFromOracle_oracle_eq' in numeric,'Complete old payload equality composes both unrestricted list equalities')
check(len(newfacts)==21 and len(witnesses)==11,'Twenty-one new facts and eleven kernel witness groups cover correction/status/default and numeric key/order/policy boundaries')
headers=lambda s:re.findall(r'(?m)^(?:private )?theorem (\w+)([\s\S]*?)\s*:=',s)
preserved={}
for name in ['CommBTables','CommBPenalty','Decoder']:
 p=Path('Proofs')/(name+'.lean');current=p.read_text();old=subprocess.check_output(['git','show','HEAD:'+str(p)],text=True);bind(p)
 check(headers(current)==headers(old),'All existing theorem declarations are byte-identical '+name);preserved[name]=len(headers(old))
 reverse=current
 if name=='CommBTables':reverse=reverse.replace('commBValue, commBAdjustValue,','commBValue,')
 elif name=='CommBPenalty':reverse=reverse.replace('Impl.commBValue, Impl.commBAdjustValue,','Impl.commBValue,')
 else:
  reverse=reverse.replace('import Proofs.CommBSemanticReuse\n','').replace('unfold Impl.commBValue Impl.commBAdjustValue Spec.commBValue','unfold Impl.commBValue Spec.commBValue')
  for target in ['commBStandardFloats','commB']:
   reverse=reverse.replace(f'  funext register word\n  rw [CommBSemanticReuse.{target}_eq_old]\n  unfold Spec.Semantics.{target}',f'  unfold Impl.Semantics.{target} Spec.Semantics.{target}')
 check(reverse==old,'Exact existing proof delta is unfolding/delegation only '+name)
 (R/(name+'.proof.diff')).write_text(''.join(difflib.unified_diff(old.splitlines(True),current.splitlines(True),fromfile='HEAD:'+str(p),tofile=str(p))))
b=load(G/'integration/targeted-build.json');bind(G/'integration/targeted-build.json');bind(G/'integration/targeted-build.log',b['log_sha256'])
check(b['status']=='passed' and b['exit_code']==0 and len(b['all_inputs_after'])==202 and b['all_inputs_before']==b['all_inputs_after'],'Combined build passed with 202 identical before/after correctness inputs')
expected={'Impl/CommB.lean','Impl/Semantics.lean','Proofs/CommBValueReuse.lean','Proofs/CommBSemanticReuse.lean','Proofs/CommBTables.lean','Proofs/CommBPenalty.lean','Proofs/Decoder.lean'}
check(set(b['inputs_after'])==expected,'Combined source inventory is exactly seven authorized sources')
for p,h in b['inputs_after'].items():bind(p,h)
facts=axioms(G/'integration/targeted-build.log');check(all(facts.get(n)==v for n,v in newfacts.items()),'Combined integration includes all 21 final helper facts')
check(all(n in facts for n in ['Lean1090.Proofs.Refinement','Lean1090.Proofs.CPRTrackingRefinement']),'Both unchanged full decoder/CPR capstone bridges remain proved')
v=load(G/'integration/validation.json');bind(G/'integration/validation.json')
check(v['status']=='passed' and v['printed_fact_count']==len(facts) and v['audited_source_count']==127 and v['all_correctness_inputs_unchanged']==202,'Independent complete log parse agrees with combined validator actual counts')
locked={p:h for h,p in [x.split('  ',1) for x in Path('spec.lock').read_text().splitlines()]}
for p,h in locked.items():bind(p,h)
check(len(locked)==104,'All 104 frozen lock entries unchanged')
result=dict(status='passed',findings=[],recorded_utc=datetime.now(timezone.utc).isoformat(),checks=checks,check_count=len(checks),bindings=bindings,source_delta=b['inputs_after'],printed_axiom_facts=newfacts,printed_fact_count=len(newfacts),kernel_witnesses=witnesses,preserved_theorem_counts=preserved,integration_printed_fact_count=len(facts),all_input_refinement_verified=True,reviewer_sha256=sha(__file__),assessments=['All nine oracle correction cases/default remain exact, and Option.bind preserves absence before adjustment. Name uniqueness covers every concrete layout and unsupported-register empty lists.','Shared standard/oracle numeric lists preserve complete pure NumericField expression trees, precision/operator order, keys, missing policies, duplicate/order cases and BDS30/BDS44/identity branches.','Existing named-value, full semantic payload and complete decoder/CPR theorem declarations remain unchanged; frozen adapters call the live runtime. No Float evaluator or callback boundary changed.'],limitations=['No compiler, decoder, test or profile was executed by reviewer. Linked source/C/object/native reuse requires the separate native review.','Kernel decide witnesses use permitted axioms; no axiom-free claim is made.'])
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),new_facts=len(newfacts),integrated_facts=len(facts),sha256=sha(p))))
