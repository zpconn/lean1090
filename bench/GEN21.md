# Generation 21: exact integer scaling normalization

Decode throughput is **1.963308902434× rs1090**; CPR throughput is **1.539889738438×**. Lean throughput changed by +6.34% / +5.05% versus gen20. Targets — 2.00× decode: unmet; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

The existing affine field helper normalizes the integer numerator product directly on its nonunit-scale branch. An unconditional equality preserves exact rational multiplication for every integer and rational scale; identity scaling, zero-offset handling and all status/extraction behavior remain unchanged. [Implementation and proof evidence](../docs/GEN21-AFFINE-NORMALIZATION.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 408.396750 | 801.808975 | 422216.876114 | 215053.716504 | 1.963308902434× |
| cpr | 523.974619 | 806.863139 | 329084.642170 | 213706.627141 | 1.539889738438× |

CPR overhead is **0.670280858541 µs/message for Lean** and **0.029311055952 µs/message for rs1090**. This is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, calculated from exact integer median durations before division. It is a difference between independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Negative differences are retained without clamping.

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen21/decode/samples.csv), [CPR samples](runs/gen21/cpr/samples.csv), [summary](runs/gen21/summary.json).

Timed commit: `11fbf4e0c8c196d70cd838dd2a14516f586fc4c5`. Actual worker SHA-256: `861d722aee03c73147893797c9876bac3ee1337120516e2a45d2bd3c664d34f5`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen21/binary-built.json), [fresh native inputs](runs/gen21/fresh-native-inputs.json), [commands](runs/gen21/commands.json).

The full gate passed with 195 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,872 exact plus 933,292 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen21/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All three agents report no running jobs and are completed. Fixed and fresh campaigns, independent reviews and duplicate cleanup finished before timing. Root performs no concurrent build, proof, test, profiler or archive work. Windows host activity is not controlled; power-plan and process captures are retained.” Guest bracketing observations: before: CPU 0 1.0%, aggregate 0.16666666666666666%; after: CPU 0 2.0%, aggregate 0.20859407592824364%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen21/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 33.225361000 s; monotonic 32.599314085 s; UTC minus monotonic 626046.915 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 37.388577000 s; monotonic 36.006650618 s; UTC minus monotonic 1381926.382 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen21/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen21/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 42 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
