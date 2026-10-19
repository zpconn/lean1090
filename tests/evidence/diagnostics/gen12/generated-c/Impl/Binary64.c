// Lean compiler output
// Module: Impl.Binary64
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
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* lean_nat_abs(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* l_Rat_mul(lean_object*, lean_object*);
lean_object* l_Rat_abs(lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
lean_object* l_Rat_neg(lean_object*);
uint8_t l_instDecidableEqRat_decEq(lean_object*, lean_object*);
lean_object* lean_int_neg(lean_object*);
lean_object* lean_nat_log2(lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
uint8_t lean_int_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
lean_object* l_Rat_sub(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_round___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_round___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_round___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_round___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_round___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_round___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_round___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_round___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_maxFinite;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_literal(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_sub(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_div(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_div___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits___boxed(lean_object*);
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(0u);
v___x_2_ = lean_nat_to_int(v___x_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1(void){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_3_ = lean_unsigned_to_nat(1u);
v___x_4_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_3_);
return v___x_4_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo(lean_object* v_exponent_5_){
_start:
{
lean_object* v___x_6_; uint8_t v___x_7_; 
v___x_6_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0);
v___x_7_ = lean_int_dec_lt(v_exponent_5_, v___x_6_);
if (v___x_7_ == 0)
{
lean_object* v___x_8_; lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; 
v___x_8_ = lean_unsigned_to_nat(2u);
v___x_9_ = l_Int_toNat(v_exponent_5_);
v___x_10_ = lean_nat_pow(v___x_8_, v___x_9_);
lean_dec(v___x_9_);
v___x_11_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_10_);
return v___x_11_;
}
else
{
lean_object* v___x_12_; lean_object* v___x_13_; lean_object* v___x_14_; lean_object* v___x_15_; lean_object* v___x_16_; lean_object* v___x_17_; 
v___x_12_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1);
v___x_13_ = lean_unsigned_to_nat(2u);
v___x_14_ = lean_nat_abs(v_exponent_5_);
v___x_15_ = lean_nat_pow(v___x_13_, v___x_14_);
lean_dec(v___x_14_);
v___x_16_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_15_);
v___x_17_ = l_Rat_div(v___x_12_, v___x_16_);
return v___x_17_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo___boxed(lean_object* v_exponent_18_){
_start:
{
lean_object* v_res_19_; 
v_res_19_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v_exponent_18_);
lean_dec(v_exponent_18_);
return v_res_19_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven(lean_object* v_numerator_20_, lean_object* v_denominator_21_){
_start:
{
lean_object* v_q_22_; lean_object* v_r_26_; lean_object* v___x_27_; lean_object* v___x_28_; uint8_t v___x_29_; 
v_q_22_ = lean_nat_div(v_numerator_20_, v_denominator_21_);
v_r_26_ = lean_nat_mod(v_numerator_20_, v_denominator_21_);
v___x_27_ = lean_unsigned_to_nat(2u);
v___x_28_ = lean_nat_mul(v___x_27_, v_r_26_);
lean_dec(v_r_26_);
v___x_29_ = lean_nat_dec_lt(v_denominator_21_, v___x_28_);
if (v___x_29_ == 0)
{
uint8_t v___x_30_; 
v___x_30_ = lean_nat_dec_eq(v___x_28_, v_denominator_21_);
lean_dec(v___x_28_);
if (v___x_30_ == 0)
{
return v_q_22_;
}
else
{
lean_object* v___x_31_; lean_object* v___x_32_; uint8_t v___x_33_; 
v___x_31_ = lean_nat_mod(v_q_22_, v___x_27_);
v___x_32_ = lean_unsigned_to_nat(1u);
v___x_33_ = lean_nat_dec_eq(v___x_31_, v___x_32_);
lean_dec(v___x_31_);
if (v___x_33_ == 0)
{
return v_q_22_;
}
else
{
goto v___jp_23_;
}
}
}
else
{
lean_dec(v___x_28_);
goto v___jp_23_;
}
v___jp_23_:
{
lean_object* v___x_24_; lean_object* v___x_25_; 
v___x_24_ = lean_unsigned_to_nat(1u);
v___x_25_ = lean_nat_add(v_q_22_, v___x_24_);
lean_dec(v_q_22_);
return v___x_25_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven___boxed(lean_object* v_numerator_34_, lean_object* v_denominator_35_){
_start:
{
lean_object* v_res_36_; 
v_res_36_ = lp_lean1090_Lean1090_Impl_Binary64_nearestEven(v_numerator_34_, v_denominator_35_);
lean_dec(v_denominator_35_);
lean_dec(v_numerator_34_);
return v_res_36_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0(void){
_start:
{
lean_object* v___x_37_; lean_object* v___x_38_; 
v___x_37_ = lean_unsigned_to_nat(1u);
v___x_38_ = lean_nat_to_int(v___x_37_);
return v___x_38_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent(lean_object* v_value_39_){
_start:
{
lean_object* v_num_40_; lean_object* v_den_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v___x_45_; lean_object* v___x_46_; lean_object* v_candidate_47_; lean_object* v___x_48_; lean_object* v___x_49_; uint8_t v___x_50_; 
v_num_40_ = lean_ctor_get(v_value_39_, 0);
v_den_41_ = lean_ctor_get(v_value_39_, 1);
v___x_42_ = lean_nat_abs(v_num_40_);
v___x_43_ = lean_nat_log2(v___x_42_);
lean_dec(v___x_42_);
v___x_44_ = lean_nat_to_int(v___x_43_);
v___x_45_ = lean_nat_log2(v_den_41_);
v___x_46_ = lean_nat_to_int(v___x_45_);
v_candidate_47_ = lean_int_sub(v___x_44_, v___x_46_);
lean_dec(v___x_46_);
lean_dec(v___x_44_);
v___x_48_ = l_Rat_abs(v_value_39_);
v___x_49_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v_candidate_47_);
v___x_50_ = l_Rat_blt(v___x_48_, v___x_49_);
if (v___x_50_ == 0)
{
return v_candidate_47_;
}
else
{
lean_object* v___x_51_; lean_object* v___x_52_; 
v___x_51_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0);
v___x_52_ = lean_int_sub(v_candidate_47_, v___x_51_);
lean_dec(v_candidate_47_);
return v___x_52_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__0(void){
_start:
{
lean_object* v___x_53_; lean_object* v___x_54_; 
v___x_53_ = lean_unsigned_to_nat(0u);
v___x_54_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_53_);
return v___x_54_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__1(void){
_start:
{
lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_55_ = lean_unsigned_to_nat(1074u);
v___x_56_ = lean_nat_to_int(v___x_55_);
return v___x_56_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__2(void){
_start:
{
lean_object* v___x_57_; lean_object* v___x_58_; 
v___x_57_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__1);
v___x_58_ = lean_int_neg(v___x_57_);
return v___x_58_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__3(void){
_start:
{
lean_object* v___x_59_; lean_object* v___x_60_; 
v___x_59_ = lean_unsigned_to_nat(52u);
v___x_60_ = lean_nat_to_int(v___x_59_);
return v___x_60_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object* v_value_61_){
_start:
{
lean_object* v___x_62_; lean_object* v___y_64_; uint8_t v___x_76_; 
v___x_62_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__0);
v___x_76_ = l_instDecidableEqRat_decEq(v_value_61_, v___x_62_);
if (v___x_76_ == 0)
{
lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; uint8_t v___x_81_; 
v___x_77_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__2, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__2);
lean_inc_ref(v_value_61_);
v___x_78_ = lp_lean1090_Lean1090_Impl_Binary64_exponent(v_value_61_);
v___x_79_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__3, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__3);
v___x_80_ = lean_int_sub(v___x_78_, v___x_79_);
lean_dec(v___x_78_);
v___x_81_ = lean_int_dec_le(v___x_77_, v___x_80_);
if (v___x_81_ == 0)
{
lean_dec(v___x_80_);
v___y_64_ = v___x_77_;
goto v___jp_63_;
}
else
{
v___y_64_ = v___x_80_;
goto v___jp_63_;
}
}
else
{
lean_dec_ref(v_value_61_);
return v___x_62_;
}
v___jp_63_:
{
lean_object* v_quantum_65_; lean_object* v___x_66_; lean_object* v_scaled_67_; lean_object* v_num_68_; lean_object* v_den_69_; lean_object* v___x_70_; lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v_rounded_73_; uint8_t v___x_74_; 
v_quantum_65_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___y_64_);
lean_dec(v___y_64_);
lean_inc_ref(v_value_61_);
v___x_66_ = l_Rat_abs(v_value_61_);
lean_inc_ref(v_quantum_65_);
v_scaled_67_ = l_Rat_div(v___x_66_, v_quantum_65_);
lean_dec_ref(v___x_66_);
v_num_68_ = lean_ctor_get(v_scaled_67_, 0);
lean_inc(v_num_68_);
v_den_69_ = lean_ctor_get(v_scaled_67_, 1);
lean_inc(v_den_69_);
lean_dec_ref(v_scaled_67_);
v___x_70_ = lean_nat_abs(v_num_68_);
lean_dec(v_num_68_);
v___x_71_ = lp_lean1090_Lean1090_Impl_Binary64_nearestEven(v___x_70_, v_den_69_);
lean_dec(v_den_69_);
lean_dec(v___x_70_);
v___x_72_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_71_);
v_rounded_73_ = l_Rat_mul(v___x_72_, v_quantum_65_);
lean_dec_ref(v___x_72_);
v___x_74_ = l_Rat_blt(v_value_61_, v___x_62_);
if (v___x_74_ == 0)
{
return v_rounded_73_;
}
else
{
lean_object* v___x_75_; 
v___x_75_ = l_Rat_neg(v_rounded_73_);
return v___x_75_;
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0(void){
_start:
{
lean_object* v___x_82_; lean_object* v___x_83_; 
v___x_82_ = lean_cstr_to_nat("9007199254740991");
v___x_83_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_82_);
return v___x_83_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1(void){
_start:
{
lean_object* v___x_84_; lean_object* v___x_85_; 
v___x_84_ = lean_unsigned_to_nat(971u);
v___x_85_ = lean_nat_to_int(v___x_84_);
return v___x_85_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2(void){
_start:
{
lean_object* v___x_86_; lean_object* v___x_87_; 
v___x_86_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1);
v___x_87_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_86_);
return v___x_87_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3(void){
_start:
{
lean_object* v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; 
v___x_88_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2);
v___x_89_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0);
v___x_90_ = l_Rat_mul(v___x_89_, v___x_88_);
return v___x_90_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite(void){
_start:
{
lean_object* v___x_91_; 
v___x_91_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3);
return v___x_91_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_literal(lean_object* v_value_92_){
_start:
{
lean_object* v___x_93_; 
v___x_93_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_value_92_);
return v___x_93_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_add(lean_object* v_a_94_, lean_object* v_b_95_){
_start:
{
lean_object* v___x_96_; lean_object* v___x_97_; 
v___x_96_ = l_Rat_add(v_a_94_, v_b_95_);
v___x_97_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_96_);
return v___x_97_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_sub(lean_object* v_a_98_, lean_object* v_b_99_){
_start:
{
lean_object* v___x_100_; lean_object* v___x_101_; 
v___x_100_ = l_Rat_sub(v_a_98_, v_b_99_);
v___x_101_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_100_);
return v___x_101_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul(lean_object* v_a_102_, lean_object* v_b_103_){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_104_ = l_Rat_mul(v_a_102_, v_b_103_);
v___x_105_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_104_);
return v___x_105_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul___boxed(lean_object* v_a_106_, lean_object* v_b_107_){
_start:
{
lean_object* v_res_108_; 
v_res_108_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v_a_106_, v_b_107_);
lean_dec_ref(v_a_106_);
return v_res_108_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_div(lean_object* v_a_109_, lean_object* v_b_110_){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; 
v___x_111_ = l_Rat_div(v_a_109_, v_b_110_);
v___x_112_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_111_);
return v___x_112_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_div___boxed(lean_object* v_a_113_, lean_object* v_b_114_){
_start:
{
lean_object* v_res_115_; 
v_res_115_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_a_113_, v_b_114_);
lean_dec_ref(v_a_113_);
return v_res_115_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0(void){
_start:
{
lean_object* v___x_116_; lean_object* v___x_117_; 
v___x_116_ = lean_unsigned_to_nat(1075u);
v___x_117_ = lean_nat_to_int(v___x_116_);
return v___x_117_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1(void){
_start:
{
lean_object* v___x_118_; lean_object* v___x_119_; 
v___x_118_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__2, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__2);
v___x_119_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_118_);
return v___x_119_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits(lean_object* v_bits_120_){
_start:
{
lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v_e_124_; lean_object* v___x_125_; uint8_t v___x_126_; 
v___x_121_ = lean_unsigned_to_nat(52u);
v___x_122_ = lean_nat_shiftr(v_bits_120_, v___x_121_);
v___x_123_ = lean_unsigned_to_nat(2048u);
v_e_124_ = lean_nat_mod(v___x_122_, v___x_123_);
lean_dec(v___x_122_);
v___x_125_ = lean_unsigned_to_nat(2047u);
v___x_126_ = lean_nat_dec_eq(v_e_124_, v___x_125_);
if (v___x_126_ == 0)
{
lean_object* v___x_127_; lean_object* v_fraction_128_; lean_object* v___x_129_; lean_object* v___y_131_; uint8_t v___x_138_; 
v___x_127_ = lean_cstr_to_nat("4503599627370496");
v_fraction_128_ = lean_nat_mod(v_bits_120_, v___x_127_);
v___x_129_ = lean_unsigned_to_nat(0u);
v___x_138_ = lean_nat_dec_eq(v_e_124_, v___x_129_);
if (v___x_138_ == 0)
{
lean_object* v___x_139_; lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; 
v___x_139_ = lean_nat_add(v___x_127_, v_fraction_128_);
lean_dec(v_fraction_128_);
v___x_140_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_139_);
v___x_141_ = lean_nat_to_int(v_e_124_);
v___x_142_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0);
v___x_143_ = lean_int_sub(v___x_141_, v___x_142_);
lean_dec(v___x_141_);
v___x_144_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_143_);
lean_dec(v___x_143_);
v___x_145_ = l_Rat_mul(v___x_140_, v___x_144_);
lean_dec_ref(v___x_140_);
v___y_131_ = v___x_145_;
goto v___jp_130_;
}
else
{
lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; 
lean_dec(v_e_124_);
v___x_146_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_fraction_128_);
v___x_147_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1);
v___x_148_ = l_Rat_mul(v___x_146_, v___x_147_);
lean_dec_ref(v___x_146_);
v___y_131_ = v___x_148_;
goto v___jp_130_;
}
v___jp_130_:
{
lean_object* v___x_132_; lean_object* v___x_133_; uint8_t v___x_134_; 
v___x_132_ = lean_unsigned_to_nat(63u);
v___x_133_ = lean_nat_shiftr(v_bits_120_, v___x_132_);
v___x_134_ = lean_nat_dec_eq(v___x_133_, v___x_129_);
lean_dec(v___x_133_);
if (v___x_134_ == 0)
{
lean_object* v___x_135_; lean_object* v___x_136_; 
v___x_135_ = l_Rat_neg(v___y_131_);
v___x_136_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_136_, 0, v___x_135_);
return v___x_136_;
}
else
{
lean_object* v___x_137_; 
v___x_137_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_137_, 0, v___y_131_);
return v___x_137_;
}
}
}
else
{
lean_object* v___x_149_; 
lean_dec(v_e_124_);
v___x_149_ = lean_box(0);
return v___x_149_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits___boxed(lean_object* v_bits_150_){
_start:
{
lean_object* v_res_151_; 
v_res_151_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v_bits_150_);
lean_dec(v_bits_150_);
return v_res_151_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Std(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Binary64(uint8_t builtin) {
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
lp_lean1090_Lean1090_Impl_Binary64_maxFinite = _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Binary64_maxFinite);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
