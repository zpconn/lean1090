# Generation 6 native syndrome-sharing review

All **48 static checks pass**, with all **47 captured input hashes unchanged**. The existing linked CLI computes one syndrome after a frame parses successfully and shares it through acceptance and report construction. This is source/C/assembly evidence, not a performance measurement or a substitute for the refinement proof and full gate.

The successful integrated build was `lake build Proofs.Decoder lean1090 messageGenerator commbDifferential`: **3,511 jobs**, completed `2026-10-18T22:00:17.095408+00:00`, log SHA-256 `ea90f1d4e702fbae60f358b21879711dda252ee89e658f40fe3cb5d5aafaaf10`. The inspected CLI SHA-256 is `099a2f4e515e53b921d629e0f218be7dccd237cc353e27e61a88a4255ade5155`. [inspection-inputs.json](inspection-inputs.json) binds the sources, generated C, object hashes, native traces and exact commands. The future freshly built timed worker is not claimed inspected here.

## Live decode path

Generated [Message.c](retained/.lake/build/ir/Impl/Message.c:1066) calls `decodeFrame` and returns on parse failure before reaching the syndrome computation. On the parsed branch, line 1100 computes `v___x_270_` once. Lines 1101 and 1115 pass that identical value to `frameAcceptedWithSyndrome` and `reportWithSyndrome`. The decoder does not call the standalone public wrappers that compute their own syndrome.

The [linked decode assembly](binary-decode.txt) has one call site to `frameSyndrome`, at `0xb8aa9d`. Its return value is retained in `%r12`, compared against zero by the inlined DF17 acceptance logic, and passed in `%rsi` to `reportWithSyndrome` at `0xb8aaf7`. The acceptance helper has been inlined; its missing standalone linked symbol does not mean acceptance work is absent. The existing ADS-B hard-validity call and supplementary-message branch remain visible.

[decode-control-flow.json](decode-control-flow.json) records a conservative traversal of every direct branch in that compiled function. It finds no syntactic path that executes the syndrome call twice. Return paths have zero or one such call; report construction and the ADS-B hard-validity call are reachable only after the one syndrome call. This traversal treats ordinary calls as returning and is not a formal proof of callee behavior. The shared callees are inspected separately, and the universal Lean refinement remains the correctness guarantee.

## Shared helpers and public entrypoints

- [reportWithSyndrome](binary-reportWithSyndrome.txt) retains the incoming syndrome in `%rbx`, passes it to `frameAddressWithSyndrome`, and passes the same value to `Parity.interrogator` on DF11. Generated C also places that argument directly in the report's CRC field. No shared report/address/interrogator helper calls `frameSyndrome` or `Parity.checksum`.
- [frameAddressWithSyndrome](binary-frameAddressWithSyndrome.txt) uses the provided argument for AP address recovery. Announced-address formats keep their existing address selection; DF19 keeps `none`. The report and address helpers have live linked symbols.
- Public `frameAccepted`, `frameAddress` and `report` each compute one standalone syndrome and delegate to the same shared helper used by `decode`. Their object definitions and generated C are retained. These unused standalone wrappers are removed from the linked CLI; the actual decoder does not route through them. There is no legacy implementation kept only for tests.
- The [CLI emit assembly](binary-cli-emit.txt) calls actual `decode` or `decodePrefix`; the latter calls actual `decode` once. Frozen benchmark and whole-message test sources retain their references to these public entrypoints. This source binding is checked without claiming that every future test executable or the fresh timed worker has been rebuilt by this review.

The change makes the syndrome eager after parsing, including a frame later rejected by payload plausibility. Invalid lengths and unsupported formats still return from parsing first. Standalone acceptance/address wrappers also calculate their syndrome eagerly even where their selected result does not need it. Those evaluation-order changes are documented in source; they do not change returned values. Counts from the accepted corpus cannot establish performance for arbitrary rejected inputs.

## Preserved work and state

The source bodies for altitude, oracle altitude, identity, ADS-B and Comm-B frame helpers are byte-identical to generation 5. Their generated C, and `frameSyndrome` itself, are identical after a bijective renaming of local variables. The non-CRC report field expressions are byte-identical, and their generated-C call counts are unchanged. Frame, parity, Comm-B and semantic native objects are byte-identical to the generation-5 fresh-build objects.

The Message module introduces no new global storage. Its static declarations differ only by renaming the existing acceptance-zero constant for the new helper. The syndrome is a local immutable value passed as an argument; no message-keyed table, mutable cache or state across messages is added. `Impl/Message.lean` is the only changed runtime source. `TRUSTED.md`, `lakefile.toml` and `spec.lock` equal their committed versions, all 104 locked hashes match, and the existing `-O3` / `-ffp-contract=off` flags remain present. No new FFI or implementation override is added.

## Execution and next diagnostic

`capture.py` and `validate.py` inspect existing bytes using Python, `git show`, `nm` and `objdump`. No compiler, decoder, test campaign, profiler or benchmark was executed. [review.json](review.json) records every check and retained artifact hash. The earlier empty disassembly probe for an assumed CLI `runLine` symbol is retained; symbol inspection identified the actual private `emit` entrypoint, whose disassembly supplies the checked CLI call path.

The next diagnostic must bind the freshly timed worker and update its live CRC-count expectation to **one per successfully parsed frame**. The earlier shadow census's repeated-call prediction must remain explicitly historical; it cannot be asserted against the new decoder. Preserve all non-CRC control-flow populations and complete output checks. The renamed report/address helpers and inlined acceptance logic also require an explicit review of native anchors and stage attribution. Missing symbols must never be interpreted as absent logical work. This review makes no claim about future instruction totals or throughput.
