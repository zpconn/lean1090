# Whole-decoder baseline — FC006

Baseline completed on 2026-10-18. This is generation 0, before any optimization. The headline is 0.166318193807× rs1090 throughput (about 6.013× slower); the 1.10× target is not met. Work is stopped for user review before gen1.

| Mode | Lean median ms | rs1090 median ms | Lean median msg/s | rs1090 median msg/s | Lean / rs1090 throughput |
| --- | ---: | ---: | ---: | ---: | ---: |
| Decode (headline) | 5301.668259 | 881.763889 | 32524.10214601 | 195553.48336566 | 0.166318193807× |
| Decode + CPR | 5615.193346 | 876.985322 | 30708.11446285 | 196619.02619620 | 0.156180788080× |

Each timed interval decodes and stores all 172,432 corpus messages. Headline timing includes exactly `Impl.decode` and its complete model projection. CPR adds the live tracking path, starting empty each run, and both implementations resolve 11,347 positions on every run. All complete results stay alive until the timer ends. Preparation, output preallocation and result destruction are outside the clock, as frozen in [BENCHMARK.md](BENCHMARK.md).

The unchanged frozen interleaver ran three AB warmup pairs, then 21 measured AB pairs for each mode, A=rs1090 and B=Lean. The median uses all 21 measured durations per implementation. Each file contains all 48 chronological samples, including warmups; no samples or runs were discarded and no comparative baseline was repeated.

- [Decode raw samples](runs/baseline-FC006/decode/samples.csv), [decode metadata and both power-plan captures](runs/baseline-FC006/decode/metadata.json).
- [CPR raw samples](runs/baseline-FC006/cpr/samples.csv), [CPR metadata and both power-plan captures](runs/baseline-FC006/cpr/metadata.json).
- [Machine-readable results](runs/baseline-FC006/summary.json) and [results.csv](results.csv).

## Commit, clean tree, lock and actual binary

Timed commit: `dee72954b7ad8e4c525b2ffb391477f8f5439809` (`checkpoint: apply FC006 and validate benchmark worker`). `git status --porcelain=v1 --untracked-files=all` returned empty before the build, immediately before each mode, and after timing. Results were initially written beneath ignored `.cache/` to preserve these clean-tree checks, then copied byte-for-byte here after timing. The new result artifacts and PROGRESS update are retained for review after the code commit.

`python3 scripts/check_lock.py` passed all 104 entries before the build, before each mode and after timing. Lock SHA-256: `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

The worker was freshly built from that commit immediately before timing: all 21 linked project C sources, native objects and relevant generated hashes/traces were removed, then `lake --no-cache --rehash -v build lean1090-bench` regenerated them. All corresponding Lean source bytes were checked against the commit. The rebuilt response file has the same 21 native object paths; every regenerated C/object/trace is present with a fresh timestamp and recorded SHA-256. The build ran 17:16:15.080544–17:16:22.466108 UTC; decode timing began at 17:16:24.369315 UTC.

Actual timed `.lake/build/bin/lean1090-bench` SHA-256: **`6e09e99f75a523370970ef5311bc296d52c4c4dbb3cb0ffcce35d87f5f7dc415`**. The fresh-build record, both frozen runner metadata files and the after-timing check all agree. The same binary was used for both modes. Oracle binary SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`.

[Build/binary record](runs/baseline-FC006/binary-built.json), [fresh build log](runs/baseline-FC006/lean-fresh-build.log), [native input hashes](runs/baseline-FC006/fresh-native-inputs.json), [command chronology](runs/baseline-FC006/commands.json), [clean state before decode](runs/baseline-FC006/before-decode-git.json), [clean state before CPR](runs/baseline-FC006/before-cpr-git.json), [clean state after timing](runs/baseline-FC006/after-timing-git.json), [passing lock check](runs/baseline-FC006/before-decode-lock.log).

## Environment and isolation

Intel Core Ultra 9 285K, logical CPU 0 for both workers, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39; 24 logical CPUs exposed. Windows power plan was queried directly before and after **each** mode: **Ultimate Performance**, GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`, unchanged across all four captures. Elevated WSL interoperability was used only because the normal sandbox cannot reach the Windows query bridge; no power or affinity settings outside the benchmark workers were changed.

Lean 4.35.0, compiler commit `eb6cafb7290e8bd5f2937522d8d804f58f02bafc`; pinned Clang 23.1.0 (`ea7d852a70e8bdfaf601d6626a760f9771b2c4b4`). Project C uses `-O3 -ffp-contract=off`, generic x86-64, no CPU-specific options. Effective Clang `-###` compile/link commands were captured before and after and are identical with defaults enabled versus `--no-default-config`; no hidden default configuration changed the driver. [Compiler/environment capture](runs/baseline-FC006/before-environment/environment.json), [effective Clang commands](runs/baseline-FC006/before-effective-clang-drivers.json).

Rust 1.93.1 (`01f6ddf75`, LLVM 21.1.8); rs1090 commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`, shipped dist settings: opt-level 3, full LTO, stripping and overflow checks enabled, default features including `bds-infer`. No compilation environment overrides or Cargo configuration files were present; retained oracle/rs1090 fingerprints have empty rustflags. The frozen runner performs its required cached Cargo build check before each mode; no build overlaps timed samples.

All other project test/proof/build commands and collaborating agents had finished before the baseline began. The only compilation was the recorded preparation; both frozen workers run sequentially on the same CPU. The one-second Linux activity samples before/after found CPU 0 idle and overall guest activity about 0.2455% / 0.0411%. Raw process snapshots and guest load/pressure records are retained. WSL exposes no thermal, governor or hwmon readings here, so physical temperature/frequency and Windows host-wide contention are not measured. These before/after observations do not establish host-wide isolation throughout the interval. [Before host observations](runs/baseline-FC006/before-host.json), [after host observations](runs/baseline-FC006/after-host.json).

The wall clock stepped backward by 0.431349 seconds between CPR sample orders 32 and 33 (17:20:33.473515 → 17:20:33.042166 UTC). No other adjacent sample timestamp regressed. These `recorded_at` labels are retained unchanged; sample order/pair fields preserve chronology. Worker durations use monotonic clocks (`IO.monoNanosNow` in Lean and `Instant` in Rust), so no throughput adjustment or rerun was made.

Decode ran 17:16:24.369315–17:18:50.249027 UTC; CPR ran 17:18:50.596330–17:21:24.311424 UTC. The two medians are separate measurements, so the slightly lower rs1090 CPR median is retained as observed rather than adjusted.

## Validation completed before timing

FC006 was applied exactly with its history entry before the lock update and retained before/after snapshots. `scripts/check_all.sh --full` passed: all 23 exact capstones and permitted axioms, 152 witness checks, import/dependency guards, units and all seven differential components. Fixed-seed whole messages: 10,476,164, with 9,542,689 exact matches plus 933,475 classified D001 cases. Fresh message/Comm-B seeds 1425820264/1176298437: 10,476,164 messages, 9,542,986 exact plus 933,178 D001. Both also pass 101,244 exact direct-register cases, all 32 DF attempts/70 ADS-B branches/14 registers, without gaps or unclassified mismatches. The full CPR stratum retains its 204 documented D009 differences. Worker validation matched all prepared inputs, airports, positions and final states before timing.

[FC006 validation record](../tests/evidence/frozen-changes/FC006/validation.json), [complete gate log](../tests/evidence/frozen-changes/FC006/gate-full.log). No benchmark, tolerance, theorem, test or frozen adapter was changed to obtain these numbers. No optimization generation or public push has occurred.

Independent result review recomputed both medians and ratios, verified all 96 rows, fresh-build/source/binary provenance, clean-tree/lock records, same-CPU affinity and all four power-plan queries. It found no blocking issue and records the wall-clock and WSL observation limits above: [results-review.json](runs/baseline-FC006/results-review.json). The report, raw results and post-timing PROGRESS update are saved locally and uncommitted for this review; the timed code commit is unchanged.
