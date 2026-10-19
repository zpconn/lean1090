# Configurable benchmark reporting target

The user raised the future headline review threshold to 1.50× rs1090. The parent authorized a separate unfrozen helper, `review/diagnostics/archive_generation_benchmark_target.py`. The historical helper and its reports remain unchanged; timing still uses the existing runner and frozen ABAB interleaver.

Future archival plans explicitly include `"decode_target_ratio": {"numerator": 3, "denominator": 2}`. An omitted ratio preserves the historical 11/10 default. Both report text and machine-readable verification compare `rs1090_median_ns * denominator >= lean1090_median_ns * numerator` with exact integers. Only positive integer ratios are accepted; booleans and floating-point values are rejected. A ratio whose decimal form does not terminate at two places is displayed as its exact fraction.

`check_target.py` validates the retained generation-10 run read-only, checks that every original non-reporting function is AST-identical, and compares the default report byte-for-byte with the old helper. Synthetic below/equal/above tests include the 3/2 target, 11/10 default, non-reduced fractions, a non-terminating decimal and integers above binary64's exact range. Malformed ratios and invalid median values are rejected. These fixtures are not measurements; no benchmark result is written.

No new generation plan or fresh seed has been created. Generation 11 remains dependent on the completed diagnostic and its selected optimization.
