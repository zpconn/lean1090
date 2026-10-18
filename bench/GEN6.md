# Generation 6: reuse a syndrome within each message

Gen6 completed on 2026-10-18. Decode throughput is **0.677659988197× rs1090** and CPR throughput is **0.547830934462×**. Lean throughput increased 7.93% and 8.10% respectively over gen5. The 1.10× decode target remains unmet; a complete diagnostic will precede selection of gen7.

The [pre-change diagnostic](../docs/GEN5-COST-BREAKDOWN.md) found frame/CRC largest at 38.86% of instructions. The decoder made 287,418 syndrome calls for 172,432 messages, from report construction, DF17 acceptance and address recovery. It now calculates one syndrome after parsing and passes it through common pure helpers. Public entrypoints delegate to those live helpers; every input retains the same result. DF11 already shared its report syndrome. No frozen file, trusted primitive or cross-message cache was added. [Implementation and proof details](../docs/GEN6-SYNDROME-REUSE.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 1222.612380 | 828.515491 | 141035.705855 | 208121.636678 | 0.677659988197× |
| cpr | 1544.613425 | 846.187016 | 111634.404576 | 203775.284588 | 0.547830934462× |

Both modes retain all 48 samples: three AB warmup pairs and 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each interval decodes all 172,432 prepared messages into retained complete outputs. The headline calls exactly `Impl.decode`; CPR starts with empty state and resolves 11,347 positions on both sides. No sample was dropped, adjusted or repeated.

[Decode samples](runs/gen6/decode/samples.csv), [CPR samples](runs/gen6/cpr/samples.csv), [summary](runs/gen6/summary.json), [results.csv](results.csv).

## Commit, correctness and build provenance

Timed commit: `cd4df90b6821ed8d375cb26e0e5baed6f6e9fecf` (`gen6: reuse one syndrome throughout each decoded message`). All six recorded working-tree checks were clean, including untracked files. All 104 frozen hashes matched the lock, SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

Immediately before timing, `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit. The actual timed binary SHA-256 is:

`930b6d6f3c5f274c1ea05cd232919281f8a86e316636bedb8a885ecb90defdec`

Both modes used that binary with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build record](runs/gen6/binary-built.json), [build log](runs/gen6/lean-fresh-build.log), [gate/commit binding](runs/gen6/gate-verification.json), [commands](runs/gen6/commands.json).

Before the commit, `scripts/check_all.sh --full` passed with 177 unchanged correctness inputs, all 23 exact theorem types and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 3190208009/1865131355: 10,476,164 = 9,543,374 exact + 932,790 D001. Each campaign matches all 101,244 direct-register cases, covers 32 DF attempts, 70 ADS-B branches and 14 registers, and has no unclassified differences or coverage gaps. Complete component archives, independent proof/native/evidence reviews and source/raw hashes are retained in [gen6 validation evidence](../tests/evidence/optimization/gen6/).

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic `-O3 -ffp-contract=off`, with no CPU-specific flags. Rust 1.93.1 builds pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30` with shipped dist/full-LTO/overflow settings and default `bds-infer`. Effective compiler commands and configuration/override checks are retained.

All four Windows power-plan captures show Ultimate Performance, unchanged GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. The recorded fresh build and provenance preparation completed before timing. Project builds, tests, proofs, profilers and all subagents were stopped during the measured runs. Supplementary one-second guest observations show CPU 0 at 0% busy before and 3.061224% after, with aggregate busy percentages of 0.208594% and 0.333472%. These snapshots do not establish Windows host-wide isolation; physical temperature, frequency and governor readings are unavailable through WSL. [Before](runs/gen6/before-host.json), [after](runs/gen6/after-host.json), [environment](runs/gen6/before-environment/environment.json).

Neither mode has adjacent UTC sample-label backsteps. Outer UTC elapsed exceeds monotonic elapsed by 0.119 microseconds for decode and 3.635 microseconds for CPR. Raw clocks remain unchanged; worker monotonic durations determine all medians and ratios. No time correction or rerun was applied.

All 48 source evidence files were copied byte-identically after timing; [archive verification](runs/gen6/archive-verification.json) records their hashes. Results rows were appended afterward, preserving all previous bytes. The [independent result review](runs/gen6/results-review.json) records 1,858 passing checks, including all 96 protocol rows, 48 archived source files, 177 gate and 102 fresh-campaign source blobs, 104 frozen blobs and 22 rebuilt native sets. Both medians and ratios were independently recomputed. No public push has occurred.
