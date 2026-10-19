# Generation 14: exact BDS60 ratio enclosure

The reviewed generation-13 diagnostic attributed 37.60% of collected
instructions to Comm-B inference, the largest stage. BDS60's candidate penalty
used 844,657,445 inclusive instructions, compared with BDS50's 151,277,418.
These nested counts overlap the exclusive stages and are diagnostic counts,
not elapsed-time predictions. [Complete diagnostic](GEN13-COST-BREAKDOWN.md).

The selected change keeps the exact `IAS / Mach` rational and bounds the
software binary64 rounding error using integer arithmetic. It returns an
outside result only when the entire interval is below 250 or above 800,
and an inside result only when the entire interval lies within those
inclusive boundaries. An uncertain interval evaluates the original rounded
comparison. Status handling and the positive-Mach guard stay unchanged.

[`Impl/CommB.lean`](../Impl/CommB.lean) represents the rational by numerator
`N` and positive denominator `D`. With `K = 2^51`, the center is `K*N` and
the error radius is `|N| + D`; both thresholds are scaled by `K*D`. All
comparisons use exact integers. The original rounding call remains inside
the uncertain branch.

[`Proofs/CommBRatio.lean`](../Proofs/CommBRatio.lean) proves equality for every
rational input using the existing general rounding-error theorem. Six kernel
witness theorems include negative and far-outside values, both exact
thresholds, neighboring values, and rationals outside the interval that round
back onto its endpoints. Explicit branch checks verify that exact and
round-back boundaries reach the fallback.

The helper build passed with all seven printed facts using only permitted
axioms. Two earlier cast-normalization proof failures are retained; runtime
code was unchanged across the attempts. The whole-decoder integration passed
its first build. [Proof evidence](../tests/evidence/optimization/gen14/proof/summary.json)
and [integration](../tests/evidence/optimization/gen14/integration/targeted-build.json).
Independent source/proof/native review passed all 31 checks with 143 held
inputs and 439 retained files. The linked helper uses exact integer arithmetic;
its sole software-rounding call is conditional on an uncertain enclosure.
The BDS60 caller forms the original exact rational division once. BDS50 and
the nineteen other production native sets remain unchanged.
[Native evidence](../tests/evidence/optimization/gen14/native-review/review.json).
The separate fresh 10M campaign passed with 10,476,164 total messages:
9,542,410 exact matches plus 933,754 documented D001 cases. All 101,244 direct
registers match, with full 32/70/14 branch coverage. Independent retention
replay verified all 110 sources, three binaries and 33 artifacts.
The fixed full gate passed: 23 contracts, 152 witness audits, 1,011 unit
assertions and seven differential components, with all 185 inputs unchanged.
Whole-message counts are 10,476,164 = 9,542,689 exact + 933,475 D001, and all
101,244 direct registers match. All component archives are retained, and
final independent archive review passed on its first attempt with no findings.
[Final review](../tests/evidence/optimization/gen14/independent-review/gate-review.json).
No frozen-file change or trusted primitive is used. There is no generation-14
throughput claim before validation and an isolated benchmark from a clean
committed build.
