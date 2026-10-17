# FC003 deku endian source scan

Executed on 2026-10-16 against rs1090 commit
`685dfaa34c5ab186c691bca3cfe2a22e12517d30` and deku 0.20.3:

```sh
python3 scripts/scan_deku_endian.py
rg -n 'bits\s*=|BitSize\(|read_bits|from_reader_with_ctx|endian' vendor/rs1090/crates/rs1090/src/decode
rg -n 'ThreatType::|threat_type|\.unused|unused\s*[:}]' vendor/rs1090/crates/rs1090/src
```

The scanner reads all 30 Rust files under `decode/`, verifies the pinned
revision and clean tracked source, inventories all 25 derived deku attributes
with widths greater than 8, all 26 explicit wide primitive-reader calls, and
all four raw-bit reads. It asserts the exact six-site set lacking an endian
attribute. Nineteen wide attributes specify endian explicitly. All 21 wide
Mode S primitive calls explicitly request `Endian::Big`; all five FLARM
wide primitive calls explicitly request `Endian::Little`. The four raw
reads use `Order::Msb0` and preserve a byte/bit buffer rather than relying
on native integer interpretation. JSON files retain every site, line,
source snippet, and SHA-256 of all scanned files.

## Reviewed missing-attribute sites

Paths below are relative to `vendor/rs1090/crates/rs1090/src/decode/`.

| Attribute site | Type and field | Width | Context and output/acceptance effect |
| --- | --- | ---: | --- |
| `bds/bds09.rs:238` | `ReservedVelocityData.reserved_data` | 22 | Serialized; no container endian attribute. `AirborneVelocitySubType` at lines217–233 receives only a `u8` subtype, not an endian context. Reserved subtype variants0/5/6/7 use this struct. Corrected by FC002. |
| `bds/bds10.rs:279` | `DataLinkCapability.dte` | 16 | Serialized; no struct endian attribute or context at lines116–122. DF20/21 selectors call its standalone `try_from` reader (`commb.rs:623,740`). Corrected by FC003. |
| `bds/bds30.rs:206` | `ThreatType::NoIdentity.unused` | 26 | `#[serde(skip)]` at line207; no field map/assertion. Parent enum at lines200–203 supplies only a two-bit ID. No consumer reads/destructures either `unused` field; register acceptance depends on other fields. Native integer differs internally but not canonical JSON or acceptance. |
| `bds/bds30.rs:219` | `ThreatType::NotAssigned.unused` | 26 | Same, `#[serde(skip)]` at line220. The source-wide reference scan finds only these declarations; neither value is validated. |
| `mod.rs:590` | `IcaoParity.0` | 24 | Map closure ignores `_v` and always returns the supplied CRC. Parent context at line586 is only `crc: u32`; the read's native-endian value is discarded. |
| `cat48.rs:1130` | `CalculatedDopplerSpeed.speed_ms` | 10 | Serialized and lacks endian context, but belongs to the separate ASTERIX CAT48 decoder (`RadialDopplerSpeed.calculated`, lines1087–1098), which `Message::from_bytes`/`DF` never invokes. Out of this project's Mode S scope. This extra site means there are six sites across the entire directory, not five. |

The entire `DF` enum (`mod.rs:43–283`) and its reader dispatch were inspected
for the boundary between Mode S and CAT48/FLARM. The BDS30 `unused` members
can appear in derived Rust Debug/PartialEq behavior; the conclusion here is
about the canonical serialized decoder reports and acceptance required by
lean1090, not every possible Rust observation.

`deku-0.20.3/src/impls/primitive.rs:679–691` was inspected: a width-only
integer context selects `Endian::default()`. `src/ctx.rs:34–44,60–65` selects
target endianness. Neither an outer MSB bit order nor a neighboring
field's explicit endian attribute overrides this integer default. The
compatibility oracle is pinned to little-endian x86_64.

FC002 and FC003 cover both observable Mode S sites in this specific bug
class at the pinned revision. This is a reproducible lexical inventory
with manually checked context and use sites, not a proof that arbitrary
Rust programs or later rs1090 revisions have no endian bugs. The out-of-scope
CAT48 finding does not request or authorize another Spec change.

## Standard source rechecked

The browser text of the [ICAO Doc9871 mirror](https://manuals.plus/m/07560cb9fbd061450f9d216b298160181a57c0b1a7795edc699cfaeb1e80fb7b.pdf)
was re-read on 2026-10-16: second edition2012, amendment1 entered9January2017,
TableA-2-16, printed p.A-37, physical PDF page65 (zero-based page64).
It places DTE in bits41–56, marks bit41 MSB and bit56 LSB, and maps consecutive
bits to subaddresses0–15 in note3. This supports retaining the MSB-first raw
status word separately from the host-dependent rs1090 integer rendering.
No local PDF download or PDF hash is claimed for this browser acquisition.
