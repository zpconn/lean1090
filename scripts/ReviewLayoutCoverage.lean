import Spec.StandardExamples
import Spec.StandardFullExamples

/-! Review-only enumeration of the frozen layout selectors. This file does not
change the frozen gate or count generated/non-vacuity inputs as published anchors. -/
open Lean1090.Spec

def reviewADSBKinds : List Nat :=
  (adsbWitnessWords.map adsbKind).eraseDups

example : reviewADSBKinds.length = 70 := by decide +kernel
example : commBRegisters.length = 14 := by decide +kernel

#eval IO.println ("ADSB canonical kinds: " ++ String.intercalate "," ((reviewADSBKinds.mergeSort (· ≤ ·)).map toString))
#eval IO.println ("Comm-B register numbers (decimal): " ++ String.intercalate "," (commBRegisters.map toString))
#eval IO.println "Published semantic anchors: ADS-B TC4, TC7, TC11, TC19.1, TC19.3; Comm-B 17,20,40,44,45,50,60 (hex). See docs/LAYOUT-ANCHORS.md for source proof names, exceptions, and the complete coverage map."
