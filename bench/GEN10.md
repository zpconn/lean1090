# Generation 10: exact QNH field-code table

Decode throughput is **1.168948811789× rs1090**; CPR throughput is **0.790786943138×**. Lean throughput changed by +14.80% / +4.98% versus gen9. The 1.10× decode threshold is reached. Stop for user review before further optimization or final deliverable work.

The live BDS40 QNH helper reads an immutable table covering all 4,096 twelve-bit field codes. Each entry retains the exact software-binary64 literal rounding, multiplication and addition in `raw * 0.1 + 800`. Unconditional proofs preserve every natural-number payload, including implausible codes and over-wide words. [Implementation and proof evidence](../tests/evidence/optimization/gen10/proof/summary.json).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 698.769176 | 816.825398 | 246765.320971 | 211100.194022 | 1.168948811789× |
| cpr | 1027.401995 | 812.456083 | 167833.039880 | 212235.471686 | 0.790786943138× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen10/decode/samples.csv), [CPR samples](runs/gen10/cpr/samples.csv), [summary](runs/gen10/summary.json).

Timed commit: `d51a3040984beb6f0f96b0f4fcf225ba2622a7e0`. Actual worker SHA-256: `e2b7efcfa6aa3a3f2e234aa97d95fabc59a4a8c15562b098f20f1f0ab4f95586`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen10/binary-built.json), [fresh native inputs](runs/gen10/fresh-native-inputs.json), [commands](runs/gen10/commands.json).

The full gate passed with 181 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,536 exact plus 933,628 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen10/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project build, test, proof, profiling and subagent jobs are stopped. The runner performs its recorded fresh build and provenance preparation before the frozen interleaver. During both modes only brief status reads occur. WSL guest observations do not establish Windows host-wide isolation or expose all thermal/frequency state.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.125%; after: CPU 0 0.0%, aggregate 0.125%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen10/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 42.200469000 s; monotonic 40.751832430 s; UTC minus monotonic 1448636.570 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 49.247358000 s; monotonic 48.389505361 s; UTC minus monotonic 857852.639 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen10/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen10/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 20 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
