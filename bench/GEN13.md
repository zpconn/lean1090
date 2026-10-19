# Generation 13: exact BDS50 wind-penalty table

Decode throughput is **1.492757184729× rs1090**; CPR throughput is **0.926632349521×**. Lean throughput changed by +9.10% / +5.23% versus gen12. The 1.50× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.

The live BDS50 wind penalty uses a 2,047-entry immutable table indexed by the signed difference of two ten-bit field codes. Every software binary64 rounding operation is retained in the table body, and an unconditional theorem covers every natural-number payload. Status handling and the final turn adjustment remain unchanged. [Implementation and proof evidence](../docs/GEN13-BDS50-PENALTY.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 545.485333 | 814.277150 | 316107.491015 | 211760.823695 | 1.492757184729× |
| cpr | 879.435413 | 814.913303 | 196071.249180 | 211595.514965 | 0.926632349521× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen13/decode/samples.csv), [CPR samples](runs/gen13/cpr/samples.csv), [summary](runs/gen13/summary.json).

Timed commit: `247a28d9a681fd5fac37a630cc4a889e30000490`. Actual worker SHA-256: `b13fac61e8bd1170cdcacae3c3c054bc05f484da39ebf2d823dd868ab5920730`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen13/binary-built.json), [fresh native inputs](runs/gen13/fresh-native-inputs.json), [commands](runs/gen13/commands.json).

The full gate passed with 184 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,998 exact plus 933,166 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen13/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All root and agent builds, tests, proofs, profilers, campaign jobs and reviews have stopped. Generation 13 is committed under the configured user identity; the working tree is clean. The frozen interleaver runs both modes with CPU 0 affinity and actual Windows power-plan captures. WSL2 and external host workload remain environmental limitations.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.041684035014589414%; after: CPU 0 0.0%, aggregate 0.24989587671803415%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen13/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 36.580988000 s; monotonic 36.580985009 s; UTC minus monotonic 2.991 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 44.758362000 s; monotonic 44.758358003 s; UTC minus monotonic 3.997 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen13/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen13/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 26 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
