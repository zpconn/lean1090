The CPR latitude-zone capstone is proved with the exact frozen statement, including all 57 transition certificates and equality between the executable table and the real `arccos` formula at every `DecodableLatitude`. Review date: 2026-10-17.

```lean
theorem Lean1090.Proofs.CPRLatitudeZones :
    Lean1090.Capstones.CPRLatitudeZones
```

The proposition in [Capstones.lean](../Capstones.lean) requires both:

- Every member of `Spec.CPR.nlCertificates` satisfies `CertifiesTransition` and `AvoidsDecodableLatitudes`.
- Every rational latitude satisfying `DecodableLatitude` has `nlTable lat = nlFormula (lat : ℝ)`.

The final theorem supplies the certificate and separation proofs itself. Its caller has no additional assumptions. The domain is the frozen union of airborne/surface, even/odd reconstructed latitude grids, restricted to −90° through 90°.

The proof has five parts:

1. [CPRCosineBounds.lean](../Proofs/CPRCosineBounds.lean) constructs the degree-32 cosine Taylor polynomial using exact rationals. Mathlib's `taylor_mean_remainder_bound` and `Real.abs_iteratedDeriv_cos_le_one` bound its error by `x^33 / 32!`, then by `10⁻²²` for `0 ≤ x ≤ 9/4`. Mathlib's proved `pi_gt_d20` and `pi_lt_d20` enclose π between `3.14159265358979323846` and `3.14159265358979323847`. The proved cosine Lipschitz inequality transfers the rational argument enclosure to `Real.cos (π*c)`. The resulting lower/upper functions bound that real cosine for every rational `0 ≤ c ≤ 2/3`.
2. [CPRTransitionCertificates.lean](../Proofs/CPRTransitionCertificates.lean) checks exact rational endpoint inequalities for all 57 frozen certificates, covering zones 59 through 3. For an endpoint latitude `a` and zone `n`, it bounds `cos(π*a/180)^2 * (1 − cos(2π/n))` strictly above or below `1 − cos(π/30)`. The cosine enclosure, positivity, square-root identities and strict `arccos` monotonicity turn these checks into the precise strict bounds on the frozen `transitionFormula`. The endpoint data are not assumed correct: `all_checks` is proved with `decide +kernel`.
3. [CPRLatitudeZones.lean](../Proofs/CPRLatitudeZones.lean) checks all four grid spacings against every certificate. For spacing `s` and interval `[L,U]`, the exact test is `floor(U/s) < ceil(L/s)`. The general `grid_avoids` proof shows this excludes every integer grid index, including negative latitudes after taking absolute value. Thus no decodable latitude lies in any closed certificate interval.
4. [CPRNLClassification.lean](../Proofs/CPRNLClassification.lean) verifies that each rounded table threshold lies inside its corresponding certificate and that the table index has the correct zone number. Grid separation then makes comparison against that rounded threshold equivalent to comparison against the true real transition. Analytic cosine/`arccos` lemmas translate this into a comparison against the real zone ratio. They explicitly handle Mathlib's saturated `arccos` cases, and prove the ratio is at least 2 and strictly below 60 for positive latitudes below 87°.
5. [CPRTableClassification.lean](../Proofs/CPRTableClassification.lean) converts those comparisons into the table's `takeWhile` count. An integer-floor equivalence and a kernel check of the 58 possible floor values, 2 through 59, establish the exact `Int.toNat` floor result. The final assembly discharges every intermediate premise with the preceding proofs.

The final classification handles zero, negative latitudes, exactly ±87°, and latitudes beyond ±87° separately. At zero it checks the frozen value 59; at ±87° it checks the frozen equality convention 2; beyond ±87°, including the poles, it checks value 1. The ±87° convention is already explicit in both frozen definitions; this proof does not replace it with a rounded transcendental calculation. The existing `Spec.CPR.nl_nonvacuous` and `nl_87_discrepancy` witnesses remain unchanged.

Review found no extra hypothesis in the final capstone, no omitted certificate or grid, and no use of a Float approximation as a mathematical premise. This theorem concerns exact rational latitude grids and the real formula; Float presentation remains a separate tested layer.

Executed validation:

```sh
lake build Proofs.CPRLatitudeZones
lake env lean Proofs/CPRLatitudeZones.lean
python3 scripts/check_lock.py
```

All three commands passed. The build log is `.cache/cpr-latitude-final-build.log`; the direct review log is `.cache/cpr-nl-proof-review.log`. The final theorem's axiom report is exactly:

```text
'Lean1090.Proofs.CPRLatitudeZones' depends on axioms: [propext, Classical.choice, Quot.sound]
```

The lock check reports all 102 frozen files match SHA-256. This review changed documentation only; the proof work added unfrozen proof modules and left the frozen statement and definitions unchanged. It makes no claim about completion of the separately running full differential gate or any benchmark measurement.
