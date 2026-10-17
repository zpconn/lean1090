# Independent preparation oracle

These source files were built from `.cache/benchmark-cpr-review-oracle/`. The manifest and lock are frozen benchmark copies except for the package name; rs1090 path/default features/dist profile are unchanged. The retained manifests preserve that original relative path.

Executed by the independent CPR reviewer:

```bash
CARGO_HOME=$PWD/.cache/cargo CARGO_TARGET_DIR=$PWD/.cache/rs1090-target cargo build --offline --locked --manifest-path .cache/benchmark-cpr-review-oracle/Cargo.toml --profile dist
.cache/rs1090-target/dist/lean1090-benchmark-cpr-review airports
.cache/rs1090-target/dist/lean1090-benchmark-cpr-review timestamps
```

The outputs check native Rust timestamp parsing and the actual compiled rs1090 airport constant, in order. The original reviewer summaries bind an earlier worker revision; final worker validation regenerates the same preparation outputs and records the final source/binary hashes separately. No comparative benchmark was performed.
