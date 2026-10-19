# Generation 20: eight-bit CRC loop batching

Decode throughput is **1.852064793419× rs1090**; CPR throughput is **1.485653752657×**. Lean throughput changed by +3.94% / +3.08% versus gen19. Targets — 2.00× decode: unmet; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

The live CRC path groups eight exact UInt32 updates per iteration for aligned widths through 128. Unconditional proofs preserve the original syndrome for every natural width and word, with the original bit loop as the live fallback. No lookup table, Float code, trusted primitive or corpus-specific branch is added. [Implementation and proof evidence](../docs/GEN20-BYTE-CRC.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 434.308678 | 804.367812 | 397026.374868 | 214369.592402 | 1.852064793419× |
| cpr | 550.459560 | 817.792311 | 313250.986140 | 210850.600673 | 1.485653752657× |

CPR overhead is **0.673603983019 µs/message for Lean** and **0.077853872831 µs/message for rs1090**. This is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, calculated from exact integer median durations before division. It is a difference between independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Negative differences are retained without clamping.

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen20/decode/samples.csv), [CPR samples](runs/gen20/cpr/samples.csv), [summary](runs/gen20/summary.json).

Timed commit: `d3a10f60e7e83a35c53d5e4066a82dce048ad2be`. Actual worker SHA-256: `b201da708eb97f588535d09c7b75d63ad1d098a93554b7f5db7014e780f0448b`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen20/binary-built.json), [fresh native inputs](runs/gen20/fresh-native-inputs.json), [commands](runs/gen20/commands.json).

The full gate passed with 195 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,976 exact plus 933,188 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen20/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project proof, test, build, profile, comparison replay, cleanup and subagent jobs are stopped. Full fixed and independent fresh 10M validation passed on the exact 195 committed inputs. Final gate/archive/plan review passed. Clean source commit d3a10f60e7e83a35c53d5e4066a82dce048ad2be uses zpconn identity. Both frozen modes are measured once; no source edits or performance work run concurrently. WSL2 host-wide contention and physical frequency visibility remain limited as documented.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.3331945022907122%; after: CPU 0 0.0%, aggregate 0.125%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen20/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 34.031726000 s; monotonic 33.523226542 s; UTC minus monotonic 508499.458 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 37.442191000 s; monotonic 36.909951645 s; UTC minus monotonic 532239.355 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen20/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen20/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 40 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
