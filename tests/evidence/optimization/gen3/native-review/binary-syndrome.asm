
.lake/build/bin/lean1090:     file format elf64-x86-64


Disassembly of section .text:

0000000000b4e110 <lp_lean1090_Lean1090_Impl_Parity_syndrome>:
  b4e110:	push   %rbp
  b4e111:	push   %r15
  b4e113:	push   %r14
  b4e115:	push   %r13
  b4e117:	push   %r12
  b4e119:	push   %rbx
  b4e11a:	push   %rax
  b4e11b:	mov    %rsi,%r14
  b4e11e:	mov    %rdi,%rbx
  b4e121:	test   $0x1,%r14b
  b4e125:	jne    b4e150 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x40>
  b4e127:	mov    %r14,%rdi
  b4e12a:	call   4897d30 <lean_uint64_of_big_nat>
  b4e12f:	mov    %rax,%r15
  b4e132:	mov    $0x81,%esi
  b4e137:	mov    %r14,%rdi
  b4e13a:	call   4895b30 <lean_nat_big_shiftr>
  b4e13f:	mov    %rax,%r13
  b4e142:	test   $0x1,%r13b
  b4e146:	je     b4e162 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x52>
  b4e148:	shr    $1,%r13
  b4e14b:	mov    %r13,%r12
  b4e14e:	jmp    b4e180 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x70>
  b4e150:	mov    %r14,%r15
  b4e153:	shr    $1,%r15
  b4e156:	mov    $0x1,%r13d
  b4e15c:	test   $0x1,%r13b
  b4e160:	jne    b4e148 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x38>
  b4e162:	mov    %r13,%rdi
  b4e165:	call   4897d30 <lean_uint64_of_big_nat>
  b4e16a:	mov    %rax,%r12
  b4e16d:	mov    0x0(%r13),%eax
  b4e171:	cmp    $0x2,%eax
  b4e174:	jl     b4e221 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x111>
  b4e17a:	dec    %eax
  b4e17c:	mov    %eax,0x0(%r13)
  b4e180:	mov    0x401efb2(%rip),%eax        # 4b6d138 <lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0_once>
  b4e186:	cmp    $0x1,%eax
  b4e189:	jne    b4e1f9 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xe9>
  b4e18b:	mov    0x401ef9e(%rip),%r13        # 4b6d130 <lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0>
  b4e192:	test   $0x1,%bl
  b4e195:	jne    b4e1a5 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
  b4e197:	mov    (%rbx),%eax
  b4e199:	test   %eax,%eax
  b4e19b:	jle    b4e236 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x126>
  b4e1a1:	inc    %eax
  b4e1a3:	mov    %eax,(%rbx)
  b4e1a5:	mov    %rbx,%rdi
  b4e1a8:	call   46faad0 <l_List_range>
  b4e1ad:	mov    %rax,%rbp
  b4e1b0:	mov    %rbx,%rdi
  b4e1b3:	mov    %r14,%rsi
  b4e1b6:	mov    %r12,%rdx
  b4e1b9:	mov    %r15,%rcx
  b4e1bc:	mov    %r13,%r8
  b4e1bf:	mov    %rax,%r9
  b4e1c2:	call   b4de00 <lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0>
  b4e1c7:	test   $0x1,%bpl
  b4e1cb:	jne    b4e1da <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xca>
  b4e1cd:	mov    0x0(%rbp),%ecx
  b4e1d0:	cmp    $0x2,%ecx
  b4e1d3:	jl     b4e249 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x139>
  b4e1d5:	dec    %ecx
  b4e1d7:	mov    %ecx,0x0(%rbp)
  b4e1da:	test   $0x1,%bl
  b4e1dd:	jne    b4e1ea <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xda>
  b4e1df:	mov    (%rbx),%ecx
  b4e1e1:	cmp    $0x2,%ecx
  b4e1e4:	jl     b4e260 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x150>
  b4e1e6:	dec    %ecx
  b4e1e8:	mov    %ecx,(%rbx)
  b4e1ea:	add    $0x8,%rsp
  b4e1ee:	pop    %rbx
  b4e1ef:	pop    %r12
  b4e1f1:	pop    %r13
  b4e1f3:	pop    %r14
  b4e1f5:	pop    %r15
  b4e1f7:	pop    %rbp
  b4e1f8:	ret
  b4e1f9:	lea    0x401ef30(%rip),%rdi        # 4b6d130 <lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0>
  b4e200:	lea    0x401ef31(%rip),%rsi        # 4b6d138 <lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0_once>
  b4e207:	lea    0x72(%rip),%rdx        # b4e280 <_init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0>
  b4e20e:	call   489b240 <lean_obj_once_cold>
  b4e213:	mov    %rax,%r13
  b4e216:	test   $0x1,%bl
  b4e219:	je     b4e197 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x87>
  b4e21f:	jmp    b4e1a5 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
  b4e221:	test   %eax,%eax
  b4e223:	je     b4e180 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x70>
  b4e229:	mov    %r13,%rdi
  b4e22c:	call   4891d30 <lean_dec_ref_cold>
  b4e231:	jmp    b4e180 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x70>
  b4e236:	cmp    $0x90000001,%eax
  b4e23b:	jb     b4e1a5 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
  b4e241:	lock decl (%rbx)
  b4e244:	jmp    b4e1a5 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
  b4e249:	test   %ecx,%ecx
  b4e24b:	je     b4e1da <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xca>
  b4e24d:	mov    %rbp,%rdi
  b4e250:	mov    %rax,%r14
  b4e253:	call   4891d30 <lean_dec_ref_cold>
  b4e258:	mov    %r14,%rax
  b4e25b:	jmp    b4e1da <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xca>
  b4e260:	test   %ecx,%ecx
  b4e262:	je     b4e1ea <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xda>
  b4e264:	mov    %rbx,%rdi
  b4e267:	mov    %rax,%rbx
  b4e26a:	call   4891d30 <lean_dec_ref_cold>
  b4e26f:	mov    %rbx,%rax
  b4e272:	jmp    b4e1ea <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xda>

Disassembly of section .init:

Disassembly of section .fini:

Disassembly of section .plt:
