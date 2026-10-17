# Exhaustive altitude differential gate

Reproduce the mandatory altitude component with:

```sh
scripts/run_differential.sh --altitude-only
```

The same `scripts/check_altitude_differential.py` runs without sampling on
every complete quick/full differential invocation from `scripts/check_all.sh`.
The component-only flag explicitly does not claim a complete gate pass.

`Tests/AltitudeDifferential.lean` evaluates all 8,192 AC13 codes in DF4 and
all 4,096 AC12 codes in DF18/TC11. It checks complete `Impl.decode` results
against `Spec.decode`, both actual frame compatibility projections, the
independent assignment interpretations, and standard altitude preservation.
DF18 permits exhausting the field without introducing DF17 CRC validation;
DF4's trailing zero bits are a valid AP overlay for an arbitrary recovered
address. Python independently places each field in the wire bytes and checks
the complete coverage, order, frame consumption, acceptance, and optional
altitude against fresh calls to the pinned `rs1090::Message::from_bytes`.

There are no D010 exemptions in the compatibility comparison. All 12 negative
Gillham values in each field remain defined in the standard view and missing
in the compatibility view. All 40 negative binary25 values in each field stay
available in both views. Kernel checks include the ICAO −900ft pulse row,
Sun's −1200ft interpretation, and the negative binary25 −1000ft control.
The full DF20 corpus regression `a1000000920805003ffc0005c6e5` also checks
that the BDS05 candidate is retained when both compatibility heights are
missing; the oracle comparison is one additional message beyond the 12,288
exhaustive field codes.

Retained artifacts:

- `input.hex.gz`: all 12,288 exhaustive wire inputs followed by the DF20
  regression.
- `lean.csv.gz`: actual reference/runtime-checked acceptance, compatibility
  altitude, and standard altitude for every field code.
- `oracle.jsonl.gz`: complete fresh pinned oracle output for every input.
- `differences.json`: every compatibility mismatch (empty on success).
- `summary.json`: exact counts, commit pin, artifact hashes, and source hashes.
- `commands.log`: executed build/check/decoder commands and build output.

The Rust harness uses its locked dependencies, default rs1090 features and
the shipped `dist` settings. The driver verifies the vendor commit and rejects
tracked source changes before running. No cached oracle result is substituted
for a new run. The separate original proposal evidence in
`../altitude-proposal/` remains historical and is not used by this gate.
