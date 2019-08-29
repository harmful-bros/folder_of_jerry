	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_Push
	.p2align	4, 0x90
_Push:                                  ## @Push
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
	movl	%edi, -4(%rbp)
	cmpl	$50000, _sp(%rip)       ## imm = 0xC350
	jl	LBB0_2
## BB#1:
	jmp	LBB0_3
LBB0_2:
	movq	_stack@GOTPCREL(%rip), %rax
	movl	-4(%rbp), %ecx
	movl	_sp(%rip), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, _sp(%rip)
	movslq	%edx, %rdi
	movl	%ecx, (%rax,%rdi,4)
LBB0_3:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Pop
	.p2align	4, 0x90
_Pop:                                   ## @Pop
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
	movl	_sp(%rip), %eax
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jge	LBB1_2
## BB#1:
	movl	$-1, -4(%rbp)
	jmp	LBB1_3
LBB1_2:
	movq	_stack@GOTPCREL(%rip), %rax
	movl	_sp(%rip), %ecx
	addl	$-1, %ecx
	movl	%ecx, _sp(%rip)
	movslq	%ecx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movl	%ecx, -4(%rbp)
LBB1_3:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Input_Data
	.p2align	4, 0x90
_Input_Data:                            ## @Input_Data
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
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movq	_N@GOTPCREL(%rip), %rsi
	movb	$0, %al
	callq	_scanf
	leaq	L_.str(%rip), %rdi
	movq	_a@GOTPCREL(%rip), %rsi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movl	$1, -4(%rbp)
	movl	%eax, -12(%rbp)         ## 4-byte Spill
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_N@GOTPCREL(%rip), %rax
	movl	-4(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB2_4
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movq	_a@GOTPCREL(%rip), %rax
	movq	_op@GOTPCREL(%rip), %rcx
	movslq	-4(%rbp), %rdx
	addq	%rdx, %rcx
	movslq	-4(%rbp), %rdx
	shlq	$2, %rdx
	addq	%rdx, %rax
	movq	%rcx, %rsi
	movq	%rax, %rdx
	movb	$0, %al
	callq	_scanf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB2_1
LBB2_4:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Multiply
	.p2align	4, 0x90
_Multiply:                              ## @Multiply
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	movl	$10000, %eax            ## imm = 0x2710
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	imull	-8(%rbp), %esi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	cltd
	movl	-12(%rbp), %esi         ## 4-byte Reload
	idivl	%esi
	movl	%edx, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_Solve
	.p2align	4, 0x90
_Solve:                                 ## @Solve
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	_a@GOTPCREL(%rip), %rax
	movl	$0, -12(%rbp)
	movl	(%rax), %edi
	callq	_Push
	movl	$1, -4(%rbp)
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_N@GOTPCREL(%rip), %rax
	movl	-4(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB4_7
## BB#2:                                ##   in Loop: Header=BB4_1 Depth=1
	movslq	-4(%rbp), %rax
	movq	_op@GOTPCREL(%rip), %rcx
	movsbl	(%rcx,%rax), %edx
	movl	%edx, %esi
	subl	$42, %esi
	movl	%edx, -16(%rbp)         ## 4-byte Spill
	movl	%esi, -20(%rbp)         ## 4-byte Spill
	je	LBB4_3
	jmp	LBB4_11
LBB4_11:                                ##   in Loop: Header=BB4_1 Depth=1
	movl	-16(%rbp), %eax         ## 4-byte Reload
	subl	$43, %eax
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	je	LBB4_4
	jmp	LBB4_5
LBB4_3:                                 ##   in Loop: Header=BB4_1 Depth=1
	callq	_Pop
	movq	_a@GOTPCREL(%rip), %rcx
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %edi
	movslq	-4(%rbp), %rdx
	movl	(%rcx,%rdx,4), %esi
	callq	_Multiply
	movl	%eax, %edi
	callq	_Push
	jmp	LBB4_5
LBB4_4:                                 ##   in Loop: Header=BB4_1 Depth=1
	movq	_a@GOTPCREL(%rip), %rax
	movslq	-4(%rbp), %rcx
	movl	(%rax,%rcx,4), %edi
	callq	_Push
LBB4_5:                                 ##   in Loop: Header=BB4_1 Depth=1
	jmp	LBB4_6
LBB4_6:                                 ##   in Loop: Header=BB4_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB4_1
LBB4_7:
	jmp	LBB4_8
LBB4_8:                                 ## =>This Inner Loop Header: Depth=1
	callq	_Pop
	movl	%eax, -8(%rbp)
	cmpl	$-1, %eax
	je	LBB4_10
## BB#9:                                ##   in Loop: Header=BB4_8 Depth=1
	movl	-8(%rbp), %eax
	addl	-12(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	LBB4_8
LBB4_10:
	movl	$10000, %eax            ## imm = 0x2710
	movl	-12(%rbp), %ecx
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-28(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	%edx, -12(%rbp)
	movl	-12(%rbp), %edx
	movl	%edx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	callq	_Input_Data
	callq	_Solve
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%esi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_sp                     ## @sp
.zerofill __DATA,__common,_sp,4,2
	.comm	_stack,200000,4         ## @stack
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

	.comm	_N,4,2                  ## @N
	.comm	_a,200000,4             ## @a
L_.str.1:                               ## @.str.1
	.asciz	" %c %d"

	.comm	_op,50000,4             ## @op
L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


.subsections_via_symbols
