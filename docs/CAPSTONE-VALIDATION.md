# Completed capstone milestone — 2026-10-17

All 23 exact frozen capstones are proved. `scripts/check_all.sh --full` passed
with exit 0 after the FC005 application and completion of the seven outstanding
proofs. The frozen final manifest checks every exact type; raw axiom reports
for all 23 constants show only `propext`, `Classical.choice` and `Quot.sound`.
The dependency audit passes all seven hypotheses and `assigned`; the 152
witness/example proofs pass the same axiom policy. No frozen statement changed.

Evidence is in `tests/evidence/capstones-complete/`: `gate-full.log`,
`final-axioms.log`, the exact manifest wrapper, source hashes, component summaries,
commands, seeds and `summary.json`. The first invocation found an import-order
error in the unfrozen root proof module; that failed log is retained separately.
The corrected full invocation passed every component.

| Whole-message campaign | Message seed | Comm-B seed | Generated | Total comparisons | Exact | D001 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Full fixed gate | 1085632 | 1085632 | 10000000 | 10476164 | 9542689 | 933475 |
| Separate fresh run | 3836954135 | 2158857898 | 10000000 | 10476164 | 9542618 | 933546 |

Each campaign also compared 101244 direct-register payloads exactly. Both cover
all 32 DF attempts, 70 ADS-B branches and 14 Comm-B registers, with no coverage
errors or unclassified mismatches. The totals include all 172432 corpus rows
and three contexts for every structured Comm-B payload. Full per-branch counts
and every mismatch are retained by the runners. D001 is the previously approved
standard Comm-D frame versus pinned parser rejection, not a newly waived failure.

Other mandatory components pass: 12288 altitude codes, 16480 reserved-velocity
cases, all 65536 DTE codes through two oracle paths, 20936723 numerical
comparisons, and upstream unit vectors (1011 fixture assertions plus the
172432-row corpus assertion and fresh oracle checks). The expanded standalone
CPR suite has 535748 calls: 535544 bit-identical and 204 documented D009 cases.
The tracking suite has 178297 rows in 446 streams, 16460 bit-identical resolved
positions, no mismatches, 31 boundary/state witnesses and 45 distinct real
outcomes. Its position pass rule remains 1e-9 degrees.

The fresh seeds were recorded before generation in `fresh-seeds.json`. The
fresh command is retained in `fresh-message.log`; the fixed command is
`scripts/check_all.sh --full`. Complete generated transcripts remain on disk
under `.cache/message-differential-*` and the evidence directories. Large
compressed transcripts are excluded from Git; their source-bound SHA-256 hashes,
seeds, command logs and complete comparison summaries are versioned. No data was
discarded to change a result.

These are milestone checks on the current workspace. The final clean-clone gate,
final-session checks, whole-decoder performance target and publication remain
required. The benchmark-worker FC006 is a separate, unapplied proposal; no
whole-decoder baseline or optimization generation has run.
