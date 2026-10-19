# Building, testing and reproducing results

Run commands from the repository root. The recorded platform is x86-64 Linux
under WSL2; the oracle compatibility view includes the pinned x86-64 behavior.
Other platforms are not claimed to reproduce those results.

## Dependencies

Install Git, Bash, Python 3.11 or newer, Lean's `elan` manager and a Rust
installation providing `cargo` and `rustc`. Put `lean` and `lake` on `PATH`.
The checked-in `lean-toolchain` selects Lean **4.35.0**; `lake-manifest.json`
locks Mathlib and its dependencies. Recorded runs used Rust **1.93.1** and
Lean's bundled Clang **23.1.0**. No system packages are installed by this project.

```sh
elan toolchain install leanprover/lean4:v4.35.0
python3 review/packaging/bootstrap.py --prepare
lake build lean1090
```

The bootstrap helper:

- Retrieves the pinned rs1090 checkout into ignored `vendor/rs1090`, at
  `685dfaa34c5ab186c691bca3cfe2a22e12517d30`, and checks corpus/airport hashes.
- Retrieves the locked Mathlib cache with `lake exe cache get`. Download files
  stay in `.cache/mathlib`; compiled dependencies live under `.lake/`.
- Runs `cargo fetch --locked` for the five oracle manifests, with
  `CARGO_HOME` set to the project's `.cache/cargo`. This is necessary because
  the frozen test harnesses subsequently build Rust with `--offline`.
- Refuses an existing dirty or differently pinned rs1090 checkout. It never
  changes source locks, installs system tools, runs the full gate or benchmarks.

Network access is needed on the first preparation. Do not run `lake update` or
`cargo update`: use the checked-in dependency manifests and lockfiles.
Several gigabytes of dependency/build storage are normal, and the full
10-million-message campaign creates additional multi-gigabyte transcripts.

For library/CLI work without the Rust oracle:

```sh
python3 review/packaging/bootstrap.py --prepare --lean-only
lake build lean1090
```

`python3 review/packaging/bootstrap.py --check` is a read-only readiness check.
It verifies dependency checkout pins and the local Cargo package cache without
network access, compiling Lean or invoking a decoder. It checks **all** locked
registry packages, including other platforms; an existing Linux-only cache may
therefore require `--prepare` even if a previous Linux test run passed.
The check does not substitute for compiling the project.

Python's standard library suffices for the CLI orchestration and correctness
gate. `requirements-tools.txt` is optional tooling for plots and source-PDF
inspection, not a decoder dependency:

```sh
python3 -m venv .cache/venv
.cache/venv/bin/python -m pip install -r requirements-tools.txt
```

## CLI and library

The CLI accepts hexadecimal messages as arguments or one message per stdin
line and emits one compact JSON value per input:

```sh
.lake/build/bin/lean1090 8D4840D6202CC371C32CE0576098
printf '%s\n' 8D4840D6202CC371C32CE0576098 | .lake/build/bin/lean1090
.lake/build/bin/lean1090 --oracle-view 8D4840D6202CC371C32CE0576098
.lake/build/bin/lean1090 --diagnostic 8D40621D58C382D690C8AC2863A7
```

The first example reports callsign `KLM1023`. Default output uses the standard
view. `--oracle-view` applies the documented compatibility adjustments.
`--diagnostic` reports both views, CRC, consumed bytes and the unconsumed suffix.
The diagnostic path uses prefix decoding; ordinary mode requires exactly one
complete frame. Invalid hexadecimal produces an error object; a rejected
well-formed byte sequence produces JSON `null`. CLI decoding errors are reported
in JSON, not by a failing process exit code. There is currently no `--help` flag.

Lean applications can `import Impl` and call:

```lean
Lean1090.Impl.decode       -- List UInt8 → Option Lean1090.Spec.Message
Lean1090.Impl.decodePrefix -- List UInt8 → Option (Lean1090.Spec.Message × List UInt8)
```

The `Spec` namespace on shared result types comes from `Model/Types.lean`;
runtime modules do not import reference algorithms from `Spec/`. Import
`Proofs.Decoder` separately when using the refinement theorems.

`Impl.decodePositions` consumes timestamped reports, explicit geography,
reference state and an update callback. It is a library API, not a CLI streaming
option. See [the runtime policy](../Impl/CPRPolicy.lean),
[numerical geography](../Impl/CPRFloat.lean) and
[the frozen tracking adapter](../Tests/Tracking.lean) for report construction.
Global surface CPR is outside the implemented scope.

## Correctness gate

```sh
scripts/check_all.sh --quick
scripts/check_all.sh --full
```

Both commands check the frozen lock first, build proofs, audit axioms and
imports, run upstream unit vectors, and run every mandatory differential
component. Quick mode includes 100,000 generated whole messages; full mode uses
10,000,000. Both also include the corpus, structured Comm-B cases, altitude,
reserved-velocity, DTE, numeric, CPR and stream-tracking strata. A component-only
command is not a complete gate pass. Full milestone validation additionally
uses newly recorded message and Comm-B seeds; the fixed gate alone does not
satisfy that additional requirement.

The frozen runners write their current outputs to generic `tests/evidence/`
directories. Running them in a fresh disposable clone is the easiest way to
preserve the versioned historical results. Do not run two gates concurrently
in the same checkout. In particular, keep `review/upstream-units/` restricted
to its seven locked scripts; generated files and `__pycache__` there fail the
membership guard.

The published generation records distinguish standard-view disagreements from
oracle compatibility exceptions. Consult [DISCREPANCIES.md](../DISCREPANCIES.md)
before interpreting a difference stream. Historical compressed raw transcripts
may be omitted from Git; seeds, commands, hashes, summaries and comparison
results are retained. Their absence in a new clone is not a fresh test pass.

## Verify a clean committed checkout

After dependency preparation, a clean Git tree can verify its committed sources
in a separate local clone:

```sh
python3 -B review/packaging/check_clean_clone.py \
  --commit "$(git rev-parse HEAD)" \
  --checkout .cache/release-checkout-repeat \
  --output tests/evidence/publication/clean-clone-repeat
```

Both destination paths must be new. The helper reuses pinned external Lean and
Cargo dependency caches, but starts with no project Lean objects or Rust target
artifacts. It runs the complete quick gate, records the clean starting commit,
and verifies that every correctness input stays unchanged. Its evidence output
makes the original checkout dirty afterward. This checks local reproducibility;
it does not replace the full and fresh-seed 10M campaigns or test a network
installation from scratch.

## Benchmark reproduction

The source of truth is [the frozen contract](../bench/BENCHMARK.md).
Headline timing measures complete `Impl.decode` results on 172,432 prepared
messages. The CPR result is separate. Every mode uses three alternating warmup
pairs and 21 alternating measured pairs on one logical CPU. Run no tests,
builds, profilers or other project work during the measured intervals.

For a direct repeat of the protocol after building the worker:

```sh
lake build lean1090-bench
python3 bench/interleave.py --mode decode --cpu 0 --output .cache/reproduce-decode
python3 bench/interleave.py --mode cpr --cpu 0 --output .cache/reproduce-cpr
```

Choose an allowed logical CPU if CPU 0 is unavailable and use the same CPU in
both commands. Output directories must be new. The frozen runner builds the
Rust oracle before timing, but expects the Lean executable to exist. Under
WSL2 it queries the Windows power plan before and after each mode. If interop is
unavailable, use the runner's `--windows-power-plan-file` option with a dated
manual JSON capture containing `active_scheme`, `captured_at`, `source` and
`reason`; a changed power plan invalidates the run.

These direct commands retain samples and basic metadata. The released result
also uses the stricter provenance runner: a clean committed tree, passed full
gate evidence matching all current correctness inputs, explicit native-artifact
invalidation and rebuilding, compiler/configuration inspection, and before/after
host observations. For the published checkout, whose runtime matches generation 10:

```sh
python3 review/diagnostics/run_generation_benchmark.py \
  --generation 10 \
  --output .cache/reproduce-gen10 \
  --gate-evidence tests/evidence/publication/gate-evidence.json \
  --gate-log tests/evidence/publication/gate-full.log \
  --cpu 0 \
  --operator-note 'Project builds, tests and profiling are stopped during timing.'
```

This command verifies the retained gate's input hashes against the current
checkout; it does not claim that historical tests ran on the new machine. Run
your own full gate separately for that claim, and supply its before/after input
record and log when validating changed sources. A changed lock or correctness
input makes the historical evidence unusable. The strict runner deliberately
rejects compiler environment overrides, Cargo configuration files and effective
CPU-specific flags. Its effective-driver checks target the recorded x86-64
Clang setup. The plain interleaver is more portable, but does not provide all of
these additional checks.

Do not compare UTC timestamps to calculate throughput: the workers use monotonic
clocks. Raw clock disagreements and unavailable WSL host thermal/frequency
information remain material limitations, documented in
[the generation-10 result](../bench/GEN10.md). A new measurement is separate
evidence; it must not overwrite or silently replace a historical run.
