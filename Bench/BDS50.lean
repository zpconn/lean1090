import Impl.BDS50

open Lean1090

private def loadWords (path : String) : IO (Array Nat) := do
  let text ← IO.FS.readFile path
  let mut values := #[]
  for line in text.splitOn "\n" do
    if !line.isEmpty then
      match line.toNat? with
      | none => throw (IO.userError "invalid decimal MB word")
      | some n =>
        if n ≥ 2^56 then throw (IO.userError "MB word wider than 56 bits")
        values := values.push n
  return values

private def rational (x : Option Rat) : String :=
  match x with
  | none => "none"
  | some x => s!"{x.num}/{x.den}"

private def runOnce (inputs : Array Nat) : IO Unit := do
  let mut output : Array (Option Model.BDS50.Result) := Array.mkEmpty inputs.size
  let start ← IO.monoNanosNow
  for word in inputs do
    output := output.push (Impl.BDS50.decode word)
  let finish ← IO.monoNanosNow
  let accepted := output.foldl (fun n v => if v.isSome then n+1 else n) 0
  IO.println s!"{finish-start} {accepted}"
  (← IO.getStdout).flush

private def worker (inputs : Array Nat) : IO Unit := do
  IO.println s!"ready {inputs.size}"
  (← IO.getStdout).flush
  let stdin ← IO.getStdin
  repeat
    let line ← stdin.getLine
    if line.isEmpty || line.trimAscii.toString == "quit" then break
    runOnce inputs

def main (args : List String) : IO UInt32 := do
  match args with
  | [mode, path] =>
    let values ← loadWords path
    if mode == "--worker" then worker values
    else if mode == "--audit" then
      for word in values do
        if word == 0 || !Impl.BDS50.wireValid word then IO.println "hard-reject"
        else
          let score := Impl.BDS50.combinedScore word
          let flag := if score ≥ -3 then "accepted" else "score-reject"
          IO.println (String.intercalate " "
            [flag, rational (Impl.BDS50.roll word), rational (Impl.BDS50.track word),
             rational (Impl.BDS50.groundSpeed word), rational (Impl.BDS50.rate word),
             rational (Impl.BDS50.trueAirspeed word), rational (some score)])
    else if mode == "--dump" then
      for word in values do
        match Impl.BDS50.decode word with
        | none => IO.println "none"
        | some r => IO.println (String.intercalate " "
            [rational r.roll, rational r.track, rational r.groundspeed,
             rational r.trackRate, rational r.tas, rational (some r.score)])
    else throw (IO.userError "unknown mode")
    return 0
  | _ =>
    IO.eprintln "usage: lean1090-bds50 --worker|--dump|--audit WORDS.txt"
    return 2
