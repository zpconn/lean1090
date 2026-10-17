import Spec.Message
import Spec.CPR
open Lean1090.Spec

-- D009: valid DF17 frames and exact CPR endpoint behavior.
#eval Parity.syndrome 112 0x8d11223348010200000000f81a47
#eval Parity.syndrome 112 0x8d11223348010508880000d59619
#eval CPR.encode .airborne false ⟨87, 0⟩
#eval CPR.encode .airborne true ⟨87, 0⟩
#eval CPR.decodeGlobal ⟨false, 65536, 0⟩ ⟨true, 33860, 0⟩ false
