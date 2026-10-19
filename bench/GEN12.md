# Generation 12: exact byte conversion in UInt64 chunks

Decode throughput is **1.375845527971× rs1090**; CPR throughput is **0.894487665175×**. Lean throughput changed by +10.40% / +7.36% versus gen11. The 1.50× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.

The live byte converter folds up to sixteen bytes in UInt64 chunks, using a tail-recursive prefix reader that returns the existing suffix without copying its list nodes. Exact natural-number arithmetic combines the final chunks; longer lists retain the original unbounded fold. An unconditional theorem covers every byte list. [Implementation and proof evidence](../docs/GEN12-BYTE-WORDS.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 595.109526 | 818.778780 | 289748.344576 | 210596.566755 | 1.375845527971× |
| cpr | 925.466896 | 827.818723 | 186318.928041 | 208296.810895 | 0.894487665175× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen12/decode/samples.csv), [CPR samples](runs/gen12/cpr/samples.csv), [summary](runs/gen12/summary.json).

Timed commit: `0592f80708c92e283a4c802f04b5889d5d69a3aa`. Actual worker SHA-256: `e2c212b470c6b331cf1b11a095adb991392b7aa7a89dea5421018acb6bcbbbee`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen12/binary-built.json), [fresh native inputs](runs/gen12/fresh-native-inputs.json), [commands](runs/gen12/commands.json).

The full gate passed with 183 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,025 exact plus 933,139 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen12/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All collaborating agents confirmed their validation/review jobs stopped. Fixed and fresh 10M campaigns and independent reviews are complete. No other project build, proof, test or profiler runs during timing. Host observations are retained without inferring Windows-wide isolation.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.08336807002917883%; after: CPU 0 0.0%, aggregate 0.08333333333333333%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen12/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 37.938540000 s; monotonic 37.938535501 s; UTC minus monotonic 4.499 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 46.517860000 s; monotonic 46.517854797 s; UTC minus monotonic 5.203 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen12/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen12/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 24 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
