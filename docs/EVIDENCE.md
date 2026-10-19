# Evidence and retention

The repository contains the decoder, proofs, frozen contracts, reproducible
checks and a substantial development record. Historical evidence is retained
unchanged, including failed attempts and superseded proposals. The current
status is in [PROGRESS.md](../PROGRESS.md); an older report describes the state
when its command ran.

The owner-requested [commit attribution correction](COMMIT-ATTRIBUTION.md)
changed commit IDs while preserving every original tree. Historical benchmark
IDs remain verbatim; the linked mapping resolves them to the current history.

| Material | Retention | How to inspect or reproduce it |
| --- | --- | --- |
| Specifications, capstones, frozen guards and test adapters | Git, with approved SHA-256 entries in `spec.lock` | [Frozen-change history](FROZEN-CHANGES.md); `python3 scripts/check_lock.py` |
| Decoder and proofs | Git, with a verified commit for each measured generation | [Optimization procedure](OPTIMIZATION.md); `scripts/check_all.sh --full` |
| Benchmark samples, commands, compiler provenance, host observations and reviews | Git under `bench/runs/` | [Method](../bench/BENCHMARK.md), [results](../bench/results.csv), and the corresponding generation report |
| Differential seeds, summaries, coverage, commands and artifact hashes | Git under `tests/evidence/` | Each campaign's `fresh-seeds.json`, execution record and verification manifest |
| Smaller regression transcripts and compressed diagnostic profiles | Git under `tests/evidence/` | Their manifests identify compressed and, where recorded, decompressed hashes |
| Large milestone whole-message transcripts | Retained on the development machine, ignored by Git | Regenerate with the recorded commands and seeds; compare the resulting artifact hashes |
| Native executables, object files, Lake/Cargo caches and original profiler files | Local ignored build/cache trees | Build from the recorded commit and pinned toolchain; provenance records bind the original binaries and objects |
| Upstream checkouts and downloaded source documents | Local ignored `vendor/` and `.cache/` trees | [Sources and pins](SOURCES.md), Cargo lockfiles and `lake-manifest.json` |

The exact exclusions are in [.gitignore](../.gitignore). In particular,
`tests/evidence/optimization/gen*/fresh-message/*.gz`,
`tests/evidence/publication/fresh-message/*.gz` and the designated earlier
10M-message transcript directories are intentionally not part of a clone.
Their summaries and compressed/decompressed hashes are committed. This is a
retention distinction, not a claim that a hash substitutes for examining an
output. Fresh regeneration is required when those local transcripts are not
available. The benchmark samples themselves are committed.

The three raw mismatch-stream links in
[the whole-message differential guide](MESSAGE-DIFFERENTIAL.md) resolve after
the relevant local run; they are not downloadable repository artifacts.
Recorded paths beginning with `.cache/`, `.lake/` or an absolute development
path likewise describe the original execution environment. Reproduction on a
different machine uses its own paths and creates new evidence; it should not
overwrite a historical run and present it as the original.

Some reports are also copied byte-for-byte into an evidence directory as a
before-change snapshot or an included report fragment. Relative links inside
those historical copies retain their original `docs/` context. Use the current
report in `docs/` or the neighboring manifest to navigate them. These copies
remain unchanged so that their recorded hashes continue to match.

Source and generated-C snapshots, symbol inventories, raw diagnostic profiles,
before/after records and failed-run logs explain the repository's size.
They are evidence rather than runtime modules. Removing them, repacking a
retained file or changing historical trees would invalidate existing
associations. The documented attribution correction preserves every tree and
records the correspondence between original and current commit IDs.

Host evidence deliberately includes operating-system and compiler versions,
CPU details, process command lines, local filesystem paths and power-plan
observations. Such observations establish what was recorded, not complete
visibility into Windows host contention. Raw UTC anomalies and unknown profiler
frames remain documented. Worker monotonic durations determine benchmark
medians; diagnostic instruction counts are not benchmark throughput.

Third-party source provenance and retained license notices are collected in
[THIRD_PARTY_NOTICES.md](../THIRD_PARTY_NOTICES.md). No downloaded ICAO or Sun
book PDF, vendored dependency tree, or built executable is included in Git.
