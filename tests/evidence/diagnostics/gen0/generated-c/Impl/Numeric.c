// Lean compiler output
// Module: Impl.Numeric
// Imports: public import Init public meta import Init public import Impl.CPRFloat public import Impl.Libm
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
uint32_t lean_uint32_of_nat(lean_object*);
float lean_float32_of_bits(uint32_t);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_exponent(lean_object*);
uint8_t l_instDecidableEqRat_decEq(lean_object*, lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_int_add(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_powerTwo(lean_object*);
lean_object* l_Rat_div(lean_object*, lean_object*);
lean_object* l_Rat_floor(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_Rat_abs(lean_object*);
lean_object* lean_nat_abs(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Binary64_nearestEven(lean_object*, lean_object*);
lean_object* l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(lean_object*);
lean_object* l_Rat_mul(lean_object*, lean_object*);
uint8_t l_Rat_blt(lean_object*, lean_object*);
uint8_t lean_int_dec_le(lean_object*, lean_object*);
double lean_float32_to_float(float);
double lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(lean_object*);
float lean_float_to_float32(double);
float lean_float32_add(float, float);
double lean_float_add(double, double);
float lean_float32_sub(float, float);
double lean_float_sub(double, double);
float lean_float32_mul(float, float);
double lean_float_mul(double, double);
float lean_float32_div(float, float);
double lean_float_div(double, double);
double fabs(double);
double lp_lean1090_Lean1090_Impl_Libm_hypot(double, double);
double lp_lean1090_Lean1090_Impl_Libm_atan2(double, double);
double lean_float_of_nat(lean_object*);
uint8_t lean_float_decLt(double, double);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__7;
LEAN_EXPORT float lp_lean1090_Lean1090_Impl_Numeric_toFloat32(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___boxed(lean_object*);
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Numeric_hypot(double, double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Numeric_hypot___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_eval___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Numeric_eval___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Numeric_eval___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Numeric_eval___closed__1;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Numeric_eval(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Numeric_eval___boxed(lean_object*);
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(149u);
v___x_2_ = lean_nat_to_int(v___x_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1(void){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_3_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__0, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__0);
v___x_4_ = lean_int_neg(v___x_3_);
return v___x_4_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__2(void){
_start:
{
lean_object* v___x_5_; lean_object* v___x_6_; 
v___x_5_ = lean_unsigned_to_nat(23u);
v___x_6_ = lean_nat_to_int(v___x_5_);
return v___x_6_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__3(void){
_start:
{
lean_object* v___x_7_; lean_object* v___x_8_; 
v___x_7_ = lean_unsigned_to_nat(127u);
v___x_8_ = lean_nat_to_int(v___x_7_);
return v___x_8_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__4(void){
_start:
{
lean_object* v___x_9_; lean_object* v___x_10_; 
v___x_9_ = lean_unsigned_to_nat(126u);
v___x_10_ = lean_nat_to_int(v___x_9_);
return v___x_10_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__5(void){
_start:
{
lean_object* v___x_11_; lean_object* v___x_12_; 
v___x_11_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__4, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__4_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__4);
v___x_12_ = lean_int_neg(v___x_11_);
return v___x_12_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__6(void){
_start:
{
lean_object* v___x_13_; lean_object* v___x_14_; 
v___x_13_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1);
v___x_14_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_13_);
return v___x_14_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__7(void){
_start:
{
lean_object* v___x_15_; lean_object* v___x_16_; 
v___x_15_ = lean_unsigned_to_nat(0u);
v___x_16_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_15_);
return v___x_16_;
}
}
LEAN_EXPORT float lp_lean1090_Lean1090_Impl_Numeric_toFloat32(lean_object* v_value_17_){
_start:
{
lean_object* v___y_19_; lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v___x_24_; lean_object* v___y_26_; lean_object* v___y_27_; lean_object* v___y_28_; lean_object* v___y_55_; lean_object* v___x_69_; uint8_t v___x_70_; 
v___x_22_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__1);
lean_inc_ref(v_value_17_);
v___x_23_ = lp_lean1090_Lean1090_Impl_Binary64_exponent(v_value_17_);
v___x_24_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__2, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__2);
v___x_69_ = lean_int_sub(v___x_23_, v___x_24_);
lean_dec(v___x_23_);
v___x_70_ = lean_int_dec_le(v___x_22_, v___x_69_);
if (v___x_70_ == 0)
{
lean_dec(v___x_69_);
v___y_55_ = v___x_22_;
goto v___jp_54_;
}
else
{
v___y_55_ = v___x_69_;
goto v___jp_54_;
}
v___jp_18_:
{
uint32_t v___x_20_; float v___x_21_; 
v___x_20_ = lean_uint32_of_nat(v___y_19_);
lean_dec(v___y_19_);
v___x_21_ = lean_float32_of_bits(v___x_20_);
return v___x_21_;
}
v___jp_25_:
{
uint8_t v___x_29_; 
v___x_29_ = l_instDecidableEqRat_decEq(v___y_26_, v___y_27_);
lean_dec_ref(v___y_27_);
if (v___x_29_ == 0)
{
lean_object* v_exponent_30_; lean_object* v___x_31_; uint8_t v___x_32_; 
lean_inc_ref(v___y_26_);
v_exponent_30_ = lp_lean1090_Lean1090_Impl_Binary64_exponent(v___y_26_);
v___x_31_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__3, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__3);
v___x_32_ = lean_int_dec_lt(v___x_31_, v_exponent_30_);
if (v___x_32_ == 0)
{
lean_object* v___x_33_; uint8_t v___x_34_; 
v___x_33_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__5, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__5_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__5);
v___x_34_ = lean_int_dec_lt(v_exponent_30_, v___x_33_);
if (v___x_34_ == 0)
{
lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_35_ = lean_int_add(v_exponent_30_, v___x_31_);
v___x_36_ = l_Int_toNat(v___x_35_);
lean_dec(v___x_35_);
v___x_37_ = lean_unsigned_to_nat(8388608u);
v___x_38_ = lean_nat_mul(v___x_36_, v___x_37_);
lean_dec(v___x_36_);
v___x_39_ = lean_nat_add(v___y_28_, v___x_38_);
lean_dec(v___x_38_);
lean_dec(v___y_28_);
v___x_40_ = lean_int_sub(v_exponent_30_, v___x_24_);
lean_dec(v_exponent_30_);
v___x_41_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___x_40_);
lean_dec(v___x_40_);
v___x_42_ = l_Rat_div(v___y_26_, v___x_41_);
lean_dec_ref(v___y_26_);
v___x_43_ = l_Rat_floor(v___x_42_);
v___x_44_ = l_Int_toNat(v___x_43_);
lean_dec(v___x_43_);
v___x_45_ = lean_nat_add(v___x_39_, v___x_44_);
lean_dec(v___x_44_);
lean_dec(v___x_39_);
v___x_46_ = lean_nat_sub(v___x_45_, v___x_37_);
lean_dec(v___x_45_);
v___y_19_ = v___x_46_;
goto v___jp_18_;
}
else
{
lean_object* v___x_47_; lean_object* v___x_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; 
lean_dec(v_exponent_30_);
v___x_47_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__6, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__6_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__6);
v___x_48_ = l_Rat_div(v___y_26_, v___x_47_);
lean_dec_ref(v___y_26_);
v___x_49_ = l_Rat_floor(v___x_48_);
v___x_50_ = l_Int_toNat(v___x_49_);
lean_dec(v___x_49_);
v___x_51_ = lean_nat_add(v___y_28_, v___x_50_);
lean_dec(v___x_50_);
lean_dec(v___y_28_);
v___y_19_ = v___x_51_;
goto v___jp_18_;
}
}
else
{
lean_object* v___x_52_; lean_object* v___x_53_; 
lean_dec(v_exponent_30_);
lean_dec_ref(v___y_26_);
v___x_52_ = lean_unsigned_to_nat(2139095040u);
v___x_53_ = lean_nat_add(v___y_28_, v___x_52_);
lean_dec(v___y_28_);
v___y_19_ = v___x_53_;
goto v___jp_18_;
}
}
else
{
lean_dec_ref(v___y_26_);
v___y_19_ = v___y_28_;
goto v___jp_18_;
}
}
v___jp_54_:
{
lean_object* v_quantum_56_; lean_object* v___x_57_; lean_object* v_scaled_58_; lean_object* v_num_59_; lean_object* v_den_60_; lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; lean_object* v_magnitude_64_; lean_object* v___x_65_; lean_object* v___x_66_; uint8_t v___x_67_; 
v_quantum_56_ = lp_lean1090_Lean1090_Impl_Binary64_powerTwo(v___y_55_);
lean_dec(v___y_55_);
lean_inc_ref(v_value_17_);
v___x_57_ = l_Rat_abs(v_value_17_);
lean_inc_ref(v_quantum_56_);
v_scaled_58_ = l_Rat_div(v___x_57_, v_quantum_56_);
lean_dec_ref(v___x_57_);
v_num_59_ = lean_ctor_get(v_scaled_58_, 0);
lean_inc(v_num_59_);
v_den_60_ = lean_ctor_get(v_scaled_58_, 1);
lean_inc(v_den_60_);
lean_dec_ref(v_scaled_58_);
v___x_61_ = lean_nat_abs(v_num_59_);
lean_dec(v_num_59_);
v___x_62_ = lp_lean1090_Lean1090_Impl_Binary64_nearestEven(v___x_61_, v_den_60_);
lean_dec(v_den_60_);
lean_dec(v___x_61_);
v___x_63_ = l_Nat_cast___at___00Std_Http_Internal_Test_defaultConfig_spec__0(v___x_62_);
v_magnitude_64_ = l_Rat_mul(v___x_63_, v_quantum_56_);
lean_dec_ref(v___x_63_);
v___x_65_ = lean_unsigned_to_nat(0u);
v___x_66_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__7, &lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__7_once, _init_lp_lean1090_Lean1090_Impl_Numeric_toFloat32___closed__7);
v___x_67_ = l_Rat_blt(v_value_17_, v___x_66_);
if (v___x_67_ == 0)
{
v___y_26_ = v_magnitude_64_;
v___y_27_ = v___x_66_;
v___y_28_ = v___x_65_;
goto v___jp_25_;
}
else
{
lean_object* v___x_68_; 
v___x_68_ = lean_unsigned_to_nat(2147483648u);
v___y_26_ = v_magnitude_64_;
v___y_27_ = v___x_66_;
v___y_28_ = v___x_68_;
goto v___jp_25_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Numeric_toFloat32___boxed(lean_object* v_value_71_){
_start:
{
float v_res_72_; lean_object* v_r_73_; 
v_res_72_ = lp_lean1090_Lean1090_Impl_Numeric_toFloat32(v_value_71_);
v_r_73_ = lean_box_float32(v_res_72_);
return v_r_73_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Numeric_hypot(double v_x_74_, double v_y_75_){
_start:
{
double v___x_76_; 
v___x_76_ = lp_lean1090_Lean1090_Impl_Libm_hypot(v_x_74_, v_y_75_);
return v___x_76_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Numeric_hypot___boxed(lean_object* v_x_77_, lean_object* v_y_78_){
_start:
{
double v_x_boxed_79_; double v_y_boxed_80_; double v_res_81_; lean_object* v_r_82_; 
v_x_boxed_79_ = lean_unbox_float(v_x_77_);
lean_dec_ref(v_x_77_);
v_y_boxed_80_ = lean_unbox_float(v_y_78_);
lean_dec_ref(v_y_78_);
v_res_81_ = lp_lean1090_Lean1090_Impl_Numeric_hypot(v_x_boxed_79_, v_y_boxed_80_);
v_r_82_ = lean_box_float(v_res_81_);
return v_r_82_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Numeric_eval___closed__0(void){
_start:
{
lean_object* v___x_83_; double v___x_84_; 
v___x_83_ = lean_unsigned_to_nat(0u);
v___x_84_ = lean_float_of_nat(v___x_83_);
return v___x_84_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Numeric_eval___closed__1(void){
_start:
{
lean_object* v___x_85_; double v___x_86_; 
v___x_85_ = lean_unsigned_to_nat(360u);
v___x_86_ = lean_float_of_nat(v___x_85_);
return v___x_86_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Numeric_eval(lean_object* v_x_87_){
_start:
{
switch(lean_obj_tag(v_x_87_))
{
case 0:
{
uint8_t v_precision_88_; 
v_precision_88_ = lean_ctor_get_uint8(v_x_87_, sizeof(void*)*1);
if (v_precision_88_ == 0)
{
lean_object* v_value_89_; float v___x_90_; double v___x_91_; 
v_value_89_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_value_89_);
lean_dec_ref_known(v_x_87_, 1);
v___x_90_ = lp_lean1090_Lean1090_Impl_Numeric_toFloat32(v_value_89_);
v___x_91_ = lean_float32_to_float(v___x_90_);
return v___x_91_;
}
else
{
lean_object* v_value_92_; double v___x_93_; 
v_value_92_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_value_92_);
lean_dec_ref_known(v_x_87_, 1);
v___x_93_ = lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat(v_value_92_);
return v___x_93_;
}
}
case 1:
{
uint8_t v_precision_94_; 
v_precision_94_ = lean_ctor_get_uint8(v_x_87_, sizeof(void*)*2);
if (v_precision_94_ == 0)
{
lean_object* v_a_95_; lean_object* v_b_96_; double v___x_97_; float v___x_98_; double v___x_99_; float v___x_100_; float v___x_101_; double v___x_102_; 
v_a_95_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_95_);
v_b_96_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_96_);
lean_dec_ref_known(v_x_87_, 2);
v___x_97_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_95_);
v___x_98_ = lean_float_to_float32(v___x_97_);
v___x_99_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_96_);
v___x_100_ = lean_float_to_float32(v___x_99_);
v___x_101_ = lean_float32_add(v___x_98_, v___x_100_);
v___x_102_ = lean_float32_to_float(v___x_101_);
return v___x_102_;
}
else
{
lean_object* v_a_103_; lean_object* v_b_104_; double v___x_105_; double v___x_106_; double v___x_107_; 
v_a_103_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_103_);
v_b_104_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_104_);
lean_dec_ref_known(v_x_87_, 2);
v___x_105_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_103_);
v___x_106_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_104_);
v___x_107_ = lean_float_add(v___x_105_, v___x_106_);
return v___x_107_;
}
}
case 2:
{
uint8_t v_precision_108_; 
v_precision_108_ = lean_ctor_get_uint8(v_x_87_, sizeof(void*)*2);
if (v_precision_108_ == 0)
{
lean_object* v_a_109_; lean_object* v_b_110_; double v___x_111_; float v___x_112_; double v___x_113_; float v___x_114_; float v___x_115_; double v___x_116_; 
v_a_109_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_109_);
v_b_110_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_110_);
lean_dec_ref_known(v_x_87_, 2);
v___x_111_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_109_);
v___x_112_ = lean_float_to_float32(v___x_111_);
v___x_113_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_110_);
v___x_114_ = lean_float_to_float32(v___x_113_);
v___x_115_ = lean_float32_sub(v___x_112_, v___x_114_);
v___x_116_ = lean_float32_to_float(v___x_115_);
return v___x_116_;
}
else
{
lean_object* v_a_117_; lean_object* v_b_118_; double v___x_119_; double v___x_120_; double v___x_121_; 
v_a_117_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_117_);
v_b_118_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_118_);
lean_dec_ref_known(v_x_87_, 2);
v___x_119_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_117_);
v___x_120_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_118_);
v___x_121_ = lean_float_sub(v___x_119_, v___x_120_);
return v___x_121_;
}
}
case 3:
{
uint8_t v_precision_122_; 
v_precision_122_ = lean_ctor_get_uint8(v_x_87_, sizeof(void*)*2);
if (v_precision_122_ == 0)
{
lean_object* v_a_123_; lean_object* v_b_124_; double v___x_125_; float v___x_126_; double v___x_127_; float v___x_128_; float v___x_129_; double v___x_130_; 
v_a_123_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_123_);
v_b_124_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_124_);
lean_dec_ref_known(v_x_87_, 2);
v___x_125_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_123_);
v___x_126_ = lean_float_to_float32(v___x_125_);
v___x_127_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_124_);
v___x_128_ = lean_float_to_float32(v___x_127_);
v___x_129_ = lean_float32_mul(v___x_126_, v___x_128_);
v___x_130_ = lean_float32_to_float(v___x_129_);
return v___x_130_;
}
else
{
lean_object* v_a_131_; lean_object* v_b_132_; double v___x_133_; double v___x_134_; double v___x_135_; 
v_a_131_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_131_);
v_b_132_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_132_);
lean_dec_ref_known(v_x_87_, 2);
v___x_133_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_131_);
v___x_134_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_132_);
v___x_135_ = lean_float_mul(v___x_133_, v___x_134_);
return v___x_135_;
}
}
case 4:
{
uint8_t v_precision_136_; 
v_precision_136_ = lean_ctor_get_uint8(v_x_87_, sizeof(void*)*2);
if (v_precision_136_ == 0)
{
lean_object* v_a_137_; lean_object* v_b_138_; double v___x_139_; float v___x_140_; double v___x_141_; float v___x_142_; float v___x_143_; double v___x_144_; 
v_a_137_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_137_);
v_b_138_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_138_);
lean_dec_ref_known(v_x_87_, 2);
v___x_139_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_137_);
v___x_140_ = lean_float_to_float32(v___x_139_);
v___x_141_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_138_);
v___x_142_ = lean_float_to_float32(v___x_141_);
v___x_143_ = lean_float32_div(v___x_140_, v___x_142_);
v___x_144_ = lean_float32_to_float(v___x_143_);
return v___x_144_;
}
else
{
lean_object* v_a_145_; lean_object* v_b_146_; double v___x_147_; double v___x_148_; double v___x_149_; 
v_a_145_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_145_);
v_b_146_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_146_);
lean_dec_ref_known(v_x_87_, 2);
v___x_147_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_145_);
v___x_148_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_146_);
v___x_149_ = lean_float_div(v___x_147_, v___x_148_);
return v___x_149_;
}
}
case 5:
{
lean_object* v_a_150_; double v___x_151_; double v___x_152_; 
v_a_150_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_150_);
lean_dec_ref_known(v_x_87_, 1);
v___x_151_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_150_);
v___x_152_ = fabs(v___x_151_);
return v___x_152_;
}
case 6:
{
lean_object* v_a_153_; lean_object* v_b_154_; double v___x_155_; double v___x_156_; double v___x_157_; 
v_a_153_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_153_);
v_b_154_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_b_154_);
lean_dec_ref_known(v_x_87_, 2);
v___x_155_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_153_);
v___x_156_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_b_154_);
v___x_157_ = lp_lean1090_Lean1090_Impl_Libm_hypot(v___x_155_, v___x_156_);
return v___x_157_;
}
case 7:
{
lean_object* v_y_158_; lean_object* v_x_159_; double v___x_160_; double v___x_161_; double v___x_162_; 
v_y_158_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_y_158_);
v_x_159_ = lean_ctor_get(v_x_87_, 1);
lean_inc_ref(v_x_159_);
lean_dec_ref_known(v_x_87_, 2);
v___x_160_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_y_158_);
v___x_161_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_x_159_);
v___x_162_ = lp_lean1090_Lean1090_Impl_Libm_atan2(v___x_160_, v___x_161_);
return v___x_162_;
}
default: 
{
lean_object* v_a_163_; double v_value_164_; double v___x_165_; uint8_t v___x_166_; 
v_a_163_ = lean_ctor_get(v_x_87_, 0);
lean_inc_ref(v_a_163_);
lean_dec_ref_known(v_x_87_, 1);
v_value_164_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_a_163_);
v___x_165_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Numeric_eval___closed__0, &lp_lean1090_Lean1090_Impl_Numeric_eval___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Numeric_eval___closed__0);
v___x_166_ = lean_float_decLt(v_value_164_, v___x_165_);
if (v___x_166_ == 0)
{
return v_value_164_;
}
else
{
double v___x_167_; double v___x_168_; 
v___x_167_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Numeric_eval___closed__1, &lp_lean1090_Lean1090_Impl_Numeric_eval___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Numeric_eval___closed__1);
v___x_168_ = lean_float_add(v_value_164_, v___x_167_);
return v___x_168_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Numeric_eval___boxed(lean_object* v_x_169_){
_start:
{
double v_res_170_; lean_object* v_r_171_; 
v_res_170_ = lp_lean1090_Lean1090_Impl_Numeric_eval(v_x_169_);
v_r_171_ = lean_box_float(v_res_170_);
return v_r_171_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_CPRFloat(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Libm(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Numeric(uint8_t builtin) {
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
res = initialize_lean1090_Impl_CPRFloat(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_Libm(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
