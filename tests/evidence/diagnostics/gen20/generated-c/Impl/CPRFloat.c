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
lean_object* lean_nat_log2(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* lean_int_neg(lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_shiftl(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
double lean_float_of_bits(uint64_t);
uint8_t lean_int_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_abs(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_round(lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_Rat_abs(lean_object*);
uint8_t l_instDecidableEqRat_decEq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* l_Rat_floor(lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
double lean_float_div(double, double);
double floor(double);
double lean_float_mul(double, double);
double lean_float_sub(double, double);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
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
double sin(double);
double cos(double);
double sqrt(double);
double atan2(double, double);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
uint8_t lean_float_decLt(double, double);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__7;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_smallDyadicBits(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_smallDyadicBits___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1;
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
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(0u);
v___x_2_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1(void){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_3_ = lean_unsigned_to_nat(1023u);
v___x_4_ = lean_nat_to_int(v___x_3_);
return v___x_4_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__2(void){
_start:
{
lean_object* v___x_5_; lean_object* v___x_6_; 
v___x_5_ = lean_unsigned_to_nat(1022u);
v___x_6_ = lean_nat_to_int(v___x_5_);
return v___x_6_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3(void){
_start:
{
lean_object* v___x_7_; lean_object* v___x_8_; 
v___x_7_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__2);
v___x_8_ = lean_int_neg(v___x_7_);
return v___x_8_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__4(void){
_start:
{
lean_object* v___x_9_; lean_object* v___x_10_; 
v___x_9_ = lean_unsigned_to_nat(52u);
v___x_10_ = lean_nat_to_int(v___x_9_);
return v___x_10_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__5(void){
_start:
{
lean_object* v___x_11_; lean_object* v___x_12_; 
v___x_11_ = lean_unsigned_to_nat(1074u);
v___x_12_ = lean_nat_to_int(v___x_11_);
return v___x_12_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__6(void){
_start:
{
lean_object* v___x_13_; lean_object* v___x_14_; 
v___x_13_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__5);
v___x_14_ = lean_int_neg(v___x_13_);
return v___x_14_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__7(void){
_start:
{
lean_object* v___x_15_; lean_object* v___x_16_; 
v___x_15_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__6);
v___x_16_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_15_);
return v___x_16_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8(void){
_start:
{
lean_object* v___x_17_; 
v___x_17_ = lean_cstr_to_nat("9223372036854775808");
return v___x_17_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback(lean_object* v_value_18_){
_start:
{
lean_object* v___y_20_; lean_object* v_rounded_23_; lean_object* v___x_24_; lean_object* v___x_25_; lean_object* v___y_27_; uint8_t v___x_55_; 
v_rounded_23_ = lp_lean1090_Lean1090_Impl_Binary64_round(v_value_18_);
v___x_24_ = lean_unsigned_to_nat(0u);
v___x_25_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__0);
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
v___x_56_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8);
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
v___x_31_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1);
v___x_32_ = lean_int_dec_lt(v___x_31_, v_exponent_30_);
if (v___x_32_ == 0)
{
lean_object* v___x_33_; uint8_t v___x_34_; 
v___x_33_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3);
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
v___x_40_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__4);
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
v___x_48_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__7, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__7_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__7);
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___boxed(lean_object* v_value_57_){
_start:
{
double v_res_58_; lean_object* v_r_59_; 
v_res_58_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback(v_value_57_);
v_r_59_ = lean_box_float(v_res_58_);
return v_r_59_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_smallDyadicBits(uint8_t v_negative_60_, lean_object* v_numerator_61_, lean_object* v_denominatorExponent_62_){
_start:
{
lean_object* v_high_63_; lean_object* v___x_64_; lean_object* v___x_65_; lean_object* v_exponent_66_; lean_object* v___y_68_; 
v_high_63_ = lean_nat_log2(v_numerator_61_);
lean_inc(v_high_63_);
v___x_64_ = lean_nat_to_int(v_high_63_);
lean_inc(v_denominatorExponent_62_);
v___x_65_ = lean_nat_to_int(v_denominatorExponent_62_);
v_exponent_66_ = lean_int_sub(v___x_64_, v___x_65_);
lean_dec(v___x_65_);
lean_dec(v___x_64_);
if (v_negative_60_ == 0)
{
lean_object* v___x_86_; 
v___x_86_ = lean_unsigned_to_nat(0u);
v___y_68_ = v___x_86_;
goto v___jp_67_;
}
else
{
lean_object* v___x_87_; 
v___x_87_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8);
v___y_68_ = v___x_87_;
goto v___jp_67_;
}
v___jp_67_:
{
lean_object* v___x_69_; uint8_t v___x_70_; 
v___x_69_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3);
v___x_70_ = lean_int_dec_lt(v_exponent_66_, v___x_69_);
if (v___x_70_ == 0)
{
lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; 
lean_dec(v_denominatorExponent_62_);
v___x_71_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1);
v___x_72_ = lean_int_add(v_exponent_66_, v___x_71_);
lean_dec(v_exponent_66_);
v___x_73_ = l_Int_toNat(v___x_72_);
lean_dec(v___x_72_);
v___x_74_ = lean_unsigned_to_nat(52u);
v___x_75_ = lean_cstr_to_nat("4503599627370496");
v___x_76_ = lean_nat_mul(v___x_73_, v___x_75_);
lean_dec(v___x_73_);
v___x_77_ = lean_nat_add(v___y_68_, v___x_76_);
lean_dec(v___x_76_);
v___x_78_ = lean_nat_sub(v___x_74_, v_high_63_);
lean_dec(v_high_63_);
v___x_79_ = lean_nat_shiftl(v_numerator_61_, v___x_78_);
lean_dec(v___x_78_);
v___x_80_ = lean_nat_add(v___x_77_, v___x_79_);
lean_dec(v___x_79_);
lean_dec(v___x_77_);
v___x_81_ = lean_nat_sub(v___x_80_, v___x_75_);
lean_dec(v___x_80_);
return v___x_81_;
}
else
{
lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; lean_object* v___x_85_; 
lean_dec(v_exponent_66_);
lean_dec(v_high_63_);
v___x_82_ = lean_unsigned_to_nat(1074u);
v___x_83_ = lean_nat_sub(v___x_82_, v_denominatorExponent_62_);
lean_dec(v_denominatorExponent_62_);
v___x_84_ = lean_nat_shiftl(v_numerator_61_, v___x_83_);
lean_dec(v___x_83_);
v___x_85_ = lean_nat_add(v___y_68_, v___x_84_);
lean_dec(v___x_84_);
return v___x_85_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_smallDyadicBits___boxed(lean_object* v_negative_88_, lean_object* v_numerator_89_, lean_object* v_denominatorExponent_90_){
_start:
{
uint8_t v_negative_boxed_91_; lean_object* v_res_92_; 
v_negative_boxed_91_ = lean_unbox(v_negative_88_);
v_res_92_ = lp_lean1090_Lean1090_Impl_CPR_Policy_smallDyadicBits(v_negative_boxed_91_, v_numerator_89_, v_denominatorExponent_90_);
lean_dec(v_numerator_89_);
return v_res_92_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0(void){
_start:
{
lean_object* v___x_93_; lean_object* v___x_94_; 
v___x_93_ = lean_unsigned_to_nat(0u);
v___x_94_ = lean_nat_to_int(v___x_93_);
return v___x_94_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1(void){
_start:
{
uint64_t v___x_95_; double v___x_96_; 
v___x_95_ = 0ULL;
v___x_96_ = lean_float_of_bits(v___x_95_);
return v___x_96_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(lean_object* v_value_97_){
_start:
{
lean_object* v___y_99_; lean_object* v_num_102_; lean_object* v_den_103_; lean_object* v___x_104_; lean_object* v___x_105_; uint8_t v___x_106_; 
v_num_102_ = lean_ctor_get(v_value_97_, 0);
v_den_103_ = lean_ctor_get(v_value_97_, 1);
v___x_104_ = lean_unsigned_to_nat(0u);
v___x_105_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__0);
v___x_106_ = lean_int_dec_eq(v_num_102_, v___x_105_);
if (v___x_106_ == 0)
{
lean_object* v_numerator_107_; lean_object* v___x_108_; uint8_t v___x_109_; 
v_numerator_107_ = lean_nat_abs(v_num_102_);
v___x_108_ = lean_cstr_to_nat("9007199254740992");
v___x_109_ = lean_nat_dec_lt(v_numerator_107_, v___x_108_);
if (v___x_109_ == 0)
{
double v___x_110_; 
lean_dec(v_numerator_107_);
v___x_110_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback(v_value_97_);
return v___x_110_;
}
else
{
lean_object* v_denominatorExponent_111_; lean_object* v___x_112_; uint8_t v___x_113_; 
v_denominatorExponent_111_ = lean_nat_log2(v_den_103_);
v___x_112_ = lean_unsigned_to_nat(1074u);
v___x_113_ = lean_nat_dec_le(v_denominatorExponent_111_, v___x_112_);
if (v___x_113_ == 0)
{
double v___x_114_; 
lean_dec(v_denominatorExponent_111_);
lean_dec(v_numerator_107_);
v___x_114_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback(v_value_97_);
return v___x_114_;
}
else
{
lean_object* v___x_115_; lean_object* v___x_116_; uint8_t v___x_117_; 
v___x_115_ = lean_unsigned_to_nat(1u);
v___x_116_ = lean_nat_shiftl(v___x_115_, v_denominatorExponent_111_);
v___x_117_ = lean_nat_dec_eq(v_den_103_, v___x_116_);
lean_dec(v___x_116_);
if (v___x_117_ == 0)
{
double v___x_118_; 
lean_dec(v_denominatorExponent_111_);
lean_dec(v_numerator_107_);
v___x_118_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback(v_value_97_);
return v___x_118_;
}
else
{
uint8_t v___x_119_; lean_object* v_high_120_; lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v_exponent_123_; lean_object* v___y_125_; 
lean_inc(v_num_102_);
lean_dec_ref(v_value_97_);
v___x_119_ = lean_int_dec_lt(v_num_102_, v___x_105_);
lean_dec(v_num_102_);
v_high_120_ = lean_nat_log2(v_numerator_107_);
lean_inc(v_high_120_);
v___x_121_ = lean_nat_to_int(v_high_120_);
lean_inc(v_denominatorExponent_111_);
v___x_122_ = lean_nat_to_int(v_denominatorExponent_111_);
v_exponent_123_ = lean_int_sub(v___x_121_, v___x_122_);
lean_dec(v___x_122_);
lean_dec(v___x_121_);
if (v___x_119_ == 0)
{
v___y_125_ = v___x_104_;
goto v___jp_124_;
}
else
{
lean_object* v___x_142_; 
v___x_142_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__8);
v___y_125_ = v___x_142_;
goto v___jp_124_;
}
v___jp_124_:
{
lean_object* v___x_126_; uint8_t v___x_127_; 
v___x_126_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__3);
v___x_127_ = lean_int_dec_lt(v_exponent_123_, v___x_126_);
if (v___x_127_ == 0)
{
lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; 
lean_dec(v_denominatorExponent_111_);
v___x_128_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback___closed__1);
v___x_129_ = lean_int_add(v_exponent_123_, v___x_128_);
lean_dec(v_exponent_123_);
v___x_130_ = l_Int_toNat(v___x_129_);
lean_dec(v___x_129_);
v___x_131_ = lean_unsigned_to_nat(52u);
v___x_132_ = lean_cstr_to_nat("4503599627370496");
v___x_133_ = lean_nat_mul(v___x_130_, v___x_132_);
lean_dec(v___x_130_);
v___x_134_ = lean_nat_add(v___y_125_, v___x_133_);
lean_dec(v___x_133_);
v___x_135_ = lean_nat_sub(v___x_131_, v_high_120_);
lean_dec(v_high_120_);
v___x_136_ = lean_nat_shiftl(v_numerator_107_, v___x_135_);
lean_dec(v___x_135_);
lean_dec(v_numerator_107_);
v___x_137_ = lean_nat_add(v___x_134_, v___x_136_);
lean_dec(v___x_136_);
lean_dec(v___x_134_);
v___x_138_ = lean_nat_sub(v___x_137_, v___x_132_);
lean_dec(v___x_137_);
v___y_99_ = v___x_138_;
goto v___jp_98_;
}
else
{
lean_object* v___x_139_; lean_object* v___x_140_; lean_object* v___x_141_; 
lean_dec(v_exponent_123_);
lean_dec(v_high_120_);
v___x_139_ = lean_nat_sub(v___x_112_, v_denominatorExponent_111_);
lean_dec(v_denominatorExponent_111_);
v___x_140_ = lean_nat_shiftl(v_numerator_107_, v___x_139_);
lean_dec(v___x_139_);
lean_dec(v_numerator_107_);
v___x_141_ = lean_nat_add(v___y_125_, v___x_140_);
lean_dec(v___x_140_);
v___y_99_ = v___x_141_;
goto v___jp_98_;
}
}
}
}
}
}
else
{
double v___x_143_; 
lean_dec_ref(v_value_97_);
v___x_143_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___closed__1);
return v___x_143_;
}
v___jp_98_:
{
uint64_t v___x_100_; double v___x_101_; 
v___x_100_ = lean_uint64_of_nat(v___y_99_);
lean_dec(v___y_99_);
v___x_101_ = lean_float_of_bits(v___x_100_);
return v___x_101_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat___boxed(lean_object* v_value_144_){
_start:
{
double v_res_145_; lean_object* v_r_146_; 
v_res_145_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_value_144_);
v_r_146_ = lean_box_float(v_res_145_);
return v_r_146_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0(void){
_start:
{
lean_object* v___x_147_; uint8_t v___x_148_; lean_object* v___x_149_; double v_rad_150_; 
v___x_147_ = lean_unsigned_to_nat(18u);
v___x_148_ = 1;
v___x_149_ = lean_cstr_to_nat("17453292519943295");
v_rad_150_ = l_Float_ofScientific(v___x_149_, v___x_148_, v___x_147_);
return v_rad_150_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1(void){
_start:
{
lean_object* v___x_151_; double v___x_152_; 
v___x_151_ = lean_unsigned_to_nat(2u);
v___x_152_ = lean_float_of_nat(v___x_151_);
return v___x_152_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2(void){
_start:
{
lean_object* v___x_153_; double v___x_154_; 
v___x_153_ = lean_unsigned_to_nat(1u);
v___x_154_ = lean_float_of_nat(v___x_153_);
return v___x_154_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3(void){
_start:
{
lean_object* v___x_155_; double v___x_156_; 
v___x_155_ = lean_unsigned_to_nat(6371u);
v___x_156_ = lean_float_of_nat(v___x_155_);
return v___x_156_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(lean_object* v_a_157_, lean_object* v_b_158_){
_start:
{
lean_object* v_lat_159_; lean_object* v_lon_160_; lean_object* v_lat_161_; lean_object* v_lon_162_; double v_lat1_163_; double v_lon1_164_; double v_lat2_165_; double v_lon2_166_; double v_rad_167_; double v___x_168_; double v_dlat_169_; double v___x_170_; double v_dlon_171_; double v___x_172_; double v___x_173_; double v___x_174_; double v___x_175_; double v___x_176_; double v___x_177_; double v___x_178_; double v___x_179_; double v___x_180_; double v___x_181_; double v___x_182_; double v___x_183_; double v___x_184_; double v_h_185_; double v___x_186_; double v___x_187_; double v___x_188_; double v___x_189_; double v___x_190_; double v_c_191_; double v___x_192_; double v___x_193_; 
v_lat_159_ = lean_ctor_get(v_a_157_, 0);
lean_inc_ref(v_lat_159_);
v_lon_160_ = lean_ctor_get(v_a_157_, 1);
lean_inc_ref(v_lon_160_);
lean_dec_ref(v_a_157_);
v_lat_161_ = lean_ctor_get(v_b_158_, 0);
lean_inc_ref(v_lat_161_);
v_lon_162_ = lean_ctor_get(v_b_158_, 1);
lean_inc_ref(v_lon_162_);
lean_dec_ref(v_b_158_);
v_lat1_163_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lat_159_);
v_lon1_164_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lon_160_);
v_lat2_165_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lat_161_);
v_lon2_166_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lon_162_);
v_rad_167_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__0);
v___x_168_ = lean_float_sub(v_lat2_165_, v_lat1_163_);
v_dlat_169_ = lean_float_mul(v___x_168_, v_rad_167_);
v___x_170_ = lean_float_sub(v_lon2_166_, v_lon1_164_);
v_dlon_171_ = lean_float_mul(v___x_170_, v_rad_167_);
v___x_172_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1);
v___x_173_ = lean_float_div(v_dlat_169_, v___x_172_);
v___x_174_ = sin(v___x_173_);
v___x_175_ = lean_float_mul(v___x_174_, v___x_174_);
v___x_176_ = lean_float_mul(v_lat1_163_, v_rad_167_);
v___x_177_ = cos(v___x_176_);
v___x_178_ = lean_float_mul(v_lat2_165_, v_rad_167_);
v___x_179_ = cos(v___x_178_);
v___x_180_ = lean_float_mul(v___x_177_, v___x_179_);
v___x_181_ = lean_float_div(v_dlon_171_, v___x_172_);
v___x_182_ = sin(v___x_181_);
v___x_183_ = lean_float_mul(v___x_180_, v___x_182_);
v___x_184_ = lean_float_mul(v___x_183_, v___x_182_);
v_h_185_ = lean_float_add(v___x_175_, v___x_184_);
v___x_186_ = sqrt(v_h_185_);
v___x_187_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__2);
v___x_188_ = lean_float_sub(v___x_187_, v_h_185_);
v___x_189_ = sqrt(v___x_188_);
v___x_190_ = atan2(v___x_186_, v___x_189_);
v_c_191_ = lean_float_mul(v___x_172_, v___x_190_);
v___x_192_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__3);
v___x_193_ = lean_float_mul(v___x_192_, v_c_191_);
return v___x_193_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___boxed(lean_object* v_a_194_, lean_object* v_b_195_){
_start:
{
double v_res_196_; lean_object* v_r_197_; 
v_res_196_ = lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(v_a_194_, v_b_195_);
v_r_197_ = lean_box_float(v_res_196_);
return v_r_197_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(double v_value_198_){
_start:
{
uint64_t v___x_199_; lean_object* v_bits_200_; lean_object* v___x_201_; 
v___x_199_ = lean_float_to_bits(v_value_198_);
v_bits_200_ = lean_uint64_to_nat(v___x_199_);
v___x_201_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v_bits_200_);
if (lean_obj_tag(v___x_201_) == 0)
{
lean_object* v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; uint8_t v___x_205_; 
v___x_202_ = lean_cstr_to_nat("4503599627370496");
v___x_203_ = lean_nat_mod(v_bits_200_, v___x_202_);
v___x_204_ = lean_unsigned_to_nat(0u);
v___x_205_ = lean_nat_dec_eq(v___x_203_, v___x_204_);
lean_dec(v___x_203_);
if (v___x_205_ == 0)
{
lean_object* v___x_206_; 
lean_dec(v_bits_200_);
v___x_206_ = lean_box(1);
return v___x_206_;
}
else
{
lean_object* v___x_207_; lean_object* v___x_208_; uint8_t v___x_209_; 
v___x_207_ = lean_unsigned_to_nat(63u);
v___x_208_ = lean_nat_shiftr(v_bits_200_, v___x_207_);
lean_dec(v_bits_200_);
v___x_209_ = lean_nat_dec_eq(v___x_208_, v___x_204_);
lean_dec(v___x_208_);
if (v___x_209_ == 0)
{
lean_object* v___x_210_; 
v___x_210_ = lean_box(3);
return v___x_210_;
}
else
{
lean_object* v___x_211_; 
v___x_211_ = lean_box(2);
return v___x_211_;
}
}
}
else
{
lean_object* v_val_212_; lean_object* v___x_214_; uint8_t v_isShared_215_; uint8_t v_isSharedCheck_219_; 
lean_dec(v_bits_200_);
v_val_212_ = lean_ctor_get(v___x_201_, 0);
v_isSharedCheck_219_ = !lean_is_exclusive(v___x_201_);
if (v_isSharedCheck_219_ == 0)
{
v___x_214_ = v___x_201_;
v_isShared_215_ = v_isSharedCheck_219_;
goto v_resetjp_213_;
}
else
{
lean_inc(v_val_212_);
lean_dec(v___x_201_);
v___x_214_ = lean_box(0);
v_isShared_215_ = v_isSharedCheck_219_;
goto v_resetjp_213_;
}
v_resetjp_213_:
{
lean_object* v___x_217_; 
if (v_isShared_215_ == 0)
{
lean_ctor_set_tag(v___x_214_, 0);
v___x_217_ = v___x_214_;
goto v_reusejp_216_;
}
else
{
lean_object* v_reuseFailAlloc_218_; 
v_reuseFailAlloc_218_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_218_, 0, v_val_212_);
v___x_217_ = v_reuseFailAlloc_218_;
goto v_reusejp_216_;
}
v_reusejp_216_:
{
return v___x_217_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat___boxed(lean_object* v_value_220_){
_start:
{
double v_value_boxed_221_; lean_object* v_res_222_; 
v_value_boxed_221_ = lean_unbox_float(v_value_220_);
lean_dec_ref(v_value_220_);
v_res_222_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(v_value_boxed_221_);
return v_res_222_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(double v_lat_223_, double v_lon_224_){
_start:
{
uint64_t v___x_225_; lean_object* v___x_226_; lean_object* v___x_227_; 
v___x_225_ = lean_float_to_bits(v_lat_223_);
v___x_226_ = lean_uint64_to_nat(v___x_225_);
v___x_227_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v___x_226_);
lean_dec(v___x_226_);
if (lean_obj_tag(v___x_227_) == 0)
{
lean_object* v___x_228_; 
v___x_228_ = lean_box(0);
return v___x_228_;
}
else
{
lean_object* v_val_229_; uint64_t v___x_230_; lean_object* v___x_231_; lean_object* v___x_232_; 
v_val_229_ = lean_ctor_get(v___x_227_, 0);
lean_inc(v_val_229_);
lean_dec_ref_known(v___x_227_, 1);
v___x_230_ = lean_float_to_bits(v_lon_224_);
v___x_231_ = lean_uint64_to_nat(v___x_230_);
v___x_232_ = lp_lean1090_Lean1090_Impl_Binary64_fromBits(v___x_231_);
lean_dec(v___x_231_);
if (lean_obj_tag(v___x_232_) == 0)
{
lean_object* v___x_233_; 
lean_dec(v_val_229_);
v___x_233_ = lean_box(0);
return v___x_233_;
}
else
{
lean_object* v_val_234_; lean_object* v___x_236_; uint8_t v_isShared_237_; uint8_t v_isSharedCheck_242_; 
v_val_234_ = lean_ctor_get(v___x_232_, 0);
v_isSharedCheck_242_ = !lean_is_exclusive(v___x_232_);
if (v_isSharedCheck_242_ == 0)
{
v___x_236_ = v___x_232_;
v_isShared_237_ = v_isSharedCheck_242_;
goto v_resetjp_235_;
}
else
{
lean_inc(v_val_234_);
lean_dec(v___x_232_);
v___x_236_ = lean_box(0);
v_isShared_237_ = v_isSharedCheck_242_;
goto v_resetjp_235_;
}
v_resetjp_235_:
{
lean_object* v___x_238_; lean_object* v___x_240_; 
v___x_238_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_238_, 0, v_val_229_);
lean_ctor_set(v___x_238_, 1, v_val_234_);
if (v_isShared_237_ == 0)
{
lean_ctor_set(v___x_236_, 0, v___x_238_);
v___x_240_ = v___x_236_;
goto v_reusejp_239_;
}
else
{
lean_object* v_reuseFailAlloc_241_; 
v_reuseFailAlloc_241_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_241_, 0, v___x_238_);
v___x_240_ = v_reuseFailAlloc_241_;
goto v_reusejp_239_;
}
v_reusejp_239_:
{
return v___x_240_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats___boxed(lean_object* v_lat_243_, lean_object* v_lon_244_){
_start:
{
double v_lat_boxed_245_; double v_lon_boxed_246_; lean_object* v_res_247_; 
v_lat_boxed_245_ = lean_unbox_float(v_lat_243_);
lean_dec_ref(v_lat_243_);
v_lon_boxed_246_ = lean_unbox_float(v_lon_244_);
lean_dec_ref(v_lon_244_);
v_res_247_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v_lat_boxed_245_, v_lon_boxed_246_);
return v_res_247_;
}
}
static double _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0(void){
_start:
{
lean_object* v___x_248_; double v___x_249_; 
v___x_248_ = lean_unsigned_to_nat(100000000u);
v___x_249_ = lean_float_of_nat(v___x_248_);
return v___x_249_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(double v_lat_250_, lean_object* v_l_251_, lean_object* v_a_252_, lean_object* v_a_253_){
_start:
{
if (lean_obj_tag(v_a_252_) == 0)
{
lean_dec_ref(v_a_253_);
lean_inc(v_l_251_);
return v_l_251_;
}
else
{
lean_object* v_head_254_; lean_object* v_tail_255_; uint64_t v___x_256_; double v___x_257_; double v___x_258_; double v___x_259_; uint8_t v___x_260_; 
v_head_254_ = lean_ctor_get(v_a_252_, 0);
lean_inc(v_head_254_);
v_tail_255_ = lean_ctor_get(v_a_252_, 1);
lean_inc(v_tail_255_);
lean_dec_ref_known(v_a_252_, 2);
v___x_256_ = lean_uint64_of_nat(v_head_254_);
v___x_257_ = lean_uint64_to_float(v___x_256_);
v___x_258_ = lean_float_once(&lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0, &lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0_once, _init_lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___closed__0);
v___x_259_ = lean_float_div(v___x_257_, v___x_258_);
v___x_260_ = lean_float_decLe(v___x_259_, v_lat_250_);
if (v___x_260_ == 0)
{
lean_object* v___x_261_; 
lean_dec(v_tail_255_);
lean_dec(v_head_254_);
v___x_261_ = lean_array_to_list(v_a_253_);
return v___x_261_;
}
else
{
lean_object* v___x_262_; 
v___x_262_ = lean_array_push(v_a_253_, v_head_254_);
v_a_252_ = v_tail_255_;
v_a_253_ = v___x_262_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0___boxed(lean_object* v_lat_264_, lean_object* v_l_265_, lean_object* v_a_266_, lean_object* v_a_267_){
_start:
{
double v_lat_boxed_268_; lean_object* v_res_269_; 
v_lat_boxed_268_ = lean_unbox_float(v_lat_264_);
lean_dec_ref(v_lat_264_);
v_res_269_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(v_lat_boxed_268_, v_l_265_, v_a_266_, v_a_267_);
lean_dec(v_l_265_);
return v_res_269_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0(void){
_start:
{
lean_object* v___x_270_; double v___x_271_; 
v___x_270_ = lean_unsigned_to_nat(87u);
v___x_271_ = lean_float_of_nat(v___x_270_);
return v___x_271_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(double v_latitude_274_){
_start:
{
double v_lat_275_; double v___x_276_; uint8_t v___x_277_; 
v_lat_275_ = fabs(v_latitude_274_);
v___x_276_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__0);
v___x_277_ = lean_float_beq(v_lat_275_, v___x_276_);
if (v___x_277_ == 0)
{
lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v___x_281_; lean_object* v___x_282_; lean_object* v___x_283_; 
v___x_278_ = lean_unsigned_to_nat(59u);
v___x_279_ = lp_lean1090_Lean1090_Impl_CPR_transitions;
v___x_280_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___closed__1));
v___x_281_ = lp_lean1090___private_Init_Data_List_Impl_0__List_takeWhileTR_go___at___00Lean1090_Impl_CPR_Policy_nlFloat_spec__0(v_lat_275_, v___x_279_, v___x_279_, v___x_280_);
v___x_282_ = l_List_lengthTR___redArg(v___x_281_);
lean_dec(v___x_281_);
v___x_283_ = lean_nat_sub(v___x_278_, v___x_282_);
lean_dec(v___x_282_);
return v___x_283_;
}
else
{
lean_object* v___x_284_; 
v___x_284_ = lean_unsigned_to_nat(2u);
return v___x_284_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat___boxed(lean_object* v_latitude_285_){
_start:
{
double v_latitude_boxed_286_; lean_object* v_res_287_; 
v_latitude_boxed_286_ = lean_unbox_float(v_latitude_285_);
lean_dec_ref(v_latitude_285_);
v_res_287_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v_latitude_boxed_286_);
return v_res_287_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(double v_a_288_, double v_b_289_){
_start:
{
double v___x_290_; double v___x_291_; double v___x_292_; double v___x_293_; 
v___x_290_ = lean_float_div(v_a_288_, v_b_289_);
v___x_291_ = floor(v___x_290_);
v___x_292_ = lean_float_mul(v_b_289_, v___x_291_);
v___x_293_ = lean_float_sub(v_a_288_, v___x_292_);
return v___x_293_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat___boxed(lean_object* v_a_294_, lean_object* v_b_295_){
_start:
{
double v_a_boxed_296_; double v_b_boxed_297_; double v_res_298_; lean_object* v_r_299_; 
v_a_boxed_296_ = lean_unbox_float(v_a_294_);
lean_dec_ref(v_a_294_);
v_b_boxed_297_ = lean_unbox_float(v_b_295_);
lean_dec_ref(v_b_295_);
v_res_298_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_a_boxed_296_, v_b_boxed_297_);
v_r_299_ = lean_box_float(v_res_298_);
return v_r_299_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0(void){
_start:
{
lean_object* v___x_300_; uint8_t v___x_301_; lean_object* v___x_302_; double v___x_303_; 
v___x_300_ = lean_unsigned_to_nat(1u);
v___x_301_ = 1;
v___x_302_ = lean_unsigned_to_nat(5u);
v___x_303_ = l_Float_ofScientific(v___x_302_, v___x_301_, v___x_300_);
return v___x_303_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1(void){
_start:
{
lean_object* v___x_304_; double v___x_305_; 
v___x_304_ = lean_unsigned_to_nat(90u);
v___x_305_ = lean_float_of_nat(v___x_304_);
return v___x_305_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2(void){
_start:
{
double v___x_306_; double v___x_307_; 
v___x_306_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___x_307_ = lean_float_negate(v___x_306_);
return v___x_307_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3(void){
_start:
{
lean_object* v___x_308_; double v___x_309_; 
v___x_308_ = lean_unsigned_to_nat(131072u);
v___x_309_ = lean_float_of_nat(v___x_308_);
return v___x_309_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4(void){
_start:
{
lean_object* v___x_310_; double v___x_311_; 
v___x_310_ = lean_unsigned_to_nat(60u);
v___x_311_ = lean_float_of_nat(v___x_310_);
return v___x_311_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5(void){
_start:
{
lean_object* v___x_312_; double v___x_313_; 
v___x_312_ = lean_unsigned_to_nat(59u);
v___x_313_ = lean_float_of_nat(v___x_312_);
return v___x_313_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6(void){
_start:
{
lean_object* v___x_314_; double v___x_315_; 
v___x_314_ = lean_unsigned_to_nat(360u);
v___x_315_ = lean_float_of_nat(v___x_314_);
return v___x_315_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat(uint8_t v_mode_316_, lean_object* v_code_317_, lean_object* v_reference_318_){
_start:
{
double v___y_320_; double v___y_321_; double v___y_322_; double v___y_323_; double v___y_324_; double v___y_325_; uint8_t v_odd_338_; lean_object* v_lat_339_; lean_object* v_lon_340_; lean_object* v___x_341_; uint8_t v___x_342_; 
v_odd_338_ = lean_ctor_get_uint8(v_code_317_, sizeof(void*)*2);
v_lat_339_ = lean_ctor_get(v_code_317_, 0);
v_lon_340_ = lean_ctor_get(v_code_317_, 1);
v___x_341_ = lean_unsigned_to_nat(131072u);
v___x_342_ = lean_nat_dec_le(v___x_341_, v_lat_339_);
if (v___x_342_ == 0)
{
uint8_t v___x_343_; 
v___x_343_ = lean_nat_dec_le(v___x_341_, v_lon_340_);
if (v___x_343_ == 0)
{
double v___y_345_; double v___y_346_; double v___y_347_; double v___y_348_; double v___y_382_; 
if (v_mode_316_ == 0)
{
double v___x_392_; 
v___x_392_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___y_382_ = v___x_392_;
goto v___jp_381_;
}
else
{
double v___x_393_; 
v___x_393_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___y_382_ = v___x_393_;
goto v___jp_381_;
}
v___jp_344_:
{
lean_object* v_lat_349_; lean_object* v_lon_350_; double v_dlat_351_; double v_refLat_352_; double v___x_353_; double v___x_354_; double v___x_355_; double v___x_356_; double v_j_357_; double v___x_358_; double v_lat_359_; double v___x_360_; double v___x_361_; uint8_t v___x_362_; 
v_lat_349_ = lean_ctor_get(v_reference_318_, 0);
lean_inc_ref(v_lat_349_);
v_lon_350_ = lean_ctor_get(v_reference_318_, 1);
lean_inc_ref(v_lon_350_);
lean_dec_ref(v_reference_318_);
v_dlat_351_ = lean_float_div(v___y_347_, v___y_348_);
v_refLat_352_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lat_349_);
v___x_353_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__0);
v___x_354_ = lean_float_div(v_refLat_352_, v_dlat_351_);
v___x_355_ = lean_float_add(v___x_353_, v___x_354_);
v___x_356_ = lean_float_sub(v___x_355_, v___y_345_);
v_j_357_ = floor(v___x_356_);
v___x_358_ = lean_float_add(v_j_357_, v___y_345_);
v_lat_359_ = lean_float_mul(v_dlat_351_, v___x_358_);
v___x_360_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___x_361_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2);
v___x_362_ = lean_float_decLe(v___x_361_, v_lat_359_);
if (v___x_362_ == 0)
{
lean_object* v___x_363_; 
lean_dec_ref(v_lon_350_);
v___x_363_ = lean_box(0);
return v___x_363_;
}
else
{
uint8_t v___x_364_; 
v___x_364_ = lean_float_decLe(v_lat_359_, v___x_360_);
if (v___x_364_ == 0)
{
lean_object* v___x_365_; 
lean_dec_ref(v_lon_350_);
v___x_365_ = lean_box(0);
return v___x_365_;
}
else
{
double v___x_366_; double v___x_367_; double v___x_368_; double v___x_369_; uint8_t v___x_370_; 
v___x_366_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat___closed__1);
v___x_367_ = lean_float_div(v_dlat_351_, v___x_366_);
v___x_368_ = lean_float_sub(v_lat_359_, v_refLat_352_);
v___x_369_ = fabs(v___x_368_);
v___x_370_ = lean_float_decLt(v___x_367_, v___x_369_);
if (v___x_370_ == 0)
{
double v_refLon_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v_ni_374_; lean_object* v___x_375_; uint8_t v___x_376_; 
v_refLon_371_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_lon_350_);
v___x_372_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v_lat_359_);
v___x_373_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_odd_338_);
v_ni_374_ = lean_nat_sub(v___x_372_, v___x_373_);
lean_dec(v___x_373_);
lean_dec(v___x_372_);
v___x_375_ = lean_unsigned_to_nat(0u);
v___x_376_ = lean_nat_dec_lt(v___x_375_, v_ni_374_);
if (v___x_376_ == 0)
{
lean_dec(v_ni_374_);
v___y_320_ = v_lat_359_;
v___y_321_ = v___x_353_;
v___y_322_ = v___y_346_;
v___y_323_ = v_refLon_371_;
v___y_324_ = v___x_366_;
v___y_325_ = v___y_347_;
goto v___jp_319_;
}
else
{
uint64_t v___x_377_; double v___x_378_; double v___x_379_; 
v___x_377_ = lean_uint64_of_nat(v_ni_374_);
lean_dec(v_ni_374_);
v___x_378_ = lean_uint64_to_float(v___x_377_);
v___x_379_ = lean_float_div(v___y_347_, v___x_378_);
v___y_320_ = v_lat_359_;
v___y_321_ = v___x_353_;
v___y_322_ = v___y_346_;
v___y_323_ = v_refLon_371_;
v___y_324_ = v___x_366_;
v___y_325_ = v___x_379_;
goto v___jp_319_;
}
}
else
{
lean_object* v___x_380_; 
lean_dec_ref(v_lon_350_);
v___x_380_ = lean_box(0);
return v___x_380_;
}
}
}
}
v___jp_381_:
{
uint64_t v___x_383_; double v___x_384_; double v___x_385_; double v_y_386_; uint64_t v___x_387_; double v___x_388_; double v_x_389_; 
v___x_383_ = lean_uint64_of_nat(v_lat_339_);
v___x_384_ = lean_uint64_to_float(v___x_383_);
v___x_385_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3);
v_y_386_ = lean_float_div(v___x_384_, v___x_385_);
v___x_387_ = lean_uint64_of_nat(v_lon_340_);
v___x_388_ = lean_uint64_to_float(v___x_387_);
v_x_389_ = lean_float_div(v___x_388_, v___x_385_);
if (v_odd_338_ == 0)
{
double v___x_390_; 
v___x_390_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4);
v___y_345_ = v_y_386_;
v___y_346_ = v_x_389_;
v___y_347_ = v___y_382_;
v___y_348_ = v___x_390_;
goto v___jp_344_;
}
else
{
double v___x_391_; 
v___x_391_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5);
v___y_345_ = v_y_386_;
v___y_346_ = v_x_389_;
v___y_347_ = v___y_382_;
v___y_348_ = v___x_391_;
goto v___jp_344_;
}
}
}
else
{
lean_object* v___x_394_; 
lean_dec_ref(v_reference_318_);
v___x_394_ = lean_box(0);
return v___x_394_;
}
}
else
{
lean_object* v___x_395_; 
lean_dec_ref(v_reference_318_);
v___x_395_ = lean_box(0);
return v___x_395_;
}
v___jp_319_:
{
double v___x_326_; double v___x_327_; double v___x_328_; double v_m_329_; double v___x_330_; double v_lon_331_; double v___x_332_; double v___x_333_; double v___x_334_; uint8_t v___x_335_; 
v___x_326_ = lean_float_div(v___y_323_, v___y_325_);
v___x_327_ = lean_float_add(v___y_321_, v___x_326_);
v___x_328_ = lean_float_sub(v___x_327_, v___y_322_);
v_m_329_ = floor(v___x_328_);
v___x_330_ = lean_float_add(v_m_329_, v___y_322_);
v_lon_331_ = lean_float_mul(v___y_325_, v___x_330_);
v___x_332_ = lean_float_div(v___y_325_, v___y_324_);
v___x_333_ = lean_float_sub(v_lon_331_, v___y_323_);
v___x_334_ = fabs(v___x_333_);
v___x_335_ = lean_float_decLt(v___x_332_, v___x_334_);
if (v___x_335_ == 0)
{
lean_object* v___x_336_; 
v___x_336_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v___y_320_, v_lon_331_);
return v___x_336_;
}
else
{
lean_object* v___x_337_; 
v___x_337_ = lean_box(0);
return v___x_337_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___boxed(lean_object* v_mode_396_, lean_object* v_code_397_, lean_object* v_reference_398_){
_start:
{
uint8_t v_mode_boxed_399_; lean_object* v_res_400_; 
v_mode_boxed_399_ = lean_unbox(v_mode_396_);
v_res_400_ = lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat(v_mode_boxed_399_, v_code_397_, v_reference_398_);
lean_dec_ref(v_code_397_);
return v_res_400_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0(void){
_start:
{
lean_object* v___x_401_; double v___x_402_; 
v___x_401_ = lean_unsigned_to_nat(180u);
v___x_402_ = lean_float_of_nat(v___x_401_);
return v___x_402_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1(void){
_start:
{
double v___x_403_; double v___x_404_; double v___x_405_; 
v___x_403_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4);
v___x_404_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___x_405_ = lean_float_div(v___x_404_, v___x_403_);
return v___x_405_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2(void){
_start:
{
double v___x_406_; double v___x_407_; double v___x_408_; 
v___x_406_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5);
v___x_407_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___x_408_ = lean_float_div(v___x_407_, v___x_406_);
return v___x_408_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3(void){
_start:
{
lean_object* v___x_409_; double v___x_410_; 
v___x_409_ = lean_unsigned_to_nat(270u);
v___x_410_ = lean_float_of_nat(v___x_409_);
return v___x_410_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat(lean_object* v_even_411_, lean_object* v_odd_412_, uint8_t v_latestOdd_413_){
_start:
{
uint8_t v_odd_414_; 
v_odd_414_ = lean_ctor_get_uint8(v_even_411_, sizeof(void*)*2);
if (v_odd_414_ == 0)
{
uint8_t v_odd_415_; 
v_odd_415_ = lean_ctor_get_uint8(v_odd_412_, sizeof(void*)*2);
if (v_odd_415_ == 0)
{
lean_object* v___x_416_; 
v___x_416_ = lean_box(0);
return v___x_416_;
}
else
{
lean_object* v_lat_417_; lean_object* v_lon_418_; lean_object* v_lat_419_; lean_object* v_lon_420_; lean_object* v___x_421_; uint8_t v___x_422_; 
v_lat_417_ = lean_ctor_get(v_even_411_, 0);
v_lon_418_ = lean_ctor_get(v_even_411_, 1);
v_lat_419_ = lean_ctor_get(v_odd_412_, 0);
v_lon_420_ = lean_ctor_get(v_odd_412_, 1);
v___x_421_ = lean_unsigned_to_nat(131072u);
v___x_422_ = lean_nat_dec_le(v___x_421_, v_lat_417_);
if (v___x_422_ == 0)
{
uint8_t v___x_423_; 
v___x_423_ = lean_nat_dec_le(v___x_421_, v_lon_418_);
if (v___x_423_ == 0)
{
uint8_t v___x_424_; 
v___x_424_ = lean_nat_dec_le(v___x_421_, v_lat_419_);
if (v___x_424_ == 0)
{
uint8_t v___x_425_; 
v___x_425_ = lean_nat_dec_le(v___x_421_, v_lon_420_);
if (v___x_425_ == 0)
{
uint64_t v___x_426_; double v___x_427_; double v___x_428_; double v_y0_429_; uint64_t v___x_430_; double v___x_431_; double v_y1_432_; uint64_t v___x_433_; double v___x_434_; double v_x0_435_; uint64_t v___x_436_; double v___x_437_; double v_x1_438_; double v___x_439_; double v___x_440_; double v___x_441_; double v___x_442_; double v___x_443_; lean_object* v___x_444_; lean_object* v___x_445_; double v___x_446_; double v___x_447_; double v_j_448_; double v___x_449_; double v___y_451_; double v___y_452_; double v___y_453_; double v___y_454_; double v___y_463_; lean_object* v___y_464_; lean_object* v___y_465_; double v___y_481_; double v___y_487_; double v___y_488_; double v___x_503_; double v___x_504_; double v___x_505_; double v_l0_506_; double v___x_507_; double v___x_508_; double v___x_509_; double v_l1_510_; double v___x_511_; double v___y_513_; uint8_t v___x_516_; 
v___x_426_ = lean_uint64_of_nat(v_lat_417_);
v___x_427_ = lean_uint64_to_float(v___x_426_);
v___x_428_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__3);
v_y0_429_ = lean_float_div(v___x_427_, v___x_428_);
v___x_430_ = lean_uint64_of_nat(v_lat_419_);
v___x_431_ = lean_uint64_to_float(v___x_430_);
v_y1_432_ = lean_float_div(v___x_431_, v___x_428_);
v___x_433_ = lean_uint64_of_nat(v_lon_418_);
v___x_434_ = lean_uint64_to_float(v___x_433_);
v_x0_435_ = lean_float_div(v___x_434_, v___x_428_);
v___x_436_ = lean_uint64_of_nat(v_lon_420_);
v___x_437_ = lean_uint64_to_float(v___x_436_);
v_x1_438_ = lean_float_div(v___x_437_, v___x_428_);
v___x_439_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__5);
v___x_440_ = lean_float_mul(v___x_439_, v_y0_429_);
v___x_441_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__4);
v___x_442_ = lean_float_mul(v___x_441_, v_y1_432_);
v___x_443_ = lean_float_sub(v___x_440_, v___x_442_);
v___x_444_ = lean_unsigned_to_nat(5u);
v___x_445_ = lean_unsigned_to_nat(1u);
v___x_446_ = l_Float_ofScientific(v___x_444_, v_odd_415_, v___x_445_);
v___x_447_ = lean_float_add(v___x_443_, v___x_446_);
v_j_448_ = floor(v___x_447_);
v___x_449_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__6);
v___x_503_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__1);
v___x_504_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_j_448_, v___x_441_);
v___x_505_ = lean_float_add(v___x_504_, v_y0_429_);
v_l0_506_ = lean_float_mul(v___x_503_, v___x_505_);
v___x_507_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__2);
v___x_508_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_j_448_, v___x_439_);
v___x_509_ = lean_float_add(v___x_508_, v_y1_432_);
v_l1_510_ = lean_float_mul(v___x_507_, v___x_509_);
v___x_511_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__3);
v___x_516_ = lean_float_decLe(v___x_511_, v_l0_506_);
if (v___x_516_ == 0)
{
v___y_513_ = v_l0_506_;
goto v___jp_512_;
}
else
{
double v___x_517_; 
v___x_517_ = lean_float_sub(v_l0_506_, v___x_449_);
v___y_513_ = v___x_517_;
goto v___jp_512_;
}
v___jp_450_:
{
double v___x_455_; double v_lon_456_; double v___x_457_; uint8_t v___x_458_; 
v___x_455_ = lean_float_add(v___y_452_, v___y_454_);
v_lon_456_ = lean_float_mul(v___y_453_, v___x_455_);
v___x_457_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___closed__0);
v___x_458_ = lean_float_decLe(v___x_457_, v_lon_456_);
if (v___x_458_ == 0)
{
lean_object* v___x_459_; 
v___x_459_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v___y_451_, v_lon_456_);
return v___x_459_;
}
else
{
double v___x_460_; lean_object* v___x_461_; 
v___x_460_ = lean_float_sub(v_lon_456_, v___x_449_);
v___x_461_ = lp_lean1090_Lean1090_Impl_CPR_Policy_positionFromFloats(v___y_451_, v___x_460_);
return v___x_461_;
}
}
v___jp_462_:
{
uint64_t v___x_466_; double v_ni_467_; lean_object* v___x_468_; uint64_t v___x_469_; double v___x_470_; double v___x_471_; uint64_t v___x_472_; double v___x_473_; double v___x_474_; double v___x_475_; double v___x_476_; double v_m_477_; double v___x_478_; double v___x_479_; 
v___x_466_ = lean_uint64_of_nat(v___y_465_);
lean_dec(v___y_465_);
v_ni_467_ = lean_uint64_to_float(v___x_466_);
v___x_468_ = lean_nat_sub(v___y_464_, v___x_445_);
v___x_469_ = lean_uint64_of_nat(v___x_468_);
lean_dec(v___x_468_);
v___x_470_ = lean_uint64_to_float(v___x_469_);
v___x_471_ = lean_float_mul(v_x0_435_, v___x_470_);
v___x_472_ = lean_uint64_of_nat(v___y_464_);
lean_dec(v___y_464_);
v___x_473_ = lean_uint64_to_float(v___x_472_);
v___x_474_ = lean_float_mul(v_x1_438_, v___x_473_);
v___x_475_ = lean_float_sub(v___x_471_, v___x_474_);
v___x_476_ = lean_float_add(v___x_475_, v___x_446_);
v_m_477_ = floor(v___x_476_);
v___x_478_ = lean_float_div(v___x_449_, v_ni_467_);
v___x_479_ = lp_lean1090_Lean1090_Impl_CPR_Policy_moduloFloat(v_m_477_, v_ni_467_);
if (v_latestOdd_413_ == 0)
{
v___y_451_ = v___y_463_;
v___y_452_ = v___x_479_;
v___y_453_ = v___x_478_;
v___y_454_ = v_x0_435_;
goto v___jp_450_;
}
else
{
v___y_451_ = v___y_463_;
v___y_452_ = v___x_479_;
v___y_453_ = v___x_478_;
v___y_454_ = v_x1_438_;
goto v___jp_450_;
}
}
v___jp_480_:
{
lean_object* v_n_482_; lean_object* v___x_483_; lean_object* v___x_484_; uint8_t v___x_485_; 
v_n_482_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v___y_481_);
v___x_483_ = lp_lean1090_Lean1090_Impl_CPR_parity(v_latestOdd_413_);
v___x_484_ = lean_nat_sub(v_n_482_, v___x_483_);
lean_dec(v___x_483_);
v___x_485_ = lean_nat_dec_le(v___x_484_, v___x_445_);
if (v___x_485_ == 0)
{
v___y_463_ = v___y_481_;
v___y_464_ = v_n_482_;
v___y_465_ = v___x_484_;
goto v___jp_462_;
}
else
{
lean_dec(v___x_484_);
v___y_463_ = v___y_481_;
v___y_464_ = v_n_482_;
v___y_465_ = v___x_445_;
goto v___jp_462_;
}
}
v___jp_486_:
{
double v___x_489_; double v___x_490_; uint8_t v___x_491_; 
v___x_489_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__1);
v___x_490_ = lean_float_once(&lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2, &lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2_once, _init_lp_lean1090_Lean1090_Impl_CPR_Policy_decodeLocalFloat___closed__2);
v___x_491_ = lean_float_decLe(v___x_490_, v___y_487_);
if (v___x_491_ == 0)
{
lean_object* v___x_492_; 
v___x_492_ = lean_box(0);
return v___x_492_;
}
else
{
uint8_t v___x_493_; 
v___x_493_ = lean_float_decLe(v___y_487_, v___x_489_);
if (v___x_493_ == 0)
{
lean_object* v___x_494_; 
v___x_494_ = lean_box(0);
return v___x_494_;
}
else
{
uint8_t v___x_495_; 
v___x_495_ = lean_float_decLe(v___x_490_, v___y_488_);
if (v___x_495_ == 0)
{
lean_object* v___x_496_; 
v___x_496_ = lean_box(0);
return v___x_496_;
}
else
{
uint8_t v___x_497_; 
v___x_497_ = lean_float_decLe(v___y_488_, v___x_489_);
if (v___x_497_ == 0)
{
lean_object* v___x_498_; 
v___x_498_ = lean_box(0);
return v___x_498_;
}
else
{
lean_object* v___x_499_; lean_object* v___x_500_; uint8_t v___x_501_; 
v___x_499_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v___y_487_);
v___x_500_ = lp_lean1090_Lean1090_Impl_CPR_Policy_nlFloat(v___y_488_);
v___x_501_ = lean_nat_dec_eq(v___x_499_, v___x_500_);
lean_dec(v___x_500_);
lean_dec(v___x_499_);
if (v___x_501_ == 0)
{
lean_object* v___x_502_; 
v___x_502_ = lean_box(0);
return v___x_502_;
}
else
{
if (v_latestOdd_413_ == 0)
{
v___y_481_ = v___y_487_;
goto v___jp_480_;
}
else
{
v___y_481_ = v___y_488_;
goto v___jp_480_;
}
}
}
}
}
}
}
v___jp_512_:
{
uint8_t v___x_514_; 
v___x_514_ = lean_float_decLe(v___x_511_, v_l1_510_);
if (v___x_514_ == 0)
{
v___y_487_ = v___y_513_;
v___y_488_ = v_l1_510_;
goto v___jp_486_;
}
else
{
double v___x_515_; 
v___x_515_ = lean_float_sub(v_l1_510_, v___x_449_);
v___y_487_ = v___y_513_;
v___y_488_ = v___x_515_;
goto v___jp_486_;
}
}
}
else
{
lean_object* v___x_518_; 
v___x_518_ = lean_box(0);
return v___x_518_;
}
}
else
{
lean_object* v___x_519_; 
v___x_519_ = lean_box(0);
return v___x_519_;
}
}
else
{
lean_object* v___x_520_; 
v___x_520_ = lean_box(0);
return v___x_520_;
}
}
else
{
lean_object* v___x_521_; 
v___x_521_ = lean_box(0);
return v___x_521_;
}
}
}
else
{
lean_object* v___x_522_; 
v___x_522_ = lean_box(0);
return v___x_522_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat___boxed(lean_object* v_even_523_, lean_object* v_odd_524_, lean_object* v_latestOdd_525_){
_start:
{
uint8_t v_latestOdd_boxed_526_; lean_object* v_res_527_; 
v_latestOdd_boxed_526_ = lean_unbox(v_latestOdd_525_);
v_res_527_ = lp_lean1090_Lean1090_Impl_CPR_Policy_decodeGlobalFloat(v_even_523_, v_odd_524_, v_latestOdd_boxed_526_);
lean_dec_ref(v_odd_524_);
lean_dec_ref(v_even_523_);
return v_res_527_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___lam__0(lean_object* v_a_528_, lean_object* v_b_529_){
_start:
{
double v___x_530_; lean_object* v___x_531_; 
v___x_530_ = lp_lean1090_Lean1090_Impl_CPR_Policy_haversineFloat(v_a_528_, v_b_529_);
v___x_531_ = lp_lean1090_Lean1090_Impl_CPR_Policy_distanceFromFloat(v___x_530_);
return v___x_531_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography(lean_object* v_airports_535_){
_start:
{
lean_object* v___f_536_; lean_object* v___x_537_; lean_object* v___x_538_; lean_object* v___x_539_; 
v___f_536_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__0));
v___x_537_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__1));
v___x_538_ = ((lean_object*)(lp_lean1090_Lean1090_Impl_CPR_Policy_numericalGeography___closed__2));
v___x_539_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_539_, 0, v___f_536_);
lean_ctor_set(v___x_539_, 1, v_airports_535_);
lean_ctor_set(v___x_539_, 2, v___x_537_);
lean_ctor_set(v___x_539_, 3, v___x_538_);
return v___x_539_;
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
