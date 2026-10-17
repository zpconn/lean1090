# CPR and altitude source record and contract notes

These files are a checkpoint-1 reference specification. The capstone propositions
remain proof obligations. The witness and counterexample lemmas listed below
have actual Lean proofs; numerical certificate generation is not a proof of NL.

## Sources actually consulted

- ICAO Annex 10, Volume IV, fourth edition, July 2007, including the amendment
  pages in the acquired copy: §3.1.2.6.5.4(a–f), §3.1.2.8.6.3.1.2,
  §3.1.2.8.6.10. Acquired copy and extraction are in
  `.cache/sources/annex10-vol4.pdf` and `.txt`; the source URL is recorded in
  the main source inventory. M=1 is reserved there, so it does not establish
  rs1090's metre extraction rule.
- ICAO Annex 10, Volume III, Part I, amendment 77 pages dated 28 November 2002,
  §2.6.1–2.6.7, pages 5-88–5-94. The seven-page extract is readable from the
  [University of Ljubljana mirror](https://lso.fe.uni-lj.si/literatura/Razno/Avionika/modes/CPRencoding.pdf).
  The original complete edition cover is absent; the identified amendment and
  page date are the provenance, not an invented edition claim.
- Junzi Sun, *The 1090 Megahertz Riddle*, second edition:
  [ch.5, airborne position and altitude](https://mode-s.org/1090mhz/content/ads-b/3-airborne-position.html),
  [ch.6, surface position](https://mode-s.org/1090mhz/content/ads-b/4-surface-position.html),
  and [ch.13, altitude code](https://mode-s.org/1090mhz/content/mode-s/3-surveillance.html).
- rs1090 commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`: only for oracle
  policies/Float evaluation order and the expressly authorized fallback
  semantics, named `oracleAC12`, `oracleAC13`, and `oracleNLTable`.

Before designing these files, inspected lean-zip's `Zip/Spec/Deflate.lean`,
`Zip/Native/Inflate.lean`, the conformance test references under `ZipTest/`,
and `git show pre-split:PLAN.md` / `git show pre-split:PROGRESS.md`. The useful
distinction is independent mathematical properties versus implementation
refinement; both remain required here.

## Encoder independence

The altitude encoder computes inverse reflected Gray code and scatters the
independently calculated symbols into the published bit layout. It never
searches for a word accepted by the decoder. Gillham represents every multiple
of 100 feet from −1200 through 126700. Q=1 represents multiples of 25 feet
from −1000 through 50175. Invalid C patterns are rejected explicitly.

The CPR encoder follows ICAO §2.6.3, which first calculates a rounded latitude
`Rlat`, then obtains the longitude zone count from that rounded latitude. Using
the physical latitude for that lookup would be a specification error near a
transition. Rounding is `floor(x+1/2)`, including ties and negative coordinates.
Only 17 low bits are transmitted. Using 90° cells for surface data is the
equivalent form of the published 19-bit encoding with two bits discarded.
No global surface decoder or theorem is included, following the user's scope
clarification. Local longitudes follow the reference's unwrapped branch;
global longitude is reduced to [−180°,180°).

## Why the CPR hypotheses are necessary

`LocalAdmissible` requires geographic input/reference coordinates and strict
half-cell proximity to the **quantized** latitude and longitude. It does not
assume that decoding works or that its error is small. An ordinary physical
180 NM / 45 NM proximity statement needs a rounding margin to entail that
nearest-cell condition. `local_margin_needed` proves a concrete counterexample:
with reference (0,0), latitude −3+3/262144 degrees lies strictly inside the
nominal airborne 3° latitude range, but rounds to the half-cell tie −3° and
decodes as +3°. The unsafe band at the nominal range boundary has width at most
half a CPR step. `local_latitude_rounding_band` proves that latitude half-step
is less than 0.000024° airborne and 0.000006° surface, for both parities.
Longitude half-steps depend on NL; their exact bound is `dLon/(2*131072)`.
The local theorem works at NL boundaries because encoding already uses `Rlat`.

`GlobalAdmissible` allows two different physical positions. It requires:

1. Valid geographic coordinates for both reports.
2. The two independently quantized latitudes differ by less than 3/59°.
   This keeps the latitude zone-index expression inside its intended rounding
   interval. `three_nm_latitude_margin` proves that a 0.05° physical latitude
   displacement plus both worst-case half-step rounding errors still fits.
   `global_latitude_separation_needed` proves that dropping this condition lets
   positions (0,0) and (0.1,0) decode the earlier latitude as −6°, although the
   decoded pair passes the same-NL check.
3. Equal `nlTable` values on the two **encoder-side rounded latitudes**,
   `roundedLatitude .airborne false pEven.lat` and
   `roundedLatitude .airborne true pOdd.lat`. No hypothesis calls the global
   decoder or its latitude reconstruction helper. Proving reconstruction of
   those latitudes, and hence the successful decoder zone check, is part of the
   capstone. This condition may fail close to a transition; it never substitutes
   an assumption about the unquantized physical zones.
   The separate rejection theorem uses `SameDecodedZone` on reconstructed
   latitudes: `boundaryEven`/`boundaryOdd` are concrete mismatched-zone frames,
   and `zone_rejection_witness` proves rejection for both recency choices.
4. For a common zone count n>1, the circular separation of independently
   quantized longitudes is less than 180/(n(n−1)) degrees. This is the
   longitude zone-index rounding margin. At n=1 there is no longitude
   ambiguity. `global_longitude_separation_needed` proves that (0,0) and
   (0,0.1) alias the earlier longitude by −360/59° when this condition is
   dropped, while latitude and NL still agree.

No spherical-distance-to-coordinate-margin theorem is claimed in this draft.
The hypotheses are exact coordinate conditions implied by the intended
geometric operating envelope only after the appropriate rounding and latitude
conversion bounds are established. The temporal 30-second pairing policy is
an rs1090 compatibility policy; elapsed time alone does not imply a movement
bound. The older published algorithm specifies 10 seconds and a 3 NM bound.

`WithinResolution` states an actual coordinate-error result, bounded by half
the encoded latitude step and half the longitude step. Longitude distance is
circular, so antimeridian crossings do not generate a spurious 360° error.

## Non-vacuity proofs and cheap bounds

`Spec/CPRContracts.lean` proves `local_nonvacuous` for both media and both
parities, `global_nonvacuous` for (0,0) and (0.001,0.001), and
`global_witness_moves` that the reports differ in both coordinates. It also
proves the zone-rejection witnesses and all four margin/counterexample results
above. `Spec/Altitude.lean` proves `binary25_nonvacuous`,
`gillham_nonvacuous`, and `invalid_gillham_nonvacuous` using ordinary bounded
nonzero examples. `Spec/CPRFormula.lean` proves the NL domain contains 0° and
87°, and proves its exact equatorial convention. These use kernel evaluation
(`decide +kernel`) or ordinary rewriting, with no runtime decision shortcut.

## NL certificate plan and an actual oracle difference

The 58 thresholds were generated from the published transition formula. The
executable list stores 10⁻⁸-degree values. Equality with the transcendental
formula is required on **all attainable rational latitude grids**, not all
real numbers: a rounded table cannot agree at every real input.

`scripts/nl_certificate_candidates.py` independently generates 57 candidate
intervals using 80-digit Decimal arithmetic and the published formula. Each
interval contains both the candidate true transition and the executable rounded
threshold. The script checks by exact rational arithmetic that none of the four
latitude grids meets an interval; it completed successfully. The closest grid
to a rounded table value is a surface odd latitude near 45.54626723°, only
about 4.67e−9° away. A uniform ±1e−8° enclosure would therefore fail. The tighter
per-transition intervals are recorded in `nl-certificate-candidates.json` and
`Spec/CPRFormula.lean`.

These are **unproved candidates**. `CertifiesTransition` requires Mathlib
`Real.arccos` bounds in the Lean kernel; `AvoidsDecodableLatitudes` requires
the finite-grid exclusion proof. The NL capstone also asserts the final table
equality, so a successful candidate generator cannot substitute for that proof.

At exactly ±87°, Sun specifies NL=2 but rs1090's strict threshold yields NL=1.
`nl_87_discrepancy` proves 87° is attainable (airborne even grid index1900544),
`nlTable 87=2`, and `oracleNLTable 87=1`. This is not dismissed as an impossible
floating-point edge. A complete encoded-frame differential reproduction and
discrepancy entry are still needed in the post-approval differential suite.

## Altitude compatibility boundaries

The standard feet semantics are independent of plausibility policy.
`oracleAC12` preserves the pinned default `bds-infer` rule that a decoded
height greater than 50000 feet rejects the message, including valid Q=1
heights 50025–50175 and valid Gillham heights above that threshold. Its nested
option distinguishes a hard rejection from accepted but unavailable altitude.

`oracleAC13` documents the pinned M=1 extraction exactly: an overlapping OR
of `((raw & 0x1f80)/4)` and `(raw & 0x3f)`, then integer multiplication by
328084 and division by100000. M=1,Q=1 is rejected. Annex IV2007 reserves metric
coding; this is an explicitly authorized rs1090-derived policy, not a theorem
about a standardized metre representation. `decodeAC13` separately preserves
the simple metric interpretation described by Sun.

Sun's ch.5 describes TC20–22 GNSS heights as unsigned metre values, while the
pinned oracle applies the same barometric AC12 decoder and 50000-foot filter
as TC9–18. `decodeGNSSMetres` records the former source meaning; `oracleAC12`
records actual compatibility behavior. These distinct names prevent an oracle
policy from silently becoming a purported standard theorem.

## Commands completed

`lake env lean Spec/Altitude.lean`, `lake env lean Spec/CPR.lean`,
`lake env lean Spec/CPRContracts.lean`, and
`lake env lean Spec/CPRFormula.lean` each passed. Imported local modules were
compiled to their Lake olean path before checking dependents.
`python3 scripts/nl_certificate_candidates.py` completed and generated the
recorded candidates with all exact rational grid checks passing. No decoder
implementation, capstone proof completion, benchmark, or differential success
is claimed here.

## Executable tracking and numerical boundary

`Spec/CPRPolicy.lean` now specifies the pinned tracking transition, including
both parity caches, strict time windows, the out-of-order early return, failed
position cache updates, motion rejection, surface reference priority, airport
selection, evidence sets, BDS1,7 support union and saturating stability count,
the address-indexed stream fold, and the separate lowest-aircraft reference
update utility. Surface processing intentionally has no stale-reference age
or speed check: the pinned source does not apply those airborne guards there.
Its global-reference fallback also accepts a candidate without the 1 km
per-aircraft check when an earlier position already exists. The 500 km jump
check applies even to globally decoded airborne candidates; the source's
comment says otherwise, but the executed branch is unconditional on origin.
The reference-update callback receives all `AirbornePosition` fields: encoded
CPR data, altitude, resolved coordinates, NUCp, surveillance status, SAF/NICb,
altitude source, and time synchronization. Metadata is carried explicitly in
the report, so callbacks are not restricted to altitude-only decisions.

`Geography` explicitly supplies numerical local/global coordinate projection,
distance evaluation, and the ordered airport data. Exact mathematical decoder
defaults support policy reasoning. `Spec/CPRFloat.lean` supplies the concrete
`numericalGeography`: local/global coordinate equations use the pinned Float
operation order; their returned binary64 coordinates are represented exactly
as rational values. The haversine calculation uses radius6371 km and the
pinned order of sine, cosine, square root and atan2. This preserves rounding
before policy decisions, instead of rounding only the final ideal coordinate.
The standard NL(±87)=2 correction remains explicit in the Float table too.

Float NaN and positive/negative infinity distances have separate constructors,
so comparisons retain IEEE behavior rather than silently replacing them with
zero. This matters because haversine rounding near an antipode can make a
square-root input invalid. Reference coordinates and timestamps use finite
values; nonfinite geographic reference inputs are outside this interface.
The rational binary64 arithmetic module's finite-domain caveats apply to
timestamp/speed calculations. No transcendental or Float-rounding correctness
theorem is asserted here; these steps require post-approval differential
testing with the pinned oracle.

The policy witness lemmas `out_of_order_nonvacuous`,
`unresolved_cache_nonvacuous`, `surface_reference_nonvacuous`, and
`global_window_nonvacuous` compile. `#print axioms` for all four returned only
`propext`, `Classical.choice`, and `Quot.sound`. `CPRPolicy.lean` and
`CPRFloat.lean` passed `lake env lean`. Float smoke evaluation produced zero
distance for coincident origins and111.194927 km for one latitude degree,
and preserved explicit NaN/infinity cases. These smoke values are not a
differential-conformance claim. Exhaustive compiled altitude checks also
returned true for all1280 representable Gillham altitudes, all2048 Q=1 heights,
and re-encoding all8192 raw13-bit words that decode as valid Gillham.
