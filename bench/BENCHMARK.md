# Frozen benchmark contract — amended checkpoint 1

The amended approval freezes this file, the complete rs1090-side harness (`bench/oracle/Cargo.toml`, `bench/oracle/Cargo.lock`, `bench/oracle/src/main.rs`, `bench/run_oracle.sh`), and the interleaving runner `bench/interleave.py`. The final theorem manifest `scripts/Final.lean`, shared `Model/` types, dependency audits, and BDS50 oracle harness are also in the inventory in `scripts/frozen_paths.py`. The user reviewed the amendment diff and authorized the final dependency fixes followed by `spec.lock`. The SHA256 inventory includes the guards themselves, and the full gate checks the lock first. The explicitly authorized BDS50 pilot below is a measured component baseline, not the whole-decoder headline.

## Inputs and oracle

Oracle commit: `685dfaa34c5ab186c691bca3cfe2a22e12517d30` in `vendor/rs1090`. Build default features, including `bds-infer`. The pinned corpus is `crates/rs1090/data/long_flight.csv`: **172432 messages**, **10186581 bytes**, SHA256 **`3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505`**. There is no header. Keep every row in file order, including the first; do not deduplicate, sort, filter, repair or replace messages.

Before timing, parse each row's timestamp, strip exactly18 hexadecimal characters from its Beast frame, and convert the remaining14 or28 hexadecimal characters to7 or14 bytes. The corpus has71639 short and100793 long messages. DF distribution:0=21393,4=8841,5=2949,11=38456,16=2694,17=31395,18=18990,20=29460,21=18254.

The logical work is the `Message::from_bytes((&bytes,0))` decode-and-store loop from the pinned `benches/long_flight.rs`. That upstream file's complete-flight function uses rayon and performs CSV/hex work inside its benchmark; this contract intentionally follows GOAL.md's explicit single-core, bytes-prepared conditions instead. Neither upstream's1000-message linear microbenchmark nor its parallel wall time is the comparison denominator.

## Timed work

Headline mode `decode`: the timed Lean call is exactly `Lean1090.Impl.decode`, the function bound in `scripts/Final.lean` by `Capstones.Refinement Lean1090.Impl.decode`. This includes every projection into the complete `Spec.Message` result model. Native decoding alone is not the headline; if measured, label it separately and never use it to claim the 1.10× target. `Impl/` may import shared data types from `Model/`, but may not import `Spec/` directly or transitively; the gate checks the compiled module graph. Any representation projection belongs to `Impl.decode` and cannot call reference decoders or substitute recomputed reference answers.

For each run allocate an empty output vector/array with capacity172432 **before** starting the timer. Start a monotonic timer; decode every input from scratch and append the complete decoded message to that output. Stop after the last append. Keep every full result alive until the timer stops; pass the completed container to an optimization barrier/observable consumer. Consume and destroy results outside the timed interval. Retaining only a checksum, an extracted field, or success counts is not equivalent work.

Input reading/parsing, hex conversion, output-capacity allocation, output destruction, reporting, plotting and executable startup are excluded on both sides. Internal decoder allocations and appends are included. A decoder error aborts the run; never drop bad rows to obtain a timing. Rust and Lean must use the same prepared bytes and storage lifetime convention. Any discrepancy exception changes correctness comparison only; it does not remove a message from the timed workload.

There is no caching or memoization across messages. Reusing immutable format tables is permitted; reusing decoded results, oracle answers, known-corruption labels, per-input branches or precomputed fields is forbidden. No warmed cross-message state may survive between runs.

Second mode `cpr`: include the same decode-and-store work and call the pinned `decode_position` immediately for each successfully decoded DF17 or DF18, in corpus order, using its timestamp and announced address. Start each run with an empty aircraft-state map, no reference, and no reference-update callback. State construction starts before the clock; population/lookup/allocation and all position work are timed. All decoded messages, including those without coordinates, remain in the output. The pinned routine's pairing/time/speed/airport policies described in `SCOPE.md` apply. Do not call optional Comm-B sanitization/evidence processors or extra receiver/aircraft enrichment. CPR pairing state is the only permitted state across messages in this mode. The secondary number cannot substitute for the headline.

The user clarified that global surface CPR is excluded. Surface local decoding remains in the second mode where the pinned state policy has a usable reference. A first surface decode may depend on the pinned airport database; no external airport service or dataset substitution is allowed.

## Build and machine conditions

- Run both executables on the same machine, one OS thread doing the work, on the same logical CPU. No rayon calls. The default-feature rs1090 dependency includes rayon, but neither benchmark path invokes it.
- Pin affinity where supported. `bench/run_oracle.sh` selects the lowest allowed CPU, or the allowed CPU named by `BENCH_CPU`. The future Lean runner must use the identical CPU. Record CPU model, logical CPU, OS/kernel, architecture, CPU governor/power mode, compiler versions and effective flags with results. Under WSL2, also record the Windows active power-plan name and GUID from `powercfg.exe /getactivescheme` before and after timing. If interop is unavailable, require an explicit dated capture with its source and reason; do not silently omit the host setting. A changed power plan invalidates the run. Record affinity unavailability rather than pretend to pin.
- Oracle `dist` reproduces upstream `[profile.release] lto="thin", overflow-checks=true`, then `[profile.dist] inherits="release", lto=true, strip=true`. The harness's locked dependencies were checked against upstream's `Cargo.lock`; no dependency version differs. `default-features=true` is explicit for rs1090. Rust's normal release opt-level3 is inherited.
- Lean's generated C must be compiled at `-O3`, with the pinned Lean runtime/compiler. No Mathlib runtime work in the hot path. No CPU-specific feature/architecture flags on either side. The shell clears `RUSTFLAGS` and `CARGO_ENCODED_RUSTFLAGS`; recorded build configuration must also rule out hidden CPU-specific Cargo/C compiler configuration.
- Do not run the two benchmarks concurrently or while builds/tests/profilers compete for the core. No affinity, frequency or compiler asymmetry is allowed. Record material thermal/background-load observations; repeat only for a documented invalid run, not to select a favorable sample.

## Runs and statistic

A single orchestrator keeps both workers alive with their inputs already prepared. It performs exactly three AB warmup pairs, then21 measured AB pairs, always A=rs1090 and B=lean1090: ABABAB, followed by ABAB… for42 measured runs. No two runs overlap, and neither worker performs additional private warmups. Independent blocks of21 Rust runs followed by21 Lean runs are not valid headline measurements. Report every warmup and measured duration, its chronological order, and throughput. For each run, `messages_per_second=172432/seconds`. The headline is the median of21 throughputs, equivalently172432 divided by the11th ascending duration. Compute the ratio `Lean median / rs1090 median` using unrounded underlying measurements. Success requires ratio≥1.10; do not confuse “10% less time” with this throughput target.

Results are separate for decode and decode+CPR. Each generation records commit, generation number, Lean msg/s, rs1090 msg/s and note in `bench/results.csv`; retain raw samples plus environment/build metadata. No whole-decoder comparison result is claimed at this amendment review. The BDS50 component result is recorded separately below. Subsequent runs must use both frozen protocol and the full gate. Final reproducibility from a clean clone uses `bench/interleave.py` for both executables, with builds and the full correctness gate completed before timing. It checks the locked corpus, uses one shared affinity, records all48 runs, and computes the two medians from the21 measured samples per side.

Optional context only: pyModeS pure Python and Cython through the pinned `python/examples/benchmark.py`, if available. Label their different preparation/serialization/workload boundaries; they never determine the≥1.10 target.

## Commands and completed validation

From the project root:

```bash
# Validate corpus, build frozen oracle, decode both paths once; no speed claim.
bench/run_oracle.sh --check

# After the complete implementation and gate exist, measure the pair.
BENCH_CPU=0 python3 bench/interleave.py --mode decode \
  --lean-worker .lake/build/bin/lean1090-bench --output bench/runs/decode
BENCH_CPU=0 python3 bench/interleave.py --mode cpr \
  --lean-worker .lake/build/bin/lean1090-bench --output bench/runs/cpr

# Reproduce format-rejection observations; no timing.
bench/run_oracle.sh --probe-formats

# Reproduce the exact87-degree CPR boundary disagreement; no timing.
bench/run_oracle.sh --probe-cpr
```

Replace CPU0 with a CPU in the process's allowed affinity set (or omit BENCH_CPU for the default selection). For the direct build check already executed:

```bash
CARGO_HOME=$PWD/.cache/cargo CARGO_TARGET_DIR=$PWD/.cache/rs1090-target \
  cargo build --locked --manifest-path vendor/rs1090/Cargo.toml -p rs1090 --profile dist
CARGO_HOME=$PWD/.cache/cargo CARGO_TARGET_DIR=$PWD/.cache/rs1090-target \
  cargo run --offline --locked --manifest-path bench/oracle/Cargo.toml --profile dist \
  -- --check vendor/rs1090/crates/rs1090/data/long_flight.csv
```

Observed second-command output: `check mode=decode messages=172432 positions=0 ok`; `check mode=cpr messages=172432 positions=11347 ok`. This checks the pinned oracle and harness only, not Lean conformance. The whole-decoder comparative benchmark awaits the proved Lean worker; absence of that worker is an error, not an oracle-only headline result. The frozen Rust persistent worker and the orchestrator protocol have been checked independently.

The separate `--probe-cpr` mode decodes two CRC-valid DF17 fixtures and invokes the public `airborne_position` function to reproduce D009; output is retained in `bench/evidence/cpr-oracle.txt`. This mode is outside all timing paths and uses the same pinned default-feature `dist` build.


## Persistent worker interface and proof binding

`--worker-decode CORPUS.csv` and `--worker-cpr CORPUS.csv` prepare inputs once and print `ready 172432`. Each stdin `run` invokes exactly one fresh decode/store interval and responds with `<nanoseconds> <resolved-positions>` after output destruction; `quit` ends the worker. The same protocol applies to the future Lean executable. Worker startup, pipe traffic and metadata collection are outside both timers. A failed decode or malformed worker response aborts the comparison.

The final manifest has an explicit theorem type for every required capstone and prints the axioms of those proving constants. It is an import-free frozen declaration fragment; the frozen checker compiles its exact bytes after integration imports in a temporary module, so frozen reference modules never import Impl or Proofs. It may fail until section4 supplies the complete implementation and proofs. The full gate cannot pass merely because proposition definitions compile. The headline worker must call `Impl.decode` inside its per-message timed loop and retain the full returned model, including all semantic report fields. Every optimization must preserve this binding and storage convention.

## Required BDS50 inference pilot

Before the remaining implementation, benchmark the complete proof-visible `Impl.BDS50.decode` against the pinned Rust BDS50 inference path on **all47714 DF20/21 MB fields** from this corpus (DF20:29460, DF21:18254). Filter only by DF; do not select accepted or scored candidates. Extraction of the seven MB bytes occurs before timing on both sides. Both sides perform status/hard checks, complete density and penalty scoring, the inclusive score≥−3 decision, and full result construction. Lean's complete result includes raw codes, all five optional quantities and the exact binary64 score; all are included in timing and retained. The Rust side uses `TrackAndTurnReport::from_bytes`, `density_score`, and `penalty`, with default `bds-infer`, and stores its complete report and score. No other register's cost is charged to this component comparison.

Use the same core, build flags, three AB warmup pairs, and21 AB measured pairs. `python3 scripts/bench_bds50.py --generated .cache/bds50/generated.csv --output bench/evidence/bds50-new-run.json` reproduces the pilot after the build/generator commands in `docs/BDS50-PILOT.md`. This pilot has an all-input kernel proof and checks the corpus plus4504 structured generated payloads, including an attainable score exactly−3 and adjacent passing/rejected values. Every reported field and exact score matched Rust. Retained samples and environment metadata are in `bench/evidence/bds50-pilot-quiet.json`.

Observed medians on2026-10-16: Lean **138987 msg/s**, rs1090 **575168 msg/s**, ratio **0.2416×** (approximately4.14× slower). Windows power plan: **Ultimate Performance**, GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. This designated confirmation ran after parallel builds/tests/generation stopped; the earlier diagnostic0.2462× run, whose isolation from parallel validation was not established, remains in `bench/evidence/bds50-pilot.json`. This result measures the cost of the initial exact binary64 runtime; it is not a whole-message result or the10% target. Future component measurements must retain this baseline and distinguish code generations.

## Comm-B generation required by the differential gate

Uniform random MB words remain useful rejection tests, but cannot substitute for accepted and near-boundary coverage. `scripts/FuzzCommB.lean` builds all14 register layouts through `Spec.encodeBDS` from named field assignments, with seeded random values and inside/at/outside cases for every plausibility bound, status consistency and sentinel. Scored registers40/44/45/50/60 require hard-valid samples on both sides of−3, neighboring representable field codes, and exact equality fixtures where attained. BDS50's exact−3 fixture and both adjacent rate codes are mandatory. Keep rejected generated inputs in the comparison. Record seeds, field assignments, coverage tags, exact scores and acceptance; do not call a nearby value an exact boundary. This structured stratum is required alongside the full corpus and100k/10M generated messages, as detailed in `docs/FUZZING.md`.
