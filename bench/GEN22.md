# Generation 22: reuse the parsed word for CRC

Decode throughput is **2.203718886895× rs1090**; CPR throughput is **1.715366461888×**. Lean throughput changed by +12.24% / +11.28% versus gen21. Targets — 2.00× decode: reached; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

The structural parser returns its existing raw word along with the frame, and the decoder computes CRC directly from that word. Unconditional parser equality and the standard encoder syndrome theorem preserve the complete decoder refinement, including malformed inputs, parity and spare bits. [Implementation and proof evidence](../docs/GEN22-PARSED-WORD-CRC.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 363.850216 | 801.823593 | 473909.296786 | 215049.795872 | 2.203718886895× |
| cpr | 470.849331 | 807.679151 | 366214.813630 | 213490.715696 | 1.715366461888× |

CPR overhead is **0.620529339102 µs/message for Lean** and **0.033958650367 µs/message for rs1090**. This is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, calculated from exact integer median durations before division. It is a difference between independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Negative differences are retained without clamping.

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen22/decode/samples.csv), [CPR samples](runs/gen22/cpr/samples.csv), [summary](runs/gen22/summary.json).

Timed commit: `74db41344a9d721c600c554b7e2e0f37b65de938`. Actual worker SHA-256: `08b905a7f7990dca51f343fea7d8c75107398ce250cf4c453ebb1943d7ccea5f`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen22/binary-built.json), [fresh native inputs](runs/gen22/fresh-native-inputs.json), [commands](runs/gen22/commands.json).

The full gate passed with 197 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,883 exact plus 933,281 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen22/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All agent tasks are stopped; the completed final reviewer was interrupted after its passing receipt was committed to enforce the timing hold. A host process check found no active project builds, proofs, tests or profilers. Fixed and fresh campaigns, independent reviews and duplicate cleanup finished before timing. Root performs no concurrent build, proof, test, profiler or archive work. Windows host activity is not controlled; power-plan and process captures are retained.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.16666666666666666%; after: CPU 0 0.0%, aggregate 0.08340283569641367%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen22/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 32.092190000 s; monotonic 31.541272952 s; UTC minus monotonic 550917.048 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 35.129078000 s; monotonic 34.579490458 s; UTC minus monotonic 549587.542 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen22/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen22/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 44 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
