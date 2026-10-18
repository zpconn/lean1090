// Lean compiler output
// Module: Tests.CommBDifferential
// Imports: public import Init public meta import Init public import Impl.JSON public import Spec.Semantics public import Lean.Data.Json.Printer
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
lean_object* lean_string_utf8_byte_size(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_String_Slice_trimAscii(lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
lean_object* l_String_splitOnAux(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_toNat_x3f(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_decodeBDS(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Spec_decodeBDS(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_Semantics_commB(lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Spec_instDecidableEqPayloadRecord_decEq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Spec_Semantics_commB(lean_object*, lean_object*);
uint8_t lp_lean1090_Lean1090_Spec_Semantics_instDecidableEqPayload_decEq(lean_object*, lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* lean_string_push(lean_object*, uint32_t);
lean_object* lean_get_stdout();
lean_object* lp_lean1090_Lean1090_Impl_JSON_commB(uint8_t, lean_object*, lean_object*, lean_object*);
lean_object* lean_get_stdin();
LEAN_EXPORT uint8_t lp_lean1090_Option_instBEq_beq___at___00__private_Tests_CommBDifferential_0__check_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Option_instBEq_beq___at___00__private_Tests_CommBDifferential_0__check_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "expected decimal register and payload"};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__0 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__0_value;
static const lean_ctor_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__0_value)}};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__1 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__1_value;
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = " "};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__2 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__2_value;
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "invalid register"};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__3 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__3_value;
static const lean_ctor_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__3_value)}};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__4 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__4_value;
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "invalid payload"};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__5 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__5_value;
static const lean_ctor_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__5_value)}};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__6 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__6_value;
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "decoder_refines"};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__7 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__7_value;
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "meaning_refines"};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__8 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__8_value;
static const lean_string_object lp_lean1090___private_Tests_CommBDifferential_0__check___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "oracle"};
static const lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___closed__9 = (const lean_object*)&lp_lean1090___private_Tests_CommBDifferential_0__check___closed__9_value;
LEAN_EXPORT lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Option_instBEq_beq___at___00__private_Tests_CommBDifferential_0__check_spec__0(lean_object* v_x_1_, lean_object* v_x_2_){
_start:
{
if (lean_obj_tag(v_x_1_) == 0)
{
if (lean_obj_tag(v_x_2_) == 0)
{
uint8_t v___x_3_; 
v___x_3_ = 1;
return v___x_3_;
}
else
{
uint8_t v___x_4_; 
lean_dec_ref_known(v_x_2_, 1);
v___x_4_ = 0;
return v___x_4_;
}
}
else
{
if (lean_obj_tag(v_x_2_) == 0)
{
uint8_t v___x_5_; 
lean_dec_ref_known(v_x_1_, 1);
v___x_5_ = 0;
return v___x_5_;
}
else
{
lean_object* v_val_6_; lean_object* v_val_7_; uint8_t v___x_8_; 
v_val_6_ = lean_ctor_get(v_x_1_, 0);
lean_inc(v_val_6_);
lean_dec_ref_known(v_x_1_, 1);
v_val_7_ = lean_ctor_get(v_x_2_, 0);
lean_inc(v_val_7_);
lean_dec_ref_known(v_x_2_, 1);
v___x_8_ = lp_lean1090_Lean1090_Spec_instDecidableEqPayloadRecord_decEq(v_val_6_, v_val_7_);
return v___x_8_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Option_instBEq_beq___at___00__private_Tests_CommBDifferential_0__check_spec__0___boxed(lean_object* v_x_9_, lean_object* v_x_10_){
_start:
{
uint8_t v_res_11_; lean_object* v_r_12_; 
v_res_11_ = lp_lean1090_Option_instBEq_beq___at___00__private_Tests_CommBDifferential_0__check_spec__0(v_x_9_, v_x_10_);
v_r_12_ = lean_box(v_res_11_);
return v_r_12_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1_spec__1(lean_object* v_s_13_){
_start:
{
lean_object* v___x_15_; lean_object* v_putStr_16_; lean_object* v___x_17_; 
v___x_15_ = lean_get_stdout();
v_putStr_16_ = lean_ctor_get(v___x_15_, 4);
lean_inc_ref(v_putStr_16_);
lean_dec_ref(v___x_15_);
v___x_17_ = lean_apply_2(v_putStr_16_, v_s_13_, lean_box(0));
return v___x_17_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1_spec__1___boxed(lean_object* v_s_18_, lean_object* v_a_19_){
_start:
{
lean_object* v_res_20_; 
v_res_20_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1_spec__1(v_s_18_);
return v_res_20_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1(lean_object* v_s_21_){
_start:
{
uint32_t v___x_23_; lean_object* v___x_24_; lean_object* v___x_25_; 
v___x_23_ = 10;
v___x_24_ = lean_string_push(v_s_21_, v___x_23_);
v___x_25_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1_spec__1(v___x_24_);
return v___x_25_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1___boxed(lean_object* v_s_26_, lean_object* v_a_27_){
_start:
{
lean_object* v_res_28_; 
v_res_28_ = lp_lean1090_IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1(v_s_26_);
return v_res_28_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check(lean_object* v_line_42_){
_start:
{
lean_object* v___x_47_; lean_object* v___x_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; 
v___x_47_ = lean_unsigned_to_nat(0u);
v___x_48_ = lean_string_utf8_byte_size(v_line_42_);
v___x_49_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_49_, 0, v_line_42_);
lean_ctor_set(v___x_49_, 1, v___x_47_);
lean_ctor_set(v___x_49_, 2, v___x_48_);
v___x_50_ = l_String_Slice_trimAscii(v___x_49_);
v___x_51_ = l_String_Slice_toString(v___x_50_);
lean_dec_ref(v___x_50_);
v___x_52_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__2));
v___x_53_ = lean_box(0);
v___x_54_ = l_String_splitOnAux(v___x_51_, v___x_52_, v___x_47_, v___x_47_, v___x_47_, v___x_53_);
lean_dec_ref(v___x_51_);
if (lean_obj_tag(v___x_54_) == 1)
{
lean_object* v_tail_55_; 
v_tail_55_ = lean_ctor_get(v___x_54_, 1);
lean_inc(v_tail_55_);
if (lean_obj_tag(v_tail_55_) == 1)
{
lean_object* v_tail_56_; 
v_tail_56_ = lean_ctor_get(v_tail_55_, 1);
if (lean_obj_tag(v_tail_56_) == 0)
{
lean_object* v_head_57_; lean_object* v___x_59_; uint8_t v_isShared_60_; uint8_t v_isSharedCheck_116_; 
v_head_57_ = lean_ctor_get(v___x_54_, 0);
v_isSharedCheck_116_ = !lean_is_exclusive(v___x_54_);
if (v_isSharedCheck_116_ == 0)
{
lean_object* v_unused_117_; 
v_unused_117_ = lean_ctor_get(v___x_54_, 1);
lean_dec(v_unused_117_);
v___x_59_ = v___x_54_;
v_isShared_60_ = v_isSharedCheck_116_;
goto v_resetjp_58_;
}
else
{
lean_inc(v_head_57_);
lean_dec(v___x_54_);
v___x_59_ = lean_box(0);
v_isShared_60_ = v_isSharedCheck_116_;
goto v_resetjp_58_;
}
v_resetjp_58_:
{
lean_object* v_head_61_; lean_object* v___x_63_; uint8_t v_isShared_64_; uint8_t v_isSharedCheck_114_; 
v_head_61_ = lean_ctor_get(v_tail_55_, 0);
v_isSharedCheck_114_ = !lean_is_exclusive(v_tail_55_);
if (v_isSharedCheck_114_ == 0)
{
lean_object* v_unused_115_; 
v_unused_115_ = lean_ctor_get(v_tail_55_, 1);
lean_dec(v_unused_115_);
v___x_63_ = v_tail_55_;
v_isShared_64_ = v_isSharedCheck_114_;
goto v_resetjp_62_;
}
else
{
lean_inc(v_head_61_);
lean_dec(v_tail_55_);
v___x_63_ = lean_box(0);
v_isShared_64_ = v_isSharedCheck_114_;
goto v_resetjp_62_;
}
v_resetjp_62_:
{
lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_67_; 
v___x_65_ = lean_string_utf8_byte_size(v_head_57_);
v___x_66_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_66_, 0, v_head_57_);
lean_ctor_set(v___x_66_, 1, v___x_47_);
lean_ctor_set(v___x_66_, 2, v___x_65_);
v___x_67_ = l_String_Slice_toNat_x3f(v___x_66_);
lean_dec_ref_known(v___x_66_, 3);
if (lean_obj_tag(v___x_67_) == 0)
{
lean_object* v___x_68_; lean_object* v___x_69_; 
lean_del_object(v___x_63_);
lean_dec(v_head_61_);
lean_del_object(v___x_59_);
v___x_68_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__4));
v___x_69_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_69_, 0, v___x_68_);
return v___x_69_;
}
else
{
lean_object* v_val_70_; lean_object* v___x_72_; uint8_t v_isShared_73_; uint8_t v_isSharedCheck_113_; 
v_val_70_ = lean_ctor_get(v___x_67_, 0);
v_isSharedCheck_113_ = !lean_is_exclusive(v___x_67_);
if (v_isSharedCheck_113_ == 0)
{
v___x_72_ = v___x_67_;
v_isShared_73_ = v_isSharedCheck_113_;
goto v_resetjp_71_;
}
else
{
lean_inc(v_val_70_);
lean_dec(v___x_67_);
v___x_72_ = lean_box(0);
v_isShared_73_ = v_isSharedCheck_113_;
goto v_resetjp_71_;
}
v_resetjp_71_:
{
lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; 
v___x_74_ = lean_string_utf8_byte_size(v_head_61_);
v___x_75_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_75_, 0, v_head_61_);
lean_ctor_set(v___x_75_, 1, v___x_47_);
lean_ctor_set(v___x_75_, 2, v___x_74_);
v___x_76_ = l_String_Slice_toNat_x3f(v___x_75_);
lean_dec_ref_known(v___x_75_, 3);
if (lean_obj_tag(v___x_76_) == 0)
{
lean_object* v___x_77_; lean_object* v___x_79_; 
lean_dec(v_val_70_);
lean_del_object(v___x_63_);
lean_del_object(v___x_59_);
v___x_77_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__6));
if (v_isShared_73_ == 0)
{
lean_ctor_set(v___x_72_, 0, v___x_77_);
v___x_79_ = v___x_72_;
goto v_reusejp_78_;
}
else
{
lean_object* v_reuseFailAlloc_80_; 
v_reuseFailAlloc_80_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_80_, 0, v___x_77_);
v___x_79_ = v_reuseFailAlloc_80_;
goto v_reusejp_78_;
}
v_reusejp_78_:
{
return v___x_79_;
}
}
else
{
lean_object* v_val_81_; lean_object* v_actual_82_; lean_object* v_reference_83_; lean_object* v_meaning_84_; lean_object* v___y_86_; 
lean_del_object(v___x_72_);
v_val_81_ = lean_ctor_get(v___x_76_, 0);
lean_inc(v_val_81_);
lean_dec_ref_known(v___x_76_, 1);
lean_inc_n(v_val_70_, 2);
v_actual_82_ = lp_lean1090_Lean1090_Impl_decodeBDS(v_val_70_, v_val_81_);
v_reference_83_ = lp_lean1090_Lean1090_Spec_decodeBDS(v_val_70_, v_val_81_);
v_meaning_84_ = lp_lean1090_Lean1090_Impl_Semantics_commB(v_val_70_, v_val_81_);
if (lean_obj_tag(v_actual_82_) == 0)
{
lean_object* v___x_108_; 
v___x_108_ = lean_box(0);
v___y_86_ = v___x_108_;
goto v___jp_85_;
}
else
{
lean_object* v_val_109_; uint8_t v___x_110_; lean_object* v___x_111_; lean_object* v___x_112_; 
v_val_109_ = lean_ctor_get(v_actual_82_, 0);
lean_inc(v_val_109_);
v___x_110_ = 1;
lean_inc_ref(v_meaning_84_);
v___x_111_ = lp_lean1090_Lean1090_Impl_JSON_commB(v___x_110_, v_val_70_, v_val_109_, v_meaning_84_);
v___x_112_ = l_Lean_Json_mkObj(v___x_111_);
lean_dec(v___x_111_);
v___y_86_ = v___x_112_;
goto v___jp_85_;
}
v___jp_85_:
{
lean_object* v___x_87_; uint8_t v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; uint8_t v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_99_; 
v___x_87_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__7));
v___x_88_ = lp_lean1090_Option_instBEq_beq___at___00__private_Tests_CommBDifferential_0__check_spec__0(v_actual_82_, v_reference_83_);
v___x_89_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_89_, 0, v___x_88_);
v___x_90_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_90_, 0, v___x_87_);
lean_ctor_set(v___x_90_, 1, v___x_89_);
v___x_91_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__8));
v___x_92_ = lp_lean1090_Lean1090_Spec_Semantics_commB(v_val_70_, v_val_81_);
lean_dec(v_val_81_);
lean_dec(v_val_70_);
v___x_93_ = lp_lean1090_Lean1090_Spec_Semantics_instDecidableEqPayload_decEq(v_meaning_84_, v___x_92_);
v___x_94_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_94_, 0, v___x_93_);
v___x_95_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_95_, 0, v___x_91_);
lean_ctor_set(v___x_95_, 1, v___x_94_);
v___x_96_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__9));
v___x_97_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_97_, 0, v___x_96_);
lean_ctor_set(v___x_97_, 1, v___y_86_);
if (v_isShared_64_ == 0)
{
lean_ctor_set(v___x_63_, 1, v___x_53_);
lean_ctor_set(v___x_63_, 0, v___x_97_);
v___x_99_ = v___x_63_;
goto v_reusejp_98_;
}
else
{
lean_object* v_reuseFailAlloc_107_; 
v_reuseFailAlloc_107_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_107_, 0, v___x_97_);
lean_ctor_set(v_reuseFailAlloc_107_, 1, v___x_53_);
v___x_99_ = v_reuseFailAlloc_107_;
goto v_reusejp_98_;
}
v_reusejp_98_:
{
lean_object* v___x_101_; 
if (v_isShared_60_ == 0)
{
lean_ctor_set(v___x_59_, 1, v___x_99_);
lean_ctor_set(v___x_59_, 0, v___x_95_);
v___x_101_ = v___x_59_;
goto v_reusejp_100_;
}
else
{
lean_object* v_reuseFailAlloc_106_; 
v_reuseFailAlloc_106_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_106_, 0, v___x_95_);
lean_ctor_set(v_reuseFailAlloc_106_, 1, v___x_99_);
v___x_101_ = v_reuseFailAlloc_106_;
goto v_reusejp_100_;
}
v_reusejp_100_:
{
lean_object* v___x_102_; lean_object* v___x_103_; lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_102_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_102_, 0, v___x_90_);
lean_ctor_set(v___x_102_, 1, v___x_101_);
v___x_103_ = l_Lean_Json_mkObj(v___x_102_);
lean_dec_ref_known(v___x_102_, 2);
v___x_104_ = l_Lean_Json_compress(v___x_103_);
v___x_105_ = lp_lean1090_IO_println___at___00__private_Tests_CommBDifferential_0__check_spec__1(v___x_104_);
return v___x_105_;
}
}
}
}
}
}
}
}
}
else
{
lean_dec_ref_known(v_tail_55_, 2);
lean_dec_ref_known(v___x_54_, 2);
goto v___jp_44_;
}
}
else
{
lean_dec_ref_known(v___x_54_, 2);
lean_dec(v_tail_55_);
goto v___jp_44_;
}
}
else
{
lean_dec(v___x_54_);
goto v___jp_44_;
}
v___jp_44_:
{
lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_45_ = ((lean_object*)(lp_lean1090___private_Tests_CommBDifferential_0__check___closed__1));
v___x_46_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_46_, 0, v___x_45_);
return v___x_46_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Tests_CommBDifferential_0__check___boxed(lean_object* v_line_118_, lean_object* v_a_119_){
_start:
{
lean_object* v_res_120_; 
v_res_120_ = lp_lean1090___private_Tests_CommBDifferential_0__check(v_line_118_);
return v_res_120_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg(lean_object* v_val_121_){
_start:
{
lean_object* v_getLine_123_; lean_object* v___x_124_; lean_object* v___x_125_; 
v_getLine_123_ = lean_ctor_get(v_val_121_, 3);
v___x_124_ = lean_box(0);
lean_inc_ref(v_getLine_123_);
v___x_125_ = lean_apply_1(v_getLine_123_, lean_box(0));
if (lean_obj_tag(v___x_125_) == 0)
{
lean_object* v_a_126_; lean_object* v___x_128_; uint8_t v_isShared_129_; uint8_t v_isSharedCheck_144_; 
v_a_126_ = lean_ctor_get(v___x_125_, 0);
v_isSharedCheck_144_ = !lean_is_exclusive(v___x_125_);
if (v_isSharedCheck_144_ == 0)
{
v___x_128_ = v___x_125_;
v_isShared_129_ = v_isSharedCheck_144_;
goto v_resetjp_127_;
}
else
{
lean_inc(v_a_126_);
lean_dec(v___x_125_);
v___x_128_ = lean_box(0);
v_isShared_129_ = v_isSharedCheck_144_;
goto v_resetjp_127_;
}
v_resetjp_127_:
{
lean_object* v___x_130_; lean_object* v___x_131_; uint8_t v___x_132_; 
v___x_130_ = lean_string_utf8_byte_size(v_a_126_);
v___x_131_ = lean_unsigned_to_nat(0u);
v___x_132_ = lean_nat_dec_eq(v___x_130_, v___x_131_);
if (v___x_132_ == 0)
{
lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; uint8_t v___x_137_; 
lean_del_object(v___x_128_);
lean_inc(v_a_126_);
v___x_133_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_133_, 0, v_a_126_);
lean_ctor_set(v___x_133_, 1, v___x_131_);
lean_ctor_set(v___x_133_, 2, v___x_130_);
v___x_134_ = l_String_Slice_trimAscii(v___x_133_);
v___x_135_ = l_String_Slice_toString(v___x_134_);
lean_dec_ref(v___x_134_);
v___x_136_ = lean_string_utf8_byte_size(v___x_135_);
lean_dec_ref(v___x_135_);
v___x_137_ = lean_nat_dec_eq(v___x_136_, v___x_131_);
if (v___x_137_ == 0)
{
lean_object* v___x_138_; 
v___x_138_ = lp_lean1090___private_Tests_CommBDifferential_0__check(v_a_126_);
if (lean_obj_tag(v___x_138_) == 0)
{
lean_dec_ref_known(v___x_138_, 1);
goto _start;
}
else
{
lean_dec_ref(v_val_121_);
return v___x_138_;
}
}
else
{
lean_dec(v_a_126_);
goto _start;
}
}
else
{
lean_object* v___x_142_; 
lean_dec(v_a_126_);
lean_dec_ref(v_val_121_);
if (v_isShared_129_ == 0)
{
lean_ctor_set(v___x_128_, 0, v___x_124_);
v___x_142_ = v___x_128_;
goto v_reusejp_141_;
}
else
{
lean_object* v_reuseFailAlloc_143_; 
v_reuseFailAlloc_143_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_143_, 0, v___x_124_);
v___x_142_ = v_reuseFailAlloc_143_;
goto v_reusejp_141_;
}
v_reusejp_141_:
{
return v___x_142_;
}
}
}
}
else
{
lean_object* v_a_145_; lean_object* v___x_147_; uint8_t v_isShared_148_; uint8_t v_isSharedCheck_152_; 
lean_dec_ref(v_val_121_);
v_a_145_ = lean_ctor_get(v___x_125_, 0);
v_isSharedCheck_152_ = !lean_is_exclusive(v___x_125_);
if (v_isSharedCheck_152_ == 0)
{
v___x_147_ = v___x_125_;
v_isShared_148_ = v_isSharedCheck_152_;
goto v_resetjp_146_;
}
else
{
lean_inc(v_a_145_);
lean_dec(v___x_125_);
v___x_147_ = lean_box(0);
v_isShared_148_ = v_isSharedCheck_152_;
goto v_resetjp_146_;
}
v_resetjp_146_:
{
lean_object* v___x_150_; 
if (v_isShared_148_ == 0)
{
v___x_150_ = v___x_147_;
goto v_reusejp_149_;
}
else
{
lean_object* v_reuseFailAlloc_151_; 
v_reuseFailAlloc_151_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_151_, 0, v_a_145_);
v___x_150_ = v_reuseFailAlloc_151_;
goto v_reusejp_149_;
}
v_reusejp_149_:
{
return v___x_150_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg___boxed(lean_object* v_val_153_, lean_object* v___y_154_){
_start:
{
lean_object* v_res_155_; 
v_res_155_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg(v_val_153_);
return v_res_155_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; 
v___x_157_ = lean_get_stdin();
v___x_158_ = lean_box(0);
v___x_159_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg(v___x_157_);
if (lean_obj_tag(v___x_159_) == 0)
{
lean_object* v___x_161_; uint8_t v_isShared_162_; uint8_t v_isSharedCheck_166_; 
v_isSharedCheck_166_ = !lean_is_exclusive(v___x_159_);
if (v_isSharedCheck_166_ == 0)
{
lean_object* v_unused_167_; 
v_unused_167_ = lean_ctor_get(v___x_159_, 0);
lean_dec(v_unused_167_);
v___x_161_ = v___x_159_;
v_isShared_162_ = v_isSharedCheck_166_;
goto v_resetjp_160_;
}
else
{
lean_dec(v___x_159_);
v___x_161_ = lean_box(0);
v_isShared_162_ = v_isSharedCheck_166_;
goto v_resetjp_160_;
}
v_resetjp_160_:
{
lean_object* v___x_164_; 
if (v_isShared_162_ == 0)
{
lean_ctor_set(v___x_161_, 0, v___x_158_);
v___x_164_ = v___x_161_;
goto v_reusejp_163_;
}
else
{
lean_object* v_reuseFailAlloc_165_; 
v_reuseFailAlloc_165_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_165_, 0, v___x_158_);
v___x_164_ = v_reuseFailAlloc_165_;
goto v_reusejp_163_;
}
v_reusejp_163_:
{
return v___x_164_;
}
}
}
else
{
return v___x_159_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object* v_a_168_){
_start:
{
lean_object* v_res_169_; 
v_res_169_ = _lean_main();
return v_res_169_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0(lean_object* v_val_170_, lean_object* v_inst_171_, lean_object* v_a_172_){
_start:
{
lean_object* v___x_174_; 
v___x_174_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___redArg(v_val_170_);
return v___x_174_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0___boxed(lean_object* v_val_175_, lean_object* v_inst_176_, lean_object* v_a_177_, lean_object* v___y_178_){
_start:
{
lean_object* v_res_179_; 
v_res_179_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__0(v_val_175_, v_inst_176_, v_a_177_);
return v_res_179_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_JSON(uint8_t builtin);
lean_object* initialize_lean1090_Spec_Semantics(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_Printer(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_Tests_CommBDifferential(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Impl_JSON(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_lean1090_Spec_Semantics(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Data_Json_Printer(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif
lean_object* run_main(int argc, char ** argv) {
    return _lean_main();
}
int main(int argc, char ** argv) {
#if defined(WIN32) || defined(_WIN32)
  SetErrorMode(SEM_FAILCRITICALERRORS);
  SetConsoleOutputCP(CP_UTF8);
#endif
  lean_object* res;
  argv = lean_setup_args(argc, argv);
  res = initialize_lean1090_Tests_CommBDifferential(1 /* builtin */);
  lean_io_mark_end_initialization();
  if (lean_io_result_is_ok(res)) {
    lean_dec_ref(res);
    lean_init_task_manager();
    res = lean_run_main(&run_main, argc, argv);
  }
  lean_finalize_task_manager();
  if (lean_io_result_is_ok(res)) {
    int ret = 0;
    lean_dec_ref(res);
    return ret;
  } else {
    lean_io_result_show_error(res);
    lean_dec_ref(res);
    return 1;
  }
}
#ifdef __cplusplus
}
#endif
