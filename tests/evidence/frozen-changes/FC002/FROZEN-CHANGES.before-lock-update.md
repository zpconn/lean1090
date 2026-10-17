# Frozen-file change history

Every change to a file listed in `spec.lock` must have an entry here **before**
its lock hash is updated. Record the date, exact files and old/new SHA-256
hashes, reason, evidence, and explicit user approval. Approval is required for
each future locked-file change; this log does not authorize changes itself.
Keep prior entries intact and add a new entry for each approved change.

## FC001 — negative Gillham compatibility policy

- Date: 2026-10-16 (America/Chicago).
- Entry recorded: 2026-10-16T19:06:49-05:00, before any `spec.lock` update.
- Approval: the user explicitly approved the proposed two-file correction in
  chat on 2026-10-16, subject to permanent exhaustive AC13/AC12 differential
  coverage, a standards-cited discrepancy retaining the standard answer, and
  this history entry before refreshing the lock.
- Authorized patch: [ALTITUDE-COMPATIBILITY-PROPOSAL.diff](ALTITUDE-COMPATIBILITY-PROPOSAL.diff),
  SHA-256 `2243b40c0de55098d5330b928390962ac5117903fd9e6de7caea044f046904b3`.
- Previous `spec.lock` SHA-256:
  `97a48a89e3b254a2c85953b345560a3c4baa7478b9c80a2c768eeef8dd6b5a2d`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `Spec/Altitude.lean` | `b406ecf0368fc55555b1b5db4aa406de03daa3ddd43dfc0e15c64bc52b4714d5` | `c505219ed76335af94f417d68c896b8667575b2e765c8be8645068401c7dc7e4` |
| `Spec/AssignmentAltitude.lean` | `203ebc09ff09a4413474485271a04d938946a9a1c6270574b08fa5e718b6ada1` | `b1d8c183288f429ec40bc39c0c2ec845167819e691c3b565199ef71dd88520ec` |

Reason: pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30`
reports negative Gillham altitudes as missing. The separately named oracle
compatibility functions previously retained them, changing Comm-B BDS05
candidate membership on 33 corpus frames. `oracleAC13`, `oracleAC12` and the
independent assignment functions `compatibility13`, `compatibility12` now
mirror that receiver policy. Standard decoders/encoders/representability and
negative Q=1 binary25 values are unchanged. No capstone, guard, tolerance or
other locked file is changed.

Evidence available before approval: [review and counterexample](ALTITUDE-COMPATIBILITY-REVIEW.md)
and `tests/evidence/altitude-proposal/summary.json` retain the proposal's
12,288-code comparison against actual pinned `Message::from_bytes`: all
8,192 AC13 plus all 4,096 AC12 values, zero mismatches. The review also
kernel-checked independent assignment equivalence and AC12 receiver acceptance.
The concrete corpus counterexample is `a1000000920805003ffc0005c6e5`.

Post-application validation and final lock-update timestamp will be appended
below after executing the checks; the hashes above already describe the exact
approved patch on disk.

Validation before the hash refresh: `lake build Proofs lean1090` passed
(2,091 jobs); the unchanged `CheckHypotheses.lean`,
`CheckReceiverPolicy.lean`, `CheckAssignment.lean`, and module-graph audit
passed. All seven hypothesis predicates and `assigned` remain independent.
The review-definition export was regenerated and its exact-source check
passed. D010 and five complete-frame standard/compatibility probes are
recorded in `DISCREPANCIES.md` and `tests/evidence/negative-gillham/`.
The permanent exhaustive test is now wired into both full and quick
differential invocations; its fresh post-lock result will be recorded below.

Lock refreshed: 2026-10-16T19:09:05-05:00. New `spec.lock` SHA-256:
`c07e637c7086255949170936a94b0e7624016f99ae89e8117612bbfd1ff0b278`. Exactly the two entries
above changed; all other 59 frozen-file entries are byte-for-byte unchanged.

Post-refresh validation: `scripts/run_differential.sh --altitude-only` passed
all **12,288** code comparisons against fresh pinned rs1090 calls, plus the
Comm-B candidate regression, with zero mismatches. AC13 accepts all 8,192
frames; AC12 accepts 3,322 and rejects 774. Each field retains all 12 negative
Gillham values in the standard view and all 40 negative binary25 values in
both views. Complete outputs, hashes and commands are in
`tests/evidence/altitude-exhaustive/`. Rechecking all 33 prior corpus candidate
mismatches also passed; the standard view retains 25 barometric negative
heights and eight GNSS metre heights (the separate D007 rule), with evidence
in `tests/evidence/altitude-corpus-regressions/`.

`python3 scripts/check_lock.py` passes all 61 files. The unchanged full gate
was executed and still fails on the nine outstanding final theorem names;
this is not a completed project/full-suite claim. Build/audit output and
before/after lock snapshots are retained in `tests/evidence/frozen-changes/FC001/`.


## FC002 — reserved velocity oracle byte order

- Entry recorded: 2026-10-16T19:44:39-05:00 (America/Chicago), before refreshing any lock entry.
- Approval: the user explicitly approved exactly `docs/RESERVED-VELOCITY-PROPOSAL.diff`, SHA-256 `274e71b9d8107d8a3e86afcc4ded4fe6e754924dee0c35bfd599234b0c61931a`, touching only the two files below. No other frozen change is authorized.
- Previous `spec.lock` SHA-256: `c07e637c7086255949170936a94b0e7624016f99ae89e8117612bbfd1ff0b278`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `Spec/Semantics.lean` | `f759fd4a7a05dc88f95dd8d6e185bf1db47d4427cfc9be0b8c389c007246af59` | `782f6f2e1f486b4645c19178eb583f3be828dc540e7fe62b850550a393a4ddf8` |
| `Spec/Assignment.lean` | `ef6fa12da290362a6c8167cbf0bef767202a451d99bb8553131b078867cc1aaa` | `01d7ea1d9c37f0b9730643fa571b109c8c834f133d9996917c6b04283a310eb8` |

Reason: TC19 subtypes0/5/6/7 preserve a22-bit MSB-first raw field. Pinned rs1090's `ReservedVelocityData` lacks an endian attribute, so deku0.20.3 uses native byte order, giving8/8/6-bit little-endian chunks on the pinned x86_64 host. The approved patch adds that separately named oracle quantity to the semantic model and independent assignment. Standard/raw fields are retained. No theorem, guard, benchmark or other frozen file changes.

Evidence available before approval: `docs/RESERVED-VELOCITY-REVIEW.md` and `tests/evidence/reserved-velocity-proposal/summary.json` record16,511 fresh-oracle comparisons of the review prototype, including zero/all-ones/all22single-bit patterns and4096seeded random values per reserved subtype, plus31 generated failures. Message `9011223398040000000000000000` has standard/raw2097152 and oracle128. This is proposal evidence; actual-runtime validation will be recorded separately after execution.

Procedure evidence: the approved patch hash and all61 pre-change lock entries were checked, and `patch --dry-run` passed before applying the exact patch. Before/after source copies and the original lock snapshot are retained in `tests/evidence/frozen-changes/FC002/`. The after-lock snapshot, post-application validation and refresh timestamp will be added after those operations.

Validation before the hash refresh: `lake build Proofs lean1090` passed2098jobs, including the extended all-input refinement and its permitted-axiom report. The unchanged hypothesis, receiver, independent-assignment and module-graph audits passed; all seven hypothesis predicates and `assigned` remain decoder-independent. The review definition export was regenerated and its exact-source check passed. Logs are retained in the FC002 evidence directory.
