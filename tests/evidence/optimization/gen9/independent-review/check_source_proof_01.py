#!/usr/bin/env python3
"""Read-only gen9 arbitrary-domain frame-field proof review; no builds or decoder runs."""
from datetime import datetime, timezone
from pathlib import Path
import hashlib,json,re,subprocess
B=Path('tests/evidence/optimization/gen9');R=B/'independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
def old(p):return subprocess.check_output(['git','cat-file','blob','HEAD:'+p]).decode()
summary=load(B/'proof/summary.json');build=load(B/'proof/build-01-result.json')
assert summary['status']=='passed' and summary['build_attempts']==1
assert summary['targeted_command']==build['command']==['lake','build','Proofs.FrameBits']
expected={'Impl/Bits.lean':'0820f68552c9a48630fa183a00a6c9a67d4bd74209ab4d33f61886dc6e2e8d3e','Proofs/FrameBits.lean':'beb3edefe61098abc5eb7d29993fbbb71f95217d8c5f468cf5410e340217ec88'}
assert expected==summary['source_sha256']==build['source_sha256']==build['source_sha256_after']
assert build['exit_code']==summary['build_exit_code']==0
for p,d in expected.items():assert sha(p)==d,p
runtime=Path('Impl/Bits.lean').read_text();proof=Path('Proofs/FrameBits.lean').read_text()
prior=old('Impl/Bits.lean')
old_body='''def field (total start width word : Nat) : BitVec width :=
  BitVec.ofNat width (word / 2 ^ (total - start - width))'''
new_body='''def field (total start width word : Nat) : BitVec width :=
  if small : width < 64 then
    BitVec.ofNatLT (payloadWordBits (word >>> (total - start - width)).toUInt64 0 width) (by
      unfold payloadWordBits
      rw [UInt64.toNat_and, payloadWordMask_toNat width small]
      exact Nat.lt_of_le_of_lt Nat.and_le_right
        (Nat.sub_lt (Nat.two_pow_pos width) (by decide)))
  else BitVec.ofNat width (word / 2 ^ (total - start - width))'''
assert prior.count(old_body)==1
expected_text=prior.replace('import Model.Types\n','import Impl.PayloadBits\n').replace(old_body,new_body).replace('All protocol callers supply a field contained within `total` bits. -/','''All protocol callers supply a field contained within `total` bits. The native
mask follows an arbitrary natural-number shift, so unrestricted words and
truncating position subtraction preserve the reference behavior as well. -/''')
assert runtime==expected_text
assert re.findall(r'^import (.+)$',runtime,re.M)==['Impl.PayloadBits']
assert re.findall(r'^import (.+)$',proof,re.M)==['Impl.Bits','Spec.Bits','Proofs.PayloadBits']
statements={}
for name in ['field_eq','field_eq_old']:
 a=proof.index('theorem '+name+' ');z=proof.index(' :=',a);statements[name]=proof[a:z]
assert statements['field_eq']=='''theorem field_eq (total start width word : Nat) :
    Impl.field total start width word = Spec.field total start width word'''
assert statements['field_eq_old']=='''theorem field_eq_old (total start width word : Nat) :
    Impl.field total start width word =
      BitVec.ofNat width (word / 2 ^ (total - start - width))'''
assert 'apply BitVec.eq_of_toNat_eq' in proof
assert 'rw [PayloadBits.payloadWordBits_eq _ 0 width (by decide) small (by omega)]' in proof
assert 'simp only [Nat.pow_zero, Nat.div_one, Nat.shiftRight_eq_div_pow]' in proof
assert '  · rfl' in proof
for path in expected:
 code=re.sub(r'/\-.*?\-/','',Path(path).read_text(),flags=re.S);code=re.sub(r'--[^\n]*','',code)
 assert not re.search(r'\b(sorry|admit|native_decide|unsafe|partial)\b|\b(panic|get|unreachable)!|@\[(implemented_by|extern)',code),path
 assert not re.search(r'^\s*axiom\s',code,re.M)
log=B/'proof/build-01.log';text=log.read_text()
assert sha(log)==summary['log_sha256']==build['log_sha256']=='cd8f47388baefd3bad54f60ff21bc8a2774ea2a03095088461ef2cde15dc1327'
assert 'Build completed successfully (8 jobs).' in text and 'error:' not in text
facts={}
for name,axioms in re.findall(r"'Lean1090.Proofs.FrameBits\.([^']+)' depends on axioms:\s*\[([^\]]*)\]",text):
 actual=sorted(x.strip() for x in axioms.split(',') if x.strip());assert set(actual)<={'propext','Classical.choice','Quot.sound'};facts[name]=actual
assert len(facts)==10 and set(facts)==set(summary['facts'])
for name,axioms in summary['facts'].items():assert facts[name]==sorted(axioms)
witnesses=sorted(n for n in facts if n.endswith('_witness'))
assert witnesses==sorted(['zero_width_witness','last_fast_width_witness','first_fallback_width_witness','wide_fallback_witness','cross_word_witness','high_shift_witness','start_underflow_witness','width_underflow_witness'])
assert proof.count('decide +kernel')==8
unchanged={}
for path in ['Impl/PayloadBits.lean','Proofs/PayloadBits.lean','Impl/Frame.lean','Impl/Message.lean','Impl/CommB.lean','Impl/Semantics.lean','Impl/Parity.lean','TRUSTED.md']:
 assert Path(path).read_text()==old(path),path;unchanged[path]=sha(path)
# Follow the project's runtime import graph, not the Spec namespace of shared model types.
graph={};todo=['Impl.Bits'];seen=set()
while todo:
 name=todo.pop()
 if name in seen:continue
 seen.add(name);path=Path(name.replace('.','/')+'.lean');assert path.exists(),name
 imports=re.findall(r'^import (.+)$',path.read_text(),re.M);graph[name]=imports
 for imp in imports:
  assert not imp.startswith(('Spec','Proofs','Mathlib')), (name,imp)
  if Path(imp.replace('.','/')+'.lean').exists():todo.append(imp)
assert graph['Impl.Bits']==['Impl.PayloadBits'] and graph['Impl.PayloadBits']==['Model.Types']
frame=Path('Impl/Frame.lean').read_text();message=Path('Impl/Message.lean').read_text()
assert 'let frame ← decodeFrame bytes' in message
assert frame.count('field width 8 80 word')==2
for marker in ['def readACAS','def readSurveillance','def decodeFrame','field width 32 56 word']:
 assert marker in frame
locked={};adapters=[]
for line in Path('spec.lock').read_text().splitlines():
 m=re.fullmatch(r'([0-9a-f]{64})\s+(.+)',line)
 if m:
  digest,path=m.groups();assert sha(path)==digest,path;locked[path]=digest
  if path.endswith('.lean') and 'Impl.' in Path(path).read_text():adapters.append(path)
assert len(locked)==104
out={'status':'passed_source_and_universal_helper_proof_review','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'source_sha256':expected,'unchanged_live_source_sha256':unchanged,'runtime_import_graph':graph,
 'proof_summary_sha256':sha(B/'proof/summary.json'),'successful_helper_build':{'manifest':str(B/'proof/build-01-result.json'),'manifest_sha256':sha(B/'proof/build-01-result.json'),'log':str(log),'log_sha256':sha(log),'exit_code':0,'jobs':8},
 'printed_axioms':facts,'universal_statements':statements,'witnesses':witnesses,
 'frozen_file_hashes_checked':len(locked),'frozen_adapter_sources_checked':adapters,'review_script_sha256':sha(__file__),'findings':[],
 'reasoning':[
 'Both equality statements quantify arbitrary Nat total, start, width and word with no layout, bounded-word, byte-length or decoder-acceptance premise. The old-body equality is exactly the frozen Spec.field formula.',
 'For width below 64, the full arbitrary-precision Nat is shifted by the original left-associated truncating subtraction total - start - width before conversion to UInt64. This preserves fields crossing bit 64 and shifts beyond 64; conversion before this shift would not.',
 'The reused machine helper is instantiated with native shift zero. The only other native shift is the mask width, proved below 64, so native modulo-64 shift counts cannot change the intended result.',
 'The core-only mask lemma establishes the exact mask 2^width - 1, including width zero; Nat.and_le_right gives the strict BitVec bound. BitVec.ofNatLT introduces no additional modulo computation in its source body.',
 'The refinement compares BitVec.toNat, instantiates the existing general helper theorem on the already-shifted arbitrary Nat at shift zero, then uses Nat.shiftRight_eq_div_pow. Widths at least 64 use the old constructor/division/power expression unchanged.',
 'Eight kernel witnesses cover widths 0, 63, 64 and 80, a field crossing bit 64, shift 242, oversized start and width subtraction underflow. They supplement the unrestricted equality rather than limiting it.',
 'Only the field body/docstring and a cycle-free runtime import changed. bytesValue, frameBytes, packFields, frame parsing, CRC, payload extraction, inference and semantic projections are unchanged. DF19 and DF24-31 continue to use the live wide fallback for their 80-bit fields.',
 'decode reaches the unchanged decodeFrame and its readACAS/readSurveillance/public field calls. No legacy adapter-specific copy, corpus condition, memoization, new table, trusted primitive or frozen change is introduced.'
 ],'limits':['Read-only source and completed owner build/axiom review; no compiler, decoder, test, profiler or benchmark executed by this reviewer.','Integrated decoder refinement, generated-C/native path binding and complete fixed/fresh gates are separate checks.','No performance improvement is claimed before the fresh committed benchmark.']}
p=R/'source-proof-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'status':out['status'],'sha256':sha(p),'axiom_facts':len(facts),'witnesses':len(witnesses),'frozen_hashes':len(locked)},indent=2))
