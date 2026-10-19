# Generation 20: eight-bit CRC loop batching

Generation 20 measured 1.852064793419× rs1090 in decode mode and
1.485653752657× with CPR. The frozen benchmark, archival checks and independent
result review passed. [Measured results and raw samples](../bench/GEN20.md).

The [generation 19 decoder diagnostic](GEN19-COST-BREAKDOWN.md) identifies
frame/CRC as the largest exclusive stage: 3,496,975,683 of 9,587,482,169
instructions. Its syndrome calculation costs 2,299,432,084 inclusive
instructions; within that, the CRC syndrome loop costs 1,119,219,468.
These nested counts overlap and are not elapsed times or predicted savings.
The [CPR diagnostic](GEN19-CPR-COST-BREAKDOWN.md) also spends most collected
instructions in the decoder. Reducing shared decoder work benefits both modes.

The change groups eight MSB-first bit updates into each CRC loop iteration.
It uses the same UInt32 `wordStep` and two cached UInt64 words. Eight explicit
updates replace repeated loop/index/cache dispatch; there is no lookup table.
The fast entry accepts byte-aligned widths through 128. Every other width
uses the original bit loop, preserving the public API's unrestricted natural
width and word domain. Inputs above the requested width remain ignored.

The proof obligations are: every cached byte bit equals the original natural
bit; unrolling preserves the eight updates in order; regrouping a natural fold
preserves every operation; and the complete selected/fallback syndrome equals
the original for all widths and words. Existing capstone and adapter statements
remain unchanged. Witnesses cover zero, unaligned and over-cache widths,
cache boundaries, complete short/long frames, and over-wide input words.

The runtime module and helper proofs compile. The integrated all-input
refinement passed its first targeted build, with all existing theorem statements
preserved. The combined production/proof build passed 3,539 jobs with all 195
correctness inputs unchanged. Independent native review confirms eight ordered
updates in the actual byte loop and the live fallback; the other 21 linked
project native sets are unchanged. A separate review verified that evidence
against generated C and disassembly. These are implementation checks, not
speed measurements. Full fixed and fresh 10M validation passed, with all 23
capstones, 1,011 unit assertions, seven differential components and complete
32/70/14 whole-message coverage. The fixed run has 9,542,689 exact matches and
933,475 documented D001 cases; the fresh run has 9,542,976 exact matches and
933,188 D001 cases. Both have 10,476,164 messages and 101,244 exact direct
Comm-B comparisons. Standard-view differences remain recorded separately.
Independent fresh replay passed. Verified cleanup reclaimed 11,092,819,968
allocated bytes of duplicate scratch while preserving evidence.

Final archive/plan review passed with no findings. The isolated benchmark ran
once from clean commit `d3a10f60e7e83a35c53d5e4066a82dce048ad2be` with a fresh
build and retained samples in both modes. Its reported CPR overhead is the
difference of mode medians: 0.673603983019 µs/message for Lean and
0.077853872831 for rs1090, including measurement noise.
No Float code, tested-only callback, trusted primitive, frozen source or
benchmark is changed. [Validation evidence](../tests/evidence/optimization/gen20/)
includes every proof attempt and both complete campaigns.
