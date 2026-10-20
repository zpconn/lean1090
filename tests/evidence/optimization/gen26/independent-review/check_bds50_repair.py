"""Focused proof-body repair review after the retained first full-gate failure."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
G=Path('tests/evidence/optimization/gen26');R=G/'independent-review';B=G/'bds50-integration'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 digest=sha(p);check(h is None or digest==h,'hash '+str(p));bindings[str(p)]=digest
s=load(B/'summary.json');bind(B/'summary.json','cd0c7262eb7e8c604332ba8f7493b465b2550c942e25bb7d52d43dc1a215dfe8')
before=(B/'before.lean').read_text();now=Path('Proofs/BDS50.lean').read_text()
bind(B/'before.lean',s['prior_source_sha256']);bind('Proofs/BDS50.lean',s['source_sha256'])
check(subprocess.check_output(['git','show','HEAD:Proofs/BDS50.lean']).decode()==before,'before source equals committed predecessor')
check(now.count('\n  norm_num\n')==before.count('\n  norm_num\n')+3 and now.replace('\n  norm_num\n','\n')==before,'exactly three norm_num additions and no other source edit')
headers=lambda t:dict(re.findall(r'(?m)^(?:@\[[^\n]*\]\s*)?theorem (\w+)([\s\S]*?)\s*:=',t))
a=headers(before);b=headers(now);check(a==b and len(a)==26,'all 26 theorem statements unchanged')
check(set(a)==set(s['unchanged_existing_theorem_statements']),'complete producer statement inventory')
for name in ['roll_eq','track_eq','rate_eq']:
 start=now.index('theorem '+name);end=now.find('\n@[simp]',start+1)
 check('  norm_num' in now[start:end],'normalization repair in '+name)
for p,h in s['unchanged_round_sources'].items():bind(p,h)
ex=load(B/'attempt-01/execution.json');bind(B/'attempt-01/execution.json',s['execution_sha256']);bind(B/'attempt-01/build.log',s['log_sha256']);bind(B/'run_build.py',ex['runner_sha256'])
check(ex['status']=='passed' and ex['exit_code']==0 and ex['command']==['lake','build','Proofs.BDS50'] and ex['before_hashes']==ex['after_hashes'] and ex['inputs_unchanged'],'targeted repair build passed with exact held inputs')
for p,h in ex['after_hashes'].items():bind(p,h)
log=(B/'attempt-01/build.log').read_text();rows=re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|does not depend on any axioms)",log)
facts=[{'name':n,'axioms':[x.strip() for x in raw.split(',') if x.strip()]} for n,raw in rows]
check(len(rows)==48 and facts==s['all_printed_facts'],'complete 48 printed facts including wrapped/axiom-free records')
check(all(set(f['axioms'])<={'propext','Classical.choice','Quot.sound'} for f in facts),'only permitted axioms')
for n in ['source.diff','trigger.json','trigger-gate-excerpt.log']:bind(B/n)
check(sha(B/'source.diff')==s['source_diff_sha256'] and sha(B/'trigger.json')==s['trigger_sha256'],'failure trigger and exact source diff bound')
old=load('tests/evidence/optimization/gen25/gate-evidence.json')['input_hashes_after'];delta={p for p,h in old.items() if sha(p)!=h}
check(delta=={'Impl/Binary64.lean','Proofs/Binary64Runtime.lean','Proofs/BDS50.lean'},'only three authorized correctness inputs differ')
prior=load(R/'source-proof-review.json');bind(R/'source-proof-review.json','07f8deb8d9a6b322cac34a7d6e1212bdcbd16a5453a6cd26c33ffb0115909a2b')
check(prior['all_input_refinement_verified'] and not prior['findings'],'prior round proof pass preserved')
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'checks':len(checks),'check_labels':checks,'findings':[],'bindings':bindings,'source_delta':sorted(delta),'preserved_bds50_statements':26,'printed_facts':facts,'all_input_refinement_verified':True,'assessment':'Only three proof-body norm_num steps close the concrete rational-power normalization goals exposed by the full gate. All old statements, both round source bytes, runtime behavior, frozen adapters and Float boundaries remain unchanged. The prior two-file review is preserved as historical evidence; current combined-build and preparation bindings must include this third proof file.','limitations':['No reviewer build or workload executed. New combined build and complete fixed gate remain required.']}
p=R/'bds50-repair-review.json'
with p.open('x') as f:f.write(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','checks':len(checks),'sha256':sha(p)}))
