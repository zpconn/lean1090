# BDS50 proof-visible inference pilot

The first runtime path is complete and proved for every natural-number input,
including malformed and over-wide words. It is deliberately the baseline that
can be shipped correctly before optimization: exact rational representations of
finite binary64 values, rounded after every operation. It imports Std and model
types only. No Lean Float operation determines a candidate's acceptance.

The runtime is `Lean1090.Impl.BDS50.decode`. It performs the empty-MB shortcut,
all status/payload consistency checks, all physical bounds, track-rate sentinel
handling, the complete density and penalty calculations, the inclusive score
threshold, and construction of every reported field. Its result includes all
ten raw field codes, the five optional semantic quantities, and the exact score.
The preallocated output array stores that complete result. No projection,
rescoring or field calculation needed by the theorem is omitted from timing.

`Lean1090.Proofs.BDS50.refinement` proves:

```lean
∀ w, Lean1090.Impl.BDS50.decode w = Lean1090.Spec.bds50Reference w
```

The reference constructs the result from `Spec.commBEligible 20 none 0x50`,
`Spec.decodeBDS`, `Spec.commBValue`, and `Spec.cbCombinedScore`. BDS50 has the same
eligibility in DF20 and DF21; it does not inspect outer altitude. Separate
all-input lemmas prove hard-check and score equivalence. The frozen reference
is in `Spec/BDS50.lean`; the common result type is in `Model/BDS50.lean`.
`#print axioms` reports only `propext`, `Classical.choice`, and `Quot.sound` for
the refinement and its concrete witnesses.

The inclusive threshold has an attainable payload witness: decimal MB
`40532396648603648` has roll 22.5 degrees and track-rate 2.625 degrees/second,
with the other three fields absent. Its binary64 score is exactly -3 and it is
accepted. Decreasing or increasing the rate by one wire step gives a passing
or rejected neighbor. `exact_threshold_nonvacuous` proves all these facts by
kernel reduction; `pilot_nonvacuous` proves a complete accepted result exists.

## Measured result

The retained final run is `bench/evidence/bds50-pilot-quiet.json`. It was executed
on 2026-10-16 using CPU 0 of an Intel Core Ultra 9 285K under WSL2,
Linux 6.6.87.2-microsoft-standard-WSL2. The Windows power plan was read before and after the
run: **Ultimate Performance**, GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`.
The report retains raw command output, all timing samples, compiler versions,
source/binary SHA256 hashes, and the Lean C compiler invocation confirming -O3.
Rust used the pinned upstream default features and shipped dist profile,
including full LTO and overflow checks. Neither side used CPU-specific flags.

| Function | Median time for 47714 MBs | Messages/second |
| --- | ---: | ---: |
| rs1090 BDS50 candidate path | 82.957 ms | 575168 |
| `Impl.BDS50.decode` including full result | 343.297 ms | 138987 |

Lean achieves **0.2416× rs1090 throughput**, approximately 4.14× slower. This is
not the whole-message headline benchmark or a claim to have met the 10% target.
It demonstrates the actual cost of this proof-visible score implementation;
fixed-width verified arithmetic or other measured changes remain future work.

The primary result was designated as a confirmation run after all parallel builds,
proof checks and fixture generation had stopped. The earlier diagnostic run occurred while parallel validation was still active,
so benchmark isolation had not been established. It is retained in
`bench/evidence/bds50-pilot.json`: Lean143081msg/s, Rust581144msg/s, ratio0.2462×.
The later quiet run is slightly slower and remains the reported baseline; no
sample was selected to improve the number.

The workload is every DF20/21 MB from the fixed 172432-message corpus:
47714 payloads, selected without examining whether BDS50 accepts them.
Hex conversion and extraction of the seven MB bytes happen before timing.
Both persistent workers allocate an output vector/array before each sample,
decode all 47714 entries, and inspect/destruct the output after timing.
Both are pinned to the same CPU. The schedule is three AB warmup pairs followed
by 21 AB measured pairs, where A is Rust and B is Lean. Reported times are the
separate medians of the 21 measurements, not the median of per-pair ratios.

The Rust harness calls the pinned `TrackAndTurnReport::from_bytes`,
`density_score` and `penalty`, then applies the same inclusive threshold and
empty-MB shortcut as Comm-B inference. It retains the report and score. It
isolates BDS50 rather than charging other candidate decoders to Rust. Lean also
retains the lossless codes required by its model. There is no score cache,
lookup-table corpus shortcut or cross-message state on either side.

## Oracle differential and structured fuzzing

The comparison checks acceptance, every optional semantic value, and the exact
binary64 score as rationals. It also compares scores and values for candidates
that pass hard checks but fail the score gate; merely observing that both
reject is insufficient. Signed zero is compared numerically, matching the
finite rational model and its branch semantics.

| Input set | Accepted | Score-rejected | Hard/empty-rejected | Total |
| --- | ---: | ---: | ---: | ---: |
| Corpus DF20/21 MBs | 9813 | 828 | 37073 | 47714 |
| Structured generated MBs | 421 | 4026 | 57 | 4504 |

All outputs and score decisions matched the pinned Rust code. The structured
suite calls `Spec.encodeBDS` on named field assignments. It includes 4096
seeded assignments inside the hard field envelope; immediately neighboring
codes at both roll limits, groundspeed 700kt, TAS 80/600kt; unavailable-rate
sentinels; every status mask with zero/nonzero fields; penalty sign and magnitude
boundaries; 276 neighboring payloads at score-gate transitions; and the exact -3
payload with its two adjacent rate codes. An adaptive sweep covers 25 contexts
and all 1023 signed rate codes to find transitions using the exact score. It
never restricts the differential comparison to accepted generated inputs.

The 4504-case pilot is additional targeted testing, not a replacement for the
future 100k/10M full differential gate. Wider register generation is documented
in `docs/FUZZING.md`.

## Reproduce

```sh
lake build bds50Pilot Proofs.BDS50
CARGO_HOME="$PWD/.cache/cargo" CARGO_TARGET_DIR="$PWD/.cache/rs1090-target" \
  cargo build --locked --manifest-path bench/bds50/Cargo.toml --profile dist
lake env lean --run scripts/FuzzBDS50.lean .cache/bds50/generated.csv
python3 scripts/bench_bds50.py --generated .cache/bds50/generated.csv \
  --output bench/evidence/bds50-new-run.json
```

Run with WSL Windows interop available so `powercfg.exe /getactivescheme` can be
recorded. If interop fails, the report records the failure instead of inventing
a plan. The final retained measured run used a successful read. Set `BENCH_CPU`
only to choose another allowed CPU; the selected affinity is recorded.
