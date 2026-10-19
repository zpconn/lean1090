# Generation 15: live decode-plus-CPR instruction diagnostic

The complete corpus loop executed **18,463,254,211 collected instructions**.
The decoder accounts for 60.75%; numeric geography and its rational/Float
conversion boundary account for 30.13%; motion-policy arithmetic accounts
for 6.20%. After separating the decoder's five stages, numeric geography is
the largest individual category. These are untimed diagnostic instruction
counts, not throughput estimates or predictions of an optimization's gain.

This run uses the generation 15 native objects and the frozen benchmark's
actual workload: immediate `Impl.decode`, its tracking projection, then
`Impl.CPR.Policy.streamStep`, followed by appending the complete output.
The frozen worker does not call batch `Impl.decodePositions` in its timed
loop. The diagnostic tests that batch API separately after collection.
Production code, proofs, frozen files and build configuration are unchanged.

The timed source is `e659220307538f2aee5398efdb0a9182bff1d778`; the diagnostic
checkout is the source-equivalent descendant
`7163b2506f3b4045caa98721aa90b7042733b0fe`. The actual worker SHA-256 is
`4deead5e3f59d9e1bc6b850d3dd0bfe6b3f0ce3a9b0b2d44263af26345432c08`.
The driver reuses 21 production/model objects from the 22 freshly timed
native sets, replacing only the benchmark worker object. The
[independent source/native review](../tests/evidence/diagnostics/gen15-cpr/source-review.json)
checks the generated C, actual linked functions and all 98 driver inputs.

All 172,432 corpus timestamps and inputs and all 6,903 airport coordinates
match the frozen worker byte-for-byte. The empty aircraft state, absent
reference and always-false update callback match the benchmark. Array
capacity and initial state are prepared before the noinline collection root.
The full decoded messages and final state remain live through the root's
return. Loop/output accounting includes the diagnostic's retained-result
packaging. Input preparation, output consumption and batch checks are outside
collection. Eager module initialization precedes collection; first-use lazy
constants reached from this root remain included.

Every per-message tracking audit row and the final state projection exposed
by the frozen worker match exactly: 172,432 bit-identical rows, including
11,347 positions. This is stronger evidence for these particular rows than
the unchanged 1e-9-degree differential tolerance. Separately, the complete
`StreamState` and every routed result equal actual `Impl.decodePositions`
after collection. The final state contains 29 aircraft, of which two have
positions; the global reference remains absent. This corpus does not cover
worldwide tracking policy by itself.

The full-message digest also matches the same-generation decode diagnostic:
172,432 messages, 732,573,131 representation bytes and FNV-1a-64
`18440978423862441655`. The complete final-state representation is 15,785
bytes, digest `1856826440252506745`. Of 50,385 routed messages, 10,408 are
airborne reports, 2,556 surface reports and 37,421 other reports. The
[retained validation](../tests/evidence/diagnostics/gen15-cpr/retained/validation/summary.json)
binds commands, full row transcripts, state checks and unchanged inputs.

The following rows form one **exclusive self-cost partition**. The five
decoder rows replace the combined decoder subtotal of 11,216,446,533; they
must not be added to that subtotal again. Runtime, allocator, rational and
GMP descendants inherit their actual calling stage.

| Stage | Collected Ir | Share |
|---|---:|---:|
| Numeric geography and conversion | 5,562,621,468 | 30.1281% |
| Decoder: frame/CRC | 3,960,930,180 | 21.4530% |
| Decoder: Comm-B inference | 3,619,925,728 | 19.6061% |
| Decoder: semantic/oracle values | 3,378,921,568 | 18.3008% |
| Motion policy, excluding numeric geography | 1,144,291,779 | 6.1977% |
| Airborne pairing policy, excluding motion/geography | 312,623,996 | 1.6932% |
| Decoder: ADS-B fields | 210,378,970 | 1.1394% |
| Tracking projection | 79,588,998 | 0.4311% |
| Remaining state/tracking control | 68,567,612 | 0.3714% |
| Surface reference policy, excluding geography | 55,281,627 | 0.2994% |
| Decoder: output/model control | 46,290,087 | 0.2507% |
| Loop/output/retained-return control | 23,832,198 | 0.1291% |
| **Total** | **18,463,254,211** | **100%** |

There are no ambiguous merged contexts and no unexplained outside-root
events. The first analyzer attempt rejected six libm/PLT contexts totaling
253 self instructions because they had no positive incoming path from the
collection root. Two nodes do have incoming edges from other unreachable
nodes; these do not establish root reachability.
Their explicit recorded caller chains contain the exact collection root and
geographic helpers. The correction applies the same stage transitions along
those chains and retains every recovered context. Foreign chains and any
remaining outside-root event still fail. Eight fixtures cover shared-context
ambiguity, stage precedence, exact sums, this recovery and negative controls.
The failed attempt, source and log are retained. See the
[compact analysis](../tests/evidence/diagnostics/gen15-cpr/analysis-reviewed/summary.json),
[complete compressed self contexts](../tests/evidence/diagnostics/gen15-cpr/analysis-reviewed/analysis.json.gz)
and [decoder subpartition](../tests/evidence/diagnostics/gen15-cpr/decoder-stages-summary.json).

The next table contains **overlapping inclusive observations** from actual
call edges. These rows nest inside the exclusive partition and each other;
their costs cannot be summed into another total.

| Live helper | Native entries | Inclusive Ir |
|---|---:|---:|
| `streamStep` | 50,385 | 7,143,386,482 |
| `toFloat` | 103,138 | 4,761,031,800 |
| `haversineFloat` | 25,256 | 4,684,951,419 |
| `stepAirborne` | 10,408 | 3,879,578,184 |
| `stepSurface` | 2,556 | 3,195,240,686 |
| `validMotion` | 10,405 | 3,148,916,306 |
| `nearestAirport` | 2 | 2,877,167,824 |
| Numeric-geography `Binary64.round` | 103,138 | 2,641,534,155 |
| Numeric-geography `Binary64.powerTwo` | 460,693 | 1,738,677,460 |
| `speedGT` | 10,403 | 440,917,967 |
| `decodeGlobalFloat` (unboxed) | 10,405 | 416,545,544 |
| `distanceFromFloat` | 25,256 | 338,006,568 |
| `positionFromFloats` | 11,452 | 304,323,206 |
| `decodeLocalFloat` (unboxed) | 1,057 | 122,775,319 |

The source explains the conversion cost: `toFloat` rounds an exact rational,
finds its binade, constructs a binary64 bit pattern and then uses
`Float.ofBits`. Haversine calls it on four coordinates. Geographic results
are converted back to exact rational values with `Binary64.fromBits`.
The two airport lookups scan the pinned airport list. These observations
preserve the existing distinction between proved pure policy and the tested
Float geography boundary; they do not add a numerical correctness claim.
Relevant source: [CPRFloat](../Impl/CPRFloat.lean),
[CPRPolicy](../Impl/CPRPolicy.lean), [Binary64](../Impl/Binary64.lean).

The requested power-of-two extraction retains actual direct edges, with
full caller contexts and reconciliation to grouped observations. In numeric
geography, `Binary64.powerTwo` calls `lean_nat_pow` 460,693 times for
462,841,885 inclusive instructions. The corresponding motion-policy edge
has 62,418 calls / 64,304,217 Ir; airborne policy has 20,842 / 19,890,739.
Within decoding, the `packFields` fold calls `lean_nat_pow` 881,619 times
for 882,817,947 Ir. These costs overlap `powerTwo`/parent costs above.
The larger `powerTwo` total includes rational construction and normalization.
One first-use constant initializer is explicitly retained in these contexts.
[All power caller edges](../tests/evidence/diagnostics/gen15-cpr/power-contexts.json).
Decoder-only and CPR profiles share message semantics but have different
caller/ownership contexts; their instruction totals are separate observations.

The actual frozen worker was also sampled separately, before any diagnostic
native/profile workers. Decode and CPR captures ran sequentially on CPU 0
with `cpu-clock:u`, 199 Hz and 16,384-byte DWARF stacks. All 197 protected
inputs remained unchanged. The CPR capture recorded 306 samples: 164 have
a visible CPR loop ancestor after excluding visible post-clock consumers;
142 are excluded. There are unknown frames in 303 stacks and unknown leaves
in 13 included samples. The recorded report headers explicitly state zero
lost samples. These small, incomplete stacks support only conditional sample
observations; they cannot produce whole-workload timing shares. The worker's
one-pass duration is not used as a benchmark result.
[Capture and exclusions](../tests/evidence/diagnostics/gen15-cpr/perf/completion.json).

Callgrind collected only the noinline live-loop root, using
`--instr-atstart=no`, `--collect-atstart=no` and `--separate-callers=40`.
The prepared/run/decoded/consume handshake, all control acknowledgements,
complete results, primary dump and termination dump are retained. Primary
raw dump SHA-256:
`fa597c1ddf3b95c2034c27bc2eae9196dc2a44cbd5d879466b13c2a9da878430`.
Instruction profiles may overlap other instruction diagnostics; none is a
timing measurement. The earlier driver symbol-check failure and subsequent
preallocation-boundary review correction are preserved, and only the final
driver was executed.

The [archive manifest](../tests/evidence/diagnostics/gen15-cpr/archive-manifest.json)
retains 67 original/tooling files in 8,863,927 bytes, including deterministic
gzip recordings with compressed and decompressed hashes. The large analysis
outputs are separately compressed and verified in
[analysis retention](../tests/evidence/diagnostics/gen15-cpr/analysis-retention.json).
Rebuildable executable/object files stay outside Git with hashes and exact
build provenance. No historical artifact or production file was altered.
The final producer checks and all report/input associations are in
[validation.json](../tests/evidence/diagnostics/gen15-cpr/validation.json).
Independent raw-accounting review remains the release condition for choosing
the next optimization.
