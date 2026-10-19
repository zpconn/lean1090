# Generation 8: skip identity rational field operations

Gen8 completed on 2026-10-18. Decode throughput is **0.927851149169× rs1090** and CPR throughput is **0.697678936875×**. Lean throughput increased 26.39% and 24.00% respectively over gen7. The 1.10× decode target remains unmet; the next complete diagnostic precedes selection of gen9.

The [pre-change diagnostic](../docs/GEN7-COST-BREAKDOWN.md) found semantic/oracle construction largest at 35.38% of collected instructions. Its payloadValue helper accounted for 8.18 billion overlapping inclusive instructions, including repeated rational arithmetic and GCD normalization. The live field projection now skips multiplication by one and addition of zero, with universal exact equality for every field definition and input. No frozen file, trusted primitive or cross-message cache changed. [Implementation and proof details](../docs/GEN8-AFFINE-IDENTITIES.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 875.472170 | 812.307859 | 196958.859355 | 212274.198864 | 0.927851149169× |
| cpr | 1166.802820 | 814.053751 | 147781.610607 | 211818.936757 | 0.697678936875× |

Both modes retain all 48 samples: three AB warmup pairs followed by 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each interval decodes all 172,432 prepared messages into retained complete outputs. The headline calls exactly Impl.decode, including its complete model construction; CPR starts from empty state and resolves 11,347 positions on both sides. No sample was dropped, adjusted or repeated.

[Decode samples](runs/gen8/decode/samples.csv), [CPR samples](runs/gen8/cpr/samples.csv), [summary](runs/gen8/summary.json), [results.csv](results.csv).

## Commit, correctness and build provenance

Timed commit: `78286f12feb79f8d8e3cdf2411ebd274161d1c3d` (`gen8: skip identity rational field operations`). All six recorded working-tree checks were clean, including untracked files. All 104 frozen hashes matched the lock, SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

Immediately before timing, `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit. The actual timed binary SHA-256 is:

`da5ebfa685b052a3b534001fc2a1d4ead02995e40f2ea077e6f8d6328b4dde31`

Both modes used that binary with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build record](runs/gen8/binary-built.json), [build log](runs/gen8/lean-fresh-build.log), [gate/commit binding](runs/gen8/gate-verification.json), [commands](runs/gen8/commands.json).

Before the commit, scripts/check_all.sh --full passed with 179 unchanged correctness inputs, all 23 exact theorem types and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 4180954545/1380605832: 10,476,164 = 9,542,821 exact + 933,343 D001. Each campaign matches all 101,244 direct-register cases, covers 32 DF attempts, 70 ADS-B branches and 14 registers, and has no unclassified differences or coverage gaps. The fresh campaign's 2,037,780 standard-view differences are separately recorded observations, not compatibility exceptions.

Complete component archives and independent proof/native/evidence reviews are retained in [gen8 validation evidence](../tests/evidence/optimization/gen8/). The first helper build's witness-format error and first fresh launch's missing-directory error remain preserved. The fresh retry used identical seeds, helpers, preflight, 104 sources and three binaries after creating the empty directory; no fixture existed before retry. The reviewer-only chronology correction is also retained. Final verification and all proofs pass without changed statements or hypotheses.

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic -O3 -ffp-contract=off, with no CPU-specific flags. Rust 1.93.1 builds pinned rs1090 685dfaa34c5ab186c691bca3cfe2a22e12517d30 with shipped dist/full-LTO/overflow settings and default bds-infer. Effective commands and configuration/override checks are retained.

All four Windows power-plan captures show Ultimate Performance, unchanged GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. The recorded fresh build and provenance preparation completed before timing. Project builds, tests, proofs, profilers and all subagents were stopped during the measured runs. Supplementary one-second guest observations show CPU 0 at 0% busy before and after; aggregate busy percentages were 0.25% and 0.041684%. These snapshots do not establish Windows host-wide isolation; physical temperature, frequency and governor readings are unavailable through WSL. [Before](runs/gen8/before-host.json), [after](runs/gen8/after-host.json), [environment](runs/gen8/before-environment/environment.json).

Neither mode has adjacent UTC sample-label backsteps, and the wrapper recorded no UTC backstep. Outer UTC elapsed exceeds monotonic elapsed by **528,689.382 microseconds for decode** and **1,124,874.309 microseconds for CPR**. The corresponding outer durations are 45.167892 versus 44.639202618 seconds, and 53.364528 versus 52.239653691 seconds. These clock differences remain in the raw records. Worker monotonic durations determine all medians and ratios; no time correction or rerun was applied.

All 48 source evidence files were copied byte-identically after timing; [archive verification](runs/gen8/archive-verification.json) records their hashes. Two results rows were appended afterward, preserving all previous bytes. [Independent result review](runs/gen8/results-review.json) passed 1,863 checks: all 96 protocol rows, 48 archived originals, 179 gate/104 fresh-campaign/104 frozen committed inputs and all 22 rebuilt native sets. Both medians and ratios were independently recomputed; all 16 previous results rows and 4,160 historical committed files remain unchanged. No public push has occurred.
