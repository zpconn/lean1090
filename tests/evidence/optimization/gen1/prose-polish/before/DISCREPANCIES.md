# Discrepancy ledger — checkpoint 1

These entries record source review and small oracle probes, not a completed differential campaign. A **confirmed oracle observation** is separate from an accepted differential exemption. The final exemption must contain the executable Lean answer and an actually read standard clause, and must be approved where the spec itself is in question. Do not treat the pending items below as blanket exclusions from testing.

## D001: Comm-D's two-bit DF is consumed as five bits

- Oracle pin: `685dfaa34c5ab186c691bca3cfe2a22e12517d30`.
- Concrete input: `c000000000000000000000000000` (14 bytes).
- Observed rs1090 answer: `Err(Incomplete(NeedSize { bits: 24 }))`.
- Standard interpretation: Comm-D DF=`11` (2 bits), spare=0, KE=0, ND=0, MD=10 zero bytes, AP=0. The standard outer frame has 112 bits. The recovered address is computed from parity; a zero raw AP does not itself make a Comm-D frame invalid.
- Executed Lean answer (`decodeFrame`): `some { body := FrameBody.commD 0 0 0 0, parity := 0 }` (bitvector fields). Captured in `bench/evidence/semantic-lean.txt`; executable expression in `bench/evidence/SemanticProbes.lean`.
- Standard clause: ICAO Annex 10 Vol.IV §3.1.2.7.3, Comm-D extended-length communication protocol, downlink format 24 layout. The DF field is 2 bits. Acquisition and actual source passage are recorded by the standard-spec source notes/docstrings.
- Cause inspected in `crates/rs1090/src/decode/mod.rs`: outer wrapper reads 112 bits; derived `DF` dispatch consumes 5 bits before `CommDExtended`'s spare1+KE1+ND4+MD80+AP24. Total is 115 bits. The wrapper only supplies the 112-bit buffer to the derived reader, so extra bytes in the caller's input cannot fix it.
- Reproduction: `bench/run_oracle.sh --probe-formats`; retained output `bench/evidence/formats.txt`. Inputs beginning `c0`, `c8`, `d0`, `d8`, `e0`, `e8`, `f0`, `f8` followed by 13 zero bytes all produce the same error. This sampled observation plus the fixed reader-width sum explains the family; it is not a machine-checked proof of every oracle input.
- Scope decision: the user requested DF24–31 coverage. Preserve the standard Comm-D layout and the explicit oracle disagreement; do not silently remove the family from scope or invent successful rs1090 output.

## D002–D004: TC19 velocity scale, source and zero altitude difference

Concrete parity-valid DF17 message: `8d1122339a000300800801cb9966` (CRC0). Payload subtype 2, EW code 3, NS code 4, positive signs, vertical-source 0, vertical-rate code 2, GNSS-minus-baro code 1.

| Field | Executed Lean standard view | Observed oracle view | Source actually read |
|---|---|---|---|
| D002 components | `some (8,12)`kt | `(2,3)`kt, groundspeed 3.605551275463989 kt | Sun 2nd ed. table 7.2, §7.3 equations 7.8–7.9: factor 4 for subtype 2 |
| D003 rate source | `"GNSS"` | `"barometric"` | Sun table 7.1 and §7.1: source 0 GNSS, 1 barometer |
| D004 GNSS-minus-baro | `some 0`ft | `None` (JSONnull) | Sun §7.2 equation 7.4: signed(code −1)×25, unavailable allzero/allone |

`Presentation.standardVelocityComponents`, `standardVerticalSource` and `standardGeoMinusBaro` are the executed standard views; explicitly named oracle views preserve the incompatible reader answers for comparison. The standard Float speed expression is hypot(8,12); this probe checks the exact components, without asserting a machine-checked libm result. The oracle uses the same track formula on components 2,3, reporting 33.690067525979785°.

## D005–D006: TC19 unavailable component and all-one height difference

Concrete parity-valid DF17 message: `8d1122339900000010007f1027d0` (CRC0). Payload subtype 1, EW=NS=0, vertical-source 1, vertical-rate 0, altitude-difference 127.

| Field | Executed Lean standard view | Observed oracle view | Source actually read |
|---|---|---|---|
| D005 velocity | `none` | components(−1,−1), groundspeed 1.4142135623730951 kt, track 225° | Sun table 7.2 and §7.3: zero component means no velocity information |
| D003 source (second polarity) | `"barometric"` | `"GNSS"` | Sun table 7.1, §7.1 |
| D006 GNSS-minus-baro | `none` | `Some(3150)`ft | Sun §7.2: all-one field unavailable |

## D007: GNSS height treated as Q-bit feet

Concrete parity-valid DF17 message: `8d112233a0010000000000b2fb95` (CRC0). TC20, 12-bit height code 16.

- Executed `Presentation.standardGNSSHeightMetres`: `some 16`metres.
- Observed oracle: `alt: Some(-1000), source: Gnss` (altitude convention is feet). Executed compatibility projection `adsbAltitude` also yields `some (-1000)`.
- Source actually read: Sun 2nd ed. §5.5.2, which gives the unsigned 12-bit GNSS height in metres. AC12 Q/Gillham barometric decoding belongs to the other altitude branch.

All three DF17 messages above were constructed with the Mode S polynomial and the pinned oracle independently reported CRC0. Raw Rust and Lean outputs are retained in `bench/evidence/semantic-oracle.txt` and `semantic-lean.txt`. Reproduce Lean with `lake env lean bench/evidence/SemanticProbes.lean`; reproduce each Rust answer with `.cache/rs1090-target/dist/lean1090-oracle-bench --probe-hex HEX` after `bench/run_oracle.sh --check` builds it. These are narrow source-backed fixtures, not a 10M-message test claim or automatic approval of all future exceptions.

## D008: representable altitude rejected by the default heuristic

Concrete parity-valid DF17 message: `8d11223348fff000000000509bc4`, TC9 and altitude code 4095. Executed standard `Altitude.decodeAC12 4095` returns `some 50175` ft; the pinned oracle returns `Err(Assertion("BDS 05 altitude 50175 ft > 50 000 ft"))`. The default-feature compatibility decoder also rejects this frame, while the standalone altitude semantics correctly retains the representable value. Source: Sun §5.5.1 Q-bit equation and ICAO Annex 10 IV §3.1.2.6.5.4(d), read editions in `docs/SOURCES.md`. This is an explicit receiver-acceptance heuristic, not an invalid altitude code. The message-level round-trip domain and the altitude representability theorem must identify this distinction. Reproduction is appended to the same semantic probe files.

## D009: global CPR rejected at the exact 87° latitude boundary

Concrete parity-valid DF17 pair, both encoding latitude 87° and longitude 0°:

- Even: `8d11223348010200000000f81a47`, CPR `(65536,0)`.
- Odd: `8d11223348010508880000d59619`, CPR `(33860,0)`.
- Both pinned Rust decodes and the executed Lean syndrome calculation return CRC0. `CPR.encode` independently returns those two coordinates for the physical position `(87,0)`.
- Executed standard result, with the even report latest: `CPR.decodeGlobal ⟨false,65536,0⟩ ⟨true,33860,0⟩ false = some { lat := 87, lon := 0 }`.
- Observed pinned oracle result: `airborne_position(odd, even)=None`.

The standard NL formula gives 2 at 87°. The odd reconstructed latitude lies just below 87° and is also in NL2. The oracle table instead uses 1 at exactly 87°, so its global decoder rejects the pair at the unequal-zone check. The same table discrepancy is symmetric in latitude, but the retained executable pair above tests the positive boundary only. This is not a claim that every polar pair differs.

Source actually read: ICAO Annex 10 Vol.III, PartI, amendment 77 (28 November 2002), §2.6.2(f), including the defining NL formula, and §2.6.7(d)–(g), global zone check and longitude reconstruction; seven-page excerpt with acquisition and SHA256 in `docs/SOURCES.md`. `CPR.nl_87_discrepancy` separately proves that 87° belongs to the represented latitude domain and that the source/oracle tables differ there. The general NL-versus-formula theorem remains an unproved capstone at this checkpoint.

Reproduction: `bench/run_oracle.sh --probe-cpr` and `lake env lean bench/evidence/CPRProbes.lean`. Captured results are `bench/evidence/cpr-oracle.txt` and `bench/evidence/cpr-lean.txt`. The probe calls the public oracle CPR function on two actually decoded messages; it does not reproduce the oracle NL implementation. It performs no timing and changes no benchmark workload.

The synthetic campaign in `docs/CPR-SYNTHETIC.md` extends D009 to both hemispheres, both airborne global recency choices, and airborne/surface local decoding. Among 535,748 compiled runtime/reference/oracle calls, 204 differences satisfy the exact ±87° condition and match a test-only counterfactual changing only NL at that equality. Every input, output bit pattern, and counterfactual result is retained in `tests/evidence/cpr-synthetic-full/differences.json`; all other numerical outputs match the oracle bit for bit. The existing source clauses above justify the same equality correction. This is a narrow executable classification, not a blanket polar-region exemption. Separately retained rational-versus-binary64 half-cell ties all violate the strict admissibility hypothesis and are documented as numerical-boundary differences, not oracle defects.

## D010: negative Gillham altitudes reported as missing

The pinned rs1090 (`685dfaa34c5ab186c691bca3cfe2a22e12517d30`) reports
**all negative Gillham heights as missing**, although the standard defines
negative altitude codes. The standard view retains these heights. Only the
explicitly named oracle compatibility views reproduce the missing values;
this policy does not redefine standard validity or representability.

Sources actually read for this entry:

- ICAO Annex 10, Volume IV, fourth edition (July 2007),
  **§3.1.2.6.5.4(c)** (printed p.3-30, amendment 85 page dated 18 November 2010)
  specifies the M=0, Q=0 Mode C bit order and refers to
  **§3.1.1.7.12.2.3** (p.3-7). That clause points to the
  **Appendix to Chapter 3, “SSR automatic pressure-altitude transmission code
  (pulse position assignment),” p.3-87** (PDF page 109). The table was visually
  inspected: its negative ranges include −950 to −850 ft with C1=C2=1 and
  every other pulse zero. This is the −900 ft Gillham code AC13=`0x1400`.
  It is not an unavailable all-zero altitude code under §3.1.2.6.5.4(f).
- Sun, *The 1090 Megahertz Riddle*, second edition (2021),
  **§13.2, equation(13.1), pp.104–105**, gives
  `500*N500 + 100*N100 − 1300` feet with the stated Gillham validity and
  reflection rules. It also defines the negative value −1200 ft for
  AC13=`0x100` in the corpus case below. The ICAO appendix page cited above
  starts at −1000 ft; the −1200 ft interpretation is attributed to Sun's
  formula, not to a nonexistent row of that table.
- The exact acquired PDFs, editions, acquisition URLs and SHA256 hashes are
  recorded in [docs/SOURCES.md](docs/SOURCES.md): Annex 10 IV
  `0ddf4c14855ecb73009d912a5ef52bb2e559910548c574e88eacb72028b837ce`
  and Sun
  `29868db6d85ee15e9e54c22f5b9b7b8843c5069d9a7ed5ac6aff332ae998ffe0`.
  The negative signs in the scanned ICAO table were checked on the rendered
  page because the text extraction misreads them as `B`.

The following complete frames were executed through the runtime and actual
`Message::from_bytes`; both DF17 examples have CRC0, and both DF4 examples
recover address`112233` from AP:

| Message | Code / encoding | Executed standard altitude | Observed rs1090 / compatibility altitude |
| --- | --- | --- | --- |
| `2000140049aa6c` | AC13=`0x1400`, Gillham | −900 ft | missing (`null`) |
| `8d11223348a000000000003e986f` | AC12=`0xa00`, Gillham | −900 ft | missing (`null`) |
| `2000001091a4b4` | AC13=`0x010`, binary25 control | −1000 ft | −1000 ft |
| `8d11223348010000000000fe0fdb` | AC12=`0x010`, binary25 control | −1000 ft | −1000 ft |

The independent standard decoders `Altitude.decodeGillham`, `decodeAC13` and
`decodeAC12`, their encoder/domain definitions, and the standard report
projection remain unchanged. The compatibility functions `oracleAC13` and
`oracleAC12`, plus the independent assignment compatibility meanings, apply
the missing-value rule only when Q=0 and the Gillham height is negative.
For AC12 this means an accepted message with missing altitude (`some none`),
not whole-message rejection. Negative binary25 heights remain available in
both views, as the two controls demonstrate.

Cause inspected: `decode/mod.rs::gray2alt` computes a count in units of 100 ft,
then returns an error if the count is less than 13 instead of returning the
negative signed result. `AC13Field::read` and `bds05.rs::decode_ac12` turn
that error into a missing altitude. This also affects the explicitly
rs1090-derived Comm-B inference policy: it compares the BDS05 altitude
option with the outer DF20 altitude option, including `None == None`.

The concrete corpus case is row 17040,
`a1000000920805003ffc0005c6e5`: outer AC13=0 is missing; MB
`920805003ffc00` has AC12=`0x080`, which expands to AC13=`0x100` and has
standard height −1200 ft. rs1090 retains BDS05 with missing height because
both compatibility heights are missing. After the approved correction,
lean1090 reports the same candidate and preserves −1200 ft in its standard
BDS05 view. The initial full-corpus comparison had 33 candidate-set
mismatches from this compatibility error; that count describes the retained
initial failure, not a new full-corpus pass.

The user approved the two-file compatibility correction on 2026-10-16,
requiring a permanent exhaustive oracle comparison and this discrepancy
entry. The review comparison covers all 8192 AC13 codes and 4096 AC12 codes;
complete review results are in `tests/evidence/altitude-proposal/`.
The permanent differential gate must compare all 12288 codes without
exempting D010 from the compatibility comparison. The source-backed
standard/oracle difference is expected only in the standard view.

The five executed complete-frame probes (the table plus the corpus case),
both full outputs and source hashes are retained in
[tests/evidence/negative-gillham/](tests/evidence/negative-gillham/).
Reproduction commands are in that directory's README. All five compatible
outputs match the oracle, and all three negative-Gillham standard outputs
retain the source-defined height. These fixtures do not by themselves
constitute the complete differential suite.

## D011: reserved TC19 velocity data uses target byte order

Concrete DF18 input: `9011223398040000000000000000` (TC19, subtype 0).
Only the first of the 22 reserved velocity bits is set. The executed
standard/raw view reports `reserved_data: 2097152` (`0x200000`, MSB-first);
pinned rs1090 reports `reserved_data: 128` (`0x80`). The standard view keeps
the raw MSB-first value. The separate oracle view reproduces 128 without
assigning an aircraft quantity to these reserved bits.

Source actually read: ICAO **Doc 9871, second edition (2012), including
amendment 1 entered 9 January 2017, Tables A-2-9a and A-2-9b**, printed
pp.A-32–A-33 (PDF pages 60–61). Both tables explicitly mark TC19 subtypes
**0,5,6,7 reserved**. The edition/amendment pages and the subtype-code
columns were read on 2026-10-16 from the
[published-document mirror](https://manuals.plus/m/07560cb9fbd061450f9d216b298160181a57c0b1a7795edc699cfaeb1e80fb7b.pdf).
The browser's extracted PDF text was available; its screenshot endpoint
failed and direct download returned HTTP403, so no locally acquired PDF or
PDF hash is claimed. Sun's second edition, chapter 7, table 7.1 (p.69),
independently locates the subtype-specific 22 bits at ME14–35 and defines
subtypes 1–4, but is not cited as explicitly listing the reserved codes.
The standard reservation gives these bits no velocity semantics; preserving
their raw MSB-first value is the project's lossless wire convention.

Cause inspected in the pinned sources:

- rs1090 `crates/rs1090/src/decode/bds/bds09.rs:236–240` defines
  `ReservedVelocityData` with `#[deku(bits = "22")] reserved_data: u32`
  and **no endian attribute**. Its enum routes subtypes 0 and 5–7 through
  this struct (lines 218–234).
- `vendor/rs1090/Cargo.lock:1302–1305` pins **deku 0.20.3**.
  Its `src/impls/primitive.rs:679–691` selects `Endian::default()` for a
  bit-sized primitive. `src/ctx.rs:34–44,60–65` defines that default from
  the target CPU's endianness. These files were read from the locked Cargo
  registry source under `.cache/cargo/registry/src/`.
- The little-endian primitive path pads the final six-bit chunk on its
  left, then interprets the 8,8,6-bit chunks least-significant first
  (`src/impls/primitive.rs:289–329`). Therefore the compatibility value is
  `first8 + 256*next8 + 65536*last6`, not the 22-bit MSB-first integer.

This oracle value is **host-endian-dependent**. The compatibility target
and fresh oracle are pinned to **x86_64** (`uname -m` confirmed the target;
the probe below confirms its little-endian output). No claim is made that
the same rs1090 value is portable to a big-endian host. This is an explicitly rs1090-derived output
policy. The standard reservation does not endorse either numeric byte order
as a physical decoding.

Reproduction after building the pinned oracle and `lean1090`:

```sh
printf '%s\n' 9011223398040000000000000000 | .cache/rs1090-target/dist/lean1090-message-oracle
printf '%s\n' 9011223398040000000000000000 | .lake/build/bin/lean1090 --diagnostic
```

Both commands were run on 2026-10-16. They consume 14 bytes with no remainder,
report CRC12216280, and agree on the complete oracle projection, including
`reserved_data: 128`; the Lean standard projection keeps 2097152. Its
different vertical-source label is the already documented D003.
The permanent fresh-oracle differential test must cover each of subtypes
0/5/6/7 with zero, all-ones, all 22 single-bit patterns and seeded random
values, with exact cardinality checks. D011 is not an exemption from
oracle-view comparison. The approved FC002 correction places the oracle
meaning in the proved record and its independent assignment; it does not
rewrite the raw wire field. Earlier failed and proposal-only runs remain
under `tests/evidence/message-generated-initial/` and
`tests/evidence/reserved-velocity-proposal/`.

## D012: BDS10 DTE oracle byte order — FC003 applied

The diagnostic campaign found a compatibility-model omission: BDS10 DTE
status is reported as a native-endian u16 by pinned rs1090/deku 0.20.3 on
x86_64. Message `a0000000100000000000011e478d` contains MB
`10000000000001`: standard/raw DTE is 1 and rs1090 reports 256. Before FC003,
Lean's compatibility view incorrectly reported 1. The approved one-file
Spec correction and matching Impl/JSON changes now derive the oracle
value from the semantic value, `first8 + 256 * last8`; the standard view
keeps the MSB-first status-bit representation. Both byte-order policies
are explicit, and the oracle policy remains host-endian-dependent.

Source actually read and rechecked 2026-10-16: ICAO Doc 9871, second
edition 2012 including amendment 1 entered 9 January 2017, TableA-2-16,
printed p.A-37/physical PDFpage 65 (zero-based 64), DTE bits 41–56 and note 3's
MSB-first correspondence to subaddresses 0–15. The
[document mirror](https://manuals.plus/m/07560cb9fbd061450f9d216b298160181a57c0b1a7795edc699cfaeb1e80fb7b.pdf)
was read through browser-extracted PDF text. The
[review](docs/DTE-BYTE-ORDER-REVIEW.md) records the prior acquisition and
oracle probes. Native integer rendering is an rs1090-derived policy,
not an alternative standard encoding.

The failed pre-FC003 campaign retained 17,235 complete-message DTE-only
mismatches and 5,740 direct BDS10 mismatches. Its input/output evidence is
preserved; these cases were failures, never an exemption. FC003's approval,
exact patch hashes and before/after lock snapshots are recorded in
[the frozen change log](docs/FROZEN-CHANGES.md).

The requested source scan was independently reproduced with
`python3 scripts/scan_deku_endian.py`. It inspected all 30 Rust files under
pinned `decode/`, found 25 derived reads with widths greater than 8, and
checked all 26 wide primitive-reader calls plus four raw-bit reads.
Nineteen of the 25 derived reads specify endian explicitly. The six
missing-attribute sites, with contexts and consumers inspected, are:

| Site under `crates/rs1090/src/decode/` | Width | Disposition |
| --- | ---: | --- |
| `bds/bds09.rs:238`, `ReservedVelocityData.reserved_data` |22| Observable Mode S output; FC002. |
| `bds/bds10.rs:279`, `DataLinkCapability.dte` |16| Observable Mode S output; FC003. |
| `bds/bds30.rs:206`, `ThreatType::NoIdentity.unused` |26| Serde-skipped, not read by a validation predicate or consumer. |
| `bds/bds30.rs:219`, `ThreatType::NotAssigned.unused` |26| Serde-skipped, not read by a validation predicate or consumer. |
| `mod.rs:590`, `IcaoParity.0` |24| Map closure discards `_v` and returns the supplied CRC. |
| `cat48.rs:1130`, `CalculatedDopplerSpeed.speed_ms` |10| Observable in the separate ASTERIX CAT48 decoder, outside `Message::from_bytes` and this project's scope. |

The five Mode S sites have no inherited endian override: the BDS09 enum
passes only subtype, BDS10 is read standalone, BDS30 supplies only a
two-bit variant ID, and IcaoParity's context is only CRC. All 21 wide
Mode S primitive calls explicitly request Big endian, and the five FLARM
calls explicitly request Little endian; raw reads use Msb0.
The source-wide BDS30 use search finds only the two `unused` declarations;
those values do not affect canonical JSON or acceptance. They can still
appear in derived Rust Debug/PartialEq behavior, which is outside this
reporting claim. deku 0.20.3 `src/impls/primitive.rs:679–691` and
`src/ctx.rs:34–44,60–65` confirm the width-only reader's target-endian default.

Thus FC002/FC003 close this missing-endian-attribute class for observable
Mode S decoder reports at the pinned commit. This conclusion is limited
to the inventoried sites and reviewed uses, not a general theorem about
Rust or future rs1090 revisions. The CAT48 site is recorded explicitly;
there are six such sites across the whole directory, five in Mode S, and
two observable Mode S output fields. Full site inventories, snippets,
source hashes and executed output are retained in
[the scan evidence](tests/evidence/deku-endian-scan/README.md).

Post-application validation: `python3 scripts/check_dte_differential.py`
passes every one of the 65,536 DTE codes through fresh whole-message and
direct-register rs1090 readers, with cardinality assertions and zero
mismatches. Actual Spec/Impl/independent assignment and standard raw
preservation are checked; no counterfactual substitution is used. The
complete diagnostic rerun also passes all 576,164 messages and 101,244 direct
register comparisons with only the documented D001/D009 exceptions in
their respective strata. The prior DTE failures remain under
`tests/evidence/message-differential-before-FC003/`; current exhaustive and
campaign evidence are under `dte-exhaustive/` and `message-differential/`.
The DTE stratum is mandatory in both quick and full differential invocations.

## Inference observations

- Comm-B BDS65 is invoked without skipping the 5-bit typecode. Confirmed probes `a0000000f8000000000000000000`, `a0000000f9000000000000000000` and the same payloads with leading `a8` all return `bds65: None`; other 21/50/60 candidates remain. The direct subtype reader sees 7 and consumes 3+40 bits, leaving 13, so exact-slice `try_from` rejects. Captured output: `bench/evidence/bds65-oracle.txt`. This is included in the explicitly rs1090-derived inference policy; do not invent a standard-backed accepted BDS65 candidate in its place.

The earlier standard clauses were read from the locally acquired texts identified by edition, acquisition URL and SHA256 in `docs/SOURCES.md`: Annex 10 IV §3.1.2.7.3 and Sun §§5.5.2,7.1–7.3. D011 separately records its Doc 9871 edition, table numbers and browser acquisition. Rounding projections (BDS40/62 selected altitude) and intentionally heuristic Comm-B candidate rules are documented in `SCOPE.md`; their use as an oracle reporting policy does not make them standards assertions.
