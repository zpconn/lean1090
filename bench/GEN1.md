# Generation 1: literal CRC modulus

Gen1 completed on 2026-10-18. Decode throughput is **0.209454235539× rs1090**, up from generation 0's 0.166318193807×. The 1.10× target is not met; work continues with a new diagnostic before selecting the next change.

The single runtime change specializes the final reduction in `Impl.Parity.step` to the literal modulus 16777216, with a proved bound. The function remains definitionally equal to the frozen algorithm; the component refinement proof adds `rfl`. Generated C no longer calls generic `BitVec.ofNat` inside each CRC bit step. The complete all-input `Impl.decode = Spec.decode` contract and all other capstones retain their exact types. No frozen source, trusted primitive or adapter path changed.

The pre-change [diagnostic cost breakdown](../docs/GEN0-COST-BREAKDOWN.md) attributed 47.61% of collected instructions to frame/CRC, the largest stage. Its instruction counts and sampling are diagnostics, not benchmark results. The timed results below use the unchanged frozen benchmark.

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 | Lean throughput gain vs gen0 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| decode | 4204.929276 | 880.740247 | 41007.110627 | 195780.765768 | 0.209454235539× | 26.08% |
| cpr | 4539.443247 | 881.841787 | 37985.274981 | 195536.209037 | 0.194262101984× | 23.70% |

Each mode retains all 48 samples: three AB warmup pairs followed by 21 measured AB pairs, A=rs1090/B=Lean, both pinned to CPU 0. All 172,432 messages are decoded from prepared bytes into retained output arrays. The headline includes the complete `Impl.decode` result. CPR starts with empty state each run and resolves 11,347 positions on both implementations. Medians use every measured sample; no sample was dropped, adjusted or rerun. These two medians are separate measurements, not a paired per-message speed claim.

[Decode samples](runs/gen1/decode/samples.csv), [decode metadata](runs/gen1/decode/metadata.json), [CPR samples](runs/gen1/cpr/samples.csv), [CPR metadata](runs/gen1/cpr/metadata.json), [machine-readable summary](runs/gen1/summary.json), [results.csv](results.csv).

## Commit, gate and fresh binary

Timed commit: `1cec196fd30565c70573fb28b7d555c4c4b71d32` (`gen1: specialize CRC remainder reduction to 24 bits`). The tree was clean, including untracked files, before the fresh build, before and after each mode and after timing. All 104 frozen entries passed the lock checks. Lock SHA-256: `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

The worker was freshly built with `lake --no-cache --rehash -v build lean1090-bench` after removing all project native artifacts covered by the committed Lean-source inventory. All 21 linked project C sources, objects and traces were regenerated from the committed sources. The actual timed binary is:

`9bdebf77cda47bb37d8105a7b2856be1157e007508238183fa393f7d471b9f43`

Both modes use that same binary; all native artifacts remain unchanged through timing. Oracle binary SHA-256: `208ae085ba9b9633a5f1fb1e1de8e7ee9deef70c83cb051377c5ac626a9dec10`. The retained source, C/object/trace and executable hashes bind the passing source gate to the binary actually timed.

[Fresh build and binary](runs/gen1/binary-built.json), [build log](runs/gen1/lean-fresh-build.log), [gate/source verification](runs/gen1/gate-verification.json), [command chronology](runs/gen1/commands.json), [complete provenance](runs/gen1/), [byte-identical archive check](runs/gen1/archive-verification.json).

Before the commit, `scripts/check_all.sh --full` passed all 23 capstone types and allowed axioms, 152 witness audits, import/dependency guards, unit tests and all seven differential components. Its 169 correctness-input hashes agree before/after and with the timed commit. The fixed-seed whole-message campaign passed 10,476,164 messages: 9,542,689 exact plus 933,475 documented D001. Fresh message/Comm-B seeds 3871650367/3100217476 passed 9,543,079 exact plus 933,085 D001, again totaling 10,476,164. Both campaigns also passed all 101,244 direct-register cases, all 32 DF attempts, 70 ADS-B branches and 14 registers, without coverage gaps or unclassified mismatches. CPR retains the checked D009 cases under the unchanged tolerance. [Gate and campaign evidence](../tests/evidence/optimization/gen1/).

## Environment and limits

Intel Core Ultra 9 285K, 24 logical CPUs, x86_64 WSL2 Linux 6.6.87.2, glibc 2.39. Windows Ultimate Performance plan GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a` was queried before and after both modes and remained unchanged across all four captures. Windows interoperability was used only for these reads; no host settings changed.

Pinned Lean 4.35.0 and Clang 23.1.0; project C uses generic x86-64, `-O3 -ffp-contract=off`, without CPU-specific flags. Actual effective Clang compile/link driver commands were checked with default configuration enabled and disabled. Rust 1.93.1, pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30`, shipped dist/full-LTO/overflow settings and default `bds-infer`. No Cargo or environment flag override was present. The frozen runner's required cached Cargo checks occur outside the measured samples.

All project test/proof/profile commands and subagents were idle before the fresh build and throughout both modes. Guest CPU 0 was idle in the one-second observations before and after; all-guest busy fractions were 0.162933% and 0.205255%. These limited observations do not establish host-wide isolation. WSL exposes no physical temperature, frequency or governor readings here. [Before observations](runs/gen1/before-host.json), [after observations](runs/gen1/after-host.json), [environment capture](runs/gen1/before-environment/environment.json).

Two decode sample labels step backward in UTC: order 31 by 0.243415 seconds and order 43 by 0.242197 seconds. The original labels and row order are preserved; durations use worker monotonic clocks. CPR has no adjacent UTC sample regression. Across each complete interleaver invocation, UTC elapsed was about 4.47 seconds (decode) / 4.46 seconds (CPR) shorter than monotonic elapsed; the independent review retains both clocks. No correction or rerun was made.

Results and provenance were copied byte-for-byte from the ignored timing directory only after timing finished, then the two rows were appended to results.csv. The [independent result review](runs/gen1/results-review.json) passed and is retained alongside the samples. No public push has occurred.
