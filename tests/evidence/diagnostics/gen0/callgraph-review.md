# Unmodified decoder call graph and diagnostic interpretation

Inspected 2026-10-18 before gen1. This is generated-code inspection and a diagnostic design, not a throughput result or an optimization. Production files and frozen files are unchanged. The associated driver links the existing native production objects; see `driver-build.json` for exact hashes and build commands.

## Live path and scope

`Impl.decode` (`Impl/Message.lean:119`) calls `decodeFrame`, `frameAccepted` and `report`, then constructs the complete `Spec.Message`. The actual native entrypoint is `lp_lean1090_Lean1090_Impl_decode`; the frozen benchmark uses that same entrypoint. `report` computes parity/address/outer altitude/identity, ADS-B or Comm-B raw field records, and both standard and oracle semantic views. There is no JSON generation in this function. Its numerical output is a proof-visible `FloatExpr` tree: `Impl.Numeric.eval` runs later in the JSON adapter and must not be charged to headline decoding. CPR tracking is a separate secondary workload.

The standalone `Impl.BDS50.decode` pilot is not the whole-message inference path. The benchmark response file does not link Impl/BDS50.c. Whole-message scores run through `Impl/CommB.lean`'s `cbDensityTerms`, `cbDensity`, `cbPenalty`, `cbCombinedScore` and `cbScorePasses`, with exact rational software-binary64 operations from `Impl/Binary64.lean`. Optimizing or profiling only the pilot would not establish a whole-decoder improvement.

## Real repeated work and compiler sharing

* Accepted DF17 computes a syndrome in `frameAccepted`, then another in `report`. AP formats DF0/4/5/16/20/21/24–31 compute a syndrome for report CRC and another for address recovery. DF11 and DF18 compute one. In DF11, generated C shares the report syndrome with interrogator extraction.
* Every `frameSyndrome` rebuilds the information word from field parts, packs with Nat arithmetic, computes the checksum through a bit loop and XORs parity. This is not a byte-table CRC. Nat/BitVec conversion, powers, division and reference-counted intermediate allocations belong to this live cost.
* The source mentions `frameCommB` twice in `report`, but generated Message.c computes it once and reuses the candidate list. The compiled report inlines the small `frameCommB` wrapper into calls to `frameOracleAltitude` and `inferCommB`; profiling only the wrapper entry would miss live inference.
* For each accepted Comm-B candidate, `decodeBDS` repeats `bdsWireValid` after eligibility already passed the same hard check. Score gates run only for registers 40/44/45/50/60 whose hard checks passed, after the nonempty-MB guard. BDS05 has an altitude-match policy and no density gate; BDS65 never survives whole-message inference.
* Accepted ADS-B messages pass `adsbHardValid` in acceptance and again inside `decodeADSB`. Raw field extraction, exact semantic values, labels and FloatExpr construction extract overlapping payload bits separately.
* `Semantics.commB` shares its tableValues list with standardValues and its labels between standard and oracle projections in generated C. These are not duplicate evaluations. However, the compiled function invokes `commBStandardFloats` and `oracleCommBFloats`; the former calls the latter (except BDS30), so numerical-expression work is repeated.
* `commBValue` performs a layout selection and named-field lookup on each call. Density/penalty/output generation therefore repeat layout searches and field extraction. Within one validity predicate, repeated QNH or temperature calls can be CSE-shared; source occurrences alone are insufficient to count work.
* `Semantics.adsb` independently constructs standard/oracle exact-value and expression lists. Oracle values often delegate to the standard implementation, so source-level identical views can still be recomputed across separate function boundaries. Verify individual branches in generated C before claiming a multiplicity.

The decisive inspected files were `.lake/build/ir/Impl/Message.c`, `.lake/build/ir/Impl/CommB.c`, `.lake/build/ir/Impl/Semantics.c`, and objdump disassembly of the actual `Impl_report` and `Semantics_commB` symbols. Native compiler inlining and CSE mean function definitions alone do not establish executed entries.

## Corpus and control-flow predictions

Independent byte parsing of the full 172432-row corpus gave DF0=21393, DF4=8841, DF5=2949, DF11=38456, DF16=2694, DF17=31395, DF18=18990, DF20=29460, DF21=18254. All other DFs have zero corpus rows. DF20/21 contain 548 empty MB words (497 and 51), leaving 47166 nonempty words. These describe this workload, not general branch coverage.

Given acceptance of every corpus message and the current generated control flow, predicted syndrome calls are 287418 (114986 more than one per message). The bit loops predict 26320784 steps. These are derived predictions, not native instrumentation. The diagnostic census labels predictions explicitly and asserts its candidate-set shadow against actual returned messages. Callgrind's executed call counts are the independent runtime check where symbols remain out of line.

## Profiling and stage attribution

The main driver prepares all bytes and selects a corpus stratum before a loop that calls unchanged `Impl.decode` once and appends each complete message. The full retained output is passed through a noinline consumer, which hashes the complete Repr including every standard/oracle semantic field and FloatExpr. Per-DF digests make the full run and individual/family runs comparable. Input selection, printing, hashing, dropping and optional census are outside the `Impl.decode` collection tree.

Use Callgrind `--collect-atstart=no --toggle-collect=lp_lean1090_Lean1090_Impl_decode` to obtain executed Ir, not wall time. Caller-side append is excluded from that root; small-allocation heartbeat deltas explicitly include append. Native perf software-clock samples should be filtered to stacks under the same root. The optional `--wait` handshake permits enabling after the prepared marker, running after `run`, disabling at the decoded marker, then continuing with `consume`. No clock or throughput number is emitted by the diagnostic driver.

Mutually exclusive major groups should be frame extraction; acceptance/parity/address; outer scalar fields; raw ADS-B fields; Comm-B inference/raw candidates; ADS-B semantic construction; Comm-B semantic construction; and direct message/report assembly plus residual control. Assign shared Nat/Rat/GMP/allocator self-cost by real ancestor context where available. Never sum inclusive parent and child totals. If caller context is insufficient, keep unresolved shared cost explicit rather than allocating it proportionally.

Allocation is an orthogonal view. Allocator costs nested inside field/scoring stages are already part of those stages; adding allocator-inclusive totals to semantic totals double counts. Direct constructor instructions under report are not the total cost of output allocation, and residual report self-cost also contains control flow.

## Register-specific score probes

Generic `cbScorePasses(register, word)` has one symbol, so a call-context profile cannot infer the register argument. Separate `score40`, `score44`, `score45`, `score50` and `score60` modes first select every nonempty corpus DF20/21 word passing that register's live `bdsWireValid`, then call the live `cbScorePasses` once for each selected word. Use its symbol as the collection root. Output includes selection counts, accepted counts, DF split and an observable input/result digest.

These are supplemental inclusive component probes over the actual reached population. Their costs overlap the full decode profile and must not be added to it or presented as a new end-to-end throughput estimate. Preparation does not call the score function. Full-decode census score-attempt/pass counts must agree exactly with each score probe's selected/pass counts; candidate acceptance is separately asserted against the complete decode output.

## Verification boundaries

The build script compiles only this new diagnostic module, replaces only Bench/WholeDecoder's object in a copied link response, and verifies all 20 reused production/model native-object hashes and production source hashes before/after. It does not edit Lake targets, frozen guards or benchmark sources. The ordinary theorem and differential gate remains the authority for a later optimization; this diagnostic tool does not replace it.

The driver validates full corpus cardinality, 7/14-byte parsing, accepted output cardinality, per-DF digest cardinality and candidate shadow agreement. Its Repr/FNV check is an observability and deterministic replay check, not collision-proof equivalence. Root-owned profile analysis must retain raw profiles, invocation flags, driver/source/object hashes, counts and unresolved attribution limitations. Zero-row DF subsets must remain explicit and must not be advertised as measured coverage.


## Implemented diagnostic evidence

`review/diagnostics/DecodeCosts.lean` and `build_decode_costs.py` are implemented outside frozen inventory. The original v1 all-corpus validation retained 172432 complete messages and asserted every candidate-set shadow. Full Repr digest is FNV1a64 18440978423862441655 over 732573131 bytes. Independent Python corpus parsing agrees with every DF count. The loop small-allocation count was 82338629; this includes append/control and excludes preparation/consumption. Evidence: `driver-all-census.jsonl`, `driver-validation.json` and preserved `driver-v1/`.

V2 adds `candidate40/44/45/50/60`: all47166 nonempty DF20/21 words call the actual `commBCoreEligible`, including the hard predicate and conditional score. Inputs retain DF and oracle outer altitude for provenance; the generic core eligibility predicate itself consumes neither. Every candidate mode's pass count matches census:15513,0,0,9813,17149. Score-only selected/pass counts are15513/15513,0/0,0/0,10641/9813,19356/17149. Evidence: `driver-v2/validation.json`. BDS44/45 hard checks are exercised but their score paths have zero reached corpus examples.

Candidate probes exclude the common per-message DF/nonempty guard, inference list traversal, accepted `decodeBDS` hard-check repetition and raw payload construction. They measure the real core eligibility helper only and are explicitly supplemental/non-additive. The main whole-message profile retains all omitted costs. A candidate probe and its score probe overlap; do not sum them or treat their difference as a paired elapsed-time experiment.

V3 changes only the diagnostic pre/post-loop handshake: it accepts no-op `poll` lines so an external controller can wake a blocked read. The controller disables instrumentation during preparation and complete-output hashing, enables it after the prepared marker, and collects only the unchanged native root. Direct vgdb commands use `--max-invoke-ms=0`, avoiding sandbox-denied PTRACE_ATTACH. Failed/slow earlier control attempts remain under `callgrind-controls-smoke*`; none modifies production.

The final control smoke for df16 passed2694 records and matched the full-model digest7637451641586568772. The explicit pre-disable dump has1641282623 Ir; an earlier polling/ptrace-retry smoke had1641280306. Small instruction-count differences can arise from allocator state affected by control/setup work; these are diagnostic instruction counts, never a new throughput estimate. Instrumentation-off can leave the termination dump with zero totals and a wrapped summary. The controller preserves it but explicitly selects `callgrind.out.1`, requiring its summary and totals to agree.

`profile_decode_costs.py` records commands, source/binary/corpus/lock hashes, control output and instrumentation-state acknowledgements, selected/retained/final cardinalities and both dump hashes. It snapshots its source per invocation. The controlled family and candidate/score profile campaign is parent-coordinated and can run independent jobs concurrently because no timing or memory-contention conclusion is drawn.
