# CPR overhead by generation

This supplement adds the requested overhead metric without changing any sealed benchmark report or sample. Future generation reports include it directly.

For each implementation, overhead is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, in microseconds per message. The calculation below subtracts exact full-corpus median nanoseconds first, then divides by `172432 * 1000`. It compares independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Signed differences, including negative rs1090 values, are retained.

| Generation | Lean decode µs/msg | Lean + CPR µs/msg | Lean CPR overhead µs/msg | rs1090 CPR overhead µs/msg |
| --- | ---: | ---: | ---: | ---: |
| [0](BASELINE.md) | 30.746429079 | 32.564682576 | 1.818253497 | -0.027712762 |
| [1](GEN1.md) | 24.386014638 | 26.325990808 | 1.939976170 | 0.006388257 |
| [2](GEN2.md) | 17.098262399 | 18.643170949 | 1.544908549 | 0.008405360 |
| [3](GEN3.md) | 11.951196970 | 13.760175263 | 1.808978293 | -0.000446112 |
| [4](GEN4.md) | 8.707526497 | 10.522183429 | 1.814656931 | 0.022418263 |
| [5](GEN5.md) | 7.652762011 | 9.683151521 | 2.030389510 | 0.163281369 |
| [6](GEN6.md) | 7.090403057 | 8.957811920 | 1.867408863 | 0.102484023 |
| [7](GEN7.md) | 6.417244328 | 8.390725944 | 1.973481616 | 0.119617037 |
| [8](GEN8.md) | 5.077202433 | 6.766741788 | 1.689539355 | 0.010125104 |
| [9](GEN9.md) | 4.651994293 | 6.254850886 | 1.602856593 | 0.014629958 |
| [10](GEN10.md) | 4.052433284 | 5.958302374 | 1.905869090 | -0.025339351 |
| [11](GEN11.md) | 3.810367675 | 5.761976170 | 1.951608495 | 0.048593504 |
| [12](GEN12.md) | 3.451270797 | 5.367141227 | 1.915870430 | 0.052426133 |
| [13](GEN13.md) | 3.163480868 | 5.100186816 | 1.936705948 | 0.003689298 |
| [14](GEN14.md) | 3.313874803 | 5.100947916 | 1.787073113 | -0.074976843 |
| [15](GEN15.md) | 2.940529519 | 4.714143976 | 1.773614457 | -0.055550779 |
| [16](GEN16.md) | 2.801214206 | 4.556052328 | 1.754838122 | 0.013870065 |
| [17](GEN17.md) | 2.802161699 | 4.099926858 | 1.297765160 | 0.038953042 |
| [18](GEN18.md) | 2.800575810 | 3.483841120 | 0.683265310 | -0.005159332 |
| [19](GEN19.md) | 2.617902112 | 3.290571269 | 0.672669157 | 0.014589282 |

All 80 implementation/mode medians were independently recomputed from 21 measured samples apiece, after the three warmups. [Structured values and exact integer differences](cpr-overhead.json) retain source hashes and the original recorded commit IDs. Historical attribution is documented in [the commit mapping](../docs/COMMIT-ATTRIBUTION.md).
