# Progress

## Status and current authorization

**Current state: optimization resumed toward 2.00× rs1090 in both modes.**
The user set a new stretch goal of **2.00× headline decode and 2.00×
decode-plus-CPR throughput**, superseding the generation 15 review stop.
**Latest measurement: generation 19 reached 1.795418481745× decode and
1.432826926432× with CPR.** Both 2.00× targets remain unmet. The measured
source is `79cc25b8c6f104da94e2b532439fe6e9b47f72ea`, authored and committed
by `zpconn <zpconn@gmail.com>`. Lean/rs1090 medians are 451.410097/810.470031 ms
for decode and 567.399785/812.985690 ms for CPR. Lean throughput increased
by 6.98% and 5.87% respectively versus generation 18. All 96 samples, six
clean-tree/lock checks, 22 freshly built native sets and four Ultimate
Performance power-plan captures are retained. Actual worker SHA-256:
`c8636e3760f9829c836a44befe239cb1f0334be6d46f93e100a4d97088f6fb7a`.
No UTC backsteps occurred; UTC-minus-monotonic differences of +441,396,829 ns
(decode) and +418,736,633 ns (CPR) remain unadjusted. Worker monotonic durations
determine the results. Environment: Intel Core Ultra 9 285K / WSL2, CPU 0;
host workload limits remain documented. [Report and raw samples](bench/GEN19.md).
Independent result review passed all 683 checks on its first execution:
`7ce0ffac700b450d0b56284fd36c5c2829cc6a9cb5f2c874657dbca0a2a4e984`.
Artifact-commit binding passed with all 192 correctness inputs identical to
the passed full gate, timed source and current tree:
`7db09303e8e74a0ebe2592214a698952af61783ecfc510f53d40ace05696e485`.
Presentation refresh passed: 40 CSV rows, 20 GIF frames, 840 plotted values,
93 links and all 23 capstones verbatim. Producer visual inspection and root
PNG inspection passed. A harmless read-only metadata-display error was
retained; no render or measurement was repeated. Independent presentation
review passed all 1,095 checks on its first execution. Completion SHA-256:
`befb0c4dd2ef52224c816cfc5488085f04f46c9c35088d786a3bea66adba966b`.
The reviewed artifacts are ready to commit and push. Then complete fresh
untimed decode and CPR diagnostics before selecting generation 20. No new
optimization is selected.

**Previous measurement: generation 18 reached 1.672168328366× decode and
1.342734836785× with CPR.** Both 2.00× targets remain unmet. The measured
source is `c19e00dd6bd45c89e4d6238d4ea9973947625449`, authored and committed
by `zpconn <zpconn@gmail.com>`. Lean/rs1090 medians are 482.908888/807.504948 ms
for decode and 600.725692/806.615314 ms for CPR. Lean throughput changed by
+0.06% and +17.68% respectively versus generation 17. All 96 raw samples,
six clean-tree and lock checks, 22 freshly built native sets and four Ultimate
Performance power-plan captures are retained. Actual worker SHA-256:
`60f7c3a9b63468db3d65565e59760eba1f10f58b5cc2fc69ee2c6dc283eebe4d`.
No UTC backsteps occurred; UTC-minus-monotonic differences of +429,111,109 ns
(decode) and +420,362,503 ns (CPR) remain unadjusted. Worker monotonic durations
determine the results. Environment: Intel Core Ultra 9 285K / WSL2, CPU 0;
host workload limitations remain documented. [Report and raw samples](bench/GEN18.md).
Independent result review passed all 679 checks. A reviewer-only stale report
path was corrected with its failed attempt retained; no measured artifact
changed. Review SHA-256:
`26224c15327d4378b3aeba5d3885057ed93b95896e8f2b5c333ae47e58ff0bb8`.
The artifact-commit binding confirms that all 190 correctness inputs match
the passed full gate, timed source and current tree:
`d61ec0289b3588a2a5890b198728c8ab32b689187de3bc1c3e426b5f454454da`.
The README and charts now show generation 18 and both unmet 2.00× targets.
Presentation validation checked all 38 CSV rows, 19 GIF frames, 760 plotted
values, 93 local links and all 23 capstones verbatim. Visual inspection and
independent review passed. Completion SHA-256:
`fc9814b940b8be9e30f190466e95025d652b0866856ea560a0e435f5fa3cec26`.
The reviewed artifacts and presentation were committed and pushed to the
private repository as `9c2745732de1626418b77b468069b12ab8a1e5c1`.
Fresh decode and CPR diagnostics completed against this source-equivalent
commit, including sequential isolated actual-worker profiles with all 281
protected inputs unchanged. The decode profiles collected 10,744,199,387
instructions; Comm-B is the largest stage at 3,612,702,399. The CPR profile
collected 13,073,500,332 instructions, of which the combined decoder accounts
for 10,747,461,664. All corpus outputs and full tracking/state checks passed.
These are diagnostic counts, not timing estimates. Both final independent
reviews passed: decode
`4c4eca9dfaab86fa3e0f0bb7059b75148fb71b0fbfda593705f833fa96f72136`,
CPR `49e7719ac8eccdb43e6a493176c98dd616434eadc14c6338e6a8a26e8d76a713`.
Both verified cleanups completed, reclaiming 275,812,352 bytes (decode) and
221,917,184 bytes (CPR), with unique perf and compressed evidence retained.
A separate power-extraction supplement independently passed:
`98bb212954e760f91e63a5e91728552af2bc86f88c2b7a28cf0667d1cf1b108a`.
It reconciles all 81 selected caller contexts: 1,467,879 direct power calls
account for 1,465,999,773 incoming inclusive instructions across the disjoint
decode families. These are observed costs, not predicted savings. The source
hold is released.

**Generation 19 selected:** replace power-of-two construction/division with
exact natural shifts and masks in `Altitude.bit`, `Altitude.grayDecode`,
`identityCode` and `payloadInteger`. This single strength reduction addresses
work in Comm-B, semantic decoding and ADS-B while retaining unrestricted
natural words, indices and widths. It adds no table, cache, hardware primitive
or frozen change. The runtime edit compiles; the lock and all import guards pass. Altitude and
identity helper proofs passed their first actual Lean build (10 jobs), with
15 permitted-axiom facts and nine kernel witnesses. A prior wrapper path
preflight failed before Lean and is retained. Independent helper review:
`4ea0c5efe8c3964aca3b8f34aab1ff69a3dec8124f7f62a05b24656a7ebb2dde`.
Initial independent runtime source review also passed:
`7c7d8167b68d2cc2d9d1e5988261511b12d2322de7981adf4e9a9844cc414ded`.
Signed-field helper proofs and existing refinement integration passed the
2,079-job targeted build on attempt 3. The new module has six kernel witness
groups; all 214 printed facts use permitted axioms. Two retained failed
attempts identified old definitional proof shortcuts in CommBTables and
oracleAC12; explicit existing equalities replace them, with every statement
unchanged. Independent proof/bridge review passed:
`a626aa245abd685f0c0b6595927806bf65d1969cbf0e2a72840db83a8232e493`.
The eight changed/new sources are staged. The combined worker/proof build
passed all 3,536 jobs on its first execution, with all 192 correctness inputs
unchanged. Record SHA-256:
`107d4bd1109e782d6c66c3a3c250abd6107bcbe54d783265f5787311d0135f01`.
The initial combined staging/build permission review timed out before execution;
separate staging succeeded and the workspace build passed. The full fixed
gate passed from 18:58:48 to 19:14:49 UTC with all 192 correctness inputs
unchanged. All 23 capstones, 152 witness proofs, 1,011 unit assertions and
seven differential components passed. The fixed campaign checked 10,476,164
messages: 9,542,689 exact matches plus 933,475 documented D001 cases, with
2,038,998 standard-view differences recorded separately. All 101,244 direct
Comm-B cases match exactly. Full-gate record SHA-256:
`0c9ead457e6e5ace1ea36a5600305320c6858a0cfe47a9cbb8ec8e888c9ea828`.
Its sealed archive and verified fixed cleanup passed; cleanup reclaimed
5,733,339,136 allocated bytes. The separate fresh 10M campaign passed on its first execution
with seeds recorded beforehand: messages 1,890,283,913 and Comm-B
1,651,874,312. It checked 10,476,164 messages: 9,543,253 exact matches plus
932,911 documented D001 cases; 2,040,622 standard-view differences are
recorded separately. All 101,244 direct Comm-B cases match exactly, with
complete 32/70/14 coverage. All 117 sources and three binaries are unchanged.
Verifier SHA-256:
`481df3cbc759c3460573d5b47057e7861d31cbb8bb9ebc9467af9d9b70041290`.
Its 33-member archive passed independent retention review and frozen
comparison replay. Cleanup removed only eight verified raw duplicates,
reclaiming 5,358,669,824 allocated bytes while preserving the active fixed run
and both historical failure roots. All 33 retained files, 117 sources, three
binaries and 264 native inputs were rehashed afterward. Completion SHA-256:
`e080913127a08ba22d6b7422aec391f1e89e5b639cd6ae5e08de7e130f216949`.
Preflight also bound all 192 correctness inputs. Current
linked-native review passed 680 checks: exactly the three changed runtime
modules among 22 native sets, all four definitions reached by live callers,
and generic natural-number behavior retained. Review SHA-256:
`1e036f1fd857a672c91d4de2bdf62e54bab00a1b366ef4186303d871f97bb2d5`.
Independent source/proof/integration review also passed, checking all 187
existing bridge statements unchanged and 238 integrated permitted-axiom facts.
The fixed/fresh cleanups together reclaimed 11,092,008,960 allocated bytes.
Final independent gate/archive/plan review passed on its first execution with
no findings. It verified all 192 inputs, seven components and 62 retained
files, source/native/proof review bindings, the fresh replay, all 38 prior
CSV rows unchanged and both exact 2/1 targets. Review SHA-256:
`f4165deed8103bdb4d809a81c5b716bd6cae5b8cf29b002b2d10a6cd62acf9f1`.
The verified source was committed and measured; the reviewed generation 19
result is recorded above.

**Previous measurement: generation 17 reached 1.669372647154× decode and
1.150460800400× with CPR.** Both 2.00× targets remain unmet. The timed source
is `0f7882f3f949118c6871a40bc012bb8a957a6a3d`, authored and committed by
`zpconn <zpconn@gmail.com>`. Lean/rs1090 medians are 483.182346/806.611392 ms
for decode and 706.958588/813.328143 ms for CPR. All 96 samples, six clean-tree
and lock checks, 22 freshly built native sets and four Ultimate Performance
captures are retained. Actual worker SHA-256:
`04b075aff3a04861d9cdb0e8d7388fe43a9fdfc0dc3a317de6a4525edb213a13`.
No UTC backsteps occurred; UTC-minus-monotonic differences of +589,956,114 ns
(decode) and +601,948,078 ns (CPR) remain unadjusted. Worker monotonic durations
determine the results. The environment remains Intel Core Ultra 9 285K / WSL2,
CPU 0, with host workload limitations documented. [Report and samples](bench/GEN17.md).
The archive helper initially rejected the run directory's naming convention;
the completed directory was renamed and all 48 original files verified
byte-identical. No timing was rerun, sample changed or helper modified. The
relocation record is in `tests/evidence/optimization/gen17/benchmark-preparation/`.
Independent result review passed all 678 checks on its first execution:
`8c81102ff81069b4e4989f665520db9ce1a4ac90d775b2dbd3d45aad4b00a8d2`.
Artifact-commit binding confirms all 188 inputs still match the passed gate,
timed source and current tree:
`6dec94304275632ada9b41d30475682fcc48db745141310b83da8fb3a765aa52`.
The README and charts now show generation 17 and the unmet 2.00× targets.
Presentation validation checked all 36 CSV rows, 18 GIF frames, 684 plotted
values, 93 links and all 23 capstones verbatim. Visual inspection and a separate
read-only review passed. Completion SHA-256:
`4bd5029763d3ed7e92ba0ecf70a8fb9e14b5ede2bf28d7b7f66ea18ce66df86b`.
The reviewed result artifacts and presentation were committed and pushed to
the private repository as `9d441eb3bdbaa17adbb289c3d82afe20307ad28b`.
Fresh untimed decode and CPR diagnostics completed against that
source-equivalent commit before selecting generation 18. Both driver builds
and the descendant source binding passed. Sequential isolated actual-worker
decode/CPR captures passed with all 279 protected inputs unchanged. All 13
decode instruction profiles passed; the CPR collection also passed its full
input, airport, tracking-output and final-state checks. Reports and independent
raw-accounting reviews passed. Decode review SHA-256:
`dac5257265edab74b9d8f8821ce6afffab04bdc7649dfbd663328b1d31f29c3c`;
CPR review:
`f8a8b47c5d486dbbc65a0f71210de87fc91e9251af853e5ddb843333e5a05f76`.
Decode collected 10,744,218,389 instructions; Comm-B remains its largest stage
at 3,612,702,286. CPR collected 15,901,328,066; numeric geography remains its
largest detailed category at 3,857,692,962. Both reviewed cleanups completed,
reclaiming 275,820,544 and 233,095,168 allocated bytes while retaining compressed
evidence and unique raw perf captures. This releases the source hold.

**Generation 18 selected:** an exact integer bit-packing path for
`Impl.CPR.Policy.toFloat`, whose 103,138 calls account for 3,333,981,092
overlapping inclusive instructions in numeric geography. This is diagnostic
evidence, not a speedup prediction or a measured fast-path hit rate. The guard
requires nonzero numerator magnitude below 2^53, denominator exactly 2^k and
k ≤ 1074. Zero remains positive zero; every other value retains the original
total conversion, including negative-underflow behavior. Prove exact exponent,
rounding and bit assembly, then equality of the complete conversion for every
rational input and integration into the existing CPR refinement statements.
The guard covers finite binary64-derived rationals of magnitude below 2^53;
it does not cover every dyadic rational of that magnitude. No frozen changes,
trusted primitives, cross-message caches or hardware arithmetic are added.
Implementation and proof work are complete. The central dyadic helper
build passed all 2,040 jobs after two routine simplifier/lemma-application
corrections; both attempts are retained. Its exponent, scaling, integer-rounding
and exact-rounding facts use only permitted axioms. Independent source/log
review passed (`75d5acfcd5d415f94bd1219483517e8c3ebfe88bbbc68f222bb10a992ed28094`).
The runtime compiles, and the lock/import guards passed. Bit assembly and CPR
integration passed the 2,048-job targeted build; all 20 printed packing/tracking
facts use permitted axioms. The first attempt's absolute-value and let-reduction
fixes are retained. Kernel witnesses cover both signs at subnormal/normal
boundaries, the largest admitted numerator, guard exclusions and underflow ties.
The combined build passed all 3,534 jobs on its first execution, with all four
changed/new sources and 190 correctness inputs unchanged. Record SHA-256:
`a4f3ddba1bced3edac6b70cfcd7be9be37a3b49f0cd4f59b64a94968b1efada3`.
An additional unfrozen conversion probe passed all 33,174 cases: 17,388 fast,
15,758 fallback and 28 zero cases, with 32,756 finite-bit checks and no mismatch.
These selected probe counts are not corpus hit rates or timings. Its first
execution preserved all 190 correctness inputs and four binaries. Completion:
`5cabef2f7921c57b5ebb12042d35b4f119e5801f29f37a4dfb0e3f4717fe95e8`.
The full fixed gate passed from 18:02:27 to 18:18:36 UTC with all 190
correctness inputs unchanged. It checked all 23 capstones, 152 witness proofs,
1,011 unit assertions and seven differential components. The fixed campaign
checked 10,476,164 messages: 9,542,689 exact matches + 933,475 documented D001
cases; 2,038,998 standard-view differences remain separately recorded.
All 101,244 direct Comm-B cases match exactly, with complete coverage.
Full-gate record SHA-256:
`93d94f75ed06e97358da45b35367fc2e6f26876806effa3bc25f05bbb165cacb`.
The generation 18 measurement and result review are recorded above. The
separate fresh campaign passed on its first execution with
seeds recorded beforehand: messages 22,240,697 and Comm-B 2,968,091,489.
It checked 10,476,164 messages: 9,543,003 exact matches + 933,161 documented
D001 cases, with 2,039,700 standard-view differences recorded separately.
All 101,244 direct Comm-B cases matched exactly, with complete 32/70/14 branch
coverage and no unclassified differences. All 115 sources and three binaries
remained unchanged. Fresh verification SHA-256:
`1fc521f1d3a0d0dade3ad5bc77b364d39f519de36d548c34afdeeb6a8c8fe31e`.
Independent retention review passed all 33 members; frozen comparison replay
also passed on its first execution. Fresh cleanup removed only eight verified
raw duplicates and reclaimed 5,359,562,752 allocated bytes, preserving the
active fixed run and both historical failure roots. All retained files, sources
and binaries were rehashed afterward. Completion SHA-256:
`2a4d4252ee5710d7c771453ffe41e7b6d36e9a1b9d99dad40beb458829b64a06`.
Independent source/proof and linked-native reviews passed. The native review
bound all 22 linked sets and 262 held inputs; only CPRFloat's set changed.
Its actual wrapper executes the integer fast path and retains the original
fallback. Decimal Nat parsing and lazy scalar initialization remain in the
generated program, so no allocation-free claim is made. Native review:
`2eb0ef7172a7ac0df89651e3bfd46244b584ffe52d31a46482b6b79b5b1873bd`.
The new nested fresh-evidence directory needed a scoped ignore rule and an
exact additional archive-root shape in the unfrozen cleanup helper. Both
were reviewed; all 31 cleanup fixtures passed independently. No locked or
captured correctness input changed. Fixed-gate archival and verified duplicate
cleanup passed, reclaiming another 5,733,330,944 allocated bytes. Combined
fixed/fresh cleanup reclaimed 11,092,893,696 bytes while preserving compressed
evidence and unique failures. Final independent gate/archive/plan review
passed, checking all 190 inputs, 104 locks, seven components and 62 retained
files, both campaigns, the source/proof/native/probe reviews and both cleanup
receipts. It preserved all 36 prior CSV rows and the separate exact 2/1
targets. Review SHA-256:
`a3aba9a73f0044243785a8b04636b627a6405c86ca2565fc413fd04fdfa22142`.
A reviewer-only assumption about two diagnostic seals awaiting this commit
was corrected with its failed attempt retained; producer evidence was
unchanged. The source was committed and both modes measured from its clean,
fresh build with all other project work stopped. The next diagnostic
controllers are prepared and independently reviewed; they have not run and
await the generation 18 artifact commit.

**Previous measurement: generation 16 reached 1.668888276454× decode and
1.029132958936× with CPR.** Neither 2.00× target is reached. The measured source
is `1593898c4425fb174ba4085ab68691feba28124e`, authored and committed by
`zpconn <zpconn@gmail.com>`. Decode medians are 483.018968 ms for Lean and
806.104693 ms for rs1090; CPR medians are 785.609215 ms and 808.496336 ms.
All 96 samples are retained, with six clean-tree/lock checks, 22 freshly built
native sets, CPU 0 affinity and four Ultimate Performance captures. The
actual worker SHA-256 is
`26e79af2c955a0dc8a0fdb1107d77b8c2b93ad31025fdd9e32112a37ee5c416f`.
No UTC backsteps occurred; outer UTC-minus-monotonic differences of
+570,713,706 ns (decode) and +583,531,483 ns (CPR) remain unadjusted. Worker
monotonic durations determine the results. Independent result review passed
all 664 top-level checks on its first execution; review SHA-256:
`1bbf383f6c999730cc307b9b463b38e07eb8d414584b50bb216a675752b358ac`.
The environment remains WSL2 on an Intel Core Ultra 9 285K, with host workload
limitations documented. [Report and raw samples](bench/GEN16.md).
The artifact-commit binding confirms all 187 inputs still match the passed
full gate, current tree and timed commit; record SHA-256:
`7f16e0febb363bbe3e4e2929c04a20f55dc55e7962aab33164922a760690b61a`.
The source and reviewed artifacts were pushed to the existing private repository
as `b4765cc1e07a758bc4661c4f6f513deb39672b9f`. Fresh untimed decode and CPR
diagnostics passed before choosing generation 17. Both fresh diagnostic reviews passed, releasing the hold after verified
scratch cleanup. Decode total: 10,748,675,266 collected instructions; Comm-B
is its largest stage at 3,617,157,311. CPR total: 17,998,526,291; numeric
geography is the largest detailed category at 5,562,629,612. All full outputs,
172,432 tracking rows and final state match. These are diagnostic counts,
not benchmark predictions. Review hashes:
`2e02055deba6efcf24b82ea55574a2e7ca0f8e616a4d769f181373da1ff5ff9e`
(decode) and
`36fa921f9dab11420481847ff59cf32f97d3207c1aaa4f1b38c1ee0c6f799c95`
(CPR). The reviewed decode cleanup reclaimed 277,315,584 allocated bytes,
retaining its unique raw perf capture and compressed evidence.

**Generation 17 selected:** replace repeated `Binary64.powerTwo` construction
with an immutable 2,098-entry table keyed only by format exponents −1074
through 1023. Keep the original total formula for every other exponent.
The table constructor uses that formula directly; it must not depend on
rounding or its own lookup. Prove equality for every integer exponent and
propagate it through all arithmetic, decoder and CPR tracking contracts.
The numeric-geography profile observed 460,693 power calls with
1,738,677,460 overlapping inclusive instructions, including 261,723 direct
rational divisions. No table-hit frequency or speedup is inferred. Preserve
observed initialization costs in the frozen benchmark. Zero new trusted
primitives or frozen-file changes are authorized. Implementation and proof
work are in progress. The central helper build passed; all 32 printed facts
use permitted axioms, including five kernel witnesses covering seven boundary
exponents. The first helper proof attempt needed a simplifier-normalization
correction; its source and log remain retained. Implementation summary SHA-256:
`8b53c1c599e86afd938aaf0ae9683ddf3024eb559c24b8260b36328c8b78706e`.
The CPR duplicate cleanup additionally reclaimed 243,105,792 allocated bytes.
The six decoder/Comm-B proof modules passed their first build (2,079 jobs,
190 permitted-axiom facts). The CPR proof passed after adding two explicit
reflexivity closures; all ten printed facts use only permitted axioms,
including complete numerical-geography program equality. Its failed attempt
is retained. The combined six-target build passed all 3,532 jobs on its first
execution with nine sources and all 188 correctness inputs unchanged;
record SHA-256:
`eb800bef73aa6513d18f3b33f90bb19851ae037b977155080c9e8dd72cdf554f`.
The full gate passed from 17:08:05 to 17:25:59 UTC with all 188 correctness
inputs unchanged. It checked all 23 capstones, 152 witness proofs, 1,011 unit
assertions and all seven differential components. The fixed campaign checked
10,476,164 messages: 9,542,689 exact matches + 933,475 documented D001 cases;
all 101,244 direct Comm-B cases matched exactly, with no coverage errors.
Its 2,038,998 standard-view differences remain separately recorded. Full-gate
record SHA-256:
`2af7f2c62ee23ab7d7cfe20fed2251084e68abee165a15a7d1fee2fb408bd38b`.
The separately seeded 10M campaign passed on its
first execution (messages 1092673074, Comm-B 2959148338, recorded beforehand):
10,476,164 messages = 9,542,937 exact matches + 933,227 documented D001 cases,
with 2,038,816 standard-view differences recorded separately. All 101,244
direct Comm-B cases match exactly. Coverage includes all 32 DF attempts,
70 ADS-B branches and 14 registers, with no unclassified differences or gaps.
All 113 sources and three binaries remained unchanged. Independent retention
review passed all 33 retained files; the frozen comparison-only replay also
passed. Fresh verification SHA-256:
`2fb04dd1fae997f4595a2701fa48a3ead90207193a4d412d16af14d26318c9d6`.
Independent retention review SHA-256:
`e31b6401a01dd89362dc5b44ea9ee2e8b707fd6e842d41902f65d5ddfedbe205`.
The fresh cleanup removed only eight verified raw duplicates and reclaimed
5,359,292,416 allocated bytes, preserving all 33 retained files and the active
fixed run. Completion SHA-256:
`bfaf3c44cce4cc6fb62bb38769d15cb588e24c24c71fccd14d5392bee46a1070`.
Independent central-source/proof and linked runtime reviews passed. Native
review checked 111 conditions, all 22 linked sets, 260 held inputs, eager
initialization before main, guarded lookup/fallback and live CPR/Comm-B
consumers; the other 21 native sets are byte-identical to generation 16.
Review SHA-256:
`cb162d0f05f10dde89132d4a09f930c3e84b9e620839861cd0e16062108ff59c`.
The combined log has 200 permitted-axiom facts, including three axiom-free
facts. Reviewer-only count/filter corrections are retained; no producer
change was needed. Fixed-gate archival and final independent review passed
on their first executions. The review checked all 188 inputs, seven
components and 62 retained files, fixed/fresh coverage, native/proof bindings,
the unchanged 34-row CSV prefix and both exact 2/1 targets. Review SHA-256:
`fe14b67f2435e228eb70a7fe910e6fc2adaad5f6f24e1a30b791c796924b879e`.
The fixed cleanup reclaimed another 5,733,330,944 allocated bytes; combined
fixed/fresh cleanup reclaimed 11,092,623,360 bytes while preserving compressed
evidence and unique earlier failures. The source was committed and both modes
were measured from its clean fresh build with all other work stopped; results
are recorded above.
[Implementation and proof](docs/GEN17-POWER-TABLE.md).

Read-only planning for a possible later CPR change identified an exact dyadic
shortcut for `toFloat`: nonzero canonical rational numerator magnitude below
2^53, denominator exactly 2^k and k ≤ 1074. Integer shifts can construct its
binary64 bits after proving exact binade and rounding identities. Zero would
remain positive zero; every rejected input keeps the existing conversion.
The guard covers finite binary64-derived rationals with magnitude below 2^53,
not arbitrary small dyadic rationals. No such implementation or new lemma has
been written, and no hit rate or speedup is claimed. Selection requires the
next measured generation's fresh diagnostic. `toFloat32` would remain separate
because its negative-underflow sign behavior differs.
A separate read-only decode candidate is direct integer-times-rational
construction in `affineValue`: multiply the field integer by `scale.num` and
normalize once against `scale.den`, with a denominator-one shortcut, preserving
the offset step. Current code skips only identity scales and zero offsets.
No implementation, proof or per-scale frequency count exists yet; this also
requires the next diagnostic before selection.
See [decode](docs/GEN16-COST-BREAKDOWN.md) and
[CPR](docs/GEN16-CPR-COST-BREAKDOWN.md) diagnostics.

Generation 16 started from pushed commit
`7163b2506f3b4045caa98721aa90b7042733b0fe`. The preceding untimed live
cost breakdowns for decode and CPR passed independent review. Both isolated actual-worker perf captures completed with
197 protected inputs unchanged; completion record:
`tests/evidence/diagnostics/gen15-cpr/isolated-perf-completion.json`.
The decode corpus output digest and control-flow census match generation 0.
The CPR driver's full 172,432-row tracking audit and final state match the
frozen worker byte-for-byte, resolving 11,347 positions. Decode review SHA-256:
`97333e1b8672ddd31bc926d0571ee5949f7e2aff000ab4b3daf13d9a26c2249e`;
CPR review:
`67272c55dcb02445b531b35a0bef6f149ab0f0e795b25661e61051fb923744c4`.
Frame/CRC is the largest decode stage (3,961,737,590 of 11,213,423,773
collected instructions). Numeric geography is the largest detailed CPR stage
(5,562,621,468 of 18,463,254,211). These are diagnostic counts, not speedup
predictions. See [decode](docs/GEN15-COST-BREAKDOWN.md) and
[CPR](docs/GEN15-CPR-COST-BREAKDOWN.md) reports. That review released the source hold for generation 16.

**Generation 16 implementation and validation:** replaced repeated powers and multiplication in
the general field-packing fold with natural-number shifts and a UInt64 mask
for widths below 64, retaining the unrestricted wider-field fallback. The
packing fold accounts for 1,280,682,876 inclusive decode instructions;
881,619 direct power calls account for 882,818,451 of those instructions.
Its all-input proof and whole-decoder integration passed the helper and
combined builds on their first executions. The integrated build checked
3,524 jobs; all nine new facts and both decoder refinements use only permitted
axioms. The full gate passed from 16:18:40 to 16:34:32 UTC with all 187
correctness inputs unchanged. It checked all 23 capstones, 152 witness proofs,
1,011 unit assertions and all seven differential components. The fixed
campaign checked 10,476,164 messages: 9,542,689 exact matches + 933,475
documented D001 cases, with all 101,244 direct Comm-B cases exact and no
coverage errors. Its 2,038,998 standard-view differences remain separately
recorded. The
fresh 10M campaign passed on its first execution: 10,476,164 messages =
9,543,217 exact matches + 932,947 documented D001 cases; all 101,244 direct
Comm-B cases match exactly. All 32 DF attempts, 70 ADS-B branches and 14
registers are covered, with no gaps or unclassified differences. The
2,037,560 standard-view differences are recorded separately. All 112 sources
and three binaries remain unchanged. Independent retention review and
comparison-only replay passed their first executions. Fresh completion
SHA-256: `2bcf68e3b9dd6fff78d91616dce911d533678ac3163ab5797bc30d3098c707a8`.
Exactly eight verified raw duplicates were removed after archival, reclaiming
5,359,882,240 allocated bytes while preserving all 33 retained files and the
active fixed-gate scratch. Fresh verifier SHA-256:
`288f95bf1e0b7189e04b7c53a638e2e2ef4b9ede394eaa490d14451b3f461d1b`.
Independent native review passed on its first
execution, checking the live shift/mask loop, wide fallback, all nine proof
facts, 21 unchanged sibling native sets and 104 locked hashes. Review SHA-256:
`fc8af38e62b1ef7726f227dee34bed319e0cdf420eaf4e41256e1ad4f8c850d6`. Fresh
seeds recorded before execution: messages 1400844992, Comm-B 1518488658.
The final independent gate/archive/benchmark-plan review passed, checking all
187 inputs, seven components/62 retained files, complete fixed/fresh coverage,
native/proof bindings, both exact 2/1 targets and the unchanged 32-row result
prefix. Review SHA-256:
`180f14c351a50a29ca555b88062c8bd1b974fc38fe617f528ac9427f7ae08cf5`.
One reviewer-only absolute-path API mistake was corrected with its original
source/log retained; no production change was needed.
The fixed archive and verified scratch cleanup completed, reclaiming another
5,733,335,040 allocated bytes. Combined fixed/fresh cleanup reclaimed
11,093,217,280 bytes while retaining compressed evidence, the earlier proposal
and the interrupted generation 15 attempt. The verified source was committed
and both frozen benchmark modes completed from its clean fresh build, with
all other work stopped. The independent result review passed as recorded
above. [Implementation and proof](docs/GEN16-PACK-FIELDS.md).

Read-only planning identified a possible later CPR change: an immutable table
of exact `Binary64.powerTwo` values for format exponents −1074 through 1023,
with the original total formula outside that range. It would need a central
all-input binary64 equality proof and propagation through the decoder,
BDS50, Mach/QNH, ratio and CPR tracking proofs. The table must initialize
from the original power formula, without calling rounding or its own lookup.
This was subsequently selected for generation 17 after the fresh generation 16
diagnostics and independent reviews above.

The unfrozen reporting
helper now supports separate exact targets for both modes; seven fixture
tests passed, including unchanged reconstruction of the old generation 15
report. Independent reporting review passed 3,318 exact decision cases plus
those seven fixtures, with all 186 correctness inputs unchanged; review SHA-256:
`3ed2081e864a2fd55e34bd8a799a84587873f295baed828585b2ebc291affb4b`. Continue verified commits and private pushes under
the user's identity, retaining all proof, frozen-file, benchmark and disk-use
safeguards. Stop for review when both new targets are reached. No frozen-file
change or trusted primitive is authorized.

**Starting measurement:**
Generation 15 measured **1.607053275134× rs1090** in decode mode and
**0.990643654222×** with CPR. The verified source commit is
`e659220307538f2aee5398efdb0a9182bff1d778`, authored and committed by
`zpconn <zpconn@gmail.com>`. All other jobs stopped before its fresh build and
both frozen ABAB modes. The actual worker SHA-256 is
`4deead5e3f59d9e1bc6b850d3dd0bfe6b3f0ce3a9b0b2d44263af26345432c08`.
Decode medians: Lean 507.041386 ms / 340,074.804071 msg/s; rs1090
814.842520 ms / 211,613.895652 msg/s. CPR medians: Lean 812.869274 ms /
212,127.589903 msg/s; rs1090 805.263788 ms / 214,131.074276 msg/s.
All 96 samples are retained (48 per mode), with six clean-tree/lock checks,
22 freshly built native sets and four Ultimate Performance captures on CPU 0.
There were no UTC-label backsteps. Outer UTC-minus-monotonic differences
(+671,880,615 ns decode; +1,206,615,574 ns CPR) remain unadjusted; medians use
worker monotonic durations. The environment remains WSL2 on an Intel Core
Ultra 9 285K, with external host workload limitations documented.
[Report and all raw samples](bench/GEN15.md). The two new CSV rows preserve
all 30 previous rows. Independent result review passed all 2,026 checks on
its first attempt, including 8,582 committed historical files, 11,640 manifest
entries and all 15 retained raw perf captures. Review SHA-256:
`370f5df1a6abd6717b18652fd61709f85764524cd4eca7ec61d0de3dc271af43`.
The artifact-commit binding confirms all 186 inputs still match the passing
full gate and timed source. The source commit has been pushed to the existing
private repository; all benchmark samples, result rows and reviews accompany
the result-artifact commit. The previous review checkpoint is resolved by
the new stretch-goal instruction above.

**Optimization resumed (2026-10-19 UTC):** the user requested continued work
toward **1.50× rs1090 headline decode throughput**. This supersedes the earlier
1.10× review stop and publication pause. Start from
`95bc97d75d83190371768950e56ef7cc0825308d`, with generation 10's measured code
(decode 1.168948811789×, CPR 0.790786943138×). Continue verified generations
and pushes to the private repository under `zpconn <zpconn@gmail.com>`;
stop for review at the new target. All frozen-file, proof, differential,
fresh-build and isolated ABAB measurement requirements remain in force.
Zero new trusted primitives are authorized.

**Resumed at the user's request (2026-10-19T15:11:34.314754+00:00):**
the disk-cleanup pause is over. The previously suspended generation 15 gate
process group is no longer present, so that attempt is retained as interrupted,
not passed. Its original log, source snapshot and 92 as-found output files
(1,135,129,422 bytes) are preserved; interruption record SHA-256:
`7fbab1e070235d0a3673b0852a1f478cc1e2a09f6db3e5d4fc7fe28b99d259fa`.
The restarted full gate passed from 15:11:33 to 15:26:58 UTC with all 186
correctness inputs unchanged. The completed fresh campaign is retained. At that resumption point,
no generation 15 timing or commit had occurred.

Cleanup recovered about 198 GiB, reducing this repository from 256 GiB to
58 GiB at the recorded check. All compressed evidence, sources and active work
were preserved. At resumption, disk readings showed WSL with 572 GiB free and Windows
C: with 223 GiB free; the cause of the later host-space increase was not
observed. See [docs/DISK-CLEANUP-2026-10-19.md](docs/DISK-CLEANUP-2026-10-19.md)
and its verification receipts. Historical cache binary paths listed as omitted
in archive manifests may now be absent; source/hash/command provenance remains.
No historical compressed evidence was removed.

**Disk-use prevention requested:** archive verification followed by removal
of byte-identical raw scratch is now a standing workflow rule in AGENTS.md.
Reusable unfrozen maintenance helpers passed 44 author/independent safety
tests and review of the actual archived formats. They run after successful
archival, outside the frozen gate; active runs, unique failures and compressed
evidence remain protected. The first live run removed four small strata and safely retained both message
scratch directories after detecting archive filesystem metadata changes. All
15 archive files still matched their hashes; the two recorded identity changes
were allocation-only, while the first failed file's original tuple was absent.
After synchronizing the archive, a fresh strict verification removed both
complete message scratch sets. In total, this run reclaimed 11,092,762,624
allocated bytes (10.33 GiB), preserving the interrupted logs and snapshot,
all compressed evidence and every cleanup receipt. The wrapper now synchronizes copied archives before cleanup inventory; its
correction passed 25 author tests, 24 independent deletion tests and five
independent flush tests. The strict cleanup helper and all gate inputs are
unchanged. Independent correction review SHA-256:
`66fe9441bf19a995638679833f61c75ff25c3a9e994685198141abbce6096d6a`.

**Previous measurement:** generation 14 (`cd749c8`), decode **1.459178582840×**
rs1090 and CPR **0.933269340154×**. Decode regressed from generation 13's
1.492757184729×; the exact 1.50× target remains unmet. Both runs are retained
unchanged. The source commit is pushed. Its full gate and fixed/fresh 10M
campaigns passed; independent measurement review passed all 1,983 checks.
The fresh diagnostic and independent review passed, releasing the source/
native hold for generation 15 below. Comm-B
inference remains the largest stage: 4,103,080,791 of 11,699,353,673 collected
instructions (35.07%). These are diagnostic counts, not timing predictions.
All 13 profiles, 241 held inputs, 22 native sets and 11,640 historical files
passed review. Final review SHA-256:
`0409d020646467981d2b0af210429c9505bbb3927c38cde218d9674df491f5e3`.
Details: [docs/GEN14-COST-BREAKDOWN.md](docs/GEN14-COST-BREAKDOWN.md).

**Generation 15 implementation and validation:** the reviewed diagnostic found that the live
Comm-B wire validator reconstructs the exact `2^56` limit by parsing decimal
text on all 627,880 calls, with 484,723,360 inclusive collected instructions.
The selected change initializes that immutable format constant once. It does
not alter the bound, register policy, score arithmetic or input domain.
The helper and integrated builds passed their first executions; the all-input
validator equality is definitional, and all six new printed facts use only
permitted axioms. Generated C initializes the literal once. The restarted full gate passed after the documented interruption, with fixed sources. It checked all 23 capstones, 152 witness axioms, 1,011 unit assertions and all seven differential components. The fixed campaign checked 10,476,164 messages: 9,542,689 exact matches plus 933,475 documented D001 cases; all 101,244 direct Comm-B cases match exactly. The separate fresh 10M campaign
passed on its first execution: 10,476,164 messages = 9,543,150 exact matches
+ 933,014 documented D001 cases, plus all 101,244 direct Comm-B cases exact.
All 32 DF attempts, 70 ADS-B branches and 14 registers are covered with zero
gaps or unclassified differences. The 2,037,305 standard-view differences
are recorded separately. All 111 sources, three binaries and 33 retained
artifacts verified unchanged; independent raw replay passed. Fresh seeds:
messages 3228104537, Comm-B 1212762037, recorded before generation. Independent native review passed 30 checks, verifying 144 held inputs and
460 retained files. The linked guard directly loads the shared constant;
19 other production sets are unchanged. Review SHA-256:
`cd64c9e72770cb25ed9b7c52ab241dac8ba3436db961945ba5b9380f912468f8`.
Reviewer-only path/format assumptions were corrected with all failed records
retained; no production changes were needed. The final independent gate/archive
review passed, checking all 186 inputs, 62 archived component files
(1,198,313,487 bytes), fresh/native/proof bindings, 658 generation 14 artifacts,
11,640 older files and the unchanged 30-row result prefix. It also verified
the interrupted-attempt preservation and sequential cleanup receipts, with
the wrapper correction separately reviewed. Final review SHA-256:
`216e336ec8a0d96dc924181dc1bd60217670d5e650a54504369365f42af233dc`.
The verified source was committed and measured as recorded above. Details:
[docs/GEN15-COMMB-CONSTANT.md](docs/GEN15-COMMB-CONSTANT.md).

The fresh untimed generation-10 diagnostic and independent review passed:
all 13 profiles, 172,432 complete outputs, 22 native artifact sets, 117 audited
Lean sources and 7,318 historical files checked. Frame/CRC is the largest
stage at 7,401,732,346 of 16,479,393,245 collected instructions (44.92%).
These are diagnostic counts, not timing claims. Details:
[docs/GEN10-COST-BREAKDOWN.md](docs/GEN10-COST-BREAKDOWN.md); final review
SHA-256 `985af7555768bece4c978357744954de736ffab8a6f371e616f2a9ff6352ffe1`.
The diagnostic source hold is released; every retained profile remains intact.

**Generation 11 complete:** replaced CRC's temporary list of bit indices
and natural-number remainder with a specialized `Nat.fold` over `UInt32`.
The public step API delegates to the same low-24-bit update. Widths, words
and the arbitrary-precision fallback for bit indices beyond 127 remain
unrestricted. The final symbolic helper build passed 2,045 jobs, with all
eleven printed facts using only permitted axioms and seven kernel witnesses.
The first integrated build passed 3,518 jobs, preserving the whole-decoder
refinement theorem. Independent source/proof/native review passed all 42
checks with 140 inputs unchanged: the linked loop uses a 32-bit remainder,
no range list, and one final result projection; the high-index fallback
remains live. The full gate passed from 02:05:35 to 02:20:48 UTC with all
182 audited inputs unchanged: all 23 exact capstone contracts, 152 witnesses,
module/dependency guards, 1,011 unit assertions and seven differential
components. The fixed campaign checked 10,476,164 messages = 9,542,689 exact
matches + 933,475 documented D001 cases, and 101,244 exact direct registers.
The separate fresh 10M campaign passed:
10,476,164 messages = 9,542,726 exact matches + 933,438 documented D001 cases;
all 101,244 direct Comm-B cases match. All 32 DF attempts, 70 ADS-B branches
and 14 registers are covered, with zero gaps or unclassified mismatches.
Fresh message seed: 2823995389; Comm-B seed: 3756304815, both recorded before
generation. All 107 sources, three binaries and 33 retained artifacts passed
independent review. The 2,038,888 standard-view differences are recorded
separately. All seven component trees and their passing log/source bindings
are archived without changing their originals: 62 files totaling
1,198,313,543 bytes. The independent gate/archive review passed on its first
execution, checking all 182 inputs, seven archives, fresh provenance, native
and proof bindings, 643 gen10 artifacts, 7,318 older files and all 22 prior
results rows. Review SHA-256:
`9e927300f0a56f218b0d7c1e308798466f88803ed33fe7c7f3e102ed70d6f641`.
The verified change was committed as
`fd20b1c3553415b1b727f1dca347d4d43dd0d142`. After all other jobs stopped,
a fresh build from that clean commit regenerated 22 native sets; the timed
worker SHA-256 is
`8abd618f802719109ef3da7d36c9280740551596635b99953ef172bd1ca1b5ae`.
Both frozen 3+21 ABAB modes completed on CPU 0, with 48 samples each, six
clean-tree/lock checks and four Ultimate Performance captures. Decode:
Lean 657.029319 ms / 262,441.865247 msg/s, rs1090 833.334725 ms /
206,918.054447 msg/s, ratio **1.268337197293×**. CPR: Lean 993.549075 ms /
173,551.568150 msg/s, rs1090 841.713800 ms / 204,858.230909 msg/s, ratio
**0.847178887465×**. All original samples are archived under
[bench/runs/gen11/](bench/runs/gen11/), with a
[complete report](bench/GEN11.md); two CSV rows were appended preserving
all 22 previous rows. There were no UTC-label backsteps; recorded outer
UTC-minus-monotonic differences remain unadjusted. Independent result review
passed all 1,972 checks, including every sample, clean source/native binding,
24-row CSV and historical records. Review SHA-256:
`1e1362fbe371ff1c2f29f2d5d592d41e53939a7b37429b61fa8c7b0b5b6bbe4e`.
The 1.50× decode target is unmet.

The complete fresh generation-11 diagnostic and independent review passed:
13 profiles, 238 held inputs, 22 native sets, 565 non-review evidence members
and 8,294 historical files. Frame/CRC remains the largest stage at
5,609,294,040 of 14,737,399,882 collected instructions (38.06%); its largest
concrete helper is `bytesValue`, with 2,100,152,579 inclusive instructions
across 172,432 calls. These nested costs overlap; they are diagnostic counts,
not benchmark predictions. Report: [docs/GEN11-COST-BREAKDOWN.md](docs/GEN11-COST-BREAKDOWN.md).
Final review SHA-256:
`5e3fcc6356d27443f272141f562db8d708ad6f8d482ef1baed2c49087e92bafa`.
The diagnostic hold is released.

**Generation 12 complete:** converted bytes in UInt64 chunks for lengths up
to 16, avoiding repeated arbitrary-precision multiply/add operations. A
tail-recursive prefix reader returns the existing suffix without copying the
prefix; longer lists retain the general natural-number fold. The helper and unconditional all-list equivalence proof passed their targeted
build (2,042 jobs), with eleven permitted-axiom facts and seven boundary
witnesses. The initial failed case-selection tactic and source are retained;
the successful proof uses explicit length cases. The first integrated build passed 3,520 jobs, retaining the whole-decoder
refinement. [Implementation and proof](docs/GEN12-BYTE-WORDS.md).
The full gate passed from 02:41:03 to 02:57:11 UTC with all 183 audited inputs
unchanged: 23 exact capstone contracts, 152 witness axiom audits, module and
dependency guards, 1,011 upstream unit assertions and all seven differential
components. Fixed whole messages: 10,476,164 = 9,542,689 exact + 933,475 D001;
all 101,244 direct registers match. The seven component archives and their
passing log/source bindings are retained. Fresh message seed
3912489638 and Comm-B seed 2788617979 were recorded before generation;
the separate 10M campaign passed on its first execution: 10,476,164 messages
= 9,543,025 exact matches + 933,139 documented D001 cases, and all 101,244
direct registers exact. Coverage includes all 32 DF attempts, 70 ADS-B branches
and 14 registers, with zero gaps or unclassified differences. Its 2,039,033
standard-view differences are retained separately. All 108 source hashes,
three binaries and 33 retained artifacts passed producer verification and
an independent retention replay, including decompressed transcripts and
separately counted difference streams. Fresh review SHA-256:
`069ccb2be918152a1d6a4f454b22e29978557d0097018c40e94d4c66535bd803`. Runtime, proof and generator
sources remained fixed throughout the full gate. The final independent
archive review passed: all 183 inputs, seven component archives (62 files,
1,198,313,686 bytes), native/proof/fresh bindings, 633 prior gen11 artifacts,
8,294 older files and all 24 prior CSV rows. Review SHA-256:
`9c76fb0536a16b2ebaf3556014f33ac0f23093a496a56be5b5462e2b74cd368c`.
The verified change was committed as
`0592f80708c92e283a4c802f04b5889d5d69a3aa` and pushed to the private repository under the user's
configured GitHub identity. All other jobs stopped before a fresh build from
that clean commit; the actual timed worker SHA-256 is
`e2c212b470c6b331cf1b11a095adb991392b7aa7a89dea5421018acb6bcbbbee`. Both frozen 3+21 ABAB modes completed on CPU 0,
retaining 48 samples each, six clean-tree/lock checks and four unchanged
Ultimate Performance captures. Decode: Lean 595.109526 ms /
289,748.344576 msg/s, rs1090 818.778780 ms / 210,596.566755 msg/s,
ratio **1.375845527971×**. CPR: Lean 925.466896 ms / 186,318.928041 msg/s,
rs1090 827.818723 ms / 208,296.810895 msg/s, ratio **0.894487665175×**.
All samples are retained in [bench/runs/gen12/](bench/runs/gen12/), with the
[full report](bench/GEN12.md). Two results rows preserve all 24 previous rows.
Independent result review passed all 1,978 checks, including every original
sample and source/native binding. Review SHA-256:
`726d98a71f25707a3af5d880dff8934b77f9c787249aa7ca763832e65e5a0b77`.
The 1.50× headline target remains unmet.
Independent source/proof/native review passed 41 checks with 141 held inputs
and 221 retained files. The compiled short and medium paths use machine-word
loops; the prefix allocates only its endpoint box and pair. The arbitrary-
length fallback remains the original natural-number fold. Compiler borrowing
changes in Frame/Message were checked against unchanged Lean sources; the
other 17 production native sets are identical. Two reviewer assumption fixes
are retained, with no runtime or proof change. Native review SHA-256:
`9df8ef966e4474e91391d85c49a299d158dc43c04cb6eee1ffb63b2d1ab265f7`.
The frozen specification and statements remain unchanged, with zero trusted
primitives.
The fresh generation-12 diagnostic and independent review passed on their
first completed executions: 13 profiles, 2,547 helper rows, ten penalty-probe
rows, 239 protected inputs and 9,286 historical files. Comm-B inference is
now the largest exclusive stage: 5,493,654,948 of 13,089,567,899 instructions
(41.97%). Its BDS50 candidate penalty used 1,066,037,418 inclusive instructions,
compared with BDS60's 844,659,720. These nested counts overlap the exclusive
stages and are diagnostics, not timing predictions.
[Complete diagnostic](docs/GEN12-COST-BREAKDOWN.md); independent review SHA-256:
`8e4a4a6b88b7a6a5a3b8607a16c3e8e621d52a0847d37fd6ba98b579b1844f43`.
The diagnostic hold is released. **Generation 13 in progress:** replace the
BDS50 wind-penalty calculation with a 2,047-entry immutable table indexed by
the signed difference of the two ten-bit speed codes. Retain every software
binary64 rounding operation in its reference body, and prove the lookup for
all payloads. The final roll/track-rate adjustment and BDS60 remain unchanged.
The helper build passed first attempt (777 jobs), with eleven permitted-axiom
facts and six kernel witness theorems. Its unconditional equality is now
integrated into whole-decoder refinement: the first integrated build passed
3,521 jobs. The full gate and separate fresh campaign are in progress with
all runtime/proof/generator sources fixed. Fresh seeds were recorded before
generation: message 1,867,035,726; Comm-B 1,294,228,047. Independent source/proof
review passed. Independent compiled-path review passed all 35 checks with
142 held inputs and 347 retained files; the live lookup and eager table
constructor preserve the software reference, and all nineteen other native
sets match generation 12. Review SHA-256:
`0228be252c9a2bb3534bce72c01c4fdcd4f91c580cb71be69cff6a8b5c495fcb`.
The separate fresh campaign passed on its first execution: 10,476,164
messages = 9,542,998 exact matches + 933,166 documented D001 cases, with all
101,244 direct registers exact. All 32 DF attempts, 70 ADS-B branches and
14 registers are covered without gaps. The 2,037,018 standard-view differences
are recorded separately. Independent retention replay verified all 109
sources, three binaries, 33 artifacts, eleven raw gzip transcripts and three
difference streams. Review SHA-256:
`cef68535d6f6745186478df7b3706a6b0e1c0d6d5b453a33e2adfb0231e2ddfa`.
A reviewer-only obsolete preparation-path assumption was corrected and both
attempts retained; the campaign itself needed no retry. Benchmark metadata
preparation likewise retained an initial wrong-generation output-path check
and its correction before writing any plan or measurement. The final plan
preserves all 26 prior CSV rows and the exact 3/2 target.
The fixed full gate passed from 03:19:36 to 03:35:32 UTC, with all 184
audited inputs unchanged: 23 exact capstone contracts, 152 witness audits,
1,011 unit assertions and seven differential components. Whole-message
counts are 10,476,164 = 9,542,689 exact + 933,475 D001; all 101,244 direct
registers match. All component archives are retained. Final archive review
passed after recovering one ignored historical Python bytecode cache exactly
from retained source and its timestamp header. A reviewer import without
bytecode suppression had regenerated that cache. The authoritative old hash
matches; both cache versions, failed review/recovery attempts and the successful
recovery are retained. No historical record or correctness input was changed
or waived. The final review verified all 184 inputs, seven archives (62 files,
1,198,313,683 bytes), fresh/native/proof bindings, 637 gen12 artifacts,
9,286 older historical files and all 26 prior CSV rows. Review SHA-256:
`4c8eb54e34a7232a1d5d917cf8ffa3cd90224e8ade8616d9da6b30071e176689`.
The verified generation was committed as
`247a28d9a681fd5fac37a630cc4a889e30000490`, under the user's GitHub identity,
and pushed to the authorized private repository.
After all other jobs stopped, the frozen benchmark completed both modes from
that clean commit, with a fresh worker build. Worker SHA-256:
`b13fac61e8bd1170cdcacae3c3c054bc05f484da39ebf2d823dd868ab5920730`.
Decode: Lean 545.485333 ms / 316,107.491015 msg/s; rs1090 814.277150 ms /
211,760.823695 msg/s; ratio **1.492757184729×**. CPR: Lean 879.435413 ms /
196,071.249180 msg/s; rs1090 814.913303 ms / 211,595.514965 msg/s;
ratio **0.926632349521×**. All 48 samples per mode, clean/lock checks,
native-build records and four power-plan captures are retained in
[bench/runs/gen13/](bench/runs/gen13/), with a [full report](bench/GEN13.md).
Two CSV rows preserve all 26 previous rows. Independent result review passed
all 1,981 checks, including every sample and clean source/native binding.
Final review SHA-256:
`d6e766e6758fc853194fc6687302bef33c26731ccaff3bea417488fb44df92d3`.
No UTC backsteps occurred; the recorded outer UTC-minus-monotonic differences
are +2,991 ns for decode and +3,997 ns for CPR. All environment limits remain
in the report. A supplementary historical-review assertion initially compared
the prior CSV snapshot with the appended file; its failure and correction to
verify the exact 26-row prefix and two validated additions are retained.
The exact 1.50× target remains unmet. The fresh untimed diagnostic and its
independent review passed: all 13 profiles, 2,542 helper groups, 240 held
inputs, 583 non-review evidence members and 10,414 historical files.
Comm-B remains the largest stage, at 4,577,845,091 of 12,174,075,418 instructions
(37.60%). Candidate BDS60's nested penalty cost is 844,657,445 instructions;
BDS50's is now 151,277,418. These overlap the stage totals and are diagnostic
counts, not timing predictions. [Full report](docs/GEN13-COST-BREAKDOWN.md).
Final diagnostic review SHA-256:
`be25e1c12d1884a1d1c6980825dbfba27112fe17a21de4db19698fd8a9e9abde`.
Two reviewer-only finalizer adaptation errors were corrected and retained;
the producer evidence was unchanged. The diagnostic hold is released.

**Generation 14 in progress:** use exact integer bounds to decide BDS60's
rounded IAS/Mach ratio test when the answer is proved, preserving the original
software binary64 comparison as a lazy fallback near 250 and 800. Keep the
exact rational division, availability checks and positive-Mach guard, and
prove unconditional equality for all rational inputs. BDS50 remains unchanged.
The helper build passed (2,050 jobs), with seven permitted-axiom facts and
six kernel witness theorems, including exact and round-back threshold cases.
Two failed cast-normalization proof attempts are retained; runtime was
unchanged. Whole-decoder integration passed its first build. The full gate
and separate fresh 10M campaign are running with all runtime/proof/generator
sources fixed. Fresh message seed 2,423,156,018 and Comm-B seed 638,885,017
were recorded before generation. Independent source/proof/native review
passed all 31 checks with 143 held inputs and 439 retained files; the linked
integer helper has one conditional software-rounding site and the caller
forms exact IAS/Mach once. BDS50 and nineteen other production native sets
remain unchanged. Review SHA-256:
`070ee05e729f6ac730f8e94d7de86a4bd022797832306c9119478d4f627be329`.
The separate fresh 10M campaign passed on its first execution: 10,476,164
messages = 9,542,410 exact matches + 933,754 documented D001 cases; all
101,244 direct registers match. Coverage includes all 32 DF attempts, 70 ADS-B
branches and 14 registers. Its 2,040,056 standard-view differences are retained
separately. Independent retention replay passed on its first execution,
verifying 110 sources, three binaries, 33 artifacts and fourteen compressed
streams, with all 185 gate and 143 native inputs unchanged. Review SHA-256:
`f9e53974cd432db9b6328b47f5c89d1e5908be5e810b887fa3efad48432cac5a`.
Benchmark preparation passed first execution and independent review, preserving
the exact prior 28 CSV rows and the 3/2 target. The fixed full gate passed
from 04:03:41 to 04:19:45 UTC with all 185 audited inputs unchanged: 23 exact
contracts, 152 witness audits, 1,011 unit assertions and seven differential
components. It checked 10,476,164 messages = 9,542,689 exact + 933,475 D001,
and all 101,244 direct registers exactly. All seven component archives are
retained: 62 files totaling 1,198,313,687 bytes. Final archive review passed
on its first attempt with no findings. It verified all 185 inputs, seven
archives, fresh/native/proof bindings, 648 complete gen13 artifacts,
10,414 older historical files, all 28 prior CSV rows and the exact 3/2 plan.
Review SHA-256:
`28a9f960947768c95719baa795cd31d0c9f6af22cf2f16087fac4d9c773f2ab1`.
The verified change was committed as
`cd749c8192a77a79ba683303f0b743f04ff6bc0c`, under the user's GitHub identity,
and pushed to the authorized private repository.
After all other jobs stopped, both frozen ABAB modes completed from its clean
commit with a fresh worker build. Actual timed worker SHA-256:
`081a1cabff3d4e3fc58fb790e1e423cdeff672d35ee2a4006eefeed17728a9b7`.
Decode: Lean 571.418060 ms / 301,761.550904 msg/s; rs1090 833.800995 ms /
206,802.343765 msg/s; ratio **1.459178582840×**. CPR: Lean 879.566651 ms /
196,041.993866 msg/s; rs1090 820.872588 ms / 210,059.395966 msg/s;
ratio **0.933269340154×**. Decode is lower than gen13's 1.492757184729×;
retain the result unchanged and investigate with a fresh diagnostic rather
than rerunning this generation. All 48 samples per mode, clean/lock checks,
fresh native artifacts and four power-plan captures are retained in
[bench/runs/gen14/](bench/runs/gen14/), with the [full report](bench/GEN14.md).
Two CSV rows preserve all 28 previous rows. Independent result/history review
passed first attempt: 1,983 primary checks, all original samples and
source/native/clean-build bindings, 7,922 committed historical files, fourteen
prior raw perf captures and 10,414 older snapshot files. Review SHA-256:
`da017a3a6b7db537ea80f4a6257b5ca76bca03aeaf2cbd76813cc40799b1bb6c`.
No sample or wrapper UTC backsteps occurred. Recorded outer UTC-minus-monotonic
differences are −275 ns decode and +406,013,507 ns CPR, retained without
correction. CPU 0 bracketing utilization was 1%/1%; physical-host, frequency
and thermal visibility limitations remain documented. The exact 1.50× target
is unmet. A fresh untimed diagnostic is in progress before selecting the
next change; no cause is inferred from this timing regression alone.

The publication records below describe completed prior work.

The first compiled finite-step proof was rejected: its `bv_decide` axiom
printout included native reflection axioms, outside the permitted set. It is
replaced by symbolic bit-vector reasoning. The rejected attempt and
all preceding elaboration failures are retained under
`tests/evidence/optimization/gen11/proof/`; no rejected proof is accepted as
validation. The independent generic `Nat.fold`/range-fold lemma compiles with
only `propext` and `Quot.sound`.

**Attribution correction (2026-10-19 UTC):** the user requested that all pushed
commits be authored by their GitHub account. All 15 original commits now use
`zpconn <zpconn@gmail.com>` for author and committer; file trees, messages and
timestamps are byte-identical. Local Git identity is configured accordingly.
[The mapping and provenance note](docs/COMMIT-ATTRIBUTION.md) preserve the meaning
of the historical commit IDs below. The rewrite was pushed with an exact
remote-tip lease, and GitHub confirmed `zpconn` as both author and committer
for every rewritten commit. No source, test, frozen file or measured artifact changed.

**Privately published (2026-10-19 UTC):**
[zpconn/lean1090](https://github.com/zpconn/lean1090) is **PRIVATE**, with default
branch `main`. Source/presentation commit
`f9a53b642f01c2d1396275955eba5b2a5af597e2` was pushed after verification from a
clean local clone; `git ls-remote` confirmed the exact remote commit. This update
records the final verification evidence. The user's explicit private-push
instruction supersedes the original public-repository requirement and earlier
review pause. No further optimization, frozen-file change or trusted primitive
was introduced.

Done: README with all 23 exact capstone statements, trust/scope limits and raw
benchmark links; an 11-frame generation-history GIF and static plot; developer
and evidence guides; pinned dependency bootstrap; third-party notices; current
status prose cleanup; independent checks of 92 links and 28 presentation claims.
The generation-10 measurements and source commit remain unchanged. Original
history and retained evidence are preserved; build caches and designated large
regenerable transcripts remain ignored.

Final verification in this publication session:

- `scripts/check_all.sh --full` passed with 181 unchanged audited inputs, all
  23 final contracts, 152 axiom-audited witnesses, 1,011 upstream unit assertions
  and all seven differential components. The fixed campaign checked 10,476,164
  messages: 9,542,689 exact plus 933,475 documented D001 cases.
- A separate fresh campaign used message seed **3111244820** and Comm-B seed
  **2426725490**: 10,476,164 messages (9,543,060 exact plus 933,104 D001),
  101,244 exact direct Comm-B comparisons, all 32 DF attempts / 70 ADS-B branches
  / 14 registers, and zero unclassified mismatches. All 106 source and three
  binary hashes stayed unchanged.
- `scripts/check_all.sh --quick` passed from the clean clone of the published
  source commit. Project Lean objects and Rust targets were initially absent;
  only pinned external dependency caches were reused and verified unchanged.
  It checked 576,164 messages (566,792 exact plus 9,372 D001), all 101,244 direct
  Comm-B cases, complete scoped coverage, and all other mandatory strata.
  Every one of the 181 correctness inputs matched before and after, across
  both checkouts. Only generated evidence changed.
- The unchanged 104-entry lock passed. The source push, private visibility and
  default branch were verified through Git and GitHub API commands.

Commands, summaries, hashes, source/copy inventories and publication records:
[tests/evidence/publication/](tests/evidence/publication/).
The clean-clone check reuses compiled external Mathlib dependencies; it is not a
claim of rebuilding the Lean toolchain or all of Mathlib from scratch. Network
dependency preparation is recorded separately. Benchmark results remain the
accepted generation-10 measurements; no new timing run is claimed.

The publication request is complete. The later optimization authorization is
recorded above; frozen-file changes still require separate approval.

## Historical development log (newest first)

**Review checkpoint reached (2026-10-18 local / 2026-10-19 UTC): generation 10 decode is 1.168948811789× rs1090, exceeding the 1.10× target. Optimization is stopped for user review. Do not begin another generation or final-run/deliverable work until the user responds. The verified source commit is d51a3040984beb6f0f96b0f4fcf225ba2622a7e0; post-timing artifacts, results rows and this progress update remain uncommitted for review. No public push occurred.**

**2026-10-18 continuation:** the user accepted generation 0 and independently reproduced its binary SHA-256, samples/medians/ratios, affinity and power-plan captures. The exact accepted baseline artifacts and prior PROGRESS update were committed unchanged as `ff450a1` (`gen0: record accepted whole-decoder baseline`). Optimization generations are authorized. Each timed generation must pass the full gate, be committed, then be freshly built from that clean commit and measured in both modes with the frozen interleaver, actual binary SHA-256, all samples and results rows. Run fresh recorded message/Comm-B seeds at milestones. No corpus caching, trusted primitives or frozen edits are authorized. Continue autonomously until decode reaches at least 1.10×, then stop for review before final-run/deliverable work. The earlier baseline pause below is historical and superseded.

The complete pre-optimization diagnostic is written in `docs/GEN0-COST-BREAKDOWN.md`, with retained evidence under `tests/evidence/diagnostics/gen0/`. All 172,432 corpus messages were profiled through unchanged live `Impl.decode` in three disjoint DF families, with complete output digests checked. All instruction self costs sum exactly, with no outside-root or ambiguous-stage costs. Of 130,942,672,972 collected instructions, frame/CRC accounts for 47.61%, Comm-B inference 38.07%, semantic/oracle construction 12.88%, ADS-B fields 1.40% and final output/control 0.03%. All five scored registers have candidate and score probes, including explicit zero reached score cases for BDS44/45. Per-DF allocation counts, native sampling limitations, overlapping diagnostic jobs, cold constants and allocator context are documented. These are diagnostics, not benchmark results. Sources, original generated C, raw compressed profiles, commands and hashes are retained; accepted baseline artifacts remain unchanged.

**Gen1 complete:** after writing that cost breakdown, specialized only `Impl.Parity.step`'s final 24-bit reduction to a literal modulus with a checked bound. The public function and exact mathematical body remain equal to the frozen reference. Generated C now uses constant `lean_nat_mod` instead of generic `BitVec.ofNat` inside the per-bit step. The first targeted build left a definitional-equality goal open; its failed log is retained. Adding `rfl` to the existing unfrozen component proof closes it. `lake build Proofs.Decoder lean1090 messageGenerator commbDifferential` passed (3,498 jobs). The subsequent `scripts/check_all.sh --full` passed, including all 23 exact capstone types/allowed axioms, 152 witnesses, import/dependency guards, 1,011 unit fixture assertions and all seven differential components. All 169 recorded correctness inputs were unchanged across the full gate and still match its passing execution record.

The fixed-seed campaign passed 10,476,164 whole messages: 9,542,689 exact matches plus 933,475 documented D001 cases. The independently run fresh-seed campaign (messages 3871650367, Comm-B 3100217476) passed 10,476,164 messages: 9,543,079 exact plus 933,085 D001. Each also passed all 101,244 direct-register cases, with coverage of 32 DF attempts, all 70 ADS-B branches and all 14 Comm-B registers, no coverage gaps and no unclassified mismatches. The full CPR and tracking strata also pass under the unchanged tolerance and known D009 classification. Evidence: `tests/evidence/optimization/gen1/`, including command logs, source inventories, seeds, summaries and artifact hashes. The verified code was committed as `1cec196fd30565c70573fb28b7d555c4c4b71d32`. A fresh native build from that clean commit regenerated all 21 linked project objects; the actual timed worker SHA-256 is `9bdebf77cda47bb37d8105a7b2856be1157e007508238183fa393f7d471b9f43`. Both frozen 3+21 ABAB modes completed on CPU 0 with all 48 samples per mode, unchanged queried Windows Ultimate Performance plan and clean-tree/lock/binary checks throughout. Decode: Lean 4,204.929276 ms / 41,007.110627 msg/s, rs1090 880.740247 ms / 195,780.765768 msg/s, ratio **0.209454235539×**. CPR: Lean 4,539.443247 ms / 37,985.274981 msg/s, rs1090 881.841787 ms / 195,536.209037 msg/s, ratio **0.194262101984×**. Lean throughput improved 26.08% / 23.70% over gen0. The independent review verified all 96 rows, exact medians, build provenance and gate inputs against committed blobs. All raw samples/environment/power captures are retained in `bench/runs/gen1/`, summarized in `bench/GEN1.md`, with both rows appended to `bench/results.csv`. Two decode UTC label backsteps and outer UTC-versus-monotonic elapsed differences are retained; worker duration arithmetic uses monotonic clocks. WSL host-observation limits remain explicit. No samples were discarded or repeated. Post-timing evidence is prepared for the next verified commit.

Independent generic binary64 error-bound proof preparation completed only in ignored `.cache/gen2-proof/`; it is not part of the gen1 runtime change. It proves the score sandwich/fallback against the software model for arbitrary rational terms of length at most four; no runtime table or gate is changed. That agent and all other parallel work have finished before benchmark preparation. The requested older-prose polish corrected 28 whitespace occurrences in PROGRESS.md, DISCREPANCIES.md and THEOREMS.md, preserving non-whitespace content, code, hashes and timestamps; docs/FROZEN-CHANGES.md is byte-identical. Before snapshots and validation are retained under the gen1 evidence.

**Gen2 complete:** the complete pre-change diagnostic is now written in `docs/GEN1-COST-BREAKDOWN.md`. Independent review reproduced every self-event sum for all 13 raw profiles, checked 416 archived files and 195 protected inputs, and confirmed unchanged outputs and earlier artifacts. Total: 103,138,318,751 collected instructions. Comm-B inference is largest at 49,856,076,161 (48.34%), then frame/CRC 34,540,771,739 (33.49%), semantic/oracle values 16,865,854,313 (16.35%), ADS-B fields 1.77% and output/control 0.04%. BDS60 is the largest scored-register probe. These are diagnostics, not timing claims. Sources and objects stayed fixed until the full report and independent review were complete; the temporary diagnostic hold is released.

Gen2 targeted the Comm-B score path under the agreed plan: immutable per-field-code tables for every density term in all five scored registers, exact rational center/envelope decisions, and a lazy full-software-model fallback near −3. The software reference and frozen statements remain unchanged. The 13 complete tables cover 20,992 field codes; their equality and four-term bound are proved for all natural register/payload inputs. The generic score error bound and interval/fallback decision are proved, including an exact −3 witness. Integration into live cbScorePasses and the all-input decoder refinement passed the first targeted build (3,507 jobs), with only the permitted axioms. Generated C confirms persistent immutable tables and a lazy full-score callback. The full gate passed with all 173 correctness-input hashes unchanged. The independent 10M fresh-seed campaign passed (messages 184794048, Comm-B 1273035172): 10,476,164 whole messages = 9,542,710 exact + 933,454 documented D001, with no unclassified differences. All 101,244 direct Comm-B cases match; coverage includes 32 DF attempts, all 70 ADS-B branches and all 14 registers. All 98 recorded source hashes, three binary hashes and retained raw artifact hashes passed the post-run verification. The fixed gate passed all 23 exact theorem/axiom checks, 152 witness audits, import/hypothesis checks, 1,011 unit fixture assertions and all seven differential components. Its 10,476,164 whole messages comprise 9,542,689 exact + 933,475 documented D001, with every direct-register case exact and all coverage checks passing. Complete copies of all seven component output trees are retained in distinct generation cache archives, with versioned summaries, hashes and exact full-gate-log binding under tests/evidence/optimization/gen2/. Details: docs/GEN2-SCORE-GATE.md and tests/evidence/optimization/gen2/. No trusted primitives, hardware score arithmetic, corpus keys or cross-message/run caches are authorized. Full validation and independent source/C/tooling reviews are complete. The verified change was committed as f05d8b1bd697269efdb2d73b045fdf50a481f969. The fresh build from that clean commit regenerated 22 linked project C/object sets; the timed binary SHA-256 is 71c52eabb059fb6b80d71ee2b0950f85630a0b0a32ec4a9704f4fbf32701eded. Both frozen 3+21 ABAB modes passed all provenance checks with 48 retained samples each, CPU 0 affinity and four unchanged Ultimate Performance power-plan captures. Decode: Lean 2,948.287582 ms / 58,485.475112 msg/s, rs1090 868.445798 ms / 198,552.402922 msg/s, ratio **0.294559392137×**. CPR: Lean 3,214.679253 ms / 53,638.943866 msg/s, rs1090 869.895151 ms / 198,221.590041 msg/s, ratio **0.270600916153×**. Lean throughput increased 42.62% / 41.21% over gen1. Complete raw samples/environment/build evidence is copied byte-identically into bench/runs/gen2; bench/GEN2.md and two results.csv rows report the result. Independent result review passed all 96 rows, 48 archived files, 173 gate/98 fresh-campaign source blobs, 104 locked blobs and all 22 rebuilt native artifact sets. There are no adjacent UTC sample backsteps, but outer UTC/monotonic elapsed differences and the after-run snapshot clock discrepancy are retained; CPU 0 observations are 0% before and 2% after, with explicit WSL host-observation limits. The threshold remains 1.10×, so autonomous work continues.

**Gen3 complete:** the complete gen2 diagnostic and independent review passed before any new runtime change. All 13 raw profiles, 229 protected inputs, 428 archived files and 22 fresh native artifact sets agree. The report is docs/GEN2-COST-BREAKDOWN.md; review evidence is tests/evidence/diagnostics/gen2/independent-review.json. Of 73,545,228,488 collected instructions, frame/CRC accounts for 46.97%, Comm-B inference 27.76%, semantic/oracle construction 22.73%, ADS-B fields 2.49% and output/control 0.06%. Within CRC, repeated Nat.testBit calls account for 21,957,771,021 inclusive instructions (63.57% of frame/CRC; overlapping costs). All 45,510 corpus score decisions use the gen2 exact interval path, with zero observed fallback entries. These are diagnostics, not benchmark results. The temporary hold is released. Gen3 targets CRC bit extraction: extract two UInt64 words once per call, retaining the original Nat path for bit indices at least 128 and proving equality for every natural input and width. The first helper-proof build passed (2,041 jobs), followed by the integrated decoder/native-target build (3,508 jobs), with only the permitted axioms. Independent source/proof review and all 12 native structural checks pass: generated C extracts both halves before the fold, and linked assembly uses machine bit operations while retaining the arbitrary-precision fallback. The separate fresh-seed 10M campaign passed (message seed 2991522103, Comm-B seed 2632950597): 10,476,164 whole messages = 9,542,847 exact + 933,317 documented D001, all 101,244 direct-register cases exact, all 32 DF attempts/70 ADS-B branches/14 registers covered, and zero unclassified mismatch or coverage gap. All 99 source hashes, three binary hashes and nine retained raw transcript hashes passed final verification. The full gate passed with all 174 correctness inputs unchanged: all 23 exact capstones and axiom checks, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven mandatory differential components. Fixed-seed results: 10,476,164 whole messages = 9,542,689 exact + 933,475 documented D001; all 101,244 direct-register cases match, with no unclassified difference or coverage gap. Numerical presentation passes all 20,936,723 exact comparisons; full CPR retains only the 204 documented D009 cases, and tracking passes all 178,297 messages with 16,460 bit-identical positions. Complete output trees for all seven gate components are archived with source hashes, exact log binding and versioned summaries under tests/evidence/optimization/gen3/. Verification completed before commit 3ba567f1d5039eb16ab033dd436d3d4f0f33c98b, which also includes the prior gen2 measurement and diagnostic evidence. A fresh build from that clean commit regenerated all 22 linked project C/object sets; the timed worker SHA-256 is 6d6b7d9a7d8535e7f6de5ff6f7d4dac643d068322bef6c0a809732603354117d. Both frozen 3+21 ABAB modes completed on CPU 0 with all 48 samples per mode, clean-tree/lock/native-hash checks throughout and four unchanged Ultimate Performance power-plan captures. Decode: Lean 2,060.768796 ms / 83,673.627209 msg/s, rs1090 838.945405 ms / 205,534.232588 msg/s, ratio **0.407103119296×**. CPR: Lean 2,372.694541 ms / 72,673.492951 msg/s, rs1090 838.868481 ms / 205,553.080019 msg/s, ratio **0.353550980332×**. Lean throughput improved 43.07% / 35.49% over gen2. All 48 source evidence files were archived byte-identically into bench/runs/gen3, summarized in bench/GEN3.md and appended as two results.csv rows. There are no adjacent UTC sample-label backsteps, but outer UTC-versus-monotonic elapsed differences are retained; CPU 0 guest observations are 0% before and after, with WSL host-observation limits explicit. Independent result review passed all 96 protocol rows, 48 archived source files, 174 gate and 99 fresh-campaign source blobs, 104 frozen blobs and 22 rebuilt native artifact sets, independently recomputing both medians and ratios. The 1.10× target remains unmet.

**Gen4 complete:** the full pre-change gen3 diagnostic and independent review passed before selecting this change. All 13 profiles, 2,756 grouped helper observations, 435 archive members, 230 protected inputs and 22 fresh native sets agree; 1,484 historical artifacts and all gen3 benchmark files remain unchanged. Total: 52,042,380,076 instructions. Comm-B inference is largest at 20,413,385,286 (39.22%), followed by semantic/oracle construction 32.12%, frame/CRC 25.05%, ADS-B fields 3.52% and output/control 0.08%. Within Comm-B, payloadBits has 3,121,720 calls and 6,396,909,632 inclusive instructions; these overlap its Nat power/division helpers and are not a predicted speedup. Report: docs/GEN3-COST-BREAKDOWN.md; evidence: tests/evidence/diagnostics/gen3/. The diagnostic hold is released. Gen4 targets payload bit extraction with UInt64 shifts/masks for widths below 64 and the original formula for wider widths. Its universal equality preserves every natural word/start/width and proves the runtime array bound without importing Spec or Mathlib. The first helper build passed (five jobs). The first integrated build exposed an older definitional-equality shortcut in the unfrozen Comm-B density-length proof; the failed log is retained. A direct structural proof of the same at-most-four bound fixes it. The second integrated build passed (3,509 jobs), including unchanged decoder refinements and permitted axioms. Three Comm-B array/Fin bounds now use the core-only universal payloadBits_lt theorem; those edits are erased proofs. Native review passed all 16 checks: the live fast branch uses machine shifts/masking; natural powers/division/remainder are confined to widths at least 64. Comm-B C has checked local renaming/copy reordering, while its entire native object is byte-identical to gen3.

The gen4 full gate passed from 20:27:26 to 20:43:58 UTC with all 175 correctness-input hashes unchanged. It checked all 23 exact capstones and allowed axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. The fixed-seed whole-message result is 10,476,164 = 9,542,689 exact + 933,475 documented D001. The separate fresh campaign (messages 388032270, Comm-B 1476569264) passed 10,476,164 = 9,543,125 exact + 933,039 D001. Each matches all 101,244 direct Comm-B cases and covers 32 DF attempts, 70 ADS-B branches and 14 registers with zero unclassified differences or coverage gaps. The fresh verifier checked all 100 source hashes, three binary hashes, nine compressed/decompressed raw streams and both standalone Comm-B snapshots. Complete fixed component archives and exact gate-log bindings are retained under tests/evidence/optimization/gen4/. Independent archive review passed all 62 retained component files (1,198,313,686 bytes), the source/proof/native reviews and unchanged historical results. The change and prior gen3 evidence were committed as 275329a2efd269dc44e549e4b6538d36277aaa3f. The subsequent fresh build from that clean commit regenerated all 22 linked project C/object sets; timed binary SHA-256 is adec5d1a48a77a241c5d5bb526155910e94796a0d5526280870ae7e36beb8f57. Both frozen 3+21 ABAB modes completed on CPU 0, with all 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance power-plan captures. Decode: Lean 1,501.456209 ms / 114,843.176222 msg/s, rs1090 833.153982 ms / 206,962.942896 msg/s, ratio **0.554897290381×**. CPR: Lean 1,814.361133 ms / 95,037.309201 msg/s, rs1090 837.019608 ms / 206,007.121401 msg/s, ratio **0.461330213030×**. Lean throughput improved 37.25% / 30.77% over gen3. All 48 source files are archived byte-identically in bench/runs/gen4, with bench/GEN4.md and both results.csv rows. Outer UTC/monotonic differences remain documented without adjustments; there are no adjacent sample-label backsteps. Independent result review passed 1,855 checks, including all 96 protocol rows, 48 source artifacts, 175 gate/100 fresh-campaign source blobs, 104 locked blobs and 22 fresh native sets, with both medians and ratios independently recomputed. The 1.10× target remains unmet; the complete subsequent gen4 cost diagnostic and independent review now pass. All 13 raw profiles, 2,713 grouped helper rows, 437 archived originals, 231 protected inputs and 2,039 historical files agree. Comm-B remains largest: 14,203,778,811 of 37,162,226,042 instructions (38.22%), then frame/CRC 35.09%, semantic/oracle construction 26.02%, ADS-B 0.56% and output/control 0.12%. The three Mach caller contexts total 53,912 calls and 3,606,158,963 overlapping inclusive instructions. Report: docs/GEN4-COST-BREAKDOWN.md; final independent review: tests/evidence/diagnostics/gen4/independent-review.json. The diagnostic hold is released.

**Gen5 complete:** target the largest Comm-B stage by replacing repeated cbMach64 arithmetic with an immutable 1,024-entry table of exact software-binary64 values keyed solely by the ten-bit Mach field. Preserve the live function, binary64 operation order and equality for every natural word; no frozen statement, trusted primitive or cross-message cache change. The helper proof passed its first build and a second build after a proof-style cleanup; all seven table/equality/kernel-witness facts use only the permitted axioms. The first integrated build passed all 3,510 jobs, including unchanged refinements. The full gate captured 176 correctness inputs; the independent fresh campaign recorded message seed 26660891 and Comm-B seed 2917856783 before generation. Sources are held fixed. Independent source/proof review passed; all 31 native checks pass with 44 captured inputs unchanged. The exact table is initialized eagerly and kept persistent before messages. Clang inlines cbMach64 into its live callers, which load the table directly; subsequent diagnostics must account for that missing standalone native boundary. The fresh campaign passed 10,476,164 whole messages (9,542,656 exact + 933,508 documented D001) and all 101,244 direct cases, with complete branch coverage and no unclassified differences. Final verification checked all 101 source hashes, three binaries, nine compressed/decompressed raw archives and both standalone snapshots. The root completed that verifier after the assisting agent hit capacity; the same existing run and seeds were preserved. The fixed full gate passed from 21:12:39 to 21:29:08 UTC with all 176 correctness inputs unchanged: all 23 exact theorem/axiom checks, 152 witnesses, 1,011 unit assertions and seven differential components. Its 10,476,164 whole messages comprise 9,542,689 exact + 933,475 documented D001; all 101,244 direct-register cases match with complete coverage. Complete component archival and independent review passed: all 62 component files (1,198,313,687 bytes), current inputs and retained source/native/fresh evidence agree; all historical benchmark/diagnostic files and previous results rows remain unchanged. The change and retained gen4 evidence were committed as eeb58261e6be0c2b87385f3064a88aed00d4d19a. A fresh build from that clean commit regenerated all 22 linked project C/object sets; timed binary SHA-256 is 6d1576d363d6fa03fea5a9ac55aaa26a323ee5011c8ad38df99821fa58a7e4ab. Both frozen 3+21 ABAB modes completed on CPU 0 with 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance power captures. Decode: Lean 1,319.581059 ms / 130,671.775579 msg/s, rs1090 811.956425 ms / 212,366.076172 msg/s, ratio **0.615313791799×**. CPR: Lean 1,669.685183 ms / 103,272.162774 msg/s, rs1090 840.111358 ms / 205,248.980814 msg/s, ratio **0.503155544862×**. Lean throughput improved 13.78% / 8.66% over gen4. All 48 source files are copied byte-identically into bench/runs/gen5; bench/GEN5.md and both results rows report them. There are no UTC sample/wrapper backsteps; outer UTC/monotonic differences are retained. CPU 0 guest bracketing activity was 0% / 2.040816%, with WSL host limits explicit. Independent result review passed 1,856 checks, including all 96 samples, 48 archived source files, 176 gate/101 fresh source blobs, 104 locked blobs and 22 fresh native sets, with both medians and ratios independently recomputed. The target remains 1.10×; the subsequent gen5 diagnostic and independent review now pass. All 13 profiles, 2,690 helper groups, 25 CRC caller records, 232 held inputs, 446 archived originals and 2,557 historical artifacts agree. Frame/CRC is largest at 13,038,590,650 of 33,549,250,063 instructions (38.86%), followed by Comm-B 31.57% and semantics 28.82%. Syndrome calls split into 172,432 report, 31,395 DF17 acceptance and 83,591 address-recovery calls. DF11 already shares its report syndrome. All instruction costs are diagnostic, not predicted speedup. Report: docs/GEN5-COST-BREAKDOWN.md; independent review SHA aa2e84fa553ce5739e82dab9f9e341f793a3d8810c9ca8d5ba97509a7a9917b9. The diagnostic hold is released.

**Gen6 complete:** share one frame syndrome within each decode through common pure acceptance/address/report helpers. Preserve public entrypoints as delegates to those live helpers and prove the same all-input semantics. No state persists between messages. The helper build passed 16 jobs on its first attempt; seven unconditional old-body/helper equalities are rfl, and three kernel rejection witnesses also pass. The integrated build passed 3,511 jobs on its first attempt, including unchanged decoder refinements and only permitted axioms. Independent source/helper review passed with no non-CRC changes. The full gate recorded 177 correctness inputs; the separate fresh campaign recorded message seed 3190208009 and Comm-B seed 1865131355 before generation. Runtime/proof inputs remain fixed. Native review passed all 48 checks with 47 captured inputs unchanged: one linked syndrome calculation after parsing, shared through acceptance/report/address/DF11. Public wrappers delegate to live helpers; unchanged Frame/Parity/CommB/Semantics objects match gen5. The independent fresh campaign passed 10,476,164 whole messages (9,543,374 exact + 932,790 documented D001) and all 101,244 direct-register cases, with complete 32-DF/70-branch/14-register coverage and no unclassified differences. All 102 source hashes, three binaries, nine compressed/decompressed raw archives and two standalone snapshots verified. The full gate passed from 22:01:21 to 22:17:59 UTC with all 177 input hashes unchanged: all 23 exact capstones and allowed axiom checks, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed results are 10,476,164 whole messages = 9,542,689 exact + 933,475 documented D001, with all 101,244 direct-register cases exact and complete coverage. All seven output trees have been archived with exact gate-log binding. Independent archive review passed all 62 retained component files (1,198,313,643 bytes), 177 inputs, fresh source/binary/archive hashes and native/proof reviews, with all historical artifacts and 12 previous results rows unchanged. The verified change and retained gen5 results/diagnostic evidence were committed as cd4df90b6821ed8d375cb26e0e5baed6f6e9fecf. A fresh build from that clean commit regenerated all 22 linked project C/object sets; timed binary SHA-256 is 930b6d6f3c5f274c1ea05cd232919281f8a86e316636bedb8a885ecb90defdec. Both frozen 3+21 ABAB modes completed on CPU 0 with 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance captures. Decode: Lean 1,222.612380 ms / 141,035.705855 msg/s, rs1090 828.515491 ms / 208,121.636678 msg/s, ratio **0.677659988197×**. CPR: Lean 1,544.613425 ms / 111,634.404576 msg/s, rs1090 846.187016 ms / 203,775.284588 msg/s, ratio **0.547830934462×**. Lean throughput improved 7.93% / 8.10% over gen5. All 48 source files are copied byte-identically into bench/runs/gen6; bench/GEN6.md and both results rows report them. No UTC sample/wrapper backsteps occurred; outer clock differences remain recorded. CPU 0 guest bracketing observations are 0% / 3.061224%, with WSL host limits explicit. Independent result review records 1,858 passing checks, including all 96 samples, 48 archived source files, 177 gate/102 fresh source blobs, 104 locked blobs and 22 rebuilt native sets, with both medians and ratios independently recomputed. The target remains 1.10×; the complete gen6 diagnostic and independent review now pass. All 13 profiles, 2,742 helper rows, 233 held inputs, 469 primary archive members, 22 fresh native sets and 3,084 historical files agree. Comm-B inference is largest at 10,590,559,330 of 30,168,814,972 instructions (35.10%), followed by semantics 32.05% and frame/CRC 32.01%. The 172,432 observed syndrome/checksum calls and 15,300,600 bit steps match the new accepted-corpus census. Report: docs/GEN6-COST-BREAKDOWN.md; independent review SHA f2e260b492b93377f5cafcf9034f43f03ae79038064c6fe056030611433689d3. Renderer/reviewer bookkeeping corrections are retained; no raw profile or decoder result changed. The diagnostic hold is released.

**Gen7 complete:** target the largest Comm-B stage by deciding the existing score enclosure with exact integer arithmetic at a common denominator. The measured choose path costs 4,070,403,745 overlapping inclusive instructions, with repeated rational sums and GCD normalization. Keep the same center/error-bound decisions and lazy full-software-binary64 fallback, and prove equality for every rational list, penalty and fallback. No hardware Float primitive, frozen change, corpus key or cross-message state is authorized. The universal helper proof passed targeted build attempt 4 (2,041 jobs), after retained elaboration attempts. All 12 printed facts use permitted axioms; seven kernel witnesses include empty, dyadic and product-denominator cases. The runtime and helper sources are stable. Root integrated the equality into the existing score proof. Its first combined build rejected a redundant dsimp tactic after the new rewrite; the failed log is retained. Removing that obsolete step preserved the statement and hypotheses; attempt 2 passed all 3,512 jobs with unchanged decoder refinements. The full gate recorded 178 correctness inputs; the separate fresh 10M campaign used previously recorded message seed 175700860 and Comm-B seed 3045455262. Runtime/proof inputs remain fixed. Independent source/proof and integrated refinement reviews passed with no findings: universal equality has no list-length, dyadic or fallback-result assumption, and all 104 frozen hashes match. Native review passed all 37 checks with 102 captured inputs unchanged: the live 15-function score-choice closure uses raw rational fields and Nat/Int operations, no normalized Rat/GCD/Binary64 operations; one conditional call retains the unchanged full software fallback. All 19 other production source/C/object/trace sets match gen6. The independent fresh campaign passed 10,476,164 whole messages (9,543,151 exact + 933,013 documented D001) and all 101,244 direct-register cases, with complete 32-DF/70-branch/14-register coverage and no unclassified mismatch. All 103 source hashes, three binaries, nine compressed/decompressed raw transcripts, two standalone snapshots and three diagnostic difference streams verified. Exact retention membership covers 33 files. The full gate passed from 22:41:50 to 22:58:34 UTC with all 178 input hashes unchanged, including all 23 exact capstones, permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed results: 10,476,164 whole messages = 9,542,689 exact + 933,475 D001; all 101,244 direct cases exact and complete coverage. Independent archive review passed all 62 component files (1,198,313,687 bytes), 178 current inputs, fresh source/binary/retention hashes and native/proof reviews. All historical artifacts and 14 previous results rows remain unchanged. The verified change and retained gen6 measurement/diagnostic evidence were committed as 7c3b44d246149a1c5aa671d119b6ba2be27d856b. A fresh build from that clean commit regenerated all 22 linked project C/object sets; timed binary SHA-256 is fc90d59af0154a578478ace9353001ca82d9780da0a182495778288224851896. Both frozen 3+21 ABAB modes completed on CPU 0 with 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance captures. Decode: Lean 1,106.538274 ms / 155,830.127210 msg/s, rs1090 820.237133 ms / 210,222.133408 msg/s, ratio **0.741264131818×**. CPR: Lean 1,446.829656 ms / 119,179.199351 msg/s, rs1090 840.862938 ms / 205,065.525197 msg/s, ratio **0.581176183743×**. Lean throughput improved 10.49% / 6.76% over gen6. All 48 source files are copied byte-identically into bench/runs/gen7; bench/GEN7.md and both results rows report them. No UTC sample/wrapper backsteps occurred; outer clock differences remain recorded. CPU 0 guest bracketing observations are 0% / 0%, with WSL host limits explicit. Independent result review passed 1,861 checks, including all 96 samples, 48 archived originals, 178 gate/103 fresh source blobs, 104 locked blobs and 22 fresh native sets, with both medians and ratios independently recomputed. All 14 previous results rows and 3,590 historical committed files remain unchanged. The target remains 1.10×. The complete subsequent gen7 diagnostic and independent review now pass: all 13 raw profiles, 2,654 grouped helper rows, 498 archived originals, 234 held inputs, 3,633 historical files and all 22 fresh native sets agree. Semantic/oracle construction is largest at 9,668,833,265 of 27,331,126,731 instructions (35.38%), followed closely by frame/CRC 35.33% and Comm-B 28.37%. Within semantics, payloadValue has 1,520,847 entries and 8,181,358,354 overlapping inclusive instructions, with repeated Rat multiplication/addition/GCD work. Report: docs/GEN7-COST-BREAKDOWN.md; independent review SHA ae587990a463a7692782d4e7d74824f01f55648ffc25d6fb03bbf2e14781d2fa. Sampling limitations include 23 included unknown leaves and remain explicit. The diagnostic hold is released.

**Gen8 complete:** target the largest semantic stage by bypassing identity rational affine operations in live payloadValue: multiplication by one and addition of zero. Preserve the same unrestricted integer/rational behavior, status checks and extraction, with unconditional equality proofs and concrete kernel witnesses. No frozen file, trusted primitive, table or cross-message state change is authorized. Fresh message seed 4180954545 and Comm-B seed 1380605832 were recorded before fixture generation. The helper proof passed attempt 2 (six jobs) after a retained witness-formatting failure; all ten printed facts use permitted axioms and seven kernel witnesses cover the branches. Independent source/proof review passed. The first integrated build passed all 3,513 jobs after rewriting the decoder equality and five Comm-B density proofs; independent integration review also passed. The full gate captured 179 correctness inputs and the separate fresh campaign has started. Runtime/proof inputs remain fixed. Native review passes all 39 checks with 137 captured inputs unchanged, confirming both live guarded shortcuts and unchanged nonidentity arithmetic; all 19 other production native sets match gen7. The fresh campaign first failed before fixture generation due to a missing output directory. That attempt is archived byte-identically, and attempt 2 uses the same helpers/preflight/seeds after creating the empty directory. The fresh campaign and all retention checks now pass: 10,476,164 whole messages = 9,542,821 exact matches + 933,343 documented D001 cases, with all 101,244 direct Comm-B cases exact. Coverage includes 32 DF attempts, all 70 ADS-B branches and 14 registers, with zero gaps or unclassified mismatches. All 104 source hashes, three binaries, nine raw transcripts, two standalone snapshots and three diagnostic difference streams verified; successful retention has exactly 33 files. The retained setup failure and unchanged-input retry are linked to the final verification. The fixed full gate passed from 23:18:33 to 23:35:19 UTC with all 179 input hashes unchanged: all 23 exact capstones and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 D001, with all 101,244 direct cases exact and complete coverage. All seven component trees are archived with exact gate-log binding: 62 files totaling 1,198,313,686 bytes. Final independent archive review passed all 62 component files, 179 current inputs, fresh source/binary/retention hashes, native/proof reviews and unchanged historical artifacts and 16 previous results rows. The first reviewer attempt assumed a missing top-level monotonic field in the failed setup record; its script/log are retained. The corrected reviewer checks the recorded child-command monotonic completion and parent UTC completion without changing campaign evidence. All validation work is complete and stopped before commit and fresh-build timing. The verified change and retained gen7 measurement/diagnostic evidence were committed as 78286f12feb79f8d8e3cdf2411ebd274161d1c3d. A fresh build from that clean commit regenerated all 22 linked project C/object sets; timed binary SHA-256 is da5ebfa685b052a3b534001fc2a1d4ead02995e40f2ea077e6f8d6328b4dde31. Both frozen 3+21 ABAB modes completed on CPU 0 with 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance captures. Decode: Lean 875.472170 ms / 196,958.859355 msg/s, rs1090 812.307859 ms / 212,274.198864 msg/s, ratio **0.927851149169×**. CPR: Lean 1,166.802820 ms / 147,781.610607 msg/s, rs1090 814.053751 ms / 211,818.936757 msg/s, ratio **0.697678936875×**. Lean throughput improved 26.39% / 24.00% over gen7. All 48 source files are copied byte-identically into bench/runs/gen8; bench/GEN8.md and both results rows report them. No UTC sample/wrapper backsteps occurred; outer UTC-minus-monotonic differences of 528,689.382 / 1,124,874.309 microseconds remain recorded without correction. CPU 0 guest bracketing observations are 0% / 0%, with WSL host limits explicit. Independent result review passed 1,863 checks, including all 96 samples, 48 archived originals, 179 gate/104 fresh source blobs, 104 locked blobs and 22 fresh native sets, with both medians and ratios independently recomputed. All 16 previous results rows and 4,160 historical committed files remain unchanged. The target remains 1.10×. The complete subsequent gen8 diagnostic and final independent review pass: all 13 raw profiles, 2,637 grouped helper rows, 505 primary archive files plus 20 supplements, 235 held inputs, 4,202 historical files and all 22 fresh native sets agree. Total instructions: 20,817,634,394; frame/CRC is largest at 9,656,551,322 (46.39%), followed by Comm-B 36.37% and semantic values 16.03%. The field helper has 881,619 entries and 2,818,893,089 overlapping inclusive instructions. Ten affine caller contexts and 31 direct arithmetic edges were independently recounted. Report: docs/GEN8-COST-BREAKDOWN.md; final independent review SHA 3000bf3449ff42df22bdd0b38fe60b2b60cf3c401dad815a3f87e26659a727db. Reviewer corrections for additional orchestration logs and a reused count variable are retained, including the preliminary incorrect count; final exact membership is independently checked at 525 non-review files. No producer/profile/decoder result changed. The diagnostic hold is released.

**Gen9 complete:** target field extraction within the largest frame/CRC stage. For widths below 64, shift the arbitrary natural word first, then extract with a machine-word mask and construct the bit vector using a proved bound. Keep the original formula for widths at least 64 and prove equality for every natural total/start/width/word, including zero widths, truncated subtraction and over-wide inputs. No frozen change, trusted primitive, table or cross-message state is authorized. Fresh message seed 4063364224 and Comm-B seed 3086385107 were recorded before generation; the output directory is prepared. The first helper build passed eight jobs; both unconditional equalities and eight kernel witnesses use only permitted axioms. Independent source/proof review passed, with a retained reviewer-only local-variable spelling correction. The first integrated build passed all 3,514 jobs and preserved every decoder refinement statement. The full gate captured 180 correctness inputs and the separate fresh campaign has started; runtime/proof inputs remain fixed. Native review passes all 38 checks with 138 captured inputs unchanged: the actual field function shifts the arbitrary Nat before machine masking; only the wide branch uses natural powers/division/generic bit-vector reduction. The linked decodeFrame retains 26 static calls to the live field function, and all 19 other production source/C/object/trace sets match gen8. The fresh campaign passed on its first execution: 10,476,164 whole messages = 9,543,360 exact matches + 932,804 documented D001 cases, with all 101,244 direct Comm-B cases exact. Coverage includes 32 DF attempts, all 70 ADS-B branches and 14 registers, with zero gaps or unclassified mismatches. All 105 sources, three binaries, nine raw transcripts, two standalone snapshots and three diagnostic streams verified; successful retention has exactly 33 files. Standard-view differences are retained separately. The full fixed-seed gate passed from 23:56:39 UTC on October 18 to 00:13:03 UTC on October 19 with all 180 correctness inputs unchanged: all 23 exact capstones and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed-seed whole messages: 10,476,164 = 9,542,689 exact + 933,475 D001; all 101,244 direct cases match, with complete 32/70/14 coverage. All seven component trees are archived with the exact gate-log binding: 62 files totaling 1,198,313,685 bytes. Final independent gate/archive review passed on its first attempt: all 180 correctness inputs, 62 component files, fresh sources/binaries/retention, native/proof review bindings, 588 complete gen8 artifacts, 4,152 older committed files and 18 prior results rows are unchanged. The reviewer also independently decompressed and counted all three extra fresh difference streams. Review SHA-256: 696075242d95b69b4e86ea8c984ca78e11203838675779cb0cdc84e740f2c54b. Validation work is stopped before commit and fresh-build timing. The separate independent fresh review passed all 105 source hashes, three binaries and exact 33-file membership, while confirming all 588 gen8 diagnostic/benchmark files and the 18 prior results rows remain unchanged. The unfrozen post-timing archive helper also passed independent review after tightening provenance completeness: real gen8 inspection, 63 rejection controls and exact below/at/above-1.10 threshold cases. Its initial source and review findings are retained; no benchmark method or correctness input changed. The verified change was committed as 0fb54f0661c4cd589816277b1a8996a9969bdc44. A fresh build from that clean commit regenerated all 22 linked native sets; timed worker SHA-256 is 48dff3c83eebe85eaf857b3ce0c04e3b03e29a57cdb518f5c3d451532e16eccd. Both frozen 3+21 ABAB modes completed on CPU 0 with 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance captures. Decode: Lean 802.152680 ms / 214,961.570658 msg/s, rs1090 813.132488 ms / 212,058.923416 msg/s, ratio **1.013687927839×**. CPR: Lean 1,078.536448 ms / 159,875.913623 msg/s, rs1090 815.655161 ms / 211,403.063751 msg/s, ratio **0.756261100413×**. Lean throughput improved 9.14% / 8.18% over gen8. All 48 source evidence files are copied byte-identically into bench/runs/gen9, with both results rows appended preserving all 18 previous rows. The automated archive report passed on its first execution. No sample-label or wrapper UTC backsteps occurred; outer UTC-minus-monotonic differences of 1,097,008.129 / 474,712.643 microseconds are retained without correction. CPU 0 guest bracketing observations are 0.990099% / 0%, with WSL host limits explicit. All project work was stopped during timing. Independent result review passed on its first attempt with 1,886 checks: all 96 samples, 48 archived originals plus two automated verification files, 180 gate/105 fresh/104 frozen committed inputs and all 22 fresh native sets. Both medians and ratios were independently recomputed; all 18 previous results rows and 4,750 historical committed files remain unchanged. Review SHA-256: afec245e169e80f2014e9232d30d7ae7345e8a8437bb31d4f1b45a71874123bc. The complete gen9 diagnostic and final independent review now pass: 13 profiles, 2,607 grouped helper rows, 10 field contexts and 23 direct edges, 520 primary archive members plus 20 supplements, 236 held inputs and 4,792 historical files. Total instructions: 18,563,052,929; Comm-B inference is largest at 7,570,594,302 (40.78%), followed by frame/CRC at 39.87%. The QNH software binary64 conversion accounts for 31,026 native entries and 2,078,532,469 overlapping inclusive instructions. Report: docs/GEN9-COST-BREAKDOWN.md; final review SHA 29ab144539673e63e9e322e6131049ee4b52dbb9162253a781d70ba04ae80440. The diagnostic hold is released; these are diagnostic costs, not predicted timing gains.

FC001–FC006 are approved and applied, committed as `dee72954b7ad8e4c525b2ffb391477f8f5439809`. The current 104-entry `spec.lock` is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`. FC006 exactly matches the approved patch; no other frozen change is authorized. The full gate and separate fresh-seed 10M campaign pass. The whole-decoder baseline is complete on that clean commit after a fresh native build: decode 32524.102146 Lean versus 195553.483366 rs1090 msg/s, ratio 0.166318193807×; CPR 30708.114463 versus 196619.026196, ratio 0.156180788080×. Both use the frozen 3+21 ABAB protocol on CPU 0, with all 48 samples per mode retained and unchanged queried Windows Ultimate Performance power plan. Actual timed binary SHA-256: `6e09e99f75a523370970ef5311bc296d52c4c4dbb3cb0ffcce35d87f5f7dc415`. Clean-tree and passing lock checks bracket timing. See `bench/BASELINE.md`, `bench/results.csv` and `bench/runs/baseline-FC006/` for medians, raw samples, build/commit/environment provenance and limitations. The post-timing result artifacts are saved for review after the verified code commit. **Stopped for user review; do not begin optimization gen1 until the user continues.**

All 23 capstones now have proofs in `Proofs/`. The seven resumed capstones compiled in targeted builds, with only `propext`, `Classical.choice` and `Quot.sound`: frame/message round-trips, both ADS-B round-trips, both Comm-B round-trips and CPR latitude-zone classification. The root proof module imports them all. The frozen final manifest passes all 23 exact types and permitted-axiom checks, and the independent hypothesis/assignment and 152-witness audits pass. `scripts/check_all.sh --full` passed with exit 0; its first invocation caught an import placed after a module docstring, which was corrected in the unfrozen `Proofs.lean`. The failed log is retained separately, and the subsequent complete passing log is `tests/evidence/capstones-complete/gate-full.log`. All seven mandatory differential components exited 0.

The milestone uses 10M fixed-seed generated messages plus a separate direct 10M message campaign with freshly recorded message seed 3836954135 and Comm-B seed 2158857898. Logs and the pre-run seed record are under `tests/evidence/capstones-complete/`. The fresh-seed campaign passed 10,476,164 whole messages (9,542,618 exact matches plus 933,546 D001 exceptions) and 101,244 direct-register cases, all exact, with no coverage gaps or unclassified mismatches. The fixed-seed full gate also passed: 10,476,164 whole messages (9,542,689 exact matches plus 933,475 D001 exceptions), 101,244 exact direct-register cases, and no coverage gaps or unclassified mismatches. Each campaign covers 32 DF attempts, 70 ADS-B branches and 14 registers. The full CPR stratum has 535,748 calls: 535,544 bit-identical and 204 documented D009 differences. Tracking passes all 178,297 messages across 446 streams, including 16,460 bit-identical resolved positions, 31 boundary/state witnesses and 45 distinct real outcomes. The benchmark-worker FC006 was subsequently approved and applied exactly, with post-application validation recorded below. The whole-decoder baseline is now recorded above; no optimization generation or push has occurred. First push remains subject to approval.

**Gen10 target reached:** target the largest Comm-B stage by tabulating the exact two-round QNH conversion for every one of its 4,096 possible 12-bit field codes. The immutable table preserves the rounded 0.1 literal, multiplication and addition of 800 in the original order; the all-input theorem must include over-wide natural payloads. No corpus keys, cross-message state, hardware Float primitive or frozen change is authorized. The first helper build passed 21 jobs; all nine printed facts use only permitted axioms. The first integrated build passed all 3,515 jobs after updating the decoder equality and BDS40 density proof; all four source hashes stayed fixed. The full gate has captured 181 correctness inputs. Fresh message seed 904147927 and Comm-B seed 2597638268 were recorded before generation, with an empty prepared output directory. Root verified the helper, seed, build and source hashes before releasing the separate fresh campaign. Runtime/proof inputs stayed fixed throughout validation. Independent source/proof review passed. Integration review verified all four sources, the 3,515-job build and 100 printed facts. Its initial warning assertion was too strict; the failed reviewer script/log are retained, and the corrected check permits exactly five existing module-system import advisories from unchanged files. No implementation or build failure occurred. Static native review passed all 44 checks with 139 captured inputs: the complete 4,096-entry table is built during module initialization and marked persistent. Actual cbValid40 and cbDensityTerms inline the same field-code lookup; standalone cbQNH64 is absent from the linked CLI because its work is inlined. The original literal/multiply/add order remains in table construction, and the lazy full-model score fallback and exact integer gate remain live. All 19 other production source/C/object/trace sets match gen9, and all 104 frozen hashes match. The separate fresh campaign passed on its first execution: 10,476,164 messages = 9,542,536 exact matches + 933,628 documented D001 cases; all 101,244 direct Comm-B cases match. Coverage includes 32 DF attempts, all 70 ADS-B branches and all 14 registers, with zero gaps or unclassified differences. All 106 sources, three binaries, nine raw transcripts, two standalone snapshots and three diagnostic streams verified; exact successful retention has 33 files. The 2,037,711 standard-view differences are retained separately. The fixed-seed full gate passed from 00:28:47 to 00:45:26 UTC with all 181 correctness inputs unchanged: all 23 exact capstones and permitted axioms, 152 witnesses, module/dependency guards, 1,011 unit assertions and all seven differential components. Fixed whole messages: 10,476,164 = 9,542,689 exact + 933,475 D001; all 101,244 direct cases match with complete coverage. All seven component trees are archived with the passing log binding: 62 files totaling 1,198,313,684 bytes. The independent fresh review also passes. The final independent gate/archive review passed on its first attempt: all 181 correctness inputs, seven component archives, fresh 106 sources/three binaries/33 files, all extra difference streams, 139 native inputs/191 retained files and all proof/native review bindings match. All 601 gen9 artifacts, 4,741 older committed files and 20 prior results rows are unchanged. Review SHA-256: 346a6e748fa37cbc7d9e9df9883f020cfa880fa85cbe0c6227017cdd4c7f970e. Validation and review jobs are stopped before commit and fresh-build timing. The verified change was committed as d51a3040984beb6f0f96b0f4fcf225ba2622a7e0. A fresh build from that clean commit regenerated all 22 linked native sets; timed worker SHA-256 is e2b7efcfa6aa3a3f2e234aa97d95fabc59a4a8c15562b098f20f1f0ab4f95586. Both frozen 3+21 ABAB modes completed on CPU 0 with 48 samples each, six clean-tree/lock checks and four unchanged Ultimate Performance captures. Decode: Lean 698.769176 ms / 246,765.320971 msg/s, rs1090 816.825398 ms / 211,100.194022 msg/s, ratio **1.168948811789×**. CPR: Lean 1,027.401995 ms / 167,833.039880 msg/s, rs1090 812.456083 ms / 212,235.471686 msg/s, ratio **0.790786943138×**. Lean throughput improved 14.80% / 4.98% over gen9. All 48 source files were archived byte-identically, and two results rows appended preserving all 20 prior rows. No sample-label or wrapper UTC backsteps occurred; outer UTC-minus-monotonic differences of 1,448,636.570 / 857,852.639 microseconds remain recorded without correction. CPU 0 bracketing observations were 0% / 0%, with WSL host limits explicit. Independent result review passed 1,969 checks: all 96 samples, 48 byte-identical original files, exact 51-member final archive, 181 gate/106 fresh/104 frozen committed inputs and all 22 fresh native sets. Both medians/ratios and the exact integer 1.10 threshold comparison were independently recomputed. All 5,353 historical artifacts, ten raw perf files and 20 previous results rows remain unchanged. The first reviewer wrongly required ignored compressed transcripts to be Git blobs; its failed script/log remain retained, and the corrected check verifies the committed manifest plus actual raw hashes/sizes. No producer artifact, report or sample changed. Final review SHA-256: 9a9d3773811e5b1fb8688a46cb8398f4c5c80a2ce48d55abd449b0a455a54137. All review jobs are stopped. The decode threshold is reached: stop for user review, with no generation 11, further diagnostic, final-run or publication work.

## FC005 validation and capstone completion history

FC005 was applied exactly after input verification and the dated history entry. The 102-entry lock is e349a52673522259491c3420dde71980cddfc908fdbe05e81013fefa51fbd3db, matching the approved patch d6ae99c26491ccd24fffe1ca9e5e547ec934a8c47378ee58cfa6e58bf6823c2f; 83 existing entries are unchanged. Before/after snapshots and executed logs are under tests/evidence/frozen-changes/FC005/. The unit source tree contains exactly the seven locked scripts, including after execution. No other frozen file changed.

Post-application lock/import guards pass. scripts/run_unit_tests.sh passes 1011 fixture assertions, the 172432-row corpus assertion, fresh oracle 67 frames/three registers and all rejection checks. The live scripts/run_differential.sh complete diagnostic exits 0 for all seven components: tracking 178297 messages/446 streams/16460 bit-identical resolved positions/zero mismatches; message 576164 cases 566792 exact+9372 D001 and 101244 direct registers exact; existing altitude/reserved/DTE/numeric/CPR components pass with only documented 204 D009 CPR cases. Coverage includes 32 DF attempts, 70 ADS-B branches and 14 registers. Fresh recorded seeds 1492453118 (message)/3638208348 (Comm-B) pass 576164 cases 566814 exact+9350 D001 and 101244 direct registers exact. Both are 100k diagnostics, not final 10M. All results and source hashes are retained in the FC005 evidence directory.

The seven resumed capstones have now compiled in their targeted builds. Parallel agents completed frame/payload inverses and the CPR real-analysis certificates/classification; the root proved independent assignment/report equivalence and the complete-message round-trip. No frozen statement or implementation changed. The integrated final manifest and full milestone gate pass as recorded above. The approved and validated FC006 is now committed, and the baseline is complete. Work is stopped for user review before any optimization generation.

## FC006 approved, applied and validated; baseline completed above

The exact approved patch is `docs/FC006-BENCHMARK-WORKER.diff`, SHA-256 `3e26e7db148c7dc54a649af7cde877d2fc4a01dbed9866d8b5aef4cfeccfb03f`. It produced the 104-entry lock `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`: three changed existing entries, two newly locked sources, 99 existing entries unchanged. All inputs were verified, the dated FC006 history preceded lock replacement, and before/approved/after snapshots are retained. Independent post-application review confirms the exact patch and chronology. No other frozen file changed.

`scripts/check_all.sh --full` exits 0. The lock/import guards pass for 104 hashes, 20 runtime modules, 30 semantic modules and 10 frozen adapters. All 23 final capstones, independent hypotheses/assigned and 152 witness axiom checks pass. Units pass 1011 fixture assertions plus the 172432-row corpus assertion. All seven differential components pass: altitude, reserved velocity, DTE, numeric presentation, full individual CPR, stream tracking and whole messages. Full CPR reports 535748 calls, 535544 bit-identical and 204 classified D009 differences; tracking reports 178297 messages and zero mismatches, with all 16460 resolved positions bit-identical, 31 witnesses and 45 cataloged real outcomes covered.

The fixed-seed 10M campaign passes 10476164 whole messages (9542689 exact plus 933475 D001) and 101244 exact direct registers. The separate direct fresh-seed 10M campaign uses message seed 1425820264 and Comm-B seed 1176298437, sampled and recorded before generation; it passes 10476164 whole messages (9542986 exact plus 933178 D001) and 101244 exact direct registers. Both cover 32 DF attempts, 70 ADS-B branches and 14 registers, with no coverage gaps or unclassified mismatches. Complete logs, seeds, summaries and source/artifact hashes are in `tests/evidence/frozen-changes/FC006/`; large compressed transcripts are retained on disk.

The live `python3 bench/check_worker.py --output tests/evidence/frozen-changes/FC006/worker-validation` exits 0. All 172432 prepared bytes/timestamps, 6903 airports, 172432 tracking outcomes and 29 final aircraft states match. All 11347 resolved positions are bit-identical; the pass rule remains 1e-9 degrees. Protocol/reset/error and comparator controls pass. These are validation smoke timings, not a baseline. The worker and validator match the approved hashes. The actual benchmark subsequently ran after the verified commit and fresh build with all other project work stopped, as recorded above.

The separately requested whitespace repair is complete in PROGRESS.md, DISCREPANCIES.md, THEOREMS.md and older FROZEN-CHANGES.md prose. The history audit preserves every prior hash, timestamp and non-whitespace byte. The whole-decoder baseline has now completed as recorded above. No optimization generation is claimed; work is stopped for review before gen1. First push still needs approval.

## FC005 proposal evidence (subsequently approved and applied above)

FC004 was applied exactly on 2026-10-17 after all input checks and the history entry: patch `eee626abcc93e917fe7d82e6f6f64f67ea54e62f227fd83e7c8515a74e52291f`, 86-entry live lock `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`. Its before/after snapshots are retained under tests/evidence/frozen-changes/FC004/. The live lock still matches that snapshot. No FC005 change is applied.

The user reproduced the original FC005 suites but requested revisions before freezing. The superseded proposal, sources and results are archived in tests/evidence/frozen-changes/FC005-review-v1/. All requested revisions are now implemented in the unfrozen test sources and proposed guard copy:

- Both surface parities bracket the actual decoded 1 km threshold within one latitude code, with and without shared references. Backward-time moving cases bracket 1200 km/h using absolute duration, and signed local-age cases around −180 seconds retain nonzero motion. Positive 180 second moving boundaries remain covered.
- The surface/airborne lifecycle tests airport clear, altitude reset, lookup only without an airport, and preservation of an existing airport when the nearest airport changes. Six independent prefixes compare the actual Lean intermediate public states before later rows could mask them.
- Every routed Rust shadow result is asserted against the actual output, including airborne motion rejection and unresolved surface results; public state/reference updates are also asserted. Three disposable wrong-shadow mutations are rejected. The checker requires integrity flags, prediction consistency, known/unique labels and 31 concrete boundary/terminal-state witnesses.
- docs/CPR-TRACKING-DIFFERENTIAL.md maps all 80 known labels to source lines and roles. There are 45 distinct cataloged real decision/result outcomes, all covered; 75 mandatory diagnostic labels and 79 observed labels. Surface age/order labels are negative controls, not claimed rs1090 rules. These are finite observed outcomes, not an exhaustive Rust branch count. The Lean pass rule remains 1e-9 degrees, with bit identity reported separately.
- Recursive membership covers every file/symlink beneath review/upstream-units without suffix/depth/cache exclusions. Generated JSON/JSONL moved to tests/evidence/upstream-unit-tests/generated/ and all seven reproduce byte-identically. Bytecode writes are disabled. Nested package/native/bytecode/data additions and a package-directory symlink are rejected by candidate guards.

**Executed revised tracking:** 178297 messages across 446 streams, zero mismatches. Corpus 172432 rows/11347 resolved; synthetic 5865 rows/5113 resolved. All 16460 resolved positions are bit-identical by observation; 161837 unresolved results agree; maximum error 0. Final states/references and 31 targeted witnesses pass. Source hashes match current sources. Nineteen comparator injection cases pass, including acceptance of a non-bit-identical 5e-10 degree difference and rejection of 2e-9 degrees, wrong labels/predictions, missing prefixes and wrong intermediate state. Evidence: tests/evidence/tracking-diagnostic/, tests/evidence/tracking-revision-probes/, tests/evidence/frozen-changes/FC005-proposal/tracking-comparator-review.json.

**Executed unit suite:** scripts/run_unit_tests.sh passes 1011/1011 fixture assertions and the 172432-row corpus assertion. The source audit accounts for 153 functions/603 sites, 139 nonempty ports, one empty function, one corpus test and 12 scope exclusions. Fresh pinned oracle comparisons match 67 frames plus 3 direct registers; seven wrong assertions and four malformed fixtures are rejected. The corpus port executes 50385 tracking reports and observes 12659 positions, without inventing a position-count expectation. The single clean rerun passes; an accidental concurrent-invocation evidence compression race is separately retained in tests/evidence/unit-membership-v2/concurrent-invocation-failure/. No test failure was hidden or expectation weakened. Documentation: docs/UPSTREAM-UNIT-PORT.md.

**Executed complete revised campaign:** tests/evidence/fc005-revision/run_candidate_campaign.py ran the exact proposed runner body via bash −c, using the live runner path as $0 only for unchanged directory resolution. No components were mocked or substituted; live frozen files stayed untouched. All seven component exits are 0: altitude 12288 codes plus regression, reserved 16480 cases, DTE 65536 codes through two fresh paths, numeric 20936723 exact comparisons, individual CPR 44228 calls (44024 bit-identical/204 classified D009), tracking 178297 messages, and whole-message 576164 cases (566792 exact/9372 D001). All 101244 direct Comm-B cases match. Coverage: 32 DFs attempted, 70 ADS-B branches, 14 registers. There are zero unclassified mismatches and no new frozen-model omission. Complete logs/command hashes: tests/evidence/fc005-revision/ and tests/evidence/differential-campaign/; complete message observations: tests/evidence/message-differential/.

**Fresh seeds:** sampled and recorded before generation at tests/evidence/fresh-seed-FC005-revision/seeds.json: message 488673482, Comm-B 1870155843. The direct fresh-seed run passes 576164 messages (566820 exact/9344 D001), all 101244 direct Comm-B cases, and every coverage check. Both fixed/fresh campaigns use 100000 generated messages and 100000 random Comm-B assignments plus 1244 targeted. Standard/oracle presentation differences 77269 fixed/77180 fresh are recorded separately, not compatibility exceptions. No final 10M run is claimed.

**Revised FC005 approval artifact:** docs/FC005-TRACKING-UNIT-FREEZE.diff SHA-256 `d6ae99c26491ccd24fffe1ca9e5e547ec934a8c47378ee58cfa6e58bf6823c2f`; proposed 102-entry lock SHA-256 `e349a52673522259491c3420dde71980cddfc908fdbe05e81013fefa51fbd3db`; 16-file manifest SHA-256 `dad99f1478350f9b4a8df363bdd1c04690e76efec31aec270ce16c7f8ca2f6a7`. It adds 16 sources, changes exactly three existing guard/runner entries and preserves 83 entries. Tracking becomes mandatory in complete quick/full runs; the unchanged full gate already requires the unit runner. Exact-patch disposable checks verify 102 hashes and reject 102 mutations, 16 deletions and 17 membership additions; separate unit tests cover directory symlinks. Import audit passes 20 runtime/30 semantic/nine adapter modules and six rejection self-tests. Five orchestration tests verify integration/failure propagation. Independent source and document reviews found no remaining blocking issue. All proposal sources/evidence are retained under tests/evidence/frozen-changes/FC005-proposal/.

**Next: wait for explicit approval of this revised FC005.** Then reverify every input, log date/files/old-new hashes/reason/evidence/approval in docs/FROZEN-CHANGES.md before touching spec.lock, preserve snapshots, apply exactly the approved patch and rerun guards/integrated suites. Only then resume the seven capstones. No optimization generation, benchmark target change, commit or push occurred. The full proof gate is still incomplete; differential success does not override seven missing final proofs.

Standing adapter/fresh-seed/benchmark-worker rules remain in AGENTS.md and docs/OPTIMIZATION.md. Every frozen adapter must continue calling live implementation paths. The benchmark worker needs its own approved FC after the proofs, followed by a whole-decoder ABAB baseline with all samples before gen1.

## FC003 complete; differential campaign passes

The exact approved `docs/DTE-BYTE-ORDER-PROPOSAL.diff` (SHA-256 `1de67cd6b73644ebd60a9e24f3e8f3e6618dd58ef364a69ef8accea29ef6968a`) changes only Spec/CommB.lean, from `dabb5ec8bd0427291c211b773a88706141e0cb469705874bcd63ab6fd65a7835` to `d2af3fa179d6dd05823b5abb00f8e592ccc1858232dd61d96f881fe2735a7b45`. The dated FC003 history entry preceded the single-entry lock refresh. All 61 hashes match; the other 60 entries are unchanged. Before/after snapshots and executed logs are retained in tests/evidence/frozen-changes/FC003/.

Impl/CommB.lean mirrors the compatibility semantic value, and Impl/JSON.lean reads dte from it. Proofs/Decoder.lean exposes DTEOracleRefinement alongside the all-input decoder refinement; the existing Comm-B arithmetic bound was extended for the two-byte DTE expression. `lake build Proofs lean1090` and all unchanged hypothesis, receiver, assignment and import audits pass. The review-definition export was regenerated and checked. D012 is applied and SCOPE.md's Comm-B10 row documents MSB-first standard data and x86_64 oracle byte order.

The permanent `Tests/DTEDifferential.lean` and `scripts/check_dte_differential.py` exhaust all 65,536 unique DTE codes with explicit cardinality/basis checks. Both fresh pinned Message::from_bytes and direct BDS10 oracle paths match: 131,072 comparisons, zero mismatches. Complete quick/full invocations of scripts/run_differential.sh require this regression; the successful complete campaign includes it. Evidence: tests/evidence/dte-exhaustive/.

`scripts/scan_deku_endian.py` reproduced the requested source scan across 30 Rust files. Of 25 wide deku attributes, six omit endian: the two observable ModeS fields (reserved velocity and DTE), two serde-skipped and unchecked BDS30 unused fields, a discarded IcaoParity read, and an additional out-of-scope CAT48 field. All 21 wide ModeS primitive reads specify Big; five other primitive reads belong to FLARM and specify Little. The two observable ModeS omissions are covered by FC002/FC003 and permanent regressions. D012 documents this specific bug-class closure at the pinned commit, including the CAT48 scope qualification; source inventories and hashes are retained in tests/evidence/deku-endian-scan/.

After fresh generation/validation of 101,244 Comm-B cases, this complete command exited 0 with all six components passing:

```sh
scripts/run_differential.sh --diagnostic --corpus --generated 100000 --commb-boundaries .cache/gate/commb.csv
```

- Whole messages: 576,164 =172,432 corpus +100,000 encoded/corrupted generated +303,732 structured Comm-B contexts. 566,792 match exactly; 9,372 satisfy the narrow D001 checks. Zero unclassified mismatches.
- Direct named-register checks: 101,244, all exact. Coverage includes every scoped DF, accepted examples for all 70 ADS-B branches and all 14 direct registers. All 32 DF values have their attempted counts reported.
- Exhaustive altitude: 12,288 codes plus the candidate regression pass. Reserved TC19: 16,480 cases pass. DTE: 65,536 codes through both oracle paths pass. Numeric presentation: 20,936,723 exact-bit comparisons pass.
- Synthetic CPR: 44,228 calls, 44,024 bit-identical and 204 narrowly checked D009 cases; zero unclassified differences or admissibility contract failures. The 22 rational/binary64 half-cell ties remain separately documented outside admissibility.
- Standard/oracle-view presentation differences (77,269 whole messages) are retained separately and are not compatibility exceptions.

Current evidence: tests/evidence/differential-campaign/{run.log,components.tsv,commb-generator.log}, tests/evidence/message-differential/, and the complete branch tables in docs/MESSAGE-DIFFERENTIAL.md. All inputs, outputs and mismatch records are retained. The failed campaign is preserved in directories ending before-FC003, as described below.

`scripts/check_all.sh --quick` was rerun: lock/source/build/import checks pass, then the unchanged exact manifest fails on the seven outstanding capstones (tests/evidence/frozen-changes/FC003/check-all.log). No new capstone work followed this run. No 10M campaign, completed unit-vector port, whole-message benchmark or performance gain is claimed.

## FC004 proposal history (subsequently approved and applied)

The exact combined proposal is **docs/FC004-DIFFERENTIAL-FREEZE.diff**, SHA-256 **`eee626abcc93e917fe7d82e6f6f64f67ea54e62f227fd83e7c8515a74e52291f`**. It was approved and applied in the current continuation above. docs/FC004-DIFFERENTIAL-FREEZE.md explains every change and lists all new hashes. The proposal adds 25 suite/dependency files and changes two existing guards, preserving 59 existing entries, for 86 locked files. It includes every requested checker, differential Lean adapter and generator, plus numeric/Rust oracle dependencies and Lean build/toolchain pins. Freezing lakefile.toml would require approval for later target/configuration changes.

The guard changes are confined to frozen membership and named test-adapter imports: six specific differential adapters may import Impl; they may not transitively import Proofs. Existing runtime, Spec/Model/capstone and theorem-manifest restrictions remain intact. Candidate guards pass the compiled import audit and six rejection self-tests. Disposable-copy lock tests reject all 86 file mutations, all 25 new-file deletions, eight membership additions and duplicate entries. The exact combined patch was applied successfully in a disposable copy; its 86 hashes and the unchanged lock self-test pass. These were pre-approval checks; live guards and the lock now match the approved 86-file proposal.

The prior FC003 lock SHA-256 is `3922793a768183a46503e5024633ea5b1a8fbc00d64c0afabcdc9eabc1dace75`; the proposed 86-file lock SHA-256 is `4be296e60bcdd1125166ce265d6e8b407704894c9999d3b68c1d8191534fc72a`. Proposal snapshots, mutation tests, import output and exact-patch evidence are under tests/evidence/frozen-changes/FC004-proposal/. The current continuation records the explicit approval and exact application, including the required before-lock history entry and snapshots.

## Prior diagnostic campaign and approved FC003 correction

Executed `scripts/run_differential.sh --diagnostic --corpus --generated 100000 --commb-boundaries .cache/gate/commb.csv` after freshly regenerating and validating 101,244 structured Comm-B fixtures. Every component ran; the script exited 1 after collecting all findings. Archived evidence: tests/evidence/differential-campaign-before-FC003/run.log and components.tsv, plus tests/evidence/message-differential-before-FC003/ with complete compressed inputs, outputs, mismatch records and source hashes.

- Whole messages: 576,164 =172,432 corpus +100,000 encoded/corrupted generated +303,732 structured Comm-B messages in three contexts. 549,557 exact oracle-view matches; 9,372 narrowly checked D001 Comm-D differences; 17,235 unclassified mismatches, **all and only BDS10 dte**. Corpus and generated inputs have no unclassified mismatches; every structured context has 5,745 DTE-only failures.
- Direct named-register comparisons: 101,244; 95,504 exact, 5,740 DTE-only mismatches. This separately exercises BDS65's direct reader even though the pinned whole-message inference policy rejects it.
- Coverage checks pass: every scoped DF, accepted examples for all 70 ADS-B branches and all 14 direct Comm-B registers. The archived `tests/evidence/message-differential-before-FC003/MESSAGE-DIFFERENTIAL.md` lists per-branch counts for all 32 DF values (including unsupported corrupted values), all 70 ADS-B selectors and all 14 registers. Every mismatch is retained, not only the first example.
- Other mandatory strata passed in this same invocation: 12,288 altitude codes plus the Comm-B regression; 16,480 reserved TC19 cases; 20,936,723 exact numeric checks; 44,228 synthetic CPR calls with 204 narrowly classified D009 differences and no unclassified mismatch or contract failure. The 22 exact-rational/binary64 half-cell ties remain separately classified outside admissibility.

The batch contains **one new frozen omission**: frame `a0000000100000000000011e478d` has standard/raw DTE 1 and oracle 256. The pre-FC003 compatibility model also said 1. Pinned rs1090's u16 DTE field lacks an endian attribute, producing byte-swapped output on x86_64. D012 and `docs/DTE-BYTE-ORDER-REVIEW.md` record actually read source evidence. `docs/DTE-BYTE-ORDER-PROPOSAL.diff` proposes only Spec/CommB.lean's oracle-value arm/docstring, SHA256 `1de67cd6b73644ebd60a9e24f3e8f3e6618dd58ef364a69ef8accea29ef6968a`. **The user has now approved exactly this one-file patch and it is applied; the before-refresh FC003 log entry is recorded.** Impl and JSON are mirrored and the refinement rebuild passed; see the completed FC003 section above. Standard values remain raw; no DTE exemption is allowed. No other frozen edit is authorized.

The review-only command `python3 review/check_dte_proposal.py` passed: the candidate matches fresh actual whole-message and direct oracles for all 65,536 DTE codes, and a DTE-only substitution resolves all 17,235 retained whole-message plus 5,740 direct failures. It preserves all standard/raw values and other BDS10 fields across 71,278 distinct words; kernel examples cover 18 basis/boundary patterns and raw 1/oracle 256. All 9,372 D001 cases remain unchanged. Evidence is in tests/evidence/dte-proposal/. That historical run was a candidate/counterfactual check, not an implementation or gate pass; the permanent applied regression is recorded above.

The final manifest still lacks seven capstones. The unchanged full gate was rerun after FC002: lock/source/build/import checks pass, then it fails on those seven absent theorem names (tests/evidence/frozen-changes/FC002/check-all.log). No capstone work, optimization generation, commit or push followed the diagnostic finding. Before gen1, the user requires a concrete differential-suite freeze proposal, but only once the actual whole-message suite passes. The post-FC003 campaign above now meets that condition, and FC004 awaits approval.

## FC002 applied; reserved velocity regression passes

After FC001 completed, continued generated testing found another frozen semantic omission. Pinned rs1090/deku 0.20.3 interprets the 22-bit reserved velocity field for TC19 subtypes 0/5/6/7 as 8, 8, 6-bit little-endian chunks on the pinned target. The frozen record preserves the MSB-first wire value but has no separate oracle meaning. The first 10,000 encoded/corrupted generated messages produced 9,029 exact matches, 940 known D001 cases and 31 reserved_data mismatches. Inputs/results are retained in tests/evidence/message-generated-initial/. This is a failed generated run, not the required 100k/10M differential pass.

`docs/RESERVED-VELOCITY-REVIEW.md` explains the counterexample and `docs/RESERVED-VELOCITY-PROPOSAL.diff` proposes changes only to Spec/Semantics.lean and Spec/Assignment.lean. **The user has now approved exactly this patch by its SHA-256. It is applied to the two authorized files and mirrored in Impl; the extended refinement and all unchanged dependency/assignment/import audits pass. FC002 was recorded before the two-entry lock refresh. All 61 hashes match; the other 59 entries are unchanged, with before/after snapshots in tests/evidence/frozen-changes/FC002/.** A review-only prototype matches actual pinned oracle results on 16,511 cases (four subtypes ×zero/all-one/22 single-bit/4096 random cases, plus 31 failures). Its proposed semantic lists also agree with the independent assignment. Complete evidence: tests/evidence/reserved-velocity-proposal/. The raw/standard fields remain unchanged. Adding a conversion only in JSON would leave an exact reported meaning outside the proved record, so approval of the frozen semantic addition is required.

Completed: Impl mirror/refinement, unchanged audits, exact two-entry lock refresh and permanent fresh-oracle reserved regression (16,480 cases, zero mismatches; all four subtypes/basis patterns/random strata). The complete diagnostic campaign below has now run. It retains every mismatch and reports all required branch counts. The remaining seven capstones have not resumed. The sole new frozen omission is presented as one batch; once its approved correction passes the actual suite, propose freezing the differential suite before gen1. No other frozen change is authorized.

## Applied approved correction: negative Gillham compatibility (FC001)

On 2026-10-16 the user approved the proposed correction, requiring permanent exhaustive AC13/AC12 differential coverage, a standards-cited discrepancy preserving standard heights, and a before-lock-update change record for this and every future frozen edit. The initial complete-corpus JSON comparison found a frozen oracle-compatibility error: rs1090 rejects negative Gillham heights, whereas the pre-correction oracleAC13/oracleAC12 returned the standard negative height. This changed the exact Comm-B candidate set on 33 corpus frames. The concrete first case is corpus row 17040, `a1000000920805003ffc0005c6e5`, with MB altitude code 0x80. The pre-correction reference supplied −1200 ft, while the oracle supplied missing; the outer height is also missing, so only rs1090 retained BDS05.

`docs/ALTITUDE-COMPATIBILITY-REVIEW.md` documents the evidence and smallest proposed correction. `docs/ALTITUDE-COMPATIBILITY-PROPOSAL.diff` edits only the compatibility functions/docstrings in two frozen files, Spec/Altitude.lean and Spec/AssignmentAltitude.lean. **The exact approved patch is applied and mirrored in Impl/Altitude.lean; validation passed and only the two approved lock entries were refreshed.** The standard Gillham domain/decoders and negative binary25 values remain intact. No guard or capstone change is needed. The unchanged receiver/assignment/dependency guards and affected refinements all passed. `docs/FROZEN-CHANGES.md` was written before the hash refresh and records date, old/new hashes, reason, evidence and explicit approval. The other 59 lock entries remain unchanged; all 61 hashes match.

`lake env lean --run review/AltitudeCompatibilityProposal.lean` passed: proposed independent/reference equivalence on all 8192 AC13/all 4096 AC12 codes, receiver acceptance on all 4096 AC12 codes, and concrete kernel regressions. Its emitted compatibility results were compared with actual pinned Message::from_bytes on 8192 DF4 and 4096 DF18 inputs: 12288 cases, zero mismatches. Complete review evidence is retained in tests/evidence/altitude-proposal/. The historical pre-approval evidence retains its original hashes.

`scripts/run_differential.sh --altitude-only` now passes the permanent actual-runtime/reference/oracle test on all 12288 codes (8192 AC13 accepted, AC12 3322 accepted/774 rejected), plus a Comm-B regression. Both complete quick/full differential paths require it. No sampling or D010 exemption is used. Each field retains 12 negative Gillham values in the standard view and 40 negative binary25 values in both views. Evidence: tests/evidence/altitude-exhaustive/. D010 cites actually inspected Annex 10 IV clauses and the negative pulse-assignment row, with Sun eq 13.1 for −1200 ft. Five source-backed probes and all 33 prior corpus candidate mismatches now pass; their standard views retain 25 barometric negatives and 8 GNSS-metre values (D007). See tests/evidence/negative-gillham/ and altitude-corpus-regressions/.

The new CLI/output adapter and message-oracle harness built. The initial corpus run consumed all 172432 messages: 170398 oracle-view matches, 2034 mismatches (33 BDS05 candidate sets, 1989 track values, 12 groundspeeds). Tests/evidence/message-initial/ preserves all outputs and failure details. This is not a passing full differential suite. The scalar numerical mismatches are a separate adapter error: it used system libm instead of rs1090's Rust libm 0.2.16 crate. The initial 20936723-value test passed against Rust system math, not the actual pinned dependency. The corrected test harness now uses pinned libm and fails at hypot(11,261). No accuracy tolerance was loosened. The freeze question is resolved. The subsequent pure port fixes these numerical differences, as recorded below; no new extern was added.

The user approved this exact two-file correction and corresponding hash refresh. `docs/FROZEN-CHANGES.md` records the old/new hashes and approval before the lock update; AGENTS.md records the permanent history requirement. Parallel agents stopped at compile-clean states. CPRLocal is proved universally in Proofs/CPRGeometry.lean; Proofs/CPRGlobal.lean now proves the complete universal CPRGlobal capstone, including circular longitude and the polar one-zone case, and is imported by Proofs.lean. WireBytes/BitPacking and Proofs/FrameRoundTrips now prove the universal forward frame inverse; the reverse inverse and final FrameRoundTrips remain unproved. CommBArithmetic now proves the complete trace contract for all natural register/payload inputs and is imported by Proofs.lean. Proofs/CPRLatitudeZones proves avoidance of all decodable latitudes for all 57 certificates via 228 kernel-checked grid gaps; actual transcendental enclosures and final table/formula equality remain unproved. No placeholder or broken source proof remains.

## Latest additions and continued implementation

- The pure `Impl/Libm.lean` translation of pinned Rust libm 0.2.16 fixes the numerical adapter. `python3 scripts/check_numeric.py` passed 20,936,723 fresh exact-bit comparisons; this check is mandatory in complete quick/full differential invocations. The corrected CLI matched all 172432 corpus oracle-view JSON/CRC/consumption/remainder outputs exactly. Evidence: tests/evidence/numeric-libm/ and message-corpus-corrected/. `docs/NUMERICAL-PRESENTATION.md` records scope and licenses. This is tested presentation only; no hardware inference primitive or Float proof claim is introduced. Generated whole-message coverage subsequently passed in the post-FC003 campaign above.

- `docs/LAYOUT-ANCHORS.md` inventories 70 ADS-B branches and 14 Comm-B registers. **24 distinct worked Sun full-frame inputs** are checked through `Spec.decode` (23 successes and one corrupt rejection); **zero ICAO complete decoding examples** occur in the sources read. Six Sun raw-only Quick Start inputs and four ICAO arithmetic assertions are counted separately. The coverage table explicitly labels every missing branch **rs1090-derived; no worked-example anchor**, while retaining any available table provenance.
- ADS-B anchors cover TC4, TC7, TC11, TC19/subtype 1 and TC19/subtype 3. Missing: TC0–3, 5–6, 8–10, 12–18, 20–27, 30; TC19/subtypes 0, 2, 4–7; TC28/subtypes 0–7; TC29/subtypes 0–3; TC31/subtype 0/versions 0–7, subtype 1/versions 0–7, and subtypes 2–7. Comm-B anchors cover 17/20/40/44/45/50/60; missing 05/10/18/19/21/30/65. `scripts/ReviewLayoutCoverage.lean` checks all 70/14 canonical branches in the kernel. SCOPE.md, THEOREMS.md and docs/EXAMPLE-COUNTS.md link the inventory.
- `scripts/check_cpr_differential.py --quick` passed 44,228 calls; `--full --output tests/evidence/cpr-synthetic-full` passed 535,748 calls from 65,536 random worldwide positions. Actual Impl exact/numerical decoders are compared to the frozen reference and pinned rs1090. All 58 NL transitions, both hemispheres/media/parities, offsets within four quantization steps, ±87°, poles, equator, antimeridian, half-cell reference limits, moving pairs and rejection cases are included. All 216 geographic grid cells are occupied.
- Full CPR result: 535,544 oracle results bit-identical; 204 individually validated known D009 (exact ±87° NL convention) differences. All 533,982 admissible cases satisfy WithinResolution; zero contract counterexamples. The 22 additional rational-vs-Float half-cell ties are all outside LocalAdmissible and actual numerical output equals rs1090; they are retained, not silently removed. `docs/CPR-SYNTHETIC.md` documents denominators and classification, with complete compressed traces and source hashes under tests/evidence/. Preliminary interpreted campaigns were interrupted to switch to native execution and are not claimed complete.
- `scripts/run_differential.sh` now makes this CPR stratum mandatory on full-suite invocations. `--cpr-only` explicitly selects component validation. The later complete post-FC003 campaign above includes both whole-message corpus/random coverage and this mandatory CPR stratum; component-only commands do not claim a full-suite pass.
- `Impl/` now implements complete frames, payload layouts, semantic reports, software-binary64 Comm-B inference and exact/numerical CPR tracking. `Proofs/Decoder.lean` proves 165 modular equalities and exact Refinement/PrefixRefinement; `Proofs/CPRTracking.lean` proves the policy and numerical program refinements. `lake build Proofs.Decoder Proofs.CPRTracking` passed. Runtime imports are Model/Impl only; no Spec or Mathlib algorithm import.
- `Proofs/Altitude.lean` proves both altitude contracts; `Proofs/ParityFinite.lean`, `ParityLinear.lean`, `ParityOverlay.lean`, and `ParityPolynomial.lean` prove all four parity contracts. Polynomial equality is against actual Mathlib Polynomial.modByMonic over ZMod2 for every width/Nat input, using coefficient semantics and division uniqueness. All targeted builds and axiom checks pass. `Proofs/BasicContracts.lean` proves inference membership, quantized-zone rejection, and out-of-order handling. `Proofs.lean` aggregates completed proofs; lake build includes it by default.
- The runtime is an initial exact implementation, not yet optimized. No new performance measurement or optimization generation is claimed; the retained BDS50 baseline below remains 0.2416469× Rust. The JSON/CLI projection now passes the complete post-FC003 campaign, including both corrected semantic omissions. The complete upstream unit-vector port and remaining universal proofs are unfinished.

## Review definitions and CPR realism check

- `docs/REVIEW-DEFS.lean` copies all 17 requested roots first, with original definition file/line, exact source spans, docstrings and namespace context. Traversal of elaborated types and bodies covers 365 project constants through 216 exact source commands, including all project-local semantic helpers. Generated auxiliaries and projections map to their authored parent commands. Twelve nontrivial library definitions are also copied, with an explicit library boundary and 248 library source references. This is a commented review artifact, not another compiled specification.
- `lake env lean scripts/review_dependencies.lean`, `python3 scripts/write_review_defs.py --check`, and `lake env lean docs/REVIEW-DEFS.lean` passed. The source checker reports all copied spans match; Lean checks the review file's comment syntax, not new proofs.
- The new, unfrozen `review/cpr-oracle/` tracer built offline in the shipped dist profile. It compares actual `decode_positions` with sequential actual `decode_position`, bit for bit across all 172432 corpus messages, and checks observed aircraft positions and route classification. It records 12964 CPR frames and 11347 accepted positions; only two aircraft have resolved positions. Reproduction and the exact schema are in its README.
- `python3 scripts/review_cpr.py .cache/review-cpr/trace.jsonl` passed, then the same evaluation from retained `docs/review-cpr/oracle-trace.jsonl.gz` passed. `scripts/ReviewCPR.lean` evaluated the actual frozen predicates on 21609 cases using exact rational interpretations of the oracle's binary64 coordinates, treated as true positions. All transmitted coordinate re-encoding checks passed.
- LocalAdmissible: 1057/1057 actual local resolutions (10 airborne fallback and 1047 surface), 100%. The auxiliary current/previous-reference population is 11345/11345,100%; all airborne references satisfy the policy age bound. Two initial global outputs lack a previous reference.
- GlobalAdmissible: 10254/10264 live under 30-second opposite-parity pairs with both members' own original arrival positions available, 99.902572%. All 10 failures are solely encoder-quantized NL mismatches; rs1090 resolves those current messages by local fallback. Of 10405 global attempts, 105 have unresolved current positions and 36 have a resolved current but unresolved original mate; these are unavailable, not counted as failures or supplied with synthetic truth. Same-pair reverse reconstruction is not used.
- `docs/CPR-REALISM.md`, `docs/review-cpr/summary.json`, compressed complete trace/evaluations, and the ten failure records retain methods, exclusions, exact bit patterns, row identities and SHA256 provenance. The percentages concern this single corpus and oracle-derived truth; they are not independent physical-position accuracy or general-domain proofs.
- The final `python3 scripts/check_lock.py` check passes all 61 frozen files. No frozen file or lock entry was changed for this review.

## Done

- Preserved the original prompt in `GOAL.md`; copied its section 0 rules into `AGENTS.md`; `CLAUDE.md` points to them. Read GOAL/PROGRESS after context resets. Parallel agents handled oracle scope/benchmarking, payload schemas/inference, and altitude/CPR; the primary agent integrated and reviewed them.
- Studied lean-zip before design: HEAD `2f7a63f38195bc667a926881b55d10c9f8a88eeb`, `pre-split` `9bc0e7d28691223e669474ffdf4ed1041d2522b5`. Commands included `git show pre-split:PLAN.md`, `PROGRESS.md`, `progress/wide-refill-2854.md`, and reads of CRC Spec/Native and conformance files. Lessons and exact source provenance are in `docs/SOURCES.md`.
- Pinned Lean 4.35.0 (`lean-toolchain`, compiler `eb6cafb7290e8bd5f2937522d8d804f58f02bafc`) and matching Mathlib commit `56a005855ea17e0b0958f73ec801ae140b0a1679` in `lakefile.toml`/`lake-manifest.json`. Official release APIs and `git ls-remote` were checked; `elan toolchain install`, `lake update` and targeted Mathlib cache retrieval succeeded.
- Cloned rs1090 into `vendor/rs1090`, detached at `685dfaa34c5ab186c691bca3cfe2a22e12517d30` (2026-10-13). Built shipped `dist`, locked dependencies, default features including bds-infer. Rust/cargo 1.93.1. Project-local `.cache/venv` contains matplotlib 3.11.2 and pypdf 6.21.0; `requirements-tools.txt` records dependencies.
- Acquired/read Annex 10 IV fourth edition 2007 with amendment 85 pages, Sun's second edition 2021, and the Annex 10 III PartI amendment 77 CPR excerpt. URLs, editions/revisions, hashes and unavailable-source handling are in `docs/SOURCES.md`. The ICAO maintenance HTML response was not treated as a PDF source.
- Wrote `SCOPE.md`, `THEOREMS.md`, `Spec/`, `Capstones.lean`, `bench/BENCHMARK.md`, the pinned Rust benchmark harness, `TRUSTED.md`, and source/topic notes. The original checkpoint had 22 named propositions; the amended contract has 23, including the proved BDS50 pilot. Later Proofs modules must prove these exact propositions without modifying the frozen file. This avoids frozen placeholder proofs. `THEOREMS.md` quotes each statement verbatim and documents every hypothesis and non-vacuity witness.
- Reference definitions include lossless frame/payload decoding and independent field encoders; polynomial CRC; altitude; exact CPR and NL formula/certificate candidates; complete CPR tracking with tested numerical adapters; all 14 Comm-B register schemas and exact binary64 inference decisions; and proof-visible exact semantic values, strings and Float-expression operands. Full structural field domains are separate from oracle receiver filters. No decoder uses a forbidden construct or a newly authorized extern primitive.
- Recorded source-backed discrepancies D001–D010, concrete inputs and both standard/oracle results in `DISCREPANCIES.md` and `bench/evidence/`. Includes Comm-D's 115-bit oracle over-read, ADS-B velocity/source/height differences, the 50000 ft receiver heuristic, and the attainable 87° NL boundary. BDS65 per-message inference's offset/length rejection is explicitly rs1090-derived; its direct schema remains covered.

## Applied approval amendments

1. **Proof and timed function.** The headline contract times exactly `Impl.decode`, including projection to the complete Spec model. `scripts/Final.lean` fixes 23 final theorem types, binds the real Impl entrypoints, and prints axioms of the proofs. It is an import-free declaration fragment compiled verbatim under temporary integration imports by the frozen checker. The result type is now explicitly `Lean1090.Model.BDS50.Result` in `Model/BDS50.lean`. The compiled graph audit rejects every direct/transitive Spec or Mathlib dependency from Impl and every Impl/Proofs dependency from frozen reference modules. Frozen Lean import headers admit only Spec, Model, Mathlib and Lean platform libraries. The audit passed for 2 runtime modules and 30 frozen semantic modules, with four rejection self-tests. All relevant guards are themselves frozen; `check_all.sh` checks the lock first.
2. **Independent hypotheses and conclusion.** `Valid` accepts independent frame fields; `assigned` now constructs reports through an independent field interpretation in `Spec/Assignment.lean`, including a separate MSB bit fold and prefix-parity Gray altitude interpretation. The dependency audit traverses all seven required predicates **and assigned** through elaborated types and bodies, including opaque definitions/proofs. It rejects indirect decoder/helper dependencies and tests body-only, type-only and assigned-via-report traps. `CheckAssignment.lean` kernel-checks every AC13/AC12 code against the independent altitude interpretation and all 29 successful complete source snapshots under assigned (32 proofs total). `GlobalAdmissible` compares NL on encoder-side rounded latitudes without calling global reconstruction. The audit also confirms `Parity.polynomialRemainder` is Mathlib `Polynomial.modByMonic` over `ZMod 2`, independent of the CRC recurrence.
3. **Published anchors.** There are 24 distinct worked full-frame Sun inputs (23 successes and one corrupt rejection), six additional raw-only Quick Start frames, and four non-frame worked groups. The ICAO sources actually read contribute four arithmetic assertions and zero complete worked decoding frames. `docs/EXAMPLE-COUNTS.md` separates these source counts from proof counts: 65 named source-anchor proofs and 57 examples in `StandardExamples`, plus 30 complete-result regression proofs/examples in `StandardFullExamples`. Additional complete-result fields absent from the source are explicitly regression expectations. Published source fields are independent literals. The detailed inventory documents source editorial contradictions and scope exclusions.
4. **BDS50 pilot.** `Impl.BDS50.decode` implements all hard checks, status consistency, sentinels, exact finite binary64 density/penalty arithmetic, the inclusive −3 gate and the complete result. `Proofs.BDS50.refinement` proves equality to the frozen reference for every Nat input, including over-wide words. Concrete witnesses prove an accepted result and an attainable exact −3 score with adjacent passing/rejected rate codes. The timed path returns all raw codes, five optional semantic fields, and exact score; no theorem projection is left outside the clock.
5. **Structured Comm-B generation.** `scripts/FuzzBDS50.lean` produced 4504 cases, including 4096 seeded plausible assignments, hard/status/sentinel boundaries, 276 score-transition neighbors and the exact −3 fixture with neighbors. The broader `scripts/FuzzCommB.lean` generates all 14 register schemas through `encodeBDS`, targeted plausibility/status boundaries and score crossings for 40/44/45/50/60. Reference generation is not a claim of full-register differential agreement; the remaining differential runner must consume these strata in addition to corpus and 100k/10M randomized messages.
6. **Timing noise and host state.** Persistent workers and `bench/interleave.py` alternate three AB warmup pairs then 21 measured AB pairs, A=Rust/B=Lean, on one core. No independent 21-run blocks remain. The headline runner records Windows active power-plan name/GUID before and after, rejects a changed plan, and requires documented capture if WSL interop is unavailable. Its Lean worker is still a section 4 deliverable; missing executable fails explicitly.

## Measured BDS50 result

The retained run is `bench/evidence/bds50-pilot-quiet.json`; method and reproduction commands are in `docs/BDS50-PILOT.md`. CPU 0, Intel Core Ultra 9 285K, WSL2 Linux 6.6.87.2. Windows power plan read successfully: **Ultimate Performance**, GUID `b96ff06e-8688-42eb-9c00-7c9f42465d2a`. Shipped Rust dist/default features, Lean generated C at −O3, no CPU-specific flags.

| Result | Lean | rs1090 |
| --- | ---: | ---: |
| Median over 21 AB-interleaved measured runs |343.297097 ms|82.956695 ms|
| Throughput for 47714 DF20/21 MBs |138987.48 msg/s|575167.56 msg/s|

Lean is **0.2416469× Rust throughput**, approximately 4.14× slower. This is an honest component baseline, not the whole-message headline or the 10% target. No optimization generation has been attempted. The quoted result is the designated confirmation after all parallel validation stopped; the earlier diagnostic 0.2462× run (isolation from parallel validation not established) remains in `bench/evidence/bds50-pilot.json`. Neither run was discarded to improve the result. All 47714 corpus MBs and 4504 structured cases matched acceptance, all five semantic values and exact binary64 scores, including hard-valid candidates rejected by score. Corpus outcomes: 9813 accepted, 828 score-rejected, 37073 hard/empty-rejected. Generated outcomes: 421 accepted, 4026 score-rejected, 57 hard/empty-rejected.

## Executed validation

- Final review audits pass: all 61 locked files, 84 Lean source files, 37 required artifacts/23 exact statements, 20 runtime modules/30 frozen semantic modules, and all 17 requested review roots with exact copied spans. Only the two FC001-approved lock entries differ from the original snapshot, with both old/new hashes in FROZEN-CHANGES.md. This earlier audit preceded FC002; the new FC002 evidence above supersedes its lock state.

- Latest continuation: `lake build Proofs Proofs.CPRLatitudeZones Proofs.FrameRoundTrips messageGenerator lean1090` passed 3518 jobs. `scripts/check_all.sh --quick` passed lock/source/build/module checks and fails on seven missing final theorem names (log .cache/continued-review-gate.log). CPRGlobal and CommBArithmetic use only the permitted three axioms. Generated prototype and proposed reserved-field tests are reported separately above, with no full-suite claim.

- FC001: `lake build Proofs lean1090`, unchanged hypothesis/receiver/assignment/module-graph checks, permanent exhaustive altitude differential entrypoint, and review source regeneration/check all passed. All 33 previous altitude candidate mismatches now match. `scripts/check_all.sh --quick` was rerun and fails on the nine missing final proofs; no commit made. Retained logs and before/after lock snapshots: tests/evidence/frozen-changes/FC001/.

- Final review checks: `lake build Proofs Proofs.CPRGlobal Proofs.BitPacking Proofs.CommBArithmetic lean1090` passed 2098 jobs; `scripts/ReviewLayoutCoverage.lean` passed its 70/14 kernel coverage checks; the compiled module-graph audit passed. `check_lock.py` passes 61 hashes, `audit_source.py` passes 81 Lean files, and `check_documents.py` verifies 37 artifacts/23 exact capstone statements. Logs `.cache/approval-review-build.log`, `.cache/approval-review-imports.log`, `.cache/layout-coverage-final.log`. These passing checks do not override the known full-suite failures.

- `scripts/check_all.sh --quick` after continued implementation: lock, source audit, build and module graph passed, then the exact manifest rejected the ten then-missing theorem constants. Log `.cache/continuation-gate.log`; CPRLocal was completed subsequently, leaving nine. Error-recovery `sorryAx` output belongs only to the failed temporary manifest, not a committed/proved theorem. No commit was made.
- `scripts/run_differential.sh --cpr-only`: passed the integrated 44228-case quick stratum and explicitly reported whole-message testing not requested. Log `.cache/cpr-entrypoint.log`. Full 535748-case evidence remains separately retained.

- `scripts/check_draft.sh`: passed after all semantic changes; full log `.cache/final-freeze-draft-check.log`. Includes source audit, build, BDS50 proof/executable, module graph, all eight dependency roots, exhaustive 4096-code receiver policy, 32 independent assignment proofs, 152 Spec witness/example proof axiom checks, payload/altitude/CPR probes and exact documented capstone checks.
- `python3 scripts/check_impl_imports.py`: passed for 2 runtime and 30 frozen semantic modules; all four rejection self-tests passed. Exact output is in `docs/CHECKPOINT-AUDIT.txt`.
- `lake env lean scripts/CheckHypotheses.lean`: all seven hypothesis predicates and assigned passed; body/type/assigned trap self-tests and polynomial-division check passed. Exact output is in `docs/CHECKPOINT-AUDIT.txt`.
- `python3 scripts/check_pilot.py`: the concrete BDS50Refinement proof and both witnesses use only propext, Classical.choice, Quot.sound. The frozen pilot manifest is now an import-free fragment compiled by this command.
- `lake build Spec.StandardExamples Spec.StandardFullExamples`: passed; source inventory and distinct example counts checked in `docs/EXAMPLE-COUNTS.md`.
- `python3 scripts/test_lock.py`: passed before writing the actual lock. Temporary-copy tests accepted the intact inventory, rejected five separate frozen-file changes, added Spec code/data files, and a duplicate lock entry. A corrupted copy's full gate failed at the lock check before any other work.
- `python3 scripts/audit_source.py`: passed for 43 Lean files, with no forbidden constructs. `python3 scripts/check_documents.py`: passed for 37 required artifacts and 23 exact capstone statements.
- `python3 scripts/check_lock.py`: passed after creating the lock with SHA-256 entries for 61 files.
- `scripts/check_all.sh --quick`: run **after** freezing; log `.cache/final-frozen-gate.log`. Lock, source audit, builds and import audits passed, then the exact final theorem manifest failed because `.lake/build/lib/lean/Impl.olean` is absent. Remaining final proofs and runners are not claimed complete; no commit was made.
- `lake env lean --run scripts/FuzzBDS50.lean .cache/bds50/generated.csv` and `python3 scripts/bench_bds50.py --generated .cache/bds50/generated.csv --output bench/evidence/bds50-pilot-quiet.json`: generated 4504 fixtures; full corpus/fixture differential passed; executed 3+21 AB pairs and retained all raw timing/environment/build evidence.
- Frozen oracle dist build and persistent worker protocol checks passed on all 172432 messages: decode 0 positions, CPR 11347 positions. The whole-decoder comparative runner correctly refuses the absent Lean worker. Rust formatting, shell and Python syntax checks passed.

`python3 scripts/check_commb_fuzz.py .cache/commb-generated.csv` passed on 101244 fixtures (100000 random plus 1244 targeted), including 83986 hard-valid payloads. The final CSV SHA256 is `2cede8dc72ee92d721f555411bc063f8a496706b88d919ef3f4a14cc594f07c5`. That command validated reference fixtures only; the later complete direct-register/whole-message campaign is recorded above. The complete upstream unit-test port and remaining universal proofs are still section 4 work. The DTE correction and passing whole-message suite are complete as recorded above. The gate checks the lock first and deliberately fails while the final manifest or required test/differential runners are missing. No commit can be made on the strength of the draft check. The BDS50 performance numbers above are the retained pilot measurements; this freeze did not rerun or claim a new benchmark.

## Earlier user decisions still in force

- Include DF19 and DF24–31 in addition to the original list. Preserve the standard Comm-D layout despite the pinned parser over-read; see DISCREPANCIES.md.
- Match rs1090 local surface CPR. Global surface CPR is a possible extension only after section 8.
- Quantized CPR zone conditions, documented hypothesis necessity/failure bounds, and concrete non-vacuity witnesses for every capstone remain required.
- Cite only actually read ICAO tables with edition/location. Unavailable-table fallback is explicitly rs1090-derived. Source/version disagreements remain explicit.
- Ask before the first push. No publication has occurred or been authorized.

## In progress, next, and open questions

FC001–FC006 are approved and applied exactly. Post-application guards and integrated suites pass; the seven capstones have resumed as recorded above. Batch later frozen-model findings rather than editing frozen files. No additional frozen change is authorized.

All 23 capstones are proved and the exact manifest passes. FC006 and the accepted generation 0 baseline are complete. Optimization is authorized under the current status above; generation 9 passed validation and has been measured from its clean commit. Its independent result review and complete diagnostic pass. Generation 10 passed the full gate and fresh campaign, was committed and freshly measured, and reached 1.168948811789× decode. Stop for user review; no further optimization or final-run/deliverable work is authorized before that review. These milestone checks do not replace the final clean-clone checks required by GOAL.md. Complete the full gate before any commit; first push still requires separate approval. For optimization, the user's order is binding: preserve software binary64 as the proved reference; first try exact per-field density tables and proved integer score decisions with a full-model fallback inside a proved rounding-error bound around −3. `docs/OPTIMIZATION.md` records the proof and measurement obligations. Only if verified approaches cannot close the gap may hardware add/sub/mul/div primitives be proposed, and the user must approve them before addition. Any approved primitives must use `-ffp-contract=off` and runtime model cross-checks. No such primitive is authorized or added. Final gate and performance requirements remain those in GOAL.md; none is redefined by the 0.2416469× pilot.

Reproducibility: install the pinned Lean toolchain, restore matching Mathlib cache, clone rs1090 at the pinned commit into vendor/rs1090, use the project-local cargo/venv caches or documented equivalent tools, and run the documented build/check commands. Vendor clones and downloaded source PDFs are ignored; source URLs/hashes, semantic definitions, checks and retained evidence live in the project.
