# Generation 8 static native review

All 39 checks pass against the successful integrated build. The captured CLI
SHA-256 is `cc682e295fa090b4ac315217c2b823c51d6ad3027a3bef84c2445f594a1f5632`.
The integration log SHA-256 is
`d865140a4d07e6f7dc9e9b749d37390d87f4fe875f1388210fc98f9b18b1645a`.
All 137 captured inputs remain unchanged, including the current proof-source
inventory and 21 CLI-linked project source/C/object/trace sets. This review
does not claim to inspect the future freshly rebuilt benchmark worker.

The actual `payloadValue` generated C starts at
`retained/.lake/build/ir/Impl/PayloadBits.c:385`. Its original status check still
returns `none` before field extraction, integer interpretation and affine
arithmetic. The present branch uses the same word, start, width and coding.
The `payloadBits`, `payloadInteger` and `decodePayloadFields` C bodies are
unchanged under bijective local-variable renaming.

`affineValue` is inlined into this live function. The scale comparison at C
line 461 tests exact rational equality to one. Its unequal branch keeps
`Rat.ofInt` then `Rat.mul`; the equal branch uses only the integer conversion.
The offset comparison at line 435 tests exact rational equality to zero.
Its unequal branch keeps `Rat.add`; the equal branch wraps the existing scaled
value directly. Nonidentity multiplication still precedes nonzero addition.
The standalone affine helper remains in the object but is absent from the
linked CLI; this is inlining, not evidence that affine computation costs zero.

Linked `payloadValue` has one `Rat.mul` call site at `0xb4f162` and one
`Rat.add` site at `0xb4f1f6`. The retained assembly loads the column's scale into
`r14` and offset into `rbx`, then passes them to the exact rational equality
tests. Warm and cold literal-initialization paths each retain those tests.
`payloadValue-control-flow.json` records a conservative direct-branch traversal
with only these actual equality outcomes fixed:

| Scale equals one | Offset equals zero | Multiplications on a present result | Additions on a present result |
|---|---|---:|---:|
| No | No | 1 | 1 |
| No | Yes | 1 | 0 |
| Yes | No | 0 | 1 |
| Yes | Yes | 0 | 0 |

For every combination, the rejected-status path has zero integer-value,
multiplication and addition calls. This static traversal treats ordinary
callees as returning and explores other branches conservatively. It does not
execute inputs or replace the universal `affineValue_eq` and
`payloadValue_eq` proofs. The constants stored in compiler lazy cells are only
the exact rational identities zero and one; there is no message-keyed state.

The actual ADS-B and Comm-B semantic paths call the same native table-map
helper, which calls live `payloadValue`. Report/decode and the frozen direct
register and whole-message adapters retain their existing live entrypoints.
The complete benchmark still calls `Impl.decode` with its output construction.

All other 19 reused production source/C/object/trace sets match gen7,
including Comm-B, the immutable density and Mach tables, the integer score
gate and software binary64. The score entrypoint still calls the integer
gate, and the boxed lazy callback still contains the original density,
penalty, software addition and rational threshold comparison. All 104 locked
hashes match. `TRUSTED.md`, `lakefile.toml` and `spec.lock` match the parent
commit; `-O3` and `-ffp-contract=off` are unchanged. No FFI or runtime import
was added.

`inspection-inputs.json` retains input hashes, executed capture commands and
the successful build binding. `review.json` inventories the retained source,
C, trace and actual object/linked disassemblies. Capture and validation passed
on their first execution. No build, native decoder, test campaign, profile or
benchmark was run by this review. The next cost diagnostic must count live
`payloadValue` and its guarded arithmetic descendants by caller context,
without treating the missing inline wrapper as an absent computation.
