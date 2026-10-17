# FC004 proposal: freeze the passing differential suite

**Approved and applied exactly on2026-10-17.** The user approved the patch and resulting86-entry lock by their hashes below. All input hashes were verified; FC004 was logged before the lock update, with before/after snapshots and passing lock/import checks in `tests/evidence/frozen-changes/FC004/`. The remainder preserves the reviewed proposal and its pre-approval evidence. The live lock now has SHA-256 `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`.

## Exact approval artifact

[FC004-DIFFERENTIAL-FREEZE.diff](FC004-DIFFERENTIAL-FREEZE.diff)

SHA-256: **`eee626abcc93e917fe7d82e6f6f64f67ea54e62f227fd83e7c8515a74e52291f`**.

This exact patch changes two existing frozen guards and updates `spec.lock`.
It preserves59 existing hashes, replaces the two guard hashes, and adds25
files, for **86 locked files**. It changes no Spec, Model, capstone, theorem
manifest, benchmark, tolerance, generator algorithm, comparison rule or
implementation. Its lock additions bind the suite that just passed, including
the permanent exhaustive DTE regression.

The [complete proposed lock](FC004-PROPOSED-spec.lock) has SHA-256
`4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`. The [25-file addition manifest](FC004-NEW-FILES.sha256)
has SHA-256 `13b42b04c5d197ebede7d6bb1430517628c264aad71cb39a84e44aa79cf45bb6`.
These are proposal artifacts; neither replaces the live `spec.lock`.

## Frozen inventory

The requested files are all included: `run_differential.sh`, every current
`check_*_differential.py`, `check_numeric.py`, every current
`Tests/*Differential.lean`, and the differential generators. The existing
`FuzzCommB.lean`, `FuzzBDS50.lean` and Comm-B generator coverage guard retain
their current hashes. Membership checks also reject unapproved additions
matching checker/adapter/generator patterns and Rust oracle source trees.

The proposal includes the suite's actual dependencies as well: the numeric
Lean checker and Rust generator; both Rust oracle harnesses and Cargo
manifests/locks; and the Lean toolchain, package lock and build configuration.
This prevents a frozen launcher from pointing at mutable test expectations or
another executable root. The implementation and CLI remain the code under test.
Freezing `lakefile.toml` means future executable-target or build-configuration
changes require an approved frozen-file change; that consequence is included
in this proposal.

Exact new files and their content hashes:

```text
b59f28adc245e46c6377c1601e924e357c789a8136df95627d80809a42334f29  Tests/AltitudeDifferential.lean
dbb8b735ccd30dc91ee4f72503db153428d59d0e0b71eb4b938fd7d2961b67cf  Tests/CommBDifferential.lean
35f0083599b6edfb54c51ec985f34a1b721c55a7641df52b71484f2b687f13d4  Tests/DTEDifferential.lean
4b6eb334dce721d5d95575164c764d344279a41453a5c3f44e5c721d43588a36  Tests/MessageGenerator.lean
d03dbc25a5b8670b3cfb9258808e9ced685027064364b3fb5360cdfa7853e5f8  Tests/Numeric.lean
69a81bffbbcfd229f5bc485bc7d5891e6ab3b728f28497ac16a8fada1a6eb0ab  Tests/ReservedVelocityDifferential.lean
4892c338e998d9b759e246cacde4f2761bd92378063fb996baf936e34dde92b7  differential/cpr-oracle/Cargo.lock
f2fc13ab79b59cd11872669c2df0882c1b519f286cf77d82878ffdc0ab6a471e  differential/cpr-oracle/Cargo.toml
24cdd1e5878c61bf648b28f8d81adfe19a6d3410495500981c11e3e6299bc6e7  differential/cpr-oracle/src/main.rs
7ce670ee666edb53d6a085ab634bb7c4be1eec5c5b642124f70fec03cacbd698  differential/message-oracle/Cargo.lock
008417f6916b75d663f2f48cf9a0af851b468956c47b421493d2aed55ea92b4c  differential/message-oracle/Cargo.toml
958ca83fc71a341bf6e63989cbe07fe0752dbc1aba1b686e2c4065d92ed5e522  differential/message-oracle/src/commb.rs
2e519c55e63bf38d8424d804accf9778fd21f74677b8f482d7544ed4d45c3db1  differential/message-oracle/src/main.rs
5f37c9b37568377682023c05a51252f854d1a15c897ef29734157a1c3895637f  lake-manifest.json
fa8f7c3b587ae0ce1dbfb50a1e11ac61905f0070324fc942262cc01d006cbcf0  lakefile.toml
ca5f1f601d34c49079e38d7e7041eb0f2a9c227fbc1df0f404820069a052330c  lean-toolchain
21d4c583f08fce9cdb71b6491d5004adbe2c248cc330c9a13a25398aba2f96e8  scripts/FuzzCPR.lean
ef5d444cadb3367ef11c76254ca66781265fe2abd26dc2882f3a7b459e59dc95  scripts/check_altitude_differential.py
2fc59ac629dbaf0ce68908d3960f2b6cab80f683b4fec0363868f007e06edd3e  scripts/check_cpr_differential.py
7c7544eb04d4f7ce5bf38867eaff2e029d868f79c52a4863c353d395fbbaa1c1  scripts/check_dte_differential.py
88d3ea0acb9fa3936135a1720039d1e892faa23c007f2d7748dd37e88084135d  scripts/check_message_differential.py
d7f4b0c4de049f6f48b20ec31a5c289590d4813113478cfc4d5c57256caea319  scripts/check_numeric.py
0568c6dbd0b068771af43a434ce8927b3bdd40ffacd68d8fd25141fb78a1a647  scripts/check_reserved_velocity_differential.py
ea7918b81763cbf45a1225859e533c50a3cb5b7d8a36303836f658f38975e067  scripts/run_differential.sh
16d7b0445539700c38ee8caa586afe9a9ee26d69bb7aad88852b7525378938ad  tests/numeric_oracle.rs
```

## Why the import guard needs an explicit amendment

The current header audit applies the semantic import restrictions to every
frozen Lean file. Freezing a differential adapter would therefore reject its
necessary `Impl` import. The proposed `check_impl_imports.py` change grants
that permission only to these six named adapters:

- `Tests/AltitudeDifferential.lean`
- `Tests/CommBDifferential.lean`
- `Tests/DTEDifferential.lean`
- `Tests/ReservedVelocityDifferential.lean`
- `Tests/Numeric.lean`
- `scripts/FuzzCPR.lean`

They may directly import `Impl` alongside the existing reference/platform
prefixes, and a compiled-graph check rejects any transitive `Proofs` import.
All existing Spec/Model/Capstones direct and transitive restrictions remain
in force, including rejection of a reference module importing an adapter.
The theorem manifests remain import-free fragments. The existing four
negative self-tests remain, with two additional rejection tests for the new
adapter boundary.

## Executed evidence

The complete FC003 diagnostic command finished with exit0:

```sh
scripts/run_differential.sh --diagnostic --corpus --generated 100000 --commb-boundaries .cache/gate/commb.csv
```

- 576,164 whole messages:172,432 corpus,100,000 encoded/corrupted messages,
  and303,732 structured Comm-B contexts.566,792 exact oracle-view matches;
  the other9,372 are strictly checked D001 cases.
- All101,244 direct register comparisons match. Coverage checks pass for
  every scoped DF, all70 ADS-B branches and all14 Comm-B registers.
- The65,536-code DTE regression matches both fresh oracle paths,131,072
  comparisons; the16,480 reserved TC19 cases and12,288 altitude codes plus
  the altitude candidate regression also pass.
- All20,936,723 numeric checks match exactly. CPR has44,228 calls:
  44,024 bit-identical results and204 narrowly checked D009 differences.
  The separate22 rational/binary64 half-cell ties remain documented outside
  admissibility. No unclassified oracle difference or contract failure remains.

Complete counts and retained observations are linked from
[MESSAGE-DIFFERENTIAL.md](MESSAGE-DIFFERENTIAL.md). Standard/oracle-view
presentation differences are separately retained; they are not compatibility
exceptions. The failed pre-FC003 campaign remains archived.

The proposed guards were tested without changing live frozen files:

- Compiled import audit:20 runtime modules,30 frozen semantic modules,
  six named adapters, and all six rejection self-tests pass.
- Disposable-copy checks reject changes to each of the86 proposed locked
  files, deletion of each of25 new entries, eight kinds of added inventory
  member, and duplicate lock entries. Lock-first full-gate rejection passes.
- The exact combined patch was applied to another disposable copy. Its
  resulting86-file lock and every proposed hash match, and the existing
  unchanged `scripts/test_lock.py` passes.
- `patch --dry-run` accepts the combined patch against the live FC003 state.
  The live `check_lock.py` still passes61 entries.

Evidence, proposed source snapshots, all old/new hashes and scratch-test logs
are retained under `tests/evidence/frozen-changes/FC004-proposal/`.
The root full proof gate still fails on the seven outstanding capstones;
this passing differential campaign does not claim a completed project, a10M
campaign, a passing final proof gate, or a performance result. The seven
capstones have not resumed, and no commit/push or optimization generation
has occurred.

## Application only after approval

Before applying this patch, record FC004 in `FROZEN-CHANGES.md` with the
approval, date, both guard old/new hashes, all25 new hashes, reason and
executed evidence. Retain the live before-lock snapshot. Verify every input
hash still matches this proposal, then apply the exact approved patch and
retain the after-lock snapshot. The record must precede the lock update.
Rerun the lock/import guards and the required gate after application.
No approval is inferred from the passing scratch tests.
