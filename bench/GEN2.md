# Generation 2: exact Comm-B density tables and score bounds

Gen2 completed on 2026-10-18. Decode throughput is **0.294559392137× rs1090** and CPR throughput is **0.270600916153×**. Lean throughput increased 42.62% and 41.21% respectively over gen1. The 1.10× decode target remains unmet; the next step is a new diagnostic before selecting another optimization.

The [pre-change diagnostic](../docs/GEN1-COST-BREAKDOWN.md) found Comm-B inference to be the largest instruction category, at 48.34%. The live score gate now reads 13 immutable, complete field-code density tables and uses a proved exact rational enclosure. Scores inside the uncertain interval around −3 invoke the original software-binary64 computation lazily. All-input table equivalence, the rounding-error bound and the full decoder refinement are proved. No trusted primitive, frozen source or corpus cache was added. [Implementation and proof details](../docs/GEN2-SCORE-GATE.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 2948.287582 | 868.445798 | 58485.475112 | 198552.402922 | 0.294559392137× |
| cpr | 3214.679253 | 869.895151 | 53638.943866 | 198221.590041 | 0.270600916153× |

Each mode retains all 48 samples: three AB warmup pairs and 21 measured AB pairs, A=rs1090/B=Lean, pinned to CPU 0. Each run decodes all 172,432 messages from prepared bytes into retained outputs. The headline times the complete `Impl.decode` result; CPR starts with empty state and resolves 11,347 positions on both sides. No samples were dropped, adjusted or repeated. Table initialization is part of process/module startup, outside the per-corpus decode interval; tables contain only complete field-code domains, as authorized.

[Decode samples](runs/gen2/decode/samples.csv), [CPR samples](runs/gen2/cpr/samples.csv), [summary](runs/gen2/summary.json), [results.csv](results.csv).

## Commit, proof gate and binary

Timed commit: `f05d8b1bd697269efdb2d73b045fdf50a481f969` (`gen2: decide Comm-B scores with proved exact tables and bounds`). All six recorded tree checks were clean, including untracked files. All 104 frozen hashes matched. Lock SHA-256: `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

The fresh `lake --no-cache --rehash -v build lean1090-bench` regenerated all 22 linked project C/object sets from that commit immediately before timing. Actual timed binary SHA-256:

`71c52eabb059fb6b80d71ee2b0950f85630a0b0a32ec4a9704f4fbf32701eded`

Both modes used that binary, with native hashes unchanged throughout. Oracle SHA-256 remained `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. [Build evidence](runs/gen2/binary-built.json), [build log](runs/gen2/lean-fresh-build.log), [gate/commit binding](runs/gen2/gate-verification.json), [command chronology](runs/gen2/commands.json).

Before committing, `scripts/check_all.sh --full` passed with 173 unchanged correctness-input hashes, all 23 exact theorem types/allowed axioms, 152 witness audits, import/hypothesis guards, 1,011 unit fixture assertions and all seven differential components. Fixed-seed whole-message results: 10,476,164 = 9,542,689 exact + 933,475 documented D001. Fresh seeds 184794048/1273035172 gave 10,476,164 = 9,542,710 exact + 933,454 D001. Both runs passed all 101,244 direct-register cases and every coverage check, with no unclassified mismatches. All component outputs have complete, separate cache archives bound to the emitted gate summaries; versioned metadata and hashes are retained in [gen2 validation evidence](../tests/evidence/optimization/gen2/).

## Environment and observations

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Lean 4.35.0/Clang 23.1.0 use generic `-O3 -ffp-contract=off`, without CPU-specific flags. Rust 1.93.1 builds pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30` with shipped dist/full-LTO/overflow settings and default `bds-infer`. Effective compiler-driver commands and override/configuration checks are retained.

All four Windows power-plan captures report the unchanged Ultimate Performance plan, GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. Project test/proof/profile jobs and all subagents were stopped throughout benchmark preparation and timing. The supplementary one-second guest observations show CPU 0 busy fractions of 0% before and 2% after; aggregate guest busy fractions were 0.203583% and 0.122850%. These snapshots do not establish Windows host-wide isolation. Physical temperature, frequency and governor readings are unavailable through this WSL environment. [Before](runs/gen2/before-host.json), [after](runs/gen2/after-host.json), [environment](runs/gen2/before-environment/environment.json).

Neither mode has an adjacent UTC sample-label backstep. Outer UTC elapsed is nevertheless 2.788987786 s shorter than monotonic elapsed for decode, and 2.761019624 s shorter for CPR. The after-run CPU snapshot spans 1.019867752 monotonic seconds but only 0.089265 UTC seconds. All clocks and original labels are retained; sample durations and medians use worker monotonic clocks. No time correction or rerun was applied.

All 48 source evidence files were copied byte-for-byte into this archive after timing completed. [Archive verification](runs/gen2/archive-verification.json). The two results rows were appended afterward. No public push has occurred.

The [independent result review](runs/gen2/results-review.json) reproduced both medians and ratios, all 96 protocol rows, the committed source/lock bindings, all 22 native artifact sets and all 48 archived files. The complete output observations and clock/environment limits agree with this report.
