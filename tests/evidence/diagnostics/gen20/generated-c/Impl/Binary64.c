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
lean_object* lean_int_neg(lean_object*);
uint8_t lean_int_dec_le(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* lean_nat_abs(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* l_Array_ofFn___redArg(lean_object*, lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
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
lean_object* lean_nat_log2(lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
lean_object* l_Rat_sub(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0(lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__0_value;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable;
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(0u);
v___x_2_ = lean_nat_to_int(v___x_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__1(void){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_3_ = lean_unsigned_to_nat(1u);
v___x_4_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_3_);
return v___x_4_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula(lean_object* v_exponent_5_){
_start:
{
lean_object* v___x_6_; uint8_t v___x_7_; 
v___x_6_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__0);
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
v___x_12_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___closed__1);
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula___boxed(lean_object* v_exponent_18_){
_start:
{
lean_object* v_res_19_; 
v_res_19_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula(v_exponent_18_);
lean_dec(v_exponent_18_);
return v_res_19_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0(void){
_start:
{
lean_object* v___x_20_; lean_object* v___x_21_; 
v___x_20_ = lean_unsigned_to_nat(1074u);
v___x_21_ = lean_nat_to_int(v___x_20_);
return v___x_21_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0(lean_object* v_code_22_){
_start:
{
lean_object* v___x_23_; lean_object* v___x_24_; lean_object* v___x_25_; lean_object* v___x_26_; 
v___x_23_ = lean_nat_to_int(v_code_22_);
v___x_24_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0);
v___x_25_ = lean_int_sub(v___x_23_, v___x_24_);
lean_dec(v___x_23_);
v___x_26_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula(v___x_25_);
lean_dec(v___x_25_);
return v___x_26_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1(void){
_start:
{
lean_object* v___f_28_; lean_object* v___x_29_; lean_object* v___x_30_; 
v___f_28_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__0));
v___x_29_ = lean_unsigned_to_nat(2098u);
v___x_30_ = l_Array_ofFn___redArg(v___x_29_, v___f_28_);
return v___x_30_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable(void){
_start:
{
lean_object* v___x_31_; 
v___x_31_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1);
return v___x_31_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0(void){
_start:
{
lean_object* v___x_32_; lean_object* v___x_33_; 
v___x_32_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0);
v___x_33_ = lean_int_neg(v___x_32_);
return v___x_33_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1(void){
_start:
{
lean_object* v___x_34_; lean_object* v___x_35_; 
v___x_34_ = lean_unsigned_to_nat(1023u);
v___x_35_ = lean_nat_to_int(v___x_34_);
return v___x_35_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo(lean_object* v_exponent_36_){
_start:
{
lean_object* v___x_37_; lean_object* v___x_38_; uint8_t v___x_39_; 
v___x_37_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___lam__0___closed__0);
v___x_38_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0);
v___x_39_ = lean_int_dec_le(v___x_38_, v_exponent_36_);
if (v___x_39_ == 0)
{
lean_object* v___x_40_; 
v___x_40_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula(v_exponent_36_);
return v___x_40_;
}
else
{
lean_object* v___x_41_; uint8_t v___x_42_; 
v___x_41_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__1);
v___x_42_ = lean_int_dec_le(v_exponent_36_, v___x_41_);
if (v___x_42_ == 0)
{
lean_object* v___x_43_; 
v___x_43_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwoFormula(v_exponent_36_);
return v___x_43_;
}
else
{
lean_object* v___x_44_; lean_object* v___x_45_; lean_object* v___x_46_; lean_object* v___x_47_; 
v___x_44_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable;
v___x_45_ = lean_int_add(v_exponent_36_, v___x_37_);
v___x_46_ = l_Int_toNat(v___x_45_);
lean_dec(v___x_45_);
v___x_47_ = lean_array_fget_borrowed(v___x_44_, v___x_46_);
lean_dec(v___x_46_);
lean_inc(v___x_47_);
return v___x_47_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo___boxed(lean_object* v_exponent_48_){
_start:
{
lean_object* v_res_49_; 
v_res_49_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v_exponent_48_);
lean_dec(v_exponent_48_);
return v_res_49_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven(lean_object* v_numerator_50_, lean_object* v_denominator_51_){
_start:
{
lean_object* v_q_52_; lean_object* v_r_56_; lean_object* v___x_57_; lean_object* v___x_58_; uint8_t v___x_59_; 
v_q_52_ = lean_nat_div(v_numerator_50_, v_denominator_51_);
v_r_56_ = lean_nat_mod(v_numerator_50_, v_denominator_51_);
v___x_57_ = lean_unsigned_to_nat(2u);
v___x_58_ = lean_nat_mul(v___x_57_, v_r_56_);
lean_dec(v_r_56_);
v___x_59_ = lean_nat_dec_lt(v_denominator_51_, v___x_58_);
if (v___x_59_ == 0)
{
uint8_t v___x_60_; 
v___x_60_ = lean_nat_dec_eq(v___x_58_, v_denominator_51_);
lean_dec(v___x_58_);
if (v___x_60_ == 0)
{
return v_q_52_;
}
else
{
lean_object* v___x_61_; lean_object* v___x_62_; uint8_t v___x_63_; 
v___x_61_ = lean_nat_mod(v_q_52_, v___x_57_);
v___x_62_ = lean_unsigned_to_nat(1u);
v___x_63_ = lean_nat_dec_eq(v___x_61_, v___x_62_);
lean_dec(v___x_61_);
if (v___x_63_ == 0)
{
return v_q_52_;
}
else
{
goto v___jp_53_;
}
}
}
else
{
lean_dec(v___x_58_);
goto v___jp_53_;
}
v___jp_53_:
{
lean_object* v___x_54_; lean_object* v___x_55_; 
v___x_54_ = lean_unsigned_to_nat(1u);
v___x_55_ = lean_nat_add(v_q_52_, v___x_54_);
lean_dec(v_q_52_);
return v___x_55_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven___boxed(lean_object* v_numerator_64_, lean_object* v_denominator_65_){
_start:
{
lean_object* v_res_66_; 
v_res_66_ = lp_lean1090_Lean1090_Impl_Binary64_nearestEven(v_numerator_64_, v_denominator_65_);
lean_dec(v_denominator_65_);
lean_dec(v_numerator_64_);
return v_res_66_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0(void){
_start:
{
lean_object* v___x_67_; lean_object* v___x_68_; 
v___x_67_ = lean_unsigned_to_nat(1u);
v___x_68_ = lean_nat_to_int(v___x_67_);
return v___x_68_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent(lean_object* v_value_69_){
_start:
{
lean_object* v_num_70_; lean_object* v_den_71_; lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v_candidate_77_; lean_object* v___x_78_; lean_object* v___x_79_; uint8_t v___x_80_; 
v_num_70_ = lean_ctor_get(v_value_69_, 0);
v_den_71_ = lean_ctor_get(v_value_69_, 1);
v___x_72_ = lean_nat_abs(v_num_70_);
v___x_73_ = lean_nat_log2(v___x_72_);
lean_dec(v___x_72_);
v___x_74_ = lean_nat_to_int(v___x_73_);
v___x_75_ = lean_nat_log2(v_den_71_);
v___x_76_ = lean_nat_to_int(v___x_75_);
v_candidate_77_ = lean_int_sub(v___x_74_, v___x_76_);
lean_dec(v___x_76_);
lean_dec(v___x_74_);
v___x_78_ = l_Rat_abs(v_value_69_);
v___x_79_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v_candidate_77_);
v___x_80_ = l_Rat_blt(v___x_78_, v___x_79_);
if (v___x_80_ == 0)
{
return v_candidate_77_;
}
else
{
lean_object* v___x_81_; lean_object* v___x_82_; 
v___x_81_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_exponent___closed__0);
v___x_82_ = lean_int_sub(v_candidate_77_, v___x_81_);
lean_dec(v_candidate_77_);
return v___x_82_;
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__0(void){
_start:
{
lean_object* v___x_83_; lean_object* v___x_84_; 
v___x_83_ = lean_unsigned_to_nat(0u);
v___x_84_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_83_);
return v___x_84_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__1(void){
_start:
{
lean_object* v___x_85_; lean_object* v___x_86_; 
v___x_85_ = lean_unsigned_to_nat(52u);
v___x_86_ = lean_nat_to_int(v___x_85_);
return v___x_86_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object* v_value_87_){
_start:
{
lean_object* v___x_88_; lean_object* v___y_90_; uint8_t v___x_102_; 
v___x_88_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__0);
v___x_102_ = l_instDecidableEqRat_decEq(v_value_87_, v___x_88_);
if (v___x_102_ == 0)
{
lean_object* v___x_103_; lean_object* v___x_104_; lean_object* v___x_105_; lean_object* v___x_106_; uint8_t v___x_107_; 
v___x_103_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0);
lean_inc_ref(v_value_87_);
v___x_104_ = lp_lean1090_Lean1090_Impl_Binary64_exponent(v_value_87_);
v___x_105_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_round___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_round___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_round___closed__1);
v___x_106_ = lean_int_sub(v___x_104_, v___x_105_);
lean_dec(v___x_104_);
v___x_107_ = lean_int_dec_le(v___x_103_, v___x_106_);
if (v___x_107_ == 0)
{
lean_dec(v___x_106_);
v___y_90_ = v___x_103_;
goto v___jp_89_;
}
else
{
v___y_90_ = v___x_106_;
goto v___jp_89_;
}
}
else
{
lean_dec_ref(v_value_87_);
return v___x_88_;
}
v___jp_89_:
{
lean_object* v_quantum_91_; lean_object* v___x_92_; lean_object* v_scaled_93_; lean_object* v_num_94_; lean_object* v_den_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v_rounded_99_; uint8_t v___x_100_; 
v_quantum_91_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___y_90_);
lean_dec(v___y_90_);
lean_inc_ref(v_value_87_);
v___x_92_ = l_Rat_abs(v_value_87_);
lean_inc_ref(v_quantum_91_);
v_scaled_93_ = l_Rat_div(v___x_92_, v_quantum_91_);
lean_dec_ref(v___x_92_);
v_num_94_ = lean_ctor_get(v_scaled_93_, 0);
lean_inc(v_num_94_);
v_den_95_ = lean_ctor_get(v_scaled_93_, 1);
lean_inc(v_den_95_);
lean_dec_ref(v_scaled_93_);
v___x_96_ = lean_nat_abs(v_num_94_);
lean_dec(v_num_94_);
v___x_97_ = lp_lean1090_Lean1090_Impl_Binary64_nearestEven(v___x_96_, v_den_95_);
lean_dec(v_den_95_);
lean_dec(v___x_96_);
v___x_98_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_97_);
v_rounded_99_ = l_Rat_mul(v___x_98_, v_quantum_91_);
lean_dec_ref(v___x_98_);
v___x_100_ = l_Rat_blt(v_value_87_, v___x_88_);
if (v___x_100_ == 0)
{
return v_rounded_99_;
}
else
{
lean_object* v___x_101_; 
v___x_101_ = l_Rat_neg(v_rounded_99_);
return v___x_101_;
}
}
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0(void){
_start:
{
lean_object* v___x_108_; lean_object* v___x_109_; 
v___x_108_ = lean_cstr_to_nat("9007199254740991");
v___x_109_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_108_);
return v___x_109_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1(void){
_start:
{
lean_object* v___x_110_; lean_object* v___x_111_; 
v___x_110_ = lean_unsigned_to_nat(971u);
v___x_111_ = lean_nat_to_int(v___x_110_);
return v___x_111_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2(void){
_start:
{
lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_112_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__1);
v___x_113_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_112_);
return v___x_113_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3(void){
_start:
{
lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; 
v___x_114_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__2);
v___x_115_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__0);
v___x_116_ = l_Rat_mul(v___x_115_, v___x_114_);
return v___x_116_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite(void){
_start:
{
lean_object* v___x_117_; 
v___x_117_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3, &lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite___closed__3);
return v___x_117_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_literal(lean_object* v_value_118_){
_start:
{
lean_object* v___x_119_; 
v___x_119_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_value_118_);
return v___x_119_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_add(lean_object* v_a_120_, lean_object* v_b_121_){
_start:
{
lean_object* v___x_122_; lean_object* v___x_123_; 
v___x_122_ = l_Rat_add(v_a_120_, v_b_121_);
v___x_123_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_122_);
return v___x_123_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_sub(lean_object* v_a_124_, lean_object* v_b_125_){
_start:
{
lean_object* v___x_126_; lean_object* v___x_127_; 
v___x_126_ = l_Rat_sub(v_a_124_, v_b_125_);
v___x_127_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_126_);
return v___x_127_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul(lean_object* v_a_128_, lean_object* v_b_129_){
_start:
{
lean_object* v___x_130_; lean_object* v___x_131_; 
v___x_130_ = l_Rat_mul(v_a_128_, v_b_129_);
v___x_131_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_130_);
return v___x_131_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_mul___boxed(lean_object* v_a_132_, lean_object* v_b_133_){
_start:
{
lean_object* v_res_134_; 
v_res_134_ = lp_lean1090_Lean1090_Impl_Binary64_mul(v_a_132_, v_b_133_);
lean_dec_ref(v_a_132_);
return v_res_134_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_div(lean_object* v_a_135_, lean_object* v_b_136_){
_start:
{
lean_object* v___x_137_; lean_object* v___x_138_; 
v___x_137_ = l_Rat_div(v_a_135_, v_b_136_);
v___x_138_ = lp_lean1090_Lean1090_Impl_Binary64_round(v___x_137_);
return v___x_138_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_div___boxed(lean_object* v_a_139_, lean_object* v_b_140_){
_start:
{
lean_object* v_res_141_; 
v_res_141_ = lp_lean1090_Lean1090_Impl_Binary64_div(v_a_139_, v_b_140_);
lean_dec_ref(v_a_139_);
return v_res_141_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0(void){
_start:
{
lean_object* v___x_142_; lean_object* v___x_143_; 
v___x_142_ = lean_unsigned_to_nat(1075u);
v___x_143_ = lean_nat_to_int(v___x_142_);
return v___x_143_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1(void){
_start:
{
lean_object* v___x_144_; lean_object* v___x_145_; 
v___x_144_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwo___closed__0);
v___x_145_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_144_);
return v___x_145_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits(lean_object* v_bits_146_){
_start:
{
lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v_e_150_; lean_object* v___x_151_; uint8_t v___x_152_; 
v___x_147_ = lean_unsigned_to_nat(52u);
v___x_148_ = lean_nat_shiftr(v_bits_146_, v___x_147_);
v___x_149_ = lean_unsigned_to_nat(2048u);
v_e_150_ = lean_nat_mod(v___x_148_, v___x_149_);
lean_dec(v___x_148_);
v___x_151_ = lean_unsigned_to_nat(2047u);
v___x_152_ = lean_nat_dec_eq(v_e_150_, v___x_151_);
if (v___x_152_ == 0)
{
lean_object* v___x_153_; lean_object* v_fraction_154_; lean_object* v___x_155_; lean_object* v___y_157_; uint8_t v___x_164_; 
v___x_153_ = lean_cstr_to_nat("4503599627370496");
v_fraction_154_ = lean_nat_mod(v_bits_146_, v___x_153_);
v___x_155_ = lean_unsigned_to_nat(0u);
v___x_164_ = lean_nat_dec_eq(v_e_150_, v___x_155_);
if (v___x_164_ == 0)
{
lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; 
v___x_165_ = lean_nat_add(v___x_153_, v_fraction_154_);
lean_dec(v_fraction_154_);
v___x_166_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_165_);
v___x_167_ = lean_nat_to_int(v_e_150_);
v___x_168_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0, &lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__0);
v___x_169_ = lean_int_sub(v___x_167_, v___x_168_);
lean_dec(v___x_167_);
v___x_170_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_169_);
lean_dec(v___x_169_);
v___x_171_ = l_Rat_mul(v___x_166_, v___x_170_);
lean_dec_ref(v___x_166_);
v___y_157_ = v___x_171_;
goto v___jp_156_;
}
else
{
lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; 
lean_dec(v_e_150_);
v___x_172_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v_fraction_154_);
v___x_173_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1, &lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Binary64_fromBits___closed__1);
v___x_174_ = l_Rat_mul(v___x_172_, v___x_173_);
lean_dec_ref(v___x_172_);
v___y_157_ = v___x_174_;
goto v___jp_156_;
}
v___jp_156_:
{
lean_object* v___x_158_; lean_object* v___x_159_; uint8_t v___x_160_; 
v___x_158_ = lean_unsigned_to_nat(63u);
v___x_159_ = lean_nat_shiftr(v_bits_146_, v___x_158_);
v___x_160_ = lean_nat_dec_eq(v___x_159_, v___x_155_);
lean_dec(v___x_159_);
if (v___x_160_ == 0)
{
lean_object* v___x_161_; lean_object* v___x_162_; 
v___x_161_ = l_Rat_neg(v___y_157_);
v___x_162_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_162_, 0, v___x_161_);
return v___x_162_;
}
else
{
lean_object* v___x_163_; 
v___x_163_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_163_, 0, v___y_157_);
return v___x_163_;
}
}
}
else
{
lean_object* v___x_175_; 
lean_dec(v_e_150_);
v___x_175_ = lean_box(0);
return v___x_175_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits___boxed(lean_object* v_bits_176_){
_start:
{
lean_object* v_res_177_; 
v_res_177_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v_bits_176_);
lean_dec(v_bits_176_);
return v_res_177_;
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
lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable = _init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable);
lp_lean1090_Lean1090_Impl_Binary64_maxFinite = _init_lp_lean1090_Lean1090_Impl_Binary64_maxFinite();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Binary64_maxFinite);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
