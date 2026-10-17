# FC006 proposal: whole-decoder benchmark worker

Status: **proposal only, not applied**. The live 102-entry FC005 lock remains unchanged. The exact patch is [FC006-BENCHMARK-WORKER.diff](FC006-BENCHMARK-WORKER.diff), SHA-256 `3e26e7db148c7dc54a649af7cde877d2fc4a01dbed9866d8b5aef4cfeccfb03f`. It proposes the 104-entry lock `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`; 99 existing entries are unchanged. The new worker and validator already exist as reviewable, unfrozen inputs; their exact hashes are added by the patch. No comparative whole-decoder baseline or optimization generation has run.

This proposal supplies the missing Lean worker required by frozen `bench/BENCHMARK.md`. It preserves the contract, Rust worker, interleaving runner, Spec, capstones and differential suites exactly.

## Proposed files

| File | Change |
| --- | --- |
| `Bench/WholeDecoder.lean` | New frozen worker and untimed input/airport/tracking audit modes. |
| `bench/check_worker.py` | New frozen worker validator and supplementary environment capture. |
| `lakefile.toml` | Add `lean1090-bench`, root `Bench.WholeDecoder`, with `-O3` and `-ffp-contract=off`; add it to `defaultTargets`. |
| `scripts/frozen_paths.py` | Include both new sources. |
| `scripts/check_impl_imports.py` | Add the worker to the exact executable-adapter list: it may import Impl but never Proofs, including transitively. Reference-module permissions are unchanged. |
| `spec.lock` | Refresh exactly the three proposed existing-file entries and add the two new sources, producing 104 entries. |

Candidate copies are under `.cache/benchmark-worker-proposal/` and retained for review under `tests/evidence/benchmark-worker-proposal/proposed/` (with their normal relative paths). The exact proposed diff and lock are assembled. Patch dry-run and the original lock checker over an isolated prospective 104-file tree pass; none of these three live frozen files has been edited. `tests/evidence/benchmark-worker-proposal/proposal-verification.json` lists every old/new hash.

Adding the executable to default targets makes the full gate rebuild the timed binary after every implementation change. The frozen interleaver builds Rust but expects an existing Lean executable. The explicit build command below also prevents a stale Lean binary at measurement time.

## Work and clock boundaries

The headline `runDecodeOnce` preallocates `Array Spec.Message` with capacity 172432 before `IO.monoNanosNow`. Its loop calls exactly `Lean1090.Impl.decode input.bytes`, aborts on any rejected row, and directly appends the complete returned message. There is no per-message wrapper, field projection, CPR work, cached result or checksum inside this interval. The second monotonic clock occurs after the last append. A noinline observable consumer receives the complete array afterwards; consumption, destruction and response reporting happen outside timing.

The separate `runCPROnce` retains each complete message and optional position, with a fresh empty `StreamState`, no receiver reference and an always-false update callback. It calls the shared `advance` immediately after each decode. That helper routes every decoded DF17/18—including non-position ADS-B bookkeeping—through the actual `Impl.CPR.Policy.streamStep`, using `Impl.CPR.Policy.numericalGeography`. The full 6903-entry pinned airport database is loaded in source order before readiness. No optional Comm-B evidence or receiver-enrichment operation runs.

Both paths prepare bytes and timestamps before readiness, preserve every corpus row in order, strip exactly 18 Beast-prefix characters and decode each message afresh on every requested run. Decimal timestamps and airport coordinates are rounded once to their exact binary64 rational values before timing. The parent frozen runner verifies the pinned oracle commit and clean tracked files, including the airport source.

Protocol: `--worker-decode CORPUS.csv` or `--worker-cpr CORPUS.csv` prints `ready 172432`. Each `run` performs one fresh interval and prints `<nanoseconds> <positions>` after consumption and destruction. `quit` exits. Unknown commands and invalid input/decoder failures abort. Neither worker performs private warmups. The frozen `bench/interleave.py` continues to control three AB warmup pairs and 21 measured AB pairs, shared affinity and Windows power-plan captures.

## Executed validation

The candidate builds without touching the live lakefile:

```bash
lake -f .cache/benchmark-worker-proposal/lakefile.toml build lean1090-bench
python3 bench/check_worker.py \
  --lakefile .cache/benchmark-worker-proposal/lakefile.toml \
  --output tests/evidence/benchmark-worker-proposal/validation
PYTHONDONTWRITEBYTECODE=1 python3 .cache/benchmark-worker-proposal/check_impl_imports.py
python3 scripts/check_lock.py
```

The retained configuration was also built successfully with:

```bash
lake -f tests/evidence/benchmark-worker-proposal/proposed/lakefile.toml build lean1090-bench
```

The complete worker validator passed:

- All **172432 prepared messages** match the original bytes and native binary64 timestamps.
- All **6903 airport records** match coordinate bit patterns and source order. An independently built Rust preparation oracle also checks the actual pinned `AIRPORTS` constant and timestamp parsing; its source, lock, commands and outputs are retained.
- The worker's actual `trackingReport`/`advance`/`streamStep` route matches a fresh pinned tracking oracle on every corpus message: **50385 routed reports**, **11347 resolved positions**, **161085 unresolved results**, zero mismatches. All resolved coordinates are bit-identical by observation; acceptance remains **1e-9 degrees**, not bit identity. Final reference and all **29 aircraft states** match.
- Both worker modes complete two requested runs and quit cleanly, with fresh-state counts. Unknown commands and a correctly sized corpus containing a rejected message fail. Empty input, bad hex, short Beast prefixes and nonfinite timestamps fail before readiness.
- Comparator controls accept a non-bit-identical 5e-10-degree change and reject a 2e-9-degree change or a missing position.

All diagnostic interval responses are retained solely as protocol checks. They are not an ABAB baseline and support no speed claim. The earlier wrapper-based draft and its validation are retained in `validation-v1-wrapper/`; the final headline uses a direct message array.

Final source hashes:

- `Bench/WholeDecoder.lean`: `ea0b8f3a94dfc801bbf0a8ce9091617f2a3eae4e122752e56de3caa5de40592b`
- `bench/check_worker.py`: `f1e569eb424cc6479248b904b576d4716c2d507d264466c53588535eac29ea37`

Evidence: `tests/evidence/benchmark-worker-proposal/validation/summary.json`, compressed complete preparation/tracking outputs, all mismatch records, native generated C, compile trace and linker response; independent preparation sources are in `fresh-rust-preparation/`. The independent C review verifies preallocation before the first clock, the exact live decode call, direct message append, the second clock before the consumer, and destruction afterwards. Compilation is `-O3 -ffp-contract=off`, with no CPU-specific flags and no Spec/Mathlib code in the native link.

## Baseline after approval and required gate completion

The primary agent will apply an approved exact patch only after recording FC006 in `docs/FROZEN-CHANGES.md`, preserve before/after lock snapshots, and rerun guards and the integrated checks. Then, with all build/test/proof work stopped, the baseline uses the unchanged interleaver:

```bash
lake build lean1090-bench
python3 bench/check_worker.py --capture-environment-only --output bench/runs/baseline-environment-before
python3 bench/interleave.py --mode decode --lean-worker .lake/build/bin/lean1090-bench --output bench/runs/baseline-decode
python3 bench/interleave.py --mode cpr --lean-worker .lake/build/bin/lean1090-bench --output bench/runs/baseline-cpr
python3 bench/check_worker.py --capture-environment-only --output bench/runs/baseline-environment-after
```

Before timing, also record Cargo configuration/effective Rust flags and material thermal/background-load observations, as required by the frozen contract. The supplementary captures record the C compiler/version, effective generated-C flags and trace hashes, worker binary/generated-C/link fingerprints, affinity and Linux CPU governor availability. The frozen interleaver records the Windows power-plan name/GUID before and after each mode, CPU model, system/toolchains, all 48 chronological samples, medians and ratio. Missing WSL interop requires the contract's dated manual capture, not an assumed power setting. These commands are proposed reproduction commands; they have not been run as a baseline.
