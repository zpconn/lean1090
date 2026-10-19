import os,sys
sys.dont_write_bytecode=True
os.environ["PYTHONDONTWRITEBYTECODE"]="1"
"""Read-only replay of independent native/proof evidence; no native execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, re

N = Path('tests/evidence/optimization/gen15/native-review')
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
assert len(review['checks']) == 30 and all(review['checks'].values())
assert review['commb_payload_limit_live_path_verified']
assert len(inspection['inputs']) == 144 and len(review['files']) == 460
for path, item in inspection['inputs'].items():
    assert sha(path) == item['sha256'] and Path(path).stat().st_size == item['bytes'], path
for path, relative in inspection['retained'].items():
    assert (N/relative).read_bytes() == Path(path).read_bytes(), path
for path, item in review['files'].items():
    assert sha(N/path) == item['sha256'] and (N/path).stat().st_size == item['bytes'], path
extras = {'review.json', 'validate.stdout', 'validate.stderr', 'validation-attempt-01/validate.stdout', 'validation-attempt-01/validate.stderr'}
assert {str(p.relative_to(N)) for p in N.rglob('*') if p.is_file()} == set(review['files']) | extras
assert (N/'validate.stderr').read_bytes() == b''
assert review['source_proof_review_sha256'] == sha(N/'source-proof-review.json')
assert review['integration_proof_review_sha256'] == sha(N/'integration-proof-review.json')
assert supplement['source_proof_review_sha256'] == sha(N/'source-proof-review.json')
assert supplement['sources'] == integration['final_source_sha256']
assert proof['sources'] == {p:h for p,h in supplement['sources'].items() if p != 'Proofs/Decoder.lean'}
for p,item in proof['inputs'].items():
    assert sha(p) == item['sha256'] and Path(p).stat().st_size == item['bytes']
assert len(proof['axiom_facts']) == 6 and proof['kernel_witness_theorems'] == 3
allowed = {'propext', 'Classical.choice', 'Quot.sound'}
for item in proof['axiom_facts']: assert set(item['axioms']) <= allowed
assert supplement['integrated_allowed_axiom_facts'] == len(integration['all_successful_printed_axioms']) == 149
assert {x['name']:x['axioms'] for x in supplement['integrated_facts']} == integration['all_successful_printed_axioms']
assert supplement['integrated_build_sha256'] == sha(supplement['integrated_build_path'])
assert supplement['integrated_log_sha256'] == sha(N.parent/'integration/targeted-build.log')
for axioms in integration['all_successful_printed_axioms'].values(): assert set(axioms) <= allowed
for cmd in inspection['commands']:
    assert cmd['exit_code'] == 0 and (N/cmd['stderr']).read_bytes() == b''

# Independently read the actual ELF literal bytes and the retained native
# initializer data flow, without executing the binary or calling a profiler.
import struct
constant=load(N/'constant-path-capture.json')
assert constant['status']=='passed' and constant['all_binary_bytes_unchanged']
assert sha(N/'constant-path-capture.json')==review['constant_path_capture_sha256']=='41bb77caa635146dc1bf6b23cddb7d4ef3ee13f175472cd263d3c2bc1e7302fe'
assert constant['inspection_sha256']==sha(N/'inspection-inputs.json')
binary=Path('.lake/build/bin/lean1090');data=binary.read_bytes()
assert hashlib.sha256(data).hexdigest()==constant['binary_sha256']
assert data[:6]==b'\x7fELF\x02\x01'
phoff=struct.unpack_from('<Q',data,32)[0]
entsize,num=struct.unpack_from('<HH',data,54)
address=int(constant['initialization_literal_virtual_address'],16)
expected=(str(2**56)+'\0').encode();matches=[]
for i in range(num):
 typ,flags,offset,vaddr,paddr,filesz,memsz,alignment=struct.unpack_from('<IIQQQQQQ',data,phoff+i*entsize)
 if typ==1 and vaddr<=address and address+len(expected)<=vaddr+filesz:
  at=offset+address-vaddr;matches.append(data[at:at+len(expected)])
assert matches==[expected] and expected.hex()==constant['literal_bytes_hex']
assert constant['literal_ascii']==str(2**56)
init=(N/'binary-initialize_lean1090_Impl_CommB.txt').read_text()
assert '\n'.join(constant['initializer_window']) in init
window=constant['initializer_window']
assert len(window)==6 and 'lea' in window[0] and 'lean_cstr_to_nat' in window[1]
assert P+'commBPayloadLimit' in window[2] and 'mov    %rax,(%rcx)' in window[3]
assert 'mov    %rax,%rdi' in window[4] and 'lean_mark_persistent' in window[5]
guard=(N/'binary-bdsWireValid.txt').read_text()
assert '<'+P+'commBPayloadLimit>' in guard and 'lean_cstr_to_nat' not in guard
rows=[(m[1],m[2],m[3]) for line in guard.splitlines() if (m:=re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)',line))]
global_index=next(i for i,row in enumerate(rows) if P+'commBPayloadLimit' in row[2])
first_branch=next(i for i,row in enumerate(rows) if row[1].startswith('j'))
assert global_index<first_branch and rows[global_index+1][1:] == ('mov','(%rax),%rax')
assert 'lean_nat_big_lt' in guard
calls=lambda text:re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>',text)
for filename in ['binary-commBCoreEligible.txt','binary-decodeBDS.txt']:
 assert calls((N/filename).read_text()).count(P+'bdsWireValid')==1
assert calls((N/'binary-commBEligible.txt').read_text()).count(P+'commBCoreEligible')==1
for filename in ['binary-cbScorePasses.txt','binary-cbScorePasses___lam__0___boxed.txt']:
 assert calls((N/filename).read_text()).count(P+'cbPenalty')==1
for command in constant['commands']:assert command['exit_code']==0 and (N/command['stderr']).read_bytes()==b''
assert len(review['unchanged_native_sources'])==19
for p,item in inspection['inputs'].items():assert sha(p)==item['sha256']
assert sha(N/'review.json')=='cd64c9e72770cb25ed9b7c52ab241dac8ba3436db961945ba5b9380f912468f8'
assert sha(N/'inspection-inputs.json')=='dfe0f86c47065b490414ce90f0927f4d84b73e99b6f905eccb6e0de2bfea4b10'
out={'status':'passed_independent_native_binding_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'findings':[],'native_review_sha256':sha(N/'review.json'),'native_inspection_sha256':sha(N/'inspection-inputs.json'),
 'integration_review_sha256':sha(R/'integration-review.json'),'independent_source_proof_review_sha256':sha(N/'source-proof-review.json'),
 'independent_integration_proof_review_sha256':sha(N/'integration-proof-review.json'),'native_checks':30,'native_inputs':144,'native_files':460,'exact_native_evidence_membership':465,
 'commb_payload_limit_live_path_verified':True,'constant_path_capture_sha256':sha(N/'constant-path-capture.json'),
 'independent_ELF_literal':{'virtual_address':hex(address),'bytes_hex':expected.hex(),'matching_load_segments':len(matches)},
 'live_guard_global_load_precedes_first_branch':True,'live_guard_callers':['commBCoreEligible','decodeBDS'],'other_unchanged_native_sets':19,
 'retained_native_reviewer_attempts':review['retained_reviewer_attempts'],'retained_source_reviewer_attempts':proof['retained_reviewer_attempts'],
 'execution_log_bindings':{str(N/n):sha(N/n) for n in extras if n!='review.json'},'review_script_sha256':sha(__file__),
 'limits':['Read-only replay of retained proof/native evidence, ELF bytes and callsite inspection; no compiler or decoder execution.',
 'Initialization still parses the exact format constant once and marks it persistent. The guard still loads/comparisons/dispatches, including arbitrary large Nat comparisons. No zero startup-cost or measured speed claim.',
 'This inspected binary is the integrated CLI, not the future freshly built timed worker. Every failed reviewer attempt remains intact.']}
p=R/'native-binding-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'inputs':144,'files':460,'membership':465},indent=2))
