# Upstream rs1090 unit-vector port

The source is rs1090 commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`.
Run `scripts/run_unit_tests.sh`. No Lake target or frozen file was changed to
add this suite. The existing `check_all.sh` already requires this executable
script. All assertions run in Lean against the live implementation; the
upstream M-bit test's local arithmetic closure is separately retained as a
formula test, with additional actual-decoder checks.

The inventory scans all tests in the three requested source trees:
`crates/rs1090/src/decode/`, `python/tests/`, and
`crates/rs1090-wasm/tests/`. It finds **153 active test functions and 603
assertion/expect sites**. Counts of source sites are distinct from expanded
checks: loops, struct assertions and implicit parser/variant preconditions
produce several Lean checks per source site.

- 139 nonempty functions are ported to source-indexed Lean fixtures, covering
  453 source sites. The source's empty `test_vertical_rate_level_flight`
  remains explicitly marked empty, rather than counted as tested behavior.
- The Python full-corpus test contributes one function/site. Its port runs
  `Impl.decode` and `Impl.decodePositions` with the source timestamps and
  reference `(43.3, 1.35)`, including pinned airport data. The assertion is
  the original equality between accepted message count and corpus row count.
  Observed position counts are reported, but are not invented unit expectations.
- Twelve functions, covering 149 sites, are outside the agreed scope: five
  CAT48 tests, three FLARM tests, aircraft/airport database APIs, and BDS21's
  optional country/database registration sanitizer. These exclusions are
  enumerated by function in `tests/evidence/upstream-unit-tests/coverage.json`.
  CAT48's records retain raw MB bytes; these tests do not contain decoded
  in-scope register assertions hidden inside the excluded format.

The completed fixture suite has **1,011 Lean checks**, plus the full-corpus
assertion. Every active Rust `hex!` vector is checked against the generated
observation list, including the 30-character invalid-altitude input. Every
assertion site has a port or explicit disposition. All source parser unwraps
represented by frame observations get explicit successful decode, DF and
ADS-B-variant checks. Direct CPR source vectors also go through these message
checks before their independent live local/global numerical calls.

The source's three ordered CPR regression tracks retain every timestamp and
arrival order, all three state-position `expect` preconditions, and the source
region/count/motion assertions. The separate stream differential suite supplies
stronger per-message oracle comparisons; these unit tests do not replace it.

Python assertions are translated through Python's AST. WASM assertions retain
Jest's strict `toBeCloseTo` rule, including the unusual fractional decimal
precision `0.1`. Rust relative comparisons use both operands' magnitudes and
machine epsilon, as `approx` does. Rust BDS62's `1012.8` expectation is a binary32
literal; it is explicitly rounded to binary32 before exact comparison. There
is no new tolerance for that equality. Small integer expectations compare
exactly; the remaining numeric equality operands are the upstream binary64
values, not arbitrary unbounded integers.

Rust Display-only wording, padding, and wrapper exception strings are not
implemented output APIs. Their substantive decoded snapshot fields are
retained as expectations, including Air/Ground capability, mode flags and the
source's display rounding precision. The excluded presentation portion is
recorded per source assertion. Decoding rejection and CRC syndrome are checked
for the invalid-CRC exception example.

Two source-test limitations are preserved explicitly:

1. The M-bit precision test checks a local arithmetic closure, not the decoder.
   It constructs seven meter values, retaining M-bit and round-trip assertions
   plus all literal foot conversions. Four constructed codes also set Q and
   are rejected by the actual pinned decoder. The Lean suite checks those
   actual rejection outcomes separately; the closure is not mistaken for
   standard semantics or for the runtime's accepted input domain.
2. The `cruise_bds50_small_penalty` fixture fails its upstream `if let Ok` guard.
   Its original assertion is therefore vacuous. The suite records the rejected
   direct register and additionally checks the live penalty arithmetic
   unconditionally. The initial diagnostic adapter failures are retained in
   `manual.jsonl`/`rust-automatic.jsonl` under the evidence directory, rather
   than erased or reported as frozen-model defects.

The runner rebuilds the pinned Rust message/direct-register oracles and
cross-checks the unique frame/direct-register observations. It checks upstream
cleanliness across all three test trees and Cargo inputs. All valid-fixture
assertion failures are accumulated. Independent oracle, rejection-self-test,
and corpus components run even if an assertion component fails.

Seven intentionally wrong assertions and four malformed fixture shapes must
be rejected. Unknown operations, invalid indices, missing mandatory keys,
non-object parents, absent booleans and expression-depth exhaustion cannot
turn into successful null assertions. Optional missing leaf keys are permitted
only when the source assertion explicitly permits an absent optional value.

Reproducible evidence is retained in `tests/evidence/upstream-unit-tests/`:
`summary.json`, `coverage.json`, every assertion and observation, commands,
fresh oracle inputs/outputs, source hashes, rejection self-tests and the corpus
component's provenance. This port found no new frozen-model omission.

The revised proposed freeze includes the two Lean adapters,
`scripts/run_unit_tests.sh`, and **every file recursively** under
`review/upstream-units/`, currently seven Python programs. Membership has no
extension, depth, hidden-file or bytecode exclusion: a new nested package such
as `json/__init__.py`, a native module, data file or bytecode file requires an
approved lock update. Directory symlinks are also inventory members, so a
symlink to a package cannot escape the recursive scan. The unchanged lock
checker rejects a newly added member before the full gate invokes this suite.
All expectation literals and mapping rules remain in the seven programs.

Regenerated JSON/JSONL now lives only in
`tests/evidence/upstream-unit-tests/generated/`. These files are **generated
snapshots**, reconstructed on each run before the Lean assertion runner reads
them; they are neither source-tree members nor independent mutable expectation
inputs. The old untracked source-tree JSON/JSONL and Python caches were removed
after preservation under `tests/evidence/unit-membership-v2/before-generated/`.
The shell entrypoint and its subprocess environment disable bytecode writes;
direct generator entrypoints also disable bytecode before local imports. No
generated cache needs an exception in the frozen source-tree membership.

Disposable-copy validation accepts the intact 102-file proposed inventory and
rejects eight added files (including nested `json/__init__.py`, JSON, a
suffixless file, native-module and bytecode paths), a package-directory symlink,
and deletion of each of the seven unit source files. Results and preserved
pre-revision artifacts are in `tests/evidence/unit-membership-v2/`. The live
FC004 lock remains unchanged. The user must approve the revised FC005 freeze;
this document does not apply it.
