# Review-only reserved velocity comparison

This captures16,511 actual oracle calls and the unapplied proposal from
`docs/RESERVED-VELOCITY-PROPOSAL.diff`. No frozen file is substituted at runtime.
The current CLI output is retained separately from the proposal values.
`cases.json.gz` identifies each case and subtype; `input.hex.gz` and
`words.txt.gz` provide both complete frames and their56-bit payload words.

Reproduce the numerical proposal and fresh oracle/current CLI outputs:

```sh
gzip -dc tests/evidence/reserved-velocity-proposal/words.txt.gz > /tmp/reserved-words.txt
gzip -dc tests/evidence/reserved-velocity-proposal/input.hex.gz > /tmp/reserved-input.hex
lake env lean --run review/ReservedVelocityProposal.lean /tmp/reserved-words.txt > /tmp/reserved-values.csv
.lake/build/bin/lean1090 --diagnostic < /tmp/reserved-input.hex > /tmp/reserved-lean.jsonl
.cache/rs1090-target/dist/lean1090-message-oracle < /tmp/reserved-input.hex > /tmp/reserved-oracle.jsonl
```

The Lean program checks equality of the full proposed semantic list with its
independent assignment for every word before emitting values. For each row,
`proposed` and `independent` must equal the oracle's `reserved_data`;
`wire_value` must equal the current CLI's field. Replacing only that field in
the current diagnostic's `oracle` object must make it equal to the entire
oracle diagnostic (after removing the Lean-only `standard` object).

There are16,503 current-output mismatches and zero proposed-output mismatches.
The unchanged zero/all-one cases explain the remaining eight. The earlier
10,000 generated-message failure campaign is retained separately under
`../message-generated-initial/`. These proposal results are not a full-suite
pass and do not authorize or apply a frozen-file change.
