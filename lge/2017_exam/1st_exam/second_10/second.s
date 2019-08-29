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
	subq	$2400, %rsp             ## imm = 0x960
	leaq	L_.str(%rip), %rdi
	movq	_N@GOTPCREL(%rip), %rsi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -2324(%rbp)
	movl	$0, -2336(%rbp)
	movl	$0, -2340(%rbp)
	movq	$0, -2352(%rbp)
	movq	$0, -2360(%rbp)
	movq	$0, -2368(%rbp)
	movb	$0, %al
	callq	_scanf
	movl	$0, -2328(%rbp)
	movl	%eax, -2372(%rbp)       ## 4-byte Spill
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-2328(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_8
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -2332(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-2332(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_6
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=2
	leaq	L_.str(%rip), %rdi
	leaq	-2320(%rbp), %rax
	movslq	-2332(%rbp), %rcx
	movslq	-2328(%rbp), %rdx
	imulq	$96, %rdx, %rdx
	addq	%rdx, %rax
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movl	%eax, -2376(%rbp)       ## 4-byte Spill
## BB#5:                                ##   in Loop: Header=BB0_3 Depth=2
	movl	-2332(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2332(%rbp)
	jmp	LBB0_3
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_7
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-2328(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2328(%rbp)
	jmp	LBB0_1
LBB0_8:
	movq	$100000000, -2368(%rbp) ## imm = 0x5F5E100
	movq	$-100000000, -2360(%rbp) ## imm = 0xFA0A1F00
	movl	$0, -2332(%rbp)
LBB0_9:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_11 Depth 2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-2332(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_18
## BB#10:                               ##   in Loop: Header=BB0_9 Depth=1
	movq	$0, -2352(%rbp)
	movl	$0, -2328(%rbp)
LBB0_11:                                ##   Parent Loop BB0_9 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-2328(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_14
## BB#12:                               ##   in Loop: Header=BB0_11 Depth=2
	leaq	-2320(%rbp), %rax
	movslq	-2332(%rbp), %rcx
	movslq	-2328(%rbp), %rdx
	imulq	$96, %rdx, %rdx
	addq	%rdx, %rax
	movslq	(%rax,%rcx,4), %rax
	addq	-2352(%rbp), %rax
	movq	%rax, -2352(%rbp)
## BB#13:                               ##   in Loop: Header=BB0_11 Depth=2
	movl	-2328(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2328(%rbp)
	jmp	LBB0_11
LBB0_14:                                ##   in Loop: Header=BB0_9 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movl	-2332(%rbp), %esi
	movq	-2352(%rbp), %rdx
	movb	$0, %al
	callq	_printf
	movq	-2352(%rbp), %rdx
	cmpq	-2368(%rbp), %rdx
	movl	%eax, -2380(%rbp)       ## 4-byte Spill
	jge	LBB0_16
## BB#15:                               ##   in Loop: Header=BB0_9 Depth=1
	movq	-2352(%rbp), %rax
	movq	%rax, -2368(%rbp)
	movl	-2332(%rbp), %ecx
	movl	%ecx, -2340(%rbp)
LBB0_16:                                ##   in Loop: Header=BB0_9 Depth=1
	jmp	LBB0_17
LBB0_17:                                ##   in Loop: Header=BB0_9 Depth=1
	movl	-2332(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2332(%rbp)
	jmp	LBB0_9
LBB0_18:
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -2328(%rbp)
	movl	%eax, -2384(%rbp)       ## 4-byte Spill
LBB0_19:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_21 Depth 2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-2328(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_28
## BB#20:                               ##   in Loop: Header=BB0_19 Depth=1
	movq	$0, -2352(%rbp)
	movl	$0, -2332(%rbp)
LBB0_21:                                ##   Parent Loop BB0_19 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	_N@GOTPCREL(%rip), %rax
	movl	-2332(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_24
## BB#22:                               ##   in Loop: Header=BB0_21 Depth=2
	leaq	-2320(%rbp), %rax
	movslq	-2332(%rbp), %rcx
	movslq	-2328(%rbp), %rdx
	imulq	$96, %rdx, %rdx
	addq	%rdx, %rax
	movslq	(%rax,%rcx,4), %rax
	addq	-2352(%rbp), %rax
	movq	%rax, -2352(%rbp)
## BB#23:                               ##   in Loop: Header=BB0_21 Depth=2
	movl	-2332(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2332(%rbp)
	jmp	LBB0_21
LBB0_24:                                ##   in Loop: Header=BB0_19 Depth=1
	leaq	L_.str.3(%rip), %rdi
	movl	-2328(%rbp), %esi
	movq	-2352(%rbp), %rdx
	movq	-2360(%rbp), %rcx
	movb	$0, %al
	callq	_printf
	movq	-2352(%rbp), %rcx
	cmpq	-2360(%rbp), %rcx
	movl	%eax, -2388(%rbp)       ## 4-byte Spill
	jle	LBB0_26
## BB#25:                               ##   in Loop: Header=BB0_19 Depth=1
	movq	-2352(%rbp), %rax
	movq	%rax, -2360(%rbp)
	movl	-2328(%rbp), %ecx
	movl	%ecx, -2336(%rbp)
LBB0_26:                                ##   in Loop: Header=BB0_19 Depth=1
	jmp	LBB0_27
LBB0_27:                                ##   in Loop: Header=BB0_19 Depth=1
	movl	-2328(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -2328(%rbp)
	jmp	LBB0_19
LBB0_28:
	leaq	L_.str.4(%rip), %rdi
	movl	-2336(%rbp), %eax
	addl	$1, %eax
	movl	-2340(%rbp), %ecx
	addl	$1, %ecx
	movl	%eax, %esi
	movl	%ecx, %edx
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %r8
	cmpq	%r8, %rdi
	movl	%eax, -2392(%rbp)       ## 4-byte Spill
	jne	LBB0_30
## BB#29:                               ## %SP_return
	xorl	%eax, %eax
	addq	$2400, %rsp             ## imm = 0x960
	popq	%rbp
	retq
LBB0_30:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

	.comm	_N,4,2                  ## @N
L_.str.1:                               ## @.str.1
	.asciz	"%3d %10lld\n"

L_.str.2:                               ## @.str.2
	.asciz	"\n"

L_.str.3:                               ## @.str.3
	.asciz	"%3d %10lld %10lld\n"

L_.str.4:                               ## @.str.4
	.asciz	"%d %d\n"


.subsections_via_symbols
