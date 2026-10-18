
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

Disassembly of section .text._init_lp_lean1090_Lean1090_Impl_Parity_syndrome___closed__0:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_syndrome___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum:

0000000000000000 <lp_lean1090_Lean1090_Impl_Parity_checksum>:
   0:	push   %r14
   2:	push   %rbx
   3:	push   %rax
   4:	mov    %rsi,%rbx
   7:	test   $0x1,%dil
   b:	je     80 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x80>
   d:	shr    $1,%rdi
  10:	add    $0x18,%rdi
  14:	js     8c <lp_lean1090_Lean1090_Impl_Parity_checksum+0x8c>
  16:	lea    0x1(,%rdi,2),%rdi
  1e:	test   $0x1,%bl
  21:	je     99 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x99>
  23:	mov    %rbx,%rax
  26:	shr    $1,%rax
  29:	je     60 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x60>
  2b:	movabs $0x10000000000,%rcx
  35:	and    %rbx,%rcx
  38:	shr    $0x29,%rbx
  3c:	or     %rcx,%rbx
  3f:	je     56 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x56>
  41:	mov    $0x1000000,%esi
  46:	mov    %rdi,%rbx
  49:	mov    %rax,%rdi
  4c:	call   51 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x51>
  51:	mov    %rbx,%rdi
  54:	jmp    5d <lp_lean1090_Lean1090_Impl_Parity_checksum+0x5d>
  56:	shl    $0x19,%rax
  5a:	inc    %rax
  5d:	mov    %rax,%rbx
  60:	mov    %rbx,%rsi
  63:	call   68 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x68>
  68:	test   $0x1,%bl
  6b:	jne    78 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x78>
  6d:	mov    (%rbx),%ecx
  6f:	cmp    $0x2,%ecx
  72:	jl     ae <lp_lean1090_Lean1090_Impl_Parity_checksum+0xae>
  74:	dec    %ecx
  76:	mov    %ecx,(%rbx)
  78:	add    $0x8,%rsp
  7c:	pop    %rbx
  7d:	pop    %r14
  7f:	ret
  80:	mov    $0x31,%esi
  85:	call   8a <lp_lean1090_Lean1090_Impl_Parity_checksum+0x8a>
  8a:	jmp    91 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x91>
  8c:	call   91 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x91>
  91:	mov    %rax,%rdi
  94:	test   $0x1,%bl
  97:	jne    23 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x23>
  99:	mov    $0x2000001,%esi
  9e:	mov    %rdi,%r14
  a1:	mov    %rbx,%rdi
  a4:	call   a9 <lp_lean1090_Lean1090_Impl_Parity_checksum+0xa9>
  a9:	mov    %r14,%rdi
  ac:	jmp    5d <lp_lean1090_Lean1090_Impl_Parity_checksum+0x5d>
  ae:	test   %ecx,%ecx
  b0:	je     78 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x78>
  b2:	mov    %rbx,%rdi
  b5:	mov    %rax,%rbx
  b8:	call   bd <lp_lean1090_Lean1090_Impl_Parity_checksum+0xbd>
  bd:	mov    %rbx,%rax
  c0:	add    $0x8,%rsp
  c4:	pop    %rbx
  c5:	pop    %r14
  c7:	ret

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_checksum___boxed:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator:

Disassembly of section .text.lp_lean1090_Lean1090_Impl_Parity_interrogator___boxed:

Disassembly of section .text.initialize_lean1090_Impl_Parity:
