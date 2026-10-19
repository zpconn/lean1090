import os,sys
sys.dont_write_bytecode=True
os.environ["PYTHONDONTWRITEBYTECODE"]="1"
"""Read-only replay of independent native/proof evidence; no native execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, re

N = Path('tests/evidence/optimization/gen14/native-review')
R = N.parent / 'independent-review'
P = 'lp_lean1090_Lean1090_Impl_'
load = lambda p: json.loads(Path(p).read_text())
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
review = load(N/'review.json')
inspection = load(N/'inspection-inputs.json')
proof = load(N/'source-proof-review.json')
supplement = load(N/'integration-proof-review.json')
integration = load(R/'integration-review.json')
assert review['status'] == proof['status'] == supplement['status'] == 'passed'
assert review['findings'] == proof['findings'] == supplement['findings'] == []
assert len(review['checks']) == 31 and all(review['checks'].values())
assert review['bds60_ratio_enclosure_live_path_verified']
assert len(inspection['inputs']) == 143 and len(review['files']) == 439
for path, item in inspection['inputs'].items():
    assert sha(path) == item['sha256'] and Path(path).stat().st_size == item['bytes'], path
for path, relative in inspection['retained'].items():
    assert (N/relative).read_bytes() == Path(path).read_bytes(), path
for path, item in review['files'].items():
    assert sha(N/path) == item['sha256'] and (N/path).stat().st_size == item['bytes'], path
extras = {'review.json', 'validate.stdout', 'validate.stderr'}
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()} == set(review['files']) | extras
assert (N/'validate.stderr').read_bytes() == b''
assert review['source_proof_review_sha256'] == sha(N/'source-proof-review.json')
assert review['integration_proof_review_sha256'] == sha(N/'integration-proof-review.json')
assert supplement['source_proof_review_sha256'] == sha(N/'source-proof-review.json')
assert supplement['sources'] == integration['final_source_sha256']
assert proof['sources'] == {p:h for p,h in supplement['sources'].items() if p != 'Proofs/Decoder.lean'}
for p,item in proof['inputs'].items():
    assert sha(p) == item['sha256'] and Path(p).stat().st_size == item['bytes']
assert len(proof['helper_facts']) == 7 and proof['kernel_witness_theorems'] == 6
allowed = {'propext', 'Classical.choice', 'Quot.sound'}
for item in proof['helper_facts']: assert set(item['axioms']) <= allowed
assert supplement['integrated_allowed_axiom_facts'] == len(integration['all_successful_printed_axioms']) == 143
assert {x['name']:x['axioms'] for x in supplement['integrated_facts']} == integration['all_successful_printed_axioms']
assert supplement['integrated_build_sha256'] == sha(supplement['integrated_build_path'])
assert supplement['integrated_log_sha256'] == sha(N.parent/'integration/targeted-build.log')
for axioms in integration['all_successful_printed_axioms'].values(): assert set(axioms) <= allowed
for cmd in inspection['commands']:
    assert cmd['exit_code'] == 0 and (N/cmd['stderr']).read_bytes() == b''

# Independently traverse the retained native helper's normal-return graph.
# Calls return; both unknown branch successors are retained, with no claim
# about real frequencies. Event traces distinguish exact fast/fallback paths.
asm=(N/'binary-cbRatioOutside250800.txt').read_text()
rows=[(int(m[1],16),m[2],m[3]) for line in asm.splitlines()
      if (m:=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line))]
index={row[0]:i for i,row in enumerate(rows)}
events={}
for addr,op,arg in rows:
 if op in ['call','jmp'] and '<'+P+'Binary64_round>' in arg:events[addr]='software_round'
 if op in ['call','jmp'] and '<l_Rat_blt>' in arg:events[addr]='rounded_Rat_compare'
assert list(events.values()).count('software_round')==1 and list(events.values()).count('rounded_Rat_compare')==2
pending=[(0,())];seen=set();exits=set()
while pending:
 i,trace=pending.pop()
 if (i,trace) in seen:continue
 seen.add((i,trace));addr,op,arg=rows[i]
 if addr in events:trace+=(events[addr],)
 assert trace.count('software_round')<=1 and trace.count('rounded_Rat_compare')<=2
 if op=='ret':exits.add((trace,'ret'));continue
 if op.startswith('j'):
  m=re.fullmatch(r'([0-9a-f]+) <([^>]+)>',arg);assert m,arg
  target=int(m[1],16)
  if target in index:pending.append((index[target],trace))
  else:assert op=='jmp';exits.add((trace,m[2]))
  if op=='jmp':continue
 assert i+1<len(rows);pending.append((i+1,trace))
derived={'instruction_count':len(rows),'reachable_instructions':len({i for i,_ in seen}),
         'event_sites':{hex(a):n for a,n in events.items()},
         'normal_exits':[{'events':list(t),'target':s} for t,s in sorted(exits)]}
cfg=load(N/'ratio-native-cfg.json');assert derived=={k:cfg[k] for k in derived}
assert derived['instruction_count']==derived['reachable_instructions']==776
assert exits=={((),'ret'),(('software_round','rounded_Rat_compare'),'ret'),(('software_round','rounded_Rat_compare','rounded_Rat_compare'),'l_Rat_blt')}
calls=lambda text:re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>',text)
assert {x for x in calls(asm) if 'Binary64_' in x or 'Rat_' in x}=={P+'Binary64_round','l_Rat_blt'}
penalty_calls=calls((N/'binary-cbPenalty.txt').read_text())
assert penalty_calls.count('l_Rat_div')==penalty_calls.count(P+'cbRatioOutside250800')==1
assert penalty_calls.index('l_Rat_div')<penalty_calls.index(P+'cbRatioOutside250800')
assert penalty_calls.count(P+'cbWindPenalty50')==1
for filename in ['binary-cbScorePasses.txt','binary-cbScorePasses___lam__0___boxed.txt']:
 assert calls((N/filename).read_text()).count(P+'cbPenalty')==1
assert len(review['unchanged_native_sources'])==19
for p,item in inspection['inputs'].items(): assert sha(p) == item['sha256']
out = {'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
       'findings':[],'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),
       'integration_review_sha256':sha(R/'integration-review.json'),
       'independent_source_proof_review_sha256':sha(N/'source-proof-review.json'),
       'independent_integration_proof_review_sha256':sha(N/'integration-proof-review.json'),
       'native_checks':31,'native_inputs':143,'native_files':439,'exact_native_evidence_membership':442,
       'bds60_ratio_enclosure_live_path_verified':True,'independent_cfg':derived,
       'ratio_native_cfg_sha256':sha(N/'ratio-native-cfg.json'),'other_unchanged_native_sets':19,
       'execution_log_bindings':{str(N/n):sha(N/n) for n in extras if n!='review.json'},
       'review_script_sha256':sha(__file__),
       'limits':['Read-only replay of retained independent source/proof/native evidence. No compiler or decoder execution.',
                 'Conservative CFG includes all branch choices and treats calls as returning. No runtime frequency or zero callee-allocation inference.',
                 'Exact Rat division remains in the BDS60 caller; the uncertain helper branch invokes the original software round and comparisons. Both integer arithmetic allocation and conditional lazy scalar initialization remain. The inspected binary is the integrated CLI, not the future fresh timed worker.']}
p = R/'native-binding-review.json'; assert not p.exists()
p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'inputs':143,'files':439,'membership':442},indent=2))
