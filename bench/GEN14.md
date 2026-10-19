# Generation 14: exact BDS60 ratio enclosure

Decode throughput is **1.459178582840× rs1090**; CPR throughput is **0.933269340154×**. Lean throughput changed by -4.54% / -0.01% versus gen13. The 1.50× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.

The live BDS60 IAS/Mach ratio gate uses exact integer bounds on the software binary64 rounding error. It decides only when the entire interval proves an outside or inside result; the original rounded comparison remains the lazy fallback near either boundary. An unconditional theorem covers every rational input. [Implementation and proof evidence](../docs/GEN14-BDS60-RATIO.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 571.418060 | 833.800995 | 301761.550904 | 206802.343765 | 1.459178582840× |
| cpr | 879.566651 | 820.872588 | 196041.993866 | 210059.395966 | 0.933269340154× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen14/decode/samples.csv), [CPR samples](runs/gen14/cpr/samples.csv), [summary](runs/gen14/summary.json).

Timed commit: `cd749c8192a77a79ba683303f0b743f04ff6bc0c`. Actual worker SHA-256: `081a1cabff3d4e3fc58fb790e1e423cdeff672d35ee2a4006eefeed17728a9b7`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen14/binary-built.json), [fresh native inputs](runs/gen14/fresh-native-inputs.json), [commands](runs/gen14/commands.json).

The full gate passed with 185 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,410 exact plus 933,754 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen14/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All root and agent builds, tests, proofs, profilers, campaign jobs and reviews have stopped. Generation 14 is committed under the configured user identity; the working tree is clean. The frozen interleaver runs both modes with CPU 0 affinity and actual Windows power-plan captures. WSL2 and external host workload remain environmental limitations.” Guest bracketing observations: before: CPU 0 1.0%, aggregate 4.208333333333333%; after: CPU 0 1.0%, aggregate 0.4583333333333333%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen14/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 38.419655000 s; monotonic 38.419655275 s; UTC minus monotonic -0.275 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 45.804308000 s; monotonic 45.398294493 s; UTC minus monotonic 406013.507 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen14/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen14/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 28 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
