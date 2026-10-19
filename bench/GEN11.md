# Generation 11: CRC loop with a UInt32 remainder

Decode throughput is **1.268337197293× rs1090**; CPR throughput is **0.847178887465×**. Lean throughput changed by +6.35% / +3.41% versus gen10. The 1.50× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.

The live CRC uses a specialized natural-number fold with a UInt32 remainder instead of constructing a list of indices. The public step delegates to the same masked polynomial update; unconditional proofs retain every width and word, including the arbitrary-precision high-bit fallback. [Implementation and proof evidence](../docs/GEN11-CRC.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 657.029319 | 833.334725 | 262441.865247 | 206918.054447 | 1.268337197293× |
| cpr | 993.549075 | 841.713800 | 173551.568150 | 204858.230909 | 0.847178887465× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen11/decode/samples.csv), [CPR samples](runs/gen11/cpr/samples.csv), [summary](runs/gen11/summary.json).

Timed commit: `fd20b1c3553415b1b727f1dca347d4d43dd0d142`. Actual worker SHA-256: `8abd618f802719109ef3da7d36c9280740551596635b99953ef172bd1ca1b5ae`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen11/binary-built.json), [fresh native inputs](runs/gen11/fresh-native-inputs.json), [commands](runs/gen11/commands.json).

The full gate passed with 182 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,726 exact plus 933,438 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen11/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All three collaborating agents confirmed their jobs stopped. Full fixed and fresh 10M campaigns and independent reviews are complete. No project builds, proofs, tests or profiling run concurrently with timing. Host observations are retained; host-wide quiescence is not inferred.” Guest bracketing observations: before: CPU 0 1.0%, aggregate 0.20824656393169513%; after: CPU 0 2.0202020202020203%, aggregate 0.20842017507294705%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen11/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 40.961087000 s; monotonic 40.073979973 s; UTC minus monotonic 887107.027 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 48.811126000 s; monotonic 48.368035533 s; UTC minus monotonic 443090.467 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen11/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen11/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 22 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
