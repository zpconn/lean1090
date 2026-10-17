# Project rules

Read `GOAL.md` and `PROGRESS.md` at session start and after every context reset. The user reviewed the amendment diff and authorized the final dependency fixes followed by writing `spec.lock`. The lock is written: the reference files and guards are frozen. The latest chat authorizes adding published-layout coverage and synthetic CPR tests, then continuing section 4 and subsequent work under GOAL.md. Later chat instructions override this file.

For optimization, keep the software binary64 model as the proved reference and first optimize the proved path: exact per-field density tables, verified integer arithmetic, and a full-model fallback inside a proved rounding-error interval around −3. These are candidate techniques, not permission to approximate decisions. Only after this approach fails to close the measured gap may hardware binary64 add/sub/mul/div primitives be proposed. Ask the user before adding them to TRUSTED.md or code; any approved primitives must use `-ffp-contract=off` and runtime cross-checks against the software model. None is currently authorized.

1. **Persistence.** First, save this prompt verbatim to `GOAL.md` (if it isn't already there). Create `AGENTS.md` with the rules in this section, plus a one-line `CLAUDE.md` pointing to it. Keep `PROGRESS.md` current (done, in progress, next, open questions), so a fresh session can resume from GOAL.md, AGENTS.md and PROGRESS.md alone.
2. **The standard is the spec; rs1090 is the oracle.** Write the reference semantics in `Spec/` from the published standards: ICAO Annex 10 Vol. IV, and Junzi Sun's *The 1090 Megahertz Riddle* (free online). Never transcribe them from rs1090's code. rs1090 is for tests, differential checks and benchmarks. Each Spec definition's docstring cites the table or section it encodes.
3. **Frozen files.** After I approve the spec at checkpoint 1, these are frozen:
   - `Spec/`
   - `Capstones.lean`
   - `bench/BENCHMARK.md`
   - the rs1090-side benchmark harness

   Record their SHA-256 hashes in `spec.lock`, and make the gate fail if any of them changes. Never edit a frozen file yourself. If you believe one is wrong, stop and ask me.

   For every explicitly approved change to a locked file, append an entry to `docs/FROZEN-CHANGES.md` **before** updating `spec.lock`: date, affected files, old/new SHA-256 hashes, reason, executed evidence and the user's approval. Preserve all prior entries and before/after lock snapshots. FC001, FC002 and FC003 are applied. FC003 changed exactly docs/DTE-BYTE-ORDER-PROPOSAL.diff (SHA-256 1de67cd6b73644ebd60a9e24f3e8f3e6618dd58ef364a69ef8accea29ef6968a), only Spec/CommB.lean; the other60 lock entries are unchanged. The FC00361-file lock passed; FC004 subsequently expanded it to86 files.

   The complete post-FC003 diagnostic campaign passes:576164 whole messages,101244 direct Comm-B cases, all scoped DFs/70 ADS-B branches/14 registers covered, with only documented D001/D009 oracle differences. Failed-campaign evidence is retained. The altitude12288-code, reserved-velocity16480-case and exhaustive65536-code DTE fresh-oracle regressions are permanent requirements in both complete quick and full differential runs. Standard negative Gillham values and MSB-first reserved/DTE fields remain available separately from oracle-compatible values. D012 records the reproduced endian-read scan.

   **FC004 is approved and applied exactly.** Patch docs/FC004-DIFFERENTIAL-FREEZE.diff has SHA-256 eee626abcc93e917fe7d82e6f6f64f67ea54e62f227fd83e7c8515a74e52291f; the86-entry live lock has SHA-256 4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a. Every input hash was verified, the FC004 history was recorded before touching the lock, and before/after snapshots are under tests/evidence/frozen-changes/FC004/. No other frozen change is authorized.

   Before resuming the seven remaining capstones, finish two new diagnostic suites: (1) actual Impl.decodePositions versus pinned rs1090 decode_positions, full timestamped corpus plus synthetic multi-aircraft pairing/reference/motion branches; (2) all upstream in-scope unit vectors, wired through scripts/run_unit_tests.sh. Accumulate every finding before proposing frozen-model corrections as a batch. Once each suite passes, propose freezing it; FC005 must also wire the stream suite into run_differential.sh as mandatory. Do not apply an unapproved proposal. Stage new diagnostic code outside frozen membership patterns until approval. Only after both suites pass and are frozen may the seven capstones resume.

   Both new diagnostic suites now pass. FC005 is proposed, not approved or applied: docs/FC005-TRACKING-UNIT-FREEZE.diff SHA-256 1dc0630b4c1324fa8f85565cb349db9aee47a215db37ec2efbf1476d5843ecf7, producing102-entry lock3daafa7400ddc2a9bac399e53698e3a20ab74356a8630d0df9db71ed2d8d21ba. It freezes16 new tracking/unit sources, extends the two guards and adds mandatory tracking to the differential runner. Live spec.lock remains FC004's86 entries. Do not apply FC005 or resume any of the seven capstones without approval. After approval, verify exact inputs, log old/new hashes before updating the lock, preserve snapshots and apply only the approved patch.

   Standing optimization/test rules from2026-10-17: every Impl name referenced by frozen adapters must remain the live path or delegate to it; never retain a dead legacy copy just for frozen tests. If a refactor cannot preserve that binding, stop and propose an FC. At every milestone and the final10M run, run the normal fixed-seed sets plus check_message_differential.py directly with a newly sampled recorded seed and freshly seeded FuzzCommB cases; report both results. lakefile.toml is frozen: the future benchmark executable target requires its own approved FC with evidence of exact bench/BENCHMARK.md compliance. After both new suites are frozen and all seven proofs are finished, propose that worker FC and measure the whole-decoder baseline under the frozen ABAB protocol with all raw samples before optimization gen1.
4. **No cheating.**
   - Forbidden anywhere in the decoder or its proofs:
     - `sorry`, `admit`, new `axiom`s, `native_decide`, `unsafe`
     - `partial`, `panic!`, `get!` or `unreachable!` in decoder code
     - `@[implemented_by]`/`@[extern]`, except entries listed in `TRUSTED.md`. At most 5 tiny primitives are allowed there, each with a pure-Lean reference body that the proofs use and that the differential suite cross-checks at runtime.
   - `#print axioms` on every capstone must list only `propext`, `Classical.choice` and `Quot.sound`.
   - Never weaken a test, theorem, tolerance or benchmark to make progress.
   - Never special-case the benchmark corpus.
5. **One gate.** `scripts/check_all.sh` must pass before every commit. It runs:
   - the build, which checks all proofs
   - the axioms and forbidden-construct audit
   - the `spec.lock` check
   - the unit tests
   - the differential suite: the full corpus plus 100k generated messages with `--quick`, and 10M generated messages before each milestone and at the end.

   Commit small, verified steps.
6. **Honesty.** Every claim in PROGRESS.md or the README must be backed by a command you ran. If the 10% target is still out of reach after you've exhausted your ideas, report the best measured number. Don't redefine success.
7. **Parallelism.** If your harness can run parallel subagents or git worktrees, use them for independent proof obligations and optimization experiments. Merge only through the gate.

