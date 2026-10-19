#!/usr/bin/env python3
"""Independent source/proof/integration review; read logs, do not compile."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen19');R=B/'runtime-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
initial=read(R/'source-initial.json');bit=read(B/'bit-proof/summary.json');payload=read(B/'payload-proof/summary.json');build=read(B/'integration/targeted-build.json')
assert bit['status']==payload['status']==build['status']=='passed' and build['exit_code']==0
for p,h in initial['runtime_sha256'].items():assert sha(p)==h,p
assert sha(bit['source'])==bit['source_sha256']
for p,h in payload['sources'].items():assert sha(p)==h,p
assert build['all_inputs_before']==build['all_inputs_after'] and len(build['all_inputs_after'])==192
assert build['inputs_before']==build['inputs_after'] and len(build['inputs_after'])==8
for p,h in build['all_inputs_after'].items():assert sha(p)==h,p
assert sha(B/'integration/targeted-build.log')==build['log_sha256']
for name,h in build['binary_hashes'].items():assert sha(Path('.lake/build/bin')/name)==h
allowed={'propext','Classical.choice','Quot.sound'}
def parse(log):
 facts=[]
 for name,ax in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",Path(log).read_text()):
  axioms=[x.strip() for x in ax.split(',') if x.strip()];assert set(axioms)<=allowed,(name,axioms);facts.append((name,axioms))
 assert facts;return facts
for name,h in bit['files'].items():assert sha(B/'bit-proof'/name)==h,name
bfacts=parse(B/'bit-proof/attempt-02/build.log');assert len(bfacts)==15
assert dict(bfacts)=={r['theorem']:r['axioms'] for r in bit['printed_axiom_facts']}
for attempt in payload['attempts']:assert sha(attempt['path'])==attempt['sha256']
exe=read(payload['targeted_build']);assert exe['status']=='passed' and exe['exit_code']==0
assert sha(payload['targeted_build'])==payload['targeted_build_sha256']
plog=Path(payload['targeted_build']).parent/'build.log';assert sha(plog)==payload['log_sha256'];pfacts=parse(plog)
assert dict(pfacts)=={r['name']:r['axioms'] for r in payload['printed_facts']} and len(pfacts)==214
ifacts=parse(B/'integration/targeted-build.log')
# Existing statements, including private dependency bridges, remain exact.
clean=lambda s:re.sub(r'/\-.*?\-/|--[^\n]*','',s,flags=re.S)
def statements(source):return [re.sub(r'\s+',' ',x).strip() for x in re.findall(r'(?:private\s+)?theorem\s+(.*?):=',clean(source),re.S)]
statement_counts={}
for name in ['Proofs/Decoder.lean','Proofs/AffineValue.lean','Proofs/CommBTables.lean']:
 old=subprocess.check_output(['git','show','HEAD:'+name],text=True);new=Path(name).read_text();assert statements(old)==statements(new),name;statement_counts[name]=len(statements(new))
bittext=Path('Proofs/BitExtraction.lean').read_text();payloadtext=Path('Proofs/PayloadIntegerShift.lean').read_text()
assert 'theorem bit_eq (word place : Nat)' in bittext and 'theorem grayDecode_eq (width word : Nat)' in bittext
assert 'theorem identityCode_eq (code : BitVec 13)' in bittext
assert 'theorem payloadInteger_eq (coding : Spec.PayloadCoding) (width code : Nat)' in payloadtext
assert 'Nat.and_one_is_mod, Nat.shiftRight_eq_div_pow' in bittext and 'Nat.one_shiftLeft' in payloadtext
assert 'decide +kernel' in bittext and 'decide +kernel' in payloadtext
assert not re.search(r'\b(sorry|admit|axiom|unsafe|native_decide)\b',clean(bittext+'\n'+payloadtext))
record=dict(status='passed_read_only_source_proof_and_integration_review',recorded_utc=datetime.now(timezone.utc).isoformat(),findings=[],initial_source_assessment_sha256=sha(R/'source-initial.json'),source_bindings=build['inputs_after'],all_gate_inputs_unchanged=192,all_binaries_unchanged=len(build['binary_hashes']),integrated_build_record_sha256=sha(B/'integration/targeted-build.json'),integrated_log_sha256=build['log_sha256'],helper_bit_facts=len(bfacts),targeted_bridge_facts=len(pfacts),integrated_printed_facts=len(ifacts),allowed_axioms_only=True,existing_statement_counts=statement_counts,proof_assessment=['Every natural word/index/width is quantified without validity, representability or machine-width hypothesis. Core Nat identities directly rewrite both optimized operations to the original mathematical expressions.','Identity equality covers all BitVec13 values and retains the same digit permutation/reserved-bit omission.','Signed payload equality is for every coding/width/code, including width0 truncated subtraction and codes beyond the modulus; no unintended masking introduced.','Existing Decoder, affine and Comm-B density statements remain identical. Bridges only replace lost definitional equalities with unconditional proved equalities.','Nine bit/Gray/identity and six signed/unsigned boundary witnesses use kernel evaluation, not native_decide.','Bit wrapper preflight failure and two payload/integration elaboration failures remain retained; only final successful logs are used for allowed-axiom conclusions.'],artifacts={str(p):sha(p) for p in [B/'bit-proof/summary.json',B/'payload-proof/summary.json',Path(payload['targeted_build']),plog,B/'bit-proof/attempt-02/build.log']},reviewer_sha256=sha(__file__),limits=['No proof build or native execution by this reviewer. Actual native capture is independently owned by fc005_verify; campaign/fixed gate remain separate pending evidence.'])
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':record['status'],'sha256':sha(p),'bit_facts':len(bfacts),'targeted_facts':len(pfacts),'integrated_facts':len(ifacts),'statement_counts':statement_counts}))
