# Generation 12: exact byte conversion in machine-word chunks

The generation-11 diagnostic attributed 38.06% of collected instructions to
frame parsing and CRC. Its largest concrete helper, `bytesValue`, used
2,100,152,579 inclusive instructions across 172,432 calls. These nested counts
overlap the stage totals and are not a prediction of elapsed-time gains.
See [the complete diagnostic](GEN11-COST-BREAKDOWN.md).

[`Impl/Bits.lean`](../Impl/Bits.lean) now folds up to eight input bytes in a
UInt64. For lengths nine through sixteen, a tail-recursive prefix worker
consumes eight bytes, returning the accumulated word and the existing suffix.
It constructs its pair only at the endpoint; it does not copy prefix list
nodes. A second word fold handles the suffix, and an exact natural-number
shift and addition combine the chunks. Longer lists retain the original
unbounded fold. The change adds no table, cache or trusted primitive.

[`Proofs/ByteWords.lean`](../Proofs/ByteWords.lean) proves the modular word fold
for every list, then uses the independent reference byte bound to remove the
modulo for chunks of at most eight bytes. Prefix and concatenation lemmas prove
`Impl.bytesValue bytes = Spec.bytesValue bytes` for every byte list, without
length or validity hypotheses. Seven kernel witnesses cover lengths zero,
seven, eight, nine, fourteen, sixteen and seventeen, including maximum words
and high bits crossing the chunk boundary. The whole-decoder refinement uses
this unconditional equality.

The helper build passed 2,042 jobs, and all eleven printed facts use only the
permitted axioms. The first attempt failed in the final case-selection tactic;
its source and log are retained. The successful proof uses explicit length
cases, with no change to the runtime. [Proof evidence](../tests/evidence/optimization/gen12/proof/summary.json).

The integrated build passed 3,520 jobs and preserves the whole-decoder
refinement. The separate fresh 10M campaign passed with no unclassified
differences; its source, binary and transcript checks passed independent
review. The full fixed-seed gate also passed: all 23 contracts, 152 witness
audits, 1,011 unit assertions and seven differential components, with all
183 audited inputs unchanged. Independent native review passed
41 checks against the actual linked decoder: the short and medium paths use
machine-word loops, the prefix allocates only its endpoint box and pair, and
the arbitrary-length fallback remains live. The compiler also changed
borrowing in the unchanged Frame/Message callers; those native deltas were
checked explicitly. [Native evidence](../tests/evidence/optimization/gen12/native-review/review.json).
No generation-12 throughput result is claimed yet.
