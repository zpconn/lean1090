# Generation 11: a machine-word CRC loop

The generation-10 diagnostic attributed 44.92% of collected instructions to
frame parsing and CRC. The syndrome path processed 15,300,600 bits across the
172,432-message corpus, constructing a list of indices and maintaining a
`BitVec 24` remainder through each fold. These are instruction and call counts,
not a prediction of a timing improvement. The complete measurement is in
[GEN10-COST-BREAKDOWN.md](GEN10-COST-BREAKDOWN.md).

[`Impl/Parity.lean`](../Impl/Parity.lean) now keeps the remainder in `UInt32`
and visits the same indices with `Nat.fold`. Its `wordStep` shifts the
remainder, inserts the input bit, applies polynomial feedback from bit 23,
and masks the result to 24 bits. The standalone `step` API delegates to that
same update. `syndrome` projects the final remainder into the original result
type once, after the fold. The implementation uses no new table, cache or
project-specific trusted primitive.

[`Proofs/ParityWord.lean`](../Proofs/ParityWord.lean) proves that every `UInt32`
state projects to the frozen polynomial step, even when its upper eight bits
are set. A range-fold identity and fold homomorphism then prove the complete
syndrome equality for every natural width and input word. The existing cached
bit extraction and its arbitrary-precision fallback beyond bit 127 are
unchanged. Seven kernel witnesses exercise high state bits, feedback, zero
width, 56- and 112-bit frames, the cache boundary and over-wide input words.

The final helper build and integrated decoder build pass, and all printed
proof dependencies are restricted to the three permitted axioms. The initial
`bv_decide` experiment was rejected because its axiom output included native
reflection axioms. The final proof uses symbolic bit-vector reasoning; the
rejected attempt and all elaboration failures remain in the
[proof evidence](../tests/evidence/optimization/gen11/proof/summary.json).

This removes the temporary index list. It does not claim allocation freedom
for arbitrary natural widths: extremely large indices may still require
arbitrary-precision arithmetic. The independent native review passed 42
checks against the linked decoder: the remainder stays in 32-bit registers,
the loop has no range-list construction or per-step projection, and exactly
one loop call is followed by one final projection. Its 140 captured inputs
stayed unchanged. The [native evidence](../tests/evidence/optimization/gen11/native-review/review.json)
also checks the retained arbitrary-precision fallback. The fresh 10M campaign passed with no unclassified difference; its
107 sources, three binaries and retained evidence passed independent review.
The fixed-seed full gate also passed, including all 23 contracts, 152 witness
audits, 1,011 unit assertions and seven mandatory differential components.
All 182 audited inputs remained unchanged. Both campaigns are recorded under
[`tests/evidence/optimization/gen11/`](../tests/evidence/optimization/gen11/).
The benchmark will run only after validation and a verified commit, using a
fresh build and the unchanged interleaved protocol in both modes.
