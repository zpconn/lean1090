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
