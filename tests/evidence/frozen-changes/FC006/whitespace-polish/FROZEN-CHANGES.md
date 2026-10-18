# Frozen-file change history

Every change to a file listed in `spec.lock` must have an entry here **before**
its lock hash is updated. Record the date, exact files and old/new SHA-256
hashes, reason, evidence, and explicit user approval. Approval is required for
each future locked-file change; this log does not authorize changes itself.
Keep prior entries intact and add a new entry for each approved change.

## FC001 — negative Gillham compatibility policy

- Date: 2026-10-16 (America/Chicago).
- Entry recorded: 2026-10-16T19:06:49-05:00, before any `spec.lock` update.
- Approval: the user explicitly approved the proposed two-file correction in
  chat on 2026-10-16, subject to permanent exhaustive AC13/AC12 differential
  coverage, a standards-cited discrepancy retaining the standard answer, and
  this history entry before refreshing the lock.
- Authorized patch: [ALTITUDE-COMPATIBILITY-PROPOSAL.diff](ALTITUDE-COMPATIBILITY-PROPOSAL.diff),
  SHA-256 `2243b40c0de55098d5330b928390962ac5117903fd9e6de7caea044f046904b3`.
- Previous `spec.lock` SHA-256:
  `97a48a89e3b254a2c85953b345560a3c4baa7478b9c80a2c768eeef8dd6b5a2d`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `Spec/Altitude.lean` | `b406ecf0368fc55555b1b5db4aa406de03daa3ddd43dfc0e15c64bc52b4714d5` | `c505219ed76335af94f417d68c896b8667575b2e765c8be8645068401c7dc7e4` |
| `Spec/AssignmentAltitude.lean` | `203ebc09ff09a4413474485271a04d938946a9a1c6270574b08fa5e718b6ada1` | `b1d8c183288f429ec40bc39c0c2ec845167819e691c3b565199ef71dd88520ec` |

Reason: pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30`
reports negative Gillham altitudes as missing. The separately named oracle
compatibility functions previously retained them, changing Comm-B BDS05
candidate membership on 33 corpus frames. `oracleAC13`, `oracleAC12` and the
independent assignment functions `compatibility13`, `compatibility12` now
mirror that receiver policy. Standard decoders/encoders/representability and
negative Q=1 binary25 values are unchanged. No capstone, guard, tolerance or
other locked file is changed.

Evidence available before approval: [review and counterexample](ALTITUDE-COMPATIBILITY-REVIEW.md)
and `tests/evidence/altitude-proposal/summary.json` retain the proposal's
12,288-code comparison against actual pinned `Message::from_bytes`: all
8,192 AC13 plus all 4,096 AC12 values, zero mismatches. The review also
kernel-checked independent assignment equivalence and AC12 receiver acceptance.
The concrete corpus counterexample is `a1000000920805003ffc0005c6e5`.

Post-application validation and final lock-update timestamp will be appended
below after executing the checks; the hashes above already describe the exact
approved patch on disk.

Validation before the hash refresh: `lake build Proofs lean1090` passed
(2,091 jobs); the unchanged `CheckHypotheses.lean`,
`CheckReceiverPolicy.lean`, `CheckAssignment.lean`, and module-graph audit
passed. All seven hypothesis predicates and `assigned` remain independent.
The review-definition export was regenerated and its exact-source check
passed. D010 and five complete-frame standard/compatibility probes are
recorded in `DISCREPANCIES.md` and `tests/evidence/negative-gillham/`.
The permanent exhaustive test is now wired into both full and quick
differential invocations; its fresh post-lock result will be recorded below.

Lock refreshed: 2026-10-16T19:09:05-05:00. New `spec.lock` SHA-256:
`c07e637c7086255949170936a94b0e7624016f99ae89e8117612bbfd1ff0b278`. Exactly the two entries
above changed; all other 59 frozen-file entries are byte-for-byte unchanged.

Post-refresh validation: `scripts/run_differential.sh --altitude-only` passed
all **12,288** code comparisons against fresh pinned rs1090 calls, plus the
Comm-B candidate regression, with zero mismatches. AC13 accepts all 8,192
frames; AC12 accepts 3,322 and rejects 774. Each field retains all 12 negative
Gillham values in the standard view and all 40 negative binary25 values in
both views. Complete outputs, hashes and commands are in
`tests/evidence/altitude-exhaustive/`. Rechecking all 33 prior corpus candidate
mismatches also passed; the standard view retains 25 barometric negative
heights and eight GNSS metre heights (the separate D007 rule), with evidence
in `tests/evidence/altitude-corpus-regressions/`.

`python3 scripts/check_lock.py` passes all 61 files. The unchanged full gate
was executed and still fails on the nine outstanding final theorem names;
this is not a completed project/full-suite claim. Build/audit output and
before/after lock snapshots are retained in `tests/evidence/frozen-changes/FC001/`.


## FC002 — reserved velocity oracle byte order

- Entry recorded: 2026-10-16T19:44:39-05:00 (America/Chicago), before refreshing any lock entry.
- Approval: the user explicitly approved exactly `docs/RESERVED-VELOCITY-PROPOSAL.diff`, SHA-256 `274e71b9d8107d8a3e86afcc4ded4fe6e754924dee0c35bfd599234b0c61931a`, touching only the two files below. No other frozen change is authorized.
- Previous `spec.lock` SHA-256: `c07e637c7086255949170936a94b0e7624016f99ae89e8117612bbfd1ff0b278`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `Spec/Semantics.lean` | `f759fd4a7a05dc88f95dd8d6e185bf1db47d4427cfc9be0b8c389c007246af59` | `782f6f2e1f486b4645c19178eb583f3be828dc540e7fe62b850550a393a4ddf8` |
| `Spec/Assignment.lean` | `ef6fa12da290362a6c8167cbf0bef767202a451d99bb8553131b078867cc1aaa` | `01d7ea1d9c37f0b9730643fa571b109c8c834f133d9996917c6b04283a310eb8` |

Reason: TC19 subtypes0/5/6/7 preserve a22-bit MSB-first raw field. Pinned rs1090's `ReservedVelocityData` lacks an endian attribute, so deku0.20.3 uses native byte order, giving8/8/6-bit little-endian chunks on the pinned x86_64 host. The approved patch adds that separately named oracle quantity to the semantic model and independent assignment. Standard/raw fields are retained. No theorem, guard, benchmark or other frozen file changes.

Evidence available before approval: `docs/RESERVED-VELOCITY-REVIEW.md` and `tests/evidence/reserved-velocity-proposal/summary.json` record16,511 fresh-oracle comparisons of the review prototype, including zero/all-ones/all22single-bit patterns and4096seeded random values per reserved subtype, plus31 generated failures. Message `9011223398040000000000000000` has standard/raw2097152 and oracle128. This is proposal evidence; actual-runtime validation will be recorded separately after execution.

Procedure evidence: the approved patch hash and all61 pre-change lock entries were checked, and `patch --dry-run` passed before applying the exact patch. Before/after source copies and the original lock snapshot are retained in `tests/evidence/frozen-changes/FC002/`. The after-lock snapshot, post-application validation and refresh timestamp will be added after those operations.

Validation before the hash refresh: `lake build Proofs lean1090` passed2098jobs, including the extended all-input refinement and its permitted-axiom report. The unchanged hypothesis, receiver, independent-assignment and module-graph audits passed; all seven hypothesis predicates and `assigned` remain decoder-independent. The review definition export was regenerated and its exact-source check passed. Logs are retained in the FC002 evidence directory.

Lock refreshed: 2026-10-16T19:47:06-05:00. New `spec.lock` SHA-256: `7d7651a2839380ca97b3c207e053ae373dafd9c6ae991a6e7e97be79c8379fac`. Exactly the two authorized entries changed; the other59 entries remain byte-for-byte unchanged. Both lock snapshots are retained under `tests/evidence/frozen-changes/FC002/`.

Post-refresh reserved-field validation: `python3 scripts/check_reserved_velocity_differential.py` passed16,480 fresh-oracle cases with zero mismatches. Each of subtypes0/5/6/7 has one zero, one all-ones, all22single-bit patterns and4096seeded random fields, with cardinality assertions. Actual Spec/Impl/independent assignment and complete JSON/CRC/consumption agree; the D011 standard raw value remains2097152 and its oracle value128. Complete retained evidence is in `tests/evidence/reserved-velocity/`. Both complete quick/full paths now require this regression. The broader diagnostic campaign is running separately and is not claimed to pass yet.

FC002 follow-up campaign completed:576,164 whole messages and101,244 direct register comparisons, with all required DF/70ADS-B/14Comm-B coverage. The only new finding is BDS10 DTE byte order (17,235 whole-message and5,740 direct mismatches). All other mandatory component strata passed. The unapproved single-file FC003 proposal is documented separately; no FC003 frozen edit or hash refresh has occurred. The full gate still fails on seven missing final theorem names. See docs/MESSAGE-DIFFERENTIAL.md and docs/DTE-BYTE-ORDER-REVIEW.md; all61 current hashes continue to match the FC002 after-lock snapshot.


## FC003 — BDS10 DTE oracle byte order

- Entry recorded: 2026-10-16T20:21:04-05:00 (America/Chicago), before refreshing any lock entry.
- Approval: the user explicitly approved exactly `docs/DTE-BYTE-ORDER-PROPOSAL.diff`, SHA-256 `1de67cd6b73644ebd60a9e24f3e8f3e6618dd58ef364a69ef8accea29ef6968a`, touching only Spec/CommB.lean. No other frozen change is authorized.
- Previous `spec.lock` SHA-256: `7d7651a2839380ca97b3c207e053ae373dafd9c6ae991a6e7e97be79c8379fac`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `Spec/CommB.lean` | `dabb5ec8bd0427291c211b773a88706141e0cb469705874bcd63ab6fd65a7835` | `d2af3fa179d6dd05823b5abb00f8e592ccc1858232dd61d96f881fe2735a7b45` |

Reason: the BDS10 DTE u16 field has no endian attribute in pinned rs1090/deku0.20.3, so its reported integer uses native little-endian byte order on the pinned x86_64 target. The approved oracle-only arm returns the first wire byte plus256 times the second. Standard/table values preserve the MSB-first status-bit representation. The independent assignment consumes the same explicitly named compatibility quantity. No validity predicate, score, theorem, benchmark, guard or other frozen file changes.

Evidence available before approval: the completed diagnostic campaign found17,235 whole-message and5,740 direct-register mismatches, all DTE-only. Message `a0000000100000000000011e478d` has standard/raw1 and oracle256. `python3 review/check_dte_proposal.py` tested the review-only candidate against fresh whole-message and direct Rust oracles on all65,536 codes and resolved every retained DTE mismatch by changing only that field. Standard/raw values and other BDS10 fields were preserved on71,278 distinct payloads. This is proposal evidence, not a claim that the implementation already passes. See docs/DTE-BYTE-ORDER-REVIEW.md and tests/evidence/dte-proposal/.

The approved patch hash, all61 pre-change lock entries and patch dry run were checked before applying the exact patch. Source before/after copies and the before-lock snapshot are retained in tests/evidence/frozen-changes/FC003/. The entire prior failed message campaign and root logs are preserved in tests/evidence/message-differential-before-FC003/ and differential-campaign-before-FC003/. Post-application checks and the lock-refresh timestamp will be appended after execution.

Validation before the hash refresh: `lake build Proofs lean1090` passed2098jobs after extending the existing Comm-B arithmetic bound proof with the new two-byte DTE bound. The initial failed build and repaired build logs are retained. The complete decoder/prefix refinement and explicit DTEOracleRefinement print only propext, Classical.choice and Quot.sound. The unchanged hypothesis, receiver, assignment and module-graph audits pass; all seven predicates and assigned remain decoder-independent. The review-definition export was regenerated and its exact-source check passed. The new native DTE differential adapter also compiled, including its kernel counterexample check.

Lock refreshed: 2026-10-16T20:24:58-05:00. New spec.lock SHA-256: `3922793a768183a46503e5024633ea5b1a8fbc00d64c0afabcdc9eabc1dace75`. Exactly Spec/CommB.lean changed; the other60 lock entries are byte-for-byte unchanged. Both lock snapshots are retained under tests/evidence/frozen-changes/FC003/.

Post-refresh validation: `python3 scripts/check_dte_differential.py` passed all65,536 DTE codes, with cardinality and permutation assertions, through both fresh pinned whole-message and direct-register oracles (131,072 comparisons). Actual Spec/Impl/assignment semantics and complete JSON/CRC/consumption match; standard raw values remain MSB-first. Both complete quick/full differential paths require this regression. Evidence: tests/evidence/dte-exhaustive/. The reproduced endian scan is recorded in D012 and tests/evidence/deku-endian-scan/: only reserved_data and dte are observable Mode S cases in this missing-attribute class; the separate CAT48 case is explicitly out of scope.

Complete post-FC003 diagnostic campaign passed:576,164 whole messages (566,792 exact oracle-view matches plus9,372 strictly classified D001 cases), all101,244 direct Comm-B comparisons exact, and all branch coverage checks. The altitude, reserved, exhaustive DTE and20,936,723 numeric comparisons passed; the44,228-call CPR stratum passed with only204 narrowly classified D009 cases. No unclassified oracle mismatch remains. Full evidence is under tests/evidence/differential-campaign/ and tests/evidence/message-differential/; failed pre-FC003 evidence is preserved separately. The unchanged full proof gate still fails on the seven outstanding final theorem names; no commit or push was made. FC004 is a separate unapproved proposal and has not changed either frozen guard or the live61-file lock.


## FC004 — freeze the passing message/component differential suite

- Entry recorded: 2026-10-17T12:16:19-05:00 (America/Chicago), before touching spec.lock.
- Approval: the user explicitly approved exactly docs/FC004-DIFFERENTIAL-FREEZE.diff, SHA-256 `eee626abcc93e917fe7d82e6f6f64f67ea54e62f227fd83e7c8515a74e52291f`, producing the86-entry lock `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`. No other frozen change is authorized.
- Previous61-entry lock SHA-256: `3922793a768183a46503e5024633ea5b1a8fbc00d64c0afabcdc9eabc1dace75`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `Tests/AltitudeDifferential.lean` | `not previously locked` | `b59f28adc245e46c6377c1601e924e357c789a8136df95627d80809a42334f29` |
| `Tests/CommBDifferential.lean` | `not previously locked` | `dbb8b735ccd30dc91ee4f72503db153428d59d0e0b71eb4b938fd7d2961b67cf` |
| `Tests/DTEDifferential.lean` | `not previously locked` | `35f0083599b6edfb54c51ec985f34a1b721c55a7641df52b71484f2b687f13d4` |
| `Tests/MessageGenerator.lean` | `not previously locked` | `4b6eb334dce721d5d95575164c764d344279a41453a5c3f44e5c721d43588a36` |
| `Tests/Numeric.lean` | `not previously locked` | `d03dbc25a5b8670b3cfb9258808e9ced685027064364b3fb5360cdfa7853e5f8` |
| `Tests/ReservedVelocityDifferential.lean` | `not previously locked` | `69a81bffbbcfd229f5bc485bc7d5891e6ab3b728f28497ac16a8fada1a6eb0ab` |
| `differential/cpr-oracle/Cargo.lock` | `not previously locked` | `4892c338e998d9b759e246cacde4f2761bd92378063fb996baf936e34dde92b7` |
| `differential/cpr-oracle/Cargo.toml` | `not previously locked` | `f2fc13ab79b59cd11872669c2df0882c1b519f286cf77d82878ffdc0ab6a471e` |
| `differential/cpr-oracle/src/main.rs` | `not previously locked` | `24cdd1e5878c61bf648b28f8d81adfe19a6d3410495500981c11e3e6299bc6e7` |
| `differential/message-oracle/Cargo.lock` | `not previously locked` | `7ce670ee666edb53d6a085ab634bb7c4be1eec5c5b642124f70fec03cacbd698` |
| `differential/message-oracle/Cargo.toml` | `not previously locked` | `008417f6916b75d663f2f48cf9a0af851b468956c47b421493d2aed55ea92b4c` |
| `differential/message-oracle/src/commb.rs` | `not previously locked` | `958ca83fc71a341bf6e63989cbe07fe0752dbc1aba1b686e2c4065d92ed5e522` |
| `differential/message-oracle/src/main.rs` | `not previously locked` | `2e519c55e63bf38d8424d804accf9778fd21f74677b8f482d7544ed4d45c3db1` |
| `lake-manifest.json` | `not previously locked` | `5f37c9b37568377682023c05a51252f854d1a15c897ef29734157a1c3895637f` |
| `lakefile.toml` | `not previously locked` | `fa8f7c3b587ae0ce1dbfb50a1e11ac61905f0070324fc942262cc01d006cbcf0` |
| `lean-toolchain` | `not previously locked` | `ca5f1f601d34c49079e38d7e7041eb0f2a9c227fbc1df0f404820069a052330c` |
| `scripts/FuzzCPR.lean` | `not previously locked` | `21d4c583f08fce9cdb71b6491d5004adbe2c248cc330c9a13a25398aba2f96e8` |
| `scripts/check_altitude_differential.py` | `not previously locked` | `ef5d444cadb3367ef11c76254ca66781265fe2abd26dc2882f3a7b459e59dc95` |
| `scripts/check_cpr_differential.py` | `not previously locked` | `2fc59ac629dbaf0ce68908d3960f2b6cab80f683b4fec0363868f007e06edd3e` |
| `scripts/check_dte_differential.py` | `not previously locked` | `7c7544eb04d4f7ce5bf38867eaff2e029d868f79c52a4863c353d395fbbaa1c1` |
| `scripts/check_impl_imports.py` | `44823e512aee811881f338b9c712205b33751132647889aada7b60805138983f` | `cf7d6960ae2521ab2c751839663432c5668b5e41c2fa9345135ee0a7d0104ce3` |
| `scripts/check_message_differential.py` | `not previously locked` | `88d3ea0acb9fa3936135a1720039d1e892faa23c007f2d7748dd37e88084135d` |
| `scripts/check_numeric.py` | `not previously locked` | `d7f4b0c4de049f6f48b20ec31a5c289590d4813113478cfc4d5c57256caea319` |
| `scripts/check_reserved_velocity_differential.py` | `not previously locked` | `0568c6dbd0b068771af43a434ce8927b3bdd40ffacd68d8fd25141fb78a1a647` |
| `scripts/frozen_paths.py` | `d636c8bbbe343f01f08031104448851c32aa493ad3f242c4bf45fde2f25ee937` | `67b05b953cc221b1c1a7717f41dbb1c4ab34755795384c782d59fcc41c16e2d2` |
| `scripts/run_differential.sh` | `not previously locked` | `ea7918b81763cbf45a1225859e533c50a3cb5b7d8a36303836f658f38975e067` |
| `tests/numeric_oracle.rs` | `not previously locked` | `16d7b0445539700c38ee8caa586afe9a9ee26d69bb7aad88852b7525378938ad` |

Reason: freeze the passing whole-message/component differential tests, generators, numeric checks, oracle dependencies and build/toolchain pins so their contracts cannot drift during implementation or optimization. The two guard changes enforce expanded membership and permit only six named differential adapters to import Impl while preserving semantic-module restrictions and rejecting their transitive Proofs imports. The other59 existing lock entries are unchanged. This does not claim coverage of stream-level tracking or upstream unit vectors: the latest user instruction identifies both as required additions before the remaining seven capstones resume.

Evidence: the complete post-FC003 diagnostic campaign passed576164 whole-message checks (566792 exact plus9372 narrowly classified D001),101244 direct Comm-B checks,65536 exhaustive DTE codes through two oracle paths,12288 altitude codes,16480 reserved-velocity cases,20936723 exact numeric checks and44228 CPR calls (44024 bit-identical plus204 D009). Every scoped DF/all70 ADS-B branches/all14 direct registers have coverage. tests/evidence/frozen-changes/FC004-proposal/ retains the exact patch application to disposable copies, all86 mutation checks, membership/deletion rejection checks and compiled import audit. No full-proof-gate or10M claim is made.

Before application in this session, every61 existing and25 added input hash, the approved patch hash and expected lock hash were verified; patch --dry-run passed. tests/evidence/frozen-changes/FC004/ retains the before lock, changed guard sources, all25 new sources, exact approved patch and expected after lock. Actual after snapshot and post-application lock/import audit output will be recorded after execution.

Exact approved patch applied and lock updated: 2026-10-17T12:16:32-05:00. The resulting86-entry lock has SHA-256 `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a` and is byte-identical to the approved proposed lock. Both lock snapshots and changed guards are retained.

Post-application checks completed 2026-10-17T12:18:54-05:00: python3 scripts/check_lock.py passes all86 hashes; python3 scripts/check_impl_imports.py passes20 runtime modules,30 frozen semantic modules, six named differential adapters and all six rejection self-tests. Logs are retained in the FC004 evidence directory. The separate stream-level and upstream-unit additions are in progress outside locked membership; no additional frozen file has changed.

Additional fresh-seed milestone validation passed: message seed1793658737 and Comm-B seed3319053038, recorded before generation, produced576164 whole messages (566829 exact plus9335 D001) and101244 exact direct-register checks with all coverage requirements and no unclassified mismatches. The retained fixed-seed results remain566792 exact plus9372 D001 on576164 messages and101244 exact direct checks. Both campaigns and every result are retained separately; see tests/evidence/fresh-seed-FC004/.


## FC005 — freeze revised stream tracking and upstream unit suites

- Entry recorded: 2026-10-17T17:01:00.694306-05:00 (America/Chicago), before applying the patch or changing `spec.lock`.
- Approval: the user explicitly approved exactly `docs/FC005-TRACKING-UNIT-FREEZE.diff`, SHA-256 `d6ae99c26491ccd24fffe1ca9e5e547ec934a8c47378ee58cfa6e58bf6823c2f`, producing the102-entry lock `e349a52673522259491c3420dde71980cddfc908fdbe05e81013fefa51fbd3db`. No other frozen change is authorized.
- Previous86-entry lock SHA-256: `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`.

| File | Old SHA-256 | New SHA-256 |
| --- | --- | --- |
| `scripts/check_impl_imports.py` | `cf7d6960ae2521ab2c751839663432c5668b5e41c2fa9345135ee0a7d0104ce3` | `23595396f7a837ec072af9adc88e0ef27bcd3d6bd0d73b7d39a5c439eaa90493` |
| `scripts/frozen_paths.py` | `67b05b953cc221b1c1a7717f41dbb1c4ab34755795384c782d59fcc41c16e2d2` | `52d7bc29ee813f0e3697fc3ded50b60f166ea591630eedf9cd2c0de70b0aa4be` |
| `scripts/run_differential.sh` | `ea7918b81763cbf45a1225859e533c50a3cb5b7d8a36303836f658f38975e067` | `15c086df8ba19a62e2ab600fe6cd9ae159e89a6b56ff05d6ad809c4c30519e41` |
| `Tests/Tracking.lean` | `new frozen member` | `196f549f758b2e4c78f263c12af1151482465a3670e96b714b5fe8885ffde6cd` |
| `Tests/Upstream.lean` | `new frozen member` | `49c0ded8fcc3016ea36221fb467332137b716626f7b5212cc80bea84b246a032` |
| `Tests/UpstreamCorpus.lean` | `new frozen member` | `28fbfcd5816440cc3f32c264ba8390993c9d29cba400e0fb4f13297006a90a2c` |
| `differential/tracking-oracle/Cargo.lock` | `new frozen member` | `f308bf25efaaf610a22cf0145837a36b2a478f687099ab043d185503d67f0786` |
| `differential/tracking-oracle/Cargo.toml` | `new frozen member` | `85b25b6c4d10fe461009618231dfd9c117e65613d503182b8da40be1a2638a7f` |
| `differential/tracking-oracle/src/main.rs` | `new frozen member` | `3fbd472310907068e885816810ad1503fbafbede364ea76e5494a7decde24374` |
| `review/upstream-units/assemble.py` | `new frozen member` | `4faf1ddda99a281adcf0b692fd3662bf74e65cfd0ba445ed9e4dcfcb3041fecc` |
| `review/upstream-units/inventory.py` | `new frozen member` | `5a0830c5c2edea5cd0031c1ba05aa6f87a8013fefd99db6978535eb6a60cc9ac` |
| `review/upstream-units/manual.py` | `new frozen member` | `5964857d807d5e894bcc1c97a715b39f4b5d14050b706614ec0f96aa6146fedf` |
| `review/upstream-units/port.py` | `new frozen member` | `ab7452beb54c431258898237ed51d17756de3c39a8e082dcdd18b109b30a40c9` |
| `review/upstream-units/run.py` | `new frozen member` | `c8d791a7b9e8737f50cf3286d52ba97830ad810850df74cbce35cc6438af04af` |
| `review/upstream-units/run_corpus.py` | `new frozen member` | `b7032df01f37f98b2c392cf5b4bd5d8902242603759a4bf1ee76c050736e8a89` |
| `review/upstream-units/rust_port.py` | `new frozen member` | `08c1b5053031d9df7a3b9fbc808f574cf3c0b90fe06fbad17de76fc331abf457` |
| `scripts/check_tracking.py` | `new frozen member` | `0ceee8daa0e504dcce12f8e499d699698c11c7f1ae111506f1e443c2e8e7b374` |
| `scripts/generate_tracking.py` | `new frozen member` | `64236d72a99fa448863c655e277f1955e4686abfd1d5bfd6edc170abb1b4a7d5` |
| `scripts/run_unit_tests.sh` | `new frozen member` | `1e53deeac74dd369ede0ccc299d44125b8f795bbdea2d1931195cf25529eb9ed` |

Reason: freeze the actual Impl.decodePositions versus rs1090 decode_positions differential, the upstream unit-vector port, their generators/oracles and recursive source membership. The revised tracking suite includes adjacent decoded1km thresholds, backward-time moving1200km/h thresholds, signed local-age windows, airport/altitude transitions and independent lifecycle prefixes. Every shadow result is asserted against actual rs1090 output including unresolved surface results. Source-linked labels distinguish45 cataloged real outcomes from diagnostic splits/duplicates/negative controls; the Lean tolerance remains1e-9degrees. Generated unit fixtures live outside the recursively frozen source directory. Mandatory complete quick/full differential runs now include tracking; the unchanged full gate already requires units. The import guard adds three exact named test adapters without changing runtime, frozen semantics or final-manifest restrictions.

Evidence before application: the revised full tracking diagnostic passed178297messages/446streams, all16460resolved positions bit-identical by observation, zero mismatches and31 targeted witnesses. The unit suite passed1011fixture assertions plus the172432-row corpus assertion, fresh pinned67frame/three-register comparisons and all rejection checks. The exact candidate seven-component campaign and a fresh-seed100kmessage/Comm-B campaign passed with only D001/D009. Nineteen comparator tests, three incorrect-shadow mutants,102file mutation tests,16deletion tests, recursive membership additions/symlink tests and six import rejection self-tests passed. Details and complete source snapshots: docs/FC005-TRACKING-UNIT-FREEZE.md and tests/evidence/frozen-changes/FC005-proposal/.

Application input verification: all86existing hashes and16new source hashes match; the three candidate guard/runner hashes and exact approved patch/proposed-lock hashes match. The patch dry run passes. review/upstream-units contains exactly the seven approved Python scripts, with no extra directory, bytecode, symlink or generated file. Input verification, the before-lock snapshot, approved after-lock candidate and before/added source snapshots are retained in tests/evidence/frozen-changes/FC005/. The other83existing entries must remain unchanged. Application and post-application results will be appended after execution.

Exact approved patch applied: 2026-10-17T17:01:12.785356-05:00. New spec.lock SHA-256 `e349a52673522259491c3420dde71980cddfc908fdbe05e81013fefa51fbd3db`;102entries match the approved candidate,83previous entries unchanged. Before/after snapshots retained. Post-application guards and integrated suites follow.

Post-application validation completed 2026-10-17T17:05:04.192022-05:00:102-file lock passes; import audit passes20runtime/30semantic/nineadapter modules and six rejection self-tests. The integrated unit suite passes1011fixture assertions and the172432-row corpus assertion; fresh67frame/three-register checks and rejection self-tests pass. The live integrated differential runner passed all seven components, including178297tracking messages/446streams with0mismatches and16460bit-identical positions (acceptance still1e-9degrees). Fixed whole-message result:576164cases,566792exact/9372D001;101244directregisters exact. Existing individual CPR204D009 cases remain narrowly classified; no new model omission. Fresh recorded seeds message1492453118/Comm-B3638208348 yield576164cases,566814exact/9350D001 and101244directregisters exact, with all coverage checks passing. This is100k generated per diagnostic campaign, not a final10M claim. The unit directory remains exactly seven scripts after execution. Logs, seeds, summaries and component exits are retained under tests/evidence/frozen-changes/FC005/. The user-authorized seven capstones now resume; the benchmark-worker FC remains a later approval checkpoint.
