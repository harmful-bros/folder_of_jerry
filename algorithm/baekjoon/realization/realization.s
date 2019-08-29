	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-24(%rbp), %rax
	leaq	-16(%rbp), %rcx
	movl	$0, -4(%rbp)
	movq	%rcx, %rdx
	addq	$4, %rdx
	movq	%rax, %rsi
	addq	$4, %rsi
	movq	%rsi, -40(%rbp)         ## 8-byte Spill
	movq	%rcx, %rsi
	movq	%rax, %rcx
	movq	-40(%rbp), %r8          ## 8-byte Reload
	movb	$0, %al
	callq	_scanf
	movl	-16(%rbp), %edi
	movl	-12(%rbp), %esi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	__ZL12_max_abs_valii
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %edi
	movl	-20(%rbp), %esi
	callq	__ZL12_max_abs_valii
	leaq	L_.str.1(%rip), %rdi
	movl	%eax, -32(%rbp)
	movl	-28(%rbp), %esi
	movl	-32(%rbp), %edx
	movb	$0, %al
	callq	_printf
	movl	-28(%rbp), %edi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	callq	__ZL19_return_start_cordii
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	-32(%rbp), %edi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	__ZL19_return_start_cordii
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	xorl	%edx, %edx
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movl	%edx, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZL12_max_abs_valii:                   ## @_ZL12_max_abs_valii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edi
	callq	_abs
	movl	-8(%rbp), %edi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_abs
	movl	-12(%rbp), %esi         ## 4-byte Reload
	cmpl	%eax, %esi
	jle	LBB1_2
## BB#1:
	movl	-4(%rbp), %eax
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	jmp	LBB1_3
LBB1_2:
	movl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)         ## 4-byte Spill
LBB1_3:
	movl	-16(%rbp), %eax         ## 4-byte Reload
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__ZL19_return_start_cordii:             ## @_ZL19_return_start_cordii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$1, -8(%rbp)
	cmpl	$0, -4(%rbp)
	jge	LBB2_2
## BB#1:
	movl	-4(%rbp), %eax
	imull	-4(%rbp), %eax
	shll	$2, %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB2_5
LBB2_2:
	cmpl	$0, -4(%rbp)
	jle	LBB2_4
## BB#3:
	movl	-4(%rbp), %eax
	shll	$1, %eax
	addl	$1, %eax
	movl	-4(%rbp), %ecx
	shll	$1, %ecx
	addl	$1, %ecx
	imull	%ecx, %eax
	movl	%eax, -8(%rbp)
LBB2_4:
	jmp	LBB2_5
LBB2_5:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d %d %d"

L_.str.1:                               ## @.str.1
	.asciz	"%d %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


.subsections_via_symbols
