Generation 4 changes payload extraction for widths below 64. The freshly bound generated C in `generated-c/Impl/PayloadBits.c` keeps UInt64 conversion, shifts and a mask in that branch; the original natural-power/division/remainder formula remains for arbitrary wider widths. The helper is inlined into the live `payloadBits` symbol. Its absence as a separate linked symbol is not zero extraction work. The source/native binding and assembly are retained in [source-review.json](../tests/evidence/diagnostics/gen4/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen4/source-inspection/).

The three Comm-B source changes are erased bound proofs. Its freshly built native object remains byte-identical to generation 3. No runtime stage boundary changed; instruction deltas below compare the same corpus populations and live entry points.

The following `payloadBits` observations group actual native symbols by their uniquely attributed stage. The inclusive costs overlap other helpers and do not form an additional cost partition or a predicted speedup. Complete observations are in [payload-helper-comparison.json](../tests/evidence/diagnostics/gen4/payload-helper-comparison.json).

| Caller stage | Gen3 entries | Gen4 entries | Gen3 self Ir | Gen4 self Ir | Gen3 inclusive Ir | Gen4 inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb_fields | 806,045 | 806,045 | 64,691,992 | 48,362,700 | 1,671,300,781 | 48,362,700 |
| commb_inference | 3,121,720 | 3,121,720 | 250,904,926 | 187,303,200 | 6,396,909,632 | 187,303,200 |
| semantic_oracle_values | 3,542,787 | 3,542,787 | 284,707,505 | 212,567,220 | 7,260,168,078 | 212,567,220 |

Across all three families, retained `payloadBits` contexts have **0** observed outgoing calls to `lean_nat_pow`; the exact positive-cost outgoing edges are retained in [payload-call-edges.json](../tests/evidence/diagnostics/gen4/payload-call-edges.json). These are native call observations, not guessed field-width counts. The arbitrary-width fallback remains in source and native code even when a workload does not reach it.

The CRC cached halves and original arbitrary-index fallback remain unchanged. The exact interval gate, callable boxed software fallback and 13 eagerly initialized immutable density arrays remain unchanged. Table construction occurs during module initialization before `main`, outside decoder-root collection and warmed benchmark loops. Other lazy scalar constants and separate allocator state may differ; no unmeasured correction is applied.

Native perf capture completed before the native census and Callgrind workers began. Family and probe profiles then intentionally overlapped, with at most six active profiles. Other agents performed read-only evidence review and benchmark archival. No host-wide isolation or timing decomposition is claimed. Sampling exclusions, unknown frames and the explicitly reported lost-sample counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen4/perf/README.md).

The largest-stage helper table retains raw inclusive incoming-edge observations. A recursive or re-entrant visit may overlap within one row, and descendants may cross a later stage boundary. Only self events form the exclusive partition; helper costs must not be added to it.
