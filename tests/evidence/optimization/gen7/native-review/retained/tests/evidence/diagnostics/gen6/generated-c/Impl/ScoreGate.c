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
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_Rat_abs(lean_object*);
lean_object* l_Rat_pow(lean_object*, lean_object*);
lean_object* l_Rat_neg(lean_object*);
lean_object* l_Rat_sub(lean_object*, lean_object*);
uint8_t l_Rat_instDecidableLe(lean_object*, lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
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
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1;
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0(void){
_start:
{
lean_object* v___x_59_; lean_object* v___x_60_; 
v___x_59_ = lean_unsigned_to_nat(3u);
v___x_60_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_59_);
return v___x_60_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1(void){
_start:
{
lean_object* v___x_61_; lean_object* v___x_62_; 
v___x_61_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__0);
v___x_62_ = l_Rat_neg(v___x_61_);
return v___x_62_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_ScoreGate_choose(lean_object* v_terms_63_, lean_object* v_penalty_64_, lean_object* v_fallback_65_){
_start:
{
lean_object* v_c_66_; lean_object* v_e_67_; lean_object* v___x_68_; lean_object* v___x_69_; uint8_t v___x_70_; 
lean_inc_ref(v_penalty_64_);
lean_inc(v_terms_63_);
v_c_66_ = lp_lean1090_Lean1090_Impl_ScoreGate_center(v_terms_63_, v_penalty_64_);
v_e_67_ = lp_lean1090_Lean1090_Impl_ScoreGate_envelope(v_terms_63_, v_penalty_64_);
v___x_68_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1, &lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1_once, _init_lp_lean1090_Lean1090_Impl_ScoreGate_choose___closed__1);
lean_inc_ref(v_e_67_);
lean_inc_ref(v_c_66_);
v___x_69_ = l_Rat_sub(v_c_66_, v_e_67_);
v___x_70_ = l_Rat_instDecidableLe(v___x_68_, v___x_69_);
if (v___x_70_ == 0)
{
lean_object* v___x_71_; uint8_t v___x_72_; 
v___x_71_ = l_Rat_add(v_c_66_, v_e_67_);
v___x_72_ = l_Rat_blt(v___x_71_, v___x_68_);
if (v___x_72_ == 0)
{
lean_object* v___x_73_; lean_object* v___x_74_; uint8_t v___x_75_; 
v___x_73_ = lean_box(0);
v___x_74_ = lean_apply_1(v_fallback_65_, v___x_73_);
v___x_75_ = lean_unbox(v___x_74_);
return v___x_75_;
}
else
{
lean_dec_ref(v_fallback_65_);
return v___x_70_;
}
}
else
{
lean_dec_ref(v_e_67_);
lean_dec_ref(v_c_66_);
lean_dec_ref(v_fallback_65_);
return v___x_70_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_ScoreGate_choose___boxed(lean_object* v_terms_76_, lean_object* v_penalty_77_, lean_object* v_fallback_78_){
_start:
{
uint8_t v_res_79_; lean_object* v_r_80_; 
v_res_79_ = lp_lean1090_Lean1090_Impl_ScoreGate_choose(v_terms_76_, v_penalty_77_, v_fallback_78_);
v_r_80_ = lean_box(v_res_79_);
return v_r_80_;
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
