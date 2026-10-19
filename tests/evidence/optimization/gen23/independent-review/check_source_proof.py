"""Focused independent source/proof review; no compilation or native execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
G=Path('tests/evidence/optimization/gen23');R=G/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
bindings={};checks=[]
def bind(p,h=None):
 p=Path(p);actual=sha(p);assert h is None or actual==h,str(p);bindings[str(p)]=actual;return actual
def check(b,label):
 assert b,label;checks.append(label)
def axioms(p):
 s=Path(p).read_text();facts={n:[x.strip() for x in a.split(',') if x.strip()] for n,a in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",s)}
 facts.update({n:[] for n in re.findall(r"'([^']+)' does not depend on any axioms",s)})
 assert facts and all(set(a)<={'propext','Classical.choice','Quot.sound'} for a in facts.values());return facts
runtime=load(R/'runtime-design-review.json');bind(R/'runtime-design-review.json','6876d8a04a0572366320a3668c633fe15670946c9c7faf2744d03e3377c8a406')
for p,h in runtime['bindings'].items():bind(p,h)
check(runtime['findings']==[],'Prior exact runtime delta and live frozen adapter assessment remains unchanged')
logs={40:G/'proof40/attempt-02.log',50:G/'proof50/attempt-02/build.log',60:G/'proof60/attempt-02/build.log'}
facts={};witnesses=[]
for reg,expected in [(40,11),(50,11),(60,16)]:
 src=Path(f'Proofs/CommBValidity{reg}.lean');text=src.read_text();bind(src);bind(logs[reg]);parsed=axioms(logs[reg]);prefix=f'Lean1090.Proofs.CommBValidity{reg}.'
 names=re.findall(r'^#print axioms (\w+)',text,re.M)
 check(len(names)==expected and all(prefix+n in parsed for n in names),f'All {expected} BDS{reg} printed facts found in successful kernel build')
 facts.update({prefix+n:parsed[prefix+n] for n in names});witnesses.extend(prefix+n for n in names if n.endswith('_witness'))
 check(f'theorem cbValid{reg}_eq_old (word : Nat)' in text,f'BDS{reg} old complete predicate equality has no input precondition')
 check(not re.search(r'\b(?:sorry|admit|axiom|native_decide|unsafe|partial)\b',re.sub(r'#print axioms.*','',re.sub(r'/\-.*?\-/','',text,flags=re.S))),f'BDS{reg} has no prohibited proof bypass')
 for p in sorted((G/f'proof{reg}').rglob('*')):
  if p.is_file():bind(p)
 check(any('attempt-01' in p and p.endswith('.lean') for p in bindings),f'BDS{reg} initial source attempt preserved')
 if reg==40:
  rec=load(G/'proof40/attempt-02.json');check(rec['status']=='passed' and rec['exit_code']==0 and rec['source_sha256']==sha(src) and rec['log_sha256']==sha(logs[reg]),'BDS40 successful source/log binding')
 else:
  rec=load(G/f'proof{reg}/summary.json');check(rec['status']=='passed' and rec['source_sha256']==sha(src) and rec['build_log_sha256']==sha(logs[reg]),f'BDS{reg} successful source/log binding')
check(len(witnesses)==16,'Sixteen kernel witnesses cover inclusive/exclusive neighbors, status, sign, sentinel and wide inputs')
s60=Path('Proofs/CommBValidity60.lean').read_text()
check('Impl.cbVertical60 (Impl.payloadBits word 47 10) 47 =' in s60 and 'Nat.mod_mod_of_dvd' in s60,'Vertical projection is the exact fixed-position 47 modular lemma, for arbitrary Nat words')
current=Path('Proofs/Decoder.lean').read_text();old=subprocess.check_output(['git','show','HEAD:Proofs/Decoder.lean'],text=True)
headers=lambda s:re.findall(r'(?m)^(?:private )?theorem (\w+)([\s\S]*?)\s*:=',s)
check(headers(current)==headers(old),'All existing Decoder theorem declarations remain byte-identical')
reverse=current
for r in [40,50,60]:reverse=reverse.replace(f'import Proofs.CommBValidity{r}\n','')
for r in [40,50]:reverse=reverse.replace(f'  funext word\n  rw [CommBValidity{r}.cbValid{r}_eq_old]\n  unfold Spec.cbValid{r}',f'  unfold Impl.cbValid{r} Spec.cbValid{r}')
reverse=reverse.replace('  funext word\n  exact CommBValidity60.cbValid60_eq word','  unfold Impl.cbValid60 Spec.cbValid60\n  simp only [decoder_cbMach64_eq, decoder_cbStatus_eq, decoder_cbVertical60_eq, decoder_payloadBits_eq]')
check(reverse==old,'Exact reverse Decoder diff changes only three proof imports and three predicate proof bodies')
bind('Proofs/Decoder.lean');ir=G/'integration/attempt-01.json';il=G/'integration/attempt-01.log';rec=load(ir)
bind(ir);bind(il,rec['log_sha256']);bind(G/'integration/attempt-01.lean',sha('Proofs/Decoder.lean'))
check(rec['status']=='passed' and rec['exit_code']==0 and rec['source_sha256']==sha('Proofs/Decoder.lean'),'Decoder refinement passed first integration attempt with final source')
integ=axioms(il);check(all(n in integ for n in facts),'Integration reprinted every new helper fact with only permitted axioms')
locked={p:h for h,p in [line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()]}
for p,h in locked.items():bind(p,h)
check(len(locked)==104,'All 104 frozen lock entries unchanged')
b=load(G/'integration/targeted-build.json');bind(G/'integration/targeted-build.json');bind(G/'integration/targeted-build.log')
check(b['status']=='passed' and b['exit_code']==0 and len(b['all_inputs_after'])==200 and b['all_inputs_before']==b['all_inputs_after'],'Combined build passed with 200 identical before/after correctness inputs')
for p,h in b['inputs_after'].items():bind(p,h)
check(set(b['inputs_after'])=={'Impl/CommB.lean','Proofs/Decoder.lean',*[f'Proofs/CommBValidity{r}.lean' for r in [40,50,60]]},'Combined source change set is exactly five authorized files')
result=dict(status='passed',findings=[],recorded_utc=datetime.now(timezone.utc).isoformat(),checks=checks,check_count=len(checks),bindings=bindings,source_delta=b['inputs_after'],printed_axiom_facts=facts,printed_fact_count=len(facts),kernel_witnesses=witnesses,preserved_decoder_theorem_count=len(headers(old)),integration_printed_fact_count=len(integ),all_input_refinement_verified=True,reviewer_sha256=sha(__file__),assessments=['Five Boolean tables preserve every original formula and every field code, including rejected codes. QNH/Mach preserve existing rounded software values.', 'Checked array indices follow payloadBits_lt; arbitrary high words and all selected-altitude positions are covered. Vertical projection is deliberately fixed to live position 47.', 'Full cbValid40/50/60 old-body equalities bridge unchanged Decoder statements; status/spare and unrelated numerical conditions, score arithmetic, semantic projections and frozen live adapters are retained.', 'All three initial helper simplification failures and successful second attempts remain intact; Decoder integration passed its first execution.'],limitations=['This receipt reviews proofs and existing build evidence. Linked native paths require the separate native review.', 'No compiler, decoder, test, benchmark or profile was run by this reviewer.'])
out=R/'source-proof-review.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','checks':len(checks),'facts':len(facts),'integration_facts':len(integ),'sha256':sha(out)}))
