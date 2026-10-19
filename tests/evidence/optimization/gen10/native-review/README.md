# Generation 10 static native review

The retained integrated CLI uses the new immutable QNH table on the live BDS40
validity and full-software density paths. All structural checks pass, with all
139 captured inputs unchanged. The captured CLI SHA-256 is
`33c316d077d1ec1b389b7f22b7b654cbd95da6cef598445ce59244db87cb6fbe`;
the successful 3,515-job integrated build log SHA-256 is
`3b4acf159a2f3d3d2e8b553f4d18924bfbab1b48eb710162c6313c5142c11547`.
This review inspects that existing CLI, not a future freshly rebuilt benchmark
worker. It executes no decoder, build, test campaign, profiler or benchmark.

Retained `Impl/CommB.c:898` defines the table entry function. It converts the
field code to a rational, obtains the software-rounded 1/10 literal, performs
`Binary64.mul`, and then `Binary64.add` with 800. The corresponding linked entry
assembly retains those operations in that order. The literal initializer at
line 880 and its linked assembly retain `Binary64.round`; the original two
rounding steps are not replaced by a single rational formula. The constructor
at line 911 calls `Array.ofFn` with exactly 4,096 entries. Its linked assembly
passes tagged 4,096 (`0x2001`) to the same constructor.

The module initializer assigns the complete table at lines 6895–6896 and marks
it persistent. The CLI initialization graph reaches `Impl.CommB` before
`lean_run_main`. This table construction therefore precedes message processing;
it is startup work, not a cache populated by message contents. The table has
one global assignment and no per-message writes. Its key is solely the 12-bit
QNH field code, including all codes outside the receiver's plausibility bounds.
Other lazy scalar constants can still initialize during later operations.

The public `cbQNH64` C body at line 929 extracts `payloadBits word 28 12` and
performs a borrowed array access. The bound is proved for every natural payload
and erased from native code. There is no software rounding, rational arithmetic,
table allocation or lazy initialization in this lookup body. Its object
definition retains the field arguments and indexed load, but the native linker
has no standalone `cbQNH64` symbol: the compiler inlines it into callers.

Actual `cbValid40` assembly loads the QNH table at `0xb7d038`, calls the live
payload extractor with tagged 28 and 12 (`0x39`, `0x19`), then loads the indexed
entry at `0xb7d05b`. Actual `cbDensityTerms` does the same at `0xb7f696` through
`0xb7f6b9`. `qnh-native-paths.json` retains both straight-line native sequences.
Neither sequence performs software binary64 arithmetic or constructs the table.
Other caller conditions and arithmetic remain live. Missing standalone QNH
calls must not be interpreted as zero QNH computation or as a measured speedup.

The candidate path still invokes `bdsWireValid`, which reaches `cbValid40`;
accepted `decodeBDS` records still recheck the same validity. The score entrypoint
retains fast density tables, the live penalty and the exact integer gate. Its
conditional callback still calls full software density, penalty, binary64
addition and the exact comparison. Full density reaches the current
`cbDensityTerms`, including the inlined QNH lookup. Frozen direct-register and
whole-message adapters retain their live public entrypoints, and the frozen
benchmark source retains all three complete `Impl.decode input.bytes` calls.
Adapter source binding is checked here; no additional adapter executable was
run or independently disassembled by this review.

The integrated proof checks all nine QNH table/equality/witness facts, including
the all-input `cbQNH64_eq` theorem and an over-wide payload witness. Complete
decoder refinement uses this equality without a validity or corpus-membership
hypothesis and retains only the three permitted axioms. The other 19 production
source/C/object/trace sets match gen9 exactly, including frame extraction,
shared CRC, affine semantic values, software binary64 and the integer gate.
Within `Impl.CommB`, all source bytes outside the QNH replacement remain
unchanged. Generated C can rename or deduplicate closed constants, so unchanged
source is not presented as byte-identical C for every function in that module.

All 104 frozen hashes match. `TRUSTED.md`, `lakefile.toml` and `spec.lock` match
the parent commit, and native flags retain `-O3` and `-ffp-contract=off`. There
is no new FFI, trusted primitive, mutable state or cross-message cache.

`inspection-inputs.json` binds the successful build, source/native hashes,
retained copies and the original 28 read-only commands. The three additional
local-constructor disassemblies and four numbered C excerpts are recorded in
`additional-inspection.json`. `validate.py` checks these claims and inventories
all evidence in `review.json`. Future diagnostics must bind the freshly timed
worker again, retain actual caller table loads and distinguish eager startup
from the collected decoder costs. Candidate/score probes and caller-stage
accounting remain the relevant measured populations when this wrapper is
inlined.
