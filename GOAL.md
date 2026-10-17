# lean1090: a formally verified, faster replacement for rs1090, in Lean 4

**Mission.** Build `lean1090`, a pure Lean 4 library and CLI that decodes Mode S / ADS-B messages from raw bytes with the same scope and output as rs1090's decoder. It must come with machine-checked theorems that guarantee correctness for every possible input. Then optimize it in an agentic loop until it is at least 10% faster than rs1090 on a single core, keeping every theorem proved and every test passing at every commit. This is a long, multi-session job: don't stop until it is fully and honestly done, except at the checkpoints below where you must wait for me. If a later instruction from me in chat conflicts with this file, the chat wins.

Before designing anything, study github.com/kim-em/lean-zip, a verified DEFLATE codec in Lean that beat Rust's miniz_oxide this way. Look at its Spec/Native split, its conformance suite against zlib, and the agent plans and progress logs preserved at its `pre-split` tag.

## 0. Ground rules (re-read these after every context reset)

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

## 1. Setup

- **Lean:** the latest stable toolchain with a matching Mathlib release; pin both. Mathlib is fine for proofs, but keep hot runtime paths free of Mathlib definitions.
- **rs1090:** clone github.com/xoolive/rs1090 and pin a commit (for example `685dfaa`, from 2026-10-13); record it in `SCOPE.md`. Build it with its shipped `dist` profile settings (full LTO, overflow checks as shipped) and default features, including `bds-infer`.
- **Other tools:** Rust for the oracle harness, and Python with matplotlib for plots. pyModeS is optional, for context in the chart.

## 2. Scope

In scope: everything rs1090's `Message::from_bytes` decodes from a 7- or 14-byte Mode S message, plus CPR position resolution.

- **Mode S formats** DF 0, 4, 5, 11, 16, 17, 18, 20 and 21: every field rs1090 reports, including parity handling (PI check, AP address recovery, DF11 interrogator ID).
- **ADS-B (DF17/18):** every type code and subtype rs1090 decodes.
- **Comm-B (DF20/21 MB field):** every BDS register rs1090 decodes, plus its default `bds-infer` strategy for guessing the register, reproduced exactly.
- **CPR:** local and global decoding, airborne and surface, with rs1090's pairing policy (time windows, reference handling).

Out of scope: FLARM, I/O sources (RTL-SDR, Beast, SeRo, SSH), demodulation, aircraft and tail-number databases, and JSON serving.

Write `SCOPE.md` listing every message type, field, unit and rounding rule, and every rs1090 policy you will mirror. For Float outputs (speeds, tracks, positions):
- compute them with rs1090's formula, from exact integer or rational quantities that you prove correct;
- the Float step itself is tested, not proved, and documented as such.

## 3. Specification and theorem statements, then CHECKPOINT 1

Write `Spec/`: a clear, slow reference decoder, plus an independent reference encoder, both taken from the standard.

Write `Capstones.lean`: statements only. Placeholder proofs are allowed at this stage and no other. Each capstone must say something on its own, not merely "fast code equals slow code". At minimum:

1. **Refinement.** `Impl.decode m = Spec.decode m` for every input. This is the ratchet that makes optimization safe.
2. **Round-trips.** For every valid field assignment `f` of every in-scope message type, `Spec.decode (Spec.encode f) = some f`. Also, if `Spec.decode m = some f`, then `Spec.encode f` reproduces every defined bit of `m`.
3. **Parity.**
   - CRC-24 equals the remainder of polynomial division over GF(2) by the Mode S generator 0x1FFF409.
   - It is linear over XOR.
   - In 56- and 112-bit messages, every single-bit error has a distinct nonzero syndrome.
4. **Altitude.** The Gillham and 25 ft/100 ft encodings round-trip for every representable altitude, and invalid codes are rejected.
5. **CPR.**
   - Local decoding against a reference within the allowed distance returns the encoded position to within encoding resolution, for every position and parity.
   - Global decoding of an even/odd pair returns it too, when the pair is within the allowed separation and in the same latitude zone.
   - Pairs that straddle a zone boundary are rejected.
   - The latitude-zone (NL) table is proved against its defining formula using Mathlib's `Real.arccos`. One way: certified rational bounds on each transition latitude, plus a finite check that no decodable latitude falls inside a bound.
6. **Comm-B inference.**
   - The reported register(s) are exactly those whose validity predicates hold. Transcribe those predicates in `Spec/CommB.lean` from rs1090's rules; this is the one place rs1090 is the spec, so say so.
   - Each register's field decoding round-trips as in (2).

Also write `THEOREMS.md`. For each capstone, give it in plain English, show the Lean statement, and say what bug it rules out.

Then **stop and wait for my approval** of SCOPE.md, THEOREMS.md, `Spec/`, `Capstones.lean` and `bench/BENCHMARK.md`. After I approve, write `spec.lock` and continue autonomously.

## 4. Implementation, proofs and tests

- **Implementation.** `Impl/` is the decoder, total and pure. Prove every capstone with zero placeholders. Optimization (section 6) may start once capstone 1 is proved; the Spec-level theorems don't depend on `Impl` and can be finished in parallel.
- **Unit tests.** Port every rs1090 test vector for in-scope decoding into a Lean test suite. They live in:
  - the `#[cfg(test)]` modules under `crates/rs1090/src/decode/`
  - `python/tests/`
  - `crates/rs1090-wasm/tests/`
- **Differential suite.**
  - A small Rust harness against the pinned rs1090 emits one canonical JSON line per message; lean1090 emits the same format.
  - Diff the two over `crates/rs1090/data/long_flight.csv`. Strip the 18-hex-character Beast prefix from each message, as rs1090's bench does.
  - Also diff at least 10M generated messages: `Spec.encode` with random fields and valid parity, plus randomly corrupted messages.
  - Positions may differ from rs1090 by at most 1e-9 degrees. Every other field must match exactly.
- **Disagreements.** Classify each one as:
  - a lean1090 bug: fix it;
  - a spec issue: stop and ask me;
  - an rs1090 bug: keep the standard's answer and log it in `DISCREPANCIES.md`, with the message, both outputs and the clause of the standard.

## 5. Benchmark (`bench/BENCHMARK.md`, frozen at checkpoint 1)

- **Workload.** Decode all 172,432 messages in `long_flight.csv` from bytes into a preallocated vector or array of decoded messages. Do the hex conversion before timing starts. This is the same work as the `Message::from_bytes` loop in rs1090's `benches/long_flight.rs`.
- **Conditions.**
  - single thread on both sides (no rayon), pinned to one core where the OS allows, on the same machine
  - release builds: rs1090's `dist` settings, Lean at `-O3`
  - no CPU-specific flags on either side
  - 3 warmup runs, then the median of 21 runs, reported in messages per second
- **No caching or memoization across messages.** Each message is decoded from scratch; CPR pairing state is the only cross-message state. Also report a second benchmark that includes CPR position resolution; it is not the headline number.
- **Context.** If feasible, also run pyModeS (pure Python and Cython) via rs1090's `python/examples/benchmark.py`.

## 6. Optimization loop

Each optimization is one generation:
1. Profile with `perf`, and read Lean's generated C (`lean -c`).
2. Make one change.
3. Run the gate and the benchmark.
4. Commit as `genN: <change>`.
5. Append a row to `bench/results.csv`: commit, generation, lean1090 msg/s, rs1090 msg/s, note.

Continue until lean1090's median is at least 1.10× rs1090's, then keep going while gains are still coming.

Stretch goals, only after that:
- a multi-threaded version, measured against rs1090's rayon mode;
- a comparison against the decoder in dump1090-fa or readsb, separated from its tracking code.

Performance notes from earlier measurements:
- **Inlining.** Lean's compiler doesn't inline small helpers by default. Adding `@[inline]` to hot helpers cut one bit-twiddling benchmark from 25.0 s to 16.6 s. Use `@[specialize]` where it applies too.
- **Data layout.** Lean is weak at allocation-heavy recursive data, because each constructor is a reference-counted heap object. It is strong at arrays updated in place while nothing else references them.
  - Represent a message as fixed-width words (two `UInt64` for 112 bits).
  - Avoid `Nat` in hot paths.
  - Keep the CPR state table referenced from one place only.
- **Bounds checks.** Proving an index in bounds gives an unchecked array access; use that instead of `get!`.

## 7. Deliverables

Publish a public GitHub repo, `lean1090`. **Ask me before the first push.** It contains:
- the code;
- a README with:
  - the capstone statements verbatim
  - the trusted computing base, also listed in `TRUSTED.md`: the Lean kernel, compiler and runtime, the C compiler, and any extern primitives
  - the scope and the discrepancy list
  - the benchmark methodology and results
- an animated GIF of throughput across generations, with one frame per generation, against rs1090 single-core (and pyModeS).

## 8. Done means: all verified by commands in the final session

- `scripts/check_all.sh` passes on a clean clone.
- Every capstone shows only the three standard axioms.
- `spec.lock` matches the approved hashes.
- All ported unit tests pass.
- The differential suite agrees on the full corpus and on at least 10M generated messages, apart from entries in `DISCREPANCIES.md`, each justified by the standard.
- On the single-core benchmark, lean1090's median is at least 1.10× rs1090's, reproducible with one command.
- The README, `results.csv` and the GIF are committed, and the repo is pushed after my OK.
