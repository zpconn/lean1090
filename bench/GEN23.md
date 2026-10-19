# Generation 23: exact Comm-B plausibility tables

Decode throughput is **2.410234595243× rs1090**; CPR throughput is **1.835727795894×**. Lean throughput changed by +11.64% / +9.83% versus gen22. Targets — 2.00× decode: reached; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

Immutable Boolean field-code tables replace the original BDS40 selected-altitude/QNH, BDS50 roll and BDS60 Mach/vertical-rate plausibility comparisons. Unrestricted all-payload equalities preserve rounding, signed boundaries, unavailable sentinels and status checks. Score arithmetic, output values and Float callbacks are unchanged. [Implementation and proof evidence](../docs/GEN23-COMMB-VALIDITY.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 325.927027 | 785.560596 | 529050.939982 | 219501.844769 | 2.410234595243× |
| cpr | 428.704761 | 786.985246 | 402216.200253 | 219104.488777 | 1.835727795894× |

CPR overhead is **0.596047914540 µs/message for Lean** and **0.008262097523 µs/message for rs1090**. This is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, calculated from exact integer median durations before division. It is a difference between independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Negative differences are retained without clamping.

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen23/decode/samples.csv), [CPR samples](runs/gen23/cpr/samples.csv), [summary](runs/gen23/summary.json).

Timed commit: `9b6868f21fcac0a59044153f01e6691d091dbb5c`. Actual worker SHA-256: `ece1cad565de9b2b45288ee494b2b944e51f3cd6ac00b4728eaa41d94e55d47e`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen23/binary-built.json), [fresh native inputs](runs/gen23/fresh-native-inputs.json), [commands](runs/gen23/commands.json).

The full gate passed with 200 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,964 exact plus 933,200 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen23/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project builds, proofs, tests, profilers and review I/O stopped for both timed modes; host observations and limitations retained.” Guest bracketing observations: before: CPU 0 0.9900990099009901%, aggregate 0.16666666666666666%; after: CPU 0 0.0%, aggregate 0.0%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen23/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 29.810989000 s; monotonic 29.810983024 s; UTC minus monotonic 5.976 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 32.668981000 s; monotonic 32.668976789 s; UTC minus monotonic 4.211 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen23/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen23/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 46 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
