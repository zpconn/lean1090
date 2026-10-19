# Generation 9: native masks for frame-field extraction

Decode throughput is **1.013687927839× rs1090**; CPR throughput is **0.756261100413×**. Lean throughput changed by +9.14% / +8.18% versus gen8. The 1.10× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.

The live frame-field extractor shifts the complete natural-number word before applying a native mask for widths below 64. Wider fields retain the original formula. Unconditional proofs preserve arbitrary inputs, including large shifts, zero widths and truncating subtraction. [Implementation and proof evidence](../tests/evidence/optimization/gen9/proof/summary.json).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 802.152680 | 813.132488 | 214961.570658 | 212058.923416 | 1.013687927839× |
| cpr | 1078.536448 | 815.655161 | 159875.913623 | 211403.063751 | 0.756261100413× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen9/decode/samples.csv), [CPR samples](runs/gen9/cpr/samples.csv), [summary](runs/gen9/summary.json).

Timed commit: `0fb54f0661c4cd589816277b1a8996a9969bdc44`. Actual worker SHA-256: `48dff3c83eebe85eaf857b3ce0c04e3b03e29a57cdb518f5c3d451532e16eccd`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen9/binary-built.json), [fresh native inputs](runs/gen9/fresh-native-inputs.json), [commands](runs/gen9/commands.json).

The full gate passed with 180 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,360 exact plus 932,804 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen9/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project build, test, proof, profiling and subagent jobs are stopped. The runner performs its recorded fresh build and provenance preparation before the frozen interleaver. During both modes only brief status reads occur. WSL guest observations do not establish Windows host-wide isolation or expose all thermal/frequency state.” Guest bracketing observations: before: CPU 0 0.9900990099009901%, aggregate 0.2896152254861398%; after: CPU 0 0.0%, aggregate 0.08336807002917883%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen9/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 44.105363000 s; monotonic 43.008354871 s; UTC minus monotonic 1097008.129 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 49.932137000 s; monotonic 49.457424357 s; UTC minus monotonic 474712.643 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen9/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen9/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 18 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
