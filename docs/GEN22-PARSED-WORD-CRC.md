# Generation 22: reuse the parsed word for CRC

Status: proofs and full fixed/fresh validation passed. Generation 22 measured
**2.203718886895× decode** and **1.715366461888× with CPR**; the combined target
remains unmet. See [the measured report](../bench/GEN22.md). Independent result
review passed. The measured predecessor was gen21: 1.963308902434×
decode and 1.539889738438× with CPR.

The completed [decode diagnostic](GEN21-COST-BREAKDOWN.md) counted
8,429,813,030 instructions. Comm-B inference and frame/CRC are nearly tied,
at 2,999,709,189 and 2,965,633,695. Within frame/CRC, the current syndrome
calculation reconstructs the parsed information with `frameParts` and
`packFields`: their inclusive costs are 69,772,275 and 816,467,903 instructions.
These are nested observations, not predicted savings. A second `bytesValue`
traversal would add work; the existing parsing traversal accounts for
454,122,335 inclusive instructions. The
[CPR diagnostic](GEN21-CPR-COST-BREAKDOWN.md) independently covers the complete
tracking stream and final state. Both diagnostics passed independent review
before this change was selected.

The selected change retains the word already constructed by the parser.
`decodeFrameWithWord` returns the same frame together with that word;
`decodeFrame` delegates to it and projects the frame. The complete `decode`
computes the full-frame syndrome from the returned word, then uses the existing
acceptance and report functions. Malformed lengths and unsupported formats
still fail before CRC. The public model and every output field remain intact.

The proof has two independent parts. Parser equivalence establishes the exact
frame and word for every byte input. The reference encoder theorem establishes
that the syndrome of a complete encoded frame is its information checksum XOR
its transmitted parity. Full structural byte reconstruction transfers that
result to every successfully parsed input, including spare bits, DF19 and
Comm-D. The integration preserves the exact existing `decode_old`,
refinement and prefix-refinement statements, with kernel-checked proofs.
The integrated build passed on attempt 2; the unfinished final simplification
from attempt 1 remains in the evidence. See
[integration execution](../tests/evidence/optimization/gen22/integration/attempt-02/execution.json).

No frozen file, hardware primitive, Float callback or numerical policy changes.
The standalone frame-based APIs retain their arbitrary-frame semantics, and
frozen parser adapters continue through the production helper. Independent
native inspection confirms one parsing word construction and the live raw-word
CRC path. Only Frame and Message changed among 22 linked native sets; the other
20 are identical. Pair allocation/reuse remains visible in the generated code,
so this inspection does not assert zero allocation or a particular speedup.
The full fixed and fresh-seed 10M differential campaigns passed with complete
coverage and only the documented oracle discrepancies. The fresh comparison
replay also passed. Verified cleanup reclaimed 11,092,504,576 allocated bytes
of duplicate scratch, preserving retained evidence and historical failures.
Only a
verified clean commit may enter the unchanged two-mode benchmark.
