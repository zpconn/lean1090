# Generation 16: shifts and masks for field packing

The live `Impl.packFields` fold now concatenates fields with a natural-number
left shift. For field widths below 64 it masks the low UInt64 word; wider
fields retain the original arbitrary-precision remainder. The accumulator
remains an unrestricted natural number.

The preceding [decode diagnostic](GEN15-COST-BREAKDOWN.md) identified
frame/CRC as the largest stage: 3,961,737,590 of 11,213,423,773 collected
instructions. Its packing fold used 1,280,682,876 inclusive instructions,
including 882,818,451 in 881,619 direct power calls. The separate
[CPR diagnostic](GEN15-CPR-COST-BREAKDOWN.md) observed the same helper in its
decoder component. These overlapping instruction counts motivate the change;
they are not benchmark results or predicted speedups.

`Proofs/PackFields.lean` proves each new fold step equals
`acc * 2^width + value % 2^width`, then lifts that equality to every list and
every initial accumulator. There is no valid-message, field-width or
field-value hypothesis. `Proofs/Decoder.lean` uses the resulting equality in
the existing whole-decoder refinement proof. Six kernel-checked witnesses
cover the empty list, width zero, widths 63 and 64, an 80-bit field and a
multiword accumulator, including field values beyond UInt64's range.

The helper build passed, and the combined integration command
`lake build Proofs.Decoder lean1090 messageGenerator commbDifferential`
passed all 3,524 jobs on its first execution with the three changed sources
unchanged. All nine newly printed facts use only permitted axioms. The helper
source's two deprecated tactic-lemma aliases were updated before integration;
the earlier passing source and log remain retained.

Independent source/proof/native review passed on its first execution. The
linked fold uses natural-number shifts and native masks below width 64;
power/remainder calls remain only in the wider branch. It contains no generic
multiplication. The live path from decoding through `frameSyndrome` reaches
this packer, all 21 sibling native sets remain unchanged, and all 104 locked
hashes match. Review SHA-256:
`fc8af38e62b1ef7726f227dee34bed319e0cdf420eaf4e41256e1ad4f8c850d6`.

`scripts/check_all.sh --full` passed with all 187 correctness inputs unchanged:
23 capstone contracts, 152 witness proofs, 1,011 unit assertions and all seven
differential components. The fixed campaign checked 10,476,164 messages
(9,542,689 exact matches and 933,475 documented D001 cases), plus 101,244
exact direct Comm-B cases. Its separate standard-view difference count is
2,038,998.

The fresh campaign also passed: 10,476,164 messages (9,543,217 exact and
932,947 D001), all 101,244 direct cases exact, and 2,037,560 separately
recorded standard-view differences. Both campaigns cover all 32 DF attempts,
70 ADS-B branches and 14 registers with no gaps or unclassified differences.
The fresh seeds, recorded before execution, are 1400844992 for messages and
1518488658 for Comm-B. Independent retention review and comparison-only
replay reproduced its complete results from the sealed transcripts.

Final independent gate/archive/benchmark-plan review passed, binding all
187 correctness inputs, all seven components, the fresh replay and retention
seals, both cleanup receipts and the exact 2/1 targets for each benchmark
mode. Review SHA-256:
`180f14c351a50a29ca555b88062c8bd1b974fc38fe617f528ac9427f7ae08cf5`.

Executed commands, logs and exact source bindings are retained under
[`tests/evidence/optimization/gen16`](../tests/evidence/optimization/gen16/).
Verified duplicate-scratch cleanup reclaimed 11,093,217,280 allocated bytes
across the fixed and fresh campaigns; compressed evidence and unique earlier
failures remain. The clean committed fresh build and both frozen interleaved
runs measured **1.668888276454× rs1090 decode** and **1.029132958936× with CPR**.
All 96 samples and provenance passed independent result review. See the
[benchmark report](../bench/GEN16.md). No frozen file or trusted primitive
changed in this generation.
