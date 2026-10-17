import Spec.CommB
import Model.BDS50

namespace Lean1090.Spec

/-- Complete reference result: directly decoded field codes, every output
quantity, and the binary64 score used by the rs1090-derived candidate policy. -/
def bds50Reference (word : Nat) : Option Model.BDS50.Result :=
  if Spec.commBEligible 20 none 0x50 word then
    (Spec.decodeBDS 0x50 word).map fun p =>
      ⟨p.fields.map (fun f => (f.name, f.code)),
       Spec.commBValue 0x50 word "roll", Spec.commBValue 0x50 word "track",
       Spec.commBValue 0x50 word "groundspeed", Spec.commBValue 0x50 word "track_rate",
       Spec.commBValue 0x50 word "TAS", Spec.cbCombinedScore 0x50 word⟩
  else none


end Lean1090.Spec
