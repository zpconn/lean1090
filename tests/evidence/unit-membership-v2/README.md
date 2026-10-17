# FC005 recursive unit-source membership revision

The candidate inventory is `.cache/fc005-proposal/scripts/frozen_paths.py`;
the live inventory and `spec.lock` are unchanged. `membership-tests.json`
records a disposable-copy run of the unchanged `scripts/check_lock.py` against
the proposed inventory: intact acceptance, eight added-file rejections, one
package-directory symlink rejection and seven source-file deletion rejections.
The copy contains every proposed source and its own freshly calculated lock.
No injection test modified the live unit-source tree.

All source-tree files are members recursively, without suffix or cache
exceptions. Directory symlinks themselves are included because `rglob` does
not traverse them. The unchanged checker rejects new members and cannot accept
a directory symlink as a hashable file.

`before-generated/` preserves the seven old untracked JSON/JSONL snapshots and
seven Python caches before their removal from `review/upstream-units/`.
`removed-generated.json` records their old paths and hashes. New runs write the
JSON/JSONL to `tests/evidence/upstream-unit-tests/generated/` instead.
`generated-snapshot-comparison.json` verifies all seven relocated outputs are
byte-identical, including every fixture assertion and exclusion.

The unit rerun command is `scripts/run_unit_tests.sh`; `run.log`, `summary.json`,
`coverage.json` and `commands.json` retain its result and source hashes. The
complete assertion/oracle/corpus traces remain under
`tests/evidence/upstream-unit-tests/`. An accidental simultaneous invocation's
evidence-file race is retained separately under `concurrent-invocation-failure/`;
it is not a decoder or specification discrepancy.

`live-lock.before` is the FC004 lock. Its hash and the current live lock remain
`4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`.
FC005 is only a candidate and has not been approved or applied.
