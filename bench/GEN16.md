# Generation 16: shift and mask field packing

Decode throughput is **1.668888276454× rs1090**; CPR throughput is **1.029132958936×**. Lean throughput changed by +4.97% / +3.47% versus gen15. Targets — 2.00× decode: unmet; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

The live field-packing fold uses a natural-number shift for concatenation and a UInt64 mask for field widths below 64, with the original modulus fallback for wider fields. Its equality proof covers every list of natural-number widths and values, including over-wide values and unbounded accumulators. [Implementation and proof evidence](../docs/GEN16-PACK-FIELDS.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 483.018968 | 806.104693 | 356988.051037 | 213907.698959 | 1.668888276454× |
| cpr | 785.609215 | 808.496336 | 219488.260458 | 213274.930661 | 1.029132958936× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen16/decode/samples.csv), [CPR samples](runs/gen16/cpr/samples.csv), [summary](runs/gen16/summary.json).

Timed commit: `1593898c4425fb174ba4085ab68691feba28124e`. Actual worker SHA-256: `26e79af2c955a0dc8a0fdb1107d77b8c2b93ad31025fdd9e32112a37ee5c416f`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen16/binary-built.json), [fresh native inputs](runs/gen16/fresh-native-inputs.json), [commands](runs/gen16/commands.json).

The full gate passed with 187 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,217 exact plus 932,947 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen16/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project builds, proof checks, tests, profilers and reviewer jobs stopped before the fresh build and both timed modes. Source commit 1593898c4425fb174ba4085ab68691feba28124e is clean and uses zpconn attribution. External WSL2/Windows host workload is not controlled; retain every sample and power-plan capture.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.12494793835901707%; after: CPU 0 0.0%, aggregate 0.12505210504376824%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen16/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 35.220183000 s; monotonic 34.649469294 s; UTC minus monotonic 570713.706 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 42.505609000 s; monotonic 41.922077517 s; UTC minus monotonic 583531.483 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen16/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen16/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 32 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
