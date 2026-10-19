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
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t l_Nat_testBit(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_lxor(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
uint8_t lean_uint64_dec_eq(uint64_t, uint64_t);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_generator;
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step(lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_wordBit(uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_cachedBit(lean_object*, uint64_t, uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object*, lean_object*, uint64_t, uint64_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
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
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_wordBit(uint64_t v_word_23_, lean_object* v_i_24_){
_start:
{
uint64_t v___x_25_; uint64_t v___x_26_; uint64_t v___x_27_; uint64_t v___x_28_; uint8_t v___x_29_; 
v___x_25_ = lean_uint64_of_nat(v_i_24_);
v___x_26_ = lean_uint64_shift_right(v_word_23_, v___x_25_);
v___x_27_ = 1ULL;
v___x_28_ = lean_uint64_land(v___x_26_, v___x_27_);
v___x_29_ = lean_uint64_dec_eq(v___x_28_, v___x_27_);
return v___x_29_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed(lean_object* v_word_30_, lean_object* v_i_31_){
_start:
{
uint64_t v_word_boxed_32_; uint8_t v_res_33_; lean_object* v_r_34_; 
v_word_boxed_32_ = lean_unbox_uint64(v_word_30_);
lean_dec_ref(v_word_30_);
v_res_33_ = lp_lean1090_Lean1090_Impl_Parity_wordBit(v_word_boxed_32_, v_i_31_);
lean_dec(v_i_31_);
v_r_34_ = lean_box(v_res_33_);
return v_r_34_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_cachedBit(lean_object* v_word_35_, uint64_t v_low_36_, uint64_t v_high_37_, lean_object* v_i_38_){
_start:
{
lean_object* v___x_39_; uint8_t v___x_40_; 
v___x_39_ = lean_unsigned_to_nat(64u);
v___x_40_ = lean_nat_dec_lt(v_i_38_, v___x_39_);
if (v___x_40_ == 0)
{
lean_object* v___x_41_; uint8_t v___x_42_; 
v___x_41_ = lean_unsigned_to_nat(128u);
v___x_42_ = lean_nat_dec_lt(v_i_38_, v___x_41_);
if (v___x_42_ == 0)
{
uint8_t v___x_43_; 
v___x_43_ = l_Nat_testBit(v_word_35_, v_i_38_);
return v___x_43_;
}
else
{
lean_object* v___x_44_; uint64_t v___x_45_; uint64_t v___x_46_; uint64_t v___x_47_; uint64_t v___x_48_; uint8_t v___x_49_; 
v___x_44_ = lean_nat_sub(v_i_38_, v___x_39_);
v___x_45_ = lean_uint64_of_nat(v___x_44_);
lean_dec(v___x_44_);
v___x_46_ = lean_uint64_shift_right(v_high_37_, v___x_45_);
v___x_47_ = 1ULL;
v___x_48_ = lean_uint64_land(v___x_46_, v___x_47_);
v___x_49_ = lean_uint64_dec_eq(v___x_48_, v___x_47_);
return v___x_49_;
}
}
else
{
uint64_t v___x_50_; uint64_t v___x_51_; uint64_t v___x_52_; uint64_t v___x_53_; uint8_t v___x_54_; 
v___x_50_ = lean_uint64_of_nat(v_i_38_);
v___x_51_ = lean_uint64_shift_right(v_low_36_, v___x_50_);
v___x_52_ = 1ULL;
v___x_53_ = lean_uint64_land(v___x_51_, v___x_52_);
v___x_54_ = lean_uint64_dec_eq(v___x_53_, v___x_52_);
return v___x_54_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed(lean_object* v_word_55_, lean_object* v_low_56_, lean_object* v_high_57_, lean_object* v_i_58_){
_start:
{
uint64_t v_low_boxed_59_; uint64_t v_high_boxed_60_; uint8_t v_res_61_; lean_object* v_r_62_; 
v_low_boxed_59_ = lean_unbox_uint64(v_low_56_);
lean_dec_ref(v_low_56_);
v_high_boxed_60_ = lean_unbox_uint64(v_high_57_);
lean_dec_ref(v_high_57_);
v_res_61_ = lp_lean1090_Lean1090_Impl_Parity_cachedBit(v_word_55_, v_low_boxed_59_, v_high_boxed_60_, v_i_58_);
lean_dec(v_i_58_);
lean_dec(v_word_55_);
v_r_62_ = lean_box(v_res_61_);
return v_r_62_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object* v_width_63_, lean_object* v_word_64_, uint64_t v_high_65_, uint64_t v_low_66_, lean_object* v_x_67_, lean_object* v_x_68_){
_start:
{
if (lean_obj_tag(v_x_68_) == 0)
{
return v_x_67_;
}
else
{
lean_object* v_head_69_; lean_object* v_tail_70_; lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; uint8_t v___x_75_; 
v_head_69_ = lean_ctor_get(v_x_68_, 0);
v_tail_70_ = lean_ctor_get(v_x_68_, 1);
v___x_71_ = lean_unsigned_to_nat(1u);
v___x_72_ = lean_nat_sub(v_width_63_, v___x_71_);
v___x_73_ = lean_nat_sub(v___x_72_, v_head_69_);
lean_dec(v___x_72_);
v___x_74_ = lean_unsigned_to_nat(64u);
v___x_75_ = lean_nat_dec_lt(v___x_73_, v___x_74_);
if (v___x_75_ == 0)
{
lean_object* v___x_76_; uint8_t v___x_77_; 
v___x_76_ = lean_unsigned_to_nat(128u);
v___x_77_ = lean_nat_dec_lt(v___x_73_, v___x_76_);
if (v___x_77_ == 0)
{
uint8_t v___x_78_; lean_object* v___x_79_; 
v___x_78_ = l_Nat_testBit(v_word_64_, v___x_73_);
lean_dec(v___x_73_);
v___x_79_ = lp_lean1090_Lean1090_Impl_Parity_step(v_x_67_, v___x_78_);
lean_dec(v_x_67_);
v_x_67_ = v___x_79_;
v_x_68_ = v_tail_70_;
goto _start;
}
else
{
lean_object* v___x_81_; uint64_t v___x_82_; uint64_t v___x_83_; uint64_t v___x_84_; uint64_t v___x_85_; uint8_t v___x_86_; lean_object* v___x_87_; 
v___x_81_ = lean_nat_sub(v___x_73_, v___x_74_);
lean_dec(v___x_73_);
v___x_82_ = lean_uint64_of_nat(v___x_81_);
lean_dec(v___x_81_);
v___x_83_ = lean_uint64_shift_right(v_high_65_, v___x_82_);
v___x_84_ = 1ULL;
v___x_85_ = lean_uint64_land(v___x_83_, v___x_84_);
v___x_86_ = lean_uint64_dec_eq(v___x_85_, v___x_84_);
v___x_87_ = lp_lean1090_Lean1090_Impl_Parity_step(v_x_67_, v___x_86_);
lean_dec(v_x_67_);
v_x_67_ = v___x_87_;
v_x_68_ = v_tail_70_;
goto _start;
}
}
else
{
uint64_t v___x_89_; uint64_t v___x_90_; uint64_t v___x_91_; uint64_t v___x_92_; uint8_t v___x_93_; lean_object* v___x_94_; 
v___x_89_ = lean_uint64_of_nat(v___x_73_);
lean_dec(v___x_73_);
v___x_90_ = lean_uint64_shift_right(v_low_66_, v___x_89_);
v___x_91_ = 1ULL;
v___x_92_ = lean_uint64_land(v___x_90_, v___x_91_);
v___x_93_ = lean_uint64_dec_eq(v___x_92_, v___x_91_);
v___x_94_ = lp_lean1090_Lean1090_Impl_Parity_step(v_x_67_, v___x_93_);
lean_dec(v_x_67_);
v_x_67_ = v___x_94_;
v_x_68_ = v_tail_70_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object* v_width_96_, lean_object* v_word_97_, lean_object* v_high_98_, lean_object* v_low_99_, lean_object* v_x_100_, lean_object* v_x_101_){
_start:
{
uint64_t v_high_boxed_102_; uint64_t v_low_boxed_103_; lean_object* v_res_104_; 
v_high_boxed_102_ = lean_unbox_uint64(v_high_98_);
lean_dec_ref(v_high_98_);
v_low_boxed_103_ = lean_unbox_uint64(v_low_99_);
lean_dec_ref(v_low_99_);
v_res_104_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_96_, v_word_97_, v_high_boxed_102_, v_low_boxed_103_, v_x_100_, v_x_101_);
lean_dec(v_x_101_);
lean_dec(v_word_97_);
lean_dec(v_width_96_);
return v_res_104_;
}
}
static lean_object* _init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0(void){
_start:
{
lean_object* v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; 
v___x_105_ = lean_unsigned_to_nat(0u);
v___x_106_ = lean_unsigned_to_nat(24u);
v___x_107_ = l_BitVec_ofNat(v___x_106_, v___x_105_);
return v___x_107_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object* v_width_108_, lean_object* v_word_109_){
_start:
{
uint64_t v_low_110_; lean_object* v___x_111_; lean_object* v___x_112_; uint64_t v_high_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; 
v_low_110_ = lean_uint64_of_nat(v_word_109_);
v___x_111_ = lean_unsigned_to_nat(64u);
v___x_112_ = lean_nat_shiftr(v_word_109_, v___x_111_);
v_high_113_ = lean_uint64_of_nat(v___x_112_);
lean_dec(v___x_112_);
v___x_114_ = lean_obj_once(&lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0, &lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0_once, _init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0);
lean_inc(v_width_108_);
v___x_115_ = l_List_range(v_width_108_);
v___x_116_ = lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_108_, v_word_109_, v_high_113_, v_low_110_, v___x_114_, v___x_115_);
lean_dec(v___x_115_);
lean_dec(v_width_108_);
return v___x_116_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object* v_width_117_, lean_object* v_word_118_){
_start:
{
lean_object* v_res_119_; 
v_res_119_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v_width_117_, v_word_118_);
lean_dec(v_word_118_);
return v_res_119_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object* v_informationWidth_120_, lean_object* v_information_121_){
_start:
{
lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v___x_125_; lean_object* v___x_126_; 
v___x_122_ = lean_unsigned_to_nat(24u);
v___x_123_ = lean_nat_add(v_informationWidth_120_, v___x_122_);
v___x_124_ = lean_unsigned_to_nat(16777216u);
v___x_125_ = lean_nat_mul(v_information_121_, v___x_124_);
v___x_126_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v___x_123_, v___x_125_);
lean_dec(v___x_125_);
return v___x_126_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum___boxed(lean_object* v_informationWidth_127_, lean_object* v_information_128_){
_start:
{
lean_object* v_res_129_; 
v_res_129_ = lp_lean1090_Lean1090_Impl_Parity_checksum(v_informationWidth_127_, v_information_128_);
lean_dec(v_information_128_);
lean_dec(v_informationWidth_127_);
return v_res_129_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object* v_s_130_){
_start:
{
lean_object* v___x_131_; uint8_t v___x_132_; 
v___x_131_ = lean_unsigned_to_nat(128u);
v___x_132_ = lean_nat_dec_lt(v_s_130_, v___x_131_);
if (v___x_132_ == 0)
{
lean_object* v___x_133_; 
v___x_133_ = lean_box(0);
return v___x_133_;
}
else
{
lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; 
v___x_134_ = lean_unsigned_to_nat(3u);
v___x_135_ = lean_unsigned_to_nat(4u);
v___x_136_ = lean_nat_shiftr(v_s_130_, v___x_135_);
v___x_137_ = l_BitVec_ofNat(v___x_134_, v___x_136_);
lean_dec(v___x_136_);
v___x_138_ = l_BitVec_ofNat(v___x_135_, v_s_130_);
v___x_139_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_139_, 0, v___x_137_);
lean_ctor_set(v___x_139_, 1, v___x_138_);
v___x_140_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_140_, 0, v___x_139_);
return v___x_140_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed(lean_object* v_s_141_){
_start:
{
lean_object* v_res_142_; 
v_res_142_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v_s_141_);
lean_dec(v_s_141_);
return v_res_142_;
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
