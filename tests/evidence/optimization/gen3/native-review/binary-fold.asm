
.lake/build/bin/lean1090:     file format elf64-x86-64


Disassembly of section .text:

0000000000b4de00 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0>:
  b4de00:	push   %rbp
  b4de01:	push   %r15
  b4de03:	push   %r14
  b4de05:	push   %r13
  b4de07:	push   %r12
  b4de09:	push   %rbx
  b4de0a:	sub    $0x28,%rsp
  b4de0e:	mov    %r9,%rbx
  b4de11:	mov    %r8,%rax
  b4de14:	mov    %rcx,0x20(%rsp)
  b4de19:	mov    %rdx,0x18(%rsp)
  b4de1e:	mov    %rsi,0x8(%rsp)
  b4de23:	mov    %rdi,%rcx
  b4de26:	mov    %rdi,0x10(%rsp)
  b4de2b:	sub    $0x2,%rcx
  b4de2f:	mov    $0x1,%r13d
  b4de35:	cmovae %rcx,%r13
  b4de39:	nopl   0x0(%rax)
  b4de40:	mov    %rax,%rbp
  b4de43:	test   $0x1,%bl
  b4de46:	jne    b4de60 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x60>
  b4de48:	movzbl 0x7(%rbx),%eax
  b4de4c:	test   %eax,%eax
  b4de4e:	jne    b4de6e <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x6e>
  b4de50:	jmp    b4e0ef <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2ef>
  b4de55:	data16 cs nopw 0x0(%rax,%rax,1)
  b4de60:	mov    %rbx,%rax
  b4de63:	shr    $1,%rax
  b4de66:	test   %eax,%eax
  b4de68:	je     b4e0ef <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2ef>
  b4de6e:	mov    0x8(%rbx),%r14
  b4de72:	mov    0x10(%rbx),%rbx
  b4de76:	mov    %r13,%r12
  b4de79:	testb  $0x1,0x10(%rsp)
  b4de7e:	je     b4df8b <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x18b>
  b4de84:	test   $0x1,%r12b
  b4de88:	je     b4dfa7 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1a7>
  b4de8e:	test   $0x1,%r14b
  b4de92:	je     b4dfcd <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1cd>
  b4de98:	shr    $1,%r12
  b4de9b:	shr    $1,%r14
  b4de9e:	mov    $0x1,%r15d
  b4dea4:	sub    %r14,%r12
  b4dea7:	jb     b4dec4 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xc4>
  b4dea9:	lea    0x1(,%r12,2),%r15
  b4deb1:	test   $0x1,%r15b
  b4deb5:	je     b4dfe0 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x1e0>
  b4debb:	cmp    $0x81,%r15
  b4dec2:	jae    b4df10 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x110>
  b4dec4:	shr    $1,%r15
  b4dec7:	mov    %r15,%rax
  b4deca:	xor    %esi,%esi
  b4decc:	mov    0x20(%rsp),%rcx
  b4ded1:	bt     %rax,%rcx
  b4ded5:	setb   %sil
  b4ded9:	mov    %rbp,%rdi
  b4dedc:	call   b4dc90 <lp_lean1090_Lean1090_Impl_Parity_step>
  b4dee1:	test   $0x1,%bpl
  b4dee5:	jne    b4de40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
  b4deeb:	mov    0x0(%rbp),%ecx
  b4deee:	cmp    $0x2,%ecx
  b4def1:	jl     b4e00f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x20f>
  b4def7:	dec    %ecx
  b4def9:	mov    %ecx,0x0(%rbp)
  b4defc:	jmp    b4de40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
  b4df01:	data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
  b4df10:	cmp    $0x101,%r15
  b4df17:	jae    b4df52 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x152>
  b4df19:	mov    $0x1,%r12d
  b4df1f:	cmp    $0x80,%r15
  b4df26:	jb     b4df2f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
  b4df28:	add    $0xffffffffffffff80,%r15
  b4df2c:	mov    %r15,%r12
  b4df2f:	test   $0x1,%r12b
  b4df33:	jne    b4df79 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x179>
  b4df35:	mov    %r12,%rdi
  b4df38:	call   4897d30 <lean_uint64_of_big_nat>
  b4df3d:	mov    (%r12),%ecx
  b4df41:	cmp    $0x2,%ecx
  b4df44:	jl     b4e07c <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x27c>
  b4df4a:	dec    %ecx
  b4df4c:	mov    %ecx,(%r12)
  b4df50:	jmp    b4df7f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x17f>
  b4df52:	mov    0x8(%rsp),%rdi
  b4df57:	mov    %r15,%rsi
  b4df5a:	call   46fe050 <l_Nat_testBit>
  b4df5f:	movzbl %al,%esi
  b4df62:	mov    %rbp,%rdi
  b4df65:	call   b4dc90 <lp_lean1090_Lean1090_Impl_Parity_step>
  b4df6a:	test   $0x1,%bpl
  b4df6e:	jne    b4de40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
  b4df74:	jmp    b4deeb <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xeb>
  b4df79:	shr    $1,%r12
  b4df7c:	mov    %r12,%rax
  b4df7f:	xor    %esi,%esi
  b4df81:	mov    0x18(%rsp),%rcx
  b4df86:	jmp    b4ded1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xd1>
  b4df8b:	mov    $0x3,%esi
  b4df90:	mov    0x10(%rsp),%rdi
  b4df95:	call   4894610 <lean_nat_big_sub>
  b4df9a:	mov    %rax,%r12
  b4df9d:	test   $0x1,%r12b
  b4dfa1:	jne    b4de8e <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x8e>
  b4dfa7:	mov    %r12,%rdi
  b4dfaa:	mov    %r14,%rsi
  b4dfad:	call   4894610 <lean_nat_big_sub>
  b4dfb2:	mov    %rax,%r15
  b4dfb5:	mov    (%r12),%eax
  b4dfb9:	cmp    $0x2,%eax
  b4dfbc:	jl     b4e097 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x297>
  b4dfc2:	dec    %eax
  b4dfc4:	mov    %eax,(%r12)
  b4dfc8:	jmp    b4deb1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
  b4dfcd:	mov    %r12,%rdi
  b4dfd0:	mov    %r14,%rsi
  b4dfd3:	call   4894610 <lean_nat_big_sub>
  b4dfd8:	mov    %rax,%r15
  b4dfdb:	jmp    b4deb1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
  b4dfe0:	mov    $0x81,%esi
  b4dfe5:	mov    %r15,%rdi
  b4dfe8:	call   48951e0 <lean_nat_big_lt>
  b4dfed:	test   %al,%al
  b4dfef:	je     b4e02a <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x22a>
  b4dff1:	mov    %r15,%rdi
  b4dff4:	call   4897d30 <lean_uint64_of_big_nat>
  b4dff9:	mov    (%r15),%ecx
  b4dffc:	cmp    $0x2,%ecx
  b4dfff:	jl     b4e0ac <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2ac>
  b4e005:	dec    %ecx
  b4e007:	mov    %ecx,(%r15)
  b4e00a:	jmp    b4deca <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xca>
  b4e00f:	test   %ecx,%ecx
  b4e011:	je     b4de40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
  b4e017:	mov    %rbp,%rdi
  b4e01a:	mov    %rax,%r14
  b4e01d:	call   4891d30 <lean_dec_ref_cold>
  b4e022:	mov    %r14,%rax
  b4e025:	jmp    b4de40 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x40>
  b4e02a:	mov    $0x101,%esi
  b4e02f:	mov    %r15,%rdi
  b4e032:	call   48951e0 <lean_nat_big_lt>
  b4e037:	test   %al,%al
  b4e039:	je     b4e05d <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x25d>
  b4e03b:	mov    $0x81,%esi
  b4e040:	mov    %r15,%rdi
  b4e043:	call   4894610 <lean_nat_big_sub>
  b4e048:	mov    %rax,%r12
  b4e04b:	mov    (%r15),%eax
  b4e04e:	cmp    $0x2,%eax
  b4e051:	jl     b4e0c3 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2c3>
  b4e053:	dec    %eax
  b4e055:	mov    %eax,(%r15)
  b4e058:	jmp    b4df2f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
  b4e05d:	mov    0x8(%rsp),%rdi
  b4e062:	mov    %r15,%rsi
  b4e065:	call   46fe050 <l_Nat_testBit>
  b4e06a:	mov    (%r15),%ecx
  b4e06d:	cmp    $0x2,%ecx
  b4e070:	jl     b4e0d8 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2d8>
  b4e072:	dec    %ecx
  b4e074:	mov    %ecx,(%r15)
  b4e077:	jmp    b4df5f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x15f>
  b4e07c:	test   %ecx,%ecx
  b4e07e:	je     b4df7f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x17f>
  b4e084:	mov    %r12,%rdi
  b4e087:	mov    %rax,%r14
  b4e08a:	call   4891d30 <lean_dec_ref_cold>
  b4e08f:	mov    %r14,%rax
  b4e092:	jmp    b4df7f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x17f>
  b4e097:	test   %eax,%eax
  b4e099:	je     b4deb1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
  b4e09f:	mov    %r12,%rdi
  b4e0a2:	call   4891d30 <lean_dec_ref_cold>
  b4e0a7:	jmp    b4deb1 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xb1>
  b4e0ac:	mov    %rax,%r14
  b4e0af:	test   %ecx,%ecx
  b4e0b1:	je     b4e0bb <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2bb>
  b4e0b3:	mov    %r15,%rdi
  b4e0b6:	call   4891d30 <lean_dec_ref_cold>
  b4e0bb:	mov    %r14,%rax
  b4e0be:	jmp    b4deca <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0xca>
  b4e0c3:	test   %eax,%eax
  b4e0c5:	je     b4df2f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
  b4e0cb:	mov    %r15,%rdi
  b4e0ce:	call   4891d30 <lean_dec_ref_cold>
  b4e0d3:	jmp    b4df2f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x12f>
  b4e0d8:	mov    %eax,%r14d
  b4e0db:	test   %ecx,%ecx
  b4e0dd:	je     b4e0e7 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x2e7>
  b4e0df:	mov    %r15,%rdi
  b4e0e2:	call   4891d30 <lean_dec_ref_cold>
  b4e0e7:	mov    %r14d,%eax
  b4e0ea:	jmp    b4df5f <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0+0x15f>
  b4e0ef:	mov    %rbp,%rax
  b4e0f2:	add    $0x28,%rsp
  b4e0f6:	pop    %rbx
  b4e0f7:	pop    %r12
  b4e0f9:	pop    %r13
  b4e0fb:	pop    %r14
  b4e0fd:	pop    %r15
  b4e0ff:	pop    %rbp
  b4e100:	ret

Disassembly of section .init:

Disassembly of section .fini:

Disassembly of section .plt:
