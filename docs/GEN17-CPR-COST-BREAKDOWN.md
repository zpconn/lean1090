# Generation 17: live decode-plus-CPR instruction diagnostic

The full corpus loop executed **15,901,328,066 collected instructions**. Numeric geography and conversion is the largest individual
category at 24.26% after separating the decoder's stages.
The combined decoder contributes 67.59%. These are untimed instruction
observations, not throughput estimates or predictions of an optimization's gain.

The timed source is `0f7882f3f949118c6871a40bc012bb8a957a6a3d`; the diagnostic
checkout is the source-equivalent artifact commit
`9d441eb3bdbaa17adbb289c3d82afe20307ad28b`. Actual worker SHA-256:
`04b075aff3a04861d9cdb0e8d7388fe43a9fdfc0dc3a317de6a4525edb213a13`.
The unchanged diagnostic driver reuses 21 production/model objects from all
22 freshly timed native sets, replacing only the worker object. The
[source/native review](../tests/evidence/diagnostics/gen17-cpr/independent-review/source-review.json)
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
[Full validation](../tests/evidence/diagnostics/gen17-cpr/retained/validation/summary.json)
retains commands, complete row/state checks and unchanged input hashes.

The following rows form one **exclusive self-cost partition**. The five
decoder rows replace its combined subtotal of 10,747,390,229;
they must not be added to that subtotal again. Runtime, allocator, rational
and GMP descendants inherit their actual calling stage.

| Stage | Collected Ir | Share |
|---|---:|---:|
| Numeric geography and conversion | 3,857,692,962 | 24.2602% |
| Decoder: Comm-B inference | 3,615,569,375 | 22.7375% |
| Decoder: frame/CRC | 3,496,197,757 | 21.9868% |
| Decoder: semantic/oracle values | 3,378,943,123 | 21.2494% |
| Motion policy, excluding numeric geography | 848,744,822 | 5.3376% |
| Airborne pairing policy, excluding motion/geography | 220,102,598 | 1.3842% |
| Decoder: ADS-B fields | 210,393,405 | 1.3231% |
| Tracking projection | 79,587,280 | 0.5005% |
| Remaining state/tracking control | 68,573,642 | 0.4312% |
| Surface reference policy, excluding geography | 55,404,335 | 0.3484% |
| Decoder: output/model control | 46,286,569 | 0.2911% |
| Loop/output/retained-return control | 23,832,198 | 0.1499% |
| **Total** | **15,901,328,066** | **100%** |

There are no ambiguous merged contexts or unexplained outside-root events.
Exactly 6 libm/PLT contexts totaling 253 self instructions lack a positive
path from the collection root but retain explicit caller chains containing
that exact root. The previously reviewed algorithm applies the same stage
transitions along those chains. Incoming edges from other unreachable nodes
do not establish root reachability. Foreign chains and remaining outside-root
events still fail. All eight attribution fixtures pass. The same previously reviewed
attribution algorithm is used unchanged. [Complete compressed analysis](../tests/evidence/diagnostics/gen17-cpr/analysis/analysis.json.gz),
[decoder subpartition](../tests/evidence/diagnostics/gen17-cpr/decoder-stages-summary.json).

These helper observations are **overlapping inclusive costs**. They nest
inside the exclusive rows and each other; do not sum them into another total.

| Live helper | Native entries | Inclusive Ir |
|---|---:|---:|
| `streamStep` | 50,385 | 5,050,518,359 |
| `toFloat` | 103,138 | 3,333,981,092 |
| `haversineFloat` | 25,256 | 3,286,729,633 |
| `stepAirborne` | 10,408 | 2,724,949,233 |
| `stepSurface` | 2,556 | 2,256,995,484 |
| `validMotion` | 10,405 | 2,207,162,992 |
| `nearestAirport` | 2 | 2,042,577,398 |
| `Numeric-geography Binary64.round` | 103,138 | 1,928,197,869 |
| `Numeric-geography Binary64.exponent` | 206,276 | 653,631,323 |
| `decodeGlobalFloat` | 10,405 | 296,597,704 |
| `decodeLocalFloat` | 1,057 | 81,740,851 |
| `Numeric-geography Binary64.powerTwo` | 460,693 | 40,540,984 |

`toFloat` rounds an exact rational, obtains its exponent and binary64 bit
pattern, then uses `Float.ofBits`. Haversine converts four coordinates;
geographic outputs return to exact rationals through `Binary64.fromBits`.
The two airport lookups scan the pinned list. These observations retain the
distinction between proved policy and tested Float geography. They add no
new correctness claim. Sources: [CPRFloat](../Impl/CPRFloat.lean),
[CPRPolicy](../Impl/CPRPolicy.lean), [Binary64](../Impl/Binary64.lean).

The largest direct conversion/normalization edges within numeric geography
are below. Each callee-inclusive row is from an actual edge; parent calls,
rational normalization and nested GCD/power costs overlap. All 77
grouped edges across stages, and their full contexts, are retained in the
[numeric supplement](../tests/evidence/diagnostics/gen17-cpr/numeric-contexts.json.gz).
The [power-only extraction](../tests/evidence/diagnostics/gen17-cpr/power-contexts.json)
is retained separately. Those inclusive costs do not measure exponent frequency or table-hit coverage.
The separate direct-edge census below observes the lookup/fallback branch
populations. Rounding and rational normalization remain present.

| Direct caller → callee, numeric geography | Calls | Inclusive Ir |
|---|---:|---:|
| `lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 101,024 | 3,272,960,594 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `lp_lean1090_Lean1090_Impl_Binary64_round` | 103,138 | 1,928,197,869 |
| `l_Rat_div` → `l_Rat_mul` | 206,276 | 1,407,212,349 |
| `l_Rat_mul` → `lean_nat_gcd` | 715,148 | 1,172,352,619 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `l_Rat_div` | 103,138 | 801,031,581 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `l_Rat_div` | 103,138 | 800,828,804 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `l_Rat_mul` | 103,138 | 548,601,614 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `lp_lean1090_Lean1090_Impl_Binary64_exponent` | 103,138 | 333,192,664 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `lp_lean1090_Lean1090_Impl_Binary64_exponent` | 103,138 | 320,438,659 |
| `lp_lean1090_Lean1090_Impl_Binary64_fromBits` → `l_Rat_mul` | 48,160 | 260,699,341 |
| `l_Rat_div` → `l_Rat_inv` | 206,276 | 192,997,828 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat` → `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` | 2,114 | 61,020,498 |
| `lp_lean1090_Lean1090_Impl_Binary64_exponent` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 206,276 | 18,152,288 |
| `lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 103,138 | 9,076,144 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` → `lp_lean1090_Lean1090_Impl_Binary64_powerTwo` | 103,138 | 9,076,144 |

The new immutable table contains every exponent from −1074 through 1023.
The independent native review follows actual module initialization into its
2,098-entry constructor before the worker loop. Each entry calls the original
formula directly; lookup does not recursively construct the table.
Inside this collected loop, actual lookup entries and direct calls to the
retained formula are:

| Calling stage | Lookup entries | Formula fallback calls | Table branch calls |
|---|---:|---:|---:|
| numeric_geography | 460,693 | 0 | 460,693 |
| decoder | 1,324 | 0 | 1,324 |
| motion_policy | 62,418 | 0 | 62,418 |
| airborne_pairing_policy | 20,842 | 0 | 20,842 |
| **Total** | **545,277** | **0** | **545,277** |

The linked lookup has two mutually exclusive fallback sites and at most one
formula call per lookup. Subtracting the observed direct fallback calls from
lookup entries therefore identifies table-branch calls for this corpus; it
is not inferred from cost. There are 0 observed table-entry constructor calls
inside collection. Construction occurs eagerly before the root, and its
startup work is not claimed to be zero. No claim is made about all possible
exponents. [Exact contexts and source binding](../tests/evidence/diagnostics/gen17-cpr/table-contexts.json.gz).

The actual frozen worker was sampled separately before diagnostic native or
profile workers. Decode then CPR ran sequentially on CPU 0 using `cpu-clock:u`,
199 Hz and 16,384-byte DWARF stacks. All 279 protected inputs stayed unchanged.
CPR recorded 283 samples: 145 have a visible CPR-loop ancestor and
138 are excluded. Unknown frames occur in 275 stacks, with
10 unknown included leaves. Both report headers explicitly state zero lost
samples. Missing/erased ancestors make these conditional observations unsuitable
for whole-workload timing shares. One-pass durations are not benchmark results.
[Capture and exclusions](../tests/evidence/diagnostics/gen17-cpr/perf/completion.json).

Callgrind uses `--instr-atstart=no`, `--collect-atstart=no` and
`--separate-callers=40`. Its prepared/run/decoded/consume handshake and every
control acknowledgement are retained. The primary raw dump SHA-256 is
`ba8c042581b94f7334e32eeaa8562315a5f591530f872dc916bac097ffdd11be`. Instruction profiling may overlap other instruction
diagnostics; none is a timing measurement.

The [archive](../tests/evidence/diagnostics/gen17-cpr/archive-manifest.json)
retains 52 original/tooling files in 6,756,193 bytes,
with deterministic compressed and decompressed hashes. Large analysis outputs
are [separately compressed](../tests/evidence/diagnostics/gen17-cpr/analysis-retention.json).
Rebuildable binaries stay outside Git with exact hashes and build provenance.
No old artifacts are recopied or replaced. The previously reviewed archive helper is reused unchanged with an explicit
`perf-gen17-cpr` directory. [Producer validation](../tests/evidence/diagnostics/gen17-cpr/validation.json)
binds this report and all inputs. Independent raw-accounting review remains
the condition for selecting the next optimization.
