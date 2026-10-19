// Lean compiler output
// Module: Impl.Bits
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
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
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
lean_object* v___x_23_; lean_object* v___x_24_; lean_object* v___x_25_; lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; 
v___x_23_ = lean_unsigned_to_nat(2u);
v___x_24_ = lean_nat_sub(v_total_19_, v_start_20_);
v___x_25_ = lean_nat_sub(v___x_24_, v_width_21_);
lean_dec(v___x_24_);
v___x_26_ = lean_nat_pow(v___x_23_, v___x_25_);
lean_dec(v___x_25_);
v___x_27_ = lean_nat_div(v_word_22_, v___x_26_);
lean_dec(v___x_26_);
v___x_28_ = l_BitVec_ofNat(v_width_21_, v___x_27_);
lean_dec(v___x_27_);
return v___x_28_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_field___boxed(lean_object* v_total_29_, lean_object* v_start_30_, lean_object* v_width_31_, lean_object* v_word_32_){
_start:
{
lean_object* v_res_33_; 
v_res_33_ = lp_lean1090_Lean1090_Impl_field(v_total_29_, v_start_30_, v_width_31_, v_word_32_);
lean_dec(v_word_32_);
lean_dec(v_width_31_);
lean_dec(v_start_30_);
lean_dec(v_total_29_);
return v_res_33_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(lean_object* v_x_34_, lean_object* v_x_35_){
_start:
{
if (lean_obj_tag(v_x_35_) == 0)
{
return v_x_34_;
}
else
{
lean_object* v_head_36_; lean_object* v_tail_37_; lean_object* v_fst_38_; lean_object* v_snd_39_; lean_object* v___x_40_; lean_object* v___x_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; 
v_head_36_ = lean_ctor_get(v_x_35_, 0);
v_tail_37_ = lean_ctor_get(v_x_35_, 1);
v_fst_38_ = lean_ctor_get(v_head_36_, 0);
v_snd_39_ = lean_ctor_get(v_head_36_, 1);
v___x_40_ = lean_unsigned_to_nat(2u);
v___x_41_ = lean_nat_pow(v___x_40_, v_fst_38_);
v___x_42_ = lean_nat_mul(v_x_34_, v___x_41_);
lean_dec(v_x_34_);
v___x_43_ = lean_nat_mod(v_snd_39_, v___x_41_);
lean_dec(v___x_41_);
v___x_44_ = lean_nat_add(v___x_42_, v___x_43_);
lean_dec(v___x_43_);
lean_dec(v___x_42_);
v_x_34_ = v___x_44_;
v_x_35_ = v_tail_37_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0___boxed(lean_object* v_x_46_, lean_object* v_x_47_){
_start:
{
lean_object* v_res_48_; 
v_res_48_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(v_x_46_, v_x_47_);
lean_dec(v_x_47_);
return v_res_48_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields(lean_object* v_fields_49_){
_start:
{
lean_object* v___x_50_; lean_object* v___x_51_; 
v___x_50_ = lean_unsigned_to_nat(0u);
v___x_51_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0(v___x_50_, v_fields_49_);
return v___x_51_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_packFields___boxed(lean_object* v_fields_52_){
_start:
{
lean_object* v_res_53_; 
v_res_53_ = lp_lean1090_Lean1090_Impl_packFields(v_fields_52_);
lean_dec(v_fields_52_);
return v_res_53_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes(lean_object* v_df_54_){
_start:
{
lean_object* v___x_55_; uint8_t v___x_56_; 
v___x_55_ = lean_unsigned_to_nat(16u);
v___x_56_ = lean_nat_dec_lt(v_df_54_, v___x_55_);
if (v___x_56_ == 0)
{
lean_object* v___x_57_; 
v___x_57_ = lean_unsigned_to_nat(14u);
return v___x_57_;
}
else
{
lean_object* v___x_58_; 
v___x_58_ = lean_unsigned_to_nat(7u);
return v___x_58_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_frameBytes___boxed(lean_object* v_df_59_){
_start:
{
lean_object* v_res_60_; 
v_res_60_ = lp_lean1090_Lean1090_Impl_frameBytes(v_df_59_);
lean_dec(v_df_59_);
return v_res_60_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
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
res = initialize_lean1090_Model_Types(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
