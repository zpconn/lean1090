# Generation 17: exact binary64 power table

Decode throughput is **1.669372647154× rs1090**; CPR throughput is **1.150460800400×**. Lean throughput changed by -0.03% / +11.13% versus gen16. Targets — 2.00× decode: unmet; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

The live software binary64 model obtains powers of two from an immutable format-exponent table spanning -1074 through 1023, with the original exact formula for every other integer exponent. Its unconditional equality proof propagates through the complete decoder and CPR tracking paths; every rounding operation remains unchanged. [Implementation and proof evidence](../docs/GEN17-POWER-TABLE.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 483.182346 | 806.611392 | 356867.342997 | 213773.325929 | 1.669372647154× |
| cpr | 706.958588 | 813.328143 | 243906.790195 | 212007.910318 | 1.150460800400× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen17/decode/samples.csv), [CPR samples](runs/gen17/cpr/samples.csv), [summary](runs/gen17/summary.json).

Timed commit: `0f7882f3f949118c6871a40bc012bb8a957a6a3d`. Actual worker SHA-256: `04b075aff3a04861d9cdb0e8d7388fe43a9fdfc0dc3a317de6a4525edb213a13`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen17/binary-built.json), [fresh native inputs](runs/gen17/fresh-native-inputs.json), [commands](runs/gen17/commands.json).

The full gate passed with 188 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,937 exact plus 933,227 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen17/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All collaborating jobs and project builds, tests, proofs and profilers stopped before this fresh build and both timed modes. Generation17 exact binary64 format-exponent table; both 2x targets retained. Host observations retained; no host-wide quiescence inferred.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.25%; after: CPU 0 0.0%, aggregate 0.20833333333333334%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen17/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 35.380669000 s; monotonic 34.790712886 s; UTC minus monotonic 589956.114 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 41.341865000 s; monotonic 40.739916922 s; UTC minus monotonic 601948.078 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen17/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen17/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 34 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
