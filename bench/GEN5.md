# Generation 5: exact software-binary64 Mach table

Gen5 completed on 2026-10-18. Decode throughput is **0.615313791799× rs1090** and CPR throughput is **0.503155544862×**. Lean throughput increased 13.78% and 8.66% respectively over gen4. The 1.10× decode target remains unmet; a complete diagnostic will precede selection of gen6.

The [pre-change diagnostic](../docs/GEN4-COST-BREAKDOWN.md) found Comm-B inference largest at 38.22% of instructions. Its repeated Mach conversion accounted for 53,912 calls and 3.61 billion overlapping inclusive instructions. `cbMach64` now reads an immutable table covering all 1,024 ten-bit field codes. Every entry preserves the exact software binary64 literal/multiply/divide sequence; equality holds for every natural payload. No frozen file, trusted primitive or cross-message cache was added. [Implementation and proof details](../docs/GEN5-MACH-TABLE.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 1319.581059 | 811.956425 | 130671.775579 | 212366.076172 | 0.615313791799× |
| cpr | 1669.685183 | 840.111358 | 103272.162774 | 205248.980814 | 0.503155544862× |

Both modes retain all 48 samples: three AB warmup pairs and 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each interval decodes all 172,432 prepared messages into retained complete outputs. The headline calls exactly `Impl.decode`; CPR starts with empty state and resolves 11,347 positions on both sides. No sample was dropped, adjusted or repeated.

[Decode samples](runs/gen5/decode/samples.csv), [CPR samples](runs/gen5/cpr/samples.csv), [summary](runs/gen5/summary.json), [results.csv](results.csv).

## Commit, correctness and build provenance

Timed commit: `eeb58261e6be0c2b87385f3064a88aed00d4d19a` (`gen5: tabulate exact software-binary64 Mach values`). All six recorded working-tree checks were clean, including untracked files. All 104 frozen hashes matched the lock, SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

Immediately before timing, `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit. The actual timed binary SHA-256 is:

`6d1576d363d6fa03fea5a9ac55aaa26a323ee5011c8ad38df99821fa58a7e4ab`

Both modes used that binary with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build record](runs/gen5/binary-built.json), [build log](runs/gen5/lean-fresh-build.log), [gate/commit binding](runs/gen5/gate-verification.json), [commands](runs/gen5/commands.json).

Before the commit, `scripts/check_all.sh --full` passed with 176 unchanged correctness inputs, all 23 exact theorem types and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 26660891/2917856783: 10,476,164 = 9,542,656 exact + 933,508 D001. Each campaign matches all 101,244 direct-register cases, covers 32 DF attempts, 70 ADS-B branches and 14 registers, and has no unclassified differences or coverage gaps. Complete component archives, independent proof/native/evidence reviews and source/raw hashes are retained in [gen5 validation evidence](../tests/evidence/optimization/gen5/). Root completed the fresh archive verifier after the assisting agent became unavailable; the passed campaign and seeds were preserved without rerunning decoders.

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic `-O3 -ffp-contract=off`, with no CPU-specific flags. Rust 1.93.1 builds pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30` with shipped dist/full-LTO/overflow settings and default `bds-infer`. Effective compiler commands and configuration/override checks are retained.

All four Windows power-plan captures show Ultimate Performance, unchanged GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. Project builds, tests, proofs, profilers and all subagents were stopped throughout preparation and timing. Supplementary one-second guest observations show CPU 0 at 0% busy before and 2.040816% after, with aggregate busy percentages of 0.083333% and 0.125104%. These snapshots do not establish Windows host-wide isolation; physical temperature, frequency and governor readings are unavailable through WSL. [Before](runs/gen5/before-host.json), [after](runs/gen5/after-host.json), [environment](runs/gen5/before-environment/environment.json).

Neither mode has adjacent UTC sample-label backsteps. Outer UTC elapsed exceeds monotonic elapsed by 4.656 microseconds for decode and 5.867 microseconds for CPR. Raw clocks remain unchanged; worker monotonic durations determine all medians and ratios. No time correction or rerun was applied.

All 48 source evidence files were copied byte-identically after timing; [archive verification](runs/gen5/archive-verification.json) records their hashes. Results rows were appended afterward, preserving all previous bytes. The [independent result review](runs/gen5/results-review.json) passed 1,856 checks, including all 96 protocol rows, 48 archived source files, 176 gate and 101 fresh-campaign source blobs, 104 frozen blobs and 22 rebuilt native sets. Both medians and ratios were independently recomputed. No public push has occurred.
