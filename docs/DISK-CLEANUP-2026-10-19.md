# Disk cleanup — 2026-10-19 UTC

The user paused optimization, requested a disk assessment, then authorized
removing everything unnecessary for continued progress. The repository shrank
from approximately 256 GiB to 58 GiB (final allocated size 61,219,708,928 bytes
at the recorded check), recovering about 198 GiB. Filesystem-wide usage fell
from 584 GiB to 385 GiB; unrelated processes can also affect that reading.
WSL reports 572 GiB available after cleanup.

| Removed material | Result |
|---|---|
| Old whole-message scratch | 42 directories, 177.34 GiB allocated |
| DTE, CPR, altitude and reserved-velocity scratch | 93 directories, 7.15 GiB allocated |
| Old diagnostic duplicates and rebuildable binaries | 5,090 files, 4.64 GiB attributable allocated space |
| Clean-clone release build | Removed its expanded Lean dependencies/build and Rust target; preserved its sources, Git and modified test evidence |
| Mathlib download archives | 473,616,384 allocated bytes; active expanded dependency retained |

Every removed transcript had a verified retained counterpart, including full
gzip decompression, byte count and SHA-256 checks. The whole-message cleanup
verified 183 retained archives and every source file independently. Mutable
current-output directories were excluded as sole archival counterparts.
Small-stratum cleanup preserved the otherwise unique quick-CPR compressed
copies before removing scratch. Unique profiler captures and unmatched files
were retained. Historical source/proof/benchmark records were not edited.

The main toolchain, expanded Mathlib, current binaries, Git history, all
compressed evidence and immutable generation gate archives remain. The
suspended generation 15 gate retains its complete working directory,
`.cache/message-differential-0gzplfih`. Process group 1126929 remains stopped;
no optimization or differential campaign was resumed. All 186 gate inputs,
111 fresh-campaign sources, three binaries and 104 locked files passed the
preservation checks. The lock and import guards passed. No commit was made:
the interrupted full gate has not yet completed.

The accumulation came primarily from the frozen whole-message runner:
`scripts/check_message_differential.py` creates a persistent `mkdtemp` directory
at line 367, writes compressed retained evidence at line 382, and leaves the
raw scratch behind. This cleanup did not change that frozen runner. Future
runs should remove only fully archived scratch, using the same verification
procedure outside the frozen suite, and protect any active run.

Windows C: still reports only 7.3 GiB free. Ubuntu's non-sparse virtual disk is
`C:\Users\zpcon\AppData\Local\wsl\{ea44aea2-e5db-40c4-ae40-eddffa5c0d3b}\ext4.vhdx`;
its observed logical file length was 642,941,714,432 bytes. Deletion freed space
inside the guest but did not shrink that host file. Microsoft's
[compact vdisk documentation](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/compact-vdisk)
requires the dynamic disk to be detached or attached read-only. Compaction
was not attempted because terminating Ubuntu would end the paused validation
and other Ubuntu processes. No WSL settings or Windows files were changed.

The complete receipts, inventories, retained guard failures and verification
scripts are in [the cleanup evidence](../tests/evidence/maintenance/disk-cleanup-20261019/).
Key records:

- [Whole-message cleanup audit](../tests/evidence/maintenance/disk-cleanup-20261019/message-temporaries/completion.json)
- [Small-stratum cleanup audit](../tests/evidence/maintenance/disk-cleanup-20261019/small-strata/completion.json)
- [Diagnostic cleanup receipt](../tests/evidence/maintenance/disk-cleanup-20261019/diagnostic-cache-cleanup.json)
- [Source preservation](../tests/evidence/maintenance/disk-cleanup-20261019/source-preservation-check.json)
- [Final disk readings](../tests/evidence/maintenance/disk-cleanup-20261019/root-after.json)

After the user resumed optimization, the original gate process was no longer
present. Its interrupted state, logs and output snapshot were preserved, and
the full gate was restarted and passed. The completed run then used the new
archive-and-cleanup workflow. Four small scratch sets were removed first;
both message sets were retained when strict filesystem identity checks saw
changes. All 15 archived files still matched their sealed hashes. The two
recorded identity changes were allocation-only (+4 KiB each); the first failed
file's original tuple was unavailable, so that particular cause remains
unproved. After synchronizing the archive to disk, a fresh verification
removed both complete, byte-identical message sets. These post-resume removals
reclaimed a further 11,092,762,624 allocated bytes (10.33 GiB), with receipts in
[the generation 15 evidence](../tests/evidence/optimization/gen15/post-gate-message-cleanup/result.json).
The earlier cleanup readings above remain historical observations.

Routine campaign retention now uses
`review/diagnostics/finish_generation_gate.py`: after a successful full gate
and producer quiescence, it invokes the existing archiver, synchronizes copied
files and directory links, then verifies explicitly selected scratch against
sealed archives. Cleanup defaults to preview; deletion requires explicit
selection and quiescence. If the gate was already archived, use
`cleanup_verified_scratch.py` directly. It retains a whole directory on any
unmatched file or changed identity, and writes durable receipts before deleting
verified files. The flush correction passed 54 author/independent tests;
the strict cleanup checks and frozen test suite remain unchanged.
