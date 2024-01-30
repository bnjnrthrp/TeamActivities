	.file	"shift.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d << 5 + x = %d\n"
.LC1:
	.string	"%d * 32 + x = %d\n"
.LC2:
	.string	"%d * 33 = %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	$10, %edx
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	8(%rsi), %rdi
	xorl	%esi, %esi
	call	strtol@PLT
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	%eax, %r12d
	movl	%eax, %r13d
	movl	%eax, %edx
	sall	$5, %r12d
	addl	%eax, %r12d
	xorl	%eax, %eax
	movl	%r12d, %ecx
	call	__printf_chk@PLT
	movl	%r12d, %ecx
	movl	%r13d, %edx
	movl	$1, %edi
	leaq	.LC1(%rip), %rsi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	%r12d, %ecx
	movl	%r13d, %edx
	movl	$1, %edi
	leaq	.LC2(%rip), %rsi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
