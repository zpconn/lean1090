/-! Frozen final theorem manifest. Its failure before section 4 is deliberate.
Each declaration requires the exact approved proposition; no implementation
parameter remains free. The gate compiles this file and audits these proofs.
The timed headline entrypoint is precisely Lean1090.Impl.decode.
This is an import-free declaration fragment. check_final.py places these exact
bytes after integration imports in a temporary Lean module; frozen semantic
modules never import Impl or Proofs. -/

namespace Lean1090.Final

theorem Refinement : Lean1090.Capstones.Refinement Lean1090.Impl.decode :=
  Lean1090.Proofs.Refinement
#print axioms Lean1090.Final.Refinement

theorem BDS50Refinement : Lean1090.Capstones.BDS50Refinement Lean1090.Impl.BDS50.decode :=
  Lean1090.Proofs.BDS50.refinement
#print axioms Lean1090.Final.BDS50Refinement

theorem PrefixRefinement : Lean1090.Capstones.PrefixRefinement Lean1090.Impl.decodePrefix :=
  Lean1090.Proofs.PrefixRefinement
#print axioms Lean1090.Final.PrefixRefinement

theorem MessageRoundTrips : Lean1090.Capstones.MessageRoundTrips :=
  Lean1090.Proofs.MessageRoundTrips
#print axioms Lean1090.Final.MessageRoundTrips

theorem ADSBRoundTrips : Lean1090.Capstones.ADSBRoundTrips :=
  Lean1090.Proofs.ADSBRoundTrips
#print axioms Lean1090.Final.ADSBRoundTrips

theorem FrameRoundTrips : Lean1090.Capstones.FrameRoundTrips :=
  Lean1090.Proofs.FrameRoundTrips
#print axioms Lean1090.Final.FrameRoundTrips

theorem ADSBFieldRoundTrips : Lean1090.Capstones.ADSBFieldRoundTrips :=
  Lean1090.Proofs.ADSBFieldRoundTrips
#print axioms Lean1090.Final.ADSBFieldRoundTrips

theorem CRCPolynomial : Lean1090.Capstones.CRCPolynomial :=
  Lean1090.Proofs.CRCPolynomial
#print axioms Lean1090.Final.CRCPolynomial

theorem CRCLinear : Lean1090.Capstones.CRCLinear :=
  Lean1090.Proofs.CRCLinear
#print axioms Lean1090.Final.CRCLinear

theorem CRCSingleBit : Lean1090.Capstones.CRCSingleBit :=
  Lean1090.Proofs.CRCSingleBit
#print axioms Lean1090.Final.CRCSingleBit

theorem ParityOverlay : Lean1090.Capstones.ParityOverlay :=
  Lean1090.Proofs.ParityOverlay
#print axioms Lean1090.Final.ParityOverlay

theorem AltitudeRoundTrips : Lean1090.Capstones.AltitudeRoundTrips :=
  Lean1090.Proofs.AltitudeRoundTrips
#print axioms Lean1090.Final.AltitudeRoundTrips

theorem AltitudeRejection : Lean1090.Capstones.AltitudeRejection :=
  Lean1090.Proofs.AltitudeRejection
#print axioms Lean1090.Final.AltitudeRejection

theorem CPRLocal : Lean1090.Capstones.CPRLocal :=
  Lean1090.Proofs.CPRLocal
#print axioms Lean1090.Final.CPRLocal

theorem CPRGlobal : Lean1090.Capstones.CPRGlobal :=
  Lean1090.Proofs.CPRGlobal
#print axioms Lean1090.Final.CPRGlobal

theorem CPRZoneRejection : Lean1090.Capstones.CPRZoneRejection :=
  Lean1090.Proofs.CPRZoneRejection
#print axioms Lean1090.Final.CPRZoneRejection

theorem CPRLatitudeZones : Lean1090.Capstones.CPRLatitudeZones :=
  Lean1090.Proofs.CPRLatitudeZones
#print axioms Lean1090.Final.CPRLatitudeZones

theorem CommBInference : Lean1090.Capstones.CommBInference :=
  Lean1090.Proofs.CommBInference
#print axioms Lean1090.Final.CommBInference

theorem CommBRoundTrips : Lean1090.Capstones.CommBRoundTrips :=
  Lean1090.Proofs.CommBRoundTrips
#print axioms Lean1090.Final.CommBRoundTrips

theorem CommBFieldRoundTrips : Lean1090.Capstones.CommBFieldRoundTrips :=
  Lean1090.Proofs.CommBFieldRoundTrips
#print axioms Lean1090.Final.CommBFieldRoundTrips

theorem CommBArithmetic : Lean1090.Capstones.CommBArithmetic :=
  Lean1090.Proofs.CommBArithmetic
#print axioms Lean1090.Final.CommBArithmetic

theorem CPRTrackingRefinement : Lean1090.Capstones.CPRTrackingRefinement Lean1090.Impl.decodePositions :=
  Lean1090.Proofs.CPRTrackingRefinement
#print axioms Lean1090.Final.CPRTrackingRefinement

theorem CPROutOfOrder : Lean1090.Capstones.CPROutOfOrder :=
  Lean1090.Proofs.CPROutOfOrder
#print axioms Lean1090.Final.CPROutOfOrder

end Lean1090.Final
