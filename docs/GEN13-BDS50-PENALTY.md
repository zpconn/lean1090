# Generation 13: exact BDS50 wind-penalty table

The reviewed generation-12 diagnostic attributed 41.97% of collected
instructions to Comm-B inference. Within the separate candidate probes,
BDS50's penalty calculation used 1,066,037,418 inclusive instructions and
BDS60's used 844,659,720. These costs overlap the exclusive stages; they are
diagnostics, not a prediction of elapsed-time gains.
See [the full diagnostic](GEN12-COST-BREAKDOWN.md).

The selected change replaces the BDS50 wind penalty with an immutable table
indexed by the signed difference of its two ten-bit speed codes. Its 2,047
entries cover the complete code domain, independently of message content or
the benchmark corpus. The reference body retains the software binary64
subtraction, absolute value, division and final subtraction. Availability
checks still return zero when either speed is absent. The subsequent
roll/track-rate adjustment and BDS60 penalty are unchanged.

[`Impl/CommB.lean`](../Impl/CommB.lean) performs the two availability checks
and indexes the table with `TAS_code + 1023 - GS_code`. A proof of the code
bounds supplies the array bound. The table retains all three software
binary64 rounding steps; its shared constant is independent of corpus data.

[`Proofs/CommBPenalty.lean`](../Proofs/CommBPenalty.lean) proves that the index
is in range and its signed value equals the exact speed difference. The
unconditional runtime theorem then recovers the original semantic-field
match for every natural-number payload, including unavailable fields and
over-wide words. Six kernel witness theorems cover absent statuses, equal
speeds, a nonexact division, both signed endpoints and a bit above the payload.

The helper build passed its first attempt (777 jobs), and all eleven printed
facts use only the permitted axioms. The first integrated build passed
3,521 jobs, preserving whole-decoder refinement. [Helper evidence](../tests/evidence/optimization/gen13/proof/summary.json)
and [integration evidence](../tests/evidence/optimization/gen13/integration/targeted-build.json)
retain the sources and logs. Independent source/proof review also passed.

Independent compiled-path review passed all 35 checks, with 142 held inputs
and 347 retained files. The live lookup checks availability before extracting
speed codes and loading the array. The complete 2,047-entry constructor
retains the software rounding operations and runs during module
initialization. The turn adjustment and BDS60 still use their original live
paths; all nineteen other linked production native sets match generation 12
byte-for-byte. [Native review](../tests/evidence/optimization/gen13/native-review/review.json).

The separate fresh 10M campaign passed: 10,476,164 total messages,
9,542,998 exact matches and 933,166 documented D001 cases. All 101,244 direct
Comm-B cases match, with full 32/70/14 branch coverage. Independent retention
replay verified the transcripts and all 109 source/three binary hashes.
The fixed full gate passed with all 184 audited inputs unchanged: 23 exact
contracts, 152 witness audits, 1,011 unit assertions and seven differential
components. It checked 10,476,164 messages (9,542,689 exact and 933,475 D001)
and all 101,244 direct registers exactly. Final archive review passed, retaining
all seven component trees and verifying the unchanged historical evidence.
An ignored Python bytecode cache required exact recovery from retained source;
both versions and every review/recovery attempt are retained, with no waiver
or historical hash edit. [Final review](../tests/evidence/optimization/gen13/independent-review/gate-review.json).
No new trusted primitive or frozen-file change is used. There is no
generation-13 throughput claim until review, a committed build and isolated
benchmark have completed.
