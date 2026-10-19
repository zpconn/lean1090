# Generation 16: live decode-plus-CPR instruction diagnostic

The full corpus loop executed **17,998,526,291 collected instructions**. Numeric
geography and its rational/Float conversion boundary remain the largest
individual category at 30.91% after separating the decoder's stages.
The combined decoder contributes 59.74%. These are untimed instruction
observations, not throughput estimates or predictions of an optimization's gain.

The timed source is `1593898c4425fb174ba4085ab68691feba28124e`; the diagnostic
checkout is the source-equivalent artifact commit
`b4765cc1e07a758bc4661c4f6f513deb39672b9f`. Actual worker SHA-256:
`26e79af2c955a0dc8a0fdb1107d77b8c2b93ad31025fdd9e32112a37ee5c416f`.
The unchanged diagnostic driver reuses 21 production/model objects from all
22 freshly timed native sets, replacing only the worker object. The
[source/native review](../tests/evidence/diagnostics/gen16-cpr/independent-review/source-review.json)
checks the live generated C and linked functions. No production code, proofs,
frozen files or build configuration changed during diagnosis.

The collected path mirrors the frozen benchmark: immediate `Impl.decode`,
tracking projection, `Impl.CPR.Policy.streamStep`, then array append. Its timed
loop does not call the batch `Impl.decodePositions` API. Preallocation and the
empty state are outside the collection root. Full decoded output and final
state remain live through its return; the loop/output category includes that
diagnostic return packaging. Timestamp/airport loading, output consumption,
and batch validation are outside collection. Eager module initialization is
outside; first-use lazy constants reached by the root remain included.

All 172,432 timestamp/input rows and 6,903 airport coordinates match the
frozen worker byte-for-byte. Empty state, absent reference and the always-false
reference-update callback are unchanged. Every per-message tracking row and
the final worker state projection match exactly: 172,432 bit-identical rows,
including 11,347 positions. The differential tolerance remains 1e-9 degrees;
bit identity is reported for these particular rows. Complete final
`StreamState` and every routed position also equal the actual batch API after
collection. The final state has 29 aircraft, two with positions, and no global
reference; this corpus alone does not cover worldwide tracking policies.

The complete message digest equals the same-generation decode diagnostic:
172,432 messages, 732,573,131 representation bytes,
FNV-1a-64 `18440978423862441655`. The complete state has
15,785 representation bytes, digest
`1856826440252506745`. Routed reports include 10,408
airborne, 2,556 surface and 37,421 other messages.
[Full validation](../tests/evidence/diagnostics/gen16-cpr/retained/validation/summary.json)
retains commands, complete row/state checks and unchanged input hashes.

The following rows form one **exclusive self-cost partition**. The five
decoder rows replace its combined subtotal of 10,751,704,753;
they must not be added to that subtotal again. Runtime, allocator, rational
and GMP descendants inherit their actual calling stage.

| Stage | Collected Ir | Share |
|---|---:|---:|
| Numeric geography and conversion | 5,562,629,612 | 30.9060% |
| Decoder: Comm-B inference | 3,619,909,896 | 20.1123% |
| Decoder: frame/CRC | 3,496,210,851 | 19.4250% |
| Decoder: semantic/oracle values | 3,378,916,351 | 18.7733% |
| Motion policy, excluding numeric geography | 1,144,291,780 | 6.3577% |
| Airborne pairing policy, excluding motion/geography | 312,626,183 | 1.7370% |
| Decoder: ADS-B fields | 210,374,074 | 1.1688% |
| Tracking projection | 79,592,517 | 0.4422% |
| Remaining state/tracking control | 68,567,621 | 0.3810% |
| Surface reference policy, excluding geography | 55,281,627 | 0.3071% |
| Decoder: output/model control | 46,293,581 | 0.2572% |
| Loop/output/retained-return control | 23,832,198 | 0.1324% |
| **Total** | **17,998,526,291** | **100%** |

There are no ambiguous merged contexts or unexplained outside-root events.
Exactly 6 libm/PLT contexts totaling 253 self instructions lack a positive
path from the collection root but retain explicit caller chains containing
that exact root. The previously reviewed algorithm applies the same stage
transitions along those chains. Incoming edges from other unreachable nodes
do not establish root reachability. Foreign chains and remaining outside-root
events still fail. All eight attribution fixtures pass. This generation's
tooling only corrects the recovery description to say “path”; the algorithm
is unchanged. [Complete compressed analysis](../tests/evidence/diagnostics/gen16-cpr/analysis/analysis.json.gz),
[decoder subpartition](../tests/evidence/diagnostics/gen16-cpr/decoder-stages-summary.json).

These helper observations are **overlapping inclusive costs**. They nest
inside the exclusive rows and each other; do not sum them into another total.

| Live helper | Native entries | Inclusive Ir |
|---|---:|---:|
| `streamStep` | 50,385 | 7,143,396,823 |
| `toFloat` | 103,138 | 4,761,033,381 |
| `haversineFloat` | 25,256 | 4,684,953,000 |
| `stepAirborne` | 10,408 | 3,879,585,480 |
| `stepSurface` | 2,556 | 3,195,243,722 |
| `validMotion` | 10,405 | 3,148,919,004 |
| `nearestAirport` | 2 | 2,877,169,405 |
| `Numeric-geography Binary64.round` | 103,138 | 2,641,536,498 |
| `Numeric-geography Binary64.powerTwo` | 460,693 | 1,738,677,460 |
| `Numeric-geography Binary64.exponent` | 206,276 | 888,945,908 |
| `decodeGlobalFloat` | 10,405 | 416,547,955 |
| `decodeLocalFloat` | 1,057 | 122,776,774 |

`toFloat` rounds an exact rational, obtains its exponent and binary64 bit
pattern, then uses `Float.ofBits`. Haversine converts four coordinates;
geographic outputs return to exact rationals through `Binary64.fromBits`.
The two airport lookups scan the pinned list. These observations retain the
distinction between proved policy and tested Float geography. They add no
new correctness claim. Sources: [CPRFloat](../Impl/CPRFloat.lean),
[CPRPolicy](../Impl/CPRPolicy.lean), [Binary64](../Impl/Binary64.lean).

The largest direct conversion/normalization edges within numeric geography
are below. Each callee-inclusive row is from an actual edge; parent calls,
rational normalization and nested GCD/power costs overlap. All 85
grouped edges across stages, and their full contexts, are retained in the
[numeric supplement](../tests/evidence/diagnostics/gen16-cpr/numeric-contexts.json.gz).
The [power-only extraction](../tests/evidence/diagnostics/gen16-cpr/power-contexts.json)
is retained separately. Neither extraction measures exponent frequency or
future table-hit coverage. Reducing power construction would not by itself
remove all rounding or rational normalization work.

| Direct caller → callee, numeric geography | Calls | Inclusive Ir |
|---|---:|---:|
| `lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 101,024 | 4,671,183,961 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `lp_lean1090_Lean1090_Impl_Binary64_round` | 103,138 | 2,641,536,498 |
| `l_Rat_div` → `l_Rat_mul` | 467,999 | 2,271,389,709 |
| `l_Rat_mul` → `lean_nat_gcd` | 1,238,594 | 1,985,872,767 |
| `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` → `l_Rat_div` | 261,723 | 1,022,143,267 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `l_Rat_div` | 103,138 | 801,150,595 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `l_Rat_div` | 103,138 | 798,815,828 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 103,138 | 607,372,448 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 103,138 | 607,360,047 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `l_Rat_mul` | 103,138 | 545,519,030 |
| `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` → `lean_nat_pow` | 460,693 | 462,841,885 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `lp_lean1090_Lean1090_Impl_Binary64_exponent` | 103,138 | 450,879,688 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `lp_lean1090_Lean1090_Impl_Binary64_exponent` | 103,138 | 438,066,220 |
| `l_Rat_div` → `l_Rat_inv` | 467,999 | 346,975,989 |
| `lp_lean1090_Lean1090_Impl_Binary64_fromBits` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 48,140 | 283,566,903 |

The actual frozen worker was sampled separately before diagnostic native or
profile workers. Decode then CPR ran sequentially on CPU 0 using `cpu-clock:u`,
199 Hz and 16,384-byte DWARF stacks. All 198 protected inputs stayed unchanged.
CPR recorded 317 samples: 119 have a visible CPR-loop ancestor and
198 are excluded. Unknown frames occur in 303 stacks, with
0 unknown included leaves. Both report headers explicitly state zero lost
samples. Missing/erased ancestors make these conditional observations unsuitable
for whole-workload timing shares. One-pass durations are not benchmark results.
[Capture and exclusions](../tests/evidence/diagnostics/gen16-cpr/perf/completion.json).

Callgrind uses `--instr-atstart=no`, `--collect-atstart=no` and
`--separate-callers=40`. Its prepared/run/decoded/consume handshake and every
control acknowledgement are retained. The primary raw dump SHA-256 is
`ba893badd457a5bce7125be33a9370ef2d5f5a0657fcb2ff95c1ce50cb73a0bb`. Instruction profiling may overlap other instruction
diagnostics; none is a timing measurement.

The [archive](../tests/evidence/diagnostics/gen16-cpr/archive-manifest.json)
retains 52 original/tooling files in 6,844,293 bytes,
with deterministic compressed and decompressed hashes. Large analysis outputs
are [separately compressed](../tests/evidence/diagnostics/gen16-cpr/analysis-retention.json).
Rebuildable binaries stay outside Git with exact hashes and build provenance.
No old artifacts are recopied or replaced. The optional archive perf-directory
argument preserves its historical default and passed focused regression and
independent tooling review. [Producer validation](../tests/evidence/diagnostics/gen16-cpr/validation.json)
binds this report and all inputs. Independent raw-accounting review remains
the condition for selecting the next optimization.
