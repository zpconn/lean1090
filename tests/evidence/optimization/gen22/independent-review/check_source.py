#!/usr/bin/env python3
"""Focused gen22 source/proof review, without a build or decoder execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib,json,re,subprocess
G=Path('tests/evidence/optimization/gen22');R=G/'independent-review'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 d=sha(p);check(h is None or d==h,'binding '+str(p));bindings[str(p)]=d;return d
parser=load(G/'parser/summary.json');raw=load(G/'raw-syndrome/summary.json');integrated=load(G/'integration/attempt-02/execution.json')
bind(G/'parser/summary.json','62fe341555b3bb001717d76236cc1b7b362b82af49393683732536b7c16654f6')
bind(G/'raw-syndrome/summary.json','bbfae6c5c5014510004e86b97cf9d954f3bf70f7c3cf8d86643d157b4c6d85e9')
bind(G/'integration/attempt-02/execution.json')
check(parser['status']==raw['status']==integrated['status']=='passed','both helpers and dependent integration passed')
check(integrated['exit_code']==0 and integrated['before']==integrated['after'],'stable integrated sources')
for p,h in integrated['after'].items():bind(p,h)
for row in parser['attempts']:
 a=G/'parser'/f"attempt-{row['attempt']:02d}"
 bind(a/'execution.json',row['execution_sha256']);bind(a/'build.log',row['log_sha256']);bind(a/'FrameWord.lean',row['proof_snapshot_sha256'])
 for p in ['Impl/Frame.lean','Impl/Message.lean']:bind(a/Path(p).name,parser['sources'][p])
for row in raw['attempts']:
 a=G/'raw-syndrome'/f"attempt-{row['attempt']:02d}"
 bind(a/'result.json',row['result_sha256']);bind(a/'build.log',row['log_sha256']);bind(a/'RawSyndromeSpec.lean',row['source_snapshot_sha256'])
for a in sorted((G/'integration').glob('attempt-*')):
 record=load(a/'execution.json');bind(a/'execution.json');bind(a/'build.log',record['log_sha256'])
 for p,h in record['before'].items():bind(a/p,h)
check([r['status'] for r in parser['attempts']]==['failed']*5+['passed'],'all five parser tactic failures retained before successful sixth attempt')
check(load(G/'raw-syndrome/attempt-01/result.json')['status']=='failed','initial Spec normalization failure retained')
check(load(G/'integration/attempt-01/execution.json')['status']=='failed','initial integration simplification failure retained')

old={}
for p in ['Impl/Frame.lean','Impl/Message.lean','Proofs/SyndromeReuse.lean','Proofs/Decoder.lean']:
 folder='parser' if p.startswith('Impl/') else 'integration'
 before=G/folder/'before'/p;bind(before);old[p]=before.read_text()
 check(before.read_bytes()==subprocess.check_output(['git','show','HEAD:'+p]),'committed original '+p)
frame=Path('Impl/Frame.lean').read_text();message=Path('Impl/Message.lean').read_text()
projection='\n/-- Public frame parsing projects the same live parser used by the full decoder. -/\ndef decodeFrame (bytes : List UInt8) : Option Frame :=\n  (decodeFrameWithWord bytes).map Prod.fst\n'
restored=frame.replace(projection,'').replace('decoder checks payload validity and applies the separately identified policies.\nThe already parsed word is returned for full-message CRC reuse. -/','decoder checks payload validity and applies the separately identified policies. -/').replace('def decodeFrameWithWord (bytes : List UInt8) : Option (Frame × Nat) := do','def decodeFrame (bytes : List UInt8) : Option Frame := do').replace('some (⟨body, parity⟩, word)','some ⟨body, parity⟩')
check(restored==old['Impl/Frame.lean'],'parser body exactly unchanged apart from paired return and live projection')
restored=message.replace('the live frame parser. The parser returns its already decoded wire word, so\nCRC does not reconstruct that word from field assignments. -/','`decodeFrame`. This changes evaluation order, not the returned value. -/').replace('let (f, word) ← decodeFrameWithWord bytes\n  let syndrome := Parity.syndrome (informationBits f.body + 24) word','let f ← decodeFrame bytes\n  let syndrome := frameSyndrome f')
check(restored==old['Impl/Message.lean'],'only main parser binding and syndrome input changed; all projections/guards/prefix and inference calls preserved')
check(frame.count('let word := bytesValue bytes')==1,'one source byte-value computation in the shared parser')
check('if bytes.length != count then none else do' in frame and frame.index('if bytes.length != count')<frame.index('let word := bytesValue bytes'),'length rejection precedes word construction')
changed=subprocess.check_output(['git','diff','HEAD','--name-only','--','Impl'],text=True).splitlines()
check(set(changed)=={'Impl/Frame.lean','Impl/Message.lean'},'exact two runtime modules changed')
headers=lambda text:dict(re.findall(r'(?m)^(?:private )?theorem (\w+)([\s\S]*?)\s*:=',text))
old_headers={}
for p in ['Proofs/SyndromeReuse.lean','Proofs/Decoder.lean']:
 a=headers(old[p]);b=headers(Path(p).read_text());check(all(b.get(n)==h for n,h in a.items()),'all '+str(len(a))+' old theorem types preserved in '+p);old_headers[p]=sorted(a)
check('exact FrameWord.decodeFrame_function_eq' in Path('Proofs/Decoder.lean').read_text(),'existing decoder parser refinement delegates to universal live-parser equality')
fp=Path('Proofs/FrameWord.lean').read_text();rp=Path('Proofs/RawSyndromeSpec.lean').read_text();sp=Path('Proofs/SyndromeReuse.lean').read_text()
check('Impl.decodeFrameWithWord bytes =\n      (Spec.decodeFrame bytes).map (fun frame => (frame, Spec.bytesValue bytes))' in fp,'paired parser theorem covers every byte list including failure')
check('Spec.decodeFrame bytes = some frame ∧ word = Spec.bytesValue bytes' in fp,'successful parse exposes both reference frame and exact complete word')
check('CRCLinear' in rp and 'ParityFacts.disjoint_append_xor 24 _ _ f.parity.isLt' in rp and 'ParityFacts.syndrome_low_word' in rp,'complete encoded-word CRC derived from disjoint concatenation, linearity and unchanged low parity')
check('BitPacking.pack_bound' in rp and 'Nat.mod_eq_of_lt bound' in rp,'complete bounded encoding removes modulo without information loss')
check('rw [← FrameRoundTrip.encode_decode bytes f decoded]' in rp,'all-byte encoder/parser roundtrip supplies raw-word equality including spare bits')
check('FrameWord.successful_parse bytes f word parsed' in sp and 'RawSyndromeSpec.syndrome_decodeFrame bytes f decoded' in sp,'integration composes independent parse and CRC lemmas')
check('cases parsed : Impl.decodeFrameWithWord bytes' in sp and 'rw [parsed_syndrome_eq bytes f word parsed]' in sp,'unconditional decoder equality covers failure and success before old acceptance/report')
# Independently enumerate the actual local Spec-only import closure.
seen=set();todo=['Proofs/RawSyndromeSpec.lean']
while todo:
 p=todo.pop()
 if p in seen:continue
 seen.add(p)
 for module in re.findall(r'^import\s+(\S+)',Path(p).read_text(),re.M):
  q=module.replace('.','/')+'.lean'
  if Path(q).is_file():todo.append(q)
check(len(seen)==29 and not any(p.startswith('Impl/') or p=='Proofs/Decoder.lean' for p in seen),'29-module reference proof closure excludes implementation and decoder refinement')
check(seen==set(raw['project_dependency_hashes']),'independent reference import closure matches retained inventory')
for p,h in raw['project_dependency_hashes'].items():bind(p,h)
# Parse actual successful Lean output, rather than trusting summary fact lists.
allowed={'propext','Classical.choice','Quot.sound'};facts={};group_counts={}
for name,path,prefix in [('parser',G/'parser/attempt-06/build.log','Lean1090.Proofs.FrameWord.'),('raw',G/'raw-syndrome/attempt-02/build.log','Lean1090.Proofs.RawSyndromeSpec.'),('integration',G/'integration/attempt-02/build.log',None)]:
 text=path.read_text();parsed={n:[v.strip() for v in a.split(',') if v.strip()] for n,a in re.findall(r"'([^']+)' depends on axioms:\s*\[([^\]]*)\]",text)}
 for n in re.findall(r"'([^']+)' does not depend on any axioms",text):parsed[n]=[]
 check(bool(parsed),'printed facts present in '+name)
 for n,a in parsed.items():check(set(a)<=allowed,'permitted axioms '+n);facts[n]=a
 group_counts[name]=sum(prefix is None or n.startswith(prefix) for n in parsed)
check(group_counts['parser']==10 and group_counts['raw']==12,'all ten parser and twelve independent CRC facts printed')
check(sum(n.startswith('Lean1090.Proofs.SyndromeReuse.') for n in facts)==11,'all eleven syndrome-sharing/refinement facts printed')
check(fp.count('decide +kernel')==6 and len(re.findall(r':= by decide\b',rp))==5,'eleven kernel boundary witnesses')
for p in integrated['after']:
 if not p.endswith('.lean'):continue
 text=Path(p).read_text()
 for token in ['sorry','admit','axiom','native_decide','unsafe','partial','panic!','get!','unreachable!','@[extern','@[implemented_by']:
  check(not re.search(r'(?<![A-Za-z_])'+re.escape(token)+r'(?![A-Za-z_])',text),'no forbidden construct '+p+' '+token)
for p in ['Bench/WholeDecoder.lean','Tests/Tracking.lean','Tests/UpstreamCorpus.lean','Tests/CommBDifferential.lean','CLI/Main.lean','Proofs/CPRTracking.lean']:
 bind(p);check(Path(p).read_bytes()==subprocess.check_output(['git','show','HEAD:'+p]),'unchanged live caller/adapter '+p)
check(Path('Bench/WholeDecoder.lean').read_text().count('let some message := Impl.decode input.bytes')==3,'frozen benchmark loops continue to call live complete decoder')
check('Impl.decodePrefix bytes' in Path('CLI/Main.lean').read_text() and 'Impl.decode bytes' in Path('Tests/UpstreamCorpus.lean').read_text(),'CLI prefix and frozen corpus remain on live decoder')
entries=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()]
check(len(entries)==104,'104 locked files')
for h,p in entries:check(sha(p)==h,'locked '+p)
for p,h in integrated['after'].items():check(sha(p)==h,'final source recheck '+p)
record=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks=checks,checks_passed=len(checks),bindings=bindings,source_hashes={p:h for p,h in integrated['after'].items() if p.endswith('.lean')},old_theorem_statements_preserved=old_headers,printed_axiom_facts=facts,printed_fact_counts=group_counts,kernel_witnesses=11,raw_word_syndrome_all_input_refinement_verified=True,source_delta=sorted(p for p in integrated['after'] if p.endswith('.lean')),reviewer_sha256=sha(__file__),assessment=['Unconditional paired-parser equality preserves every failure and every complete frame field; successful parsing returns the exact bytesValue, not a reconstructed field value.','The independent Spec-only proof uses full-byte roundtrip, exact bounded concatenation and CRC linearity. It covers short/long, DF19, Comm-D, spare and parity bits without acceptance, parity-validity or corpus assumptions.','Existing standalone frame APIs, decodePrefix, acceptance, report projections and inference calls are unchanged; all prior theorem types and frozen live adapters remain intact.','Five parser tactic failures, one independent CRC normalization failure and one integration simplification failure remain bound. Only successful build outputs establish accepted axioms.','No Float callback, trusted primitive, global state, cache, frozen change, source edit or build by reviewer.','Actual linked one-parse/raw-syndrome path and pair ownership/allocation remain separate static native checks after combined build; no throughput or allocation-free claim.'])
out=R/'source-proof-review.json';assert not out.exists();out.write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(dict(status='passed',checks=len(checks),facts=group_counts,sha256=sha(out))))
