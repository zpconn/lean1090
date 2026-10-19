# Generation 18: exact dyadic rational-to-Float conversion

Decode throughput is **1.672168328366× rs1090**; CPR throughput is **1.342734836785×**. Lean throughput changed by +0.06% / +17.68% versus gen17. Targets — 2.00× decode: unmet; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

The live CPR rational-to-Float conversion assembles binary64 bits with exact integer arithmetic for nonzero rationals whose numerator magnitude is below 2^53 and denominator is exactly 2^k with k at most 1074. Zero remains positive zero, and all rejected inputs delegate to the unchanged original conversion. The equality proof covers every rational input and preserves the complete numerical-geography and tracking refinements. [Implementation and proof evidence](../docs/GEN18-DYADIC-CONVERSION.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 482.908888 | 807.504948 | 357069.427142 | 213536.772037 | 1.672168328366× |
| cpr | 600.725692 | 806.615314 | 287039.496223 | 213772.286500 | 1.342734836785× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen18/decode/samples.csv), [CPR samples](runs/gen18/cpr/samples.csv), [summary](runs/gen18/summary.json).

Timed commit: `c19e00dd6bd45c89e4d6238d4ea9973947625449`. Actual worker SHA-256: `60f7c3a9b63468db3d65565e59760eba1f10f58b5cc2fc69ee2c6dc283eebe4d`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen18/binary-built.json), [fresh native inputs](runs/gen18/fresh-native-inputs.json), [commands](runs/gen18/commands.json).

The full gate passed with 190 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,003 exact plus 933,161 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen18/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project build, proof, test, profiler and reviewer jobs stopped before timing; fixed and fresh 10M validation and independent archive review passed. Host observations are retained without claiming control of unrelated Windows activity.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.29130253849354976%; after: CPU 0 0.0%, aggregate 0.16666666666666666%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen18/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 35.083596000 s; monotonic 34.654484891 s; UTC minus monotonic 429111.109 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 38.083795000 s; monotonic 37.663432497 s; UTC minus monotonic 420362.503 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen18/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen18/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 36 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
