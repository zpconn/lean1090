# Verified score optimization order

The current target is **2.00× rs1090 in both decode and decode-plus-CPR**.
Stop for review only when both measured ratios reach it. Generation 21 reached
1.96331× decode and 1.53989× with CPR; [its report](../bench/GEN21.md) retains
all samples and conditions. No project-specific trusted primitive is authorized.

CPR changes must remain inside the proved boundary. Moving work into tested-only
Float callbacks, including haversine, or adding tested-only Float code requires
explicit user approval. The benchmark harness and interleaver remain frozen.
Each future generation report includes signed CPR overhead for both decoders:
`1e6 / cpr_msg_s - 1e6 / decode_msg_s`, in microseconds per message. Compute it
from exact integer median durations before division. It is a difference between
mode medians, includes measurement noise, and does not isolate CPR execution.
[The historical supplement](../bench/CPR-OVERHEAD.md) preserves negative values
and leaves every sealed generation report unchanged.

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

## Unselected candidates after generation 20

Generation 21 measured exact integer/rational field normalization. Later choices
must follow fresh diagnostics of the resulting measured code; the following
are possibilities, not implemented changes or predicted speedups.

- Exact dyadic inputs can bypass software rounding using the existing
  `Binary64Dyadic.round_eq` theorem and a proved guard. Measure the admitted
  population first: division results need not have power-of-two denominators,
  so the current rounding call count is not a shortcut hit count.
- The general rounding algorithm could compute its scaled quotient and
  nearest-even decision directly with integer shifts and division, avoiding
  intermediate rational normalization. This needs an all-input proof that
  nearest-even rounding is invariant under the reference fraction reduction.
- `fromBits` could construct the exact signed dyadic directly, retaining the
  same finite-value rejection and an unrestricted bit-pattern refinement.
  The existing Float callbacks and their arithmetic must remain unchanged.
- Semantic field construction repeats some field decoding for standard and
  oracle views. Sharing would require exact per-layout proofs, including every
  documented discrepancy and unrestricted input; identical-looking formulas
  are insufficient evidence.
- ScoreGate's multiplication by 2^40 can potentially be moved out of its
  comparisons using exact integer ceiling/floor division. Its measured tail
  is smaller than the complete gate cost. Any alternative early decision from
  term bounds must be proved over all field codes and retain the current
  uncertain-case fallback. No corpus-specific shortcut is acceptable.
