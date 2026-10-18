
.lake/build/ir/Impl/Parity.c.o.export:     file format elf64-x86-64


Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_step:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_step___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_wordBit:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_wordBit___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_cachedBit:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_cachedBit___boxed:

Disassembly of section .text.lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0:

Disassembly of section .text.lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome:

0000000000000000 <lp_lean1090_Lean1090_Impl_Parity_syndrome>:
   0:	push   %rbp
   1:	push   %r15
   3:	push   %r14
   5:	push   %r13
   7:	push   %r12
   9:	push   %rbx
   a:	push   %rax
   b:	mov    %rsi,%r14
   e:	mov    %rdi,%rbx
  11:	test   $0x1,%r14b
  15:	jne    40 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x40>
  17:	mov    %r14,%rdi
  1a:	call   1f <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x1f>
  1f:	mov    %rax,%r15
  22:	mov    $0x81,%esi
  27:	mov    %r14,%rdi
  2a:	call   2f <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x2f>
  2f:	mov    %rax,%r13
  32:	test   $0x1,%r13b
  36:	je     52 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x52>
  38:	shr    $1,%r13
  3b:	mov    %r13,%r12
  3e:	jmp    70 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x70>
  40:	mov    %r14,%r15
  43:	shr    $1,%r15
  46:	mov    $0x1,%r13d
  4c:	test   $0x1,%r13b
  50:	jne    38 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x38>
  52:	mov    %r13,%rdi
  55:	call   5a <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x5a>
  5a:	mov    %rax,%r12
  5d:	mov    0x0(%r13),%eax
  61:	cmp    $0x2,%eax
  64:	jl     111 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x111>
  6a:	dec    %eax
  6c:	mov    %eax,0x0(%r13)
  70:	mov    0x0(%rip),%eax        # 76 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x76>
  76:	cmp    $0x1,%eax
  79:	jne    e9 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xe9>
  7b:	mov    0x0(%rip),%r13        # 82 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x82>
  82:	test   $0x1,%bl
  85:	jne    95 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
  87:	mov    (%rbx),%eax
  89:	test   %eax,%eax
  8b:	jle    126 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x126>
  91:	inc    %eax
  93:	mov    %eax,(%rbx)
  95:	mov    %rbx,%rdi
  98:	call   9d <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x9d>
  9d:	mov    %rax,%rbp
  a0:	mov    %rbx,%rdi
  a3:	mov    %r14,%rsi
  a6:	mov    %r12,%rdx
  a9:	mov    %r15,%rcx
  ac:	mov    %r13,%r8
  af:	mov    %rax,%r9
  b2:	call   b7 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xb7>
  b7:	test   $0x1,%bpl
  bb:	jne    ca <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xca>
  bd:	mov    0x0(%rbp),%ecx
  c0:	cmp    $0x2,%ecx
  c3:	jl     139 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x139>
  c5:	dec    %ecx
  c7:	mov    %ecx,0x0(%rbp)
  ca:	test   $0x1,%bl
  cd:	jne    da <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xda>
  cf:	mov    (%rbx),%ecx
  d1:	cmp    $0x2,%ecx
  d4:	jl     150 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x150>
  d6:	dec    %ecx
  d8:	mov    %ecx,(%rbx)
  da:	add    $0x8,%rsp
  de:	pop    %rbx
  df:	pop    %r12
  e1:	pop    %r13
  e3:	pop    %r14
  e5:	pop    %r15
  e7:	pop    %rbp
  e8:	ret
  e9:	lea    0x0(%rip),%rdi        # f0 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xf0>
  f0:	lea    0x0(%rip),%rsi        # f7 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xf7>
  f7:	lea    0x0(%rip),%rdx        # fe <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xfe>
  fe:	call   103 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x103>
 103:	mov    %rax,%r13
 106:	test   $0x1,%bl
 109:	je     87 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x87>
 10f:	jmp    95 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
 111:	test   %eax,%eax
 113:	je     70 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x70>
 119:	mov    %r13,%rdi
 11c:	call   121 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x121>
 121:	jmp    70 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x70>
 126:	cmp    $0x90000001,%eax
 12b:	jb     95 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
 131:	lock decl (%rbx)
 134:	jmp    95 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x95>
 139:	test   %ecx,%ecx
 13b:	je     ca <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xca>
 13d:	mov    %rbp,%rdi
 140:	mov    %rax,%r14
 143:	call   148 <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x148>
 148:	mov    %r14,%rax
 14b:	jmp    ca <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xca>
 150:	test   %ecx,%ecx
 152:	je     da <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xda>
 154:	mov    %rbx,%rdi
 157:	mov    %rax,%rbx
 15a:	call   15f <lp_lean1090_Lean1090_Impl_Parity_syndrome+0x15f>
 15f:	mov    %rbx,%rax
 162:	jmp    da <lp_lean1090_Lean1090_Impl_Parity_syndrome+0xda>

Disassembly of section .text._init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed:

Disassembly of section .text.initialize_lean1090_Impl_Parity:
