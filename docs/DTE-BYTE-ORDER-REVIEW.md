# FC003 review: BDS10 DTE oracle byte order

**Historical proposal, now approved and applied.** The user approved the exact
patch below. Application, before/after lock snapshots and current validation
are recorded in [FROZEN-CHANGES.md](FROZEN-CHANGES.md). The original proposal
observations below describe the pre-FC003 state; the review-only driver expects
that state. Use `python3 scripts/check_dte_differential.py` for the permanent
post-application regression, which passes all65,536 codes against fresh
whole-message and direct oracles.

This is the complete batch of new frozen-model omissions found by the FC002
follow-up diagnostic campaign: **one issue, BDS10 `dte` byte order**. The
campaign finished before this review was prepared. No frozen correction in
this proposal has been applied, and none is authorized by FC002.

## Observation and complete campaign

The executed command was:

```sh
scripts/run_differential.sh --diagnostic --corpus --generated 100000 --commb-boundaries .cache/gate/commb.csv
```

The boundary file was freshly generated with the frozen `FuzzCommB.lean`
using 100,000 random assignments and seed1085632. The diagnostic runner
completed all strata and returned failure after retaining every disagreement.

| Comparison | Cases | Result |
| --- | ---: | --- |
| Full corpus | 172,432 | Exact oracle-view match on every message |
| Encoded/corrupted generated messages | 100,000 | 90,628 exact; 9,372 narrowly checked D001 Comm-D differences |
| Structured Comm-B, three full-message contexts | 303,732 | 17,235 DTE-only mismatches; 286,497 exact |
| Direct named Comm-B registers | 101,244 | 5,740 DTE-only mismatches; 95,504 exact |
| Exhaustive altitude codes | 12,288 plus one candidate regression | Passed |
| Reserved TC19 regression | 16,480 | Passed |
| Binary64 presentation checks | 20,936,723 | Exact bit matches |
| Worldwide/boundary CPR | 44,228 | Passed with 204 narrowly classified D009 cases; no unclassified differences or contract failures |

All 70 ADS-B branches have accepted inputs in both implementations. Every
scoped DF has input coverage, and every non-Comm-D scoped DF has accepted
inputs; rs1090 rejects the standard Comm-D family under D001. All 14 Comm-B
registers have targeted messages and accepted direct-decoder inputs. The
complete counts for all32 DF values, all70 ADS-B branches and all14 registers
are in [MESSAGE-DIFFERENTIAL.md](MESSAGE-DIFFERENTIAL.md).

Every mismatch, including known D001 instances, is retained in
`tests/evidence/message-differential/mismatches.jsonl.gz`; direct-register
mismatches are in `direct-mismatches.jsonl.gz`. Full inputs and both outputs
are retained beside them. The only unclassified complete-message path is
`/oracle/bds10/dte`; the only direct-register path is `10:/dte`. There are
5,745 affected messages in each structured context, including five payloads
per context targeted at another register but also inferred as BDS10.

## Minimal counterexample and cause

Message `a0000000100000000000011e478d` is a DF20 report with MB
`10000000000001`, DTE raw1 and AP-recovered address112233. The executed
standard/raw and current Lean compatibility outputs both contain `dte: 1`;
actual pinned rs1090 contains `dte: 256`. Both accept the frame. Every other
JSON field, CRC, consumed length and remainder agrees.

The published DTE field is an array of status bits. ICAO Doc9871, second
edition2012 including amendment1 entered9January2017, **Table A-2-16**,
printed p.A-37 (PDF page65), assigns DTE bits41–56, with bit41 MSB and bit56
LSB; note3 maps consecutive bits from the MSB to subaddresses0–15. This
passage was actually read through the extracted PDF text of the
[document mirror](https://manuals.plus/m/07560cb9fbd061450f9d216b298160181a57c0b1a7795edc699cfaeb1e80fb7b.pdf)
on2026-10-16. As with D011, screenshot retrieval was unavailable; no local
PDF or invented PDF hash is claimed. Keeping its MSB-first wire integer is
the project's lossless raw convention, not a new physical scalar quantity.

The inspected pinned rs1090 `bds10.rs:279–280` declares
`#[deku(bits = "16")] pub dte: u16` with no field or struct endian
attribute. In deku0.20.3, `src/impls/primitive.rs:679–691` selects
`Endian::default()` and `src/ctx.rs:34–44,60–65` uses the target CPU's byte
order. On the pinned x86_64 target, the first wire byte is the low byte and
the second is the high byte. Thus the oracle value is
`payloadBits word 41 8 + 256 * payloadBits word 49 8`.
The oracle probes `1→256`, `256→1`, `0x1234→0x3412` and `65535→65535`
confirm this host-dependent behavior.

## Review-only validation

`python3 review/check_dte_proposal.py` passed after the full diagnostic run.
The prototype is an exact copy of the frozen `commBValue` body with only the
proposed match arm added; the driver verifies that correspondence and the
patch SHA-256. No Spec or Impl file is substituted during this review.

- All65,536 raw DTE values were sent to fresh pinned whole-message and
  direct-register Rust oracles. Substituting only the candidate DTE value in
  the current complete outputs matches both oracles on every code.
- The unchanged implementation mismatches65,280 of those codes on each
  path; the256 equal-byte values already match. These failed current results
  are retained alongside the candidate evidence.
- Applying the same single-field counterfactual to every retained failure
  resolves all17,235 whole-message and5,740 direct DTE mismatches. All9,372
  documented D001 cases are left unchanged.
- Across71,278 distinct payload words, the candidate preserves the standard
  raw value and every other BDS10 semantic field. Kernel-checked examples
  cover the concrete raw1/oracle256 case plus zero, all ones and all16
  single-bit patterns.

The [prototype](../review/DTEByteOrderProposal.lean),
[driver](../review/check_dte_proposal.py), and complete retained
[evidence summary](../tests/evidence/dte-proposal/summary.json) make this
review reproducible. This is evidence for an **unapplied proposal**. It does
not make the implementation or differential gate pass. The current frozen
lock still matches all61 files, and Spec/CommB.lean remains unchanged.

## Exact requested change

Approve only [DTE-BYTE-ORDER-PROPOSAL.diff](DTE-BYTE-ORDER-PROPOSAL.diff),
SHA-256 **`1de67cd6b73644ebd60a9e24f3e8f3e6618dd58ef364a69ef8accea29ef6968a`**.
Current file SHA-256: `dabb5ec8bd0427291c211b773a88706141e0cb469705874bcd63ab6fd65a7835`. Proposed file SHA-256: `d2af3fa179d6dd05823b5abb00f8e592ccc1858232dd61d96f881fe2735a7b45`.

It changes only **`Spec/CommB.lean`**: one explicitly rs1090-derived oracle
case in `commBValue`, plus its explanatory docstring. Both the reference
oracle meaning and independent assignment already consume this function.
Standard/table values continue to use the original MSB-first layout. No
validity predicate, score, theorem, benchmark, tolerance or other frozen file
changes.

After approval, the application must use the FC001/FC002 procedure: log the
approval, exact old/new hashes, reason and evidence before refreshing the
single lock entry; retain both lock snapshots. Mirror the arm in Impl,
extend its refinement, and make JSON read `dte` from the semantic value
instead of the raw column. Add a permanent exhaustive16-bit regression and
rerun the complete campaign. This is a correction to the compatibility
model, **not an exemption** for DTE mismatches.

The seven remaining capstones remain untouched. Freezing the differential
suite is deferred until the actual whole-message suite passes, as requested;
no optimization generation has begun.
