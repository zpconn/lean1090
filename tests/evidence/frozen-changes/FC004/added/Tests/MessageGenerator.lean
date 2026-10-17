import Spec.Message

/-! Deterministic full-message differential inputs from independently assigned
fields and Spec.encode, with valid parity and explicit corruption strata.
ADSB records are generated from every frozen canonical layout. Rejected payload
assignments are retained rather than silently resampled. -/
namespace Lean1090.Tests.MessageGenerator
open Spec

private def next (seed : UInt64) : UInt64 := seed * 6364136223846793005 + 1442695040888963407
private def draw (seed : UInt64) : Nat :=
  let z := (seed ^^^ (seed >>> 30)) * 0xbf58476d1ce4e5b9
  let z := (z ^^^ (z >>> 27)) * 0x94d049bb133111eb
  (z ^^^ (z >>> 31)).toNat
private def sample (width : Nat) : StateM UInt64 (BitVec width) := do
  let seed ← get
  set (next seed)
  return BitVec.ofNat width (draw seed * 2^64 + draw (next seed))

private def acas : StateM UInt64 ACASFields := do
  return ⟨← sample 1, ← sample 1, ← sample 1, ← sample 3,
    ← sample 2, ← sample 4, ← sample 2, ← sample 13⟩
private def surveillance : StateM UInt64 SurveillanceFields := do
  return ⟨← sample 3, ← sample 5, ← sample 6, ← sample 13⟩
private def emptyReport : Report := ⟨0,none,none,none,none,none,[],none,[]⟩

private def randomADSB (kind : Nat) (narrow : Bool) : StateM UInt64 (BitVec 56) := do
  let columns := (adsbLayoutOfKind kind).getD []
  let mut fields := []
  for c in columns do
    let code ← sample c.width
    let code := if c.name == "tc" then kind / 64
      else if c.name == "subtype" then kind / 8 % 8
      else if c.name == "version" then kind % 8
      else if narrow && (c.name.toLower.splitOn "reserved").length > 1 then 0
      else if narrow && c.name == "altitude_code" then
        -- Quantized 25-foot levels from -1000 through 49975 feet.
        let count := code.toNat % 2040
        count / 16 * 32 + 16 + count % 16
      else code.toNat
    fields := fields ++ [⟨c.name, code⟩]
  return BitVec.ofNat 56 (encodeADSB ⟨kind, fields⟩)

private def body (index kind : Nat) : StateM UInt64 FrameBody := do
  match index % 11 with
  | 0 => return .shortACAS (← acas)
  | 1 => return .surveillance false (← surveillance)
  | 2 => return .surveillance true (← surveillance)
  | 3 => return .allCall (← sample 3) (← sample 24)
  | 4 => return .longACAS (← acas) (← sample 56)
  | 5 => return .extended false (← sample 3) (← sample 24) (← randomADSB kind (index % 3 != 0))
  | 6 => return .extended true (← sample 3) (← sample 24) (← randomADSB kind (index % 3 != 0))
  | 7 => return .military (← sample 3) (← sample 80)
  | 8 => return .commB false (← surveillance) (← sample 56)
  | 9 => return .commB true (← surveillance) (← sample 56)
  | _ => return .commD (← sample 1) (← sample 1) (← sample 4) (← sample 80)

private def hexByte (byte : UInt8) : String :=
  let digits := "0123456789abcdef".toList.toArray
  String.ofList [digits[byte.toNat / 16]?.getD '0', digits[byte.toNat % 16]?.getD '0']
private def flip (bytes : List UInt8) (bit : Nat) : List UInt8 :=
  bytes.zipIdx |>.map fun (byte, index) =>
    if index == bit / 8 then byte ^^^ (1 <<< (bit % 8).toUInt8) else byte

def run (path : String) (count seed : Nat) : IO Unit := do
  let out ← IO.FS.Handle.mk path .write
  let kinds := ((adsbWitnessWords.map adsbKind).eraseDups).toArray
  let mut state := seed.toUInt64
  out.putStrLn "index\tstratum\tfamily\tlayout\thex"
  for i in [:count] do
    let kind := kinds[(i/11) % kinds.size]?.getD 0
    let (b, s) := (body i kind).run state
    state := s
    let (overlay, s) := (sample 24).run state
    state := s
    let overlay := if i % 11 == 5 then 0 else overlay
    let f := withOverlay b overlay
    let bytes := encode ⟨f, emptyReport⟩
    let phase := i/770 % 4
    let (bytes, tag) := if phase == 1 then
        (flip bytes (draw state % (bytes.length*8)), "one_bit_corruption")
      else if phase == 2 then
        (let first := draw state % (bytes.length*8)
         let second := (first + 1 + draw (next state) % (bytes.length*8-1)) % (bytes.length*8)
         flip (flip bytes first) second, "two_bit_corruption")
      else (bytes, "encoded_fields")
    state := next state
    out.putStrLn s!"{i}\t{tag}\t{i%11}\t{kind}\t{String.join (bytes.map hexByte)}"
  out.flush
  IO.eprintln s!"Generated {count} independently assigned encoded/corrupted messages; seed {seed}."

end Lean1090.Tests.MessageGenerator

def main (args : List String) : IO Unit :=
  match args with
  | [path,count,seed] => Lean1090.Tests.MessageGenerator.run path
      (count.toNat?.getD 100000) (seed.toNat?.getD 1085632)
  | _ => throw (IO.userError "usage: messageGenerator output.tsv count seed")
