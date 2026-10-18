# Generation 3: CRC bit extraction with machine words

Gen3 completed on 2026-10-18. Decode throughput is **0.407103119296× rs1090** and CPR throughput is **0.353550980332×**. Lean throughput increased 43.07% and 35.49% respectively over gen2. The 1.10× decode target remains unmet; another complete diagnostic is required before choosing gen4.

The [pre-change diagnostic](../docs/GEN2-COST-BREAKDOWN.md) found frame/CRC to be the largest category at 46.97% of instructions, with repeated `Nat.testBit` calls accounting for 63.57% of that stage's overlapping inclusive cost. `Impl.Parity.syndrome` now extracts two machine words once per call and uses their bits below index 128. Higher indices retain the arbitrary-precision path. The helper equality holds for every natural word and index, preserving the existing all-width CRC and all-input decoder refinement. No frozen file, trusted primitive, table or cross-message cache was added. [Implementation and proof details](../docs/GEN3-CRC-BITS.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 2060.768796 | 838.945405 | 83673.627209 | 205534.232588 | 0.407103119296× |
| cpr | 2372.694541 | 838.868481 | 72673.492951 | 205553.080019 | 0.353550980332× |

Both modes retain all 48 samples: three AB warmup pairs and 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each interval decodes all 172,432 prepared messages into retained complete outputs. The headline calls exactly `Impl.decode`; CPR starts with empty state and resolves 11,347 positions on both sides. No sample was dropped, adjusted or repeated.

[Decode samples](runs/gen3/decode/samples.csv), [CPR samples](runs/gen3/cpr/samples.csv), [summary](runs/gen3/summary.json), [results.csv](results.csv).

## Commit, correctness and build provenance

Timed commit: `3ba567f1d5039eb16ab033dd436d3d4f0f33c98b` (`gen3: extract CRC bits with fixed-width words`). All six recorded working-tree checks were clean, including untracked files. All 104 frozen hashes matched the lock, SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

Immediately before timing, `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit. The actual timed binary SHA-256 is:

`6d6b7d9a7d8535e7f6de5ff6f7d4dac643d068322bef6c0a809732603354117d`

Both modes used that binary with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build record](runs/gen3/binary-built.json), [build log](runs/gen3/lean-fresh-build.log), [gate/commit binding](runs/gen3/gate-verification.json), [commands](runs/gen3/commands.json).

Before the commit, `scripts/check_all.sh --full` passed with 174 unchanged correctness inputs, all 23 exact theorem types and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 2991522103/2632950597: 10,476,164 = 9,542,847 exact + 933,317 D001. Each campaign matches all 101,244 direct-register cases, covers 32 DF attempts, 70 ADS-B branches and 14 registers, and has no unclassified differences or coverage gaps. Complete component archives, independent proof/native/evidence reviews and source/raw hashes are retained in [gen3 validation evidence](../tests/evidence/optimization/gen3/).

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic `-O3 -ffp-contract=off`, with no CPU-specific flags. Rust 1.93.1 builds pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30` with shipped dist/full-LTO/overflow settings and default `bds-infer`. Effective compiler commands and configuration/override checks are retained.

All four Windows power-plan captures show Ultimate Performance, unchanged GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. Project builds, tests, proofs, profilers and all subagents were stopped throughout preparation and timing. Supplementary one-second guest observations show CPU 0 at 0% busy both before and after, with aggregate busy fractions of 0.081934% and 0.164813%. These observations do not establish Windows host-wide isolation; physical temperature, frequency and governor readings are unavailable through WSL. [Before](runs/gen3/before-host.json), [after](runs/gen3/after-host.json), [environment](runs/gen3/before-environment/environment.json).

Neither mode has adjacent UTC sample-label backsteps. Outer UTC elapsed is 2.377723093 seconds shorter than monotonic elapsed for decode and 1.572996932 seconds shorter for CPR. Raw clocks remain unchanged; worker monotonic durations determine all medians and ratios. No time correction or rerun was applied.

All 48 source evidence files were copied byte-identically after timing; [archive verification](runs/gen3/archive-verification.json) records their hashes. Results rows were appended afterward. The [independent result review](runs/gen3/results-review.json) passed: all 96 protocol rows, 48 archived source files, 174 gate and 99 fresh-campaign source blobs, 104 frozen blobs and 22 rebuilt native artifact sets match. Both medians and ratios were independently recomputed. No public push has occurred.
