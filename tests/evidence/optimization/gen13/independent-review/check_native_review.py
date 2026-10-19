"""Read-only replay of independent native/proof evidence; no native execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, re

N = Path('tests/evidence/optimization/gen13/native-review')
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
assert len(review['checks']) == 35 and all(review['checks'].values())
assert review['bds50_wind_penalty_live_path_verified']
assert len(inspection['inputs']) == 142 and len(review['files']) == 347
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
assert len(proof['helper_facts']) == 11 and proof['kernel_witness_theorems'] == 6
allowed = {'propext', 'Classical.choice', 'Quot.sound'}
for item in proof['helper_facts']: assert set(item['axioms']) <= allowed
assert supplement['integrated_allowed_axiom_facts'] == len(integration['all_successful_printed_axioms']) == 136
assert {x['name']:x['axioms'] for x in supplement['integrated_facts']} == integration['all_successful_printed_axioms']
assert supplement['integrated_build_sha256'] == sha(supplement['integrated_build_path'])
assert supplement['integrated_log_sha256'] == sha(N.parent/'integration/targeted-build.log')
for axioms in integration['all_successful_printed_axioms'].values(): assert set(axioms) <= allowed
for cmd in inspection['commands']:
    assert cmd['exit_code'] == 0 and (N/cmd['stderr']).read_bytes() == b''

# Derive field sites and table-load sites from the retained actual instructions,
# then independently traverse all branch choices, treating calls as returning.
asm = (N/'binary-cbWindPenalty50.txt').read_text()
rows = [(int(m[1],16),m[2],m[3]) for line in asm.splitlines()
        if (m := re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line))]
index = {row[0]:i for i,row in enumerate(rows)}
fields = [i for i,(_,op,arg) in enumerate(rows) if op == 'call' and '<'+P+'payloadBits>' in arg]
assert len(fields) == 4
events = {}
for i,name,start,width in zip(fields, ['status46','status24','tas47','gs25'], [46,24,47,25], [1,1,10,10]):
    context = [(op,arg) for _,op,arg in rows[max(0,i-4):i]]
    assert ('mov',f'$0x{start*2+1:x},%esi') in context
    assert ('mov',f'$0x{width*2+1:x},%edx') in context
    events[rows[i][0]] = name
loads = [addr for addr,op,arg in rows if op == 'mov' and arg.startswith('0x18(%r15,%rcx,4),')]
assert len(loads) == 1
events[loads[0]] = 'table_load'
pending = [(0,())]; seen = set(); exits = set()
while pending:
    i,trace = pending.pop()
    if (i,trace) in seen: continue
    seen.add((i,trace)); addr,op,arg = rows[i]
    if addr in events: trace += (events[addr],)
    assert len(trace) <= 5
    if op == 'ret': exits.add((trace,'ret')); continue
    if op.startswith('j'):
        m = re.fullmatch(r'([0-9a-f]+) <([^>]+)>', arg); assert m, arg
        target = int(m[1],16)
        if target in index: pending.append((index[target],trace))
        else: assert op == 'jmp'; exits.add((trace,m[2]))
        if op == 'jmp': continue
    assert i+1 < len(rows)
    pending.append((i+1,trace))
derived = {'instruction_count':len(rows), 'reachable_instructions':len({i for i,_ in seen}),
           'event_sites':{hex(a):n for a,n in events.items()},
           'normal_exits':[{'events':list(t),'target':s} for t,s in sorted(exits)]}
cfg = load(N/'wind-native-cfg.json')
assert derived == {k:cfg[k] for k in derived}
assert derived['instruction_count'] == derived['reachable_instructions'] == 197
assert {trace for trace,_ in exits} == {('status46',),('status46','status24'),('status46','status24','tas47','gs25','table_load')}
calls = lambda text: re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>',text)
assert not any(any(x in name for x in ['Binary64_', 'Rat_', 'Array_ofFn']) for name in calls(asm))
ordered = ['l_Rat_sub','l_Rat_mul',P+'Binary64_round','l_Rat_abs',P+'Binary64_div',P+'Binary64_sub']
assert [x for x in calls((N/'binary-cbWindPenaltyTable___lam__0.txt').read_text()) if x in ordered] == ordered
assert calls((N/'binary-cbPenalty.txt').read_text()).count(P+'cbWindPenalty50') == 1
for filename in ['binary-cbScorePasses.txt','binary-cbScorePasses___lam__0___boxed.txt']:
    assert calls((N/filename).read_text()).count(P+'cbPenalty') == 1
assert len(review['unchanged_native_sources']) == 19
for p,item in inspection['inputs'].items(): assert sha(p) == item['sha256']
out = {'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
       'findings':[],'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),
       'integration_review_sha256':sha(R/'integration-review.json'),
       'independent_source_proof_review_sha256':sha(N/'source-proof-review.json'),
       'independent_integration_proof_review_sha256':sha(N/'integration-proof-review.json'),
       'native_checks':35,'native_inputs':142,'native_files':347,'exact_native_evidence_membership':350,
       'bds50_wind_penalty_live_path_verified':True,'independent_cfg':derived,
       'wind_native_cfg_sha256':sha(N/'wind-native-cfg.json'),'other_unchanged_native_sets':19,
       'execution_log_bindings':{str(N/n):sha(N/n) for n in extras if n!='review.json'},
       'review_script_sha256':sha(__file__),
       'limits':['Read-only replay of retained independent source/proof/native evidence. No compiler or decoder execution.',
                 'Conservative CFG includes all branch choices and treats calls as returning. No runtime frequency or zero callee-allocation inference.',
                 'Exact software arithmetic remains in eager complete table initialization and in unaffected turn/BDS60 paths. The inspected binary is the integrated CLI, not the future fresh timed worker.']}
p = R/'native-binding-review.json'; assert not p.exists()
p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'inputs':142,'files':347,'membership':350},indent=2))
