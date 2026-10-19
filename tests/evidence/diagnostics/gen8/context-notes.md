Generation 8 skips rational multiplication by one and addition of zero in the live payloadValue present branch. Extraction and status checks are unchanged. The universally proved identity helper is inlined into payloadValue; its absent standalone native boundary does not mean zero affine computation. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen8/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen8/source-inspection/).

The actual linked payloadValue tests scale equality to one and offset equality to zero, with direct Rat.mul and Rat.add calls only on their nonidentity branches. A separate recount of the retained gen7/gen8 family profiles below reports the actual direct arithmetic edges and unchanged payloadValue entry populations. No branch counts are inferred from an absent inlined symbol.

Generation 7 exact integer score decisions remain live: commonDenominator and the integer pair-fold entry are reconciled with actual choose counts in every family and register probe. Rational center/envelope/mass remain pure reference APIs used by the post-collection shadow census, not the live choose fast path. The unchanged full-software-score callback remains lazy. Candidate and score probes overlap each other and the full decoder.

Generation 6 sharing remains live: one syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this corpus population. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution.

All immutable density and Mach tables are initialized before main. Their construction is outside collected decoder roots and warmed benchmark loops. The Mach accessor remains inlined into its callers. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied.

The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and archived benchmark documentation; no host-wide isolation is claimed. Of 323 samples, 160 have a visible decoder ancestor and 163 are excluded; 320 stacks contain an unknown frame and 19 included leaves are unknown. These conditional observations cannot allocate whole-decoder time reliably. The exact capture conditions and reported zero-lost counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen8/perf/README.md). These are diagnostics, not benchmark timings.

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

### Live affine-value observations

The same native `payloadValue` entry populations are observed in both generations. The direct `Rat.mul` and `Rat.add` edges below are actual collected calls; the inlined affine helper has no separate native boundary. Full caller contexts, self costs and edge records are retained in [affine-caller-contexts.json](../tests/evidence/diagnostics/gen8/affine-caller-contexts.json). Incoming and outgoing inclusive costs overlap and must not be added to one another or to stage totals.

| Generation / family / stage | payloadValue calls | payloadValue inclusive Ir | Direct mul calls | Direct mul inclusive Ir | Direct add calls | Direct add inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| Gen7 / adsb / semantic_oracle_values | 462,367 | 2,470,940,022 | 458,078 | 1,486,912,778 | 458,078 | 823,558,847 |
| Gen7 / commb / semantic_oracle_values | 1,058,480 | 5,710,418,332 | 1,048,288 | 3,340,150,441 | 1,048,288 | 1,802,422,565 |
| Gen7 / commb / commb_inference | 78,306 | 431,668,285 | 75,314 | 242,379,993 | 75,314 | 130,025,797 |
| Gen8 / adsb / semantic_oracle_values | 462,367 | 167,625,084 | 2,467 | 7,999,568 | 0 | 0 |
| Gen8 / commb / semantic_oracle_values | 1,058,480 | 1,683,457,990 | 322,168 | 1,037,767,756 | 31,026 | 53,468,882 |
| Gen8 / commb / commb_inference | 78,306 | 249,471,187 | 57,908 | 186,267,668 | 0 | 0 |

These counts do not separate every scale/offset assignment: missing-status fields also avoid arithmetic. The actual generated C and linked assembly independently establish the guarded identity branches. This is an instruction diagnostic, not a throughput prediction.

