# Native decoder diagnostic profile — gen0

One unmodified frozen-worker pass over all 172,432 corpus messages, pinned to CPU 0, sampled with perf software `cpu-clock:u` at 199 Hz and DWARF stacks. This is diagnostic attribution, not a benchmark. Worker durations are retained only as raw protocol output and are not used to claim throughput.

The worker/source/object hashes remained identical before and after capture. Binary SHA-256: `6e09e99f75a523370970ef5311bc296d52c4c4dbb3cb0ffcce35d87f5f7dc415`. No decoder, proof or frozen file changed. The runner was allowed to overlap a possible small diagnostic-driver compile; no benchmark isolation claim is made.

perf captured **1166 samples**, with zero lost samples reported. Exactly **590** contain the actual `lp_lean1090_Lean1090_Impl_decode` frame; only these enter the stage table below. The other **576** are excluded: 90 show other worker phases, 23 show its decode loop without the decode frame, and 463 show neither frame (including possible unwinding failures). Thus the percentages are conditional on visible decoder ancestry and may be biased, especially in allocator/GMP routines. Missing ancestors are not classified as preparation.

| Visible stage | Samples | % of 590 attributed samples |
| --- | ---: | ---: |

| Comm-B inference and raw payload | 247 | 41.86% |

| report parity/address | 205 | 34.75% |

| Comm-B semantic projection | 45 | 7.63% |

| acceptance | 34 | 5.76% |

| ADS-B semantic projection | 27 | 4.58% |

| frame extraction | 17 | 2.88% |

| ADS-B raw payload | 7 | 1.19% |

| altitude | 4 | 0.68% |

| identity | 3 | 0.51% |

| report other/self/unresolved substage | 1 | 0.17% |


These rows are disjoint and sum to 590. The strongest visible costs are Comm-B inference and parity/address work, followed by semantic projections. This is evidence to corroborate with per-DF Callgrind instruction counts; the single mixed stream does not independently identify individual DFs.

Overlapping nested counts, **not additive**: 374 GMP/mpz, 218 Parity, 200 software Binary64 and 196 Rat samples. The leading attributed leaf is `__gmpz_n_pow_ui` (75 samples); other prominent leaves include small-object allocation (36), GMP addition (33), realloc (26), default allocation (24), and `BitVec.ofNat` (22). Inlining/tail calls can erase function boundaries. 1110 total samples have at least one unknown frame, often at a bottom runtime/libc thread frame; the exact visible decode ancestor is still required.

Hardware cycles/instructions are unavailable in this WSL kernel. Software sampling and Callgrind Ir must not be described as hardware instruction measurements or used as the performance target.

Artifacts: `capture.json` contains commands, stdin, commit, hashes and provenance; `script.txt` is the complete decoded stack stream; `report-self.txt` and `report-children.txt` retain perf reports; `analysis.json` and `decode-samples.jsonl` retain the explicit classification. Capture/analysis scripts and package hashes are copied here.

Large raw data remains at `.cache/gen1-planning/perf-gen0/perf.data` (19579764 bytes), SHA-256 `5efc0e16c52b524ce8b2ac5e28b7ead0c688391257a29400b3bcff69dd18f475`. The matching binary is retained at `.cache/gen1-planning/perf-gen0/lean1090-bench`, SHA-256 `6e09e99f75a523370970ef5311bc296d52c4c4dbb3cb0ffcce35d87f5f7dc415`. Preserve both when archiving or re-symbolizing.
