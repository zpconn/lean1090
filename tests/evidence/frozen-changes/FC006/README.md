# FC006 application evidence

The exact approved patch was verified and applied after the dated history entry. `spec.lock.before`, `spec.lock.approved` and `spec.lock.after`, source snapshots, input/application records and independent reviews retain the full chronology. The resulting 104-entry lock matches the approved hash; 99 prior entries are unchanged.

`gate-full.log` is the passing `scripts/check_all.sh --full` run: 23 exact capstones, permitted axioms, hypothesis/assignment and 152-witness audits, unit tests and all seven differential components. `validation.json` and `components.tsv` record successful exits. `component-snapshots/` preserves this invocation's specialist summaries.

`fixed-message/` records the 10M fixed-seed campaign; its full compressed transcripts remain in `tests/evidence/message-differential/`. `fresh-seeds.json` was written before generation; `fresh-commands.json`, `fresh-campaign.log` and `fresh-message/` retain the direct fresh-seed 10M campaign and freshly seeded structured Comm-B cases. Both campaign summaries include artifact SHA-256 hashes and all branch counts. Large compressed message transcripts are retained on disk and ignored by Git; their seeds, commands, hashes and summaries are committed.

`worker-validation/` records the approved live target's correctness/protocol checks. Those timings are smoke checks under validation load, not the baseline. Baseline timing follows the verified commit and a fresh build with all project correctness work stopped.

`whitespace-polish/` retains original documents and audits for the separately authorized prose repair. Earlier frozen-history text changed only in whitespace; all hashes, timestamps and wording are preserved. New FC006 entries are separate appended history.
