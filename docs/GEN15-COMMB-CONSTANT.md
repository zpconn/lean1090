# Generation 15: share the Comm-B payload limit

The generation 14 diagnostic found that `bdsWireValid` reconstructs the exact
56-bit payload limit with `lean_cstr_to_nat("72057594037927936")` on every
call. The corpus produced 627,880 calls, costing 484,723,360 inclusive guest
instructions. This is a nested diagnostic observation, not a time measurement
or a predicted speedup. The independently reviewed breakdown is in
[GEN14-COST-BREAKDOWN.md](GEN14-COST-BREAKDOWN.md).

The change defines `commBPayloadLimit : Nat := 2^56` as a non-inlined immutable
constant and uses it in the same exclusive upper-bound check. It depends only
on the message format. No message, corpus value or previous result is stored.
Every register branch and all score arithmetic remain unchanged.

`Proofs.CommBConstant.bdsWireValid_eq_old` proves equality to the complete old
body for every natural-number register and payload by `rfl`. The theorem has
no width, validity or representability hypothesis. Additional kernel checks
cover zero, the largest 56-bit word, the exact limit, an over-wide word with a
supported header, an accepted register and an unsupported register. All six
printed facts use only permitted axioms.

The helper build passed its first execution. The integrated build also passed
on its first execution, preserving the whole-decoder refinement. The generated
C loads a shared global in the live validator and parses the literal only in
its initializer. Independent source/proof/native review passed 30 checks with all 144 held
inputs and 460 retained evidence files verified. The linked validator directly
loads the global, without a getter or parser call; the module initializer
parses the exact decimal bytes once and marks the value persistent. Both
inference and direct register decoding call the live guard. The other 19
production native sets match generation 14.

Reviewer-only script assumptions about source formatting and paths required
correction; the failed scripts and logs are retained. The author's empty
working-tree diff, captured after staging, is also retained; scope verification
uses the independently reconstructed before/after diff. No production or proof
change was needed for these review corrections.

The separate fresh-seed 10M campaign passed on its first execution: 10,476,164
messages, comprising 9,543,150 exact matches and 933,014 documented D001 cases.
All 101,244 direct Comm-B cases match exactly. All 32 DF attempts, 70 ADS-B
branches and 14 registers are covered, with no unclassified mismatches. The
2,037,305 standard-view differences are recorded separately. Seeds 3228104537
(messages) and 1212762037 (Comm-B) were recorded before generation. Independent
review verified the retained transcripts and unchanged sources and binaries.

The first full-gate attempt was interrupted for the user's disk-cleanup pause;
it is preserved as interrupted, not passed. The restarted full gate passed
from 15:11:33 to 15:26:58 UTC with all 186 inputs unchanged. It checked all
23 capstones, 152 witness axioms, 1,011 unit assertions and seven differential
components. Its fixed campaign checked 10,476,164 messages: 9,542,689 exact
matches plus 933,475 documented D001 cases; all 101,244 direct registers match.
The subsequent clean-commit benchmark measured 1.607053275134× rs1090
decode throughput and 0.990643654222× with CPR. All samples and environment
limitations are retained in [the generation 15 report](../bench/GEN15.md).
The 1.50× decode target is reached; further optimization is stopped for review.

Evidence:

- [Helper proof and generated C](../tests/evidence/optimization/gen15/proof/summary.json)
- [Integrated build](../tests/evidence/optimization/gen15/integration/targeted-build.json)
- [Independent native review](../tests/evidence/optimization/gen15/native-review/review.json)
- [Fresh seeds, recorded before generation](../tests/evidence/optimization/gen15/fresh-seeds.json)
- [Full gate and unchanged input hashes](../tests/evidence/optimization/gen15/gate-evidence.json)
- [Seven archived components](../tests/evidence/optimization/gen15/gate-archive.json)
- [Interrupted first attempt](../tests/evidence/optimization/gen15/attempt-01-interrupted-for-cleanup/interruption.json)
- [Verified message-scratch cleanup](../tests/evidence/optimization/gen15/post-gate-message-cleanup/result.json)
- [Final independent evidence review](../tests/evidence/optimization/gen15/independent-review/gate-review.json)
