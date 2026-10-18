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
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_pow(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_shift_left(uint64_t, uint64_t);
uint64_t lean_uint64_sub(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* lp_lean1090_Lean1090_Spec_PayloadCoding_ctorIdx(uint8_t);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* l_Rat_mul(lean_object*, lean_object*);
lean_object* l_Rat_add(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadWordBits(uint64_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadWordBits___boxed(lean_object*, lean_object*, lean_object*);
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
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadWordBits(uint64_t v_word_1_, lean_object* v_shift_2_, lean_object* v_width_3_){
_start:
{
uint64_t v___x_4_; uint64_t v___x_5_; uint64_t v___x_6_; uint64_t v___x_7_; uint64_t v___x_8_; uint64_t v___x_9_; uint64_t v___x_10_; lean_object* v___x_11_; 
v___x_4_ = lean_uint64_of_nat(v_shift_2_);
v___x_5_ = lean_uint64_shift_right(v_word_1_, v___x_4_);
v___x_6_ = 1ULL;
v___x_7_ = lean_uint64_of_nat(v_width_3_);
v___x_8_ = lean_uint64_shift_left(v___x_6_, v___x_7_);
v___x_9_ = lean_uint64_sub(v___x_8_, v___x_6_);
v___x_10_ = lean_uint64_land(v___x_5_, v___x_9_);
v___x_11_ = lean_uint64_to_nat(v___x_10_);
return v___x_11_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadWordBits___boxed(lean_object* v_word_12_, lean_object* v_shift_13_, lean_object* v_width_14_){
_start:
{
uint64_t v_word_boxed_15_; lean_object* v_res_16_; 
v_word_boxed_15_ = lean_unbox_uint64(v_word_12_);
lean_dec_ref(v_word_12_);
v_res_16_ = lp_lean1090_Lean1090_Impl_payloadWordBits(v_word_boxed_15_, v_shift_13_, v_width_14_);
lean_dec(v_width_14_);
lean_dec(v_shift_13_);
return v_res_16_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits(lean_object* v_word_17_, lean_object* v_start_18_, lean_object* v_width_19_){
_start:
{
lean_object* v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v_shift_24_; lean_object* v___x_25_; uint8_t v___x_26_; 
v___x_20_ = lean_unsigned_to_nat(56u);
v___x_21_ = lean_unsigned_to_nat(1u);
v___x_22_ = lean_nat_sub(v_start_18_, v___x_21_);
v___x_23_ = lean_nat_add(v___x_22_, v_width_19_);
lean_dec(v___x_22_);
v_shift_24_ = lean_nat_sub(v___x_20_, v___x_23_);
lean_dec(v___x_23_);
v___x_25_ = lean_unsigned_to_nat(64u);
v___x_26_ = lean_nat_dec_lt(v_width_19_, v___x_25_);
if (v___x_26_ == 0)
{
lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; 
v___x_27_ = lean_unsigned_to_nat(2u);
v___x_28_ = lean_nat_pow(v___x_27_, v_shift_24_);
lean_dec(v_shift_24_);
v___x_29_ = lean_nat_div(v_word_17_, v___x_28_);
lean_dec(v___x_28_);
v___x_30_ = lean_nat_pow(v___x_27_, v_width_19_);
v___x_31_ = lean_nat_mod(v___x_29_, v___x_30_);
lean_dec(v___x_30_);
lean_dec(v___x_29_);
return v___x_31_;
}
else
{
uint64_t v___x_32_; uint64_t v___x_33_; uint64_t v___x_34_; uint64_t v___x_35_; uint64_t v___x_36_; uint64_t v___x_37_; uint64_t v___x_38_; uint64_t v___x_39_; lean_object* v___x_40_; 
v___x_32_ = lean_uint64_of_nat(v_word_17_);
v___x_33_ = lean_uint64_of_nat(v_shift_24_);
lean_dec(v_shift_24_);
v___x_34_ = lean_uint64_shift_right(v___x_32_, v___x_33_);
v___x_35_ = 1ULL;
v___x_36_ = lean_uint64_of_nat(v_width_19_);
v___x_37_ = lean_uint64_shift_left(v___x_35_, v___x_36_);
v___x_38_ = lean_uint64_sub(v___x_37_, v___x_35_);
v___x_39_ = lean_uint64_land(v___x_34_, v___x_38_);
v___x_40_ = lean_uint64_to_nat(v___x_39_);
return v___x_40_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits___boxed(lean_object* v_word_41_, lean_object* v_start_42_, lean_object* v_width_43_){
_start:
{
lean_object* v_res_44_; 
v_res_44_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_41_, v_start_42_, v_width_43_);
lean_dec(v_width_43_);
lean_dec(v_start_42_);
lean_dec(v_word_41_);
return v_res_44_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(lean_object* v_word_45_, lean_object* v_a_46_, lean_object* v_a_47_){
_start:
{
if (lean_obj_tag(v_a_46_) == 0)
{
lean_object* v___x_48_; 
v___x_48_ = l_List_reverse___redArg(v_a_47_);
return v___x_48_;
}
else
{
lean_object* v_head_49_; lean_object* v_tail_50_; lean_object* v___x_52_; uint8_t v_isShared_53_; uint8_t v_isSharedCheck_63_; 
v_head_49_ = lean_ctor_get(v_a_46_, 0);
v_tail_50_ = lean_ctor_get(v_a_46_, 1);
v_isSharedCheck_63_ = !lean_is_exclusive(v_a_46_);
if (v_isSharedCheck_63_ == 0)
{
v___x_52_ = v_a_46_;
v_isShared_53_ = v_isSharedCheck_63_;
goto v_resetjp_51_;
}
else
{
lean_inc(v_tail_50_);
lean_inc(v_head_49_);
lean_dec(v_a_46_);
v___x_52_ = lean_box(0);
v_isShared_53_ = v_isSharedCheck_63_;
goto v_resetjp_51_;
}
v_resetjp_51_:
{
lean_object* v_name_54_; lean_object* v_start_55_; lean_object* v_width_56_; lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v___x_60_; 
v_name_54_ = lean_ctor_get(v_head_49_, 0);
lean_inc_ref(v_name_54_);
v_start_55_ = lean_ctor_get(v_head_49_, 1);
lean_inc(v_start_55_);
v_width_56_ = lean_ctor_get(v_head_49_, 2);
lean_inc(v_width_56_);
lean_dec(v_head_49_);
v___x_57_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_45_, v_start_55_, v_width_56_);
lean_dec(v_width_56_);
lean_dec(v_start_55_);
v___x_58_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_58_, 0, v_name_54_);
lean_ctor_set(v___x_58_, 1, v___x_57_);
if (v_isShared_53_ == 0)
{
lean_ctor_set(v___x_52_, 1, v_a_47_);
lean_ctor_set(v___x_52_, 0, v___x_58_);
v___x_60_ = v___x_52_;
goto v_reusejp_59_;
}
else
{
lean_object* v_reuseFailAlloc_62_; 
v_reuseFailAlloc_62_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_62_, 0, v___x_58_);
lean_ctor_set(v_reuseFailAlloc_62_, 1, v_a_47_);
v___x_60_ = v_reuseFailAlloc_62_;
goto v_reusejp_59_;
}
v_reusejp_59_:
{
v_a_46_ = v_tail_50_;
v_a_47_ = v___x_60_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0___boxed(lean_object* v_word_64_, lean_object* v_a_65_, lean_object* v_a_66_){
_start:
{
lean_object* v_res_67_; 
v_res_67_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(v_word_64_, v_a_65_, v_a_66_);
lean_dec(v_word_64_);
return v_res_67_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields(lean_object* v_layout_68_, lean_object* v_word_69_){
_start:
{
lean_object* v___x_70_; lean_object* v___x_71_; 
v___x_70_ = lean_box(0);
v___x_71_ = lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_decodePayloadFields_spec__0(v_word_69_, v_layout_68_, v___x_70_);
return v___x_71_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_decodePayloadFields___boxed(lean_object* v_layout_72_, lean_object* v_word_73_){
_start:
{
lean_object* v_res_74_; 
v_res_74_ = lp_lean1090_Lean1090_Impl_decodePayloadFields(v_layout_72_, v_word_73_);
lean_dec(v_word_73_);
return v_res_74_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_payloadInteger___closed__0(void){
_start:
{
uint8_t v___x_75_; lean_object* v___x_76_; 
v___x_75_ = 1;
v___x_76_ = lp_lean1090_Lean1090_Spec_PayloadCoding_ctorIdx(v___x_75_);
return v___x_76_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadInteger(uint8_t v_coding_77_, lean_object* v_width_78_, lean_object* v_code_79_){
_start:
{
lean_object* v___x_80_; lean_object* v___x_81_; uint8_t v___x_82_; 
v___x_80_ = lp_lean1090_Lean1090_Spec_PayloadCoding_ctorIdx(v_coding_77_);
v___x_81_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_payloadInteger___closed__0, &lp_lean1090_Lean1090_Impl_payloadInteger___closed__0_once, _init_lp_lean1090_Lean1090_Impl_payloadInteger___closed__0);
v___x_82_ = lean_nat_dec_eq(v___x_80_, v___x_81_);
lean_dec(v___x_80_);
if (v___x_82_ == 0)
{
lean_object* v___x_83_; 
v___x_83_ = lean_nat_to_int(v_code_79_);
return v___x_83_;
}
else
{
lean_object* v___x_84_; lean_object* v___x_85_; lean_object* v___x_86_; lean_object* v___x_87_; uint8_t v___x_88_; 
v___x_84_ = lean_unsigned_to_nat(2u);
v___x_85_ = lean_unsigned_to_nat(1u);
v___x_86_ = lean_nat_sub(v_width_78_, v___x_85_);
v___x_87_ = lean_nat_pow(v___x_84_, v___x_86_);
lean_dec(v___x_86_);
v___x_88_ = lean_nat_dec_le(v___x_87_, v_code_79_);
lean_dec(v___x_87_);
if (v___x_88_ == 0)
{
lean_object* v___x_89_; 
v___x_89_ = lean_nat_to_int(v_code_79_);
return v___x_89_;
}
else
{
lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; lean_object* v___x_93_; 
v___x_90_ = lean_nat_to_int(v_code_79_);
v___x_91_ = lean_nat_pow(v___x_84_, v_width_78_);
v___x_92_ = lean_nat_to_int(v___x_91_);
v___x_93_ = lean_int_sub(v___x_90_, v___x_92_);
lean_dec(v___x_92_);
lean_dec(v___x_90_);
return v___x_93_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadInteger___boxed(lean_object* v_coding_94_, lean_object* v_width_95_, lean_object* v_code_96_){
_start:
{
uint8_t v_coding_boxed_97_; lean_object* v_res_98_; 
v_coding_boxed_97_ = lean_unbox(v_coding_94_);
v_res_98_ = lp_lean1090_Lean1090_Impl_payloadInteger(v_coding_boxed_97_, v_width_95_, v_code_96_);
lean_dec(v_width_95_);
return v_res_98_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadValue(lean_object* v_column_99_, lean_object* v_word_100_){
_start:
{
lean_object* v_start_101_; lean_object* v_width_102_; uint8_t v_coding_103_; lean_object* v_scale_104_; lean_object* v_offset_105_; lean_object* v_status_106_; lean_object* v___x_114_; uint8_t v___x_115_; 
v_start_101_ = lean_ctor_get(v_column_99_, 1);
lean_inc(v_start_101_);
v_width_102_ = lean_ctor_get(v_column_99_, 2);
lean_inc(v_width_102_);
v_coding_103_ = lean_ctor_get_uint8(v_column_99_, sizeof(void*)*6);
v_scale_104_ = lean_ctor_get(v_column_99_, 3);
lean_inc_ref(v_scale_104_);
v_offset_105_ = lean_ctor_get(v_column_99_, 4);
lean_inc_ref(v_offset_105_);
v_status_106_ = lean_ctor_get(v_column_99_, 5);
lean_inc(v_status_106_);
lean_dec_ref(v_column_99_);
v___x_114_ = lean_unsigned_to_nat(0u);
v___x_115_ = lean_nat_dec_eq(v_status_106_, v___x_114_);
if (v___x_115_ == 0)
{
lean_object* v___x_116_; lean_object* v___x_117_; uint8_t v___x_118_; 
v___x_116_ = lean_unsigned_to_nat(1u);
v___x_117_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_100_, v_status_106_, v___x_116_);
lean_dec(v_status_106_);
v___x_118_ = lean_nat_dec_eq(v___x_117_, v___x_114_);
lean_dec(v___x_117_);
if (v___x_118_ == 0)
{
goto v___jp_107_;
}
else
{
lean_object* v___x_119_; 
lean_dec_ref(v_offset_105_);
lean_dec_ref(v_scale_104_);
lean_dec(v_width_102_);
lean_dec(v_start_101_);
v___x_119_ = lean_box(0);
return v___x_119_;
}
}
else
{
lean_dec(v_status_106_);
goto v___jp_107_;
}
v___jp_107_:
{
lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_108_ = lp_lean1090_Lean1090_Impl_payloadBits(v_word_100_, v_start_101_, v_width_102_);
lean_dec(v_start_101_);
v___x_109_ = lp_lean1090_Lean1090_Impl_payloadInteger(v_coding_103_, v_width_102_, v___x_108_);
lean_dec(v_width_102_);
v___x_110_ = l_Rat_ofInt(v___x_109_);
v___x_111_ = l_Rat_mul(v___x_110_, v_scale_104_);
lean_dec_ref(v___x_110_);
v___x_112_ = l_Rat_add(v___x_111_, v_offset_105_);
v___x_113_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_113_, 0, v___x_112_);
return v___x_113_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadValue___boxed(lean_object* v_column_120_, lean_object* v_word_121_){
_start:
{
lean_object* v_res_122_; 
v_res_122_ = lp_lean1090_Lean1090_Impl_payloadValue(v_column_120_, v_word_121_);
lean_dec(v_word_121_);
return v_res_122_;
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
