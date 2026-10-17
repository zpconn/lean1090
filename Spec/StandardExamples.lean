import Spec.Message
import Spec.CPR

/-!
# Published decoding examples, checked by the Lean kernel

Sources and editorial contradictions are inventoried in docs/STANDARD-EXAMPLES.md.
Every complete source frame enters `Spec.decode` as literal bytes. Expected frame
fields are literal constants, with no encoder or decoder used to construct them.
Source semantic claims are checked separately by projections of the returned
message, because the source never supplies this project's complete Report record.
The projection helpers below only look up already-decoded fields; they do not
re-decode the frame. Numeric results remain exact before the documented Float
presentation boundary. No universal correctness claim follows from these examples.
-/
namespace Lean1090.Spec.StandardExamples

set_option maxRecDepth 100000
set_option maxHeartbeats 0

/-- Sun 2nd ed., §2.4.1, printed p.28; published message `8D451DBD9905B5018004005979C5`. -/
def quick_startBytes : List UInt8 := [0x8d, 0x45, 0x1d, 0xbd, 0x99, 0x05, 0xb5, 0x01, 0x80, 0x04, 0x00, 0x59, 0x79, 0xc5]

/-- Sun 2nd ed., §2.4.1, printed p.28: independent literal wire-field anchor. -/
theorem quick_start_frame :
    (decode quick_startBytes).map Message.fields = some ⟨.extended false 5 0x451dbd 0x9905b501800400, 0x5979c5⟩ := by
  decide +kernel

example : (decode quick_startBytes).map Message.fields =
    some ⟨.extended false 5 0x451dbd 0x9905b501800400, 0x5979c5⟩ := quick_start_frame

/-- Sun 2nd ed., §§3.5/4.3, printed pp.37–38/42–43; published message `8D4840D6202CC371C32CE0576098`. -/
def identificationBytes : List UInt8 := [0x8d, 0x48, 0x40, 0xd6, 0x20, 0x2c, 0xc3, 0x71, 0xc3, 0x2c, 0xe0, 0x57, 0x60, 0x98]

/-- Sun 2nd ed., §§3.5/4.3, printed pp.37–38/42–43: independent literal wire-field anchor. -/
theorem identification_frame :
    (decode identificationBytes).map Message.fields = some ⟨.extended false 5 0x4840d6 0x202cc371c32ce0, 0x576098⟩ := by
  decide +kernel

example : (decode identificationBytes).map Message.fields =
    some ⟨.extended false 5 0x4840d6 0x202cc371c32ce0, 0x576098⟩ := identification_frame

/-- Sun 2nd ed., §§5.3.3/5.4.4/5.5, printed pp.53–59; published message `8D40621D58C382D690C8AC2863A7`. -/
def airborne_evenBytes : List UInt8 := [0x8d, 0x40, 0x62, 0x1d, 0x58, 0xc3, 0x82, 0xd6, 0x90, 0xc8, 0xac, 0x28, 0x63, 0xa7]

/-- Sun 2nd ed., §§5.3.3/5.4.4/5.5, printed pp.53–59: independent literal wire-field anchor. -/
theorem airborne_even_frame :
    (decode airborne_evenBytes).map Message.fields = some ⟨.extended false 5 0x40621d 0x58c382d690c8ac, 0x2863a7⟩ := by
  decide +kernel

example : (decode airborne_evenBytes).map Message.fields =
    some ⟨.extended false 5 0x40621d 0x58c382d690c8ac, 0x2863a7⟩ := airborne_even_frame

/-- Sun 2nd ed., §5.3.3, printed pp.53–55; published message `8D40621D58C386435CC412692AD6`. -/
def airborne_oddBytes : List UInt8 := [0x8d, 0x40, 0x62, 0x1d, 0x58, 0xc3, 0x86, 0x43, 0x5c, 0xc4, 0x12, 0x69, 0x2a, 0xd6]

/-- Sun 2nd ed., §5.3.3, printed pp.53–55: independent literal wire-field anchor. -/
theorem airborne_odd_frame :
    (decode airborne_oddBytes).map Message.fields = some ⟨.extended false 5 0x40621d 0x58c386435cc412, 0x692ad6⟩ := by
  decide +kernel

example : (decode airborne_oddBytes).map Message.fields =
    some ⟨.extended false 5 0x40621d 0x58c386435cc412, 0x692ad6⟩ := airborne_odd_frame

/-- Sun 2nd ed., §6.4.1, printed pp.63–66; published message `8C4841753AAB238733C8CD4020B1`. -/
def surface_evenBytes : List UInt8 := [0x8c, 0x48, 0x41, 0x75, 0x3a, 0xab, 0x23, 0x87, 0x33, 0xc8, 0xcd, 0x40, 0x20, 0xb1]

/-- Sun 2nd ed., §6.4.1, printed pp.63–66: independent literal wire-field anchor. -/
theorem surface_even_frame :
    (decode surface_evenBytes).map Message.fields = some ⟨.extended false 4 0x484175 0x3aab238733c8cd, 0x4020b1⟩ := by
  decide +kernel

example : (decode surface_evenBytes).map Message.fields =
    some ⟨.extended false 4 0x484175 0x3aab238733c8cd, 0x4020b1⟩ := surface_even_frame

/-- Sun 2nd ed., §6.4.1, printed pp.63–66; published message `8C4841753A8A35323FAEBDAC702D`. -/
def surface_oddBytes : List UInt8 := [0x8c, 0x48, 0x41, 0x75, 0x3a, 0x8a, 0x35, 0x32, 0x3f, 0xae, 0xbd, 0xac, 0x70, 0x2d]

/-- Sun 2nd ed., §6.4.1, printed pp.63–66: independent literal wire-field anchor. -/
theorem surface_odd_frame :
    (decode surface_oddBytes).map Message.fields = some ⟨.extended false 4 0x484175 0x3a8a35323faebd, 0xac702d⟩ := by
  decide +kernel

example : (decode surface_oddBytes).map Message.fields =
    some ⟨.extended false 4 0x484175 0x3a8a35323faebd, 0xac702d⟩ := surface_odd_frame

/-- Sun 2nd ed., §§6.4.2–3, printed pp.66–68; published message `8C4841753A9A153237AEF0F275BE`. -/
def surface_localBytes : List UInt8 := [0x8c, 0x48, 0x41, 0x75, 0x3a, 0x9a, 0x15, 0x32, 0x37, 0xae, 0xf0, 0xf2, 0x75, 0xbe]

/-- Sun 2nd ed., §§6.4.2–3, printed pp.66–68: independent literal wire-field anchor. -/
theorem surface_local_frame :
    (decode surface_localBytes).map Message.fields = some ⟨.extended false 4 0x484175 0x3a9a153237aef0, 0xf275be⟩ := by
  decide +kernel

example : (decode surface_localBytes).map Message.fields =
    some ⟨.extended false 4 0x484175 0x3a9a153237aef0, 0xf275be⟩ := surface_local_frame

/-- Sun 2nd ed., §§7.1–3, printed pp.70–74; published message `8D485020994409940838175B284F`. -/
def velocity_groundBytes : List UInt8 := [0x8d, 0x48, 0x50, 0x20, 0x99, 0x44, 0x09, 0x94, 0x08, 0x38, 0x17, 0x5b, 0x28, 0x4f]

/-- Sun 2nd ed., §§7.1–3, printed pp.70–74: independent literal wire-field anchor. -/
theorem velocity_ground_frame :
    (decode velocity_groundBytes).map Message.fields = some ⟨.extended false 5 0x485020 0x99440994083817, 0x5b284f⟩ := by
  decide +kernel

example : (decode velocity_groundBytes).map Message.fields =
    some ⟨.extended false 5 0x485020 0x99440994083817, 0x5b284f⟩ := velocity_ground_frame

/-- Sun 2nd ed., §§7.1/7.4, printed pp.70–71/74–75; published message `8DA05F219B06B6AF189400CBC33F`. -/
def velocity_airBytes : List UInt8 := [0x8d, 0xa0, 0x5f, 0x21, 0x9b, 0x06, 0xb6, 0xaf, 0x18, 0x94, 0x00, 0xcb, 0xc3, 0x3f]

/-- Sun 2nd ed., §§7.1/7.4, printed pp.70–71/74–75: independent literal wire-field anchor. -/
theorem velocity_air_frame :
    (decode velocity_airBytes).map Message.fields = some ⟨.extended false 5 0xa05f21 0x9b06b6af189400, 0xcbc33f⟩ := by
  decide +kernel

example : (decode velocity_airBytes).map Message.fields =
    some ⟨.extended false 5 0xa05f21 0x9b06b6af189400, 0xcbc33f⟩ := velocity_air_frame

/-- Sun 2nd ed., §10.2, printed pp.91–92; published message `8D406B902015A678D4D220AA4BDA`. -/
def crc_goodBytes : List UInt8 := [0x8d, 0x40, 0x6b, 0x90, 0x20, 0x15, 0xa6, 0x78, 0xd4, 0xd2, 0x20, 0xaa, 0x4b, 0xda]

/-- Sun 2nd ed., §10.2, printed pp.91–92: independent literal wire-field anchor. -/
theorem crc_good_frame :
    (decode crc_goodBytes).map Message.fields = some ⟨.extended false 5 0x406b90 0x2015a678d4d220, 0xaa4bda⟩ := by
  decide +kernel

example : (decode crc_goodBytes).map Message.fields =
    some ⟨.extended false 5 0x406b90 0x2015a678d4d220, 0xaa4bda⟩ := crc_good_frame

/-- Sun 2nd ed., §11.3, printed pp.97–98; published message `A0001838CA380031440000F24177`. -/
def address_parityBytes : List UInt8 := [0xa0, 0x00, 0x18, 0x38, 0xca, 0x38, 0x00, 0x31, 0x44, 0x00, 0x00, 0xf2, 0x41, 0x77]

/-- Sun 2nd ed., §11.3, printed pp.97–98: independent literal wire-field anchor. -/
theorem address_parity_frame :
    (decode address_parityBytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 6200⟩ 0xca380031440000, 0xf24177⟩ := by
  decide +kernel

example : (decode address_parityBytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 6200⟩ 0xca380031440000, 0xf24177⟩ := address_parity_frame

/-- Sun 2nd ed., ch.12, printed pp.101–102; published message `5D484FDEA248F5`. -/
def all_callBytes : List UInt8 := [0x5d, 0x48, 0x4f, 0xde, 0xa2, 0x48, 0xf5]

/-- Sun 2nd ed., ch.12, printed pp.101–102: independent literal wire-field anchor. -/
theorem all_call_frame :
    (decode all_callBytes).map Message.fields = some ⟨.allCall 5 0x484fde, 0xa248f5⟩ := by
  decide +kernel

example : (decode all_callBytes).map Message.fields =
    some ⟨.allCall 5 0x484fde, 0xa248f5⟩ := all_call_frame

/-- Sun 2nd ed., §13.2, printed p.105; published message `2000171806A983`. -/
def altitudeBytes : List UInt8 := [0x20, 0x00, 0x17, 0x18, 0x06, 0xa9, 0x83]

/-- Sun 2nd ed., §13.2, printed p.105: independent literal wire-field anchor. -/
theorem altitude_frame :
    (decode altitudeBytes).map Message.fields = some ⟨.surveillance false ⟨0, 0, 0, 5912⟩, 0x06a983⟩ := by
  decide +kernel

example : (decode altitudeBytes).map Message.fields =
    some ⟨.surveillance false ⟨0, 0, 0, 5912⟩, 0x06a983⟩ := altitude_frame

/-- Sun 2nd ed., §13.3, printed pp.105–106; published message `2A00516D492B80`. -/
def identityBytes : List UInt8 := [0x2a, 0x00, 0x51, 0x6d, 0x49, 0x2b, 0x80]

/-- Sun 2nd ed., §13.3, printed pp.105–106: independent literal wire-field anchor. -/
theorem identity_frame :
    (decode identityBytes).map Message.fields = some ⟨.surveillance true ⟨2, 0, 2, 4461⟩, 0x492b80⟩ := by
  decide +kernel

example : (decode identityBytes).map Message.fields =
    some ⟨.surveillance true ⟨2, 0, 2, 4461⟩, 0x492b80⟩ := identity_frame

/-- Sun 2nd ed., §16.2, printed pp.119–120; published message `A0000638FA81C10000000081A92F`. -/
def gicbBytes : List UInt8 := [0xa0, 0x00, 0x06, 0x38, 0xfa, 0x81, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x81, 0xa9, 0x2f]

/-- Sun 2nd ed., §16.2, printed pp.119–120: independent literal wire-field anchor. -/
theorem gicb_frame :
    (decode gicbBytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 1592⟩ 0xfa81c100000000, 0x81a92f⟩ := by
  decide +kernel

example : (decode gicbBytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 1592⟩ 0xfa81c100000000, 0x81a92f⟩ := gicb_frame

/-- Sun 2nd ed., §16.3, printed pp.121–122; published message `A000083E202CC371C31DE0AA1CCF`. -/
def commb_identificationBytes : List UInt8 := [0xa0, 0x00, 0x08, 0x3e, 0x20, 0x2c, 0xc3, 0x71, 0xc3, 0x1d, 0xe0, 0xaa, 0x1c, 0xcf]

/-- Sun 2nd ed., §16.3, printed pp.121–122: independent literal wire-field anchor. -/
theorem commb_identification_frame :
    (decode commb_identificationBytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 2110⟩ 0x202cc371c31de0, 0xaa1ccf⟩ := by
  decide +kernel

example : (decode commb_identificationBytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 2110⟩ 0x202cc371c31de0, 0xaa1ccf⟩ := commb_identification_frame

/-- Sun 2nd ed., §17.1/figure17.1, printed pp.128–129; published message `A8001EBCAEE57730A80106DE1344`. -/
def selected_altitudeBytes : List UInt8 := [0xa8, 0x00, 0x1e, 0xbc, 0xae, 0xe5, 0x77, 0x30, 0xa8, 0x01, 0x06, 0xde, 0x13, 0x44]

/-- Sun 2nd ed., §17.1/figure17.1, printed pp.128–129: independent literal wire-field anchor. -/
theorem selected_altitude_frame :
    (decode selected_altitudeBytes).map Message.fields = some ⟨.commB true ⟨0, 0, 0, 7868⟩ 0xaee57730a80106, 0xde1344⟩ := by
  decide +kernel

example : (decode selected_altitudeBytes).map Message.fields =
    some ⟨.commB true ⟨0, 0, 0, 7868⟩ 0xaee57730a80106, 0xde1344⟩ := selected_altitude_frame

/-- Sun 2nd ed., §17.2/figure17.2, printed p.131; published message `A80006ACF9363D3BBF9CE98F1E1D`. -/
def track_turnBytes : List UInt8 := [0xa8, 0x00, 0x06, 0xac, 0xf9, 0x36, 0x3d, 0x3b, 0xbf, 0x9c, 0xe9, 0x8f, 0x1e, 0x1d]

/-- Sun 2nd ed., §17.2/figure17.2, printed p.131: independent literal wire-field anchor. -/
theorem track_turn_frame :
    (decode track_turnBytes).map Message.fields = some ⟨.commB true ⟨0, 0, 0, 1708⟩ 0xf9363d3bbf9ce9, 0x8f1e1d⟩ := by
  decide +kernel

example : (decode track_turnBytes).map Message.fields =
    some ⟨.commB true ⟨0, 0, 0, 1708⟩ 0xf9363d3bbf9ce9, 0x8f1e1d⟩ := track_turn_frame

/-- Sun 2nd ed., §17.3/figure17.3, printed pp.133–134; published message `A80004AAA74A072BFDEFC1D5CB4F`. -/
def heading_speedBytes : List UInt8 := [0xa8, 0x00, 0x04, 0xaa, 0xa7, 0x4a, 0x07, 0x2b, 0xfd, 0xef, 0xc1, 0xd5, 0xcb, 0x4f]

/-- Sun 2nd ed., §17.3/figure17.3, printed pp.133–134: independent literal wire-field anchor. -/
theorem heading_speed_frame :
    (decode heading_speedBytes).map Message.fields = some ⟨.commB true ⟨0, 0, 0, 1194⟩ 0xa74a072bfdefc1, 0xd5cb4f⟩ := by
  decide +kernel

example : (decode heading_speedBytes).map Message.fields =
    some ⟨.commB true ⟨0, 0, 0, 1194⟩ 0xa74a072bfdefc1, 0xd5cb4f⟩ := heading_speed_frame

/-- Sun 2nd ed., §18.1/figure18.1, printed pp.136–137; published message `A0001692185BD5CF400000DFC696`. -/
def meteo_routineBytes : List UInt8 := [0xa0, 0x00, 0x16, 0x92, 0x18, 0x5b, 0xd5, 0xcf, 0x40, 0x00, 0x00, 0xdf, 0xc6, 0x96]

/-- Sun 2nd ed., §18.1/figure18.1, printed pp.136–137: independent literal wire-field anchor. -/
theorem meteo_routine_frame :
    (decode meteo_routineBytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 5778⟩ 0x185bd5cf400000, 0xdfc696⟩ := by
  decide +kernel

example : (decode meteo_routineBytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 5778⟩ 0x185bd5cf400000, 0xdfc696⟩ := meteo_routine_frame

/-- Sun 2nd ed., §18.2/figure18.2, printed p.139; hex read visually from figure; published message `A00016920001CF400000008BD87B`. -/
def meteo_hazardBytes : List UInt8 := [0xa0, 0x00, 0x16, 0x92, 0x00, 0x01, 0xcf, 0x40, 0x00, 0x00, 0x00, 0x8b, 0xd8, 0x7b]

/-- Sun 2nd ed., §18.2/figure18.2, printed p.139; hex read visually from figure: independent literal wire-field anchor. -/
theorem meteo_hazard_frame :
    (decode meteo_hazardBytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 5778⟩ 0x0001cf40000000, 0x8bd87b⟩ := by
  decide +kernel

example : (decode meteo_hazardBytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 5778⟩ 0x0001cf40000000, 0x8bd87b⟩ := meteo_hazard_frame

/-- Sun 2nd ed., §19.3/figure19.1, printed pp.143–144; published message `A0001838E519F33160240142D7FA`. -/
def inference_df20Bytes : List UInt8 := [0xa0, 0x00, 0x18, 0x38, 0xe5, 0x19, 0xf3, 0x31, 0x60, 0x24, 0x01, 0x42, 0xd7, 0xfa]

/-- Sun 2nd ed., §19.3/figure19.1, printed pp.143–144: independent literal wire-field anchor. -/
theorem inference_df20_frame :
    (decode inference_df20Bytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 6200⟩ 0xe519f331602401, 0x42d7fa⟩ := by
  decide +kernel

example : (decode inference_df20Bytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 6200⟩ 0xe519f331602401, 0x42d7fa⟩ := inference_df20_frame

/-- Sun 2nd ed., §19.3/figure19.2, printed pp.143–144; published message `A8001EBCFFFB23286004A73F6A5B`. -/
def inference_df21Bytes : List UInt8 := [0xa8, 0x00, 0x1e, 0xbc, 0xff, 0xfb, 0x23, 0x28, 0x60, 0x04, 0xa7, 0x3f, 0x6a, 0x5b]

/-- Sun 2nd ed., §19.3/figure19.2, printed pp.143–144: independent literal wire-field anchor. -/
theorem inference_df21_frame :
    (decode inference_df21Bytes).map Message.fields = some ⟨.commB true ⟨0, 0, 0, 7868⟩ 0xfffb23286004a7, 0x3f6a5b⟩ := by
  decide +kernel

example : (decode inference_df21Bytes).map Message.fields =
    some ⟨.commB true ⟨0, 0, 0, 7868⟩ 0xfffb23286004a7, 0x3f6a5b⟩ := inference_df21_frame

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim; published message `5D4074358AD00C`. -/
def raw_only_1Bytes : List UInt8 := [0x5d, 0x40, 0x74, 0x35, 0x8a, 0xd0, 0x0c]

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim: independent literal wire-field anchor. -/
theorem raw_only_1_frame :
    (decode raw_only_1Bytes).map Message.fields = some ⟨.allCall 5 0x407435, 0x8ad00c⟩ := by
  decide +kernel

example : (decode raw_only_1Bytes).map Message.fields =
    some ⟨.allCall 5 0x407435, 0x8ad00c⟩ := raw_only_1_frame

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim; published message `8D407435990DBD01900484F66C3C`. -/
def raw_only_2Bytes : List UInt8 := [0x8d, 0x40, 0x74, 0x35, 0x99, 0x0d, 0xbd, 0x01, 0x90, 0x04, 0x84, 0xf6, 0x6c, 0x3c]

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim: independent literal wire-field anchor. -/
theorem raw_only_2_frame :
    (decode raw_only_2Bytes).map Message.fields = some ⟨.extended false 5 0x407435 0x990dbd01900484, 0xf66c3c⟩ := by
  decide +kernel

example : (decode raw_only_2Bytes).map Message.fields =
    some ⟨.extended false 5 0x407435 0x990dbd01900484, 0xf66c3c⟩ := raw_only_2_frame

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim; published message `8D40743558AF828CD326FE0C2FE9`. -/
def raw_only_3Bytes : List UInt8 := [0x8d, 0x40, 0x74, 0x35, 0x58, 0xaf, 0x82, 0x8c, 0xd3, 0x26, 0xfe, 0x0c, 0x2f, 0xe9]

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim: independent literal wire-field anchor. -/
theorem raw_only_3_frame :
    (decode raw_only_3Bytes).map Message.fields = some ⟨.extended false 5 0x407435 0x58af828cd326fe, 0x0c2fe9⟩ := by
  decide +kernel

example : (decode raw_only_3Bytes).map Message.fields =
    some ⟨.extended false 5 0x407435 0x58af828cd326fe, 0x0c2fe9⟩ := raw_only_3_frame

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim; published message `A80011B1E0DA112FE0140060939F`. -/
def raw_only_4Bytes : List UInt8 := [0xa8, 0x00, 0x11, 0xb1, 0xe0, 0xda, 0x11, 0x2f, 0xe0, 0x14, 0x00, 0x60, 0x93, 0x9f]

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim: independent literal wire-field anchor. -/
theorem raw_only_4_frame :
    (decode raw_only_4Bytes).map Message.fields = some ⟨.commB true ⟨0, 0, 0, 4529⟩ 0xe0da112fe01400, 0x60939f⟩ := by
  decide +kernel

example : (decode raw_only_4Bytes).map Message.fields =
    some ⟨.commB true ⟨0, 0, 0, 4529⟩ 0xe0da112fe01400, 0x60939f⟩ := raw_only_4_frame

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim; published message `A00015B8C2680030A80000318667`. -/
def raw_only_5Bytes : List UInt8 := [0xa0, 0x00, 0x15, 0xb8, 0xc2, 0x68, 0x00, 0x30, 0xa8, 0x00, 0x00, 0x31, 0x86, 0x67]

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim: independent literal wire-field anchor. -/
theorem raw_only_5_frame :
    (decode raw_only_5Bytes).map Message.fields = some ⟨.commB false ⟨0, 0, 0, 5560⟩ 0xc2680030a80000, 0x318667⟩ := by
  decide +kernel

example : (decode raw_only_5Bytes).map Message.fields =
    some ⟨.commB false ⟨0, 0, 0, 5560⟩ 0xc2680030a80000, 0x318667⟩ := raw_only_5_frame

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim; published message `5D4074358AD030`. -/
def raw_only_6Bytes : List UInt8 := [0x5d, 0x40, 0x74, 0x35, 0x8a, 0xd0, 0x30]

/-- Sun 2nd ed., §2.4.1, printed p.28; raw-only output, no decoded claim: independent literal wire-field anchor. -/
theorem raw_only_6_frame :
    (decode raw_only_6Bytes).map Message.fields = some ⟨.allCall 5 0x407435, 0x8ad030⟩ := by
  decide +kernel

example : (decode raw_only_6Bytes).map Message.fields =
    some ⟨.allCall 5 0x407435, 0x8ad030⟩ := raw_only_6_frame

/-- Source-table projection utility: select a named value already in a report. -/
def value (values : Semantics.Values) (key : String) : Option Rat :=
  (values.find? (fun p => p.1 == key)).bind Prod.snd

/-- Source-table projection utility: select a named label already in a report. -/
def label (labels : Semantics.Labels) (key : String) : Option String :=
  (labels.find? (fun p => p.1 == key)).bind Prod.snd

/-- Projection of the returned ADS-B semantic record; no bit parsing. -/
def adsbValues (keys : List String) (m : Message) : Option (List (Option Rat)) :=
  m.decoded.semanticADSB.map fun p => keys.map (value p.standardValues)

/-- Projection of returned ADS-B affine table quantities; no bit parsing. -/
def adsbTable (keys : List String) (m : Message) : Option (List (Option Rat)) :=
  m.decoded.semanticADSB.map fun p => keys.map (value p.tableValues)

/-- Projection of returned ADS-B source labels; no bit parsing. -/
def adsbLabels (keys : List String) (m : Message) : Option (List (Option String)) :=
  m.decoded.semanticADSB.map fun p => keys.map (label p.standardLabels)

/-- Projection of the returned candidate's semantic record; no second inference. -/
def commBPayload (reg : Nat) (m : Message) : Option Semantics.Payload :=
  (m.decoded.semanticCommB.find? (fun p => p.1 == reg)).map Prod.snd

/-- Projection of returned source Comm-B quantities; no bit parsing. -/
def commBValues (reg : Nat) (keys : List String) (m : Message) : Option (List (Option Rat)) :=
  (commBPayload reg m).map fun p => keys.map (value p.standardValues)

/-- Projection of returned Comm-B labels; no bit parsing. -/
def commBLabels (reg : Nat) (keys : List String) (m : Message) : Option (List (Option String)) :=
  (commBPayload reg m).map fun p => keys.map (label p.standardLabels)

/-- Source CPR table projection: select already-decoded parity and coordinate codes. -/
def cprCode (m : Message) : Option CPR.Encoded := do
  let p ← m.decoded.adsb
  let parity ← payloadField p "parity"
  let lat ← payloadField p "lat_cpr"
  let lon ← payloadField p "lon_cpr"
  some ⟨parity == 1, lat, lon⟩

/-- Sun 2nd ed., §§3.5/4.3 pp.37–38/43: category0, KLM1023, unavailable wake category. -/
theorem identification_meaning :
    (decode identificationBytes).bind (adsbTable ["tc", "category"]) = some [some 4, some 0] ∧
    (decode identificationBytes).bind (adsbLabels ["callsign", "wake_vortex"]) =
      some [some "KLM1023", some "n/a"] ∧
    (decode identificationBytes).bind (fun m => m.decoded.address) = some 0x4840d6 := by
  decide +kernel

example : (decode identificationBytes).bind (adsbTable ["tc", "category"]) = some [some 4, some 0] ∧
    (decode identificationBytes).bind (adsbLabels ["callsign", "wake_vortex"]) =
      some [some "KLM1023", some "n/a"] ∧
    (decode identificationBytes).bind (fun m => m.decoded.address) = some 0x4840d6 := identification_meaning

/-- Sun 2nd ed., §2.4.1 p.28: DF17/TC19.1, AA451DBD, zeroCRC/rate/NACv; rounded speed/track derive from−436,+11kt. -/
theorem quick_start_meaning :
    (decode quick_startBytes).map (fun m => m.decoded.crc) = some 0 ∧
    (decode quick_startBytes).bind (fun m => m.decoded.address) = some 0x451dbd ∧
    (decode quick_startBytes).bind (adsbTable ["tc", "subtype", "NACv"]) =
      some [some 19, some 1, some 0] ∧
    (decode quick_startBytes).bind (adsbValues ["east_velocity", "north_velocity", "vertical_rate"]) =
      some [some (-436), some 11, some 0] := by
  decide +kernel

example : (decode quick_startBytes).map (fun m => m.decoded.crc) = some 0 ∧
    (decode quick_startBytes).bind (fun m => m.decoded.address) = some 0x451dbd ∧
    (decode quick_startBytes).bind (adsbTable ["tc", "subtype", "NACv"]) =
      some [some 19, some 1, some 0] ∧
    (decode quick_startBytes).bind (adsbValues ["east_velocity", "north_velocity", "vertical_rate"]) =
      some [some (-436), some 11, some 0] := quick_start_meaning

/-- Sun 2nd ed., §5.3.3 pp.53–54 equation5.16: both encoded CPR pairs. -/
theorem airborne_coordinates :
    (decode airborne_evenBytes).bind cprCode = some ⟨false, 93000, 51372⟩ ∧
    (decode airborne_oddBytes).bind cprCode = some ⟨true, 74158, 50194⟩ := by
  decide +kernel

example : (decode airborne_evenBytes).bind cprCode = some ⟨false, 93000, 51372⟩ ∧
    (decode airborne_oddBytes).bind cprCode = some ⟨true, 74158, 50194⟩ := airborne_coordinates

/-- Sun 2nd ed., §5.5.1 pp.58–59: code0xC38, Q1,38000ft; TC11. -/
theorem airborne_altitude :
    (decode airborne_evenBytes).bind (adsbTable ["tc", "altitude_code"]) =
      some [some 11, some 3128] ∧
    (decode airborne_evenBytes).bind (fun m => m.decoded.altitude) = some (.feet 38000) ∧
    (decode airborne_oddBytes).bind (fun m => m.decoded.altitude) = some (.feet 38000) := by
  decide +kernel

example : (decode airborne_evenBytes).bind (adsbTable ["tc", "altitude_code"]) =
      some [some 11, some 3128] ∧
    (decode airborne_evenBytes).bind (fun m => m.decoded.altitude) = some (.feet 38000) ∧
    (decode airborne_oddBytes).bind (fun m => m.decoded.altitude) = some (.feet 38000) := airborne_altitude

/-- Sun 2nd ed., §5.3.3 pp.54–55 equations5.20/5.23: exact52.25720214843750°,3.91937255859375°, even most recent. -/
theorem airborne_global_position :
    ((decode airborne_evenBytes).bind cprCode).bind (fun even =>
      ((decode airborne_oddBytes).bind cprCode).bind (fun odd => CPR.decodeGlobal even odd false)) =
      some ⟨3424728 / 65536, 256860 / 65536⟩ := by
  decide +kernel

example : ((decode airborne_evenBytes).bind cprCode).bind (fun even =>
      ((decode airborne_oddBytes).bind cprCode).bind (fun odd => CPR.decodeGlobal even odd false)) =
      some ⟨3424728 / 65536, 256860 / 65536⟩ := airborne_global_position

/-- Sun 2nd ed., §5.4.4 pp.57–58: reference52.258°,3.918° gives same position. -/
theorem airborne_local_position :
    ((decode airborne_evenBytes).bind cprCode).bind (fun c =>
      CPR.decodeLocal .airborne c ⟨52258/1000, 3918/1000⟩) =
      some ⟨3424728 / 65536, 256860 / 65536⟩ := by
  decide +kernel

example : ((decode airborne_evenBytes).bind cprCode).bind (fun c =>
      CPR.decodeLocal .airborne c ⟨52258/1000, 3918/1000⟩) =
      some ⟨3424728 / 65536, 256860 / 65536⟩ := airborne_local_position

/-- Sun 2nd ed., §6.4.1 p.64 equation6.4: source surface pair; global surface algorithm stays out of scope. -/
theorem surface_coordinates :
    (decode surface_evenBytes).bind cprCode = some ⟨false, 115609, 116941⟩ ∧
    (decode surface_oddBytes).bind cprCode = some ⟨true, 39199, 110269⟩ ∧
    (decode surface_localBytes).bind cprCode = some ⟨true, 39195, 110320⟩ := by
  decide +kernel

example : (decode surface_evenBytes).bind cprCode = some ⟨false, 115609, 116941⟩ ∧
    (decode surface_oddBytes).bind cprCode = some ⟨true, 39199, 110269⟩ ∧
    (decode surface_localBytes).bind cprCode = some ⟨true, 39195, 110320⟩ := surface_coordinates

/-- Sun 2nd ed., §6.4.1 pp.65–66 equations6.10/6.13:52.320607072215964°,4.734734671456474°; local decoding is in scope. -/
theorem surface_odd_local_reconstruction :
    ((decode surface_oddBytes).bind cprCode).bind (fun c =>
      CPR.decodeLocal .surface c ⟨51990/1000, 4375/1000⟩) =
      some ⟨90/59 * (34 + 39199/131072), 90/35 * (1 + 110269/131072)⟩ := by
  decide +kernel

example : ((decode surface_oddBytes).bind cprCode).bind (fun c =>
      CPR.decodeLocal .surface c ⟨51990/1000, 4375/1000⟩) =
      some ⟨90/59 * (34 + 39199/131072), 90/35 * (1 + 110269/131072)⟩ := surface_odd_local_reconstruction

/-- Sun 2nd ed., §6.4.2 p.67 equations6.17/6.20, using printed reference52.320607°,4.734735°; stale Python output is documented. -/
theorem surface_local_position :
    ((decode surface_localBytes).bind cprCode).bind (fun c =>
      CPR.decodeLocal .surface c ⟨52320607/1000000, 4734735/1000000⟩) =
      some ⟨90/59 * (34 + 39195/131072), 90/35 * (1 + 110320/131072)⟩ := by
  decide +kernel

example : ((decode surface_localBytes).bind cprCode).bind (fun c =>
      CPR.decodeLocal .surface c ⟨52320607/1000000, 4734735/1000000⟩) =
      some ⟨90/59 * (34 + 39195/131072), 90/35 * (1 + 110320/131072)⟩ := surface_local_position

/-- Sun 2nd ed., §6.4.3 p.68: movement41→17kt, track33→92.8125°. -/
theorem surface_movement_track :
    (decode surface_localBytes).bind (adsbTable ["tc", "movement", "track"]) =
      some [some 7, some 41, some (1485/16)] ∧
    (decode surface_localBytes).bind (adsbValues ["groundspeed"]) = some [some 17] := by
  decide +kernel

example : (decode surface_localBytes).bind (adsbTable ["tc", "movement", "track"]) =
      some [some 7, some 41, some (1485/16)] ∧
    (decode surface_localBytes).bind (adsbValues ["groundspeed"]) = some [some 17] := surface_movement_track

/-- Sun 2nd ed., §§7.1–3 pp.70–74:−8kt east,−159kt north,−832ft/min GNSS rate,+550ft difference. -/
theorem velocity_ground_meaning :
    (decode velocity_groundBytes).bind
      (adsbValues ["east_velocity", "north_velocity", "vertical_rate", "geo_minus_baro"]) =
      some [some (-8), some (-159), some (-832), some 550] ∧
    (decode velocity_groundBytes).bind (adsbLabels ["vrate_src"]) = some [some "GNSS"] ∧
    (decode velocity_groundBytes).bind
      (adsbTable ["tc", "subtype", "intent_change", "ifr_capability", "NACv", "vertical_rate_code", "geo_minus_baro_code"]) =
      some [some 19, some 1, some 0, some 1, some 0, some 14, some 23] := by
  decide +kernel

example : (decode velocity_groundBytes).bind
      (adsbValues ["east_velocity", "north_velocity", "vertical_rate", "geo_minus_baro"]) =
      some [some (-8), some (-159), some (-832), some 550] ∧
    (decode velocity_groundBytes).bind (adsbLabels ["vrate_src"]) = some [some "GNSS"] ∧
    (decode velocity_groundBytes).bind
      (adsbTable ["tc", "subtype", "intent_change", "ifr_capability", "NACv", "vertical_rate_code", "geo_minus_baro_code"]) =
      some [some 19, some 1, some 0, some 1, some 0, some 14, some 23] := velocity_ground_meaning

/-- Sun 2nd ed., §§7.1/7.4 pp.71/75: TAS375kt, magnetic heading694×360/1024°,−2304ft/min barometric rate; unavailable height difference. -/
theorem velocity_air_meaning :
    (decode velocity_airBytes).bind (adsbValues ["airspeed", "vertical_rate", "geo_minus_baro"]) =
      some [some 375, some (-2304), none] ∧
    (decode velocity_airBytes).bind (adsbTable ["tc", "subtype", "heading", "vertical_rate_code"]) =
      some [some 19, some 3, some (15615/64), some 37] ∧
    (decode velocity_airBytes).bind (adsbLabels ["vrate_src", "airspeed_type"]) =
      some [some "barometric", some "TAS"] := by
  decide +kernel

example : (decode velocity_airBytes).bind (adsbValues ["airspeed", "vertical_rate", "geo_minus_baro"]) =
      some [some 375, some (-2304), none] ∧
    (decode velocity_airBytes).bind (adsbTable ["tc", "subtype", "heading", "vertical_rate_code"]) =
      some [some 19, some 3, some (15615/64), some 37] ∧
    (decode velocity_airBytes).bind (adsbLabels ["vrate_src", "airspeed_type"]) =
      some [some "barometric", some "TAS"] := velocity_air_meaning

/-- Sun 2nd ed., §10.2 pp.91–92: parityAA4BDA and zero syndrome. -/
theorem crc_good_meaning :
    (decode crc_goodBytes).map (fun m => m.decoded.crc) = some 0 ∧
    Parity.checksum 88 0x8d406b902015a678d4d220 = 0xaa4bda := by
  decide +kernel

example : (decode crc_goodBytes).map (fun m => m.decoded.crc) = some 0 ∧
    Parity.checksum 88 0x8d406b902015a678d4d220 = 0xaa4bda := crc_good_meaning

/-- Sun 2nd ed., §10.2 p.92: received messageB has syndrome16; DF17 rejects it. -/
theorem crc_bad_rejected :
    decode [0x8d,0x4c,0xa2,0x51,0x20,0x49,0x94,0xb1,0xc3,0x6e,0x60,0xa5,0x34,0x3d] = none ∧
    Parity.syndrome 112 0x8d4ca251204994b1c36e60a5343d = 16 := by
  decide +kernel

example : decode [0x8d,0x4c,0xa2,0x51,0x20,0x49,0x94,0xb1,0xc3,0x6e,0x60,0xa5,0x34,0x3d] = none ∧
    Parity.syndrome 112 0x8d4ca251204994b1c36e60a5343d = 16 := crc_bad_rejected

/-- Sun 2nd ed., §11.3 pp.97–98: CRCpayloadCE2CA7 XOR APF24177 gives address3C6DD0. -/
theorem address_parity_meaning :
    (decode address_parityBytes).bind (fun m => m.decoded.address) = some 0x3c6dd0 ∧
    Parity.checksum 88 0xa0001838ca380031440000 = 0xce2ca7 := by
  decide +kernel

example : (decode address_parityBytes).bind (fun m => m.decoded.address) = some 0x3c6dd0 ∧
    Parity.checksum 88 0xa0001838ca380031440000 = 0xce2ca7 := address_parity_meaning

/-- Sun 2nd ed., ch.12 p.101: ICAO484FDE, CA5, overlaid interrogator identifier22. -/
theorem all_call_meaning :
    (decode all_callBytes).bind (fun m => m.decoded.address) = some 0x484fde ∧
    (decode all_callBytes).map (fun m => m.decoded.crc) = some 22 := by
  decide +kernel

example : (decode all_callBytes).bind (fun m => m.decoded.address) = some 0x484fde ∧
    (decode all_callBytes).map (fun m => m.decoded.crc) = some 22 := all_call_meaning

/-- Sun 2nd ed., §13.2 p.105:36000ft. -/
theorem altitude_meaning :
    (decode altitudeBytes).bind (fun m => m.decoded.altitude) = some (.feet 36000) := by
  decide +kernel

example : (decode altitudeBytes).bind (fun m => m.decoded.altitude) = some (.feet 36000) := altitude_meaning

/-- Sun 2nd ed., §13.3 pp.105–106: squawk0356, represented as the integer of its four octal digits. -/
theorem identity_meaning :
    (decode identityBytes).bind (fun m => m.decoded.identity) = some 238 := by
  decide +kernel

example : (decode identityBytes).bind (fun m => m.decoded.identity) = some 238 := identity_meaning

/-- Sun 2nd ed., §16.2 p.120: all11 source bitmap flags, including BDS52 in source Python output but omitted from prose list. -/
theorem gicb_meaning :
    (decode gicbBytes).bind (fun m => (commBPayload 0x17 m).map fun p =>
      (p.tableValues.filter (fun pair => pair.2 == some 1)).map Prod.fst) =
      some ["bds05", "bds06", "bds07", "bds08", "bds09", "bds20", "bds40", "bds50", "bds51", "bds52", "bds60"] := by
  decide +kernel

example : (decode gicbBytes).bind (fun m => (commBPayload 0x17 m).map fun p =>
      (p.tableValues.filter (fun pair => pair.2 == some 1)).map Prod.fst) =
      some ["bds05", "bds06", "bds07", "bds08", "bds09", "bds20", "bds40", "bds50", "bds51", "bds52", "bds60"] := gicb_meaning

/-- Sun 2nd ed., §16.3 pp.121–122: KLM1017, trailing source space is suppressed by declared presentation policy. -/
theorem commb_identification_meaning :
    (decode commb_identificationBytes).bind (commBLabels 0x20 ["callsign"]) = some [some "KLM1017"] := by
  decide +kernel

example : (decode commb_identificationBytes).bind (commBLabels 0x20 ["callsign"]) = some [some "KLM1017"] := commb_identification_meaning

/-- Sun 2nd ed., §17.1 figure17.1 pp.128–129: both24000ft,1013.2hPa, three modesoff, targetsourceMCP. -/
theorem selected_altitude_meaning :
    (decode selected_altitudeBytes).bind
      (commBValues 0x40 ["selected_mcp", "selected_fms", "barometric_setting", "vnav_mode", "alt_hold_mode", "approach_mode", "target_altitude_source"]) =
      some [some 24000, some 24000, some (5066/5), some 0, some 0, some 0, some 2] := by
  decide +kernel

example : (decode selected_altitudeBytes).bind
      (commBValues 0x40 ["selected_mcp", "selected_fms", "barometric_setting", "vnav_mode", "alt_hold_mode", "approach_mode", "target_altitude_source"]) =
      some [some 24000, some 24000, some (5066/5), some 0, some 0, some 0, some 2] := selected_altitude_meaning

/-- Sun 2nd ed., §17.2 figure17.2 p.131: exact values before display rounding, using published signed codes457/798/499 and speed codes238/233. -/
theorem track_turn_meaning :
    (decode track_turnBytes).bind (commBValues 0x50 ["roll", "track", "track_rate", "groundspeed", "TAS"]) =
      some [some (-2475/256), some (17955/128), some (-13/32), some 476, some 466] := by
  decide +kernel

example : (decode track_turnBytes).bind (commBValues 0x50 ["roll", "track", "track_rate", "groundspeed", "TAS"]) =
      some [some (-2475/256), some (17955/128), some (-13/32), some 476, some 466] := track_turn_meaning

/-- Sun 2nd ed., §17.3 figure17.3 pp.133–134: heading110.390625°,IAS259kt,Mach0.7, rates−2144/−2016ft/min. -/
theorem heading_speed_meaning :
    (decode heading_speedBytes).bind
      (commBValues 0x60 ["heading", "IAS", "Mach", "vrate_barometric", "vrate_inertial"]) =
      some [some (7065/64), some 259, some (7/10), some (-2144), some (-2016)] := by
  decide +kernel

example : (decode heading_speedBytes).bind
      (commBValues 0x60 ["heading", "IAS", "Mach", "vrate_barometric", "vrate_inertial"]) =
      some [some (7065/64), some 259, some (7/10), some (-2144), some (-2016)] := heading_speed_meaning

/-- Sun 2nd ed., §18.1 figure18.1 pp.136–137:22kt,344.53125°,−48.75°C; pressure/turbulence/humidity unavailable. Chosen quarter-degree version is explicit inSCOPE. -/
theorem meteo_routine_meaning :
    (decode meteo_routineBytes).bind
      (commBValues 0x44 ["figure_of_merit", "wind_speed", "wind_direction", "temperature", "pressure", "turbulence", "humidity"]) =
      some [some 1, some 22, some (11025/32), some (-195/4), none, none, none] := by
  decide +kernel

example : (decode meteo_routineBytes).bind
      (commBValues 0x44 ["figure_of_merit", "wind_speed", "wind_direction", "temperature", "pressure", "turbulence", "humidity"]) =
      some [some 1, some 22, some (11025/32), some (-195/4), none, none, none] := meteo_routine_meaning

/-- Sun 2nd ed., §18.2 figure18.2 p.139: only temperature−48.75°C available; published hex visually transcribed. -/
theorem meteo_hazard_meaning :
    (decode meteo_hazardBytes).bind
      (commBValues 0x45 ["turbulence", "wind_shear", "microburst", "icing", "wake_vortex", "static_temperature", "static_pressure", "radio_height"]) =
      some [none, none, none, none, none, some (-195/4), none, none] := by
  decide +kernel

example : (decode meteo_hazardBytes).bind
      (commBValues 0x45 ["turbulence", "wind_shear", "microburst", "icing", "wake_vortex", "static_temperature", "static_pressure", "radio_height"]) =
      some [none, none, none, none, none, some (-195/4), none, none] := meteo_hazard_meaning

/-- Sun 2nd ed., §19.3 figure19.1 p.144:38000ft, BDS60 candidate, IAS249kt/Mach0.788; CASconversion is an out-of-scope inference extension. -/
theorem inference_df20_meaning :
    (decode inference_df20Bytes).bind (fun m => m.decoded.altitude) = some (.feet 38000) ∧
    (decode inference_df20Bytes).map (fun m => m.decoded.commB.map Prod.fst) = some [0x60] ∧
    (decode inference_df20Bytes).bind (commBValues 0x60 ["IAS", "Mach"]) = some [some 249, some (197/250)] := by
  decide +kernel

example : (decode inference_df20Bytes).bind (fun m => m.decoded.altitude) = some (.feet 38000) ∧
    (decode inference_df20Bytes).map (fun m => m.decoded.commB.map Prod.fst) = some [0x60] ∧
    (decode inference_df20Bytes).bind (commBValues 0x60 ["IAS", "Mach"]) = some [some 249, some (197/250)] := inference_df20_meaning

/-- Sun 2nd ed., §19.3 figure19.2 p.144: both50/60 candidates without extraADS-B reference; ground322kt versus IAS401kt; signed angles normalize to approximately250°/359° as coarsely displayed in the figure. -/
theorem inference_df21_meaning :
    (decode inference_df21Bytes).map (fun m => m.decoded.commB.map Prod.fst) = some [0x50, 0x60] ∧
    (decode inference_df21Bytes).bind (commBValues 0x50 ["groundspeed", "track"]) =
      some [some 322, some (-28035/256)] ∧
    (decode inference_df21Bytes).bind (commBValues 0x60 ["IAS", "heading"]) =
      some [some 401, some (-45/256)] := by
  decide +kernel

example : (decode inference_df21Bytes).map (fun m => m.decoded.commB.map Prod.fst) = some [0x50, 0x60] ∧
    (decode inference_df21Bytes).bind (commBValues 0x50 ["groundspeed", "track"]) =
      some [some 322, some (-28035/256)] ∧
    (decode inference_df21Bytes).bind (commBValues 0x60 ["IAS", "heading"]) =
      some [some 401, some (-45/256)] := inference_df21_meaning

/-- Sun 2nd ed., §7.3 equations7.10–12, pp.73–74: fixed literal expression
operands for the speed/track example. Evaluation by platform Float is outside
kernel semantics, but changing the decoded components or operation tree fails. -/
def groundPrograms : List Presentation.NumericField :=
  [⟨"groundspeed", some (.hypot64
      (.abs64 (.literal .binary64 (-8))) (.abs64 (.literal .binary64 (-159)))), .null⟩,
   ⟨"track", some (.addIfNegative64 (.mul .binary64
      (.atan2_64 (.literal .binary64 (-8)) (.literal .binary64 (-159)))
      (.div .binary64 (.literal .binary64 360)
        (.mul .binary64 (.literal .binary64 2)
          (.literal .binary64 (884279719003555/281474976710656)))))), .null⟩]

/-- Sun 2nd ed., §7.3 pp.73–74: message decoding fixes all numeric operands
before the independently tested Float boundary. -/
theorem velocity_ground_programs :
    (decode velocity_groundBytes).bind (fun m =>
      m.decoded.semanticADSB.map Semantics.Payload.standardFloats) = some groundPrograms := by
  decide +kernel

example : (decode velocity_groundBytes).bind (fun m =>
    m.decoded.semanticADSB.map Semantics.Payload.standardFloats) = some groundPrograms :=
  velocity_ground_programs

/-- Sun 2nd ed., §7.3 p.74:159.20kt agrees with the actual−8/−159 components
at two decimal places; the equation's−9/−160 operands are a source typo. This
is a rational square bound, not a theorem about a Float sqrt implementation. -/
theorem velocity_ground_speed_rounding :
    (159195/1000 : Rat)^2 < (-8 : Rat)^2 + (-159 : Rat)^2 ∧
    (-8 : Rat)^2 + (-159 : Rat)^2 < (159205/1000 : Rat)^2 := by
  decide +kernel

/-- Sun 2nd ed., §2.4.1 p.28:436.1kt is consistent with the decoded−436/+11
components at one decimal place. -/
theorem quick_start_speed_rounding :
    (43605/100 : Rat)^2 < (-436 : Rat)^2 + (11 : Rat)^2 ∧
    (-436 : Rat)^2 + (11 : Rat)^2 < (43615/100 : Rat)^2 := by
  decide +kernel

/-- Sun 2nd ed., §19.3 figure19.1 p.144: alternative BDS50 interpretation of
the very same decoded MB block. It is excluded from inference, so these
hypothetical quantities are intentionally not claimed to be reported candidates. -/
theorem inference_df20_rejected_alternative :
    (decode inference_df20Bytes).map (fun m => match m.fields.body with
      | .commB _ _ mb =>
        (commBValue 0x50 mb.toNat "groundspeed", commBValue 0x50 mb.toNat "TAS")
      | _ => (none, none)) = some (some 394, some 2) := by
  decide +kernel

/-- Sun 2nd ed., §11.2 p.96: data-parity modified-address worked calculation;
no complete frame is supplied by this example. -/
theorem data_parity_overlay : (0xdd33aa : BitVec 24) ^^^ 0x440000 = 0x9933aa := by
  decide +kernel

/-- Sun 2nd ed., §11.4 pp.98–99: signed9-value-bit examples, positive467
and negative45; no complete frame is supplied by the source. -/
theorem twos_complement_examples :
    payloadInteger .twosComplement 10 467 = 467 ∧
    payloadInteger .twosComplement 10 979 = -45 := by
  decide +kernel

/-- Sun 2nd ed., §5.1 pp.46–47: pedagogical16×16-world example, not Mode S
CPR; modulo4 gives(1,3), modulo5 gives(4,2), with unique point(9,7). -/
theorem toy_cpr_example :
    (9 % 4, 7 % 4) = (1, 3) ∧ (9 % 5, 7 % 5) = (4, 2) ∧
    ((List.range 16).product (List.range 16)).filter (fun (x, y) =>
      x % 4 == 1 && y % 4 == 3 && x % 5 == 4 && y % 5 == 2) = [(9,7)] := by
  decide +kernel

/-- ICAO Annex10 III PartI amendment77, §2.6.2(c,e) notes3/4, p.5-89:
floor and positive-modulo numerical examples actually printed in the source.
Neither is a complete Mode S frame. -/
theorem icao_cpr_arithmetic_examples :
    (38/10 : Rat).floor = 3 ∧ (-38/10 : Rat).floor = -4 ∧
    CPR.modQ (-40) 6 = 2 ∧ CPR.modQ 320 6 = 2 := by
  decide +kernel

/-- Sun 2nd ed., §10.2 figure10.2 p.91: the source prints quotient110010110,
divisor1101, data101101111000 and remainder010. The literal carryless-product
identity shows the actual remainder is110, and proves the printed010 cannot
be correct. This pedagogical generator is not the Mode S generator. -/
theorem toy_crc_source_disagreement :
    (Nat.xor ((List.range 9).foldl (fun product i =>
      if (406 / 2^i) % 2 == 1 then Nat.xor product (13 * 2^i) else product) 0) 6) = 2936 ∧
    6 < 2^3 ∧
    (Nat.xor ((List.range 9).foldl (fun product i =>
      if (406 / 2^i) % 2 == 1 then Nat.xor product (13 * 2^i) else product) 0) 2) ≠ 2936 := by
  decide +kernel

end Lean1090.Spec.StandardExamples
