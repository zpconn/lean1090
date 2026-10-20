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
lean_object* lean_nat_lxor(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_nat_land(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_int_mul(lean_object*, lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_lor(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
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
lean_object* v___x_3_; lean_object* v___x_4_; lean_object* v___x_5_; 
v___x_3_ = lean_nat_shiftr(v_word_1_, v_place_2_);
v___x_4_ = lean_unsigned_to_nat(1u);
v___x_5_ = lean_nat_land(v___x_3_, v___x_4_);
lean_dec(v___x_3_);
return v___x_5_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_bit___boxed(lean_object* v_word_6_, lean_object* v_place_7_){
_start:
{
lean_object* v_res_8_; 
v_res_8_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_6_, v_place_7_);
lean_dec(v_place_7_);
lean_dec(v_word_6_);
return v_res_8_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(lean_object* v_word_9_, lean_object* v_x_10_, lean_object* v_x_11_){
_start:
{
if (lean_obj_tag(v_x_11_) == 0)
{
return v_x_10_;
}
else
{
lean_object* v_head_12_; lean_object* v_tail_13_; lean_object* v___x_14_; lean_object* v___x_15_; 
v_head_12_ = lean_ctor_get(v_x_11_, 0);
v_tail_13_ = lean_ctor_get(v_x_11_, 1);
v___x_14_ = lean_nat_shiftr(v_word_9_, v_head_12_);
v___x_15_ = lean_nat_lxor(v_x_10_, v___x_14_);
lean_dec(v___x_14_);
lean_dec(v_x_10_);
v_x_10_ = v___x_15_;
v_x_11_ = v_tail_13_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0___boxed(lean_object* v_word_17_, lean_object* v_x_18_, lean_object* v_x_19_){
_start:
{
lean_object* v_res_20_; 
v_res_20_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(v_word_17_, v_x_18_, v_x_19_);
lean_dec(v_x_19_);
lean_dec(v_word_17_);
return v_res_20_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_grayDecode(lean_object* v_width_21_, lean_object* v_word_22_){
_start:
{
lean_object* v___x_23_; lean_object* v___x_24_; lean_object* v___x_25_; 
v___x_23_ = lean_unsigned_to_nat(0u);
v___x_24_ = l_List_range(v_width_21_);
v___x_25_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0(v_word_22_, v___x_23_, v___x_24_);
lean_dec(v___x_24_);
return v___x_25_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_grayDecode___boxed(lean_object* v_width_26_, lean_object* v_word_27_){
_start:
{
lean_object* v_res_28_; 
v_res_28_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v_width_26_, v_word_27_);
lean_dec(v_word_27_);
return v_res_28_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(lean_object* v_word_29_, lean_object* v_x_30_, lean_object* v_x_31_){
_start:
{
if (lean_obj_tag(v_x_31_) == 0)
{
return v_x_30_;
}
else
{
lean_object* v_head_32_; lean_object* v_tail_33_; lean_object* v___x_34_; lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; 
v_head_32_ = lean_ctor_get(v_x_31_, 0);
v_tail_33_ = lean_ctor_get(v_x_31_, 1);
v___x_34_ = lean_unsigned_to_nat(2u);
v___x_35_ = lean_nat_mul(v___x_34_, v_x_30_);
lean_dec(v_x_30_);
v___x_36_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_29_, v_head_32_);
v___x_37_ = lean_nat_add(v___x_35_, v___x_36_);
lean_dec(v___x_36_);
lean_dec(v___x_35_);
v_x_30_ = v___x_37_;
v_x_31_ = v_tail_33_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0___boxed(lean_object* v_word_39_, lean_object* v_x_40_, lean_object* v_x_41_){
_start:
{
lean_object* v_res_42_; 
v_res_42_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(v_word_39_, v_x_40_, v_x_41_);
lean_dec(v_x_41_);
lean_dec(v_word_39_);
return v_res_42_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500(lean_object* v_word_67_){
_start:
{
lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; 
v___x_68_ = lean_unsigned_to_nat(0u);
v___x_69_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Altitude_gray500___closed__7));
v___x_70_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_gray500_spec__0(v_word_67_, v___x_68_, v___x_69_);
return v___x_70_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray500___boxed(lean_object* v_word_71_){
_start:
{
lean_object* v_res_72_; 
v_res_72_ = lp_lean1090_Lean1090_Impl_Altitude_gray500(v_word_71_);
lean_dec(v_word_71_);
return v_res_72_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray100(lean_object* v_word_73_){
_start:
{
lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; lean_object* v___x_85_; 
v___x_74_ = lean_unsigned_to_nat(4u);
v___x_75_ = lean_unsigned_to_nat(12u);
v___x_76_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_73_, v___x_75_);
v___x_77_ = lean_nat_mul(v___x_74_, v___x_76_);
lean_dec(v___x_76_);
v___x_78_ = lean_unsigned_to_nat(2u);
v___x_79_ = lean_unsigned_to_nat(10u);
v___x_80_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_73_, v___x_79_);
v___x_81_ = lean_nat_mul(v___x_78_, v___x_80_);
lean_dec(v___x_80_);
v___x_82_ = lean_nat_add(v___x_77_, v___x_81_);
lean_dec(v___x_81_);
lean_dec(v___x_77_);
v___x_83_ = lean_unsigned_to_nat(8u);
v___x_84_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_73_, v___x_83_);
v___x_85_ = lean_nat_add(v___x_82_, v___x_84_);
lean_dec(v___x_84_);
lean_dec(v___x_82_);
return v___x_85_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_gray100___boxed(lean_object* v_word_86_){
_start:
{
lean_object* v_res_87_; 
v_res_87_ = lp_lean1090_Lean1090_Impl_Altitude_gray100(v_word_86_);
lean_dec(v_word_86_);
return v_res_87_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Altitude_validGillham(lean_object* v_word_88_){
_start:
{
lean_object* v___x_89_; uint8_t v___x_90_; 
v___x_89_ = lean_unsigned_to_nat(8192u);
v___x_90_ = lean_nat_dec_lt(v_word_88_, v___x_89_);
if (v___x_90_ == 0)
{
return v___x_90_;
}
else
{
lean_object* v___x_91_; lean_object* v___x_92_; lean_object* v___x_93_; uint8_t v___x_94_; 
v___x_91_ = lean_unsigned_to_nat(6u);
v___x_92_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_88_, v___x_91_);
v___x_93_ = lean_unsigned_to_nat(0u);
v___x_94_ = lean_nat_dec_eq(v___x_92_, v___x_93_);
lean_dec(v___x_92_);
if (v___x_94_ == 0)
{
return v___x_94_;
}
else
{
lean_object* v___x_95_; lean_object* v___x_96_; uint8_t v___x_97_; 
v___x_95_ = lean_unsigned_to_nat(4u);
v___x_96_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_88_, v___x_95_);
v___x_97_ = lean_nat_dec_eq(v___x_96_, v___x_93_);
lean_dec(v___x_96_);
if (v___x_97_ == 0)
{
return v___x_97_;
}
else
{
lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v_c_100_; uint8_t v___x_101_; 
v___x_98_ = lean_unsigned_to_nat(3u);
v___x_99_ = lp_lean1090_Lean1090_Impl_Altitude_gray100(v_word_88_);
v_c_100_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v___x_98_, v___x_99_);
lean_dec(v___x_99_);
v___x_101_ = lean_nat_dec_eq(v_c_100_, v___x_93_);
if (v___x_101_ == 0)
{
lean_object* v___x_102_; uint8_t v___x_103_; 
v___x_102_ = lean_unsigned_to_nat(5u);
v___x_103_ = lean_nat_dec_eq(v_c_100_, v___x_102_);
if (v___x_103_ == 0)
{
uint8_t v___x_104_; 
v___x_104_ = lean_nat_dec_eq(v_c_100_, v___x_91_);
lean_dec(v_c_100_);
if (v___x_104_ == 0)
{
return v___x_97_;
}
else
{
return v___x_103_;
}
}
else
{
lean_dec(v_c_100_);
return v___x_101_;
}
}
else
{
uint8_t v___x_105_; 
lean_dec(v_c_100_);
v___x_105_ = 0;
return v___x_105_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_validGillham___boxed(lean_object* v_word_106_){
_start:
{
uint8_t v_res_107_; lean_object* v_r_108_; 
v_res_107_ = lp_lean1090_Lean1090_Impl_Altitude_validGillham(v_word_106_);
lean_dec(v_word_106_);
v_r_108_ = lean_box(v_res_107_);
return v_r_108_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0(void){
_start:
{
lean_object* v___x_109_; lean_object* v___x_110_; 
v___x_109_ = lean_unsigned_to_nat(500u);
v___x_110_ = lean_nat_to_int(v___x_109_);
return v___x_110_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1(void){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; 
v___x_111_ = lean_unsigned_to_nat(100u);
v___x_112_ = lean_nat_to_int(v___x_111_);
return v___x_112_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2(void){
_start:
{
lean_object* v___x_113_; lean_object* v___x_114_; 
v___x_113_ = lean_unsigned_to_nat(1300u);
v___x_114_ = lean_nat_to_int(v___x_113_);
return v___x_114_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(lean_object* v_word_115_){
_start:
{
uint8_t v___x_116_; 
v___x_116_ = lp_lean1090_Lean1090_Impl_Altitude_validGillham(v_word_115_);
if (v___x_116_ == 0)
{
lean_object* v___x_117_; 
v___x_117_ = lean_box(0);
return v___x_117_;
}
else
{
lean_object* v___x_118_; lean_object* v___x_119_; lean_object* v_n500_120_; lean_object* v___y_122_; lean_object* v___y_134_; lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v_c_143_; lean_object* v___x_144_; uint8_t v___x_145_; 
v___x_118_ = lean_unsigned_to_nat(8u);
v___x_119_ = lp_lean1090_Lean1090_Impl_Altitude_gray500(v_word_115_);
v_n500_120_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v___x_118_, v___x_119_);
lean_dec(v___x_119_);
v___x_141_ = lean_unsigned_to_nat(3u);
v___x_142_ = lp_lean1090_Lean1090_Impl_Altitude_gray100(v_word_115_);
v_c_143_ = lp_lean1090_Lean1090_Impl_Altitude_grayDecode(v___x_141_, v___x_142_);
lean_dec(v___x_142_);
v___x_144_ = lean_unsigned_to_nat(7u);
v___x_145_ = lean_nat_dec_eq(v_c_143_, v___x_144_);
if (v___x_145_ == 0)
{
v___y_134_ = v_c_143_;
goto v___jp_133_;
}
else
{
lean_object* v___x_146_; 
lean_dec(v_c_143_);
v___x_146_ = lean_unsigned_to_nat(5u);
v___y_134_ = v___x_146_;
goto v___jp_133_;
}
v___jp_121_:
{
lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v___x_125_; lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; 
v___x_123_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__0);
v___x_124_ = lean_nat_to_int(v_n500_120_);
v___x_125_ = lean_int_mul(v___x_123_, v___x_124_);
lean_dec(v___x_124_);
v___x_126_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1, &lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__1);
v___x_127_ = lean_nat_to_int(v___y_122_);
v___x_128_ = lean_int_mul(v___x_126_, v___x_127_);
lean_dec(v___x_127_);
v___x_129_ = lean_int_add(v___x_125_, v___x_128_);
lean_dec(v___x_128_);
lean_dec(v___x_125_);
v___x_130_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2, &lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___closed__2);
v___x_131_ = lean_int_sub(v___x_129_, v___x_130_);
lean_dec(v___x_129_);
v___x_132_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_132_, 0, v___x_131_);
return v___x_132_;
}
v___jp_133_:
{
lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; uint8_t v___x_138_; 
v___x_135_ = lean_unsigned_to_nat(2u);
v___x_136_ = lean_nat_mod(v_n500_120_, v___x_135_);
v___x_137_ = lean_unsigned_to_nat(1u);
v___x_138_ = lean_nat_dec_eq(v___x_136_, v___x_137_);
lean_dec(v___x_136_);
if (v___x_138_ == 0)
{
v___y_122_ = v___y_134_;
goto v___jp_121_;
}
else
{
lean_object* v___x_139_; lean_object* v___x_140_; 
v___x_139_ = lean_unsigned_to_nat(6u);
v___x_140_ = lean_nat_sub(v___x_139_, v___y_134_);
lean_dec(v___y_134_);
v___y_122_ = v___x_140_;
goto v___jp_121_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGillham___boxed(lean_object* v_word_147_){
_start:
{
lean_object* v_res_148_; 
v_res_148_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v_word_147_);
lean_dec(v_word_147_);
return v_res_148_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0(void){
_start:
{
lean_object* v___x_149_; lean_object* v___x_150_; 
v___x_149_ = lean_unsigned_to_nat(25u);
v___x_150_ = lean_nat_to_int(v___x_149_);
return v___x_150_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1(void){
_start:
{
lean_object* v___x_151_; lean_object* v___x_152_; 
v___x_151_ = lean_unsigned_to_nat(1000u);
v___x_152_ = lean_nat_to_int(v___x_151_);
return v___x_152_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(lean_object* v_word_153_){
_start:
{
lean_object* v___x_154_; uint8_t v___x_155_; 
v___x_154_ = lean_unsigned_to_nat(8192u);
v___x_155_ = lean_nat_dec_le(v___x_154_, v_word_153_);
if (v___x_155_ == 0)
{
lean_object* v___x_156_; uint8_t v___x_157_; 
v___x_156_ = lean_unsigned_to_nat(0u);
v___x_157_ = lean_nat_dec_eq(v_word_153_, v___x_156_);
if (v___x_157_ == 0)
{
lean_object* v___x_158_; lean_object* v___x_159_; lean_object* v___x_160_; uint8_t v___x_161_; 
v___x_158_ = lean_unsigned_to_nat(6u);
v___x_159_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_153_, v___x_158_);
v___x_160_ = lean_unsigned_to_nat(1u);
v___x_161_ = lean_nat_dec_eq(v___x_159_, v___x_160_);
lean_dec(v___x_159_);
if (v___x_161_ == 0)
{
lean_object* v___x_162_; lean_object* v___x_163_; uint8_t v___x_164_; 
v___x_162_ = lean_unsigned_to_nat(4u);
v___x_163_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_153_, v___x_162_);
v___x_164_ = lean_nat_dec_eq(v___x_163_, v___x_160_);
lean_dec(v___x_163_);
if (v___x_164_ == 0)
{
lean_object* v___x_165_; 
v___x_165_ = lp_lean1090_Lean1090_Impl_Altitude_decodeGillham(v_word_153_);
if (lean_obj_tag(v___x_165_) == 0)
{
lean_object* v___x_166_; 
v___x_166_ = lean_box(0);
return v___x_166_;
}
else
{
lean_object* v_val_167_; lean_object* v___x_169_; uint8_t v_isShared_170_; uint8_t v_isSharedCheck_175_; 
v_val_167_ = lean_ctor_get(v___x_165_, 0);
v_isSharedCheck_175_ = !lean_is_exclusive(v___x_165_);
if (v_isSharedCheck_175_ == 0)
{
v___x_169_ = v___x_165_;
v_isShared_170_ = v_isSharedCheck_175_;
goto v_resetjp_168_;
}
else
{
lean_inc(v_val_167_);
lean_dec(v___x_165_);
v___x_169_ = lean_box(0);
v_isShared_170_ = v_isSharedCheck_175_;
goto v_resetjp_168_;
}
v_resetjp_168_:
{
lean_object* v___x_171_; lean_object* v___x_173_; 
v___x_171_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_171_, 0, v_val_167_);
if (v_isShared_170_ == 0)
{
lean_ctor_set(v___x_169_, 0, v___x_171_);
v___x_173_ = v___x_169_;
goto v_reusejp_172_;
}
else
{
lean_object* v_reuseFailAlloc_174_; 
v_reuseFailAlloc_174_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_174_, 0, v___x_171_);
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
lean_object* v___x_176_; lean_object* v___x_177_; lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v_n_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v___x_191_; lean_object* v___x_192_; lean_object* v___x_193_; 
v___x_176_ = lean_unsigned_to_nat(7u);
v___x_177_ = lean_nat_shiftr(v_word_153_, v___x_176_);
v___x_178_ = lean_unsigned_to_nat(32u);
v___x_179_ = lean_nat_mul(v___x_177_, v___x_178_);
lean_dec(v___x_177_);
v___x_180_ = lean_unsigned_to_nat(5u);
v___x_181_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_153_, v___x_180_);
v___x_182_ = lean_unsigned_to_nat(16u);
v___x_183_ = lean_nat_mul(v___x_181_, v___x_182_);
lean_dec(v___x_181_);
v___x_184_ = lean_nat_add(v___x_179_, v___x_183_);
lean_dec(v___x_183_);
lean_dec(v___x_179_);
v___x_185_ = lean_nat_mod(v_word_153_, v___x_182_);
v_n_186_ = lean_nat_add(v___x_184_, v___x_185_);
lean_dec(v___x_185_);
lean_dec(v___x_184_);
v___x_187_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__0);
v___x_188_ = lean_nat_to_int(v_n_186_);
v___x_189_ = lean_int_mul(v___x_187_, v___x_188_);
lean_dec(v___x_188_);
v___x_190_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1, &lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___closed__1);
v___x_191_ = lean_int_sub(v___x_189_, v___x_190_);
lean_dec(v___x_189_);
v___x_192_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_192_, 0, v___x_191_);
v___x_193_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_193_, 0, v___x_192_);
return v___x_193_;
}
}
else
{
lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; 
v___x_194_ = lean_unsigned_to_nat(7u);
v___x_195_ = lean_nat_shiftr(v_word_153_, v___x_194_);
v___x_196_ = lean_unsigned_to_nat(64u);
v___x_197_ = lean_nat_mul(v___x_195_, v___x_196_);
lean_dec(v___x_195_);
v___x_198_ = lean_nat_mod(v_word_153_, v___x_196_);
v___x_199_ = lean_nat_add(v___x_197_, v___x_198_);
lean_dec(v___x_198_);
lean_dec(v___x_197_);
v___x_200_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_200_, 0, v___x_199_);
v___x_201_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_201_, 0, v___x_200_);
return v___x_201_;
}
}
else
{
lean_object* v___x_202_; 
v___x_202_ = lean_box(0);
return v___x_202_;
}
}
else
{
lean_object* v___x_203_; 
v___x_203_ = lean_box(0);
return v___x_203_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC13___boxed(lean_object* v_word_204_){
_start:
{
lean_object* v_res_205_; 
v_res_205_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_word_204_);
lean_dec(v_word_204_);
return v_res_205_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_expandAC12(lean_object* v_word_206_){
_start:
{
lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_209_; lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; 
v___x_207_ = lean_unsigned_to_nat(64u);
v___x_208_ = lean_unsigned_to_nat(6u);
v___x_209_ = lean_nat_shiftr(v_word_206_, v___x_208_);
v___x_210_ = lean_unsigned_to_nat(128u);
v___x_211_ = lean_nat_mul(v___x_209_, v___x_210_);
lean_dec(v___x_209_);
v___x_212_ = lean_nat_mod(v_word_206_, v___x_207_);
v___x_213_ = lean_nat_add(v___x_211_, v___x_212_);
lean_dec(v___x_212_);
lean_dec(v___x_211_);
return v___x_213_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_expandAC12___boxed(lean_object* v_word_214_){
_start:
{
lean_object* v_res_215_; 
v_res_215_ = lp_lean1090_Lean1090_Impl_Altitude_expandAC12(v_word_214_);
lean_dec(v_word_214_);
return v_res_215_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(lean_object* v_word_216_){
_start:
{
lean_object* v___x_217_; uint8_t v___x_218_; 
v___x_217_ = lean_unsigned_to_nat(4096u);
v___x_218_ = lean_nat_dec_lt(v_word_216_, v___x_217_);
if (v___x_218_ == 0)
{
lean_object* v___x_219_; 
v___x_219_ = lean_box(0);
return v___x_219_;
}
else
{
lean_object* v___x_220_; lean_object* v___x_221_; 
v___x_220_ = lp_lean1090_Lean1090_Impl_Altitude_expandAC12(v_word_216_);
v___x_221_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v___x_220_);
lean_dec(v___x_220_);
if (lean_obj_tag(v___x_221_) == 1)
{
lean_object* v_val_222_; lean_object* v___x_224_; uint8_t v_isShared_225_; uint8_t v_isSharedCheck_231_; 
v_val_222_ = lean_ctor_get(v___x_221_, 0);
v_isSharedCheck_231_ = !lean_is_exclusive(v___x_221_);
if (v_isSharedCheck_231_ == 0)
{
v___x_224_ = v___x_221_;
v_isShared_225_ = v_isSharedCheck_231_;
goto v_resetjp_223_;
}
else
{
lean_inc(v_val_222_);
lean_dec(v___x_221_);
v___x_224_ = lean_box(0);
v_isShared_225_ = v_isSharedCheck_231_;
goto v_resetjp_223_;
}
v_resetjp_223_:
{
if (lean_obj_tag(v_val_222_) == 0)
{
lean_object* v_height_226_; lean_object* v___x_228_; 
v_height_226_ = lean_ctor_get(v_val_222_, 0);
lean_inc(v_height_226_);
lean_dec_ref_known(v_val_222_, 1);
if (v_isShared_225_ == 0)
{
lean_ctor_set(v___x_224_, 0, v_height_226_);
v___x_228_ = v___x_224_;
goto v_reusejp_227_;
}
else
{
lean_object* v_reuseFailAlloc_229_; 
v_reuseFailAlloc_229_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_229_, 0, v_height_226_);
v___x_228_ = v_reuseFailAlloc_229_;
goto v_reusejp_227_;
}
v_reusejp_227_:
{
return v___x_228_;
}
}
else
{
lean_object* v___x_230_; 
lean_del_object(v___x_224_);
lean_dec(v_val_222_);
v___x_230_ = lean_box(0);
return v___x_230_;
}
}
}
else
{
lean_object* v___x_232_; 
lean_dec(v___x_221_);
v___x_232_ = lean_box(0);
return v___x_232_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeAC12___boxed(lean_object* v_word_233_){
_start:
{
lean_object* v_res_234_; 
v_res_234_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v_word_233_);
lean_dec(v_word_233_);
return v_res_234_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_decodeGNSSMetres(lean_object* v_word_235_){
_start:
{
lean_object* v___x_236_; uint8_t v___x_237_; 
v___x_236_ = lean_unsigned_to_nat(4096u);
v___x_237_ = lean_nat_dec_lt(v_word_235_, v___x_236_);
if (v___x_237_ == 0)
{
lean_object* v___x_238_; 
lean_dec(v_word_235_);
v___x_238_ = lean_box(0);
return v___x_238_;
}
else
{
lean_object* v___x_239_; 
v___x_239_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_239_, 0, v_word_235_);
return v___x_239_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0(void){
_start:
{
lean_object* v___x_240_; lean_object* v___x_241_; 
v___x_240_ = lean_unsigned_to_nat(0u);
v___x_241_ = lean_nat_to_int(v___x_240_);
return v___x_241_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(lean_object* v_word_242_){
_start:
{
lean_object* v___x_243_; uint8_t v___x_244_; 
v___x_243_ = lean_unsigned_to_nat(8192u);
v___x_244_ = lean_nat_dec_le(v___x_243_, v_word_242_);
if (v___x_244_ == 0)
{
lean_object* v___x_245_; uint8_t v___x_246_; 
v___x_245_ = lean_unsigned_to_nat(0u);
v___x_246_ = lean_nat_dec_eq(v_word_242_, v___x_245_);
if (v___x_246_ == 0)
{
lean_object* v___x_247_; lean_object* v___x_248_; lean_object* v___x_249_; uint8_t v___x_250_; 
v___x_247_ = lean_unsigned_to_nat(6u);
v___x_248_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_242_, v___x_247_);
v___x_249_ = lean_unsigned_to_nat(1u);
v___x_250_ = lean_nat_dec_eq(v___x_248_, v___x_249_);
lean_dec(v___x_248_);
if (v___x_250_ == 0)
{
lean_object* v___x_251_; 
v___x_251_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC13(v_word_242_);
if (lean_obj_tag(v___x_251_) == 1)
{
lean_object* v_val_252_; lean_object* v___x_254_; uint8_t v_isShared_255_; uint8_t v_isSharedCheck_270_; 
v_val_252_ = lean_ctor_get(v___x_251_, 0);
v_isSharedCheck_270_ = !lean_is_exclusive(v___x_251_);
if (v_isSharedCheck_270_ == 0)
{
v___x_254_ = v___x_251_;
v_isShared_255_ = v_isSharedCheck_270_;
goto v_resetjp_253_;
}
else
{
lean_inc(v_val_252_);
lean_dec(v___x_251_);
v___x_254_ = lean_box(0);
v_isShared_255_ = v_isSharedCheck_270_;
goto v_resetjp_253_;
}
v_resetjp_253_:
{
if (lean_obj_tag(v_val_252_) == 0)
{
lean_object* v_height_256_; lean_object* v___x_257_; lean_object* v___x_258_; uint8_t v___x_259_; 
v_height_256_ = lean_ctor_get(v_val_252_, 0);
lean_inc(v_height_256_);
lean_dec_ref_known(v_val_252_, 1);
v___x_257_ = lean_unsigned_to_nat(4u);
v___x_258_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_242_, v___x_257_);
v___x_259_ = lean_nat_dec_eq(v___x_258_, v___x_245_);
lean_dec(v___x_258_);
if (v___x_259_ == 0)
{
lean_object* v___x_261_; 
if (v_isShared_255_ == 0)
{
lean_ctor_set(v___x_254_, 0, v_height_256_);
v___x_261_ = v___x_254_;
goto v_reusejp_260_;
}
else
{
lean_object* v_reuseFailAlloc_262_; 
v_reuseFailAlloc_262_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_262_, 0, v_height_256_);
v___x_261_ = v_reuseFailAlloc_262_;
goto v_reusejp_260_;
}
v_reusejp_260_:
{
return v___x_261_;
}
}
else
{
lean_object* v___x_263_; uint8_t v___x_264_; 
v___x_263_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0);
v___x_264_ = lean_int_dec_lt(v_height_256_, v___x_263_);
if (v___x_264_ == 0)
{
lean_object* v___x_266_; 
if (v_isShared_255_ == 0)
{
lean_ctor_set(v___x_254_, 0, v_height_256_);
v___x_266_ = v___x_254_;
goto v_reusejp_265_;
}
else
{
lean_object* v_reuseFailAlloc_267_; 
v_reuseFailAlloc_267_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_267_, 0, v_height_256_);
v___x_266_ = v_reuseFailAlloc_267_;
goto v_reusejp_265_;
}
v_reusejp_265_:
{
return v___x_266_;
}
}
else
{
lean_object* v___x_268_; 
lean_dec(v_height_256_);
lean_del_object(v___x_254_);
v___x_268_ = lean_box(0);
return v___x_268_;
}
}
}
else
{
lean_object* v___x_269_; 
lean_del_object(v___x_254_);
lean_dec(v_val_252_);
v___x_269_ = lean_box(0);
return v___x_269_;
}
}
}
else
{
lean_object* v___x_271_; 
lean_dec(v___x_251_);
v___x_271_ = lean_box(0);
return v___x_271_;
}
}
else
{
lean_object* v___x_272_; lean_object* v___x_273_; uint8_t v___x_274_; 
v___x_272_ = lean_unsigned_to_nat(4u);
v___x_273_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_242_, v___x_272_);
v___x_274_ = lean_nat_dec_eq(v___x_273_, v___x_249_);
lean_dec(v___x_273_);
if (v___x_274_ == 0)
{
lean_object* v___x_275_; lean_object* v___x_276_; lean_object* v___x_277_; lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v_metres_281_; lean_object* v___x_282_; lean_object* v___x_283_; lean_object* v___x_284_; lean_object* v___x_285_; lean_object* v___x_286_; lean_object* v___x_287_; 
v___x_275_ = lean_unsigned_to_nat(8064u);
v___x_276_ = lean_nat_land(v_word_242_, v___x_275_);
v___x_277_ = lean_unsigned_to_nat(2u);
v___x_278_ = lean_nat_shiftr(v___x_276_, v___x_277_);
lean_dec(v___x_276_);
v___x_279_ = lean_unsigned_to_nat(63u);
v___x_280_ = lean_nat_land(v_word_242_, v___x_279_);
v_metres_281_ = lean_nat_lor(v___x_278_, v___x_280_);
lean_dec(v___x_280_);
lean_dec(v___x_278_);
v___x_282_ = lean_unsigned_to_nat(328084u);
v___x_283_ = lean_nat_mul(v_metres_281_, v___x_282_);
lean_dec(v_metres_281_);
v___x_284_ = lean_unsigned_to_nat(100000u);
v___x_285_ = lean_nat_div(v___x_283_, v___x_284_);
lean_dec(v___x_283_);
v___x_286_ = lean_nat_to_int(v___x_285_);
v___x_287_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_287_, 0, v___x_286_);
return v___x_287_;
}
else
{
lean_object* v___x_288_; 
v___x_288_ = lean_box(0);
return v___x_288_;
}
}
}
else
{
lean_object* v___x_289_; 
v___x_289_ = lean_box(0);
return v___x_289_;
}
}
else
{
lean_object* v___x_290_; 
v___x_290_ = lean_box(0);
return v___x_290_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___boxed(lean_object* v_word_291_){
_start:
{
lean_object* v_res_292_; 
v_res_292_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC13(v_word_291_);
lean_dec(v_word_291_);
return v_res_292_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0(void){
_start:
{
lean_object* v___x_293_; lean_object* v___x_294_; 
v___x_293_ = lean_unsigned_to_nat(50000u);
v___x_294_ = lean_nat_to_int(v___x_293_);
return v___x_294_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12(lean_object* v_word_297_){
_start:
{
lean_object* v___x_298_; uint8_t v___x_299_; 
v___x_298_ = lean_unsigned_to_nat(4096u);
v___x_299_ = lean_nat_dec_le(v___x_298_, v_word_297_);
if (v___x_299_ == 0)
{
lean_object* v___x_300_; 
v___x_300_ = lp_lean1090_Lean1090_Impl_Altitude_decodeAC12(v_word_297_);
if (lean_obj_tag(v___x_300_) == 0)
{
lean_object* v___x_301_; 
v___x_301_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_301_, 0, v___x_300_);
return v___x_301_;
}
else
{
lean_object* v_val_302_; lean_object* v___x_308_; lean_object* v___x_309_; lean_object* v___x_310_; uint8_t v___x_311_; 
v_val_302_ = lean_ctor_get(v___x_300_, 0);
lean_inc(v_val_302_);
v___x_308_ = lean_unsigned_to_nat(4u);
v___x_309_ = lp_lean1090_Lean1090_Impl_Altitude_bit(v_word_297_, v___x_308_);
v___x_310_ = lean_unsigned_to_nat(0u);
v___x_311_ = lean_nat_dec_eq(v___x_309_, v___x_310_);
lean_dec(v___x_309_);
if (v___x_311_ == 0)
{
goto v___jp_303_;
}
else
{
lean_object* v___x_312_; uint8_t v___x_313_; 
v___x_312_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC13___closed__0);
v___x_313_ = lean_int_dec_lt(v_val_302_, v___x_312_);
if (v___x_313_ == 0)
{
goto v___jp_303_;
}
else
{
lean_object* v___x_314_; 
lean_dec(v_val_302_);
lean_dec_ref_known(v___x_300_, 1);
v___x_314_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__1));
return v___x_314_;
}
}
v___jp_303_:
{
lean_object* v___x_304_; uint8_t v___x_305_; 
v___x_304_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0, &lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___closed__0);
v___x_305_ = lean_int_dec_lt(v___x_304_, v_val_302_);
lean_dec(v_val_302_);
if (v___x_305_ == 0)
{
lean_object* v___x_306_; 
v___x_306_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_306_, 0, v___x_300_);
return v___x_306_;
}
else
{
lean_object* v___x_307_; 
lean_dec_ref_known(v___x_300_, 1);
v___x_307_ = lean_box(0);
return v___x_307_;
}
}
}
}
else
{
lean_object* v___x_315_; 
v___x_315_ = lean_box(0);
return v___x_315_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Altitude_oracleAC12___boxed(lean_object* v_word_316_){
_start:
{
lean_object* v_res_317_; 
v_res_317_ = lp_lean1090_Lean1090_Impl_Altitude_oracleAC12(v_word_316_);
lean_dec(v_word_316_);
return v_res_317_;
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
