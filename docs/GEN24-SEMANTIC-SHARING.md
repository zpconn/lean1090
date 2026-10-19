# Generation 24: share common Comm-B semantic views

Generation 23's completed and independently reviewed diagnostics identify
Comm-B inference and semantic construction as the largest decode stages:
2,306,055,650 and 2,229,067,976 collected instructions. These are untimed
diagnostic observations, not predictions of throughput gains. The
[decode report](GEN23-COST-BREAKDOWN.md) and
[CPR report](GEN23-CPR-COST-BREAKDOWN.md) retain the full partitions.

The semantic oracle-value loop calls `commBValue` 525,932 times. Its repeated
`payloadValue` calls cost 552,281,123 inclusive instructions; the standard
Comm-B table-value loop separately spends 553,722,018 instructions decoding
the same fields. Those observations overlap their parent stages and must not
be added to the stage totals. Generated C already shares identical table
values and labels between output fields. The remaining duplication is between
the decoded table and the separately looked-up oracle fields.

This change builds the table once and derives the oracle values from its
`(name, Option Rat)` entries. Absent fields remain absent through `Option.bind`.
The present-value adjustment is the original match, including DTE byte order,
selected-altitude rounding, temperature correction, wrapped angles and rate
sentinels. The public `commBValue` uses the same adjustment helper after its
original lookup and status checks. The proof establishes unique names for
all twelve core layouts and equality with the previous map for every natural
register and payload, including unsupported registers and over-wide words.

The same semantic construction currently calls `oracleCommBFloats` 91,223
times, costing 115,934,997 overlapping instructions. This builds exact
`NumericField` expression trees; it does not execute new Float arithmetic.
The new path constructs that list once. The standard view is empty for BDS30,
replaces temperature expressions for BDS44, and shares the list for other
registers. An arbitrary-list equality preserves field order, keys, missing
value policy and exact expressions. The standalone standard helper retains
its BDS30 early return. BDS05/65 routing through ADS-B semantics is unchanged.

No Float evaluator, callback, frozen file, benchmark harness, theorem contract,
trusted primitive, table or cross-message cache changes. Proof work is split
between scalar-list reuse and pure numerical-expression/full-payload reuse.
The runtime build and both independent proof modules pass. Scalar reuse
prints 13 permitted-axiom facts, including eight kernel witness groups.
Numerical-expression and full-payload reuse prints eight permitted-axiom
facts. The combined decoder/proof build passed on its first attempt: 3,549
jobs, 202 unchanged correctness inputs, 127 audited sources and 346 printed
facts using only permitted axioms. Validation receipt:
`bc65dfc2d5965365fe6faf62da8fb8104504e464d4598401361acdb4a7d13e50`.
Source/proof review passed 32 checks. Native review passed 122 checks, binding
274 inputs and all 22 native sets; 20 sibling sets are unchanged. Actual-worker
C and assembly confirm one scalar table and one oracle-expression construction
per Comm-B payload. The absent-value bypass and BDS30/44/identity branches
remain live. Float evaluators/callbacks and frozen decoder callers are unchanged.
A reviewer-only assembly call-count correction is retained: LLVM duplicates
one C call into mutually exclusive allocation/reuse branches. No runtime change
or repeated measurement followed. Native receipt:
`d8df3f6f6934f3ae2096576dce7369d22a92f9246dbabbf1132f087c64f4a442`.
Full fixed and separate fresh 10M campaigns passed. Fresh seeds were
1,799,246,425 (messages) and 1,314,217,890 (Comm-B), sampled and recorded before
generation. Each campaign covered 10,476,164 messages and 101,244 direct
Comm-B cases. Only documented D001 classifications remain; full 32/70/14
branch coverage passed. Independent fresh retention and comparison replay
passed. Verified cleanup reclaimed 11,092,824,064 allocated bytes of duplicate
scratch while retaining all compressed evidence. A final fresh reporting-path
correction is documented; tests and deletion were not repeated. Fixed archive:
`8ada495695bc1a3b89a422e69335cd47c65064e020469d15b362fb9de9a43fbc`.
Final archive review passed: `1e0e8ce1e43e54bba0c3ac855b4d447aa0aa92bca4ad7dbf94d3387f8abac894`.
Two reviewer-only failures are retained: a missing launcher flag and a
sorted JSON map-key order assumption. Neither changed producer evidence
or correctness inputs. Source commit and frozen timing are next.
No speedup is claimed.

Evidence will be retained under [generation 24](../tests/evidence/optimization/gen24/).
