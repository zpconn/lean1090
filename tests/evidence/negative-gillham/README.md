# D010 negative-Gillham probes

These five inputs demonstrate the source-backed difference recorded in
`DISCREPANCIES.md`: two negative Gillham frames, two negative binary25
controls, and the concrete Comm-B corpus regression. `lean.jsonl` contains
both standard and compatibility views; `oracle.jsonl` comes from the actual
pinned `Message::from_bytes`. `summary.json` records executed assertions and
the exact input/output and relevant source hashes.

Reproduce after building `lean1090` and the message oracle:

```sh
lake build lean1090
CARGO_HOME="$PWD/.cache/cargo" CARGO_TARGET_DIR="$PWD/.cache/rs1090-target" cargo build --offline --manifest-path differential/message-oracle/Cargo.toml --profile dist --bin lean1090-message-oracle
.lake/build/bin/lean1090 --diagnostic < tests/evidence/negative-gillham/input.hex > /tmp/negative-gillham-lean.jsonl
.cache/rs1090-target/dist/lean1090-message-oracle < tests/evidence/negative-gillham/input.hex > /tmp/negative-gillham-oracle.jsonl
diff -u tests/evidence/negative-gillham/lean.jsonl /tmp/negative-gillham-lean.jsonl
diff -u tests/evidence/negative-gillham/oracle.jsonl /tmp/negative-gillham-oracle.jsonl
```

DF17 parity was calculated by polynomial division using generator0x1FFF409;
both actual oracle outputs confirm CRC0. DF4 AP overlays address0x112233,
which both implementations recover. The fifth frame is unmodified corpus
row17040. These are exact component regressions, not a passing full-suite
claim. The permanent altitude differential stratum separately enumerates
all8192 AC13 and4096 AC12 words.
