// Lean compiler output
// Module: Impl.Bits
// Imports: public import Init public meta import Init public import Impl.PayloadBits
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
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_shift_left(uint64_t, uint64_t);
uint64_t lean_uint64_sub(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* lean_nat_mod(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesValue(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesValue___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(lean_object* v_x_1_, lean_object* v_x_2_){
_start:
{
if (lean_obj_tag(v_x_2_) == 0)
{
return v_x_1_;
}
else
{
lean_object* v_head_3_; lean_object* v_tail_4_; lean_object* v___x_5_; lean_object* v___x_6_; uint8_t v___x_7_; lean_object* v___x_8_; lean_object* v___x_9_; 
v_head_3_ = lean_ctor_get(v_x_2_, 0);
v_tail_4_ = lean_ctor_get(v_x_2_, 1);
v___x_5_ = lean_unsigned_to_nat(256u);
v___x_6_ = lean_nat_mul(v___x_5_, v_x_1_);
lean_dec(v_x_1_);
v___x_7_ = lean_unbox(v_head_3_);
v___x_8_ = lean_uint8_to_nat(v___x_7_);
v___x_9_ = lean_nat_add(v___x_6_, v___x_8_);
lean_dec(v___x_6_);
v_x_1_ = v___x_9_;
v_x_2_ = v_tail_4_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0___boxed(lean_object* v_x_11_, lean_object* v_x_12_){
_start:
{
lean_object* v_res_13_; 
v_res_13_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(v_x_11_, v_x_12_);
lean_dec(v_x_12_);
return v_res_13_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesValue(lean_object* v_bytes_14_){
_start:
{
lean_object* v___x_15_; lean_object* v___x_16_; 
v___x_15_ = lean_unsigned_to_nat(0u);
v___x_16_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0(v___x_15_, v_bytes_14_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_bytesValue___boxed(lean_object* v_bytes_17_){
_start:
{
lean_object* v_res_18_; 
v_res_18_ = lp_lean1090_Lean1090_Impl_bytesValue(v_bytes_17_);
lean_dec(v_bytes_17_);
return v_res_18_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field(lean_object* v_total_19_, lean_object* v_start_20_, lean_object* v_width_21_, lean_object* v_word_22_){
_start:
{
lean_object* v___x_23_; uint8_t v___x_24_; 
v___x_23_ = lean_unsigned_to_nat(64u);
v___x_24_ = lean_nat_dec_lt(v_width_21_, v___x_23_);
if (v___x_24_ == 0)
{
lean_object* v___x_25_; lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; lean_object* v___x_30_; 
v___x_25_ = lean_unsigned_to_nat(2u);
v___x_26_ = lean_nat_sub(v_total_19_, v_start_20_);
v___x_27_ = lean_nat_sub(v___x_26_, v_width_21_);
lean_dec(v___x_26_);
v___x_28_ = lean_nat_pow(v___x_25_, v___x_27_);
lean_dec(v___x_27_);
v___x_29_ = lean_nat_div(v_word_22_, v___x_28_);
lean_dec(v___x_28_);
v___x_30_ = l_BitVec_ofNat(v_width_21_, v___x_29_);
lean_dec(v___x_29_);
return v___x_30_;
}
else
{
lean_object* v___x_31_; lean_object* v___x_32_; lean_object* v___x_33_; uint64_t v___x_34_; uint64_t v___x_35_; uint64_t v___x_36_; uint64_t v___x_37_; uint64_t v___x_38_; uint64_t v___x_39_; lean_object* v___x_40_; 
v___x_31_ = lean_nat_sub(v_total_19_, v_start_20_);
v___x_32_ = lean_nat_sub(v___x_31_, v_width_21_);
lean_dec(v___x_31_);
v___x_33_ = lean_nat_shiftr(v_word_22_, v___x_32_);
lean_dec(v___x_32_);
v___x_34_ = lean_uint64_of_nat(v___x_33_);
lean_dec(v___x_33_);
v___x_35_ = 1ULL;
v___x_36_ = lean_uint64_of_nat(v_width_21_);
v___x_37_ = lean_uint64_shift_left(v___x_35_, v___x_36_);
v___x_38_ = lean_uint64_sub(v___x_37_, v___x_35_);
v___x_39_ = lean_uint64_land(v___x_34_, v___x_38_);
v___x_40_ = lean_uint64_to_nat(v___x_39_);
return v___x_40_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field___boxed(lean_object* v_total_41_, lean_object* v_start_42_, lean_object* v_width_43_, lean_object* v_word_44_){
_start:
{
lean_object* v_res_45_; 
v_res_45_ = lp_lean1090_Lean1090_Impl_field(v_total_41_, v_start_42_, v_width_43_, v_word_44_);
lean_dec(v_word_44_);
lean_dec(v_width_43_);
lean_dec(v_start_42_);
lean_dec(v_total_41_);
return v_res_45_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(lean_object* v_x_46_, lean_object* v_x_47_){
_start:
{
if (lean_obj_tag(v_x_47_) == 0)
{
return v_x_46_;
}
else
{
lean_object* v_head_48_; lean_object* v_tail_49_; lean_object* v_fst_50_; lean_object* v_snd_51_; lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; 
v_head_48_ = lean_ctor_get(v_x_47_, 0);
v_tail_49_ = lean_ctor_get(v_x_47_, 1);
v_fst_50_ = lean_ctor_get(v_head_48_, 0);
v_snd_51_ = lean_ctor_get(v_head_48_, 1);
v___x_52_ = lean_unsigned_to_nat(2u);
v___x_53_ = lean_nat_pow(v___x_52_, v_fst_50_);
v___x_54_ = lean_nat_mul(v_x_46_, v___x_53_);
lean_dec(v_x_46_);
v___x_55_ = lean_nat_mod(v_snd_51_, v___x_53_);
lean_dec(v___x_53_);
v___x_56_ = lean_nat_add(v___x_54_, v___x_55_);
lean_dec(v___x_55_);
lean_dec(v___x_54_);
v_x_46_ = v___x_56_;
v_x_47_ = v_tail_49_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0___boxed(lean_object* v_x_58_, lean_object* v_x_59_){
_start:
{
lean_object* v_res_60_; 
v_res_60_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(v_x_58_, v_x_59_);
lean_dec(v_x_59_);
return v_res_60_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object* v_fields_61_){
_start:
{
lean_object* v___x_62_; lean_object* v___x_63_; 
v___x_62_ = lean_unsigned_to_nat(0u);
v___x_63_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(v___x_62_, v_fields_61_);
return v___x_63_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields___boxed(lean_object* v_fields_64_){
_start:
{
lean_object* v_res_65_; 
v_res_65_ = lp_lean1090_Lean1090_Impl_packFields(v_fields_64_);
lean_dec(v_fields_64_);
return v_res_65_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object* v_df_66_){
_start:
{
lean_object* v___x_67_; uint8_t v___x_68_; 
v___x_67_ = lean_unsigned_to_nat(16u);
v___x_68_ = lean_nat_dec_lt(v_df_66_, v___x_67_);
if (v___x_68_ == 0)
{
lean_object* v___x_69_; 
v___x_69_ = lean_unsigned_to_nat(14u);
return v___x_69_;
}
else
{
lean_object* v___x_70_; 
v___x_70_ = lean_unsigned_to_nat(7u);
return v___x_70_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes___boxed(lean_object* v_df_71_){
_start:
{
lean_object* v_res_72_; 
v_res_72_ = lp_lean1090_Lean1090_Impl_frameBytes(v_df_71_);
lean_dec(v_df_71_);
return v_res_72_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_PayloadBits(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Bits(uint8_t builtin) {
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
res = initialize_lean1090_Impl_PayloadBits(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
