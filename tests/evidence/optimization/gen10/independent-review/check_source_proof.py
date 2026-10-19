#!/usr/bin/env python3
"""Read-only universal QNH table review; no builds or runtime execution."""
from datetime import datetime,timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen10');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
summary=load(B/'proof/summary.json');build=load(B/'proof/build-01-result.json')
expected={'Impl/CommB.lean':'3cc6b80332f575bc89309bc0f83e837e14286f0cf6bd3b8d85ce75d50d30a71b','Proofs/CommBQNH.lean':'8964a05667900106dbeb69a4815f9767680eb98f5a673d696c4cf3a9821a923c'}
assert summary['status']=='passed' and len(summary['attempts'])==1
assert build['command']==summary['attempts'][0]['command']==['lake','build','Proofs.CommBQNH']
assert expected==summary['sources']==build['sources']==build['sources_after']
assert build['sources_unchanged'] and build['exit_code']==summary['attempts'][0]['exit_code']==0
for p,d in expected.items():assert sha(p)==d,p
runtime=Path('Impl/CommB.lean').read_text();proof=Path('Proofs/CommBQNH.lean').read_text();prior=old('Impl/CommB.lean')
a='''/-- rs1090-derived bds40.rs: binary64 `raw * 0.1 + 800`, preserving two rounds. -/
def cbQNH64 (word : Nat) : Rat :=
  Binary64.add (Binary64.mul (payloadBits word 28 12 : Rat)
    (Binary64.literal (1 / 10))) 800'''
b='''/-- Exact BDS40 QNH values for all 4096 twelve-bit field codes. The immutable
table preserves literal rounding, multiplication and addition in that order. -/
def cbQNHValueTable : Array Rat := Array.ofFn fun code : Fin 4096 =>
  Binary64.add (Binary64.mul (code.val : Rat)
    (Binary64.literal (1 / 10))) 800

/-- rs1090-derived bds40.rs: binary64 `raw * 0.1 + 800`, preserving two rounds. -/
def cbQNH64 (word : Nat) : Rat :=
  cbQNHValueTable[payloadBits word 28 12]'(by
    simpa only [cbQNHValueTable, Array.size_ofFn] using payloadBits_lt word 28 12)'''
assert prior.count(a)==1 and runtime==prior.replace(a,b)
assert re.findall(r'^import (.+)$',proof,re.M)==['Impl.CommB','Spec.CommB','Proofs.PayloadBits']
statements={}
for name in ['table_size','table_get','cbQNH64_eq_runtime','cbQNH64_eq']:
 start=proof.index('theorem '+name+' ');end=proof.index(' :=',start);statements[name]=proof[start:end]
assert statements['cbQNH64_eq_runtime']=='''theorem cbQNH64_eq_runtime (word : Nat) :
    Impl.cbQNH64 word =
      Impl.Binary64.add (Impl.Binary64.mul (Impl.payloadBits word 28 12 : Rat)
        (Impl.Binary64.literal (1 / 10))) 800'''
assert statements['cbQNH64_eq']=='theorem cbQNH64_eq (word : Nat) : Impl.cbQNH64 word = Spec.cbQNH64 word'
assert 'rw [cbQNH64_eq_runtime, PayloadBits.payloadBits_eq]\n  rfl' in proof
for p in expected:
 code=re.sub(r'/\-.*?\-/','',Path(p).read_text(),flags=re.S);code=re.sub(r'--[^\n]*','',code)
 assert not re.search(r'\b(sorry|admit|native_decide|unsafe|partial)\b|\b(panic|get|unreachable)!|@\[(implemented_by|extern)',code),p
 assert not re.search(r'^\s*axiom\s',code,re.M)
log=B/'proof/build-01.log';text=log.read_text()
assert sha(log)==build['log_sha256']==summary['attempts'][0]['log_sha256']=='1e48dfebacea2ca03d7c80c90b9ec5ac19e047ebf2a881b7a53d2a994e7a1056'
assert 'Build completed successfully (21 jobs).' in text and 'error:' not in text and 'warning:' not in text
facts={}
for name,axioms in re.findall(r"'Lean1090.Proofs.CommBQNH\.([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'};facts[name]=actual
assert len(facts)==9 and set(facts)==set(summary['theorems'])
for name,axioms in summary['theorems'].items():assert facts[name]==sorted(x.strip() for x in axioms.split(','))
witnesses=sorted(n for n in facts if n.endswith('_witness'))
assert witnesses==sorted(['zero_witness','fractional_witness','plausibility_boundary_witness','maximal_witness','maximal_wide_witness'])
assert proof.count('decide +kernel')==5
for marker in ['(1 * 2^17)','(3999 * 2^17)','(4000 * 2^17)','(4001 * 2^17)','(4095 * 2^17)','2^130 + 4095 * 2^17','≠ (8001 / 10 : Rat)']:
 assert marker in proof,marker
unchanged={}
for p in ['Impl/Binary64.lean','Impl/PayloadBits.lean','Impl/Bits.lean','Impl/Frame.lean','Impl/Message.lean','Impl/Semantics.lean','Impl/ScoreGate.lean','Impl/CommBLayouts.lean','Impl/Parity.lean','TRUSTED.md']:
 assert Path(p).read_text()==old(p),p;unchanged[p]=sha(p)
graph={};todo=['Impl.CommB'];seen=set()
while todo:
 name=todo.pop()
 if name in seen:continue
 seen.add(name);path=Path(name.replace('.','/')+'.lean');assert path.exists(),name
 imports=re.findall(r'^import (.+)$',path.read_text(),re.M);graph[name]=imports
 for imp in imports:
  assert not imp.startswith(('Spec','Proofs','Mathlib')), (name,imp)
  if Path(imp.replace('.','/')+'.lean').exists():todo.append(imp)
for marker in ['cbQNH64 word ≥ 800 && cbQNH64 word ≤ 1200','cbScoreField ((value "barometric_setting").map fun _ => cbQNH64 word)','(fun _ => cbCombinedScore register word ≥ -3)','commBCoreRegisters.contains register && bdsWireValid register word &&']:
 assert marker in runtime,marker
assert 'let f ← decodeFrame bytes' in Path('Impl/Message.lean').read_text()
assert 'let actual := Impl.decodeBDS register word' in Path('Tests/CommBDifferential.lean').read_text()
locked={};adapters=[]
for line in Path('spec.lock').read_text().splitlines():
 m=re.fullmatch(r'([0-9a-f]{64})\s+(.+)',line)
 if m:
  digest,p=m.groups();assert sha(p)==digest,p;locked[p]=digest
  if p.endswith('.lean') and 'Impl.' in Path(p).read_text():adapters.append(p)
assert len(locked)==104
out={'status':'passed_source_and_universal_helper_proof_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'source_sha256':expected,'unchanged_live_source_sha256':unchanged,'runtime_import_graph':graph,
 'proof_summary_sha256':sha(B/'proof/summary.json'),'successful_helper_build':{'manifest':str(B/'proof/build-01-result.json'),'manifest_sha256':sha(B/'proof/build-01-result.json'),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':21},
 'reviewer_attempt':1,'printed_axioms':facts,'universal_statements':statements,'witnesses':witnesses,
 'frozen_file_hashes_checked':len(locked),'frozen_adapter_sources_checked':adapters,'review_script_sha256':sha(__file__),'findings':[],
 'reasoning':[
 'The global immutable Array.ofFn table contains exactly all 4096 twelve-bit codes, including codes above the receiver plausibility limit. The only key is the unchanged extraction payloadBits word 28 12.',
 'Each entry evaluates the software Binary64 literal 1/10, multiplication by the code and addition of 800 in exactly the original order. It preserves literal rounding and the two arithmetic rounds; it does not replace these with one rational affine calculation or hardware floating point.',
 'Both runtime and frozen-reference equalities quantify every Nat payload with no validity, bounded-word, score, plausibility, field-status or corpus hypothesis. Checked indexing uses the universal payloadBits_lt bound, so arbitrary over-wide Nat words are covered.',
 'The lookup equality simplifies Array.ofFn/get for an arbitrary code, then the frozen-reference equality rewrites the existing all-input payload extraction refinement. No code enumeration, acceptance test or decoder hypothesis appears in the proof.',
 'Five kernel witnesses cover the zero code at 800, a fractional result which explicitly differs from decimal 800.1, codes 3999/4000/4001 around the inclusive 1200 limit, maximum code 4095 and a payload with bit 130 set. These supplement the universal equalities.',
 'The entire runtime diff is exactly the immutable value-table definition and cbQNH64 lookup. Existing density score tables, field layouts, status/sentinel checks, bounds, penalties, score order, selection strategy and semantic presentation are byte-identical.',
 'Existing cbValid40 checks and the full software cbDensityTerms fallback still call the same public cbQNH64, which now reads this complete table. Frozen decodeBDS/semantic/whole-message adapters continue through the live shared validation/inference path; there is no separate legacy copy.',
 'The runtime transitive local import graph remains Model/Impl/Std only, and all 104 frozen hashes and TRUSTED.md remain unchanged. No new primitive, corpus data dependency or message cache is present.'
 ],'limits':['Read-only source and completed owner proof-build/axiom review; no compiler, decoder, test, profiler or benchmark executed by this reviewer.','Integrated refinement, generated-C/native binding and full fixed/fresh campaigns are separate checks.','No timing or speedup is claimed.']}
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'axiom_facts':len(facts),'witnesses':len(witnesses),'frozen_hashes':len(locked)},indent=2))
