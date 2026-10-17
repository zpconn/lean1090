# Kernel-checked published examples

The count below distinguishes distinct worked inputs from repeated appearances,
raw-only transcript lines, and multiple assertions about the same input.

| Source and count | What the kernel checks |
| --- | --- |
| Sun, second edition (2021): **24 distinct worked full-frame inputs** | 23 successful decodes and one corrupt-frame rejection. Published field values are independently fixed literals; repeated uses of a frame share an input fixture. |
| Sun Quick Start: **6 additional raw-only full-frame inputs** | Fixed wire-field decomposition and complete-result regression fixtures. The source supplies no decoded semantic claim for these six inputs, so they are not counted as worked decoding examples. |
| Sun: **4 non-frame worked-example groups** | Toy CPR reconstruction; toy CRC polynomial arithmetic (including the documented printed error); data-parity XOR; two signed-number conversions. |
| Consulted ICAO sources: **4 numerical arithmetic assertions** | `floor(3.8) = 3`, `floor(-3.8) = -4`, `MOD(-40, 6) = 2`, and `MOD(320, 6) = 2`, from Annex 10 Volume III Part I, amendment 77, §2.6.2(c,e), printed p.5-89. They are combined in one theorem. |
| Consulted ICAO sources: **0 complete worked decoding frames** | The sources actually read supply no complete in-scope frame with a worked decoding result. Range-monitoring policy and partial PPM signal examples are documented exclusions, not invented decoder fixtures. |

The two example modules contain **95 named kernel proofs** and **87 anonymous
`example` declarations**. Those are proof counts, not counts of distinct published
examples: `StandardExamples` contains 65 named source-anchor proofs and 57 examples;
`StandardFullExamples` adds 30 complete-result regression proofs and 30 examples.
There are 30 distinct complete input frames in total: the 24 worked inputs and six
raw-only inputs above. The additional full-result fields not supplied by Sun are
explicitly regression data, not attributed to the book.

The complete frame/source table, independently asserted quantities, editorial
contradictions, and scope qualifications are in
[STANDARD-EXAMPLES.md](STANDARD-EXAMPLES.md). Source editions, acquisition URLs,
and hashes are in [SOURCES.md](SOURCES.md).

Verification performed for this audit:

```sh
lake build Spec.StandardExamples Spec.StandardFullExamples
```

The command passed (1430 jobs). A source-level count of `^theorem`, `^example`, and
literal `...Bytes` definitions produced the numbers above. The cached Sun text's
complete hexadecimal tokens were compared with the fixtures: the only complete
frame absent from the 29 successful fixture definitions is the separately checked
corrupt frame. Other unmatched 14-character tokens are payload fragments, binary
strings, or decimal fractions. Figure-only inputs are listed with their visual
source provenance in the full inventory. The ICAO excerpt's actual arithmetic
examples were checked against its cached text and the four-conjunct theorem
`Lean1090.Spec.StandardExamples.icao_cpr_arithmetic_examples`.

The layout-by-layout audit is [LAYOUT-ANCHORS.md](LAYOUT-ANCHORS.md): five of70
canonical ADS-B TC/subtype/version branches and seven of14 Comm-B registers have
independent published semantic anchors. Every unanchored branch is explicitly
labelled rs1090-derived for compatibility/validation, alongside its actual
standard-table or fallback provenance. The ICAO count **against Spec.decode is
zero**; the four arithmetic assertions above do not increase it.
