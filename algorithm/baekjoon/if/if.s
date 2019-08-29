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
	subq	$48, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	$0, -4(%rbp)
	movl	$0, -20(%rbp)
	movb	$0, %al
	callq	_scanf
	movl	$10, %ecx
	movl	-8(%rbp), %edx
	movl	%edx, -16(%rbp)
	movl	-8(%rbp), %edx
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	-8(%rbp), %r8d
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%r8d, %eax
	cltd
	idivl	%ecx
	movl	-28(%rbp), %r8d         ## 4-byte Reload
	addl	%edx, %r8d
	movl	%r8d, %eax
	cltd
	idivl	%ecx
	movl	%edx, -12(%rbp)
	movl	-8(%rbp), %edx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	imull	$10, %edx, %ecx
	addl	-12(%rbp), %ecx
	movl	%ecx, -8(%rbp)
	movl	-20(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -20(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-8(%rbp), %eax
	je	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$10, %eax
	movl	-20(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -20(%rbp)
	movl	-8(%rbp), %ecx
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-32(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	-8(%rbp), %esi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	cltd
	idivl	%ecx
	movl	-36(%rbp), %esi         ## 4-byte Reload
	addl	%edx, %esi
	movl	%esi, %eax
	cltd
	idivl	%ecx
	movl	%edx, -12(%rbp)
	movl	-8(%rbp), %edx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	imull	$10, %edx, %edx
	addl	-12(%rbp), %edx
	movl	%edx, -8(%rbp)
	jmp	LBB0_1
LBB0_3:
	leaq	L_.str.1(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"%d\n"


.subsections_via_symbols
