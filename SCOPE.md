# Decoder scope and oracle contract — checkpoint 1 draft

This inventory is based on the pinned oracle's actual readers, not just its Rust enum names or comments. It describes the target and reporting policies implemented by the checkpoint reference modules. The initial complete pure runtime and its all-input refinement are implemented and proved. The remaining semantic capstones, complete unit-vector port and whole-message differential tests are section4 work. The BDS50 measured baseline is in docs/BDS50-PILOT.md. See `THEOREMS.md` for the exact proof boundary and `PROGRESS.md` for executed checks.

## Pins and sources

- Oracle: [`xoolive/rs1090`](https://github.com/xoolive/rs1090/tree/685dfaa34c5ab186c691bca3cfe2a22e12517d30), commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`, package version 0.7.0. Checkout is `vendor/rs1090`. Use its committed `Cargo.lock`, default features (`bds-infer` enabled), and shipped `dist` profile: release optimization, full LTO, overflow checks enabled, symbols stripped. No `target-cpu=native` or other CPU-specific flags.
- Lean: `leanprover/lean4:v4.35.0`, compiler commit `eb6cafb7290e8bd5f2937522d8d804f58f02bafc`; Mathlib `v4.35.0`, commit `56a005855ea17e0b0958f73ec801ae140b0a1679`, pinned in `lakefile.toml` and `lake-manifest.json`.
- Standards: ICAO Annex 10 Vol. IV and Junzi Sun's [*The 1090 Megahertz Riddle*](https://mode-s.org/1090mhz/) are the primary mathematical sources. The actually read editions are Annex10 IV fourth edition (July2007), amended pages18November2010, and Sun second edition (2021); acquisition URLs and hashes are in `docs/SOURCES.md`. Individual `Spec/` docstrings identify their sections. The user's later instruction permits additional ICAO tables actually read, and an explicitly marked **rs1090-derived** fallback where published field semantics are unavailable. No source is claimed read merely because rs1090 cites it.
- This document's reader behavior, JSON projection, implementation-specific validity filters, and rounding rules are **rs1090-derived** from the pinned files under `crates/rs1090/src/decode/`. Those policies are identified separately from standard field semantics. The inference predicates are intentionally oracle-defined.
- Prior-art study completed before design: lean-zip commit `2f7a63f38195bc667a926881b55d10c9f8a88eeb`, `Zip/Native/Inflate.lean`, `Zip/Spec/DeflateRoundtrip.lean`, `conformance/Conformance/NativeInflate.lean`, `NativeDeflate.lean`; and `pre-split:PLAN.md`, `PROGRESS.md`, `progress/2026-02-19T13-22-13Z_000003.md`. The useful pattern is independent characterizing theorems plus implementation refinement, with bidirectional external conformance and reproducible per-session evidence.

## Boundary and exactness

Input is a byte sequence, with a message boundary at bit offset zero. The normal API accepts exactly 7 or 14 bytes according to DF; all other lengths return an explicit error. The compatibility projection for `Message::from_bytes` additionally records consumed bytes/remainder: that Rust entrypoint accepts a short-format message at the start of a 14-byte slice and returns the unused suffix. `Message::try_from` rejects such trailing data. The main differential suite must distinguish these APIs rather than silently treating them as equivalent.

MSB-first bit numbering is used throughout. Wire bits are counted from 1; MB/ME fields are counted relative to the start of their 56-bit payload. Exact raw fields, including meaningful unavailable/status codes, must remain available for the encoder and bit round-trip theorem. Rounded JSON output alone is not an injective representation of a message. Spare/reserved bits are not assigned new aircraft meaning. Retaining them for a bit-preserving wire representation is distinct from asserting they are standard-defined data.

The target includes the oracle’s reported fields; the inventory additionally records useful parsed internal fields omitted by `#[serde(skip)]` so they are not accidentally confused with JSON. Accidental early reads of a serde-skipped parity member are not a target behavior: retain actual wire parity. JSON parity is a separate projection: same keys, values, omissions, enum tags, and numeric widths as the oracle. Recoverable errors need the same success/failure classification; incidental deku error wording is not a semantic requirement. Canonical JSON must not normalize absent into null, null into zero, or reserved into known. The exact semantic record and diagnostic raw bits may be richer than default serde JSON, but extra keys must not be inserted into the comparison projection.

Numerical conventions:

- Altitudes and selected altitudes: feet unless a standard GNSS-height or reserved metric branch explicitly says metres; output must label the source. Rates: feet/minute. Air/ground/wind speeds: knots. Angles: degrees; turn rate: degrees/second. Pressure: hPa (equivalent to mbar). Temperatures: °C; humidity: percent. Time: seconds. CPR coordinates: 17-bit integers divided by 131072; resolved coordinates: decimal degrees.
- No extra display rounding is allowed. f32 output fields must be rounded as f32 before JSON serialization; f64 fields use binary64. Decimal JSON text is compared by canonical numeric value, with f32 values interpreted at their represented precision.
- Float conversion, `hypot`, `atan2`, geodesic calculations and presentation are tested, not claimed proved. Their exact integer/rational inputs and formulas are proof obligations. Position tolerance is at most `1e-9` degree; every other output must match exactly except individually documented standard-backed discrepancies.
- Float **branch decisions**, particularly the Comm-B score gate, are not merely presentation. An all-input inference theorem must specify the actual binary64 operations (including constant rounding and evaluation order), or prove a complete correspondence with a rational decision procedure. Treating unrounded rational scores as identical without that proof is not allowed.

Excluded: FLARM, receiver/source protocols and APIs, demodulation, aircraft/tail-number database enrichment, JSON serving. Beast stripping is benchmark preparation only. CPR's airport proximity policy is listed below because it is called by the oracle decoder; airport lookup is not aircraft/tail-number enrichment.

## Mode S formats and parity

The user's scope clarification includes DF19 and the DF24–31 family and keeps global surface CPR as a possible extension after section 8. **DF24–31 are declared Rust variants but the pinned 14-byte reader rejects them; see `DISCREPANCIES.md`.** Scope therefore distinguishes the standard Comm-D format from the oracle rejection behavior.

| DF | Length | Decoded wire fields and reported meaning | Default JSON projection |
|---|---:|---|---|
| 0 | 56 | VS1, CC1, unused1, SL3, spare2, RI4, unused2, AC13, AP24; VS airborne/ground, SL ACAS sensitivity, RI reply information; recovered ICAO address | `df`, `altitude` (nullable), `icao24` |
| 4 | 56 | FS3, DR5, UM6 = IIS4 + IDS2, AC13, AP24 | `df`, `altitude`, `icao24` |
| 5 | 56 | FS3, DR5, UM6, identity13, AP24 | `df`, `squawk`, `icao24` |
| 11 | 56 | CA3, announced address24, raw PI24; checksum/interrogator overlay available in root `crc` | `df`, `capability`, `icao24`; raw PI/root CRC skipped |
| 16 | 112 | VS1, reserved2, SL3, reserved2, RI4, reserved2, AC13, MV56 uninterpreted bytes, AP24 | `df`, `vs`, `sl`, `ri`, `altitude`, `icao24`; reserved/MV omitted |
| 17 | 112 | CA3, ICAO24, ME56, PI24; all ME variants below | `df`, `icao24`, flattened ME; CA/PI omitted |
| 18 | 112 | CF3, AA24, ME56, PI24; oracle always applies the same ME reader even for coarse/reserved CF | `df`, `tisb`, `icao24`, flattened ME; PI omitted |
| 19 | 112 | AF3 only; remaining 104 bits consumed by outer frame reader but not interpreted by DF variant | `df: "ExtendedSquitterMilitary"`, `af` |
| 20 | 112 | FS3, DR5, UM6, AC13, MB56 candidate set, AP24 | `df`, `altitude`, `icao24`, each surviving `bdsXX` object |
| 21 | 112 | FS3, DR5, UM6, identity13, MB56 candidate set, AP24 | `df`, `squawk`, `icao24`, surviving `bdsXX` objects |
| 24–31 | 112 standard Comm-D | Standard two-bit DF=`11`, spare1, KE1, ND4, MD80, AP24; oracle instead consumes five-bit DF then tries the same remaining layout, requiring 115 bits | Oracle returns error for 14-byte input; declared variant would report `spare`, `ke`, `nd`, `md`, `parity` |

FS codes 0–5 distinguish alert/SPI and air/ground; 6 is reserved, 7 not assigned. DR0 = none, 1 = request-send-Comm-B, 4/5 = broadcast message1/2, other values collapse to Unknown in Rust. UM IDS0/1/2/3 = no information/Comm-B/Comm-C/Comm-D. CA0 = level1, 1–3 collapse to reserved, 4 ground, 5 airborne, 6 either, 7 DR0. Identity maps the Mode-A interleaving into four octal digits rendered as a four-character string (leading zeroes retained). ICAO addresses are six lowercase hex digits.

CF0..7 map respectively to `ADSB_ES_NT`, `ADSB_ES_NT_ALT`, `TISB_FINE`, `TISB_COARSE`, `TISB_MANAGE`, `TISB_ADSB_RELAY`, `TISB_ADSB`, `Reserved`; no implicit reinterpretation of an alternate address as a database identity.

Oracle hidden-field caveat: some ME readers consume fewer than56bits. `Unused` consumes5+48, TC25–27 consumes5+8, reserved TC31 subtypes consume5+3+40, and version0/reserved TC31 versions omit quality tails. Therefore the Rust ADSB/DF18 **parsed parity member** may read24bits earlier than the wire PI location. Those members are serde-skipped; the root CRC still uses the correct complete frame. The standard wire record must retain actual final24bits, and the compatibility output excludes these serde-skipped accidental parity reads.

Parity policy (**rs1090-derived**): CRC24 uses generator `0x1FFF409`; root `crc` is computed across the DF-selected whole frame. DF17 alone rejects nonzero CRC. DF0/4/5/16/20/21 use the complete remainder as recovered AP address, with no whitelist validation. DF11 retains AA and raw PI; the oracle does not reject an invalid interrogator overlay, nor expose a separate II field in JSON. DF18 also does not enforce zero remainder. Standard PI validity and DF11 overlay interpretation belong to explicitly labeled spec fields; adding their rejection to the compatibility entrypoint would be a discrepancy, not silent “cleanup.”

Altitude policy (**rs1090-derived reporting; mathematical code semantics cited in `Spec/Altitude.lean`**): AC13=0 gives unavailable. M=0,Q=1 removes M/Q and computes `25*N-1000` exactly. M=0,Q=0 uses Gillham Gray conversion, invalid patterns unavailable. M=1,Q=1 is unavailable. M=1,Q=0 uses the oracle expression `meters=((raw & 0x1f80)>>2)|(raw & 0x3f)`, then integer floor `meters*328084/100000`; this is an oracle compatibility convention for a reserved encoding, not a claim that 3.28084 is the exact physical conversion. AC12=0 is unavailable; otherwise Q/Gillham decode. With default `bds-infer`, AC12 above 50000 ft raises a decode error, including on DF17/18. AC13 has no corresponding 50000-ft filter. TC20–22 currently also use this same AC12 path despite being tagged GNSS; standards disagreement must remain visible.

## Extended squitter payloads

All code/status fields below are dimensionless bitfields or enums unless units are specified. Raw identifiers are retained for wire round-trip, even if serde omits or collapses them. The inventory and compatibility projections here are **rs1090-derived**; `Spec/` must label whether each field formula is standard-backed or uses the permitted fallback.

| TC / subtype | Fields decoded, including omitted fields | Conversion/reporting policy |
|---|---|---|
| 0 | `NoPosition` unused payload | No altitude or position reported; payload ignored by oracle |
| 1–4 / category0–7 | aircraft identification: typecode, category `ca`, wake-vortex/category interpretation, eight 6-bit callsign characters | Callsign alphabet/space processing as reader; `bds:"08"`; TC/category classification retained internally |
| 5–8 | surface: derived NUCp, movement7, track-status1, track7, time1, parity1, latCPR17, lonCPR17; optional resolved latitude/longitude | Movement mapping below; track `raw*360/128`, absent when status0; `bds:"06"`, TC retained |
| 9–18,20–22 | airborne: derived NUCp, surveillance-status2, SAF/NICb1, altitude12, source, UTC sync1, CPR parity1, lat17, lon17; optional resolved latitude/longitude | NUCp=`18-TC` for9–18; 9/8 for20/21; 0 for22. NICb present only TC<19. SS omitted in serde. AC12 policy above; `bds:"05"` |
| 19 / 0,5–7 | intent-change, IFR-capability, NACv3, reserved 22-bit velocity payload; vertical source/sign/code9; reserved2; GNSS-minus-baro sign/code7 | Reserved subtype preserved internally; other shared fields still decoded |
| 19 / 1,2 | shared fields plus EW sign+10-bit velocity, NS sign+10-bit velocity, groundspeed and track | Oracle both subtypes use signed `(raw-1)` without subtype2 ×4 scaling. `hypot(abs(EW),abs(NS))`; normalized `atan2(EW,NS)*360/(2*pi)`. Code0 becomes signed −1, not unavailable; record discrepancy rather than copy into standard semantics |
| 19 / 3 | heading status, heading10, IAS/TAS selector, speed10 | heading f64=`raw*360/1024`; status0 absent; speed0 absent, otherwise `raw-1` kt |
| 19 / 4 | heading status, heading10, IAS/TAS selector, speed10 | heading f32=`raw*360/1024`; speed0 absent, otherwise `4*(raw-1)` kt |
| 23,24,30 | reserved / surface-system-status / operational-coordination tags with unused payload | `bds` tags `id23`, `id24`, `id30`; no interpreted aircraft fields |
| 25–27 | variant ID and next `unused` byte | `bds:"id25_27"`, `_id`, `unused`; remaining payload ignored by reader |
| 28 / all subtypes | subtype enum, emergency-state3, squawk13; rest padded/ignored | subtype0 no-information,1 emergency-priority,2 ACAS-RA,3–7 reserved; oracle still uses emergency/squawk layout for every subtype; `bds:"61"` |
| 29 / all accepted subtype codes | subtype2, skipped SIL-supplement1, MCP/FMS altitude-source1, selected-altitude11, pressure9, heading-status1, heading9, NACp4, NICbaro1, SIL2, mode-status1, autopilot1,VNAV1,alt-hold1,IMF1,approach1,TCAS1,LNAV1, skipped reserve2 | Oracle uses one target-state layout; selected altitude none for0/1, else `floor(((n-1)*32+16)/100)*100` ft; pressure0 absent else f32 `800+(n-1)*0.8`; selected heading f32 `raw*180/256`; mode status gates AP/VNAV/alt-hold/approach/LNAV, not TCAS or IMF; `bds:"62"` |
| 31 / 0 | airborne capability-class, operational-mode, ADS-B version branch | Nested fields below; `bds:"65"` |
| 31 / 1 | surface capability-class, length/width code4, operational-mode, GPS antenna offset8, ADS-B version branch | Nested fields below |
| 31 / 2–7 | reserved subtype ID and five raw status bytes | Preserve reported raw bytes and tag; no standard aircraft interpretation |

For TC19, vertical rate code0 is unavailable and positive codes encode signed `64*(n-1)` ft/min; source distinguishes barometric/geometric; the pinned enum assigns0=barometric and1=GNSS, which is tracked against the standard source table in `DISCREPANCIES.md`. GNSS-minus-baro in the oracle is absent for code0 **and code1**, otherwise signed `25*(n-1)` ft, including127; standard availability/saturation treatment is tracked in `DISCREPANCIES.md`. Source/sign and raw zero codes remain available internally even where JSON flattens them.

Callsign conversion (**rs1090-derived**): eight6-bit characters map1..26 to A..Z,48..57 to0..9, other reserved codes to the reader’s `#` placeholder; code32 is removed at every position, not merely trimmed at the end. Retain raw characters for bit round-trip. TC4 category0..7 means no-information/light/medium1/medium2/high-vortex/heavy/high-performance/rotorcraft; TC3 means no-information/glider/lighter-than-air/parachutist/ultralight/reserved/UAV/space; TC2 category0=no-information,1=emergency-vehicle,3=service-vehicle,2/4..7=obstruction; TC1 is reserved.

Surface movement code: 0 and125–127 unavailable; 1→0 kt;2–8→`0.125+(n-2)*0.125`;9–12→`1+(n-9)*0.25`;13–38→`2+(n-13)*0.5`;39–93→`15+n-39`;94–108→`70+2*(n-94)`;109–123→`100+5*(n-109)`;124→175 kt. This reports quantization endpoints, not inferred exact physical speeds.

TC31 nested inventory:

- Airborne capability class: reserved2 (must zero), ACAS1, CDTI1, reserved2, ARV1, TS1, TC2; six trailing pad bits in the capability class and a padded byte after operational mode before version. Surface capability class: reserved2 (must zero), POE1,1090ES-in1,pad2,B2-low1,UAT-in1,NACv3,NICc1; plus length/width4. Capability classes and operational mode are skipped in default serde even though decoded.
- Operational mode: reserved2 (must zero), TCAS-RA-active1, IDENT-active1, reserved/ATC-service1, single-antenna1, system-design-assurance2.
- Airborne version0: no quality fields decoded. Version1: NIC supplement1,NACp4,barometric-altitude-quality2,SIL2,barometric-integrity1,horizontal-reference1. Version2: NICa1,NACp4,GVA2,SIL2,barometric-integrity1,horizontal-reference1,SIL-supplement1. Versions3–7 remain reserved enum payloads. The output version-dependent keys follow the custom serializers in `bds65.rs`.
- Surface version0: no quality fields decoded. Version1: NIC supplement1,NACp4,SIL2,track-angle-or-heading1,horizontal-reference1. Version2: NICa1,NACp4,SIL2,track-angle-or-heading1,horizontal-reference1,SIL-supplement1. Reserved versions retained as such.

## Comm-B candidate fields

The MB candidate set can be ambiguous; report every survivor. It is not a single guessed BDS code. DF20's candidates are 05,10,17,18,19,20,21,30,40,44,45,50,60,65. DF21 has the same storage shape but never attempts05. Standalone direct-register decoders are useful test sources; accepting a direct BDS09 or BDS62 payload does not imply that the DF20/21 selector tries it.

The following inventories include parsed fields hidden by serde. All inference constraints and empirical normalizations are **rs1090-derived**. Standard scaling is linked by the corresponding `Spec/` field docstring, or marked fallback there.

| BDS | All fields | Units / exact reporting conversion |
|---|---|---|
| 0,5 | airborne fields above | DF20 only; candidate altitude must equal outer AC13 option exactly |
| 1,0 | header8, config1,reserved5,OVC1,ACAS1,subnetwork-version7,level5,Mode-S-specific-services,uplink-ELM3,downlink-ELM4,identification,squitter,SIC,GICB,ACAS-hybrid,ACAS-RA,ACAS-RTCA2,DTE16 | Boolean capabilities and unsigned code fields; header0x10 and reserved zero |
| 1,7 | capability bits05,06,07,08,09,0A,20,21,40,41,42,43,44,45,48,50,51,52,53,54,55,56,5F,60; reserved tail and internal check flag | false capability keys omitted in JSON; all capability bits meaningful internally |
| 1,8 | every capability bit from38 down to01, in descending BDS order | 56 booleans; false keys omitted |
| 1,9 | every capability bit from70 down to39, descending | 56 booleans; false keys omitted |
| 2,0 | header8 and eight6-bit callsign characters | Mandatory header0x20; same character mapping as BDS08, including reserved placeholders |
| 2,1 | aircraft-registration-status1, seven6-bit registration chars, airline-status1, two6-bit airline chars | Codes0,32,45 stripped as dash/space placeholders; others map alphabet or `#`; unavailable status requires no nonplaceholder characters; actual registration and airline strings optional |
| 3,0 | header8,issued-RA1, corrective/downward-sense/increased-rate/sense-reversal/altitude-crossing/positive bits, reserved-ACAS3 field7, RAC no-below/no-above/no-left/no-right bits, terminated1,multiple1,threat-type2,threat-data26 | RA/RAC options present only when issued-RA. Threat0/3 raw unused26; threat1 ICAO24+zeros2; threat2 AC13 altitude + range7 + bearing6. Range0 absent else f32 `(n-1)/10` NM; bearing0 absent else `6*(n-1)+3` degrees |
| 4,0 | status+MCP-alt12,status+FMS-alt12,status+pressure12,reserved8,mode-status,VNAV,alt-hold,approach,reserved2,source-status,target-source2 | Altitudes output `floor((16*n+8)/100)*100` ft (not conventional nearest100); pressure f64 `800+n*0.1`; target source Unknown/AircraftAltitude/FcpMcuSelectedAltitude/FmsSelectedAltitude |
| 4,4 | figure-of-merit4,wind-status,wind-speed9,wind-direction9,temperature sign+10bits,pressure-status+11bits,turbulence-status+2bits,humidity-status+6bits | Wind kt; direction `n*180/256`; temperature signed quarter-degree with legacy wrap below−80 adding256; pressure raw hPa; humidity `n*100/64`%; turbulence nil/light/moderate/severe. Default inference rejects any present turbulence/humidity |
| 4,5 | status+2bit level each for turbulence,wind-shear,microburst,icing,wake-vortex; temperature-status+sign+9bits; pressure-status+11bits; height-status+12bits; reserved5 | Levels nil/light/moderate/severe; temperature signed `n/4`°C; pressure raw hPa; radio height `n*16`ft |
| 5,0 | roll status/sign/9bits; true-track status/sign/10bits; ground-speed status/10bits; track-rate status/sign/9bits; TAS status/10bits | Roll signed×45/256 degrees; track signed×90/512 normalized to[0,360); GS/TAS×2kt; rate signed×8/256 degree/s, value511→None even when status set |
| 6,0 | magnetic-heading status/sign/10bits; IAS status/10bits; Mach status/10bits; barometric-rate status/sign/9bits; inertial-rate status/sign/9bits | Heading signed×90/512 normalized; IAS raw kt; Mach f64 `n*2.048/512`; rates signed×32ft/min, magnitude0/511→Some(0) independent of sign |
| 6,5 | TC31 operation-status structure above | Selector checks TC31 and subtype0/1, but calls the subtype reader at payload start: top3bits=7 routes to reserved5bytes and exact-slice decoding fails on leftover bits. Four concrete probes return no65 candidate (see ledger) |

Status-gated Comm-B numeric fields generally require all value and sign bits zero when unavailable. An unavailable code is not the same as present zero. Per-field exceptions above must be preserved. Unrecognized/spare bits and statuses are validated exactly as their reader does, without inferred extra aircraft-plausibility checks.

## Default inference decision policy

Policy sources: pinned `commb.rs`, each `bds/bdsXX.rs`, `bds/mod.rs`, `bds/density.rs`, `bds/penalty.rs`. These are the intentional oracle-as-spec exception, not normative aviation rules.

1. All-zero MB yields `is_empty=true` and no candidates (flag skipped in serde).
2. DF20 attempts BDS05 only when `9 <= TC < 22 && TC != 19`; this excludes TC22 despite the reader comment. The decoded altitude option must exactly equal the same frame's outer AC13. DF21 does not attempt it.
3. Independently attempt10,17,18,19,20,21,30,40,44,45,50,60. Retain all successful candidates after the relevant score gate. No winner-take-all or cross-message filter is automatically applied by `Message::from_bytes`.
4. Attempt65 only for TC31 and low3bits<2. The selector calls `AircraftOperationStatus::try_from` on the full seven bytes; this reader's own subtype consumption is authoritative for oracle behavior.
5. Default `bds-infer` hard bounds: BDS05 altitude≤50000ft; BDS40 rounded selected altitudes≤50000ft and pressure800..1200hPa; BDS44 FOM INS/GNSS only, wind≤250kt,temp−80..60°C,no present turbulence/humidity; BDS45 no present turbulence/wind-shear/microburst/icing/wake-vortex via its unused-level readers and temp−80..60°C; BDS50 |roll|≤45°,GS≤700kt,TAS80..600kt; BDS60 IAS≤500kt,Mach≤1,inertial rate |v|≤6000ft/min (barometric rate unbounded). Structural headers, zero reserves, capability restrictions and status consistency are also required.
6. BDS17 requires20=true, capability41/42/43/48/54/55/56=false, and bits30..56 zero; its intervening five reserved bits are not rejected. BDS18 requires20/19/18/17=true; only30/21/20/1F/1E/1D/1C/1B/1A/19/18/17/10/0F/0B/0A/09/08/07/06/05 may be true. BDS19 permits only65/62/61/60/5F/53/52/51/50/45/44/40 true. All unlisted capability bits must be false. `Spec/CommB.lean` gives the exact bit-index predicates for approval.
7. BDS21 requires airline status false and both airline characters stripped placeholders; a true airline status is rejected. Aircraft registration may contain at most two `#` characters under `bds-infer`; registration matching against ICAO country blocks is only in the optional context sanitizer.

For40/44/45/50/60, field decode success additionally passes the density-plus-penalty gate. Define `G(x,mu,s) = -0.5*z*z`, `z=(x-mu)/s`; `L(x,m,b)=-abs(x-m)/b`. Evaluate each present score in the order below, sum left-to-right from0, divide by present count. When there are no scored fields and penalty is zero, accept; otherwise use zero in place of an absent density, add the penalty, and reject only when the result is less than−3. Preserve binary64 operation order/constants.

| BDS | Ordered density terms |
|---|---|
|40|L(QNH,1013.2,5.4);G(MCP,24688,10844);G(FMS,24688,10844)|
|44|L(temperature,−21,9.90);G(wind,52,29);L(pressure,393,290)|
|45|G(temperature,−14.2,16.4);L(pressure,393,290)|
|50|L(roll,0,10);L(turn-rate,0,0.70);G(TAS,413,120);G(GS,418,129)|
|60|G(IAS,272,55);G(Mach,0.69,0.21);G(inertial-rate,−298,1669)|

Penalty starts0: for50 subtract `abs(TAS-GS)/100` when both exist; subtract2 if |roll|>5°,|rate|>0.3°/s and their signs disagree. For60 subtract3 if Mach>0 and IAS/Mach lies outside250..800. Gate threshold is−3 inclusive. The library also defines a BDS05 altitude density `G(alt,26302,10573)`, but the raw DF20 selector does not call its score gate; do not apply it there accidentally.

Optional `MessageProcessor` sanitization is outside the requested stateless `Message::from_bytes` contract. For reproducibility its policies are recorded: same-aircraft altitude disagreement>100ft rejects05; stable BDS17 capability set after three consistent records rejects unsupported candidate registers; country registration regexes filter21; headers10/20/30 evict other candidates; GICB17/18 contradictions against observed transmissions act only when a non-GICB alternative survives (19 is treated consistent); local CPR discrepancy>5NM rejects05. Evidence tracking records surviving data registers and builds stable capabilities. These extra tracking/database operations are not part of either frozen benchmark unless separately named in a later approved extension.

## CPR API and pairing policy

Required: airborne global even/odd decoding, airborne local decoding, surface local decoding against a reference, and the pinned stateful pairing policy. **Global surface CPR is not required by the user's subsequent scope clarification; it is a possible extension after section8.**

Stateless airborne global: opposite parity required; normalize CPR17 by131072; latitude index `floor(59*yEven−60*yOdd+0.5)`; spacing360/60 and360/59. Latitudes≥270 subtract360; reject either latitude outside[−90,90] or differing NL zones. Return the later argument's parity/latitude; longitude uses `floor(xEven*(NL−1)−xOdd*NL+0.5)`, `ni=max(NL−parity,1)` and spacing360/ni; longitude≥180 subtract360. Timestamps are not checked by this low-level routine.

Stateless local: spacing360/(60−parity) airborne or90/(60−parity) surface; index `floor(0.5+reference/spacing−normalizedCPR)`. Reject latitude outside[−90,90] or latitude/longitude offset beyond half respective cell. Longitude spacing uses NL(decoded latitude)−parity, fallback360 or90 if≤0. Local longitude is not explicitly normalized at±180 by the oracle. Distance preconditions for a mathematical round-trip must account for quantization and zone stability, not merely restate a successful decode as an assumption.

State keyed by ICAO: latest accepted position/time, altitude, optional airport, last even/odd airborne message/time, seen BDS codes, declared supported BDS codes/count. Every run starts empty. Arrival order is corpus order, with no sorting:

- Reject an airborne update entirely when its timestamp is earlier than stored opposite-parity timestamp.
- Try opposite-parity global when time difference is strictly<30s. On failure try last accepted aircraft position when age is strictly<180s. There is no initial airborne fallback to the external reference.
- If a new position has an older accepted reference and the absolute time gap<1800s and>0, reject implied speed>1200km/h. The actual code also rejects distance>500km when absolute gap<30s, even after a global decode (the nearby comment suggests a narrower purpose than the condition).
- Validation failure retains the last good position; store the current parity message/time after normal processing even when no new position is accepted. Out-of-order early return does not store it. On acceptance set message coordinates and latest position/time/altitude, clear airport, record05; optional callback may update external reference.
- Surface: first try previous aircraft position; accept only if distance strictly<1km. Otherwise use external reference if supplied. If no prior aircraft position, accept this result only within strictly10km of an airport from the pinned database. A prior position removes that airport precondition. No surface message pairing/global solver is called. On acceptance update position/time, clear altitude, record06, and find nearest airport within10km if not already recorded.
- Other ADS-B types register the corresponding observed BDS code. `decode_positions` applies this to DF17/18 only, using the announced address even for alternate-address CF categories. Comm-B BDS05 candidates do not enter this routine.
- `update_global_reference` is a separate opt-in helper: selects the position of the lowest-altitude aircraft active within300s, treating unavailable altitude (surface) as lower than any known altitude. It is not automatically called by offline `decode_positions`; the frozen benchmark supplies no update callback and an initially absent external reference.
- Haversine uses Earth radius6371km; nautical miles divide by1.852. These floating distance checks, their exact inequality boundaries, and the airport dataset version belong to the tested compatibility layer, not a claim of machine-checked transcendental Float correctness.

## Evidence and unresolved review items

Commands already run: `git -C vendor/rs1090 rev-parse HEAD`; source inspection with `sed`/`rg`; the default-feature `cargo build --locked --manifest-path vendor/rs1090/Cargo.toml -p rs1090 --profile dist`; corpus byte/hash/count inspection with Python; and the format probe retained in `bench/oracle`.

The checked corpus has172432 lines, no header,10186581bytes, SHA256 `3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505`. Count every row, including the first. See `bench/BENCHMARK.md` for exact benchmark preparation and checks.

Checkpoint review must distinguish the complete reference definitions from unproved universal capstones and the tested-only Float/serialization boundary in `THEOREMS.md`. The DF24 parser failure is an observed discrepancy. Other quirks listed here are observed code behavior, not yet automatically classified as standard violations; a discrepancy exception requires a concrete message, both outputs, and an actually read standard clause. Concrete standard/oracle projection probes are recorded in `DISCREPANCIES.md`, with executable Lean expressions and captured outputs. No full differential corpus comparison or proof completion is claimed in this stage.


## Exact JSON key and omission contract

This is an **rs1090-derived** reporting projection, separate from the richer wire-field inventory. Object key order is irrelevant; array order, case, tag values, missing keys and nulls are significant. Every surviving Comm-B `bdsXX` object is nested under that key; absent candidates are omitted. Comm-B10/17/18/19/20/21/30/40/44/45/50/60 objects include their string `bds` tag. BDS05 is the shared airborne object without its own inner tag. The flags used only for validation are not extra output keys.

| Payload | Keys / omission rules |
|---|---|
| ADS-B05 | `tc`, `NUCp`, nullable `altitude`, `source` (`barometric`/`GNSS`), `time_sync`, `parity` (`even`/`odd`), `lat_cpr`, `lon_cpr`; `NICb` only when present; `latitude`/`longitude` only after resolution; SS omitted |
| ADS-B06 | `tc`, `NUCp`, nullable `groundspeed` and `track`, `parity`, `lat_cpr`, `lon_cpr`; coordinates only when present; time/track-status omitted |
| ADS-B08 | `wake_vortex`, `callsign`; category/TC omitted; wake-vortex strings are `Reserved`, `n/a`, `Surface emergency vehicle`, `Surface service vehicle`, `Obstruction`, `Glider`, `Lighter than air`, `Parachutist`, `Ultralight`, `UAV`, `Space`, `<7000kg`, `<34,000kg`, `<136,000kg`, `High vortex`, `Heavy`, `High performance`, `Rotorcraft` |
| ADS-B09 | `NACv`, `vrate_src`; `vertical_rate` omitted when unavailable; `geo_minus_baro` always present and null when unavailable; subtype/intent/IFR/sign/reserved flags omitted; subtypes1/2 add `groundspeed`,`track`; subtypes3/4 add optional `heading` and exactly one of `IAS`/`TAS` when speed is available; reserved subtypes0/5/6/7 expose `reserved_data`: standard/raw view preserves the22 wire bits MSB-first; the explicitly rs1090-derived oracle view uses `first8 + 256*next8 + 65536*last6`, matching deku0.20.3's target-endian reader on pinned x86_64 (host-dependent, not a portable wire convention; D011) |
| ADS-B61 | `subtype` (`no_information`,`emergency_priority`,`acas_ra`,`reserved`), `emergency_state` (`none`,`general`,`medical`,`minimum_fuel`,`no_communication`,`unlawful_interference`,`downed_aircraft`,`reserved`), `squawk` |
| ADS-B62 | `source` (`MCP/FCU`/`FMS`), `NACp`, `nic_baro`, `tcas_operational`; omit absent `selected_altitude`,`barometric_setting`,`selected_heading`,`autopilot`,`vnav_mode`,`alt_hold`,`approach_mode`,`lnav_mode`; subtype,heading-status,SIL,mode-status,IMF and spare bits omitted |
| ADS-B65 | versions0/3..7 report numeric `version`; version1/2 adds the version-dependent uppercase quality keys in the nested-field inventory above; `TAH` names surface track-angle/heading and `SILs` the supplement. Capability/operational classes, length-width and antenna offset are omitted. Reserved subtype reports `id` and `status` containing `data` byte array |
| Comm-B10 | `config`,`ovc`,`acas`,`subnet`,`level5`,`mode_s`,`identification`,`squitter`,`sic`,`gicb`,`acas_hybrid`,`acas_ra`,`dte`; header, reserves,uplink,downlink,ACAS RTCA omitted. Standard/raw `dte` preserves MB bits41–56 MSB-first (Doc9871 TableA-2-16); the explicitly rs1090-derived oracle value is `first8 + 256*last8`, matching deku0.20.3's target-endian u16 reader on pinned x86_64. This swaps the two wire bytes and is host-dependent, not a portable wire convention (D012). |
| Comm-B17/18/19 | named `bdsXX` capability keys only when true; no false entries, reserves or check flag |
| Comm-B20 | `callsign` |
| Comm-B21 | nullable `registration`; optional `airline`; status bits omitted |
| Comm-B30 | `issued_ra`,`terminated`,`multiple`; each advisory/RAC bool omitted when absent; flattened threat variant: no identity gives no threat keys; address gives `threat_identity`; orientation gives nullable `threat_altitude`,`threat_range`,`threat_bearing`; header/reserves omitted |
| Comm-B40 | optional `selected_mcp`,`selected_fms`,`barometric_setting`; `target_source` omitted when Unknown, else enum spelling `AircraftAltitude`,`FcpMcuSelectedAltitude`,`FmsSelectedAltitude`; mode/source statuses, mode bits,reserves omitted |
| Comm-B44 | `figure_of_merit`,`wind_speed`,`wind_direction`,`temperature`,`pressure`,`turbulence`,`humidity`; unavailable optional fields are null |
| Comm-B45 | `turbulence`,`wind_shear`,`microburst`,`icing`,`wake_vortex`,`static_temperature`,`static_pressure`,`radio_height`; unavailable optional fields are null; reserve omitted |
| Comm-B50 | `roll`,`track`,`groundspeed`,`track_rate`,`TAS`; unavailable fields are null |
| Comm-B60 | `heading`,`IAS`,`Mach`,`vrate_barometric`,`vrate_inertial`; each unavailable field omitted |

`Spec/Presentation.lean` records every nonintegral payload numeric expression with explicit binary32/binary64 conversion, operation order, output key and omission/null policy. It also separates standard TC19 velocity/source/height-difference and TC20–22 metre-height views from the oracle projections. This is an inspectable formula specification, not a claim that a Float evaluator or JSON emitter has already been implemented or proved. Resolved CPR formulas/policies remain in `Spec/CPR*.lean` and the CPR section above.


## Reference interfaces included at checkpoint1

`Spec/Message.lean` composes all frame, parity, altitude, ADS-B and Comm-B definitions into a total exact-input decoder and an independent encoder; `decodePrefix` additionally preserves the source API remainder. `Spec/Semantics.lean` attaches exact quantities, optional values, strings/labels, typed threat semantics and ordered Float-expression operands to the decoded message. Implementation refinement therefore constrains these meanings as well as raw field codes. JSON serialization is a tested adapter consuming that semantic record; no proof of an unwritten serializer is claimed.

The unfiltered structural codecs `decodeFrame`, `decodeADSBFields` and `decodeBDSFields` cover every representable field assignment. Separate receiver codecs apply the documented plausibility/acceptance policy. Both have independent round-trip targets. A schema-valid50175ft ADS-B altitude and BDS50 GS1000kt/TAS60kt are concrete proved examples outside receiver acceptance; full-domain theorems are not narrowed to make receiver heuristics look like standard validity.

`Spec/CPRPolicy.lean` includes the complete state transition and full airborne callback metadata. `Spec/CPRFloat.lean` supplies explicit ordered numerical local/global decoding and haversine callbacks. Mathematical CPR theorems concern the exact rational equations; the numerical adapter is tested. Callback/reference/timestamp inputs use finite represented values; nonfinite haversine distance results have explicit comparison behavior. The pinned airport list is supplied as data.


## Approved checkpoint amendments

The headline times `Impl.decode` including every projection into the exact model, bound by `scripts/Final.lean`. `Model/` shares data types without reference formulas; the gate rejects direct or transitive `Spec/` or Mathlib imports in `Impl/`. The frozen inventory includes these model types, the exact final manifest and dependency-audit programs. The requested Capstones/benchmark diff has been reviewed; the user authorized the final dependency fixes and SHA256 freeze.

`Valid` is independent frame validity; semantic report construction is in the round-trip conclusion. The Lean environment audit checks all seven named validity/admissibility predicates for transitive decoder/helper dependencies. Global CPR admissibility compares NL on the encoder-side quantized latitudes. The separate rejection theorem still concerns reconstructed latitudes. The CRC reference is Mathlib polynomial division over `ZMod 2`.

Every complete worked source frame and every published decoding quantity found in the consulted documents is anchored by kernel-checked literal expectations in `Spec/StandardExamples.lean`; the source inventory and editorial contradictions are in `docs/STANDARD-EXAMPLES.md`. Comm-B structured generation uses `encodeBDS` for every register and explicitly targets plausibility and score boundaries; see `docs/FUZZING.md`. The first BDS50 implementation uses proof-visible binary64 decisions, with all-input refinement and corpus plus4504-case differential checks. It measured0.2416× Rust throughput; this is a component baseline, not the whole-message performance target.


The final freeze also audits the complete `assigned` conclusion constructor.
Its independent report interpretation uses MSB-first source-column assembly and
Gray-prefix altitude formulas, with no reference decoder or inference helper.
The unchanged MessageRoundTrips contract must prove this separately constructed
report equals decoding the encoded assignment. Exhaustive kernel altitude checks
and all29 successful complete source fixtures check the new constructor now.

The BDS50 result type is `Lean1090.Model.BDS50.Result`, defined in
`Model/BDS50.lean`. Frozen Lean files import only the reference/model, Mathlib
and Lean standard libraries; the compiled reference graph cannot reach Impl or
Proofs. Final and pilot manifests are import-free declaration fragments compiled
verbatim under temporary integration imports by the frozen audit runners.
`scripts/check_all.sh` checks the SHA256 lock before any build or audit, and the
lock includes its own inventory/checker plus the audit programs and entrypoints.

## Worked-example coverage addendum

[docs/LAYOUT-ANCHORS.md](docs/LAYOUT-ANCHORS.md) gives the exhaustive70-branch
ADS-B TC/subtype/version inventory and all14 Comm-B registers, separating source
examples from captured regression expectations. Kernel checks through
`Spec.decode` cover24 distinct worked Sun frames (23 successes and one corrupt
rejection), but **zero ICAO worked decoding frames**; the four ICAO arithmetic
assertions are not decoding examples. The six raw-only Sun frames are additional
regressions, not worked decoding anchors.

Published payload anchors exist for ADS-B TC4, TC7, TC11, TC19.1 and TC19.3, and
Comm-B17/20/40/44/45/50/60. Every other branch is explicitly labelled
**rs1090-derived; no worked-example anchor** in the linked inventory. For Comm-B,
the missing registers are05/10/18/19/21/30/65, including all their internal
variants. BDS05's shared TC11 ADS-B example does not independently validate the
DF20 candidate path; the address-parity calculation does not validate BDS10.

This label describes compatibility and the lack of independent worked-example
validation. It does not falsely change a standard table's provenance: the
inventory separately records the actual table source for each frozen schema,
and identifies schemas whose detailed table was unavailable and was itself
rs1090-derived. A round-trip or shared layout is not counted as a published anchor.
The reference definitions and all61 frozen file hashes remain unchanged.
