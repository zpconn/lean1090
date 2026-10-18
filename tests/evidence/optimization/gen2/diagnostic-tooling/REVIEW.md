# Dynamic diagnostic object discovery

`review/diagnostics/build_decode_costs.py` now discovers the reused project objects from the actual `lean1090-bench.rsp` instead of requiring 20. It retains exactly one replacement of the `Bench/WholeDecoder` object. The permitted project modules are `Impl`, `Model`, their submodules and that worker. Every linked object must have an existing generated C file and Lean source; symlinks, duplicate canonical paths, foreign objects, explicit archives, unknown project modules and nested response files are rejected. Nested response detection includes comma-separated linker arguments and arguments following `-L` or `--sysroot`.

Each associated Lean source, including `Model` and the worker, must be committed at the pinned HEAD and byte-identical to that blob. The build manifest records the object-to-source mapping and every linked source, C and object hash. Existing source/object/lock checks remain; additional checks cover the worker inputs, response, native traces, diagnostic source and pinned HEAD across the diagnostic build.

Native commands still come from the worker traces. Substitution requires exactly one occurrence of each original artifact path: two compile paths, two link paths and one response entry. Every other token remains in the same order, including `-O3` and `-ffp-contract=off`. No Lake target or native flag changed.

**Freshness is a caller prerequisite.** The caller must supply a fresh worker build from committed sources and retain its source/object build provenance, as the generation benchmark workflow does. This builder's source/HEAD checks and before/after hashes establish identity and immutability; they do not independently prove that existing native objects were compiled from those sources. The docstring and emitted manifest now state this limit explicitly.

Validation executed:

```sh
python3 -B tests/evidence/optimization/gen2/diagnostic-tooling/structural_checks.py
```

All 47 checks pass. Temporary non-executable text fixtures cover valid inventories of 2, 20 and 21 production objects, including a new `Impl/ScoreGate` and Model provenance; rejection cases cover missing/dirty/uncommitted inputs, symlinks, duplicate paths, unknown/foreign modules, hidden objects/archives and nested responses. Actual worker compile/link/response metadata were read only to confirm exact artifact-only substitutions and unchanged remaining flags. The committed-blob reader was checked against `Model/Types.lean` and a nonexistent source. Both Python files parse without creating bytecode. `structural-results.json` records hashes, checks, command tokens and scope.

No diagnostic build ran against evolving gen2 objects. No Lean/compiler/linker invocation, runtime test, profile, benchmark, source/proof/frozen-file change, staging or commit was performed by this maintenance task. A future diagnostic run must execute the fresh-build prerequisite and full before/after guards; the structural fixtures do not claim that run has happened.
