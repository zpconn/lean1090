"""Read-only gen6 exact-source/proof review; no builds or decoder runs."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
E=Path('tests/evidence/optimization/gen6'); O=E/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
build=load(E/'proof/build-01-result.json');summary=load(E/'proof/summary.json')
assert build['exit_code']==0 and summary['build_exit_code']==0 and summary['jobs']==16
sources={p:sha(p) for p in ['Impl/Message.lean','Proofs/SyndromeReuse.lean','Proofs/Decoder.lean']}
for p,h in summary['sources'].items():assert sources[p]==h==build['source_sha256'][p]
log=Path(summary['build_log']).read_text();assert sha(summary['build_log'])==summary['build_log_sha256']
assert 'Build completed successfully (16 jobs).' in log
axioms=re.findall(r"'Lean1090.Proofs.SyndromeReuse.([^']+)' depends on axioms: \[([^\]]*)\]",log,re.S)
assert len(axioms)==10
for n,a in axioms:assert set(x.strip() for x in a.split(',')) <= {'propext','Classical.choice','Quot.sound'}
base=build['base_commit']; old=subprocess.check_output(['git','cat-file','blob',base+':Impl/Message.lean']).decode(); new=Path('Impl/Message.lean').read_text()
def definitions(text):
 return {m[1]:m[0].strip() for m in re.finditer(r'^def (\w+)[\s\S]*?(?=^/--|^-- Initial|^end Lean1090|\Z)',text,re.M)}
a,b=definitions(old),definitions(new)
assert set(b)==set(a)|{'frameAcceptedWithSyndrome','frameAddressWithSyndrome','reportWithSyndrome'}
for name in set(a)-{'frameAccepted','frameAddress','report','decode'}:assert a[name]==b[name],name
assert b['frameAcceptedWithSyndrome']==a['frameAccepted'].replace('def frameAccepted (f : Frame)', 'def frameAcceptedWithSyndrome (f : Frame) (syndrome : BitVec 24)').replace('(frameSyndrome f)','syndrome').replace('frameSyndrome f','syndrome')
assert b['frameAddressWithSyndrome']==a['frameAddress'].replace('def frameAddress (f : Frame)', 'def frameAddressWithSyndrome (f : Frame) (syndrome : BitVec 24)').replace('(frameSyndrome f)','syndrome').replace('frameSyndrome f','syndrome')
assert b['reportWithSyndrome']==a['report'].replace('def report (f : Frame)', 'def reportWithSyndrome (f : Frame) (syndrome : BitVec 24)').replace('(frameSyndrome f)','syndrome').replace('frameSyndrome f','syndrome').replace('frameAddress f','frameAddressWithSyndrome f syndrome')
for name,typ in [('frameAccepted','Bool'),('frameAddress','Option (BitVec 24)'),('report','Report')]:
 assert b[name]==f'def {name} (f : Frame) : {typ} :=\n  {name}WithSyndrome f (frameSyndrome f)'
assert b['decode']=='''def decode (bytes : List UInt8) : Option Message := do
  let f ← decodeFrame bytes
  let syndrome := frameSyndrome f
  if frameAcceptedWithSyndrome f syndrome then some ⟨f, reportWithSyndrome f syndrome⟩ else none'''
assert b['decode'].count('frameSyndrome')==1 and b['reportWithSyndrome'].count('frameCommB f')==2
assert [x for x in new.splitlines() if x.startswith('import ')]==[x for x in old.splitlines() if x.startswith('import ')]
proof=Path('Proofs/SyndromeReuse.lean').read_text()
assert proof.count(':= rfl')==8 and proof.count('decide +kernel')==2
assert not any(re.search(r'\b'+x+r'\b',proof) for x in ['sorry','admit','axiom','native_decide','unsafe'])
decoder=Path('Proofs/Decoder.lean').read_text()
for name in ['frameAccepted','frameAddress','report','decode']:assert f'rw [SyndromeReuse.{name}_old]' in decoder
lock=Path('spec.lock');assert sha(lock)==build['lock_sha256']
locked={line.split('  ',1)[1]:line.split('  ',1)[0] for line in lock.read_text().splitlines()};assert len(locked)==104
for p,h in locked.items():assert sha(p)==h,p
out={'status':'passed_source_and_targeted_proof_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'base_commit':base,'source_sha256':sources,'proof_build_log':{'path':summary['build_log'],'sha256':summary['build_log_sha256'],'jobs':16,'exit_code':0},'axiom_outputs':[{'name':'Lean1090.Proofs.SyndromeReuse.'+n,'axioms':[x.strip() for x in a.split(',')]} for n,a in axioms],'frozen_files_checked':104,'spec_lock_sha256':sha(lock),'findings':[],'scope_review':['Every existing definition except frameAccepted, frameAddress, report and decode retains its exact original body; only three shared helper definitions are added. Runtime imports remain unchanged.','Each helper body exactly substitutes the provided syndrome into its former public body. Report retains both frameCommB calls and every altitude, identity, ADS-B, semantic and inference projection unchanged.','Each public standalone acceptance/address/report entry point delegates directly to the same helper used by complete decode. No legacy duplicate or frozen-adapter-only path exists.','The complete decoder binds one local frameSyndrome after decodeFrame succeeds and passes it to acceptance and report. No global state, mutable cache, corpus key or cross-message/run reuse is introduced.'],'semantics_and_domain':['All seven canonical/old-body helper equalities quantify over every Frame or byte list, without validity, length, parity, acceptance or corpus hypotheses; each proof is rfl.','DF17 still requires hard-valid ADS-B payload and zero syndrome; DF18 still ignores PI syndrome; all other frame constructors retain prior acceptance.','Announced all-call/extended addresses, missing DF19 address, AP-recovered addresses and DF11 interrogator projection retain exactly their old values.','Empty, truncated and unsupported-DF byte inputs still terminate at decodeFrame before the local syndrome binding. The pure CRC may run earlier for a parsed frame rejected later by payload validity; this evaluation-order change is explicitly documented and cannot change the Option result.','Standalone delegates can also evaluate a syndrome earlier than their old short-circuit body. They remain total and extensionally equal; this record does not claim unchanged standalone cost.','Kernel witnesses cover empty input, one-byte truncation and a complete DF17 parity failure. These supplement rather than replace the universal equalities.'],'integration_review':['Decoder rewrites each modified public function through its exact old-body theorem before reusing the frozen component refinement chain. Final integrated compilation remains separately recorded.'],'review_script':str(Path(__file__)),'review_script_sha256':sha(__file__),'limits':'Read-only source/diff/hash/log inspection only. No build, test, decoder execution, native artifact change or frozen edit. Generated-C/native call count, integrated build and complete gate remain separate obligations.'}
p=O/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(sha(p))
