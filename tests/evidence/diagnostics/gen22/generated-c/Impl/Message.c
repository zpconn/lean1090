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
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_informationBits(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameParts(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object*, lean_object*);
lean_object* lean_nat_lxor(lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Impl_adsbHardValid(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_inferCommB(lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_identityCode(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Semantics_adsb(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object*);
lean_object* l_List_head_x3f___redArg(lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_decodeFrameWithWord(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameSyndrome(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___closed__0;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_frameAccepted(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAccepted___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome___boxed(lean_object*, lean_object*);
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
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_reportWithSyndrome(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_report(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object*);
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___closed__0(void){
_start:
{
lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; 
v___x_9_ = lean_unsigned_to_nat(0u);
v___x_10_ = lean_unsigned_to_nat(24u);
v___x_11_ = l_BitVec_ofNat(v___x_10_, v___x_9_);
return v___x_11_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome(lean_object* v_f_12_, lean_object* v_syndrome_13_){
_start:
{
lean_object* v_body_14_; 
v_body_14_ = lean_ctor_get(v_f_12_, 0);
if (lean_obj_tag(v_body_14_) == 4)
{
uint8_t v_supplementary_15_; lean_object* v_me_16_; uint8_t v___x_17_; 
v_supplementary_15_ = lean_ctor_get_uint8(v_body_14_, sizeof(void*)*3);
v_me_16_ = lean_ctor_get(v_body_14_, 2);
v___x_17_ = lp_lean1090_Lean1090_Impl_adsbHardValid(v_me_16_);
if (v___x_17_ == 0)
{
return v___x_17_;
}
else
{
if (v_supplementary_15_ == 0)
{
lean_object* v___x_18_; uint8_t v___x_19_; 
v___x_18_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___closed__0, &lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___closed__0_once, _init_lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___closed__0);
v___x_19_ = lean_nat_dec_eq(v_syndrome_13_, v___x_18_);
return v___x_19_;
}
else
{
return v_supplementary_15_;
}
}
}
else
{
uint8_t v___x_20_; 
v___x_20_ = 1;
return v___x_20_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome___boxed(lean_object* v_f_21_, lean_object* v_syndrome_22_){
_start:
{
uint8_t v_res_23_; lean_object* v_r_24_; 
v_res_23_ = lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome(v_f_21_, v_syndrome_22_);
lean_dec(v_syndrome_22_);
lean_dec_ref(v_f_21_);
v_r_24_ = lean_box(v_res_23_);
return v_r_24_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_frameAccepted(lean_object* v_f_25_){
_start:
{
lean_object* v___x_26_; uint8_t v___x_27_; 
lean_inc_ref(v_f_25_);
v___x_26_ = lp_lean1090_Lean1090_Impl_frameSyndrome(v_f_25_);
v___x_27_ = lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome(v_f_25_, v___x_26_);
lean_dec(v___x_26_);
lean_dec_ref(v_f_25_);
return v___x_27_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAccepted___boxed(lean_object* v_f_28_){
_start:
{
uint8_t v_res_29_; lean_object* v_r_30_; 
v_res_29_ = lp_lean1090_Lean1090_Impl_frameAccepted(v_f_28_);
v_r_30_ = lean_box(v_res_29_);
return v_r_30_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome(lean_object* v_f_31_, lean_object* v_syndrome_32_){
_start:
{
lean_object* v_body_33_; 
v_body_33_ = lean_ctor_get(v_f_31_, 0);
switch(lean_obj_tag(v_body_33_))
{
case 2:
{
lean_object* v_aa_34_; lean_object* v___x_35_; 
lean_dec(v_syndrome_32_);
v_aa_34_ = lean_ctor_get(v_body_33_, 1);
lean_inc(v_aa_34_);
v___x_35_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_35_, 0, v_aa_34_);
return v___x_35_;
}
case 4:
{
lean_object* v_aa_36_; lean_object* v___x_37_; 
lean_dec(v_syndrome_32_);
v_aa_36_ = lean_ctor_get(v_body_33_, 1);
lean_inc(v_aa_36_);
v___x_37_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_37_, 0, v_aa_36_);
return v___x_37_;
}
case 5:
{
lean_object* v___x_38_; 
lean_dec(v_syndrome_32_);
v___x_38_ = lean_box(0);
return v___x_38_;
}
default: 
{
lean_object* v___x_39_; 
v___x_39_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_39_, 0, v_syndrome_32_);
return v___x_39_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome___boxed(lean_object* v_f_40_, lean_object* v_syndrome_41_){
_start:
{
lean_object* v_res_42_; 
v_res_42_ = lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome(v_f_40_, v_syndrome_41_);
lean_dec_ref(v_f_40_);
return v_res_42_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAddress(lean_object* v_f_43_){
_start:
{
lean_object* v___x_44_; lean_object* v___x_45_; 
lean_inc_ref(v_f_43_);
v___x_44_ = lp_lean1090_Lean1090_Impl_frameSyndrome(v_f_43_);
v___x_45_ = lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome(v_f_43_, v___x_44_);
lean_dec_ref(v_f_43_);
return v___x_45_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAltitude(lean_object* v_f_46_){
_start:
{
lean_object* v_body_47_; 
v_body_47_ = lean_ctor_get(v_f_46_, 0);
switch(lean_obj_tag(v_body_47_))
{
case 0:
{
lean_object* v_fields_48_; lean_object* v_ac_49_; lean_object* v___x_50_; 
v_fields_48_ = lean_ctor_get(v_body_47_, 0);
v_ac_49_ = lean_ctor_get(v_fields_48_, 7);
v___x_50_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_ac_49_);
return v___x_50_;
}
case 3:
{
lean_object* v_fields_51_; lean_object* v_ac_52_; lean_object* v___x_53_; 
v_fields_51_ = lean_ctor_get(v_body_47_, 0);
v_ac_52_ = lean_ctor_get(v_fields_51_, 7);
v___x_53_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_ac_52_);
return v___x_53_;
}
case 1:
{
uint8_t v_identity_54_; 
v_identity_54_ = lean_ctor_get_uint8(v_body_47_, sizeof(void*)*1);
if (v_identity_54_ == 0)
{
lean_object* v_fields_55_; lean_object* v_code_56_; lean_object* v___x_57_; 
v_fields_55_ = lean_ctor_get(v_body_47_, 0);
v_code_56_ = lean_ctor_get(v_fields_55_, 3);
v___x_57_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_code_56_);
return v___x_57_;
}
else
{
lean_object* v___x_58_; 
v___x_58_ = lean_box(0);
return v___x_58_;
}
}
case 6:
{
uint8_t v_identity_59_; 
v_identity_59_ = lean_ctor_get_uint8(v_body_47_, sizeof(void*)*2);
if (v_identity_59_ == 0)
{
lean_object* v_fields_60_; lean_object* v_code_61_; lean_object* v___x_62_; 
v_fields_60_ = lean_ctor_get(v_body_47_, 0);
v_code_61_ = lean_ctor_get(v_fields_60_, 3);
v___x_62_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_code_61_);
return v___x_62_;
}
else
{
lean_object* v___x_63_; 
v___x_63_ = lean_box(0);
return v___x_63_;
}
}
case 4:
{
lean_object* v_me_64_; lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v_tc_67_; lean_object* v___x_68_; uint8_t v___x_89_; 
v_me_64_ = lean_ctor_get(v_body_47_, 2);
v___x_65_ = lean_unsigned_to_nat(1u);
v___x_66_ = lean_unsigned_to_nat(5u);
v_tc_67_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_64_, v___x_65_, v___x_66_);
v___x_68_ = lean_unsigned_to_nat(9u);
v___x_89_ = lean_nat_dec_le(v___x_68_, v_tc_67_);
if (v___x_89_ == 0)
{
goto v___jp_69_;
}
else
{
lean_object* v___x_90_; uint8_t v___x_91_; 
v___x_90_ = lean_unsigned_to_nat(18u);
v___x_91_ = lean_nat_dec_le(v_tc_67_, v___x_90_);
if (v___x_91_ == 0)
{
goto v___jp_69_;
}
else
{
lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___x_94_; 
lean_dec(v_tc_67_);
v___x_92_ = lean_unsigned_to_nat(12u);
v___x_93_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_64_, v___x_68_, v___x_92_);
v___x_94_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v___x_93_);
lean_dec(v___x_93_);
if (lean_obj_tag(v___x_94_) == 0)
{
lean_object* v___x_95_; 
v___x_95_ = lean_box(0);
return v___x_95_;
}
else
{
lean_object* v_val_96_; lean_object* v___x_98_; uint8_t v_isShared_99_; uint8_t v_isSharedCheck_104_; 
v_val_96_ = lean_ctor_get(v___x_94_, 0);
v_isSharedCheck_104_ = !lean_is_exclusive(v___x_94_);
if (v_isSharedCheck_104_ == 0)
{
v___x_98_ = v___x_94_;
v_isShared_99_ = v_isSharedCheck_104_;
goto v_resetjp_97_;
}
else
{
lean_inc(v_val_96_);
lean_dec(v___x_94_);
v___x_98_ = lean_box(0);
v_isShared_99_ = v_isSharedCheck_104_;
goto v_resetjp_97_;
}
v_resetjp_97_:
{
lean_object* v___x_100_; lean_object* v___x_102_; 
v___x_100_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_100_, 0, v_val_96_);
if (v_isShared_99_ == 0)
{
lean_ctor_set(v___x_98_, 0, v___x_100_);
v___x_102_ = v___x_98_;
goto v_reusejp_101_;
}
else
{
lean_object* v_reuseFailAlloc_103_; 
v_reuseFailAlloc_103_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_103_, 0, v___x_100_);
v___x_102_ = v_reuseFailAlloc_103_;
goto v_reusejp_101_;
}
v_reusejp_101_:
{
return v___x_102_;
}
}
}
}
}
v___jp_69_:
{
lean_object* v___x_70_; uint8_t v___x_71_; 
v___x_70_ = lean_unsigned_to_nat(20u);
v___x_71_ = lean_nat_dec_le(v___x_70_, v_tc_67_);
if (v___x_71_ == 0)
{
lean_object* v___x_72_; 
lean_dec(v_tc_67_);
v___x_72_ = lean_box(0);
return v___x_72_;
}
else
{
lean_object* v___x_73_; uint8_t v___x_74_; 
v___x_73_ = lean_unsigned_to_nat(22u);
v___x_74_ = lean_nat_dec_le(v_tc_67_, v___x_73_);
lean_dec(v_tc_67_);
if (v___x_74_ == 0)
{
lean_object* v___x_75_; 
v___x_75_ = lean_box(0);
return v___x_75_;
}
else
{
lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; 
v___x_76_ = lean_unsigned_to_nat(12u);
v___x_77_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_64_, v___x_68_, v___x_76_);
v___x_78_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(v___x_77_);
if (lean_obj_tag(v___x_78_) == 0)
{
lean_object* v___x_79_; 
v___x_79_ = lean_box(0);
return v___x_79_;
}
else
{
lean_object* v_val_80_; lean_object* v___x_82_; uint8_t v_isShared_83_; uint8_t v_isSharedCheck_88_; 
v_val_80_ = lean_ctor_get(v___x_78_, 0);
v_isSharedCheck_88_ = !lean_is_exclusive(v___x_78_);
if (v_isSharedCheck_88_ == 0)
{
v___x_82_ = v___x_78_;
v_isShared_83_ = v_isSharedCheck_88_;
goto v_resetjp_81_;
}
else
{
lean_inc(v_val_80_);
lean_dec(v___x_78_);
v___x_82_ = lean_box(0);
v_isShared_83_ = v_isSharedCheck_88_;
goto v_resetjp_81_;
}
v_resetjp_81_:
{
lean_object* v___x_84_; lean_object* v___x_86_; 
v___x_84_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_84_, 0, v_val_80_);
if (v_isShared_83_ == 0)
{
lean_ctor_set(v___x_82_, 0, v___x_84_);
v___x_86_ = v___x_82_;
goto v_reusejp_85_;
}
else
{
lean_object* v_reuseFailAlloc_87_; 
v_reuseFailAlloc_87_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_87_, 0, v___x_84_);
v___x_86_ = v_reuseFailAlloc_87_;
goto v_reusejp_85_;
}
v_reusejp_85_:
{
return v___x_86_;
}
}
}
}
}
}
}
default: 
{
lean_object* v___x_105_; 
v___x_105_ = lean_box(0);
return v___x_105_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameAltitude___boxed(lean_object* v_f_106_){
_start:
{
lean_object* v_res_107_; 
v_res_107_ = lp_lean1090_Lean1090_Impl_frameAltitude(v_f_106_);
lean_dec_ref(v_f_106_);
return v_res_107_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude(lean_object* v_f_108_){
_start:
{
lean_object* v_body_109_; 
v_body_109_ = lean_ctor_get(v_f_108_, 0);
switch(lean_obj_tag(v_body_109_))
{
case 0:
{
lean_object* v_fields_110_; lean_object* v_ac_111_; lean_object* v___x_112_; 
v_fields_110_ = lean_ctor_get(v_body_109_, 0);
v_ac_111_ = lean_ctor_get(v_fields_110_, 7);
v___x_112_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_ac_111_);
return v___x_112_;
}
case 3:
{
lean_object* v_fields_113_; lean_object* v_ac_114_; lean_object* v___x_115_; 
v_fields_113_ = lean_ctor_get(v_body_109_, 0);
v_ac_114_ = lean_ctor_get(v_fields_113_, 7);
v___x_115_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_ac_114_);
return v___x_115_;
}
case 1:
{
uint8_t v_identity_116_; 
v_identity_116_ = lean_ctor_get_uint8(v_body_109_, sizeof(void*)*1);
if (v_identity_116_ == 0)
{
lean_object* v_fields_117_; lean_object* v_code_118_; lean_object* v___x_119_; 
v_fields_117_ = lean_ctor_get(v_body_109_, 0);
v_code_118_ = lean_ctor_get(v_fields_117_, 3);
v___x_119_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_code_118_);
return v___x_119_;
}
else
{
lean_object* v___x_120_; 
v___x_120_ = lean_box(0);
return v___x_120_;
}
}
case 6:
{
uint8_t v_identity_121_; 
v_identity_121_ = lean_ctor_get_uint8(v_body_109_, sizeof(void*)*2);
if (v_identity_121_ == 0)
{
lean_object* v_fields_122_; lean_object* v_code_123_; lean_object* v___x_124_; 
v_fields_122_ = lean_ctor_get(v_body_109_, 0);
v_code_123_ = lean_ctor_get(v_fields_122_, 3);
v___x_124_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_code_123_);
return v___x_124_;
}
else
{
lean_object* v___x_125_; 
v___x_125_ = lean_box(0);
return v___x_125_;
}
}
case 4:
{
lean_object* v_me_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v_tc_129_; lean_object* v___x_138_; uint8_t v___x_139_; 
v_me_126_ = lean_ctor_get(v_body_109_, 2);
v___x_127_ = lean_unsigned_to_nat(1u);
v___x_128_ = lean_unsigned_to_nat(5u);
v_tc_129_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_126_, v___x_127_, v___x_128_);
v___x_138_ = lean_unsigned_to_nat(9u);
v___x_139_ = lean_nat_dec_le(v___x_138_, v_tc_129_);
if (v___x_139_ == 0)
{
goto v___jp_130_;
}
else
{
lean_object* v___x_140_; uint8_t v___x_141_; 
v___x_140_ = lean_unsigned_to_nat(18u);
v___x_141_ = lean_nat_dec_le(v_tc_129_, v___x_140_);
if (v___x_141_ == 0)
{
goto v___jp_130_;
}
else
{
lean_object* v___x_142_; 
lean_dec(v_tc_129_);
v___x_142_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_me_126_);
return v___x_142_;
}
}
v___jp_130_:
{
lean_object* v___x_131_; uint8_t v___x_132_; 
v___x_131_ = lean_unsigned_to_nat(20u);
v___x_132_ = lean_nat_dec_le(v___x_131_, v_tc_129_);
if (v___x_132_ == 0)
{
lean_object* v___x_133_; 
lean_dec(v_tc_129_);
v___x_133_ = lean_box(0);
return v___x_133_;
}
else
{
lean_object* v___x_134_; uint8_t v___x_135_; 
v___x_134_ = lean_unsigned_to_nat(22u);
v___x_135_ = lean_nat_dec_le(v_tc_129_, v___x_134_);
lean_dec(v_tc_129_);
if (v___x_135_ == 0)
{
lean_object* v___x_136_; 
v___x_136_ = lean_box(0);
return v___x_136_;
}
else
{
lean_object* v___x_137_; 
v___x_137_ = lp_lean1090_Lean1090_Impl_adsbAltitude(v_me_126_);
return v___x_137_;
}
}
}
}
default: 
{
lean_object* v___x_143_; 
v___x_143_ = lean_box(0);
return v___x_143_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameOracleAltitude___boxed(lean_object* v_f_144_){
_start:
{
lean_object* v_res_145_; 
v_res_145_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_f_144_);
lean_dec_ref(v_f_144_);
return v_res_145_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameIdentity(lean_object* v_f_146_){
_start:
{
lean_object* v_body_147_; 
v_body_147_ = lean_ctor_get(v_f_146_, 0);
switch(lean_obj_tag(v_body_147_))
{
case 1:
{
uint8_t v_identity_148_; 
v_identity_148_ = lean_ctor_get_uint8(v_body_147_, sizeof(void*)*1);
if (v_identity_148_ == 1)
{
lean_object* v_fields_149_; lean_object* v_code_150_; lean_object* v___x_151_; lean_object* v___x_152_; 
v_fields_149_ = lean_ctor_get(v_body_147_, 0);
v_code_150_ = lean_ctor_get(v_fields_149_, 3);
v___x_151_ = lp_lean1090_Lean1090_Impl_identityCode(v_code_150_);
v___x_152_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_152_, 0, v___x_151_);
return v___x_152_;
}
else
{
lean_object* v___x_153_; 
v___x_153_ = lean_box(0);
return v___x_153_;
}
}
case 6:
{
uint8_t v_identity_154_; 
v_identity_154_ = lean_ctor_get_uint8(v_body_147_, sizeof(void*)*2);
if (v_identity_154_ == 1)
{
lean_object* v_fields_155_; lean_object* v_code_156_; lean_object* v___x_157_; lean_object* v___x_158_; 
v_fields_155_ = lean_ctor_get(v_body_147_, 0);
v_code_156_ = lean_ctor_get(v_fields_155_, 3);
v___x_157_ = lp_lean1090_Lean1090_Impl_identityCode(v_code_156_);
v___x_158_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_158_, 0, v___x_157_);
return v___x_158_;
}
else
{
lean_object* v___x_159_; 
v___x_159_ = lean_box(0);
return v___x_159_;
}
}
case 4:
{
lean_object* v_me_160_; lean_object* v___x_161_; lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; uint8_t v___x_165_; 
v_me_160_ = lean_ctor_get(v_body_147_, 2);
v___x_161_ = lean_unsigned_to_nat(1u);
v___x_162_ = lean_unsigned_to_nat(5u);
v___x_163_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_160_, v___x_161_, v___x_162_);
v___x_164_ = lean_unsigned_to_nat(28u);
v___x_165_ = lean_nat_dec_eq(v___x_163_, v___x_164_);
lean_dec(v___x_163_);
if (v___x_165_ == 0)
{
lean_object* v___x_166_; 
v___x_166_ = lean_box(0);
return v___x_166_;
}
else
{
lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; lean_object* v___x_172_; 
v___x_167_ = lean_unsigned_to_nat(13u);
v___x_168_ = lean_unsigned_to_nat(12u);
v___x_169_ = lp_lean1090_Lean1090_Impl_payloadBits(v_me_160_, v___x_168_, v___x_167_);
v___x_170_ = l_BitVec_ofNat(v___x_167_, v___x_169_);
lean_dec(v___x_169_);
v___x_171_ = lp_lean1090_Lean1090_Impl_identityCode(v___x_170_);
lean_dec(v___x_170_);
v___x_172_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_172_, 0, v___x_171_);
return v___x_172_;
}
}
default: 
{
lean_object* v___x_173_; 
v___x_173_ = lean_box(0);
return v___x_173_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameIdentity___boxed(lean_object* v_f_174_){
_start:
{
lean_object* v_res_175_; 
v_res_175_ = lp_lean1090_Lean1090_Impl_frameIdentity(v_f_174_);
lean_dec_ref(v_f_174_);
return v_res_175_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameADSB(lean_object* v_f_176_){
_start:
{
lean_object* v_body_177_; 
v_body_177_ = lean_ctor_get(v_f_176_, 0);
if (lean_obj_tag(v_body_177_) == 4)
{
lean_object* v_me_178_; lean_object* v___x_179_; 
v_me_178_ = lean_ctor_get(v_body_177_, 2);
v___x_179_ = lp_lean1090_Lean1090_Impl_decodeADSB(v_me_178_);
if (lean_obj_tag(v___x_179_) == 0)
{
lean_object* v___x_180_; 
lean_dec_ref_known(v___x_179_, 1);
v___x_180_ = lean_box(0);
return v___x_180_;
}
else
{
lean_object* v_a_181_; lean_object* v___x_183_; uint8_t v_isShared_184_; uint8_t v_isSharedCheck_188_; 
v_a_181_ = lean_ctor_get(v___x_179_, 0);
v_isSharedCheck_188_ = !lean_is_exclusive(v___x_179_);
if (v_isSharedCheck_188_ == 0)
{
v___x_183_ = v___x_179_;
v_isShared_184_ = v_isSharedCheck_188_;
goto v_resetjp_182_;
}
else
{
lean_inc(v_a_181_);
lean_dec(v___x_179_);
v___x_183_ = lean_box(0);
v_isShared_184_ = v_isSharedCheck_188_;
goto v_resetjp_182_;
}
v_resetjp_182_:
{
lean_object* v___x_186_; 
if (v_isShared_184_ == 0)
{
v___x_186_ = v___x_183_;
goto v_reusejp_185_;
}
else
{
lean_object* v_reuseFailAlloc_187_; 
v_reuseFailAlloc_187_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_187_, 0, v_a_181_);
v___x_186_ = v_reuseFailAlloc_187_;
goto v_reusejp_185_;
}
v_reusejp_185_:
{
return v___x_186_;
}
}
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameADSB___boxed(lean_object* v_f_190_){
_start:
{
lean_object* v_res_191_; 
v_res_191_ = lp_lean1090_Lean1090_Impl_frameADSB(v_f_190_);
lean_dec_ref(v_f_190_);
return v_res_191_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameCommB(lean_object* v_f_192_){
_start:
{
lean_object* v_body_193_; 
v_body_193_ = lean_ctor_get(v_f_192_, 0);
if (lean_obj_tag(v_body_193_) == 6)
{
uint8_t v_identity_194_; lean_object* v_mb_195_; lean_object* v___y_197_; 
v_identity_194_ = lean_ctor_get_uint8(v_body_193_, sizeof(void*)*2);
v_mb_195_ = lean_ctor_get(v_body_193_, 1);
lean_inc(v_mb_195_);
if (v_identity_194_ == 0)
{
lean_object* v___x_200_; 
v___x_200_ = lean_unsigned_to_nat(20u);
v___y_197_ = v___x_200_;
goto v___jp_196_;
}
else
{
lean_object* v___x_201_; 
v___x_201_ = lean_unsigned_to_nat(21u);
v___y_197_ = v___x_201_;
goto v___jp_196_;
}
v___jp_196_:
{
lean_object* v___x_198_; lean_object* v___x_199_; 
v___x_198_ = lp_lean1090_Lean1090_Impl_frameOracleAltitude(v_f_192_);
lean_dec_ref(v_f_192_);
v___x_199_ = lp_lean1090_Lean1090_Impl_inferCommB(v___y_197_, v___x_198_, v_mb_195_);
return v___x_199_;
}
}
else
{
lean_object* v___x_202_; 
lean_dec_ref(v_f_192_);
v___x_202_ = lean_box(0);
return v___x_202_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0(lean_object* v_mb_203_, lean_object* v_a_204_, lean_object* v_a_205_){
_start:
{
if (lean_obj_tag(v_a_204_) == 0)
{
lean_object* v___x_206_; 
v___x_206_ = l_List_reverse___redArg(v_a_205_);
return v___x_206_;
}
else
{
lean_object* v_head_207_; lean_object* v_tail_208_; lean_object* v___x_210_; uint8_t v_isShared_211_; uint8_t v_isSharedCheck_226_; 
v_head_207_ = lean_ctor_get(v_a_204_, 0);
v_tail_208_ = lean_ctor_get(v_a_204_, 1);
v_isSharedCheck_226_ = !lean_is_exclusive(v_a_204_);
if (v_isSharedCheck_226_ == 0)
{
v___x_210_ = v_a_204_;
v_isShared_211_ = v_isSharedCheck_226_;
goto v_resetjp_209_;
}
else
{
lean_inc(v_tail_208_);
lean_inc(v_head_207_);
lean_dec(v_a_204_);
v___x_210_ = lean_box(0);
v_isShared_211_ = v_isSharedCheck_226_;
goto v_resetjp_209_;
}
v_resetjp_209_:
{
lean_object* v_fst_212_; lean_object* v___x_214_; uint8_t v_isShared_215_; uint8_t v_isSharedCheck_224_; 
v_fst_212_ = lean_ctor_get(v_head_207_, 0);
v_isSharedCheck_224_ = !lean_is_exclusive(v_head_207_);
if (v_isSharedCheck_224_ == 0)
{
lean_object* v_unused_225_; 
v_unused_225_ = lean_ctor_get(v_head_207_, 1);
lean_dec(v_unused_225_);
v___x_214_ = v_head_207_;
v_isShared_215_ = v_isSharedCheck_224_;
goto v_resetjp_213_;
}
else
{
lean_inc(v_fst_212_);
lean_dec(v_head_207_);
v___x_214_ = lean_box(0);
v_isShared_215_ = v_isSharedCheck_224_;
goto v_resetjp_213_;
}
v_resetjp_213_:
{
lean_object* v___x_216_; lean_object* v___x_218_; 
v___x_216_ = lp_lean1090_Lean1090_Impl_Semantics_commB(v_fst_212_, v_mb_203_);
if (v_isShared_215_ == 0)
{
lean_ctor_set(v___x_214_, 1, v___x_216_);
v___x_218_ = v___x_214_;
goto v_reusejp_217_;
}
else
{
lean_object* v_reuseFailAlloc_223_; 
v_reuseFailAlloc_223_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_223_, 0, v_fst_212_);
lean_ctor_set(v_reuseFailAlloc_223_, 1, v___x_216_);
v___x_218_ = v_reuseFailAlloc_223_;
goto v_reusejp_217_;
}
v_reusejp_217_:
{
lean_object* v___x_220_; 
if (v_isShared_211_ == 0)
{
lean_ctor_set(v___x_210_, 1, v_a_205_);
lean_ctor_set(v___x_210_, 0, v___x_218_);
v___x_220_ = v___x_210_;
goto v_reusejp_219_;
}
else
{
lean_object* v_reuseFailAlloc_222_; 
v_reuseFailAlloc_222_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_222_, 0, v___x_218_);
lean_ctor_set(v_reuseFailAlloc_222_, 1, v_a_205_);
v___x_220_ = v_reuseFailAlloc_222_;
goto v_reusejp_219_;
}
v_reusejp_219_:
{
v_a_204_ = v_tail_208_;
v_a_205_ = v___x_220_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0___boxed(lean_object* v_mb_227_, lean_object* v_a_228_, lean_object* v_a_229_){
_start:
{
lean_object* v_res_230_; 
v_res_230_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0(v_mb_227_, v_a_228_, v_a_229_);
lean_dec(v_mb_227_);
return v_res_230_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_reportWithSyndrome(lean_object* v_f_231_, lean_object* v_syndrome_232_){
_start:
{
lean_object* v_body_233_; lean_object* v___x_234_; lean_object* v___y_236_; lean_object* v___y_237_; lean_object* v___y_238_; lean_object* v___y_239_; lean_object* v___y_240_; lean_object* v___y_241_; lean_object* v___y_249_; 
v_body_233_ = lean_ctor_get(v_f_231_, 0);
lean_inc_ref(v_body_233_);
lean_inc(v_syndrome_232_);
v___x_234_ = lp_lean1090_Lean1090_Impl_frameAddressWithSyndrome(v_f_231_, v_syndrome_232_);
if (lean_obj_tag(v_body_233_) == 2)
{
lean_object* v___x_258_; 
v___x_258_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v_syndrome_232_);
v___y_249_ = v___x_258_;
goto v___jp_248_;
}
else
{
lean_object* v___x_259_; 
v___x_259_ = lean_box(0);
v___y_249_ = v___x_259_;
goto v___jp_248_;
}
v___jp_235_:
{
if (lean_obj_tag(v_body_233_) == 6)
{
lean_object* v_mb_242_; lean_object* v___x_243_; lean_object* v___x_244_; lean_object* v___x_245_; 
v_mb_242_ = lean_ctor_get(v_body_233_, 1);
lean_inc(v_mb_242_);
lean_dec_ref_known(v_body_233_, 2);
v___x_243_ = lean_box(0);
lean_inc(v___y_240_);
v___x_244_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_reportWithSyndrome_spec__0(v_mb_242_, v___y_240_, v___x_243_);
lean_dec(v_mb_242_);
v___x_245_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_245_, 0, v_syndrome_232_);
lean_ctor_set(v___x_245_, 1, v___x_234_);
lean_ctor_set(v___x_245_, 2, v___y_237_);
lean_ctor_set(v___x_245_, 3, v___y_236_);
lean_ctor_set(v___x_245_, 4, v___y_238_);
lean_ctor_set(v___x_245_, 5, v___y_239_);
lean_ctor_set(v___x_245_, 6, v___y_240_);
lean_ctor_set(v___x_245_, 7, v___y_241_);
lean_ctor_set(v___x_245_, 8, v___x_244_);
return v___x_245_;
}
else
{
lean_object* v___x_246_; lean_object* v___x_247_; 
lean_dec_ref(v_body_233_);
v___x_246_ = lean_box(0);
v___x_247_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_247_, 0, v_syndrome_232_);
lean_ctor_set(v___x_247_, 1, v___x_234_);
lean_ctor_set(v___x_247_, 2, v___y_237_);
lean_ctor_set(v___x_247_, 3, v___y_236_);
lean_ctor_set(v___x_247_, 4, v___y_238_);
lean_ctor_set(v___x_247_, 5, v___y_239_);
lean_ctor_set(v___x_247_, 6, v___y_240_);
lean_ctor_set(v___x_247_, 7, v___y_241_);
lean_ctor_set(v___x_247_, 8, v___x_246_);
return v___x_247_;
}
}
v___jp_248_:
{
lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; lean_object* v___x_253_; 
v___x_250_ = lp_lean1090_Lean1090_Impl_frameAltitude(v_f_231_);
v___x_251_ = lp_lean1090_Lean1090_Impl_frameIdentity(v_f_231_);
v___x_252_ = lp_lean1090_Lean1090_Impl_frameADSB(v_f_231_);
v___x_253_ = lp_lean1090_Lean1090_Impl_frameCommB(v_f_231_);
if (lean_obj_tag(v_body_233_) == 4)
{
lean_object* v_me_254_; lean_object* v___x_255_; lean_object* v___x_256_; 
v_me_254_ = lean_ctor_get(v_body_233_, 2);
v___x_255_ = lp_lean1090_Lean1090_Impl_Semantics_adsb(v_me_254_);
v___x_256_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_256_, 0, v___x_255_);
v___y_236_ = v___x_250_;
v___y_237_ = v___y_249_;
v___y_238_ = v___x_251_;
v___y_239_ = v___x_252_;
v___y_240_ = v___x_253_;
v___y_241_ = v___x_256_;
goto v___jp_235_;
}
else
{
lean_object* v___x_257_; 
v___x_257_ = lean_box(0);
v___y_236_ = v___x_250_;
v___y_237_ = v___y_249_;
v___y_238_ = v___x_251_;
v___y_239_ = v___x_252_;
v___y_240_ = v___x_253_;
v___y_241_ = v___x_257_;
goto v___jp_235_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_report(lean_object* v_f_260_){
_start:
{
lean_object* v___x_261_; lean_object* v___x_262_; 
lean_inc_ref(v_f_260_);
v___x_261_ = lp_lean1090_Lean1090_Impl_frameSyndrome(v_f_260_);
v___x_262_ = lp_lean1090_Lean1090_Impl_reportWithSyndrome(v_f_260_, v___x_261_);
return v___x_262_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object* v_bytes_263_){
_start:
{
lean_object* v___x_264_; 
v___x_264_ = lp_lean1090_Lean1090_Impl_decodeFrameWithWord(v_bytes_263_);
if (lean_obj_tag(v___x_264_) == 0)
{
lean_object* v___x_265_; 
v___x_265_ = lean_box(0);
return v___x_265_;
}
else
{
lean_object* v_val_266_; lean_object* v___x_268_; uint8_t v_isShared_269_; uint8_t v_isSharedCheck_290_; 
v_val_266_ = lean_ctor_get(v___x_264_, 0);
v_isSharedCheck_290_ = !lean_is_exclusive(v___x_264_);
if (v_isSharedCheck_290_ == 0)
{
v___x_268_ = v___x_264_;
v_isShared_269_ = v_isSharedCheck_290_;
goto v_resetjp_267_;
}
else
{
lean_inc(v_val_266_);
lean_dec(v___x_264_);
v___x_268_ = lean_box(0);
v_isShared_269_ = v_isSharedCheck_290_;
goto v_resetjp_267_;
}
v_resetjp_267_:
{
lean_object* v_fst_270_; lean_object* v_snd_271_; lean_object* v___x_273_; uint8_t v_isShared_274_; uint8_t v_isSharedCheck_289_; 
v_fst_270_ = lean_ctor_get(v_val_266_, 0);
v_snd_271_ = lean_ctor_get(v_val_266_, 1);
v_isSharedCheck_289_ = !lean_is_exclusive(v_val_266_);
if (v_isSharedCheck_289_ == 0)
{
v___x_273_ = v_val_266_;
v_isShared_274_ = v_isSharedCheck_289_;
goto v_resetjp_272_;
}
else
{
lean_inc(v_snd_271_);
lean_inc(v_fst_270_);
lean_dec(v_val_266_);
v___x_273_ = lean_box(0);
v_isShared_274_ = v_isSharedCheck_289_;
goto v_resetjp_272_;
}
v_resetjp_272_:
{
lean_object* v_body_275_; lean_object* v___x_276_; lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_279_; uint8_t v___x_280_; 
v_body_275_ = lean_ctor_get(v_fst_270_, 0);
v___x_276_ = lp_lean1090_Lean1090_Impl_informationBits(v_body_275_);
v___x_277_ = lean_unsigned_to_nat(24u);
v___x_278_ = lean_nat_add(v___x_276_, v___x_277_);
lean_dec(v___x_276_);
v___x_279_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v___x_278_, v_snd_271_);
lean_dec(v_snd_271_);
v___x_280_ = lp_lean1090_Lean1090_Impl_frameAcceptedWithSyndrome(v_fst_270_, v___x_279_);
if (v___x_280_ == 0)
{
lean_object* v___x_281_; 
lean_dec(v___x_279_);
lean_del_object(v___x_273_);
lean_dec(v_fst_270_);
lean_del_object(v___x_268_);
v___x_281_ = lean_box(0);
return v___x_281_;
}
else
{
lean_object* v___x_282_; lean_object* v___x_284_; 
lean_inc(v_fst_270_);
v___x_282_ = lp_lean1090_Lean1090_Impl_reportWithSyndrome(v_fst_270_, v___x_279_);
if (v_isShared_274_ == 0)
{
lean_ctor_set(v___x_273_, 1, v___x_282_);
v___x_284_ = v___x_273_;
goto v_reusejp_283_;
}
else
{
lean_object* v_reuseFailAlloc_288_; 
v_reuseFailAlloc_288_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_288_, 0, v_fst_270_);
lean_ctor_set(v_reuseFailAlloc_288_, 1, v___x_282_);
v___x_284_ = v_reuseFailAlloc_288_;
goto v_reusejp_283_;
}
v_reusejp_283_:
{
lean_object* v___x_286_; 
if (v_isShared_269_ == 0)
{
lean_ctor_set(v___x_268_, 0, v___x_284_);
v___x_286_ = v___x_268_;
goto v_reusejp_285_;
}
else
{
lean_object* v_reuseFailAlloc_287_; 
v_reuseFailAlloc_287_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_287_, 0, v___x_284_);
v___x_286_ = v_reuseFailAlloc_287_;
goto v_reusejp_285_;
}
v_reusejp_285_:
{
return v___x_286_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePrefix(lean_object* v_bytes_293_){
_start:
{
lean_object* v___x_294_; 
v___x_294_ = l_List_head_x3f___redArg(v_bytes_293_);
if (lean_obj_tag(v___x_294_) == 0)
{
lean_object* v___x_295_; 
lean_dec(v_bytes_293_);
v___x_295_ = lean_box(0);
return v___x_295_;
}
else
{
lean_object* v_val_296_; uint8_t v___x_297_; lean_object* v___x_298_; lean_object* v___x_299_; lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_302_; lean_object* v___x_303_; lean_object* v___x_304_; 
v_val_296_ = lean_ctor_get(v___x_294_, 0);
lean_inc(v_val_296_);
lean_dec_ref_known(v___x_294_, 1);
v___x_297_ = lean_unbox(v_val_296_);
lean_dec(v_val_296_);
v___x_298_ = lean_uint8_to_nat(v___x_297_);
v___x_299_ = lean_unsigned_to_nat(3u);
v___x_300_ = lean_nat_shiftr(v___x_298_, v___x_299_);
v___x_301_ = lp_lean1090_Lean1090_Impl_frameBytes(v___x_300_);
lean_dec(v___x_300_);
v___x_302_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_decodePrefix___closed__0));
lean_inc(v___x_301_);
lean_inc(v_bytes_293_);
v___x_303_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_bytes_293_, v_bytes_293_, v___x_301_, v___x_302_);
v___x_304_ = lp_lean1090_Lean1090_Impl_decode(v___x_303_);
if (lean_obj_tag(v___x_304_) == 0)
{
lean_object* v___x_305_; 
lean_dec(v___x_301_);
lean_dec(v_bytes_293_);
v___x_305_ = lean_box(0);
return v___x_305_;
}
else
{
lean_object* v_val_306_; lean_object* v___x_308_; uint8_t v_isShared_309_; uint8_t v_isSharedCheck_315_; 
v_val_306_ = lean_ctor_get(v___x_304_, 0);
v_isSharedCheck_315_ = !lean_is_exclusive(v___x_304_);
if (v_isSharedCheck_315_ == 0)
{
v___x_308_ = v___x_304_;
v_isShared_309_ = v_isSharedCheck_315_;
goto v_resetjp_307_;
}
else
{
lean_inc(v_val_306_);
lean_dec(v___x_304_);
v___x_308_ = lean_box(0);
v_isShared_309_ = v_isSharedCheck_315_;
goto v_resetjp_307_;
}
v_resetjp_307_:
{
lean_object* v___x_310_; lean_object* v___x_311_; lean_object* v___x_313_; 
v___x_310_ = l_List_drop___redArg(v___x_301_, v_bytes_293_);
lean_dec(v_bytes_293_);
v___x_311_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_311_, 0, v_val_306_);
lean_ctor_set(v___x_311_, 1, v___x_310_);
if (v_isShared_309_ == 0)
{
lean_ctor_set(v___x_308_, 0, v___x_311_);
v___x_313_ = v___x_308_;
goto v_reusejp_312_;
}
else
{
lean_object* v_reuseFailAlloc_314_; 
v_reuseFailAlloc_314_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_314_, 0, v___x_311_);
v___x_313_ = v_reuseFailAlloc_314_;
goto v_reusejp_312_;
}
v_reusejp_312_:
{
return v___x_313_;
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
