# Comm-B boundary generation

`scripts/FuzzCommB.lean` generates named field assignments and calls the
independent `Spec.encodeBDS`. It does not discard rejected assignments, replace
them with accepted messages, or search the corpus for favourable examples.
Each row retains the assigned field codes, register, generator state, family
tag, encoded56-bit word, hard-validity result, ordered binary64 density terms,
penalty, exact final score numerator/denominator, and inference eligibility.
DF20 is reported with matching and absent outer altitude; DF21 is separate.

Run from the repository root:

```sh
lake env lean --run scripts/FuzzCommB.lean .cache/commb-generated.csv 100000 1085632
python3 scripts/check_commb_fuzz.py .cache/commb-generated.csv
```

The second argument is the number of random assignments; the third is the
seed, default1085632. The generator adds deterministic boundary assignments
and score scans. Its UInt64 LCG uses multiplier6364136223846793005 and
increment1442695040888963407, wrapping modulo2^64. Before each bounded draw,
the state is scrambled by xor-shifts30/27/31 and multipliers
0xbf58476d1ce4e5b9 and0x94d049bb133111eb, so bitmap draws do not inherit
the LCG's alternating low bit. Every fifth random case
uses full field widths. The others stay inside the register's hard envelope,
except BDS05's AC12 draw deliberately includes the ceiling-rejected codes.
Bitmap fixed bits, reserved fields, required status bits and BDS21's character
rules are preserved in these inside-envelope draws. Full-width draws and
explicit neighboring cases exercise violations.

These commands generate and check **reference fixtures**. They do not establish
agreement with the Rust oracle across all registers. The full differential
gate must feed every fixture, including rejects, to both implementations and
compare candidate sets, decoded fields and the applicable score decisions.
The independent BDS50 pilot already has a Rust/Lean comparison driver and
its own structured generator; see [BDS50-PILOT.md](BDS50-PILOT.md).

## Required boundary families

Every supported schema also gets each named field at0,1,and its maximum code,
except the BDS05/65 layout selectors. A status-gated field gets an absent-zero
case with its complete status group cleared, and an absent-nonzero case.
These include all bitmap mandatory/forbidden flags, reserved-zero regions,
hazard flags, and status/value consistency checks. For BDS65, an unsupported
subtype has no `encodeBDS` layout and is not misrepresented as an encoded
field assignment; malformed raw-message generation covers that separate case.

The33 mandatory named bound families are checked independently by
`scripts/check_commb_fuzz.py`. All numeric limits below are the explicitly
rs1090-derived receiver rules in `Spec/CommB.lean`; this generator does not
treat them as limits of the ICAO field encodings.

| Register | Boundary assignments |
| --- | --- |
| 05 | Q-altitude49975,50000,50025,50175ft; Gillham49900,50000,50100ft; TC8/9/18/19/20/21/22/23, distinguishing direct decoding from DF20 inference. |
| 10 | Header0x0f/0x10/0x11; reserved bits0/1/31. |
| 17 | Required BDS20 support0/1,27-bit required-zero suffix0/1/max; every other bitmap flag and allowed five-bit spare field gets extrema. |
| 18,19 | Every support bit at0/1, against a complete base assignment; structured random draws preserve required/forbidden support bits. |
| 20 | Header0x1f/0x20/0x21; all eight character codes at0/1/63 and random values. |
| 21 | One,two,three unknown registration symbols; absent/present registration; airline status; placeholder codes0/32/45 versus1/63 in each airline character. |
| 30 | Header0x2f/0x30/0x31; all RA/TTI/TID field extrema. |
| 40 | Both selected-altitude raw codes3124–3132, plus0/1/4095. Codes3125–3130 all report50000ft;3131 first reports50100ft. QNH codes0/1/3999/4000/4001/4095 exercise800–1200hPa.800hPa is the unsigned field minimum: no below-minimum field code exists. |
| 44 | FOM0/1/2/3/15; wind249/250/251kt and endpoints; temperature−80/60°C adjacent quarter-degree codes, plus the signed wrap at raw1024 and the wrapped60°C boundary1264/1265. Generic cases cover pressure status and the required-absent turbulence/humidity region. |
| 45 | Temperature−80/60°C and adjacent quarter-degree codes; absent temperature permits sign-only raw512 but rejects nonzero magnitude. Generic cases cover all five hazard flags, pressure/height status and spares. |
| 50 | Roll signed codes±255/±256/±257 around±45°; groundspeed698/700/702kt; TAS78/80/82 and598/600/602kt; rate magnitude511 sentinel and signed endpoints; both signs around roll5° and rate0.3°/s penalty activation; an exact−3 score with both neighboring rate codes. |
| 60 | IAS499/500/501kt; Mach codes249/250/251 around1; inertial rates±5984/±6016ft/min around6000 (6000 is not representable in32ft/min steps); both sign/magnitude0/511 sentinels; barometric sentinels; IAS/Mach ratios248/250/252 and798/800/802 with Mach0.5. |
| 65 | TC30/31, capability/operational reserved regions and all field extrema for the supported airborne layout. Per-message inference always rejects BDS65 under the documented pinned-oracle offset/length behavior. |

The full-width draws do not replace the boundary families. No absence of
random acceptances can excuse an untested hard-valid score path.

## Targeting the−3 decision

For BDS40/44/45/50/60, finite field-code scans retain every observed adjacent
hard-valid crossing of the exact binary64 score predicate, plus the nearest
scanned value below−3 and the nearest scanned value at or above−3. The scans
vary QNH, wind/temperature, temperature, track rate, and IAS respectively.
Two additional seeded cross-field contexts per register vary other score
operands and penalties. Each scan must find both sides or generation fails.
“Nearest” means nearest within that stated finite one-field scan, not across
the entire56-bit payload space.

BDS50 has an exact threshold assignment: roll code128 (22.5°), rate code84
(2.625°/s), both present; track, groundspeed and TAS absent with zero codes.
`encodeBDS` produces40532396648603648 and the exact score is−3. The rate83
and85 neighbors produce40532396648601600 and40532396648605696: the first
passes and the second fails. This exercises the inclusive comparison.
`Proofs.BDS50.exact_threshold_nonvacuous` proves the exact case in the kernel;
the pilot compares all three against Rust. No claim is made that other
registers can attain exactly−3, or that failure to find one proves otherwise.

Scores are retained even on hard-invalid fixtures to aid diagnosis; the
actual oracle may reject before evaluating them. Differential acceptance
checks must respect that control flow rather than invent an observable score
for a rejected message.

## Recorded run

The command above was run with100000 random assignments. It emitted101244
rows, with all14 registers, all33 mandatory bound families, hard-valid score
brackets for all five scored registers, and one exact−3 payload. The coverage
checker passed. Full counts and the generated CSV's SHA256 are retained in
`bench/evidence/commb-fuzz-summary.json`; per-family acceptance counts are in
`bench/evidence/commb-fuzz-coverage.csv`. The30MB fixture itself is reproducible
and remains in ignored `.cache/`.

`scripts/CheckReceiverPolicy.lean` separately kernel-checks all4096 AC12 codes:
the independent `altitudeCodeAdmissible` predicate agrees with the prior
`Altitude.oracleAC12` acceptance behavior. That check preserves the receiver
policy while the environment audit verifies that validity predicates do not
depend on decoder implementations.
