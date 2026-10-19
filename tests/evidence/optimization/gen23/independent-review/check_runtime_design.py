"""Focused source-only design review; no build or executable invocation."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,subprocess
E=Path('tests/evidence/optimization/gen23/independent-review')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
path=Path('Impl/CommB.lean');source=path.read_text();old=subprocess.check_output(['git','show','HEAD:Impl/CommB.lean'],text=True)
assert sha(path)=='56510dc21951a14351bec8077213f1ace91717751d71dfbbd2bef10764ef3594'
# Remove exactly the three inserted table/helper groups and undo only the
# three live predicate replacements; all remaining source must be byte-identical.
reverse=source
for start,end in [('/-- The original selected-altitude plausibility decision','/-- rs1090-derived bds40.rs:'),('/-- The original roll plausibility formula','/-- rs1090-derived bds50.rs:'),('/-- The original Mach bound','/-- rs1090-derived bds60.rs:')]:
 a=reverse.index(start);b=reverse.index(end,a);reverse=reverse[:a]+reverse[b:]
reverse=reverse.replace('  cbSelectedValid40 word 2 && cbSelectedValid40 word 15 && cbQNHValid40 word','  cbSelected (payloadBits word 2 12) ≤ 50000 &&\n  cbSelected (payloadBits word 15 12) ≤ 50000 &&\n  cbQNH64 word ≥ 800 && cbQNH64 word ≤ 1200')
reverse=reverse.replace('  cbRollValid50 word &&','  (cbSigned word 2 10 * 45 / 256).abs ≤ 45 &&')
reverse=reverse.replace('  payloadBits word 14 10 ≤ 500 && cbMachValid60 word && cbVerticalValid60 word','  payloadBits word 14 10 ≤ 500 && cbMach64 word ≤ 1 &&\n  (cbVertical60 word 47).abs ≤ 6000')
assert reverse==old
snippets={
 'selected':'Array.ofFn fun code : Fin 4096 =>\n  decide (cbSelected code.val ≤ 50000)',
 'qnh':'cbQNHValueTable.map fun value =>\n  decide (value ≥ 800) && decide (value ≤ 1200)',
 'roll':'Array.ofFn fun code : Fin 1024 =>\n  decide (((payloadInteger .twosComplement 10 code.val : Rat) * 45 / 256).abs ≤ 45)',
 'mach':'cbMachValueTable.map fun value =>\n  decide (value ≤ 1)',
 'vertical':'Array.ofFn fun code : Fin 1024 =>\n  decide ((cbVertical60 code.val 47).abs ≤ 6000)'}
for text in snippets.values():assert text in source
for helper,table,position,width in [('cbSelectedValid40','cbSelectedValid40Table','start',12),('cbQNHValid40','cbQNHValid40Table','28',12),('cbRollValid50','cbRollValid50Table','2',10),('cbMachValid60','cbMachValid60Table','25',10),('cbVerticalValid60','cbVerticalValid60Table','47',10)]:
 assert f'{table}[payloadBits word {position} {width}]\'(by' in source
 assert f'using payloadBits_lt word {position} {width})' in source
 assert source.index('def '+table)<source.index('def '+helper+' (')
 # Every table constructor refers only to previously defined production formulas.
 dependency={'cbSelectedValid40Table':'cbSelected','cbQNHValid40Table':'cbQNHValueTable','cbRollValid50Table':None,'cbMachValid60Table':'cbMachValueTable','cbVerticalValid60Table':'cbVertical60'}[table]
 if dependency:assert source.index('def '+dependency+' ')<source.index('def '+table+' ')
record=read(E.parent/'runtime-build-01.json')
assert record['status']=='passed' and record['exit_code']==0 and record['command']==['lake','build','Impl.CommB']
assert record['source_sha256']==sha(path) and record['log_sha256']==sha(E.parent/'runtime-build-01.log')
locked={p:h for h,p in [line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()]}
assert len(locked)==104
adapters=['Bench/WholeDecoder.lean','Tests/CommBDifferential.lean','Tests/Tracking.lean','Tests/Upstream.lean']
for p in adapters:assert sha(p)==locked[p]
assert 'let actual := Impl.decodeBDS register word' in Path(adapters[1]).read_text()
assert Path(adapters[0]).read_text().count('let some message := Impl.decode input.bytes')==3
assert 'let m ← Impl.decode bytes' in Path(adapters[2]).read_text()
assert 'if bdsWireValid register word then' in source and 'commBCoreRegisters.contains register && bdsWireValid register word &&' in source
assert 'if commBEligible df outerAltitude register word then' in source and '(decodeBDS register word).map' in source
checks=['Exact reverse edit reproduces committed Impl.CommB byte-for-byte outside ten added definitions and three predicate replacements.','Five complete Bool tables cover 4096/4096/1024/1024/1024 field codes, including rejected codes.','QNH and Mach map existing exact software-binary64 values; original literal/operation order remains unchanged.','Selected-altitude and roll use original exact rational expressions; no threshold algebra substitutes for the formula.','Vertical-rate table applies original cbVertical60 at fixed live position 47, preserving both sign/sentinel bits.','Every helper uses payloadBits_lt for its checked array index; arbitrary natural words remain accepted as inputs.','Definitions are acyclic and depend only on format codes/unchanged production formulas.','All status/spare/IAS/groundspeed/TAS predicates and their order outside replaced predicates remain unchanged.','Semantic reporting, score arithmetic, penalties, projection helpers and existing tables are byte-identical.','Frozen direct-register, complete decode, tracking and benchmark adapters retain live production entrypoints.','Runtime module build passed once with the exact reviewed source; proof and linked native acceptance remain pending.']
result={'status':'passed_read_only_runtime_design_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'checks':checks,'check_count':len(checks),'bindings':{str(p):sha(p) for p in [path,E.parent/'runtime-build-01.json',E.parent/'runtime-build-01.log',Path('spec.lock'),*[Path(p) for p in adapters]]},'baseline_commit':subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),'baseline_source_sha256':hashlib.sha256(old.encode()).hexdigest(),'table_entries':[4096,4096,1024,1024,1024],'findings':[],'proof_obligations':['Unconditional cbValid40/50/60 equality for all Nat words; no validity, corpus or word-size premise.','Table size/get and exact helper equations; old Decoder theorem statements preserved.','Kernel witnesses at threshold neighbors, high words and sentinel/sign boundaries, using existing Binary64 bridges before reduction.'],'native_review_plan':['Bind current source/generated C/object/trace/flags and actual four built binaries after root release; compare all 22 linked sets to gen22.','Inspect actual cbValid40/50/60 calls or inlined lookups, all status/field guards and proven indices; no allocation-free claim from absent helper symbols.','Inspect all five table constructors and module initialization, complete cardinalities and persistence before timed worker loops.','Rebind old semantic/score uses and frozen live adapters; no corpus caching or new Float/trusted primitive.'],'limits':['Source-only assessment; no proof theorem or compiled native implementation is accepted by this receipt.','No build, test, decoder, benchmark or profile executed by reviewer.'],'reviewer_script_sha256':sha(__file__)}
out=E/'runtime-design-review.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':result['status'],'sha256':sha(out),'checks':len(checks)}))
