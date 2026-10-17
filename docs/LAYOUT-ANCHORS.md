# Published example coverage by layout

This is an **unfrozen review/provenance addendum**. It does not change `Spec/`,
any capstone, the audit guards, or `spec.lock`.

There are **24 distinct worked Sun full-frame inputs kernel-checked through
`Spec.decode`**: 23 successful messages and one corrupt-frame rejection.
There are **zero ICAO worked decoding examples checked through `Spec.decode`**
in the sources actually read. ICAO contributes four kernel-checked arithmetic
assertions, which are not decoder examples. Six additional Sun Quick Start
frames are raw transcript lines with no published decoded answer; they do not
increase the worked-example count. Neither do Sun's four non-frame worked
example groups.

`Spec/StandardExamples.lean` fixes literal source inputs and independently stated
published fields, checking them as projections of `Spec.decode` (or as its
rejection). `Spec/StandardFullExamples.lean` also has complete `Spec.decode` result
equalities for all 30 distinct frames. Its additional fields were captured from
the decoder: they are regression checks, not independent published anchors.
The source list, editions, pages, editorial errors and scope exceptions remain
in [STANDARD-EXAMPLES.md](STANDARD-EXAMPLES.md),
[EXAMPLE-COUNTS.md](EXAMPLE-COUNTS.md), and [SOURCES.md](SOURCES.md).

## Meaning of the labels

A **published anchor** below requires a source's decoded payload quantity to be
checked from the actual `Spec.decode` result. A raw frame, CRC-only worked
calculation, generated round-trip, non-vacuity witness, captured full-result
fixture, or an example of another TC sharing the same schema does not qualify.
An anchor checks the published quantities, not every possible value, optional
branch or scale in that layout.

Every branch without such an anchor is explicitly labelled **rs1090-derived;
no worked-example anchor**. This is the conservative compatibility/validation
label requested by the user: the oracle's interpretation is the remaining
behavioral cross-check, and no independent worked example validates that branch.
The adjacent origin column preserves the actual source of the frozen field
positions/scales. A formula transcribed from a published standard table remains
standard-table-derived; the absence of a worked example does not make it
historically derived from Rust. Where the table itself was unavailable, both the
schema and its compatibility behavior are rs1090-derived, as already identified
in the frozen docstrings. This addendum neither invents a published example nor
retroactively changes a frozen definition's derivation.

All inference validity predicates, density scores, binary64 operation order,
receiver heuristics, serialization, and departures from the standard are
rs1090-derived even when a layout has a published field anchor. A source example
does not independently certify those receiver policies.

## ADS-B: all 70 canonical TC/subtype/version branches

Only **5 of 70** branches have a published semantic anchor. The key is exactly
`tc * 64 + subtype * 8 + version` from `adsbKind`; irrelevant components are zero.
TC29 has a two-bit subtype, so its domain is 0–3. TC31 subtypes0/1 each have eight
version branches; its reserved subtypes2–7 do not read a version discriminator.
Category, status, parity and value codes are fields, not additional layout keys.
The TC4 example has category0; it does not validate the remaining wake categories.

| Anchor | Source actually read and decoded quantities | Kernel theorem |
| --- | --- | --- |
| A1 | Sun second ed. (2021), §§3.5/4.3, pp.37–38/42–43: TC4, category0, KLM1023 and no wake information | `identification_meaning` ([source](../Spec/StandardExamples.lean#L381)) |
| A2 | Sun §6.4, pp.63–68: TC7 surface CPR fields, local coordinates, movement41→17kt and track33→92.8125° | `surface_movement_track` ([source](../Spec/StandardExamples.lean#L488)) |
| A3 | Sun §§5.3.3/5.4.4/5.5, pp.53–59: TC11 even/odd CPR fields, global/local coordinates and altitude38000ft | `airborne_altitude` ([source](../Spec/StandardExamples.lean#L420)) |
| A4 | Sun §§7.1–3, pp.70–74, plus §2.4.1 p.28: TC19.1 velocity components/rate/height difference | `velocity_ground_meaning` ([source](../Spec/StandardExamples.lean#L499)) |
| A5 | Sun §§7.1/7.4, pp.70–71/74–75: TC19.3 TAS375kt, heading243.984375°, barometric rate−2304ft/min | `velocity_air_meaning` ([source](../Spec/StandardExamples.lean#L518)) |

A2 additionally uses `surface_coordinates`, `surface_odd_local_reconstruction`
and `surface_local_position`; A3 uses `airborne_coordinates`,
`airborne_global_position` and `airborne_local_position`; A4 uses
`quick_start_meaning`, the fixed expression-tree assertion and rational display
rounding bounds. These statements all start with the literal decoded source
frame; floating transcendental presentation remains tested, not proved.

Compatibility-source keys below refer to the pinned rs1090 commit
`685dfaa34c5ab186c691bca3cfe2a22e12517d30`, under
`vendor/rs1090/crates/rs1090/src/decode/`:

- P-ID: `bds/bds08.rs`; P-SURF: `bds/bds06.rs`; P-POS: `bds/bds05.rs`.
- P-VEL: `bds/bds09.rs`; P-STATUS: `bds/bds61.rs`; P-TARGET: `bds/bds62.rs`.
- P-OPS: `bds/bds65.rs`; P-RAW: `adsb.rs` and its raw/reserved variants.

| TC | Subtype | Version | Canonical kind | Worked-example status | Frozen table origin / compatibility source |
| ---: | ---: | ---: | ---: | --- | --- |
| 0 | — | — | 0 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 1 | — | — | 64 | **rs1090-derived; no worked-example anchor** | Sun ch.4 diagram / table4.1; P-ID |
| 2 | — | — | 128 | **rs1090-derived; no worked-example anchor** | Sun ch.4 diagram / table4.1; P-ID |
| 3 | — | — | 192 | **rs1090-derived; no worked-example anchor** | Sun ch.4 diagram / table4.1; P-ID |
| 4 | — | — | 256 | Published: A1 | Sun ch.4 diagram / table4.1; P-ID |
| 5 | — | — | 320 | **rs1090-derived; no worked-example anchor** | Sun tables6.1–6.2; P-SURF |
| 6 | — | — | 384 | **rs1090-derived; no worked-example anchor** | Sun tables6.1–6.2; P-SURF |
| 7 | — | — | 448 | Published: A2 | Sun tables6.1–6.2; P-SURF |
| 8 | — | — | 512 | **rs1090-derived; no worked-example anchor** | Sun tables6.1–6.2; P-SURF |
| 9 | — | — | 576 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 10 | — | — | 640 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 11 | — | — | 704 | Published: A3 | Sun table5.1 / §5.5; P-POS |
| 12 | — | — | 768 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 13 | — | — | 832 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 14 | — | — | 896 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 15 | — | — | 960 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 16 | — | — | 1024 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 17 | — | — | 1088 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 18 | — | — | 1152 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 19 | 0 | — | 1216 | **rs1090-derived; no worked-example anchor** | Reserved payload: P-VEL |
| 19 | 1 | — | 1224 | Published: A4 | Sun tables7.1–7.3; P-VEL |
| 19 | 2 | — | 1232 | **rs1090-derived; no worked-example anchor** | Sun tables7.1–7.3; P-VEL |
| 19 | 3 | — | 1240 | Published: A5 | Sun tables7.1–7.3; P-VEL |
| 19 | 4 | — | 1248 | **rs1090-derived; no worked-example anchor** | Sun tables7.1–7.3; P-VEL |
| 19 | 5 | — | 1256 | **rs1090-derived; no worked-example anchor** | Reserved payload: P-VEL |
| 19 | 6 | — | 1264 | **rs1090-derived; no worked-example anchor** | Reserved payload: P-VEL |
| 19 | 7 | — | 1272 | **rs1090-derived; no worked-example anchor** | Reserved payload: P-VEL |
| 20 | — | — | 1280 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 21 | — | — | 1344 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 22 | — | — | 1408 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5; P-POS |
| 23 | — | — | 1472 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 24 | — | — | 1536 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 25 | — | — | 1600 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 26 | — | — | 1664 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 27 | — | — | 1728 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 28 | 0 | — | 1792 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 1 | — | 1800 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 2 | — | 1808 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 3 | — | 1816 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 4 | — | 1824 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 5 | — | 1832 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 6 | — | 1840 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 28 | 7 | — | 1848 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-STATUS |
| 29 | 0 | — | 1856 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-TARGET |
| 29 | 1 | — | 1864 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-TARGET |
| 29 | 2 | — | 1872 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-TARGET |
| 29 | 3 | — | 1880 | **rs1090-derived; no worked-example anchor** | Detailed schema: P-TARGET |
| 30 | — | — | 1920 | **rs1090-derived; no worked-example anchor** | Sun table3.3 classification; payload treatment P-RAW |
| 31 | 0 | 0 | 1984 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 0 | 1 | 1985 | **rs1090-derived; no worked-example anchor** | Sun tables8.2–8.3 enclosing blocks; detailed bits P-OPS |
| 31 | 0 | 2 | 1986 | **rs1090-derived; no worked-example anchor** | Sun tables8.2–8.3 enclosing blocks; detailed bits P-OPS |
| 31 | 0 | 3 | 1987 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 0 | 4 | 1988 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 0 | 5 | 1989 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 0 | 6 | 1990 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 0 | 7 | 1991 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 1 | 0 | 1992 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 1 | 1 | 1993 | **rs1090-derived; no worked-example anchor** | Sun tables8.2–8.3 enclosing blocks; detailed bits P-OPS |
| 31 | 1 | 2 | 1994 | **rs1090-derived; no worked-example anchor** | Sun tables8.2–8.3 enclosing blocks; detailed bits P-OPS |
| 31 | 1 | 3 | 1995 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 1 | 4 | 1996 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 1 | 5 | 1997 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 1 | 6 | 1998 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 1 | 7 | 1999 | **rs1090-derived; no worked-example anchor** | Opaque version tail / detailed bits: P-OPS |
| 31 | 2 | — | 2000 | **rs1090-derived; no worked-example anchor** | Reserved subtype bytes: P-OPS |
| 31 | 3 | — | 2008 | **rs1090-derived; no worked-example anchor** | Reserved subtype bytes: P-OPS |
| 31 | 4 | — | 2016 | **rs1090-derived; no worked-example anchor** | Reserved subtype bytes: P-OPS |
| 31 | 5 | — | 2024 | **rs1090-derived; no worked-example anchor** | Reserved subtype bytes: P-OPS |
| 31 | 6 | — | 2032 | **rs1090-derived; no worked-example anchor** | Reserved subtype bytes: P-OPS |
| 31 | 7 | — | 2040 | **rs1090-derived; no worked-example anchor** | Reserved subtype bytes: P-OPS |

The **65 branches without a published anchor** are therefore:

- TC0, TC1, TC2, TC3, TC5, TC6, TC8, TC9, TC10, TC12, TC13, TC14,
  TC15, TC16, TC17, TC18, TC20, TC21, TC22, TC23, TC24, TC25, TC26, TC27, TC30.
- TC19 subtypes0,2,4,5,6,7.
- TC28 subtypes0,1,2,3,4,5,6,7.
- TC29 subtypes0,1,2,3.
- TC31 subtype0 versions0,1,2,3,4,5,6,7; subtype1 versions0,1,2,3,4,5,6,7;
  and reserved subtypes2,3,4,5,6,7.

The TC20–22 GNSS-height and TC19.2 velocity discrepancies remain documented in
`DISCREPANCIES.md`; inheriting TC11 or TC19.1 coverage would hide precisely the
source/scale difference that this audit is intended to expose.

## Comm-B: all 14 register candidates/direct schemas

Seven registers have published decoded payload anchors. The other seven,
**BDS05, BDS10, BDS18, BDS19, BDS21, BDS30 and BDS65**, have none in the required
Comm-B `Spec.decode` path and are explicitly labelled below. Registers use the
usual hexadecimal BDS notation (05 means0x05, 17 means0x17).

| BDS | Worked-example status | Published source and kernel anchor, or explicit provenance/coverage limitation |
| --- | --- | --- |
| 05 | **rs1090-derived; no worked-example anchor** | Sun table5.1 / §5.5 supplies the shared airborne schema; compatibility source `commb.rs` and `bds/bds05.rs`. TC11 has an ADS-B anchor, but there is no published DF20 BDS05 candidate example through `Spec.decode`. TC9–18 and20–22 direct schemas are all included here; DF20 inference excludes TC22, and DF21 never attempts05. |
| 10 | **rs1090-derived; no worked-example anchor** | ICAO Annex10 IV, fourth ed.2007/amendment85, table3-6; Sun table16.1. No worked capability decode. Compatibility source `bds/bds10.rs`. The address-parity example checks CRC/AP/address, not a BDS10 capability record. |
| 17 | Published: `gicb_meaning` ([source](../Spec/StandardExamples.lean#L585)) | Sun §16.2, pp.119–120/table16.2: all eleven set capability bits, including BDS52. |
| 18 | **rs1090-derived; no worked-example anchor** | No independently read layout table or worked bitmap example. Schema and policy from `bds/bds18.rs`. |
| 19 | **rs1090-derived; no worked-example anchor** | No independently read layout table or worked bitmap example. Schema and policy from `bds/bds19.rs`. |
| 20 | Published: `commb_identification_meaning` ([source](../Spec/StandardExamples.lean#L596)) | Sun §16.3, pp.121–122/table16.3: callsign KLM1017; ICAO table3-8 independently supplies the alphabet. |
| 21 | **rs1090-derived; no worked-example anchor** | No independently read registration layout table or worked example. Schema and policy from `bds/bds21.rs`. |
| 30 | **rs1090-derived; no worked-example anchor** | ICAO Annex10 IV fourth ed.2007/amendment85 §4.3.8.4.2.2.1.1–6 and Sun table16.4 provide fields. No worked RA/RAC/threat decode, for any threat-type0,1,2,3. Compatibility source `bds/bds30.rs`. |
| 40 | Published: `selected_altitude_meaning` ([source](../Spec/StandardExamples.lean#L603)) | Sun §17.1/figure17.1, pp.128–129: MCP/FMS24000ft, QNH1013.2hPa, mode/source fields; ICAO table3-10 also supplies definitions. |
| 44 | Published: `meteo_routine_meaning` ([source](../Spec/StandardExamples.lean#L634)) | Sun §18.1/figure18.1, pp.136–137/table18.1: wind22kt at344.53125°, temperature−48.75°C, optional fields absent. |
| 45 | Published: `meteo_hazard_meaning` ([source](../Spec/StandardExamples.lean#L645)) | Sun §18.2/figure18.2, p.139/table18.2: temperature−48.75°C, all hazards/pressure/height absent. The figure-only hex was read visually. |
| 50 | Published: `track_turn_meaning` ([source](../Spec/StandardExamples.lean#L614)) | Sun §17.2/figure17.2, p.131/table17.2: roll, track, rate, GS476kt and TAS466kt; §19.3/figure19.2 supplies another decoded candidate. |
| 60 | Published: `heading_speed_meaning` ([source](../Spec/StandardExamples.lean#L623)) | Sun §17.3/figure17.3, pp.133–134/table17.3: heading, IAS259kt, Mach0.7, vertical rates; §19.3 supplies two more decoded candidate interpretations. |
| 65 | **rs1090-derived; no worked-example anchor** | Sun tables8.2–8.3 give enclosing blocks; detailed fields/compatibility from `bds/bds65.rs` and `commb.rs`. No worked example for either subtype0/1 or any version0–7. The pinned per-message selector rejects every65 candidate because of its documented offset/length behavior; direct register schemas remain in scope. |

A source's capability bit announcing support for another BDS register is not an
example decoding that other register. In particular, the BDS17 support bitmap
does not anchor BDS05/10/18/19/21/30/65. The chapter19 hypothetical rejected BDS50
interpretation is an additional field calculation, not an extra successful
candidate or a replacement for its separate accepted track/turn example.

The ADS-B BDS-style names06/08/09/61/62 are not additional DF20/21 inference
registers: their in-scope payloads are covered by the TC table above. No unsupported
Comm-B register is silently added to reach a coverage total.

## Outer message formats and remaining limitations

The worked full-frame set contains DF4,5,11,17,20,21. DF0,16,18,19 and24–31 have no
published complete worked decoding anchor in the consulted sources and carry
an explicit **rs1090-derived compatibility; no worked-example anchor** label
here. Their standard wire definitions retain their cited ICAO table provenance.
All listed ADS-B examples are DF17, so none independently anchors the DF18 wrapper.
The known DF24–31 parser over-read remains a recorded standards discrepancy.

One example per layout is a minimum external anchor, not evidence that every
field or branch is correct. For example, the BDS45 worked example has unavailable
radio height and hazards; it cannot by itself validate every present-value scale.
The field tables, independent encoder, universal theorem contracts and expanded
differential strata are still required. No missing anchor is presented as a
completed standard conformance proof.

## Verification

Executed successfully:

```sh
lake build Spec.StandardExamples Spec.StandardFullExamples
lake env lean scripts/ReviewLayoutCoverage.lean
```

The build checked both source-example modules (1432 jobs). The unfrozen review
script evaluates the frozen selectors and kernel-checks the count of70 canonical
ADS-B branches and14 Comm-B registers; it does not claim that generated witnesses
are published examples. Its exact enumerations were compared with every row of
this table. Source inspection counted29 distinct successful literal-byte fixtures
(23 worked, six raw-only), plus the independent corrupt-frame assertion, and
checked every cited source theorem against its published-quantity statement.
No source, example module or locked guard was edited for this coverage report.
