# Generation 2: exact Comm-B score decisions

The pre-change [generation-1 diagnostic](GEN1-COST-BREAKDOWN.md) attributes 48.34% of collected instructions to Comm-B candidate inference, the largest stage. Generation 2 replaces repeated density evaluation in the live `Impl.cbScorePasses` path with complete field-code tables and a proved rational enclosure. This document describes the implementation and proof; benchmark results are recorded separately after the full gate and a clean commit.

Thirteen immutable arrays contain 20,992 exact software-binary64 density values. Their domains are complete field codes, including codes that receiver plausibility checks reject. MCP/FMS altitude share one table; the two pressure fields share another. Lookups preserve field order, status bits and sentinels. The arrays are defined by pure `Array.ofFn` over the existing software model. Generated C initializes and marks them persistent during module initialization; the per-message path reads them without mutation. No key is a message, aircraft identifier or corpus index.

For the resulting list of at most four exact density terms `t` and the existing software-model penalty `p`, the runtime computes these quantities using exact rational arithmetic:

```
c = (if t is empty then 0 else sum(t) / length(t)) + p
e = (sum(abs(t)) + abs(p) + 1) / 2^40
```

The proof establishes `abs(scoreReference(t, p) - c) ≤ e`, where `scoreReference` retains every software-binary64 rounding step in the ordered sum, division and final addition. It holds for arbitrary rational terms and penalty, assuming only the proved length bound. It does not assume acceptance, a finite observed range or corpus membership.

The gate accepts when `c - e ≥ -3`, rejects when `c + e < -3`, and otherwise calls the original complete `cbCombinedScore` comparison. The inclusive boundary is preserved. The fallback is a `Unit → Bool` callback; generated C confirms its body is not evaluated before the interval decision. Kernel-checked witnesses cover acceptance, rejection, fallback and an exact score of −3.

The all-input connection is:

1. `Proofs.CommBTables.density_terms_eq` proves every table-derived list equals the original density list, for all natural-number registers and payloads, including over-wide payloads.
2. `density_terms_length` proves the unconditional four-term bound.
3. `Proofs.Binary64Error.score_error` proves the enclosure against the unchanged software model.
4. `Proofs.ScoreGate.choose_eq` proves the interval/fallback Boolean decision.
5. `Proofs.Decoder` connects that decision to the frozen `Spec.cbScorePasses` and the complete `Impl.decode` refinement.

The existing density, penalty and complete-score functions remain live through the fallback. Frozen whole-message adapters reach the new gate; direct-register and semantic adapters continue to call the live functions they test. The historical BDS50 pilot is a separate API and is not evidence for this new whole-decoder path. There are no new trusted primitives or frozen-source changes.

The first integrated build passed all 3,507 requested jobs, including the decoder refinement with only `propext`, `Classical.choice` and `Quot.sound`. The implementation, proof and generated-C inspection evidence is retained under [tests/evidence/optimization/gen2](../tests/evidence/optimization/gen2/). Full-gate, fresh-seed and timed results must be read from their completed records; this implementation note makes no throughput claim.

The subsequent `scripts/check_all.sh --full` passed with 173 unchanged correctness inputs. Fixed and fresh campaigns each covered 10,476,164 messages and 101,244 direct-register cases, with no unclassified differences or coverage gaps. The fresh seeds were 184794048 (messages) and 1273035172 (Comm-B). The [validation record](../tests/evidence/optimization/gen2/validation.json) links the exact counts, proofs, source snapshots and complete component archives. Timing has not yet run.
