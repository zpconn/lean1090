# Generation 18: exact dyadic conversion

Generation 18 measured **1.672168× decode** and **1.342735× decode plus CPR**
against rs1090. CPR throughput improved 17.68% over generation 17; decode
throughput changed by 0.06%. Both 2.00× targets remain unmet.
[Measurements and raw samples](../bench/GEN18.md).

The preceding [CPR diagnostic](GEN17-CPR-COST-BREAKDOWN.md) found numeric
geography to be the largest detailed category: 3,857,692,962 of
15,901,328,066 collected instructions. Within it, 103,138 calls to `toFloat`
accounted for 3,333,981,092 inclusive instructions. The nested rounding and
rational-division costs overlap; these counts are diagnostic observations,
not predicted speedups or a fast-path hit rate. The complete
[decode diagnostic](GEN17-COST-BREAKDOWN.md) and independent reviews of both
diagnostics passed before this change was selected.

`Impl.CPR.Policy.toFloat` now has an exact integer path for nonzero
canonical rationals whose numerator magnitude is below 2^53 and denominator
is exactly 2^k with k ≤ 1074. These values are already representable in
binary64. For numerator magnitude `n`, let `h = log2 n` and `e = h − k`.
Normal values use the significand `n << (52 − h)` and biased exponent
`e + 1023`; subnormal values use the fraction `n << (1074 − k)`. The sign
comes from the numerator. The final conversion still uses `Float.ofBits`.

Zero produces positive zero. Every rejected input uses the unchanged old
conversion, named `toFloatFallback`, including its behavior for negative
values that round to zero. The guard covers finite binary64-derived
rationals with magnitude below 2^53; it does not accept every dyadic rational
of that magnitude. There is no position lookup table, message cache,
hardware arithmetic shortcut or new trusted primitive.

The central proof module establishes the exact binade, an integer formula for
division by the rounding quantum, and identity of software rounding on the
guarded inputs. Its targeted build passed; all four printed facts use only the
permitted axioms. Two routine elaboration corrections and the successful
attempt are retained. Independent source/log review passed.

Bit assembly and CPR integration also passed their targeted build. The
conversion equality holds for every rational input and feeds the existing
numerical-geography and complete CPR tracking refinements. Kernel witnesses
cover both signs at the smallest and largest subnormals, smallest normal,
largest admitted numerator, guard exclusions and signed underflow ties.
The first build's proof elaboration corrections remain retained. Equality of these
programs does not claim that opaque trigonometric Float operations implement
real arithmetic.

The combined six-target build passed 3,534 jobs with all four changed/new
sources and 190 correctness inputs unchanged. A separate unfrozen conversion
probe passed 33,174 cases, covering all finite exponent fields, both signs,
significand boundaries, seeded bit patterns and excluded rational domains.
It exercised 17,388 fast cases, 15,758 fallbacks and 28 zero cases, with zero
mismatches and 32,756 finite-bit checks. This selected test distribution is
neither a corpus hit-rate estimate nor a benchmark.

Independent source/proof and linked-native reviews passed. All 22 native sets
were bound to the actual worker; the other 21 sets are unchanged from generation
17. The integer path and original fallback remain live. The generated wrapper
still parses decimal Nat constants and retains lazy scalar initialization;
this change is not claimed to make conversion allocation-free. Failed
reviewer assumptions about generated-code shape remain preserved with the
corrected checks.

The full fixed gate passed with all 190 correctness inputs unchanged, checking
all 23 capstones, 152 witness proofs, 1,011 unit assertions and seven mandatory
differential components. The fixed and independently seeded campaigns each
checked 10,476,164 whole messages and 101,244 direct Comm-B cases, covering all
32 DF attempts, 70 ADS-B branches and 14 registers. Only the documented D001
whole-message compatibility cases occurred; standard-view differences remain
separately recorded. Independent fresh retention review and frozen comparison
replay passed. Verified fresh scratch cleanup reclaimed 5,359,562,752 allocated
bytes while preserving all retained evidence and protected data.
Fixed-gate archival and selected duplicate cleanup also passed, reclaiming
another 5,733,330,944 allocated bytes. Total reclaimed: 11,092,893,696 bytes;
compressed evidence and unique failures remain retained.

Implementation, proof attempts and validation are retained
under [`tests/evidence/optimization/gen18`](../tests/evidence/optimization/gen18/).
Final independent gate/archive/plan review passed. Both modes were measured
from a clean committed fresh build with all other project work stopped. The
result review checked all 96 samples, native/build bindings and power/clock
metadata; the unchanged full-gate inputs also bind the result artifact commit.
