# Generation 25: exact numerator scaling identity

The generation 24 decode diagnostic collected 5,805,983,682 instructions.
Comm-B inference was the largest exclusive stage at 2,306,269,761 instructions.
Within it, `ScoreGate.choose` accounted for 1,233,320,887 overlapping inclusive
instructions; its outer `scaledTotals` fold accounted for 641,477,536.
The outer and inner folds made 45,510 and 95,802 direct native big-integer
multiplication calls, respectively. Their direct big-natural division counts
were 1,356 and 2,899. These are surviving native boundaries, not every inlined
operation or a count of equal denominators. Inclusive costs overlap and do not
predict a timing gain. [Diagnostic report](GEN24-COST-BREAKDOWN.md) and
[exact score contexts](../tests/evidence/diagnostics/gen24/score-scale-contexts.json)
retain the observations.

`scaledNumerator denominator value` now returns `value.num` when
`denominator == value.den`. Otherwise it evaluates the original expression,
`value.num * (denominator / value.den : Nat)`, verbatim. No zero-numerator
special case or other runtime change is included. The shortcut applies to
arbitrary rational denominators, including non-dyadic ones.

`Lean1090.Proofs.ScoreGateInteger.scaledNumerator_eq_old` proves equality to
that original formula for **every** natural denominator and rational value.
A rational denominator is positive, so division by itself is one. Unequal,
zero and non-divisible input denominators retain the original natural-division
semantics. The existing `scaledNumerator_cast` proof rewrites through this
unconditional equality; all previous theorem statements remain unchanged.

Six new kernel witness groups check:

- Equal denominator: `scaledNumerator 8 (13/8) = 13`.
- Unequal denominator: `scaledNumerator 24 (13/8) = 39`.
- Zero denominator: `scaledNumerator 0 (5/7) = 0`.
- Negative values in both branches: denominators 8 and 24 yield −13 and −39.
- Non-dyadic equality: `scaledNumerator 7 (10/7) = 10`.
- Non-divisible denominator: `scaledNumerator 19 (10/7) = 20`.

The targeted `lake build Proofs.ScoreGateInteger` passed on attempt 3
(2,041 jobs). All 20 printed module facts use only the permitted axioms.
The first two attempts retained proof elaboration errors involving lambda
binder types and the positivity argument to `Nat.div_self`; the runtime
was unchanged across all attempts. [Sources, commands, logs and summary](../tests/evidence/optimization/gen25/score-scaling/summary.json)
retain those attempts.

The [combined production and proof build](../tests/evidence/optimization/gen25/integration/validation.json)
passed with 202 unchanged correctness inputs. The
[full fixed gate](../tests/evidence/optimization/gen25/gate-evidence.json)
and [independently reviewed fresh campaign](../tests/evidence/optimization/gen25/independent-review/fresh-completion.json)
passed, including their separate 10-million-message generations and direct
Comm-B checks. The fresh campaign retained 33 evidence files and bound all
127 audited sources and three binaries. Its exact matches and documented
D001 cases account for all 10,476,164 whole-message comparisons.

[Native review](../tests/evidence/optimization/gen25/native-review/review.json)
verified the equality arm and unchanged fallback in the linked worker;
21 of 22 native sets remain byte-identical to generation 24. Fixed archival
retained all seven components and 62 files before verified duplicate cleanup.
The [benchmark plan](../tests/evidence/optimization/gen25/benchmark-preparation/plan.json)
preserves the 50-row historical CSV prefix, both exact 2.00× targets and both
signed CPR-overhead calculations. Isolated measurement remains pending.
No shortcut hit rate or throughput result is claimed here.
