# Generation 25: reuse the numerator at an equal denominator

Decode throughput is **2.649719962329× rs1090**; CPR throughput is **1.947699046086×**. Lean throughput changed by -7.09% / -6.91% versus gen24. Targets — 2.00× decode: reached; 2.00× cpr: unmet. Both targets are required. A complete diagnostic and independent review precede the next optimization.

An exact identity arm returns the existing numerator when the selected denominator equals the rational denominator; the unequal branch retains the original integer multiplication and natural division verbatim. Unconditional equality covers all natural denominators and rationals, including zero/non-divisible denominators and non-dyadic values. No other arithmetic, threshold or fallback behavior changes. [Implementation and proof evidence](../docs/GEN25-SCORE-SCALING.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 309.933123 | 821.235983 | 556352.281198 | 209966.445175 | 2.649719962329× |
| cpr | 425.358628 | 828.470594 | 405380.280660 | 208132.915337 | 1.947699046086× |

CPR overhead is **0.669397240651 µs/message for Lean** and **0.041956313213 µs/message for rs1090**. This is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, calculated from exact integer median durations before division. It is a difference between independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Negative differences are retained without clamping.

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen25/decode/samples.csv), [CPR samples](runs/gen25/cpr/samples.csv), [summary](runs/gen25/summary.json).

Timed commit: `eaa7b36225b0d3ae29720a319295b0fac34e995b`. Actual worker SHA-256: `0383b0488863b837ebae02e78b00c86bba11eea96916ee0816b8db2dcb0ba189`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen25/binary-built.json), [fresh native inputs](runs/gen25/fresh-native-inputs.json), [commands](runs/gen25/commands.json).

The full gate passed with 202 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,542,528 exact plus 933,636 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen25/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All project tests, proofs, profilers and reviewer jobs are stopped. Root is running only the approved clean-commit fresh build and frozen CPU-0 ABAB measurements in decode and CPR modes; WSL2 host observations and power-plan captures are retained.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.29130253849354976%; after: CPU 0 0.0%, aggregate 0.08216926869350863%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen25/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 30.715851000 s; monotonic 30.715848060 s; UTC minus monotonic 2.940 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 34.085507000 s; monotonic 34.085503262 s; UTC minus monotonic 3.738 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen25/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen25/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 50 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
