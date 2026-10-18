# Generation 7: integer score-enclosure comparisons

Gen7 completed on 2026-10-18. Decode throughput is **0.741264131818× rs1090** and CPR throughput is **0.581176183743×**. Lean throughput increased 10.49% and 6.76% respectively over gen6. The 1.10× decode target remains unmet; a complete diagnostic will precede selection of gen8.

The [pre-change diagnostic](../docs/GEN6-COST-BREAKDOWN.md) found Comm-B inference largest at 35.10% of instructions. The score-choice path accounted for 4.07 billion overlapping inclusive instructions, with repeated rational sums and GCD normalization. The gate now compares integers at an exact common denominator while preserving the previous center/error-bound decisions for every rational input list, penalty and fallback. Uncertain cases still invoke the full software-binary64 score. No frozen file, trusted primitive or cross-message cache was added. [Implementation and proof details](../docs/GEN7-INTEGER-SCORE-GATE.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 1106.538274 | 820.237133 | 155830.127210 | 210222.133408 | 0.741264131818× |
| cpr | 1446.829656 | 840.862938 | 119179.199351 | 205065.525197 | 0.581176183743× |

Both modes retain all 48 samples: three AB warmup pairs and 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each interval decodes all 172,432 prepared messages into retained complete outputs. The headline calls exactly `Impl.decode`; CPR starts with empty state and resolves 11,347 positions on both sides. No sample was dropped, adjusted or repeated.

[Decode samples](runs/gen7/decode/samples.csv), [CPR samples](runs/gen7/cpr/samples.csv), [summary](runs/gen7/summary.json), [results.csv](results.csv).

## Commit, correctness and build provenance

Timed commit: `7c3b44d246149a1c5aa671d119b6ba2be27d856b` (`gen7: compare score enclosures with exact integer arithmetic`). All six recorded working-tree checks were clean, including untracked files. All 104 frozen hashes matched the lock, SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

Immediately before timing, `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit. The actual timed binary SHA-256 is:

`fc90d59af0154a578478ace9353001ca82d9780da0a182495778288224851896`

Both modes used that binary with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build record](runs/gen7/binary-built.json), [build log](runs/gen7/lean-fresh-build.log), [gate/commit binding](runs/gen7/gate-verification.json), [commands](runs/gen7/commands.json).

Before the commit, `scripts/check_all.sh --full` passed with 178 unchanged correctness inputs, all 23 exact theorem types and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 175700860/3045455262: 10,476,164 = 9,543,151 exact + 933,013 D001. Each campaign matches all 101,244 direct-register cases, covers 32 DF attempts, 70 ADS-B branches and 14 registers, and has no unclassified differences or coverage gaps. Complete component archives, independent proof/native/evidence reviews and source/raw hashes are retained in [gen7 validation evidence](../tests/evidence/optimization/gen7/). All four helper-build attempts and both integrated-build attempts remain recorded; final proofs pass without changed statements or hypotheses.

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic `-O3 -ffp-contract=off`, with no CPU-specific flags. Rust 1.93.1 builds pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30` with shipped dist/full-LTO/overflow settings and default `bds-infer`. Effective compiler commands and configuration/override checks are retained.

All four Windows power-plan captures show Ultimate Performance, unchanged GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. The recorded fresh build and provenance preparation completed before timing. Project builds, tests, proofs, profilers and all subagents were stopped during the measured runs. Supplementary one-second guest observations show CPU 0 at 0% busy both before and after, with aggregate busy percentages of 0.330715% and 0.166597%. These snapshots do not establish Windows host-wide isolation; physical temperature, frequency and governor readings are unavailable through WSL. [Before](runs/gen7/before-host.json), [after](runs/gen7/after-host.json), [environment](runs/gen7/before-environment/environment.json).

Neither mode has adjacent UTC sample-label backsteps. Outer UTC elapsed exceeds monotonic elapsed by 11.354 microseconds for decode and 4.690 microseconds for CPR. Raw clocks remain unchanged; worker monotonic durations determine all medians and ratios. No time correction or rerun was applied.

All 48 source evidence files were copied byte-identically after timing; [archive verification](runs/gen7/archive-verification.json) records their hashes. Results rows were appended afterward, preserving all previous bytes. [Independent result review](runs/gen7/results-review.json) passed 1,861 checks: all 96 protocol rows, 48 archived originals, 178 gate/103 fresh-campaign/104 frozen committed inputs and all 22 rebuilt native sets. Both medians and ratios were independently recomputed; all 14 previous results rows and 3,590 historical committed files remain unchanged. No public push has occurred.
