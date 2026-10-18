// Lean compiler output
// Module: Impl.PayloadBits
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
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Spec_PayloadCoding_ctorIdx(uint8_t);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* l_Rat_mul(lean_object*, lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields___boxed(lean_object*, lean_object*);
static lean_once_cell_t lp_lean1090_Lean1090_Impl_payloadInteger___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090_Lean1090_Impl_payloadInteger___closed__0;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadInteger(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadInteger___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadValue(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadValue___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object* v_word_1_, lean_object* v_start_2_, lean_object* v_width_3_){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; lean_object* v___x_7_; lean_object* v___x_8_; lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; lean_object* v___x_12_; lean_object* v___x_13_; 
v___x_4_ = lean_unsigned_to_nat(2u);
v___x_5_ = lean_unsigned_to_nat(56u);
v___x_6_ = lean_unsigned_to_nat(1u);
v___x_7_ = lean_nat_sub(v_start_2_, v___x_6_);
v___x_8_ = lean_nat_add(v___x_7_, v_width_3_);
lean_dec(v___x_7_);
v___x_9_ = lean_nat_sub(v___x_5_, v___x_8_);
lean_dec(v___x_8_);
v___x_10_ = lean_nat_pow(v___x_4_, v___x_9_);
lean_dec(v___x_9_);
v___x_11_ = lean_nat_div(v_word_1_, v___x_10_);
lean_dec(v___x_10_);
v___x_12_ = lean_nat_pow(v___x_4_, v_width_3_);
v___x_13_ = lean_nat_mod(v___x_11_, v___x_12_);
lean_dec(v___x_12_);
lean_dec(v___x_11_);
return v___x_13_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits___boxed(lean_object* v_word_14_, lean_object* v_start_15_, lean_object* v_width_16_){
_start:
{
lean_object* v_res_17_; 
v_res_17_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_14_, v_start_15_, v_width_16_);
lean_dec(v_width_16_);
lean_dec(v_start_15_);
lean_dec(v_word_14_);
return v_res_17_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(lean_object* v_word_18_, lean_object* v_a_19_, lean_object* v_a_20_){
_start:
{
if (lean_obj_tag(v_a_19_) == 0)
{
lean_object* v___x_21_; 
v___x_21_ = l_List_reverse___redArg(v_a_20_);
return v___x_21_;
}
else
{
lean_object* v_head_22_; lean_object* v_tail_23_; lean_object* v___x_25_; uint8_t v_isShared_26_; uint8_t v_isSharedCheck_36_; 
v_head_22_ = lean_ctor_get(v_a_19_, 0);
v_tail_23_ = lean_ctor_get(v_a_19_, 1);
v_isSharedCheck_36_ = !lean_is_exclusive(v_a_19_);
if (v_isSharedCheck_36_ == 0)
{
v___x_25_ = v_a_19_;
v_isShared_26_ = v_isSharedCheck_36_;
goto v_resetjp_24_;
}
else
{
lean_inc(v_tail_23_);
lean_inc(v_head_22_);
lean_dec(v_a_19_);
v___x_25_ = lean_box(0);
v_isShared_26_ = v_isSharedCheck_36_;
goto v_resetjp_24_;
}
v_resetjp_24_:
{
lean_object* v_name_27_; lean_object* v_start_28_; lean_object* v_width_29_; lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_33_; 
v_name_27_ = lean_ctor_get(v_head_22_, 0);
lean_inc_ref(v_name_27_);
v_start_28_ = lean_ctor_get(v_head_22_, 1);
lean_inc(v_start_28_);
v_width_29_ = lean_ctor_get(v_head_22_, 2);
lean_inc(v_width_29_);
lean_dec(v_head_22_);
v___x_30_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_18_, v_start_28_, v_width_29_);
lean_dec(v_width_29_);
lean_dec(v_start_28_);
v___x_31_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_31_, 0, v_name_27_);
lean_ctor_set(v___x_31_, 1, v___x_30_);
if (v_isShared_26_ == 0)
{
lean_ctor_set(v___x_25_, 1, v_a_20_);
lean_ctor_set(v___x_25_, 0, v___x_31_);
v___x_33_ = v___x_25_;
goto v_reusejp_32_;
}
else
{
lean_object* v_reuseFailAlloc_35_; 
v_reuseFailAlloc_35_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_35_, 0, v___x_31_);
lean_ctor_set(v_reuseFailAlloc_35_, 1, v_a_20_);
v___x_33_ = v_reuseFailAlloc_35_;
goto v_reusejp_32_;
}
v_reusejp_32_:
{
v_a_19_ = v_tail_23_;
v_a_20_ = v___x_33_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0___boxed(lean_object* v_word_37_, lean_object* v_a_38_, lean_object* v_a_39_){
_start:
{
lean_object* v_res_40_; 
v_res_40_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(v_word_37_, v_a_38_, v_a_39_);
lean_dec(v_word_37_);
return v_res_40_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields(lean_object* v_layout_41_, lean_object* v_word_42_){
_start:
{
lean_object* v___x_43_; lean_object* v___x_44_; 
v___x_43_ = lean_box(0);
v___x_44_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(v_word_42_, v_layout_41_, v___x_43_);
return v___x_44_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields___boxed(lean_object* v_layout_45_, lean_object* v_word_46_){
_start:
{
lean_object* v_res_47_; 
v_res_47_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_layout_45_, v_word_46_);
lean_dec(v_word_46_);
return v_res_47_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_payloadInteger___closed__0(void){
_start:
{
uint8_t v___x_48_; lean_object* v___x_49_; 
v___x_48_ = 1;
v___x_49_ = lp_lean1090_Lean1090_Spec_PayloadCoding_ctorIdx(v___x_48_);
return v___x_49_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadInteger(uint8_t v_coding_50_, lean_object* v_width_51_, lean_object* v_code_52_){
_start:
{
lean_object* v___x_53_; lean_object* v___x_54_; uint8_t v___x_55_; 
v___x_53_ = lp_lean1090_Lean1090_Spec_PayloadCoding_ctorIdx(v_coding_50_);
v___x_54_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_payloadInteger___closed__0, &lp_lean1090_Lean1090_Impl_payloadInteger___closed__0_once, _init_lp_lean1090_Lean1090_Impl_payloadInteger___closed__0);
v___x_55_ = lean_nat_dec_eq(v___x_53_, v___x_54_);
lean_dec(v___x_53_);
if (v___x_55_ == 0)
{
lean_object* v___x_56_; 
v___x_56_ = lean_nat_to_int(v_code_52_);
return v___x_56_;
}
else
{
lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; uint8_t v___x_61_; 
v___x_57_ = lean_unsigned_to_nat(2u);
v___x_58_ = lean_unsigned_to_nat(1u);
v___x_59_ = lean_nat_sub(v_width_51_, v___x_58_);
v___x_60_ = lean_nat_pow(v___x_57_, v___x_59_);
lean_dec(v___x_59_);
v___x_61_ = lean_nat_dec_le(v___x_60_, v_code_52_);
lean_dec(v___x_60_);
if (v___x_61_ == 0)
{
lean_object* v___x_62_; 
v___x_62_ = lean_nat_to_int(v_code_52_);
return v___x_62_;
}
else
{
lean_object* v___x_63_; lean_object* v___x_64_; lean_object* v___x_65_; lean_object* v___x_66_; 
v___x_63_ = lean_nat_to_int(v_code_52_);
v___x_64_ = lean_nat_pow(v___x_57_, v_width_51_);
v___x_65_ = lean_nat_to_int(v___x_64_);
v___x_66_ = lean_int_sub(v___x_63_, v___x_65_);
lean_dec(v___x_65_);
lean_dec(v___x_63_);
return v___x_66_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadInteger___boxed(lean_object* v_coding_67_, lean_object* v_width_68_, lean_object* v_code_69_){
_start:
{
uint8_t v_coding_boxed_70_; lean_object* v_res_71_; 
v_coding_boxed_70_ = lean_unbox(v_coding_67_);
v_res_71_ = lp_lean1090_Lean1090_Impl_payloadInteger(v_coding_boxed_70_, v_width_68_, v_code_69_);
lean_dec(v_width_68_);
return v_res_71_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadValue(lean_object* v_column_72_, lean_object* v_word_73_){
_start:
{
lean_object* v_start_74_; lean_object* v_width_75_; uint8_t v_coding_76_; lean_object* v_scale_77_; lean_object* v_offset_78_; lean_object* v_status_79_; lean_object* v___x_87_; uint8_t v___x_88_; 
v_start_74_ = lean_ctor_get(v_column_72_, 1);
lean_inc(v_start_74_);
v_width_75_ = lean_ctor_get(v_column_72_, 2);
lean_inc(v_width_75_);
v_coding_76_ = lean_ctor_get_uint8(v_column_72_, sizeof(void*)*6);
v_scale_77_ = lean_ctor_get(v_column_72_, 3);
lean_inc_ref(v_scale_77_);
v_offset_78_ = lean_ctor_get(v_column_72_, 4);
lean_inc_ref(v_offset_78_);
v_status_79_ = lean_ctor_get(v_column_72_, 5);
lean_inc(v_status_79_);
lean_dec_ref(v_column_72_);
v___x_87_ = lean_unsigned_to_nat(0u);
v___x_88_ = lean_nat_dec_eq(v_status_79_, v___x_87_);
if (v___x_88_ == 0)
{
lean_object* v___x_89_; lean_object* v___x_90_; uint8_t v___x_91_; 
v___x_89_ = lean_unsigned_to_nat(1u);
v___x_90_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_73_, v_status_79_, v___x_89_);
lean_dec(v_status_79_);
v___x_91_ = lean_nat_dec_eq(v___x_90_, v___x_87_);
lean_dec(v___x_90_);
if (v___x_91_ == 0)
{
goto v___jp_80_;
}
else
{
lean_object* v___x_92_; 
lean_dec_ref(v_offset_78_);
lean_dec_ref(v_scale_77_);
lean_dec(v_width_75_);
lean_dec(v_start_74_);
v___x_92_ = lean_box(0);
return v___x_92_;
}
}
else
{
lean_dec(v_status_79_);
goto v___jp_80_;
}
v___jp_80_:
{
lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; lean_object* v___x_85_; lean_object* v___x_86_; 
v___x_81_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_73_, v_start_74_, v_width_75_);
lean_dec(v_start_74_);
v___x_82_ = lp_lean1090_Lean1090_Impl_payloadInteger(v_coding_76_, v_width_75_, v___x_81_);
lean_dec(v_width_75_);
v___x_83_ = l_Rat_ofInt(v___x_82_);
v___x_84_ = l_Rat_mul(v___x_83_, v_scale_77_);
lean_dec_ref(v___x_83_);
v___x_85_ = l_Rat_add(v___x_84_, v_offset_78_);
v___x_86_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_86_, 0, v___x_85_);
return v___x_86_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadValue___boxed(lean_object* v_column_93_, lean_object* v_word_94_){
_start:
{
lean_object* v_res_95_; 
v_res_95_ = lp_lean1090_Lean1090_Impl_payloadValue(v_column_93_, v_word_94_);
lean_dec(v_word_94_);
return v_res_95_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Model_Types(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Impl_PayloadBits(uint8_t builtin) {
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
