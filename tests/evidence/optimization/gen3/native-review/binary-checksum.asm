
.lake/build/bin/lean1090:     file format elf64-x86-64


Disassembly of section .text:

0000000000b4e290 <lp_lean1090_Lean1090_Impl_Parity_checksum>:
  b4e290:	push   %r14
  b4e292:	push   %rbx
  b4e293:	push   %rax
  b4e294:	mov    %rsi,%rbx
  b4e297:	test   $0x1,%dil
  b4e29b:	je     b4e310 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x80>
  b4e29d:	shr    $1,%rdi
  b4e2a0:	add    $0x18,%rdi
  b4e2a4:	js     b4e31c <lp_lean1090_Lean1090_Impl_Parity_checksum+0x8c>
  b4e2a6:	lea    0x1(,%rdi,2),%rdi
  b4e2ae:	test   $0x1,%bl
  b4e2b1:	je     b4e329 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x99>
  b4e2b3:	mov    %rbx,%rax
  b4e2b6:	shr    $1,%rax
  b4e2b9:	je     b4e2f0 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x60>
  b4e2bb:	movabs $0x10000000000,%rcx
  b4e2c5:	and    %rbx,%rcx
  b4e2c8:	shr    $0x29,%rbx
  b4e2cc:	or     %rcx,%rbx
  b4e2cf:	je     b4e2e6 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x56>
  b4e2d1:	mov    $0x1000000,%esi
  b4e2d6:	mov    %rdi,%rbx
  b4e2d9:	mov    %rax,%rdi
  b4e2dc:	call   4894aa0 <lean_nat_overflow_mul>
  b4e2e1:	mov    %rbx,%rdi
  b4e2e4:	jmp    b4e2ed <lp_lean1090_Lean1090_Impl_Parity_checksum+0x5d>
  b4e2e6:	shl    $0x19,%rax
  b4e2ea:	inc    %rax
  b4e2ed:	mov    %rax,%rbx
  b4e2f0:	mov    %rbx,%rsi
  b4e2f3:	call   b4e110 <lp_lean1090_Lean1090_Impl_Parity_syndrome>
  b4e2f8:	test   $0x1,%bl
  b4e2fb:	jne    b4e308 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x78>
  b4e2fd:	mov    (%rbx),%ecx
  b4e2ff:	cmp    $0x2,%ecx
  b4e302:	jl     b4e33e <lp_lean1090_Lean1090_Impl_Parity_checksum+0xae>
  b4e304:	dec    %ecx
  b4e306:	mov    %ecx,(%rbx)
  b4e308:	add    $0x8,%rsp
  b4e30c:	pop    %rbx
  b4e30d:	pop    %r14
  b4e30f:	ret
  b4e310:	mov    $0x31,%esi
  b4e315:	call   48943f0 <lean_nat_big_add>
  b4e31a:	jmp    b4e321 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x91>
  b4e31c:	call   4894250 <lean_big_usize_to_nat>
  b4e321:	mov    %rax,%rdi
  b4e324:	test   $0x1,%bl
  b4e327:	jne    b4e2b3 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x23>
  b4e329:	mov    $0x2000001,%esi
  b4e32e:	mov    %rdi,%r14
  b4e331:	mov    %rbx,%rdi
  b4e334:	call   4894830 <lean_nat_big_mul>
  b4e339:	mov    %r14,%rdi
  b4e33c:	jmp    b4e2ed <lp_lean1090_Lean1090_Impl_Parity_checksum+0x5d>
  b4e33e:	test   %ecx,%ecx
  b4e340:	je     b4e308 <lp_lean1090_Lean1090_Impl_Parity_checksum+0x78>
  b4e342:	mov    %rbx,%rdi
  b4e345:	mov    %rax,%rbx
  b4e348:	call   4891d30 <lean_dec_ref_cold>
  b4e34d:	mov    %rbx,%rax
  b4e350:	add    $0x8,%rsp
  b4e354:	pop    %rbx
  b4e355:	pop    %r14
  b4e357:	ret

Disassembly of section .init:

Disassembly of section .fini:

Disassembly of section .plt:
