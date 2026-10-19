import Impl.Message

/-!
Per-frame syndrome sharing preserves the previous public function bodies by
definitional equality. These statements cover every Frame and byte list, with
no acceptance, length, parity or corpus assumption. Strict evaluation may do
the pure CRC calculation before a later rejection; it cannot change a result.
-/

namespace Lean1090.Proofs.SyndromeReuse
open Spec

/-- The standalone acceptance API delegates to the live shared helper. -/
theorem frameAccepted_canonical (f : Frame) :
    Impl.frameAcceptedWithSyndrome f (Impl.frameSyndrome f) = Impl.frameAccepted f := rfl

/-- The standalone address API delegates to the live shared helper. -/
theorem frameAddress_canonical (f : Frame) :
    Impl.frameAddressWithSyndrome f (Impl.frameSyndrome f) = Impl.frameAddress f := rfl

/-- The standalone report API delegates to the live shared helper. -/
theorem report_canonical (f : Frame) :
    Impl.reportWithSyndrome f (Impl.frameSyndrome f) = Impl.report f := rfl

/-- Exact previous acceptance expression for every frame assignment. -/
theorem frameAccepted_old (f : Frame) :
    Impl.frameAccepted f =
      match f.body with
      | .extended supplementary _ _ me =>
          Impl.adsbHardValid me.toNat && (supplementary || Impl.frameSyndrome f == 0)
      | _ => true := rfl

/-- Exact previous address expression for every frame assignment. -/
theorem frameAddress_old (f : Frame) :
    Impl.frameAddress f =
      match f.body with
      | .allCall _ aa | .extended _ _ aa _ => some aa
      | .military _ _ => none
      | _ => some (Impl.frameSyndrome f) := rfl

/-- Every original report field and inference call remains unchanged. -/
theorem report_old (f : Frame) :
    Impl.report f =
      ⟨Impl.frameSyndrome f, Impl.frameAddress f,
       (match f.body with
        | .allCall _ _ => Impl.Parity.interrogator (Impl.frameSyndrome f)
        | _ => none),
       Impl.frameAltitude f, Impl.frameIdentity f, Impl.frameADSB f, Impl.frameCommB f,
       (match f.body with
        | .extended _ _ _ me => some (Impl.Semantics.adsb me.toNat)
        | _ => none),
       (match f.body with
        | .commB _ _ mb => (Impl.frameCommB f).map fun (reg, _) =>
            (reg, Impl.Semantics.commB reg mb.toNat)
        | _ => [])⟩ := rfl

/-- Shared evaluation equals the previous decoder body on every byte input. -/
theorem decode_old (bytes : List UInt8) :
    Impl.decode bytes = (do
      let f ← Impl.decodeFrame bytes
      if Impl.frameAccepted f then some ⟨f, Impl.report f⟩ else none) := rfl

/-- Empty input still fails before frame-dependent computation. -/
theorem empty_input_witness : Impl.decode [] = none := rfl

/-- A truncated extended squitter still fails before frame-dependent computation. -/
theorem truncated_input_witness : Impl.decode [0x88] = none := by
  decide +kernel

/-- A complete DF17 frame with incorrect parity still fails acceptance. -/
theorem bad_parity_witness :
    Impl.decode [0x88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] = none := by
  decide +kernel

#print axioms frameAccepted_canonical
#print axioms frameAddress_canonical
#print axioms report_canonical
#print axioms frameAccepted_old
#print axioms frameAddress_old
#print axioms report_old
#print axioms decode_old
#print axioms empty_input_witness
#print axioms truncated_input_witness
#print axioms bad_parity_witness

end Lean1090.Proofs.SyndromeReuse
