	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_Data_Input
	.p2align	4, 0x90
_Data_Input:                            ## @Data_Input
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
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movq	_N@GOTPCREL(%rip), %rsi
	movb	$0, %al
	callq	_scanf
	movl	$0, -4(%rbp)
	movl	%eax, -8(%rbp)          ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_N@GOTPCREL(%rip), %rax
	movl	-4(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movq	_project_info@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	shlq	$4, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	addq	$8, %rdx
	movslq	-4(%rbp), %rcx
	shlq	$4, %rcx
	addq	%rcx, %rax
	addq	$12, %rax
	movq	%rdx, %rsi
	movq	%rax, %rdx
	movb	$0, %al
	callq	_scanf
	movq	_project_info@GOTPCREL(%rip), %rcx
	movslq	-4(%rbp), %rdx
	shlq	$4, %rdx
	movq	%rcx, %rsi
	addq	%rdx, %rsi
	movl	12(%rsi), %r8d
	movslq	-4(%rbp), %rdx
	shlq	$4, %rdx
	movq	%rcx, %rsi
	addq	%rdx, %rsi
	subl	8(%rsi), %r8d
	movslq	-4(%rbp), %rdx
	shlq	$4, %rdx
	addq	%rdx, %rcx
	movl	%r8d, (%rcx)
	movl	%eax, -12(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_1
LBB0_4:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
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
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	callq	_Data_Input
	movq	_project_info@GOTPCREL(%rip), %rax
	movl	$16, %ecx
	movl	%ecx, %edx
	leaq	__compare(%rip), %rcx
	movq	_N@GOTPCREL(%rip), %rsi
	movslq	(%rsi), %rsi
	movq	%rax, %rdi
	callq	_qsort
	movq	_project_info@GOTPCREL(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	$0, -12(%rbp)
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-12(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB1_15
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	$0, -16(%rbp)
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB1_11
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=2
	movslq	-16(%rbp), %rax
	shlq	$4, %rax
	addq	-24(%rbp), %rax
	cmpl	$0, 4(%rax)
	je	LBB1_6
## BB#5:                                ##   in Loop: Header=BB1_3 Depth=2
	jmp	LBB1_10
LBB1_6:                                 ##   in Loop: Header=BB1_3 Depth=2
	movslq	-12(%rbp), %rax
	shlq	$4, %rax
	addq	-24(%rbp), %rax
	movl	12(%rax), %ecx
	movslq	-16(%rbp), %rax
	shlq	$4, %rax
	addq	-24(%rbp), %rax
	cmpl	8(%rax), %ecx
	jl	LBB1_9
## BB#7:                                ##   in Loop: Header=BB1_3 Depth=2
	movslq	-12(%rbp), %rax
	shlq	$4, %rax
	addq	-24(%rbp), %rax
	movl	8(%rax), %ecx
	movslq	-16(%rbp), %rax
	shlq	$4, %rax
	addq	-24(%rbp), %rax
	cmpl	12(%rax), %ecx
	jg	LBB1_9
## BB#8:                                ##   in Loop: Header=BB1_1 Depth=1
	movslq	-12(%rbp), %rax
	shlq	$4, %rax
	addq	-24(%rbp), %rax
	movl	$1, 4(%rax)
	jmp	LBB1_11
LBB1_9:                                 ##   in Loop: Header=BB1_3 Depth=2
	jmp	LBB1_10
LBB1_10:                                ##   in Loop: Header=BB1_3 Depth=2
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB1_3
LBB1_11:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	LBB1_13
## BB#12:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
LBB1_13:                                ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_14
LBB1_14:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB1_1
LBB1_15:
	leaq	L_.str.2(%rip), %rdi
	movl	-8(%rbp), %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.p2align	4, 0x90
__compare:                              ## @_compare
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
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movl	(%rsi), %eax
	movq	-16(%rbp), %rsi
	subl	(%rsi), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

	.comm	_N,4,2                  ## @N
L_.str.1:                               ## @.str.1
	.asciz	"%d %d"

	.comm	_project_info,240,4     ## @project_info
L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


.subsections_via_symbols
