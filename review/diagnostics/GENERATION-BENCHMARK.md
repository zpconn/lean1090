# Reusable generation benchmark provenance

`run_generation_benchmark.py` prepares and records future genN measurements using the **unchanged frozen** `bench/interleave.py`, `bench/check_worker.py` and oracle harness. It is not a replacement benchmark. Its first live use completed for gen1 after the preparation validation below; `bench/GEN1.md` records the verified results and retained provenance. `capture_benchmark_host.py` is copied byte-for-byte from the reviewed baseline helper; its project-root calculation remains correct at this location.

Before running it, complete the generation's proof/test gate, commit the verified sources, and stop all project tests, builds, profilers and parallel agents. The runner requires a clean tracked **and untracked** working tree and checks the same committed HEAD before rebuilding, before and after each mode, and after final observations. It never commits, publishes, changes a power plan, retries a failed sample, or launches optimization work. Windows interop must permit the frozen interleaver's real `/getactivescheme` queries; the baseline's stricter requirement for queried (rather than manual) captures remains in force.

## Bind the full gate to source bytes

Stage newly added correctness sources **before** generating the before-gate inventory. The helper explicitly rejects relevant untracked files to prevent a new Impl/Proofs module being omitted. It does not stage or commit anything. Editing an already tracked file is allowed at this gate-evidence stage; the final benchmark requires all changes committed and clean.

```sh
python3 review/diagnostics/run_generation_benchmark.py --print-gate-inputs > .cache/genN-gate-inputs-before.json
# Execute the real full gate, retaining the command, exit code, raw log and UTC:
scripts/check_all.sh --full
python3 review/diagnostics/run_generation_benchmark.py --print-gate-inputs > .cache/genN-gate-inputs-after.json
```

The hash helper only reads files and Git metadata. Capture the real gate output in a dedicated log. The gate's recording orchestration should create a JSON record with this schema **from that executed command and its two inventories**:

```json
{
  "schema": 1,
  "status": "passed",
  "command": ["scripts/check_all.sh", "--full"],
  "exit_code": 0,
  "generated_messages": 10000000,
  "started_at": "ACTUAL_TIME_WITH_TIMEZONE",
  "finished_at": "ACTUAL_TIME_WITH_TIMEZONE",
  "gate_log_sha256": "SHA256_OF_RETAINED_FULL_GATE_LOG",
  "input_hashes_before": {"FILE": "HASH"},
  "input_hashes_after": {"FILE": "HASH"}
}
```

Both input maps must be the complete helper output and must exactly match the inputs at benchmark launch. The inventory covers the frozen members; tracked Spec, Model, Impl, Proofs, Tests, Numeric, CLI, Bench, scripts, differential and oracle/unit-port sources; top-level Lean roots; and build/toolchain/lock/trusted-base configuration. It excludes changing prose/evidence artifacts. This permits the gate to run before the required verified commit without silently accepting a gate for older runtime/proof code. The JSON is an honest execution record, not independent proof that a command ran; the runner verifies its command, exit status, input identity and retained-log digest. It will not construct a passing record or infer success from a log suffix.

Separate freshly seeded milestone/final campaigns remain required by the standing rules. This runner does not claim they happened or replace their evidence.

## Invocation after the verified commit

```sh
python3 review/diagnostics/run_generation_benchmark.py \
  --generation N \
  --output .cache/bench-runs/genN-UNIQUE \
  --gate-evidence PATH_TO_ACTUAL_GATE_RECORD.json \
  --gate-log PATH_TO_ACTUAL_FULL_GATE.log \
  --cpu 0 \
  --operator-note 'Actual known background-load observations or constraints'
```

`N` must be at least one. The output must be a new ignored directory below this project's `.cache`; an existing path is rejected. Partial or failed runs are retained with `status: invalid`, and there is no automatic retry. Do not repeat a valid run to select a better sample. After both modes finish, archive the complete output and exact provenance scripts into the appropriate committed results location. Timing happens while all new evidence is ignored, so its creation cannot silently dirty the measured source commit.

## Safeguards retained or strengthened

- The exact approved `spec.lock` contents are read at launch, verified by the frozen lock checker, then required unchanged throughout. The runner does not hardcode the FC006 hash, so later explicitly approved locks work without silently authorizing any change.
- Every linked project native object is discovered from the actual response file. Before rebuilding, generated C/object/trace paths for the **complete committed Lean-source inventory** are invalidated, including modules absent from a stale response file. The executable and response file are rebuilt with `lake --no-cache --rehash -v build lean1090-bench`. There is no fixed count of 21 objects. Every resulting project C/object/trace must correspond to committed source and to a path removed before the rebuild. Unknown object/archive forms fail for review.
- All actual linked project C, object and trace hashes, executable/link response, source hashes and membership additions/removals are retained. Filesystem mtimes are recorded raw. Freshness follows explicit removal/recreation, not a UTC comparison that could fail or mislead when the host clock steps backward.
- Both unchanged interleaver modes run, each with three AB warmup pairs and 21 measured pairs: **48 retained rows per mode**. Validation checks row order, phases, pair numbers, implementation alternation, all message/position counts, positive durations, every row's throughput arithmetic, medians, ratio, binaries, corpus, pinned oracle commit, CPU and power-plan identity. The same power plan is required across both modes.
- Native artifacts remain byte-identical throughout timing. Clean-tree/HEAD/lock checks bracket each mode, not just the complete run.
- The baseline's host/process/load/thermal/governor captures, Cargo/config/flag rejection, fingerprint flags, C compiler/toolchain hashes and actual `-###` effective-driver checks are preserved. The frozen capture's historical module list is supplemented with **every dynamically linked project object**. The real and `--no-default-config` driver expansions must agree; effective compilation must be generic x86-64, `-O3`, `-ffp-contract=off`, with no explicit CPU target-feature overrides.
- UTC timestamps and any clock backsteps are retained unchanged. Command events additionally carry monotonic timestamps; sample ordering remains the recorded integer sequence. Backsteps are reported, never repaired, dropped or used to choose samples.

The wrappers cannot prove host-wide isolation; WSL may hide physical frequency, temperatures and contention. All other project work must be stopped by the operator. The current strict compiler checks are for the reviewed x86_64 machine; a different architecture, compiler, accepted nonempty build configuration or changed local archive form needs an explicit runner review rather than bypassing its checks.

## Preparation validation only

Syntax was parsed without running `main`. `PYTHONDONTWRITEBYTECODE=1 python3 review/diagnostics/test_generation_benchmark.py` passes four pure tests: both existing baseline modes, 21 rejected protocol/identity mutations, eight rejected gate-record mutations, and UTC-backstep retention. These tests read baseline artifacts without modifying them and do not execute a decoder, build, gate or benchmark. The read-only input-inventory helper was also exercised; its then-current inventory contained 169 files. These preparation checks do not claim that a future native rebuild or benchmark has run.
