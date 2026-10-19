// Lean compiler output
// Module: Impl.CPRFloat
// Imports: public import Init public meta import Init public import Impl.CPRPolicy
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
lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo(lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
double lean_float_of_bits(uint64_t);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_Rat_abs(lean_object*);
uint8_t l_instDecidableEqRat_decEq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent(lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* l_Rat_floor(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
double lean_float_div(double, double);
double floor(double);
double lean_float_mul(double, double);
double lean_float_sub(double, double);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
double lean_uint64_to_float(uint64_t);
double lean_float_of_nat(lean_object*);
double l_Float_ofScientific(lean_object*, uint8_t, lean_object*);
double lean_float_add(double, double);
uint8_t lean_float_decLe(double, double);
uint64_t lean_float_to_bits(double);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_fromBits(lean_object*);
double fabs(double);
uint8_t lean_float_beq(double, double);
extern lean_object* lp_lean1090_Lean1090_Impl_CPR_transitions;
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_CPR_parity(uint8_t);
double lean_float_negate(double);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
double sin(double);
double cos(double);
double sqrt(double);
double atan2(double, double);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
uint8_t lean_float_decLt(double, double);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__7;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__8;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(double, double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0;
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(double, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0;
static const lean_array_object lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__1_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___boxed(lean_object*);
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(double, double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___lam__0(lean_object*, lean_object*);
static const lean_closure_object lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___lam__0, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__0 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__0_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___boxed, .m_arity = 3, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__1 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__1_value;
static const lean_closure_object lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___boxed, .m_arity = 3, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__2 = (const lean_object*)&lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__2_value;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography(lean_object*);
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(0u);
v___x_2_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1(void){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_3_ = lean_unsigned_to_nat(1023u);
v___x_4_ = lean_nat_to_int(v___x_3_);
return v___x_4_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__2(void){
_start:
{
lean_object* v___x_5_; lean_object* v___x_6_; 
v___x_5_ = lean_unsigned_to_nat(1022u);
v___x_6_ = lean_nat_to_int(v___x_5_);
return v___x_6_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__3(void){
_start:
{
lean_object* v___x_7_; lean_object* v___x_8_; 
v___x_7_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__2);
v___x_8_ = lean_int_neg(v___x_7_);
return v___x_8_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__4(void){
_start:
{
lean_object* v___x_9_; lean_object* v___x_10_; 
v___x_9_ = lean_unsigned_to_nat(52u);
v___x_10_ = lean_nat_to_int(v___x_9_);
return v___x_10_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__5(void){
_start:
{
lean_object* v___x_11_; lean_object* v___x_12_; 
v___x_11_ = lean_unsigned_to_nat(1074u);
v___x_12_ = lean_nat_to_int(v___x_11_);
return v___x_12_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__6(void){
_start:
{
lean_object* v___x_13_; lean_object* v___x_14_; 
v___x_13_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__5);
v___x_14_ = lean_int_neg(v___x_13_);
return v___x_14_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__7(void){
_start:
{
lean_object* v___x_15_; lean_object* v___x_16_; 
v___x_15_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__6);
v___x_16_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_15_);
return v___x_16_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__8(void){
_start:
{
lean_object* v___x_17_; 
v___x_17_ = lean_cstr_to_nat("9223372036854775808");
return v___x_17_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(lean_object* v_value_18_){
_start:
{
lean_object* v___y_20_; lean_object* v_rounded_23_; lean_object* v___x_24_; lean_object* v___x_25_; lean_object* v___y_27_; uint8_t v___x_55_; 
v_rounded_23_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_value_18_);
v___x_24_ = lean_unsigned_to_nat(0u);
v___x_25_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0);
lean_inc_ref(v_rounded_23_);
v___x_55_ = l_Rat_blt(v_rounded_23_, v___x_25_);
if (v___x_55_ == 0)
{
v___y_27_ = v___x_24_;
goto v___jp_26_;
}
else
{
lean_object* v___x_56_; 
v___x_56_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__8, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__8_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__8);
v___y_27_ = v___x_56_;
goto v___jp_26_;
}
v___jp_19_:
{
uint64_t v___x_21_; double v___x_22_; 
v___x_21_ = lean_uint64_of_nat(v___y_20_);
lean_dec(v___y_20_);
v___x_22_ = lean_float_of_bits(v___x_21_);
return v___x_22_;
}
v___jp_26_:
{
lean_object* v_magnitude_28_; uint8_t v___x_29_; 
v_magnitude_28_ = l_Rat_abs(v_rounded_23_);
v___x_29_ = l_instDecidableEqRat_decEq(v_magnitude_28_, v___x_25_);
if (v___x_29_ == 0)
{
lean_object* v_exponent_30_; lean_object* v___x_31_; uint8_t v___x_32_; 
lean_inc_ref(v_magnitude_28_);
v_exponent_30_ = lp_lean1090_Lean1090_Impl_Binary64_exponent(v_magnitude_28_);
v___x_31_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1);
v___x_32_ = lean_int_dec_lt(v___x_31_, v_exponent_30_);
if (v___x_32_ == 0)
{
lean_object* v___x_33_; uint8_t v___x_34_; 
v___x_33_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__3);
v___x_34_ = lean_int_dec_lt(v_exponent_30_, v___x_33_);
if (v___x_34_ == 0)
{
lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v___x_45_; lean_object* v___x_46_; lean_object* v___x_47_; 
v___x_35_ = lean_int_add(v_exponent_30_, v___x_31_);
v___x_36_ = l_Int_toNat(v___x_35_);
lean_dec(v___x_35_);
v___x_37_ = lean_cstr_to_nat("4503599627370496");
v___x_38_ = lean_nat_mul(v___x_36_, v___x_37_);
lean_dec(v___x_36_);
v___x_39_ = lean_nat_add(v___y_27_, v___x_38_);
lean_dec(v___x_38_);
lean_dec(v___y_27_);
v___x_40_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__4);
v___x_41_ = lean_int_sub(v_exponent_30_, v___x_40_);
lean_dec(v_exponent_30_);
v___x_42_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_41_);
lean_dec(v___x_41_);
v___x_43_ = l_Rat_div(v_magnitude_28_, v___x_42_);
lean_dec_ref(v_magnitude_28_);
v___x_44_ = l_Rat_floor(v___x_43_);
v___x_45_ = l_Int_toNat(v___x_44_);
lean_dec(v___x_44_);
v___x_46_ = lean_nat_add(v___x_39_, v___x_45_);
lean_dec(v___x_45_);
lean_dec(v___x_39_);
v___x_47_ = lean_nat_sub(v___x_46_, v___x_37_);
lean_dec(v___x_46_);
v___y_20_ = v___x_47_;
goto v___jp_19_;
}
else
{
lean_object* v___x_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; lean_object* v___x_52_; 
lean_dec(v_exponent_30_);
v___x_48_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__7, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__7_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__7);
v___x_49_ = l_Rat_div(v_magnitude_28_, v___x_48_);
lean_dec_ref(v_magnitude_28_);
v___x_50_ = l_Rat_floor(v___x_49_);
v___x_51_ = l_Int_toNat(v___x_50_);
lean_dec(v___x_50_);
v___x_52_ = lean_nat_add(v___y_27_, v___x_51_);
lean_dec(v___x_51_);
lean_dec(v___y_27_);
v___y_20_ = v___x_52_;
goto v___jp_19_;
}
}
else
{
lean_object* v___x_53_; lean_object* v___x_54_; 
lean_dec(v_exponent_30_);
lean_dec_ref(v_magnitude_28_);
v___x_53_ = lean_cstr_to_nat("9218868437227405312");
v___x_54_ = lean_nat_add(v___y_27_, v___x_53_);
lean_dec(v___y_27_);
v___y_20_ = v___x_54_;
goto v___jp_19_;
}
}
else
{
lean_dec_ref(v_magnitude_28_);
v___y_20_ = v___y_27_;
goto v___jp_19_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___boxed(lean_object* v_value_57_){
_start:
{
double v_res_58_; lean_object* v_r_59_; 
v_res_58_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_value_57_);
v_r_59_ = lean_box_float(v_res_58_);
return v_r_59_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0(void){
_start:
{
lean_object* v___x_60_; uint8_t v___x_61_; lean_object* v___x_62_; double v_rad_63_; 
v___x_60_ = lean_unsigned_to_nat(18u);
v___x_61_ = 1;
v___x_62_ = lean_cstr_to_nat("17453292519943295");
v_rad_63_ = l_Float_ofScientific(v___x_62_, v___x_61_, v___x_60_);
return v_rad_63_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1(void){
_start:
{
lean_object* v___x_64_; double v___x_65_; 
v___x_64_ = lean_unsigned_to_nat(2u);
v___x_65_ = lean_float_of_nat(v___x_64_);
return v___x_65_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2(void){
_start:
{
lean_object* v___x_66_; double v___x_67_; 
v___x_66_ = lean_unsigned_to_nat(1u);
v___x_67_ = lean_float_of_nat(v___x_66_);
return v___x_67_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3(void){
_start:
{
lean_object* v___x_68_; double v___x_69_; 
v___x_68_ = lean_unsigned_to_nat(6371u);
v___x_69_ = lean_float_of_nat(v___x_68_);
return v___x_69_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(lean_object* v_a_70_, lean_object* v_b_71_){
_start:
{
lean_object* v_lat_72_; lean_object* v_lon_73_; lean_object* v_lat_74_; lean_object* v_lon_75_; double v_lat1_76_; double v_lon1_77_; double v_lat2_78_; double v_lon2_79_; double v_rad_80_; double v___x_81_; double v_dlat_82_; double v___x_83_; double v_dlon_84_; double v___x_85_; double v___x_86_; double v___x_87_; double v___x_88_; double v___x_89_; double v___x_90_; double v___x_91_; double v___x_92_; double v___x_93_; double v___x_94_; double v___x_95_; double v___x_96_; double v___x_97_; double v_h_98_; double v___x_99_; double v___x_100_; double v___x_101_; double v___x_102_; double v___x_103_; double v_c_104_; double v___x_105_; double v___x_106_; 
v_lat_72_ = lean_ctor_get(v_a_70_, 0);
lean_inc_ref(v_lat_72_);
v_lon_73_ = lean_ctor_get(v_a_70_, 1);
lean_inc_ref(v_lon_73_);
lean_dec_ref(v_a_70_);
v_lat_74_ = lean_ctor_get(v_b_71_, 0);
lean_inc_ref(v_lat_74_);
v_lon_75_ = lean_ctor_get(v_b_71_, 1);
lean_inc_ref(v_lon_75_);
lean_dec_ref(v_b_71_);
v_lat1_76_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lat_72_);
v_lon1_77_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lon_73_);
v_lat2_78_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lat_74_);
v_lon2_79_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lon_75_);
v_rad_80_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0);
v___x_81_ = lean_float_sub(v_lat2_78_, v_lat1_76_);
v_dlat_82_ = lean_float_mul(v___x_81_, v_rad_80_);
v___x_83_ = lean_float_sub(v_lon2_79_, v_lon1_77_);
v_dlon_84_ = lean_float_mul(v___x_83_, v_rad_80_);
v___x_85_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1);
v___x_86_ = lean_float_div(v_dlat_82_, v___x_85_);
v___x_87_ = sin(v___x_86_);
v___x_88_ = lean_float_mul(v___x_87_, v___x_87_);
v___x_89_ = lean_float_mul(v_lat1_76_, v_rad_80_);
v___x_90_ = cos(v___x_89_);
v___x_91_ = lean_float_mul(v_lat2_78_, v_rad_80_);
v___x_92_ = cos(v___x_91_);
v___x_93_ = lean_float_mul(v___x_90_, v___x_92_);
v___x_94_ = lean_float_div(v_dlon_84_, v___x_85_);
v___x_95_ = sin(v___x_94_);
v___x_96_ = lean_float_mul(v___x_93_, v___x_95_);
v___x_97_ = lean_float_mul(v___x_96_, v___x_95_);
v_h_98_ = lean_float_add(v___x_88_, v___x_97_);
v___x_99_ = sqrt(v_h_98_);
v___x_100_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2);
v___x_101_ = lean_float_sub(v___x_100_, v_h_98_);
v___x_102_ = sqrt(v___x_101_);
v___x_103_ = atan2(v___x_99_, v___x_102_);
v_c_104_ = lean_float_mul(v___x_85_, v___x_103_);
v___x_105_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3);
v___x_106_ = lean_float_mul(v___x_105_, v_c_104_);
return v___x_106_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___boxed(lean_object* v_a_107_, lean_object* v_b_108_){
_start:
{
double v_res_109_; lean_object* v_r_110_; 
v_res_109_ = lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(v_a_107_, v_b_108_);
v_r_110_ = lean_box_float(v_res_109_);
return v_r_110_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(double v_value_111_){
_start:
{
uint64_t v___x_112_; lean_object* v_bits_113_; lean_object* v___x_114_; 
v___x_112_ = lean_float_to_bits(v_value_111_);
v_bits_113_ = lean_uint64_to_nat(v___x_112_);
v___x_114_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v_bits_113_);
if (lean_obj_tag(v___x_114_) == 0)
{
lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; uint8_t v___x_118_; 
v___x_115_ = lean_cstr_to_nat("4503599627370496");
v___x_116_ = lean_nat_mod(v_bits_113_, v___x_115_);
v___x_117_ = lean_unsigned_to_nat(0u);
v___x_118_ = lean_nat_dec_eq(v___x_116_, v___x_117_);
lean_dec(v___x_116_);
if (v___x_118_ == 0)
{
lean_object* v___x_119_; 
lean_dec(v_bits_113_);
v___x_119_ = lean_box(1);
return v___x_119_;
}
else
{
lean_object* v___x_120_; lean_object* v___x_121_; uint8_t v___x_122_; 
v___x_120_ = lean_unsigned_to_nat(63u);
v___x_121_ = lean_nat_shiftr(v_bits_113_, v___x_120_);
lean_dec(v_bits_113_);
v___x_122_ = lean_nat_dec_eq(v___x_121_, v___x_117_);
lean_dec(v___x_121_);
if (v___x_122_ == 0)
{
lean_object* v___x_123_; 
v___x_123_ = lean_box(3);
return v___x_123_;
}
else
{
lean_object* v___x_124_; 
v___x_124_ = lean_box(2);
return v___x_124_;
}
}
}
else
{
lean_object* v_val_125_; lean_object* v___x_127_; uint8_t v_isShared_128_; uint8_t v_isSharedCheck_132_; 
lean_dec(v_bits_113_);
v_val_125_ = lean_ctor_get(v___x_114_, 0);
v_isSharedCheck_132_ = !lean_is_exclusive(v___x_114_);
if (v_isSharedCheck_132_ == 0)
{
v___x_127_ = v___x_114_;
v_isShared_128_ = v_isSharedCheck_132_;
goto v_resetjp_126_;
}
else
{
lean_inc(v_val_125_);
lean_dec(v___x_114_);
v___x_127_ = lean_box(0);
v_isShared_128_ = v_isSharedCheck_132_;
goto v_resetjp_126_;
}
v_resetjp_126_:
{
lean_object* v___x_130_; 
if (v_isShared_128_ == 0)
{
lean_ctor_set_tag(v___x_127_, 0);
v___x_130_ = v___x_127_;
goto v_reusejp_129_;
}
else
{
lean_object* v_reuseFailAlloc_131_; 
v_reuseFailAlloc_131_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_131_, 0, v_val_125_);
v___x_130_ = v_reuseFailAlloc_131_;
goto v_reusejp_129_;
}
v_reusejp_129_:
{
return v___x_130_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat___boxed(lean_object* v_value_133_){
_start:
{
double v_value_boxed_134_; lean_object* v_res_135_; 
v_value_boxed_134_ = lean_unbox_float(v_value_133_);
lean_dec_ref(v_value_133_);
v_res_135_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(v_value_boxed_134_);
return v_res_135_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(double v_lat_136_, double v_lon_137_){
_start:
{
uint64_t v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; 
v___x_138_ = lean_float_to_bits(v_lat_136_);
v___x_139_ = lean_uint64_to_nat(v___x_138_);
v___x_140_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v___x_139_);
lean_dec(v___x_139_);
if (lean_obj_tag(v___x_140_) == 0)
{
lean_object* v___x_141_; 
v___x_141_ = lean_box(0);
return v___x_141_;
}
else
{
lean_object* v_val_142_; uint64_t v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; 
v_val_142_ = lean_ctor_get(v___x_140_, 0);
lean_inc(v_val_142_);
lean_dec_ref_known(v___x_140_, 1);
v___x_143_ = lean_float_to_bits(v_lon_137_);
v___x_144_ = lean_uint64_to_nat(v___x_143_);
v___x_145_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v___x_144_);
lean_dec(v___x_144_);
if (lean_obj_tag(v___x_145_) == 0)
{
lean_object* v___x_146_; 
lean_dec(v_val_142_);
v___x_146_ = lean_box(0);
return v___x_146_;
}
else
{
lean_object* v_val_147_; lean_object* v___x_149_; uint8_t v_isShared_150_; uint8_t v_isSharedCheck_155_; 
v_val_147_ = lean_ctor_get(v___x_145_, 0);
v_isSharedCheck_155_ = !lean_is_exclusive(v___x_145_);
if (v_isSharedCheck_155_ == 0)
{
v___x_149_ = v___x_145_;
v_isShared_150_ = v_isSharedCheck_155_;
goto v_resetjp_148_;
}
else
{
lean_inc(v_val_147_);
lean_dec(v___x_145_);
v___x_149_ = lean_box(0);
v_isShared_150_ = v_isSharedCheck_155_;
goto v_resetjp_148_;
}
v_resetjp_148_:
{
lean_object* v___x_151_; lean_object* v___x_153_; 
v___x_151_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_151_, 0, v_val_142_);
lean_ctor_set(v___x_151_, 1, v_val_147_);
if (v_isShared_150_ == 0)
{
lean_ctor_set(v___x_149_, 0, v___x_151_);
v___x_153_ = v___x_149_;
goto v_reusejp_152_;
}
else
{
lean_object* v_reuseFailAlloc_154_; 
v_reuseFailAlloc_154_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_154_, 0, v___x_151_);
v___x_153_ = v_reuseFailAlloc_154_;
goto v_reusejp_152_;
}
v_reusejp_152_:
{
return v___x_153_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats___boxed(lean_object* v_lat_156_, lean_object* v_lon_157_){
_start:
{
double v_lat_boxed_158_; double v_lon_boxed_159_; lean_object* v_res_160_; 
v_lat_boxed_158_ = lean_unbox_float(v_lat_156_);
lean_dec_ref(v_lat_156_);
v_lon_boxed_159_ = lean_unbox_float(v_lon_157_);
lean_dec_ref(v_lon_157_);
v_res_160_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v_lat_boxed_158_, v_lon_boxed_159_);
return v_res_160_;
}
}
static double _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0(void){
_start:
{
lean_object* v___x_161_; double v___x_162_; 
v___x_161_ = lean_unsigned_to_nat(100000000u);
v___x_162_ = lean_float_of_nat(v___x_161_);
return v___x_162_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(double v_lat_163_, lean_object* v_l_164_, lean_object* v_a_165_, lean_object* v_a_166_){
_start:
{
if (lean_obj_tag(v_a_165_) == 0)
{
lean_dec_ref(v_a_166_);
lean_inc(v_l_164_);
return v_l_164_;
}
else
{
lean_object* v_head_167_; lean_object* v_tail_168_; uint64_t v___x_169_; double v___x_170_; double v___x_171_; double v___x_172_; uint8_t v___x_173_; 
v_head_167_ = lean_ctor_get(v_a_165_, 0);
lean_inc(v_head_167_);
v_tail_168_ = lean_ctor_get(v_a_165_, 1);
lean_inc(v_tail_168_);
lean_dec_ref_known(v_a_165_, 2);
v___x_169_ = lean_uint64_of_nat(v_head_167_);
v___x_170_ = lean_uint64_to_float(v___x_169_);
v___x_171_ = lean_float_once(&lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0, &lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0);
v___x_172_ = lean_float_div(v___x_170_, v___x_171_);
v___x_173_ = lean_float_decLe(v___x_172_, v_lat_163_);
if (v___x_173_ == 0)
{
lean_object* v___x_174_; 
lean_dec(v_tail_168_);
lean_dec(v_head_167_);
v___x_174_ = lean_array_to_list(v_a_166_);
return v___x_174_;
}
else
{
lean_object* v___x_175_; 
v___x_175_ = lean_array_push(v_a_166_, v_head_167_);
v_a_165_ = v_tail_168_;
v_a_166_ = v___x_175_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___boxed(lean_object* v_lat_177_, lean_object* v_l_178_, lean_object* v_a_179_, lean_object* v_a_180_){
_start:
{
double v_lat_boxed_181_; lean_object* v_res_182_; 
v_lat_boxed_181_ = lean_unbox_float(v_lat_177_);
lean_dec_ref(v_lat_177_);
v_res_182_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(v_lat_boxed_181_, v_l_178_, v_a_179_, v_a_180_);
lean_dec(v_l_178_);
return v_res_182_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0(void){
_start:
{
lean_object* v___x_183_; double v___x_184_; 
v___x_183_ = lean_unsigned_to_nat(87u);
v___x_184_ = lean_float_of_nat(v___x_183_);
return v___x_184_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(double v_latitude_187_){
_start:
{
double v_lat_188_; double v___x_189_; uint8_t v___x_190_; 
v_lat_188_ = fabs(v_latitude_187_);
v___x_189_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0);
v___x_190_ = lean_float_beq(v_lat_188_, v___x_189_);
if (v___x_190_ == 0)
{
lean_object* v___x_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; 
v___x_191_ = lean_unsigned_to_nat(59u);
v___x_192_ = lp_lean1090_Lean1090_Impl_CPR_transitions;
v___x_193_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__1));
v___x_194_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(v_lat_188_, v___x_192_, v___x_192_, v___x_193_);
v___x_195_ = l_List_lengthTR___redArg(v___x_194_);
lean_dec(v___x_194_);
v___x_196_ = lean_nat_sub(v___x_191_, v___x_195_);
lean_dec(v___x_195_);
return v___x_196_;
}
else
{
lean_object* v___x_197_; 
v___x_197_ = lean_unsigned_to_nat(2u);
return v___x_197_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___boxed(lean_object* v_latitude_198_){
_start:
{
double v_latitude_boxed_199_; lean_object* v_res_200_; 
v_latitude_boxed_199_ = lean_unbox_float(v_latitude_198_);
lean_dec_ref(v_latitude_198_);
v_res_200_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v_latitude_boxed_199_);
return v_res_200_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(double v_a_201_, double v_b_202_){
_start:
{
double v___x_203_; double v___x_204_; double v___x_205_; double v___x_206_; 
v___x_203_ = lean_float_div(v_a_201_, v_b_202_);
v___x_204_ = floor(v___x_203_);
v___x_205_ = lean_float_mul(v_b_202_, v___x_204_);
v___x_206_ = lean_float_sub(v_a_201_, v___x_205_);
return v___x_206_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat___boxed(lean_object* v_a_207_, lean_object* v_b_208_){
_start:
{
double v_a_boxed_209_; double v_b_boxed_210_; double v_res_211_; lean_object* v_r_212_; 
v_a_boxed_209_ = lean_unbox_float(v_a_207_);
lean_dec_ref(v_a_207_);
v_b_boxed_210_ = lean_unbox_float(v_b_208_);
lean_dec_ref(v_b_208_);
v_res_211_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_a_boxed_209_, v_b_boxed_210_);
v_r_212_ = lean_box_float(v_res_211_);
return v_r_212_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0(void){
_start:
{
lean_object* v___x_213_; uint8_t v___x_214_; lean_object* v___x_215_; double v___x_216_; 
v___x_213_ = lean_unsigned_to_nat(1u);
v___x_214_ = 1;
v___x_215_ = lean_unsigned_to_nat(5u);
v___x_216_ = l_Float_ofScientific(v___x_215_, v___x_214_, v___x_213_);
return v___x_216_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1(void){
_start:
{
lean_object* v___x_217_; double v___x_218_; 
v___x_217_ = lean_unsigned_to_nat(90u);
v___x_218_ = lean_float_of_nat(v___x_217_);
return v___x_218_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2(void){
_start:
{
double v___x_219_; double v___x_220_; 
v___x_219_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___x_220_ = lean_float_negate(v___x_219_);
return v___x_220_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3(void){
_start:
{
lean_object* v___x_221_; double v___x_222_; 
v___x_221_ = lean_unsigned_to_nat(131072u);
v___x_222_ = lean_float_of_nat(v___x_221_);
return v___x_222_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4(void){
_start:
{
lean_object* v___x_223_; double v___x_224_; 
v___x_223_ = lean_unsigned_to_nat(60u);
v___x_224_ = lean_float_of_nat(v___x_223_);
return v___x_224_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5(void){
_start:
{
lean_object* v___x_225_; double v___x_226_; 
v___x_225_ = lean_unsigned_to_nat(59u);
v___x_226_ = lean_float_of_nat(v___x_225_);
return v___x_226_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6(void){
_start:
{
lean_object* v___x_227_; double v___x_228_; 
v___x_227_ = lean_unsigned_to_nat(360u);
v___x_228_ = lean_float_of_nat(v___x_227_);
return v___x_228_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat(uint8_t v_mode_229_, lean_object* v_code_230_, lean_object* v_reference_231_){
_start:
{
double v___y_233_; double v___y_234_; double v___y_235_; double v___y_236_; double v___y_237_; double v___y_238_; uint8_t v_odd_251_; lean_object* v_lat_252_; lean_object* v_lon_253_; lean_object* v___x_254_; uint8_t v___x_255_; 
v_odd_251_ = lean_ctor_get_uint8(v_code_230_, sizeof(void*)*2);
v_lat_252_ = lean_ctor_get(v_code_230_, 0);
v_lon_253_ = lean_ctor_get(v_code_230_, 1);
v___x_254_ = lean_unsigned_to_nat(131072u);
v___x_255_ = lean_nat_dec_le(v___x_254_, v_lat_252_);
if (v___x_255_ == 0)
{
uint8_t v___x_256_; 
v___x_256_ = lean_nat_dec_le(v___x_254_, v_lon_253_);
if (v___x_256_ == 0)
{
double v___y_258_; double v___y_259_; double v___y_260_; double v___y_261_; double v___y_295_; 
if (v_mode_229_ == 0)
{
double v___x_305_; 
v___x_305_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___y_295_ = v___x_305_;
goto v___jp_294_;
}
else
{
double v___x_306_; 
v___x_306_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___y_295_ = v___x_306_;
goto v___jp_294_;
}
v___jp_257_:
{
lean_object* v_lat_262_; lean_object* v_lon_263_; double v_dlat_264_; double v_refLat_265_; double v___x_266_; double v___x_267_; double v___x_268_; double v___x_269_; double v_j_270_; double v___x_271_; double v_lat_272_; double v___x_273_; double v___x_274_; uint8_t v___x_275_; 
v_lat_262_ = lean_ctor_get(v_reference_231_, 0);
lean_inc_ref(v_lat_262_);
v_lon_263_ = lean_ctor_get(v_reference_231_, 1);
lean_inc_ref(v_lon_263_);
lean_dec_ref(v_reference_231_);
v_dlat_264_ = lean_float_div(v___y_260_, v___y_261_);
v_refLat_265_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lat_262_);
v___x_266_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0);
v___x_267_ = lean_float_div(v_refLat_265_, v_dlat_264_);
v___x_268_ = lean_float_add(v___x_266_, v___x_267_);
v___x_269_ = lean_float_sub(v___x_268_, v___y_258_);
v_j_270_ = floor(v___x_269_);
v___x_271_ = lean_float_add(v_j_270_, v___y_258_);
v_lat_272_ = lean_float_mul(v_dlat_264_, v___x_271_);
v___x_273_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___x_274_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2);
v___x_275_ = lean_float_decLe(v___x_274_, v_lat_272_);
if (v___x_275_ == 0)
{
lean_object* v___x_276_; 
lean_dec_ref(v_lon_263_);
v___x_276_ = lean_box(0);
return v___x_276_;
}
else
{
uint8_t v___x_277_; 
v___x_277_ = lean_float_decLe(v_lat_272_, v___x_273_);
if (v___x_277_ == 0)
{
lean_object* v___x_278_; 
lean_dec_ref(v_lon_263_);
v___x_278_ = lean_box(0);
return v___x_278_;
}
else
{
double v___x_279_; double v___x_280_; double v___x_281_; double v___x_282_; uint8_t v___x_283_; 
v___x_279_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1);
v___x_280_ = lean_float_div(v_dlat_264_, v___x_279_);
v___x_281_ = lean_float_sub(v_lat_272_, v_refLat_265_);
v___x_282_ = fabs(v___x_281_);
v___x_283_ = lean_float_decLt(v___x_280_, v___x_282_);
if (v___x_283_ == 0)
{
double v_refLon_284_; lean_object* v___x_285_; lean_object* v___x_286_; lean_object* v_ni_287_; lean_object* v___x_288_; uint8_t v___x_289_; 
v_refLon_284_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lon_263_);
v___x_285_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v_lat_272_);
v___x_286_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_odd_251_);
v_ni_287_ = lean_nat_sub(v___x_285_, v___x_286_);
lean_dec(v___x_286_);
lean_dec(v___x_285_);
v___x_288_ = lean_unsigned_to_nat(0u);
v___x_289_ = lean_nat_dec_lt(v___x_288_, v_ni_287_);
if (v___x_289_ == 0)
{
lean_dec(v_ni_287_);
v___y_233_ = v_refLon_284_;
v___y_234_ = v___x_279_;
v___y_235_ = v___x_266_;
v___y_236_ = v___y_259_;
v___y_237_ = v_lat_272_;
v___y_238_ = v___y_260_;
goto v___jp_232_;
}
else
{
uint64_t v___x_290_; double v___x_291_; double v___x_292_; 
v___x_290_ = lean_uint64_of_nat(v_ni_287_);
lean_dec(v_ni_287_);
v___x_291_ = lean_uint64_to_float(v___x_290_);
v___x_292_ = lean_float_div(v___y_260_, v___x_291_);
v___y_233_ = v_refLon_284_;
v___y_234_ = v___x_279_;
v___y_235_ = v___x_266_;
v___y_236_ = v___y_259_;
v___y_237_ = v_lat_272_;
v___y_238_ = v___x_292_;
goto v___jp_232_;
}
}
else
{
lean_object* v___x_293_; 
lean_dec_ref(v_lon_263_);
v___x_293_ = lean_box(0);
return v___x_293_;
}
}
}
}
v___jp_294_:
{
uint64_t v___x_296_; double v___x_297_; double v___x_298_; double v_y_299_; uint64_t v___x_300_; double v___x_301_; double v_x_302_; 
v___x_296_ = lean_uint64_of_nat(v_lat_252_);
v___x_297_ = lean_uint64_to_float(v___x_296_);
v___x_298_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3);
v_y_299_ = lean_float_div(v___x_297_, v___x_298_);
v___x_300_ = lean_uint64_of_nat(v_lon_253_);
v___x_301_ = lean_uint64_to_float(v___x_300_);
v_x_302_ = lean_float_div(v___x_301_, v___x_298_);
if (v_odd_251_ == 0)
{
double v___x_303_; 
v___x_303_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4);
v___y_258_ = v_y_299_;
v___y_259_ = v_x_302_;
v___y_260_ = v___y_295_;
v___y_261_ = v___x_303_;
goto v___jp_257_;
}
else
{
double v___x_304_; 
v___x_304_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5);
v___y_258_ = v_y_299_;
v___y_259_ = v_x_302_;
v___y_260_ = v___y_295_;
v___y_261_ = v___x_304_;
goto v___jp_257_;
}
}
}
else
{
lean_object* v___x_307_; 
lean_dec_ref(v_reference_231_);
v___x_307_ = lean_box(0);
return v___x_307_;
}
}
else
{
lean_object* v___x_308_; 
lean_dec_ref(v_reference_231_);
v___x_308_ = lean_box(0);
return v___x_308_;
}
v___jp_232_:
{
double v___x_239_; double v___x_240_; double v___x_241_; double v_m_242_; double v___x_243_; double v_lon_244_; double v___x_245_; double v___x_246_; double v___x_247_; uint8_t v___x_248_; 
v___x_239_ = lean_float_div(v___y_233_, v___y_238_);
v___x_240_ = lean_float_add(v___y_235_, v___x_239_);
v___x_241_ = lean_float_sub(v___x_240_, v___y_236_);
v_m_242_ = floor(v___x_241_);
v___x_243_ = lean_float_add(v_m_242_, v___y_236_);
v_lon_244_ = lean_float_mul(v___y_238_, v___x_243_);
v___x_245_ = lean_float_div(v___y_238_, v___y_234_);
v___x_246_ = lean_float_sub(v_lon_244_, v___y_233_);
v___x_247_ = fabs(v___x_246_);
v___x_248_ = lean_float_decLt(v___x_245_, v___x_247_);
if (v___x_248_ == 0)
{
lean_object* v___x_249_; 
v___x_249_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v___y_237_, v_lon_244_);
return v___x_249_;
}
else
{
lean_object* v___x_250_; 
v___x_250_ = lean_box(0);
return v___x_250_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___boxed(lean_object* v_mode_309_, lean_object* v_code_310_, lean_object* v_reference_311_){
_start:
{
uint8_t v_mode_boxed_312_; lean_object* v_res_313_; 
v_mode_boxed_312_ = lean_unbox(v_mode_309_);
v_res_313_ = lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat(v_mode_boxed_312_, v_code_310_, v_reference_311_);
lean_dec_ref(v_code_310_);
return v_res_313_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0(void){
_start:
{
lean_object* v___x_314_; double v___x_315_; 
v___x_314_ = lean_unsigned_to_nat(180u);
v___x_315_ = lean_float_of_nat(v___x_314_);
return v___x_315_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1(void){
_start:
{
double v___x_316_; double v___x_317_; double v___x_318_; 
v___x_316_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4);
v___x_317_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___x_318_ = lean_float_div(v___x_317_, v___x_316_);
return v___x_318_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2(void){
_start:
{
double v___x_319_; double v___x_320_; double v___x_321_; 
v___x_319_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5);
v___x_320_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___x_321_ = lean_float_div(v___x_320_, v___x_319_);
return v___x_321_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3(void){
_start:
{
lean_object* v___x_322_; double v___x_323_; 
v___x_322_ = lean_unsigned_to_nat(270u);
v___x_323_ = lean_float_of_nat(v___x_322_);
return v___x_323_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat(lean_object* v_even_324_, lean_object* v_odd_325_, uint8_t v_latestOdd_326_){
_start:
{
uint8_t v_odd_327_; 
v_odd_327_ = lean_ctor_get_uint8(v_even_324_, sizeof(void*)*2);
if (v_odd_327_ == 0)
{
uint8_t v_odd_328_; 
v_odd_328_ = lean_ctor_get_uint8(v_odd_325_, sizeof(void*)*2);
if (v_odd_328_ == 0)
{
lean_object* v___x_329_; 
v___x_329_ = lean_box(0);
return v___x_329_;
}
else
{
lean_object* v_lat_330_; lean_object* v_lon_331_; lean_object* v_lat_332_; lean_object* v_lon_333_; lean_object* v___x_334_; uint8_t v___x_335_; 
v_lat_330_ = lean_ctor_get(v_even_324_, 0);
v_lon_331_ = lean_ctor_get(v_even_324_, 1);
v_lat_332_ = lean_ctor_get(v_odd_325_, 0);
v_lon_333_ = lean_ctor_get(v_odd_325_, 1);
v___x_334_ = lean_unsigned_to_nat(131072u);
v___x_335_ = lean_nat_dec_le(v___x_334_, v_lat_330_);
if (v___x_335_ == 0)
{
uint8_t v___x_336_; 
v___x_336_ = lean_nat_dec_le(v___x_334_, v_lon_331_);
if (v___x_336_ == 0)
{
uint8_t v___x_337_; 
v___x_337_ = lean_nat_dec_le(v___x_334_, v_lat_332_);
if (v___x_337_ == 0)
{
uint8_t v___x_338_; 
v___x_338_ = lean_nat_dec_le(v___x_334_, v_lon_333_);
if (v___x_338_ == 0)
{
uint64_t v___x_339_; double v___x_340_; double v___x_341_; double v_y0_342_; uint64_t v___x_343_; double v___x_344_; double v_y1_345_; uint64_t v___x_346_; double v___x_347_; double v_x0_348_; uint64_t v___x_349_; double v___x_350_; double v_x1_351_; double v___x_352_; double v___x_353_; double v___x_354_; double v___x_355_; double v___x_356_; lean_object* v___x_357_; lean_object* v___x_358_; double v___x_359_; double v___x_360_; double v_j_361_; double v___x_362_; double v___y_364_; double v___y_365_; double v___y_366_; double v___y_367_; lean_object* v___y_376_; double v___y_377_; lean_object* v___y_378_; double v___y_394_; double v___y_400_; double v___y_401_; double v___x_416_; double v___x_417_; double v___x_418_; double v_l0_419_; double v___x_420_; double v___x_421_; double v___x_422_; double v_l1_423_; double v___x_424_; double v___y_426_; uint8_t v___x_429_; 
v___x_339_ = lean_uint64_of_nat(v_lat_330_);
v___x_340_ = lean_uint64_to_float(v___x_339_);
v___x_341_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3);
v_y0_342_ = lean_float_div(v___x_340_, v___x_341_);
v___x_343_ = lean_uint64_of_nat(v_lat_332_);
v___x_344_ = lean_uint64_to_float(v___x_343_);
v_y1_345_ = lean_float_div(v___x_344_, v___x_341_);
v___x_346_ = lean_uint64_of_nat(v_lon_331_);
v___x_347_ = lean_uint64_to_float(v___x_346_);
v_x0_348_ = lean_float_div(v___x_347_, v___x_341_);
v___x_349_ = lean_uint64_of_nat(v_lon_333_);
v___x_350_ = lean_uint64_to_float(v___x_349_);
v_x1_351_ = lean_float_div(v___x_350_, v___x_341_);
v___x_352_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5);
v___x_353_ = lean_float_mul(v___x_352_, v_y0_342_);
v___x_354_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4);
v___x_355_ = lean_float_mul(v___x_354_, v_y1_345_);
v___x_356_ = lean_float_sub(v___x_353_, v___x_355_);
v___x_357_ = lean_unsigned_to_nat(5u);
v___x_358_ = lean_unsigned_to_nat(1u);
v___x_359_ = l_Float_ofScientific(v___x_357_, v_odd_328_, v___x_358_);
v___x_360_ = lean_float_add(v___x_356_, v___x_359_);
v_j_361_ = floor(v___x_360_);
v___x_362_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___x_416_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1);
v___x_417_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_j_361_, v___x_354_);
v___x_418_ = lean_float_add(v___x_417_, v_y0_342_);
v_l0_419_ = lean_float_mul(v___x_416_, v___x_418_);
v___x_420_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2);
v___x_421_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_j_361_, v___x_352_);
v___x_422_ = lean_float_add(v___x_421_, v_y1_345_);
v_l1_423_ = lean_float_mul(v___x_420_, v___x_422_);
v___x_424_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3);
v___x_429_ = lean_float_decLe(v___x_424_, v_l0_419_);
if (v___x_429_ == 0)
{
v___y_426_ = v_l0_419_;
goto v___jp_425_;
}
else
{
double v___x_430_; 
v___x_430_ = lean_float_sub(v_l0_419_, v___x_362_);
v___y_426_ = v___x_430_;
goto v___jp_425_;
}
v___jp_363_:
{
double v___x_368_; double v_lon_369_; double v___x_370_; uint8_t v___x_371_; 
v___x_368_ = lean_float_add(v___y_365_, v___y_367_);
v_lon_369_ = lean_float_mul(v___y_364_, v___x_368_);
v___x_370_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0);
v___x_371_ = lean_float_decLe(v___x_370_, v_lon_369_);
if (v___x_371_ == 0)
{
lean_object* v___x_372_; 
v___x_372_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v___y_366_, v_lon_369_);
return v___x_372_;
}
else
{
double v___x_373_; lean_object* v___x_374_; 
v___x_373_ = lean_float_sub(v_lon_369_, v___x_362_);
v___x_374_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v___y_366_, v___x_373_);
return v___x_374_;
}
}
v___jp_375_:
{
uint64_t v___x_379_; double v_ni_380_; lean_object* v___x_381_; uint64_t v___x_382_; double v___x_383_; double v___x_384_; uint64_t v___x_385_; double v___x_386_; double v___x_387_; double v___x_388_; double v___x_389_; double v_m_390_; double v___x_391_; double v___x_392_; 
v___x_379_ = lean_uint64_of_nat(v___y_378_);
lean_dec(v___y_378_);
v_ni_380_ = lean_uint64_to_float(v___x_379_);
v___x_381_ = lean_nat_sub(v___y_376_, v___x_358_);
v___x_382_ = lean_uint64_of_nat(v___x_381_);
lean_dec(v___x_381_);
v___x_383_ = lean_uint64_to_float(v___x_382_);
v___x_384_ = lean_float_mul(v_x0_348_, v___x_383_);
v___x_385_ = lean_uint64_of_nat(v___y_376_);
lean_dec(v___y_376_);
v___x_386_ = lean_uint64_to_float(v___x_385_);
v___x_387_ = lean_float_mul(v_x1_351_, v___x_386_);
v___x_388_ = lean_float_sub(v___x_384_, v___x_387_);
v___x_389_ = lean_float_add(v___x_388_, v___x_359_);
v_m_390_ = floor(v___x_389_);
v___x_391_ = lean_float_div(v___x_362_, v_ni_380_);
v___x_392_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_m_390_, v_ni_380_);
if (v_latestOdd_326_ == 0)
{
v___y_364_ = v___x_391_;
v___y_365_ = v___x_392_;
v___y_366_ = v___y_377_;
v___y_367_ = v_x0_348_;
goto v___jp_363_;
}
else
{
v___y_364_ = v___x_391_;
v___y_365_ = v___x_392_;
v___y_366_ = v___y_377_;
v___y_367_ = v_x1_351_;
goto v___jp_363_;
}
}
v___jp_393_:
{
lean_object* v_n_395_; lean_object* v___x_396_; lean_object* v___x_397_; uint8_t v___x_398_; 
v_n_395_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v___y_394_);
v___x_396_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_latestOdd_326_);
v___x_397_ = lean_nat_sub(v_n_395_, v___x_396_);
lean_dec(v___x_396_);
v___x_398_ = lean_nat_dec_le(v___x_397_, v___x_358_);
if (v___x_398_ == 0)
{
v___y_376_ = v_n_395_;
v___y_377_ = v___y_394_;
v___y_378_ = v___x_397_;
goto v___jp_375_;
}
else
{
lean_dec(v___x_397_);
v___y_376_ = v_n_395_;
v___y_377_ = v___y_394_;
v___y_378_ = v___x_358_;
goto v___jp_375_;
}
}
v___jp_399_:
{
double v___x_402_; double v___x_403_; uint8_t v___x_404_; 
v___x_402_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___x_403_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2);
v___x_404_ = lean_float_decLe(v___x_403_, v___y_400_);
if (v___x_404_ == 0)
{
lean_object* v___x_405_; 
v___x_405_ = lean_box(0);
return v___x_405_;
}
else
{
uint8_t v___x_406_; 
v___x_406_ = lean_float_decLe(v___y_400_, v___x_402_);
if (v___x_406_ == 0)
{
lean_object* v___x_407_; 
v___x_407_ = lean_box(0);
return v___x_407_;
}
else
{
uint8_t v___x_408_; 
v___x_408_ = lean_float_decLe(v___x_403_, v___y_401_);
if (v___x_408_ == 0)
{
lean_object* v___x_409_; 
v___x_409_ = lean_box(0);
return v___x_409_;
}
else
{
uint8_t v___x_410_; 
v___x_410_ = lean_float_decLe(v___y_401_, v___x_402_);
if (v___x_410_ == 0)
{
lean_object* v___x_411_; 
v___x_411_ = lean_box(0);
return v___x_411_;
}
else
{
lean_object* v___x_412_; lean_object* v___x_413_; uint8_t v___x_414_; 
v___x_412_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v___y_400_);
v___x_413_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v___y_401_);
v___x_414_ = lean_nat_dec_eq(v___x_412_, v___x_413_);
lean_dec(v___x_413_);
lean_dec(v___x_412_);
if (v___x_414_ == 0)
{
lean_object* v___x_415_; 
v___x_415_ = lean_box(0);
return v___x_415_;
}
else
{
if (v_latestOdd_326_ == 0)
{
v___y_394_ = v___y_400_;
goto v___jp_393_;
}
else
{
v___y_394_ = v___y_401_;
goto v___jp_393_;
}
}
}
}
}
}
}
v___jp_425_:
{
uint8_t v___x_427_; 
v___x_427_ = lean_float_decLe(v___x_424_, v_l1_423_);
if (v___x_427_ == 0)
{
v___y_400_ = v___y_426_;
v___y_401_ = v_l1_423_;
goto v___jp_399_;
}
else
{
double v___x_428_; 
v___x_428_ = lean_float_sub(v_l1_423_, v___x_362_);
v___y_400_ = v___y_426_;
v___y_401_ = v___x_428_;
goto v___jp_399_;
}
}
}
else
{
lean_object* v___x_431_; 
v___x_431_ = lean_box(0);
return v___x_431_;
}
}
else
{
lean_object* v___x_432_; 
v___x_432_ = lean_box(0);
return v___x_432_;
}
}
else
{
lean_object* v___x_433_; 
v___x_433_ = lean_box(0);
return v___x_433_;
}
}
else
{
lean_object* v___x_434_; 
v___x_434_ = lean_box(0);
return v___x_434_;
}
}
}
else
{
lean_object* v___x_435_; 
v___x_435_ = lean_box(0);
return v___x_435_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___boxed(lean_object* v_even_436_, lean_object* v_odd_437_, lean_object* v_latestOdd_438_){
_start:
{
uint8_t v_latestOdd_boxed_439_; lean_object* v_res_440_; 
v_latestOdd_boxed_439_ = lean_unbox(v_latestOdd_438_);
v_res_440_ = lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat(v_even_436_, v_odd_437_, v_latestOdd_boxed_439_);
lean_dec_ref(v_odd_437_);
lean_dec_ref(v_even_436_);
return v_res_440_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___lam__0(lean_object* v_a_441_, lean_object* v_b_442_){
_start:
{
double v___x_443_; lean_object* v___x_444_; 
v___x_443_ = lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(v_a_441_, v_b_442_);
v___x_444_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(v___x_443_);
return v___x_444_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography(lean_object* v_airports_448_){
_start:
{
lean_object* v___f_449_; lean_object* v___x_450_; lean_object* v___x_451_; lean_object* v___x_452_; 
v___f_449_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__0));
v___x_450_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__1));
v___x_451_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__2));
v___x_452_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_452_, 0, v___f_449_);
lean_ctor_set(v___x_452_, 1, v_airports_448_);
lean_ctor_set(v___x_452_, 2, v___x_450_);
lean_ctor_set(v___x_452_, 3, v___x_451_);
return v___x_452_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_CPRPolicy(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_CPRFloat(uint8_t builtin) {
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
res = initialize_lean1090_Impl_CPRPolicy(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
