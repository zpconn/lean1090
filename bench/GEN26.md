# Generation 26: skip exact small-dyadic rounding

Decode throughput is **2.672161039215× rs1090**; CPR throughput is **2.013985173701×**. Lean throughput changed by +2.37% / +5.91% versus gen25. Targets — 2.00× decode: reached; 2.00× cpr: reached. Both targets are reached. Stop for user review before further optimization or final deliverable work.

A pure integer guard returns an already representable small dyadic rational unchanged; every rejected input uses the previous software rounding algorithm. Unconditional refinement retains the frozen binary64 model for all rational inputs. No Float callback or trusted primitive changes. [Implementation and proof evidence](../docs/GEN26-ROUND-IDENTITY.md).

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
| decode | 302.761535 | 809.027578 | 569530.736459 | 213134.885249 | 2.672161039215× |
| cpr | 401.637128 | 808.891221 | 429322.858817 | 213170.813978 | 2.013985173701× |

CPR overhead is **0.573417886471 µs/message for Lean** and **-0.000790787093 µs/message for rs1090**. This is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, calculated from exact integer median durations before division. It is a difference between independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Negative differences are retained without clamping.

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all 172,432 prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen26/decode/samples.csv), [CPR samples](runs/gen26/cpr/samples.csv), [summary](runs/gen26/summary.json).

Timed commit: `c1a28b1027a60d5579e0d1f8dc92ca07bb518ed8`. Actual worker SHA-256: `37f8b00d9d49754a4afd27f21c16c585e4548cd8481ffe5cb83dc5949bf90370`. Oracle SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The fresh build regenerated 22 linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. [Build provenance](runs/gen26/binary-built.json), [fresh native inputs](runs/gen26/fresh-native-inputs.json), [commands](runs/gen26/commands.json).

The full gate passed with 202 unchanged correctness inputs. The separately verified fresh campaign contains 10,476,164 messages: 9,543,358 exact plus 932,806 documented D001; all 101,244 direct Comm-B cases match. Coverage is 32 DF attempts, 70 ADS-B branches and 14 registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen26/).

Environment: Intel(R) Core(TM) Ultra 9 285K; Linux-6.6.87.2-microsoft-standard-WSL2-x86_64-with-glibc2.39. Lean (version 4.35.0, x86_64-unknown-linux-gnu, commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc, Release); rustc 1.93.1 (01f6ddf75 2026-02-11). C compiler: clang version 23.1.0 (https://github.com/llvm/llvm-project ea7d852a70e8bdfaf601d6626a760f9771b2c4b4). Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`; raw plan output: `Power Scheme GUID: b96ff06e-8688-42eb-9c00-7c9f42465d2a  (Ultimate Performance)`.

The operator's recorded isolation note is: “All generation 26 fixed/fresh producers, proof builds, diagnostic and independent review jobs have completed and stopped. Root performs only this fresh committed build followed by the frozen decode/CPR interleaver; no other project work during timing. Host observations and their limits are retained.” Guest bracketing observations: before: CPU 0 0.0%, aggregate 0.12494793835901707%; after: CPU 0 0.9900990099009901%, aggregate 0.041684035014589414%. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen26/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: 0.

- decode: outer UTC 30.305958000 s; monotonic 29.868625732 s; UTC minus monotonic 437332.268 µs. Adjacent sample-label backsteps: 0.
- cpr: outer UTC 32.916320000 s; monotonic 32.504737975 s; UTC minus monotonic 411582.025 µs. Adjacent sample-label backsteps: 0.

[Structured reporting checks](runs/gen26/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen26/archive-verification.json) hashes all 48 original files copied byte-identically. Exactly two results rows were appended while preserving all 52 previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
