# Generation 15 decode actual-worker diagnostic sampling

One actual frozen worker run was sampled on CPU 0 with cpu-clock:u at 199 Hz after both diagnostic builds. Decode and CPR captures ran sequentially while all other native/profile jobs were held. This is not a benchmark. The timed binary and all 22 fresh native sets are unchanged; the explicit binding relates timed e659220 to current 7163b25 without attributing performance to documentation commits.

All 257 recorded samples were parsed; 68 have the required visible workload ancestor. 189 samples are excluded rather than treated as preparation. 246 stacks contain an unknown frame, and 0 included leaves are unknown. Both perf reports explicitly state zero lost samples. These conditional shares can be biased by inlining, tail calls and unwinding. Startup field-table construction is outside the visible loop subset. Full stacks and raw perf hashes are retained.
