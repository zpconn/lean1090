# Synthetic CPR differential stratum

This component adds worldwide and boundary coverage to the geographically
limited flight corpus. It calls the actual frozen `Spec.CPR.encode`, exact
`decodeLocal`/`decodeGlobal`, numerical `decodeLocalFloat`/`decodeGlobalFloat`,
and admissibility/resolution predicates. The new Rust adapter calls the pinned
rs1090 public `airborne_position`, `airborne_position_with_reference`, and
`surface_position_with_reference` functions. The compared outputs now come
from `Impl.CPR.decodeLocal`/`decodeGlobal` and their `Impl.CPR.Policy` Float
adapters; each output must equal the frozen reference before oracle comparison.
`Proofs/CPRTracking.lean` proves these exact and numerical program refinements.
The Rust adapter does not copy the oracle decoders.
The oracle remains commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`, default
features, shipped dist settings. No frozen file or tolerance was changed.

Run from the repository root:

```sh
python3 scripts/check_cpr_differential.py --quick
python3 scripts/check_cpr_differential.py --full --output tests/evidence/cpr-synthetic-full
```

`--quick` generates 4,096 random physical positions; `--full` generates 65,536.
`--random-positions N` and `--seed N` allow additional campaigns. The default
seed is 10902026. Neither mode replaces the separately required whole-message
corpus and 100k/10M generated-message suite. The complete runtime decoder and
its remaining proofs are still required. The component first verifies the
frozen lock and oracle pin, then builds its Rust adapter offline from the
project-local Cargo cache. All inputs, outputs and metadata are retained.
The Lean adapter is built as the `cprDifferential` executable at `-O3`; its
runtime decoders are the proved `Impl` functions. Each run has a separate
temporary cache directory so concurrent campaigns cannot overwrite inputs.

## Generation and coverage

Every physical position and reference is supplied as exact rational
numerator/denominator pairs. Lean generates both 17-bit coordinate codes with
the actual reference encoder; Python never supplies precomputed CPR codes.
The only conversion to binary64 is the documented numerical boundary. The
oracle receives precisely the same code words and reference bit patterns.

- Random latitude and longitude are sampled uniformly in degree coordinates
  on a nanodegree grid, not uniformly by spherical area. Each position produces
  four local calls (airborne/surface × even/odd), a stationary global pair with
  both recency choices, and a moved global pair with both recency choices.
  Local references vary independently by up to a quarter latitude/longitude
  cell; references crossing the antimeridian are canonicalized. Moving pairs
  change each coordinate by up to 0.001°.
- All 58 frozen NL transitions, including 87°, are exercised in both
  hemispheres, both media and both parities. Offsets are −4, −2, −1, −½, 0,
  +½, +1, +2 and +4 of that medium/parity's latitude quantization step.
  This gives 4,176 required local combinations; airborne cases also exercise
  both global recency choices. An explicit cross-transition pair on either
  side of each boundary tests global zone rejection, for 232 more calls.
- The equator, ±87° and both poles have explicit strata, with invalid physical
  latitudes excluded and valid pole points retained. Longitude zero, −180°,
  and a point near +90° are included at each latitude. The antimeridian
  stratum uses longitude offsets in the applicable longitude quantization
  steps at nine latitudes, references across the seam, both media/parities and
  both global recency choices. Local output is compared on its original
  unwrapped branch; the comparator does not normalize away a discrepancy.
- Local references are tested one step inside, exactly at, and one step
  outside each signed latitude/longitude half-cell limit. The first 256 random
  positions also supply same-parity rejection cases and pairs displaced by
  one degree. Rejection outcomes are compared, not dropped. These cases do
  not assert that an ambiguous pair must reconstruct its generating truth.

The generator checks every required transition combination and, for runs of
at least 4,096 random positions, occupancy of all 216 cells in a 10° latitude ×
30° longitude grid. It preserves named-stratum duplicates deliberately.
For each legitimately encoded pair/reference satisfying the frozen
`LocalAdmissible` or `GlobalAdmissible`, the actual exact decoder must return
a position satisfying the actual `WithinResolution` predicate. Any such
counterexample fails the script and is retained; malformed same-parity pairs
are checked for rejection and never counted as applicable contract instances.

## Executed quick run

`python3 scripts/check_cpr_differential.py --quick` completed with 44,228 calls
from 4,096 random worldwide positions. All 216 geographic cells and 4,176
required transition combinations were covered. The 42,498 applicable
admissible cases all satisfied the exact resolution contract; no contract
counterexample was observed. These are executed finite checks, not universal
proofs.

| Stratum | Calls | Numerical matches | Documented D009 differences |
| --- | ---: | ---: | ---: |
| Worldwide local | 16,384 | 16,384 | 0 |
| Worldwide stationary global | 8,192 | 8,192 | 0 |
| Worldwide moving global | 8,192 | 8,192 | 0 |
| NL transition neighborhoods | 8,352 | 8,332 | 20 |
| NL straddling pairs | 232 | 232 | 0 |
| Equator, ±87°, poles | 888 | 844 | 44 |
| Antimeridian | 648 | 544 | 104 |
| Reference half-cell limits | 316 | 280 | 36 |
| Same-parity rejection | 512 | 512 | 0 |
| Separated pairs | 512 | 512 | 0 |
| **Total** | **44,228** | **44,024** | **204** |

The oracle accepted 42,905 calls and rejected 1,323. The frozen numerical
reference accepted 43,009. All 232 deliberate NL-straddling pairs and all 512
same-parity cases were rejected on both sides. The numerical tolerance remains
1e−9 degrees per coordinate; the maximum error among matching accepted
results was zero in this run.

The full compiled campaign also completed:
`python3 scripts/check_cpr_differential.py --full --output tests/evidence/cpr-synthetic-full`.
It used 65,536 random worldwide positions and **535,748 decoder calls**.
**535,544 results were bit-identical to rs1090**; the remaining **204** were
the same narrowly checked D009 boundary cases. The oracle accepted 534,389
calls and rejected 1,359. All **533,982** applicable admissible cases satisfied
the exact resolution contract, with **zero** contract counterexamples. The
same 22 exact-only half-cell ties were retained, and there were no additional
unclassified numerical or mathematical differences. Random moving pairs
included 40 zone-rejected calls on both sides. Full source hashes, counts and
complete traces are retained separately in `tests/evidence/cpr-synthetic-full/`.

## Precisely retained differences

The 204 numerical differences are instances of the already documented D009:
the standard reference uses NL(±87°)=2, whereas pinned rs1090 uses 1. The script
does **not** disregard polar cases generally. Every classified case must have
a reconstructed latitude exactly ±87°, and the oracle must match a test-only
counterfactual of the frozen Float adapter that changes only that equality
convention. Any other numerical mismatch fails. Full input/output bits and
the counterfactual result for every D009 case are in `differences.json`.
Source: the actually read ICAO Annex 10, Vol. III, Part I, amendment 77,
§2.6.2(f), §2.6.5–7, and the existing concrete parity-valid D009 pair in
`DISCREPANCIES.md`. This extends the executable evidence for that discrepancy,
including southern latitudes and local surface decoding.

There are 22 additional **exact-rational versus binary64** differences, all at
the deliberately exact half-cell reference ties. Every one has
`LocalAdmissible = false`; no admissible accuracy claim is being exempted.
Both the frozen Float adapter and actual oracle give the same result. The
actual rational floor equations choose a tie branch, whereas binary64
rounding can choose the adjacent cell or cause the subsequent half-cell test
to reject it. These are the published local floor equations of ICAO §2.6.5–6,
the strict margins in `Spec/CPRContracts.lean`, and the explicitly tested
rs1090/DO-260C arithmetic order in `Spec/CPRFloat.lean`.

For example, a surface odd message encoded from `(−45°,12°)` with reference
`(−2700/59°,12°)` yields exact latitude −45°. The frozen numerical adapter
and oracle both yield −46.52542372881356°, selecting the adjacent cell. The
reference is exactly half a cell from the encoded latitude, so the strict
admissibility hypothesis fails. The exact output is not claimed to equal
the binary64 output at that excluded tie. Each of the 22 fixtures, its exact
rational reference, codes, predicate result, and both outputs is retained in
`exact-differences.json`. An exact-vs-oracle difference outside these finite
conditions or D009 fails the script for investigation.

## Evidence

`tests/evidence/cpr-synthetic/summary.json` records counts, per-stratum results,
coverage, seed, oracle pin, source hashes and uncompressed artifact hashes.
The adjacent deterministic gzip files retain all exact inputs, encoded
fields, outputs and named-stratum metadata. `contract-failures.json` is empty.
The full campaign's corresponding evidence is under
`tests/evidence/cpr-synthetic-full/`. The evidence is generated by the current
unfrozen differential tools, not by
changing the reference or adding oracle exemptions to frozen files.
