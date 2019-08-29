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
	subq	$1000080, %rsp          ## imm = 0xF4290
	movl	$1000002, %esi          ## imm = 0xF4242
	movq	___stdinp@GOTPCREL(%rip), %rax
	leaq	-1000016(%rbp), %rcx
	xorl	%edx, %edx
	movl	$1000002, %edi          ## imm = 0xF4242
	movl	%edi, %r8d
	movq	___stack_chk_guard@GOTPCREL(%rip), %r9
	movq	(%r9), %r9
	movq	%r9, -8(%rbp)
	movl	$0, -1000020(%rbp)
	movl	$0, -1000032(%rbp)
	movl	$0, -1000036(%rbp)
	movq	%rcx, %r9
	movq	%r9, %rdi
	movl	%esi, -1000040(%rbp)    ## 4-byte Spill
	movl	%edx, %esi
	movq	%r8, %rdx
	movq	%rcx, -1000048(%rbp)    ## 8-byte Spill
	movq	%rax, -1000056(%rbp)    ## 8-byte Spill
	callq	_memset
	movq	-1000056(%rbp), %rax    ## 8-byte Reload
	movq	(%rax), %rdx
	movq	-1000048(%rbp), %rdi    ## 8-byte Reload
	movl	-1000040(%rbp), %esi    ## 4-byte Reload
	callq	_fgets
	leaq	-1000016(%rbp), %rdi
	movq	%rax, -1000064(%rbp)    ## 8-byte Spill
	callq	_strlen
	subq	$1, %rax
	movl	%eax, %esi
	movl	%esi, -1000028(%rbp)
	movslq	-1000028(%rbp), %rax
	movb	$0, -1000016(%rbp,%rax)
	movl	$0, -1000024(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-1000024(%rbp), %eax
	cmpl	-1000028(%rbp), %eax
	jge	LBB0_9
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movslq	-1000024(%rbp), %rax
	movsbl	-1000016(%rbp,%rax), %ecx
	cmpl	$32, %ecx
	jle	LBB0_6
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	cmpl	$0, -1000036(%rbp)
	jne	LBB0_5
## BB#4:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-1000032(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -1000032(%rbp)
	movl	$1, -1000036(%rbp)
LBB0_5:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_7
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -1000036(%rbp)
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_8
LBB0_8:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-1000024(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -1000024(%rbp)
	jmp	LBB0_1
LBB0_9:
	leaq	L_.str(%rip), %rdi
	movl	-1000032(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rdi
	movl	%eax, -1000068(%rbp)    ## 4-byte Spill
	jne	LBB0_11
## BB#10:                               ## %SP_return
	xorl	%eax, %eax
	addq	$1000080, %rsp          ## imm = 0xF4290
	popq	%rbp
	retq
LBB0_11:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
