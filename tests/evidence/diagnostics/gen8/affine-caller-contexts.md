### Live affine-value observations

The same native `payloadValue` entry populations are observed in both generations. The direct `Rat.mul` and `Rat.add` edges below are actual collected calls; the inlined affine helper has no separate native boundary. Full caller contexts, self costs and edge records are retained in [affine-caller-contexts.json](../tests/evidence/diagnostics/gen8/affine-caller-contexts.json). Incoming and outgoing inclusive costs overlap and must not be added to one another or to stage totals.

| Generation / family / stage | payloadValue calls | payloadValue inclusive Ir | Direct mul calls | Direct mul inclusive Ir | Direct add calls | Direct add inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| Gen7 / adsb / semantic_oracle_values | 462,367 | 2,470,940,022 | 458,078 | 1,486,912,778 | 458,078 | 823,558,847 |
| Gen7 / commb / semantic_oracle_values | 1,058,480 | 5,710,418,332 | 1,048,288 | 3,340,150,441 | 1,048,288 | 1,802,422,565 |
| Gen7 / commb / commb_inference | 78,306 | 431,668,285 | 75,314 | 242,379,993 | 75,314 | 130,025,797 |
| Gen8 / adsb / semantic_oracle_values | 462,367 | 167,625,084 | 2,467 | 7,999,568 | 0 | 0 |
| Gen8 / commb / semantic_oracle_values | 1,058,480 | 1,683,457,990 | 322,168 | 1,037,767,756 | 31,026 | 53,468,882 |
| Gen8 / commb / commb_inference | 78,306 | 249,471,187 | 57,908 | 186,267,668 | 0 | 0 |

These counts do not separate every scale/offset assignment: missing-status fields also avoid arithmetic. The actual generated C and linked assembly independently establish the guarded identity branches. This is an instruction diagnostic, not a throughput prediction.
