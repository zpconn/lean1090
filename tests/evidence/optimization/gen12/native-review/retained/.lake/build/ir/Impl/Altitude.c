// Lean compiler output
// Module: Impl.Altitude
// Imports: public import Init public meta import Init public import Model.Types
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
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_nat_lxor(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_int_mul(lean_object*, lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_land(lean_object*, lean_object*);
lean_object* lean_nat_lor(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_bit(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_bit___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_grayDecode(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_grayDecode___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0___boxed(lean_object*, lean_object*, lean_object*);
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__0_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__0_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__1_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__1_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__2_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(7) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__2_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__3 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__3_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(9) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__3_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__4 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__4_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(11) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__4_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__5 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__5_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__5_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__6 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__6_value;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__6_value)}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__7 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__7_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray100(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray100___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Altitude_validGillham(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_validGillham___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_expandAC12(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_expandAC12___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0;
static const lean_ctor_object lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_bit(lean_object* v_word_1_, lean_object* v_place_2_){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; 
v___x_3_ = lean_unsigned_to_nat(2u);
v___x_4_ = lean_nat_pow(v___x_3_, v_place_2_);
v___x_5_ = lean_nat_div(v_word_1_, v___x_4_);
lean_dec(v___x_4_);
v___x_6_ = lean_nat_mod(v___x_5_, v___x_3_);
lean_dec(v___x_5_);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_bit___boxed(lean_object* v_word_7_, lean_object* v_place_8_){
_start:
{
lean_object* v_res_9_; 
v_res_9_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_7_, v_place_8_);
lean_dec(v_place_8_);
lean_dec(v_word_7_);
return v_res_9_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(lean_object* v_word_10_, lean_object* v_x_11_, lean_object* v_x_12_){
_start:
{
if (lean_obj_tag(v_x_12_) == 0)
{
return v_x_11_;
}
else
{
lean_object* v_head_13_; lean_object* v_tail_14_; lean_object* v___x_15_; lean_object* v___x_16_; lean_object* v___x_17_; lean_object* v___x_18_; 
v_head_13_ = lean_ctor_get(v_x_12_, 0);
v_tail_14_ = lean_ctor_get(v_x_12_, 1);
v___x_15_ = lean_unsigned_to_nat(2u);
v___x_16_ = lean_nat_pow(v___x_15_, v_head_13_);
v___x_17_ = lean_nat_div(v_word_10_, v___x_16_);
lean_dec(v___x_16_);
v___x_18_ = lean_nat_lxor(v_x_11_, v___x_17_);
lean_dec(v___x_17_);
lean_dec(v_x_11_);
v_x_11_ = v___x_18_;
v_x_12_ = v_tail_14_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0___boxed(lean_object* v_word_20_, lean_object* v_x_21_, lean_object* v_x_22_){
_start:
{
lean_object* v_res_23_; 
v_res_23_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(v_word_20_, v_x_21_, v_x_22_);
lean_dec(v_x_22_);
lean_dec(v_word_20_);
return v_res_23_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_grayDecode(lean_object* v_width_24_, lean_object* v_word_25_){
_start:
{
lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; 
v___x_26_ = lean_unsigned_to_nat(0u);
v___x_27_ = l_List_range(v_width_24_);
v___x_28_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(v_word_25_, v___x_26_, v___x_27_);
lean_dec(v___x_27_);
return v___x_28_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_grayDecode___boxed(lean_object* v_width_29_, lean_object* v_word_30_){
_start:
{
lean_object* v_res_31_; 
v_res_31_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v_width_29_, v_word_30_);
lean_dec(v_word_30_);
return v_res_31_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(lean_object* v_word_32_, lean_object* v_x_33_, lean_object* v_x_34_){
_start:
{
if (lean_obj_tag(v_x_34_) == 0)
{
return v_x_33_;
}
else
{
lean_object* v_head_35_; lean_object* v_tail_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___x_40_; 
v_head_35_ = lean_ctor_get(v_x_34_, 0);
v_tail_36_ = lean_ctor_get(v_x_34_, 1);
v___x_37_ = lean_unsigned_to_nat(2u);
v___x_38_ = lean_nat_mul(v___x_37_, v_x_33_);
lean_dec(v_x_33_);
v___x_39_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_32_, v_head_35_);
v___x_40_ = lean_nat_add(v___x_38_, v___x_39_);
lean_dec(v___x_39_);
lean_dec(v___x_38_);
v_x_33_ = v___x_40_;
v_x_34_ = v_tail_36_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0___boxed(lean_object* v_word_42_, lean_object* v_x_43_, lean_object* v_x_44_){
_start:
{
lean_object* v_res_45_; 
v_res_45_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(v_word_42_, v_x_43_, v_x_44_);
lean_dec(v_x_44_);
lean_dec(v_word_42_);
return v_res_45_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500(lean_object* v_word_70_){
_start:
{
lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v___x_73_; 
v___x_71_ = lean_unsigned_to_nat(0u);
v___x_72_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__7));
v___x_73_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(v_word_70_, v___x_71_, v___x_72_);
return v___x_73_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___boxed(lean_object* v_word_74_){
_start:
{
lean_object* v_res_75_; 
v_res_75_ = lp_lean1090_Lean1090_Impl_Altitude_gray500(v_word_74_);
lean_dec(v_word_74_);
return v_res_75_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray100(lean_object* v_word_76_){
_start:
{
lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; lean_object* v___x_85_; lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_88_; 
v___x_77_ = lean_unsigned_to_nat(4u);
v___x_78_ = lean_unsigned_to_nat(12u);
v___x_79_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_76_, v___x_78_);
v___x_80_ = lean_nat_mul(v___x_77_, v___x_79_);
lean_dec(v___x_79_);
v___x_81_ = lean_unsigned_to_nat(2u);
v___x_82_ = lean_unsigned_to_nat(10u);
v___x_83_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_76_, v___x_82_);
v___x_84_ = lean_nat_mul(v___x_81_, v___x_83_);
lean_dec(v___x_83_);
v___x_85_ = lean_nat_add(v___x_80_, v___x_84_);
lean_dec(v___x_84_);
lean_dec(v___x_80_);
v___x_86_ = lean_unsigned_to_nat(8u);
v___x_87_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_76_, v___x_86_);
v___x_88_ = lean_nat_add(v___x_85_, v___x_87_);
lean_dec(v___x_87_);
lean_dec(v___x_85_);
return v___x_88_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray100___boxed(lean_object* v_word_89_){
_start:
{
lean_object* v_res_90_; 
v_res_90_ = lp_lean1090_Lean1090_Impl_Altitude_gray100(v_word_89_);
lean_dec(v_word_89_);
return v_res_90_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Altitude_validGillham(lean_object* v_word_91_){
_start:
{
lean_object* v___x_92_; uint8_t v___x_93_; 
v___x_92_ = lean_unsigned_to_nat(8192u);
v___x_93_ = lean_nat_dec_lt(v_word_91_, v___x_92_);
if (v___x_93_ == 0)
{
return v___x_93_;
}
else
{
lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; uint8_t v___x_97_; 
v___x_94_ = lean_unsigned_to_nat(6u);
v___x_95_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_91_, v___x_94_);
v___x_96_ = lean_unsigned_to_nat(0u);
v___x_97_ = lean_nat_dec_eq(v___x_95_, v___x_96_);
lean_dec(v___x_95_);
if (v___x_97_ == 0)
{
return v___x_97_;
}
else
{
lean_object* v___x_98_; lean_object* v___x_99_; uint8_t v___x_100_; 
v___x_98_ = lean_unsigned_to_nat(4u);
v___x_99_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_91_, v___x_98_);
v___x_100_ = lean_nat_dec_eq(v___x_99_, v___x_96_);
lean_dec(v___x_99_);
if (v___x_100_ == 0)
{
return v___x_100_;
}
else
{
lean_object* v___x_101_; lean_object* v___x_102_; lean_object* v_c_103_; uint8_t v___x_104_; 
v___x_101_ = lean_unsigned_to_nat(3u);
v___x_102_ = lp_lean1090_Lean1090_Impl_Altitude_gray100(v_word_91_);
v_c_103_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v___x_101_, v___x_102_);
lean_dec(v___x_102_);
v___x_104_ = lean_nat_dec_eq(v_c_103_, v___x_96_);
if (v___x_104_ == 0)
{
lean_object* v___x_105_; uint8_t v___x_106_; 
v___x_105_ = lean_unsigned_to_nat(5u);
v___x_106_ = lean_nat_dec_eq(v_c_103_, v___x_105_);
if (v___x_106_ == 0)
{
uint8_t v___x_107_; 
v___x_107_ = lean_nat_dec_eq(v_c_103_, v___x_94_);
lean_dec(v_c_103_);
if (v___x_107_ == 0)
{
return v___x_100_;
}
else
{
return v___x_106_;
}
}
else
{
lean_dec(v_c_103_);
return v___x_104_;
}
}
else
{
uint8_t v___x_108_; 
lean_dec(v_c_103_);
v___x_108_ = 0;
return v___x_108_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_validGillham___boxed(lean_object* v_word_109_){
_start:
{
uint8_t v_res_110_; lean_object* v_r_111_; 
v_res_110_ = lp_lean1090_Lean1090_Impl_Altitude_validGillham(v_word_109_);
lean_dec(v_word_109_);
v_r_111_ = lean_box(v_res_110_);
return v_r_111_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0(void){
_start:
{
lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_112_ = lean_unsigned_to_nat(500u);
v___x_113_ = lean_nat_to_int(v___x_112_);
return v___x_113_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1(void){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; 
v___x_114_ = lean_unsigned_to_nat(100u);
v___x_115_ = lean_nat_to_int(v___x_114_);
return v___x_115_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2(void){
_start:
{
lean_object* v___x_116_; lean_object* v___x_117_; 
v___x_116_ = lean_unsigned_to_nat(1300u);
v___x_117_ = lean_nat_to_int(v___x_116_);
return v___x_117_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(lean_object* v_word_118_){
_start:
{
uint8_t v___x_119_; 
v___x_119_ = lp_lean1090_Lean1090_Impl_Altitude_validGillham(v_word_118_);
if (v___x_119_ == 0)
{
lean_object* v___x_120_; 
v___x_120_ = lean_box(0);
return v___x_120_;
}
else
{
lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v_n500_123_; lean_object* v___y_125_; lean_object* v___y_137_; lean_object* v___x_144_; lean_object* v___x_145_; lean_object* v_c_146_; lean_object* v___x_147_; uint8_t v___x_148_; 
v___x_121_ = lean_unsigned_to_nat(8u);
v___x_122_ = lp_lean1090_Lean1090_Impl_Altitude_gray500(v_word_118_);
v_n500_123_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v___x_121_, v___x_122_);
lean_dec(v___x_122_);
v___x_144_ = lean_unsigned_to_nat(3u);
v___x_145_ = lp_lean1090_Lean1090_Impl_Altitude_gray100(v_word_118_);
v_c_146_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v___x_144_, v___x_145_);
lean_dec(v___x_145_);
v___x_147_ = lean_unsigned_to_nat(7u);
v___x_148_ = lean_nat_dec_eq(v_c_146_, v___x_147_);
if (v___x_148_ == 0)
{
v___y_137_ = v_c_146_;
goto v___jp_136_;
}
else
{
lean_object* v___x_149_; 
lean_dec(v_c_146_);
v___x_149_ = lean_unsigned_to_nat(5u);
v___y_137_ = v___x_149_;
goto v___jp_136_;
}
v___jp_124_:
{
lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; 
v___x_126_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0);
v___x_127_ = lean_nat_to_int(v_n500_123_);
v___x_128_ = lean_int_mul(v___x_126_, v___x_127_);
lean_dec(v___x_127_);
v___x_129_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1, &lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1);
v___x_130_ = lean_nat_to_int(v___y_125_);
v___x_131_ = lean_int_mul(v___x_129_, v___x_130_);
lean_dec(v___x_130_);
v___x_132_ = lean_int_add(v___x_128_, v___x_131_);
lean_dec(v___x_131_);
lean_dec(v___x_128_);
v___x_133_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2, &lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2);
v___x_134_ = lean_int_sub(v___x_132_, v___x_133_);
lean_dec(v___x_132_);
v___x_135_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_135_, 0, v___x_134_);
return v___x_135_;
}
v___jp_136_:
{
lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; uint8_t v___x_141_; 
v___x_138_ = lean_unsigned_to_nat(2u);
v___x_139_ = lean_nat_mod(v_n500_123_, v___x_138_);
v___x_140_ = lean_unsigned_to_nat(1u);
v___x_141_ = lean_nat_dec_eq(v___x_139_, v___x_140_);
lean_dec(v___x_139_);
if (v___x_141_ == 0)
{
v___y_125_ = v___y_137_;
goto v___jp_124_;
}
else
{
lean_object* v___x_142_; lean_object* v___x_143_; 
v___x_142_ = lean_unsigned_to_nat(6u);
v___x_143_ = lean_nat_sub(v___x_142_, v___y_137_);
lean_dec(v___y_137_);
v___y_125_ = v___x_143_;
goto v___jp_124_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___boxed(lean_object* v_word_150_){
_start:
{
lean_object* v_res_151_; 
v_res_151_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v_word_150_);
lean_dec(v_word_150_);
return v_res_151_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0(void){
_start:
{
lean_object* v___x_152_; lean_object* v___x_153_; 
v___x_152_ = lean_unsigned_to_nat(25u);
v___x_153_ = lean_nat_to_int(v___x_152_);
return v___x_153_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1(void){
_start:
{
lean_object* v___x_154_; lean_object* v___x_155_; 
v___x_154_ = lean_unsigned_to_nat(1000u);
v___x_155_ = lean_nat_to_int(v___x_154_);
return v___x_155_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(lean_object* v_word_156_){
_start:
{
lean_object* v___x_157_; uint8_t v___x_158_; 
v___x_157_ = lean_unsigned_to_nat(8192u);
v___x_158_ = lean_nat_dec_le(v___x_157_, v_word_156_);
if (v___x_158_ == 0)
{
lean_object* v___x_159_; uint8_t v___x_160_; 
v___x_159_ = lean_unsigned_to_nat(0u);
v___x_160_ = lean_nat_dec_eq(v_word_156_, v___x_159_);
if (v___x_160_ == 0)
{
lean_object* v___x_161_; lean_object* v___x_162_; lean_object* v___x_163_; uint8_t v___x_164_; 
v___x_161_ = lean_unsigned_to_nat(6u);
v___x_162_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_156_, v___x_161_);
v___x_163_ = lean_unsigned_to_nat(1u);
v___x_164_ = lean_nat_dec_eq(v___x_162_, v___x_163_);
lean_dec(v___x_162_);
if (v___x_164_ == 0)
{
lean_object* v___x_165_; lean_object* v___x_166_; uint8_t v___x_167_; 
v___x_165_ = lean_unsigned_to_nat(4u);
v___x_166_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_156_, v___x_165_);
v___x_167_ = lean_nat_dec_eq(v___x_166_, v___x_163_);
lean_dec(v___x_166_);
if (v___x_167_ == 0)
{
lean_object* v___x_168_; 
v___x_168_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v_word_156_);
if (lean_obj_tag(v___x_168_) == 0)
{
lean_object* v___x_169_; 
v___x_169_ = lean_box(0);
return v___x_169_;
}
else
{
lean_object* v_val_170_; lean_object* v___x_172_; uint8_t v_isShared_173_; uint8_t v_isSharedCheck_178_; 
v_val_170_ = lean_ctor_get(v___x_168_, 0);
v_isSharedCheck_178_ = !lean_is_exclusive(v___x_168_);
if (v_isSharedCheck_178_ == 0)
{
v___x_172_ = v___x_168_;
v_isShared_173_ = v_isSharedCheck_178_;
goto v_resetjp_171_;
}
else
{
lean_inc(v_val_170_);
lean_dec(v___x_168_);
v___x_172_ = lean_box(0);
v_isShared_173_ = v_isSharedCheck_178_;
goto v_resetjp_171_;
}
v_resetjp_171_:
{
lean_object* v___x_174_; lean_object* v___x_176_; 
v___x_174_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_174_, 0, v_val_170_);
if (v_isShared_173_ == 0)
{
lean_ctor_set(v___x_172_, 0, v___x_174_);
v___x_176_ = v___x_172_;
goto v_reusejp_175_;
}
else
{
lean_object* v_reuseFailAlloc_177_; 
v_reuseFailAlloc_177_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_177_, 0, v___x_174_);
v___x_176_ = v_reuseFailAlloc_177_;
goto v_reusejp_175_;
}
v_reusejp_175_:
{
return v___x_176_;
}
}
}
}
else
{
lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v_n_189_; lean_object* v___x_190_; lean_object* v___x_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; 
v___x_179_ = lean_unsigned_to_nat(7u);
v___x_180_ = lean_nat_shiftr(v_word_156_, v___x_179_);
v___x_181_ = lean_unsigned_to_nat(32u);
v___x_182_ = lean_nat_mul(v___x_180_, v___x_181_);
lean_dec(v___x_180_);
v___x_183_ = lean_unsigned_to_nat(5u);
v___x_184_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_156_, v___x_183_);
v___x_185_ = lean_unsigned_to_nat(16u);
v___x_186_ = lean_nat_mul(v___x_184_, v___x_185_);
lean_dec(v___x_184_);
v___x_187_ = lean_nat_add(v___x_182_, v___x_186_);
lean_dec(v___x_186_);
lean_dec(v___x_182_);
v___x_188_ = lean_nat_mod(v_word_156_, v___x_185_);
v_n_189_ = lean_nat_add(v___x_187_, v___x_188_);
lean_dec(v___x_188_);
lean_dec(v___x_187_);
v___x_190_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0);
v___x_191_ = lean_nat_to_int(v_n_189_);
v___x_192_ = lean_int_mul(v___x_190_, v___x_191_);
lean_dec(v___x_191_);
v___x_193_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1, &lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1);
v___x_194_ = lean_int_sub(v___x_192_, v___x_193_);
lean_dec(v___x_192_);
v___x_195_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_195_, 0, v___x_194_);
v___x_196_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_196_, 0, v___x_195_);
return v___x_196_;
}
}
else
{
lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; 
v___x_197_ = lean_unsigned_to_nat(7u);
v___x_198_ = lean_nat_shiftr(v_word_156_, v___x_197_);
v___x_199_ = lean_unsigned_to_nat(64u);
v___x_200_ = lean_nat_mul(v___x_198_, v___x_199_);
lean_dec(v___x_198_);
v___x_201_ = lean_nat_mod(v_word_156_, v___x_199_);
v___x_202_ = lean_nat_add(v___x_200_, v___x_201_);
lean_dec(v___x_201_);
lean_dec(v___x_200_);
v___x_203_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_203_, 0, v___x_202_);
v___x_204_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_204_, 0, v___x_203_);
return v___x_204_;
}
}
else
{
lean_object* v___x_205_; 
v___x_205_ = lean_box(0);
return v___x_205_;
}
}
else
{
lean_object* v___x_206_; 
v___x_206_ = lean_box(0);
return v___x_206_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___boxed(lean_object* v_word_207_){
_start:
{
lean_object* v_res_208_; 
v_res_208_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_word_207_);
lean_dec(v_word_207_);
return v_res_208_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_expandAC12(lean_object* v_word_209_){
_start:
{
lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v___x_215_; lean_object* v___x_216_; 
v___x_210_ = lean_unsigned_to_nat(64u);
v___x_211_ = lean_unsigned_to_nat(6u);
v___x_212_ = lean_nat_shiftr(v_word_209_, v___x_211_);
v___x_213_ = lean_unsigned_to_nat(128u);
v___x_214_ = lean_nat_mul(v___x_212_, v___x_213_);
lean_dec(v___x_212_);
v___x_215_ = lean_nat_mod(v_word_209_, v___x_210_);
v___x_216_ = lean_nat_add(v___x_214_, v___x_215_);
lean_dec(v___x_215_);
lean_dec(v___x_214_);
return v___x_216_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_expandAC12___boxed(lean_object* v_word_217_){
_start:
{
lean_object* v_res_218_; 
v_res_218_ = lp_lean1090_Lean1090_Impl_Altitude_expandAC12(v_word_217_);
lean_dec(v_word_217_);
return v_res_218_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(lean_object* v_word_219_){
_start:
{
lean_object* v___x_220_; uint8_t v___x_221_; 
v___x_220_ = lean_unsigned_to_nat(4096u);
v___x_221_ = lean_nat_dec_lt(v_word_219_, v___x_220_);
if (v___x_221_ == 0)
{
lean_object* v___x_222_; 
v___x_222_ = lean_box(0);
return v___x_222_;
}
else
{
lean_object* v___x_223_; lean_object* v___x_224_; 
v___x_223_ = lp_lean1090_Lean1090_Impl_Altitude_expandAC12(v_word_219_);
v___x_224_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v___x_223_);
lean_dec(v___x_223_);
if (lean_obj_tag(v___x_224_) == 1)
{
lean_object* v_val_225_; lean_object* v___x_227_; uint8_t v_isShared_228_; uint8_t v_isSharedCheck_234_; 
v_val_225_ = lean_ctor_get(v___x_224_, 0);
v_isSharedCheck_234_ = !lean_is_exclusive(v___x_224_);
if (v_isSharedCheck_234_ == 0)
{
v___x_227_ = v___x_224_;
v_isShared_228_ = v_isSharedCheck_234_;
goto v_resetjp_226_;
}
else
{
lean_inc(v_val_225_);
lean_dec(v___x_224_);
v___x_227_ = lean_box(0);
v_isShared_228_ = v_isSharedCheck_234_;
goto v_resetjp_226_;
}
v_resetjp_226_:
{
if (lean_obj_tag(v_val_225_) == 0)
{
lean_object* v_height_229_; lean_object* v___x_231_; 
v_height_229_ = lean_ctor_get(v_val_225_, 0);
lean_inc(v_height_229_);
lean_dec_ref_known(v_val_225_, 1);
if (v_isShared_228_ == 0)
{
lean_ctor_set(v___x_227_, 0, v_height_229_);
v___x_231_ = v___x_227_;
goto v_reusejp_230_;
}
else
{
lean_object* v_reuseFailAlloc_232_; 
v_reuseFailAlloc_232_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_232_, 0, v_height_229_);
v___x_231_ = v_reuseFailAlloc_232_;
goto v_reusejp_230_;
}
v_reusejp_230_:
{
return v___x_231_;
}
}
else
{
lean_object* v___x_233_; 
lean_del_object(v___x_227_);
lean_dec(v_val_225_);
v___x_233_ = lean_box(0);
return v___x_233_;
}
}
}
else
{
lean_object* v___x_235_; 
lean_dec(v___x_224_);
v___x_235_ = lean_box(0);
return v___x_235_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12___boxed(lean_object* v_word_236_){
_start:
{
lean_object* v_res_237_; 
v_res_237_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v_word_236_);
lean_dec(v_word_236_);
return v_res_237_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(lean_object* v_word_238_){
_start:
{
lean_object* v___x_239_; uint8_t v___x_240_; 
v___x_239_ = lean_unsigned_to_nat(4096u);
v___x_240_ = lean_nat_dec_lt(v_word_238_, v___x_239_);
if (v___x_240_ == 0)
{
lean_object* v___x_241_; 
lean_dec(v_word_238_);
v___x_241_ = lean_box(0);
return v___x_241_;
}
else
{
lean_object* v___x_242_; 
v___x_242_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_242_, 0, v_word_238_);
return v___x_242_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0(void){
_start:
{
lean_object* v___x_243_; lean_object* v___x_244_; 
v___x_243_ = lean_unsigned_to_nat(0u);
v___x_244_ = lean_nat_to_int(v___x_243_);
return v___x_244_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(lean_object* v_word_245_){
_start:
{
lean_object* v___x_246_; uint8_t v___x_247_; 
v___x_246_ = lean_unsigned_to_nat(8192u);
v___x_247_ = lean_nat_dec_le(v___x_246_, v_word_245_);
if (v___x_247_ == 0)
{
lean_object* v___x_248_; uint8_t v___x_249_; 
v___x_248_ = lean_unsigned_to_nat(0u);
v___x_249_ = lean_nat_dec_eq(v_word_245_, v___x_248_);
if (v___x_249_ == 0)
{
lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; uint8_t v___x_253_; 
v___x_250_ = lean_unsigned_to_nat(6u);
v___x_251_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_245_, v___x_250_);
v___x_252_ = lean_unsigned_to_nat(1u);
v___x_253_ = lean_nat_dec_eq(v___x_251_, v___x_252_);
lean_dec(v___x_251_);
if (v___x_253_ == 0)
{
lean_object* v___x_254_; 
v___x_254_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_word_245_);
if (lean_obj_tag(v___x_254_) == 1)
{
lean_object* v_val_255_; lean_object* v___x_257_; uint8_t v_isShared_258_; uint8_t v_isSharedCheck_273_; 
v_val_255_ = lean_ctor_get(v___x_254_, 0);
v_isSharedCheck_273_ = !lean_is_exclusive(v___x_254_);
if (v_isSharedCheck_273_ == 0)
{
v___x_257_ = v___x_254_;
v_isShared_258_ = v_isSharedCheck_273_;
goto v_resetjp_256_;
}
else
{
lean_inc(v_val_255_);
lean_dec(v___x_254_);
v___x_257_ = lean_box(0);
v_isShared_258_ = v_isSharedCheck_273_;
goto v_resetjp_256_;
}
v_resetjp_256_:
{
if (lean_obj_tag(v_val_255_) == 0)
{
lean_object* v_height_259_; lean_object* v___x_260_; lean_object* v___x_261_; uint8_t v___x_262_; 
v_height_259_ = lean_ctor_get(v_val_255_, 0);
lean_inc(v_height_259_);
lean_dec_ref_known(v_val_255_, 1);
v___x_260_ = lean_unsigned_to_nat(4u);
v___x_261_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_245_, v___x_260_);
v___x_262_ = lean_nat_dec_eq(v___x_261_, v___x_248_);
lean_dec(v___x_261_);
if (v___x_262_ == 0)
{
lean_object* v___x_264_; 
if (v_isShared_258_ == 0)
{
lean_ctor_set(v___x_257_, 0, v_height_259_);
v___x_264_ = v___x_257_;
goto v_reusejp_263_;
}
else
{
lean_object* v_reuseFailAlloc_265_; 
v_reuseFailAlloc_265_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_265_, 0, v_height_259_);
v___x_264_ = v_reuseFailAlloc_265_;
goto v_reusejp_263_;
}
v_reusejp_263_:
{
return v___x_264_;
}
}
else
{
lean_object* v___x_266_; uint8_t v___x_267_; 
v___x_266_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0);
v___x_267_ = lean_int_dec_lt(v_height_259_, v___x_266_);
if (v___x_267_ == 0)
{
lean_object* v___x_269_; 
if (v_isShared_258_ == 0)
{
lean_ctor_set(v___x_257_, 0, v_height_259_);
v___x_269_ = v___x_257_;
goto v_reusejp_268_;
}
else
{
lean_object* v_reuseFailAlloc_270_; 
v_reuseFailAlloc_270_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_270_, 0, v_height_259_);
v___x_269_ = v_reuseFailAlloc_270_;
goto v_reusejp_268_;
}
v_reusejp_268_:
{
return v___x_269_;
}
}
else
{
lean_object* v___x_271_; 
lean_dec(v_height_259_);
lean_del_object(v___x_257_);
v___x_271_ = lean_box(0);
return v___x_271_;
}
}
}
else
{
lean_object* v___x_272_; 
lean_del_object(v___x_257_);
lean_dec(v_val_255_);
v___x_272_ = lean_box(0);
return v___x_272_;
}
}
}
else
{
lean_object* v___x_274_; 
lean_dec(v___x_254_);
v___x_274_ = lean_box(0);
return v___x_274_;
}
}
else
{
lean_object* v___x_275_; lean_object* v___x_276_; uint8_t v___x_277_; 
v___x_275_ = lean_unsigned_to_nat(4u);
v___x_276_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_245_, v___x_275_);
v___x_277_ = lean_nat_dec_eq(v___x_276_, v___x_252_);
lean_dec(v___x_276_);
if (v___x_277_ == 0)
{
lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v___x_281_; lean_object* v___x_282_; lean_object* v___x_283_; lean_object* v_metres_284_; lean_object* v___x_285_; lean_object* v___x_286_; lean_object* v___x_287_; lean_object* v___x_288_; lean_object* v___x_289_; lean_object* v___x_290_; 
v___x_278_ = lean_unsigned_to_nat(8064u);
v___x_279_ = lean_nat_land(v_word_245_, v___x_278_);
v___x_280_ = lean_unsigned_to_nat(2u);
v___x_281_ = lean_nat_shiftr(v___x_279_, v___x_280_);
lean_dec(v___x_279_);
v___x_282_ = lean_unsigned_to_nat(63u);
v___x_283_ = lean_nat_land(v_word_245_, v___x_282_);
v_metres_284_ = lean_nat_lor(v___x_281_, v___x_283_);
lean_dec(v___x_283_);
lean_dec(v___x_281_);
v___x_285_ = lean_unsigned_to_nat(328084u);
v___x_286_ = lean_nat_mul(v_metres_284_, v___x_285_);
lean_dec(v_metres_284_);
v___x_287_ = lean_unsigned_to_nat(100000u);
v___x_288_ = lean_nat_div(v___x_286_, v___x_287_);
lean_dec(v___x_286_);
v___x_289_ = lean_nat_to_int(v___x_288_);
v___x_290_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_290_, 0, v___x_289_);
return v___x_290_;
}
else
{
lean_object* v___x_291_; 
v___x_291_ = lean_box(0);
return v___x_291_;
}
}
}
else
{
lean_object* v___x_292_; 
v___x_292_ = lean_box(0);
return v___x_292_;
}
}
else
{
lean_object* v___x_293_; 
v___x_293_ = lean_box(0);
return v___x_293_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___boxed(lean_object* v_word_294_){
_start:
{
lean_object* v_res_295_; 
v_res_295_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_word_294_);
lean_dec(v_word_294_);
return v_res_295_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0(void){
_start:
{
lean_object* v___x_296_; lean_object* v___x_297_; 
v___x_296_ = lean_unsigned_to_nat(50000u);
v___x_297_ = lean_nat_to_int(v___x_296_);
return v___x_297_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12(lean_object* v_word_300_){
_start:
{
lean_object* v___x_301_; uint8_t v___x_302_; 
v___x_301_ = lean_unsigned_to_nat(4096u);
v___x_302_ = lean_nat_dec_le(v___x_301_, v_word_300_);
if (v___x_302_ == 0)
{
lean_object* v___x_303_; 
v___x_303_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v_word_300_);
if (lean_obj_tag(v___x_303_) == 0)
{
lean_object* v___x_304_; 
v___x_304_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_304_, 0, v___x_303_);
return v___x_304_;
}
else
{
lean_object* v_val_305_; lean_object* v___x_311_; lean_object* v___x_312_; lean_object* v___x_313_; uint8_t v___x_314_; 
v_val_305_ = lean_ctor_get(v___x_303_, 0);
lean_inc(v_val_305_);
v___x_311_ = lean_unsigned_to_nat(4u);
v___x_312_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_300_, v___x_311_);
v___x_313_ = lean_unsigned_to_nat(0u);
v___x_314_ = lean_nat_dec_eq(v___x_312_, v___x_313_);
lean_dec(v___x_312_);
if (v___x_314_ == 0)
{
goto v___jp_306_;
}
else
{
lean_object* v___x_315_; uint8_t v___x_316_; 
v___x_315_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0);
v___x_316_ = lean_int_dec_lt(v_val_305_, v___x_315_);
if (v___x_316_ == 0)
{
goto v___jp_306_;
}
else
{
lean_object* v___x_317_; 
lean_dec(v_val_305_);
lean_dec_ref_known(v___x_303_, 1);
v___x_317_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__1));
return v___x_317_;
}
}
v___jp_306_:
{
lean_object* v___x_307_; uint8_t v___x_308_; 
v___x_307_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0);
v___x_308_ = lean_int_dec_lt(v___x_307_, v_val_305_);
lean_dec(v_val_305_);
if (v___x_308_ == 0)
{
lean_object* v___x_309_; 
v___x_309_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_309_, 0, v___x_303_);
return v___x_309_;
}
else
{
lean_object* v___x_310_; 
lean_dec_ref_known(v___x_303_, 1);
v___x_310_ = lean_box(0);
return v___x_310_;
}
}
}
}
else
{
lean_object* v___x_318_; 
v___x_318_ = lean_box(0);
return v___x_318_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___boxed(lean_object* v_word_319_){
_start:
{
lean_object* v_res_320_; 
v_res_320_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC12(v_word_319_);
lean_dec(v_word_319_);
return v_res_320_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Altitude(uint8_t builtin) {
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
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
