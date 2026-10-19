# Generation 17: exact powers of two

`Impl.Binary64.powerTwo` now looks up an immutable table for integer exponents
from −1074 through 1023. Its 2,098 entries contain the original exact rational
formula; every other exponent still uses that formula directly. The table is
keyed only by binary64 format exponents. No message data, geographic position
or corpus content determines an entry.

The preceding [CPR diagnostic](GEN16-CPR-COST-BREAKDOWN.md) found numeric
geography to be the largest detailed category: 5,562,629,612 of
17,998,526,291 collected instructions. Within it, 460,693 calls to `powerTwo`
used 1,738,677,460 inclusive instructions. Its 261,723 direct rational divisions
accounted for 1,022,143,267 of those instructions. These nested counts overlap;
they are diagnostics, not predicted speedups or measured table-hit rates.
The complete [decode diagnostic](GEN16-COST-BREAKDOWN.md) and both independent
reviews passed before this change was selected.

`Proofs/Binary64Runtime.lean` proves each table lookup and the public function
equal the frozen specification for every integer exponent. The proof is
symbolic in the index, with an unrestricted fallback. It then transports the
equality through exponent selection, rounding, arithmetic, finite-bit decoding
and the model's range predicate. Five kernel witnesses cover seven exponents
at the lookup boundaries and sign split. All 32 printed facts use only the
permitted axioms. The table constructor calls the original formula, without
depending on rounding or its own lookup.

The decoder and Comm-B proof updates preserve their statements. CPR tracking
continues to preserve every state transition and per-message result. Additional
equalities explicitly cover the live stream step, reference-refresh utility,
rational-to-Float conversion, distance interpretation and complete numerical
geography. These are equalities of the specified programs; they do not claim
that opaque Float operations equal real arithmetic. Every rounding operation
and the software binary64 reference remain unchanged.

The combined build checked 3,532 jobs with all nine changed/new sources and
188 correctness inputs unchanged. The six decoder/Comm-B proof modules passed
on their first build. The central helper needed one simplifier-normalization
correction; the CPR proof needed two explicit reflexivity closures. Both
failed attempts remain retained alongside the passing builds. No theorem
statement, frozen file or trusted primitive changed.

Independent native review passed all 111 checks, binding the 22 linked sets
and 260 held inputs. The other 21 native sets are byte-identical to generation
16. The linked module initializes and marks the table persistent before
`main`; both guarded lookup and unrestricted formula fallback remain live,
including their CPR and Comm-B consumers. All 200 facts in the combined log
use permitted axioms, including three facts needing none.

The separately seeded 10M campaign passed, covering all 32 DF attempts,
70 ADS-B branches and 14 Comm-B registers without unclassified differences.
All 101,244 direct Comm-B cases match exactly. Independent retention review
and replay of the frozen comparison also passed. The fixed full gate passed,
checking all 23 capstones, 152 witnesses, 1,011 unit assertions and seven
differential components with all 188 correctness inputs unchanged. Its
10,476,164 messages contain only exact matches or documented D001 cases;
standard-view differences remain separately recorded. The final independent
gate, archive and benchmark-plan review passed. Verified duplicate cleanup
reclaimed 11,092,623,360 allocated bytes while preserving compressed evidence.
The frozen benchmark measured 1.669372647154× decode and 1.150460800400× CPR
throughput against rs1090. Both 2.00× targets remain unmet. It retained the
compiled program's initialization behavior without moving or subtracting its
cost. [Measurements and raw samples](../bench/GEN17.md). Commands, source snapshots, logs and reviews are under
[`tests/evidence/optimization/gen17`](../tests/evidence/optimization/gen17/).
