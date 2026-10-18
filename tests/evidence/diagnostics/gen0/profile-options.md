# Diagnostic profiling options before gen1

Recorded 2026-10-18. This is tooling and generated-code inspection, **not a benchmark or an optimization**. No decoder workload has been profiled in this preparation. The only executable probes were `/bin/true` and a small Python startup/sum smoke. No runtime, frozen file, decoder, proof, system package database, sysctl or machine setting was changed.

## Available tools and executed probes

The initial PATH had no perf, Valgrind, heaptrack, bpftrace or gdb. It had strace, readelf, nm, objdump and `/usr/bin/time`. The host is x86_64 WSL2, Linux `6.6.87.2-microsoft-standard-WSL2`; `perf_event_paranoid=2`, `kptr_restrict=1`.

A read-only `perf_event_open` permission probe opened a **disabled** userspace software CPU-clock event successfully. A disabled hardware cycles event returned `ENOENT`. Neither probe enabled counters or measured a workload.

At the parent's request, downloaded official Ubuntu packages were extracted into `.cache/profiling-tools/root`; nothing was installed system-wide. The sandbox download initially failed DNS resolution. The same `apt-get download` with approved network access succeeded. Every downloaded file's SHA-256 was checked against `apt-cache show` metadata before extraction. Full hashes, versions, byte sizes and extraction commands are in `.cache/profiling-tools/packages.json`.

| Package | Version | SHA-256 |
| --- | --- | --- |
| valgrind | 1:3.22.0-0ubuntu3 | 744e081e5cf3d5c598b499dbb7d2250ea3f2869dde4a4d7b231fe6114f347d7d |
| libc6-dbg | 2.39-0ubuntu8.9 | c4b086cef3a6bbb6a90299969b3c0bf3867f40cb8e9bbbb0edfe5ae23f2c04f0 |
| linux-tools-6.8.0-147 | 6.8.0-147.147 | 7bf31034e1914ff171c2b82c48e1f17b5123b7e63e1d4ef0582877c45cc17cd0 |
| linux-tools-common | 6.8.0-147.147 | 7de54cebd84e7e30fb3c16a399b49a471d36d1b2b4a52dfcc2645dcf30c04167 |
| libtraceevent1 | 1:1.8.2-1ubuntu2.1 | fb03496824a22ffb70c67a92a66c4e369bbbefc934078a1fecda564364793d56 |

The local libc debug package matches installed libc6 2.39-0ubuntu8.9. `ldd` found only libtraceevent missing for perf; its package was then extracted locally. All other perf dependencies resolve to installed libraries. The kernel-specific generic metapackage was unnecessary: the actual executable is in linux-tools-6.8.0-147. The standard `/usr/bin/perf` package wrapper expects the current kernel name, so the local wrapper invokes that executable directly.

Executed download commands, from `.cache/profiling-tools/downloads`:

```sh
apt-get download valgrind=1:3.22.0-0ubuntu3 libc6-dbg=2.39-0ubuntu8.9 linux-tools-6.8.0-147=6.8.0-147.147 linux-tools-common=6.8.0-147.147
apt-get download libtraceevent1=1:1.8.2-1ubuntu2.1
```

Each package was unpacked by `dpkg-deb -x PACKAGE .cache/profiling-tools/root` after hash verification. Local wrappers set only their child process environment and are ready at:

- `.cache/profiling-tools/bin/perf`: perf **6.8.12**, with the extracted libtraceevent path.
- `.cache/profiling-tools/bin/valgrind`: Valgrind **3.22.0**, with its extracted tool directory and extra libc debug-symbol directory.
- `.cache/profiling-tools/root/usr/bin/callgrind_annotate`: **3.22.0**.

The following smoke probes passed:

```sh
.cache/profiling-tools/bin/valgrind --tool=callgrind \
  --callgrind-out-file=.cache/gen1-planning/callgrind-true.out \
  --log-file=.cache/gen1-planning/callgrind-true.log /bin/true
.cache/profiling-tools/bin/perf stat \
  -o .cache/gen1-planning/perf-stat-true.txt \
  -e cpu-clock:u,task-clock:u,context-switches:u -- /bin/true
.cache/profiling-tools/bin/perf record \
  -o .cache/gen1-planning/perf-record-smoke.data \
  -e cpu-clock:u -F 99 --call-graph dwarf,8192 \
  -- /usr/bin/python3 -c 'sum(range(1000000))'
.cache/profiling-tools/bin/perf script \
  -i .cache/gen1-planning/perf-record-smoke.data \
  > .cache/gen1-planning/perf-record-smoke.txt
.cache/profiling-tools/bin/perf stat \
  -o .cache/gen1-planning/perf-hardware-probe.txt \
  -e cycles:u,instructions:u -- /bin/true
```

The first Callgrind invocation used the identical expanded wrapper command and collected **174333 Ir** for `/bin/true`, exit 0. Software perf stat works; record collected one sample with a useful DWARF caller chain. Hardware `cycles:u` and `instructions:u` explicitly report **not supported**. Retained outputs are in `.cache/gen1-planning/`. These values are tool smokes, not decoder cost measurements.

## What the installed Lean runtime supports

Local toolchain is Lean 4.35.0, prefix `/home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0`.

- `lean --help` states `--profile` reports **elaboration/typechecking** time. `--stats` reports environment statistics. Neither profiles the native decoder.
- `src/lean/Init/System/IO.lean:589–594` documents `IO.getNumHeartbeats`: the current thread's number of small allocations. `include/lean/lean.h:490–524` shows increments in the small-object allocation path. This is available in the actual binary as `lean_io_get_num_heartbeats`; it can supply per-DF small-allocation deltas around the live diagnostic loop, with preparation/printing/drop outside the interval. It is not total allocated bytes, retained bytes, or RSS; large allocations and foreign allocator work need separate interpretation.
- `IO.allocprof` exists at `Init/System/IO.lean:220`, but the shipped runtime does **not** enable its statistics. Disassembly of `lean::allocprof::~allocprof` and its referenced literal in the existing worker show: “Allocation profiling data is not available, compile lean using `-D RUNTIME_STATS=ON`”. Rebuilding Lean's runtime would change the diagnostic artifact; do not silently treat allocprof as working or change the measured runtime.
- `/usr/bin/time -v` can provide process-level peak RSS, but not per-stage allocation counts. Callgrind counts instructions, not allocation bytes. Massif/DHAT cannot be assumed to count Lean objects correctly: the small-object/mimalloc allocator requires separate interpretation. Prefer the supported heartbeat count for small allocation counts initially.

## Generated C and the actual decoder binding

The frozen worker `.lake/build/ir/Bench/WholeDecoder.c` calls `lp_lean1090_Lean1090_Impl_decode`. The live body is `.lake/build/ir/Impl/Message.c:1027`, corresponding to `Impl/Message.lean`'s exact `Impl.decode`; it calls decodeFrame, frameAccepted and report, then constructs the complete Message result. All are normal exported symbols in `.lake/build/bin/lean1090-bench`; `nm` also finds Parity, ADS-B, Comm-B, Semantics, Binary64 and Rat/runtime symbols. The binary retains `.symtab`, `.eh_frame` and some debug sections. Generated module traces show `-O3 -ffp-contract=off`; there is no `-g` or frame-pointer preservation in that module compile command. Function-level attribution is available; do not promise exact Lean source-line attribution or frame-pointer-only call stacks.

Useful actual stage boundaries:

| Stage | Symbol suffix after `lp_lean1090_` | Generated source |
| --- | --- | --- |
| Whole proved path | `Lean1090_Impl_decode` | Impl/Message.c:1027 |
| Frame extraction | `Lean1090_Impl_decodeFrame` | Impl/Frame.c |
| Acceptance | `Lean1090_Impl_frameAccepted` | Impl/Message.c:102 |
| Full report/projection | `Lean1090_Impl_report` | Impl/Message.c:924 |
| Parity/address | `Lean1090_Impl_frameSyndrome`, `Lean1090_Impl_frameAddress`, `Lean1090_Impl_Parity_*` | Impl/Message.c, Impl/Parity.c |
| Raw ADS-B record | `Lean1090_Impl_frameADSB`, `Lean1090_Impl_decodeADSB` | Impl/Message.c, Impl/ADSB.c |
| ADS-B semantic fields | `Lean1090_Impl_Semantics_adsb` | Impl/Semantics.c |
| Comm-B inference | `Lean1090_Impl_frameCommB`, `Lean1090_Impl_inferCommB` | Impl/Message.c, Impl/CommB.c |
| Comm-B semantic fields | `Lean1090_Impl_Semantics_commB` | Impl/Semantics.c |
| Software binary64 | `Lean1090_Impl_Binary64_*` plus called Rat/GMP/runtime routines | Impl/Binary64.c and runtime |

Important inspection result: report's Lean source mentions frameCommB twice, but **generated C computes it once and reuses the result** (Message.c:995 and the map at 956). Counting source occurrences would falsely suggest duplicate inference. Stage claims must use executed code/call counts, not source estimates.

## Feasible diagnostic procedure, pending coordination

1. Keep the recorded benchmark and all frozen files unchanged. Build a separate, explicitly diagnostic driver that links the same unmodified Impl object files and calls the live `Impl.decode` exactly once per selected message, retaining the full result. Prepare inputs and select DF strata outside collection. Record the corpus hash, every selection rule/count, driver/source/object hashes and output/cardinality checks. No alternative decoder or legacy copy.
2. Use **Callgrind Ir** for deterministic instruction attribution, not wall-time performance. Start with a small declared corpus stratum to estimate cost, then choose the agreed full/stratified diagnostic run. `--collect-atstart=no --toggle-collect=lp_lean1090_Lean1090_Impl_decode` collects only the true entrypoint and its descendants. This deliberately excludes caller-side append/drop; document that distinction. A caller wrapper toggle can separately measure decode+append if desired. No decoder edits are required. The CLI support was verified by local `--help`.
3. Run separate strata by DF or dump/reset between named DF wrappers. Report counts, instruction totals and Ir/message; do not extrapolate an equal-per-DF sample as a whole-corpus average without actual corpus weights. Do not call this a new throughput result. `--separate-callers=3` or deeper caller separation can distinguish shared Rat/GMP/allocator cost reached from different stages; increase only when necessary. Keep raw callgrind files. Inclusive parent/child costs overlap: never sum inclusive rows as disjoint costs. Present a disjoint top-level stage partition plus separate nested details.
4. Supplement with native **perf software CPU-clock samples**, e.g. `-e cpu-clock:u -F 99 --call-graph dwarf,8192`. The tool supports `--delay=-1 --control=fifo:CONTROL,ACK`; enable after the diagnostic worker's ready signal, disable after its run, retain acknowledgments and sample-loss/unknown-stack counts. Alternatively attach only for a coordinated ready/run interval. Inspect that stacks actually reach the true decode symbol. Sampling perturbs execution and gives statistical attribution, not a benchmark median.
5. Add `IO.getNumHeartbeats` deltas to an uninstrumented diagnostic driver, prepared/retained equivalently. Verify generated C places count reads on the correct sides of the live calls. Report small allocations and harness overhead separately; do not modify runtime counters inside the decoder. Callgrind allocator call counts can cross-check event counts for supported allocation paths but are not byte counts.
6. Run one profiler at a time, with project tests/builds/benchmarks stopped. Stop profiling before the frozen ABAB measurement. The only success/performance comparison remains the unchanged headline worker and interleave protocol after a proved optimization passes the gate.

No profiled decoder run, diagnostic driver build, optimization, gate or comparative benchmark was performed by this preparation task.
