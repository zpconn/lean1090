"""Independent source/proof evidence review; no build or decoder execution."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
E=Path('tests/evidence/optimization/gen5/independent-review')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
proof=read('tests/evidence/optimization/gen5/proof/build-02-result.json')
assert proof['exit_code']==0 and proof['jobs']==21
log_path='tests/evidence/optimization/gen5/proof/build-02.log';log=Path(log_path).read_text()
assert sha(log_path)==proof['log_sha256']
paths=['Impl/CommB.lean','Proofs/CommBMach.lean','Proofs/CommBTables.lean','Proofs/Decoder.lean']
sources={p:sha(p) for p in paths}
for p,h in proof['source_sha256'].items():assert sources[p]==h
lock_sha=sha('spec.lock');assert lock_sha==proof['lock_sha256']
locked={line.split('  ',1)[1]:line.split('  ',1)[0] for line in Path('spec.lock').read_text().splitlines()}
assert len(locked)==104
for p,h in locked.items():assert sha(p)==h,p
facts=re.findall(r"'Lean1090.Proofs.CommBMach.([^']+)' depends on axioms: \[([^\]]*)\]",log,re.S)
assert len(facts)==7 and {x[0] for x in facts}=={'table_size','table_get','cbMach64_eq_runtime','cbMach64_eq','zero_witness','plausibility_boundary_witness','maximal_wide_witness'}
for n,axioms in facts:assert set(x.strip() for x in axioms.split(',')) <= {'propext','Classical.choice','Quot.sound'}
impl=Path('Impl/CommB.lean').read_text();old=subprocess.check_output(['git','cat-file','blob',proof['base_commit']+':Impl/CommB.lean']).decode()
old_body='def cbMach64 (word : Nat) : Rat :=\n  Binary64.div (Binary64.mul (payloadBits word 25 10 : Rat)\n    (Binary64.literal (256 / 125))) 512'
new_body='def cbMach64 (word : Nat) : Rat :=\n  cbMachValueTable[payloadBits word 25 10]\'(by\n    simpa only [cbMachValueTable, Array.size_ofFn] using payloadBits_lt word 25 10)'
table='/-- Exact BDS60 Mach values for all 1024 ten-bit field codes. The immutable\ntable preserves literal rounding, multiplication and division in that order. -/\ndef cbMachValueTable : Array Rat := Array.ofFn fun code : Fin 1024 =>\n  Binary64.div (Binary64.mul (code.val : Rat)\n    (Binary64.literal (256 / 125))) 512\n\n'
assert old_body in old and new_body in impl and table in impl
assert impl.replace(table,'').replace(new_body,old_body)==old,'exact one-change runtime diff'
for needle in ['payloadBits word 14 10 ≤ 500 && cbMach64 word ≤ 1','cbScoreField ((value "Mach").map fun _ => cbMach64 word)','let mach := cbMach64 word']:
 assert needle in impl
assert 'cbDensityTermsFast register word' in impl and 'fun _ => cbCombinedScore register word ≥ -3' in impl
pr=Path('Proofs/CommBMach.lean').read_text()
assert 'theorem cbMach64_eq_runtime (word : Nat)' in pr and 'theorem cbMach64_eq (word : Nat)' in pr
assert 'rw [cbMach64_eq_runtime, PayloadBits.payloadBits_eq]\n  rfl' in pr
assert not any(re.search(r'\b'+w+r'\b',pr) for w in ['sorry','admit','axiom','native_decide','unsafe'])
assert 'exact CommBMach.cbMach64_eq word' in Path('Proofs/Decoder.lean').read_text()
assert 'CommBMach.cbMach64_eq_runtime' in Path('Proofs/CommBTables.lean').read_text()
assert 'Impl.decodeBDS register word' in Path('Tests/CommBDifferential.lean').read_text()
assert 'Impl.decode' in Path('CLI/Main.lean').read_text()
out={'status':'passed_source_and_targeted_proof_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'base_commit':proof['base_commit'],'source_sha256':sources,'proof_build_log':{'path':log_path,'sha256':sha(log_path),'jobs':21,'exit_code':0},'axiom_outputs':[{'name':'Lean1090.Proofs.CommBMach.'+n,'axioms':[x.strip() for x in a.split(',')]} for n,a in facts],'frozen_files_checked':len(locked),'spec_lock_sha256':lock_sha,'findings':[],'domain_review':['The new immutable Array.ofFn covers exactly every Fin 1024 code. No message, timestamp, aircraft, validity or corpus data enters table construction.','Every entry uses software Binary64.literal(256/125), then Binary64.mul(code,literal), then Binary64.div(product,512), exactly matching the former definition. There is no replacement by rational code/250 or reassociation.','The public cbMach64 lookup index is payloadBits word 25 10; universal payloadBits_lt proves it below 1024 for every Nat word, including words wider than the ModeS frame.','table_get proves exact contents for every Fin 1024 index; cbMach64_eq_runtime and cbMach64_eq universally quantify over Nat word without validity, score or acceptance hypotheses.','Kernel-checked witnesses cover codes 0, 249/250/251 around Mach 1 and code 1023 embedded in a 130-bit natural. These supplement rather than replace the universal proof.'],'live_binding_review':['The runtime diff is exactly one new complete value table plus replacing cbMach64 body with the checked lookup; every other character of Impl.CommB is unchanged.','cbMach64 remains the public live name used by BDS60 plausibility, software density fallback and IAS/Mach penalty. Frozen direct-register and whole-message adapters continue reaching these live definitions through decodeBDS/inferCommB/Impl.decode.','The existing software fallback remains real and uses the exact table equality rather than retaining a dead old cbMach64 copy. Existing independent Mach density table is unchanged.','Runtime imports are unchanged and remain independent of Spec/Mathlib. No Float arithmetic, external primitive, unsafe access, mutable array, corpus special case or cross-message cache is added.','Decoder integration uses funext plus the new universal reference equality. CommBTables density60 proof rewrites through the runtime equality, preserving its unchanged exact statement and software fallback.'],'review_script':str(Path(__file__)),'review_script_sha256':sha(__file__),'scope':'Read-only source/diff/hash/log review. No builds, tests, decoder execution, native edits or frozen changes by reviewer.','remaining_validation':'The integrated build, generated/native code review, full gate and fresh campaign remain separate obligations; this record only confirms the targeted proof build.'}
integration=read('tests/evidence/optimization/gen5/integration/targeted-build.json')
integration_log=Path('tests/evidence/optimization/gen5/integration/targeted-build.log')
assert integration['exit_code']==0 and sha(integration_log)==integration['log_sha256']
integration_text=integration_log.read_text();assert 'Build completed successfully (3510 jobs).' in integration_text
integration_axioms=re.findall(r"'([^']+)' depends on axioms: \[([^\]]*)\]",integration_text,re.S)
for name,ax in integration_axioms:assert set(x.strip() for x in ax.split(',')) <= {'propext','Classical.choice','Quot.sound'}
assert any(n.endswith('CommBTables.density_terms_eq') for n,a in integration_axioms)
assert any(n=='Lean1090.Proofs.Refinement' for n,a in integration_axioms)
out['status']='passed_source_targeted_and_integrated_proof_review'
out['integration']={**integration,'log':str(integration_log),'axiom_outputs_checked':len(integration_axioms),'jobs':3510}
out['remaining_validation']='Native code review, full gate and fresh campaign remain separate obligations.'
p=E/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(sha(p))
