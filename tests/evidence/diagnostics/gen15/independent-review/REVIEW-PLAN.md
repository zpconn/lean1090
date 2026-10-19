# Generation 15 diagnostic review plan

This is review preparation, not a passed diagnostic or a performance result.
The current source commit is `7163b2506f3b4045caa98721aa90b7042733b0fe`;
the unchanged timed source is `e659220307538f2aee5398efdb0a9182bff1d778`.
The user now requires 2.00 times rs1090 throughput in both benchmark modes.
No implementation change is selected by this plan.

All Python invocations use `PYTHONDONTWRITEBYTECODE=1 python3 -B`, with
bytecode disabled before local imports. Static native inspection and broad
hashing wait until both isolated actual-worker perf captures have finished.
Review does not build or execute a decoder, change production sources, rerun
measurements, or rewrite historical evidence.

## Decoder evidence

- Bind the driver to all 22 native source/C/object/trace sets in generation
  15's fresh benchmark inventory, with exactly 21 production/model objects
  reused. Verify the ordinary descendant-commit binding against the timed
  Git blobs, complete audited Lean inventory, unchanged lock and worker hash.
- Inspect the actual eager `commBPayloadLimit` initializer and live
  `bdsWireValid` global load. Confirm the collected guard has no direct decimal
  parser call; do not infer that startup initialization is free.
- Preserve the previous source-review keys for shared CRC, UInt32 CRC fold,
  byte-word construction, field extraction, affine identity guards, exact
  density/Mach/QNH/wind tables, integer score gate and BDS60 ratio enclosure.
- Independently parse all 13 compressed primary Callgrind profiles. Recount
  self instructions, actual edge calls, exclusive stages and every grouped
  helper row. Inclusive helper costs are overlapping observations, never an
  additive decomposition. Retain absent/inlined-symbol limitations.
- Check full corpus and per-DF output digests, original shadow census,
  accepted-frame CRC census, interval decisions, zero-population probes and
  all source/native/command/collection associations. The profile roots exclude
  loading, startup, output consumption and post-collection census work.
- Recount new direct guard/parser contexts against generation 14, plus the
  unchanged ratio contexts. Do not convert instruction changes into elapsed
  time or throughput predictions.
- Verify actual perf attribution, unknown/excluded samples, raw capture hash,
  capture-before-work ordering and explicit sampling limitations.

## CPR evidence

The separate CPR review lives under
`tests/evidence/diagnostics/gen15-cpr/independent-review/`. It checks the whole
frozen secondary workload, not a batch-only substitute. See its checklist.

## Preservation and disk bounds

Verify exact archive membership and every compressed member's source hash,
size and complete decompression. Bind all supplements and failed attempts
explicitly; report primary, supplement and total membership separately.
Historical cache binaries explicitly omitted from archived manifests may be
absent only when the authorized cleanup receipts identify them. This does not
relax any archived source, generated-C, command, hash or raw-perf check. Bind
the current source/native set directly. Avoid large uncompressed whole-binary
symbol listings; retain targeted disassembly or compressed symbol evidence.
The generation 15 benchmark, all prior result rows and historical compressed
evidence remain byte-identical. Final review is written only after producer
artifacts are sealed and all review checks pass; failed reviewer attempts are
retained.
