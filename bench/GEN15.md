# Generation 15: shared Comm-B payload limit

Decode throughput is **1.607053275134× rs1090**; CPR throughput is **0.990643654222×**. Lean throughput changed by +12.70% / +8.21% versus gen14. The 1.50× decode threshold is reached. Stop for user review before further optimization or final deliverable work.

The live Comm-B validator reads its exact 2^56 payload limit from an immutable format constant initialized once, avoiding repeated decimal literal parsing. Every register branch and all scoring arithmetic remain unchanged. Definitional equality covers every natural-number register and payload. [Implementation and proof evidence](../docs/GEN15-COMMB-CONSTANT.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 507.041386 | 814.842520 | 340074.804071 | 211613.895652 | 1.607053275134× |
| cpr | 812.869274 | 805.263788 | 212127.589903 | 214131.074276 | 0.990643654222× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen15/decode/samples.csv), [CPR samples](runs/gen15/cpr/samples.csv), [summary](runs/gen15/summary.json).

Timed commit: `e659220307538f2aee5398efdb0a9182bff1d778`. Actual worker SHA-256: `4deead5e3f59d9e1bc6b850d3dd0bfe6b3f0ce3a9b0b2d44263af26345432c08`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen15/binary-built.json), [fresh native inputs](runs/gen15/fresh-native-inputs.json), [commands](runs/gen15/commands.json).

The full gate passed with 186 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,150 exact plus 933,014 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen15/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All root and agent builds, tests, proofs, profilers, campaign jobs, cleanup jobs and reviews have stopped. The full gate and independent reviews passed, all source changes are committed, and archived scratch cleanup is complete. WSL2 and external host workload remain environmental limitations.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.12505210504376824%; after: CPU 0 1.0%, aggregate 0.20833333333333334%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen15/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 36.258388000 s; monotonic 35.586507385 s; UTC minus monotonic 671880.615 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 44.096029000 s; monotonic 42.889413426 s; UTC minus monotonic 1206615.574 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen15/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen15/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 30 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
