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
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
uint64_t lean_uint64_land(uint64_t, uint64_t);
uint8_t lean_uint64_dec_eq(uint64_t, uint64_t);
uint8_t l_Nat_testBit(lean_object*, lean_object*);
uint32_t lean_uint32_xor(uint32_t, uint32_t);
uint32_t lean_uint32_land(uint32_t, uint32_t);
uint32_t lean_uint32_shift_left(uint32_t, uint32_t);
uint32_t lean_uint32_lor(uint32_t, uint32_t);
uint8_t lean_uint32_dec_eq(uint32_t, uint32_t);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_uint32_to_nat(uint32_t);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
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
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_Parity_byteStep(uint32_t, uint64_t);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_byteStep___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_lean1090_Lean1090_Impl_Parity_cachedByte(uint64_t, uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_cachedByte___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg(lean_object*, lean_object*, uint64_t, uint64_t, lean_object*, lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBits(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBits___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0(lean_object*, lean_object*, uint64_t, uint64_t, lean_object*, lean_object*, lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg(lean_object*, uint64_t, uint64_t, lean_object*, lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBytes(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBytes___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0(lean_object*, uint64_t, uint64_t, lean_object*, lean_object*, lean_object*, uint32_t);
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
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
LEAN_EXPORT uint32_t lp_lean1090_Lean1090_Impl_Parity_byteStep(uint32_t v_remainder_94_, uint64_t v_byte_95_){
_start:
{
uint32_t v___y_97_; uint32_t v___y_98_; uint32_t v___y_99_; uint32_t v___y_103_; uint32_t v___y_104_; uint32_t v___y_105_; uint32_t v___y_106_; uint64_t v___x_113_; uint64_t v___x_114_; uint64_t v___x_115_; uint64_t v___x_116_; uint8_t v___x_117_; uint32_t v___x_118_; uint32_t v___y_120_; uint32_t v___y_121_; uint32_t v___y_122_; uint32_t v___y_130_; uint32_t v___y_131_; uint32_t v___y_132_; uint32_t v___y_133_; uint32_t v___y_141_; uint32_t v___y_142_; uint32_t v___y_143_; uint32_t v___y_152_; uint32_t v___y_153_; uint32_t v___y_154_; uint32_t v___y_155_; uint32_t v___y_163_; uint32_t v___y_164_; uint32_t v___y_165_; uint32_t v___y_175_; uint32_t v___y_176_; uint32_t v___y_177_; uint32_t v___y_178_; uint32_t v___y_186_; uint32_t v___y_187_; uint32_t v___y_188_; uint32_t v___y_198_; uint32_t v___y_199_; uint32_t v___y_200_; uint32_t v___y_201_; uint32_t v___y_209_; uint32_t v___y_210_; uint32_t v___y_211_; uint32_t v___y_221_; uint32_t v___y_222_; uint32_t v___y_223_; uint32_t v___y_224_; uint32_t v___y_232_; uint32_t v___y_233_; uint32_t v___y_234_; uint32_t v___y_244_; uint32_t v___y_245_; uint32_t v___y_246_; uint32_t v___y_247_; uint32_t v___y_255_; uint32_t v___y_256_; uint32_t v___x_266_; uint32_t v___y_268_; 
v___x_113_ = 7ULL;
v___x_114_ = lean_uint64_shift_right(v_byte_95_, v___x_113_);
v___x_115_ = 1ULL;
v___x_116_ = lean_uint64_land(v___x_114_, v___x_115_);
v___x_117_ = lean_uint64_dec_eq(v___x_116_, v___x_115_);
v___x_118_ = 1;
v___x_266_ = lean_uint32_shift_left(v_remainder_94_, v___x_118_);
if (v___x_117_ == 0)
{
uint32_t v___x_275_; 
v___x_275_ = 0;
v___y_268_ = v___x_275_;
goto v___jp_267_;
}
else
{
v___y_268_ = v___x_118_;
goto v___jp_267_;
}
v___jp_96_:
{
uint32_t v___x_100_; uint32_t v___x_101_; 
v___x_100_ = lean_uint32_xor(v___y_97_, v___y_99_);
v___x_101_ = lean_uint32_land(v___x_100_, v___y_98_);
return v___x_101_;
}
v___jp_102_:
{
uint32_t v_shifted_107_; uint32_t v___x_108_; uint32_t v___x_109_; uint32_t v___x_110_; uint8_t v___x_111_; 
v_shifted_107_ = lean_uint32_lor(v___y_104_, v___y_106_);
v___x_108_ = 8388608;
v___x_109_ = lean_uint32_land(v___y_103_, v___x_108_);
v___x_110_ = 0;
v___x_111_ = lean_uint32_dec_eq(v___x_109_, v___x_110_);
if (v___x_111_ == 0)
{
uint32_t v___x_112_; 
v___x_112_ = 33551369;
v___y_97_ = v_shifted_107_;
v___y_98_ = v___y_105_;
v___y_99_ = v___x_112_;
goto v___jp_96_;
}
else
{
v___y_97_ = v_shifted_107_;
v___y_98_ = v___y_105_;
v___y_99_ = v___x_110_;
goto v___jp_96_;
}
}
v___jp_119_:
{
uint32_t v___x_123_; uint32_t v___x_124_; uint64_t v___x_125_; uint8_t v___x_126_; uint32_t v___x_127_; 
v___x_123_ = lean_uint32_xor(v___y_120_, v___y_122_);
v___x_124_ = lean_uint32_land(v___x_123_, v___y_121_);
v___x_125_ = lean_uint64_land(v_byte_95_, v___x_115_);
v___x_126_ = lean_uint64_dec_eq(v___x_125_, v___x_115_);
v___x_127_ = lean_uint32_shift_left(v___x_124_, v___x_118_);
if (v___x_126_ == 0)
{
uint32_t v___x_128_; 
v___x_128_ = 0;
v___y_103_ = v___x_124_;
v___y_104_ = v___x_127_;
v___y_105_ = v___y_121_;
v___y_106_ = v___x_128_;
goto v___jp_102_;
}
else
{
v___y_103_ = v___x_124_;
v___y_104_ = v___x_127_;
v___y_105_ = v___y_121_;
v___y_106_ = v___x_118_;
goto v___jp_102_;
}
}
v___jp_129_:
{
uint32_t v_shifted_134_; uint32_t v___x_135_; uint32_t v___x_136_; uint32_t v___x_137_; uint8_t v___x_138_; 
v_shifted_134_ = lean_uint32_lor(v___y_130_, v___y_133_);
v___x_135_ = 8388608;
v___x_136_ = lean_uint32_land(v___y_131_, v___x_135_);
v___x_137_ = 0;
v___x_138_ = lean_uint32_dec_eq(v___x_136_, v___x_137_);
if (v___x_138_ == 0)
{
uint32_t v___x_139_; 
v___x_139_ = 33551369;
v___y_120_ = v_shifted_134_;
v___y_121_ = v___y_132_;
v___y_122_ = v___x_139_;
goto v___jp_119_;
}
else
{
v___y_120_ = v_shifted_134_;
v___y_121_ = v___y_132_;
v___y_122_ = v___x_137_;
goto v___jp_119_;
}
}
v___jp_140_:
{
uint32_t v___x_144_; uint32_t v___x_145_; uint64_t v___x_146_; uint64_t v___x_147_; uint8_t v___x_148_; uint32_t v___x_149_; 
v___x_144_ = lean_uint32_xor(v___y_141_, v___y_143_);
v___x_145_ = lean_uint32_land(v___x_144_, v___y_142_);
v___x_146_ = lean_uint64_shift_right(v_byte_95_, v___x_115_);
v___x_147_ = lean_uint64_land(v___x_146_, v___x_115_);
v___x_148_ = lean_uint64_dec_eq(v___x_147_, v___x_115_);
v___x_149_ = lean_uint32_shift_left(v___x_145_, v___x_118_);
if (v___x_148_ == 0)
{
uint32_t v___x_150_; 
v___x_150_ = 0;
v___y_130_ = v___x_149_;
v___y_131_ = v___x_145_;
v___y_132_ = v___y_142_;
v___y_133_ = v___x_150_;
goto v___jp_129_;
}
else
{
v___y_130_ = v___x_149_;
v___y_131_ = v___x_145_;
v___y_132_ = v___y_142_;
v___y_133_ = v___x_118_;
goto v___jp_129_;
}
}
v___jp_151_:
{
uint32_t v_shifted_156_; uint32_t v___x_157_; uint32_t v___x_158_; uint32_t v___x_159_; uint8_t v___x_160_; 
v_shifted_156_ = lean_uint32_lor(v___y_154_, v___y_155_);
v___x_157_ = 8388608;
v___x_158_ = lean_uint32_land(v___y_152_, v___x_157_);
v___x_159_ = 0;
v___x_160_ = lean_uint32_dec_eq(v___x_158_, v___x_159_);
if (v___x_160_ == 0)
{
uint32_t v___x_161_; 
v___x_161_ = 33551369;
v___y_141_ = v_shifted_156_;
v___y_142_ = v___y_153_;
v___y_143_ = v___x_161_;
goto v___jp_140_;
}
else
{
v___y_141_ = v_shifted_156_;
v___y_142_ = v___y_153_;
v___y_143_ = v___x_159_;
goto v___jp_140_;
}
}
v___jp_162_:
{
uint32_t v___x_166_; uint32_t v___x_167_; uint64_t v___x_168_; uint64_t v___x_169_; uint64_t v___x_170_; uint8_t v___x_171_; uint32_t v___x_172_; 
v___x_166_ = lean_uint32_xor(v___y_163_, v___y_165_);
v___x_167_ = lean_uint32_land(v___x_166_, v___y_164_);
v___x_168_ = 2ULL;
v___x_169_ = lean_uint64_shift_right(v_byte_95_, v___x_168_);
v___x_170_ = lean_uint64_land(v___x_169_, v___x_115_);
v___x_171_ = lean_uint64_dec_eq(v___x_170_, v___x_115_);
v___x_172_ = lean_uint32_shift_left(v___x_167_, v___x_118_);
if (v___x_171_ == 0)
{
uint32_t v___x_173_; 
v___x_173_ = 0;
v___y_152_ = v___x_167_;
v___y_153_ = v___y_164_;
v___y_154_ = v___x_172_;
v___y_155_ = v___x_173_;
goto v___jp_151_;
}
else
{
v___y_152_ = v___x_167_;
v___y_153_ = v___y_164_;
v___y_154_ = v___x_172_;
v___y_155_ = v___x_118_;
goto v___jp_151_;
}
}
v___jp_174_:
{
uint32_t v_shifted_179_; uint32_t v___x_180_; uint32_t v___x_181_; uint32_t v___x_182_; uint8_t v___x_183_; 
v_shifted_179_ = lean_uint32_lor(v___y_176_, v___y_178_);
v___x_180_ = 8388608;
v___x_181_ = lean_uint32_land(v___y_175_, v___x_180_);
v___x_182_ = 0;
v___x_183_ = lean_uint32_dec_eq(v___x_181_, v___x_182_);
if (v___x_183_ == 0)
{
uint32_t v___x_184_; 
v___x_184_ = 33551369;
v___y_163_ = v_shifted_179_;
v___y_164_ = v___y_177_;
v___y_165_ = v___x_184_;
goto v___jp_162_;
}
else
{
v___y_163_ = v_shifted_179_;
v___y_164_ = v___y_177_;
v___y_165_ = v___x_182_;
goto v___jp_162_;
}
}
v___jp_185_:
{
uint32_t v___x_189_; uint32_t v___x_190_; uint64_t v___x_191_; uint64_t v___x_192_; uint64_t v___x_193_; uint8_t v___x_194_; uint32_t v___x_195_; 
v___x_189_ = lean_uint32_xor(v___y_186_, v___y_188_);
v___x_190_ = lean_uint32_land(v___x_189_, v___y_187_);
v___x_191_ = 3ULL;
v___x_192_ = lean_uint64_shift_right(v_byte_95_, v___x_191_);
v___x_193_ = lean_uint64_land(v___x_192_, v___x_115_);
v___x_194_ = lean_uint64_dec_eq(v___x_193_, v___x_115_);
v___x_195_ = lean_uint32_shift_left(v___x_190_, v___x_118_);
if (v___x_194_ == 0)
{
uint32_t v___x_196_; 
v___x_196_ = 0;
v___y_175_ = v___x_190_;
v___y_176_ = v___x_195_;
v___y_177_ = v___y_187_;
v___y_178_ = v___x_196_;
goto v___jp_174_;
}
else
{
v___y_175_ = v___x_190_;
v___y_176_ = v___x_195_;
v___y_177_ = v___y_187_;
v___y_178_ = v___x_118_;
goto v___jp_174_;
}
}
v___jp_197_:
{
uint32_t v_shifted_202_; uint32_t v___x_203_; uint32_t v___x_204_; uint32_t v___x_205_; uint8_t v___x_206_; 
v_shifted_202_ = lean_uint32_lor(v___y_199_, v___y_201_);
v___x_203_ = 8388608;
v___x_204_ = lean_uint32_land(v___y_198_, v___x_203_);
v___x_205_ = 0;
v___x_206_ = lean_uint32_dec_eq(v___x_204_, v___x_205_);
if (v___x_206_ == 0)
{
uint32_t v___x_207_; 
v___x_207_ = 33551369;
v___y_186_ = v_shifted_202_;
v___y_187_ = v___y_200_;
v___y_188_ = v___x_207_;
goto v___jp_185_;
}
else
{
v___y_186_ = v_shifted_202_;
v___y_187_ = v___y_200_;
v___y_188_ = v___x_205_;
goto v___jp_185_;
}
}
v___jp_208_:
{
uint32_t v___x_212_; uint32_t v___x_213_; uint64_t v___x_214_; uint64_t v___x_215_; uint64_t v___x_216_; uint8_t v___x_217_; uint32_t v___x_218_; 
v___x_212_ = lean_uint32_xor(v___y_209_, v___y_211_);
v___x_213_ = lean_uint32_land(v___x_212_, v___y_210_);
v___x_214_ = 4ULL;
v___x_215_ = lean_uint64_shift_right(v_byte_95_, v___x_214_);
v___x_216_ = lean_uint64_land(v___x_215_, v___x_115_);
v___x_217_ = lean_uint64_dec_eq(v___x_216_, v___x_115_);
v___x_218_ = lean_uint32_shift_left(v___x_213_, v___x_118_);
if (v___x_217_ == 0)
{
uint32_t v___x_219_; 
v___x_219_ = 0;
v___y_198_ = v___x_213_;
v___y_199_ = v___x_218_;
v___y_200_ = v___y_210_;
v___y_201_ = v___x_219_;
goto v___jp_197_;
}
else
{
v___y_198_ = v___x_213_;
v___y_199_ = v___x_218_;
v___y_200_ = v___y_210_;
v___y_201_ = v___x_118_;
goto v___jp_197_;
}
}
v___jp_220_:
{
uint32_t v_shifted_225_; uint32_t v___x_226_; uint32_t v___x_227_; uint32_t v___x_228_; uint8_t v___x_229_; 
v_shifted_225_ = lean_uint32_lor(v___y_221_, v___y_224_);
v___x_226_ = 8388608;
v___x_227_ = lean_uint32_land(v___y_222_, v___x_226_);
v___x_228_ = 0;
v___x_229_ = lean_uint32_dec_eq(v___x_227_, v___x_228_);
if (v___x_229_ == 0)
{
uint32_t v___x_230_; 
v___x_230_ = 33551369;
v___y_209_ = v_shifted_225_;
v___y_210_ = v___y_223_;
v___y_211_ = v___x_230_;
goto v___jp_208_;
}
else
{
v___y_209_ = v_shifted_225_;
v___y_210_ = v___y_223_;
v___y_211_ = v___x_228_;
goto v___jp_208_;
}
}
v___jp_231_:
{
uint32_t v___x_235_; uint32_t v___x_236_; uint64_t v___x_237_; uint64_t v___x_238_; uint64_t v___x_239_; uint8_t v___x_240_; uint32_t v___x_241_; 
v___x_235_ = lean_uint32_xor(v___y_232_, v___y_234_);
v___x_236_ = lean_uint32_land(v___x_235_, v___y_233_);
v___x_237_ = 5ULL;
v___x_238_ = lean_uint64_shift_right(v_byte_95_, v___x_237_);
v___x_239_ = lean_uint64_land(v___x_238_, v___x_115_);
v___x_240_ = lean_uint64_dec_eq(v___x_239_, v___x_115_);
v___x_241_ = lean_uint32_shift_left(v___x_236_, v___x_118_);
if (v___x_240_ == 0)
{
uint32_t v___x_242_; 
v___x_242_ = 0;
v___y_221_ = v___x_241_;
v___y_222_ = v___x_236_;
v___y_223_ = v___y_233_;
v___y_224_ = v___x_242_;
goto v___jp_220_;
}
else
{
v___y_221_ = v___x_241_;
v___y_222_ = v___x_236_;
v___y_223_ = v___y_233_;
v___y_224_ = v___x_118_;
goto v___jp_220_;
}
}
v___jp_243_:
{
uint32_t v_shifted_248_; uint32_t v___x_249_; uint32_t v___x_250_; uint32_t v___x_251_; uint8_t v___x_252_; 
v_shifted_248_ = lean_uint32_lor(v___y_244_, v___y_247_);
v___x_249_ = 8388608;
v___x_250_ = lean_uint32_land(v___y_245_, v___x_249_);
v___x_251_ = 0;
v___x_252_ = lean_uint32_dec_eq(v___x_250_, v___x_251_);
if (v___x_252_ == 0)
{
uint32_t v___x_253_; 
v___x_253_ = 33551369;
v___y_232_ = v_shifted_248_;
v___y_233_ = v___y_246_;
v___y_234_ = v___x_253_;
goto v___jp_231_;
}
else
{
v___y_232_ = v_shifted_248_;
v___y_233_ = v___y_246_;
v___y_234_ = v___x_251_;
goto v___jp_231_;
}
}
v___jp_254_:
{
uint32_t v___x_257_; uint32_t v___x_258_; uint32_t v___x_259_; uint64_t v___x_260_; uint64_t v___x_261_; uint64_t v___x_262_; uint8_t v___x_263_; uint32_t v___x_264_; 
v___x_257_ = lean_uint32_xor(v___y_255_, v___y_256_);
v___x_258_ = 16777215;
v___x_259_ = lean_uint32_land(v___x_257_, v___x_258_);
v___x_260_ = 6ULL;
v___x_261_ = lean_uint64_shift_right(v_byte_95_, v___x_260_);
v___x_262_ = lean_uint64_land(v___x_261_, v___x_115_);
v___x_263_ = lean_uint64_dec_eq(v___x_262_, v___x_115_);
v___x_264_ = lean_uint32_shift_left(v___x_259_, v___x_118_);
if (v___x_263_ == 0)
{
uint32_t v___x_265_; 
v___x_265_ = 0;
v___y_244_ = v___x_264_;
v___y_245_ = v___x_259_;
v___y_246_ = v___x_258_;
v___y_247_ = v___x_265_;
goto v___jp_243_;
}
else
{
v___y_244_ = v___x_264_;
v___y_245_ = v___x_259_;
v___y_246_ = v___x_258_;
v___y_247_ = v___x_118_;
goto v___jp_243_;
}
}
v___jp_267_:
{
uint32_t v_shifted_269_; uint32_t v___x_270_; uint32_t v___x_271_; uint32_t v___x_272_; uint8_t v___x_273_; 
v_shifted_269_ = lean_uint32_lor(v___x_266_, v___y_268_);
v___x_270_ = 8388608;
v___x_271_ = lean_uint32_land(v_remainder_94_, v___x_270_);
v___x_272_ = 0;
v___x_273_ = lean_uint32_dec_eq(v___x_271_, v___x_272_);
if (v___x_273_ == 0)
{
uint32_t v___x_274_; 
v___x_274_ = 33551369;
v___y_255_ = v_shifted_269_;
v___y_256_ = v___x_274_;
goto v___jp_254_;
}
else
{
v___y_255_ = v_shifted_269_;
v___y_256_ = v___x_272_;
goto v___jp_254_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_byteStep___boxed(lean_object* v_remainder_276_, lean_object* v_byte_277_){
_start:
{
uint32_t v_remainder_boxed_278_; uint64_t v_byte_boxed_279_; uint32_t v_res_280_; lean_object* v_r_281_; 
v_remainder_boxed_278_ = lean_unbox_uint32(v_remainder_276_);
lean_dec(v_remainder_276_);
v_byte_boxed_279_ = lean_unbox_uint64(v_byte_277_);
lean_dec_ref(v_byte_277_);
v_res_280_ = lp_lean1090_Lean1090_Impl_Parity_byteStep(v_remainder_boxed_278_, v_byte_boxed_279_);
v_r_281_ = lean_box_uint32(v_res_280_);
return v_r_281_;
}
}
LEAN_EXPORT uint64_t lp_lean1090_Lean1090_Impl_Parity_cachedByte(uint64_t v_low_282_, uint64_t v_high_283_, lean_object* v_offset_284_){
_start:
{
lean_object* v___x_285_; uint8_t v___x_286_; 
v___x_285_ = lean_unsigned_to_nat(64u);
v___x_286_ = lean_nat_dec_lt(v_offset_284_, v___x_285_);
if (v___x_286_ == 0)
{
lean_object* v___x_287_; uint64_t v___x_288_; uint64_t v___x_289_; 
v___x_287_ = lean_nat_sub(v_offset_284_, v___x_285_);
v___x_288_ = lean_uint64_of_nat(v___x_287_);
lean_dec(v___x_287_);
v___x_289_ = lean_uint64_shift_right(v_high_283_, v___x_288_);
return v___x_289_;
}
else
{
uint64_t v___x_290_; uint64_t v___x_291_; 
v___x_290_ = lean_uint64_of_nat(v_offset_284_);
v___x_291_ = lean_uint64_shift_right(v_low_282_, v___x_290_);
return v___x_291_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_cachedByte___boxed(lean_object* v_low_292_, lean_object* v_high_293_, lean_object* v_offset_294_){
_start:
{
uint64_t v_low_boxed_295_; uint64_t v_high_boxed_296_; uint64_t v_res_297_; lean_object* v_r_298_; 
v_low_boxed_295_ = lean_unbox_uint64(v_low_292_);
lean_dec_ref(v_low_292_);
v_high_boxed_296_ = lean_unbox_uint64(v_high_293_);
lean_dec_ref(v_high_293_);
v_res_297_ = lp_lean1090_Lean1090_Impl_Parity_cachedByte(v_low_boxed_295_, v_high_boxed_296_, v_offset_294_);
lean_dec(v_offset_294_);
v_r_298_ = lean_box_uint64(v_res_297_);
return v_r_298_;
}
}
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg(lean_object* v_width_299_, lean_object* v_word_300_, uint64_t v_high_301_, uint64_t v_low_302_, lean_object* v_n_303_, lean_object* v_j_304_, uint32_t v_a_305_){
_start:
{
lean_object* v_zero_306_; uint8_t v_isZero_307_; 
v_zero_306_ = lean_unsigned_to_nat(0u);
v_isZero_307_ = lean_nat_dec_eq(v_j_304_, v_zero_306_);
if (v_isZero_307_ == 1)
{
lean_dec(v_j_304_);
return v_a_305_;
}
else
{
lean_object* v_one_308_; lean_object* v_n_309_; uint32_t v___y_311_; uint32_t v___y_312_; uint32_t v___y_318_; uint32_t v___y_319_; uint8_t v___y_327_; lean_object* v___x_331_; lean_object* v___x_332_; lean_object* v___x_333_; lean_object* v___x_334_; uint8_t v___x_335_; 
v_one_308_ = lean_unsigned_to_nat(1u);
v_n_309_ = lean_nat_sub(v_j_304_, v_one_308_);
v___x_331_ = lean_nat_sub(v_n_303_, v_j_304_);
lean_dec(v_j_304_);
v___x_332_ = lean_nat_sub(v_width_299_, v_one_308_);
v___x_333_ = lean_nat_sub(v___x_332_, v___x_331_);
lean_dec(v___x_331_);
lean_dec(v___x_332_);
v___x_334_ = lean_unsigned_to_nat(64u);
v___x_335_ = lean_nat_dec_lt(v___x_333_, v___x_334_);
if (v___x_335_ == 0)
{
lean_object* v___x_336_; uint8_t v___x_337_; 
v___x_336_ = lean_unsigned_to_nat(128u);
v___x_337_ = lean_nat_dec_lt(v___x_333_, v___x_336_);
if (v___x_337_ == 0)
{
uint8_t v___x_338_; 
v___x_338_ = l_Nat_testBit(v_word_300_, v___x_333_);
lean_dec(v___x_333_);
v___y_327_ = v___x_338_;
goto v___jp_326_;
}
else
{
lean_object* v___x_339_; uint64_t v___x_340_; uint64_t v___x_341_; uint64_t v___x_342_; uint64_t v___x_343_; uint8_t v___x_344_; 
v___x_339_ = lean_nat_sub(v___x_333_, v___x_334_);
lean_dec(v___x_333_);
v___x_340_ = lean_uint64_of_nat(v___x_339_);
lean_dec(v___x_339_);
v___x_341_ = lean_uint64_shift_right(v_high_301_, v___x_340_);
v___x_342_ = 1ULL;
v___x_343_ = lean_uint64_land(v___x_341_, v___x_342_);
v___x_344_ = lean_uint64_dec_eq(v___x_343_, v___x_342_);
v___y_327_ = v___x_344_;
goto v___jp_326_;
}
}
else
{
uint64_t v___x_345_; uint64_t v___x_346_; uint64_t v___x_347_; uint64_t v___x_348_; uint8_t v___x_349_; 
v___x_345_ = lean_uint64_of_nat(v___x_333_);
lean_dec(v___x_333_);
v___x_346_ = lean_uint64_shift_right(v_low_302_, v___x_345_);
v___x_347_ = 1ULL;
v___x_348_ = lean_uint64_land(v___x_346_, v___x_347_);
v___x_349_ = lean_uint64_dec_eq(v___x_348_, v___x_347_);
v___y_327_ = v___x_349_;
goto v___jp_326_;
}
v___jp_310_:
{
uint32_t v___x_313_; uint32_t v___x_314_; uint32_t v___x_315_; 
v___x_313_ = lean_uint32_xor(v___y_311_, v___y_312_);
v___x_314_ = 16777215;
v___x_315_ = lean_uint32_land(v___x_313_, v___x_314_);
v_j_304_ = v_n_309_;
v_a_305_ = v___x_315_;
goto _start;
}
v___jp_317_:
{
uint32_t v_shifted_320_; uint32_t v___x_321_; uint32_t v___x_322_; uint32_t v___x_323_; uint8_t v___x_324_; 
v_shifted_320_ = lean_uint32_lor(v___y_318_, v___y_319_);
v___x_321_ = 8388608;
v___x_322_ = lean_uint32_land(v_a_305_, v___x_321_);
v___x_323_ = 0;
v___x_324_ = lean_uint32_dec_eq(v___x_322_, v___x_323_);
if (v___x_324_ == 0)
{
uint32_t v___x_325_; 
v___x_325_ = 33551369;
v___y_311_ = v_shifted_320_;
v___y_312_ = v___x_325_;
goto v___jp_310_;
}
else
{
v___y_311_ = v_shifted_320_;
v___y_312_ = v___x_323_;
goto v___jp_310_;
}
}
v___jp_326_:
{
uint32_t v___x_328_; uint32_t v___x_329_; 
v___x_328_ = 1;
v___x_329_ = lean_uint32_shift_left(v_a_305_, v___x_328_);
if (v___y_327_ == 0)
{
uint32_t v___x_330_; 
v___x_330_ = 0;
v___y_318_ = v___x_329_;
v___y_319_ = v___x_330_;
goto v___jp_317_;
}
else
{
v___y_318_ = v___x_329_;
v___y_319_ = v___x_328_;
goto v___jp_317_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg___boxed(lean_object* v_width_350_, lean_object* v_word_351_, lean_object* v_high_352_, lean_object* v_low_353_, lean_object* v_n_354_, lean_object* v_j_355_, lean_object* v_a_356_){
_start:
{
uint64_t v_high_boxed_357_; uint64_t v_low_boxed_358_; uint32_t v_a_239__boxed_359_; uint32_t v_res_360_; lean_object* v_r_361_; 
v_high_boxed_357_ = lean_unbox_uint64(v_high_352_);
lean_dec_ref(v_high_352_);
v_low_boxed_358_ = lean_unbox_uint64(v_low_353_);
lean_dec_ref(v_low_353_);
v_a_239__boxed_359_ = lean_unbox_uint32(v_a_356_);
lean_dec(v_a_356_);
v_res_360_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg(v_width_350_, v_word_351_, v_high_boxed_357_, v_low_boxed_358_, v_n_354_, v_j_355_, v_a_239__boxed_359_);
lean_dec(v_n_354_);
lean_dec(v_word_351_);
lean_dec(v_width_350_);
v_r_361_ = lean_box_uint32(v_res_360_);
return v_r_361_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBits(lean_object* v_width_362_, lean_object* v_word_363_){
_start:
{
uint64_t v_low_364_; lean_object* v___x_365_; lean_object* v___x_366_; uint64_t v_high_367_; uint32_t v___x_368_; uint32_t v_remainder_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; 
v_low_364_ = lean_uint64_of_nat(v_word_363_);
v___x_365_ = lean_unsigned_to_nat(64u);
v___x_366_ = lean_nat_shiftr(v_word_363_, v___x_365_);
v_high_367_ = lean_uint64_of_nat(v___x_366_);
lean_dec(v___x_366_);
v___x_368_ = 0;
lean_inc(v_width_362_);
v_remainder_369_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg(v_width_362_, v_word_363_, v_high_367_, v_low_364_, v_width_362_, v_width_362_, v___x_368_);
lean_dec(v_width_362_);
v___x_370_ = lean_unsigned_to_nat(24u);
v___x_371_ = lean_uint32_to_nat(v_remainder_369_);
v___x_372_ = l_BitVec_ofNat(v___x_370_, v___x_371_);
lean_dec(v___x_371_);
return v___x_372_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBits___boxed(lean_object* v_width_373_, lean_object* v_word_374_){
_start:
{
lean_object* v_res_375_; 
v_res_375_ = lp_lean1090_Lean1090_Impl_Parity_syndromeBits(v_width_373_, v_word_374_);
lean_dec(v_word_374_);
return v_res_375_;
}
}
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0(lean_object* v_width_376_, lean_object* v_word_377_, uint64_t v_high_378_, uint64_t v_low_379_, lean_object* v_n_380_, lean_object* v_j_381_, lean_object* v_a_382_, uint32_t v_a_383_){
_start:
{
uint32_t v___x_384_; 
v___x_384_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg(v_width_376_, v_word_377_, v_high_378_, v_low_379_, v_n_380_, v_j_381_, v_a_383_);
return v___x_384_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___boxed(lean_object* v_width_385_, lean_object* v_word_386_, lean_object* v_high_387_, lean_object* v_low_388_, lean_object* v_n_389_, lean_object* v_j_390_, lean_object* v_a_391_, lean_object* v_a_392_){
_start:
{
uint64_t v_high_boxed_393_; uint64_t v_low_boxed_394_; uint32_t v_a_335__boxed_395_; uint32_t v_res_396_; lean_object* v_r_397_; 
v_high_boxed_393_ = lean_unbox_uint64(v_high_387_);
lean_dec_ref(v_high_387_);
v_low_boxed_394_ = lean_unbox_uint64(v_low_388_);
lean_dec_ref(v_low_388_);
v_a_335__boxed_395_ = lean_unbox_uint32(v_a_392_);
lean_dec(v_a_392_);
v_res_396_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0(v_width_385_, v_word_386_, v_high_boxed_393_, v_low_boxed_394_, v_n_389_, v_j_390_, v_a_391_, v_a_335__boxed_395_);
lean_dec(v_n_389_);
lean_dec(v_word_386_);
lean_dec(v_width_385_);
v_r_397_ = lean_box_uint32(v_res_396_);
return v_r_397_;
}
}
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg(lean_object* v_byteCount_398_, uint64_t v_high_399_, uint64_t v_low_400_, lean_object* v_n_401_, lean_object* v_j_402_, uint32_t v_a_403_){
_start:
{
lean_object* v_zero_404_; uint8_t v_isZero_405_; 
v_zero_404_ = lean_unsigned_to_nat(0u);
v_isZero_405_ = lean_nat_dec_eq(v_j_402_, v_zero_404_);
if (v_isZero_405_ == 1)
{
lean_dec(v_j_402_);
return v_a_403_;
}
else
{
lean_object* v_one_406_; lean_object* v_n_407_; uint32_t v___y_409_; uint32_t v___y_410_; uint32_t v___y_411_; uint32_t v___y_416_; uint32_t v___y_417_; uint32_t v___y_418_; uint32_t v___y_419_; uint32_t v___y_427_; uint64_t v___y_428_; uint32_t v___y_429_; uint64_t v___y_430_; uint32_t v___y_431_; uint32_t v___y_432_; uint32_t v___y_440_; uint32_t v___y_441_; uint64_t v___y_442_; uint32_t v___y_443_; uint64_t v___y_444_; uint32_t v___y_445_; uint32_t v___y_446_; uint32_t v___y_454_; uint64_t v___y_455_; uint64_t v___y_456_; uint32_t v___y_457_; uint32_t v___y_458_; uint32_t v___y_459_; uint32_t v___y_468_; uint64_t v___y_469_; uint32_t v___y_470_; uint32_t v___y_471_; uint64_t v___y_472_; uint32_t v___y_473_; uint32_t v___y_474_; uint32_t v___y_482_; uint64_t v___y_483_; uint64_t v___y_484_; uint32_t v___y_485_; uint32_t v___y_486_; uint32_t v___y_487_; uint32_t v___y_497_; uint64_t v___y_498_; uint64_t v___y_499_; uint32_t v___y_500_; uint32_t v___y_501_; uint32_t v___y_502_; uint32_t v___y_503_; uint32_t v___y_511_; uint64_t v___y_512_; uint32_t v___y_513_; uint64_t v___y_514_; uint32_t v___y_515_; uint32_t v___y_516_; uint32_t v___y_526_; uint64_t v___y_527_; uint64_t v___y_528_; uint32_t v___y_529_; uint32_t v___y_530_; uint32_t v___y_531_; uint32_t v___y_532_; uint32_t v___y_540_; uint64_t v___y_541_; uint32_t v___y_542_; uint64_t v___y_543_; uint32_t v___y_544_; uint32_t v___y_545_; uint32_t v___y_555_; uint32_t v___y_556_; uint64_t v___y_557_; uint64_t v___y_558_; uint32_t v___y_559_; uint32_t v___y_560_; uint32_t v___y_561_; uint32_t v___y_569_; uint64_t v___y_570_; uint32_t v___y_571_; uint64_t v___y_572_; uint32_t v___y_573_; uint32_t v___y_574_; uint32_t v___y_584_; uint64_t v___y_585_; uint32_t v___y_586_; uint32_t v___y_587_; uint64_t v___y_588_; uint32_t v___y_589_; uint32_t v___y_590_; uint32_t v___y_598_; uint64_t v___y_599_; uint32_t v___y_600_; uint64_t v___y_601_; uint32_t v___y_602_; uint32_t v___y_613_; uint64_t v___y_614_; uint64_t v___y_615_; uint32_t v___y_616_; uint32_t v___y_617_; uint64_t v___y_625_; lean_object* v___x_634_; lean_object* v___x_635_; lean_object* v___x_636_; lean_object* v___x_637_; lean_object* v___x_638_; lean_object* v___x_639_; uint8_t v___x_640_; 
v_one_406_ = lean_unsigned_to_nat(1u);
v_n_407_ = lean_nat_sub(v_j_402_, v_one_406_);
v___x_634_ = lean_nat_sub(v_n_401_, v_j_402_);
lean_dec(v_j_402_);
v___x_635_ = lean_unsigned_to_nat(8u);
v___x_636_ = lean_nat_sub(v_byteCount_398_, v_one_406_);
v___x_637_ = lean_nat_sub(v___x_636_, v___x_634_);
lean_dec(v___x_634_);
lean_dec(v___x_636_);
v___x_638_ = lean_nat_mul(v___x_635_, v___x_637_);
lean_dec(v___x_637_);
v___x_639_ = lean_unsigned_to_nat(64u);
v___x_640_ = lean_nat_dec_lt(v___x_638_, v___x_639_);
if (v___x_640_ == 0)
{
lean_object* v___x_641_; uint64_t v___x_642_; uint64_t v___x_643_; 
v___x_641_ = lean_nat_sub(v___x_638_, v___x_639_);
lean_dec(v___x_638_);
v___x_642_ = lean_uint64_of_nat(v___x_641_);
lean_dec(v___x_641_);
v___x_643_ = lean_uint64_shift_right(v_high_399_, v___x_642_);
v___y_625_ = v___x_643_;
goto v___jp_624_;
}
else
{
uint64_t v___x_644_; uint64_t v___x_645_; 
v___x_644_ = lean_uint64_of_nat(v___x_638_);
lean_dec(v___x_638_);
v___x_645_ = lean_uint64_shift_right(v_low_400_, v___x_644_);
v___y_625_ = v___x_645_;
goto v___jp_624_;
}
v___jp_408_:
{
uint32_t v___x_412_; uint32_t v___x_413_; 
v___x_412_ = lean_uint32_xor(v___y_410_, v___y_411_);
v___x_413_ = lean_uint32_land(v___x_412_, v___y_409_);
v_j_402_ = v_n_407_;
v_a_403_ = v___x_413_;
goto _start;
}
v___jp_415_:
{
uint32_t v_shifted_420_; uint32_t v___x_421_; uint32_t v___x_422_; uint32_t v___x_423_; uint8_t v___x_424_; 
v_shifted_420_ = lean_uint32_lor(v___y_417_, v___y_419_);
v___x_421_ = 8388608;
v___x_422_ = lean_uint32_land(v___y_416_, v___x_421_);
v___x_423_ = 0;
v___x_424_ = lean_uint32_dec_eq(v___x_422_, v___x_423_);
if (v___x_424_ == 0)
{
uint32_t v___x_425_; 
v___x_425_ = 33551369;
v___y_409_ = v___y_418_;
v___y_410_ = v_shifted_420_;
v___y_411_ = v___x_425_;
goto v___jp_408_;
}
else
{
v___y_409_ = v___y_418_;
v___y_410_ = v_shifted_420_;
v___y_411_ = v___x_423_;
goto v___jp_408_;
}
}
v___jp_426_:
{
uint32_t v___x_433_; uint32_t v___x_434_; uint64_t v___x_435_; uint8_t v___x_436_; uint32_t v___x_437_; 
v___x_433_ = lean_uint32_xor(v___y_429_, v___y_432_);
v___x_434_ = lean_uint32_land(v___x_433_, v___y_431_);
v___x_435_ = lean_uint64_land(v___y_430_, v___y_428_);
v___x_436_ = lean_uint64_dec_eq(v___x_435_, v___y_428_);
v___x_437_ = lean_uint32_shift_left(v___x_434_, v___y_427_);
if (v___x_436_ == 0)
{
uint32_t v___x_438_; 
v___x_438_ = 0;
v___y_416_ = v___x_434_;
v___y_417_ = v___x_437_;
v___y_418_ = v___y_431_;
v___y_419_ = v___x_438_;
goto v___jp_415_;
}
else
{
v___y_416_ = v___x_434_;
v___y_417_ = v___x_437_;
v___y_418_ = v___y_431_;
v___y_419_ = v___y_427_;
goto v___jp_415_;
}
}
v___jp_439_:
{
uint32_t v_shifted_447_; uint32_t v___x_448_; uint32_t v___x_449_; uint32_t v___x_450_; uint8_t v___x_451_; 
v_shifted_447_ = lean_uint32_lor(v___y_443_, v___y_446_);
v___x_448_ = 8388608;
v___x_449_ = lean_uint32_land(v___y_441_, v___x_448_);
v___x_450_ = 0;
v___x_451_ = lean_uint32_dec_eq(v___x_449_, v___x_450_);
if (v___x_451_ == 0)
{
uint32_t v___x_452_; 
v___x_452_ = 33551369;
v___y_427_ = v___y_440_;
v___y_428_ = v___y_442_;
v___y_429_ = v_shifted_447_;
v___y_430_ = v___y_444_;
v___y_431_ = v___y_445_;
v___y_432_ = v___x_452_;
goto v___jp_426_;
}
else
{
v___y_427_ = v___y_440_;
v___y_428_ = v___y_442_;
v___y_429_ = v_shifted_447_;
v___y_430_ = v___y_444_;
v___y_431_ = v___y_445_;
v___y_432_ = v___x_450_;
goto v___jp_426_;
}
}
v___jp_453_:
{
uint32_t v___x_460_; uint32_t v___x_461_; uint64_t v___x_462_; uint64_t v___x_463_; uint8_t v___x_464_; uint32_t v___x_465_; 
v___x_460_ = lean_uint32_xor(v___y_458_, v___y_459_);
v___x_461_ = lean_uint32_land(v___x_460_, v___y_457_);
v___x_462_ = lean_uint64_shift_right(v___y_456_, v___y_455_);
v___x_463_ = lean_uint64_land(v___x_462_, v___y_455_);
v___x_464_ = lean_uint64_dec_eq(v___x_463_, v___y_455_);
v___x_465_ = lean_uint32_shift_left(v___x_461_, v___y_454_);
if (v___x_464_ == 0)
{
uint32_t v___x_466_; 
v___x_466_ = 0;
v___y_440_ = v___y_454_;
v___y_441_ = v___x_461_;
v___y_442_ = v___y_455_;
v___y_443_ = v___x_465_;
v___y_444_ = v___y_456_;
v___y_445_ = v___y_457_;
v___y_446_ = v___x_466_;
goto v___jp_439_;
}
else
{
v___y_440_ = v___y_454_;
v___y_441_ = v___x_461_;
v___y_442_ = v___y_455_;
v___y_443_ = v___x_465_;
v___y_444_ = v___y_456_;
v___y_445_ = v___y_457_;
v___y_446_ = v___y_454_;
goto v___jp_439_;
}
}
v___jp_467_:
{
uint32_t v_shifted_475_; uint32_t v___x_476_; uint32_t v___x_477_; uint32_t v___x_478_; uint8_t v___x_479_; 
v_shifted_475_ = lean_uint32_lor(v___y_470_, v___y_474_);
v___x_476_ = 8388608;
v___x_477_ = lean_uint32_land(v___y_471_, v___x_476_);
v___x_478_ = 0;
v___x_479_ = lean_uint32_dec_eq(v___x_477_, v___x_478_);
if (v___x_479_ == 0)
{
uint32_t v___x_480_; 
v___x_480_ = 33551369;
v___y_454_ = v___y_468_;
v___y_455_ = v___y_469_;
v___y_456_ = v___y_472_;
v___y_457_ = v___y_473_;
v___y_458_ = v_shifted_475_;
v___y_459_ = v___x_480_;
goto v___jp_453_;
}
else
{
v___y_454_ = v___y_468_;
v___y_455_ = v___y_469_;
v___y_456_ = v___y_472_;
v___y_457_ = v___y_473_;
v___y_458_ = v_shifted_475_;
v___y_459_ = v___x_478_;
goto v___jp_453_;
}
}
v___jp_481_:
{
uint32_t v___x_488_; uint32_t v___x_489_; uint64_t v___x_490_; uint64_t v___x_491_; uint64_t v___x_492_; uint8_t v___x_493_; uint32_t v___x_494_; 
v___x_488_ = lean_uint32_xor(v___y_485_, v___y_487_);
v___x_489_ = lean_uint32_land(v___x_488_, v___y_486_);
v___x_490_ = 2ULL;
v___x_491_ = lean_uint64_shift_right(v___y_484_, v___x_490_);
v___x_492_ = lean_uint64_land(v___x_491_, v___y_483_);
v___x_493_ = lean_uint64_dec_eq(v___x_492_, v___y_483_);
v___x_494_ = lean_uint32_shift_left(v___x_489_, v___y_482_);
if (v___x_493_ == 0)
{
uint32_t v___x_495_; 
v___x_495_ = 0;
v___y_468_ = v___y_482_;
v___y_469_ = v___y_483_;
v___y_470_ = v___x_494_;
v___y_471_ = v___x_489_;
v___y_472_ = v___y_484_;
v___y_473_ = v___y_486_;
v___y_474_ = v___x_495_;
goto v___jp_467_;
}
else
{
v___y_468_ = v___y_482_;
v___y_469_ = v___y_483_;
v___y_470_ = v___x_494_;
v___y_471_ = v___x_489_;
v___y_472_ = v___y_484_;
v___y_473_ = v___y_486_;
v___y_474_ = v___y_482_;
goto v___jp_467_;
}
}
v___jp_496_:
{
uint32_t v_shifted_504_; uint32_t v___x_505_; uint32_t v___x_506_; uint32_t v___x_507_; uint8_t v___x_508_; 
v_shifted_504_ = lean_uint32_lor(v___y_502_, v___y_503_);
v___x_505_ = 8388608;
v___x_506_ = lean_uint32_land(v___y_500_, v___x_505_);
v___x_507_ = 0;
v___x_508_ = lean_uint32_dec_eq(v___x_506_, v___x_507_);
if (v___x_508_ == 0)
{
uint32_t v___x_509_; 
v___x_509_ = 33551369;
v___y_482_ = v___y_497_;
v___y_483_ = v___y_498_;
v___y_484_ = v___y_499_;
v___y_485_ = v_shifted_504_;
v___y_486_ = v___y_501_;
v___y_487_ = v___x_509_;
goto v___jp_481_;
}
else
{
v___y_482_ = v___y_497_;
v___y_483_ = v___y_498_;
v___y_484_ = v___y_499_;
v___y_485_ = v_shifted_504_;
v___y_486_ = v___y_501_;
v___y_487_ = v___x_507_;
goto v___jp_481_;
}
}
v___jp_510_:
{
uint32_t v___x_517_; uint32_t v___x_518_; uint64_t v___x_519_; uint64_t v___x_520_; uint64_t v___x_521_; uint8_t v___x_522_; uint32_t v___x_523_; 
v___x_517_ = lean_uint32_xor(v___y_513_, v___y_516_);
v___x_518_ = lean_uint32_land(v___x_517_, v___y_515_);
v___x_519_ = 3ULL;
v___x_520_ = lean_uint64_shift_right(v___y_514_, v___x_519_);
v___x_521_ = lean_uint64_land(v___x_520_, v___y_512_);
v___x_522_ = lean_uint64_dec_eq(v___x_521_, v___y_512_);
v___x_523_ = lean_uint32_shift_left(v___x_518_, v___y_511_);
if (v___x_522_ == 0)
{
uint32_t v___x_524_; 
v___x_524_ = 0;
v___y_497_ = v___y_511_;
v___y_498_ = v___y_512_;
v___y_499_ = v___y_514_;
v___y_500_ = v___x_518_;
v___y_501_ = v___y_515_;
v___y_502_ = v___x_523_;
v___y_503_ = v___x_524_;
goto v___jp_496_;
}
else
{
v___y_497_ = v___y_511_;
v___y_498_ = v___y_512_;
v___y_499_ = v___y_514_;
v___y_500_ = v___x_518_;
v___y_501_ = v___y_515_;
v___y_502_ = v___x_523_;
v___y_503_ = v___y_511_;
goto v___jp_496_;
}
}
v___jp_525_:
{
uint32_t v_shifted_533_; uint32_t v___x_534_; uint32_t v___x_535_; uint32_t v___x_536_; uint8_t v___x_537_; 
v_shifted_533_ = lean_uint32_lor(v___y_529_, v___y_532_);
v___x_534_ = 8388608;
v___x_535_ = lean_uint32_land(v___y_531_, v___x_534_);
v___x_536_ = 0;
v___x_537_ = lean_uint32_dec_eq(v___x_535_, v___x_536_);
if (v___x_537_ == 0)
{
uint32_t v___x_538_; 
v___x_538_ = 33551369;
v___y_511_ = v___y_526_;
v___y_512_ = v___y_527_;
v___y_513_ = v_shifted_533_;
v___y_514_ = v___y_528_;
v___y_515_ = v___y_530_;
v___y_516_ = v___x_538_;
goto v___jp_510_;
}
else
{
v___y_511_ = v___y_526_;
v___y_512_ = v___y_527_;
v___y_513_ = v_shifted_533_;
v___y_514_ = v___y_528_;
v___y_515_ = v___y_530_;
v___y_516_ = v___x_536_;
goto v___jp_510_;
}
}
v___jp_539_:
{
uint32_t v___x_546_; uint32_t v___x_547_; uint64_t v___x_548_; uint64_t v___x_549_; uint64_t v___x_550_; uint8_t v___x_551_; uint32_t v___x_552_; 
v___x_546_ = lean_uint32_xor(v___y_542_, v___y_545_);
v___x_547_ = lean_uint32_land(v___x_546_, v___y_544_);
v___x_548_ = 4ULL;
v___x_549_ = lean_uint64_shift_right(v___y_543_, v___x_548_);
v___x_550_ = lean_uint64_land(v___x_549_, v___y_541_);
v___x_551_ = lean_uint64_dec_eq(v___x_550_, v___y_541_);
v___x_552_ = lean_uint32_shift_left(v___x_547_, v___y_540_);
if (v___x_551_ == 0)
{
uint32_t v___x_553_; 
v___x_553_ = 0;
v___y_526_ = v___y_540_;
v___y_527_ = v___y_541_;
v___y_528_ = v___y_543_;
v___y_529_ = v___x_552_;
v___y_530_ = v___y_544_;
v___y_531_ = v___x_547_;
v___y_532_ = v___x_553_;
goto v___jp_525_;
}
else
{
v___y_526_ = v___y_540_;
v___y_527_ = v___y_541_;
v___y_528_ = v___y_543_;
v___y_529_ = v___x_552_;
v___y_530_ = v___y_544_;
v___y_531_ = v___x_547_;
v___y_532_ = v___y_540_;
goto v___jp_525_;
}
}
v___jp_554_:
{
uint32_t v_shifted_562_; uint32_t v___x_563_; uint32_t v___x_564_; uint32_t v___x_565_; uint8_t v___x_566_; 
v_shifted_562_ = lean_uint32_lor(v___y_560_, v___y_561_);
v___x_563_ = 8388608;
v___x_564_ = lean_uint32_land(v___y_556_, v___x_563_);
v___x_565_ = 0;
v___x_566_ = lean_uint32_dec_eq(v___x_564_, v___x_565_);
if (v___x_566_ == 0)
{
uint32_t v___x_567_; 
v___x_567_ = 33551369;
v___y_540_ = v___y_555_;
v___y_541_ = v___y_557_;
v___y_542_ = v_shifted_562_;
v___y_543_ = v___y_558_;
v___y_544_ = v___y_559_;
v___y_545_ = v___x_567_;
goto v___jp_539_;
}
else
{
v___y_540_ = v___y_555_;
v___y_541_ = v___y_557_;
v___y_542_ = v_shifted_562_;
v___y_543_ = v___y_558_;
v___y_544_ = v___y_559_;
v___y_545_ = v___x_565_;
goto v___jp_539_;
}
}
v___jp_568_:
{
uint32_t v___x_575_; uint32_t v___x_576_; uint64_t v___x_577_; uint64_t v___x_578_; uint64_t v___x_579_; uint8_t v___x_580_; uint32_t v___x_581_; 
v___x_575_ = lean_uint32_xor(v___y_571_, v___y_574_);
v___x_576_ = lean_uint32_land(v___x_575_, v___y_573_);
v___x_577_ = 5ULL;
v___x_578_ = lean_uint64_shift_right(v___y_572_, v___x_577_);
v___x_579_ = lean_uint64_land(v___x_578_, v___y_570_);
v___x_580_ = lean_uint64_dec_eq(v___x_579_, v___y_570_);
v___x_581_ = lean_uint32_shift_left(v___x_576_, v___y_569_);
if (v___x_580_ == 0)
{
uint32_t v___x_582_; 
v___x_582_ = 0;
v___y_555_ = v___y_569_;
v___y_556_ = v___x_576_;
v___y_557_ = v___y_570_;
v___y_558_ = v___y_572_;
v___y_559_ = v___y_573_;
v___y_560_ = v___x_581_;
v___y_561_ = v___x_582_;
goto v___jp_554_;
}
else
{
v___y_555_ = v___y_569_;
v___y_556_ = v___x_576_;
v___y_557_ = v___y_570_;
v___y_558_ = v___y_572_;
v___y_559_ = v___y_573_;
v___y_560_ = v___x_581_;
v___y_561_ = v___y_569_;
goto v___jp_554_;
}
}
v___jp_583_:
{
uint32_t v_shifted_591_; uint32_t v___x_592_; uint32_t v___x_593_; uint32_t v___x_594_; uint8_t v___x_595_; 
v_shifted_591_ = lean_uint32_lor(v___y_587_, v___y_590_);
v___x_592_ = 8388608;
v___x_593_ = lean_uint32_land(v___y_586_, v___x_592_);
v___x_594_ = 0;
v___x_595_ = lean_uint32_dec_eq(v___x_593_, v___x_594_);
if (v___x_595_ == 0)
{
uint32_t v___x_596_; 
v___x_596_ = 33551369;
v___y_569_ = v___y_584_;
v___y_570_ = v___y_585_;
v___y_571_ = v_shifted_591_;
v___y_572_ = v___y_588_;
v___y_573_ = v___y_589_;
v___y_574_ = v___x_596_;
goto v___jp_568_;
}
else
{
v___y_569_ = v___y_584_;
v___y_570_ = v___y_585_;
v___y_571_ = v_shifted_591_;
v___y_572_ = v___y_588_;
v___y_573_ = v___y_589_;
v___y_574_ = v___x_594_;
goto v___jp_568_;
}
}
v___jp_597_:
{
uint32_t v___x_603_; uint32_t v___x_604_; uint32_t v___x_605_; uint64_t v___x_606_; uint64_t v___x_607_; uint64_t v___x_608_; uint8_t v___x_609_; uint32_t v___x_610_; 
v___x_603_ = lean_uint32_xor(v___y_600_, v___y_602_);
v___x_604_ = 16777215;
v___x_605_ = lean_uint32_land(v___x_603_, v___x_604_);
v___x_606_ = 6ULL;
v___x_607_ = lean_uint64_shift_right(v___y_601_, v___x_606_);
v___x_608_ = lean_uint64_land(v___x_607_, v___y_599_);
v___x_609_ = lean_uint64_dec_eq(v___x_608_, v___y_599_);
v___x_610_ = lean_uint32_shift_left(v___x_605_, v___y_598_);
if (v___x_609_ == 0)
{
uint32_t v___x_611_; 
v___x_611_ = 0;
v___y_584_ = v___y_598_;
v___y_585_ = v___y_599_;
v___y_586_ = v___x_605_;
v___y_587_ = v___x_610_;
v___y_588_ = v___y_601_;
v___y_589_ = v___x_604_;
v___y_590_ = v___x_611_;
goto v___jp_583_;
}
else
{
v___y_584_ = v___y_598_;
v___y_585_ = v___y_599_;
v___y_586_ = v___x_605_;
v___y_587_ = v___x_610_;
v___y_588_ = v___y_601_;
v___y_589_ = v___x_604_;
v___y_590_ = v___y_598_;
goto v___jp_583_;
}
}
v___jp_612_:
{
uint32_t v_shifted_618_; uint32_t v___x_619_; uint32_t v___x_620_; uint32_t v___x_621_; uint8_t v___x_622_; 
v_shifted_618_ = lean_uint32_lor(v___y_616_, v___y_617_);
v___x_619_ = 8388608;
v___x_620_ = lean_uint32_land(v_a_403_, v___x_619_);
v___x_621_ = 0;
v___x_622_ = lean_uint32_dec_eq(v___x_620_, v___x_621_);
if (v___x_622_ == 0)
{
uint32_t v___x_623_; 
v___x_623_ = 33551369;
v___y_598_ = v___y_613_;
v___y_599_ = v___y_614_;
v___y_600_ = v_shifted_618_;
v___y_601_ = v___y_615_;
v___y_602_ = v___x_623_;
goto v___jp_597_;
}
else
{
v___y_598_ = v___y_613_;
v___y_599_ = v___y_614_;
v___y_600_ = v_shifted_618_;
v___y_601_ = v___y_615_;
v___y_602_ = v___x_621_;
goto v___jp_597_;
}
}
v___jp_624_:
{
uint64_t v___x_626_; uint64_t v___x_627_; uint64_t v___x_628_; uint64_t v___x_629_; uint8_t v___x_630_; uint32_t v___x_631_; uint32_t v___x_632_; 
v___x_626_ = 7ULL;
v___x_627_ = lean_uint64_shift_right(v___y_625_, v___x_626_);
v___x_628_ = 1ULL;
v___x_629_ = lean_uint64_land(v___x_627_, v___x_628_);
v___x_630_ = lean_uint64_dec_eq(v___x_629_, v___x_628_);
v___x_631_ = 1;
v___x_632_ = lean_uint32_shift_left(v_a_403_, v___x_631_);
if (v___x_630_ == 0)
{
uint32_t v___x_633_; 
v___x_633_ = 0;
v___y_613_ = v___x_631_;
v___y_614_ = v___x_628_;
v___y_615_ = v___y_625_;
v___y_616_ = v___x_632_;
v___y_617_ = v___x_633_;
goto v___jp_612_;
}
else
{
v___y_613_ = v___x_631_;
v___y_614_ = v___x_628_;
v___y_615_ = v___y_625_;
v___y_616_ = v___x_632_;
v___y_617_ = v___x_631_;
goto v___jp_612_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg___boxed(lean_object* v_byteCount_646_, lean_object* v_high_647_, lean_object* v_low_648_, lean_object* v_n_649_, lean_object* v_j_650_, lean_object* v_a_651_){
_start:
{
uint64_t v_high_boxed_652_; uint64_t v_low_boxed_653_; uint32_t v_a_864__boxed_654_; uint32_t v_res_655_; lean_object* v_r_656_; 
v_high_boxed_652_ = lean_unbox_uint64(v_high_647_);
lean_dec_ref(v_high_647_);
v_low_boxed_653_ = lean_unbox_uint64(v_low_648_);
lean_dec_ref(v_low_648_);
v_a_864__boxed_654_ = lean_unbox_uint32(v_a_651_);
lean_dec(v_a_651_);
v_res_655_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg(v_byteCount_646_, v_high_boxed_652_, v_low_boxed_653_, v_n_649_, v_j_650_, v_a_864__boxed_654_);
lean_dec(v_n_649_);
lean_dec(v_byteCount_646_);
v_r_656_ = lean_box_uint32(v_res_655_);
return v_r_656_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBytes(lean_object* v_byteCount_657_, lean_object* v_word_658_){
_start:
{
uint64_t v_low_659_; lean_object* v___x_660_; lean_object* v___x_661_; uint64_t v_high_662_; uint32_t v___x_663_; uint32_t v_remainder_664_; lean_object* v___x_665_; lean_object* v___x_666_; lean_object* v___x_667_; 
v_low_659_ = lean_uint64_of_nat(v_word_658_);
v___x_660_ = lean_unsigned_to_nat(64u);
v___x_661_ = lean_nat_shiftr(v_word_658_, v___x_660_);
v_high_662_ = lean_uint64_of_nat(v___x_661_);
lean_dec(v___x_661_);
v___x_663_ = 0;
lean_inc(v_byteCount_657_);
v_remainder_664_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg(v_byteCount_657_, v_high_662_, v_low_659_, v_byteCount_657_, v_byteCount_657_, v___x_663_);
lean_dec(v_byteCount_657_);
v___x_665_ = lean_unsigned_to_nat(24u);
v___x_666_ = lean_uint32_to_nat(v_remainder_664_);
v___x_667_ = l_BitVec_ofNat(v___x_665_, v___x_666_);
lean_dec(v___x_666_);
return v___x_667_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndromeBytes___boxed(lean_object* v_byteCount_668_, lean_object* v_word_669_){
_start:
{
lean_object* v_res_670_; 
v_res_670_ = lp_lean1090_Lean1090_Impl_Parity_syndromeBytes(v_byteCount_668_, v_word_669_);
lean_dec(v_word_669_);
return v_res_670_;
}
}
LEAN_EXPORT uint32_t lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0(lean_object* v_byteCount_671_, uint64_t v_high_672_, uint64_t v_low_673_, lean_object* v_n_674_, lean_object* v_j_675_, lean_object* v_a_676_, uint32_t v_a_677_){
_start:
{
uint32_t v___x_678_; 
v___x_678_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg(v_byteCount_671_, v_high_672_, v_low_673_, v_n_674_, v_j_675_, v_a_677_);
return v___x_678_;
}
}
LEAN_EXPORT lean_object* lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___boxed(lean_object* v_byteCount_679_, lean_object* v_high_680_, lean_object* v_low_681_, lean_object* v_n_682_, lean_object* v_j_683_, lean_object* v_a_684_, lean_object* v_a_685_){
_start:
{
uint64_t v_high_boxed_686_; uint64_t v_low_boxed_687_; uint32_t v_a_1342__boxed_688_; uint32_t v_res_689_; lean_object* v_r_690_; 
v_high_boxed_686_ = lean_unbox_uint64(v_high_680_);
lean_dec_ref(v_high_680_);
v_low_boxed_687_ = lean_unbox_uint64(v_low_681_);
lean_dec_ref(v_low_681_);
v_a_1342__boxed_688_ = lean_unbox_uint32(v_a_685_);
lean_dec(v_a_685_);
v_res_689_ = lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0(v_byteCount_679_, v_high_boxed_686_, v_low_boxed_687_, v_n_682_, v_j_683_, v_a_684_, v_a_1342__boxed_688_);
lean_dec(v_n_682_);
lean_dec(v_byteCount_679_);
v_r_690_ = lean_box_uint32(v_res_689_);
return v_r_690_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome(lean_object* v_width_691_, lean_object* v_word_692_){
_start:
{
lean_object* v___x_693_; uint8_t v___x_694_; 
v___x_693_ = lean_unsigned_to_nat(128u);
v___x_694_ = lean_nat_dec_le(v_width_691_, v___x_693_);
if (v___x_694_ == 0)
{
lean_object* v___x_695_; 
v___x_695_ = lp_lean1090_Lean1090_Impl_Parity_syndromeBits(v_width_691_, v_word_692_);
return v___x_695_;
}
else
{
lean_object* v___x_696_; lean_object* v___x_697_; lean_object* v___x_698_; uint8_t v___x_699_; 
v___x_696_ = lean_unsigned_to_nat(8u);
v___x_697_ = lean_nat_mod(v_width_691_, v___x_696_);
v___x_698_ = lean_unsigned_to_nat(0u);
v___x_699_ = lean_nat_dec_eq(v___x_697_, v___x_698_);
lean_dec(v___x_697_);
if (v___x_699_ == 0)
{
lean_object* v___x_700_; 
v___x_700_ = lp_lean1090_Lean1090_Impl_Parity_syndromeBits(v_width_691_, v_word_692_);
return v___x_700_;
}
else
{
lean_object* v___x_701_; lean_object* v___x_702_; lean_object* v___x_703_; 
v___x_701_ = lean_unsigned_to_nat(3u);
v___x_702_ = lean_nat_shiftr(v_width_691_, v___x_701_);
lean_dec(v_width_691_);
v___x_703_ = lp_lean1090_Lean1090_Impl_Parity_syndromeBytes(v___x_702_, v_word_692_);
return v___x_703_;
}
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed(lean_object* v_width_704_, lean_object* v_word_705_){
_start:
{
lean_object* v_res_706_; 
v_res_706_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v_width_704_, v_word_705_);
lean_dec(v_word_705_);
return v_res_706_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum(lean_object* v_informationWidth_707_, lean_object* v_information_708_){
_start:
{
lean_object* v___x_709_; lean_object* v___x_710_; lean_object* v___x_711_; lean_object* v___x_712_; lean_object* v___x_713_; 
v___x_709_ = lean_unsigned_to_nat(24u);
v___x_710_ = lean_nat_add(v_informationWidth_707_, v___x_709_);
v___x_711_ = lean_unsigned_to_nat(16777216u);
v___x_712_ = lean_nat_mul(v_information_708_, v___x_711_);
v___x_713_ = lp_lean1090_Lean1090_Impl_Parity_syndrome(v___x_710_, v___x_712_);
lean_dec(v___x_712_);
return v___x_713_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_checksum___boxed(lean_object* v_informationWidth_714_, lean_object* v_information_715_){
_start:
{
lean_object* v_res_716_; 
v_res_716_ = lp_lean1090_Lean1090_Impl_Parity_checksum(v_informationWidth_714_, v_information_715_);
lean_dec(v_information_715_);
lean_dec(v_informationWidth_714_);
return v_res_716_;
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator(lean_object* v_s_717_){
_start:
{
lean_object* v___x_718_; uint8_t v___x_719_; 
v___x_718_ = lean_unsigned_to_nat(128u);
v___x_719_ = lean_nat_dec_lt(v_s_717_, v___x_718_);
if (v___x_719_ == 0)
{
lean_object* v___x_720_; 
v___x_720_ = lean_box(0);
return v___x_720_;
}
else
{
lean_object* v___x_721_; lean_object* v___x_722_; lean_object* v___x_723_; lean_object* v___x_724_; lean_object* v___x_725_; lean_object* v___x_726_; lean_object* v___x_727_; 
v___x_721_ = lean_unsigned_to_nat(3u);
v___x_722_ = lean_unsigned_to_nat(4u);
v___x_723_ = lean_nat_shiftr(v_s_717_, v___x_722_);
v___x_724_ = l_BitVec_ofNat(v___x_721_, v___x_723_);
lean_dec(v___x_723_);
v___x_725_ = l_BitVec_ofNat(v___x_722_, v_s_717_);
v___x_726_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_726_, 0, v___x_724_);
lean_ctor_set(v___x_726_, 1, v___x_725_);
v___x_727_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_727_, 0, v___x_726_);
return v___x_727_;
}
}
}
LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed(lean_object* v_s_728_){
_start:
{
lean_object* v_res_729_; 
v_res_729_ = lp_lean1090_Lean1090_Impl_Parity_interrogator(v_s_728_);
lean_dec(v_s_728_);
return v_res_729_;
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
