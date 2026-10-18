# Generation 4: payload fields with machine shifts and masks

Gen4 completed on 2026-10-18. Decode throughput is **0.554897290381× rs1090** and CPR throughput is **0.461330213030×**. Lean throughput increased 37.25% and 30.77% respectively over gen3. The 1.10× decode target remains unmet; the next complete diagnostic will precede selection of gen5.

The [pre-change diagnostic](../docs/GEN3-COST-BREAKDOWN.md) found Comm-B inference largest at 39.22% of instructions, including 3,121,720 calls to `payloadBits`. Its two generic natural powers and division/remainder are replaced with UInt64 shifts and a mask for widths below 64. Wider fields retain the original formula. The helper equality holds for every natural word, start and width, preserving the unchanged decoder refinement. No frozen file, trusted primitive, table or cross-message cache was added. [Implementation and proof details](../docs/GEN4-PAYLOAD-BITS.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 1501.456209 | 833.153982 | 114843.176222 | 206962.942896 | 0.554897290381× |
| cpr | 1814.361133 | 837.019608 | 95037.309201 | 206007.121401 | 0.461330213030× |

Both modes retain all 48 samples: three AB warmup pairs and 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each interval decodes all 172,432 prepared messages into retained complete outputs. The headline calls exactly `Impl.decode`; CPR starts with empty state and resolves 11,347 positions on both sides. No sample was dropped, adjusted or repeated.

[Decode samples](runs/gen4/decode/samples.csv), [CPR samples](runs/gen4/cpr/samples.csv), [summary](runs/gen4/summary.json), [results.csv](results.csv).

## Commit, correctness and build provenance

Timed commit: `275329a2efd269dc44e549e4b6538d36277aaa3f` (`gen4: extract payload fields with machine shifts and masks`). All six recorded working-tree checks were clean, including untracked files. All 104 frozen hashes matched the lock, SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

Immediately before timing, `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit. The actual timed binary SHA-256 is:

`adec5d1a48a77a241c5d5bb526155910e94796a0d5526280870ae7e36beb8f57`

Both modes used that binary with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build record](runs/gen4/binary-built.json), [build log](runs/gen4/lean-fresh-build.log), [gate/commit binding](runs/gen4/gate-verification.json), [commands](runs/gen4/commands.json).

Before the commit, `scripts/check_all.sh --full` passed with 175 unchanged correctness inputs, all 23 exact theorem types and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 388032270/1476569264: 10,476,164 = 9,543,125 exact + 933,039 D001. Each campaign matches all 101,244 direct-register cases, covers 32 DF attempts, 70 ADS-B branches and 14 registers, and has no unclassified differences or coverage gaps. Complete component archives, independent proof/native/evidence reviews and source/raw hashes are retained in [gen4 validation evidence](../tests/evidence/optimization/gen4/).

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic `-O3 -ffp-contract=off`, with no CPU-specific flags. Rust 1.93.1 builds pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30` with shipped dist/full-LTO/overflow settings and default `bds-infer`. Effective compiler commands and configuration/override checks are retained.

All four Windows power-plan captures show Ultimate Performance, unchanged GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. Project builds, tests, proofs, profilers and all subagents were stopped throughout preparation and timing. Supplementary one-second guest observations show CPU 0 at 0% busy both before and after, with aggregate busy percentages of 0.122649% and 0.082440%. These observations do not establish Windows host-wide isolation; physical temperature, frequency and governor readings are unavailable through WSL. [Before](runs/gen4/before-host.json), [after](runs/gen4/after-host.json), [environment](runs/gen4/before-environment/environment.json).

Neither mode has adjacent UTC sample-label backsteps. Outer UTC elapsed is 1.254293938 seconds shorter than monotonic elapsed for decode and 1.116133244 seconds shorter for CPR. Raw clocks remain unchanged; worker monotonic durations determine all medians and ratios. No time correction or rerun was applied.

All 48 source evidence files were copied byte-identically after timing; [archive verification](runs/gen4/archive-verification.json) records their hashes. Results rows were appended afterward, preserving all previous bytes. The [independent result review](runs/gen4/results-review.json) passed 1,855 checks: all 96 protocol rows, 48 archived source files, 175 gate and 100 fresh-campaign source blobs, 104 frozen blobs and 22 rebuilt native sets match. Both medians and ratios were independently recomputed. No public push has occurred.
