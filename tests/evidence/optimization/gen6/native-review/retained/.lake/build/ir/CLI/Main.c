// Lean compiler output
// Module: CLI.Main
// Imports: public import Init public meta import Init public import Impl.JSON public import Lean.Data.Json.Printer
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
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* lean_string_push(lean_object*, uint32_t);
lean_object* lean_get_stdout();
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_String_Slice_trimAscii(lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
lean_object* lean_string_data(lean_object*);
uint8_t lean_uint32_dec_le(uint32_t, uint32_t);
lean_object* lean_uint32_to_nat(uint32_t);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
uint8_t lean_uint8_of_nat(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_decode(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_JSON_message(uint8_t, lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_decodePrefix(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lp_lean1090_Lean1090_Impl_JSON_integer(lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lean_int_sub(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_uint8_to_nat(uint8_t);
lean_object* lp_lean1090_Lean1090_Impl_JSON_digits(lean_object*, lean_object*, lean_object*);
lean_object* l_List_foldl___at___00Std_Time_GenericFormat_format_spec__1(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
lean_object* lean_get_stdin();
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__nibble(uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__nibble___boxed(lean_object*);
static const lean_ctor_object lp_lean1090___private_CLI_Main_0__hexBytes___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090___private_CLI_Main_0__hexBytes___closed__0 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__hexBytes___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__hexBytes(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_CLI_Main_0__emit_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_CLI_Main_0__emit_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_CLI_Main_0__emit_spec__0_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_CLI_Main_0__emit_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_CLI_Main_0__emit_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__0 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__0_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "invalid hexadecimal input"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__1 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__1_value;
static const lean_ctor_object lp_lean1090___private_CLI_Main_0__emit___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__1_value)}};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__2 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__2_value;
static const lean_ctor_object lp_lean1090___private_CLI_Main_0__emit___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__0_value),((lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__2_value)}};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__3 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__3_value;
static const lean_ctor_object lp_lean1090___private_CLI_Main_0__emit___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__3_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__4 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__4_value;
static lean_once_cell_t lp_lean1090___private_CLI_Main_0__emit___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__5;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "--diagnostic"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__6 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__6_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "--oracle-view"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__7 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__7_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "standard"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__8 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__8_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "oracle"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__9 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__9_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "crc"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__10 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__10_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "consumed"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__11 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__11_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "remainder"};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__12 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__12_value;
static const lean_string_object lp_lean1090___private_CLI_Main_0__emit___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* lp_lean1090___private_CLI_Main_0__emit___closed__13 = (const lean_object*)&lp_lean1090___private_CLI_Main_0__emit___closed__13_value;
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__emit(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__emit___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg(lean_object*, uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_lean1090_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "--standard"};
static const lean_object* lp_lean1090_main___closed__0 = (const lean_object*)&lp_lean1090_main___closed__0_value;
LEAN_EXPORT lean_object* lp_lean1090_main___boxed__const__1;
LEAN_EXPORT lean_object* _lean_main(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__nibble(uint32_t v_c_1_){
_start:
{
uint32_t v___x_26_; uint8_t v___x_27_; 
v___x_26_ = 48;
v___x_27_ = lean_uint32_dec_le(v___x_26_, v_c_1_);
if (v___x_27_ == 0)
{
goto v___jp_15_;
}
else
{
uint32_t v___x_28_; uint8_t v___x_29_; 
v___x_28_ = 57;
v___x_29_ = lean_uint32_dec_le(v_c_1_, v___x_28_);
if (v___x_29_ == 0)
{
goto v___jp_15_;
}
else
{
lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; lean_object* v___x_33_; 
v___x_30_ = lean_uint32_to_nat(v_c_1_);
v___x_31_ = lean_unsigned_to_nat(48u);
v___x_32_ = lean_nat_sub(v___x_30_, v___x_31_);
lean_dec(v___x_30_);
v___x_33_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_33_, 0, v___x_32_);
return v___x_33_;
}
}
v___jp_2_:
{
uint32_t v___x_3_; uint8_t v___x_4_; 
v___x_3_ = 65;
v___x_4_ = lean_uint32_dec_le(v___x_3_, v_c_1_);
if (v___x_4_ == 0)
{
lean_object* v___x_5_; 
v___x_5_ = lean_box(0);
return v___x_5_;
}
else
{
uint32_t v___x_6_; uint8_t v___x_7_; 
v___x_6_ = 70;
v___x_7_ = lean_uint32_dec_le(v_c_1_, v___x_6_);
if (v___x_7_ == 0)
{
lean_object* v___x_8_; 
v___x_8_ = lean_box(0);
return v___x_8_;
}
else
{
lean_object* v___x_9_; lean_object* v___x_10_; lean_object* v___x_11_; lean_object* v___x_12_; lean_object* v___x_13_; lean_object* v___x_14_; 
v___x_9_ = lean_uint32_to_nat(v_c_1_);
v___x_10_ = lean_unsigned_to_nat(65u);
v___x_11_ = lean_nat_sub(v___x_9_, v___x_10_);
lean_dec(v___x_9_);
v___x_12_ = lean_unsigned_to_nat(10u);
v___x_13_ = lean_nat_add(v___x_11_, v___x_12_);
lean_dec(v___x_11_);
v___x_14_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_14_, 0, v___x_13_);
return v___x_14_;
}
}
}
v___jp_15_:
{
uint32_t v___x_16_; uint8_t v___x_17_; 
v___x_16_ = 97;
v___x_17_ = lean_uint32_dec_le(v___x_16_, v_c_1_);
if (v___x_17_ == 0)
{
goto v___jp_2_;
}
else
{
uint32_t v___x_18_; uint8_t v___x_19_; 
v___x_18_ = 102;
v___x_19_ = lean_uint32_dec_le(v_c_1_, v___x_18_);
if (v___x_19_ == 0)
{
goto v___jp_2_;
}
else
{
lean_object* v___x_20_; lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v___x_24_; lean_object* v___x_25_; 
v___x_20_ = lean_uint32_to_nat(v_c_1_);
v___x_21_ = lean_unsigned_to_nat(97u);
v___x_22_ = lean_nat_sub(v___x_20_, v___x_21_);
lean_dec(v___x_20_);
v___x_23_ = lean_unsigned_to_nat(10u);
v___x_24_ = lean_nat_add(v___x_22_, v___x_23_);
lean_dec(v___x_22_);
v___x_25_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_25_, 0, v___x_24_);
return v___x_25_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__nibble___boxed(lean_object* v_c_34_){
_start:
{
uint32_t v_c_boxed_35_; lean_object* v_res_36_; 
v_c_boxed_35_ = lean_unbox_uint32(v_c_34_);
lean_dec(v_c_34_);
v_res_36_ = lp_lean1090___private_CLI_Main_0__nibble(v_c_boxed_35_);
return v_res_36_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__hexBytes(lean_object* v_x_39_){
_start:
{
if (lean_obj_tag(v_x_39_) == 0)
{
lean_object* v___x_40_; 
v___x_40_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__hexBytes___closed__0));
return v___x_40_;
}
else
{
lean_object* v_tail_41_; 
v_tail_41_ = lean_ctor_get(v_x_39_, 1);
lean_inc(v_tail_41_);
if (lean_obj_tag(v_tail_41_) == 1)
{
lean_object* v_head_42_; lean_object* v_head_43_; lean_object* v_tail_44_; lean_object* v___x_46_; uint8_t v_isShared_47_; uint8_t v_isSharedCheck_73_; 
v_head_42_ = lean_ctor_get(v_x_39_, 0);
lean_inc(v_head_42_);
lean_dec_ref_known(v_x_39_, 2);
v_head_43_ = lean_ctor_get(v_tail_41_, 0);
v_tail_44_ = lean_ctor_get(v_tail_41_, 1);
v_isSharedCheck_73_ = !lean_is_exclusive(v_tail_41_);
if (v_isSharedCheck_73_ == 0)
{
v___x_46_ = v_tail_41_;
v_isShared_47_ = v_isSharedCheck_73_;
goto v_resetjp_45_;
}
else
{
lean_inc(v_tail_44_);
lean_inc(v_head_43_);
lean_dec(v_tail_41_);
v___x_46_ = lean_box(0);
v_isShared_47_ = v_isSharedCheck_73_;
goto v_resetjp_45_;
}
v_resetjp_45_:
{
uint32_t v___x_48_; lean_object* v___x_49_; 
v___x_48_ = lean_unbox_uint32(v_head_42_);
lean_dec(v_head_42_);
v___x_49_ = lp_lean1090___private_CLI_Main_0__nibble(v___x_48_);
if (lean_obj_tag(v___x_49_) == 0)
{
lean_object* v___x_50_; 
lean_del_object(v___x_46_);
lean_dec(v_tail_44_);
lean_dec(v_head_43_);
v___x_50_ = lean_box(0);
return v___x_50_;
}
else
{
lean_object* v_val_51_; uint32_t v___x_52_; lean_object* v___x_53_; 
v_val_51_ = lean_ctor_get(v___x_49_, 0);
lean_inc(v_val_51_);
lean_dec_ref_known(v___x_49_, 1);
v___x_52_ = lean_unbox_uint32(v_head_43_);
lean_dec(v_head_43_);
v___x_53_ = lp_lean1090___private_CLI_Main_0__nibble(v___x_52_);
if (lean_obj_tag(v___x_53_) == 0)
{
lean_object* v___x_54_; 
lean_dec(v_val_51_);
lean_del_object(v___x_46_);
lean_dec(v_tail_44_);
v___x_54_ = lean_box(0);
return v___x_54_;
}
else
{
lean_object* v_val_55_; lean_object* v___x_56_; 
v_val_55_ = lean_ctor_get(v___x_53_, 0);
lean_inc(v_val_55_);
lean_dec_ref_known(v___x_53_, 1);
v___x_56_ = lp_lean1090___private_CLI_Main_0__hexBytes(v_tail_44_);
if (lean_obj_tag(v___x_56_) == 0)
{
lean_dec(v_val_55_);
lean_dec(v_val_51_);
lean_del_object(v___x_46_);
return v___x_56_;
}
else
{
lean_object* v_val_57_; lean_object* v___x_59_; uint8_t v_isShared_60_; uint8_t v_isSharedCheck_72_; 
v_val_57_ = lean_ctor_get(v___x_56_, 0);
v_isSharedCheck_72_ = !lean_is_exclusive(v___x_56_);
if (v_isSharedCheck_72_ == 0)
{
v___x_59_ = v___x_56_;
v_isShared_60_ = v_isSharedCheck_72_;
goto v_resetjp_58_;
}
else
{
lean_inc(v_val_57_);
lean_dec(v___x_56_);
v___x_59_ = lean_box(0);
v_isShared_60_ = v_isSharedCheck_72_;
goto v_resetjp_58_;
}
v_resetjp_58_:
{
lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; uint8_t v___x_64_; lean_object* v___x_65_; lean_object* v___x_67_; 
v___x_61_ = lean_unsigned_to_nat(16u);
v___x_62_ = lean_nat_mul(v_val_51_, v___x_61_);
lean_dec(v_val_51_);
v___x_63_ = lean_nat_add(v___x_62_, v_val_55_);
lean_dec(v_val_55_);
lean_dec(v___x_62_);
v___x_64_ = lean_uint8_of_nat(v___x_63_);
lean_dec(v___x_63_);
v___x_65_ = lean_box(v___x_64_);
if (v_isShared_47_ == 0)
{
lean_ctor_set(v___x_46_, 1, v_val_57_);
lean_ctor_set(v___x_46_, 0, v___x_65_);
v___x_67_ = v___x_46_;
goto v_reusejp_66_;
}
else
{
lean_object* v_reuseFailAlloc_71_; 
v_reuseFailAlloc_71_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_71_, 0, v___x_65_);
lean_ctor_set(v_reuseFailAlloc_71_, 1, v_val_57_);
v___x_67_ = v_reuseFailAlloc_71_;
goto v_reusejp_66_;
}
v_reusejp_66_:
{
lean_object* v___x_69_; 
if (v_isShared_60_ == 0)
{
lean_ctor_set(v___x_59_, 0, v___x_67_);
v___x_69_ = v___x_59_;
goto v_reusejp_68_;
}
else
{
lean_object* v_reuseFailAlloc_70_; 
v_reuseFailAlloc_70_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_70_, 0, v___x_67_);
v___x_69_ = v_reuseFailAlloc_70_;
goto v_reusejp_68_;
}
v_reusejp_68_:
{
return v___x_69_;
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
lean_object* v___x_74_; 
lean_dec_ref_known(v_x_39_, 2);
lean_dec(v_tail_41_);
v___x_74_ = lean_box(0);
return v___x_74_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_mapTR_loop___at___00__private_CLI_Main_0__emit_spec__1(lean_object* v_a_75_, lean_object* v_a_76_){
_start:
{
if (lean_obj_tag(v_a_75_) == 0)
{
lean_object* v___x_77_; 
v___x_77_ = l_List_reverse___redArg(v_a_76_);
return v___x_77_;
}
else
{
lean_object* v_head_78_; lean_object* v_tail_79_; lean_object* v___x_81_; uint8_t v_isShared_82_; uint8_t v_isSharedCheck_92_; 
v_head_78_ = lean_ctor_get(v_a_75_, 0);
v_tail_79_ = lean_ctor_get(v_a_75_, 1);
v_isSharedCheck_92_ = !lean_is_exclusive(v_a_75_);
if (v_isSharedCheck_92_ == 0)
{
v___x_81_ = v_a_75_;
v_isShared_82_ = v_isSharedCheck_92_;
goto v_resetjp_80_;
}
else
{
lean_inc(v_tail_79_);
lean_inc(v_head_78_);
lean_dec(v_a_75_);
v___x_81_ = lean_box(0);
v_isShared_82_ = v_isSharedCheck_92_;
goto v_resetjp_80_;
}
v_resetjp_80_:
{
lean_object* v___x_83_; lean_object* v___x_84_; uint8_t v___x_85_; lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_89_; 
v___x_83_ = lean_unsigned_to_nat(16u);
v___x_84_ = lean_unsigned_to_nat(2u);
v___x_85_ = lean_unbox(v_head_78_);
lean_dec(v_head_78_);
v___x_86_ = lean_uint8_to_nat(v___x_85_);
v___x_87_ = lp_lean1090_Lean1090_Impl_JSON_digits(v___x_83_, v___x_84_, v___x_86_);
if (v_isShared_82_ == 0)
{
lean_ctor_set(v___x_81_, 1, v_a_76_);
lean_ctor_set(v___x_81_, 0, v___x_87_);
v___x_89_ = v___x_81_;
goto v_reusejp_88_;
}
else
{
lean_object* v_reuseFailAlloc_91_; 
v_reuseFailAlloc_91_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_91_, 0, v___x_87_);
lean_ctor_set(v_reuseFailAlloc_91_, 1, v_a_76_);
v___x_89_ = v_reuseFailAlloc_91_;
goto v_reusejp_88_;
}
v_reusejp_88_:
{
v_a_75_ = v_tail_79_;
v_a_76_ = v___x_89_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_CLI_Main_0__emit_spec__0_spec__0(lean_object* v_s_93_){
_start:
{
lean_object* v___x_95_; lean_object* v_putStr_96_; lean_object* v___x_97_; 
v___x_95_ = lean_get_stdout();
v_putStr_96_ = lean_ctor_get(v___x_95_, 4);
lean_inc_ref(v_putStr_96_);
lean_dec_ref(v___x_95_);
v___x_97_ = lean_apply_2(v_putStr_96_, v_s_93_, lean_box(0));
return v___x_97_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_print___at___00IO_println___at___00__private_CLI_Main_0__emit_spec__0_spec__0___boxed(lean_object* v_s_98_, lean_object* v_a_99_){
_start:
{
lean_object* v_res_100_; 
v_res_100_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_CLI_Main_0__emit_spec__0_spec__0(v_s_98_);
return v_res_100_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_CLI_Main_0__emit_spec__0(lean_object* v_s_101_){
_start:
{
uint32_t v___x_103_; lean_object* v___x_104_; lean_object* v___x_105_; 
v___x_103_ = 10;
v___x_104_ = lean_string_push(v_s_101_, v___x_103_);
v___x_105_ = lp_lean1090_IO_print___at___00IO_println___at___00__private_CLI_Main_0__emit_spec__0_spec__0(v___x_104_);
return v___x_105_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_IO_println___at___00__private_CLI_Main_0__emit_spec__0___boxed(lean_object* v_s_106_, lean_object* v_a_107_){
_start:
{
lean_object* v_res_108_; 
v_res_108_ = lp_lean1090_IO_println___at___00__private_CLI_Main_0__emit_spec__0(v_s_106_);
return v_res_108_;
}
}
static lean_object* _init_lp_lean1090___private_CLI_Main_0__emit___closed__5(void){
_start:
{
lean_object* v___x_119_; lean_object* v___x_120_; 
v___x_119_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__4));
v___x_120_ = l_Lean_Json_mkObj(v___x_119_);
return v___x_120_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__emit(lean_object* v_mode_129_, lean_object* v_line_130_){
_start:
{
lean_object* v___y_133_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v_bytes_142_; 
v___x_136_ = lean_unsigned_to_nat(0u);
v___x_137_ = lean_string_utf8_byte_size(v_line_130_);
v___x_138_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_138_, 0, v_line_130_);
lean_ctor_set(v___x_138_, 1, v___x_136_);
lean_ctor_set(v___x_138_, 2, v___x_137_);
v___x_139_ = l_String_Slice_trimAscii(v___x_138_);
v___x_140_ = l_String_Slice_toString(v___x_139_);
lean_dec_ref(v___x_139_);
v___x_141_ = lean_string_data(v___x_140_);
v_bytes_142_ = lp_lean1090___private_CLI_Main_0__hexBytes(v___x_141_);
if (lean_obj_tag(v_bytes_142_) == 0)
{
lean_object* v___x_143_; 
v___x_143_ = lean_obj_once(&lp_lean1090___private_CLI_Main_0__emit___closed__5, &lp_lean1090___private_CLI_Main_0__emit___closed__5_once, _init_lp_lean1090___private_CLI_Main_0__emit___closed__5);
v___y_133_ = v___x_143_;
goto v___jp_132_;
}
else
{
lean_object* v_val_144_; lean_object* v___x_145_; uint8_t v___x_146_; 
v_val_144_ = lean_ctor_get(v_bytes_142_, 0);
lean_inc(v_val_144_);
lean_dec_ref_known(v_bytes_142_, 1);
v___x_145_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__6));
v___x_146_ = lean_string_dec_eq(v_mode_129_, v___x_145_);
if (v___x_146_ == 0)
{
lean_object* v___x_147_; 
v___x_147_ = lp_lean1090_Lean1090_Impl_decode(v_val_144_);
lean_dec(v_val_144_);
if (lean_obj_tag(v___x_147_) == 0)
{
lean_object* v___x_148_; 
v___x_148_ = lean_box(0);
v___y_133_ = v___x_148_;
goto v___jp_132_;
}
else
{
lean_object* v_val_149_; lean_object* v___x_150_; uint8_t v___x_151_; lean_object* v___x_152_; 
v_val_149_ = lean_ctor_get(v___x_147_, 0);
lean_inc(v_val_149_);
lean_dec_ref_known(v___x_147_, 1);
v___x_150_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__7));
v___x_151_ = lean_string_dec_eq(v_mode_129_, v___x_150_);
v___x_152_ = lp_lean1090_Lean1090_Impl_JSON_message(v___x_151_, v_val_149_);
v___y_133_ = v___x_152_;
goto v___jp_132_;
}
}
else
{
lean_object* v___x_153_; 
lean_inc(v_val_144_);
v___x_153_ = lp_lean1090_Lean1090_Impl_decodePrefix(v_val_144_);
if (lean_obj_tag(v___x_153_) == 0)
{
lean_object* v___x_154_; 
lean_dec(v_val_144_);
v___x_154_ = lean_box(0);
v___y_133_ = v___x_154_;
goto v___jp_132_;
}
else
{
lean_object* v_val_155_; lean_object* v___x_157_; uint8_t v_isShared_158_; uint8_t v_isSharedCheck_204_; 
v_val_155_ = lean_ctor_get(v___x_153_, 0);
v_isSharedCheck_204_ = !lean_is_exclusive(v___x_153_);
if (v_isSharedCheck_204_ == 0)
{
v___x_157_ = v___x_153_;
v_isShared_158_ = v_isSharedCheck_204_;
goto v_resetjp_156_;
}
else
{
lean_inc(v_val_155_);
lean_dec(v___x_153_);
v___x_157_ = lean_box(0);
v_isShared_158_ = v_isSharedCheck_204_;
goto v_resetjp_156_;
}
v_resetjp_156_:
{
lean_object* v_fst_159_; lean_object* v_decoded_160_; lean_object* v_snd_161_; lean_object* v___x_163_; uint8_t v_isShared_164_; uint8_t v_isSharedCheck_202_; 
v_fst_159_ = lean_ctor_get(v_val_155_, 0);
lean_inc(v_fst_159_);
v_decoded_160_ = lean_ctor_get(v_fst_159_, 1);
v_snd_161_ = lean_ctor_get(v_val_155_, 1);
v_isSharedCheck_202_ = !lean_is_exclusive(v_val_155_);
if (v_isSharedCheck_202_ == 0)
{
lean_object* v_unused_203_; 
v_unused_203_ = lean_ctor_get(v_val_155_, 0);
lean_dec(v_unused_203_);
v___x_163_ = v_val_155_;
v_isShared_164_ = v_isSharedCheck_202_;
goto v_resetjp_162_;
}
else
{
lean_inc(v_snd_161_);
lean_dec(v_val_155_);
v___x_163_ = lean_box(0);
v_isShared_164_ = v_isSharedCheck_202_;
goto v_resetjp_162_;
}
v_resetjp_162_:
{
lean_object* v_crc_165_; uint8_t v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_170_; 
v_crc_165_ = lean_ctor_get(v_decoded_160_, 0);
lean_inc(v_crc_165_);
v___x_166_ = 0;
lean_inc(v_fst_159_);
v___x_167_ = lp_lean1090_Lean1090_Impl_JSON_message(v___x_166_, v_fst_159_);
v___x_168_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__8));
if (v_isShared_164_ == 0)
{
lean_ctor_set(v___x_163_, 1, v___x_167_);
lean_ctor_set(v___x_163_, 0, v___x_168_);
v___x_170_ = v___x_163_;
goto v_reusejp_169_;
}
else
{
lean_object* v_reuseFailAlloc_201_; 
v_reuseFailAlloc_201_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_201_, 0, v___x_168_);
lean_ctor_set(v_reuseFailAlloc_201_, 1, v___x_167_);
v___x_170_ = v_reuseFailAlloc_201_;
goto v_reusejp_169_;
}
v_reusejp_169_:
{
lean_object* v___x_171_; lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; lean_object* v___x_177_; lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v___x_187_; lean_object* v___x_188_; lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v___x_192_; 
v___x_171_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__9));
v___x_172_ = lp_lean1090_Lean1090_Impl_JSON_message(v___x_146_, v_fst_159_);
v___x_173_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_173_, 0, v___x_171_);
lean_ctor_set(v___x_173_, 1, v___x_172_);
v___x_174_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__10));
v___x_175_ = lean_nat_to_int(v_crc_165_);
v___x_176_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_175_);
v___x_177_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_177_, 0, v___x_174_);
lean_ctor_set(v___x_177_, 1, v___x_176_);
v___x_178_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__11));
v___x_179_ = l_List_lengthTR___redArg(v_val_144_);
lean_dec(v_val_144_);
v___x_180_ = lean_nat_to_int(v___x_179_);
v___x_181_ = l_List_lengthTR___redArg(v_snd_161_);
v___x_182_ = lean_nat_to_int(v___x_181_);
v___x_183_ = lean_int_sub(v___x_180_, v___x_182_);
lean_dec(v___x_182_);
lean_dec(v___x_180_);
v___x_184_ = lp_lean1090_Lean1090_Impl_JSON_integer(v___x_183_);
v___x_185_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_185_, 0, v___x_178_);
lean_ctor_set(v___x_185_, 1, v___x_184_);
v___x_186_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__12));
v___x_187_ = lean_box(0);
v___x_188_ = lp_lean1090_List_mapTR_loop___at___00__private_CLI_Main_0__emit_spec__1(v_snd_161_, v___x_187_);
v___x_189_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__13));
v___x_190_ = l_List_foldl___at___00Std_Time_GenericFormat_format_spec__1(v___x_189_, v___x_188_);
lean_dec(v___x_188_);
if (v_isShared_158_ == 0)
{
lean_ctor_set_tag(v___x_157_, 3);
lean_ctor_set(v___x_157_, 0, v___x_190_);
v___x_192_ = v___x_157_;
goto v_reusejp_191_;
}
else
{
lean_object* v_reuseFailAlloc_200_; 
v_reuseFailAlloc_200_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_200_, 0, v___x_190_);
v___x_192_ = v_reuseFailAlloc_200_;
goto v_reusejp_191_;
}
v_reusejp_191_:
{
lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; 
v___x_193_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_193_, 0, v___x_186_);
lean_ctor_set(v___x_193_, 1, v___x_192_);
v___x_194_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_194_, 0, v___x_193_);
lean_ctor_set(v___x_194_, 1, v___x_187_);
v___x_195_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_195_, 0, v___x_185_);
lean_ctor_set(v___x_195_, 1, v___x_194_);
v___x_196_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_196_, 0, v___x_177_);
lean_ctor_set(v___x_196_, 1, v___x_195_);
v___x_197_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_197_, 0, v___x_173_);
lean_ctor_set(v___x_197_, 1, v___x_196_);
v___x_198_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_198_, 0, v___x_170_);
lean_ctor_set(v___x_198_, 1, v___x_197_);
v___x_199_ = l_Lean_Json_mkObj(v___x_198_);
lean_dec_ref_known(v___x_198_, 2);
v___y_133_ = v___x_199_;
goto v___jp_132_;
}
}
}
}
}
}
}
v___jp_132_:
{
lean_object* v___x_134_; lean_object* v___x_135_; 
v___x_134_ = l_Lean_Json_compress(v___y_133_);
v___x_135_ = lp_lean1090_IO_println___at___00__private_CLI_Main_0__emit_spec__0(v___x_134_);
return v___x_135_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_CLI_Main_0__emit___boxed(lean_object* v_mode_205_, lean_object* v_line_206_, lean_object* v_a_207_){
_start:
{
lean_object* v_res_208_; 
v_res_208_ = lp_lean1090___private_CLI_Main_0__emit(v_mode_205_, v_line_206_);
lean_dec_ref(v_mode_205_);
return v_res_208_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg(lean_object* v_fst_209_, lean_object* v_as_x27_210_, lean_object* v_b_211_){
_start:
{
if (lean_obj_tag(v_as_x27_210_) == 0)
{
lean_object* v___x_213_; 
v___x_213_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_213_, 0, v_b_211_);
return v___x_213_;
}
else
{
lean_object* v_head_214_; lean_object* v_tail_215_; lean_object* v___x_216_; lean_object* v___x_217_; 
v_head_214_ = lean_ctor_get(v_as_x27_210_, 0);
v_tail_215_ = lean_ctor_get(v_as_x27_210_, 1);
v___x_216_ = lean_box(0);
lean_inc(v_head_214_);
v___x_217_ = lp_lean1090___private_CLI_Main_0__emit(v_fst_209_, v_head_214_);
if (lean_obj_tag(v___x_217_) == 0)
{
lean_dec_ref_known(v___x_217_, 1);
v_as_x27_210_ = v_tail_215_;
v_b_211_ = v___x_216_;
goto _start;
}
else
{
return v___x_217_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg___boxed(lean_object* v_fst_219_, lean_object* v_as_x27_220_, lean_object* v_b_221_, lean_object* v___y_222_){
_start:
{
lean_object* v_res_223_; 
v_res_223_ = lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg(v_fst_219_, v_as_x27_220_, v_b_221_);
lean_dec(v_as_x27_220_);
lean_dec_ref(v_fst_219_);
return v_res_223_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg(lean_object* v_val_224_, uint8_t v___x_225_, lean_object* v_fst_226_){
_start:
{
lean_object* v_getLine_228_; lean_object* v___x_229_; lean_object* v___x_230_; 
v_getLine_228_ = lean_ctor_get(v_val_224_, 3);
v___x_229_ = lean_box(0);
lean_inc_ref(v_getLine_228_);
v___x_230_ = lean_apply_1(v_getLine_228_, lean_box(0));
if (lean_obj_tag(v___x_230_) == 0)
{
lean_object* v_a_231_; lean_object* v___x_233_; uint8_t v_isShared_234_; uint8_t v_isSharedCheck_250_; 
v_a_231_ = lean_ctor_get(v___x_230_, 0);
v_isSharedCheck_250_ = !lean_is_exclusive(v___x_230_);
if (v_isSharedCheck_250_ == 0)
{
v___x_233_ = v___x_230_;
v_isShared_234_ = v_isSharedCheck_250_;
goto v_resetjp_232_;
}
else
{
lean_inc(v_a_231_);
lean_dec(v___x_230_);
v___x_233_ = lean_box(0);
v_isShared_234_ = v_isSharedCheck_250_;
goto v_resetjp_232_;
}
v_resetjp_232_:
{
lean_object* v___x_235_; lean_object* v___x_236_; uint8_t v___x_237_; 
v___x_235_ = lean_string_utf8_byte_size(v_a_231_);
v___x_236_ = lean_unsigned_to_nat(0u);
v___x_237_ = lean_nat_dec_eq(v___x_235_, v___x_236_);
if (v___x_237_ == 0)
{
lean_object* v___x_238_; lean_object* v___x_239_; lean_object* v___x_240_; lean_object* v___x_241_; uint8_t v___x_242_; 
lean_del_object(v___x_233_);
lean_inc(v_a_231_);
v___x_238_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_238_, 0, v_a_231_);
lean_ctor_set(v___x_238_, 1, v___x_236_);
lean_ctor_set(v___x_238_, 2, v___x_235_);
v___x_239_ = l_String_Slice_trimAscii(v___x_238_);
v___x_240_ = l_String_Slice_toString(v___x_239_);
lean_dec_ref(v___x_239_);
v___x_241_ = lean_string_utf8_byte_size(v___x_240_);
lean_dec_ref(v___x_240_);
v___x_242_ = lean_nat_dec_eq(v___x_241_, v___x_236_);
if (v___x_242_ == 0)
{
if (v___x_225_ == 0)
{
lean_dec(v_a_231_);
goto _start;
}
else
{
lean_object* v___x_244_; 
v___x_244_ = lp_lean1090___private_CLI_Main_0__emit(v_fst_226_, v_a_231_);
if (lean_obj_tag(v___x_244_) == 0)
{
lean_dec_ref_known(v___x_244_, 1);
goto _start;
}
else
{
lean_dec_ref(v_val_224_);
return v___x_244_;
}
}
}
else
{
lean_dec(v_a_231_);
goto _start;
}
}
else
{
lean_object* v___x_248_; 
lean_dec(v_a_231_);
lean_dec_ref(v_val_224_);
if (v_isShared_234_ == 0)
{
lean_ctor_set(v___x_233_, 0, v___x_229_);
v___x_248_ = v___x_233_;
goto v_reusejp_247_;
}
else
{
lean_object* v_reuseFailAlloc_249_; 
v_reuseFailAlloc_249_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_249_, 0, v___x_229_);
v___x_248_ = v_reuseFailAlloc_249_;
goto v_reusejp_247_;
}
v_reusejp_247_:
{
return v___x_248_;
}
}
}
}
else
{
lean_object* v_a_251_; lean_object* v___x_253_; uint8_t v_isShared_254_; uint8_t v_isSharedCheck_258_; 
lean_dec_ref(v_val_224_);
v_a_251_ = lean_ctor_get(v___x_230_, 0);
v_isSharedCheck_258_ = !lean_is_exclusive(v___x_230_);
if (v_isSharedCheck_258_ == 0)
{
v___x_253_ = v___x_230_;
v_isShared_254_ = v_isSharedCheck_258_;
goto v_resetjp_252_;
}
else
{
lean_inc(v_a_251_);
lean_dec(v___x_230_);
v___x_253_ = lean_box(0);
v_isShared_254_ = v_isSharedCheck_258_;
goto v_resetjp_252_;
}
v_resetjp_252_:
{
lean_object* v___x_256_; 
if (v_isShared_254_ == 0)
{
v___x_256_ = v___x_253_;
goto v_reusejp_255_;
}
else
{
lean_object* v_reuseFailAlloc_257_; 
v_reuseFailAlloc_257_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_257_, 0, v_a_251_);
v___x_256_ = v_reuseFailAlloc_257_;
goto v_reusejp_255_;
}
v_reusejp_255_:
{
return v___x_256_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg___boxed(lean_object* v_val_259_, lean_object* v___x_260_, lean_object* v_fst_261_, lean_object* v___y_262_){
_start:
{
uint8_t v___x_1494__boxed_263_; lean_object* v_res_264_; 
v___x_1494__boxed_263_ = lean_unbox(v___x_260_);
v_res_264_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg(v_val_259_, v___x_1494__boxed_263_, v_fst_261_);
lean_dec_ref(v_fst_261_);
return v_res_264_;
}
}
static lean_object* _init_lp_lean1090_main___boxed__const__1(void){
_start:
{
uint32_t v___x_266_; lean_object* v___x_267_; 
v___x_266_ = 0;
v___x_267_ = lean_box_uint32(v___x_266_);
return v___x_267_;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* v_args_268_){
_start:
{
lean_object* v_fst_274_; lean_object* v_snd_275_; 
if (lean_obj_tag(v_args_268_) == 0)
{
lean_object* v___x_297_; 
v___x_297_ = ((lean_object*)(lp_lean1090_main___closed__0));
v_fst_274_ = v___x_297_;
v_snd_275_ = v_args_268_;
goto v___jp_273_;
}
else
{
lean_object* v_head_298_; lean_object* v_tail_299_; lean_object* v___x_300_; uint8_t v___x_301_; 
v_head_298_ = lean_ctor_get(v_args_268_, 0);
v_tail_299_ = lean_ctor_get(v_args_268_, 1);
v___x_300_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__7));
v___x_301_ = lean_string_dec_eq(v_head_298_, v___x_300_);
if (v___x_301_ == 0)
{
lean_object* v___x_302_; uint8_t v___x_303_; 
v___x_302_ = ((lean_object*)(lp_lean1090___private_CLI_Main_0__emit___closed__6));
v___x_303_ = lean_string_dec_eq(v_head_298_, v___x_302_);
if (v___x_303_ == 0)
{
lean_object* v___x_304_; 
v___x_304_ = ((lean_object*)(lp_lean1090_main___closed__0));
v_fst_274_ = v___x_304_;
v_snd_275_ = v_args_268_;
goto v___jp_273_;
}
else
{
lean_inc(v_tail_299_);
lean_inc(v_head_298_);
lean_dec_ref_known(v_args_268_, 2);
v_fst_274_ = v_head_298_;
v_snd_275_ = v_tail_299_;
goto v___jp_273_;
}
}
else
{
lean_inc(v_tail_299_);
lean_inc(v_head_298_);
lean_dec_ref_known(v_args_268_, 2);
v_fst_274_ = v_head_298_;
v_snd_275_ = v_tail_299_;
goto v___jp_273_;
}
}
v___jp_270_:
{
lean_object* v___x_271_; lean_object* v___x_272_; 
v___x_271_ = lp_lean1090_main___boxed__const__1;
v___x_272_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_272_, 0, v___x_271_);
return v___x_272_;
}
v___jp_273_:
{
uint8_t v___x_276_; 
v___x_276_ = l_List_isEmpty___redArg(v_snd_275_);
if (v___x_276_ == 0)
{
lean_object* v___x_277_; lean_object* v___x_278_; 
v___x_277_ = lean_box(0);
v___x_278_ = lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg(v_fst_274_, v_snd_275_, v___x_277_);
lean_dec(v_snd_275_);
lean_dec_ref(v_fst_274_);
if (lean_obj_tag(v___x_278_) == 0)
{
lean_dec_ref_known(v___x_278_, 1);
goto v___jp_270_;
}
else
{
lean_object* v_a_279_; lean_object* v___x_281_; uint8_t v_isShared_282_; uint8_t v_isSharedCheck_286_; 
v_a_279_ = lean_ctor_get(v___x_278_, 0);
v_isSharedCheck_286_ = !lean_is_exclusive(v___x_278_);
if (v_isSharedCheck_286_ == 0)
{
v___x_281_ = v___x_278_;
v_isShared_282_ = v_isSharedCheck_286_;
goto v_resetjp_280_;
}
else
{
lean_inc(v_a_279_);
lean_dec(v___x_278_);
v___x_281_ = lean_box(0);
v_isShared_282_ = v_isSharedCheck_286_;
goto v_resetjp_280_;
}
v_resetjp_280_:
{
lean_object* v___x_284_; 
if (v_isShared_282_ == 0)
{
v___x_284_ = v___x_281_;
goto v_reusejp_283_;
}
else
{
lean_object* v_reuseFailAlloc_285_; 
v_reuseFailAlloc_285_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_285_, 0, v_a_279_);
v___x_284_ = v_reuseFailAlloc_285_;
goto v_reusejp_283_;
}
v_reusejp_283_:
{
return v___x_284_;
}
}
}
}
else
{
lean_object* v___x_287_; lean_object* v___x_288_; 
lean_dec(v_snd_275_);
v___x_287_ = lean_get_stdin();
v___x_288_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg(v___x_287_, v___x_276_, v_fst_274_);
lean_dec_ref(v_fst_274_);
if (lean_obj_tag(v___x_288_) == 0)
{
lean_dec_ref_known(v___x_288_, 1);
goto v___jp_270_;
}
else
{
lean_object* v_a_289_; lean_object* v___x_291_; uint8_t v_isShared_292_; uint8_t v_isSharedCheck_296_; 
v_a_289_ = lean_ctor_get(v___x_288_, 0);
v_isSharedCheck_296_ = !lean_is_exclusive(v___x_288_);
if (v_isSharedCheck_296_ == 0)
{
v___x_291_ = v___x_288_;
v_isShared_292_ = v_isSharedCheck_296_;
goto v_resetjp_290_;
}
else
{
lean_inc(v_a_289_);
lean_dec(v___x_288_);
v___x_291_ = lean_box(0);
v_isShared_292_ = v_isSharedCheck_296_;
goto v_resetjp_290_;
}
v_resetjp_290_:
{
lean_object* v___x_294_; 
if (v_isShared_292_ == 0)
{
v___x_294_ = v___x_291_;
goto v_reusejp_293_;
}
else
{
lean_object* v_reuseFailAlloc_295_; 
v_reuseFailAlloc_295_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_295_, 0, v_a_289_);
v___x_294_ = v_reuseFailAlloc_295_;
goto v_reusejp_293_;
}
v_reusejp_293_:
{
return v___x_294_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_main___boxed(lean_object* v_args_305_, lean_object* v_a_306_){
_start:
{
lean_object* v_res_307_; 
v_res_307_ = _lean_main(v_args_305_);
return v_res_307_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0(lean_object* v_fst_308_, lean_object* v_as_309_, lean_object* v_as_x27_310_, lean_object* v_b_311_, lean_object* v_a_312_){
_start:
{
lean_object* v___x_314_; 
v___x_314_ = lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___redArg(v_fst_308_, v_as_x27_310_, v_b_311_);
return v___x_314_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_forIn_x27_loop___at___00main_spec__0___boxed(lean_object* v_fst_315_, lean_object* v_as_316_, lean_object* v_as_x27_317_, lean_object* v_b_318_, lean_object* v_a_319_, lean_object* v___y_320_){
_start:
{
lean_object* v_res_321_; 
v_res_321_ = lp_lean1090_List_forIn_x27_loop___at___00main_spec__0(v_fst_315_, v_as_316_, v_as_x27_317_, v_b_318_, v_a_319_);
lean_dec(v_as_x27_317_);
lean_dec(v_as_316_);
lean_dec_ref(v_fst_315_);
return v_res_321_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1(lean_object* v_val_322_, uint8_t v___x_323_, lean_object* v_fst_324_, lean_object* v_inst_325_, lean_object* v_a_326_){
_start:
{
lean_object* v___x_328_; 
v___x_328_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___redArg(v_val_322_, v___x_323_, v_fst_324_);
return v___x_328_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1___boxed(lean_object* v_val_329_, lean_object* v___x_330_, lean_object* v_fst_331_, lean_object* v_inst_332_, lean_object* v_a_333_, lean_object* v___y_334_){
_start:
{
uint8_t v___x_1665__boxed_335_; lean_object* v_res_336_; 
v___x_1665__boxed_335_ = lean_unbox(v___x_330_);
v_res_336_ = lp_lean1090___private_Init_While_0__repeatM_erased___at___00main_spec__1(v_val_329_, v___x_1665__boxed_335_, v_fst_331_, v_inst_332_, v_a_333_);
lean_dec_ref(v_fst_331_);
return v_res_336_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_lean1090_Impl_JSON(uint8_t builtin);
lean_object* initialize_Lean_Data_Json_Printer(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_lean1090_CLI_Main(uint8_t builtin) {
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
res = initialize_Lean_Data_Json_Printer(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_lean1090_main___boxed__const__1 = _init_lp_lean1090_main___boxed__const__1();
lean_mark_persistent(lp_lean1090_main___boxed__const__1);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif
lean_object* run_main(int argc, char ** argv) {
    lean_object* in = lean_box(0);
    int i = argc;
    while (i > 1) {
      lean_object* n;
      i--;
      n = lean_alloc_ctor(1,2,0); lean_ctor_set(n, 0, lean_mk_string(argv[i])); lean_ctor_set(n, 1, in);
      in = n;
    }
    return _lean_main(in);
}
int main(int argc, char ** argv) {
#if defined(WIN32) || defined(_WIN32)
  SetErrorMode(SEM_FAILCRITICALERRORS);
  SetConsoleOutputCP(CP_UTF8);
#endif
  lean_object* res;
  argv = lean_setup_args(argc, argv);
  res = initialize_lean1090_CLI_Main(1 /* builtin */);
  lean_io_mark_end_initialization();
  if (lean_io_result_is_ok(res)) {
    lean_dec_ref(res);
    lean_init_task_manager();
    res = lean_run_main(&run_main, argc, argv);
  }
  lean_finalize_task_manager();
  if (lean_io_result_is_ok(res)) {
    int ret = lean_unbox_uint32(lean_io_result_get_value(res));
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
