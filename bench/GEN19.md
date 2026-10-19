# Generation 19: exact natural shift and mask bit extraction

Decode throughput is **1.795418481745× rs1090**; CPR throughput is **1.432826926432×**. Lean throughput changed by +6.98% / +5.87% versus gen18. Targets — 2.00× decode: unmet; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

Four existing definitions use exact natural shifts and masks in altitude bits, Gray decoding, identity bits and signed payload thresholds. Unconditional proofs preserve every natural input and width, every 13-bit identity field, and the existing decoder refinement. No machine-word narrowing or corpus-specific branch is added. [Implementation and proof evidence](../docs/GEN19-SHIFT-EXTRACTION.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 451.410097 | 810.470031 | 381985.252758 | 212755.553450 | 1.795418481745× |
| cpr | 567.399785 | 812.985690 | 303898.599468 | 212097.214159 | 1.432826926432× |

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen19/decode/samples.csv), [CPR samples](runs/gen19/cpr/samples.csv), [summary](runs/gen19/summary.json).

Timed commit: `79cc25b8c6f104da94e2b532439fe6e9b47f72ea`. Actual worker SHA-256: `c8636e3760f9829c836a44befe239cb1f0334be6d46f93e100a4d97088f6fb7a`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen19/binary-built.json), [fresh native inputs](runs/gen19/fresh-native-inputs.json), [commands](runs/gen19/commands.json).

The full gate passed with 192 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,253 exact plus 932,911 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen19/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All other project builds, proofs, tests, profilers and agent work stopped before the fresh build and both timing modes. Root confirmed all three agents stopped. Full fixed and fresh 10M validation and independent gate/native/archive reviews passed; clean committed source 79cc25b8c6f104da94e2b532439fe6e9b47f72ea. Frozen ABAB protocol, CPU 0, both exact 2/1 targets; no sample adjustment.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.041684035014589414%; after: CPU 0 1.0101010101010102%, aggregate 0.20833333333333334%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen19/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 34.457376000 s; monotonic 34.015979171 s; UTC minus monotonic 441396.829 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 37.697565000 s; monotonic 37.278828367 s; UTC minus monotonic 418736.633 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen19/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen19/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 38 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
