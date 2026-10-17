# Payload specification evidence

`Spec/PayloadBits.lean` defines auditable one-based MSB-first field schemas, exact rational projections, field-assignment validity, positional decoding and independent field-placement encoding. `Spec/ADSB.lean` covers all type codes accepted by the pinned oracle; `Spec/CommBLayouts.lean` and `Spec/CommB.lean` cover the Comm-B direct codecs and per-message inference. All schema records retain named field codes rather than an original opaque payload word.

The Comm-B source provenance, all acceptance predicates, rounding behavior, source conflicts, score semantics, numerical trust boundary and proven non-vacuity witnesses are documented in [COMMB.md](COMMB.md). ADSB source provenance and exact public scope are in [SCOPE.md](../SCOPE.md) and the individual definition docstrings.

The design follows the inspected lean-zip separation: mathematical reference data independent of an optimized representation, explicit refinement targets, separate source conformance and proof checks, and progress logs suitable for resuming work. The study included `Zip/Spec/Deflate.lean`, `Zip/Native/Inflate.lean`, zlib references in `ZipTest/`, and `git show pre-split:PLAN.md` / `git show pre-split:PROGRESS.md`. No speed, proof-completeness or differential-conformance claim is inferred merely from following that architecture.
