// Lean compiler output
// Module: Impl.ScoreGate
// Imports: public import Init public meta import Init public import Std
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
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* lean_nat_abs(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_int_mul(lean_object*, lean_object*);
lean_object* lean_int_neg(lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
uint8_t lean_int_dec_le(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* l_Rat_pow(lean_object*, lean_object*);
lean_object* l_Rat_abs(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_mass_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_mass(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_center(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__2;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_envelope(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_commonDenominator(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledNumerator(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledNumerator___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2;
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_ScoreGate_choose(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1(lean_object* v_init_1_, lean_object* v_x_2_){
_start:
{
if (lean_obj_tag(v_x_2_) == 0)
{
lean_inc_ref(v_init_1_);
return v_init_1_;
}
else
{
lean_object* v_head_3_; lean_object* v_tail_4_; lean_object* v___x_5_; lean_object* v___x_6_; 
v_head_3_ = lean_ctor_get(v_x_2_, 0);
lean_inc(v_head_3_);
v_tail_4_ = lean_ctor_get(v_x_2_, 1);
lean_inc(v_tail_4_);
lean_dec_ref_known(v_x_2_, 2);
v___x_5_ = lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1(v_init_1_, v_tail_4_);
v___x_6_ = l_Rat_add(v_head_3_, v___x_5_);
return v___x_6_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1___boxed(lean_object* v_init_7_, lean_object* v_x_8_){
_start:
{
lean_object* v_res_9_; 
v_res_9_ = lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1(v_init_7_, v_x_8_);
lean_dec_ref(v_init_7_);
return v_res_9_;
}
}
static lean_object* _init_lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0(void){
_start:
{
lean_object* v___x_10_; lean_object* v___x_11_; 
v___x_10_ = lean_unsigned_to_nat(0u);
v___x_11_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_10_);
return v___x_11_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1(lean_object* v_l_12_){
_start:
{
lean_object* v___x_13_; lean_object* v___x_14_; 
v___x_13_ = lean_obj_once(&lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0, &lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0_once, _init_lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0);
v___x_14_ = lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1(v___x_13_, v_l_12_);
return v___x_14_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_mass_spec__0(lean_object* v_a_15_, lean_object* v_a_16_){
_start:
{
if (lean_obj_tag(v_a_15_) == 0)
{
lean_object* v___x_17_; 
v___x_17_ = l_List_reverse___redArg(v_a_16_);
return v___x_17_;
}
else
{
lean_object* v_head_18_; lean_object* v_tail_19_; lean_object* v___x_21_; uint8_t v_isShared_22_; uint8_t v_isSharedCheck_28_; 
v_head_18_ = lean_ctor_get(v_a_15_, 0);
v_tail_19_ = lean_ctor_get(v_a_15_, 1);
v_isSharedCheck_28_ = !lean_is_exclusive(v_a_15_);
if (v_isSharedCheck_28_ == 0)
{
v___x_21_ = v_a_15_;
v_isShared_22_ = v_isSharedCheck_28_;
goto v_resetjp_20_;
}
else
{
lean_inc(v_tail_19_);
lean_inc(v_head_18_);
lean_dec(v_a_15_);
v___x_21_ = lean_box(0);
v_isShared_22_ = v_isSharedCheck_28_;
goto v_resetjp_20_;
}
v_resetjp_20_:
{
lean_object* v___x_23_; lean_object* v___x_25_; 
v___x_23_ = l_Rat_abs(v_head_18_);
if (v_isShared_22_ == 0)
{
lean_ctor_set(v___x_21_, 1, v_a_16_);
lean_ctor_set(v___x_21_, 0, v___x_23_);
v___x_25_ = v___x_21_;
goto v_reusejp_24_;
}
else
{
lean_object* v_reuseFailAlloc_27_; 
v_reuseFailAlloc_27_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_27_, 0, v___x_23_);
lean_ctor_set(v_reuseFailAlloc_27_, 1, v_a_16_);
v___x_25_ = v_reuseFailAlloc_27_;
goto v_reusejp_24_;
}
v_reusejp_24_:
{
v_a_15_ = v_tail_19_;
v_a_16_ = v___x_25_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_mass(lean_object* v_terms_29_){
_start:
{
lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_30_ = lean_box(0);
v___x_31_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_mass_spec__0(v_terms_29_, v___x_30_);
v___x_32_ = lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1(v___x_31_);
return v___x_32_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_center(lean_object* v_terms_33_, lean_object* v_penalty_34_){
_start:
{
uint8_t v___x_35_; 
v___x_35_ = l_List_isEmpty___redArg(v_terms_33_);
if (v___x_35_ == 0)
{
lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___x_40_; 
lean_inc(v_terms_33_);
v___x_36_ = lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1(v_terms_33_);
v___x_37_ = l_List_lengthTR___redArg(v_terms_33_);
lean_dec(v_terms_33_);
v___x_38_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_37_);
v___x_39_ = l_Rat_div(v___x_36_, v___x_38_);
lean_dec_ref(v___x_36_);
v___x_40_ = l_Rat_add(v___x_39_, v_penalty_34_);
return v___x_40_;
}
else
{
lean_object* v___x_41_; lean_object* v___x_42_; 
lean_dec(v_terms_33_);
v___x_41_ = lean_obj_once(&lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0, &lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0_once, _init_lp_lean1090_List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1___closed__0);
v___x_42_ = l_Rat_add(v___x_41_, v_penalty_34_);
return v___x_42_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__0(void){
_start:
{
lean_object* v___x_43_; lean_object* v___x_44_; 
v___x_43_ = lean_unsigned_to_nat(1u);
v___x_44_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_43_);
return v___x_44_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__1(void){
_start:
{
lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_45_ = lean_unsigned_to_nat(2u);
v___x_46_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_45_);
return v___x_46_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__2(void){
_start:
{
lean_object* v___x_47_; lean_object* v___x_48_; lean_object* v___x_49_; 
v___x_47_ = lean_unsigned_to_nat(40u);
v___x_48_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__1, &lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__1_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__1);
v___x_49_ = l_Rat_pow(v___x_48_, v___x_47_);
return v___x_49_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_envelope(lean_object* v_terms_50_, lean_object* v_penalty_51_){
_start:
{
lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; lean_object* v___x_57_; lean_object* v___x_58_; 
v___x_52_ = lp_lean1090_Lean1090_Impl_ScoreGate_mass(v_terms_50_);
v___x_53_ = l_Rat_abs(v_penalty_51_);
v___x_54_ = l_Rat_add(v___x_52_, v___x_53_);
v___x_55_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__0, &lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__0_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__0);
v___x_56_ = l_Rat_add(v___x_54_, v___x_55_);
v___x_57_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__2, &lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__2_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_envelope___closed__2);
v___x_58_ = l_Rat_div(v___x_56_, v___x_57_);
lean_dec_ref(v___x_56_);
return v___x_58_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1(lean_object* v_x_59_, lean_object* v_x_60_){
_start:
{
if (lean_obj_tag(v_x_60_) == 0)
{
lean_inc(v_x_59_);
return v_x_59_;
}
else
{
lean_object* v_head_61_; lean_object* v_tail_62_; uint8_t v___x_63_; 
v_head_61_ = lean_ctor_get(v_x_60_, 0);
v_tail_62_ = lean_ctor_get(v_x_60_, 1);
v___x_63_ = lean_nat_dec_le(v_x_59_, v_head_61_);
if (v___x_63_ == 0)
{
v_x_60_ = v_tail_62_;
goto _start;
}
else
{
v_x_59_ = v_head_61_;
v_x_60_ = v_tail_62_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1___boxed(lean_object* v_x_66_, lean_object* v_x_67_){
_start:
{
lean_object* v_res_68_; 
v_res_68_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1(v_x_66_, v_x_67_);
lean_dec(v_x_67_);
lean_dec(v_x_66_);
return v_res_68_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2(lean_object* v_largest_69_, lean_object* v_x_70_){
_start:
{
if (lean_obj_tag(v_x_70_) == 0)
{
uint8_t v___x_71_; 
v___x_71_ = 1;
return v___x_71_;
}
else
{
lean_object* v_head_72_; lean_object* v_tail_73_; lean_object* v___x_74_; lean_object* v___x_75_; uint8_t v___x_76_; 
v_head_72_ = lean_ctor_get(v_x_70_, 0);
v_tail_73_ = lean_ctor_get(v_x_70_, 1);
v___x_74_ = lean_nat_mod(v_largest_69_, v_head_72_);
v___x_75_ = lean_unsigned_to_nat(0u);
v___x_76_ = lean_nat_dec_eq(v___x_74_, v___x_75_);
lean_dec(v___x_74_);
if (v___x_76_ == 0)
{
return v___x_76_;
}
else
{
v_x_70_ = v_tail_73_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2___boxed(lean_object* v_largest_78_, lean_object* v_x_79_){
_start:
{
uint8_t v_res_80_; lean_object* v_r_81_; 
v_res_80_ = lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2(v_largest_78_, v_x_79_);
lean_dec(v_x_79_);
lean_dec(v_largest_78_);
v_r_81_ = lean_box(v_res_80_);
return v_r_81_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(lean_object* v_init_82_, lean_object* v_x_83_){
_start:
{
if (lean_obj_tag(v_x_83_) == 0)
{
lean_inc(v_init_82_);
return v_init_82_;
}
else
{
lean_object* v_head_84_; lean_object* v_tail_85_; lean_object* v___x_86_; lean_object* v___x_87_; 
v_head_84_ = lean_ctor_get(v_x_83_, 0);
v_tail_85_ = lean_ctor_get(v_x_83_, 1);
v___x_86_ = lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(v_init_82_, v_tail_85_);
v___x_87_ = lean_nat_mul(v_head_84_, v___x_86_);
lean_dec(v___x_86_);
return v___x_87_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3___boxed(lean_object* v_init_88_, lean_object* v_x_89_){
_start:
{
lean_object* v_res_90_; 
v_res_90_ = lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(v_init_88_, v_x_89_);
lean_dec(v_x_89_);
lean_dec(v_init_88_);
return v_res_90_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3(lean_object* v_l_91_){
_start:
{
lean_object* v___x_92_; lean_object* v___x_93_; 
v___x_92_ = lean_unsigned_to_nat(1u);
v___x_93_ = lp_lean1090_List_foldr___at___00List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3_spec__3(v___x_92_, v_l_91_);
return v___x_93_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3___boxed(lean_object* v_l_94_){
_start:
{
lean_object* v_res_95_; 
v_res_95_ = lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3(v_l_94_);
lean_dec(v_l_94_);
return v_res_95_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__0(lean_object* v_a_96_, lean_object* v_a_97_){
_start:
{
if (lean_obj_tag(v_a_96_) == 0)
{
lean_object* v___x_98_; 
v___x_98_ = l_List_reverse___redArg(v_a_97_);
return v___x_98_;
}
else
{
lean_object* v_head_99_; lean_object* v_tail_100_; lean_object* v___x_102_; uint8_t v_isShared_103_; uint8_t v_isSharedCheck_109_; 
v_head_99_ = lean_ctor_get(v_a_96_, 0);
v_tail_100_ = lean_ctor_get(v_a_96_, 1);
v_isSharedCheck_109_ = !lean_is_exclusive(v_a_96_);
if (v_isSharedCheck_109_ == 0)
{
v___x_102_ = v_a_96_;
v_isShared_103_ = v_isSharedCheck_109_;
goto v_resetjp_101_;
}
else
{
lean_inc(v_tail_100_);
lean_inc(v_head_99_);
lean_dec(v_a_96_);
v___x_102_ = lean_box(0);
v_isShared_103_ = v_isSharedCheck_109_;
goto v_resetjp_101_;
}
v_resetjp_101_:
{
lean_object* v_den_104_; lean_object* v___x_106_; 
v_den_104_ = lean_ctor_get(v_head_99_, 1);
lean_inc(v_den_104_);
lean_dec(v_head_99_);
if (v_isShared_103_ == 0)
{
lean_ctor_set(v___x_102_, 1, v_a_97_);
lean_ctor_set(v___x_102_, 0, v_den_104_);
v___x_106_ = v___x_102_;
goto v_reusejp_105_;
}
else
{
lean_object* v_reuseFailAlloc_108_; 
v_reuseFailAlloc_108_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_108_, 0, v_den_104_);
lean_ctor_set(v_reuseFailAlloc_108_, 1, v_a_97_);
v___x_106_ = v_reuseFailAlloc_108_;
goto v_reusejp_105_;
}
v_reusejp_105_:
{
v_a_96_ = v_tail_100_;
v_a_97_ = v___x_106_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_commonDenominator(lean_object* v_terms_110_, lean_object* v_penalty_111_){
_start:
{
lean_object* v_den_112_; lean_object* v___x_114_; uint8_t v_isShared_115_; uint8_t v_isSharedCheck_125_; 
v_den_112_ = lean_ctor_get(v_penalty_111_, 1);
v_isSharedCheck_125_ = !lean_is_exclusive(v_penalty_111_);
if (v_isSharedCheck_125_ == 0)
{
lean_object* v_unused_126_; 
v_unused_126_ = lean_ctor_get(v_penalty_111_, 0);
lean_dec(v_unused_126_);
v___x_114_ = v_penalty_111_;
v_isShared_115_ = v_isSharedCheck_125_;
goto v_resetjp_113_;
}
else
{
lean_inc(v_den_112_);
lean_dec(v_penalty_111_);
v___x_114_ = lean_box(0);
v_isShared_115_ = v_isSharedCheck_125_;
goto v_resetjp_113_;
}
v_resetjp_113_:
{
lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v_denominators_119_; 
v___x_116_ = lean_box(0);
v___x_117_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__0(v_terms_110_, v___x_116_);
if (v_isShared_115_ == 0)
{
lean_ctor_set_tag(v___x_114_, 1);
lean_ctor_set(v___x_114_, 1, v___x_117_);
lean_ctor_set(v___x_114_, 0, v_den_112_);
v_denominators_119_ = v___x_114_;
goto v_reusejp_118_;
}
else
{
lean_object* v_reuseFailAlloc_124_; 
v_reuseFailAlloc_124_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_124_, 0, v_den_112_);
lean_ctor_set(v_reuseFailAlloc_124_, 1, v___x_117_);
v_denominators_119_ = v_reuseFailAlloc_124_;
goto v_reusejp_118_;
}
v_reusejp_118_:
{
lean_object* v___x_120_; lean_object* v_largest_121_; uint8_t v___x_122_; 
v___x_120_ = lean_unsigned_to_nat(1u);
v_largest_121_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__1(v___x_120_, v_denominators_119_);
v___x_122_ = lp_lean1090_List_all___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__2(v_largest_121_, v_denominators_119_);
if (v___x_122_ == 0)
{
lean_object* v___x_123_; 
lean_dec(v_largest_121_);
v___x_123_ = lp_lean1090_List_prod___at___00Lean1090_Impl_ScoreGate_commonDenominator_spec__3(v_denominators_119_);
lean_dec_ref(v_denominators_119_);
return v___x_123_;
}
else
{
lean_dec_ref(v_denominators_119_);
return v_largest_121_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledNumerator(lean_object* v_denominator_127_, lean_object* v_value_128_){
_start:
{
lean_object* v_num_129_; lean_object* v_den_130_; uint8_t v___x_131_; 
v_num_129_ = lean_ctor_get(v_value_128_, 0);
v_den_130_ = lean_ctor_get(v_value_128_, 1);
v___x_131_ = lean_nat_dec_eq(v_denominator_127_, v_den_130_);
if (v___x_131_ == 0)
{
lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; 
v___x_132_ = lean_nat_div(v_denominator_127_, v_den_130_);
v___x_133_ = lean_nat_to_int(v___x_132_);
v___x_134_ = lean_int_mul(v_num_129_, v___x_133_);
lean_dec(v___x_133_);
return v___x_134_;
}
else
{
lean_inc(v_num_129_);
return v_num_129_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledNumerator___boxed(lean_object* v_denominator_135_, lean_object* v_value_136_){
_start:
{
lean_object* v_res_137_; 
v_res_137_ = lp_lean1090_Lean1090_Impl_ScoreGate_scaledNumerator(v_denominator_135_, v_value_136_);
lean_dec_ref(v_value_136_);
lean_dec(v_denominator_135_);
return v_res_137_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0(lean_object* v_denominator_138_, lean_object* v_x_139_, lean_object* v_x_140_){
_start:
{
if (lean_obj_tag(v_x_140_) == 0)
{
return v_x_139_;
}
else
{
lean_object* v_head_141_; lean_object* v_tail_142_; lean_object* v___y_144_; lean_object* v_num_159_; lean_object* v_den_160_; uint8_t v___x_161_; 
v_head_141_ = lean_ctor_get(v_x_140_, 0);
lean_inc(v_head_141_);
v_tail_142_ = lean_ctor_get(v_x_140_, 1);
lean_inc(v_tail_142_);
lean_dec_ref_known(v_x_140_, 2);
v_num_159_ = lean_ctor_get(v_head_141_, 0);
lean_inc(v_num_159_);
v_den_160_ = lean_ctor_get(v_head_141_, 1);
lean_inc(v_den_160_);
lean_dec(v_head_141_);
v___x_161_ = lean_nat_dec_eq(v_denominator_138_, v_den_160_);
if (v___x_161_ == 0)
{
lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; 
v___x_162_ = lean_nat_div(v_denominator_138_, v_den_160_);
lean_dec(v_den_160_);
v___x_163_ = lean_nat_to_int(v___x_162_);
v___x_164_ = lean_int_mul(v_num_159_, v___x_163_);
lean_dec(v___x_163_);
lean_dec(v_num_159_);
v___y_144_ = v___x_164_;
goto v___jp_143_;
}
else
{
lean_dec(v_den_160_);
v___y_144_ = v_num_159_;
goto v___jp_143_;
}
v___jp_143_:
{
lean_object* v_fst_145_; lean_object* v_snd_146_; lean_object* v___x_148_; uint8_t v_isShared_149_; uint8_t v_isSharedCheck_158_; 
v_fst_145_ = lean_ctor_get(v_x_139_, 0);
v_snd_146_ = lean_ctor_get(v_x_139_, 1);
v_isSharedCheck_158_ = !lean_is_exclusive(v_x_139_);
if (v_isSharedCheck_158_ == 0)
{
v___x_148_ = v_x_139_;
v_isShared_149_ = v_isSharedCheck_158_;
goto v_resetjp_147_;
}
else
{
lean_inc(v_snd_146_);
lean_inc(v_fst_145_);
lean_dec(v_x_139_);
v___x_148_ = lean_box(0);
v_isShared_149_ = v_isSharedCheck_158_;
goto v_resetjp_147_;
}
v_resetjp_147_:
{
lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_155_; 
v___x_150_ = lean_int_add(v_fst_145_, v___y_144_);
lean_dec(v_fst_145_);
v___x_151_ = lean_nat_abs(v___y_144_);
lean_dec(v___y_144_);
v___x_152_ = lean_nat_to_int(v___x_151_);
v___x_153_ = lean_int_add(v_snd_146_, v___x_152_);
lean_dec(v___x_152_);
lean_dec(v_snd_146_);
if (v_isShared_149_ == 0)
{
lean_ctor_set(v___x_148_, 1, v___x_153_);
lean_ctor_set(v___x_148_, 0, v___x_150_);
v___x_155_ = v___x_148_;
goto v_reusejp_154_;
}
else
{
lean_object* v_reuseFailAlloc_157_; 
v_reuseFailAlloc_157_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_157_, 0, v___x_150_);
lean_ctor_set(v_reuseFailAlloc_157_, 1, v___x_153_);
v___x_155_ = v_reuseFailAlloc_157_;
goto v_reusejp_154_;
}
v_reusejp_154_:
{
v_x_139_ = v___x_155_;
v_x_140_ = v_tail_142_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0___boxed(lean_object* v_denominator_165_, lean_object* v_x_166_, lean_object* v_x_167_){
_start:
{
lean_object* v_res_168_; 
v_res_168_ = lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0(v_denominator_165_, v_x_166_, v_x_167_);
lean_dec(v_denominator_165_);
return v_res_168_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0(lean_object* v_denominator_169_, lean_object* v_x_170_, lean_object* v_x_171_){
_start:
{
if (lean_obj_tag(v_x_171_) == 0)
{
return v_x_170_;
}
else
{
lean_object* v_head_172_; lean_object* v_tail_173_; lean_object* v___y_175_; lean_object* v_num_190_; lean_object* v_den_191_; uint8_t v___x_192_; 
v_head_172_ = lean_ctor_get(v_x_171_, 0);
lean_inc(v_head_172_);
v_tail_173_ = lean_ctor_get(v_x_171_, 1);
lean_inc(v_tail_173_);
lean_dec_ref_known(v_x_171_, 2);
v_num_190_ = lean_ctor_get(v_head_172_, 0);
lean_inc(v_num_190_);
v_den_191_ = lean_ctor_get(v_head_172_, 1);
lean_inc(v_den_191_);
lean_dec(v_head_172_);
v___x_192_ = lean_nat_dec_eq(v_denominator_169_, v_den_191_);
if (v___x_192_ == 0)
{
lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; 
v___x_193_ = lean_nat_div(v_denominator_169_, v_den_191_);
lean_dec(v_den_191_);
v___x_194_ = lean_nat_to_int(v___x_193_);
v___x_195_ = lean_int_mul(v_num_190_, v___x_194_);
lean_dec(v___x_194_);
lean_dec(v_num_190_);
v___y_175_ = v___x_195_;
goto v___jp_174_;
}
else
{
lean_dec(v_den_191_);
v___y_175_ = v_num_190_;
goto v___jp_174_;
}
v___jp_174_:
{
lean_object* v_fst_176_; lean_object* v_snd_177_; lean_object* v___x_179_; uint8_t v_isShared_180_; uint8_t v_isSharedCheck_189_; 
v_fst_176_ = lean_ctor_get(v_x_170_, 0);
v_snd_177_ = lean_ctor_get(v_x_170_, 1);
v_isSharedCheck_189_ = !lean_is_exclusive(v_x_170_);
if (v_isSharedCheck_189_ == 0)
{
v___x_179_ = v_x_170_;
v_isShared_180_ = v_isSharedCheck_189_;
goto v_resetjp_178_;
}
else
{
lean_inc(v_snd_177_);
lean_inc(v_fst_176_);
lean_dec(v_x_170_);
v___x_179_ = lean_box(0);
v_isShared_180_ = v_isSharedCheck_189_;
goto v_resetjp_178_;
}
v_resetjp_178_:
{
lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_186_; 
v___x_181_ = lean_int_add(v_fst_176_, v___y_175_);
lean_dec(v_fst_176_);
v___x_182_ = lean_nat_abs(v___y_175_);
lean_dec(v___y_175_);
v___x_183_ = lean_nat_to_int(v___x_182_);
v___x_184_ = lean_int_add(v_snd_177_, v___x_183_);
lean_dec(v___x_183_);
lean_dec(v_snd_177_);
if (v_isShared_180_ == 0)
{
lean_ctor_set(v___x_179_, 1, v___x_184_);
lean_ctor_set(v___x_179_, 0, v___x_181_);
v___x_186_ = v___x_179_;
goto v_reusejp_185_;
}
else
{
lean_object* v_reuseFailAlloc_188_; 
v_reuseFailAlloc_188_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_188_, 0, v___x_181_);
lean_ctor_set(v_reuseFailAlloc_188_, 1, v___x_184_);
v___x_186_ = v_reuseFailAlloc_188_;
goto v_reusejp_185_;
}
v_reusejp_185_:
{
lean_object* v___x_187_; 
v___x_187_ = lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0(v_denominator_169_, v___x_186_, v_tail_173_);
return v___x_187_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0___boxed(lean_object* v_denominator_196_, lean_object* v_x_197_, lean_object* v_x_198_){
_start:
{
lean_object* v_res_199_; 
v_res_199_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0(v_denominator_196_, v_x_197_, v_x_198_);
lean_dec(v_denominator_196_);
return v_res_199_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0(void){
_start:
{
lean_object* v___x_200_; lean_object* v___x_201_; 
v___x_200_ = lean_unsigned_to_nat(0u);
v___x_201_ = lean_nat_to_int(v___x_200_);
return v___x_201_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1(void){
_start:
{
lean_object* v___x_202_; lean_object* v___x_203_; 
v___x_202_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0, &lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0);
v___x_203_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_203_, 0, v___x_202_);
lean_ctor_set(v___x_203_, 1, v___x_202_);
return v___x_203_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals(lean_object* v_denominator_204_, lean_object* v_terms_205_){
_start:
{
lean_object* v___x_206_; lean_object* v___x_207_; 
v___x_206_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1, &lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1);
v___x_207_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0(v_denominator_204_, v___x_206_, v_terms_205_);
return v___x_207_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___boxed(lean_object* v_denominator_208_, lean_object* v_terms_209_){
_start:
{
lean_object* v_res_210_; 
v_res_210_ = lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals(v_denominator_208_, v_terms_209_);
lean_dec(v_denominator_208_);
return v_res_210_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0(void){
_start:
{
lean_object* v___x_211_; lean_object* v___x_212_; 
v___x_211_ = lean_cstr_to_nat("1099511627776");
v___x_212_ = lean_nat_to_int(v___x_211_);
return v___x_212_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1(void){
_start:
{
lean_object* v___x_213_; lean_object* v___x_214_; 
v___x_213_ = lean_unsigned_to_nat(3u);
v___x_214_ = lean_nat_to_int(v___x_213_);
return v___x_214_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2(void){
_start:
{
lean_object* v___x_215_; lean_object* v___x_216_; 
v___x_215_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1);
v___x_216_ = lean_int_neg(v___x_215_);
return v___x_216_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_ScoreGate_choose(lean_object* v_terms_217_, lean_object* v_penalty_218_, lean_object* v_fallback_219_){
_start:
{
lean_object* v_num_220_; lean_object* v_den_221_; lean_object* v_denominator_222_; lean_object* v_totals_223_; lean_object* v___y_225_; lean_object* v___y_226_; lean_object* v___y_252_; uint8_t v___x_256_; 
v_num_220_ = lean_ctor_get(v_penalty_218_, 0);
lean_inc(v_num_220_);
v_den_221_ = lean_ctor_get(v_penalty_218_, 1);
lean_inc(v_den_221_);
lean_inc_n(v_terms_217_, 2);
v_denominator_222_ = lp_lean1090_Lean1090_Impl_ScoreGate_commonDenominator(v_terms_217_, v_penalty_218_);
v_totals_223_ = lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals(v_denominator_222_, v_terms_217_);
v___x_256_ = lean_nat_dec_eq(v_denominator_222_, v_den_221_);
if (v___x_256_ == 0)
{
lean_object* v___x_257_; lean_object* v___x_258_; lean_object* v___x_259_; 
v___x_257_ = lean_nat_div(v_denominator_222_, v_den_221_);
lean_dec(v_den_221_);
v___x_258_ = lean_nat_to_int(v___x_257_);
v___x_259_ = lean_int_mul(v_num_220_, v___x_258_);
lean_dec(v___x_258_);
lean_dec(v_num_220_);
v___y_252_ = v___x_259_;
goto v___jp_251_;
}
else
{
lean_dec(v_den_221_);
v___y_252_ = v_num_220_;
goto v___jp_251_;
}
v___jp_224_:
{
lean_object* v_fst_227_; lean_object* v_snd_228_; lean_object* v_n_229_; lean_object* v___x_230_; lean_object* v_c_231_; lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; lean_object* v___x_235_; lean_object* v_e_236_; lean_object* v___x_237_; lean_object* v_scaledCenter_238_; lean_object* v_scaledError_239_; lean_object* v___x_240_; lean_object* v___x_241_; lean_object* v___x_242_; lean_object* v_threshold_243_; lean_object* v___x_244_; uint8_t v___x_245_; 
v_fst_227_ = lean_ctor_get(v_totals_223_, 0);
lean_inc(v_fst_227_);
v_snd_228_ = lean_ctor_get(v_totals_223_, 1);
lean_inc(v_snd_228_);
lean_dec_ref(v_totals_223_);
v_n_229_ = lean_nat_to_int(v___y_226_);
v___x_230_ = lean_int_mul(v_n_229_, v___y_225_);
v_c_231_ = lean_int_add(v_fst_227_, v___x_230_);
lean_dec(v___x_230_);
lean_dec(v_fst_227_);
v___x_232_ = lean_nat_abs(v___y_225_);
lean_dec(v___y_225_);
v___x_233_ = lean_nat_to_int(v___x_232_);
v___x_234_ = lean_int_add(v_snd_228_, v___x_233_);
lean_dec(v___x_233_);
lean_dec(v_snd_228_);
v___x_235_ = lean_nat_to_int(v_denominator_222_);
v_e_236_ = lean_int_add(v___x_234_, v___x_235_);
lean_dec(v___x_234_);
v___x_237_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0);
v_scaledCenter_238_ = lean_int_mul(v___x_237_, v_c_231_);
lean_dec(v_c_231_);
v_scaledError_239_ = lean_int_mul(v_n_229_, v_e_236_);
lean_dec(v_e_236_);
v___x_240_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__2);
v___x_241_ = lean_int_mul(v___x_240_, v_n_229_);
lean_dec(v_n_229_);
v___x_242_ = lean_int_mul(v___x_241_, v___x_235_);
lean_dec(v___x_235_);
lean_dec(v___x_241_);
v_threshold_243_ = lean_int_mul(v___x_242_, v___x_237_);
lean_dec(v___x_242_);
v___x_244_ = lean_int_sub(v_scaledCenter_238_, v_scaledError_239_);
v___x_245_ = lean_int_dec_le(v_threshold_243_, v___x_244_);
lean_dec(v___x_244_);
if (v___x_245_ == 0)
{
lean_object* v___x_246_; uint8_t v___x_247_; 
v___x_246_ = lean_int_add(v_scaledCenter_238_, v_scaledError_239_);
lean_dec(v_scaledError_239_);
lean_dec(v_scaledCenter_238_);
v___x_247_ = lean_int_dec_lt(v___x_246_, v_threshold_243_);
lean_dec(v_threshold_243_);
lean_dec(v___x_246_);
if (v___x_247_ == 0)
{
lean_object* v___x_248_; lean_object* v___x_249_; uint8_t v___x_250_; 
v___x_248_ = lean_box(0);
v___x_249_ = lean_apply_1(v_fallback_219_, v___x_248_);
v___x_250_ = lean_unbox(v___x_249_);
return v___x_250_;
}
else
{
lean_dec_ref(v_fallback_219_);
return v___x_245_;
}
}
else
{
lean_dec(v_threshold_243_);
lean_dec(v_scaledError_239_);
lean_dec(v_scaledCenter_238_);
lean_dec_ref(v_fallback_219_);
return v___x_245_;
}
}
v___jp_251_:
{
lean_object* v___x_253_; lean_object* v___x_254_; uint8_t v___x_255_; 
v___x_253_ = l_List_lengthTR___redArg(v_terms_217_);
lean_dec(v_terms_217_);
v___x_254_ = lean_unsigned_to_nat(1u);
v___x_255_ = lean_nat_dec_le(v___x_253_, v___x_254_);
if (v___x_255_ == 0)
{
v___y_225_ = v___y_252_;
v___y_226_ = v___x_253_;
goto v___jp_224_;
}
else
{
lean_dec(v___x_253_);
v___y_225_ = v___y_252_;
v___y_226_ = v___x_254_;
goto v___jp_224_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___boxed(lean_object* v_terms_260_, lean_object* v_penalty_261_, lean_object* v_fallback_262_){
_start:
{
uint8_t v_res_263_; lean_object* v_r_264_; 
v_res_263_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v_terms_260_, v_penalty_261_, v_fallback_262_);
v_r_264_ = lean_box(v_res_263_);
return v_r_264_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Std(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_ScoreGate(uint8_t builtin) {
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
res = initialize_Std(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
