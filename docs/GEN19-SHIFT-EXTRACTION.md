# Generation 19: exact shifts for bit extraction

Generation 19 measured **1.79542× rs1090 decode** and **1.43283× with CPR**.
Lean throughput increased by 6.98% and 5.87% versus generation 18. Both 2.00×
targets remain unmet. [Measurement, environment and raw samples](../bench/GEN19.md).

The [generation 18 decode diagnostic](GEN18-COST-BREAKDOWN.md) found Comm-B
inference, frame/CRC and semantic values to be the largest stages. Its
[separate power-edge recount](../tests/evidence/diagnostics/gen18/post-review-power-edges/)
matched 81 caller contexts across the three disjoint corpus families:

| Caller | Direct power calls | Incoming inclusive instructions |
| --- | ---: | ---: |
| Altitude bit selection | 683,670 | 690,743,441 |
| Signed payload interpretation | 374,417 | 382,294,677 |
| Mode A identity bit selection | 255,084 | 251,066,427 |
| Gray-code fold | 154,708 | 141,895,228 |

These are diagnostic observations, not elapsed times or predicted savings.
The [CPR diagnostic](GEN18-CPR-COST-BREAKDOWN.md) attributes 82.21% of its
collected instructions to the decoder, so decoder work matters in both modes.

The change replaces division by a power of two with a natural right shift,
single-bit remainder extraction with a mask, and powers of two in signed
interpretation with natural left shifts. The four live definitions are
`Impl.Altitude.bit`, `Impl.Altitude.grayDecode`, `Impl.identityCode` and
`Impl.payloadInteger`. Natural operations preserve arbitrary widths and
indices; no machine shift-count wrapping or field-validity assumption is added.

Unconditional proofs establish equality with the frozen reference on every
input, with concrete witnesses at zero, sign boundaries and beyond machine
widths. The integrated decoder proof passed its targeted build. Two old
definitional shortcuts needed explicit equality lemmas; all statements stayed
unchanged and failed attempts are retained.
Existing frozen adapters continue to call these live functions. There are no
new tables, caches, trusted primitives or frozen-file changes.

The combined native/proof build passed all 3,536 jobs with all 192 correctness
inputs unchanged. Independent native review found exactly the expected three
changed runtime modules among 22 linked native sets. Their bit, Gray, identity
and signed-payload bodies have no direct power or division calls, retain the
generic natural-number branches, and remain on the production decoder path.
This is static implementation evidence, not a throughput or allocation claim.

The fresh 10M campaign passed with complete DF/ADS-B/Comm-B coverage and no
unclassified differences. Independent retained-output replay passed; verified
duplicate cleanup reclaimed 5,358,669,824 allocated bytes. The fixed full gate
also passed all 23 capstones, the unit suite and all seven differential
components, retaining all 192 correctness inputs unchanged. Its verified
cleanup reclaimed a further 5,733,339,136 allocated bytes. Final independent
gate/archive/plan review passed without findings. The clean-commit two-mode
benchmark and independent result review then passed, retaining every sample.
Result review checked all 683 conditions on its first execution.
