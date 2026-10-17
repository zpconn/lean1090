# FC005 proposal: freeze stream tracking and upstream unit tests

**Proposal only; not applied.** FC004 is applied exactly; the current86-file lock has SHA-256 `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`. Both new suites are required before the seven remaining capstones resume. This proposal changes no Spec, Model, theorem statement, proof manifest, benchmark contract or runtime implementation.

## Exact approval artifact

[FC005-TRACKING-UNIT-FREEZE.diff](FC005-TRACKING-UNIT-FREEZE.diff)

SHA-256: **`1dc0630b4c1324fa8f85565cb349db9aee47a215db37ec2efbf1476d5843ecf7`**.

The exact patch changes three existing frozen files and updates spec.lock. It adds16 test/dependency files, preserves83 existing entries and changes three guard/runner hashes, for **102 locked files**. The [proposed lock](FC005-PROPOSED-spec.lock) has SHA-256 `3daafa7400ddc2a9bac399e53698e3a20ab74356a8630d0df9db71ed2d8d21ba`. The [16-file manifest](FC005-NEW-FILES.sha256) has SHA-256 `4f4a9101d59027075794889cff48cb477199e13805fa200817b1e4458647091a`.

## What changes

- `scripts/run_differential.sh` invokes the complete tracking checker after the existing individual-CPR checker in every complete quick/full campaign. It keeps the full corpus and all targeted/random tracking strata. Existing component-only commands still explicitly disclaim a complete suite. Diagnostic failure accumulation remains in force.
- `scripts/frozen_paths.py` locks the six tracking sources and ten upstream-unit sources, plus membership of the tracking Rust source tree and unit Python generator directory. Existing membership guards remain intact.
- `scripts/check_impl_imports.py` extends the existing named test-adapter allowance to exactly Tests/Tracking.lean, Tests/Upstream.lean and Tests/UpstreamCorpus.lean (nine total adapters). Those adapters can import Impl/platform/reference modules but cannot transitively import Proofs. Spec/Model/capstone restrictions and import-free manifests are unchanged.
- `scripts/run_unit_tests.sh` is already mandatory in the unchanged check_all.sh. Freezing it and its generators binds all expectations and source-coverage rules. Generated JSON/JSONL inventory and fixtures are reproduced each run from the pinned upstream source and the proposed frozen Python programs; they are not mutable independent expectations.

No Lake target is added or changed. The benchmark worker target still needs its own future approved FC after the remaining proofs, as requested.

## Tracking evidence

`python3 scripts/check_tracking.py --diagnostic` compares actual Impl.decodePositions against actual pinned rs1090 decode_positions on every original row. Timestamp/reference binary64 bits and all6903 pinned airports are supplied to the live numerical geography path. A separately observed sequential Rust replay supplies branch labels only after every result is checked against the actual batch output.

| Population | Messages | Streams | Resolved, all bit-identical | Matching unresolved |
| --- | ---: | ---: | ---: | ---: |
| Full timestamped corpus |172432|1|11347|161085|
| Synthetic multi-aircraft |5748|417|5028|720|
| Total |178180|418|16375|161805|

All59 mandatory branches occur;63 observed labels and complete counts are in [CPR-TRACKING-DIFFERENTIAL.md](CPR-TRACKING-DIFFERENTIAL.md). Pairing windows/parities/orders, cache replacement and early return, reference callbacks/updates, global/local selection, surface-reference precedence and airport checks, motion rejection and interleaved aircraft are covered. The required tolerance remains1e-9 degrees; observed maximum error is0. Final public aircraft state and shared reference also match. No frozen CPR-policy omission was found. Evidence is under tests/evidence/tracking-diagnostic/.

Independent comparator checks reject coordinate errors above tolerance, lost positions/rows, wrong routing/row identity and missing branch coverage, while accepting an intact trace and a sub-tolerance error. Five isolated runner orchestration checks verify mandatory quick/full invocation, preserved input arguments, component-only disclaimers, normal failure propagation and diagnostic continuation. These comparator/orchestration checks are distinct from the actual full tracking execution.

## Upstream unit evidence

The source audit accounts for153 test functions and603 assertion/expect sites across all three requested trees. It ports139 nonempty functions, records one empty upstream function, runs the Python full-corpus assertion separately, and documents12 scope exclusions. Every active in-scope Rust hex vector and source assertion site has an explicit disposition; loops, structure fields and successful-parser preconditions are expanded into Lean checks.

The final suite checks1011 Lean fixture assertions plus the upstream full-corpus assertion. That corpus assertion compares172432 actual successful Impl.decode results with172432 inputs, using the source reference(43.3,1.35) and executing Impl.decodePositions with all50385 timestamped ADS-B reports. Its observed12659 positions are not invented upstream expectations. The combined runner passed all1011 fixture assertions and the corpus assertion,67 unique full-frame plus three direct-register fresh pinned Rust comparisons, and seven intentional assertion failures/four malformed-fixture rejections. These checks are mandatory in the unit runner. Full combined final-run results are recorded in tests/evidence/upstream-unit-tests/summary.json.

[UPSTREAM-UNIT-PORT.md](UPSTREAM-UNIT-PORT.md) describes scope exclusions, exact source tolerances, Display/wrapper presentation dispositions and two upstream limitations: a helper-only metric-altitude closure and a vacuous conditional BDS50 penalty assertion. Initial adapter failures remain retained. No new frozen-model omission was found.

## Exact new locked files

```text
196f549f758b2e4c78f263c12af1151482465a3670e96b714b5fe8885ffde6cd  Tests/Tracking.lean
49c0ded8fcc3016ea36221fb467332137b716626f7b5212cc80bea84b246a032  Tests/Upstream.lean
28fbfcd5816440cc3f32c264ba8390993c9d29cba400e0fb4f13297006a90a2c  Tests/UpstreamCorpus.lean
f308bf25efaaf610a22cf0145837a36b2a478f687099ab043d185503d67f0786  differential/tracking-oracle/Cargo.lock
85b25b6c4d10fe461009618231dfd9c117e65613d503182b8da40be1a2638a7f  differential/tracking-oracle/Cargo.toml
c7168934991826f7391d2c4ffc350b7990194acae43c1ea58de8a071498a962b  differential/tracking-oracle/src/main.rs
a4c328f4880f9ad5be7bdc58ef86d0daa2c78eeac36cff8a83425de17c0d8902  review/upstream-units/assemble.py
d1e1483ddccf963e41535ebd8e95e768cca4f23225e89466ceb60ddd3e742593  review/upstream-units/inventory.py
ad66c8fa8f8ccfe97e5e7e02e8602514b152add547821bbde187c4e06d2b5ab2  review/upstream-units/manual.py
19b9bfaaa1b97b8cddc03ac0506494bed76727fe44f40828fc50e012adfeef46  review/upstream-units/port.py
98bee8e3b5e84d8b8a6dde4edb8fc7d52d1709cbf39fc925fb42c8c9512fd4ac  review/upstream-units/run.py
b7032df01f37f98b2c392cf5b4bd5d8902242603759a4bf1ee76c050736e8a89  review/upstream-units/run_corpus.py
50b1ba95b722baa7ba4911b0cbe5f6b07f7c2cd278fe717e95693bfacb1f1950  review/upstream-units/rust_port.py
995a99758552651a0944e8b8143a8babcbf425476398595a0f727a5017891272  scripts/check_tracking.py
f36ea39027a57591c3a23ad6f3675a6eef34626e83607de4129e98d5907812e9  scripts/generate_tracking.py
ba49bbf2e5e5211ee0997d2a2caf5a24479d3b13d4fdef79fb7123286b5a88e8  scripts/run_unit_tests.sh
```

## Proposal validation and application boundary

The proposed import audit passes20 runtime modules,30 frozen semantic modules, nine named test adapters and all six rejection self-tests. The exact combined patch was applied in a disposable copy: all102 hashes match; mutation of each102 file and deletion of each16 new file is rejected, as are ten new-member patterns. The unchanged lock self-tests still enforce lock-first rejection. Patch dry-run succeeds against the live FC004 state; its live86-file lock still matches.

All proposal sources, inventories, hashes, import logs, comparator/orchestration checks and lock-mutation results are retained under tests/evidence/frozen-changes/FC005-proposal/. FC004's fixed and freshly seeded100k message campaigns are retained separately; neither is represented as the final10M campaign. The full proof gate still lacks seven capstones. No optimization generation, commit, push or whole-decoder baseline has occurred.

**Apply only after explicit approval.** Verify all current inputs against this proposal again, record FC005's date, approval, exact old/new hashes and evidence in FROZEN-CHANGES.md before changing spec.lock, retain before/after lock snapshots, and apply only the approved patch. Then rerun the lock/import guards and integrated suites. The seven capstones stay paused until both suites pass and this freeze is approved and applied.
