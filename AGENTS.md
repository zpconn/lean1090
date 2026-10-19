# Project rules

Read `GOAL.md` and the current-status section of `PROGRESS.md` at session start
and after every context reset. Later chat instructions override project files.

## Current authorization

The user accepted generation 10's measured result and explicitly authorized
committing all project work, tidying documentation and presentation, and the
first push to a **private** GitHub repository. This supersedes the earlier
review pause and GOAL.md's public-repository/first-push approval requirement.
Do not ask for that approval again. No additional optimization, frozen-file
change or trusted primitive is authorized by the publication task.

Generation 10's verified source commit is
`d51a3040984beb6f0f96b0f4fcf225ba2622a7e0`. Decode reached 1.168948811789×
rs1090; CPR reached 0.790786943138×. Retain the measured artifacts unchanged.
All 23 capstone contracts are proved. The runtime uses zero project-specific
trusted primitives. The current lock has 104 entries and SHA-256
`5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

## Ground rules

1. **Persistence.** First, save this prompt verbatim to `GOAL.md` (if it isn't already there). Create `AGENTS.md` with the rules in this section, plus a one-line `CLAUDE.md` pointing to it. Keep `PROGRESS.md` current (done, in progress, next, open questions), so a fresh session can resume from GOAL.md, AGENTS.md and PROGRESS.md alone.
2. **The standard is the spec; rs1090 is the oracle.** Write the reference semantics in `Spec/` from the published standards: ICAO Annex 10 Vol. IV, and Junzi Sun's *The 1090 Megahertz Riddle* (free online). Never transcribe them from rs1090's code. rs1090 is for tests, differential checks and benchmarks. Each Spec definition's docstring cites the table or section it encodes.
3. **Frozen files.** After I approve the spec at checkpoint 1, these are frozen:
   - `Spec/`
   - `Capstones.lean`
   - `bench/BENCHMARK.md`
   - the rs1090-side benchmark harness

   Record their SHA-256 hashes in `spec.lock`, and make the gate fail if any of them changes. Never edit a frozen file yourself. If you believe one is wrong, stop and ask me.
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

## Active safeguards

- Never edit a locked file without exact user approval. For every approved
  change, record date, files, old/new hashes, reason, executed evidence and
  approval in `docs/FROZEN-CHANGES.md` **before** updating the lock. Keep
  before/after snapshots. FC001–FC006 are the complete approved history.
- Frozen membership matters. In particular, `review/upstream-units` contains
  exactly its seven locked scripts; bytecode or an added package fails the gate.
- Frozen adapters must call the live production path or delegate to it.
  Do not keep obsolete implementations solely for tests. `Impl/` imports
  neither `Spec/` nor Mathlib; frozen reference modules never import `Impl/`
  or `Proofs/`. Do not alter the frozen hypothesis/assignment dependency guards.
- At milestones and the final 10M run, run the fixed-seed gate and a separate
  whole-message campaign with freshly sampled, recorded message and Comm-B
  seeds. Preserve every finding and coverage count.
- If optimization is authorized again, complete an untimed live-decoder cost
  breakdown before selecting each change. Preserve software binary64 semantics;
  exact field-code tables and proved integer bounds may use the full model as
  fallback. No hardware Float primitive is authorized. Never cache corpus
  messages. Every timed generation needs a passing full gate, a committed
  clean tree, a fresh build and binary hash, the frozen ABAB interleaver in both
  modes, all raw samples and Windows power-plan captures. Stop all other
  builds, proofs, tests and profilers while timing.
- Preserve historical evidence and benchmark commits. Build caches, vendor
  checkouts and explicitly ignored large transcripts are not publication
  sources; document their reconstruction rather than force-adding them.
