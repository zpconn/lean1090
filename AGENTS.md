# Project rules

Read `GOAL.md` and the current-status section of `PROGRESS.md` at session start
and after every context reset. Later chat instructions override project files.

## Current authorization

The user requires all commits to use their GitHub identity: `zpconn <zpconn@gmail.com>`. Repository-local Git configuration is set; do not override
it with a Codex identity. All 15 previously pushed commits have been rewritten
without changing their trees, messages or timestamps. Historical IDs below and
in evidence map to the current history through `docs/COMMIT-ATTRIBUTION.md`.

The user accepted generation 10's measured result and explicitly authorized
committing all project work, tidying documentation and presentation, and the
first push to a **private** GitHub repository. This supersedes the earlier
review pause and GOAL.md's public-repository/first-push approval requirement.
Do not ask for that approval again. The subsequent user instruction authorizes
continued optimization toward **2.00× rs1090 in both headline decode and
decode-plus-CPR throughput**, and pushing verified generations to the same
private repository. This latest stretch goal supersedes the 1.50× review stop.
Stop for review when both mode targets are reached. No frozen-file change or trusted primitive is
authorized.

The private repository is `https://github.com/zpconn/lean1090`, default branch
`main`. The verified source/presentation commit `f9a53b6` has been pushed;
`PROGRESS.md` and `tests/evidence/publication/` record final validation.
Publication is complete; the new optimization task starts from commit
`95bc97d75d83190371768950e56ef7cc0825308d` and generation 10's measured code.

Generation 10's verified source commit is
`d51a3040984beb6f0f96b0f4fcf225ba2622a7e0`. Decode reached 1.168948811789×
rs1090; CPR reached 0.790786943138×. Retain the measured artifacts unchanged.
All 23 capstone contracts are proved. The runtime uses zero project-specific
trusted primitives. The current lock has 104 entries and SHA-256
`5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

## Current optimization state

Generation 22 measured **2.203718886895× decode** and **1.715366461888×
decode plus CPR**. Decode has reached 2.00×; CPR has not. Continue until both
mode targets are reached. Measured source:
`74db41344a9d721c600c554b7e2e0f37b65de938`, under the user's identity.
All 96 samples and provenance are in `bench/runs/gen22/`; report:
`bench/GEN22.md`. Signed CPR overhead is 0.620529339102 µs/message for Lean
and 0.033958650367 for rs1090, including noise between mode medians.

Generation 22 reuses the parser's raw word for CRC, with unrestricted parser
and full-decoder refinement proofs. The full fixed and separate fresh 10M
campaigns, independent replay and final archive review passed; all 197
correctness inputs remained unchanged. All 23 capstone contracts are proved.
Verified cleanup reclaimed 11,092,504,576 allocated bytes of duplicate scratch.
The initial build summary undercounted four line-wrapped axiom facts; the
corrected count is 287, with all original evidence retained. The benchmark
archive initially rejected the output directory name. An atomic rename kept
all 48 original files byte-identical; no measurement was repeated.

Measured-result review, artifact-source binding and presentation review passed.
The documentation-status update has a retained supplemental check; no render
or measurement repeated. Artifacts were committed and pushed to private main as
`59685cd27e65fa8250934daf165a0a74a1dc2ace`, under the user’s identity. Both
diagnostic builds are released against that source-equivalent commit, before
choosing generation 23. Both diagnostics and independent reviews passed; verified
cleanup reclaimed 485,339,136 bytes. Generation 23 is now implementing exact
field-code Boolean tables for the five BDS40/50/60 plausibility checks. Runtime
and full-decoder refinement proofs pass. The combined production build passed
with 200 unchanged correctness inputs. Independent source/proof review passed;
full fixed and separate fresh 10M campaigns passed. Fresh seeds are
1,958,132,729 (messages) and 972,156,822 (Comm-B). Native review passed: five
live tables, only CommB changed among 22 sets. Fresh producer passed all
10,476,164 messages with only documented D001 cases and full 32/70/14 coverage;
independent retention and replay passed. Verified fresh cleanup reclaimed
5,359,271,936 bytes of duplicate scratch. Fixed-gate archival and cleanup
reclaimed another 5,733,335,040 bytes. All 200 correctness inputs remain
unchanged. Independent archive/plan review passed, with three checker-only
adaptation failures retained. Commit and timing remain. No speedup is claimed.
No frozen file, Float callback
or trusted primitive change is authorized. Software arithmetic optimizations
must retain exact proved refinement. See PROGRESS.md and
`docs/GEN23-COMMB-VALIDITY.md` for the executed evidence and next steps.

## CPR optimization and reporting constraints

The user requires each future generation report to include CPR overhead for
both implementations in microseconds per message: `1e6 / cpr_msg_s -
1e6 / decode_msg_s`, equivalently the difference of full-corpus median
nanoseconds divided by `172432 * 1000`. Retain signed differences and label
this as a difference between mode medians; do not imply precise isolated CPR
cost or clamp measurement noise. Add historical values in a separate supplement
without rewriting sealed benchmark artifacts.

CPR optimizations must stay inside the proved boundary. Do not move work into
tested-only Float callbacks (including haversine) or add tested-only Float code
without explicit user approval. No hardware Float primitive is authorized.
The benchmark harness and interleaver remain frozen. Generation 19's Lean
CPR overhead is 0.672669156537 µs/message versus rs1090's 0.014589281572;
the combined target needs decode headroom as well as lower CPR overhead.

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
- Complete an untimed live-decoder cost
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
- Keep disk use bounded. After a campaign finishes, archive and verify its
  evidence, then remove raw scratch only when every file has a byte-identical
  retained counterpart. Preserve active runs, unique failures, compressed
  evidence and all provenance. Record cleanup receipts. Remove rebuildable
  diagnostic binaries once their source, commands and hashes are retained;
  retain unique profiler captures. Do not let completed generations accumulate
  redundant scratch or release-checkout builds. Use unfrozen maintenance
  helpers; this rule does not authorize changes to the frozen test suite.
