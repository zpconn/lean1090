// Lean compiler output
// Module: Impl.Libm
// Imports: public import Init public meta import Init public import Init
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
double lean_float_of_bits(uint64_t);
double lean_float_of_nat(lean_object*);
double lean_float_negate(double);
double lean_float_mul(double, double);
double lean_float_div(double, double);
uint32_t lean_uint32_land(uint32_t, uint32_t);
uint8_t lean_uint32_dec_eq(uint32_t, uint32_t);
double lean_float_sub(double, double);
double fabs(double);
double lean_float_add(double, double);
uint64_t lean_float_to_bits(double);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint32_t lean_uint64_to_uint32(uint64_t);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
uint8_t lean_uint32_dec_lt(uint32_t, uint32_t);
double l_Float_ofScientific(lean_object*, uint8_t, lean_object*);
uint8_t lean_float_isnan(double);
uint8_t lean_uint64_dec_eq(uint64_t, uint64_t);
uint32_t lean_uint32_sub(uint32_t, uint32_t);
uint32_t lean_uint32_lor(uint32_t, uint32_t);
uint32_t lean_uint32_shift_right(uint32_t, uint32_t);
uint32_t lean_uint32_add(uint32_t, uint32_t);
double sqrt(double);
uint64_t lean_uint64_sub(uint64_t, uint64_t);
uint8_t lean_uint64_dec_lt(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
static lean_once_cell_t lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__0;
static lean_once_cell_t lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1;
LEAN_EXPORT lean_object* lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts(double);
LEAN_EXPORT lean_object* lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Libm_hypot(double, double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_hypot___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__7;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__8;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__9;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__10;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__11;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__12;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__13;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__14;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__15;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__16;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__17;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__18;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__19;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__20;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__21;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__22_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__22;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__23;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__24_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__24;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__25_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__25;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__1;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__26_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__26;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__27_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___closed__27;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__28_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__28;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__29_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__29;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan___closed__30_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan___closed__30;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Libm_atan(double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___boxed(lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__2;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__4;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__6;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__7;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__9;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__10;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__11;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__12;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__13;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__14;
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Libm_atan2___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_lean1090_Lean1090_Impl_Libm_atan2___closed__15;
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Libm_atan2(double, double);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan2___boxed(lean_object*, lean_object*);
static double _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__0(void){
_start:
{
lean_object* v___x_1_; double v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(134217729u);
v___x_2_ = lean_float_of_nat(v___x_1_);
return v___x_2_;
}
}
static double _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1(void){
_start:
{
lean_object* v___x_3_; double v___x_4_; 
v___x_3_ = lean_unsigned_to_nat(2u);
v___x_4_ = lean_float_of_nat(v___x_3_);
return v___x_4_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts(double v_x_5_){
_start:
{
double v___x_6_; double v_xc_7_; double v___x_8_; double v_xh_9_; double v_xl_10_; double v_hi_11_; double v___x_12_; double v___x_13_; double v___x_14_; double v___x_15_; double v___x_16_; double v___x_17_; double v___x_18_; double v_lo_19_; lean_object* v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; 
v___x_6_ = lean_float_once(&lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__0, &lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__0_once, _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__0);
v_xc_7_ = lean_float_mul(v_x_5_, v___x_6_);
v___x_8_ = lean_float_sub(v_x_5_, v_xc_7_);
v_xh_9_ = lean_float_add(v___x_8_, v_xc_7_);
v_xl_10_ = lean_float_sub(v_x_5_, v_xh_9_);
v_hi_11_ = lean_float_mul(v_x_5_, v_x_5_);
v___x_12_ = lean_float_mul(v_xh_9_, v_xh_9_);
v___x_13_ = lean_float_sub(v___x_12_, v_hi_11_);
v___x_14_ = lean_float_once(&lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1, &lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1_once, _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1);
v___x_15_ = lean_float_mul(v___x_14_, v_xh_9_);
v___x_16_ = lean_float_mul(v___x_15_, v_xl_10_);
v___x_17_ = lean_float_add(v___x_13_, v___x_16_);
v___x_18_ = lean_float_mul(v_xl_10_, v_xl_10_);
v_lo_19_ = lean_float_add(v___x_17_, v___x_18_);
v___x_20_ = lean_box_float(v_hi_11_);
v___x_21_ = lean_box_float(v_lo_19_);
v___x_22_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_22_, 0, v___x_20_);
lean_ctor_set(v___x_22_, 1, v___x_21_);
return v___x_22_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___boxed(lean_object* v_x_23_){
_start:
{
double v_x_boxed_24_; lean_object* v_res_25_; 
v_x_boxed_24_ = lean_unbox_float(v_x_23_);
lean_dec_ref(v_x_23_);
v_res_25_ = lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts(v_x_boxed_24_);
return v_res_25_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0(void){
_start:
{
lean_object* v___x_26_; double v___x_27_; 
v___x_26_ = lean_unsigned_to_nat(1u);
v___x_27_ = lean_float_of_nat(v___x_26_);
return v___x_27_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1(void){
_start:
{
uint64_t v___x_28_; double v___x_29_; 
v___x_28_ = 7759702157959364608ULL;
v___x_29_ = lean_float_of_bits(v___x_28_);
return v___x_29_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2(void){
_start:
{
uint64_t v___x_30_; double v___x_31_; 
v___x_30_ = 1454662679640670208ULL;
v___x_31_ = lean_float_of_bits(v___x_30_);
return v___x_31_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Libm_hypot(double v_x_32_, double v_y_33_){
_start:
{
double v_fst_35_; double v_fst_36_; double v_snd_37_; uint64_t v_fst_54_; uint64_t v_snd_55_; uint64_t v___x_83_; uint64_t v___x_84_; uint64_t v_ux_85_; uint64_t v___x_86_; uint64_t v_uy_87_; uint8_t v___x_88_; 
v___x_83_ = lean_float_to_bits(v_x_32_);
v___x_84_ = 9223372036854775807ULL;
v_ux_85_ = lean_uint64_land(v___x_83_, v___x_84_);
v___x_86_ = lean_float_to_bits(v_y_33_);
v_uy_87_ = lean_uint64_land(v___x_86_, v___x_84_);
v___x_88_ = lean_uint64_dec_lt(v_ux_85_, v_uy_87_);
if (v___x_88_ == 0)
{
v_fst_54_ = v_ux_85_;
v_snd_55_ = v_uy_87_;
goto v___jp_53_;
}
else
{
v_fst_54_ = v_uy_87_;
v_snd_55_ = v_ux_85_;
goto v___jp_53_;
}
v___jp_34_:
{
lean_object* v___x_38_; lean_object* v_fst_39_; lean_object* v_snd_40_; lean_object* v___x_41_; lean_object* v_fst_42_; lean_object* v_snd_43_; double v___x_44_; double v___x_45_; double v___x_46_; double v___x_47_; double v___x_48_; double v___x_49_; double v___x_50_; double v___x_51_; double v___x_52_; 
v___x_38_ = lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts(v_fst_35_);
v_fst_39_ = lean_ctor_get(v___x_38_, 0);
lean_inc(v_fst_39_);
v_snd_40_ = lean_ctor_get(v___x_38_, 1);
lean_inc(v_snd_40_);
lean_dec_ref(v___x_38_);
v___x_41_ = lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts(v_fst_36_);
v_fst_42_ = lean_ctor_get(v___x_41_, 0);
lean_inc(v_fst_42_);
v_snd_43_ = lean_ctor_get(v___x_41_, 1);
lean_inc(v_snd_43_);
lean_dec_ref(v___x_41_);
v___x_44_ = lean_unbox_float(v_snd_43_);
lean_dec(v_snd_43_);
v___x_45_ = lean_unbox_float(v_snd_40_);
lean_dec(v_snd_40_);
v___x_46_ = lean_float_add(v___x_44_, v___x_45_);
v___x_47_ = lean_unbox_float(v_fst_42_);
lean_dec(v_fst_42_);
v___x_48_ = lean_float_add(v___x_46_, v___x_47_);
v___x_49_ = lean_unbox_float(v_fst_39_);
lean_dec(v_fst_39_);
v___x_50_ = lean_float_add(v___x_48_, v___x_49_);
v___x_51_ = sqrt(v___x_50_);
v___x_52_ = lean_float_mul(v_snd_37_, v___x_51_);
return v___x_52_;
}
v___jp_53_:
{
uint64_t v___x_56_; uint64_t v_ex_57_; uint64_t v_ey_58_; double v_y_59_; uint64_t v___x_60_; uint8_t v___x_61_; 
v___x_56_ = 52ULL;
v_ex_57_ = lean_uint64_shift_right(v_fst_54_, v___x_56_);
v_ey_58_ = lean_uint64_shift_right(v_snd_55_, v___x_56_);
v_y_59_ = lean_float_of_bits(v_snd_55_);
v___x_60_ = 2047ULL;
v___x_61_ = lean_uint64_dec_eq(v_ey_58_, v___x_60_);
if (v___x_61_ == 0)
{
double v_x_62_; uint8_t v___x_63_; 
v_x_62_ = lean_float_of_bits(v_fst_54_);
v___x_63_ = lean_uint64_dec_eq(v_ex_57_, v___x_60_);
if (v___x_63_ == 0)
{
uint64_t v___x_64_; uint8_t v___x_65_; 
v___x_64_ = 0ULL;
v___x_65_ = lean_uint64_dec_eq(v_snd_55_, v___x_64_);
if (v___x_65_ == 0)
{
uint64_t v___x_66_; uint64_t v___x_67_; uint8_t v___x_68_; 
v___x_66_ = 64ULL;
v___x_67_ = lean_uint64_sub(v_ex_57_, v_ey_58_);
v___x_68_ = lean_uint64_dec_lt(v___x_66_, v___x_67_);
if (v___x_68_ == 0)
{
uint64_t v___x_69_; uint8_t v___x_70_; 
v___x_69_ = 1533ULL;
v___x_70_ = lean_uint64_dec_lt(v___x_69_, v_ex_57_);
if (v___x_70_ == 0)
{
uint64_t v___x_71_; uint8_t v___x_72_; 
v___x_71_ = 573ULL;
v___x_72_ = lean_uint64_dec_lt(v_ey_58_, v___x_71_);
if (v___x_72_ == 0)
{
double v___x_73_; 
v___x_73_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0);
v_fst_35_ = v_x_62_;
v_fst_36_ = v_y_59_;
v_snd_37_ = v___x_73_;
goto v___jp_34_;
}
else
{
double v___x_74_; double v___x_75_; double v___x_76_; double v___x_77_; 
v___x_74_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1);
v___x_75_ = lean_float_mul(v_x_62_, v___x_74_);
v___x_76_ = lean_float_mul(v_y_59_, v___x_74_);
v___x_77_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2);
v_fst_35_ = v___x_75_;
v_fst_36_ = v___x_76_;
v_snd_37_ = v___x_77_;
goto v___jp_34_;
}
}
else
{
double v___x_78_; double v___x_79_; double v___x_80_; double v___x_81_; 
v___x_78_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__2);
v___x_79_ = lean_float_mul(v_x_62_, v___x_78_);
v___x_80_ = lean_float_mul(v_y_59_, v___x_78_);
v___x_81_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__1);
v_fst_35_ = v___x_79_;
v_fst_36_ = v___x_80_;
v_snd_37_ = v___x_81_;
goto v___jp_34_;
}
}
else
{
double v___x_82_; 
v___x_82_ = lean_float_add(v_x_62_, v_y_59_);
return v___x_82_;
}
}
else
{
return v_x_62_;
}
}
else
{
return v_x_62_;
}
}
else
{
return v_y_59_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_hypot___boxed(lean_object* v_x_89_, lean_object* v_y_90_){
_start:
{
double v_x_boxed_91_; double v_y_boxed_92_; double v_res_93_; lean_object* v_r_94_; 
v_x_boxed_91_ = lean_unbox_float(v_x_89_);
lean_dec_ref(v_x_89_);
v_y_boxed_92_ = lean_unbox_float(v_y_90_);
lean_dec_ref(v_y_90_);
v_res_93_ = lp_lean1090_Lean1090_Impl_Libm_hypot(v_x_boxed_91_, v_y_boxed_92_);
v_r_94_ = lean_box_float(v_res_93_);
return v_r_94_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__0(void){
_start:
{
uint64_t v___x_95_; double v___x_96_; 
v___x_95_ = 4599676419421066509ULL;
v___x_96_ = lean_float_of_bits(v___x_95_);
return v___x_96_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__1(void){
_start:
{
uint64_t v___x_97_; double v___x_98_; 
v___x_97_ = 4594314991288484863ULL;
v___x_98_ = lean_float_of_bits(v___x_97_);
return v___x_98_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__2(void){
_start:
{
uint64_t v___x_99_; double v___x_100_; 
v___x_99_ = 4591215095208222830ULL;
v___x_100_ = lean_float_of_bits(v___x_99_);
return v___x_100_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__3(void){
_start:
{
uint64_t v___x_101_; double v___x_102_; 
v___x_101_ = 4589464229703073105ULL;
v___x_102_ = lean_float_of_bits(v___x_101_);
return v___x_102_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__4(void){
_start:
{
uint64_t v___x_103_; double v___x_104_; 
v___x_103_ = 4587333258118041067ULL;
v___x_104_ = lean_float_of_bits(v___x_103_);
return v___x_104_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__5(void){
_start:
{
uint64_t v___x_105_; double v___x_106_; 
v___x_105_ = 4580351289466214929ULL;
v___x_106_ = lean_float_of_bits(v___x_105_);
return v___x_106_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__6(void){
_start:
{
uint64_t v___x_107_; double v___x_108_; 
v___x_107_ = 13819745816549059524ULL;
v___x_108_ = lean_float_of_bits(v___x_107_);
return v___x_108_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__7(void){
_start:
{
uint64_t v___x_109_; double v___x_110_; 
v___x_109_ = 13816042856347014769ULL;
v___x_110_ = lean_float_of_bits(v___x_109_);
return v___x_110_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__8(void){
_start:
{
uint64_t v___x_111_; double v___x_112_; 
v___x_111_ = 13813579038447671917ULL;
v___x_112_ = lean_float_of_bits(v___x_111_);
return v___x_112_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__9(void){
_start:
{
uint64_t v___x_113_; double v___x_114_; 
v___x_113_ = 13811939918460419482ULL;
v___x_114_ = lean_float_of_bits(v___x_113_);
return v___x_114_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__10(void){
_start:
{
uint64_t v___x_115_; double v___x_116_; 
v___x_115_ = 13808797612367309871ULL;
v___x_116_ = lean_float_of_bits(v___x_115_);
return v___x_116_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__11(void){
_start:
{
double v___x_117_; double v___x_118_; 
v___x_117_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0);
v___x_118_ = lean_float_negate(v___x_117_);
return v___x_118_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__12(void){
_start:
{
uint64_t v___x_119_; double v___x_120_; 
v___x_119_ = 4609753056924675352ULL;
v___x_120_ = lean_float_of_bits(v___x_119_);
return v___x_120_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__13(void){
_start:
{
uint64_t v___x_121_; double v___x_122_; 
v___x_121_ = 4364452196894661639ULL;
v___x_122_ = lean_float_of_bits(v___x_121_);
return v___x_122_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__1(void){
_start:
{
double v___x_123_; lean_object* v___x_124_; 
v___x_123_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__12, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__12_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__12);
v___x_124_ = lean_box_float(v___x_123_);
return v___x_124_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__2(void){
_start:
{
double v___x_125_; lean_object* v___x_126_; 
v___x_125_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__13, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__13_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__13);
v___x_126_ = lean_box_float(v___x_125_);
return v___x_126_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__14(void){
_start:
{
lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; 
v___x_127_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__1;
v___x_128_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__2;
v___x_129_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_129_, 0, v___x_127_);
lean_ctor_set(v___x_129_, 1, v___x_128_);
return v___x_129_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__15(void){
_start:
{
lean_object* v___x_130_; lean_object* v___x_131_; 
v___x_130_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__14, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__14_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__14);
v___x_131_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_131_, 0, v___x_130_);
return v___x_131_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__16(void){
_start:
{
uint64_t v___x_132_; double v___x_133_; 
v___x_132_ = 4607027438436873883ULL;
v___x_133_ = lean_float_of_bits(v___x_132_);
return v___x_133_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__17(void){
_start:
{
uint64_t v___x_134_; double v___x_135_; 
v___x_134_ = 4354989122426817469ULL;
v___x_135_ = lean_float_of_bits(v___x_134_);
return v___x_135_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__1(void){
_start:
{
double v___x_136_; lean_object* v___x_137_; 
v___x_136_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__16, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__16_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__16);
v___x_137_ = lean_box_float(v___x_136_);
return v___x_137_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__2(void){
_start:
{
double v___x_138_; lean_object* v___x_139_; 
v___x_138_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__17, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__17_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__17);
v___x_139_ = lean_box_float(v___x_138_);
return v___x_139_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__18(void){
_start:
{
lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v___x_142_; 
v___x_140_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__1;
v___x_141_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__2;
v___x_142_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_142_, 0, v___x_140_);
lean_ctor_set(v___x_142_, 1, v___x_141_);
return v___x_142_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__19(void){
_start:
{
lean_object* v___x_143_; lean_object* v___x_144_; 
v___x_143_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__18, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__18_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__18);
v___x_144_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_144_, 0, v___x_143_);
return v___x_144_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__20(void){
_start:
{
uint64_t v___x_145_; double v___x_146_; 
v___x_145_ = 4605249457297304856ULL;
v___x_146_ = lean_float_of_bits(v___x_145_);
return v___x_146_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__21(void){
_start:
{
uint64_t v___x_147_; double v___x_148_; 
v___x_147_ = 4359948597267291143ULL;
v___x_148_ = lean_float_of_bits(v___x_147_);
return v___x_148_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__1(void){
_start:
{
double v___x_149_; lean_object* v___x_150_; 
v___x_149_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__20, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__20_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__20);
v___x_150_ = lean_box_float(v___x_149_);
return v___x_150_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__2(void){
_start:
{
double v___x_151_; lean_object* v___x_152_; 
v___x_151_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__21, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__21_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__21);
v___x_152_ = lean_box_float(v___x_151_);
return v___x_152_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__22(void){
_start:
{
lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; 
v___x_153_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__1;
v___x_154_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__2;
v___x_155_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_155_, 0, v___x_153_);
lean_ctor_set(v___x_155_, 1, v___x_154_);
return v___x_155_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__23(void){
_start:
{
lean_object* v___x_156_; lean_object* v___x_157_; 
v___x_156_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__22, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__22_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__22);
v___x_157_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_157_, 0, v___x_156_);
return v___x_157_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__24(void){
_start:
{
uint64_t v___x_158_; double v___x_159_; 
v___x_158_ = 4602023952714414927ULL;
v___x_159_ = lean_float_of_bits(v___x_158_);
return v___x_159_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__25(void){
_start:
{
uint64_t v___x_160_; double v___x_161_; 
v___x_160_ = 4357843414468748770ULL;
v___x_161_ = lean_float_of_bits(v___x_160_);
return v___x_161_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__1(void){
_start:
{
double v___x_162_; lean_object* v___x_163_; 
v___x_162_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__24, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__24_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__24);
v___x_163_ = lean_box_float(v___x_162_);
return v___x_163_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__2(void){
_start:
{
double v___x_164_; lean_object* v___x_165_; 
v___x_164_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__25, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__25_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__25);
v___x_165_ = lean_box_float(v___x_164_);
return v___x_165_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__26(void){
_start:
{
lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; 
v___x_166_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__1;
v___x_167_ = lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__2;
v___x_168_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_168_, 0, v___x_166_);
lean_ctor_set(v___x_168_, 1, v___x_167_);
return v___x_168_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__27(void){
_start:
{
lean_object* v___x_169_; lean_object* v___x_170_; 
v___x_169_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__26, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__26_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__26);
v___x_170_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_170_, 0, v___x_169_);
return v___x_170_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__28(void){
_start:
{
uint64_t v___x_171_; double v___x_172_; 
v___x_171_ = 58720256ULL;
v___x_172_ = lean_float_of_bits(v___x_171_);
return v___x_172_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__29(void){
_start:
{
double v___x_173_; double v___x_174_; double v_z_175_; 
v___x_173_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__28, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__28_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__28);
v___x_174_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__12, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__12_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__12);
v_z_175_ = lean_float_add(v___x_174_, v___x_173_);
return v_z_175_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__30(void){
_start:
{
double v_z_176_; double v___x_177_; 
v_z_176_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__29, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__29_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__29);
v___x_177_ = lean_float_negate(v_z_176_);
return v___x_177_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Libm_atan(double v_input_178_){
_start:
{
uint8_t v___y_180_; double v_fst_181_; lean_object* v_snd_182_; uint64_t v___x_230_; uint64_t v___x_231_; uint64_t v___x_232_; uint32_t v___x_233_; uint32_t v___x_234_; uint32_t v_ix_235_; uint8_t v___y_237_; uint64_t v___x_279_; uint64_t v___x_280_; uint64_t v___x_281_; uint8_t v___x_282_; 
v___x_230_ = lean_float_to_bits(v_input_178_);
v___x_231_ = 32ULL;
v___x_232_ = lean_uint64_shift_right(v___x_230_, v___x_231_);
v___x_233_ = lean_uint64_to_uint32(v___x_232_);
v___x_234_ = 2147483647;
v_ix_235_ = lean_uint32_land(v___x_233_, v___x_234_);
v___x_279_ = 63ULL;
v___x_280_ = lean_uint64_shift_right(v___x_230_, v___x_279_);
v___x_281_ = 0ULL;
v___x_282_ = lean_uint64_dec_eq(v___x_280_, v___x_281_);
if (v___x_282_ == 0)
{
uint8_t v___x_283_; 
v___x_283_ = 1;
v___y_237_ = v___x_283_;
goto v___jp_236_;
}
else
{
uint8_t v___x_284_; 
v___x_284_ = 0;
v___y_237_ = v___x_284_;
goto v___jp_236_;
}
v___jp_179_:
{
double v_z_183_; double v_w_184_; double v___x_185_; double v___x_186_; double v___x_187_; double v___x_188_; double v___x_189_; double v___x_190_; double v___x_191_; double v___x_192_; double v___x_193_; double v___x_194_; double v___x_195_; double v___x_196_; double v___x_197_; double v___x_198_; double v___x_199_; double v___x_200_; double v_s1_201_; double v___x_202_; double v___x_203_; double v___x_204_; double v___x_205_; double v___x_206_; double v___x_207_; double v___x_208_; double v___x_209_; double v___x_210_; double v___x_211_; double v___x_212_; double v___x_213_; double v___x_214_; double v_s2_215_; 
v_z_183_ = lean_float_mul(v_fst_181_, v_fst_181_);
v_w_184_ = lean_float_mul(v_z_183_, v_z_183_);
v___x_185_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__0);
v___x_186_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__1, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__1);
v___x_187_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__2, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__2);
v___x_188_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__3, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__3);
v___x_189_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__4, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__4_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__4);
v___x_190_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__5, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__5_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__5);
v___x_191_ = lean_float_mul(v_w_184_, v___x_190_);
v___x_192_ = lean_float_add(v___x_189_, v___x_191_);
v___x_193_ = lean_float_mul(v_w_184_, v___x_192_);
v___x_194_ = lean_float_add(v___x_188_, v___x_193_);
v___x_195_ = lean_float_mul(v_w_184_, v___x_194_);
v___x_196_ = lean_float_add(v___x_187_, v___x_195_);
v___x_197_ = lean_float_mul(v_w_184_, v___x_196_);
v___x_198_ = lean_float_add(v___x_186_, v___x_197_);
v___x_199_ = lean_float_mul(v_w_184_, v___x_198_);
v___x_200_ = lean_float_add(v___x_185_, v___x_199_);
v_s1_201_ = lean_float_mul(v_z_183_, v___x_200_);
v___x_202_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__6, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__6_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__6);
v___x_203_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__7, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__7_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__7);
v___x_204_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__8, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__8_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__8);
v___x_205_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__9, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__9_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__9);
v___x_206_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__10, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__10_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__10);
v___x_207_ = lean_float_mul(v_w_184_, v___x_206_);
v___x_208_ = lean_float_add(v___x_205_, v___x_207_);
v___x_209_ = lean_float_mul(v_w_184_, v___x_208_);
v___x_210_ = lean_float_add(v___x_204_, v___x_209_);
v___x_211_ = lean_float_mul(v_w_184_, v___x_210_);
v___x_212_ = lean_float_add(v___x_203_, v___x_211_);
v___x_213_ = lean_float_mul(v_w_184_, v___x_212_);
v___x_214_ = lean_float_add(v___x_202_, v___x_213_);
v_s2_215_ = lean_float_mul(v_w_184_, v___x_214_);
if (lean_obj_tag(v_snd_182_) == 0)
{
double v___x_216_; double v___x_217_; double v___x_218_; 
v___x_216_ = lean_float_add(v_s1_201_, v_s2_215_);
v___x_217_ = lean_float_mul(v_fst_181_, v___x_216_);
v___x_218_ = lean_float_sub(v_fst_181_, v___x_217_);
return v___x_218_;
}
else
{
lean_object* v_val_219_; lean_object* v_fst_220_; lean_object* v_snd_221_; double v___x_222_; double v___x_223_; double v___x_224_; double v___x_225_; double v___x_226_; double v___x_227_; double v_result_228_; 
v_val_219_ = lean_ctor_get(v_snd_182_, 0);
v_fst_220_ = lean_ctor_get(v_val_219_, 0);
v_snd_221_ = lean_ctor_get(v_val_219_, 1);
v___x_222_ = lean_float_add(v_s1_201_, v_s2_215_);
v___x_223_ = lean_float_mul(v_fst_181_, v___x_222_);
v___x_224_ = lean_unbox_float(v_snd_221_);
v___x_225_ = lean_float_sub(v___x_223_, v___x_224_);
v___x_226_ = lean_float_sub(v___x_225_, v_fst_181_);
v___x_227_ = lean_unbox_float(v_fst_220_);
v_result_228_ = lean_float_sub(v___x_227_, v___x_226_);
if (v___y_180_ == 0)
{
return v_result_228_;
}
else
{
double v___x_229_; 
v___x_229_ = lean_float_negate(v_result_228_);
return v___x_229_;
}
}
}
v___jp_236_:
{
uint32_t v___x_238_; uint8_t v___x_239_; 
v___x_238_ = 1141899264;
v___x_239_ = lean_uint32_dec_le(v___x_238_, v_ix_235_);
if (v___x_239_ == 0)
{
uint32_t v___x_240_; uint8_t v___x_241_; 
v___x_240_ = 1044381696;
v___x_241_ = lean_uint32_dec_lt(v_ix_235_, v___x_240_);
if (v___x_241_ == 0)
{
uint32_t v___x_242_; uint8_t v___x_243_; 
v___x_242_ = 1071382528;
v___x_243_ = lean_uint32_dec_lt(v_ix_235_, v___x_242_);
if (v___x_243_ == 0)
{
double v_x_244_; uint32_t v___x_245_; uint8_t v___x_246_; 
v_x_244_ = fabs(v_input_178_);
v___x_245_ = 1072889856;
v___x_246_ = lean_uint32_dec_lt(v_ix_235_, v___x_245_);
if (v___x_246_ == 0)
{
uint32_t v___x_247_; uint8_t v___x_248_; 
v___x_247_ = 1073971200;
v___x_248_ = lean_uint32_dec_lt(v_ix_235_, v___x_247_);
if (v___x_248_ == 0)
{
double v___x_249_; double v___x_250_; lean_object* v___x_251_; 
v___x_249_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__11, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__11_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__11);
v___x_250_ = lean_float_div(v___x_249_, v_x_244_);
v___x_251_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__15, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__15_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__15);
v___y_180_ = v___y_237_;
v_fst_181_ = v___x_250_;
v_snd_182_ = v___x_251_;
goto v___jp_179_;
}
else
{
lean_object* v___x_252_; lean_object* v___x_253_; double v___x_254_; double v___x_255_; double v___x_256_; double v___x_257_; double v___x_258_; double v___x_259_; lean_object* v___x_260_; 
v___x_252_ = lean_unsigned_to_nat(15u);
v___x_253_ = lean_unsigned_to_nat(1u);
v___x_254_ = l_Float_ofScientific(v___x_252_, v___x_248_, v___x_253_);
v___x_255_ = lean_float_sub(v_x_244_, v___x_254_);
v___x_256_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0);
v___x_257_ = lean_float_mul(v___x_254_, v_x_244_);
v___x_258_ = lean_float_add(v___x_256_, v___x_257_);
v___x_259_ = lean_float_div(v___x_255_, v___x_258_);
v___x_260_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__19, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__19_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__19);
v___y_180_ = v___y_237_;
v_fst_181_ = v___x_259_;
v_snd_182_ = v___x_260_;
goto v___jp_179_;
}
}
else
{
uint32_t v___x_261_; uint8_t v___x_262_; 
v___x_261_ = 1072037888;
v___x_262_ = lean_uint32_dec_lt(v_ix_235_, v___x_261_);
if (v___x_262_ == 0)
{
double v___x_263_; double v___x_264_; double v___x_265_; double v___x_266_; lean_object* v___x_267_; 
v___x_263_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0);
v___x_264_ = lean_float_sub(v_x_244_, v___x_263_);
v___x_265_ = lean_float_add(v_x_244_, v___x_263_);
v___x_266_ = lean_float_div(v___x_264_, v___x_265_);
v___x_267_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__23, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__23_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__23);
v___y_180_ = v___y_237_;
v_fst_181_ = v___x_266_;
v_snd_182_ = v___x_267_;
goto v___jp_179_;
}
else
{
double v___x_268_; double v___x_269_; double v___x_270_; double v___x_271_; double v___x_272_; double v___x_273_; lean_object* v___x_274_; 
v___x_268_ = lean_float_once(&lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1, &lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1_once, _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1);
v___x_269_ = lean_float_mul(v___x_268_, v_x_244_);
v___x_270_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0, &lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_hypot___closed__0);
v___x_271_ = lean_float_sub(v___x_269_, v___x_270_);
v___x_272_ = lean_float_add(v___x_268_, v_x_244_);
v___x_273_ = lean_float_div(v___x_271_, v___x_272_);
v___x_274_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__27, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__27_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__27);
v___y_180_ = v___y_237_;
v_fst_181_ = v___x_273_;
v_snd_182_ = v___x_274_;
goto v___jp_179_;
}
}
}
else
{
lean_object* v___x_275_; 
v___x_275_ = lean_box(0);
v___y_180_ = v___y_237_;
v_fst_181_ = v_input_178_;
v_snd_182_ = v___x_275_;
goto v___jp_179_;
}
}
else
{
return v_input_178_;
}
}
else
{
uint8_t v___x_276_; 
v___x_276_ = lean_float_isnan(v_input_178_);
if (v___x_276_ == 0)
{
double v_z_277_; 
v_z_277_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__29, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__29_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__29);
if (v___y_237_ == 0)
{
return v_z_277_;
}
else
{
double v___x_278_; 
v___x_278_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan___closed__30, &lp_lean1090_Lean1090_Impl_Libm_atan___closed__30_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__30);
return v___x_278_;
}
}
else
{
return v_input_178_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan___boxed(lean_object* v_input_285_){
_start:
{
double v_input_boxed_286_; double v_res_287_; lean_object* v_r_288_; 
v_input_boxed_286_ = lean_unbox_float(v_input_285_);
lean_dec_ref(v_input_285_);
v_res_287_ = lp_lean1090_Lean1090_Impl_Libm_atan(v_input_boxed_286_);
v_r_288_ = lean_box_float(v_res_287_);
return v_r_288_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0(void){
_start:
{
uint64_t v___x_289_; double v_pi_290_; 
v___x_289_ = 4614256656552045848ULL;
v_pi_290_ = lean_float_of_bits(v___x_289_);
return v_pi_290_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1(void){
_start:
{
double v_pi_291_; double v___x_292_; 
v_pi_291_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0);
v___x_292_ = lean_float_negate(v_pi_291_);
return v___x_292_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__2(void){
_start:
{
uint64_t v___x_293_; double v_piLow_294_; 
v___x_293_ = 4368955796522032135ULL;
v_piLow_294_ = lean_float_of_bits(v___x_293_);
return v_piLow_294_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3(void){
_start:
{
lean_object* v___x_295_; double v___x_296_; 
v___x_295_ = lean_unsigned_to_nat(0u);
v___x_296_ = lean_float_of_nat(v___x_295_);
return v___x_296_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__4(void){
_start:
{
uint64_t v___x_297_; double v___x_298_; 
v___x_297_ = 9223372036854775808ULL;
v___x_298_ = lean_float_of_bits(v___x_297_);
return v___x_298_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5(void){
_start:
{
lean_object* v___x_299_; double v___x_300_; 
v___x_299_ = lean_unsigned_to_nat(3u);
v___x_300_ = lean_float_of_nat(v___x_299_);
return v___x_300_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__6(void){
_start:
{
double v___x_301_; double v___x_302_; 
v___x_301_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5);
v___x_302_ = lean_float_negate(v___x_301_);
return v___x_302_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__7(void){
_start:
{
double v_pi_303_; double v___x_304_; double v___x_305_; 
v_pi_303_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0);
v___x_304_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__6, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__6_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__6);
v___x_305_ = lean_float_mul(v___x_304_, v_pi_303_);
return v___x_305_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8(void){
_start:
{
lean_object* v___x_306_; double v___x_307_; 
v___x_306_ = lean_unsigned_to_nat(4u);
v___x_307_ = lean_float_of_nat(v___x_306_);
return v___x_307_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__9(void){
_start:
{
double v___x_308_; double v___x_309_; double v___x_310_; 
v___x_308_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8);
v___x_309_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__7, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__7_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__7);
v___x_310_ = lean_float_div(v___x_309_, v___x_308_);
return v___x_310_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__10(void){
_start:
{
double v_pi_311_; double v___x_312_; double v___x_313_; 
v_pi_311_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0);
v___x_312_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__5);
v___x_313_ = lean_float_mul(v___x_312_, v_pi_311_);
return v___x_313_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__11(void){
_start:
{
double v___x_314_; double v___x_315_; double v___x_316_; 
v___x_314_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8);
v___x_315_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__10, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__10_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__10);
v___x_316_ = lean_float_div(v___x_315_, v___x_314_);
return v___x_316_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__12(void){
_start:
{
double v___x_317_; double v___x_318_; double v___x_319_; 
v___x_317_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8);
v___x_318_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1);
v___x_319_ = lean_float_div(v___x_318_, v___x_317_);
return v___x_319_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__13(void){
_start:
{
double v___x_320_; double v_pi_321_; double v___x_322_; 
v___x_320_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__8);
v_pi_321_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0);
v___x_322_ = lean_float_div(v_pi_321_, v___x_320_);
return v___x_322_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__14(void){
_start:
{
double v___x_323_; double v___x_324_; double v___x_325_; 
v___x_323_ = lean_float_once(&lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1, &lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1_once, _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1);
v___x_324_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1);
v___x_325_ = lean_float_div(v___x_324_, v___x_323_);
return v___x_325_;
}
}
static double _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__15(void){
_start:
{
double v___x_326_; double v_pi_327_; double v___x_328_; 
v___x_326_ = lean_float_once(&lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1, &lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1_once, _init_lp_lean1090___private_Impl_Libm_0__Lean1090_Impl_Libm_squareParts___closed__1);
v_pi_327_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0);
v___x_328_ = lean_float_div(v_pi_327_, v___x_326_);
return v___x_328_;
}
}
LEAN_EXPORT double lp_lean1090_Lean1090_Impl_Libm_atan2(double v_y_329_, double v_x_330_){
_start:
{
double v_pi_331_; uint32_t v___y_333_; uint32_t v___y_334_; uint32_t v___y_335_; lean_object* v___y_336_; double v_piLow_344_; uint32_t v___y_346_; uint32_t v___y_347_; uint32_t v___y_348_; uint32_t v___y_349_; double v___y_350_; uint32_t v___y_360_; uint32_t v___y_361_; uint32_t v___y_362_; uint32_t v___y_363_; uint8_t v___y_368_; uint8_t v___x_434_; 
v_pi_331_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__0);
v_piLow_344_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__2, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__2_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__2);
v___x_434_ = lean_float_isnan(v_x_330_);
if (v___x_434_ == 0)
{
uint8_t v___x_435_; 
v___x_435_ = lean_float_isnan(v_y_329_);
v___y_368_ = v___x_435_;
goto v___jp_367_;
}
else
{
v___y_368_ = v___x_434_;
goto v___jp_367_;
}
v___jp_332_:
{
uint32_t v___x_337_; uint8_t v___x_338_; 
v___x_337_ = lean_uint32_land(v___y_333_, v___y_335_);
v___x_338_ = lean_uint32_dec_eq(v___x_337_, v___y_334_);
if (v___x_338_ == 0)
{
double v___x_339_; double v___x_340_; double v___x_341_; 
v___x_339_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1);
v___x_340_ = lean_float_of_nat(v___y_336_);
v___x_341_ = lean_float_div(v___x_339_, v___x_340_);
return v___x_341_;
}
else
{
double v___x_342_; double v___x_343_; 
v___x_342_ = lean_float_of_nat(v___y_336_);
v___x_343_ = lean_float_div(v_pi_331_, v___x_342_);
return v___x_343_;
}
}
v___jp_345_:
{
uint8_t v___x_351_; 
v___x_351_ = lean_uint32_dec_eq(v___y_346_, v___y_348_);
if (v___x_351_ == 0)
{
uint8_t v___x_352_; 
v___x_352_ = lean_uint32_dec_eq(v___y_346_, v___y_349_);
if (v___x_352_ == 0)
{
uint8_t v___x_353_; 
v___x_353_ = lean_uint32_dec_eq(v___y_346_, v___y_347_);
if (v___x_353_ == 0)
{
double v___x_354_; double v___x_355_; 
v___x_354_ = lean_float_sub(v___y_350_, v_piLow_344_);
v___x_355_ = lean_float_sub(v___x_354_, v_pi_331_);
return v___x_355_;
}
else
{
double v___x_356_; double v___x_357_; 
v___x_356_ = lean_float_sub(v___y_350_, v_piLow_344_);
v___x_357_ = lean_float_sub(v_pi_331_, v___x_356_);
return v___x_357_;
}
}
else
{
double v___x_358_; 
v___x_358_ = lean_float_negate(v___y_350_);
return v___x_358_;
}
}
else
{
return v___y_350_;
}
}
v___jp_359_:
{
double v___x_364_; double v___x_365_; double v___x_366_; 
v___x_364_ = lean_float_div(v_y_329_, v_x_330_);
v___x_365_ = fabs(v___x_364_);
v___x_366_ = lp_lean1090_Lean1090_Impl_Libm_atan(v___x_365_);
v___y_346_ = v___y_360_;
v___y_347_ = v___y_362_;
v___y_348_ = v___y_361_;
v___y_349_ = v___y_363_;
v___y_350_ = v___x_366_;
goto v___jp_345_;
}
v___jp_367_:
{
if (v___y_368_ == 0)
{
uint64_t v___x_369_; uint64_t v___x_370_; uint64_t v___x_371_; uint32_t v_ix_372_; uint32_t v_lx_373_; uint32_t v___x_374_; uint32_t v___x_375_; uint32_t v___x_376_; uint32_t v___x_377_; uint8_t v___x_378_; 
v___x_369_ = lean_float_to_bits(v_x_330_);
v___x_370_ = 32ULL;
v___x_371_ = lean_uint64_shift_right(v___x_369_, v___x_370_);
v_ix_372_ = lean_uint64_to_uint32(v___x_371_);
v_lx_373_ = lean_uint64_to_uint32(v___x_369_);
v___x_374_ = 1072693248;
v___x_375_ = lean_uint32_sub(v_ix_372_, v___x_374_);
v___x_376_ = lean_uint32_lor(v___x_375_, v_lx_373_);
v___x_377_ = 0;
v___x_378_ = lean_uint32_dec_eq(v___x_376_, v___x_377_);
if (v___x_378_ == 0)
{
uint64_t v___x_379_; uint64_t v___x_380_; uint32_t v_iy_381_; uint32_t v_ly_382_; uint32_t v___x_383_; uint32_t v___x_384_; uint32_t v___x_385_; uint32_t v___x_386_; uint32_t v___x_387_; uint32_t v___x_388_; uint32_t v___x_389_; uint32_t v___x_390_; uint32_t v_m_391_; uint32_t v___x_392_; uint32_t v_ix_393_; uint32_t v_iy_394_; uint32_t v___x_395_; uint8_t v___x_396_; 
v___x_379_ = lean_float_to_bits(v_y_329_);
v___x_380_ = lean_uint64_shift_right(v___x_379_, v___x_370_);
v_iy_381_ = lean_uint64_to_uint32(v___x_380_);
v_ly_382_ = lean_uint64_to_uint32(v___x_379_);
v___x_383_ = 31;
v___x_384_ = lean_uint32_shift_right(v_iy_381_, v___x_383_);
v___x_385_ = 1;
v___x_386_ = lean_uint32_land(v___x_384_, v___x_385_);
v___x_387_ = 30;
v___x_388_ = lean_uint32_shift_right(v_ix_372_, v___x_387_);
v___x_389_ = 2;
v___x_390_ = lean_uint32_land(v___x_388_, v___x_389_);
v_m_391_ = lean_uint32_lor(v___x_386_, v___x_390_);
v___x_392_ = 2147483647;
v_ix_393_ = lean_uint32_land(v_ix_372_, v___x_392_);
v_iy_394_ = lean_uint32_land(v_iy_381_, v___x_392_);
v___x_395_ = lean_uint32_lor(v_iy_394_, v_ly_382_);
v___x_396_ = lean_uint32_dec_eq(v___x_395_, v___x_377_);
if (v___x_396_ == 0)
{
lean_object* v___x_397_; uint32_t v___x_398_; uint8_t v___x_399_; 
v___x_397_ = lean_unsigned_to_nat(2u);
v___x_398_ = lean_uint32_lor(v_ix_393_, v_lx_373_);
v___x_399_ = lean_uint32_dec_eq(v___x_398_, v___x_377_);
if (v___x_399_ == 0)
{
uint32_t v___x_400_; uint8_t v___x_401_; 
v___x_400_ = 2146435072;
v___x_401_ = lean_uint32_dec_eq(v_ix_393_, v___x_400_);
if (v___x_401_ == 0)
{
uint32_t v___x_402_; uint32_t v___x_403_; uint8_t v___x_404_; 
v___x_402_ = 67108864;
v___x_403_ = lean_uint32_add(v_ix_393_, v___x_402_);
v___x_404_ = lean_uint32_dec_lt(v___x_403_, v_iy_394_);
if (v___x_404_ == 0)
{
uint8_t v___x_405_; 
v___x_405_ = lean_uint32_dec_eq(v_iy_394_, v___x_400_);
if (v___x_405_ == 0)
{
uint32_t v___x_406_; uint8_t v___x_407_; 
v___x_406_ = lean_uint32_land(v_m_391_, v___x_389_);
v___x_407_ = lean_uint32_dec_eq(v___x_406_, v___x_377_);
if (v___x_407_ == 0)
{
uint32_t v___x_408_; uint8_t v___x_409_; 
v___x_408_ = lean_uint32_add(v_iy_394_, v___x_402_);
v___x_409_ = lean_uint32_dec_lt(v___x_408_, v_ix_393_);
if (v___x_409_ == 0)
{
v___y_360_ = v_m_391_;
v___y_361_ = v___x_377_;
v___y_362_ = v___x_389_;
v___y_363_ = v___x_385_;
goto v___jp_359_;
}
else
{
double v___x_410_; 
v___x_410_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3);
v___y_346_ = v_m_391_;
v___y_347_ = v___x_389_;
v___y_348_ = v___x_377_;
v___y_349_ = v___x_385_;
v___y_350_ = v___x_410_;
goto v___jp_345_;
}
}
else
{
v___y_360_ = v_m_391_;
v___y_361_ = v___x_377_;
v___y_362_ = v___x_389_;
v___y_363_ = v___x_385_;
goto v___jp_359_;
}
}
else
{
v___y_333_ = v_m_391_;
v___y_334_ = v___x_377_;
v___y_335_ = v___x_385_;
v___y_336_ = v___x_397_;
goto v___jp_332_;
}
}
else
{
v___y_333_ = v_m_391_;
v___y_334_ = v___x_377_;
v___y_335_ = v___x_385_;
v___y_336_ = v___x_397_;
goto v___jp_332_;
}
}
else
{
uint8_t v___x_411_; 
v___x_411_ = lean_uint32_dec_eq(v_iy_394_, v___x_400_);
if (v___x_411_ == 0)
{
uint8_t v___x_412_; 
v___x_412_ = lean_uint32_dec_eq(v_m_391_, v___x_377_);
if (v___x_412_ == 0)
{
uint8_t v___x_413_; 
v___x_413_ = lean_uint32_dec_eq(v_m_391_, v___x_385_);
if (v___x_413_ == 0)
{
uint8_t v___x_414_; 
v___x_414_ = lean_uint32_dec_eq(v_m_391_, v___x_389_);
if (v___x_414_ == 0)
{
double v___x_415_; 
v___x_415_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1);
return v___x_415_;
}
else
{
return v_pi_331_;
}
}
else
{
double v___x_416_; 
v___x_416_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__4, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__4_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__4);
return v___x_416_;
}
}
else
{
double v___x_417_; 
v___x_417_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__3);
return v___x_417_;
}
}
else
{
uint8_t v___x_418_; 
v___x_418_ = lean_uint32_dec_eq(v_m_391_, v___x_377_);
if (v___x_418_ == 0)
{
uint8_t v___x_419_; 
v___x_419_ = lean_uint32_dec_eq(v_m_391_, v___x_385_);
if (v___x_419_ == 0)
{
uint8_t v___x_420_; 
v___x_420_ = lean_uint32_dec_eq(v_m_391_, v___x_389_);
if (v___x_420_ == 0)
{
double v___x_421_; 
v___x_421_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__9, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__9_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__9);
return v___x_421_;
}
else
{
double v___x_422_; 
v___x_422_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__11, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__11_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__11);
return v___x_422_;
}
}
else
{
double v___x_423_; 
v___x_423_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__12, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__12_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__12);
return v___x_423_;
}
}
else
{
double v___x_424_; 
v___x_424_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__13, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__13_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__13);
return v___x_424_;
}
}
}
}
else
{
uint32_t v___x_425_; uint8_t v___x_426_; 
v___x_425_ = lean_uint32_land(v_m_391_, v___x_385_);
v___x_426_ = lean_uint32_dec_eq(v___x_425_, v___x_377_);
if (v___x_426_ == 0)
{
double v___x_427_; 
v___x_427_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__14, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__14_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__14);
return v___x_427_;
}
else
{
double v___x_428_; 
v___x_428_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__15, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__15_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__15);
return v___x_428_;
}
}
}
else
{
uint8_t v___x_429_; 
v___x_429_ = lean_uint32_dec_lt(v_m_391_, v___x_389_);
if (v___x_429_ == 0)
{
uint8_t v___x_430_; 
v___x_430_ = lean_uint32_dec_eq(v_m_391_, v___x_389_);
if (v___x_430_ == 0)
{
double v___x_431_; 
v___x_431_ = lean_float_once(&lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1, &lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1_once, _init_lp_lean1090_Lean1090_Impl_Libm_atan2___closed__1);
return v___x_431_;
}
else
{
return v_pi_331_;
}
}
else
{
return v_y_329_;
}
}
}
else
{
double v___x_432_; 
v___x_432_ = lp_lean1090_Lean1090_Impl_Libm_atan(v_y_329_);
return v___x_432_;
}
}
else
{
double v___x_433_; 
v___x_433_ = lean_float_add(v_x_330_, v_y_329_);
return v___x_433_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Libm_atan2___boxed(lean_object* v_y_436_, lean_object* v_x_437_){
_start:
{
double v_y_boxed_438_; double v_x_boxed_439_; double v_res_440_; lean_object* v_r_441_; 
v_y_boxed_438_ = lean_unbox_float(v_y_436_);
lean_dec_ref(v_y_436_);
v_x_boxed_439_ = lean_unbox_float(v_x_437_);
lean_dec_ref(v_x_437_);
v_res_440_ = lp_lean1090_Lean1090_Impl_Libm_atan2(v_y_boxed_438_, v_x_boxed_439_);
v_r_441_ = lean_box_float(v_res_440_);
return v_r_441_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Libm(uint8_t builtin) {
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
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__1 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__1();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__1);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__2 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__2();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__14___boxed__const__2);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__1 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__1();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__1);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__2 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__2();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__18___boxed__const__2);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__1 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__1();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__1);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__2 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__2();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__22___boxed__const__2);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__1 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__1();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__1);
lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__2 = _init_lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__2();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Libm_atan___closed__26___boxed__const__2);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
