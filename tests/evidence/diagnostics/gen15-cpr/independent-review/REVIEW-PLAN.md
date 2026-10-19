# CPR diagnostic independent review plan

This checklist prepares an untimed diagnostic review; it makes no speed claim.
The normative workload is frozen `Bench/WholeDecoder.lean:runCPROnce`, using
the same 172,432 corpus rows, original timestamps and 6,903 pinned airports.
Only the diagnostic worker object may be replaced; production/model objects
must match the retained generation 15 fresh-build inventory exactly.

## Work and collection boundaries

1. Compare copied input decoding, binary64 timestamp/airport preparation,
   `trackingReport` and `advance` with the frozen worker. Strip exactly the
   Beast prefix, preserve all rows/order, and retain the same input bits.
2. Preallocate the full output array, empty aircraft state and absent reference
   before entering the collected root. The root must decode each message once,
   route each accepted DF17/18 immediately through live `streamStep`, append
   the complete message and optional position, and retain the final state.
   The callback remains `fun _ => false`; no prior run state is reused.
3. Inspect generated C/native lifetime and calls: input/airport preparation,
   eager immutable-table initialization, control protocol, JSON generation,
   audits, digesting and destruction occur outside the collected root.
   No counter or shadow computation is inserted inside production work.
4. Full messages and the entire final state must remain observable after
   collection. Compare the full-message digest to the established decoder
   diagnostic; compare every position/routing row and projected final state to
   the actual frozen worker. Also audit all internal final state fields against
   the live batch policy after collection, explicitly distinguishing that
   additional diagnostic check from the frozen worker's projected audit.
5. Preserve the 1e-9-degree comparison rule and report bit-identical counts
   separately. Do not substitute aggregate position counts for per-row checks.
6. Audit all prepared input bytes/timestamp bits and airport rows/bits/order.
   Hash the exact corpus, airport data, worker and diagnostic binaries and all
   compile/link commands. Document diagnostic-only wrapper allocation/call
   overhead instead of claiming byte-identical benchmark machine code.

## Accounting and interpretation

- Establish a single whole-stream native root and its exact observed entry
  count. Account every primary self instruction once; require the raw summary
  and all exclusive stage totals to agree. Independently replay the parser.
- Use full caller contexts to separate decoding, message projection/routing,
  state lookup/update, numerical local/global CPR, motion/geography and output
  control where actual native boundaries support that distinction. Keep
  shared/ambiguous or inlined work explicit instead of inventing attribution.
- Aggregate same-symbol self costs only after context attribution. Incoming
  inclusive costs overlap descendants and recursion and must not be summed
  as exclusive stages. Supplementary component probes, if any, are separate
  observations and cannot be added to whole-stream totals.
- Verify actual worker CPR perf separately, including unknown/excluded sample
  counts and sequencing before native/Callgrind work. Callgrind is diagnostic
  instruction accounting, not a timing comparison with rs1090.
- Corpus coverage is narrow: it resolves positions for only two aircraft.
  Counts cannot establish global policy correctness or predict other tracks.
  Any later change still needs the frozen synthetic tracking suite and the
  unconditional tracking refinement for arbitrary geography, callback,
  reference and reports (`Proofs/CPRTracking.lean`).

## Initial source review finding

The first inspected `runCPR` allocated output capacity inside the collected
root. The owner agreed to move that allocation and empty state construction
outside and preserve the earlier source/build attempts. Final review must
inspect the corrected source and generated C, not infer completion from this
plan. Full unfiltered symbol output is also being replaced by filtered evidence.

All Python runs disable bytecode before imports. No review-side native runs,
builds or broad hashing occur during the isolated perf windows. Final reports
must bind exact source/native/history/archive membership, preserve failures and
retain targeted or compressed native inspection evidence to bound disk use.
