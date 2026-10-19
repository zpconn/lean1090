#!/usr/bin/env python3
"""Read-only initial review of exact natural strength reduction; no proof build."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen19/runtime-review')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
strip=lambda s:re.sub(r'/\-.*?\-/|--[^\n]*','',s,flags=re.S)
changes={'Impl/Altitude.lean':[('(word / 2 ^ place) % 2','(word >>> place) &&& 1'),('(word / 2 ^ index)','(word >>> index)')],'Impl/Frame.lean':[('(code.toNat / 2^n) % 2','(code.toNat >>> n) &&& 1')],'Impl/PayloadBits.lean':[('code ≥ 2 ^ (width - 1)','code ≥ (1 : Nat) <<< (width - 1)'),('(2 ^ width : Nat)','((1 : Nat) <<< width)')]}
bindings={};before={}
for path,replacements in changes.items():
 old=subprocess.check_output(['git','show','HEAD:'+path],text=True);current=Path(path).read_text();expected=old
 for a,b in replacements:assert expected.count(a)==1,(path,a);expected=expected.replace(a,b)
 assert strip(expected)==strip(current),path
 assert not re.search(r'^import (Spec|Proofs|Mathlib)',current,re.M)
 bindings[path]=sha(path);before[path]=hashlib.sha256(old.encode()).hexdigest()
for p in ['Tests/AltitudeDifferential.lean','Tests/Upstream.lean','Tests/CommBDifferential.lean','Bench/WholeDecoder.lean','spec.lock']:
 assert subprocess.check_output(['git','show','HEAD:'+p])==Path(p).read_bytes(),p;bindings[p]=sha(p)
core=Path('/home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat')
corefiles=[core/'Bitwise/Basic.lean',core/'Bitwise/Lemmas.lean',core/'Lemmas.lean']
assert 'theorem shiftRight_eq_div_pow (m : Nat) : ∀ n, m >>> n = m / 2 ^ n' in corefiles[0].read_text()
assert 'theorem and_one_is_mod (x : Nat) : x &&& 1 = x % 2' in corefiles[1].read_text()
assert 'theorem one_shiftLeft (n : Nat) : 1 <<< n = 2 ^ n' in corefiles[2].read_text()
record=dict(status='passed_initial_read_only_runtime_assessment',recorded_utc=datetime.now(timezone.utc).isoformat(),findings=[],runtime_sha256=bindings,prior_committed_source_sha256=before,baseline_commit=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),core_lemma_bindings={str(p):sha(p) for p in corefiles},checks=['Exactly four executable definitions changed; comments aside all remaining runtime text in three modules is identical.','Altitude.bit uses arbitrary Nat shift before mask, so high input bits and oversized indices keep original total semantics.','grayDecode keeps List.range order, original accumulator/XOR order and full arbitrary width/word domain; no machine truncation.','identityCode preserves all digit indices and weighting; reserved bit6 remains unused.','payloadInteger keeps coding predicate and Int subtraction, including width0 truncated subtraction and noncanonical code values; no new modulo truncation or validity hypothesis.','Existing frozen altitude/upstream/Comm-B/worker adapters remain byte-identical and call live production entrypoints.','Only existing core Nat operations are used; no new cache, corpus dependence, trusted primitive or hardware Float arithmetic.'],boundary_obligations=['bit zero/place0/high200/above highest index','Gray width0/width80/over-wide word retained','all BitVec13 identities including all bits and reserved bit6','signed width0 code0/1/2; width1; unsigned overwide; midpoint−1/midpoint/max; code above modulus; width80'],limits=['Source reasoning only at this stage. Final owner proof/integration logs and fresh linked C/native paths must be independently bound after combined build.','Exact natural shifts may still allocate on large values; no allocation-free or timing claim.'],reviewer_sha256=sha(__file__))
p=R/'source-initial.json';assert not p.exists();p.write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(dict(status=record['status'],sha256=sha(p),findings=[])))
