#!/usr/bin/env python3
"""Independent source and retained-kernel-evidence review of gen15."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import json,hashlib,re,difflib
O=Path(__file__).resolve().parent;B=O.parent;P=B/'proof'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def facts(s):
 return [{'name':n,'axioms':sorted(x.strip() for x in a.split(',') if x.strip())} for n,a in re.findall(r"'([^']+)' (?:depends on axioms:\s*\[([^]]*)\]|does not depend on any axioms)",s,re.S)]
def norm(s):return ''.join(s.split())
def main():
 assert not (O/'source-proof-review.json').exists()
 summary=read(P/'summary.json');assert summary['status']=='passed' and len(summary['attempts'])==1
 record=read(P/'build-01.json');log=(P/'build-01.log').read_text();assert record['exit_code']==0 and 'Build completed successfully (12 jobs).' in log
 assert sha(P/'build-01.log')==record['log_sha256']==summary['attempts'][0]['log_sha256']
 assert sha(P/'build-01.json')==summary['attempts'][0]['sha256']
 assert record['sources_before']==record['sources_after']==summary['sources']
 for path,digest in summary['sources'].items():assert sha(path)==digest
 for path,digest in summary['files'].items():assert sha(path)==digest
 old=(O/'before/Impl/CommB.lean').read_text();source=Path('Impl/CommB.lean').read_text();proof=Path('Proofs/CommBConstant.lean').read_text()
 assert sha(P/'before-Impl-CommB.lean')==sha(O/'before/Impl/CommB.lean')
 start=source.index('/-- The exclusive upper bound for a 56-bit Comm-B payload.')
 end=source.index('-- Initial algorithm: Spec/CommB.lean:240.',start)
 added=source[start:end]
 assert '@[noinline] def commBPayloadLimit : Nat := 2^56' in added
 assert (source[:start]+source[end:]).replace('word < commBPayloadLimit && match register with','word < 2^56 && match register with')==old
 assert 'theorem payload_limit_eq : Impl.commBPayloadLimit = 2^56 := rfl' in proof
 assert 'theorem bdsWireValid_eq_old (register word : Nat) :' in proof
 rhs=proof.split('      (word < 2^56',1)[1].split(') := rfl',1)[0]
 rhs='word < 2^56'+rhs
 oldbody=old.split('def bdsWireValid (register word : Nat) : Bool :=',1)[1].split('-- Initial algorithm:',1)[0]
 assert norm(rhs.replace('Impl.',''))==norm(oldbody)
 assert not re.search(r'\b(sorry|admit|axiom|native_decide|bv_decide|unsafe|partial)\b|BVDecide|@\[(?:extern|implemented_by)',proof)
 fs=facts(log);assert len(fs)==6 and all(set(x['axioms'])<={'propext','Classical.choice','Quot.sound'} for x in fs)
 assert {x['name'] for x in fs}=={x['theorem'] for x in summary['axiom_facts']}
 assert proof.count('decide +kernel')==3
 assert all(s in proof for s in ('2^56 - 1','2^130 + 0x20 * 2^48','Impl.bdsWireValid 0x22','large : 2^56 ≤ word'))
 diff=''.join(difflib.unified_diff(old.splitlines(True),source.splitlines(True),fromfile='gen14/Impl/CommB.lean',tofile='gen15/Impl/CommB.lean'))
 (O/'verified-before-after.diff').write_text(diff)
 inputs={str(p):{'sha256':sha(p),'bytes':Path(p).stat().st_size} for p in [*map(Path,summary['sources']),P/'summary.json',P/'build-01.json',P/'build-01.log',P/'before-Impl-CommB.lean',P/'runtime.diff',O/'before/Impl/CommB.lean',O/'before-native-inventory.json']}
 for path in inputs:
  dest=O/'proof-inputs'/Path(path);dest.parent.mkdir(parents=True,exist_ok=True);assert not dest.exists();dest.write_bytes(Path(path).read_bytes())
 out={'status':'passed','findings':[],'reviewer':'/root/cost_analysis; independent of helper/runtime author','sources':summary['sources'],'inputs':inputs,'unconditional_all_register_word_equality_verified':True,'exact_runtime_scope_reconstructed':True,'axiom_facts':fs,'kernel_witness_theorems':3,'mathematical_assessment':'The only runtime change is a transparent noinline zero-argument Nat definition exactly equal to 2^56 and substitution of that definition in the existing guard. The full original branch body is textually recovered after unfolding the name; the universal theorem is rfl for every Nat register and word, with no width or validity assumption. Unsupported registers and oversized inputs remain covered. The separate rejection theorem adds only the natural bound it needs. Three kernel witnesses exercise range endpoints, a 130-bit word, accepted and unsupported headers. No primitive, state, approximate arithmetic or theorem change.','retained_author_diff_note':'The author runtime.diff is empty because the file was already staged before that capture. It is preserved unchanged and is not scope evidence; verified-before-after.diff is independently derived from the saved gen14 source blob and the current source.','verified_diff_sha256':sha(O/'verified-before-after.diff'),'script_sha256':sha(__file__),'limits':'Mathematical/source assessment and replay of retained proof-build hashes/axioms only; no independent build. Native global initialization is checked separately after successful integration.'}
 q=O/'source-proof-review.json';q.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':'passed','review_sha256':sha(q),'sources':len(inputs),'axiom_facts':len(fs),'diff_sha256':out['verified_diff_sha256']}))
if __name__=='__main__':main()
