# Comm-B specification review

The reference codec and inference functions are in `Spec/CommB.lean`; independent layout tables are in `Spec/CommBLayouts.lean`. They compile with Lean 4.35.0 (`lake build Spec.CommBWitnesses`). This is a checkpoint-1 specification, not a completed correctness proof or a production decoder.

The wire representation is a list of separately named field codes. No original message word is retained. `decodePayloadFields` extracts fields by table position. `encodePayloadFields` independently places the supplied fields at those positions. Keeping codes makes unavailable values, signed-zero aliases, sentinels and ignored bits distinguishable. Unit projections are separate, so a rounded displayed altitude does not become an incorrectly claimed lossless encoder input.

## Sources actually read

- ICAO Annex 10 Volume IV, fourth edition (2007), amendment 85 applicable 18 November 2010, tables 3-3, 3-6, 3-8, 3-10 and §4.3.8.4.2.2.1. Local extraction: `.cache/sources/annex10-vol4.txt`, printed pages 3-75 through 3-78 and 4-19 through 4-22.
- Junzi Sun, *The 1090 Megahertz Riddle*, second edition (2021), tables 16.1–16.4, 17.1–17.3 and 18.1–18.2; local extraction `.cache/sources/riddle.txt`. Online chapters: [elementary surveillance](https://mode-s.org/1090mhz/content/mode-s/6-els.html), [enhanced surveillance](https://mode-s.org/1090mhz/content/mode-s/7-ehs.html), [meteorological services](https://mode-s.org/1090mhz/content/mode-s/8-meteo.html). The web pages number their tables locally as 1.1 etc.; the printed book uses chapter numbering.
- rs1090 commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`: `decode/commb.rs`, `decode/bds/{bds10,bds17,bds18,bds19,bds20,bds21,bds30,bds40,bds44,bds45,bds50,bds60,bds65,mod,density,penalty}.rs`. These define the permitted inference-policy exception and the explicitly authorized fallback semantics below.
- The cached dependency source `deku_derive-0.20.3/src/macros/deku_read.rs`, `emit_try_from`, was read to resolve the BDS65 byte-consumption behavior.

BDS18, BDS19 and BDS21 layouts are **rs1090-derived**. No underlying ICAO table for these layouts was independently obtained or cited as if read. BDS65 detailed subfields inherit the explicitly labelled ADSB source status. BDS10/17/20/30/40/44/45/50/60 layouts come from the read standard/book tables. Every receiver rejection predicate is **rs1090-derived**, including restrictions narrower than the standard field domains.

## Direct register codec and actual inference are different APIs

`decodeBDS register word : Option PayloadRecord` decodes a specified register. `ValidBDS record` requires named-field shape, width bounds, and its field rejection rules; it never assumes a round-trip result. `encodeBDS record` places the fields independently. BDS05 and BDS65 use the ADSB layout machinery while retaining the BDS register as `record.kind`.

`decodeBDSFields` and `ValidBDSFields` provide the full source field-code domain, without receiver plausibility limits, status consistency checks or reserved-bit rejection. They require the named schema, field widths and register/type discriminants; the encoder is the same independent `encodeBDS`. This keeps the full field round-trip contract separate from compatibility acceptance. The domain retains reserved and unavailable codes as well as all standard-valid assignments. `bdsFields_nonvacuous` proves a BDS50 assignment with ground speed 1000 kt and TAS 60 kt is accepted and reconstructed by the field codec while the compatibility decoder rejects it. `bdsAllFields_nonvacuous` proves inhabitants for all fourteen schemas.

`inferCommB df outerAltitude word : List (Nat × PayloadRecord)` models only `Message::from_bytes` with default features. It retains every successful candidate, in this order: 05, 10, 17, 18, 19, 20, 21, 30, 40, 44, 45, 50, 60, 65. There is no winner suppression, country-prefix check or historical aircraft state in this API. Those belong to separate `sanitize`, `infer_bds` or processing APIs and are not silently applied here.

- DF must be 20 or 21. An all-zero MB field returns no candidates.
- BDS05 is attempted only in DF20. Its TC must be 9–18 or 20–21: the oracle's half-open `9..22` range excludes TC22. Inner and outer optional altitudes must match exactly, including `None = None`. The BDS05 density model is not called by this path.
- BDS65 never survives this path in the pinned oracle. The TC31/subtype0-or-1 guard is followed by `AircraftOperationStatus::try_from` without skipping the five TC bits. It therefore reads reserved subtype7, consumes 43 bits, and `TryFrom` rejects the leftover bytes. A direct BDS65 codec still has valid assignments and round-trip witnesses. The inference predicate for BDS65 is explicitly false; no impossible acceptance witness is claimed.
- BDS40/44/45/50/60 receive the density-plus-penalty gate after their field predicates. Other core candidates have no score gate.

## Field acceptance predicates

All rows are the default-feature oracle policy, not a claim that the standard forbids every rejected assignment.

| Register | Predicate beyond the 56-bit input bound |
|---|---|
| 05 | TC9–18/20–22 for direct codec; altitude parser accepts unavailable/invalid codes as absent, rejects decoded altitude above 50,000 ft |
| 10 | Header 0x10; bits10–14 zero |
| 17 | Bit7 set; bits10,11,12,15,20,21,22 clear; bits30–56 zero; bits25–29 are retained without a zero check |
| 18 | Only registers 30,21,20,1F,1E,1D,1C,1B,1A,19,18,17,10,0F,0B,0A,09,08,07,06,05 may be set; 20,19,18,17 must be set |
| 19 | Only registers 65,62,61,60,5F,53,52,51,50,45,44,40 may be set |
| 20 | Header 0x20; all six-bit symbol codes are accepted |
| 21 | With aircraft status false, all seven characters must be stripped placeholders; otherwise at most two retained `#` symbols. Airline status false and both airline symbols stripped placeholders |
| 30 | Header 0x30; all four threat-type values accepted, including unassigned; ignored bits retained |
| 40 | Unavailable altitude/pressure fields must have zero value; spare regions zero; displayed selected altitudes ≤50,000 ft; binary64 pressure in [800,1200] hPa. Mode/source status does not force corresponding mode/source codes to zero |
| 44 | FOM1/2; unavailable wind must zero both speed and direction; wind speed≤250 kt; corrected temperature in [-80,60] °C; unavailable pressure zero; turbulence and humidity fields entirely zero |
| 45 | All five hazard fields zero; unavailable temperature has zero magnitude but may have sign1; available temperature in [-80,60] °C; unavailable pressure/height zero; tail five bits zero |
| 50 | Unavailable values/signs zero; absolute roll≤45°; ground speed≤700 kt; present TAS in [80,600] kt; track-rate magnitude511 is accepted as unavailable |
| 60 | Unavailable values/signs zero; IAS≤500 kt; binary64 Mach≤1; inertial rate absolute value≤6000 ft/min; barometric rate unbounded within its encoded range |
| 65 | Direct codec: TC31, subtype0/1, capability leading reserved bits and operational-mode leading reserved bits zero. Actual Comm-B inference: never retained, for the offset issue above |

## Unit projections and deliberate compatibility rules

The table schemas express exact rational scale, offset and status. `commBValue`, `cbThreat`, `cbCallsign` and `cbRegistration` add the following explicit behavior:

- BDS20 strips every code32, including interior spaces. Code0 and other undefined symbols display `#`. The alphabet itself is Annex10 table3-8.
- BDS21 strips codes0/32/45, including the empirically used nonstandard dash placeholder45. A present but entirely blank registration remains an empty string.
- `cbStandardThreat` follows the read Annex10IV§4.3.8.4.2.2.1.5–6 tables: Mode C Gillham altitude; range1 below0.05NM,2–126 as `(code-1)/10 ±0.05`NM,127 above12.55NM; bearing1–60 as six-degree sectors and61–63 explicitly unassigned. TTI1 address padding must be zero. These meanings are separate from the compatibility view, with concrete edge witnesses proved in `standardThreatEdges_nonvacuous`.
- The explicitly oracle-derived `cbThreat` exposes AC13 altitude, exact pre-Float `(rangeCode-1)/10` NM and bearing `6*(code-1)+3` degrees, with code0 absent. Oracle range127 becomes12.6NM; reserved bearing61–63 still becomes numeric. The oracle presents range as binary32; that final Float conversion is tested rather than proved.
- BDS40 selected altitude uses `((raw*16+8)/100)*100` integer feet. This is the shipped formula, not general nearest-100 rounding. Pressure has exact meaning `raw/10+800`; inference models the actual two binary64 operations `raw*0.1+800`.
- BDS44 temperature uses signed quarter-degrees, followed by +256°C if initially below -80°C. This oracle firmware workaround differs from simple two's-complement decoding. Wind direction is `raw*180/256` degrees; pressure is raw hPa; humidity is `raw*100/64` percent before its inference rejection.
- BDS50 roll is signed `raw*45/256` degrees, track signed `raw*90/512` degrees wrapped into [0,360), ground speed/TAS `raw*2` knots, and track rate signed `raw*8/256` degrees/second except magnitude511 means absent.
- BDS60 heading wraps as above, IAS is raw knots, Mach has exact meaning `raw/250`, and rates are signed `raw*32` ft/min except magnitude0 or511 means zero regardless of sign. Inference preserves the oracle's binary64 operation order `raw*2.048/512` for Mach.

## Score semantics and finite arithmetic obligation

`Binary64` models finite IEEE binary64 numeric values by exact rationals with nearest-even rounding after each arithmetic operation. No opaque Lean `Float`, external primitive or numerical axiom enters the predicate. It does not claim to model infinities, NaNs or division by zero; signed zeros are collapsed where their numeric comparisons agree.

Let `G(x,μ,σ) = (-0.5*z)*z`, with `z=(x-μ)/σ`, and `L(x,m,b)=-abs(x-m)/b`. Every decimal constant is first rounded to binary64; every arithmetic operation below is separately rounded. Present terms are accumulated in the order shown and divided by the count. No terms means a zero density contribution.

| Register | Ordered density terms |
|---|---|
| 40 | L(QNH,1013.2,5.4); G(selected MCP,24688,10844); G(selected FMS,24688,10844) |
| 44 | L(temperature,-21,9.90); G(wind speed,52,29); L(pressure,393,290) |
| 45 | G(temperature,-14.2,16.4); L(pressure,393,290) |
| 50 | L(roll,0,10); L(track rate,0,0.70); G(TAS,413,120); G(ground speed,418,129) |
| 60 | G(IAS,272,55); G(Mach,0.69,0.21); G(inertial vertical rate,-298,1669) |

BDS50 subtracts `abs(TAS-GS)/100` when both are present, then subtracts2 when absolute roll>5°, absolute rate>the rounded0.3°/s and their signs differ. BDS60 subtracts3 when present Mach>0 and IAS/Mach lies outside [250,800]. The final rounded density-plus-penalty score must be at least -3.

`Spec/CommBArithmetic.lean` exposes `CommBScoreArithmeticFinite`: all traced operands, exact pre-round results and rounded results are within the finite binary64 range, and each executed divisor is nonzero. This is a proof obligation for every bounded payload; it is **not** an added acceptance condition. Main universal arithmetic and codec theorems remain to be proved after approval. A concrete scored BDS40 witness already proves the complete finite condition and actual inference membership by kernel reduction.

## Commands run during drafting

- `lake build Spec.CommBWitnesses`: passes; builds the schemas, codec, arithmetic-domain predicates and all witness proofs.
- `lake env lean --run scripts/PayloadExamples.lean`: passes 2048 exact per-bit layout checks, 4080 oracle-accepted structured examples out of 4096 inputs, all 4096 full ADSB field-code patterns, 1566 full Comm-B individual-bit/maximum patterns, 14 concrete register round-trips, and published identification/altitude/temperature/velocity/movement examples. The TC31 example reports candidates 21/50/60 and no 65. This retained draft script supersedes the initial temporary scratch checks.
- `lake env lean /tmp/lean1090-commb-axioms.lean`: `#print axioms` on all 14 direct-register witnesses, the inference and arithmetic witnesses, both full-field-domain witnesses and the standard threat edge witness lists only `propext`, `Classical.choice`, `Quot.sound`.
- Oracle probe supplied by the scope agent: `.cache/rs1090-target/dist/lean1090-oracle-bench --probe-hex a0000000f8000000000000000000` confirms BDS65 absence; matching subtype1 and DF21 probes also omit65.

`Spec/CommBWitnesses.lean` proves a valid assignment for each of the14 direct register codecs. `commBInference_nonvacuous` proves a concrete BDS40 candidate survives both field predicates and the actual rounded score gate. `commBArithmetic_nonvacuous` proves its finite-arithmetic domain. No universal round-trip, inference equivalence or refinement theorem is represented as already proved.
