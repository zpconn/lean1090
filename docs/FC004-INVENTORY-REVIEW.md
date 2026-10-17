# FC004 inventory review (supporting review; not applied)

The finalized proposal and campaign result are in
[FC004-DIFFERENTIAL-FREEZE.md](FC004-DIFFERENTIAL-FREEZE.md). The standalone
CPR freshness and metadata issues identified below were corrected before
the passing campaign; that observation is historical. The final proposal
includes the exact combined guard-and-lock patch and all file hashes.

Reviewed on 2026-10-16 after the user's FC003 approval. This is a read-only
dependency review, not the final FC004 proposal or a claim that the diagnostic
campaign has passed. No frozen file or lock entry was changed for this review.
The exact DTE test filenames and all hashes must be finalized after the FC003
implementation and successful complete campaign.

## Requested minimum

The user's requested freeze adds these current paths, plus the new permanent
DTE checker and adapter (provisional names shown):

```text
scripts/run_differential.sh
scripts/check_altitude_differential.py
scripts/check_cpr_differential.py
scripts/check_dte_differential.py
scripts/check_message_differential.py
scripts/check_reserved_velocity_differential.py
scripts/check_numeric.py
Tests/AltitudeDifferential.lean
Tests/CommBDifferential.lean
Tests/DTEDifferential.lean
Tests/ReservedVelocityDifferential.lean
Tests/MessageGenerator.lean
scripts/FuzzCPR.lean
```

`scripts/FuzzCommB.lean`, `scripts/FuzzBDS50.lean`, and
`scripts/check_commb_fuzz.py` are already frozen. Their entries should be retained
unchanged. CPR generation is partly Python (`check_cpr_differential.py`) and
partly Lean (`FuzzCPR.lean`); both are needed. The reserved-field and DTE Python
checkers also generate their test inputs, so generator coverage includes those
files. No generated CSV, cache, build product, or mutable evidence output needs
to be locked as an input.

The existing inventory has 61 paths. With these provisional DTE names, the
minimum adds 13 paths. Use dynamic inventory membership for
`scripts/check_*_differential.py`, `Tests/*Differential.lean`, and the selected
generator patterns, so adding another member without a lock entry is rejected.
Keep explicit entries for all approved current files as well, so deletion still
fails clearly. Preserve all existing entries and the sorted, deduplicated return.

## Dependencies recommended in the same proposal

The following files are executable test/oracle dependencies even though their
names do not match the user's minimum patterns:

| Paths | Reason |
| --- | --- |
| `Tests/Numeric.lean` | Contains the actual numeric comparison loop and expected domains. Freezing its Python launcher alone leaves the checks editable. |
| `tests/numeric_oracle.rs` | Produces the expected libm and binary32 results for that loop. |
| `differential/message-oracle/Cargo.toml`, `Cargo.lock`, `src/main.rs`, `src/commb.rs` | Build configuration, pinned dependencies, fresh whole-message reader, and fresh named-register reader used by message/altitude/reserved/DTE checks. |
| `differential/cpr-oracle/Cargo.toml`, `Cargo.lock`, `src/main.rs` | Build configuration, pinned dependencies, and actual public global/local CPR calls. |
| `lakefile.toml` | Maps the test executable names to Lean roots and controls native compiler flags. Otherwise a frozen launcher can be redirected to another root. |
| `lean-toolchain`, `lake-manifest.json` | Preserve the compiler and exact package resolution used by those builds. These are reproducibility additions beyond the requested minimum. |

These are 12 additional paths, bringing the provisional complete inventory to
86. Their inclusion requires the user's FC004 approval. Freezing `lakefile.toml`
also means later additions of executable targets require explicit approval;
the proposal should state that consequence rather than silently introducing it.

The actual implementation modules remain optimization targets. They should not
be frozen by this testing amendment. `Impl.JSON` and the CLI are the system under
test, rather than sources of oracle expectations. The existing test adapters
exercise actual implementation and Spec values, including the exact semantic
values now corrected by FC002/FC003. The exception rules are executable in the
checkers; `DISCREPANCIES.md` is not dynamically consulted to waive mismatches.

## Required compatibility amendment to an existing frozen guard

A change only to `scripts/frozen_paths.py` will **not** work. In the current
`scripts/check_impl_imports.py`, lines 74–75 construct `FROZEN_LEAN_FILES` from
every frozen `.lean` file. Its direct-import loop permits only Spec, Model,
Mathlib, Init, Std, and Lean. The new frozen differential adapters necessarily
import Impl; the unchanged guard would reject them immediately.

FC004 therefore needs a second, explicit proposed diff to that guard. Keep its
current semantic transitive check, all current direct checks, the import-free
manifest checks, and all four negative self-tests unchanged in force. Add a
separate **exact list** of approved differential adapters whose direct import
policy permits Impl as well. Their imports of Proofs or arbitrary local helper
names need not be permitted. The current such files are:

```text
Tests/AltitudeDifferential.lean
Tests/CommBDifferential.lean
Tests/DTEDifferential.lean
Tests/ReservedVelocityDifferential.lean
Tests/Numeric.lean
scripts/FuzzCPR.lean
```

`Tests/MessageGenerator.lean` imports only Spec and can retain the existing
direct-import restriction. Do not replace the existing all-frozen-header check
with an unrestricted filename exclusion, and do not allow a Spec/Model module
to acquire an Impl dependency through these adapters. The existing transitive
semantic audit continues to reject that route. Add rejection checks for a
semantic module importing an adapter and for an adapter importing Proofs when
preparing the guard proposal; these are tests of the amended guard, not a change
to any theorem or benchmark requirement.

`scripts/check_lock.py` already checks exact membership and every SHA-256, so it
does not need a functional change. The existing `scripts/test_lock.py` copies
the inventory dynamically and remains usable. For FC004, demonstrate in a
disposable copy that changing each newly frozen file is rejected, that adding a
matching new checker/adapter/generator is rejected, and that the full gate still
checks the lock first. A separate review-only validation can exercise these
cases without changing the frozen self-test script. If the permanent self-test
is extended, include that as another explicit FC004 guard diff and hash.

## Observed gaps and limits before the freeze

1. **Standalone CPR freshness:** `check_cpr_differential.py` checks the vendor
   commit but, at review time, does not check the vendor worktree with
   `git diff --exit-code HEAD -- crates/rs1090 Cargo.toml Cargo.lock`. The other
   principal checkers do. The complete campaign catches a dirty oracle through
   those components, so this observation does not invalidate its prior clean
   evidence. Add the same check before freezing the standalone CPR checker.
   Its summary also still says the whole-message runner is required; that is an
   outdated description rather than a failed test.
2. **Whole-message versus full gate:** a passing diagnostic campaign still
   leaves the seven missing capstones, the complete upstream unit-vector port,
   and the final full gate outstanding. FC004 can freeze this differential
   suite without claiming those items are complete.
3. **Full scale has not been established by this review:** the quick campaign
   requires 100,000 generated messages; the frozen `check_all.sh --full`
   requests 10,000,000. Nothing in this read-only inventory review substitutes
   for the required full run before milestones/end.
4. **Diagnostic scope:** the message checker accumulates every whole-message
   and direct-register mismatch. The numeric adapter raises on its first
   failing comparison, and the CPR adapter raises on a runtime/Spec refinement
   failure. The outer diagnostic runner still proceeds to later components.
   This does not hide a passing campaign's comparisons, but a future failing
   campaign would not contain every later numeric/refinement mismatch. The
   user's current whole-message accumulation requirement is satisfied by its
   dedicated message checker; do not describe every component as exhaustive
   after an early internal exception.

Finalize the concrete FC004 patch, exact added-path hash manifest, and proposed
before/after inventory only after all mandatory campaign strata pass with no
unclassified differences. Do not write an applied FC004 log entry or refresh
`spec.lock` until that exact proposal is approved.

## Proposed guard implementation and executed scratch checks

Candidate copies now exist under `.cache/fc004-proposal/scripts/`; the actual
frozen guards remain unchanged. `GUARDS.diff` in that directory modifies only
`scripts/frozen_paths.py` and `scripts/check_impl_imports.py`. Its SHA-256 is
`e43007ad27995219a80050382cdd3c153513bad79156b0542156df03d702a2c6`.
This is a candidate for the primary agent's final review, not an applied FC004.

The proposed inventory has 86 files: all 61 current entries and the 25 additions
listed above. It includes dynamic membership for new matching checkers, Fuzz
generators, differential adapters, message generators, and Rust oracle helpers.
The proposed import guard permits Impl imports only for the six exact named
adapters, checks each adapter's compiled environment for any transitive Proofs
module, and retains every existing semantic and manifest restriction.

Executed `python3 .cache/fc004-proposal/scripts/check_impl_imports.py`: passed
for 20 runtime modules, 30 semantic modules, and six adapters. All four original
negative self-tests and two new rejection tests passed: a Spec module cannot
import an adapter, and an adapter environment cannot import Proofs. Log:
`.cache/fc004-proposal/import-audit.log`.

Executed `python3 .cache/fc004-proposal/check_lock_proposal.py` entirely in
temporary copies. The intact candidate passed; each of 86 single-file mutations,
each deletion of the 25 new files, eight added-file membership changes, and a
duplicate lock record were rejected. The full gate rejected a changed lock
input before any other work. The unchanged existing `scripts/test_lock.py`
also passed against the proposed inventory. Results:
`.cache/fc004-proposal/lock-review.json` and `lock-review.log`. No project lock
refresh or seven-capstone work was performed.
