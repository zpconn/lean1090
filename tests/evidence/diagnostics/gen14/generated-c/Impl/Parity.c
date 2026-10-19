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
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint32_t lean_uint32_xor(uint32_t, uint32_t);
uint32_t lean_uint32_land(uint32_t, uint32_t);
uint32_t lean_uint32_lor(uint32_t, uint32_t);
uint8_t lean_uint32_dec_eq(uint32_t, uint32_t);
uint32_t lean_uint32_shift_left(uint32_t, uint32_t);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
uint8_t l_Nat_testBit(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
uint8_t lean_uint64_dec_eq(uint64_t, uint64_t);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lean_uint32_to_nat(uint32_t);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
uint32_t lean_uint32_of_nat(lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_generator;
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_Parity_wordStep(uint32_t, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_wordStep___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step(lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_wordBit(uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_cachedBit(lean_object*, uint64_t, uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg(lean_object*, lean_object*, uint64_t, uint64_t, lean_object*, lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object*, lean_object*, uint64_t, uint64_t, lean_object*, lean_object*, lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
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
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_Parity_wordStep(uint32_t v_remainder_2_, uint8_t v_bit_3_){
_start:
{
uint32_t v___y_5_; uint32_t v___y_6_; uint32_t v___x_10_; uint32_t v___x_11_; uint32_t v___y_13_; 
v___x_10_ = 1;
v___x_11_ = lean_uint32_shift_left(v_remainder_2_, v___x_10_);
if (v_bit_3_ == 0)
{
uint32_t v___x_20_; 
v___x_20_ = 0;
v___y_13_ = v___x_20_;
goto v___jp_12_;
}
else
{
v___y_13_ = v___x_10_;
goto v___jp_12_;
}
v___jp_4_:
{
uint32_t v___x_7_; uint32_t v___x_8_; uint32_t v___x_9_; 
v___x_7_ = lean_uint32_xor(v___y_5_, v___y_6_);
v___x_8_ = 16777215;
v___x_9_ = lean_uint32_land(v___x_7_, v___x_8_);
return v___x_9_;
}
v___jp_12_:
{
uint32_t v_shifted_14_; uint32_t v___x_15_; uint32_t v___x_16_; uint32_t v___x_17_; uint8_t v___x_18_; 
v_shifted_14_ = lean_uint32_lor(v___x_11_, v___y_13_);
v___x_15_ = 8388608;
v___x_16_ = lean_uint32_land(v_remainder_2_, v___x_15_);
v___x_17_ = 0;
v___x_18_ = lean_uint32_dec_eq(v___x_16_, v___x_17_);
if (v___x_18_ == 0)
{
uint32_t v___x_19_; 
v___x_19_ = 33551369;
v___y_5_ = v_shifted_14_;
v___y_6_ = v___x_19_;
goto v___jp_4_;
}
else
{
v___y_5_ = v_shifted_14_;
v___y_6_ = v___x_17_;
goto v___jp_4_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_wordStep___boxed(lean_object* v_remainder_21_, lean_object* v_bit_22_){
_start:
{
uint32_t v_remainder_boxed_23_; uint8_t v_bit_boxed_24_; uint32_t v_res_25_; lean_object* v_r_26_; 
v_remainder_boxed_23_ = lean_unbox_uint32(v_remainder_21_);
lean_dec(v_remainder_21_);
v_bit_boxed_24_ = lean_unbox(v_bit_22_);
v_res_25_ = lp_lean1090_Lean1090_Impl_Parity_wordStep(v_remainder_boxed_23_, v_bit_boxed_24_);
v_r_26_ = lean_box_uint32(v_res_25_);
return v_r_26_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step(lean_object* v_remainder_27_, uint8_t v_bit_28_){
_start:
{
lean_object* v___x_29_; uint32_t v___y_31_; uint32_t v___y_32_; uint32_t v___x_38_; uint32_t v___x_39_; uint32_t v___x_40_; uint32_t v___y_42_; 
v___x_29_ = lean_unsigned_to_nat(24u);
v___x_38_ = lean_uint32_of_nat(v_remainder_27_);
v___x_39_ = 1;
v___x_40_ = lean_uint32_shift_left(v___x_38_, v___x_39_);
if (v_bit_28_ == 0)
{
uint32_t v___x_49_; 
v___x_49_ = 0;
v___y_42_ = v___x_49_;
goto v___jp_41_;
}
else
{
v___y_42_ = v___x_39_;
goto v___jp_41_;
}
v___jp_30_:
{
uint32_t v___x_33_; uint32_t v___x_34_; uint32_t v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; 
v___x_33_ = lean_uint32_xor(v___y_31_, v___y_32_);
v___x_34_ = 16777215;
v___x_35_ = lean_uint32_land(v___x_33_, v___x_34_);
v___x_36_ = lean_uint32_to_nat(v___x_35_);
v___x_37_ = l_BitVec_ofNat(v___x_29_, v___x_36_);
lean_dec(v___x_36_);
return v___x_37_;
}
v___jp_41_:
{
uint32_t v_shifted_43_; uint32_t v___x_44_; uint32_t v___x_45_; uint32_t v___x_46_; uint8_t v___x_47_; 
v_shifted_43_ = lean_uint32_lor(v___x_40_, v___y_42_);
v___x_44_ = 8388608;
v___x_45_ = lean_uint32_land(v___x_38_, v___x_44_);
v___x_46_ = 0;
v___x_47_ = lean_uint32_dec_eq(v___x_45_, v___x_46_);
if (v___x_47_ == 0)
{
uint32_t v___x_48_; 
v___x_48_ = 33551369;
v___y_31_ = v_shifted_43_;
v___y_32_ = v___x_48_;
goto v___jp_30_;
}
else
{
v___y_31_ = v_shifted_43_;
v___y_32_ = v___x_46_;
goto v___jp_30_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_step___boxed(lean_object* v_remainder_50_, lean_object* v_bit_51_){
_start:
{
uint8_t v_bit_boxed_52_; lean_object* v_res_53_; 
v_bit_boxed_52_ = lean_unbox(v_bit_51_);
v_res_53_ = lp_lean1090_Lean1090_Impl_Parity_step(v_remainder_50_, v_bit_boxed_52_);
lean_dec(v_remainder_50_);
return v_res_53_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_wordBit(uint64_t v_word_54_, lean_object* v_i_55_){
_start:
{
uint64_t v___x_56_; uint64_t v___x_57_; uint64_t v___x_58_; uint64_t v___x_59_; uint8_t v___x_60_; 
v___x_56_ = lean_uint64_of_nat(v_i_55_);
v___x_57_ = lean_uint64_shift_right(v_word_54_, v___x_56_);
v___x_58_ = 1ULL;
v___x_59_ = lean_uint64_land(v___x_57_, v___x_58_);
v___x_60_ = lean_uint64_dec_eq(v___x_59_, v___x_58_);
return v___x_60_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed(lean_object* v_word_61_, lean_object* v_i_62_){
_start:
{
uint64_t v_word_boxed_63_; uint8_t v_res_64_; lean_object* v_r_65_; 
v_word_boxed_63_ = lean_unbox_uint64(v_word_61_);
lean_dec_ref(v_word_61_);
v_res_64_ = lp_lean1090_Lean1090_Impl_Parity_wordBit(v_word_boxed_63_, v_i_62_);
lean_dec(v_i_62_);
v_r_65_ = lean_box(v_res_64_);
return v_r_65_;
}
}
LEAN_EXPORT uint8_t lp_lean1090_Lean1090_Impl_Parity_cachedBit(lean_object* v_word_66_, uint64_t v_low_67_, uint64_t v_high_68_, lean_object* v_i_69_){
_start:
{
lean_object* v___x_70_; uint8_t v___x_71_; 
v___x_70_ = lean_unsigned_to_nat(64u);
v___x_71_ = lean_nat_dec_lt(v_i_69_, v___x_70_);
if (v___x_71_ == 0)
{
lean_object* v___x_72_; uint8_t v___x_73_; 
v___x_72_ = lean_unsigned_to_nat(128u);
v___x_73_ = lean_nat_dec_lt(v_i_69_, v___x_72_);
if (v___x_73_ == 0)
{
uint8_t v___x_74_; 
v___x_74_ = l_Nat_testBit(v_word_66_, v_i_69_);
return v___x_74_;
}
else
{
lean_object* v___x_75_; uint64_t v___x_76_; uint64_t v___x_77_; uint64_t v___x_78_; uint64_t v___x_79_; uint8_t v___x_80_; 
v___x_75_ = lean_nat_sub(v_i_69_, v___x_70_);
v___x_76_ = lean_uint64_of_nat(v___x_75_);
lean_dec(v___x_75_);
v___x_77_ = lean_uint64_shift_right(v_high_68_, v___x_76_);
v___x_78_ = 1ULL;
v___x_79_ = lean_uint64_land(v___x_77_, v___x_78_);
v___x_80_ = lean_uint64_dec_eq(v___x_79_, v___x_78_);
return v___x_80_;
}
}
else
{
uint64_t v___x_81_; uint64_t v___x_82_; uint64_t v___x_83_; uint64_t v___x_84_; uint8_t v___x_85_; 
v___x_81_ = lean_uint64_of_nat(v_i_69_);
v___x_82_ = lean_uint64_shift_right(v_low_67_, v___x_81_);
v___x_83_ = 1ULL;
v___x_84_ = lean_uint64_land(v___x_82_, v___x_83_);
v___x_85_ = lean_uint64_dec_eq(v___x_84_, v___x_83_);
return v___x_85_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed(lean_object* v_word_86_, lean_object* v_low_87_, lean_object* v_high_88_, lean_object* v_i_89_){
_start:
{
uint64_t v_low_boxed_90_; uint64_t v_high_boxed_91_; uint8_t v_res_92_; lean_object* v_r_93_; 
v_low_boxed_90_ = lean_unbox_uint64(v_low_87_);
lean_dec_ref(v_low_87_);
v_high_boxed_91_ = lean_unbox_uint64(v_high_88_);
lean_dec_ref(v_high_88_);
v_res_92_ = lp_lean1090_Lean1090_Impl_Parity_cachedBit(v_word_86_, v_low_boxed_90_, v_high_boxed_91_, v_i_89_);
lean_dec(v_i_89_);
lean_dec(v_word_86_);
v_r_93_ = lean_box(v_res_92_);
return v_r_93_;
}
}
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg(lean_object* v_width_94_, lean_object* v_word_95_, uint64_t v_high_96_, uint64_t v_low_97_, lean_object* v_n_98_, lean_object* v_j_99_, uint32_t v_a_100_){
_start:
{
lean_object* v_zero_101_; uint8_t v_isZero_102_; 
v_zero_101_ = lean_unsigned_to_nat(0u);
v_isZero_102_ = lean_nat_dec_eq(v_j_99_, v_zero_101_);
if (v_isZero_102_ == 1)
{
lean_dec(v_j_99_);
return v_a_100_;
}
else
{
lean_object* v_one_103_; lean_object* v_n_104_; uint32_t v___y_106_; uint32_t v___y_107_; uint32_t v___y_113_; uint32_t v___y_114_; uint8_t v___y_122_; lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; uint8_t v___x_130_; 
v_one_103_ = lean_unsigned_to_nat(1u);
v_n_104_ = lean_nat_sub(v_j_99_, v_one_103_);
v___x_126_ = lean_nat_sub(v_n_98_, v_j_99_);
lean_dec(v_j_99_);
v___x_127_ = lean_nat_sub(v_width_94_, v_one_103_);
v___x_128_ = lean_nat_sub(v___x_127_, v___x_126_);
lean_dec(v___x_126_);
lean_dec(v___x_127_);
v___x_129_ = lean_unsigned_to_nat(64u);
v___x_130_ = lean_nat_dec_lt(v___x_128_, v___x_129_);
if (v___x_130_ == 0)
{
lean_object* v___x_131_; uint8_t v___x_132_; 
v___x_131_ = lean_unsigned_to_nat(128u);
v___x_132_ = lean_nat_dec_lt(v___x_128_, v___x_131_);
if (v___x_132_ == 0)
{
uint8_t v___x_133_; 
v___x_133_ = l_Nat_testBit(v_word_95_, v___x_128_);
lean_dec(v___x_128_);
v___y_122_ = v___x_133_;
goto v___jp_121_;
}
else
{
lean_object* v___x_134_; uint64_t v___x_135_; uint64_t v___x_136_; uint64_t v___x_137_; uint64_t v___x_138_; uint8_t v___x_139_; 
v___x_134_ = lean_nat_sub(v___x_128_, v___x_129_);
lean_dec(v___x_128_);
v___x_135_ = lean_uint64_of_nat(v___x_134_);
lean_dec(v___x_134_);
v___x_136_ = lean_uint64_shift_right(v_high_96_, v___x_135_);
v___x_137_ = 1ULL;
v___x_138_ = lean_uint64_land(v___x_136_, v___x_137_);
v___x_139_ = lean_uint64_dec_eq(v___x_138_, v___x_137_);
v___y_122_ = v___x_139_;
goto v___jp_121_;
}
}
else
{
uint64_t v___x_140_; uint64_t v___x_141_; uint64_t v___x_142_; uint64_t v___x_143_; uint8_t v___x_144_; 
v___x_140_ = lean_uint64_of_nat(v___x_128_);
lean_dec(v___x_128_);
v___x_141_ = lean_uint64_shift_right(v_low_97_, v___x_140_);
v___x_142_ = 1ULL;
v___x_143_ = lean_uint64_land(v___x_141_, v___x_142_);
v___x_144_ = lean_uint64_dec_eq(v___x_143_, v___x_142_);
v___y_122_ = v___x_144_;
goto v___jp_121_;
}
v___jp_105_:
{
uint32_t v___x_108_; uint32_t v___x_109_; uint32_t v___x_110_; 
v___x_108_ = lean_uint32_xor(v___y_106_, v___y_107_);
v___x_109_ = 16777215;
v___x_110_ = lean_uint32_land(v___x_108_, v___x_109_);
v_j_99_ = v_n_104_;
v_a_100_ = v___x_110_;
goto _start;
}
v___jp_112_:
{
uint32_t v_shifted_115_; uint32_t v___x_116_; uint32_t v___x_117_; uint32_t v___x_118_; uint8_t v___x_119_; 
v_shifted_115_ = lean_uint32_lor(v___y_113_, v___y_114_);
v___x_116_ = 8388608;
v___x_117_ = lean_uint32_land(v_a_100_, v___x_116_);
v___x_118_ = 0;
v___x_119_ = lean_uint32_dec_eq(v___x_117_, v___x_118_);
if (v___x_119_ == 0)
{
uint32_t v___x_120_; 
v___x_120_ = 33551369;
v___y_106_ = v_shifted_115_;
v___y_107_ = v___x_120_;
goto v___jp_105_;
}
else
{
v___y_106_ = v_shifted_115_;
v___y_107_ = v___x_118_;
goto v___jp_105_;
}
}
v___jp_121_:
{
uint32_t v___x_123_; uint32_t v___x_124_; 
v___x_123_ = 1;
v___x_124_ = lean_uint32_shift_left(v_a_100_, v___x_123_);
if (v___y_122_ == 0)
{
uint32_t v___x_125_; 
v___x_125_ = 0;
v___y_113_ = v___x_124_;
v___y_114_ = v___x_125_;
goto v___jp_112_;
}
else
{
v___y_113_ = v___x_124_;
v___y_114_ = v___x_123_;
goto v___jp_112_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg___boxed(lean_object* v_width_145_, lean_object* v_word_146_, lean_object* v_high_147_, lean_object* v_low_148_, lean_object* v_n_149_, lean_object* v_j_150_, lean_object* v_a_151_){
_start:
{
uint64_t v_high_boxed_152_; uint64_t v_low_boxed_153_; uint32_t v_a_239__boxed_154_; uint32_t v_res_155_; lean_object* v_r_156_; 
v_high_boxed_152_ = lean_unbox_uint64(v_high_147_);
lean_dec_ref(v_high_147_);
v_low_boxed_153_ = lean_unbox_uint64(v_low_148_);
lean_dec_ref(v_low_148_);
v_a_239__boxed_154_ = lean_unbox_uint32(v_a_151_);
lean_dec(v_a_151_);
v_res_155_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg(v_width_145_, v_word_146_, v_high_boxed_152_, v_low_boxed_153_, v_n_149_, v_j_150_, v_a_239__boxed_154_);
lean_dec(v_n_149_);
lean_dec(v_word_146_);
lean_dec(v_width_145_);
v_r_156_ = lean_box_uint32(v_res_155_);
return v_r_156_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object* v_width_157_, lean_object* v_word_158_){
_start:
{
uint64_t v_low_159_; lean_object* v___x_160_; lean_object* v___x_161_; uint64_t v_high_162_; uint32_t v___x_163_; uint32_t v_remainder_164_; lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; 
v_low_159_ = lean_uint64_of_nat(v_word_158_);
v___x_160_ = lean_unsigned_to_nat(64u);
v___x_161_ = lean_nat_shiftr(v_word_158_, v___x_160_);
v_high_162_ = lean_uint64_of_nat(v___x_161_);
lean_dec(v___x_161_);
v___x_163_ = 0;
lean_inc(v_width_157_);
v_remainder_164_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg(v_width_157_, v_word_158_, v_high_162_, v_low_159_, v_width_157_, v_width_157_, v___x_163_);
lean_dec(v_width_157_);
v___x_165_ = lean_unsigned_to_nat(24u);
v___x_166_ = lean_uint32_to_nat(v_remainder_164_);
v___x_167_ = l_BitVec_ofNat(v___x_165_, v___x_166_);
lean_dec(v___x_166_);
return v___x_167_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object* v_width_168_, lean_object* v_word_169_){
_start:
{
lean_object* v_res_170_; 
v_res_170_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v_width_168_, v_word_169_);
lean_dec(v_word_169_);
return v_res_170_;
}
}
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0(lean_object* v_width_171_, lean_object* v_word_172_, uint64_t v_high_173_, uint64_t v_low_174_, lean_object* v_n_175_, lean_object* v_j_176_, lean_object* v_a_177_, uint32_t v_a_178_){
_start:
{
uint32_t v___x_179_; 
v___x_179_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg(v_width_171_, v_word_172_, v_high_173_, v_low_174_, v_n_175_, v_j_176_, v_a_178_);
return v___x_179_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed(lean_object* v_width_180_, lean_object* v_word_181_, lean_object* v_high_182_, lean_object* v_low_183_, lean_object* v_n_184_, lean_object* v_j_185_, lean_object* v_a_186_, lean_object* v_a_187_){
_start:
{
uint64_t v_high_boxed_188_; uint64_t v_low_boxed_189_; uint32_t v_a_335__boxed_190_; uint32_t v_res_191_; lean_object* v_r_192_; 
v_high_boxed_188_ = lean_unbox_uint64(v_high_182_);
lean_dec_ref(v_high_182_);
v_low_boxed_189_ = lean_unbox_uint64(v_low_183_);
lean_dec_ref(v_low_183_);
v_a_335__boxed_190_ = lean_unbox_uint32(v_a_187_);
lean_dec(v_a_187_);
v_res_191_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0(v_width_180_, v_word_181_, v_high_boxed_188_, v_low_boxed_189_, v_n_184_, v_j_185_, v_a_186_, v_a_335__boxed_190_);
lean_dec(v_n_184_);
lean_dec(v_word_181_);
lean_dec(v_width_180_);
v_r_192_ = lean_box_uint32(v_res_191_);
return v_r_192_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object* v_informationWidth_193_, lean_object* v_information_194_){
_start:
{
lean_object* v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; 
v___x_195_ = lean_unsigned_to_nat(24u);
v___x_196_ = lean_nat_add(v_informationWidth_193_, v___x_195_);
v___x_197_ = lean_unsigned_to_nat(16777216u);
v___x_198_ = lean_nat_mul(v_information_194_, v___x_197_);
v___x_199_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v___x_196_, v___x_198_);
lean_dec(v___x_198_);
return v___x_199_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum___boxed(lean_object* v_informationWidth_200_, lean_object* v_information_201_){
_start:
{
lean_object* v_res_202_; 
v_res_202_ = lp_lean1090_Lean1090_Impl_Parity_checksum(v_informationWidth_200_, v_information_201_);
lean_dec(v_information_201_);
lean_dec(v_informationWidth_200_);
return v_res_202_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object* v_s_203_){
_start:
{
lean_object* v___x_204_; uint8_t v___x_205_; 
v___x_204_ = lean_unsigned_to_nat(128u);
v___x_205_ = lean_nat_dec_lt(v_s_203_, v___x_204_);
if (v___x_205_ == 0)
{
lean_object* v___x_206_; 
v___x_206_ = lean_box(0);
return v___x_206_;
}
else
{
lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_209_; lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; 
v___x_207_ = lean_unsigned_to_nat(3u);
v___x_208_ = lean_unsigned_to_nat(4u);
v___x_209_ = lean_nat_shiftr(v_s_203_, v___x_208_);
v___x_210_ = l_BitVec_ofNat(v___x_207_, v___x_209_);
lean_dec(v___x_209_);
v___x_211_ = l_BitVec_ofNat(v___x_208_, v_s_203_);
v___x_212_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_212_, 0, v___x_210_);
lean_ctor_set(v___x_212_, 1, v___x_211_);
v___x_213_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_213_, 0, v___x_212_);
return v___x_213_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed(lean_object* v_s_214_){
_start:
{
lean_object* v_res_215_; 
v_res_215_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v_s_214_);
lean_dec(v_s_214_);
return v_res_215_;
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
