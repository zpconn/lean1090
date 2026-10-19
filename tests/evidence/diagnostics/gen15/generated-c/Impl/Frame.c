// Lean compiler output
// Module: Impl.Frame
// Imports: public import Init public meta import Init public import Model.Types public import Impl.Bits
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
lean_object* l_List_head_x3f___redArg(lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_bytesValue(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_field(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readACAS(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readACAS___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readSurveillance(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readSurveillance___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeFrame(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_acasParts(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_acasParts___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_surveillanceParts(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_surveillanceParts___boxed(lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_frameParts___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_frameParts___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_frameParts___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_frameParts___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(11) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_frameParts___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_frameParts___closed__1_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_frameParts___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(16) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_frameParts___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_frameParts___closed__2_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_frameParts___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(19) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_frameParts___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_frameParts___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_frameParts___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)(((size_t)(3) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_frameParts___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_frameParts___closed__4_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameParts(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_informationBits(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_informationBits___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readACAS(lean_object* v_width_1_, lean_object* v_word_2_){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; lean_object* v___x_7_; lean_object* v___x_8_; lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; lean_object* v___x_12_; lean_object* v___x_13_; lean_object* v___x_14_; lean_object* v___x_15_; lean_object* v___x_16_; lean_object* v___x_17_; lean_object* v___x_18_; lean_object* v___x_19_; lean_object* v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; 
v___x_3_ = lean_unsigned_to_nat(5u);
v___x_4_ = lean_unsigned_to_nat(1u);
v___x_5_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_3_, v___x_4_, v_word_2_);
v___x_6_ = lean_unsigned_to_nat(6u);
v___x_7_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_6_, v___x_4_, v_word_2_);
v___x_8_ = lean_unsigned_to_nat(7u);
v___x_9_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_8_, v___x_4_, v_word_2_);
v___x_10_ = lean_unsigned_to_nat(8u);
v___x_11_ = lean_unsigned_to_nat(3u);
v___x_12_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_10_, v___x_11_, v_word_2_);
v___x_13_ = lean_unsigned_to_nat(11u);
v___x_14_ = lean_unsigned_to_nat(2u);
v___x_15_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_13_, v___x_14_, v_word_2_);
v___x_16_ = lean_unsigned_to_nat(13u);
v___x_17_ = lean_unsigned_to_nat(4u);
v___x_18_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_16_, v___x_17_, v_word_2_);
v___x_19_ = lean_unsigned_to_nat(17u);
v___x_20_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_19_, v___x_14_, v_word_2_);
v___x_21_ = lean_unsigned_to_nat(19u);
v___x_22_ = lp_lean1090_Lean1090_Impl_field(v_width_1_, v___x_21_, v___x_16_, v_word_2_);
v___x_23_ = lean_alloc_ctor(0, 8, 0);
lean_ctor_set(v___x_23_, 0, v___x_5_);
lean_ctor_set(v___x_23_, 1, v___x_7_);
lean_ctor_set(v___x_23_, 2, v___x_9_);
lean_ctor_set(v___x_23_, 3, v___x_12_);
lean_ctor_set(v___x_23_, 4, v___x_15_);
lean_ctor_set(v___x_23_, 5, v___x_18_);
lean_ctor_set(v___x_23_, 6, v___x_20_);
lean_ctor_set(v___x_23_, 7, v___x_22_);
return v___x_23_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readACAS___boxed(lean_object* v_width_24_, lean_object* v_word_25_){
_start:
{
lean_object* v_res_26_; 
v_res_26_ = lp_lean1090_Lean1090_Impl_readACAS(v_width_24_, v_word_25_);
lean_dec(v_word_25_);
lean_dec(v_width_24_);
return v_res_26_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readSurveillance(lean_object* v_width_27_, lean_object* v_word_28_){
_start:
{
lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; lean_object* v___x_33_; lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; 
v___x_29_ = lean_unsigned_to_nat(5u);
v___x_30_ = lean_unsigned_to_nat(3u);
v___x_31_ = lp_lean1090_Lean1090_Impl_field(v_width_27_, v___x_29_, v___x_30_, v_word_28_);
v___x_32_ = lean_unsigned_to_nat(8u);
v___x_33_ = lp_lean1090_Lean1090_Impl_field(v_width_27_, v___x_32_, v___x_29_, v_word_28_);
v___x_34_ = lean_unsigned_to_nat(13u);
v___x_35_ = lean_unsigned_to_nat(6u);
v___x_36_ = lp_lean1090_Lean1090_Impl_field(v_width_27_, v___x_34_, v___x_35_, v_word_28_);
v___x_37_ = lean_unsigned_to_nat(19u);
v___x_38_ = lp_lean1090_Lean1090_Impl_field(v_width_27_, v___x_37_, v___x_34_, v_word_28_);
v___x_39_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_39_, 0, v___x_31_);
lean_ctor_set(v___x_39_, 1, v___x_33_);
lean_ctor_set(v___x_39_, 2, v___x_36_);
lean_ctor_set(v___x_39_, 3, v___x_38_);
return v___x_39_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readSurveillance___boxed(lean_object* v_width_40_, lean_object* v_word_41_){
_start:
{
lean_object* v_res_42_; 
v_res_42_ = lp_lean1090_Lean1090_Impl_readSurveillance(v_width_40_, v_word_41_);
lean_dec(v_word_41_);
lean_dec(v_width_40_);
return v_res_42_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeFrame(lean_object* v_bytes_43_){
_start:
{
lean_object* v___x_44_; 
v___x_44_ = l_List_head_x3f___redArg(v_bytes_43_);
if (lean_obj_tag(v___x_44_) == 0)
{
lean_object* v___x_45_; 
lean_dec(v_bytes_43_);
v___x_45_ = lean_box(0);
return v___x_45_;
}
else
{
lean_object* v_val_46_; lean_object* v___x_48_; uint8_t v_isShared_49_; uint8_t v_isSharedCheck_140_; 
v_val_46_ = lean_ctor_get(v___x_44_, 0);
v_isSharedCheck_140_ = !lean_is_exclusive(v___x_44_);
if (v_isSharedCheck_140_ == 0)
{
v___x_48_ = v___x_44_;
v_isShared_49_ = v_isSharedCheck_140_;
goto v_resetjp_47_;
}
else
{
lean_inc(v_val_46_);
lean_dec(v___x_44_);
v___x_48_ = lean_box(0);
v_isShared_49_ = v_isSharedCheck_140_;
goto v_resetjp_47_;
}
v_resetjp_47_:
{
uint8_t v___x_50_; lean_object* v___x_51_; lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; uint8_t v___x_56_; 
v___x_50_ = lean_unbox(v_val_46_);
lean_dec(v_val_46_);
v___x_51_ = lean_uint8_to_nat(v___x_50_);
v___x_52_ = lean_unsigned_to_nat(3u);
v___x_53_ = lean_nat_shiftr(v___x_51_, v___x_52_);
v___x_54_ = lp_lean1090_Lean1090_Impl_frameBytes(v___x_53_);
v___x_55_ = l_List_lengthTR___redArg(v_bytes_43_);
v___x_56_ = lean_nat_dec_eq(v___x_55_, v___x_54_);
lean_dec(v___x_55_);
if (v___x_56_ == 0)
{
lean_object* v___x_57_; 
lean_dec(v___x_54_);
lean_dec(v___x_53_);
lean_del_object(v___x_48_);
lean_dec(v_bytes_43_);
v___x_57_ = lean_box(0);
return v___x_57_;
}
else
{
lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; lean_object* v_body_65_; lean_object* v___x_70_; uint8_t v___x_71_; 
v___x_58_ = lean_unsigned_to_nat(8u);
v___x_59_ = lean_nat_mul(v___x_54_, v___x_58_);
lean_dec(v___x_54_);
v___x_60_ = lp_lean1090_Lean1090_Impl_bytesValue(v_bytes_43_);
v___x_61_ = lean_unsigned_to_nat(24u);
v___x_62_ = lean_nat_sub(v___x_59_, v___x_61_);
v___x_63_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_62_, v___x_61_, v___x_60_);
lean_dec(v___x_62_);
v___x_70_ = lean_unsigned_to_nat(0u);
v___x_71_ = lean_nat_dec_eq(v___x_53_, v___x_70_);
if (v___x_71_ == 0)
{
lean_object* v___x_72_; uint8_t v___x_73_; 
v___x_72_ = lean_unsigned_to_nat(4u);
v___x_73_ = lean_nat_dec_eq(v___x_53_, v___x_72_);
if (v___x_73_ == 0)
{
lean_object* v___x_74_; uint8_t v___x_75_; 
v___x_74_ = lean_unsigned_to_nat(5u);
v___x_75_ = lean_nat_dec_eq(v___x_53_, v___x_74_);
if (v___x_75_ == 0)
{
lean_object* v___x_76_; uint8_t v___x_77_; 
v___x_76_ = lean_unsigned_to_nat(11u);
v___x_77_ = lean_nat_dec_eq(v___x_53_, v___x_76_);
if (v___x_77_ == 0)
{
lean_object* v___x_78_; uint8_t v___x_79_; 
v___x_78_ = lean_unsigned_to_nat(16u);
v___x_79_ = lean_nat_dec_eq(v___x_53_, v___x_78_);
if (v___x_79_ == 0)
{
lean_object* v___x_80_; uint8_t v___x_81_; 
v___x_80_ = lean_unsigned_to_nat(17u);
v___x_81_ = lean_nat_dec_eq(v___x_53_, v___x_80_);
if (v___x_81_ == 0)
{
lean_object* v___x_82_; uint8_t v___x_83_; 
v___x_82_ = lean_unsigned_to_nat(18u);
v___x_83_ = lean_nat_dec_eq(v___x_53_, v___x_82_);
if (v___x_83_ == 0)
{
lean_object* v___x_84_; uint8_t v___x_85_; 
v___x_84_ = lean_unsigned_to_nat(19u);
v___x_85_ = lean_nat_dec_eq(v___x_53_, v___x_84_);
if (v___x_85_ == 0)
{
lean_object* v___x_86_; uint8_t v___x_87_; 
v___x_86_ = lean_unsigned_to_nat(20u);
v___x_87_ = lean_nat_dec_eq(v___x_53_, v___x_86_);
if (v___x_87_ == 0)
{
lean_object* v___x_88_; uint8_t v___x_89_; 
v___x_88_ = lean_unsigned_to_nat(21u);
v___x_89_ = lean_nat_dec_eq(v___x_53_, v___x_88_);
if (v___x_89_ == 0)
{
uint8_t v___x_90_; 
v___x_90_ = lean_nat_dec_le(v___x_61_, v___x_53_);
lean_dec(v___x_53_);
if (v___x_90_ == 0)
{
lean_object* v___x_91_; 
lean_dec(v___x_63_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
lean_del_object(v___x_48_);
v___x_91_ = lean_box(0);
return v___x_91_;
}
else
{
lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; 
v___x_92_ = lean_unsigned_to_nat(2u);
v___x_93_ = lean_unsigned_to_nat(1u);
v___x_94_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_92_, v___x_93_, v___x_60_);
v___x_95_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_52_, v___x_93_, v___x_60_);
v___x_96_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_72_, v___x_72_, v___x_60_);
v___x_97_ = lean_unsigned_to_nat(80u);
v___x_98_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_97_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_99_ = lean_alloc_ctor(7, 4, 0);
lean_ctor_set(v___x_99_, 0, v___x_94_);
lean_ctor_set(v___x_99_, 1, v___x_95_);
lean_ctor_set(v___x_99_, 2, v___x_96_);
lean_ctor_set(v___x_99_, 3, v___x_98_);
v_body_65_ = v___x_99_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_100_; lean_object* v___x_101_; lean_object* v___x_102_; lean_object* v___x_103_; lean_object* v___x_104_; 
lean_dec(v___x_53_);
v___x_100_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
v___x_101_ = lean_unsigned_to_nat(32u);
v___x_102_ = lean_unsigned_to_nat(56u);
v___x_103_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_101_, v___x_102_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_104_ = lean_alloc_ctor(6, 2, 1);
lean_ctor_set(v___x_104_, 0, v___x_100_);
lean_ctor_set(v___x_104_, 1, v___x_103_);
lean_ctor_set_uint8(v___x_104_, sizeof(void*)*2, v___x_56_);
v_body_65_ = v___x_104_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; 
lean_dec(v___x_53_);
v___x_105_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
v___x_106_ = lean_unsigned_to_nat(32u);
v___x_107_ = lean_unsigned_to_nat(56u);
v___x_108_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_106_, v___x_107_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_109_ = lean_alloc_ctor(6, 2, 1);
lean_ctor_set(v___x_109_, 0, v___x_105_);
lean_ctor_set(v___x_109_, 1, v___x_108_);
lean_ctor_set_uint8(v___x_109_, sizeof(void*)*2, v___x_71_);
v_body_65_ = v___x_109_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_110_; lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; 
lean_dec(v___x_53_);
v___x_110_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_74_, v___x_52_, v___x_60_);
v___x_111_ = lean_unsigned_to_nat(80u);
v___x_112_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_111_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_113_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_113_, 0, v___x_110_);
lean_ctor_set(v___x_113_, 1, v___x_112_);
v_body_65_ = v___x_113_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; 
lean_dec(v___x_53_);
v___x_114_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_74_, v___x_52_, v___x_60_);
v___x_115_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_61_, v___x_60_);
v___x_116_ = lean_unsigned_to_nat(32u);
v___x_117_ = lean_unsigned_to_nat(56u);
v___x_118_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_116_, v___x_117_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_119_ = lean_alloc_ctor(4, 3, 1);
lean_ctor_set(v___x_119_, 0, v___x_114_);
lean_ctor_set(v___x_119_, 1, v___x_115_);
lean_ctor_set(v___x_119_, 2, v___x_118_);
lean_ctor_set_uint8(v___x_119_, sizeof(void*)*3, v___x_56_);
v_body_65_ = v___x_119_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_120_; lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v___x_125_; 
lean_dec(v___x_53_);
v___x_120_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_74_, v___x_52_, v___x_60_);
v___x_121_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_61_, v___x_60_);
v___x_122_ = lean_unsigned_to_nat(32u);
v___x_123_ = lean_unsigned_to_nat(56u);
v___x_124_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_122_, v___x_123_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_125_ = lean_alloc_ctor(4, 3, 1);
lean_ctor_set(v___x_125_, 0, v___x_120_);
lean_ctor_set(v___x_125_, 1, v___x_121_);
lean_ctor_set(v___x_125_, 2, v___x_124_);
lean_ctor_set_uint8(v___x_125_, sizeof(void*)*3, v___x_71_);
v_body_65_ = v___x_125_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; 
lean_dec(v___x_53_);
v___x_126_ = lp_lean1090_Lean1090_Impl_readACAS(v___x_59_, v___x_60_);
v___x_127_ = lean_unsigned_to_nat(32u);
v___x_128_ = lean_unsigned_to_nat(56u);
v___x_129_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_127_, v___x_128_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_130_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_130_, 0, v___x_126_);
lean_ctor_set(v___x_130_, 1, v___x_129_);
v_body_65_ = v___x_130_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; 
lean_dec(v___x_53_);
v___x_131_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_74_, v___x_52_, v___x_60_);
v___x_132_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_61_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_133_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_133_, 0, v___x_131_);
lean_ctor_set(v___x_133_, 1, v___x_132_);
v_body_65_ = v___x_133_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_134_; lean_object* v___x_135_; 
lean_dec(v___x_53_);
v___x_134_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_135_ = lean_alloc_ctor(1, 1, 1);
lean_ctor_set(v___x_135_, 0, v___x_134_);
lean_ctor_set_uint8(v___x_135_, sizeof(void*)*1, v___x_56_);
v_body_65_ = v___x_135_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_136_; lean_object* v___x_137_; 
lean_dec(v___x_53_);
v___x_136_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_137_ = lean_alloc_ctor(1, 1, 1);
lean_ctor_set(v___x_137_, 0, v___x_136_);
lean_ctor_set_uint8(v___x_137_, sizeof(void*)*1, v___x_71_);
v_body_65_ = v___x_137_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_138_; lean_object* v___x_139_; 
lean_dec(v___x_53_);
v___x_138_ = lp_lean1090_Lean1090_Impl_readACAS(v___x_59_, v___x_60_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
v___x_139_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_139_, 0, v___x_138_);
v_body_65_ = v___x_139_;
goto v___jp_64_;
}
v___jp_64_:
{
lean_object* v___x_66_; lean_object* v___x_68_; 
v___x_66_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_66_, 0, v_body_65_);
lean_ctor_set(v___x_66_, 1, v___x_63_);
if (v_isShared_49_ == 0)
{
lean_ctor_set(v___x_48_, 0, v___x_66_);
v___x_68_ = v___x_48_;
goto v_reusejp_67_;
}
else
{
lean_object* v_reuseFailAlloc_69_; 
v_reuseFailAlloc_69_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_69_, 0, v___x_66_);
v___x_68_ = v_reuseFailAlloc_69_;
goto v_reusejp_67_;
}
v_reusejp_67_:
{
return v___x_68_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_acasParts(lean_object* v_f_141_){
_start:
{
lean_object* v_vs_142_; lean_object* v_cc_143_; lean_object* v_spare1_144_; lean_object* v_sl_145_; lean_object* v_spare2_146_; lean_object* v_ri_147_; lean_object* v_spare3_148_; lean_object* v_ac_149_; lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; lean_object* v___x_160_; lean_object* v___x_161_; lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; 
v_vs_142_ = lean_ctor_get(v_f_141_, 0);
v_cc_143_ = lean_ctor_get(v_f_141_, 1);
v_spare1_144_ = lean_ctor_get(v_f_141_, 2);
v_sl_145_ = lean_ctor_get(v_f_141_, 3);
v_spare2_146_ = lean_ctor_get(v_f_141_, 4);
v_ri_147_ = lean_ctor_get(v_f_141_, 5);
v_spare3_148_ = lean_ctor_get(v_f_141_, 6);
v_ac_149_ = lean_ctor_get(v_f_141_, 7);
v___x_150_ = lean_unsigned_to_nat(1u);
lean_inc(v_vs_142_);
v___x_151_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_151_, 0, v___x_150_);
lean_ctor_set(v___x_151_, 1, v_vs_142_);
lean_inc(v_cc_143_);
v___x_152_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_152_, 0, v___x_150_);
lean_ctor_set(v___x_152_, 1, v_cc_143_);
lean_inc(v_spare1_144_);
v___x_153_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_153_, 0, v___x_150_);
lean_ctor_set(v___x_153_, 1, v_spare1_144_);
v___x_154_ = lean_unsigned_to_nat(3u);
lean_inc(v_sl_145_);
v___x_155_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_155_, 0, v___x_154_);
lean_ctor_set(v___x_155_, 1, v_sl_145_);
v___x_156_ = lean_unsigned_to_nat(2u);
lean_inc(v_spare2_146_);
v___x_157_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_157_, 0, v___x_156_);
lean_ctor_set(v___x_157_, 1, v_spare2_146_);
v___x_158_ = lean_unsigned_to_nat(4u);
lean_inc(v_ri_147_);
v___x_159_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_159_, 0, v___x_158_);
lean_ctor_set(v___x_159_, 1, v_ri_147_);
lean_inc(v_spare3_148_);
v___x_160_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_160_, 0, v___x_156_);
lean_ctor_set(v___x_160_, 1, v_spare3_148_);
v___x_161_ = lean_unsigned_to_nat(13u);
lean_inc(v_ac_149_);
v___x_162_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_162_, 0, v___x_161_);
lean_ctor_set(v___x_162_, 1, v_ac_149_);
v___x_163_ = lean_box(0);
v___x_164_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_164_, 0, v___x_162_);
lean_ctor_set(v___x_164_, 1, v___x_163_);
v___x_165_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_165_, 0, v___x_160_);
lean_ctor_set(v___x_165_, 1, v___x_164_);
v___x_166_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_166_, 0, v___x_159_);
lean_ctor_set(v___x_166_, 1, v___x_165_);
v___x_167_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_167_, 0, v___x_157_);
lean_ctor_set(v___x_167_, 1, v___x_166_);
v___x_168_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_168_, 0, v___x_155_);
lean_ctor_set(v___x_168_, 1, v___x_167_);
v___x_169_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_169_, 0, v___x_153_);
lean_ctor_set(v___x_169_, 1, v___x_168_);
v___x_170_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_170_, 0, v___x_152_);
lean_ctor_set(v___x_170_, 1, v___x_169_);
v___x_171_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_171_, 0, v___x_151_);
lean_ctor_set(v___x_171_, 1, v___x_170_);
return v___x_171_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_acasParts___boxed(lean_object* v_f_172_){
_start:
{
lean_object* v_res_173_; 
v_res_173_ = lp_lean1090_Lean1090_Impl_acasParts(v_f_172_);
lean_dec_ref(v_f_172_);
return v_res_173_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_surveillanceParts(lean_object* v_f_174_){
_start:
{
lean_object* v_fs_175_; lean_object* v_dr_176_; lean_object* v_um_177_; lean_object* v_code_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v___x_191_; 
v_fs_175_ = lean_ctor_get(v_f_174_, 0);
v_dr_176_ = lean_ctor_get(v_f_174_, 1);
v_um_177_ = lean_ctor_get(v_f_174_, 2);
v_code_178_ = lean_ctor_get(v_f_174_, 3);
v___x_179_ = lean_unsigned_to_nat(3u);
lean_inc(v_fs_175_);
v___x_180_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_180_, 0, v___x_179_);
lean_ctor_set(v___x_180_, 1, v_fs_175_);
v___x_181_ = lean_unsigned_to_nat(5u);
lean_inc(v_dr_176_);
v___x_182_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_182_, 0, v___x_181_);
lean_ctor_set(v___x_182_, 1, v_dr_176_);
v___x_183_ = lean_unsigned_to_nat(6u);
lean_inc(v_um_177_);
v___x_184_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_184_, 0, v___x_183_);
lean_ctor_set(v___x_184_, 1, v_um_177_);
v___x_185_ = lean_unsigned_to_nat(13u);
lean_inc(v_code_178_);
v___x_186_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_186_, 0, v___x_185_);
lean_ctor_set(v___x_186_, 1, v_code_178_);
v___x_187_ = lean_box(0);
v___x_188_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_188_, 0, v___x_186_);
lean_ctor_set(v___x_188_, 1, v___x_187_);
v___x_189_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_189_, 0, v___x_184_);
lean_ctor_set(v___x_189_, 1, v___x_188_);
v___x_190_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_190_, 0, v___x_182_);
lean_ctor_set(v___x_190_, 1, v___x_189_);
v___x_191_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_191_, 0, v___x_180_);
lean_ctor_set(v___x_191_, 1, v___x_190_);
return v___x_191_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_surveillanceParts___boxed(lean_object* v_f_192_){
_start:
{
lean_object* v_res_193_; 
v_res_193_ = lp_lean1090_Lean1090_Impl_surveillanceParts(v_f_192_);
lean_dec_ref(v_f_192_);
return v_res_193_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameParts(lean_object* v_x_209_){
_start:
{
switch(lean_obj_tag(v_x_209_))
{
case 0:
{
lean_object* v_fields_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; 
v_fields_210_ = lean_ctor_get(v_x_209_, 0);
lean_inc_ref(v_fields_210_);
lean_dec_ref_known(v_x_209_, 1);
v___x_211_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__0));
v___x_212_ = lp_lean1090_Lean1090_Impl_acasParts(v_fields_210_);
lean_dec_ref(v_fields_210_);
v___x_213_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_213_, 0, v___x_211_);
lean_ctor_set(v___x_213_, 1, v___x_212_);
return v___x_213_;
}
case 1:
{
uint8_t v_identity_214_; lean_object* v_fields_215_; lean_object* v___x_216_; lean_object* v___y_218_; 
v_identity_214_ = lean_ctor_get_uint8(v_x_209_, sizeof(void*)*1);
v_fields_215_ = lean_ctor_get(v_x_209_, 0);
lean_inc_ref(v_fields_215_);
lean_dec_ref_known(v_x_209_, 1);
v___x_216_ = lean_unsigned_to_nat(5u);
if (v_identity_214_ == 0)
{
lean_object* v___x_222_; 
v___x_222_ = lean_unsigned_to_nat(4u);
v___y_218_ = v___x_222_;
goto v___jp_217_;
}
else
{
v___y_218_ = v___x_216_;
goto v___jp_217_;
}
v___jp_217_:
{
lean_object* v___x_219_; lean_object* v___x_220_; lean_object* v___x_221_; 
v___x_219_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_219_, 0, v___x_216_);
lean_ctor_set(v___x_219_, 1, v___y_218_);
v___x_220_ = lp_lean1090_Lean1090_Impl_surveillanceParts(v_fields_215_);
lean_dec_ref(v_fields_215_);
v___x_221_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_221_, 0, v___x_219_);
lean_ctor_set(v___x_221_, 1, v___x_220_);
return v___x_221_;
}
}
case 2:
{
lean_object* v_ca_223_; lean_object* v_aa_224_; lean_object* v___x_226_; uint8_t v_isShared_227_; uint8_t v_isSharedCheck_239_; 
v_ca_223_ = lean_ctor_get(v_x_209_, 0);
v_aa_224_ = lean_ctor_get(v_x_209_, 1);
v_isSharedCheck_239_ = !lean_is_exclusive(v_x_209_);
if (v_isSharedCheck_239_ == 0)
{
v___x_226_ = v_x_209_;
v_isShared_227_ = v_isSharedCheck_239_;
goto v_resetjp_225_;
}
else
{
lean_inc(v_aa_224_);
lean_inc(v_ca_223_);
lean_dec(v_x_209_);
v___x_226_ = lean_box(0);
v_isShared_227_ = v_isSharedCheck_239_;
goto v_resetjp_225_;
}
v_resetjp_225_:
{
lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_231_; 
v___x_228_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__1));
v___x_229_ = lean_unsigned_to_nat(3u);
if (v_isShared_227_ == 0)
{
lean_ctor_set_tag(v___x_226_, 0);
lean_ctor_set(v___x_226_, 1, v_ca_223_);
lean_ctor_set(v___x_226_, 0, v___x_229_);
v___x_231_ = v___x_226_;
goto v_reusejp_230_;
}
else
{
lean_object* v_reuseFailAlloc_238_; 
v_reuseFailAlloc_238_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_238_, 0, v___x_229_);
lean_ctor_set(v_reuseFailAlloc_238_, 1, v_ca_223_);
v___x_231_ = v_reuseFailAlloc_238_;
goto v_reusejp_230_;
}
v_reusejp_230_:
{
lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; lean_object* v___x_235_; lean_object* v___x_236_; lean_object* v___x_237_; 
v___x_232_ = lean_unsigned_to_nat(24u);
v___x_233_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_233_, 0, v___x_232_);
lean_ctor_set(v___x_233_, 1, v_aa_224_);
v___x_234_ = lean_box(0);
v___x_235_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_235_, 0, v___x_233_);
lean_ctor_set(v___x_235_, 1, v___x_234_);
v___x_236_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_236_, 0, v___x_231_);
lean_ctor_set(v___x_236_, 1, v___x_235_);
v___x_237_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_237_, 0, v___x_228_);
lean_ctor_set(v___x_237_, 1, v___x_236_);
return v___x_237_;
}
}
}
case 3:
{
lean_object* v_fields_240_; lean_object* v_mv_241_; lean_object* v___x_243_; uint8_t v_isShared_244_; uint8_t v_isSharedCheck_255_; 
v_fields_240_ = lean_ctor_get(v_x_209_, 0);
v_mv_241_ = lean_ctor_get(v_x_209_, 1);
v_isSharedCheck_255_ = !lean_is_exclusive(v_x_209_);
if (v_isSharedCheck_255_ == 0)
{
v___x_243_ = v_x_209_;
v_isShared_244_ = v_isSharedCheck_255_;
goto v_resetjp_242_;
}
else
{
lean_inc(v_mv_241_);
lean_inc(v_fields_240_);
lean_dec(v_x_209_);
v___x_243_ = lean_box(0);
v_isShared_244_ = v_isSharedCheck_255_;
goto v_resetjp_242_;
}
v_resetjp_242_:
{
lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_248_; 
v___x_245_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__2));
v___x_246_ = lp_lean1090_Lean1090_Impl_acasParts(v_fields_240_);
lean_dec_ref(v_fields_240_);
if (v_isShared_244_ == 0)
{
lean_ctor_set_tag(v___x_243_, 1);
lean_ctor_set(v___x_243_, 1, v___x_246_);
lean_ctor_set(v___x_243_, 0, v___x_245_);
v___x_248_ = v___x_243_;
goto v_reusejp_247_;
}
else
{
lean_object* v_reuseFailAlloc_254_; 
v_reuseFailAlloc_254_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_254_, 0, v___x_245_);
lean_ctor_set(v_reuseFailAlloc_254_, 1, v___x_246_);
v___x_248_ = v_reuseFailAlloc_254_;
goto v_reusejp_247_;
}
v_reusejp_247_:
{
lean_object* v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; lean_object* v___x_253_; 
v___x_249_ = lean_unsigned_to_nat(56u);
v___x_250_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_250_, 0, v___x_249_);
lean_ctor_set(v___x_250_, 1, v_mv_241_);
v___x_251_ = lean_box(0);
v___x_252_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_252_, 0, v___x_250_);
lean_ctor_set(v___x_252_, 1, v___x_251_);
v___x_253_ = l_List_appendTR___redArg(v___x_248_, v___x_252_);
return v___x_253_;
}
}
}
case 4:
{
uint8_t v_supplementary_256_; lean_object* v_control_257_; lean_object* v_aa_258_; lean_object* v_me_259_; lean_object* v___x_260_; lean_object* v___y_262_; 
v_supplementary_256_ = lean_ctor_get_uint8(v_x_209_, sizeof(void*)*3);
v_control_257_ = lean_ctor_get(v_x_209_, 0);
lean_inc(v_control_257_);
v_aa_258_ = lean_ctor_get(v_x_209_, 1);
lean_inc(v_aa_258_);
v_me_259_ = lean_ctor_get(v_x_209_, 2);
lean_inc(v_me_259_);
lean_dec_ref_known(v_x_209_, 3);
v___x_260_ = lean_unsigned_to_nat(5u);
if (v_supplementary_256_ == 0)
{
lean_object* v___x_275_; 
v___x_275_ = lean_unsigned_to_nat(17u);
v___y_262_ = v___x_275_;
goto v___jp_261_;
}
else
{
lean_object* v___x_276_; 
v___x_276_ = lean_unsigned_to_nat(18u);
v___y_262_ = v___x_276_;
goto v___jp_261_;
}
v___jp_261_:
{
lean_object* v___x_263_; lean_object* v___x_264_; lean_object* v___x_265_; lean_object* v___x_266_; lean_object* v___x_267_; lean_object* v___x_268_; lean_object* v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_272_; lean_object* v___x_273_; lean_object* v___x_274_; 
v___x_263_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_263_, 0, v___x_260_);
lean_ctor_set(v___x_263_, 1, v___y_262_);
v___x_264_ = lean_unsigned_to_nat(3u);
v___x_265_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_265_, 0, v___x_264_);
lean_ctor_set(v___x_265_, 1, v_control_257_);
v___x_266_ = lean_unsigned_to_nat(24u);
v___x_267_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_267_, 0, v___x_266_);
lean_ctor_set(v___x_267_, 1, v_aa_258_);
v___x_268_ = lean_unsigned_to_nat(56u);
v___x_269_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_269_, 0, v___x_268_);
lean_ctor_set(v___x_269_, 1, v_me_259_);
v___x_270_ = lean_box(0);
v___x_271_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_271_, 0, v___x_269_);
lean_ctor_set(v___x_271_, 1, v___x_270_);
v___x_272_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_272_, 0, v___x_267_);
lean_ctor_set(v___x_272_, 1, v___x_271_);
v___x_273_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_273_, 0, v___x_265_);
lean_ctor_set(v___x_273_, 1, v___x_272_);
v___x_274_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_274_, 0, v___x_263_);
lean_ctor_set(v___x_274_, 1, v___x_273_);
return v___x_274_;
}
}
case 5:
{
lean_object* v_af_277_; lean_object* v_reserved_278_; lean_object* v___x_280_; uint8_t v_isShared_281_; uint8_t v_isSharedCheck_293_; 
v_af_277_ = lean_ctor_get(v_x_209_, 0);
v_reserved_278_ = lean_ctor_get(v_x_209_, 1);
v_isSharedCheck_293_ = !lean_is_exclusive(v_x_209_);
if (v_isSharedCheck_293_ == 0)
{
v___x_280_ = v_x_209_;
v_isShared_281_ = v_isSharedCheck_293_;
goto v_resetjp_279_;
}
else
{
lean_inc(v_reserved_278_);
lean_inc(v_af_277_);
lean_dec(v_x_209_);
v___x_280_ = lean_box(0);
v_isShared_281_ = v_isSharedCheck_293_;
goto v_resetjp_279_;
}
v_resetjp_279_:
{
lean_object* v___x_282_; lean_object* v___x_283_; lean_object* v___x_285_; 
v___x_282_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__3));
v___x_283_ = lean_unsigned_to_nat(3u);
if (v_isShared_281_ == 0)
{
lean_ctor_set_tag(v___x_280_, 0);
lean_ctor_set(v___x_280_, 1, v_af_277_);
lean_ctor_set(v___x_280_, 0, v___x_283_);
v___x_285_ = v___x_280_;
goto v_reusejp_284_;
}
else
{
lean_object* v_reuseFailAlloc_292_; 
v_reuseFailAlloc_292_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_292_, 0, v___x_283_);
lean_ctor_set(v_reuseFailAlloc_292_, 1, v_af_277_);
v___x_285_ = v_reuseFailAlloc_292_;
goto v_reusejp_284_;
}
v_reusejp_284_:
{
lean_object* v___x_286_; lean_object* v___x_287_; lean_object* v___x_288_; lean_object* v___x_289_; lean_object* v___x_290_; lean_object* v___x_291_; 
v___x_286_ = lean_unsigned_to_nat(80u);
v___x_287_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_287_, 0, v___x_286_);
lean_ctor_set(v___x_287_, 1, v_reserved_278_);
v___x_288_ = lean_box(0);
v___x_289_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_289_, 0, v___x_287_);
lean_ctor_set(v___x_289_, 1, v___x_288_);
v___x_290_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_290_, 0, v___x_285_);
lean_ctor_set(v___x_290_, 1, v___x_289_);
v___x_291_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_291_, 0, v___x_282_);
lean_ctor_set(v___x_291_, 1, v___x_290_);
return v___x_291_;
}
}
}
case 6:
{
uint8_t v_identity_294_; lean_object* v_fields_295_; lean_object* v_mb_296_; lean_object* v___x_297_; lean_object* v___y_299_; 
v_identity_294_ = lean_ctor_get_uint8(v_x_209_, sizeof(void*)*2);
v_fields_295_ = lean_ctor_get(v_x_209_, 0);
lean_inc_ref(v_fields_295_);
v_mb_296_ = lean_ctor_get(v_x_209_, 1);
lean_inc(v_mb_296_);
lean_dec_ref_known(v_x_209_, 2);
v___x_297_ = lean_unsigned_to_nat(5u);
if (v_identity_294_ == 0)
{
lean_object* v___x_308_; 
v___x_308_ = lean_unsigned_to_nat(20u);
v___y_299_ = v___x_308_;
goto v___jp_298_;
}
else
{
lean_object* v___x_309_; 
v___x_309_ = lean_unsigned_to_nat(21u);
v___y_299_ = v___x_309_;
goto v___jp_298_;
}
v___jp_298_:
{
lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_302_; lean_object* v___x_303_; lean_object* v___x_304_; lean_object* v___x_305_; lean_object* v___x_306_; lean_object* v___x_307_; 
v___x_300_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_300_, 0, v___x_297_);
lean_ctor_set(v___x_300_, 1, v___y_299_);
v___x_301_ = lp_lean1090_Lean1090_Impl_surveillanceParts(v_fields_295_);
lean_dec_ref(v_fields_295_);
v___x_302_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_302_, 0, v___x_300_);
lean_ctor_set(v___x_302_, 1, v___x_301_);
v___x_303_ = lean_unsigned_to_nat(56u);
v___x_304_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_304_, 0, v___x_303_);
lean_ctor_set(v___x_304_, 1, v_mb_296_);
v___x_305_ = lean_box(0);
v___x_306_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_306_, 0, v___x_304_);
lean_ctor_set(v___x_306_, 1, v___x_305_);
v___x_307_ = l_List_appendTR___redArg(v___x_302_, v___x_306_);
return v___x_307_;
}
}
default: 
{
lean_object* v_spare_310_; lean_object* v_ke_311_; lean_object* v_nd_312_; lean_object* v_md_313_; lean_object* v___x_314_; lean_object* v___x_315_; lean_object* v___x_316_; lean_object* v___x_317_; lean_object* v___x_318_; lean_object* v___x_319_; lean_object* v___x_320_; lean_object* v___x_321_; lean_object* v___x_322_; lean_object* v___x_323_; lean_object* v___x_324_; lean_object* v___x_325_; lean_object* v___x_326_; lean_object* v___x_327_; 
v_spare_310_ = lean_ctor_get(v_x_209_, 0);
lean_inc(v_spare_310_);
v_ke_311_ = lean_ctor_get(v_x_209_, 1);
lean_inc(v_ke_311_);
v_nd_312_ = lean_ctor_get(v_x_209_, 2);
lean_inc(v_nd_312_);
v_md_313_ = lean_ctor_get(v_x_209_, 3);
lean_inc(v_md_313_);
lean_dec_ref_known(v_x_209_, 4);
v___x_314_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__4));
v___x_315_ = lean_unsigned_to_nat(1u);
v___x_316_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_316_, 0, v___x_315_);
lean_ctor_set(v___x_316_, 1, v_spare_310_);
v___x_317_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_317_, 0, v___x_315_);
lean_ctor_set(v___x_317_, 1, v_ke_311_);
v___x_318_ = lean_unsigned_to_nat(4u);
v___x_319_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_319_, 0, v___x_318_);
lean_ctor_set(v___x_319_, 1, v_nd_312_);
v___x_320_ = lean_unsigned_to_nat(80u);
v___x_321_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_321_, 0, v___x_320_);
lean_ctor_set(v___x_321_, 1, v_md_313_);
v___x_322_ = lean_box(0);
v___x_323_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_323_, 0, v___x_321_);
lean_ctor_set(v___x_323_, 1, v___x_322_);
v___x_324_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_324_, 0, v___x_319_);
lean_ctor_set(v___x_324_, 1, v___x_323_);
v___x_325_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_325_, 0, v___x_317_);
lean_ctor_set(v___x_325_, 1, v___x_324_);
v___x_326_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_326_, 0, v___x_316_);
lean_ctor_set(v___x_326_, 1, v___x_325_);
v___x_327_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_327_, 0, v___x_314_);
lean_ctor_set(v___x_327_, 1, v___x_326_);
return v___x_327_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_informationBits(lean_object* v_x_328_){
_start:
{
switch(lean_obj_tag(v_x_328_))
{
case 0:
{
lean_object* v___x_329_; 
v___x_329_ = lean_unsigned_to_nat(32u);
return v___x_329_;
}
case 1:
{
lean_object* v___x_330_; 
v___x_330_ = lean_unsigned_to_nat(32u);
return v___x_330_;
}
case 2:
{
lean_object* v___x_331_; 
v___x_331_ = lean_unsigned_to_nat(32u);
return v___x_331_;
}
default: 
{
lean_object* v___x_332_; 
v___x_332_ = lean_unsigned_to_nat(88u);
return v___x_332_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_informationBits___boxed(lean_object* v_x_333_){
_start:
{
lean_object* v_res_334_; 
v_res_334_ = lp_lean1090_Lean1090_Impl_informationBits(v_x_333_);
lean_dec_ref(v_x_333_);
return v_res_334_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___lam__0(lean_object* v_code_335_, lean_object* v_n_336_){
_start:
{
lean_object* v___x_337_; lean_object* v___x_338_; lean_object* v___x_339_; lean_object* v___x_340_; 
v___x_337_ = lean_unsigned_to_nat(2u);
v___x_338_ = lean_nat_pow(v___x_337_, v_n_336_);
v___x_339_ = lean_nat_div(v_code_335_, v___x_338_);
lean_dec(v___x_338_);
v___x_340_ = lean_nat_mod(v___x_339_, v___x_337_);
lean_dec(v___x_339_);
return v___x_340_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___lam__0___boxed(lean_object* v_code_341_, lean_object* v_n_342_){
_start:
{
lean_object* v_res_343_; 
v_res_343_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_341_, v_n_342_);
lean_dec(v_n_342_);
lean_dec(v_code_341_);
return v_res_343_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode(lean_object* v_code_344_){
_start:
{
lean_object* v___x_345_; lean_object* v___x_346_; lean_object* v___x_347_; lean_object* v___x_348_; lean_object* v___x_349_; lean_object* v___x_350_; lean_object* v___x_351_; lean_object* v___x_352_; lean_object* v___x_353_; lean_object* v___x_354_; lean_object* v___x_355_; lean_object* v_a_356_; lean_object* v___x_357_; lean_object* v___x_358_; lean_object* v___x_359_; lean_object* v___x_360_; lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___x_365_; lean_object* v_b_366_; lean_object* v___x_367_; lean_object* v___x_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v_c_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; lean_object* v___x_382_; lean_object* v___x_383_; lean_object* v_d_384_; lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; lean_object* v___x_389_; lean_object* v___x_390_; lean_object* v___x_391_; lean_object* v___x_392_; 
v___x_345_ = lean_unsigned_to_nat(11u);
v___x_346_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_345_);
v___x_347_ = lean_unsigned_to_nat(2u);
v___x_348_ = lean_unsigned_to_nat(9u);
v___x_349_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_348_);
v___x_350_ = lean_nat_mul(v___x_347_, v___x_349_);
lean_dec(v___x_349_);
v___x_351_ = lean_nat_add(v___x_346_, v___x_350_);
lean_dec(v___x_350_);
lean_dec(v___x_346_);
v___x_352_ = lean_unsigned_to_nat(4u);
v___x_353_ = lean_unsigned_to_nat(7u);
v___x_354_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_353_);
v___x_355_ = lean_nat_mul(v___x_352_, v___x_354_);
lean_dec(v___x_354_);
v_a_356_ = lean_nat_add(v___x_351_, v___x_355_);
lean_dec(v___x_355_);
lean_dec(v___x_351_);
v___x_357_ = lean_unsigned_to_nat(5u);
v___x_358_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_357_);
v___x_359_ = lean_unsigned_to_nat(3u);
v___x_360_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_359_);
v___x_361_ = lean_nat_mul(v___x_347_, v___x_360_);
lean_dec(v___x_360_);
v___x_362_ = lean_nat_add(v___x_358_, v___x_361_);
lean_dec(v___x_361_);
lean_dec(v___x_358_);
v___x_363_ = lean_unsigned_to_nat(1u);
v___x_364_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_363_);
v___x_365_ = lean_nat_mul(v___x_352_, v___x_364_);
lean_dec(v___x_364_);
v_b_366_ = lean_nat_add(v___x_362_, v___x_365_);
lean_dec(v___x_365_);
lean_dec(v___x_362_);
v___x_367_ = lean_unsigned_to_nat(12u);
v___x_368_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_367_);
v___x_369_ = lean_unsigned_to_nat(10u);
v___x_370_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_369_);
v___x_371_ = lean_nat_mul(v___x_347_, v___x_370_);
lean_dec(v___x_370_);
v___x_372_ = lean_nat_add(v___x_368_, v___x_371_);
lean_dec(v___x_371_);
lean_dec(v___x_368_);
v___x_373_ = lean_unsigned_to_nat(8u);
v___x_374_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_373_);
v___x_375_ = lean_nat_mul(v___x_352_, v___x_374_);
lean_dec(v___x_374_);
v_c_376_ = lean_nat_add(v___x_372_, v___x_375_);
lean_dec(v___x_375_);
lean_dec(v___x_372_);
v___x_377_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_352_);
v___x_378_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_347_);
v___x_379_ = lean_nat_mul(v___x_347_, v___x_378_);
lean_dec(v___x_378_);
v___x_380_ = lean_nat_add(v___x_377_, v___x_379_);
lean_dec(v___x_379_);
lean_dec(v___x_377_);
v___x_381_ = lean_unsigned_to_nat(0u);
v___x_382_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_344_, v___x_381_);
v___x_383_ = lean_nat_mul(v___x_352_, v___x_382_);
lean_dec(v___x_382_);
v_d_384_ = lean_nat_add(v___x_380_, v___x_383_);
lean_dec(v___x_383_);
lean_dec(v___x_380_);
v___x_385_ = lean_unsigned_to_nat(512u);
v___x_386_ = lean_nat_mul(v___x_385_, v_a_356_);
lean_dec(v_a_356_);
v___x_387_ = lean_unsigned_to_nat(64u);
v___x_388_ = lean_nat_mul(v___x_387_, v_b_366_);
lean_dec(v_b_366_);
v___x_389_ = lean_nat_add(v___x_386_, v___x_388_);
lean_dec(v___x_388_);
lean_dec(v___x_386_);
v___x_390_ = lean_nat_mul(v___x_373_, v_c_376_);
lean_dec(v_c_376_);
v___x_391_ = lean_nat_add(v___x_389_, v___x_390_);
lean_dec(v___x_390_);
lean_dec(v___x_389_);
v___x_392_ = lean_nat_add(v___x_391_, v_d_384_);
lean_dec(v_d_384_);
lean_dec(v___x_391_);
return v___x_392_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___boxed(lean_object* v_code_393_){
_start:
{
lean_object* v_res_394_; 
v_res_394_ = lp_lean1090_Lean1090_Impl_identityCode(v_code_393_);
lean_dec(v_code_393_);
return v_res_394_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Bits(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Frame(uint8_t builtin) {
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
res = initialize_lean1090_Impl_Bits(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
