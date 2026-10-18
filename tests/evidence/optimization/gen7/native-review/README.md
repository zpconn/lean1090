# Generation 7 static native review

All 37 inspection checks pass for the successful integrated CLI build. The
captured CLI SHA-256 is
`3c847677eb434aca74e579d43aedcba95cced4ac0c9bf4cb19cfa438f3da66d9`.
The integration log reports 3,512 jobs and has SHA-256
`bb400edeb8ea22769af21c322bf69d21d033b50baafb1e149b027ef4ba78befd`.
All 102 captured source, proof, C, object, trace and configuration inputs remain
unchanged. The CLI links 21 project objects; this is separate from the future
freshly built benchmark worker and its own provenance record.

The live `ScoreGate.choose` uses integer cross multiplication for the same
enclosure. Generated `Impl/ScoreGate.c:784` computes a common denominator,
scaled signed/absolute numerator sums, a positive count, and the two integer
comparisons. The common denominator at line 461 checks whether each denominator
divides the maximum; its exact product branch remains available for arbitrary
non-dyadic inputs. The pair fold processes the scaled signed and absolute sums
together. Its scalar operations are `Nat`/`Int` operations and raw rational
field reads. The retained 15-function C reference closure, including cold
literal initializers, contains no normalized rational operation, GCD operation
or software-binary64 operation.

Actual linked `choose` calls the common-denominator helper at `0xb780d7` and
the integer pair-fold helper at `0xb780fd`. Small values use tagged integer
operations; arbitrary-precision division, addition, multiplication, subtraction
and comparisons remain explicit runtime paths. This inspection does not claim
that integer arithmetic or allocation is free.

The inclusive lower comparison and strict upper comparison retain their
original order. The sole generated-C callback application is at line 867,
inside both uncertain-branch conditions. The sole linked `lean_apply_1` site
is `0xb786b2`. A conservative intraprocedural branch traversal finds return
paths with zero or one callback application, never more than one. That traversal
does not interpret arithmetic; the C nesting and the universal
`Proofs.ScoreGateInteger.choose_eq_old` theorem establish the exact predicates.

The linked `cbScorePasses` constructs the original closure, computes the live
table-derived terms and penalty, and tail-calls `choose`. The retained callback
still calls `cbDensity`, `cbPenalty`, software `Binary64.add`, and the inclusive
rational threshold comparison. `Impl/CommB.c` is byte-identical to gen6.
All 19 other reused production source/C/object/trace sets match the freshly
built gen6 artifacts. Actual linked message/report/inference/candidate paths
reach the same live `cbScorePasses`. The frozen direct-register adapter calls
live `decodeBDS` and semantic decoding; the whole-message adapter exercises
actual `Impl.decode`. No adapter has been redirected to an old implementation.

The pure `mass`, `center` and `envelope` definitions remain mathematical
reference APIs. They are also used by the after-collection diagnostic census.
No frozen Lean adapter directly refers to them, and they are not called from
the new live `choose`. Their absent linked CLI symbols do not imply zero
logical enclosure computation. Likewise, standalone `scaledNumerator` and
`scaledTotals` wrappers are inlined; the denominator and pair-fold boundaries
remain live and are retained in the assembly. The next diagnostic must use
these actual helpers while leaving the shadow census outside collection.

Compiler lazy cells contain only immutable literal constants and the zero
accumulator pair. There is no message-dependent cache, new trusted primitive,
FFI annotation or build-flag change. All 104 locked hashes match; `TRUSTED.md`,
`lakefile.toml` and `spec.lock` match the parent commit. `-O3` and
`-ffp-contract=off` remain in the compiled object trace.

Commands and hashes are in `inspection-inputs.json` and
`additional-inspection.json`; `review.json` inventories this evidence.
`choose-C-reference-closure.json` lists exact local references and external
operations, and `choose-control-flow.json` records the branch traversal. Actual
C, sources, traces and symbol disassemblies are retained. No native decoder,
build, profiler, benchmark or differential campaign was executed by this review.

Two inspector preparation errors are retained with their original scripts and
failure records. The capture initially expected relative response-file paths;
the successful version also normalizes absolute paths inside this repository.
The first validator incorrectly expected the direct BDS adapter to run candidate
inference; the corrected check follows its actual decode/semantic entrypoints
and verifies the separate linked whole-message candidate path. Neither error
changed production files, frozen files, test expectations or decoder results.
