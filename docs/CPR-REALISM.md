# CPR admissibility on the rs1090 corpus

The frozen `LocalAdmissible` holds for **1,057 / 1,057 actual local resolutions
(100%)**. The frozen `GlobalAdmissible` holds for **10,254 / 10,264 live airborne
pairs with both positions available (99.902572%)**. All ten global failures are
quantized latitude-zone mismatches; rs1090 accepts those current messages through
local fallback instead.

| Predicate and population | Satisfied | Fraction |
| --- | ---: | ---: |
| Local: actual airborne fallback | 10 / 10 | 100% |
| Local: actual surface decoding | 1,047 / 1,047 | 100% |
| Local: both actual local routes | 1,057 / 1,057 | 100% |
| Local: every resolved message with a previous aircraft position, including global results | 11,345 / 11,345 | 100% |
| Global: all live eligible pairs with independently available positions | 10,254 / 10,264 | 99.902572% |
| Global: subset whose current position used global decoding | 10,254 / 10,254 | 100% |
| Global: subset whose current position used local fallback | 0 / 10 | 0% |

## Inputs and populations

The pinned oracle is rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30`. Its
`long_flight.csv` contains 172,432 messages. Playback uses the original order and
timestamps, strips the 18-character Beast prefix, starts with empty aircraft
state and no external reference, and disables reference updates, as the frozen
CPR benchmark does. No surface reference is invented. Actual rs1090
`decode_positions` and frame-by-frame `decode_position` outputs were compared
bit for bit for the entire corpus; all comparisons passed. The trace contains
12,964 CPR messages and 11,347 resolved positions.

Each returned binary64 latitude/longitude is converted to its **exact rational
value** with `Spec.Binary64.fromBits` and treated as the true position, as
requested. [ReviewCPR.lean](../scripts/ReviewCPR.lean) executes `decide` on the
actual frozen predicates. It preserves their strict inequalities, encoder-side
rounding, and latitude-zone table. This is runtime evaluation of the exact
definitions, not a new universal theorem or an independent accuracy check.

For local cases, `p` is the current resolved position; `reference` is the
aircraft's last accepted position **before** the current message. The current
medium and parity are used. Actual local routes are reported separately from
the broader hypothetical use of that reference for every resolved message.
Two initial global resolutions had no prior reference and are unavailable for
this latter check. All airborne references in the broader population meet the
180-second age condition; the largest surface reference age is 70.524 seconds.

For global cases, the pair is the live opposite-parity cached message and the
current message at an actual nonnegative, strictly-under-30-second global
attempt. Each member uses the position accepted at **its own original arrival**,
ordered even then odd. Events are counted in processing order, including reuse
of a cached mate. This includes all ten failed global attempts followed by
successful local decoding. It does not select only successful global results.

There were 10,405 global attempts: 105 had no accepted current position, and
36 had an accepted current position but no position at the mate's original
arrival. Those 141 events are unavailable for this check, leaving 10,264 pairs.
The trace's supplemental reverse-decoded mate positions are not used to fill
missing data. Doing so would test positions reconstructed from the same pair
being checked and bias the result.

## Failure details and additional checks

All ten failures concern aircraft `486257`, at current corpus rows 38444,
38451, 52662, 69356, 69369, 86725, 105732, 127975, 148005 and 148019. They fail
only `nlTable r0 = nlTable r1`: geographic validity and both separation bounds
pass. Their pair ages range from 0.527452 to 1.475122 seconds. The complete
positions, mate rows, raw CPR fields and component decisions are retained in
[failures.json](review-cpr/failures.json).

Every evaluated current position, and both members of every evaluated global
pair, re-encodes to the original transmitted CPR latitude and longitude codes.
No tolerance was used for this check. The evaluator also checks that the
component diagnostics agree with the complete predicate on every case.

The corpus resolves positions for only **two aircraft**. These percentages
describe this corpus and oracle-derived surrogate truth; they do not establish
coverage for other regions, long pairing gaps, or arbitrary physical positions.

## Reproduction and retained evidence

Build and run the review-only tracer using the commands in
[review/cpr-oracle/README.md](../review/cpr-oracle/README.md), then run:

```sh
python3 scripts/review_cpr.py .cache/review-cpr/trace.jsonl
python3 scripts/check_lock.py
```

To repeat just the Lean evaluation from the retained exact trace:

```sh
python3 scripts/review_cpr.py docs/review-cpr/oracle-trace.jsonl.gz
```

Both evaluation commands were run successfully, each evaluating 21,609 cases:
11,345 local-reference cases and 10,264 global pairs. The primary populations
are subsets of these cases. The results are in
[summary.json](review-cpr/summary.json), with corpus, trace, lock and evaluator
hashes. [evaluations.csv.gz](review-cpr/evaluations.csv.gz) retains every input
bit pattern, corpus row, group membership and decision.

The review sources and evidence are outside `spec.lock`. No frozen definition,
benchmark, guard or lock entry was changed.
