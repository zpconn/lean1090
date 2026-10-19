Generation 9 changes the live frame field extractor for widths below 64. It performs the exact natural-number shift before conversion to UInt64, then applies the native low mask and returns its proved-bounded value. The original natural power/division/BitVec reduction remains for wider fields. The universal equality covers arbitrary total, start, width and word values, including large shifts and truncating subtraction. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen9/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen9/source-inspection/).

The actual linked decodeFrame retains 26 static calls to the same live field function; these are call sites, not per-message counts. The timed-worker narrow branch shifts before conversion and masking, while the wide branch retains the original power/division path. The existing mask helper is inlined. A separate recount of gen8/gen9 profiles below preserves actual field caller contexts and direct outgoing helper counts. Missing native edges do not mean zero inlined work or remove arbitrary-input fallback behavior.

The live syndrome fold, checksum, byte fold, field extractor and field-packing helper are retained as explicit nested anchors. Their incoming inclusive costs overlap each other and the exclusive stage totals; they are not additive subdivisions. Complete helper self costs remain the exact partition. Generation 8 affine guards and generation 7 exact integer score decisions remain live and unchanged. Rational center/envelope/mass are pure reference APIs used only by the post-collection census. The unchanged software-score callback remains lazy.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this accepted corpus. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution. Integer choose/common-denominator/pair-fold and fallback native counts remain reconciled with the separately checked register populations.

All immutable density and Mach tables are initialized before main. Their construction is outside collected decoder roots and warmed benchmark loops. The Mach accessor remains inlined into its callers. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied.

The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and archived benchmark documentation; no host-wide isolation is claimed. Of 324 samples, 114 have a visible decoder ancestor and 210 are excluded; 317 stacks contain an unknown frame and 0 included leaves are unknown. Most recorded samples lack a usable decoder ancestor, so these conditional observations cannot allocate whole-decoder time reliably. The exact capture conditions and reported zero-lost counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen9/perf/README.md). These are diagnostics, not benchmark timings.

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

### Live frame-field observations

The native `field` entry populations match between generations. The following totals retain actual caller contexts and direct outgoing helper edges; the machine mask and small-Nat operations can inline into `field`. All raw records and checks are in [field-caller-contexts.json](../tests/evidence/diagnostics/gen9/field-caller-contexts.json). Incoming and outgoing inclusive counts overlap and must not be added to stage totals.

| Generation / family / stage | field calls | field self Ir | field inclusive Ir |
|---|---:|---:|---:|
| Gen8 / adsb / frame_crc | 201,540 | 12,596,250 | 846,393,810 |
| Gen8 / commb / frame_crc | 286,284 | 17,845,036 | 1,115,688,769 |
| Gen8 / other / frame_crc | 393,795 | 24,420,678 | 856,810,510 |
| Gen9 / adsb / frame_crc | 201,540 | 12,999,330 | 237,771,724 |
| Gen9 / commb / frame_crc | 286,284 | 18,035,892 | 281,000,668 |
| Gen9 / other / frame_crc | 393,795 | 25,143,612 | 45,646,386 |

| Generation / family / stage | Direct callee | Calls | Inclusive Ir |
|---|---|---:|---:|
| Gen8 / adsb / frame_crc | `lean_nat_pow` | 201,540 | 211,739,310 |
| Gen8 / adsb / frame_crc | `l_BitVec_ofNat` | 201,540 | 354,307,488 |
| Gen8 / adsb / frame_crc | `lean_nat_big_div` | 201,540 | 232,884,342 |
| Gen8 / adsb / frame_crc | `lean_nat_big_shiftr` | 0 | 0 |
| Gen8 / adsb / frame_crc | `lean_uint64_of_big_nat` | 0 | 0 |
| Gen8 / commb / frame_crc | `lean_nat_pow` | 286,284 | 311,730,967 |
| Gen8 / commb / frame_crc | `l_BitVec_ofNat` | 286,284 | 434,671,968 |
| Gen8 / commb / frame_crc | `lean_nat_big_div` | 286,284 | 301,913,666 |
| Gen8 / commb / frame_crc | `lean_nat_big_shiftr` | 0 | 0 |
| Gen8 / commb / frame_crc | `lean_uint64_of_big_nat` | 0 | 0 |
| Gen8 / other / frame_crc | `lean_nat_pow` | 393,795 | 396,234,889 |
| Gen8 / other / frame_crc | `l_BitVec_ofNat` | 393,795 | 405,272,508 |
| Gen8 / other / frame_crc | `lean_nat_big_div` | 26,940 | 26,221,815 |
| Gen8 / other / frame_crc | `lean_nat_big_shiftr` | 0 | 0 |
| Gen8 / other / frame_crc | `lean_uint64_of_big_nat` | 0 | 0 |
| Gen9 / adsb / frame_crc | `lean_nat_pow` | 0 | 0 |
| Gen9 / adsb / frame_crc | `l_BitVec_ofNat` | 0 | 0 |
| Gen9 / adsb / frame_crc | `lean_nat_big_div` | 0 | 0 |
| Gen9 / adsb / frame_crc | `lean_nat_big_shiftr` | 201,540 | 117,553,132 |
| Gen9 / adsb / frame_crc | `lean_uint64_of_big_nat` | 100,770 | 89,786,052 |
| Gen9 / commb / frame_crc | `lean_nat_pow` | 0 | 0 |
| Gen9 / commb / frame_crc | `l_BitVec_ofNat` | 0 | 0 |
| Gen9 / commb / frame_crc | `lean_nat_big_div` | 0 | 0 |
| Gen9 / commb / frame_crc | `lean_nat_big_shiftr` | 286,284 | 161,444,235 |
| Gen9 / commb / frame_crc | `lean_uint64_of_big_nat` | 95,428 | 85,011,497 |
| Gen9 / other / frame_crc | `lean_nat_pow` | 0 | 0 |
| Gen9 / other / frame_crc | `l_BitVec_ofNat` | 0 | 0 |
| Gen9 / other / frame_crc | `lean_nat_big_div` | 0 | 0 |
| Gen9 / other / frame_crc | `lean_nat_big_shiftr` | 26,940 | 14,769,945 |
| Gen9 / other / frame_crc | `lean_uint64_of_big_nat` | 5,388 | 4,800,705 |

Only collected native edges are reported. The original wide-width formula remains in the live function, as independently verified in the fresh source/native review. An unobserved edge in this corpus does not eliminate arbitrary-width fallback semantics or imply zero inlined work. These are instruction observations, not a throughput prediction.

