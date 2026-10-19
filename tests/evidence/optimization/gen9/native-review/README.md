# Generation 9 static native review

All 38 checks pass against the first successful integrated build. The captured
CLI SHA-256 is `ac2443eee11a55e970598c0924f3fa9953ef9438bd3285b94cdd9dc2682d6103`;
the build log SHA-256 is
`73bd82ef883e2ee0e5834b02b132d9ac73c57df1d9a2a433ca5644676dc2b6d5`.
All 138 captured inputs remain unchanged, including all proof sources and the
21 CLI-linked project source/C/object/trace sets. This review does not claim
to inspect a future freshly rebuilt benchmark worker.

The live `field` body starts at retained generated `Impl/Bits.c:95`. Its width
comparison at line 100 branches at 64. For widths below 64, lines 119–124 perform
the same two truncating natural subtractions, then `lean_nat_shiftr`, then
conversion of that exact shifted result to `UInt64`. Lines 128–131 construct
the low-bit mask with machine shift/subtract, apply the mask and return the
natural-number value directly. The existing `payloadWordBits` helper is inlined;
the `BitVec.ofNatLT` bound proof is erased. No natural power, division, modulus
or generic `BitVec.ofNat` call remains in this narrow C branch.

Widths at least 64 retain the original formula: natural power and division,
followed by `BitVec.ofNat` with its original modular reduction. This fallback
has no bounded-width or bounded-word assumption. The universal `field_eq` and
`field_eq_old` statements quantify all four natural-number inputs without
hypotheses. The integrated build checks them and eight kernel witnesses for
widths 0, 63, 64 and 80, cross-word extraction, shifts above 64 and both
subtraction-underflow cases. The complete decoder refinement calls the new
field equality and retains only the three permitted axioms.

The linked CLI retains a callable `field` at `0xb4b3f0`. The actual width guard
uses tagged 64 (`0x81`) and routes to the narrow entry at `0xb4b414` or wide
entry at `0xb4b524`; big natural widths use the corresponding runtime comparison.
The narrow path has the original exact natural shift, including its big-Nat
runtime branch. Its small-Nat shift has the explicit large-count guard and
conditional zero result. The subsequent mask is `shl`, `not`, `and`, followed
by tagged-Nat construction. `field-control-flow.json` records conservative
intraprocedural reachability from both actual guard successors: every narrow
return passes the exact-shift operation, no narrow path reaches power,
division or the generic BitVec constructor, and the wide path retains those
operations. Ordinary callees are assumed to return. This is a static structure
check, not runtime testing or a replacement for the proof.

The actual `decodeFrame` assembly contains 26 static call sites to this same
live `field`; these are call sites, not per-message call counts. `decode`
continues calling `decodeFrame` and one shared syndrome before the same report
path. The frozen whole-message/direct-register adapters and benchmark worker
retain their live entrypoints. No legacy field implementation was added.

The other 19 production source/C/object/trace sets match gen8 exactly. They
include parity, frame parsing, semantic interpretation, affine payload values,
Comm-B tables, the integer score gate and software binary64. The unchanged
score entrypoint still calls the integer gate, and its lazy callback retains
the full software density/penalty/addition/comparison sequence. The unchanged
`bytesValue` and `packFields` folds in the edited Bits module also match their
prior generated bodies under local-variable renaming.

All 104 locked hashes match; `TRUSTED.md`, `lakefile.toml` and `spec.lock` match
the parent commit. Compiler flags retain `-O3` and `-ffp-contract=off`. The only
runtime import change reuses the existing pure payload-mask module. No FFI,
trusted primitive, mutable cache or cross-message state was introduced.

`inspection-inputs.json` binds the successful build, exact input hashes and
all executed `nm`/`objdump`/read-only git commands. `review.json` inventories
these retained sources, C, traces and disassemblies. Capture and checks passed
on their first execution; the initial review before this README was added is
preserved separately. No build, native decoder, test campaign, profile or
benchmark ran during this review. Future diagnostics must bind the freshly
timed worker and measure actual field/shift/convert contexts, preserving the
wide fallback and existing shared-CRC/integer-gate population checks.
