# Whole-message differential campaign

`scripts/check_message_differential.py` builds and executes the pinned
`Message::from_bytes` oracle and the actual `lean1090 --diagnostic` executable.
The complete shell entrypoint also runs exhaustive altitude, reserved TC19,
numeric presentation and synthetic CPR checks. Diagnostic mode continues
across component failures and returns failure after recording the campaign.

```sh
lake build commbGenerator
.lake/build/bin/commbGenerator .cache/gate/commb.csv 100000 1085632
scripts/run_differential.sh --diagnostic --corpus --generated 100000 \
  --commb-boundaries .cache/gate/commb.csv
```

The whole-message component compares these inputs without early exit on a
disagreement:

- All 172,432 corpus frames, stripping the 18 hexadecimal Beast prefix before
  decoding. Input cardinality is asserted.
- At least 100,000 deterministic `Spec.encode` messages, including intact
  parity-valid assignments, single-bit corruptions and two distinct bit
  corruptions. Rejected field assignments remain in the suite.
- Every row of the structured `encodeBDS` generator in three complete-frame
  contexts: DF20 with matching AC12/AC13 bits, DF20 with missing outer altitude,
  and DF21. Header, status, extreme-field, plausibility and score-threshold
  fixtures are preserved, along with at least 100,000 random field assignments.
- Direct named-register comparisons on every structured payload, before the
  score gate, using actual library readers and the compiled Lean register
  decoder. The adapter also compares the runtime record and meanings with
  Spec, recording both refinement flags without stopping the stream.

The complete-frame comparison checks acceptance, the exact oracle JSON view,
CRC, bytes consumed and the unconsumed suffix. Floating outputs compare as
parsed binary64 values with no tolerance; CPR's separately enforced positional
tolerance belongs to its own component. Standard JSON is retained separately
for inspection and cannot excuse an oracle-view mismatch.

Coverage comes from the final transmitted bytes, not pre-corruption generator
labels. The report includes every DF0–31, all 70 canonical ADS-B branches and
all 14 Comm-B registers. Each ADS-B branch must have an intact generated input
and an accepted input from both decoders. Comm-B reports targeted payloads,
complete-message candidate opportunities and actual returned candidates
separately from direct-register acceptance. BDS65's whole-message candidate
count is zero under the pinned API's documented offset policy; direct BDS65
testing uses its actual reader at the correct five-bit offset and does not
pretend that inference succeeded.

D001 is the only whole-message acceptance exception. Its classifier requires
oracle rejection and an exact independently constructed full standard Comm-D
answer, including polynomial syndrome, address, raw fields and the complete
JSON key set. Every classified D001 instance is retained. All other oracle
disagreements fail the component. D002–D011 are not blanket exemptions: their
compatibility view must match the oracle exactly.

`tests/evidence/message-differential/summary.json` contains per-branch counts,
coverage failures, mismatch-path counts, input/output digests and source
hashes. `mismatches.jsonl.gz` and `direct-mismatches.jsonl.gz` contain every
finding, complete inputs and both outputs; no sampling or first-error cutoff
is applied. `standard-differences.jsonl.gz` retains every standard/oracle-view
difference. Full metadata, generated assignments, the structured CSV and both
programs' raw output streams are retained as compressed artifacts. The parent
campaign's component statuses and command output are stored separately under
`tests/evidence/differential-campaign/`.

These files are implementation and test work awaiting the user's requested
freeze proposal. Their existence does not assert that the campaign or the
final proof gate passes; consult the retained command result.

# Observed diagnostic results

Executed by the complete diagnostic campaign retained in `tests/evidence/differential-campaign/run.log`.
The campaign failed on one new frozen-model omission: BDS10 DTE byte order. These coverage counts do not claim a passing differential suite.

The message component compared **576,164 complete frames**: 172,432 corpus frames, 100,000 generated frames (50,050 intact, 25,310 one-bit corruptions, 24,640 two-bit corruptions), and 303,732 structured Comm-B contexts. There were 549,557 exact oracle-view matches, 9,372 narrowly classified D001 Comm-D differences, and 17,235 BDS10 DTE mismatches. Direct named-register comparisons added 101,244 cases: 95,504 exact matches and 5,740 DTE mismatches. No branch-cardinality checks failed.

Every mismatch, complete input and both outputs is retained in `tests/evidence/message-differential/mismatches.jsonl.gz` or `direct-mismatches.jsonl.gz`. All new complete-frame mismatches have the sole path `/oracle/bds10/dte`: 5,745 in each of DF20 matching-altitude, DF20 missing-altitude and DF21 structured contexts. The corpus and the 100,000 generated messages have zero unclassified mismatches. All 5,740 new direct mismatches have the sole path `/dte`. The 60,134 standard/oracle-view differences are retained separately and are never used as compatibility exemptions.

## Downlink formats

Inputs are classified by the final wire DF after corruption. Unsupported DFs are retained as rejection tests. DF24–31 are intentionally accepted by the standard decoder and rejected by the oracle under D001.

| DF | Inputs | Lean accepted | Oracle accepted | Unclassified | D001 |
| --- | ---: | ---: | ---: | ---: | ---: |
| 0 | 30,058 | 30,058 | 30,058 | 0 | 0 |
| 1 | 320 | 0 | 0 | 0 | 0 |
| 2 | 169 | 0 | 0 | 0 | 0 |
| 3 | 185 | 0 | 0 | 0 | 0 |
| 4 | 17,645 | 17,645 | 17,645 | 0 | 0 |
| 5 | 11,616 | 11,616 | 11,616 | 0 | 0 |
| 6 | 131 | 0 | 0 | 0 | 0 |
| 7 | 116 | 0 | 0 | 0 | 0 |
| 8 | 142 | 0 | 0 | 0 | 0 |
| 9 | 120 | 0 | 0 | 0 | 0 |
| 10 | 126 | 0 | 0 | 0 | 0 |
| 11 | 46,966 | 46,966 | 46,966 | 0 | 0 |
| 12 | 112 | 0 | 0 | 0 | 0 |
| 13 | 130 | 0 | 0 | 0 | 0 |
| 14 | 11 | 0 | 0 | 0 | 0 |
| 15 | 120 | 0 | 0 | 0 | 0 |
| 16 | 11,781 | 11,660 | 11,660 | 0 | 0 |
| 17 | 40,338 | 35,565 | 35,565 | 0 | 0 |
| 18 | 27,903 | 27,153 | 27,153 | 0 | 0 |
| 19 | 8,893 | 8,891 | 8,891 | 0 | 0 |
| 20 | 240,994 | 240,884 | 240,884 | 11,490 | 0 |
| 21 | 128,536 | 128,414 | 128,414 | 5,745 | 0 |
| 22 | 121 | 0 | 0 | 0 | 0 |
| 23 | 135 | 0 | 0 | 0 | 0 |
| 24 | 1,199 | 1,196 | 0 | 0 | 1,196 |
| 25 | 1,197 | 1,193 | 0 | 0 | 1,193 |
| 26 | 1,183 | 1,183 | 0 | 0 | 1,183 |
| 27 | 1,315 | 1,201 | 0 | 0 | 1,201 |
| 28 | 1,223 | 1,221 | 0 | 0 | 1,221 |
| 29 | 1,150 | 1,150 | 0 | 0 | 1,150 |
| 30 | 1,121 | 1,121 | 0 | 0 | 1,121 |
| 31 | 1,108 | 1,107 | 0 | 0 | 1,107 |

## ADS-B branches

All 70 selectors below have intact generated inputs and at least one accepted input from each decoder. Version selectors are reported only for TC31 subtypes0/1. Counts derive from final transmitted bytes, not pre-corruption metadata.

| Branch | Inputs | Intact generated | Lean accepted | Oracle accepted | Unclassified |
| --- | ---: | ---: | ---: | ---: | ---: |
| TC0 | 272 | 130 | 196 | 196 | 0 |
| TC1 | 249 | 130 | 194 | 194 | 0 |
| TC2 | 269 | 130 | 204 | 204 | 0 |
| TC3 | 285 | 130 | 214 | 214 | 0 |
| TC4 | 1,572 | 130 | 1,513 | 1,513 | 0 |
| TC5 | 264 | 130 | 198 | 198 | 0 |
| TC6 | 355 | 130 | 284 | 284 | 0 |
| TC7 | 2,727 | 130 | 2,658 | 2,658 | 0 |
| TC8 | 267 | 130 | 202 | 202 | 0 |
| TC9 | 261 | 130 | 188 | 188 | 0 |
| TC10 | 265 | 130 | 187 | 187 | 0 |
| TC11 | 10,671 | 130 | 10,590 | 10,590 | 0 |
| TC12 | 267 | 130 | 183 | 183 | 0 |
| TC13 | 263 | 130 | 176 | 176 | 0 |
| TC14 | 269 | 130 | 175 | 175 | 0 |
| TC15 | 284 | 130 | 189 | 189 | 0 |
| TC16 | 260 | 130 | 188 | 188 | 0 |
| TC17 | 271 | 130 | 187 | 187 | 0 |
| TC18 | 269 | 130 | 186 | 186 | 0 |
| TC19.0 | 240 | 130 | 184 | 184 | 0 |
| TC19.1 | 10,705 | 130 | 10,642 | 10,642 | 0 |
| TC19.2 | 244 | 130 | 188 | 188 | 0 |
| TC19.3 | 247 | 130 | 185 | 185 | 0 |
| TC19.4 | 249 | 130 | 188 | 188 | 0 |
| TC19.5 | 245 | 130 | 185 | 185 | 0 |
| TC19.6 | 248 | 130 | 188 | 188 | 0 |
| TC19.7 | 250 | 130 | 191 | 191 | 0 |
| TC20 | 281 | 130 | 187 | 187 | 0 |
| TC21 | 263 | 130 | 183 | 183 | 0 |
| TC22 | 258 | 130 | 181 | 181 | 0 |
| TC23 | 308 | 130 | 221 | 221 | 0 |
| TC24 | 19,126 | 130 | 19,064 | 19,064 | 0 |
| TC25 | 268 | 130 | 197 | 197 | 0 |
| TC26 | 267 | 130 | 198 | 198 | 0 |
| TC27 | 291 | 130 | 212 | 212 | 0 |
| TC28.0 | 254 | 130 | 190 | 190 | 0 |
| TC28.1 | 263 | 130 | 204 | 204 | 0 |
| TC28.2 | 236 | 130 | 183 | 183 | 0 |
| TC28.3 | 246 | 130 | 187 | 187 | 0 |
| TC28.4 | 238 | 130 | 185 | 185 | 0 |
| TC28.5 | 244 | 130 | 190 | 190 | 0 |
| TC28.6 | 249 | 130 | 190 | 190 | 0 |
| TC28.7 | 235 | 130 | 185 | 185 | 0 |
| TC29.0 | 283 | 130 | 206 | 206 | 0 |
| TC29.1 | 4,427 | 130 | 4,363 | 4,363 | 0 |
| TC29.2 | 247 | 130 | 191 | 191 | 0 |
| TC29.3 | 270 | 130 | 203 | 203 | 0 |
| TC30 | 299 | 130 | 212 | 212 | 0 |
| TC31.0.v0 | 243 | 130 | 130 | 130 | 0 |
| TC31.0.v1 | 240 | 130 | 123 | 123 | 0 |
| TC31.0.v2 | 2,331 | 130 | 2,214 | 2,214 | 0 |
| TC31.0.v3 | 235 | 130 | 121 | 121 | 0 |
| TC31.0.v4 | 242 | 130 | 125 | 125 | 0 |
| TC31.0.v5 | 248 | 130 | 132 | 132 | 0 |
| TC31.0.v6 | 239 | 130 | 125 | 125 | 0 |
| TC31.0.v7 | 240 | 130 | 124 | 124 | 0 |
| TC31.1.v0 | 251 | 130 | 125 | 125 | 0 |
| TC31.1.v1 | 238 | 130 | 120 | 120 | 0 |
| TC31.1.v2 | 718 | 130 | 604 | 604 | 0 |
| TC31.1.v3 | 244 | 130 | 130 | 130 | 0 |
| TC31.1.v4 | 228 | 130 | 128 | 128 | 0 |
| TC31.1.v5 | 233 | 130 | 128 | 128 | 0 |
| TC31.1.v6 | 239 | 130 | 120 | 120 | 0 |
| TC31.1.v7 | 238 | 130 | 126 | 126 | 0 |
| TC31.2 | 257 | 130 | 191 | 191 | 0 |
| TC31.3 | 249 | 130 | 191 | 191 | 0 |
| TC31.4 | 258 | 130 | 193 | 193 | 0 |
| TC31.5 | 265 | 130 | 200 | 200 | 0 |
| TC31.6 | 245 | 130 | 184 | 184 | 0 |
| TC31.7 | 233 | 130 | 189 | 189 | 0 |

## Comm-B registers

Each target payload was wrapped into three complete messages. Candidate counts include all complete-message corpus/generated/structured inputs, while direct counts are independent named-register checks before the score gate. BDS65 has zero inferred candidates because of the pinned whole-message API's offset policy; its direct reader is exercised at the correct offset. `summary.json` also reports rejected inputs, complete-message candidate opportunities and refinement checks.

| Register | Targeted messages | Lean inferred | Oracle inferred | Direct inputs | Direct Lean accepted | Direct oracle accepted | Direct mismatches |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 05 | 21,540 | 26,766 | 26,766 | 7,180 | 5,839 | 5,839 | 0 |
| 10 | 21,612 | 17,861 | 17,861 | 7,204 | 5,813 | 5,813 | 5,740 |
| 17 | 21,681 | 17,693 | 17,693 | 7,227 | 5,778 | 5,778 | 0 |
| 18 | 21,936 | 17,435 | 17,435 | 7,312 | 5,810 | 5,810 | 0 |
| 19 | 21,936 | 17,379 | 17,379 | 7,312 | 5,796 | 5,796 | 0 |
| 20 | 21,522 | 23,442 | 23,442 | 7,174 | 7,169 | 7,169 | 0 |
| 21 | 21,576 | 35,032 | 35,032 | 7,192 | 5,751 | 5,751 | 0 |
| 30 | 21,654 | 21,870 | 21,870 | 7,218 | 7,213 | 7,213 | 0 |
| 40 | 21,720 | 19,890 | 19,890 | 7,240 | 5,791 | 5,791 | 0 |
| 44 | 21,690 | 7,572 | 7,572 | 7,230 | 5,775 | 5,775 | 0 |
| 45 | 21,729 | 10,281 | 10,281 | 7,243 | 5,775 | 5,775 | 0 |
| 50 | 21,846 | 12,003 | 12,003 | 7,282 | 5,835 | 5,835 | 0 |
| 60 | 21,711 | 25,253 | 25,253 | 7,237 | 5,789 | 5,789 | 0 |
| 65 | 21,579 | 0 | 0 | 7,193 | 5,852 | 5,852 | 0 |

The exhaustive machine-readable source is `tests/evidence/message-differential/summary.json`; `coverage.csv` is its long-form coverage projection. Neither source outputs nor mismatch records are sampled.
