// Lean compiler output
// Module: Impl.Parity
// Imports: public import Init public meta import Init public import Impl.Bits
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
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t l_Nat_testBit(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lean_nat_lxor(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_generator;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step(lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed(lean_object*);
static lean_object* _init_lp_lean1090_Lean1090_Impl_Parity_generator(void){
_start:
{
lean_object* v___x_1_; 
v___x_1_ = lean_unsigned_to_nat(33551369u);
return v___x_1_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step(lean_object* v_remainder_2_, uint8_t v_bit_3_){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; lean_object* v___y_8_; 
v___x_4_ = lean_unsigned_to_nat(2u);
v___x_5_ = lean_unsigned_to_nat(24u);
v___x_6_ = lean_nat_mul(v___x_4_, v_remainder_2_);
if (v_bit_3_ == 0)
{
lean_object* v___x_16_; 
v___x_16_ = lean_unsigned_to_nat(0u);
v___y_8_ = v___x_16_;
goto v___jp_7_;
}
else
{
lean_object* v___x_17_; 
v___x_17_ = lean_unsigned_to_nat(1u);
v___y_8_ = v___x_17_;
goto v___jp_7_;
}
v___jp_7_:
{
lean_object* v_shifted_9_; lean_object* v___x_10_; uint8_t v___x_11_; 
v_shifted_9_ = lean_nat_add(v___x_6_, v___y_8_);
lean_dec(v___x_6_);
v___x_10_ = lean_unsigned_to_nat(8388608u);
v___x_11_ = lean_nat_dec_le(v___x_10_, v_remainder_2_);
if (v___x_11_ == 0)
{
lean_object* v___x_12_; 
v___x_12_ = l_BitVec_ofNat(v___x_5_, v_shifted_9_);
lean_dec(v_shifted_9_);
return v___x_12_;
}
else
{
lean_object* v___x_13_; lean_object* v___x_14_; lean_object* v___x_15_; 
v___x_13_ = lean_unsigned_to_nat(33551369u);
v___x_14_ = lean_nat_lxor(v_shifted_9_, v___x_13_);
lean_dec(v_shifted_9_);
v___x_15_ = l_BitVec_ofNat(v___x_5_, v___x_14_);
lean_dec(v___x_14_);
return v___x_15_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step___boxed(lean_object* v_remainder_18_, lean_object* v_bit_19_){
_start:
{
uint8_t v_bit_boxed_20_; lean_object* v_res_21_; 
v_bit_boxed_20_ = lean_unbox(v_bit_19_);
v_res_21_ = lp_lean1090_Lean1090_Impl_Parity_step(v_remainder_18_, v_bit_boxed_20_);
lean_dec(v_remainder_18_);
return v_res_21_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object* v_width_22_, lean_object* v_word_23_, lean_object* v_x_24_, lean_object* v_x_25_){
_start:
{
if (lean_obj_tag(v_x_25_) == 0)
{
return v_x_24_;
}
else
{
lean_object* v_head_26_; lean_object* v_tail_27_; lean_object* v___x_28_; lean_object* v___x_29_; lean_object* v___x_30_; uint8_t v___x_31_; lean_object* v___x_32_; 
v_head_26_ = lean_ctor_get(v_x_25_, 0);
v_tail_27_ = lean_ctor_get(v_x_25_, 1);
v___x_28_ = lean_unsigned_to_nat(1u);
v___x_29_ = lean_nat_sub(v_width_22_, v___x_28_);
v___x_30_ = lean_nat_sub(v___x_29_, v_head_26_);
lean_dec(v___x_29_);
v___x_31_ = l_Nat_testBit(v_word_23_, v___x_30_);
lean_dec(v___x_30_);
v___x_32_ = lp_lean1090_Lean1090_Impl_Parity_step(v_x_24_, v___x_31_);
lean_dec(v_x_24_);
v_x_24_ = v___x_32_;
v_x_25_ = v_tail_27_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object* v_width_34_, lean_object* v_word_35_, lean_object* v_x_36_, lean_object* v_x_37_){
_start:
{
lean_object* v_res_38_; 
v_res_38_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_34_, v_word_35_, v_x_36_, v_x_37_);
lean_dec(v_x_37_);
lean_dec(v_word_35_);
lean_dec(v_width_34_);
return v_res_38_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0(void){
_start:
{
lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; 
v___x_39_ = lean_unsigned_to_nat(0u);
v___x_40_ = lean_unsigned_to_nat(24u);
v___x_41_ = l_BitVec_ofNat(v___x_40_, v___x_39_);
return v___x_41_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object* v_width_42_, lean_object* v_word_43_){
_start:
{
lean_object* v___x_44_; lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_44_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0, &lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0);
lean_inc(v_width_42_);
v___x_45_ = l_List_range(v_width_42_);
v___x_46_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_42_, v_word_43_, v___x_44_, v___x_45_);
lean_dec(v___x_45_);
lean_dec(v_width_42_);
return v___x_46_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object* v_width_47_, lean_object* v_word_48_){
_start:
{
lean_object* v_res_49_; 
v_res_49_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v_width_47_, v_word_48_);
lean_dec(v_word_48_);
return v_res_49_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object* v_informationWidth_50_, lean_object* v_information_51_){
_start:
{
lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_52_ = lean_unsigned_to_nat(24u);
v___x_53_ = lean_nat_add(v_informationWidth_50_, v___x_52_);
v___x_54_ = lean_unsigned_to_nat(16777216u);
v___x_55_ = lean_nat_mul(v_information_51_, v___x_54_);
v___x_56_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v___x_53_, v___x_55_);
lean_dec(v___x_55_);
return v___x_56_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum___boxed(lean_object* v_informationWidth_57_, lean_object* v_information_58_){
_start:
{
lean_object* v_res_59_; 
v_res_59_ = lp_lean1090_Lean1090_Impl_Parity_checksum(v_informationWidth_57_, v_information_58_);
lean_dec(v_information_58_);
lean_dec(v_informationWidth_57_);
return v_res_59_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object* v_s_60_){
_start:
{
lean_object* v___x_61_; uint8_t v___x_62_; 
v___x_61_ = lean_unsigned_to_nat(128u);
v___x_62_ = lean_nat_dec_lt(v_s_60_, v___x_61_);
if (v___x_62_ == 0)
{
lean_object* v___x_63_; 
v___x_63_ = lean_box(0);
return v___x_63_;
}
else
{
lean_object* v___x_64_; lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; 
v___x_64_ = lean_unsigned_to_nat(3u);
v___x_65_ = lean_unsigned_to_nat(4u);
v___x_66_ = lean_nat_shiftr(v_s_60_, v___x_65_);
v___x_67_ = l_BitVec_ofNat(v___x_64_, v___x_66_);
lean_dec(v___x_66_);
v___x_68_ = l_BitVec_ofNat(v___x_65_, v_s_60_);
v___x_69_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_69_, 0, v___x_67_);
lean_ctor_set(v___x_69_, 1, v___x_68_);
v___x_70_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_70_, 0, v___x_69_);
return v___x_70_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed(lean_object* v_s_71_){
_start:
{
lean_object* v_res_72_; 
v_res_72_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v_s_71_);
lean_dec(v_s_71_);
return v_res_72_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_Bits(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_Parity(uint8_t builtin) {
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
res = initialize_lean1090_Impl_Bits(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_lean1090_Lean1090_Impl_Parity_generator = _init_lp_lean1090_Lean1090_Impl_Parity_generator();
lean_mark_persistent(lp_lean1090_Lean1090_Impl_Parity_generator);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
