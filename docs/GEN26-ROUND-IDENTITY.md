# Generation 26: skip rounding already representable rationals

**Targeted proof build passes; no generation 26 performance result exists.**

Generation 25 remains the latest measurement: 2.649719962329× decode and
1.947699046086× decode plus CPR. Its signed CPR overhead is
0.669397240651 µs/message for Lean and 0.041956313213 for rs1090, calculated
from independent mode medians and including noise. The combined 2.00× target
remains unmet.

## Measured reason for this change

The fresh generation 25 diagnostics precede implementation. The complete
decode collection has 5,748,262,724 guest instructions; the complete CPR
collection has 8,076,647,012. All 172,432 tracking outputs, 11,347 positions
and the complete final state match. See the [decode breakdown](GEN25-COST-BREAKDOWN.md)
and [CPR breakdown](GEN25-CPR-COST-BREAKDOWN.md).

Comm-B inference remains the largest decode stage at 2,248,598,424
instructions, followed by frame/CRC at 1,773,037,831 and semantic value
construction at 1,472,188,439. Generation 25 reduced decode instructions
by 57,720,958 (about 1%), despite the measured throughput regression. Retain
both observations; these counts do not isolate the cause of elapsed-time changes.

For the remaining CPR target, the pure software rounding boundary is a
substantial cost within the motion and pairing policy:

| Caller and stage | Calls to `Binary64.round` | Inclusive instructions |
|---|---:|---:|
| Division, motion policy | 20,806 | 429,171,673 |
| Subtraction, motion policy | 10,403 | 149,591,035 |
| Subtraction, airborne pairing | 10,421 | 148,215,613 |

These caller costs are nested within the stage totals. Their sum,
726,978,321 instructions, is not an estimate of removable work. Callgrind
does not retain rational argument values, so the existing profile does not
establish how often the proposed guard succeeds. All figures here are
diagnostics, not benchmark throughput or predicted speedups.

Both independent diagnostic reviews pass:
`25deaaa37376320ce9c2718a2f5e97ab0229fa030cee78d0aa053409f52ba13b`
and `58413f66740a599d029c0edca09905b58d4ac46211837ebe194432e663901e11`.
Sequential archive-verified cleanup reclaimed 479,670,272 allocated bytes.
Unique raw perf captures, retained evidence and review corrections remain.

## Implementation and proof boundary

`Impl/Binary64.lean` retains the previous complete rounding algorithm as
a live fallback. It first checks that the rational's absolute numerator is below
2^53, then checks that its denominator is exactly 2^k for k ≤ 1074. It returns
the original rational on that guard and uses the existing algorithm otherwise.
The guard depends only on the current rational value.

`Proofs/Binary64Dyadic.lean` already proves that the frozen rational rounding
model returns its input under precisely these bounds. The implementation reuses
that theorem in `Proofs/Binary64Runtime.lean` to retain the unrestricted type of
`round_eq`. The fallback also has an unconditional equality theorem. Boundary
witnesses cover zero, both signs, the numerator and subnormal boundaries,
non-dyadic denominators and rounding ties.

No frozen statement, Float callback, hardware primitive, benchmark harness
or interleaver change is part of this generation.

`lake build Proofs.Binary64Runtime` passed on its first execution (2,042 jobs),
with source hashes unchanged throughout. The retained log is
[`attempt-01/build.log`](../tests/evidence/optimization/gen26/round-proof/attempt-01/build.log),
SHA-256 `debd94c1bd5e59602fbcb93c1c0567c4e29075a05efbab5ad803a85cb8823f45`.
The combined command `lake build Proofs.Decoder Proofs.CPRTracking lean1090
messageGenerator commbDifferential lean1090-bench` also passed on its first
execution (3,549 jobs). Its validator confirms 202 unchanged correctness inputs,
127 audited sources and 362 permitted printed facts. Independent source/proof
review passed 231 checks, retaining every prior theorem type and the fallback
body. Review receipt:
`07f8deb8d9a6b322cac34a7d6e1212bdcbd16a5453a6cd26c33ffb0115909a2b`.

The first full gate failed during the broader proof build, before differential
tests ran. Importing the existing dyadic theorem changes transitive Mathlib
simplification in three BDS50 lemmas: the goals retain rational powers 2^10
and 2^11 opposite 1024 and 2048. `Proofs/BDS50.lean` now adds an explicit
`norm_num` step to those three proof bodies. All 26 statements there and all
runtime bytes are unchanged. `lake build Proofs.BDS50` passed on its first
repair attempt (2,044 jobs); its three printed theorems use permitted axioms.
The failed gate is preserved in
[`gate-attempt-01`](../tests/evidence/optimization/gen26/gate-attempt-01/retention.json).
The corrected combined build explicitly includes `Proofs.BDS50` and passed
(3,551 jobs, 365 permitted printed facts, 202 unchanged correctness inputs).
All four runtime binaries are byte-identical to the earlier build. Validator:
`7a472cfacd5c54bd833c0da633617122cfa583fec98452e46323b11423b0d74d`.

The second full fixed gate passed from 00:56:42.703055 to 01:12:48.883078
UTC on 2026-10-20. All 202 correctness inputs are unchanged. Its 10,476,164
messages include 9,542,689 exact matches and 933,475 documented D001 cases;
all 101,244 direct cases match. All 23 capstone contracts, 152 witness audits,
1,011 unit checks and seven mandatory differential strata pass. The separate
fresh campaign passed
all 10,476,164 messages: 9,543,358 exact matches and 932,806 documented
D001 cases, with 101,244 exact direct cases and full 32/70/14 coverage.
Independent retained-byte and comparison-replay reviews also passed. Fresh
cleanup reclaimed 5,359,734,784 allocated bytes, retaining all 33 archived
members. Fixed archival retains seven components and 62 files, and its
verified cleanup reclaimed another 5,733,335,040 allocated bytes. Together
these cleanups reclaimed 11,093,069,824 bytes of duplicate scratch. Historical
evidence and every failed attempt remain. The first consolidated review
stopped at its final index check because the three source files were not yet
staged. After staging those exact bytes, the unchanged checker passes on
attempt 2, with the first attempt retained. Consolidated review receipt:
`41409e98b8bb0371adebc846b9fa703cfac9b05624d20c624c7f0433ad21c1b8`.
The reviewed benchmark plan is ready; all producer and reviewer jobs are stopped. Fresh
message and Comm-B seeds 748,317,927 and 713,274,074 remain unchanged;
no fresh campaign began before the failure or repair. The fresh preflight
binds 127 sources, three binaries and 202 correctness inputs to the amended
build. Native review passed on its first execution: 763 checks, 274 held
bindings and 22 native sets, with 21 sibling sets byte-identical. Fresh C and
assembly show the linked numerator-first guard returning the original rational
and all three rejection conditions reaching the original fallback. The frozen
CPR loop reaches the live policy, subtraction/division and rounding functions.
No argument hit rate, allocation claim or timing result is inferred. Receipt:
`84ca7ee8c29fa2c065240a9734a52e278cdbc91f30a5d1c530c686b2052cd356`.
Both complete campaigns pass; isolated measurements remain pending. The
pre-timing plan retains a reviewer-detected correction to one prior-generation
filename guard; no benchmark or plan execution preceded that correction.
