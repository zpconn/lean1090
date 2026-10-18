import Impl
import Lean.Data.Json.Parser
import Lean.Data.Json.FromToJson.Basic

/-! Diagnostic driver only. It links the unchanged production object files and
calls Impl.decode once per selected corpus row. There are no clocks or alternate
decoders. Repr hashing, census replay, printing and input preparation occur
outside the collected Impl.decode call tree. This is not a benchmark worker. -/
namespace Lean1090.Diagnostics.DecodeCosts
open Lean

private structure Input where
  df : Nat
  bytes : List UInt8

private def nibble (c : Char) : Option Nat :=
  if '0' ≤ c && c ≤ '9' then some (c.toNat - 48)
  else if 'a' ≤ c && c ≤ 'f' then some (c.toNat - 87)
  else if 'A' ≤ c && c ≤ 'F' then some (c.toNat - 55) else none

private def hexBytes : List Char → Option (List UInt8)
  | [] => some []
  | a :: b :: rest => do
      return ((← nibble a) * 16 + (← nibble b)).toUInt8 :: (← hexBytes rest)
  | _ => none

private def loadInputs (path : String) : IO (Array Input) := do
  let text ← IO.FS.readFile path
  let lines := text.splitOn "\n"
  let mut inputs := Array.mkEmpty 172432
  for (line, index) in lines.zipIdx do
    if line.isEmpty && index + 1 == lines.length then continue
    let row := if line.endsWith "\r" then line.dropEnd 1 |>.toString else line
    let [_, beast] := row.splitOn ","
      | throw (IO.userError s!"row {index + 1}: expected timestamp,frame")
    if beast.length < 18 then throw (IO.userError "missing Beast prefix")
    let hexadecimal := beast.toList.drop 18
    if hexadecimal.length != 14 && hexadecimal.length != 28 then
      throw (IO.userError "expected 7 or 14 message bytes")
    let some bytes := hexBytes hexadecimal
      | throw (IO.userError "invalid hexadecimal digit")
    let some first := bytes.head? | throw (IO.userError "empty message")
    inputs := inputs.push ⟨first.toNat / 8, bytes⟩
  if inputs.size != 172432 then
    throw (IO.userError s!"expected full 172432-row corpus, found {inputs.size}")
  return inputs

private def emit (value : Json) : IO Unit := do
  IO.println value.compress
  (← IO.getStdout).flush

private def select (mode : String) : Except String (Nat → Bool) := do
  match mode with
  | "all" => return fun _ => true
  | "adsb" => return fun df => df == 17 || df == 18
  | "commb" => return fun df => df == 20 || df == 21
  | "other" => return fun df => ![17,18,20,21].contains df
  | _ =>
    if mode.startsWith "df" then
      let some df := (mode.drop 2).toString.toNat?
        | throw "invalid DF number"
      if df ≥ 32 then throw "DF must be 0..31"
      return fun n => n == df
    else throw "mode must be all, adsb, commb, other, df0..df31, or score40/44/45/50/60"

private def scoreRegister (mode : String) : Option Nat :=
  match mode with
  | "score40" => some 0x40 | "score44" => some 0x44 | "score45" => some 0x45
  | "score50" => some 0x50 | "score60" => some 0x60 | _ => none

private def command (enabled : Bool) (expected : String) : IO Unit := do
  if enabled then
    let line ← (← IO.getStdin).getLine
    if line.trimAscii.toString != expected then
      throw (IO.userError s!"expected diagnostic command: {expected}")

private def offsetBasis : UInt64 := 14695981039346656037
private def prime : UInt64 := 1099511628211

private def hashBytes (hash : UInt64) (bytes : ByteArray) : UInt64 :=
  bytes.data.foldl (fun h b => (h ^^^ b.toUInt64) * prime) hash

private structure Digest where
  count : Nat := 0
  bytes : Nat := 0
  value : UInt64 := offsetBasis

private def extend (digest : Digest) (bytes : ByteArray) : Digest :=
  ⟨digest.count + 1, digest.bytes + bytes.size, hashBytes digest.value bytes⟩

/-- Consume every field, including standard/oracle values and FloatExpr trees.
The delimiter prevents concatenated records from losing their boundary. This
checksum is an observability/cross-run check, not a cryptographic assertion. -/
@[noinline] private def consume (inputs : Array Input) (output : Array Spec.Message) :
    IO (Digest × Array Digest) := do
  if output.size != inputs.size then throw (IO.userError "incomplete retained output")
  let mut total : Digest := {}
  let mut byDF := Array.replicate 32 ({} : Digest)
  for h : i in [:output.size] do
    let some input := inputs[i]? | throw (IO.userError "missing retained input")
    let bytes := (reprStr output[i] ++ "\n").toUTF8
    total := extend total bytes
    byDF := byDF.modify input.df (fun digest => extend digest bytes)
  if (byDF.toList.map (·.count)).sum != output.size then
    throw (IO.userError "DF digest cardinality mismatch")
  return (total, byDF)

private def digestJson (digest : Digest) : Json := Json.mkObj [
  ("count", toJson digest.count), ("repr_bytes", toJson digest.bytes),
  ("fnv1a64_decimal", toJson digest.value.toNat)]

/-- Exactly the production decoder and complete-array append. Heartbeats count
small allocations in this loop, including the append, not time or bytes. -/
@[noinline] private def runDecode (inputs : Array Input) : IO (Array Spec.Message × Nat) := do
  let mut output : Array Spec.Message := Array.mkEmpty inputs.size
  let start ← IO.getNumHeartbeats
  for input in inputs do
    let some message := Impl.decode input.bytes
      | throw (IO.userError s!"decoder rejected corpus DF{input.df}")
    output := output.push message
  let finish ← IO.getNumHeartbeats
  return (output, finish - start)

private def bump (values : List (Nat × Nat)) (key : Nat) : List (Nat × Nat) :=
  match values with
  | [] => [(key, 1)]
  | (k, n) :: rest => if k == key then (k, n+1) :: rest else (k,n) :: bump rest key

private def scored : List Nat := [0x40,0x44,0x45,0x50,0x60]

private structure RegisterCensus where
  nonempty : Nat := 0
  hardAttempts : Nat := 0
  hardPass : Nat := 0
  scoreAttempts : Nat := 0
  scorePass : Nat := 0
  eligible : Nat := 0
  accepted : Nat := 0

/-- Untimed shadow census, checked against each actual returned candidate set.
An entry predicts how many live predicate calls its control flow reached; it
does not claim to be an instrumented count of native function entries. -/
private def registerCensus (df register : Nat) (messages : List Spec.Message) :
    IO RegisterCensus := do
  let mut count : RegisterCensus := {}
  for message in messages do
    let .commB _ _ mb := message.fields.body
      | throw (IO.userError "Comm-B census received a different DF")
    let word := mb.toNat
    let nonempty := word != 0
    let tc := Impl.payloadBits word 1 5
    let hardAttempt := nonempty &&
      (if register == 0x05 then df == 20 && tc ≥ 9 && tc < 22 && tc != 19
       else register != 0x65)
    let hardPass := hardAttempt && Impl.bdsWireValid register word
    let scoreAttempt := hardPass && scored.contains register
    let scorePass := scoreAttempt && Impl.cbScorePasses register word
    let eligible := hardPass &&
      (if register == 0x05 then decide (Impl.adsbAltitude word = Impl.frameOracleAltitude message.fields)
       else if scored.contains register then scorePass else true)
    let accepted := message.decoded.commB.any (fun entry => entry.1 == register)
    if eligible != accepted then
      throw (IO.userError s!"census shadow disagrees: DF{df} register={register} word={word}")
    count := ⟨count.nonempty + nonempty.toNat,
      count.hardAttempts + hardAttempt.toNat,
      count.hardPass + hardPass.toNat,
      count.scoreAttempts + scoreAttempt.toNat,
      count.scorePass + scorePass.toNat,
      count.eligible + eligible.toNat,
      count.accepted + accepted.toNat⟩
  return count

private def census (inputs : Array Input) (output : Array Spec.Message) : IO Json := do
  let mut rows := []
  for df in List.range 32 do
    let mut messages := []
    for h : i in [:output.size] do
      let some input := inputs[i]? | throw (IO.userError "missing census input")
      if input.df == df then messages := output[i] :: messages
    let mut branches := []
    for message in messages do
      if let some payload := message.decoded.adsb then branches := bump branches payload.kind
    let mut registers := []
    if df == 20 || df == 21 then
      for register in Impl.commBRegisters do
        let c ← registerCensus df register messages
        registers := registers ++ [Json.mkObj [
          ("register_decimal", toJson register), ("eligibility_slots", toJson messages.length),
          ("nonempty", toJson c.nonempty), ("hard_attempt_predictions", toJson c.hardAttempts),
          ("hard_pass", toJson c.hardPass), ("score_attempt_predictions", toJson c.scoreAttempts),
          ("score_pass", toJson c.scorePass), ("eligible", toJson c.eligible),
          ("accepted", toJson c.accepted), ("decodeBDS_recheck_predictions", toJson c.accepted)]]
    let crcPerMessage := if [0,4,5,16,17,20,21,24,25,26,27,28,29,30,31].contains df then 2 else 1
    rows := rows ++ [Json.mkObj [
      ("df", toJson df), ("count", toJson messages.length),
      ("decodeFrame_call_predictions", toJson messages.length),
      ("crc_call_predictions", toJson (messages.length * crcPerMessage)),
      ("adsbHardValid_call_predictions", toJson (if df == 17 || df == 18 then messages.length * 2 else 0)),
      ("adsb_accepted", toJson ((branches.map (·.2)).sum)),
      ("adsb_payload_kinds", toJson ((branches.mergeSort (fun a b => a.1 ≤ b.1)).map
        (fun (kind, count) => Json.mkObj [("kind", toJson kind), ("count", toJson count)]))),
      ("commb", toJson registers)]]
  return Json.mkObj [("kind", .str "post_decode_shadow_census"),
    ("native_call_counts", .bool false), ("per_df", toJson rows)]

private def decodeMode (mode : String) (inputs : Array Input) (withCensus wait : Bool) : IO Unit := do
  let predicate ← IO.ofExcept (select mode)
  let inputs := inputs.filter (fun input => predicate input.df)
  emit (Json.mkObj [("phase", .str "prepared"), ("mode", .str mode),
    ("selected", toJson inputs.size), ("corpus_rows", toJson (172432 : Nat))])
  command wait "run"
  let (output, heartbeats) ← runDecode inputs
  emit (Json.mkObj [("phase", .str "decoded"), ("mode", .str mode),
    ("retained", toJson output.size), ("loop_small_allocations", toJson heartbeats)])
  command wait "consume"
  let (total, perDF) ← consume inputs output
  emit (Json.mkObj [("phase", .str "result"), ("mode", .str mode),
    ("digest", digestJson total), ("per_df", toJson (perDF.toList.zipIdx.map
      (fun (digest, df) => Json.mkObj [("df", toJson df), ("digest", digestJson digest)]))),
    ("loop_small_allocations", toJson heartbeats)])
  if withCensus then emit (← census inputs output)

private structure ScoreInput where
  df : Nat
  word : Nat

/-- All selection and hard validity work precedes the score collection root. -/
private def prepareScores (inputs : Array Input) (register : Nat) : IO (Array ScoreInput × Nat) := do
  let mut selected := #[]
  let mut nonempty := 0
  for input in inputs do
    if input.df != 20 && input.df != 21 then continue
    let some frame := Impl.decodeFrame input.bytes | throw (IO.userError "score frame rejected")
    let .commB _ _ mb := frame.body | throw (IO.userError "score expected Comm-B")
    if mb.toNat == 0 then continue
    nonempty := nonempty + 1
    if Impl.bdsWireValid register mb.toNat then selected := selected.push ⟨input.df, mb.toNat⟩
  return (selected, nonempty)

@[noinline] private def runScores (register : Nat) (inputs : Array ScoreInput) : IO (Array Bool × Nat) := do
  let mut output := Array.mkEmpty inputs.size
  let start ← IO.getNumHeartbeats
  for input in inputs do output := output.push (Impl.cbScorePasses register input.word)
  let finish ← IO.getNumHeartbeats
  return (output, finish - start)

private def scoreMode (mode : String) (register : Nat) (inputs : Array Input) (wait : Bool) : IO Unit := do
  let (inputs, nonempty) ← prepareScores inputs register
  emit (Json.mkObj [("phase", .str "prepared"), ("mode", .str mode),
    ("selected", toJson inputs.size), ("nonempty_commb", toJson nonempty),
    ("non_additive_probe", .bool true)])
  command wait "run"
  let (output, heartbeats) ← runScores register inputs
  emit (Json.mkObj [("phase", .str "decoded"), ("mode", .str mode),
    ("retained", toJson output.size), ("loop_small_allocations", toJson heartbeats)])
  command wait "consume"
  if output.size != inputs.size then throw (IO.userError "incomplete retained scores")
  let mut digest : Digest := {}
  let mut passes := 0
  let mut df20 := 0
  for h : i in [:output.size] do
    let some input := inputs[i]? | throw (IO.userError "missing score input")
    digest := extend digest (s!"{input.df}:{input.word}:{output[i]}\n").toUTF8
    passes := passes + output[i].toNat
    df20 := df20 + (input.df == 20).toNat
  emit (Json.mkObj [("phase", .str "result"), ("mode", .str mode),
    ("register_decimal", toJson register), ("non_additive_probe", .bool true),
    ("digest", digestJson digest), ("passes", toJson passes),
    ("df20", toJson df20), ("df21", toJson (inputs.size - df20)),
    ("loop_small_allocations", toJson heartbeats)])

def execute (args : List String) : IO Unit := do
  let mode :: path :: flags := args
    | throw (IO.userError "usage: decode-costs MODE CORPUS [--census] [--wait]")
  if flags.any (fun flag => flag != "--census" && flag != "--wait") then
    throw (IO.userError "unknown diagnostic flag")
  let inputs ← loadInputs path
  if let some register := scoreRegister mode then
    if flags.contains "--census" then throw (IO.userError "--census is for whole-decode modes")
    scoreMode mode register inputs (flags.contains "--wait")
  else decodeMode mode inputs (flags.contains "--census") (flags.contains "--wait")

end Lean1090.Diagnostics.DecodeCosts

def main (args : List String) : IO Unit := Lean1090.Diagnostics.DecodeCosts.execute args
