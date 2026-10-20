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
lean_object* lean_nat_land(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readACAS(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readACAS___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readSurveillance(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_readSurveillance___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeFrameWithWord(lean_object*);
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeFrameWithWord(lean_object* v_bytes_43_){
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
lean_object* v_val_46_; lean_object* v___x_48_; uint8_t v_isShared_49_; uint8_t v_isSharedCheck_141_; 
v_val_46_ = lean_ctor_get(v___x_44_, 0);
v_isSharedCheck_141_ = !lean_is_exclusive(v___x_44_);
if (v_isSharedCheck_141_ == 0)
{
v___x_48_ = v___x_44_;
v_isShared_49_ = v_isSharedCheck_141_;
goto v_resetjp_47_;
}
else
{
lean_inc(v_val_46_);
lean_dec(v___x_44_);
v___x_48_ = lean_box(0);
v_isShared_49_ = v_isSharedCheck_141_;
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
lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; lean_object* v_body_65_; lean_object* v___x_71_; uint8_t v___x_72_; 
v___x_58_ = lean_unsigned_to_nat(8u);
v___x_59_ = lean_nat_mul(v___x_54_, v___x_58_);
lean_dec(v___x_54_);
v___x_60_ = lp_lean1090_Lean1090_Impl_bytesValue(v_bytes_43_);
v___x_61_ = lean_unsigned_to_nat(24u);
v___x_62_ = lean_nat_sub(v___x_59_, v___x_61_);
v___x_63_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_62_, v___x_61_, v___x_60_);
lean_dec(v___x_62_);
v___x_71_ = lean_unsigned_to_nat(0u);
v___x_72_ = lean_nat_dec_eq(v___x_53_, v___x_71_);
if (v___x_72_ == 0)
{
lean_object* v___x_73_; uint8_t v___x_74_; 
v___x_73_ = lean_unsigned_to_nat(4u);
v___x_74_ = lean_nat_dec_eq(v___x_53_, v___x_73_);
if (v___x_74_ == 0)
{
lean_object* v___x_75_; uint8_t v___x_76_; 
v___x_75_ = lean_unsigned_to_nat(5u);
v___x_76_ = lean_nat_dec_eq(v___x_53_, v___x_75_);
if (v___x_76_ == 0)
{
lean_object* v___x_77_; uint8_t v___x_78_; 
v___x_77_ = lean_unsigned_to_nat(11u);
v___x_78_ = lean_nat_dec_eq(v___x_53_, v___x_77_);
if (v___x_78_ == 0)
{
lean_object* v___x_79_; uint8_t v___x_80_; 
v___x_79_ = lean_unsigned_to_nat(16u);
v___x_80_ = lean_nat_dec_eq(v___x_53_, v___x_79_);
if (v___x_80_ == 0)
{
lean_object* v___x_81_; uint8_t v___x_82_; 
v___x_81_ = lean_unsigned_to_nat(17u);
v___x_82_ = lean_nat_dec_eq(v___x_53_, v___x_81_);
if (v___x_82_ == 0)
{
lean_object* v___x_83_; uint8_t v___x_84_; 
v___x_83_ = lean_unsigned_to_nat(18u);
v___x_84_ = lean_nat_dec_eq(v___x_53_, v___x_83_);
if (v___x_84_ == 0)
{
lean_object* v___x_85_; uint8_t v___x_86_; 
v___x_85_ = lean_unsigned_to_nat(19u);
v___x_86_ = lean_nat_dec_eq(v___x_53_, v___x_85_);
if (v___x_86_ == 0)
{
lean_object* v___x_87_; uint8_t v___x_88_; 
v___x_87_ = lean_unsigned_to_nat(20u);
v___x_88_ = lean_nat_dec_eq(v___x_53_, v___x_87_);
if (v___x_88_ == 0)
{
lean_object* v___x_89_; uint8_t v___x_90_; 
v___x_89_ = lean_unsigned_to_nat(21u);
v___x_90_ = lean_nat_dec_eq(v___x_53_, v___x_89_);
if (v___x_90_ == 0)
{
uint8_t v___x_91_; 
v___x_91_ = lean_nat_dec_le(v___x_61_, v___x_53_);
lean_dec(v___x_53_);
if (v___x_91_ == 0)
{
lean_object* v___x_92_; 
lean_dec(v___x_63_);
lean_dec(v___x_60_);
lean_dec(v___x_59_);
lean_del_object(v___x_48_);
v___x_92_ = lean_box(0);
return v___x_92_;
}
else
{
lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; 
v___x_93_ = lean_unsigned_to_nat(2u);
v___x_94_ = lean_unsigned_to_nat(1u);
v___x_95_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_93_, v___x_94_, v___x_60_);
v___x_96_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_52_, v___x_94_, v___x_60_);
v___x_97_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_73_, v___x_73_, v___x_60_);
v___x_98_ = lean_unsigned_to_nat(80u);
v___x_99_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_98_, v___x_60_);
lean_dec(v___x_59_);
v___x_100_ = lean_alloc_ctor(7, 4, 0);
lean_ctor_set(v___x_100_, 0, v___x_95_);
lean_ctor_set(v___x_100_, 1, v___x_96_);
lean_ctor_set(v___x_100_, 2, v___x_97_);
lean_ctor_set(v___x_100_, 3, v___x_99_);
v_body_65_ = v___x_100_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_101_; lean_object* v___x_102_; lean_object* v___x_103_; lean_object* v___x_104_; lean_object* v___x_105_; 
lean_dec(v___x_53_);
v___x_101_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
v___x_102_ = lean_unsigned_to_nat(32u);
v___x_103_ = lean_unsigned_to_nat(56u);
v___x_104_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_102_, v___x_103_, v___x_60_);
lean_dec(v___x_59_);
v___x_105_ = lean_alloc_ctor(6, 2, 1);
lean_ctor_set(v___x_105_, 0, v___x_101_);
lean_ctor_set(v___x_105_, 1, v___x_104_);
lean_ctor_set_uint8(v___x_105_, sizeof(void*)*2, v___x_56_);
v_body_65_ = v___x_105_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; 
lean_dec(v___x_53_);
v___x_106_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
v___x_107_ = lean_unsigned_to_nat(32u);
v___x_108_ = lean_unsigned_to_nat(56u);
v___x_109_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_107_, v___x_108_, v___x_60_);
lean_dec(v___x_59_);
v___x_110_ = lean_alloc_ctor(6, 2, 1);
lean_ctor_set(v___x_110_, 0, v___x_106_);
lean_ctor_set(v___x_110_, 1, v___x_109_);
lean_ctor_set_uint8(v___x_110_, sizeof(void*)*2, v___x_72_);
v_body_65_ = v___x_110_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; lean_object* v___x_114_; 
lean_dec(v___x_53_);
v___x_111_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_75_, v___x_52_, v___x_60_);
v___x_112_ = lean_unsigned_to_nat(80u);
v___x_113_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_112_, v___x_60_);
lean_dec(v___x_59_);
v___x_114_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_114_, 0, v___x_111_);
lean_ctor_set(v___x_114_, 1, v___x_113_);
v_body_65_ = v___x_114_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; lean_object* v___x_120_; 
lean_dec(v___x_53_);
v___x_115_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_75_, v___x_52_, v___x_60_);
v___x_116_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_61_, v___x_60_);
v___x_117_ = lean_unsigned_to_nat(32u);
v___x_118_ = lean_unsigned_to_nat(56u);
v___x_119_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_117_, v___x_118_, v___x_60_);
lean_dec(v___x_59_);
v___x_120_ = lean_alloc_ctor(4, 3, 1);
lean_ctor_set(v___x_120_, 0, v___x_115_);
lean_ctor_set(v___x_120_, 1, v___x_116_);
lean_ctor_set(v___x_120_, 2, v___x_119_);
lean_ctor_set_uint8(v___x_120_, sizeof(void*)*3, v___x_56_);
v_body_65_ = v___x_120_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v___x_125_; lean_object* v___x_126_; 
lean_dec(v___x_53_);
v___x_121_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_75_, v___x_52_, v___x_60_);
v___x_122_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_61_, v___x_60_);
v___x_123_ = lean_unsigned_to_nat(32u);
v___x_124_ = lean_unsigned_to_nat(56u);
v___x_125_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_123_, v___x_124_, v___x_60_);
lean_dec(v___x_59_);
v___x_126_ = lean_alloc_ctor(4, 3, 1);
lean_ctor_set(v___x_126_, 0, v___x_121_);
lean_ctor_set(v___x_126_, 1, v___x_122_);
lean_ctor_set(v___x_126_, 2, v___x_125_);
lean_ctor_set_uint8(v___x_126_, sizeof(void*)*3, v___x_72_);
v_body_65_ = v___x_126_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; 
lean_dec(v___x_53_);
v___x_127_ = lp_lean1090_Lean1090_Impl_readACAS(v___x_59_, v___x_60_);
v___x_128_ = lean_unsigned_to_nat(32u);
v___x_129_ = lean_unsigned_to_nat(56u);
v___x_130_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_128_, v___x_129_, v___x_60_);
lean_dec(v___x_59_);
v___x_131_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_131_, 0, v___x_127_);
lean_ctor_set(v___x_131_, 1, v___x_130_);
v_body_65_ = v___x_131_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; 
lean_dec(v___x_53_);
v___x_132_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_75_, v___x_52_, v___x_60_);
v___x_133_ = lp_lean1090_Lean1090_Impl_field(v___x_59_, v___x_58_, v___x_61_, v___x_60_);
lean_dec(v___x_59_);
v___x_134_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_134_, 0, v___x_132_);
lean_ctor_set(v___x_134_, 1, v___x_133_);
v_body_65_ = v___x_134_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_135_; lean_object* v___x_136_; 
lean_dec(v___x_53_);
v___x_135_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
lean_dec(v___x_59_);
v___x_136_ = lean_alloc_ctor(1, 1, 1);
lean_ctor_set(v___x_136_, 0, v___x_135_);
lean_ctor_set_uint8(v___x_136_, sizeof(void*)*1, v___x_56_);
v_body_65_ = v___x_136_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_137_; lean_object* v___x_138_; 
lean_dec(v___x_53_);
v___x_137_ = lp_lean1090_Lean1090_Impl_readSurveillance(v___x_59_, v___x_60_);
lean_dec(v___x_59_);
v___x_138_ = lean_alloc_ctor(1, 1, 1);
lean_ctor_set(v___x_138_, 0, v___x_137_);
lean_ctor_set_uint8(v___x_138_, sizeof(void*)*1, v___x_72_);
v_body_65_ = v___x_138_;
goto v___jp_64_;
}
}
else
{
lean_object* v___x_139_; lean_object* v___x_140_; 
lean_dec(v___x_53_);
v___x_139_ = lp_lean1090_Lean1090_Impl_readACAS(v___x_59_, v___x_60_);
lean_dec(v___x_59_);
v___x_140_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_140_, 0, v___x_139_);
v_body_65_ = v___x_140_;
goto v___jp_64_;
}
v___jp_64_:
{
lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v___x_69_; 
v___x_66_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_66_, 0, v_body_65_);
lean_ctor_set(v___x_66_, 1, v___x_63_);
v___x_67_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_67_, 0, v___x_66_);
lean_ctor_set(v___x_67_, 1, v___x_60_);
if (v_isShared_49_ == 0)
{
lean_ctor_set(v___x_48_, 0, v___x_67_);
v___x_69_ = v___x_48_;
goto v_reusejp_68_;
}
else
{
lean_object* v_reuseFailAlloc_70_; 
v_reuseFailAlloc_70_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_70_, 0, v___x_67_);
v___x_69_ = v_reuseFailAlloc_70_;
goto v_reusejp_68_;
}
v_reusejp_68_:
{
return v___x_69_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodeFrame(lean_object* v_bytes_142_){
_start:
{
lean_object* v___x_143_; 
v___x_143_ = lp_lean1090_Lean1090_Impl_decodeFrameWithWord(v_bytes_142_);
if (lean_obj_tag(v___x_143_) == 0)
{
lean_object* v___x_144_; 
v___x_144_ = lean_box(0);
return v___x_144_;
}
else
{
lean_object* v_val_145_; lean_object* v___x_147_; uint8_t v_isShared_148_; uint8_t v_isSharedCheck_153_; 
v_val_145_ = lean_ctor_get(v___x_143_, 0);
v_isSharedCheck_153_ = !lean_is_exclusive(v___x_143_);
if (v_isSharedCheck_153_ == 0)
{
v___x_147_ = v___x_143_;
v_isShared_148_ = v_isSharedCheck_153_;
goto v_resetjp_146_;
}
else
{
lean_inc(v_val_145_);
lean_dec(v___x_143_);
v___x_147_ = lean_box(0);
v_isShared_148_ = v_isSharedCheck_153_;
goto v_resetjp_146_;
}
v_resetjp_146_:
{
lean_object* v_fst_149_; lean_object* v___x_151_; 
v_fst_149_ = lean_ctor_get(v_val_145_, 0);
lean_inc(v_fst_149_);
lean_dec(v_val_145_);
if (v_isShared_148_ == 0)
{
lean_ctor_set(v___x_147_, 0, v_fst_149_);
v___x_151_ = v___x_147_;
goto v_reusejp_150_;
}
else
{
lean_object* v_reuseFailAlloc_152_; 
v_reuseFailAlloc_152_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_152_, 0, v_fst_149_);
v___x_151_ = v_reuseFailAlloc_152_;
goto v_reusejp_150_;
}
v_reusejp_150_:
{
return v___x_151_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_acasParts(lean_object* v_f_154_){
_start:
{
lean_object* v_vs_155_; lean_object* v_cc_156_; lean_object* v_spare1_157_; lean_object* v_sl_158_; lean_object* v_spare2_159_; lean_object* v_ri_160_; lean_object* v_spare3_161_; lean_object* v_ac_162_; lean_object* v___x_163_; lean_object* v___x_164_; lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; lean_object* v___x_177_; lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; 
v_vs_155_ = lean_ctor_get(v_f_154_, 0);
v_cc_156_ = lean_ctor_get(v_f_154_, 1);
v_spare1_157_ = lean_ctor_get(v_f_154_, 2);
v_sl_158_ = lean_ctor_get(v_f_154_, 3);
v_spare2_159_ = lean_ctor_get(v_f_154_, 4);
v_ri_160_ = lean_ctor_get(v_f_154_, 5);
v_spare3_161_ = lean_ctor_get(v_f_154_, 6);
v_ac_162_ = lean_ctor_get(v_f_154_, 7);
v___x_163_ = lean_unsigned_to_nat(1u);
lean_inc(v_vs_155_);
v___x_164_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_164_, 0, v___x_163_);
lean_ctor_set(v___x_164_, 1, v_vs_155_);
lean_inc(v_cc_156_);
v___x_165_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_165_, 0, v___x_163_);
lean_ctor_set(v___x_165_, 1, v_cc_156_);
lean_inc(v_spare1_157_);
v___x_166_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_166_, 0, v___x_163_);
lean_ctor_set(v___x_166_, 1, v_spare1_157_);
v___x_167_ = lean_unsigned_to_nat(3u);
lean_inc(v_sl_158_);
v___x_168_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_168_, 0, v___x_167_);
lean_ctor_set(v___x_168_, 1, v_sl_158_);
v___x_169_ = lean_unsigned_to_nat(2u);
lean_inc(v_spare2_159_);
v___x_170_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_170_, 0, v___x_169_);
lean_ctor_set(v___x_170_, 1, v_spare2_159_);
v___x_171_ = lean_unsigned_to_nat(4u);
lean_inc(v_ri_160_);
v___x_172_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_172_, 0, v___x_171_);
lean_ctor_set(v___x_172_, 1, v_ri_160_);
lean_inc(v_spare3_161_);
v___x_173_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_173_, 0, v___x_169_);
lean_ctor_set(v___x_173_, 1, v_spare3_161_);
v___x_174_ = lean_unsigned_to_nat(13u);
lean_inc(v_ac_162_);
v___x_175_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_175_, 0, v___x_174_);
lean_ctor_set(v___x_175_, 1, v_ac_162_);
v___x_176_ = lean_box(0);
v___x_177_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_177_, 0, v___x_175_);
lean_ctor_set(v___x_177_, 1, v___x_176_);
v___x_178_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_178_, 0, v___x_173_);
lean_ctor_set(v___x_178_, 1, v___x_177_);
v___x_179_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_179_, 0, v___x_172_);
lean_ctor_set(v___x_179_, 1, v___x_178_);
v___x_180_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_180_, 0, v___x_170_);
lean_ctor_set(v___x_180_, 1, v___x_179_);
v___x_181_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_181_, 0, v___x_168_);
lean_ctor_set(v___x_181_, 1, v___x_180_);
v___x_182_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_182_, 0, v___x_166_);
lean_ctor_set(v___x_182_, 1, v___x_181_);
v___x_183_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_183_, 0, v___x_165_);
lean_ctor_set(v___x_183_, 1, v___x_182_);
v___x_184_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_184_, 0, v___x_164_);
lean_ctor_set(v___x_184_, 1, v___x_183_);
return v___x_184_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_acasParts___boxed(lean_object* v_f_185_){
_start:
{
lean_object* v_res_186_; 
v_res_186_ = lp_lean1090_Lean1090_Impl_acasParts(v_f_185_);
lean_dec_ref(v_f_185_);
return v_res_186_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_surveillanceParts(lean_object* v_f_187_){
_start:
{
lean_object* v_fs_188_; lean_object* v_dr_189_; lean_object* v_um_190_; lean_object* v_code_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; 
v_fs_188_ = lean_ctor_get(v_f_187_, 0);
v_dr_189_ = lean_ctor_get(v_f_187_, 1);
v_um_190_ = lean_ctor_get(v_f_187_, 2);
v_code_191_ = lean_ctor_get(v_f_187_, 3);
v___x_192_ = lean_unsigned_to_nat(3u);
lean_inc(v_fs_188_);
v___x_193_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_193_, 0, v___x_192_);
lean_ctor_set(v___x_193_, 1, v_fs_188_);
v___x_194_ = lean_unsigned_to_nat(5u);
lean_inc(v_dr_189_);
v___x_195_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_195_, 0, v___x_194_);
lean_ctor_set(v___x_195_, 1, v_dr_189_);
v___x_196_ = lean_unsigned_to_nat(6u);
lean_inc(v_um_190_);
v___x_197_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_197_, 0, v___x_196_);
lean_ctor_set(v___x_197_, 1, v_um_190_);
v___x_198_ = lean_unsigned_to_nat(13u);
lean_inc(v_code_191_);
v___x_199_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_199_, 0, v___x_198_);
lean_ctor_set(v___x_199_, 1, v_code_191_);
v___x_200_ = lean_box(0);
v___x_201_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_201_, 0, v___x_199_);
lean_ctor_set(v___x_201_, 1, v___x_200_);
v___x_202_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_202_, 0, v___x_197_);
lean_ctor_set(v___x_202_, 1, v___x_201_);
v___x_203_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_203_, 0, v___x_195_);
lean_ctor_set(v___x_203_, 1, v___x_202_);
v___x_204_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_204_, 0, v___x_193_);
lean_ctor_set(v___x_204_, 1, v___x_203_);
return v___x_204_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_surveillanceParts___boxed(lean_object* v_f_205_){
_start:
{
lean_object* v_res_206_; 
v_res_206_ = lp_lean1090_Lean1090_Impl_surveillanceParts(v_f_205_);
lean_dec_ref(v_f_205_);
return v_res_206_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameParts(lean_object* v_x_222_){
_start:
{
switch(lean_obj_tag(v_x_222_))
{
case 0:
{
lean_object* v_fields_223_; lean_object* v___x_224_; lean_object* v___x_225_; lean_object* v___x_226_; 
v_fields_223_ = lean_ctor_get(v_x_222_, 0);
lean_inc_ref(v_fields_223_);
lean_dec_ref_known(v_x_222_, 1);
v___x_224_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__0));
v___x_225_ = lp_lean1090_Lean1090_Impl_acasParts(v_fields_223_);
lean_dec_ref(v_fields_223_);
v___x_226_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_226_, 0, v___x_224_);
lean_ctor_set(v___x_226_, 1, v___x_225_);
return v___x_226_;
}
case 1:
{
uint8_t v_identity_227_; lean_object* v_fields_228_; lean_object* v___x_229_; lean_object* v___y_231_; 
v_identity_227_ = lean_ctor_get_uint8(v_x_222_, sizeof(void*)*1);
v_fields_228_ = lean_ctor_get(v_x_222_, 0);
lean_inc_ref(v_fields_228_);
lean_dec_ref_known(v_x_222_, 1);
v___x_229_ = lean_unsigned_to_nat(5u);
if (v_identity_227_ == 0)
{
lean_object* v___x_235_; 
v___x_235_ = lean_unsigned_to_nat(4u);
v___y_231_ = v___x_235_;
goto v___jp_230_;
}
else
{
v___y_231_ = v___x_229_;
goto v___jp_230_;
}
v___jp_230_:
{
lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; 
v___x_232_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_232_, 0, v___x_229_);
lean_ctor_set(v___x_232_, 1, v___y_231_);
v___x_233_ = lp_lean1090_Lean1090_Impl_surveillanceParts(v_fields_228_);
lean_dec_ref(v_fields_228_);
v___x_234_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_234_, 0, v___x_232_);
lean_ctor_set(v___x_234_, 1, v___x_233_);
return v___x_234_;
}
}
case 2:
{
lean_object* v_ca_236_; lean_object* v_aa_237_; lean_object* v___x_239_; uint8_t v_isShared_240_; uint8_t v_isSharedCheck_252_; 
v_ca_236_ = lean_ctor_get(v_x_222_, 0);
v_aa_237_ = lean_ctor_get(v_x_222_, 1);
v_isSharedCheck_252_ = !lean_is_exclusive(v_x_222_);
if (v_isSharedCheck_252_ == 0)
{
v___x_239_ = v_x_222_;
v_isShared_240_ = v_isSharedCheck_252_;
goto v_resetjp_238_;
}
else
{
lean_inc(v_aa_237_);
lean_inc(v_ca_236_);
lean_dec(v_x_222_);
v___x_239_ = lean_box(0);
v_isShared_240_ = v_isSharedCheck_252_;
goto v_resetjp_238_;
}
v_resetjp_238_:
{
lean_object* v___x_241_; lean_object* v___x_242_; lean_object* v___x_244_; 
v___x_241_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__1));
v___x_242_ = lean_unsigned_to_nat(3u);
if (v_isShared_240_ == 0)
{
lean_ctor_set_tag(v___x_239_, 0);
lean_ctor_set(v___x_239_, 1, v_ca_236_);
lean_ctor_set(v___x_239_, 0, v___x_242_);
v___x_244_ = v___x_239_;
goto v_reusejp_243_;
}
else
{
lean_object* v_reuseFailAlloc_251_; 
v_reuseFailAlloc_251_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_251_, 0, v___x_242_);
lean_ctor_set(v_reuseFailAlloc_251_, 1, v_ca_236_);
v___x_244_ = v_reuseFailAlloc_251_;
goto v_reusejp_243_;
}
v_reusejp_243_:
{
lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_247_; lean_object* v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; 
v___x_245_ = lean_unsigned_to_nat(24u);
v___x_246_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_246_, 0, v___x_245_);
lean_ctor_set(v___x_246_, 1, v_aa_237_);
v___x_247_ = lean_box(0);
v___x_248_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_248_, 0, v___x_246_);
lean_ctor_set(v___x_248_, 1, v___x_247_);
v___x_249_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_249_, 0, v___x_244_);
lean_ctor_set(v___x_249_, 1, v___x_248_);
v___x_250_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_250_, 0, v___x_241_);
lean_ctor_set(v___x_250_, 1, v___x_249_);
return v___x_250_;
}
}
}
case 3:
{
lean_object* v_fields_253_; lean_object* v_mv_254_; lean_object* v___x_256_; uint8_t v_isShared_257_; uint8_t v_isSharedCheck_268_; 
v_fields_253_ = lean_ctor_get(v_x_222_, 0);
v_mv_254_ = lean_ctor_get(v_x_222_, 1);
v_isSharedCheck_268_ = !lean_is_exclusive(v_x_222_);
if (v_isSharedCheck_268_ == 0)
{
v___x_256_ = v_x_222_;
v_isShared_257_ = v_isSharedCheck_268_;
goto v_resetjp_255_;
}
else
{
lean_inc(v_mv_254_);
lean_inc(v_fields_253_);
lean_dec(v_x_222_);
v___x_256_ = lean_box(0);
v_isShared_257_ = v_isSharedCheck_268_;
goto v_resetjp_255_;
}
v_resetjp_255_:
{
lean_object* v___x_258_; lean_object* v___x_259_; lean_object* v___x_261_; 
v___x_258_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__2));
v___x_259_ = lp_lean1090_Lean1090_Impl_acasParts(v_fields_253_);
lean_dec_ref(v_fields_253_);
if (v_isShared_257_ == 0)
{
lean_ctor_set_tag(v___x_256_, 1);
lean_ctor_set(v___x_256_, 1, v___x_259_);
lean_ctor_set(v___x_256_, 0, v___x_258_);
v___x_261_ = v___x_256_;
goto v_reusejp_260_;
}
else
{
lean_object* v_reuseFailAlloc_267_; 
v_reuseFailAlloc_267_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_267_, 0, v___x_258_);
lean_ctor_set(v_reuseFailAlloc_267_, 1, v___x_259_);
v___x_261_ = v_reuseFailAlloc_267_;
goto v_reusejp_260_;
}
v_reusejp_260_:
{
lean_object* v___x_262_; lean_object* v___x_263_; lean_object* v___x_264_; lean_object* v___x_265_; lean_object* v___x_266_; 
v___x_262_ = lean_unsigned_to_nat(56u);
v___x_263_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_263_, 0, v___x_262_);
lean_ctor_set(v___x_263_, 1, v_mv_254_);
v___x_264_ = lean_box(0);
v___x_265_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_265_, 0, v___x_263_);
lean_ctor_set(v___x_265_, 1, v___x_264_);
v___x_266_ = l_List_appendTR___redArg(v___x_261_, v___x_265_);
return v___x_266_;
}
}
}
case 4:
{
uint8_t v_supplementary_269_; lean_object* v_control_270_; lean_object* v_aa_271_; lean_object* v_me_272_; lean_object* v___x_273_; lean_object* v___y_275_; 
v_supplementary_269_ = lean_ctor_get_uint8(v_x_222_, sizeof(void*)*3);
v_control_270_ = lean_ctor_get(v_x_222_, 0);
lean_inc(v_control_270_);
v_aa_271_ = lean_ctor_get(v_x_222_, 1);
lean_inc(v_aa_271_);
v_me_272_ = lean_ctor_get(v_x_222_, 2);
lean_inc(v_me_272_);
lean_dec_ref_known(v_x_222_, 3);
v___x_273_ = lean_unsigned_to_nat(5u);
if (v_supplementary_269_ == 0)
{
lean_object* v___x_288_; 
v___x_288_ = lean_unsigned_to_nat(17u);
v___y_275_ = v___x_288_;
goto v___jp_274_;
}
else
{
lean_object* v___x_289_; 
v___x_289_ = lean_unsigned_to_nat(18u);
v___y_275_ = v___x_289_;
goto v___jp_274_;
}
v___jp_274_:
{
lean_object* v___x_276_; lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v___x_281_; lean_object* v___x_282_; lean_object* v___x_283_; lean_object* v___x_284_; lean_object* v___x_285_; lean_object* v___x_286_; lean_object* v___x_287_; 
v___x_276_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_276_, 0, v___x_273_);
lean_ctor_set(v___x_276_, 1, v___y_275_);
v___x_277_ = lean_unsigned_to_nat(3u);
v___x_278_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_278_, 0, v___x_277_);
lean_ctor_set(v___x_278_, 1, v_control_270_);
v___x_279_ = lean_unsigned_to_nat(24u);
v___x_280_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_280_, 0, v___x_279_);
lean_ctor_set(v___x_280_, 1, v_aa_271_);
v___x_281_ = lean_unsigned_to_nat(56u);
v___x_282_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_282_, 0, v___x_281_);
lean_ctor_set(v___x_282_, 1, v_me_272_);
v___x_283_ = lean_box(0);
v___x_284_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_284_, 0, v___x_282_);
lean_ctor_set(v___x_284_, 1, v___x_283_);
v___x_285_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_285_, 0, v___x_280_);
lean_ctor_set(v___x_285_, 1, v___x_284_);
v___x_286_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_286_, 0, v___x_278_);
lean_ctor_set(v___x_286_, 1, v___x_285_);
v___x_287_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_287_, 0, v___x_276_);
lean_ctor_set(v___x_287_, 1, v___x_286_);
return v___x_287_;
}
}
case 5:
{
lean_object* v_af_290_; lean_object* v_reserved_291_; lean_object* v___x_293_; uint8_t v_isShared_294_; uint8_t v_isSharedCheck_306_; 
v_af_290_ = lean_ctor_get(v_x_222_, 0);
v_reserved_291_ = lean_ctor_get(v_x_222_, 1);
v_isSharedCheck_306_ = !lean_is_exclusive(v_x_222_);
if (v_isSharedCheck_306_ == 0)
{
v___x_293_ = v_x_222_;
v_isShared_294_ = v_isSharedCheck_306_;
goto v_resetjp_292_;
}
else
{
lean_inc(v_reserved_291_);
lean_inc(v_af_290_);
lean_dec(v_x_222_);
v___x_293_ = lean_box(0);
v_isShared_294_ = v_isSharedCheck_306_;
goto v_resetjp_292_;
}
v_resetjp_292_:
{
lean_object* v___x_295_; lean_object* v___x_296_; lean_object* v___x_298_; 
v___x_295_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__3));
v___x_296_ = lean_unsigned_to_nat(3u);
if (v_isShared_294_ == 0)
{
lean_ctor_set_tag(v___x_293_, 0);
lean_ctor_set(v___x_293_, 1, v_af_290_);
lean_ctor_set(v___x_293_, 0, v___x_296_);
v___x_298_ = v___x_293_;
goto v_reusejp_297_;
}
else
{
lean_object* v_reuseFailAlloc_305_; 
v_reuseFailAlloc_305_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_305_, 0, v___x_296_);
lean_ctor_set(v_reuseFailAlloc_305_, 1, v_af_290_);
v___x_298_ = v_reuseFailAlloc_305_;
goto v_reusejp_297_;
}
v_reusejp_297_:
{
lean_object* v___x_299_; lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_302_; lean_object* v___x_303_; lean_object* v___x_304_; 
v___x_299_ = lean_unsigned_to_nat(80u);
v___x_300_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_300_, 0, v___x_299_);
lean_ctor_set(v___x_300_, 1, v_reserved_291_);
v___x_301_ = lean_box(0);
v___x_302_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_302_, 0, v___x_300_);
lean_ctor_set(v___x_302_, 1, v___x_301_);
v___x_303_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_303_, 0, v___x_298_);
lean_ctor_set(v___x_303_, 1, v___x_302_);
v___x_304_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_304_, 0, v___x_295_);
lean_ctor_set(v___x_304_, 1, v___x_303_);
return v___x_304_;
}
}
}
case 6:
{
uint8_t v_identity_307_; lean_object* v_fields_308_; lean_object* v_mb_309_; lean_object* v___x_310_; lean_object* v___y_312_; 
v_identity_307_ = lean_ctor_get_uint8(v_x_222_, sizeof(void*)*2);
v_fields_308_ = lean_ctor_get(v_x_222_, 0);
lean_inc_ref(v_fields_308_);
v_mb_309_ = lean_ctor_get(v_x_222_, 1);
lean_inc(v_mb_309_);
lean_dec_ref_known(v_x_222_, 2);
v___x_310_ = lean_unsigned_to_nat(5u);
if (v_identity_307_ == 0)
{
lean_object* v___x_321_; 
v___x_321_ = lean_unsigned_to_nat(20u);
v___y_312_ = v___x_321_;
goto v___jp_311_;
}
else
{
lean_object* v___x_322_; 
v___x_322_ = lean_unsigned_to_nat(21u);
v___y_312_ = v___x_322_;
goto v___jp_311_;
}
v___jp_311_:
{
lean_object* v___x_313_; lean_object* v___x_314_; lean_object* v___x_315_; lean_object* v___x_316_; lean_object* v___x_317_; lean_object* v___x_318_; lean_object* v___x_319_; lean_object* v___x_320_; 
v___x_313_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_313_, 0, v___x_310_);
lean_ctor_set(v___x_313_, 1, v___y_312_);
v___x_314_ = lp_lean1090_Lean1090_Impl_surveillanceParts(v_fields_308_);
lean_dec_ref(v_fields_308_);
v___x_315_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_315_, 0, v___x_313_);
lean_ctor_set(v___x_315_, 1, v___x_314_);
v___x_316_ = lean_unsigned_to_nat(56u);
v___x_317_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_317_, 0, v___x_316_);
lean_ctor_set(v___x_317_, 1, v_mb_309_);
v___x_318_ = lean_box(0);
v___x_319_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_319_, 0, v___x_317_);
lean_ctor_set(v___x_319_, 1, v___x_318_);
v___x_320_ = l_List_appendTR___redArg(v___x_315_, v___x_319_);
return v___x_320_;
}
}
default: 
{
lean_object* v_spare_323_; lean_object* v_ke_324_; lean_object* v_nd_325_; lean_object* v_md_326_; lean_object* v___x_327_; lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; lean_object* v___x_331_; lean_object* v___x_332_; lean_object* v___x_333_; lean_object* v___x_334_; lean_object* v___x_335_; lean_object* v___x_336_; lean_object* v___x_337_; lean_object* v___x_338_; lean_object* v___x_339_; lean_object* v___x_340_; 
v_spare_323_ = lean_ctor_get(v_x_222_, 0);
lean_inc(v_spare_323_);
v_ke_324_ = lean_ctor_get(v_x_222_, 1);
lean_inc(v_ke_324_);
v_nd_325_ = lean_ctor_get(v_x_222_, 2);
lean_inc(v_nd_325_);
v_md_326_ = lean_ctor_get(v_x_222_, 3);
lean_inc(v_md_326_);
lean_dec_ref_known(v_x_222_, 4);
v___x_327_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_frameParts___closed__4));
v___x_328_ = lean_unsigned_to_nat(1u);
v___x_329_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_329_, 0, v___x_328_);
lean_ctor_set(v___x_329_, 1, v_spare_323_);
v___x_330_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_330_, 0, v___x_328_);
lean_ctor_set(v___x_330_, 1, v_ke_324_);
v___x_331_ = lean_unsigned_to_nat(4u);
v___x_332_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_332_, 0, v___x_331_);
lean_ctor_set(v___x_332_, 1, v_nd_325_);
v___x_333_ = lean_unsigned_to_nat(80u);
v___x_334_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_334_, 0, v___x_333_);
lean_ctor_set(v___x_334_, 1, v_md_326_);
v___x_335_ = lean_box(0);
v___x_336_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_336_, 0, v___x_334_);
lean_ctor_set(v___x_336_, 1, v___x_335_);
v___x_337_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_337_, 0, v___x_332_);
lean_ctor_set(v___x_337_, 1, v___x_336_);
v___x_338_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_338_, 0, v___x_330_);
lean_ctor_set(v___x_338_, 1, v___x_337_);
v___x_339_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_339_, 0, v___x_329_);
lean_ctor_set(v___x_339_, 1, v___x_338_);
v___x_340_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_340_, 0, v___x_327_);
lean_ctor_set(v___x_340_, 1, v___x_339_);
return v___x_340_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_informationBits(lean_object* v_x_341_){
_start:
{
switch(lean_obj_tag(v_x_341_))
{
case 0:
{
lean_object* v___x_342_; 
v___x_342_ = lean_unsigned_to_nat(32u);
return v___x_342_;
}
case 1:
{
lean_object* v___x_343_; 
v___x_343_ = lean_unsigned_to_nat(32u);
return v___x_343_;
}
case 2:
{
lean_object* v___x_344_; 
v___x_344_ = lean_unsigned_to_nat(32u);
return v___x_344_;
}
default: 
{
lean_object* v___x_345_; 
v___x_345_ = lean_unsigned_to_nat(88u);
return v___x_345_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_informationBits___boxed(lean_object* v_x_346_){
_start:
{
lean_object* v_res_347_; 
v_res_347_ = lp_lean1090_Lean1090_Impl_informationBits(v_x_346_);
lean_dec_ref(v_x_346_);
return v_res_347_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___lam__0(lean_object* v_code_348_, lean_object* v_n_349_){
_start:
{
lean_object* v___x_350_; lean_object* v___x_351_; lean_object* v___x_352_; 
v___x_350_ = lean_nat_shiftr(v_code_348_, v_n_349_);
v___x_351_ = lean_unsigned_to_nat(1u);
v___x_352_ = lean_nat_land(v___x_350_, v___x_351_);
lean_dec(v___x_350_);
return v___x_352_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___lam__0___boxed(lean_object* v_code_353_, lean_object* v_n_354_){
_start:
{
lean_object* v_res_355_; 
v_res_355_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_353_, v_n_354_);
lean_dec(v_n_354_);
lean_dec(v_code_353_);
return v_res_355_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode(lean_object* v_code_356_){
_start:
{
lean_object* v___x_357_; lean_object* v___x_358_; lean_object* v___x_359_; lean_object* v___x_360_; lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; lean_object* v___x_364_; lean_object* v___x_365_; lean_object* v___x_366_; lean_object* v___x_367_; lean_object* v_a_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v___x_376_; lean_object* v___x_377_; lean_object* v_b_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; lean_object* v___x_382_; lean_object* v___x_383_; lean_object* v___x_384_; lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v_c_388_; lean_object* v___x_389_; lean_object* v___x_390_; lean_object* v___x_391_; lean_object* v___x_392_; lean_object* v___x_393_; lean_object* v___x_394_; lean_object* v___x_395_; lean_object* v_d_396_; lean_object* v___x_397_; lean_object* v___x_398_; lean_object* v___x_399_; lean_object* v___x_400_; lean_object* v___x_401_; lean_object* v___x_402_; lean_object* v___x_403_; lean_object* v___x_404_; 
v___x_357_ = lean_unsigned_to_nat(11u);
v___x_358_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_357_);
v___x_359_ = lean_unsigned_to_nat(2u);
v___x_360_ = lean_unsigned_to_nat(9u);
v___x_361_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_360_);
v___x_362_ = lean_nat_mul(v___x_359_, v___x_361_);
lean_dec(v___x_361_);
v___x_363_ = lean_nat_add(v___x_358_, v___x_362_);
lean_dec(v___x_362_);
lean_dec(v___x_358_);
v___x_364_ = lean_unsigned_to_nat(4u);
v___x_365_ = lean_unsigned_to_nat(7u);
v___x_366_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_365_);
v___x_367_ = lean_nat_mul(v___x_364_, v___x_366_);
lean_dec(v___x_366_);
v_a_368_ = lean_nat_add(v___x_363_, v___x_367_);
lean_dec(v___x_367_);
lean_dec(v___x_363_);
v___x_369_ = lean_unsigned_to_nat(5u);
v___x_370_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_369_);
v___x_371_ = lean_unsigned_to_nat(3u);
v___x_372_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_371_);
v___x_373_ = lean_nat_mul(v___x_359_, v___x_372_);
lean_dec(v___x_372_);
v___x_374_ = lean_nat_add(v___x_370_, v___x_373_);
lean_dec(v___x_373_);
lean_dec(v___x_370_);
v___x_375_ = lean_unsigned_to_nat(1u);
v___x_376_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_375_);
v___x_377_ = lean_nat_mul(v___x_364_, v___x_376_);
lean_dec(v___x_376_);
v_b_378_ = lean_nat_add(v___x_374_, v___x_377_);
lean_dec(v___x_377_);
lean_dec(v___x_374_);
v___x_379_ = lean_unsigned_to_nat(12u);
v___x_380_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_379_);
v___x_381_ = lean_unsigned_to_nat(10u);
v___x_382_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_381_);
v___x_383_ = lean_nat_mul(v___x_359_, v___x_382_);
lean_dec(v___x_382_);
v___x_384_ = lean_nat_add(v___x_380_, v___x_383_);
lean_dec(v___x_383_);
lean_dec(v___x_380_);
v___x_385_ = lean_unsigned_to_nat(8u);
v___x_386_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_385_);
v___x_387_ = lean_nat_mul(v___x_364_, v___x_386_);
lean_dec(v___x_386_);
v_c_388_ = lean_nat_add(v___x_384_, v___x_387_);
lean_dec(v___x_387_);
lean_dec(v___x_384_);
v___x_389_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_364_);
v___x_390_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_359_);
v___x_391_ = lean_nat_mul(v___x_359_, v___x_390_);
lean_dec(v___x_390_);
v___x_392_ = lean_nat_add(v___x_389_, v___x_391_);
lean_dec(v___x_391_);
lean_dec(v___x_389_);
v___x_393_ = lean_unsigned_to_nat(0u);
v___x_394_ = lp_lean1090_Lean1090_Impl_identityCode___lam__0(v_code_356_, v___x_393_);
v___x_395_ = lean_nat_mul(v___x_364_, v___x_394_);
lean_dec(v___x_394_);
v_d_396_ = lean_nat_add(v___x_392_, v___x_395_);
lean_dec(v___x_395_);
lean_dec(v___x_392_);
v___x_397_ = lean_unsigned_to_nat(512u);
v___x_398_ = lean_nat_mul(v___x_397_, v_a_368_);
lean_dec(v_a_368_);
v___x_399_ = lean_unsigned_to_nat(64u);
v___x_400_ = lean_nat_mul(v___x_399_, v_b_378_);
lean_dec(v_b_378_);
v___x_401_ = lean_nat_add(v___x_398_, v___x_400_);
lean_dec(v___x_400_);
lean_dec(v___x_398_);
v___x_402_ = lean_nat_mul(v___x_385_, v_c_388_);
lean_dec(v_c_388_);
v___x_403_ = lean_nat_add(v___x_401_, v___x_402_);
lean_dec(v___x_402_);
lean_dec(v___x_401_);
v___x_404_ = lean_nat_add(v___x_403_, v_d_396_);
lean_dec(v_d_396_);
lean_dec(v___x_403_);
return v___x_404_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_identityCode___boxed(lean_object* v_code_405_){
_start:
{
lean_object* v_res_406_; 
v_res_406_ = lp_lean1090_Lean1090_Impl_identityCode(v_code_405_);
lean_dec(v_code_405_);
return v_res_406_;
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
