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
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_lxor(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
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
lean_object* v___y_5_; lean_object* v___x_8_; lean_object* v___x_9_; lean_object* v___y_11_; 
v___x_8_ = lean_unsigned_to_nat(2u);
v___x_9_ = lean_nat_mul(v___x_8_, v_remainder_2_);
if (v_bit_3_ == 0)
{
lean_object* v___x_17_; 
v___x_17_ = lean_unsigned_to_nat(0u);
v___y_11_ = v___x_17_;
goto v___jp_10_;
}
else
{
lean_object* v___x_18_; 
v___x_18_ = lean_unsigned_to_nat(1u);
v___y_11_ = v___x_18_;
goto v___jp_10_;
}
v___jp_4_:
{
lean_object* v___x_6_; lean_object* v___x_7_; 
v___x_6_ = lean_unsigned_to_nat(16777216u);
v___x_7_ = lean_nat_mod(v___y_5_, v___x_6_);
lean_dec(v___y_5_);
return v___x_7_;
}
v___jp_10_:
{
lean_object* v_shifted_12_; lean_object* v___x_13_; uint8_t v___x_14_; 
v_shifted_12_ = lean_nat_add(v___x_9_, v___y_11_);
lean_dec(v___x_9_);
v___x_13_ = lean_unsigned_to_nat(8388608u);
v___x_14_ = lean_nat_dec_le(v___x_13_, v_remainder_2_);
if (v___x_14_ == 0)
{
v___y_5_ = v_shifted_12_;
goto v___jp_4_;
}
else
{
lean_object* v___x_15_; lean_object* v___x_16_; 
v___x_15_ = lean_unsigned_to_nat(33551369u);
v___x_16_ = lean_nat_lxor(v_shifted_12_, v___x_15_);
lean_dec(v_shifted_12_);
v___y_5_ = v___x_16_;
goto v___jp_4_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step___boxed(lean_object* v_remainder_19_, lean_object* v_bit_20_){
_start:
{
uint8_t v_bit_boxed_21_; lean_object* v_res_22_; 
v_bit_boxed_21_ = lean_unbox(v_bit_20_);
v_res_22_ = lp_lean1090_Lean1090_Impl_Parity_step(v_remainder_19_, v_bit_boxed_21_);
lean_dec(v_remainder_19_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object* v_width_23_, lean_object* v_word_24_, lean_object* v_x_25_, lean_object* v_x_26_){
_start:
{
if (lean_obj_tag(v_x_26_) == 0)
{
return v_x_25_;
}
else
{
lean_object* v_head_27_; lean_object* v_tail_28_; lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; uint8_t v___x_32_; lean_object* v___x_33_; 
v_head_27_ = lean_ctor_get(v_x_26_, 0);
v_tail_28_ = lean_ctor_get(v_x_26_, 1);
v___x_29_ = lean_unsigned_to_nat(1u);
v___x_30_ = lean_nat_sub(v_width_23_, v___x_29_);
v___x_31_ = lean_nat_sub(v___x_30_, v_head_27_);
lean_dec(v___x_30_);
v___x_32_ = l_Nat_testBit(v_word_24_, v___x_31_);
lean_dec(v___x_31_);
v___x_33_ = lp_lean1090_Lean1090_Impl_Parity_step(v_x_25_, v___x_32_);
lean_dec(v_x_25_);
v_x_25_ = v___x_33_;
v_x_26_ = v_tail_28_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object* v_width_35_, lean_object* v_word_36_, lean_object* v_x_37_, lean_object* v_x_38_){
_start:
{
lean_object* v_res_39_; 
v_res_39_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_35_, v_word_36_, v_x_37_, v_x_38_);
lean_dec(v_x_38_);
lean_dec(v_word_36_);
lean_dec(v_width_35_);
return v_res_39_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0(void){
_start:
{
lean_object* v___x_40_; lean_object* v___x_41_; lean_object* v___x_42_; 
v___x_40_ = lean_unsigned_to_nat(0u);
v___x_41_ = lean_unsigned_to_nat(24u);
v___x_42_ = l_BitVec_ofNat(v___x_41_, v___x_40_);
return v___x_42_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object* v_width_43_, lean_object* v_word_44_){
_start:
{
lean_object* v___x_45_; lean_object* v___x_46_; lean_object* v___x_47_; 
v___x_45_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0, &lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0);
lean_inc(v_width_43_);
v___x_46_ = l_List_range(v_width_43_);
v___x_47_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_43_, v_word_44_, v___x_45_, v___x_46_);
lean_dec(v___x_46_);
lean_dec(v_width_43_);
return v___x_47_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object* v_width_48_, lean_object* v_word_49_){
_start:
{
lean_object* v_res_50_; 
v_res_50_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v_width_48_, v_word_49_);
lean_dec(v_word_49_);
return v_res_50_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object* v_informationWidth_51_, lean_object* v_information_52_){
_start:
{
lean_object* v___x_53_; lean_object* v___x_54_; lean_object* v___x_55_; lean_object* v___x_56_; lean_object* v___x_57_; 
v___x_53_ = lean_unsigned_to_nat(24u);
v___x_54_ = lean_nat_add(v_informationWidth_51_, v___x_53_);
v___x_55_ = lean_unsigned_to_nat(16777216u);
v___x_56_ = lean_nat_mul(v_information_52_, v___x_55_);
v___x_57_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v___x_54_, v___x_56_);
lean_dec(v___x_56_);
return v___x_57_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum___boxed(lean_object* v_informationWidth_58_, lean_object* v_information_59_){
_start:
{
lean_object* v_res_60_; 
v_res_60_ = lp_lean1090_Lean1090_Impl_Parity_checksum(v_informationWidth_58_, v_information_59_);
lean_dec(v_information_59_);
lean_dec(v_informationWidth_58_);
return v_res_60_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object* v_s_61_){
_start:
{
lean_object* v___x_62_; uint8_t v___x_63_; 
v___x_62_ = lean_unsigned_to_nat(128u);
v___x_63_ = lean_nat_dec_lt(v_s_61_, v___x_62_);
if (v___x_63_ == 0)
{
lean_object* v___x_64_; 
v___x_64_ = lean_box(0);
return v___x_64_;
}
else
{
lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; lean_object* v___x_71_; 
v___x_65_ = lean_unsigned_to_nat(3u);
v___x_66_ = lean_unsigned_to_nat(4u);
v___x_67_ = lean_nat_shiftr(v_s_61_, v___x_66_);
v___x_68_ = l_BitVec_ofNat(v___x_65_, v___x_67_);
lean_dec(v___x_67_);
v___x_69_ = l_BitVec_ofNat(v___x_66_, v_s_61_);
v___x_70_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_70_, 0, v___x_68_);
lean_ctor_set(v___x_70_, 1, v___x_69_);
v___x_71_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_71_, 0, v___x_70_);
return v___x_71_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed(lean_object* v_s_72_){
_start:
{
lean_object* v_res_73_; 
v_res_73_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v_s_72_);
lean_dec(v_s_72_);
return v_res_73_;
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
