import Impl.CPRFloat
import Lean.Data.Json

/-! Unfrozen generation-18 equivalence probe. No timing or trusted primitive.
Inputs and seed are recorded separately before execution. -/
namespace Lean1090.Diagnostics.Gen18FloatProbe
open Lean

private def hashBytes (h : UInt64) (bytes : ByteArray) : UInt64 :=
  bytes.data.foldl (fun v b => (v ^^^ b.toUInt64) * 1099511628211) h

private def classify (value : Rat) : String :=
  if value.num == 0 then "zero" else
  if value.num.natAbs < 2^53 ∧ value.den.log2 ≤ 1074 ∧
      value.den = 1 <<< value.den.log2 then "fast" else "fallback"

end Lean1090.Diagnostics.Gen18FloatProbe

open Lean Lean1090.Diagnostics.Gen18FloatProbe

def main (args : List String) : IO UInt32 := do
  let [input, failures] := args
    | throw (IO.userError "expected input.tsv failures.jsonl")
  let text ← IO.FS.readFile input
  let failureStream ← IO.FS.Handle.mk failures IO.FS.Mode.write
  let mut count := 0
  let mut mismatches := 0
  let mut zero := 0
  let mut fast := 0
  let mut fallbackCount := 0
  let mut finiteChecks := 0
  let mut digest : UInt64 := 14695981039346656037
  for line in text.splitOn "\n" do
    if line.isEmpty then continue
    let [label, numerator, denominator, originalBits, branch] := line.splitOn "\t"
      | throw (IO.userError "malformed five-field probe row")
    let some n := numerator.toInt? | throw (IO.userError "invalid numerator")
    let some d := denominator.toNat? | throw (IO.userError "invalid denominator")
    if d == 0 then throw (IO.userError "zero denominator")
    let value : Rat := (n : Rat) / (d : Rat)
    let actual := (Lean1090.Impl.CPR.Policy.toFloat value).toBits.toNat
    let reference := (Lean1090.Impl.CPR.Policy.toFloatFallback value).toBits.toNat
    let gotBranch := Lean1090.Diagnostics.Gen18FloatProbe.classify value
    let mut expected := actual
    let mut finiteExact := true
    if originalBits != "-" then
      let some bits := originalBits.toNat? | throw (IO.userError "invalid finite bits")
      if bits ≥ 2^64 || bits / 2^52 % 2048 == 2047 then
        throw (IO.userError "nonfinite or oversized finite-bit witness")
      -- Rational zero has no negative sign; the frozen conversion returns +0.
      expected := if value == 0 then 0 else bits
      finiteExact := Lean1090.Impl.Binary64.fromBits bits.toUInt64.toBitVec == some value
      finiteChecks := finiteChecks + 1
    count := count + 1
    if gotBranch == "zero" then zero := zero + 1
    else if gotBranch == "fast" then fast := fast + 1
    else fallbackCount := fallbackCount + 1
    digest := Lean1090.Diagnostics.Gen18FloatProbe.hashBytes digest
      s!"{label}\t{numerator}\t{denominator}\t{actual}\t{reference}\n".toUTF8
    if actual != reference || actual != expected || gotBranch != branch || !finiteExact then
      mismatches := mismatches + 1
      failureStream.putStrLn (Json.mkObj [("label",toJson label),("numerator",toJson numerator),
        ("denominator",toJson denominator),("actual_bits",toJson actual),
        ("fallback_bits",toJson reference),("expected_bits",toJson expected),
        ("expected_branch",toJson branch),("actual_branch",toJson gotBranch),
        ("finite_fromBits_exact",toJson finiteExact)]).compress
  failureStream.flush
  IO.println (Json.mkObj [("status",toJson (if mismatches == 0 then "passed" else "failed")),
    ("cases",toJson count),("finite_bit_checks",toJson finiteChecks),
    ("zero_cases",toJson zero),("fast_cases",toJson fast),("fallback_cases",toJson fallbackCount),
    ("mismatches",toJson mismatches),("output_fnv1a64_decimal",toJson digest.toNat),
    ("timing_measurement",toJson false)]).compress
  return if mismatches == 0 then 0 else 1
