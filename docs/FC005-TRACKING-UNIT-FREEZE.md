# FC005 revised proposal: freeze stream tracking and upstream unit tests

**Proposal only; not approved or applied.** This replaces the first FC005 proposal, archived with its sources and results under `tests/evidence/frozen-changes/FC005-review-v1/`. The live FC004 lock still has86 entries and SHA-256 `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`. The seven capstones remain paused until this revised freeze is approved and applied. No Spec, Model, theorem statement, benchmark contract, runtime implementation or proof changed in this revision.

## Exact approval artifacts

- [Exact patch](FC005-TRACKING-UNIT-FREEZE.diff): SHA-256 **`d6ae99c26491ccd24fffe1ca9e5e547ec934a8c47378ee58cfa6e58bf6823c2f`**.
- [Proposed102-entry lock](FC005-PROPOSED-spec.lock): SHA-256 **`e349a52673522259491c3420dde71980cddfc908fdbe05e81013fefa51fbd3db`**.
- [Manifest of16 new sources](FC005-NEW-FILES.sha256): SHA-256 `dad99f1478350f9b4a8df363bdd1c04690e76efec31aec270ce16c7f8ca2f6a7`.

The patch changes exactly three existing frozen files (`scripts/frozen_paths.py`, `scripts/check_impl_imports.py`, `scripts/run_differential.sh`) and updates `spec.lock`. It adds16 source/dependency entries, preserves83 existing entries and changes three guard/runner hashes. The new source bodies are retained under `tests/evidence/frozen-changes/FC005-proposal/proposed/` and bound by the lock and manifest.

## Requested revisions

1. **Decoded threshold witnesses.** Both surface parities and both shared-reference contexts bracket1km within one latitude code. Decoded distances are0.9989320840756828/1.00020460902355km (even) and0.9990399251729599/1.0003340183402822km (odd). Backward-time moving cases bracket1200km/h for both parities; signed local ages just below, exactly at and just above−180s remain admissible, with nonzero movement. Positive180s moving boundaries remain covered. Metrics and required targeted checks prevent accidental coverage by unrelated corpus rows.
2. **State transitions.** A labeled EHAM→LFBO lifecycle checks airport clearing on airborne, altitude reset on surface, lookup when no airport is set, and preservation of an existing airport even when the nearest airport changes. Six independent prefixes expose intermediate states through the real Lean final-state comparator, so later messages cannot mask an incorrect update.
3. **Label integrity.** Every routed oracle replay asserts actual position equals the shadow candidate after the airborne motion gate, or the surface candidate unconditionally, including None. It also asserts actual public position, altitude, airport, seen-register evidence and shared reference. Batch/replay assertions validate labels against actual `decode_positions`; they do not impose bit identity on Lean. Three disposable incorrect-shadow mutants are rejected. The Python checker requires integrity flags, prediction consistency, known/unique labels and31 concrete targeted witnesses including prefix terminals.
4. **Honest coverage.** [The tracking report](CPR-TRACKING-DIFFERENTIAL.md) maps every label to exact pinned `cpr.rs` lines and its role. The result covers45 distinct cataloged real decision/result outcomes,75 required diagnostic labels and79 observed labels. Aliases are deduplicated; surface age/order labels are explicitly negative controls for rules rs1090 does not have. This is finite observed outcome coverage, not a count of all Rust branches or an exhaustive control-flow claim.
5. **Position tolerance.** Lean/rs1090 comparisons pass at1e-9degrees. Bit identity is reported separately. Independent comparator checks accept a non-bit-identical5e-10-degree change and reject a2e-9-degree change.
6. **Recursive unit membership.** The candidate guard includes every file or symlink recursively under `review/upstream-units/`, with no extension, depth or cache exclusion. Nested packages, native modules, bytecode, data files and symlinks cannot enter silently. Generated JSON/JSONL moved to `tests/evidence/upstream-unit-tests/generated/`; all seven reproduced files are byte-identical to the previous expectations. Historical copies are labeled snapshots. Bytecode creation is disabled in the unit entrypoint and subprocesses. No generated file remains in the source tree.

## Gate wiring and boundaries

The proposed `scripts/run_differential.sh` invokes the complete tracking checker after individual CPR in every complete quick/full campaign. It preserves the full corpus, targeted/random strata and diagnostic failure accumulation. Component-only modes still disclaim a complete suite. The unchanged `check_all.sh` already requires `scripts/run_unit_tests.sh`.

The import guard adds exactly `Tests/Tracking.lean`, `Tests/Upstream.lean` and `Tests/UpstreamCorpus.lean` to the named adapter allowance. All nine adapters may import Impl/platform/reference modules and may not transitively import Proofs. Runtime, frozen semantic and import-free manifest restrictions remain unchanged. Tracking Rust-source membership is also guarded. No Lake target changes; the benchmark worker still needs a separate approved FC.

## Executed tracking and unit results

| Tracking population | Messages | Streams | Resolved | Bit-identical positions | Matching unresolved |
| --- | ---: | ---: | ---: | ---: | ---: |
| Full timestamped corpus |172432|1|11347|11347|161085|
| Synthetic multi-aircraft |5865|445|5113|5113|752|
| Total |178297|446|16460|16460|161837|

`python3 scripts/check_tracking.py --diagnostic` passes with zero mismatches and observed maximum coordinate error0. Actual `Impl.decodePositions` is compared against actual pinned `rs1090::decode::cpr::decode_positions`; all6903 pinned airports are supplied. Final public state/reference and all31 targeted witnesses pass. Complete rows, labels, metrics, source hashes and generation metadata are retained in `tests/evidence/tracking-diagnostic/`.

`scripts/run_unit_tests.sh` passes1011/1011 Lean fixture assertions plus the upstream172432-row corpus assertion. The corpus port executes tracking on50385 timestamped reports and observes12659 positions; only the source cardinality expectation is asserted. Fresh Rust checks match67 unique frames and three direct registers. All seven intentionally wrong assertions and four malformed fixtures are rejected. The source audit accounts for153 functions/603 assertion sites:139 nonempty ports, one empty upstream function, one corpus test and12 explicit scope exclusions. [The unit report](UPSTREAM-UNIT-PORT.md) records exact scope and upstream limitations. A concurrent diagnostic invocation caused an evidence compression race; its failed log is retained, and the subsequent single complete invocation passes.

No new frozen-model omission was found by either suite. Neither suite is frozen yet.

## Complete campaign and fresh seeds

The exact proposed runner body was executed with `bash -c`, using the live runner pathname only as `$0` for its unchanged directory-resolution command. No runner text, tool calls or components were rewritten or mocked; the live frozen runner and lock were untouched. Reproduction driver: `tests/evidence/fc005-revision/run_candidate_campaign.py`. Its recorded candidate hash is the proposed runner hash. All seven components exited0:

| Component | Executed result |
| --- | --- |
| Altitude |12288 exhaustive codes plus regression pass|
| Reserved velocity |16480 cases pass|
| DTE |65536 codes through both fresh oracle paths pass|
| Numeric presentation |20936723 exact pinned-libm comparisons pass|
| Individual CPR |44228 calls:44024 bit-identical,204 narrowly classified D009|
| Stream tracking |178297 messages, zero mismatches|
| Whole message + structured Comm-B |576164 messages:566792 exact,9372 narrowly classified D001;101244 direct registers exact|

Complete fixed-seed coverage includes all32 attempted DFs, all70 ADS-B branches and all14 registers. There are zero unclassified mismatches. Standard/oracle presentation differences are retained separately and do not waive compatibility failures. Commands, exit codes and logs: `tests/evidence/fc005-revision/`, `tests/evidence/differential-campaign/`, and `tests/evidence/message-differential/`.

Fresh seeds were sampled and recorded before generation: message488673482, Comm-B1870155843. The direct fresh-seed campaign also passes576164 messages:566820 exact,9344 D001, all101244 direct registers exact, and all coverage checks pass. Evidence: `tests/evidence/fresh-seed-FC005-revision/`. Both campaigns include100000 generated whole messages and100000 random Comm-B assignments plus1244 targeted cases. These are diagnostic100k campaigns, not the final10M run.

## Exact new locked files

```text
196f549f758b2e4c78f263c12af1151482465a3670e96b714b5fe8885ffde6cd  Tests/Tracking.lean
49c0ded8fcc3016ea36221fb467332137b716626f7b5212cc80bea84b246a032  Tests/Upstream.lean
28fbfcd5816440cc3f32c264ba8390993c9d29cba400e0fb4f13297006a90a2c  Tests/UpstreamCorpus.lean
f308bf25efaaf610a22cf0145837a36b2a478f687099ab043d185503d67f0786  differential/tracking-oracle/Cargo.lock
85b25b6c4d10fe461009618231dfd9c117e65613d503182b8da40be1a2638a7f  differential/tracking-oracle/Cargo.toml
3fbd472310907068e885816810ad1503fbafbede364ea76e5494a7decde24374  differential/tracking-oracle/src/main.rs
4faf1ddda99a281adcf0b692fd3662bf74e65cfd0ba445ed9e4dcfcb3041fecc  review/upstream-units/assemble.py
5a0830c5c2edea5cd0031c1ba05aa6f87a8013fefd99db6978535eb6a60cc9ac  review/upstream-units/inventory.py
5964857d807d5e894bcc1c97a715b39f4b5d14050b706614ec0f96aa6146fedf  review/upstream-units/manual.py
ab7452beb54c431258898237ed51d17756de3c39a8e082dcdd18b109b30a40c9  review/upstream-units/port.py
c8d791a7b9e8737f50cf3286d52ba97830ad810850df74cbce35cc6438af04af  review/upstream-units/run.py
b7032df01f37f98b2c392cf5b4bd5d8902242603759a4bf1ee76c050736e8a89  review/upstream-units/run_corpus.py
08c1b5053031d9df7a3b9fbc808f574cf3c0b90fe06fbad17de76fc331abf457  review/upstream-units/rust_port.py
0ceee8daa0e504dcce12f8e499d699698c11c7f1ae111506f1e443c2e8e7b374  scripts/check_tracking.py
64236d72a99fa448863c655e277f1955e4686abfd1d5bfd6edc170abb1b4a7d5  scripts/generate_tracking.py
1e53deeac74dd369ede0ccc299d44125b8f795bbdea2d1931195cf25529eb9ed  scripts/run_unit_tests.sh
```

## Proposal validation and approval boundary

The proposed import audit passes20 runtime modules,30 frozen semantic modules, nine adapters and six rejection self-tests. Applying the exact combined patch in a disposable copy yields all102 expected hashes. The guard rejects mutation of every102 file, deletion of every16 new file and17 added-member patterns; separate unit-membership checks also reject a package-directory symlink. Unchanged lock self-tests still verify lock-first rejection. Five isolated orchestration checks verify mandatory quick/full tracking invocation, argument preservation, component-only behavior, failure propagation and diagnostic continuation. Nineteen independent comparator cases also verify tolerance, label integrity, mandatory boundary witnesses, prefix membership and intermediate state rejection. These isolated tests supplement the real complete campaign above.

Evidence and proposed source snapshots are under `tests/evidence/frozen-changes/FC005-proposal/`; focused boundary/shadow-assertion checks are under `tests/evidence/tracking-revision-probes/`, and recursive-membership checks under `tests/evidence/unit-membership-v2/`. The full proof gate still lacks seven capstones. No optimization generation, whole-decoder baseline, commit or push occurred.

**Apply only after explicit approval.** Reverify every input hash, record FC005's date, approval, old/new hashes and executed evidence in `FROZEN-CHANGES.md` before touching `spec.lock`, preserve before/after snapshots, and apply only the approved patch. Then rerun the lock/import guards and integrated suites. The seven capstones remain paused until this revised FC005 is approved and applied.
