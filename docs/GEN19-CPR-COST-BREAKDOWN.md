# Generation 19: live decode-plus-CPR instruction diagnostic

The full corpus loop executed **11,916,756,598 collected instructions**. Decoder: frame/CRC is the largest individual
category at 29.34% after separating the decoder's stages.
The combined decoder contributes 80.48%. These are untimed instruction
observations, not throughput estimates or predictions of an optimization's gain.

The timed source is `79cc25b8c6f104da94e2b532439fe6e9b47f72ea`; the diagnostic
checkout is the source-equivalent artifact commit
`3f3478c62a1db4c43b40cd8464bdf1787e10976f`. Actual worker SHA-256:
`c8636e3760f9829c836a44befe239cb1f0334be6d46f93e100a4d97088f6fb7a`.
The unchanged diagnostic driver reuses 21 production/model objects from all
22 freshly timed native sets, replacing only the worker object. The
[source/native review](../tests/evidence/diagnostics/gen19-cpr/independent-review/source-review.json)
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
[Full validation](../tests/evidence/diagnostics/gen19-cpr/retained/validation/summary.json)
retains commands, complete row/state checks and unchanged input hashes.

The following rows form one **exclusive self-cost partition**. The five
decoder rows replace its combined subtotal of 9,590,711,983;
they must not be added to that subtotal again. Runtime, allocator, rational
and GMP descendants inherit their actual calling stage.

| Stage | Collected Ir | Share |
|---|---:|---:|
| Decoder: frame/CRC | 3,496,267,091 | 29.3391% |
| Decoder: Comm-B inference | 3,068,644,285 | 25.7507% |
| Decoder: semantic/oracle values | 2,790,365,793 | 23.4155% |
| Numeric geography and conversion | 1,029,437,260 | 8.6386% |
| Motion policy, excluding numeric geography | 849,188,964 | 7.1260% |
| Airborne pairing policy, excluding motion/geography | 220,103,710 | 1.8470% |
| Decoder: ADS-B fields | 189,118,102 | 1.5870% |
| Tracking projection | 79,582,787 | 0.6678% |
| Remaining state/tracking control | 68,564,231 | 0.5754% |
| Surface reference policy, excluding geography | 55,335,465 | 0.4644% |
| Decoder: output/model control | 46,316,712 | 0.3887% |
| Loop/output/retained-return control | 23,832,198 | 0.2000% |
| **Total** | **11,916,756,598** | **100%** |

There are no ambiguous merged contexts or unexplained outside-root events.
Exactly 6 libm/PLT contexts totaling 253 self instructions lack a positive
path from the collection root but retain explicit caller chains containing
that exact root. The previously reviewed algorithm applies the same stage
transitions along those chains. Incoming edges from other unreachable nodes
do not establish root reachability. Foreign chains and remaining outside-root
events still fail. All eight attribution fixtures pass. The same previously reviewed
attribution algorithm is used unchanged. [Complete compressed analysis](../tests/evidence/diagnostics/gen19-cpr/analysis/analysis.json.gz),
[decoder subpartition](../tests/evidence/diagnostics/gen19-cpr/decoder-stages-summary.json).

These helper observations are **overlapping inclusive costs**. They nest
inside the exclusive rows and each other; do not sum them into another total.

| Live helper | Native entries | Inclusive Ir |
|---|---:|---:|
| `streamStep` | 50,385 | 2,222,629,630 |
| `stepAirborne` | 10,408 | 1,626,312,415 |
| `validMotion` | 10,405 | 1,109,080,285 |
| `motion_policy Binary64.round` | 31,209 | 578,799,591 |
| `stepSurface` | 2,556 | 527,752,984 |
| `haversineFloat` | 25,256 | 510,649,935 |
| `toFloat` | 103,138 | 505,586,984 |
| `nearestAirport` | 2 | 468,524,356 |
| `numeric_geography Binary64.fromBits` | 48,160 | 362,241,366 |
| `decodeGlobalFloat` | 10,405 | 296,618,021 |
| `airborne_pairing_policy Binary64.round` | 10,421 | 148,227,959 |
| `motion_policy Binary64.exponent` | 31,209 | 80,333,368 |
| `decodeLocalFloat` | 1,057 | 29,486,248 |
| `airborne_pairing_policy Binary64.exponent` | 10,421 | 6,182,592 |
| `motion_policy Binary64.powerTwo` | 62,418 | 5,492,784 |
| `numeric_geography Binary64.powerTwo` | 48,141 | 4,236,408 |
| `airborne_pairing_policy Binary64.powerTwo` | 20,842 | 1,834,096 |

The current `toFloat` returns positive zero for zero and uses integer bit
assembly for nonzero values with numerator magnitude below 2^53, denominator
exactly 2^k and k at most 1074. Every other value calls `toFloatFallback`, which
retains the original rational rounding, exponent and bit-pattern construction.
Both paths use `Float.ofBits`. Haversine converts four coordinates;
geographic outputs return to exact rationals through `Binary64.fromBits`.
The two airport lookups scan the pinned list. These observations retain the
distinction between proved policy and tested Float geography. They add no
new correctness claim. Sources: [CPRFloat](../Impl/CPRFloat.lean),
[CPRPolicy](../Impl/CPRPolicy.lean), [Binary64](../Impl/Binary64.lean).

The following actual direct edges keep wrapper and fallback calls separate.
Their inclusive costs overlap and are already contained in the exclusive
partition above. No accepted-dyadic population is inferred from these costs:
wrapper entries that do not call fallback include zero as well as admitted
dyadics. Inlined packing has no separately callable native boundary. The
current source/native review checks both guarded packing and the original
fallback; first-use scalar constants remain part of collection when reached.

| Stage | Direct conversion edge | Calls | Inclusive Ir |
|---|---|---:|---:|
| numeric_geography | `lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 101,024 | 496,880,896 |
| numeric_geography | `lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 2,114 | 8,706,088 |

The retained profile has 0 actual incoming calls to the source-verified
callable `toFloatFallback` boundary. This is an observation for this corpus;
the fallback remains required for arbitrary rational inputs. The separate
[remaining-conversion contexts](../tests/evidence/diagnostics/gen19-cpr/remaining-conversion-contexts.json)
reconcile `fromBits`, rounding and exponent calls against the complete helper
groups, preserving the caller chains that distinguish policy arithmetic from
conversion fallback. Their costs overlap and do not imply a timing gain.

The largest direct conversion/normalization edges within numeric geography
are below. Each callee-inclusive row is from an actual edge; parent calls,
rational normalization and nested GCD/power costs overlap. All 62
grouped edges across stages, and their full contexts, are retained in the
[numeric supplement](../tests/evidence/diagnostics/gen19-cpr/numeric-contexts.json.gz).
The [power-only extraction](../tests/evidence/diagnostics/gen19-cpr/power-contexts.json)
is retained separately. Those inclusive costs do not measure exponent frequency or table-hit coverage.
The separate direct-edge census below observes the lookup/fallback branch
populations. Rounding and rational normalization remain present.

| Direct caller → callee, numeric geography | Calls | Inclusive Ir |
|---|---:|---:|
| `lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 101,024 | 496,880,896 |
| `lp_lean1090_Lean1090_Impl_Binary64_fromBits` → `l_Rat_mul` | 48,160 | 260,781,074 |
| `l_Rat_mul` → `lean_nat_gcd` | 96,320 | 156,836,205 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 2,114 | 8,706,088 |
| `lp_lean1090_Lean1090_Impl_Binary64_fromBits` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 48,140 | 4,236,320 |
| `l_Int_pow` → `lean_nat_pow` | 4 | 4,085 |
| `l_BitVec_ofNat` → `lean_nat_pow` | 2 | 2,058 |
| `l_Float_Model_UnpackedFloat_ofScientific` → `lean_nat_pow` | 1 | 1,025 |
| `l_Float_Model_UnpackedFloat_pack` → `lean_nat_pow` | 1 | 1,022 |
| `l_Float_Model_Format_exponentBias` → `lean_nat_pow` | 1 | 1,021 |
| `_init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 1 | 88 |

The existing immutable table contains every exponent from −1074 through 1023.
The independent native review follows actual module initialization into its
2,098-entry constructor before the worker loop. Each entry calls the original
formula directly; lookup does not recursively construct the table.
Inside this collected loop, actual lookup entries and direct calls to the
retained formula are:

| Calling stage | Lookup entries | Formula fallback calls | Table branch calls |
|---|---:|---:|---:|
| numeric_geography | 48,141 | 0 | 48,141 |
| decoder | 1,324 | 0 | 1,324 |
| motion_policy | 62,418 | 0 | 62,418 |
| airborne_pairing_policy | 20,842 | 0 | 20,842 |
| **Total** | **132,725** | **0** | **132,725** |

The linked lookup has two mutually exclusive fallback sites and at most one
formula call per lookup. Subtracting the observed direct fallback calls from
lookup entries therefore identifies table-branch calls for this corpus; it
is not inferred from cost. There are 0 observed table-entry constructor calls
inside collection. Construction occurs eagerly before the root, and its
startup work is not claimed to be zero. No claim is made about all possible
exponents. [Exact contexts and source binding](../tests/evidence/diagnostics/gen19-cpr/table-contexts.json.gz).

The actual frozen worker was sampled separately before diagnostic native or
profile workers. Decode then CPR ran sequentially on CPU 0 using `cpu-clock:u`,
199 Hz and 16,384-byte DWARF stacks. All 283 protected inputs stayed unchanged.
CPR recorded 240 samples: 117 have a visible CPR-loop ancestor and
123 are excluded. Unknown frames occur in 233 stacks, with
5 unknown included leaves. Both report headers explicitly state zero lost
samples. Missing/erased ancestors make these conditional observations unsuitable
for whole-workload timing shares. One-pass durations are not benchmark results.
[Capture and exclusions](../tests/evidence/diagnostics/gen19-cpr/perf/completion.json).

Callgrind uses `--instr-atstart=no`, `--collect-atstart=no` and
`--separate-callers=40`. Its prepared/run/decoded/consume handshake and every
control acknowledgement are retained. The primary raw dump SHA-256 is
`c0b839be0a7ce762e3383afb8ddc229319f41fd3e02c4af358752338bb68fc5f`. Instruction profiling may overlap other instruction
diagnostics; none is a timing measurement.

The [archive](../tests/evidence/diagnostics/gen19-cpr/archive-manifest.json)
retains 52 original/tooling files in 6,471,444 bytes,
with deterministic compressed and decompressed hashes. Large analysis outputs
are [separately compressed](../tests/evidence/diagnostics/gen19-cpr/analysis-retention.json).
Rebuildable binaries stay outside Git with exact hashes and build provenance.
No old artifacts are recopied or replaced. The previously reviewed archive helper is reused unchanged with an explicit
`perf-gen19-cpr` directory. [Producer validation](../tests/evidence/diagnostics/gen19-cpr/validation.json)
binds this report and all inputs. Independent raw-accounting review remains
the condition for selecting the next optimization.
