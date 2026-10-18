// Lean compiler output
// Module: Impl.Message
// Imports: public import Init public meta import Init public import Model.Types public import Impl.Frame public import Impl.Parity public import Impl.CommB public import Impl.Semantics
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lp_lean1090_Lean1090_Impl_decodeADSB(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_adsbAltitude(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_decodeFrame(lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_adsbHardValid(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_informationBits(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameParts(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object*, lean_object*);
lean_object* lean_nat_lxor(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_identityCode(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsb(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object*);
lean_object* l_List_head_x3f___redArg(lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameSyndrome(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_frameAccepted___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_frameAccepted___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_frameAccepted(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAccepted___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddress(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAltitude(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAltitude___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameIdentity(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameIdentity___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameADSB(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameADSB___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameCommB(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameCommB___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_report_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_report_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_report(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decode___boxed(lean_object*);
static const lean_array_object lp_lean1090_Lean1090_Impl_decodePrefix___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_lean1090_Lean1090_Impl_decodePrefix___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_decodePrefix___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePrefix(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameSyndrome(lean_object* v_f_1_){
_start:
{
lean_object* v_body_2_; lean_object* v_parity_3_; lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; lean_object* v___x_7_; lean_object* v___x_8_; 
v_body_2_ = lean_ctor_get(v_f_1_, 0);
lean_inc_ref(v_body_2_);
v_parity_3_ = lean_ctor_get(v_f_1_, 1);
lean_inc(v_parity_3_);
lean_dec_ref(v_f_1_);
v___x_4_ = lp_lean1090_Lean1090_Impl_informationBits(v_body_2_);
v___x_5_ = lp_lean1090_Lean1090_Impl_frameParts(v_body_2_);
v___x_6_ = lp_lean1090_Lean1090_Impl_packFields(v___x_5_);
lean_dec(v___x_5_);
v___x_7_ = lp_lean1090_Lean1090_Impl_Parity_checksum(v___x_4_, v___x_6_);
lean_dec(v___x_6_);
lean_dec(v___x_4_);
v___x_8_ = lean_nat_lxor(v___x_7_, v_parity_3_);
lean_dec(v_parity_3_);
lean_dec(v___x_7_);
return v___x_8_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_frameAccepted___closed__0(void){
_start:
{
lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; 
v___x_9_ = lean_unsigned_to_nat(0u);
v___x_10_ = lean_unsigned_to_nat(24u);
v___x_11_ = l_BitVec_ofNat(v___x_10_, v___x_9_);
return v___x_11_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_frameAccepted(lean_object* v_f_12_){
_start:
{
lean_object* v_body_13_; 
v_body_13_ = lean_ctor_get(v_f_12_, 0);
if (lean_obj_tag(v_body_13_) == 4)
{
uint8_t v_supplementary_14_; lean_object* v_me_15_; uint8_t v___x_16_; 
v_supplementary_14_ = lean_ctor_get_uint8(v_body_13_, sizeof(void*)*3);
v_me_15_ = lean_ctor_get(v_body_13_, 2);
v___x_16_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_me_15_);
if (v___x_16_ == 0)
{
lean_dec_ref(v_f_12_);
return v___x_16_;
}
else
{
if (v_supplementary_14_ == 0)
{
lean_object* v___x_17_; lean_object* v___x_18_; uint8_t v___x_19_; 
v___x_17_ = lp_lean1090_Lean1090_Impl_frameSyndrome(v_f_12_);
v___x_18_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_frameAccepted___closed__0, &lp_lean1090_Lean1090_Impl_frameAccepted___closed__0_once, _init_lp_lean1090_Lean1090_Impl_frameAccepted___closed__0);
v___x_19_ = lean_nat_dec_eq(v___x_17_, v___x_18_);
lean_dec(v___x_17_);
return v___x_19_;
}
else
{
lean_dec_ref(v_f_12_);
return v_supplementary_14_;
}
}
}
else
{
uint8_t v___x_20_; 
lean_dec_ref(v_f_12_);
v___x_20_ = 1;
return v___x_20_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAccepted___boxed(lean_object* v_f_21_){
_start:
{
uint8_t v_res_22_; lean_object* v_r_23_; 
v_res_22_ = lp_lean1090_Lean1090_Impl_frameAccepted(v_f_21_);
v_r_23_ = lean_box(v_res_22_);
return v_r_23_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddress(lean_object* v_f_24_){
_start:
{
lean_object* v_body_25_; 
v_body_25_ = lean_ctor_get(v_f_24_, 0);
switch(lean_obj_tag(v_body_25_))
{
case 2:
{
lean_object* v_aa_26_; lean_object* v___x_27_; 
lean_inc_ref(v_body_25_);
lean_dec_ref(v_f_24_);
v_aa_26_ = lean_ctor_get(v_body_25_, 1);
lean_inc(v_aa_26_);
lean_dec_ref_known(v_body_25_, 2);
v___x_27_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_27_, 0, v_aa_26_);
return v___x_27_;
}
case 4:
{
lean_object* v_aa_28_; lean_object* v___x_29_; 
lean_inc_ref(v_body_25_);
lean_dec_ref(v_f_24_);
v_aa_28_ = lean_ctor_get(v_body_25_, 1);
lean_inc(v_aa_28_);
lean_dec_ref_known(v_body_25_, 3);
v___x_29_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_29_, 0, v_aa_28_);
return v___x_29_;
}
case 5:
{
lean_object* v___x_30_; 
lean_dec_ref(v_f_24_);
v___x_30_ = lean_box(0);
return v___x_30_;
}
default: 
{
lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_31_ = lp_lean1090_Lean1090_Impl_frameSyndrome(v_f_24_);
v___x_32_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_32_, 0, v___x_31_);
return v___x_32_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAltitude(lean_object* v_f_33_){
_start:
{
lean_object* v_body_34_; 
v_body_34_ = lean_ctor_get(v_f_33_, 0);
switch(lean_obj_tag(v_body_34_))
{
case 0:
{
lean_object* v_fields_35_; lean_object* v_ac_36_; lean_object* v___x_37_; 
v_fields_35_ = lean_ctor_get(v_body_34_, 0);
v_ac_36_ = lean_ctor_get(v_fields_35_, 7);
v___x_37_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_ac_36_);
return v___x_37_;
}
case 3:
{
lean_object* v_fields_38_; lean_object* v_ac_39_; lean_object* v___x_40_; 
v_fields_38_ = lean_ctor_get(v_body_34_, 0);
v_ac_39_ = lean_ctor_get(v_fields_38_, 7);
v___x_40_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_ac_39_);
return v___x_40_;
}
case 1:
{
uint8_t v_identity_41_; 
v_identity_41_ = lean_ctor_get_uint8(v_body_34_, sizeof(void*)*1);
if (v_identity_41_ == 0)
{
lean_object* v_fields_42_; lean_object* v_code_43_; lean_object* v___x_44_; 
v_fields_42_ = lean_ctor_get(v_body_34_, 0);
v_code_43_ = lean_ctor_get(v_fields_42_, 3);
v___x_44_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_code_43_);
return v___x_44_;
}
else
{
lean_object* v___x_45_; 
v___x_45_ = lean_box(0);
return v___x_45_;
}
}
case 6:
{
uint8_t v_identity_46_; 
v_identity_46_ = lean_ctor_get_uint8(v_body_34_, sizeof(void*)*2);
if (v_identity_46_ == 0)
{
lean_object* v_fields_47_; lean_object* v_code_48_; lean_object* v___x_49_; 
v_fields_47_ = lean_ctor_get(v_body_34_, 0);
v_code_48_ = lean_ctor_get(v_fields_47_, 3);
v___x_49_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_code_48_);
return v___x_49_;
}
else
{
lean_object* v___x_50_; 
v___x_50_ = lean_box(0);
return v___x_50_;
}
}
case 4:
{
lean_object* v_me_51_; lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v_tc_54_; lean_object* v___x_55_; uint8_t v___x_76_; 
v_me_51_ = lean_ctor_get(v_body_34_, 2);
v___x_52_ = lean_unsigned_to_nat(1u);
v___x_53_ = lean_unsigned_to_nat(5u);
v_tc_54_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_51_, v___x_52_, v___x_53_);
v___x_55_ = lean_unsigned_to_nat(9u);
v___x_76_ = lean_nat_dec_le(v___x_55_, v_tc_54_);
if (v___x_76_ == 0)
{
goto v___jp_56_;
}
else
{
lean_object* v___x_77_; uint8_t v___x_78_; 
v___x_77_ = lean_unsigned_to_nat(18u);
v___x_78_ = lean_nat_dec_le(v_tc_54_, v___x_77_);
if (v___x_78_ == 0)
{
goto v___jp_56_;
}
else
{
lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; 
lean_dec(v_tc_54_);
v___x_79_ = lean_unsigned_to_nat(12u);
v___x_80_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_51_, v___x_55_, v___x_79_);
v___x_81_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v___x_80_);
lean_dec(v___x_80_);
if (lean_obj_tag(v___x_81_) == 0)
{
lean_object* v___x_82_; 
v___x_82_ = lean_box(0);
return v___x_82_;
}
else
{
lean_object* v_val_83_; lean_object* v___x_85_; uint8_t v_isShared_86_; uint8_t v_isSharedCheck_91_; 
v_val_83_ = lean_ctor_get(v___x_81_, 0);
v_isSharedCheck_91_ = !lean_is_exclusive(v___x_81_);
if (v_isSharedCheck_91_ == 0)
{
v___x_85_ = v___x_81_;
v_isShared_86_ = v_isSharedCheck_91_;
goto v_resetjp_84_;
}
else
{
lean_inc(v_val_83_);
lean_dec(v___x_81_);
v___x_85_ = lean_box(0);
v_isShared_86_ = v_isSharedCheck_91_;
goto v_resetjp_84_;
}
v_resetjp_84_:
{
lean_object* v___x_87_; lean_object* v___x_89_; 
v___x_87_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_87_, 0, v_val_83_);
if (v_isShared_86_ == 0)
{
lean_ctor_set(v___x_85_, 0, v___x_87_);
v___x_89_ = v___x_85_;
goto v_reusejp_88_;
}
else
{
lean_object* v_reuseFailAlloc_90_; 
v_reuseFailAlloc_90_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_90_, 0, v___x_87_);
v___x_89_ = v_reuseFailAlloc_90_;
goto v_reusejp_88_;
}
v_reusejp_88_:
{
return v___x_89_;
}
}
}
}
}
v___jp_56_:
{
lean_object* v___x_57_; uint8_t v___x_58_; 
v___x_57_ = lean_unsigned_to_nat(20u);
v___x_58_ = lean_nat_dec_le(v___x_57_, v_tc_54_);
if (v___x_58_ == 0)
{
lean_object* v___x_59_; 
lean_dec(v_tc_54_);
v___x_59_ = lean_box(0);
return v___x_59_;
}
else
{
lean_object* v___x_60_; uint8_t v___x_61_; 
v___x_60_ = lean_unsigned_to_nat(22u);
v___x_61_ = lean_nat_dec_le(v_tc_54_, v___x_60_);
lean_dec(v_tc_54_);
if (v___x_61_ == 0)
{
lean_object* v___x_62_; 
v___x_62_ = lean_box(0);
return v___x_62_;
}
else
{
lean_object* v___x_63_; lean_object* v___x_64_; lean_object* v___x_65_; 
v___x_63_ = lean_unsigned_to_nat(12u);
v___x_64_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_51_, v___x_55_, v___x_63_);
v___x_65_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(v___x_64_);
if (lean_obj_tag(v___x_65_) == 0)
{
lean_object* v___x_66_; 
v___x_66_ = lean_box(0);
return v___x_66_;
}
else
{
lean_object* v_val_67_; lean_object* v___x_69_; uint8_t v_isShared_70_; uint8_t v_isSharedCheck_75_; 
v_val_67_ = lean_ctor_get(v___x_65_, 0);
v_isSharedCheck_75_ = !lean_is_exclusive(v___x_65_);
if (v_isSharedCheck_75_ == 0)
{
v___x_69_ = v___x_65_;
v_isShared_70_ = v_isSharedCheck_75_;
goto v_resetjp_68_;
}
else
{
lean_inc(v_val_67_);
lean_dec(v___x_65_);
v___x_69_ = lean_box(0);
v_isShared_70_ = v_isSharedCheck_75_;
goto v_resetjp_68_;
}
v_resetjp_68_:
{
lean_object* v___x_71_; lean_object* v___x_73_; 
v___x_71_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_71_, 0, v_val_67_);
if (v_isShared_70_ == 0)
{
lean_ctor_set(v___x_69_, 0, v___x_71_);
v___x_73_ = v___x_69_;
goto v_reusejp_72_;
}
else
{
lean_object* v_reuseFailAlloc_74_; 
v_reuseFailAlloc_74_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_74_, 0, v___x_71_);
v___x_73_ = v_reuseFailAlloc_74_;
goto v_reusejp_72_;
}
v_reusejp_72_:
{
return v___x_73_;
}
}
}
}
}
}
}
default: 
{
lean_object* v___x_92_; 
v___x_92_ = lean_box(0);
return v___x_92_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAltitude___boxed(lean_object* v_f_93_){
_start:
{
lean_object* v_res_94_; 
v_res_94_ = lp_lean1090_Lean1090_Impl_frameAltitude(v_f_93_);
lean_dec_ref(v_f_93_);
return v_res_94_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude(lean_object* v_f_95_){
_start:
{
lean_object* v_body_96_; 
v_body_96_ = lean_ctor_get(v_f_95_, 0);
switch(lean_obj_tag(v_body_96_))
{
case 0:
{
lean_object* v_fields_97_; lean_object* v_ac_98_; lean_object* v___x_99_; 
v_fields_97_ = lean_ctor_get(v_body_96_, 0);
v_ac_98_ = lean_ctor_get(v_fields_97_, 7);
v___x_99_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_ac_98_);
return v___x_99_;
}
case 3:
{
lean_object* v_fields_100_; lean_object* v_ac_101_; lean_object* v___x_102_; 
v_fields_100_ = lean_ctor_get(v_body_96_, 0);
v_ac_101_ = lean_ctor_get(v_fields_100_, 7);
v___x_102_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_ac_101_);
return v___x_102_;
}
case 1:
{
uint8_t v_identity_103_; 
v_identity_103_ = lean_ctor_get_uint8(v_body_96_, sizeof(void*)*1);
if (v_identity_103_ == 0)
{
lean_object* v_fields_104_; lean_object* v_code_105_; lean_object* v___x_106_; 
v_fields_104_ = lean_ctor_get(v_body_96_, 0);
v_code_105_ = lean_ctor_get(v_fields_104_, 3);
v___x_106_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_code_105_);
return v___x_106_;
}
else
{
lean_object* v___x_107_; 
v___x_107_ = lean_box(0);
return v___x_107_;
}
}
case 6:
{
uint8_t v_identity_108_; 
v_identity_108_ = lean_ctor_get_uint8(v_body_96_, sizeof(void*)*2);
if (v_identity_108_ == 0)
{
lean_object* v_fields_109_; lean_object* v_code_110_; lean_object* v___x_111_; 
v_fields_109_ = lean_ctor_get(v_body_96_, 0);
v_code_110_ = lean_ctor_get(v_fields_109_, 3);
v___x_111_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_code_110_);
return v___x_111_;
}
else
{
lean_object* v___x_112_; 
v___x_112_ = lean_box(0);
return v___x_112_;
}
}
case 4:
{
lean_object* v_me_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v_tc_116_; lean_object* v___x_125_; uint8_t v___x_126_; 
v_me_113_ = lean_ctor_get(v_body_96_, 2);
v___x_114_ = lean_unsigned_to_nat(1u);
v___x_115_ = lean_unsigned_to_nat(5u);
v_tc_116_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_113_, v___x_114_, v___x_115_);
v___x_125_ = lean_unsigned_to_nat(9u);
v___x_126_ = lean_nat_dec_le(v___x_125_, v_tc_116_);
if (v___x_126_ == 0)
{
goto v___jp_117_;
}
else
{
lean_object* v___x_127_; uint8_t v___x_128_; 
v___x_127_ = lean_unsigned_to_nat(18u);
v___x_128_ = lean_nat_dec_le(v_tc_116_, v___x_127_);
if (v___x_128_ == 0)
{
goto v___jp_117_;
}
else
{
lean_object* v___x_129_; 
lean_dec(v_tc_116_);
v___x_129_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_me_113_);
return v___x_129_;
}
}
v___jp_117_:
{
lean_object* v___x_118_; uint8_t v___x_119_; 
v___x_118_ = lean_unsigned_to_nat(20u);
v___x_119_ = lean_nat_dec_le(v___x_118_, v_tc_116_);
if (v___x_119_ == 0)
{
lean_object* v___x_120_; 
lean_dec(v_tc_116_);
v___x_120_ = lean_box(0);
return v___x_120_;
}
else
{
lean_object* v___x_121_; uint8_t v___x_122_; 
v___x_121_ = lean_unsigned_to_nat(22u);
v___x_122_ = lean_nat_dec_le(v_tc_116_, v___x_121_);
lean_dec(v_tc_116_);
if (v___x_122_ == 0)
{
lean_object* v___x_123_; 
v___x_123_ = lean_box(0);
return v___x_123_;
}
else
{
lean_object* v___x_124_; 
v___x_124_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_me_113_);
return v___x_124_;
}
}
}
}
default: 
{
lean_object* v___x_130_; 
v___x_130_ = lean_box(0);
return v___x_130_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude___boxed(lean_object* v_f_131_){
_start:
{
lean_object* v_res_132_; 
v_res_132_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_f_131_);
lean_dec_ref(v_f_131_);
return v_res_132_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameIdentity(lean_object* v_f_133_){
_start:
{
lean_object* v_body_134_; 
v_body_134_ = lean_ctor_get(v_f_133_, 0);
switch(lean_obj_tag(v_body_134_))
{
case 1:
{
uint8_t v_identity_135_; 
v_identity_135_ = lean_ctor_get_uint8(v_body_134_, sizeof(void*)*1);
if (v_identity_135_ == 1)
{
lean_object* v_fields_136_; lean_object* v_code_137_; lean_object* v___x_138_; lean_object* v___x_139_; 
v_fields_136_ = lean_ctor_get(v_body_134_, 0);
v_code_137_ = lean_ctor_get(v_fields_136_, 3);
v___x_138_ = lp_lean1090_Lean1090_Impl_identityCode(v_code_137_);
v___x_139_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_139_, 0, v___x_138_);
return v___x_139_;
}
else
{
lean_object* v___x_140_; 
v___x_140_ = lean_box(0);
return v___x_140_;
}
}
case 6:
{
uint8_t v_identity_141_; 
v_identity_141_ = lean_ctor_get_uint8(v_body_134_, sizeof(void*)*2);
if (v_identity_141_ == 1)
{
lean_object* v_fields_142_; lean_object* v_code_143_; lean_object* v___x_144_; lean_object* v___x_145_; 
v_fields_142_ = lean_ctor_get(v_body_134_, 0);
v_code_143_ = lean_ctor_get(v_fields_142_, 3);
v___x_144_ = lp_lean1090_Lean1090_Impl_identityCode(v_code_143_);
v___x_145_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_145_, 0, v___x_144_);
return v___x_145_;
}
else
{
lean_object* v___x_146_; 
v___x_146_ = lean_box(0);
return v___x_146_;
}
}
case 4:
{
lean_object* v_me_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v___x_151_; uint8_t v___x_152_; 
v_me_147_ = lean_ctor_get(v_body_134_, 2);
v___x_148_ = lean_unsigned_to_nat(1u);
v___x_149_ = lean_unsigned_to_nat(5u);
v___x_150_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_147_, v___x_148_, v___x_149_);
v___x_151_ = lean_unsigned_to_nat(28u);
v___x_152_ = lean_nat_dec_eq(v___x_150_, v___x_151_);
lean_dec(v___x_150_);
if (v___x_152_ == 0)
{
lean_object* v___x_153_; 
v___x_153_ = lean_box(0);
return v___x_153_;
}
else
{
lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; 
v___x_154_ = lean_unsigned_to_nat(13u);
v___x_155_ = lean_unsigned_to_nat(12u);
v___x_156_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_147_, v___x_155_, v___x_154_);
v___x_157_ = l_BitVec_ofNat(v___x_154_, v___x_156_);
lean_dec(v___x_156_);
v___x_158_ = lp_lean1090_Lean1090_Impl_identityCode(v___x_157_);
lean_dec(v___x_157_);
v___x_159_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_159_, 0, v___x_158_);
return v___x_159_;
}
}
default: 
{
lean_object* v___x_160_; 
v___x_160_ = lean_box(0);
return v___x_160_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameIdentity___boxed(lean_object* v_f_161_){
_start:
{
lean_object* v_res_162_; 
v_res_162_ = lp_lean1090_Lean1090_Impl_frameIdentity(v_f_161_);
lean_dec_ref(v_f_161_);
return v_res_162_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameADSB(lean_object* v_f_163_){
_start:
{
lean_object* v_body_164_; 
v_body_164_ = lean_ctor_get(v_f_163_, 0);
if (lean_obj_tag(v_body_164_) == 4)
{
lean_object* v_me_165_; lean_object* v___x_166_; 
v_me_165_ = lean_ctor_get(v_body_164_, 2);
v___x_166_ = lp_lean1090_Lean1090_Impl_decodeADSB(v_me_165_);
if (lean_obj_tag(v___x_166_) == 0)
{
lean_object* v___x_167_; 
lean_dec_ref_known(v___x_166_, 1);
v___x_167_ = lean_box(0);
return v___x_167_;
}
else
{
lean_object* v_a_168_; lean_object* v___x_170_; uint8_t v_isShared_171_; uint8_t v_isSharedCheck_175_; 
v_a_168_ = lean_ctor_get(v___x_166_, 0);
v_isSharedCheck_175_ = !lean_is_exclusive(v___x_166_);
if (v_isSharedCheck_175_ == 0)
{
v___x_170_ = v___x_166_;
v_isShared_171_ = v_isSharedCheck_175_;
goto v_resetjp_169_;
}
else
{
lean_inc(v_a_168_);
lean_dec(v___x_166_);
v___x_170_ = lean_box(0);
v_isShared_171_ = v_isSharedCheck_175_;
goto v_resetjp_169_;
}
v_resetjp_169_:
{
lean_object* v___x_173_; 
if (v_isShared_171_ == 0)
{
v___x_173_ = v___x_170_;
goto v_reusejp_172_;
}
else
{
lean_object* v_reuseFailAlloc_174_; 
v_reuseFailAlloc_174_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_174_, 0, v_a_168_);
v___x_173_ = v_reuseFailAlloc_174_;
goto v_reusejp_172_;
}
v_reusejp_172_:
{
return v___x_173_;
}
}
}
}
else
{
lean_object* v___x_176_; 
v___x_176_ = lean_box(0);
return v___x_176_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameADSB___boxed(lean_object* v_f_177_){
_start:
{
lean_object* v_res_178_; 
v_res_178_ = lp_lean1090_Lean1090_Impl_frameADSB(v_f_177_);
lean_dec_ref(v_f_177_);
return v_res_178_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameCommB(lean_object* v_f_179_){
_start:
{
lean_object* v_body_180_; 
v_body_180_ = lean_ctor_get(v_f_179_, 0);
if (lean_obj_tag(v_body_180_) == 6)
{
uint8_t v_identity_181_; lean_object* v_mb_182_; lean_object* v___y_184_; 
v_identity_181_ = lean_ctor_get_uint8(v_body_180_, sizeof(void*)*2);
v_mb_182_ = lean_ctor_get(v_body_180_, 1);
if (v_identity_181_ == 0)
{
lean_object* v___x_187_; 
v___x_187_ = lean_unsigned_to_nat(20u);
v___y_184_ = v___x_187_;
goto v___jp_183_;
}
else
{
lean_object* v___x_188_; 
v___x_188_ = lean_unsigned_to_nat(21u);
v___y_184_ = v___x_188_;
goto v___jp_183_;
}
v___jp_183_:
{
lean_object* v___x_185_; lean_object* v___x_186_; 
v___x_185_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_f_179_);
v___x_186_ = lp_lean1090_Lean1090_Impl_inferCommB(v___y_184_, v___x_185_, v_mb_182_);
return v___x_186_;
}
}
else
{
lean_object* v___x_189_; 
v___x_189_ = lean_box(0);
return v___x_189_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameCommB___boxed(lean_object* v_f_190_){
_start:
{
lean_object* v_res_191_; 
v_res_191_ = lp_lean1090_Lean1090_Impl_frameCommB(v_f_190_);
lean_dec_ref(v_f_190_);
return v_res_191_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_report_spec__0(lean_object* v_mb_192_, lean_object* v_a_193_, lean_object* v_a_194_){
_start:
{
if (lean_obj_tag(v_a_193_) == 0)
{
lean_object* v___x_195_; 
v___x_195_ = l_List_reverse___redArg(v_a_194_);
return v___x_195_;
}
else
{
lean_object* v_head_196_; lean_object* v_tail_197_; lean_object* v___x_199_; uint8_t v_isShared_200_; uint8_t v_isSharedCheck_215_; 
v_head_196_ = lean_ctor_get(v_a_193_, 0);
v_tail_197_ = lean_ctor_get(v_a_193_, 1);
v_isSharedCheck_215_ = !lean_is_exclusive(v_a_193_);
if (v_isSharedCheck_215_ == 0)
{
v___x_199_ = v_a_193_;
v_isShared_200_ = v_isSharedCheck_215_;
goto v_resetjp_198_;
}
else
{
lean_inc(v_tail_197_);
lean_inc(v_head_196_);
lean_dec(v_a_193_);
v___x_199_ = lean_box(0);
v_isShared_200_ = v_isSharedCheck_215_;
goto v_resetjp_198_;
}
v_resetjp_198_:
{
lean_object* v_fst_201_; lean_object* v___x_203_; uint8_t v_isShared_204_; uint8_t v_isSharedCheck_213_; 
v_fst_201_ = lean_ctor_get(v_head_196_, 0);
v_isSharedCheck_213_ = !lean_is_exclusive(v_head_196_);
if (v_isSharedCheck_213_ == 0)
{
lean_object* v_unused_214_; 
v_unused_214_ = lean_ctor_get(v_head_196_, 1);
lean_dec(v_unused_214_);
v___x_203_ = v_head_196_;
v_isShared_204_ = v_isSharedCheck_213_;
goto v_resetjp_202_;
}
else
{
lean_inc(v_fst_201_);
lean_dec(v_head_196_);
v___x_203_ = lean_box(0);
v_isShared_204_ = v_isSharedCheck_213_;
goto v_resetjp_202_;
}
v_resetjp_202_:
{
lean_object* v___x_205_; lean_object* v___x_207_; 
v___x_205_ = lp_lean1090_Lean1090_Impl_Semantics_commB(v_fst_201_, v_mb_192_);
if (v_isShared_204_ == 0)
{
lean_ctor_set(v___x_203_, 1, v___x_205_);
v___x_207_ = v___x_203_;
goto v_reusejp_206_;
}
else
{
lean_object* v_reuseFailAlloc_212_; 
v_reuseFailAlloc_212_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_212_, 0, v_fst_201_);
lean_ctor_set(v_reuseFailAlloc_212_, 1, v___x_205_);
v___x_207_ = v_reuseFailAlloc_212_;
goto v_reusejp_206_;
}
v_reusejp_206_:
{
lean_object* v___x_209_; 
if (v_isShared_200_ == 0)
{
lean_ctor_set(v___x_199_, 1, v_a_194_);
lean_ctor_set(v___x_199_, 0, v___x_207_);
v___x_209_ = v___x_199_;
goto v_reusejp_208_;
}
else
{
lean_object* v_reuseFailAlloc_211_; 
v_reuseFailAlloc_211_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_211_, 0, v___x_207_);
lean_ctor_set(v_reuseFailAlloc_211_, 1, v_a_194_);
v___x_209_ = v_reuseFailAlloc_211_;
goto v_reusejp_208_;
}
v_reusejp_208_:
{
v_a_193_ = v_tail_197_;
v_a_194_ = v___x_209_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_report_spec__0___boxed(lean_object* v_mb_216_, lean_object* v_a_217_, lean_object* v_a_218_){
_start:
{
lean_object* v_res_219_; 
v_res_219_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_report_spec__0(v_mb_216_, v_a_217_, v_a_218_);
lean_dec(v_mb_216_);
return v_res_219_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_report(lean_object* v_f_220_){
_start:
{
lean_object* v_body_221_; lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v___y_225_; lean_object* v___y_226_; lean_object* v___y_227_; lean_object* v___y_228_; lean_object* v___y_229_; lean_object* v___y_230_; lean_object* v___y_238_; 
v_body_221_ = lean_ctor_get(v_f_220_, 0);
lean_inc_ref(v_body_221_);
lean_inc_ref_n(v_f_220_, 2);
v___x_222_ = lp_lean1090_Lean1090_Impl_frameSyndrome(v_f_220_);
v___x_223_ = lp_lean1090_Lean1090_Impl_frameAddress(v_f_220_);
if (lean_obj_tag(v_body_221_) == 2)
{
lean_object* v___x_247_; 
v___x_247_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v___x_222_);
v___y_238_ = v___x_247_;
goto v___jp_237_;
}
else
{
lean_object* v___x_248_; 
v___x_248_ = lean_box(0);
v___y_238_ = v___x_248_;
goto v___jp_237_;
}
v___jp_224_:
{
if (lean_obj_tag(v_body_221_) == 6)
{
lean_object* v_mb_231_; lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; 
v_mb_231_ = lean_ctor_get(v_body_221_, 1);
lean_inc(v_mb_231_);
lean_dec_ref_known(v_body_221_, 2);
v___x_232_ = lean_box(0);
lean_inc(v___y_225_);
v___x_233_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_report_spec__0(v_mb_231_, v___y_225_, v___x_232_);
lean_dec(v_mb_231_);
v___x_234_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_234_, 0, v___x_222_);
lean_ctor_set(v___x_234_, 1, v___x_223_);
lean_ctor_set(v___x_234_, 2, v___y_228_);
lean_ctor_set(v___x_234_, 3, v___y_227_);
lean_ctor_set(v___x_234_, 4, v___y_229_);
lean_ctor_set(v___x_234_, 5, v___y_226_);
lean_ctor_set(v___x_234_, 6, v___y_225_);
lean_ctor_set(v___x_234_, 7, v___y_230_);
lean_ctor_set(v___x_234_, 8, v___x_233_);
return v___x_234_;
}
else
{
lean_object* v___x_235_; lean_object* v___x_236_; 
lean_dec_ref(v_body_221_);
v___x_235_ = lean_box(0);
v___x_236_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_236_, 0, v___x_222_);
lean_ctor_set(v___x_236_, 1, v___x_223_);
lean_ctor_set(v___x_236_, 2, v___y_228_);
lean_ctor_set(v___x_236_, 3, v___y_227_);
lean_ctor_set(v___x_236_, 4, v___y_229_);
lean_ctor_set(v___x_236_, 5, v___y_226_);
lean_ctor_set(v___x_236_, 6, v___y_225_);
lean_ctor_set(v___x_236_, 7, v___y_230_);
lean_ctor_set(v___x_236_, 8, v___x_235_);
return v___x_236_;
}
}
v___jp_237_:
{
lean_object* v___x_239_; lean_object* v___x_240_; lean_object* v___x_241_; lean_object* v___x_242_; 
v___x_239_ = lp_lean1090_Lean1090_Impl_frameAltitude(v_f_220_);
v___x_240_ = lp_lean1090_Lean1090_Impl_frameIdentity(v_f_220_);
v___x_241_ = lp_lean1090_Lean1090_Impl_frameADSB(v_f_220_);
v___x_242_ = lp_lean1090_Lean1090_Impl_frameCommB(v_f_220_);
lean_dec_ref(v_f_220_);
if (lean_obj_tag(v_body_221_) == 4)
{
lean_object* v_me_243_; lean_object* v___x_244_; lean_object* v___x_245_; 
v_me_243_ = lean_ctor_get(v_body_221_, 2);
v___x_244_ = lp_lean1090_Lean1090_Impl_Semantics_adsb(v_me_243_);
v___x_245_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_245_, 0, v___x_244_);
v___y_225_ = v___x_242_;
v___y_226_ = v___x_241_;
v___y_227_ = v___x_239_;
v___y_228_ = v___y_238_;
v___y_229_ = v___x_240_;
v___y_230_ = v___x_245_;
goto v___jp_224_;
}
else
{
lean_object* v___x_246_; 
v___x_246_ = lean_box(0);
v___y_225_ = v___x_242_;
v___y_226_ = v___x_241_;
v___y_227_ = v___x_239_;
v___y_228_ = v___y_238_;
v___y_229_ = v___x_240_;
v___y_230_ = v___x_246_;
goto v___jp_224_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object* v_bytes_249_){
_start:
{
lean_object* v___x_250_; 
v___x_250_ = lp_lean1090_Lean1090_Impl_decodeFrame(v_bytes_249_);
if (lean_obj_tag(v___x_250_) == 0)
{
lean_object* v___x_251_; 
v___x_251_ = lean_box(0);
return v___x_251_;
}
else
{
lean_object* v_val_252_; lean_object* v___x_254_; uint8_t v_isShared_255_; uint8_t v_isSharedCheck_263_; 
v_val_252_ = lean_ctor_get(v___x_250_, 0);
v_isSharedCheck_263_ = !lean_is_exclusive(v___x_250_);
if (v_isSharedCheck_263_ == 0)
{
v___x_254_ = v___x_250_;
v_isShared_255_ = v_isSharedCheck_263_;
goto v_resetjp_253_;
}
else
{
lean_inc(v_val_252_);
lean_dec(v___x_250_);
v___x_254_ = lean_box(0);
v_isShared_255_ = v_isSharedCheck_263_;
goto v_resetjp_253_;
}
v_resetjp_253_:
{
uint8_t v___x_256_; 
lean_inc(v_val_252_);
v___x_256_ = lp_lean1090_Lean1090_Impl_frameAccepted(v_val_252_);
if (v___x_256_ == 0)
{
lean_object* v___x_257_; 
lean_del_object(v___x_254_);
lean_dec(v_val_252_);
v___x_257_ = lean_box(0);
return v___x_257_;
}
else
{
lean_object* v___x_258_; lean_object* v___x_259_; lean_object* v___x_261_; 
lean_inc(v_val_252_);
v___x_258_ = lp_lean1090_Lean1090_Impl_report(v_val_252_);
v___x_259_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_259_, 0, v_val_252_);
lean_ctor_set(v___x_259_, 1, v___x_258_);
if (v_isShared_255_ == 0)
{
lean_ctor_set(v___x_254_, 0, v___x_259_);
v___x_261_ = v___x_254_;
goto v_reusejp_260_;
}
else
{
lean_object* v_reuseFailAlloc_262_; 
v_reuseFailAlloc_262_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_262_, 0, v___x_259_);
v___x_261_ = v_reuseFailAlloc_262_;
goto v_reusejp_260_;
}
v_reusejp_260_:
{
return v___x_261_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decode___boxed(lean_object* v_bytes_264_){
_start:
{
lean_object* v_res_265_; 
v_res_265_ = lp_lean1090_Lean1090_Impl_decode(v_bytes_264_);
lean_dec(v_bytes_264_);
return v_res_265_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePrefix(lean_object* v_bytes_268_){
_start:
{
lean_object* v___x_269_; 
v___x_269_ = l_List_head_x3f___redArg(v_bytes_268_);
if (lean_obj_tag(v___x_269_) == 0)
{
lean_object* v___x_270_; 
lean_dec(v_bytes_268_);
v___x_270_ = lean_box(0);
return v___x_270_;
}
else
{
lean_object* v_val_271_; uint8_t v___x_272_; lean_object* v___x_273_; lean_object* v___x_274_; lean_object* v___x_275_; lean_object* v___x_276_; lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_279_; 
v_val_271_ = lean_ctor_get(v___x_269_, 0);
lean_inc(v_val_271_);
lean_dec_ref_known(v___x_269_, 1);
v___x_272_ = lean_unbox(v_val_271_);
lean_dec(v_val_271_);
v___x_273_ = lean_uint8_to_nat(v___x_272_);
v___x_274_ = lean_unsigned_to_nat(3u);
v___x_275_ = lean_nat_shiftr(v___x_273_, v___x_274_);
v___x_276_ = lp_lean1090_Lean1090_Impl_frameBytes(v___x_275_);
lean_dec(v___x_275_);
v___x_277_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_decodePrefix___closed__0));
lean_inc(v___x_276_);
lean_inc(v_bytes_268_);
v___x_278_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_bytes_268_, v_bytes_268_, v___x_276_, v___x_277_);
v___x_279_ = lp_lean1090_Lean1090_Impl_decode(v___x_278_);
lean_dec(v___x_278_);
if (lean_obj_tag(v___x_279_) == 0)
{
lean_object* v___x_280_; 
lean_dec(v___x_276_);
lean_dec(v_bytes_268_);
v___x_280_ = lean_box(0);
return v___x_280_;
}
else
{
lean_object* v_val_281_; lean_object* v___x_283_; uint8_t v_isShared_284_; uint8_t v_isSharedCheck_290_; 
v_val_281_ = lean_ctor_get(v___x_279_, 0);
v_isSharedCheck_290_ = !lean_is_exclusive(v___x_279_);
if (v_isSharedCheck_290_ == 0)
{
v___x_283_ = v___x_279_;
v_isShared_284_ = v_isSharedCheck_290_;
goto v_resetjp_282_;
}
else
{
lean_inc(v_val_281_);
lean_dec(v___x_279_);
v___x_283_ = lean_box(0);
v_isShared_284_ = v_isSharedCheck_290_;
goto v_resetjp_282_;
}
v_resetjp_282_:
{
lean_object* v___x_285_; lean_object* v___x_286_; lean_object* v___x_288_; 
v___x_285_ = l_List_drop___redArg(v___x_276_, v_bytes_268_);
lean_dec(v_bytes_268_);
v___x_286_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_286_, 0, v_val_281_);
lean_ctor_set(v___x_286_, 1, v___x_285_);
if (v_isShared_284_ == 0)
{
lean_ctor_set(v___x_283_, 0, v___x_286_);
v___x_288_ = v___x_283_;
goto v_reusejp_287_;
}
else
{
lean_object* v_reuseFailAlloc_289_; 
v_reuseFailAlloc_289_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_289_, 0, v___x_286_);
v___x_288_ = v_reuseFailAlloc_289_;
goto v_reusejp_287_;
}
v_reusejp_287_:
{
return v___x_288_;
}
}
}
}
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Frame(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Parity(uint8_t builtin);
lean_object* initialize_lean1090_Impl_CommB(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Semantics(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Message(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize_runtime_module();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Model_Types(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Frame(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Parity(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_CommB(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Semantics(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
