# Trusted computing base

Checkpoint 1 reference contract. The BDS50 pilot refinement is proved; the
whole-decoder correctness proofs remain outstanding. The measured software
binary64 baseline is recorded in `docs/BDS50-PILOT.md`.

The intended trust boundary is the Lean kernel, Lean compiler and runtime, the C compiler, and the machine executing them. Mathlib proofs are checked by Lean; its mathematical definitions are confined to specification and proofs. The eventual Float presentation step is tested against the pinned oracle, rather than proved to equal exact real arithmetic. Comm-B Float-dependent inference decisions use the proof-visible Binary64 model and a finite-domain capstone. CPR tracking exposes same-order numerical coordinate/geodesy callbacks; libm and Float operations at that documented boundary are tested, not mathematically verified. The pure CPR accuracy capstones use exact rationals and do not assert accuracy of arbitrary Float callbacks. The host math library belongs to the numerical test boundary.

There are **zero** project `@[extern]` or `@[implemented_by]` primitives authorized at this checkpoint. GOAL.md permits at most five, each requiring a pure reference definition and runtime differential checks. No new primitive is authorized by this document.

The user's optimization instruction preserves the software binary64 model as
the proved reference. First optimize the proved implementation with exact
per-field tables and verified integer score decisions; any fast decision must
have a proved error bound and use the full model for ambiguous threshold cases.
Only if that approach cannot close the measured gap may hardware binary64
add/sub/mul/div be proposed as trusted primitives. **Ask before adding any.**
An approved proposal must compile with `-ffp-contract=off`, preserve operation
order, retain pure Lean reference bodies and cross-check runtime results against
the software model. This is a possible future proposal, not authorization.

`Capstones.lean` contains proposition statements to freeze after checkpoint approval. Later proof modules will prove those propositions without editing the statement file. The post-approval gate must inspect the actual proof constants, not merely the proposition definitions, with `#print axioms`. The only permitted axioms are `propext`, `Classical.choice`, and `Quot.sound`.


The amended checkpoint adds `scripts/Final.lean`: exact final theorem types bound to the actual implementation entrypoints, with axiom checks on the proofs. `Model/` contains shared data types only and is frozen with the specifications. The compiled import audit rejects transitive Spec/Mathlib dependencies in Impl/ and transitive Impl/Proofs dependencies in the frozen reference graph. Final and pilot manifests are import-free fragments compiled verbatim under temporary integration imports. The dependency audit inspects Lean environment bodies and types of all seven hypothesis predicates and assigned for circular decoder dependencies. The lock inventory, lock checker, audit scripts and gate entrypoints are themselves frozen, with the lock checked first. Kernel-checked source examples provide independent concrete anchors. The BDS50 pilot uses exact finite binary64 rounding in pure Lean rather than Float acceptance decisions; it adds no trusted primitive.
