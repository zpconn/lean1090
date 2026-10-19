#!/usr/bin/env python3
"""Independent runtime/fold/composition source review; no build or native work."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, re, subprocess
B = Path('tests/evidence/optimization/gen20')
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
read = lambda p: json.loads(Path(p).read_text())
checks = []
def check(value, label):
    assert value, label
    checks.append(label)
def facts(path, prefix):
    values = {name: [] if empty else [x.strip() for x in axes.split(',') if x.strip()]
        for name, axes, empty in re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^\]]*)\]|(does not depend on any axioms))", Path(path).read_text())
        if name.startswith(prefix)}
    check(all(set(a) <= {'propext','Classical.choice','Quot.sound'} for a in values.values()), 'permitted axioms '+prefix)
    return values
runtime = Path('Impl/Parity.lean').read_text()
before = (B/'runtime-preparation/Parity-before.lean').read_text()
rebuilt = runtime
start = rebuilt.index('/-- Eight exact MSB-first remainder updates')
end = rebuilt.index('-- Initial algorithm: Spec/Parity.lean:25.', start)
rebuilt = rebuilt[:start] + rebuilt[end:]
start = rebuilt.index('/-- Process complete cached bytes')
end = rebuilt.index('-- Initial algorithm: Spec/Parity.lean:31.', start)
rebuilt = rebuilt[:start] + rebuilt[end:]
rebuilt = rebuilt.replace('def syndromeBits (width word : Nat)', 'def syndrome (width word : Nat)')
check(rebuilt == before, 'removing new byte helpers/guard and reversing syndrome rename restores original runtime bytes')
changed = subprocess.check_output(['git','diff','HEAD','--name-only','--','Impl']).decode().splitlines()
check(changed == ['Impl/Parity.lean'], 'exactly one runtime source changed')
byte_body = runtime[runtime.index('@[inline] def byteStep'):runtime.index('/-- Shift an aligned byte')]
check(re.findall(r'wordBit byte ([0-9]+)', byte_body) == [str(n) for n in range(7,-1,-1)], 'eight explicit updates in decreasing bit order')
check('if width ≤ 128 ∧ width % 8 = 0 then syndromeBytes (width / 8) word' in runtime and 'else syndromeBits width word' in runtime, 'public guard restricts cache and retains all-width bit fallback')
check('8 * (byteCount - 1 - i)' in runtime and 'Nat' in runtime, 'byte loop uses decreasing aligned offsets')
word = Path('Proofs/ParityWord.lean').read_text()
restored = word.replace('import Proofs.ParityByte\n','').replace('  rw [ParityByte.syndrome_eq_bits]\n  unfold Impl.Parity.syndromeBits Spec.Parity.syndrome','  unfold Impl.Parity.syndrome Spec.Parity.syndrome')
check(restored == (B/'byte-integration/before/ParityWord.lean').read_text(), 'all existing ParityWord statements and residual proofs byte-identical')
fold = read(B/'fold-proof/summary.json'); integration = read(B/'byte-integration/summary.json')
check(fold['status'] == integration['status'] == 'passed', 'helper and composition targeted builds passed')
check(sha('Proofs/FoldBlocks.lean') == fold['source_sha256'], 'stable fold source')
fold_axioms = facts(B/'fold-proof/attempt-02/build.log','Lean1090.Proofs.FoldBlocks.')
check(fold_axioms == fold['printed_axioms'] and len(fold_axioms) == 3, 'all fold facts and core-only witnesses bound')
check(Path('Proofs/FoldBlocks.lean').read_text().startswith('import Init.Data.Nat.Fold\n'), 'fold theorem uses core dependency')
for p,h in integration['source_hashes'].items(): check(sha(p) == h, 'stable integrated source '+p)
log = B/'byte-integration/attempt-01/build.log'
check(sha(log) == integration['targeted_log_sha256'], 'composition build log bound')
parsed = facts(log,'Lean1090.Proofs.ParityByte.') | facts(log,'Lean1090.Proofs.ParityWord.')
check(parsed == integration['printed_facts'] and len(parsed) == 17, 'all 17 composition/unchanged-refinement facts bound')
check(integration['kernel_witness_widths'] == [0,7,8,56,64,112,120,128,129], 'boundary witness inventory')
for p in ['Proofs/FoldBlocks.lean','Proofs/ParityByte.lean','Proofs/ParityWord.lean','Impl/Parity.lean']:
    check(not re.search(r'\b(sorry|admit|native_decide|unsafe)\b|^\s*axiom\s',Path(p).read_text(),re.M), 'no forbidden proof escape '+p)
for path,terms in {'Impl/Message.lean':['Parity.checksum','let syndrome := frameSyndrome f'], 'Bench/WholeDecoder.lean':['Impl.decode'], 'Tests/Upstream.lean':['Impl.Parity.syndrome']}.items():
    check(all(t in Path(path).read_text() for t in terms), 'live public caller '+path)
lock = [line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()]
check(len(lock) == 104, '104 locked members')
for digest,path in lock:check(sha(path)==digest,'locked '+path)
paths = [Path(p) for p in ['Impl/Parity.lean','Proofs/FoldBlocks.lean','Proofs/ParityByte.lean','Proofs/ParityWord.lean','Proofs/ParityByteBits.lean','spec.lock','Impl/Message.lean','Bench/WholeDecoder.lean','Tests/Upstream.lean']]
paths += [B/p for p in ['runtime-preparation/Parity-before.lean','runtime-preparation/Parity-after-initial.lean','runtime-preparation/initial-build.json','fold-proof/summary.json','fold-proof/attempt-02/build.log','byte-bits-proof/summary.json','byte-integration/summary.json','byte-integration/attempt-01/build.log','byte-integration/attempt-01/execution.json','byte-integration/integration.diff','byte-integration/before/ParityWord.lean']]
record = {'status':'passed_independent_source_and_build_evidence_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks':checks,'checks_passed':len(checks),'bindings':{str(p):sha(p) for p in paths},'reviewer_script_sha256':sha(__file__),'fold_facts':fold_axioms,'composition_and_existing_facts':parsed,'assessment':['The core fold theorem is universal in accumulator, transition and both dimensions; zero dimensions and an order-sensitive witness are retained.','For i < byteCount ≤16 and j <8, the composition establishes the aligned offset and cache bound, then proves 8*(byteCount-1-i)+(7-j) = 8*byteCount-1-(8*i+j). No input word bound is introduced.','The public syndrome theorem removes the byte guard for all Nat widths/words by exact division/remainder identity; non-byte and above-cache widths retain the complete original body.','Every existing ParityWord theorem statement is unchanged; the Spec recurrence proof now composes the new public equality. Checksum, message syndrome sharing and frozen adapters still call the live public entrypoint.'],'authorship_limit':'This reviewer authored ParityByteBits and does not claim independent review of that module; its source/build binding is retained as a dependency. Root separately reviews its mathematical content.','native_limit':'No build, decoder, benchmark or native inspection executed by this source review; combined linked-native validation follows root release.'}
out=B/'independent-review/source-proof-review.json';assert not out.exists();out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':record['status'],'sha256':sha(out),'checks':len(checks)}))
