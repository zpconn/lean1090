# Generation 23: exact Comm-B plausibility tables

Generation 22's completed instruction diagnostic identifies Comm-B inference
as the largest decode stage: 3,003,800,578 of 7,260,483,187 instructions.
The BDS50, BDS60 and BDS40 validity helpers account for 284,172,699,
260,847,884 and 245,938,829 inclusive instructions. These nested costs are
diagnostic observations, not predicted throughput gains.

The [retained helper breakdown](../tests/evidence/diagnostics/gen22/priority-helper-contexts.json)
shows repeated rational construction and comparison in those checks. BDS50
calls rational multiplication and division for roll; BDS60 computes signed
vertical rate and compares rounded Mach; BDS40 compares selected altitudes
and rounded pressure. The
[complete decode report](GEN22-COST-BREAKDOWN.md) and
[CPR report](GEN22-CPR-COST-BREAKDOWN.md) passed independent review before
this change was selected.

The change stores five original Boolean expressions in immutable tables:

| Check | Field codes | Construction |
|---|---:|---|
| BDS40 selected altitude | 4,096 | Original selected-altitude rounding and bound |
| BDS40 QNH | 4,096 | Both bounds on the existing software-binary64 value table |
| BDS50 roll | 1,024 | Original signed scaling, absolute value and bound |
| BDS60 Mach | 1,024 | Original bound on the existing software-binary64 value table |
| BDS60 inertial vertical rate | 1,024 | Original fixed-position decoding, sentinels and bound |

Lookups use the complete field code and a proved index bound. Tables cover
the entire field domain, including implausible values. They contain no
message or corpus keys and no cross-message cache. QNH and Mach reuse their
existing rounded values, retaining the literal and operation order. The
score gate and all remaining status, spare-bit and plausibility predicates
are unchanged. Existing semantic-value helpers remain live.

The runtime build passed on its first attempt. All three unconditional lookup
and complete-register refinement modules passed, and full-decoder refinement
passed on its first integration attempt. Each helper module retains its initial
simplification failure and successful second attempt. The production-build
inventory guard initially required staging the three new modules; no build had
started, and staging resolved it without changing source. No generation 23
throughput result is claimed. The combined production/proof build passed with
200 unchanged correctness inputs. Independent source/proof review verified
38 new facts and 16 kernel witnesses, with every existing Decoder statement
unchanged. The separate fresh campaign passed, including independent retained-byte and
comparison replays: 10,476,164 messages, 9,542,964 exact matches plus 933,200
documented D001 cases, 2,038,902 separately recorded standard-view differences,
and all 101,244 direct Comm-B cases exact. Coverage includes all 32 DFs,
70 ADS-B branches and 14 registers. Fresh seeds were messages 1,958,132,729
and Comm-B 972,156,822. Verified cleanup reclaimed 5,359,271,936 allocated
bytes of duplicate scratch. The full fixed gate passed all seven differential
components, all 23 capstones, 152 audited witnesses and 1,011 unit assertions,
with all 200 correctness inputs unchanged. The fixed whole-message campaign
has 9,542,689 exact matches and 933,475 documented D001 cases, with no
unclassified differences. Fixed-gate archival and verified cleanup reclaimed
another 5,733,335,040 bytes. Independent archive/plan review passed; three
checker-only adaptation failures remain retained, without any producer change.
The frozen two-mode benchmark subsequently passed from clean source commit
`9b6868f21fcac0a59044153f01e6691d091dbb5c`: **2.410234595243× decode** and
**1.835727795894× CPR**. Lean throughput increased 11.64% and 9.83% versus
generation 22. Signed CPR overhead is 0.596047914540 µs/message for Lean
and 0.008262097523 for rs1090, including measurement noise between modes.
All 96 samples, fresh-build provenance and four Windows power-plan captures
are retained in the [benchmark report](../bench/GEN23.md).

Native review passed: 161 checks bind 272 inputs and all 22
native sets. CommB is the sole changed set. The tables initialize persistently
before the benchmark loop; the actual BDS40/50/60 predicates contain three,
one and two indexed Boolean load sites respectively, with no direct rational
arithmetic calls. The original semantic-value helpers remain present and live.
A reviewer-only symbol-spelling correction is retained; no native file changed.
[Native review](../tests/evidence/optimization/gen23/native-review/review.json).

Evidence: [generation 23](../tests/evidence/optimization/gen23/).
