# Verified score optimization order

Generation 10 reached 1.16895× rs1090 decode throughput with the software model
and zero trusted primitives. The user subsequently authorized continued
optimization toward **1.50× headline decode throughput**. Stop for review when
that target is reached. Generation 13 subsequently measured 1.49276× decode
and 0.92663× CPR; [bench/GEN13.md](../bench/GEN13.md) retains the complete
measurement. The policy below governs the resumed work.

The user specified this order after reviewing the BDS50 baseline of about
0.24× rs1090 throughput. The baseline is evidence of a performance gap, not
evidence that verified software arithmetic cannot close it.

1. Keep `Spec/Binary64.lean` as the proved reference. Preserve its operation
   order, nearest-even rounding, status handling and inclusive −3 threshold.
2. First optimize the proved path. One candidate is a finite table containing
   each density term's exact binary64 value for every field code. Prove every
   table lookup agrees with the software reference; include absent fields and
   sentinels. Tables must cover the field domain, never the benchmark corpus.
3. Use exact integer or fixed-point arithmetic for the aggregate score where
   possible. If an accelerated decision uses a bound on rounding error, prove
   that bound over the complete input domain, including cross-field penalties.
   Accept or reject directly only when the entire proved score interval lies
   on one side of the inclusive threshold. Evaluate the full software model
   when the interval touches or straddles −3. Exact equality must still accept.
4. Prove refinement of the actual timed entrypoint after every change, run the
   frozen gate, inspect generated C and profiles, and use the frozen interleaved
   benchmark. Report table size, allocation costs, fallback frequency and exact
   threshold coverage when they help explain the measured result. Do not drop
   hard-invalid or score-rejected messages from the timed corpus.
5. Only if measured verified approaches cannot close the gap, propose hardware
   binary64 add/sub/mul/div as `TRUSTED.md` primitives and ask the user before
   adding them. Any approved proposal must use `-ffp-contract=off`, pure Lean
   reference bodies used by proofs, and runtime differential checks against
   the model. The existing maximum of five tiny primitives still applies.

No hardware primitive is authorized now. The frozen reference and guard files
must not be changed to make an optimization pass. Any required change to a
frozen file needs explicit user approval.


## Live-path and milestone requirements (2026-10-17)

Every Impl name referenced by a frozen adapter must remain the production
code path or delegate to it, including Altitude, decodeBDS, Semantics.commB,
CPR, CPR.Policy numerical adapters, Numeric/Presentation and JSON helpers.
A legacy implementation kept only to satisfy frozen tests is forbidden. If a
refactor cannot preserve this binding, stop and propose a frozen-file change.

At every milestone and for the final 10M campaign, retain the normal fixed-seed
results and also run check_message_differential.py directly with a newly
sampled, recorded seed and a newly seeded FuzzCommB corpus. Record seeds
before generation, retain both results and investigate every finding.

The following preparation requirements were completed through FC005/FC006:
the stream-level decodePositions differential
and complete upstream unit-vector suite passed and were frozen with approval.
All capstones were completed, the benchmark worker and executable target were
frozen, and the whole-decoder baseline was taken with the prescribed ABAB
protocol before generation 1. Historical approvals and hashes remain in
[FROZEN-CHANGES.md](FROZEN-CHANGES.md).
