	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## BB#0:
	pushq	%rbp
Ltmp31:
	.cfi_def_cfa_offset 16
Ltmp32:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp33:
	.cfi_def_cfa_register %rbp
	subq	$2016, %rsp             ## imm = 0x7E0
	xorl	%esi, %esi
	movl	$24, %eax
	movl	%eax, %edx
	leaq	-1616(%rbp), %rcx
	movl	$0, -1588(%rbp)
	movq	%rcx, -1584(%rbp)
	movq	-1584(%rbp), %rcx
	movq	%rcx, -1576(%rbp)
	movq	-1576(%rbp), %rcx
	movq	%rcx, -1568(%rbp)
	movq	-1568(%rbp), %rdi
	movq	%rdi, -1560(%rbp)
	movq	-1560(%rbp), %rdi
	movq	%rdi, -1552(%rbp)
	movq	-1552(%rbp), %rdi
	movq	%rdi, %r8
	movq	%r8, -1544(%rbp)
	movq	%rcx, -1712(%rbp)       ## 8-byte Spill
	callq	_memset
	movq	-1712(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1520(%rbp)
	movq	-1520(%rbp), %rdx
	movq	%rdx, -1512(%rbp)
	movq	-1512(%rbp), %rdx
	movq	%rdx, -1504(%rbp)
	movq	-1504(%rbp), %rdx
	movq	%rdx, -1528(%rbp)
	movl	$0, -1532(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$3, -1532(%rbp)
	jae	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-1532(%rbp), %eax
	movl	%eax, %ecx
	movq	-1528(%rbp), %rdx
	movq	$0, (%rdx,%rcx,8)
	movl	-1532(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -1532(%rbp)
	jmp	LBB0_1
LBB0_3:                                 ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Ev.exit
	movq	__ZNSt3__13cinE@GOTPCREL(%rip), %rax
	movq	%rax, -1488(%rbp)
	leaq	-1616(%rbp), %rax
	movq	%rax, -1496(%rbp)
	movq	-1488(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-24(%rdx), %rdx
	movq	%rcx, %rsi
	addq	%rdx, %rsi
	movq	%rsi, -1448(%rbp)
	movb	$10, -1449(%rbp)
	movq	-1448(%rbp), %rsi
Ltmp0:
	leaq	-1464(%rbp), %rdi
	movq	%rax, -1720(%rbp)       ## 8-byte Spill
	movq	%rcx, -1728(%rbp)       ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
Ltmp1:
	jmp	LBB0_4
LBB0_4:                                 ## %.noexc
	leaq	-1464(%rbp), %rax
	movq	%rax, -1440(%rbp)
Ltmp2:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp3:
	movq	%rax, -1736(%rbp)       ## 8-byte Spill
	jmp	LBB0_5
LBB0_5:                                 ## %_ZNSt3__19use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE.exit.i.i
	movb	-1449(%rbp), %al
	movq	-1736(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1424(%rbp)
	movb	%al, -1425(%rbp)
	movq	-1424(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-1425(%rbp), %edi
Ltmp4:
	movl	%edi, -1740(%rbp)       ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-1740(%rbp), %r8d       ## 4-byte Reload
	movq	%rsi, -1752(%rbp)       ## 8-byte Spill
	movl	%r8d, %esi
	movq	-1752(%rbp), %rdx       ## 8-byte Reload
	callq	*%rdx
Ltmp5:
	movb	%al, -1753(%rbp)        ## 1-byte Spill
	jmp	LBB0_7
LBB0_6:
Ltmp6:
	movl	%edx, %ecx
	movq	%rax, -1472(%rbp)
	movl	%ecx, -1476(%rbp)
	leaq	-1464(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-1472(%rbp), %rax
	movl	-1476(%rbp), %ecx
	movq	%rax, -1768(%rbp)       ## 8-byte Spill
	movl	%ecx, -1772(%rbp)       ## 4-byte Spill
	jmp	LBB0_33
LBB0_7:                                 ## %_ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc.exit.i
	leaq	-1464(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
Ltmp7:
	movb	-1753(%rbp), %al        ## 1-byte Reload
	movsbl	%al, %edx
	movq	-1728(%rbp), %rdi       ## 8-byte Reload
	movq	-1720(%rbp), %rsi       ## 8-byte Reload
	callq	__ZNSt3__17getlineIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_istreamIT_T0_EES9_RNS_12basic_stringIS6_S7_T1_EES6_
Ltmp8:
	movq	%rax, -1784(%rbp)       ## 8-byte Spill
	jmp	LBB0_8
LBB0_8:                                 ## %_ZNSt3__17getlineIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_istreamIT_T0_EES9_RNS_12basic_stringIS6_S7_T1_EE.exit
	jmp	LBB0_9
LBB0_9:
	leaq	-1232(%rbp), %rax
	leaq	-1256(%rbp), %rcx
	leaq	-1304(%rbp), %rdx
	leaq	-1328(%rbp), %rsi
	leaq	-1688(%rbp), %rdi
	movl	$0, -1632(%rbp)
	movl	$0, -1636(%rbp)
	movq	%rdi, -1416(%rbp)
	movq	-1416(%rbp), %rdi
	movq	%rdi, -1408(%rbp)
	movq	-1408(%rbp), %rdi
	movq	%rdi, -1400(%rbp)
	movq	-1400(%rbp), %rdi
	movq	%rdi, -1392(%rbp)
	movq	-1392(%rbp), %rdi
	movq	%rdi, -1368(%rbp)
	movq	-1368(%rbp), %rdi
	movq	%rdi, -1360(%rbp)
	movq	-1360(%rbp), %r8
	movq	%r8, -1352(%rbp)
	movq	-1352(%rbp), %r8
	movq	$0, (%r8)
	movq	$0, 8(%r8)
	movq	$0, 16(%r8)
	addq	$24, %r8
	movq	%r8, -1336(%rbp)
	movq	$0, -1344(%rbp)
	movq	-1336(%rbp), %r8
	movq	-1344(%rbp), %r9
	movq	%r8, -1320(%rbp)
	movq	%r9, -1328(%rbp)
	movq	-1320(%rbp), %r8
	movq	%rsi, -1312(%rbp)
	movq	-1312(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%r8, -1296(%rbp)
	movq	%rsi, -1304(%rbp)
	movq	-1296(%rbp), %rsi
	movq	%rsi, %r8
	movq	%r8, -1288(%rbp)
	movq	%rdx, -1280(%rbp)
	movq	-1280(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rsi)
	movq	$0, 32(%rdi)
	addq	$40, %rdi
	movq	%rdi, -1264(%rbp)
	movq	$0, -1272(%rbp)
	movq	-1264(%rbp), %rdx
	movq	-1272(%rbp), %rsi
	movq	%rdx, -1248(%rbp)
	movq	%rsi, -1256(%rbp)
	movq	-1248(%rbp), %rdx
	movq	%rcx, -1240(%rbp)
	movq	-1240(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rdx, -1224(%rbp)
	movq	%rcx, -1232(%rbp)
	movq	-1224(%rbp), %rcx
	movq	%rcx, %rdx
	movq	%rdx, -1216(%rbp)
	movq	%rax, -1208(%rbp)
	movq	-1208(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rcx)
LBB0_10:                                ## =>This Inner Loop Header: Depth=1
	leaq	-1616(%rbp), %rax
	movslq	-1632(%rbp), %rcx
	movq	%rax, -1192(%rbp)
	movq	%rcx, -1200(%rbp)
	movq	-1192(%rbp), %rax
	movq	%rax, -1184(%rbp)
	movq	-1184(%rbp), %rax
	movq	%rax, -1176(%rbp)
	movq	-1176(%rbp), %rcx
	movq	%rcx, -1168(%rbp)
	movq	-1168(%rbp), %rcx
	movq	%rcx, -1160(%rbp)
	movq	-1160(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -1792(%rbp)       ## 8-byte Spill
	je	LBB0_12
## BB#11:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1112(%rbp)
	movq	-1112(%rbp), %rcx
	movq	%rcx, -1104(%rbp)
	movq	-1104(%rbp), %rcx
	movq	%rcx, -1096(%rbp)
	movq	-1096(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1800(%rbp)       ## 8-byte Spill
	jmp	LBB0_13
LBB0_12:                                ##   in Loop: Header=BB0_10 Depth=1
	movq	-1792(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1152(%rbp)
	movq	-1152(%rbp), %rcx
	movq	%rcx, -1144(%rbp)
	movq	-1144(%rbp), %rcx
	movq	%rcx, -1136(%rbp)
	movq	-1136(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -1128(%rbp)
	movq	-1128(%rbp), %rcx
	movq	%rcx, -1120(%rbp)
	movq	-1120(%rbp), %rcx
	movq	%rcx, -1800(%rbp)       ## 8-byte Spill
LBB0_13:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit
                                        ##   in Loop: Header=BB0_10 Depth=1
	movq	-1800(%rbp), %rax       ## 8-byte Reload
	addq	-1200(%rbp), %rax
	movq	%rax, -1808(%rbp)       ## 8-byte Spill
## BB#14:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1808(%rbp), %rax       ## 8-byte Reload
	cmpb	$0, (%rax)
	je	LBB0_72
## BB#15:                               ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1616(%rbp), %rax
	movslq	-1632(%rbp), %rcx
	movq	%rax, -1080(%rbp)
	movq	%rcx, -1088(%rbp)
	movq	-1080(%rbp), %rax
	movq	%rax, -1072(%rbp)
	movq	-1072(%rbp), %rax
	movq	%rax, -1064(%rbp)
	movq	-1064(%rbp), %rcx
	movq	%rcx, -1056(%rbp)
	movq	-1056(%rbp), %rcx
	movq	%rcx, -1048(%rbp)
	movq	-1048(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -1816(%rbp)       ## 8-byte Spill
	je	LBB0_17
## BB#16:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1816(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1000(%rbp)
	movq	-1000(%rbp), %rcx
	movq	%rcx, -992(%rbp)
	movq	-992(%rbp), %rcx
	movq	%rcx, -984(%rbp)
	movq	-984(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1824(%rbp)       ## 8-byte Spill
	jmp	LBB0_18
LBB0_17:                                ##   in Loop: Header=BB0_10 Depth=1
	movq	-1816(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1040(%rbp)
	movq	-1040(%rbp), %rcx
	movq	%rcx, -1032(%rbp)
	movq	-1032(%rbp), %rcx
	movq	%rcx, -1024(%rbp)
	movq	-1024(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -1016(%rbp)
	movq	-1016(%rbp), %rcx
	movq	%rcx, -1008(%rbp)
	movq	-1008(%rbp), %rcx
	movq	%rcx, -1824(%rbp)       ## 8-byte Spill
LBB0_18:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit2
                                        ##   in Loop: Header=BB0_10 Depth=1
	movq	-1824(%rbp), %rax       ## 8-byte Reload
	addq	-1088(%rbp), %rax
	movq	%rax, -1832(%rbp)       ## 8-byte Spill
## BB#19:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1832(%rbp), %rax       ## 8-byte Reload
	movsbl	(%rax), %ecx
	cmpl	$40, %ecx
	je	LBB0_25
## BB#20:                               ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1616(%rbp), %rax
	movslq	-1632(%rbp), %rcx
	movq	%rax, -968(%rbp)
	movq	%rcx, -976(%rbp)
	movq	-968(%rbp), %rax
	movq	%rax, -960(%rbp)
	movq	-960(%rbp), %rax
	movq	%rax, -952(%rbp)
	movq	-952(%rbp), %rcx
	movq	%rcx, -944(%rbp)
	movq	-944(%rbp), %rcx
	movq	%rcx, -936(%rbp)
	movq	-936(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -1840(%rbp)       ## 8-byte Spill
	je	LBB0_22
## BB#21:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1840(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -888(%rbp)
	movq	-888(%rbp), %rcx
	movq	%rcx, -880(%rbp)
	movq	-880(%rbp), %rcx
	movq	%rcx, -872(%rbp)
	movq	-872(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1848(%rbp)       ## 8-byte Spill
	jmp	LBB0_23
LBB0_22:                                ##   in Loop: Header=BB0_10 Depth=1
	movq	-1840(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -928(%rbp)
	movq	-928(%rbp), %rcx
	movq	%rcx, -920(%rbp)
	movq	-920(%rbp), %rcx
	movq	%rcx, -912(%rbp)
	movq	-912(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -904(%rbp)
	movq	-904(%rbp), %rcx
	movq	%rcx, -896(%rbp)
	movq	-896(%rbp), %rcx
	movq	%rcx, -1848(%rbp)       ## 8-byte Spill
LBB0_23:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit3
                                        ##   in Loop: Header=BB0_10 Depth=1
	movq	-1848(%rbp), %rax       ## 8-byte Reload
	addq	-976(%rbp), %rax
	movq	%rax, -1856(%rbp)       ## 8-byte Spill
## BB#24:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1856(%rbp), %rax       ## 8-byte Reload
	movsbl	(%rax), %ecx
	cmpl	$91, %ecx
	jne	LBB0_35
LBB0_25:                                ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1616(%rbp), %rax
	movslq	-1632(%rbp), %rcx
	movq	%rax, -856(%rbp)
	movq	%rcx, -864(%rbp)
	movq	-856(%rbp), %rax
	movq	%rax, -848(%rbp)
	movq	-848(%rbp), %rax
	movq	%rax, -840(%rbp)
	movq	-840(%rbp), %rcx
	movq	%rcx, -832(%rbp)
	movq	-832(%rbp), %rcx
	movq	%rcx, -824(%rbp)
	movq	-824(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -1864(%rbp)       ## 8-byte Spill
	je	LBB0_27
## BB#26:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1864(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -776(%rbp)
	movq	-776(%rbp), %rcx
	movq	%rcx, -768(%rbp)
	movq	-768(%rbp), %rcx
	movq	%rcx, -760(%rbp)
	movq	-760(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1872(%rbp)       ## 8-byte Spill
	jmp	LBB0_28
LBB0_27:                                ##   in Loop: Header=BB0_10 Depth=1
	movq	-1864(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -816(%rbp)
	movq	-816(%rbp), %rcx
	movq	%rcx, -808(%rbp)
	movq	-808(%rbp), %rcx
	movq	%rcx, -800(%rbp)
	movq	-800(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -792(%rbp)
	movq	-792(%rbp), %rcx
	movq	%rcx, -784(%rbp)
	movq	-784(%rbp), %rcx
	movq	%rcx, -1872(%rbp)       ## 8-byte Spill
LBB0_28:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit4
                                        ##   in Loop: Header=BB0_10 Depth=1
	movq	-1872(%rbp), %rax       ## 8-byte Reload
	addq	-864(%rbp), %rax
	movq	%rax, -1880(%rbp)       ## 8-byte Spill
## BB#29:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1880(%rbp), %rax       ## 8-byte Reload
	movsbl	(%rax), %ecx
	movl	%ecx, -1692(%rbp)
	leaq	-1688(%rbp), %rdx
	movq	%rdx, -744(%rbp)
	leaq	-1692(%rbp), %rdx
	movq	%rdx, -752(%rbp)
	movq	-744(%rbp), %rdi
	movq	%rdx, -736(%rbp)
Ltmp28:
	movq	%rdx, %rsi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj
Ltmp29:
	jmp	LBB0_30
LBB0_30:                                ## %_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEE4pushEOj.exit
                                        ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_31
LBB0_31:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_71
LBB0_32:
Ltmp9:
	movl	%edx, %ecx
	movq	%rax, -1768(%rbp)       ## 8-byte Spill
	movl	%ecx, -1772(%rbp)       ## 4-byte Spill
	jmp	LBB0_33
LBB0_33:                                ## %.body
	movl	-1772(%rbp), %eax       ## 4-byte Reload
	movq	-1768(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1624(%rbp)
	movl	%eax, -1628(%rbp)
	jmp	LBB0_93
LBB0_34:
Ltmp30:
	leaq	-1688(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -1624(%rbp)
	movl	%ecx, -1628(%rbp)
	callq	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED1Ev
	jmp	LBB0_93
LBB0_35:                                ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1616(%rbp), %rax
	movslq	-1632(%rbp), %rcx
	movq	%rax, -720(%rbp)
	movq	%rcx, -728(%rbp)
	movq	-720(%rbp), %rax
	movq	%rax, -712(%rbp)
	movq	-712(%rbp), %rax
	movq	%rax, -704(%rbp)
	movq	-704(%rbp), %rcx
	movq	%rcx, -696(%rbp)
	movq	-696(%rbp), %rcx
	movq	%rcx, -688(%rbp)
	movq	-688(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -1888(%rbp)       ## 8-byte Spill
	je	LBB0_37
## BB#36:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1888(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -640(%rbp)
	movq	-640(%rbp), %rcx
	movq	%rcx, -632(%rbp)
	movq	-632(%rbp), %rcx
	movq	%rcx, -624(%rbp)
	movq	-624(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1896(%rbp)       ## 8-byte Spill
	jmp	LBB0_38
LBB0_37:                                ##   in Loop: Header=BB0_10 Depth=1
	movq	-1888(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rcx
	movq	%rcx, -672(%rbp)
	movq	-672(%rbp), %rcx
	movq	%rcx, -664(%rbp)
	movq	-664(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -656(%rbp)
	movq	-656(%rbp), %rcx
	movq	%rcx, -648(%rbp)
	movq	-648(%rbp), %rcx
	movq	%rcx, -1896(%rbp)       ## 8-byte Spill
LBB0_38:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit6
                                        ##   in Loop: Header=BB0_10 Depth=1
	movq	-1896(%rbp), %rax       ## 8-byte Reload
	addq	-728(%rbp), %rax
	movq	%rax, -1904(%rbp)       ## 8-byte Spill
## BB#39:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1904(%rbp), %rax       ## 8-byte Reload
	movsbl	(%rax), %ecx
	cmpl	$41, %ecx
	jne	LBB0_52
## BB#40:                               ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -608(%rbp)
	movq	-608(%rbp), %rax
	movq	%rax, -592(%rbp)
	movq	-592(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -584(%rbp)
	movq	-584(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -576(%rbp)
	movq	-576(%rbp), %rcx
	movq	%rcx, -568(%rbp)
	movq	-568(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -600(%rbp)
	movq	%rax, -560(%rbp)
	movq	-560(%rbp), %rax
	movq	8(%rax), %rax
	movq	-600(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-600(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -1912(%rbp)       ## 8-byte Spill
## BB#41:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1912(%rbp), %rax       ## 8-byte Reload
	cmpl	$40, (%rax)
	jne	LBB0_47
## BB#42:                               ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -232(%rbp)
Ltmp24:
	movq	%rax, %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
Ltmp25:
	jmp	LBB0_43
LBB0_43:                                ## %_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEE3popEv.exit9
                                        ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_44
LBB0_44:                                ##   in Loop: Header=BB0_10 Depth=1
	movl	$2, -1696(%rbp)
	leaq	-1688(%rbp), %rax
	movq	%rax, -216(%rbp)
	leaq	-1696(%rbp), %rax
	movq	%rax, -224(%rbp)
	movq	-216(%rbp), %rdi
	movq	%rax, -208(%rbp)
Ltmp26:
	movq	%rax, %rsi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj
Ltmp27:
	jmp	LBB0_45
LBB0_45:                                ## %_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEE4pushEOj.exit11
                                        ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_46
LBB0_46:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_51
LBB0_47:                                ##   in Loop: Header=BB0_10 Depth=1
Ltmp20:
	leaq	-1688(%rbp), %rdi
	movl	$91, %esi
	movl	$40, %edx
	movl	$2, %ecx
	callq	__ZL14_push_in_stackRNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEEEhhj
Ltmp21:
	movb	%al, -1913(%rbp)        ## 1-byte Spill
	jmp	LBB0_48
LBB0_48:                                ##   in Loop: Header=BB0_10 Depth=1
	movb	-1913(%rbp), %al        ## 1-byte Reload
	andb	$1, %al
	movzbl	%al, %ecx
	cmpl	$0, %ecx
	jne	LBB0_50
## BB#49:
	jmp	LBB0_90
LBB0_50:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_51
LBB0_51:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_70
LBB0_52:                                ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1616(%rbp), %rax
	movslq	-1632(%rbp), %rcx
	movq	%rax, -192(%rbp)
	movq	%rcx, -200(%rbp)
	movq	-192(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rcx
	movq	%rcx, -168(%rbp)
	movq	-168(%rbp), %rcx
	movq	%rcx, -160(%rbp)
	movq	-160(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -1928(%rbp)       ## 8-byte Spill
	je	LBB0_54
## BB#53:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1928(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -1936(%rbp)       ## 8-byte Spill
	jmp	LBB0_55
LBB0_54:                                ##   in Loop: Header=BB0_10 Depth=1
	movq	-1928(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -152(%rbp)
	movq	-152(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -1936(%rbp)       ## 8-byte Spill
LBB0_55:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEixEm.exit12
                                        ##   in Loop: Header=BB0_10 Depth=1
	movq	-1936(%rbp), %rax       ## 8-byte Reload
	addq	-200(%rbp), %rax
	movq	%rax, -1944(%rbp)       ## 8-byte Spill
## BB#56:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1944(%rbp), %rax       ## 8-byte Reload
	movsbl	(%rax), %ecx
	cmpl	$93, %ecx
	jne	LBB0_69
## BB#57:                               ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -56(%rbp)
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	-56(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-56(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -1952(%rbp)       ## 8-byte Spill
## BB#58:                               ##   in Loop: Header=BB0_10 Depth=1
	movq	-1952(%rbp), %rax       ## 8-byte Reload
	cmpl	$91, (%rax)
	jne	LBB0_64
## BB#59:                               ##   in Loop: Header=BB0_10 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -8(%rbp)
Ltmp16:
	movq	%rax, %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
Ltmp17:
	jmp	LBB0_60
LBB0_60:                                ## %_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEE3popEv.exit16
                                        ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_61
LBB0_61:                                ##   in Loop: Header=BB0_10 Depth=1
	movl	$3, -1700(%rbp)
	leaq	-1688(%rbp), %rax
	movq	%rax, -80(%rbp)
	leaq	-1700(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-80(%rbp), %rdi
	movq	%rax, -72(%rbp)
Ltmp18:
	movq	%rax, %rsi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj
Ltmp19:
	jmp	LBB0_62
LBB0_62:                                ## %_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEE4pushEOj.exit14
                                        ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_63
LBB0_63:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_68
LBB0_64:                                ##   in Loop: Header=BB0_10 Depth=1
Ltmp14:
	leaq	-1688(%rbp), %rdi
	movl	$40, %esi
	movl	$91, %edx
	movl	$3, %ecx
	callq	__ZL14_push_in_stackRNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEEEhhj
Ltmp15:
	movb	%al, -1953(%rbp)        ## 1-byte Spill
	jmp	LBB0_65
LBB0_65:                                ##   in Loop: Header=BB0_10 Depth=1
	movb	-1953(%rbp), %al        ## 1-byte Reload
	andb	$1, %al
	movzbl	%al, %ecx
	cmpl	$0, %ecx
	jne	LBB0_67
## BB#66:
	jmp	LBB0_90
LBB0_67:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_68
LBB0_68:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_69
LBB0_69:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_70
LBB0_70:                                ##   in Loop: Header=BB0_10 Depth=1
	jmp	LBB0_71
LBB0_71:                                ##   in Loop: Header=BB0_10 Depth=1
	movl	-1632(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -1632(%rbp)
	jmp	LBB0_10
LBB0_72:
	jmp	LBB0_73
LBB0_73:                                ## =>This Inner Loop Header: Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	%rax, -264(%rbp)
	movq	-264(%rbp), %rax
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rax
	movq	%rax, -240(%rbp)
	movq	-240(%rbp), %rax
	cmpq	$0, (%rax)
	sete	%cl
	movb	%cl, -1954(%rbp)        ## 1-byte Spill
## BB#74:                               ##   in Loop: Header=BB0_73 Depth=1
	movb	-1954(%rbp), %al        ## 1-byte Reload
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB0_75
	jmp	LBB0_88
LBB0_75:                                ##   in Loop: Header=BB0_73 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -328(%rbp)
	movq	-328(%rbp), %rax
	movq	%rax, -312(%rbp)
	movq	-312(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -304(%rbp)
	movq	-304(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -296(%rbp)
	movq	-296(%rbp), %rcx
	movq	%rcx, -288(%rbp)
	movq	-288(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -320(%rbp)
	movq	%rax, -280(%rbp)
	movq	-280(%rbp), %rax
	movq	8(%rax), %rax
	movq	-320(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-320(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -1968(%rbp)       ## 8-byte Spill
## BB#76:                               ##   in Loop: Header=BB0_73 Depth=1
	movq	-1968(%rbp), %rax       ## 8-byte Reload
	cmpl	$40, (%rax)
	je	LBB0_83
## BB#77:                               ##   in Loop: Header=BB0_73 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -384(%rbp)
	movq	-384(%rbp), %rax
	movq	%rax, -368(%rbp)
	movq	-368(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -360(%rbp)
	movq	-360(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -352(%rbp)
	movq	-352(%rbp), %rcx
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -376(%rbp)
	movq	%rax, -336(%rbp)
	movq	-336(%rbp), %rax
	movq	8(%rax), %rax
	movq	-376(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-376(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -1976(%rbp)       ## 8-byte Spill
## BB#78:                               ##   in Loop: Header=BB0_73 Depth=1
	movq	-1976(%rbp), %rax       ## 8-byte Reload
	cmpl	$41, (%rax)
	je	LBB0_83
## BB#79:                               ##   in Loop: Header=BB0_73 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -440(%rbp)
	movq	-440(%rbp), %rax
	movq	%rax, -424(%rbp)
	movq	-424(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -416(%rbp)
	movq	-416(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -408(%rbp)
	movq	-408(%rbp), %rcx
	movq	%rcx, -400(%rbp)
	movq	-400(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -432(%rbp)
	movq	%rax, -392(%rbp)
	movq	-392(%rbp), %rax
	movq	8(%rax), %rax
	movq	-432(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-432(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -1984(%rbp)       ## 8-byte Spill
## BB#80:                               ##   in Loop: Header=BB0_73 Depth=1
	movq	-1984(%rbp), %rax       ## 8-byte Reload
	cmpl	$91, (%rax)
	je	LBB0_83
## BB#81:                               ##   in Loop: Header=BB0_73 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -496(%rbp)
	movq	-496(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -472(%rbp)
	movq	-472(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -464(%rbp)
	movq	-464(%rbp), %rcx
	movq	%rcx, -456(%rbp)
	movq	-456(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -488(%rbp)
	movq	%rax, -448(%rbp)
	movq	-448(%rbp), %rax
	movq	8(%rax), %rax
	movq	-488(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-488(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -1992(%rbp)       ## 8-byte Spill
## BB#82:                               ##   in Loop: Header=BB0_73 Depth=1
	movq	-1992(%rbp), %rax       ## 8-byte Reload
	cmpl	$93, (%rax)
	jne	LBB0_84
LBB0_83:
	jmp	LBB0_90
LBB0_84:                                ##   in Loop: Header=BB0_73 Depth=1
	leaq	-1688(%rbp), %rax
	movq	%rax, -552(%rbp)
	movq	-552(%rbp), %rax
	movq	%rax, -536(%rbp)
	movq	-536(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -528(%rbp)
	movq	-528(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rcx
	movq	%rcx, -512(%rbp)
	movq	-512(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -544(%rbp)
	movq	%rax, -504(%rbp)
	movq	-504(%rbp), %rax
	movq	8(%rax), %rax
	movq	-544(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-544(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -2000(%rbp)       ## 8-byte Spill
## BB#85:                               ##   in Loop: Header=BB0_73 Depth=1
	movq	-2000(%rbp), %rax       ## 8-byte Reload
	movl	(%rax), %ecx
	movl	-1636(%rbp), %edx
	addl	%ecx, %edx
	movl	%edx, -1636(%rbp)
	leaq	-1688(%rbp), %rsi
	movq	%rsi, -616(%rbp)
Ltmp12:
	movq	%rsi, %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
Ltmp13:
	jmp	LBB0_86
LBB0_86:                                ## %_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEE3popEv.exit
                                        ##   in Loop: Header=BB0_73 Depth=1
	jmp	LBB0_87
LBB0_87:                                ##   in Loop: Header=BB0_73 Depth=1
	jmp	LBB0_73
LBB0_88:
	movl	-1636(%rbp), %esi
Ltmp10:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	callq	_printf
Ltmp11:
	movl	%eax, -2004(%rbp)       ## 4-byte Spill
	jmp	LBB0_89
LBB0_89:
	movl	$0, -1588(%rbp)
	movl	$1, -1704(%rbp)
	jmp	LBB0_92
LBB0_90:
Ltmp22:
	leaq	L_.str.1(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	callq	_printf
Ltmp23:
	movl	%eax, -2008(%rbp)       ## 4-byte Spill
	jmp	LBB0_91
LBB0_91:
	movl	$-1, -1588(%rbp)
	movl	$1, -1704(%rbp)
LBB0_92:
	leaq	-1688(%rbp), %rdi
	callq	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED1Ev
	leaq	-1616(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	movl	-1588(%rbp), %eax
	addq	$2016, %rsp             ## imm = 0x7E0
	popq	%rbp
	retq
LBB0_93:
	leaq	-1616(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
## BB#94:
	movq	-1624(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table0:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\320"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	78                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp1-Ltmp0                     ##   Call between Ltmp0 and Ltmp1
	.long	Lset3
Lset4 = Ltmp9-Lfunc_begin0              ##     jumps to Ltmp9
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp2-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Ltmp5-Ltmp2                     ##   Call between Ltmp2 and Ltmp5
	.long	Lset6
Lset7 = Ltmp6-Lfunc_begin0              ##     jumps to Ltmp6
	.long	Lset7
	.byte	0                       ##   On action: cleanup
Lset8 = Ltmp7-Lfunc_begin0              ## >> Call Site 4 <<
	.long	Lset8
Lset9 = Ltmp8-Ltmp7                     ##   Call between Ltmp7 and Ltmp8
	.long	Lset9
Lset10 = Ltmp9-Lfunc_begin0             ##     jumps to Ltmp9
	.long	Lset10
	.byte	0                       ##   On action: cleanup
Lset11 = Ltmp28-Lfunc_begin0            ## >> Call Site 5 <<
	.long	Lset11
Lset12 = Ltmp23-Ltmp28                  ##   Call between Ltmp28 and Ltmp23
	.long	Lset12
Lset13 = Ltmp30-Lfunc_begin0            ##     jumps to Ltmp30
	.long	Lset13
	.byte	0                       ##   On action: cleanup
Lset14 = Ltmp23-Lfunc_begin0            ## >> Call Site 6 <<
	.long	Lset14
Lset15 = Lfunc_end0-Ltmp23              ##   Call between Ltmp23 and Lfunc_end0
	.long	Lset15
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
__ZL14_push_in_stackRNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEEEhhj: ## @_ZL14_push_in_stackRNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEEEhhj
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp34:
	.cfi_def_cfa_offset 16
Ltmp35:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp36:
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movb	%dl, %al
	movb	%sil, %r8b
	movq	%rdi, -144(%rbp)
	movb	%r8b, -145(%rbp)
	movb	%al, -146(%rbp)
	movl	%ecx, -152(%rbp)
	movl	$0, -160(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-144(%rbp), %rax
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rax
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	cmpq	$0, (%rax)
	sete	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	jne	LBB1_2
	jmp	LBB1_9
LBB1_2:                                 ##   in Loop: Header=BB1_1 Depth=1
	movq	-144(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	(%rcx), %rcx
	addq	32(%rax), %rcx
	subq	$1, %rcx
	movq	%rcx, -72(%rbp)
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	-72(%rbp), %rcx
	shrq	$10, %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-72(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	movl	(%rax,%rcx,4), %edx
	movl	%edx, -156(%rbp)
	movl	-156(%rbp), %edx
	movzbl	-145(%rbp), %esi
	cmpl	%esi, %edx
	jne	LBB1_4
## BB#3:
	jmp	LBB1_10
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-156(%rbp), %eax
	movzbl	-146(%rbp), %ecx
	cmpl	%ecx, %eax
	jne	LBB1_6
## BB#5:
	movq	-144(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
	leaq	-160(%rbp), %rax
	movl	-152(%rbp), %ecx
	imull	-160(%rbp), %ecx
	movl	%ecx, -160(%rbp)
	movq	-144(%rbp), %rdi
	movq	%rdi, -16(%rbp)
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backERKj
	jmp	LBB1_9
LBB1_6:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-156(%rbp), %eax
	addl	-160(%rbp), %eax
	movl	%eax, -160(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
## BB#7:                                ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_8
LBB1_8:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_1
LBB1_9:
	movb	$1, -129(%rbp)
	jmp	LBB1_11
LBB1_10:
	movb	$0, -129(%rbp)
LBB1_11:
	movb	-129(%rbp), %al
	andb	$1, %al
	movzbl	%al, %eax
	addq	$160, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED1Ev
	.p2align	4, 0x90
__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED1Ev: ## @_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp37:
	.cfi_def_cfa_offset 16
Ltmp38:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp39:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backERKj
	.weak_definition	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backERKj
	.p2align	4, 0x90
__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backERKj: ## @_ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backERKj
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp40:
	.cfi_def_cfa_offset 16
Ltmp41:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp42:
	.cfi_def_cfa_register %rbp
	subq	$320, %rsp              ## imm = 0x140
	movq	%rdi, -248(%rbp)
	movq	%rsi, -256(%rbp)
	movq	-248(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	addq	$40, %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	%rdi, -224(%rbp)
	movq	-224(%rbp), %rdi
	movq	%rdi, -264(%rbp)
	movq	%rsi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	cmpq	$0, %rdx
	movq	%rsi, -288(%rbp)        ## 8-byte Spill
	movq	%rdi, -296(%rbp)        ## 8-byte Spill
	movq	%rax, -304(%rbp)        ## 8-byte Spill
	jne	LBB3_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -312(%rbp)        ## 8-byte Spill
	jmp	LBB3_3
LBB3_2:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rcx
	movq	8(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	shlq	$10, %rcx
	subq	$1, %rcx
	movq	%rcx, -312(%rbp)        ## 8-byte Spill
LBB3_3:                                 ## %_ZNKSt3__15dequeIjNS_9allocatorIjEEE12__back_spareEv.exit
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	movq	32(%rcx), %rdx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	addq	(%rcx), %rdx
	subq	%rdx, %rax
	cmpq	$0, %rax
	jne	LBB3_5
## BB#4:
	movq	-288(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE19__add_back_capacityEv
LBB3_5:
	movq	-264(%rbp), %rax
	movq	-288(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, %rdi
	movq	%rax, -320(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv
	leaq	-280(%rbp), %rcx
	movq	%rax, -280(%rbp)
	movq	%rdx, -272(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	-256(%rbp), %rcx
	movq	-320(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -160(%rbp)
	movq	%rax, -168(%rbp)
	movq	%rcx, -176(%rbp)
	movq	-160(%rbp), %rax
	movq	-168(%rbp), %rcx
	movq	-176(%rbp), %rdx
	movq	%rdx, -152(%rbp)
	movq	-152(%rbp), %rdx
	movq	%rax, -128(%rbp)
	movq	%rcx, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-128(%rbp), %rax
	movq	-136(%rbp), %rcx
	movq	-144(%rbp), %rdx
	movq	%rdx, -112(%rbp)
	movq	-112(%rbp), %rdx
	movq	%rax, -88(%rbp)
	movq	%rcx, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	-96(%rbp), %rax
	movq	-104(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movl	(%rcx), %esi
	movl	%esi, (%rax)
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -208(%rbp)
	movq	-208(%rbp), %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	(%rax), %rcx
	addq	$1, %rcx
	movq	%rcx, (%rax)
	addq	$320, %rsp              ## imm = 0x140
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIjNS_9allocatorIjEEE19__add_back_capacityEv
	.weak_definition	__ZNSt3__15dequeIjNS_9allocatorIjEEE19__add_back_capacityEv
	.p2align	4, 0x90
__ZNSt3__15dequeIjNS_9allocatorIjEEE19__add_back_capacityEv: ## @_ZNSt3__15dequeIjNS_9allocatorIjEEE19__add_back_capacityEv
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## BB#0:
	pushq	%rbp
Ltmp57:
	.cfi_def_cfa_offset 16
Ltmp58:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp59:
	.cfi_def_cfa_register %rbp
	subq	$3376, %rsp             ## imm = 0xD30
	movq	%rdi, -3032(%rbp)
	movq	-3032(%rbp), %rdi
	movq	%rdi, %rax
	movq	%rax, -3024(%rbp)
	movq	-3024(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -3016(%rbp)
	movq	-3016(%rbp), %rax
	movq	%rax, -3008(%rbp)
	movq	-3008(%rbp), %rax
	movq	%rax, -3040(%rbp)
	movq	%rdi, -3000(%rbp)
	movq	-3000(%rbp), %rax
	cmpq	$1024, 32(%rax)         ## imm = 0x400
	movq	%rdi, -3208(%rbp)       ## 8-byte Spill
	jb	LBB4_14
## BB#1:
	leaq	-3048(%rbp), %rax
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	32(%rcx), %rdx
	subq	$1024, %rdx             ## imm = 0x400
	movq	%rdx, 32(%rcx)
	movq	%rcx, -2992(%rbp)
	movq	-2992(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -3048(%rbp)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2824(%rbp)
	movq	-2824(%rbp), %rcx
	movq	8(%rcx), %rdx
	addq	$8, %rdx
	movq	%rcx, -2792(%rbp)
	movq	%rdx, -2800(%rbp)
	movq	-2792(%rbp), %rcx
	movq	-2800(%rbp), %rdx
	movq	%rcx, -2776(%rbp)
	movq	%rdx, -2784(%rbp)
	movq	-2776(%rbp), %rcx
	movq	-2784(%rbp), %rdx
	movq	%rdx, 8(%rcx)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -2256(%rbp)
	movq	%rax, -2264(%rbp)
	movq	-2256(%rbp), %rax
	movq	16(%rax), %rcx
	movq	%rax, -2248(%rbp)
	movq	-2248(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -2240(%rbp)
	movq	-2240(%rbp), %rdx
	movq	%rdx, -2232(%rbp)
	movq	-2232(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -3216(%rbp)       ## 8-byte Spill
	jne	LBB4_13
## BB#2:
	movq	-3216(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB4_6
## BB#3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -2272(%rbp)
	movq	-2272(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -3224(%rbp)       ## 8-byte Spill
	cqto
	movq	-3224(%rbp), %rdi       ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -2272(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-2272(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -2056(%rbp)
	movq	%r8, -2064(%rbp)
	movq	%r9, -2072(%rbp)
	movq	-2056(%rbp), %rax
	movq	%rax, -2048(%rbp)
	movq	-2048(%rbp), %rax
	movq	-2064(%rbp), %rcx
	movq	%rcx, -2000(%rbp)
	movq	-2000(%rbp), %rcx
	movq	-2072(%rbp), %r8
	movq	%r8, -2008(%rbp)
	movq	-2008(%rbp), %r8
	movq	%rax, -2016(%rbp)
	movq	%rcx, -2024(%rbp)
	movq	%r8, -2032(%rbp)
	movq	-2024(%rbp), %rax
	movq	-2016(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -2040(%rbp)
	cmpq	$0, -2040(%rbp)
	jbe	LBB4_5
## BB#4:
	movq	-2032(%rbp), %rax
	movq	-2016(%rbp), %rcx
	movq	-2040(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -3232(%rbp)       ## 8-byte Spill
LBB4_5:                                 ## %_ZNSt3__14moveIPPjS2_EET0_T_S4_S3_.exit.i
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-2032(%rbp), %rdx
	movq	-2040(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-2272(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB4_12
LBB4_6:
	leaq	-1688(%rbp), %rax
	leaq	-2296(%rbp), %rcx
	leaq	-2288(%rbp), %rdx
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -1992(%rbp)
	movq	-1992(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -1984(%rbp)
	movq	-1984(%rbp), %rdi
	movq	%rdi, -1976(%rbp)
	movq	-1976(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -2288(%rbp)
	movq	$1, -2296(%rbp)
	movq	%rdx, -1712(%rbp)
	movq	%rcx, -1720(%rbp)
	movq	-1712(%rbp), %rcx
	movq	-1720(%rbp), %rdx
	movq	%rcx, -1696(%rbp)
	movq	%rdx, -1704(%rbp)
	movq	-1696(%rbp), %rcx
	movq	-1704(%rbp), %rdx
	movq	%rax, -1664(%rbp)
	movq	%rcx, -1672(%rbp)
	movq	%rdx, -1680(%rbp)
	movq	-1672(%rbp), %rax
	movq	(%rax), %rax
	movq	-1680(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB4_8
## BB#7:
	movq	-1704(%rbp), %rax
	movq	%rax, -3240(%rbp)       ## 8-byte Spill
	jmp	LBB4_9
LBB4_8:
	movq	-1696(%rbp), %rax
	movq	%rax, -3240(%rbp)       ## 8-byte Spill
LBB4_9:                                 ## %_ZNSt3__13maxImEERKT_S3_S3_.exit.i
	movq	-3240(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rax
	movq	%rax, -2280(%rbp)
	movq	%rax, %rcx
	shrq	$2, %rcx
	movq	-3216(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -1592(%rbp)
	addq	$24, %rdx
	movq	%rdx, -1584(%rbp)
	movq	%rdx, -1576(%rbp)
	leaq	-2336(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rsi, -3248(%rbp)       ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -3256(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-3256(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	movq	-3216(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	leaq	-2344(%rbp), %rdx
	movq	%rdx, -1616(%rbp)
	movq	%rcx, -1624(%rbp)
	movq	-1616(%rbp), %rdx
	movq	%rdx, -1600(%rbp)
	movq	%rcx, -1608(%rbp)
	movq	-1600(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	16(%rax), %rcx
	leaq	-2368(%rbp), %rdx
	movq	%rdx, -1648(%rbp)
	movq	%rcx, -1656(%rbp)
	movq	-1648(%rbp), %rdx
	movq	%rdx, -1632(%rbp)
	movq	%rcx, -1640(%rbp)
	movq	-1632(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-2344(%rbp), %rsi
	movq	-2368(%rbp), %rdx
Ltmp54:
	movq	-3248(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp55:
	jmp	LBB4_10
LBB4_10:
	leaq	-2336(%rbp), %rax
	leaq	-1968(%rbp), %rcx
	leaq	-1872(%rbp), %rdx
	leaq	-1824(%rbp), %rsi
	leaq	-1776(%rbp), %rdi
	movq	-3216(%rbp), %r8        ## 8-byte Reload
	movq	%r8, -1760(%rbp)
	movq	%rax, -1768(%rbp)
	movq	-1760(%rbp), %r9
	movq	%r9, -1752(%rbp)
	movq	-1752(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -1776(%rbp)
	movq	-1768(%rbp), %r9
	movq	%r9, -1736(%rbp)
	movq	-1736(%rbp), %r9
	movq	(%r9), %r9
	movq	-1760(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -1744(%rbp)
	movq	-1744(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-1768(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -1808(%rbp)
	movq	%rdi, -1816(%rbp)
	movq	-1808(%rbp), %rdi
	movq	%rdi, -1800(%rbp)
	movq	-1800(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -1824(%rbp)
	movq	-1816(%rbp), %rdi
	movq	%rdi, -1784(%rbp)
	movq	-1784(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-1808(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -1792(%rbp)
	movq	-1792(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1816(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-3216(%rbp), %rsi       ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -1856(%rbp)
	movq	%rdi, -1864(%rbp)
	movq	-1856(%rbp), %rsi
	movq	%rsi, -1848(%rbp)
	movq	-1848(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -1872(%rbp)
	movq	-1864(%rbp), %rsi
	movq	%rsi, -1832(%rbp)
	movq	-1832(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1856(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -1840(%rbp)
	movq	-1840(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-1864(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-3216(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -1896(%rbp)
	movq	-1896(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -1888(%rbp)
	movq	-1888(%rbp), %rsi
	movq	%rsi, -1880(%rbp)
	movq	-1880(%rbp), %rsi
	movq	%rax, -1920(%rbp)
	movq	-1920(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -1912(%rbp)
	movq	-1912(%rbp), %rdi
	movq	%rdi, -1904(%rbp)
	movq	-1904(%rbp), %rdi
	movq	%rsi, -1952(%rbp)
	movq	%rdi, -1960(%rbp)
	movq	-1952(%rbp), %rsi
	movq	%rsi, -1944(%rbp)
	movq	-1944(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -1968(%rbp)
	movq	-1960(%rbp), %rsi
	movq	%rsi, -1928(%rbp)
	movq	-1928(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-1952(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -1936(%rbp)
	movq	-1936(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-1960(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB4_12
LBB4_11:
Ltmp56:
	leaq	-2336(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -2352(%rbp)
	movl	%ecx, -2356(%rbp)
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	movq	-2352(%rbp), %rax
	movq	%rax, -3264(%rbp)       ## 8-byte Spill
	jmp	LBB4_52
LBB4_12:
	jmp	LBB4_13
LBB4_13:                                ## %_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backERKS1_.exit
	movq	-3216(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2096(%rbp)
	movq	-2096(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -2088(%rbp)
	movq	-2088(%rbp), %rcx
	movq	%rcx, -2080(%rbp)
	movq	-2080(%rbp), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -2104(%rbp)
	movq	-2104(%rbp), %rdx
	movq	-2264(%rbp), %rsi
	movq	%rcx, -2192(%rbp)
	movq	%rdx, -2200(%rbp)
	movq	%rsi, -2208(%rbp)
	movq	-2192(%rbp), %rcx
	movq	-2200(%rbp), %rdx
	movq	-2208(%rbp), %rsi
	movq	%rsi, -2184(%rbp)
	movq	-2184(%rbp), %rsi
	movq	%rcx, -2160(%rbp)
	movq	%rdx, -2168(%rbp)
	movq	%rsi, -2176(%rbp)
	movq	-2160(%rbp), %rcx
	movq	-2168(%rbp), %rdx
	movq	-2176(%rbp), %rsi
	movq	%rsi, -2144(%rbp)
	movq	-2144(%rbp), %rsi
	movq	%rcx, -2120(%rbp)
	movq	%rdx, -2128(%rbp)
	movq	%rsi, -2136(%rbp)
	movq	-2128(%rbp), %rcx
	movq	-2136(%rbp), %rdx
	movq	%rdx, -2112(%rbp)
	movq	-2112(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
	jmp	LBB4_50
LBB4_14:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1568(%rbp)
	movq	-1568(%rbp), %rax
	movq	16(%rax), %rcx
	movq	8(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1560(%rbp)
	movq	-1560(%rbp), %rax
	movq	%rax, -1552(%rbp)
	movq	-1552(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -1544(%rbp)
	movq	-1544(%rbp), %rdx
	movq	%rdx, -1536(%rbp)
	movq	-1536(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	(%rax), %rax
	subq	%rax, %rdx
	sarq	$3, %rdx
	cmpq	%rdx, %rcx
	jae	LBB4_31
## BB#15:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1528(%rbp)
	movq	-1528(%rbp), %rax
	movq	%rax, -1520(%rbp)
	movq	-1520(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -1512(%rbp)
	movq	-1512(%rbp), %rcx
	movq	%rcx, -1504(%rbp)
	movq	-1504(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	16(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	cmpq	$0, %rcx
	je	LBB4_17
## BB#16:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	-3040(%rbp), %rcx
	movq	%rcx, -1488(%rbp)
	movq	$1024, -1496(%rbp)      ## imm = 0x400
	movq	-1488(%rbp), %rcx
	movq	-1496(%rbp), %rdx
	movq	%rcx, -1464(%rbp)
	movq	%rdx, -1472(%rbp)
	movq	$0, -1480(%rbp)
	movq	-1472(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rcx, -1456(%rbp)
	movq	-1456(%rbp), %rdi
	movq	%rax, -3272(%rbp)       ## 8-byte Spill
	callq	__Znwm
	leaq	-3056(%rbp), %rsi
	movq	%rax, -3056(%rbp)
	movq	-3272(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backEOS1_
	jmp	LBB4_30
LBB4_17:
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	-3040(%rbp), %rcx
	movq	%rcx, -1440(%rbp)
	movq	$1024, -1448(%rbp)      ## imm = 0x400
	movq	-1440(%rbp), %rcx
	movq	-1448(%rbp), %rdx
	movq	%rcx, -1416(%rbp)
	movq	%rdx, -1424(%rbp)
	movq	$0, -1432(%rbp)
	movq	-1424(%rbp), %rcx
	shlq	$2, %rcx
	movq	%rcx, -1408(%rbp)
	movq	-1408(%rbp), %rdi
	movq	%rax, -3280(%rbp)       ## 8-byte Spill
	callq	__Znwm
	leaq	-3064(%rbp), %rsi
	movq	%rax, -3064(%rbp)
	movq	-3280(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE10push_frontEOS1_
	leaq	-3072(%rbp), %rax
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1400(%rbp)
	movq	-1400(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -3072(%rbp)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1392(%rbp)
	movq	-1392(%rbp), %rcx
	movq	8(%rcx), %rdx
	addq	$8, %rdx
	movq	%rcx, -1360(%rbp)
	movq	%rdx, -1368(%rbp)
	movq	-1360(%rbp), %rcx
	movq	-1368(%rbp), %rdx
	movq	%rcx, -1344(%rbp)
	movq	%rdx, -1352(%rbp)
	movq	-1344(%rbp), %rcx
	movq	-1352(%rbp), %rdx
	movq	%rdx, 8(%rcx)
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1160(%rbp)
	movq	%rax, -1168(%rbp)
	movq	-1160(%rbp), %rax
	movq	16(%rax), %rcx
	movq	%rax, -1152(%rbp)
	movq	-1152(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -1144(%rbp)
	movq	-1144(%rbp), %rdx
	movq	%rdx, -1136(%rbp)
	movq	-1136(%rbp), %rdx
	cmpq	(%rdx), %rcx
	movq	%rax, -3288(%rbp)       ## 8-byte Spill
	jne	LBB4_29
## BB#18:
	movq	-3288(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB4_22
## BB#19:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -1176(%rbp)
	movq	-1176(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -3296(%rbp)       ## 8-byte Spill
	cqto
	movq	-3296(%rbp), %rdi       ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -1176(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-1176(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -960(%rbp)
	movq	%r8, -968(%rbp)
	movq	%r9, -976(%rbp)
	movq	-960(%rbp), %rax
	movq	%rax, -952(%rbp)
	movq	-952(%rbp), %rax
	movq	-968(%rbp), %rcx
	movq	%rcx, -904(%rbp)
	movq	-904(%rbp), %rcx
	movq	-976(%rbp), %r8
	movq	%r8, -912(%rbp)
	movq	-912(%rbp), %r8
	movq	%rax, -920(%rbp)
	movq	%rcx, -928(%rbp)
	movq	%r8, -936(%rbp)
	movq	-928(%rbp), %rax
	movq	-920(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -944(%rbp)
	cmpq	$0, -944(%rbp)
	jbe	LBB4_21
## BB#20:
	movq	-936(%rbp), %rax
	movq	-920(%rbp), %rcx
	movq	-944(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -3304(%rbp)       ## 8-byte Spill
LBB4_21:                                ## %_ZNSt3__14moveIPPjS2_EET0_T_S4_S3_.exit.i2
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-936(%rbp), %rdx
	movq	-944(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-1176(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB4_28
LBB4_22:
	leaq	-592(%rbp), %rax
	leaq	-1200(%rbp), %rcx
	leaq	-1192(%rbp), %rdx
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -896(%rbp)
	movq	-896(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -888(%rbp)
	movq	-888(%rbp), %rdi
	movq	%rdi, -880(%rbp)
	movq	-880(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -1192(%rbp)
	movq	$1, -1200(%rbp)
	movq	%rdx, -616(%rbp)
	movq	%rcx, -624(%rbp)
	movq	-616(%rbp), %rcx
	movq	-624(%rbp), %rdx
	movq	%rcx, -600(%rbp)
	movq	%rdx, -608(%rbp)
	movq	-600(%rbp), %rcx
	movq	-608(%rbp), %rdx
	movq	%rax, -568(%rbp)
	movq	%rcx, -576(%rbp)
	movq	%rdx, -584(%rbp)
	movq	-576(%rbp), %rax
	movq	(%rax), %rax
	movq	-584(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB4_24
## BB#23:
	movq	-608(%rbp), %rax
	movq	%rax, -3312(%rbp)       ## 8-byte Spill
	jmp	LBB4_25
LBB4_24:
	movq	-600(%rbp), %rax
	movq	%rax, -3312(%rbp)       ## 8-byte Spill
LBB4_25:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit.i3
	movq	-3312(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rax
	movq	%rax, -1184(%rbp)
	movq	%rax, %rcx
	shrq	$2, %rcx
	movq	-3288(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -496(%rbp)
	addq	$24, %rdx
	movq	%rdx, -488(%rbp)
	movq	%rdx, -480(%rbp)
	leaq	-1240(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rsi, -3320(%rbp)       ## 8-byte Spill
	movq	%rax, %rsi
	movq	%rdx, -3328(%rbp)       ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-3328(%rbp), %rcx       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	movq	-3288(%rbp), %rax       ## 8-byte Reload
	movq	8(%rax), %rcx
	leaq	-1248(%rbp), %rdx
	movq	%rdx, -520(%rbp)
	movq	%rcx, -528(%rbp)
	movq	-520(%rbp), %rdx
	movq	%rdx, -504(%rbp)
	movq	%rcx, -512(%rbp)
	movq	-504(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	16(%rax), %rcx
	leaq	-1272(%rbp), %rdx
	movq	%rdx, -552(%rbp)
	movq	%rcx, -560(%rbp)
	movq	-552(%rbp), %rdx
	movq	%rdx, -536(%rbp)
	movq	%rcx, -544(%rbp)
	movq	-536(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-1248(%rbp), %rsi
	movq	-1272(%rbp), %rdx
Ltmp51:
	movq	-3320(%rbp), %rdi       ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp52:
	jmp	LBB4_26
LBB4_26:
	leaq	-1240(%rbp), %rax
	leaq	-872(%rbp), %rcx
	leaq	-776(%rbp), %rdx
	leaq	-728(%rbp), %rsi
	leaq	-680(%rbp), %rdi
	movq	-3288(%rbp), %r8        ## 8-byte Reload
	movq	%r8, -664(%rbp)
	movq	%rax, -672(%rbp)
	movq	-664(%rbp), %r9
	movq	%r9, -656(%rbp)
	movq	-656(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -680(%rbp)
	movq	-672(%rbp), %r9
	movq	%r9, -640(%rbp)
	movq	-640(%rbp), %r9
	movq	(%r9), %r9
	movq	-664(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -648(%rbp)
	movq	-648(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-672(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -712(%rbp)
	movq	%rdi, -720(%rbp)
	movq	-712(%rbp), %rdi
	movq	%rdi, -704(%rbp)
	movq	-704(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -728(%rbp)
	movq	-720(%rbp), %rdi
	movq	%rdi, -688(%rbp)
	movq	-688(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-712(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -696(%rbp)
	movq	-696(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-720(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-3288(%rbp), %rsi       ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -760(%rbp)
	movq	%rdi, -768(%rbp)
	movq	-760(%rbp), %rsi
	movq	%rsi, -752(%rbp)
	movq	-752(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -776(%rbp)
	movq	-768(%rbp), %rsi
	movq	%rsi, -736(%rbp)
	movq	-736(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-760(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -744(%rbp)
	movq	-744(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-768(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-3288(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -800(%rbp)
	movq	-800(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -792(%rbp)
	movq	-792(%rbp), %rsi
	movq	%rsi, -784(%rbp)
	movq	-784(%rbp), %rsi
	movq	%rax, -824(%rbp)
	movq	-824(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -816(%rbp)
	movq	-816(%rbp), %rdi
	movq	%rdi, -808(%rbp)
	movq	-808(%rbp), %rdi
	movq	%rsi, -856(%rbp)
	movq	%rdi, -864(%rbp)
	movq	-856(%rbp), %rsi
	movq	%rsi, -848(%rbp)
	movq	-848(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -872(%rbp)
	movq	-864(%rbp), %rsi
	movq	%rsi, -832(%rbp)
	movq	-832(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-856(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -840(%rbp)
	movq	-840(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-864(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB4_28
LBB4_27:
Ltmp53:
	leaq	-1240(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -1256(%rbp)
	movl	%ecx, -1260(%rbp)
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	movq	-1256(%rbp), %rax
	movq	%rax, -3264(%rbp)       ## 8-byte Spill
	jmp	LBB4_52
LBB4_28:
	jmp	LBB4_29
LBB4_29:                                ## %_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backERKS1_.exit4
	movq	-3288(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1000(%rbp)
	movq	-1000(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -992(%rbp)
	movq	-992(%rbp), %rcx
	movq	%rcx, -984(%rbp)
	movq	-984(%rbp), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -1008(%rbp)
	movq	-1008(%rbp), %rdx
	movq	-1168(%rbp), %rsi
	movq	%rcx, -1096(%rbp)
	movq	%rdx, -1104(%rbp)
	movq	%rsi, -1112(%rbp)
	movq	-1096(%rbp), %rcx
	movq	-1104(%rbp), %rdx
	movq	-1112(%rbp), %rsi
	movq	%rsi, -1088(%rbp)
	movq	-1088(%rbp), %rsi
	movq	%rcx, -1064(%rbp)
	movq	%rdx, -1072(%rbp)
	movq	%rsi, -1080(%rbp)
	movq	-1064(%rbp), %rcx
	movq	-1072(%rbp), %rdx
	movq	-1080(%rbp), %rsi
	movq	%rsi, -1048(%rbp)
	movq	-1048(%rbp), %rsi
	movq	%rcx, -1024(%rbp)
	movq	%rdx, -1032(%rbp)
	movq	%rsi, -1040(%rbp)
	movq	-1032(%rbp), %rcx
	movq	-1040(%rbp), %rdx
	movq	%rdx, -1016(%rbp)
	movq	-1016(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
LBB4_30:
	jmp	LBB4_49
LBB4_31:
	leaq	-400(%rbp), %rax
	leaq	-3128(%rbp), %rcx
	leaq	-3120(%rbp), %rdx
	movq	-3208(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -472(%rbp)
	movq	-472(%rbp), %rsi
	movq	%rsi, -464(%rbp)
	movq	-464(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -456(%rbp)
	movq	-456(%rbp), %rdi
	movq	%rdi, -448(%rbp)
	movq	-448(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	subq	%rsi, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -3120(%rbp)
	movq	$1, -3128(%rbp)
	movq	%rdx, -424(%rbp)
	movq	%rcx, -432(%rbp)
	movq	-424(%rbp), %rcx
	movq	-432(%rbp), %rdx
	movq	%rcx, -408(%rbp)
	movq	%rdx, -416(%rbp)
	movq	-408(%rbp), %rcx
	movq	-416(%rbp), %rdx
	movq	%rax, -376(%rbp)
	movq	%rcx, -384(%rbp)
	movq	%rdx, -392(%rbp)
	movq	-384(%rbp), %rax
	movq	(%rax), %rax
	movq	-392(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB4_33
## BB#32:
	movq	-416(%rbp), %rax
	movq	%rax, -3336(%rbp)       ## 8-byte Spill
	jmp	LBB4_34
LBB4_33:
	movq	-408(%rbp), %rax
	movq	%rax, -3336(%rbp)       ## 8-byte Spill
LBB4_34:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-3336(%rbp), %rax       ## 8-byte Reload
	movq	(%rax), %rsi
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -368(%rbp)
	movq	8(%rax), %rcx
	movq	16(%rax), %rdx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	movq	%rax, -360(%rbp)
	addq	$24, %rax
	movq	%rax, -352(%rbp)
	movq	%rax, -344(%rbp)
	leaq	-3112(%rbp), %rdi
	movq	%rax, %rcx
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	movq	-3040(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	$1024, -48(%rbp)        ## imm = 0x400
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	$1024, -24(%rbp)        ## imm = 0x400
	movq	$0, -32(%rbp)
	movq	-24(%rbp), %rax
	shlq	$2, %rax
	movq	%rax, -8(%rbp)
Ltmp43:
	movq	%rax, %rdi
	callq	__Znwm
Ltmp44:
	movq	%rax, -3344(%rbp)       ## 8-byte Spill
	jmp	LBB4_35
LBB4_35:                                ## %_ZNSt3__116allocator_traitsINS_9allocatorIjEEE8allocateERS2_m.exit
	movq	-3344(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -3352(%rbp)       ## 8-byte Spill
## BB#36:
	movq	-3040(%rbp), %rax
	leaq	-3184(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	%rax, -88(%rbp)
	movq	$1024, -96(%rbp)        ## imm = 0x400
	movq	-80(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movq	$1024, -72(%rbp)        ## imm = 0x400
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-72(%rbp), %rdx
	movq	%rdx, 8(%rax)
	leaq	-3152(%rbp), %rax
	movq	%rax, -296(%rbp)
	movq	-3352(%rbp), %rdx       ## 8-byte Reload
	movq	%rdx, -304(%rbp)
	movq	%rcx, -312(%rbp)
	movq	-296(%rbp), %rsi
	movq	-304(%rbp), %rdi
	movq	%rsi, -256(%rbp)
	movq	%rdi, -264(%rbp)
	movq	%rcx, -272(%rbp)
	movq	-256(%rbp), %rsi
	movq	-264(%rbp), %rdi
	movq	%rcx, -248(%rbp)
	movq	-3184(%rbp), %rcx
	movq	-3176(%rbp), %r8
	movq	%r8, -280(%rbp)
	movq	%rcx, -288(%rbp)
	movq	-288(%rbp), %rcx
	movq	-280(%rbp), %r8
	movq	%rcx, -224(%rbp)
	movq	%r8, -216(%rbp)
	movq	%rsi, -232(%rbp)
	movq	%rdi, -240(%rbp)
	movq	-232(%rbp), %rcx
	movq	-224(%rbp), %rsi
	movq	-216(%rbp), %r8
	movq	%rsi, -176(%rbp)
	movq	%r8, -168(%rbp)
	movq	%rcx, -184(%rbp)
	movq	%rdi, -192(%rbp)
	movq	-184(%rbp), %rcx
	leaq	-192(%rbp), %rsi
	movq	%rsi, -160(%rbp)
	movq	-192(%rbp), %rsi
	leaq	-176(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-176(%rbp), %rdi
	movq	-168(%rbp), %r8
	movq	%r8, -200(%rbp)
	movq	%rdi, -208(%rbp)
	movq	-208(%rbp), %rdi
	movq	-200(%rbp), %r8
	movq	%rdi, -136(%rbp)
	movq	%r8, -128(%rbp)
	movq	%rcx, -144(%rbp)
	movq	%rsi, -152(%rbp)
	movq	-144(%rbp), %rcx
	leaq	-152(%rbp), %rsi
	movq	%rsi, -120(%rbp)
	movq	-152(%rbp), %rsi
	movq	%rsi, (%rcx)
	leaq	-136(%rbp), %rsi
	movq	%rsi, -112(%rbp)
	movq	-136(%rbp), %rsi
	movq	-128(%rbp), %rdi
	movq	%rdi, 16(%rcx)
	movq	%rsi, 8(%rcx)
	movq	%rax, -336(%rbp)
	movq	%rax, -328(%rbp)
	movq	%rax, -320(%rbp)
	movq	-3152(%rbp), %rax
	movq	%rax, -3192(%rbp)
Ltmp46:
	leaq	-3112(%rbp), %rdi
	leaq	-3192(%rbp), %rsi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE9push_backEOS1_
Ltmp47:
	jmp	LBB4_37
LBB4_37:
	leaq	-3152(%rbp), %rax
	movq	%rax, -1312(%rbp)
	movq	-1312(%rbp), %rax
	movq	%rax, -1304(%rbp)
	movq	-1304(%rbp), %rcx
	movq	%rcx, -1296(%rbp)
	movq	-1296(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -1320(%rbp)
	movq	%rax, -1288(%rbp)
	movq	-1288(%rbp), %rax
	movq	%rax, -1280(%rbp)
	movq	-1280(%rbp), %rax
	movq	$0, (%rax)
	movq	-3208(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -1328(%rbp)
	movq	-1328(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -3200(%rbp)
LBB4_38:                                ## =>This Inner Loop Header: Depth=1
	movq	-3200(%rbp), %rax
	movq	-3208(%rbp), %rcx       ## 8-byte Reload
	movq	%rcx, -1336(%rbp)
	movq	-1336(%rbp), %rcx
	cmpq	8(%rcx), %rax
	je	LBB4_45
## BB#39:                               ##   in Loop: Header=BB4_38 Depth=1
	movq	-3200(%rbp), %rax
	addq	$-8, %rax
	movq	%rax, -3200(%rbp)
Ltmp48:
	leaq	-3112(%rbp), %rdi
	movq	%rax, %rsi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE10push_frontERKS1_
Ltmp49:
	jmp	LBB4_40
LBB4_40:                                ##   in Loop: Header=BB4_38 Depth=1
	jmp	LBB4_38
LBB4_41:
Ltmp45:
	movl	%edx, %ecx
	movq	%rax, -3160(%rbp)
	movl	%ecx, -3164(%rbp)
	jmp	LBB4_48
LBB4_42:
Ltmp50:
	leaq	-3152(%rbp), %rcx
	movl	%edx, %esi
	movq	%rax, -3160(%rbp)
	movl	%esi, -3164(%rbp)
	movq	%rcx, -2528(%rbp)
	movq	-2528(%rbp), %rax
	movq	%rax, -2520(%rbp)
	movq	-2520(%rbp), %rax
	movq	%rax, -2496(%rbp)
	movq	$0, -2504(%rbp)
	movq	-2496(%rbp), %rax
	movq	%rax, -2488(%rbp)
	movq	-2488(%rbp), %rcx
	movq	%rcx, -2480(%rbp)
	movq	-2480(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -2512(%rbp)
	movq	-2504(%rbp), %rcx
	movq	%rax, -2400(%rbp)
	movq	-2400(%rbp), %rdx
	movq	%rdx, -2392(%rbp)
	movq	-2392(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -2512(%rbp)
	movq	%rax, -3360(%rbp)       ## 8-byte Spill
	je	LBB4_44
## BB#43:
	movq	-3360(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2384(%rbp)
	movq	-2384(%rbp), %rcx
	movq	%rcx, -2376(%rbp)
	movq	-2376(%rbp), %rcx
	addq	$8, %rcx
	movq	-2512(%rbp), %rdx
	movq	%rcx, -2464(%rbp)
	movq	%rdx, -2472(%rbp)
	movq	-2464(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-2472(%rbp), %rsi
	movq	8(%rcx), %rcx
	movq	%rdx, -2440(%rbp)
	movq	%rsi, -2448(%rbp)
	movq	%rcx, -2456(%rbp)
	movq	-2440(%rbp), %rcx
	movq	-2448(%rbp), %rdx
	movq	-2456(%rbp), %rsi
	movq	%rcx, -2416(%rbp)
	movq	%rdx, -2424(%rbp)
	movq	%rsi, -2432(%rbp)
	movq	-2424(%rbp), %rcx
	movq	%rcx, -2408(%rbp)
	movq	-2408(%rbp), %rdi
	callq	__ZdlPv
LBB4_44:                                ## %_ZNSt3__110unique_ptrIPjNS_22__allocator_destructorINS_9allocatorIjEEEEED1Ev.exit1
	jmp	LBB4_48
LBB4_45:
	leaq	-3152(%rbp), %rax
	leaq	-2768(%rbp), %rcx
	leaq	-3112(%rbp), %rdx
	leaq	-2672(%rbp), %rsi
	leaq	-2624(%rbp), %rdi
	leaq	-2576(%rbp), %r8
	movq	-3208(%rbp), %r9        ## 8-byte Reload
	movq	%r9, -2560(%rbp)
	movq	%rdx, -2568(%rbp)
	movq	-2560(%rbp), %r9
	movq	%r9, -2552(%rbp)
	movq	-2552(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -2576(%rbp)
	movq	-2568(%rbp), %r9
	movq	%r9, -2536(%rbp)
	movq	-2536(%rbp), %r9
	movq	(%r9), %r9
	movq	-2560(%rbp), %r10
	movq	%r9, (%r10)
	movq	%r8, -2544(%rbp)
	movq	-2544(%rbp), %r8
	movq	(%r8), %r8
	movq	-2568(%rbp), %r9
	movq	%r8, (%r9)
	movq	-3208(%rbp), %r8        ## 8-byte Reload
	addq	$8, %r8
	movq	%rdx, %r9
	addq	$8, %r9
	movq	%r8, -2608(%rbp)
	movq	%r9, -2616(%rbp)
	movq	-2608(%rbp), %r8
	movq	%r8, -2600(%rbp)
	movq	-2600(%rbp), %r8
	movq	(%r8), %r8
	movq	%r8, -2624(%rbp)
	movq	-2616(%rbp), %r8
	movq	%r8, -2584(%rbp)
	movq	-2584(%rbp), %r8
	movq	(%r8), %r8
	movq	-2608(%rbp), %r9
	movq	%r8, (%r9)
	movq	%rdi, -2592(%rbp)
	movq	-2592(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-2616(%rbp), %r8
	movq	%rdi, (%r8)
	movq	-3208(%rbp), %rdi       ## 8-byte Reload
	addq	$16, %rdi
	movq	%rdx, %r8
	addq	$16, %r8
	movq	%rdi, -2656(%rbp)
	movq	%r8, -2664(%rbp)
	movq	-2656(%rbp), %rdi
	movq	%rdi, -2648(%rbp)
	movq	-2648(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -2672(%rbp)
	movq	-2664(%rbp), %rdi
	movq	%rdi, -2632(%rbp)
	movq	-2632(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-2656(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -2640(%rbp)
	movq	-2640(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-2664(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-3208(%rbp), %rsi       ## 8-byte Reload
	movq	%rsi, -2696(%rbp)
	movq	-2696(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -2688(%rbp)
	movq	-2688(%rbp), %rsi
	movq	%rsi, -2680(%rbp)
	movq	-2680(%rbp), %rsi
	movq	%rdx, -2720(%rbp)
	movq	-2720(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -2712(%rbp)
	movq	-2712(%rbp), %rdx
	movq	%rdx, -2704(%rbp)
	movq	-2704(%rbp), %rdx
	movq	%rsi, -2752(%rbp)
	movq	%rdx, -2760(%rbp)
	movq	-2752(%rbp), %rdx
	movq	%rdx, -2744(%rbp)
	movq	-2744(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -2768(%rbp)
	movq	-2760(%rbp), %rdx
	movq	%rdx, -2728(%rbp)
	movq	-2728(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-2752(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	%rcx, -2736(%rbp)
	movq	-2736(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-2760(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	%rax, -2984(%rbp)
	movq	-2984(%rbp), %rax
	movq	%rax, -2976(%rbp)
	movq	-2976(%rbp), %rax
	movq	%rax, -2952(%rbp)
	movq	$0, -2960(%rbp)
	movq	-2952(%rbp), %rax
	movq	%rax, -2944(%rbp)
	movq	-2944(%rbp), %rcx
	movq	%rcx, -2936(%rbp)
	movq	-2936(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -2968(%rbp)
	movq	-2960(%rbp), %rcx
	movq	%rax, -2856(%rbp)
	movq	-2856(%rbp), %rdx
	movq	%rdx, -2848(%rbp)
	movq	-2848(%rbp), %rdx
	movq	%rcx, (%rdx)
	cmpq	$0, -2968(%rbp)
	movq	%rax, -3368(%rbp)       ## 8-byte Spill
	je	LBB4_47
## BB#46:
	movq	-3368(%rbp), %rax       ## 8-byte Reload
	movq	%rax, -2840(%rbp)
	movq	-2840(%rbp), %rcx
	movq	%rcx, -2832(%rbp)
	movq	-2832(%rbp), %rcx
	addq	$8, %rcx
	movq	-2968(%rbp), %rdx
	movq	%rcx, -2920(%rbp)
	movq	%rdx, -2928(%rbp)
	movq	-2920(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-2928(%rbp), %rsi
	movq	8(%rcx), %rcx
	movq	%rdx, -2896(%rbp)
	movq	%rsi, -2904(%rbp)
	movq	%rcx, -2912(%rbp)
	movq	-2896(%rbp), %rcx
	movq	-2904(%rbp), %rdx
	movq	-2912(%rbp), %rsi
	movq	%rcx, -2872(%rbp)
	movq	%rdx, -2880(%rbp)
	movq	%rsi, -2888(%rbp)
	movq	-2880(%rbp), %rcx
	movq	%rcx, -2864(%rbp)
	movq	-2864(%rbp), %rdi
	callq	__ZdlPv
LBB4_47:                                ## %_ZNSt3__110unique_ptrIPjNS_22__allocator_destructorINS_9allocatorIjEEEEED1Ev.exit
	leaq	-3112(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB4_49
LBB4_48:
	leaq	-3112(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB4_51
LBB4_49:
	jmp	LBB4_50
LBB4_50:
	addq	$3376, %rsp             ## imm = 0xD30
	popq	%rbp
	retq
LBB4_51:
	movq	-3160(%rbp), %rax
	movq	%rax, -3264(%rbp)       ## 8-byte Spill
LBB4_52:                                ## %unwind_resume
	movq	-3264(%rbp), %rax       ## 8-byte Reload
	movq	%rax, %rdi
	callq	__Unwind_Resume
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table4:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\352\200\200"          ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	104                     ## Call site table length
Lset16 = Lfunc_begin1-Lfunc_begin1      ## >> Call Site 1 <<
	.long	Lset16
Lset17 = Ltmp54-Lfunc_begin1            ##   Call between Lfunc_begin1 and Ltmp54
	.long	Lset17
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset18 = Ltmp54-Lfunc_begin1            ## >> Call Site 2 <<
	.long	Lset18
Lset19 = Ltmp55-Ltmp54                  ##   Call between Ltmp54 and Ltmp55
	.long	Lset19
Lset20 = Ltmp56-Lfunc_begin1            ##     jumps to Ltmp56
	.long	Lset20
	.byte	0                       ##   On action: cleanup
Lset21 = Ltmp55-Lfunc_begin1            ## >> Call Site 3 <<
	.long	Lset21
Lset22 = Ltmp51-Ltmp55                  ##   Call between Ltmp55 and Ltmp51
	.long	Lset22
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset23 = Ltmp51-Lfunc_begin1            ## >> Call Site 4 <<
	.long	Lset23
Lset24 = Ltmp52-Ltmp51                  ##   Call between Ltmp51 and Ltmp52
	.long	Lset24
Lset25 = Ltmp53-Lfunc_begin1            ##     jumps to Ltmp53
	.long	Lset25
	.byte	0                       ##   On action: cleanup
Lset26 = Ltmp52-Lfunc_begin1            ## >> Call Site 5 <<
	.long	Lset26
Lset27 = Ltmp43-Ltmp52                  ##   Call between Ltmp52 and Ltmp43
	.long	Lset27
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset28 = Ltmp43-Lfunc_begin1            ## >> Call Site 6 <<
	.long	Lset28
Lset29 = Ltmp44-Ltmp43                  ##   Call between Ltmp43 and Ltmp44
	.long	Lset29
Lset30 = Ltmp45-Lfunc_begin1            ##     jumps to Ltmp45
	.long	Lset30
	.byte	0                       ##   On action: cleanup
Lset31 = Ltmp46-Lfunc_begin1            ## >> Call Site 7 <<
	.long	Lset31
Lset32 = Ltmp49-Ltmp46                  ##   Call between Ltmp46 and Ltmp49
	.long	Lset32
Lset33 = Ltmp50-Lfunc_begin1            ##     jumps to Ltmp50
	.long	Lset33
	.byte	0                       ##   On action: cleanup
Lset34 = Ltmp49-Lfunc_begin1            ## >> Call Site 8 <<
	.long	Lset34
Lset35 = Lfunc_end1-Ltmp49              ##   Call between Ltmp49 and Lfunc_end1
	.long	Lset35
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv
	.weak_definition	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv: ## @_ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp60:
	.cfi_def_cfa_offset 16
Ltmp61:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp62:
	.cfi_def_cfa_register %rbp
	subq	$40, %rsp
	movq	%rdi, -112(%rbp)
	movq	-112(%rbp), %rdi
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rdi, -136(%rbp)        ## 8-byte Spill
	movq	%rax, -144(%rbp)        ## 8-byte Spill
## BB#1:
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-136(%rbp), %rdx        ## 8-byte Reload
	addq	32(%rdx), %rcx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	-120(%rbp), %rsi
	shrq	$10, %rsi
	shlq	$3, %rsi
	addq	%rsi, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	16(%rsi), %rdi
	cmpq	8(%rsi), %rdi
	sete	%r8b
	movq	%rcx, -152(%rbp)        ## 8-byte Spill
	movb	%r8b, -153(%rbp)        ## 1-byte Spill
## BB#2:
	movb	-153(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB5_3
	jmp	LBB5_4
LBB5_3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -168(%rbp)        ## 8-byte Spill
	jmp	LBB5_5
LBB5_4:
	movq	-128(%rbp), %rax
	movq	(%rax), %rax
	movq	-120(%rbp), %rcx
	andq	$1023, %rcx             ## imm = 0x3FF
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -168(%rbp)        ## 8-byte Spill
LBB5_5:
	movq	-168(%rbp), %rax        ## 8-byte Reload
	leaq	-104(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	-152(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -48(%rbp)
	movq	%rax, -56(%rbp)
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	%rdx, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rax, -32(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-104(%rbp), %rax
	movq	-96(%rbp), %rdx
	addq	$40, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backEOS1_
	.weak_definition	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backEOS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backEOS1_: ## @_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE9push_backEOS1_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## BB#0:
	pushq	%rbp
Ltmp66:
	.cfi_def_cfa_offset 16
Ltmp67:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp68:
	.cfi_def_cfa_register %rbp
	subq	$848, %rsp              ## imm = 0x350
	movq	%rdi, -696(%rbp)
	movq	%rsi, -704(%rbp)
	movq	-696(%rbp), %rsi
	movq	16(%rsi), %rdi
	movq	%rsi, -688(%rbp)
	movq	-688(%rbp), %rax
	addq	$24, %rax
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rax
	movq	%rax, -672(%rbp)
	movq	-672(%rbp), %rax
	cmpq	(%rax), %rdi
	movq	%rsi, -816(%rbp)        ## 8-byte Spill
	jne	LBB6_14
## BB#1:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB6_5
## BB#2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -712(%rbp)
	movq	-712(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -824(%rbp)        ## 8-byte Spill
	cqto
	movq	-824(%rbp), %rdi        ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -712(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-712(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -488(%rbp)
	movq	%r8, -496(%rbp)
	movq	%r9, -504(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rax
	movq	-496(%rbp), %rcx
	movq	%rcx, -432(%rbp)
	movq	-432(%rbp), %rcx
	movq	-504(%rbp), %r8
	movq	%r8, -440(%rbp)
	movq	-440(%rbp), %r8
	movq	%rax, -448(%rbp)
	movq	%rcx, -456(%rbp)
	movq	%r8, -464(%rbp)
	movq	-456(%rbp), %rax
	movq	-448(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB6_4
## BB#3:
	movq	-464(%rbp), %rax
	movq	-448(%rbp), %rcx
	movq	-472(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -832(%rbp)        ## 8-byte Spill
LBB6_4:                                 ## %_ZNSt3__14moveIPPjS2_EET0_T_S4_S3_.exit
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-464(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-712(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB6_13
LBB6_5:
	leaq	-120(%rbp), %rax
	leaq	-736(%rbp), %rcx
	leaq	-728(%rbp), %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -424(%rbp)
	movq	-424(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -416(%rbp)
	movq	-416(%rbp), %rdi
	movq	%rdi, -408(%rbp)
	movq	-408(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -728(%rbp)
	movq	$1, -736(%rbp)
	movq	%rdx, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -128(%rbp)
	movq	%rdx, -136(%rbp)
	movq	-128(%rbp), %rcx
	movq	-136(%rbp), %rdx
	movq	%rax, -96(%rbp)
	movq	%rcx, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	-112(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB6_7
## BB#6:
	movq	-136(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
	jmp	LBB6_8
LBB6_7:
	movq	-128(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
LBB6_8:                                 ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-840(%rbp), %rax        ## 8-byte Reload
	leaq	-776(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -720(%rbp)
	movq	-720(%rbp), %rsi
	movq	-720(%rbp), %rax
	shrq	$2, %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, -848(%rbp)        ## 8-byte Spill
	movq	%rax, %rdx
	movq	-848(%rbp), %rcx        ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-784(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-48(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-808(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-80(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-784(%rbp), %rsi
	movq	-808(%rbp), %rdx
Ltmp63:
	leaq	-776(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp64:
	jmp	LBB6_11
LBB6_11:
	leaq	-776(%rbp), %rax
	leaq	-400(%rbp), %rcx
	leaq	-304(%rbp), %rdx
	leaq	-256(%rbp), %rsi
	leaq	-208(%rbp), %rdi
	movq	-816(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -192(%rbp)
	movq	%rax, -200(%rbp)
	movq	-192(%rbp), %r9
	movq	%r9, -184(%rbp)
	movq	-184(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -208(%rbp)
	movq	-200(%rbp), %r9
	movq	%r9, -168(%rbp)
	movq	-168(%rbp), %r9
	movq	(%r9), %r9
	movq	-192(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-200(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -240(%rbp)
	movq	%rdi, -248(%rbp)
	movq	-240(%rbp), %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -256(%rbp)
	movq	-248(%rbp), %rdi
	movq	%rdi, -216(%rbp)
	movq	-216(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-240(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -224(%rbp)
	movq	-224(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-248(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -288(%rbp)
	movq	%rdi, -296(%rbp)
	movq	-288(%rbp), %rsi
	movq	%rsi, -280(%rbp)
	movq	-280(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -304(%rbp)
	movq	-296(%rbp), %rsi
	movq	%rsi, -264(%rbp)
	movq	-264(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-288(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -272(%rbp)
	movq	-272(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-296(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-816(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -328(%rbp)
	movq	-328(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -320(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -312(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rax, -352(%rbp)
	movq	-352(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -344(%rbp)
	movq	-344(%rbp), %rdi
	movq	%rdi, -336(%rbp)
	movq	-336(%rbp), %rdi
	movq	%rsi, -384(%rbp)
	movq	%rdi, -392(%rbp)
	movq	-384(%rbp), %rsi
	movq	%rsi, -376(%rbp)
	movq	-376(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -400(%rbp)
	movq	-392(%rbp), %rsi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-384(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -368(%rbp)
	movq	-368(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-392(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB6_13
LBB6_12:
Ltmp65:
	leaq	-776(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -792(%rbp)
	movl	%ecx, -796(%rbp)
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB6_15
LBB6_13:
	jmp	LBB6_14
LBB6_14:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -528(%rbp)
	movq	-528(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rcx
	movq	%rcx, -512(%rbp)
	movq	-512(%rbp), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -536(%rbp)
	movq	-536(%rbp), %rdx
	movq	-704(%rbp), %rsi
	movq	%rsi, -544(%rbp)
	movq	-544(%rbp), %rsi
	movq	%rcx, -632(%rbp)
	movq	%rdx, -640(%rbp)
	movq	%rsi, -648(%rbp)
	movq	-632(%rbp), %rcx
	movq	-640(%rbp), %rdx
	movq	-648(%rbp), %rsi
	movq	%rsi, -624(%rbp)
	movq	-624(%rbp), %rsi
	movq	%rcx, -600(%rbp)
	movq	%rdx, -608(%rbp)
	movq	%rsi, -616(%rbp)
	movq	-600(%rbp), %rcx
	movq	-608(%rbp), %rdx
	movq	-616(%rbp), %rsi
	movq	%rsi, -584(%rbp)
	movq	-584(%rbp), %rsi
	movq	%rcx, -560(%rbp)
	movq	%rdx, -568(%rbp)
	movq	%rsi, -576(%rbp)
	movq	-568(%rbp), %rcx
	movq	-576(%rbp), %rdx
	movq	%rdx, -552(%rbp)
	movq	-552(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
	addq	$848, %rsp              ## imm = 0x350
	popq	%rbp
	retq
LBB6_15:
	movq	-792(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table6:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset36 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset36
Lset37 = Ltmp63-Lfunc_begin2            ##   Call between Lfunc_begin2 and Ltmp63
	.long	Lset37
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset38 = Ltmp63-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset38
Lset39 = Ltmp64-Ltmp63                  ##   Call between Ltmp63 and Ltmp64
	.long	Lset39
Lset40 = Ltmp65-Lfunc_begin2            ##     jumps to Ltmp65
	.long	Lset40
	.byte	0                       ##   On action: cleanup
Lset41 = Ltmp64-Lfunc_begin2            ## >> Call Site 3 <<
	.long	Lset41
Lset42 = Lfunc_end2-Ltmp64              ##   Call between Ltmp64 and Lfunc_end2
	.long	Lset42
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE10push_frontEOS1_
	.weak_definition	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE10push_frontEOS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE10push_frontEOS1_: ## @_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE10push_frontEOS1_
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## BB#0:
	pushq	%rbp
Ltmp72:
	.cfi_def_cfa_offset 16
Ltmp73:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp74:
	.cfi_def_cfa_register %rbp
	subq	$880, %rsp              ## imm = 0x370
	movq	%rdi, -720(%rbp)
	movq	%rsi, -728(%rbp)
	movq	-720(%rbp), %rsi
	movq	8(%rsi), %rdi
	cmpq	(%rsi), %rdi
	movq	%rsi, -840(%rbp)        ## 8-byte Spill
	jne	LBB7_14
## BB#1:
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	%rax, -712(%rbp)
	movq	-712(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -704(%rbp)
	movq	-704(%rbp), %rdx
	movq	%rdx, -696(%rbp)
	movq	-696(%rbp), %rdx
	cmpq	(%rdx), %rcx
	jae	LBB7_5
## BB#2:
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-840(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -528(%rbp)
	movq	-528(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -520(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -512(%rbp)
	movq	-512(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	16(%rdx), %rdi
	subq	%rdi, %rsi
	sarq	$3, %rsi
	movq	%rsi, -736(%rbp)
	movq	-736(%rbp), %rsi
	addq	$1, %rsi
	movq	%rsi, %rax
	cqto
	idivq	%rcx
	movq	%rax, -736(%rbp)
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	16(%rax), %rsi
	movq	16(%rax), %rdi
	movq	-736(%rbp), %r8
	shlq	$3, %r8
	addq	%r8, %rdi
	movq	%rcx, -488(%rbp)
	movq	%rsi, -496(%rbp)
	movq	%rdi, -504(%rbp)
	movq	-488(%rbp), %rcx
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	-496(%rbp), %rsi
	movq	%rsi, -432(%rbp)
	movq	-432(%rbp), %rsi
	movq	-504(%rbp), %rdi
	movq	%rdi, -440(%rbp)
	movq	-440(%rbp), %rdi
	movq	%rcx, -448(%rbp)
	movq	%rsi, -456(%rbp)
	movq	%rdi, -464(%rbp)
	movq	-456(%rbp), %rcx
	movq	-448(%rbp), %rsi
	subq	%rsi, %rcx
	sarq	$3, %rcx
	movq	%rcx, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB7_4
## BB#3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-472(%rbp), %rdx
	movq	-464(%rbp), %rsi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rsi
	movq	%rsi, -464(%rbp)
	movq	-464(%rbp), %rcx
	movq	-448(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	movq	%rcx, %rdi
	movq	%rsi, -848(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-848(%rbp), %rdx        ## 8-byte Reload
	callq	_memmove
	movq	%rax, -856(%rbp)        ## 8-byte Spill
LBB7_4:                                 ## %_ZNSt3__113move_backwardIPPjS2_EET0_T_S4_S3_.exit
	movq	-464(%rbp), %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, 8(%rcx)
	movq	-736(%rbp), %rax
	shlq	$3, %rax
	addq	16(%rcx), %rax
	movq	%rax, 16(%rcx)
	jmp	LBB7_13
LBB7_5:
	leaq	-56(%rbp), %rax
	leaq	-760(%rbp), %rcx
	leaq	-752(%rbp), %rdx
	movq	-840(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	%rdi, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -752(%rbp)
	movq	$1, -760(%rbp)
	movq	%rdx, -80(%rbp)
	movq	%rcx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB7_7
## BB#6:
	movq	-72(%rbp), %rax
	movq	%rax, -864(%rbp)        ## 8-byte Spill
	jmp	LBB7_8
LBB7_7:
	movq	-64(%rbp), %rax
	movq	%rax, -864(%rbp)        ## 8-byte Spill
LBB7_8:                                 ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-864(%rbp), %rax        ## 8-byte Reload
	leaq	-800(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -744(%rbp)
	movq	-744(%rbp), %rsi
	movq	-744(%rbp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	%rdx, -872(%rbp)        ## 8-byte Spill
	movq	%rax, %rdx
	movq	-872(%rbp), %rcx        ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-808(%rbp), %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -120(%rbp)
	movq	%rdx, -128(%rbp)
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-832(%rbp), %rax
	movq	-840(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -152(%rbp)
	movq	%rdx, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-808(%rbp), %rsi
	movq	-832(%rbp), %rdx
Ltmp69:
	leaq	-800(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp70:
	jmp	LBB7_11
LBB7_11:
	leaq	-800(%rbp), %rax
	leaq	-424(%rbp), %rcx
	leaq	-328(%rbp), %rdx
	leaq	-280(%rbp), %rsi
	leaq	-232(%rbp), %rdi
	movq	-840(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -216(%rbp)
	movq	%rax, -224(%rbp)
	movq	-216(%rbp), %r9
	movq	%r9, -208(%rbp)
	movq	-208(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -232(%rbp)
	movq	-224(%rbp), %r9
	movq	%r9, -192(%rbp)
	movq	-192(%rbp), %r9
	movq	(%r9), %r9
	movq	-216(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -200(%rbp)
	movq	-200(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-224(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -264(%rbp)
	movq	%rdi, -272(%rbp)
	movq	-264(%rbp), %rdi
	movq	%rdi, -256(%rbp)
	movq	-256(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -280(%rbp)
	movq	-272(%rbp), %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-264(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -248(%rbp)
	movq	-248(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-272(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-840(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -312(%rbp)
	movq	%rdi, -320(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rsi, -304(%rbp)
	movq	-304(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -328(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -288(%rbp)
	movq	-288(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-312(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -296(%rbp)
	movq	-296(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-320(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-840(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -352(%rbp)
	movq	-352(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	movq	%rsi, -336(%rbp)
	movq	-336(%rbp), %rsi
	movq	%rax, -376(%rbp)
	movq	-376(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -368(%rbp)
	movq	-368(%rbp), %rdi
	movq	%rdi, -360(%rbp)
	movq	-360(%rbp), %rdi
	movq	%rsi, -408(%rbp)
	movq	%rdi, -416(%rbp)
	movq	-408(%rbp), %rsi
	movq	%rsi, -400(%rbp)
	movq	-400(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -424(%rbp)
	movq	-416(%rbp), %rsi
	movq	%rsi, -384(%rbp)
	movq	-384(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-408(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-416(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB7_13
LBB7_12:
Ltmp71:
	leaq	-800(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -816(%rbp)
	movl	%ecx, -820(%rbp)
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB7_15
LBB7_13:
	jmp	LBB7_14
LBB7_14:
	movq	-840(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -552(%rbp)
	movq	-552(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -544(%rbp)
	movq	-544(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	-536(%rbp), %rcx
	movq	8(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, -560(%rbp)
	movq	-560(%rbp), %rdx
	movq	-728(%rbp), %rsi
	movq	%rsi, -568(%rbp)
	movq	-568(%rbp), %rsi
	movq	%rcx, -656(%rbp)
	movq	%rdx, -664(%rbp)
	movq	%rsi, -672(%rbp)
	movq	-656(%rbp), %rcx
	movq	-664(%rbp), %rdx
	movq	-672(%rbp), %rsi
	movq	%rsi, -648(%rbp)
	movq	-648(%rbp), %rsi
	movq	%rcx, -624(%rbp)
	movq	%rdx, -632(%rbp)
	movq	%rsi, -640(%rbp)
	movq	-624(%rbp), %rcx
	movq	-632(%rbp), %rdx
	movq	-640(%rbp), %rsi
	movq	%rsi, -608(%rbp)
	movq	-608(%rbp), %rsi
	movq	%rcx, -584(%rbp)
	movq	%rdx, -592(%rbp)
	movq	%rsi, -600(%rbp)
	movq	-592(%rbp), %rcx
	movq	-600(%rbp), %rdx
	movq	%rdx, -576(%rbp)
	movq	-576(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	8(%rax), %rcx
	addq	$-8, %rcx
	movq	%rcx, 8(%rax)
	addq	$880, %rsp              ## imm = 0x370
	popq	%rbp
	retq
LBB7_15:
	movq	-816(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table7:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset43 = Lfunc_begin3-Lfunc_begin3      ## >> Call Site 1 <<
	.long	Lset43
Lset44 = Ltmp69-Lfunc_begin3            ##   Call between Lfunc_begin3 and Ltmp69
	.long	Lset44
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset45 = Ltmp69-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset45
Lset46 = Ltmp70-Ltmp69                  ##   Call between Ltmp69 and Ltmp70
	.long	Lset46
Lset47 = Ltmp71-Lfunc_begin3            ##     jumps to Ltmp71
	.long	Lset47
	.byte	0                       ##   On action: cleanup
Lset48 = Ltmp70-Lfunc_begin3            ## >> Call Site 3 <<
	.long	Lset48
Lset49 = Lfunc_end3-Ltmp70              ##   Call between Ltmp70 and Lfunc_end3
	.long	Lset49
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp75:
	.cfi_def_cfa_offset 16
Ltmp76:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp77:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rcx
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC2EmmS4_
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE9push_backEOS1_
	.weak_definition	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE9push_backEOS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE9push_backEOS1_: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE9push_backEOS1_
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## BB#0:
	pushq	%rbp
Ltmp81:
	.cfi_def_cfa_offset 16
Ltmp82:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp83:
	.cfi_def_cfa_register %rbp
	subq	$848, %rsp              ## imm = 0x350
	movq	%rdi, -696(%rbp)
	movq	%rsi, -704(%rbp)
	movq	-696(%rbp), %rsi
	movq	16(%rsi), %rdi
	movq	%rsi, -688(%rbp)
	movq	-688(%rbp), %rax
	addq	$24, %rax
	movq	%rax, -680(%rbp)
	movq	-680(%rbp), %rax
	movq	%rax, -672(%rbp)
	movq	-672(%rbp), %rax
	cmpq	(%rax), %rdi
	movq	%rsi, -816(%rbp)        ## 8-byte Spill
	jne	LBB9_14
## BB#1:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	cmpq	(%rax), %rcx
	jbe	LBB9_5
## BB#2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$2, %eax
	movl	%eax, %edx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	8(%rsi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	movq	%rdi, -712(%rbp)
	movq	-712(%rbp), %rdi
	addq	$1, %rdi
	movq	%rdi, %rax
	movq	%rdx, -824(%rbp)        ## 8-byte Spill
	cqto
	movq	-824(%rbp), %rdi        ## 8-byte Reload
	idivq	%rdi
	movq	%rax, -712(%rbp)
	movq	8(%rsi), %rax
	movq	16(%rsi), %r8
	movq	8(%rsi), %r9
	subq	-712(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %r9
	movq	%rax, -488(%rbp)
	movq	%r8, -496(%rbp)
	movq	%r9, -504(%rbp)
	movq	-488(%rbp), %rax
	movq	%rax, -480(%rbp)
	movq	-480(%rbp), %rax
	movq	-496(%rbp), %rcx
	movq	%rcx, -432(%rbp)
	movq	-432(%rbp), %rcx
	movq	-504(%rbp), %r8
	movq	%r8, -440(%rbp)
	movq	-440(%rbp), %r8
	movq	%rax, -448(%rbp)
	movq	%rcx, -456(%rbp)
	movq	%r8, -464(%rbp)
	movq	-456(%rbp), %rax
	movq	-448(%rbp), %rcx
	subq	%rcx, %rax
	sarq	$3, %rax
	movq	%rax, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB9_4
## BB#3:
	movq	-464(%rbp), %rax
	movq	-448(%rbp), %rcx
	movq	-472(%rbp), %rdx
	shlq	$3, %rdx
	movq	%rax, %rdi
	movq	%rcx, %rsi
	callq	_memmove
	movq	%rax, -832(%rbp)        ## 8-byte Spill
LBB9_4:                                 ## %_ZNSt3__14moveIPPjS2_EET0_T_S4_S3_.exit
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-464(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	addq	%rsi, %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rdx, 16(%rsi)
	movq	-712(%rbp), %rdx
	movq	8(%rsi), %rdi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 8(%rsi)
	jmp	LBB9_13
LBB9_5:
	leaq	-120(%rbp), %rax
	leaq	-736(%rbp), %rcx
	leaq	-728(%rbp), %rdx
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -424(%rbp)
	movq	-424(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -416(%rbp)
	movq	-416(%rbp), %rdi
	movq	%rdi, -408(%rbp)
	movq	-408(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -728(%rbp)
	movq	$1, -736(%rbp)
	movq	%rdx, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -128(%rbp)
	movq	%rdx, -136(%rbp)
	movq	-128(%rbp), %rcx
	movq	-136(%rbp), %rdx
	movq	%rax, -96(%rbp)
	movq	%rcx, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	-112(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB9_7
## BB#6:
	movq	-136(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
	jmp	LBB9_8
LBB9_7:
	movq	-128(%rbp), %rax
	movq	%rax, -840(%rbp)        ## 8-byte Spill
LBB9_8:                                 ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-840(%rbp), %rax        ## 8-byte Reload
	leaq	-776(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -720(%rbp)
	movq	-720(%rbp), %rsi
	movq	-720(%rbp), %rax
	shrq	$2, %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	8(%rdx), %rcx
	movq	%rax, %rdx
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-784(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-48(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-808(%rbp), %rax
	movq	-816(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-80(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-784(%rbp), %rsi
	movq	-808(%rbp), %rdx
Ltmp78:
	leaq	-776(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp79:
	jmp	LBB9_11
LBB9_11:
	leaq	-776(%rbp), %rax
	leaq	-400(%rbp), %rcx
	leaq	-304(%rbp), %rdx
	leaq	-256(%rbp), %rsi
	leaq	-208(%rbp), %rdi
	movq	-816(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -192(%rbp)
	movq	%rax, -200(%rbp)
	movq	-192(%rbp), %r9
	movq	%r9, -184(%rbp)
	movq	-184(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -208(%rbp)
	movq	-200(%rbp), %r9
	movq	%r9, -168(%rbp)
	movq	-168(%rbp), %r9
	movq	(%r9), %r9
	movq	-192(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-200(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -240(%rbp)
	movq	%rdi, -248(%rbp)
	movq	-240(%rbp), %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -256(%rbp)
	movq	-248(%rbp), %rdi
	movq	%rdi, -216(%rbp)
	movq	-216(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-240(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -224(%rbp)
	movq	-224(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-248(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-816(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -288(%rbp)
	movq	%rdi, -296(%rbp)
	movq	-288(%rbp), %rsi
	movq	%rsi, -280(%rbp)
	movq	-280(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -304(%rbp)
	movq	-296(%rbp), %rsi
	movq	%rsi, -264(%rbp)
	movq	-264(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-288(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -272(%rbp)
	movq	-272(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-296(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-816(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -328(%rbp)
	movq	-328(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -320(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -312(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rax, -352(%rbp)
	movq	-352(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -344(%rbp)
	movq	-344(%rbp), %rdi
	movq	%rdi, -336(%rbp)
	movq	-336(%rbp), %rdi
	movq	%rsi, -384(%rbp)
	movq	%rdi, -392(%rbp)
	movq	-384(%rbp), %rsi
	movq	%rsi, -376(%rbp)
	movq	-376(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -400(%rbp)
	movq	-392(%rbp), %rsi
	movq	%rsi, -360(%rbp)
	movq	-360(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-384(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -368(%rbp)
	movq	-368(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-392(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB9_13
LBB9_12:
Ltmp80:
	leaq	-776(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -792(%rbp)
	movl	%ecx, -796(%rbp)
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB9_15
LBB9_13:
	jmp	LBB9_14
LBB9_14:
	movq	-816(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -528(%rbp)
	movq	-528(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -520(%rbp)
	movq	-520(%rbp), %rcx
	movq	%rcx, -512(%rbp)
	movq	-512(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	16(%rax), %rdx
	movq	%rdx, -536(%rbp)
	movq	-536(%rbp), %rdx
	movq	-704(%rbp), %rsi
	movq	%rsi, -544(%rbp)
	movq	-544(%rbp), %rsi
	movq	%rcx, -632(%rbp)
	movq	%rdx, -640(%rbp)
	movq	%rsi, -648(%rbp)
	movq	-632(%rbp), %rcx
	movq	-640(%rbp), %rdx
	movq	-648(%rbp), %rsi
	movq	%rsi, -624(%rbp)
	movq	-624(%rbp), %rsi
	movq	%rcx, -600(%rbp)
	movq	%rdx, -608(%rbp)
	movq	%rsi, -616(%rbp)
	movq	-600(%rbp), %rcx
	movq	-608(%rbp), %rdx
	movq	-616(%rbp), %rsi
	movq	%rsi, -584(%rbp)
	movq	-584(%rbp), %rsi
	movq	%rcx, -560(%rbp)
	movq	%rdx, -568(%rbp)
	movq	%rsi, -576(%rbp)
	movq	-568(%rbp), %rcx
	movq	-576(%rbp), %rdx
	movq	%rdx, -552(%rbp)
	movq	-552(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	16(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, 16(%rax)
	addq	$848, %rsp              ## imm = 0x350
	popq	%rbp
	retq
LBB9_15:
	movq	-792(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table9:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset50 = Lfunc_begin4-Lfunc_begin4      ## >> Call Site 1 <<
	.long	Lset50
Lset51 = Ltmp78-Lfunc_begin4            ##   Call between Lfunc_begin4 and Ltmp78
	.long	Lset51
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset52 = Ltmp78-Lfunc_begin4            ## >> Call Site 2 <<
	.long	Lset52
Lset53 = Ltmp79-Ltmp78                  ##   Call between Ltmp78 and Ltmp79
	.long	Lset53
Lset54 = Ltmp80-Lfunc_begin4            ##     jumps to Ltmp80
	.long	Lset54
	.byte	0                       ##   On action: cleanup
Lset55 = Ltmp79-Lfunc_begin4            ## >> Call Site 3 <<
	.long	Lset55
Lset56 = Lfunc_end4-Ltmp79              ##   Call between Ltmp79 and Lfunc_end4
	.long	Lset56
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE10push_frontERKS1_
	.weak_definition	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE10push_frontERKS1_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE10push_frontERKS1_: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE10push_frontERKS1_
Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception5
## BB#0:
	pushq	%rbp
Ltmp87:
	.cfi_def_cfa_offset 16
Ltmp88:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp89:
	.cfi_def_cfa_register %rbp
	subq	$864, %rsp              ## imm = 0x360
	movq	%rdi, -712(%rbp)
	movq	%rsi, -720(%rbp)
	movq	-712(%rbp), %rsi
	movq	8(%rsi), %rdi
	cmpq	(%rsi), %rdi
	movq	%rsi, -832(%rbp)        ## 8-byte Spill
	jne	LBB10_14
## BB#1:
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	16(%rax), %rcx
	movq	%rax, -704(%rbp)
	movq	-704(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -696(%rbp)
	movq	-696(%rbp), %rdx
	movq	%rdx, -688(%rbp)
	movq	-688(%rbp), %rdx
	cmpq	(%rdx), %rcx
	jae	LBB10_5
## BB#2:
	movl	$2, %eax
	movl	%eax, %ecx
	movq	-832(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -528(%rbp)
	movq	-528(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -520(%rbp)
	movq	-520(%rbp), %rsi
	movq	%rsi, -512(%rbp)
	movq	-512(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	16(%rdx), %rdi
	subq	%rdi, %rsi
	sarq	$3, %rsi
	movq	%rsi, -728(%rbp)
	movq	-728(%rbp), %rsi
	addq	$1, %rsi
	movq	%rsi, %rax
	cqto
	idivq	%rcx
	movq	%rax, -728(%rbp)
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	16(%rax), %rsi
	movq	16(%rax), %rdi
	movq	-728(%rbp), %r8
	shlq	$3, %r8
	addq	%r8, %rdi
	movq	%rcx, -488(%rbp)
	movq	%rsi, -496(%rbp)
	movq	%rdi, -504(%rbp)
	movq	-488(%rbp), %rcx
	movq	%rcx, -480(%rbp)
	movq	-480(%rbp), %rcx
	movq	-496(%rbp), %rsi
	movq	%rsi, -432(%rbp)
	movq	-432(%rbp), %rsi
	movq	-504(%rbp), %rdi
	movq	%rdi, -440(%rbp)
	movq	-440(%rbp), %rdi
	movq	%rcx, -448(%rbp)
	movq	%rsi, -456(%rbp)
	movq	%rdi, -464(%rbp)
	movq	-456(%rbp), %rcx
	movq	-448(%rbp), %rsi
	subq	%rsi, %rcx
	sarq	$3, %rcx
	movq	%rcx, -472(%rbp)
	cmpq	$0, -472(%rbp)
	jbe	LBB10_4
## BB#3:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-472(%rbp), %rdx
	movq	-464(%rbp), %rsi
	subq	%rdx, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rsi
	movq	%rsi, -464(%rbp)
	movq	-464(%rbp), %rcx
	movq	-448(%rbp), %rdx
	movq	-472(%rbp), %rsi
	shlq	$3, %rsi
	movq	%rcx, %rdi
	movq	%rsi, -840(%rbp)        ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-840(%rbp), %rdx        ## 8-byte Reload
	callq	_memmove
	movq	%rax, -848(%rbp)        ## 8-byte Spill
LBB10_4:                                ## %_ZNSt3__113move_backwardIPPjS2_EET0_T_S4_S3_.exit
	movq	-464(%rbp), %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, 8(%rcx)
	movq	-728(%rbp), %rax
	shlq	$3, %rax
	addq	16(%rcx), %rax
	movq	%rax, 16(%rcx)
	jmp	LBB10_13
LBB10_5:
	leaq	-56(%rbp), %rax
	leaq	-752(%rbp), %rcx
	leaq	-744(%rbp), %rdx
	movq	-832(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movq	%rdi, -168(%rbp)
	movq	-168(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %r8
	subq	%r8, %rdi
	sarq	$3, %rdi
	shlq	$1, %rdi
	movq	%rdi, -744(%rbp)
	movq	$1, -752(%rbp)
	movq	%rdx, -80(%rbp)
	movq	%rcx, -88(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rax, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rcx
	cmpq	(%rcx), %rax
	jae	LBB10_7
## BB#6:
	movq	-72(%rbp), %rax
	movq	%rax, -856(%rbp)        ## 8-byte Spill
	jmp	LBB10_8
LBB10_7:
	movq	-64(%rbp), %rax
	movq	%rax, -856(%rbp)        ## 8-byte Spill
LBB10_8:                                ## %_ZNSt3__13maxImEERKT_S3_S3_.exit
	movq	-856(%rbp), %rax        ## 8-byte Reload
	leaq	-792(%rbp), %rdi
	movq	(%rax), %rax
	movq	%rax, -736(%rbp)
	movq	-736(%rbp), %rsi
	movq	-736(%rbp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	8(%rdx), %rcx
	movq	%rax, %rdx
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC1EmmS4_
	leaq	-800(%rbp), %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	8(%rcx), %rdx
	movq	%rax, -120(%rbp)
	movq	%rdx, -128(%rbp)
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rdx
	movq	%rax, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#9:
	leaq	-824(%rbp), %rax
	movq	-832(%rbp), %rcx        ## 8-byte Reload
	movq	16(%rcx), %rdx
	movq	%rax, -152(%rbp)
	movq	%rdx, -160(%rbp)
	movq	-152(%rbp), %rax
	movq	-160(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	%rdx, -144(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rdx
	movq	%rdx, (%rax)
## BB#10:
	movq	-800(%rbp), %rsi
	movq	-824(%rbp), %rdx
Ltmp84:
	leaq	-792(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
Ltmp85:
	jmp	LBB10_11
LBB10_11:
	leaq	-792(%rbp), %rax
	leaq	-424(%rbp), %rcx
	leaq	-328(%rbp), %rdx
	leaq	-280(%rbp), %rsi
	leaq	-232(%rbp), %rdi
	movq	-832(%rbp), %r8         ## 8-byte Reload
	movq	%r8, -216(%rbp)
	movq	%rax, -224(%rbp)
	movq	-216(%rbp), %r9
	movq	%r9, -208(%rbp)
	movq	-208(%rbp), %r9
	movq	(%r9), %r9
	movq	%r9, -232(%rbp)
	movq	-224(%rbp), %r9
	movq	%r9, -192(%rbp)
	movq	-192(%rbp), %r9
	movq	(%r9), %r9
	movq	-216(%rbp), %r10
	movq	%r9, (%r10)
	movq	%rdi, -200(%rbp)
	movq	-200(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-224(%rbp), %r9
	movq	%rdi, (%r9)
	addq	$8, %r8
	movq	%rax, %rdi
	addq	$8, %rdi
	movq	%r8, -264(%rbp)
	movq	%rdi, -272(%rbp)
	movq	-264(%rbp), %rdi
	movq	%rdi, -256(%rbp)
	movq	-256(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	%rdi, -280(%rbp)
	movq	-272(%rbp), %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	-264(%rbp), %r8
	movq	%rdi, (%r8)
	movq	%rsi, -248(%rbp)
	movq	-248(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-272(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	-832(%rbp), %rsi        ## 8-byte Reload
	addq	$16, %rsi
	movq	%rax, %rdi
	addq	$16, %rdi
	movq	%rsi, -312(%rbp)
	movq	%rdi, -320(%rbp)
	movq	-312(%rbp), %rsi
	movq	%rsi, -304(%rbp)
	movq	-304(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -328(%rbp)
	movq	-320(%rbp), %rsi
	movq	%rsi, -288(%rbp)
	movq	-288(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-312(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rdx, -296(%rbp)
	movq	-296(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	-320(%rbp), %rsi
	movq	%rdx, (%rsi)
	movq	-832(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -352(%rbp)
	movq	-352(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -344(%rbp)
	movq	-344(%rbp), %rsi
	movq	%rsi, -336(%rbp)
	movq	-336(%rbp), %rsi
	movq	%rax, -376(%rbp)
	movq	-376(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -368(%rbp)
	movq	-368(%rbp), %rdi
	movq	%rdi, -360(%rbp)
	movq	-360(%rbp), %rdi
	movq	%rsi, -408(%rbp)
	movq	%rdi, -416(%rbp)
	movq	-408(%rbp), %rsi
	movq	%rsi, -400(%rbp)
	movq	-400(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -424(%rbp)
	movq	-416(%rbp), %rsi
	movq	%rsi, -384(%rbp)
	movq	-384(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-408(%rbp), %rdi
	movq	%rsi, (%rdi)
	movq	%rcx, -392(%rbp)
	movq	-392(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	-416(%rbp), %rsi
	movq	%rcx, (%rsi)
	movq	%rax, %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB10_13
LBB10_12:
Ltmp86:
	leaq	-792(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -808(%rbp)
	movl	%ecx, -812(%rbp)
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	jmp	LBB10_15
LBB10_13:
	jmp	LBB10_14
LBB10_14:
	movq	-832(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -552(%rbp)
	movq	-552(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -544(%rbp)
	movq	-544(%rbp), %rcx
	movq	%rcx, -536(%rbp)
	movq	-536(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	8(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, -560(%rbp)
	movq	-560(%rbp), %rdx
	movq	-720(%rbp), %rsi
	movq	%rcx, -648(%rbp)
	movq	%rdx, -656(%rbp)
	movq	%rsi, -664(%rbp)
	movq	-648(%rbp), %rcx
	movq	-656(%rbp), %rdx
	movq	-664(%rbp), %rsi
	movq	%rsi, -640(%rbp)
	movq	-640(%rbp), %rsi
	movq	%rcx, -616(%rbp)
	movq	%rdx, -624(%rbp)
	movq	%rsi, -632(%rbp)
	movq	-616(%rbp), %rcx
	movq	-624(%rbp), %rdx
	movq	-632(%rbp), %rsi
	movq	%rsi, -600(%rbp)
	movq	-600(%rbp), %rsi
	movq	%rcx, -576(%rbp)
	movq	%rdx, -584(%rbp)
	movq	%rsi, -592(%rbp)
	movq	-584(%rbp), %rcx
	movq	-592(%rbp), %rdx
	movq	%rdx, -568(%rbp)
	movq	-568(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
	movq	8(%rax), %rcx
	addq	$-8, %rcx
	movq	%rcx, 8(%rax)
	addq	$864, %rsp              ## imm = 0x360
	popq	%rbp
	retq
LBB10_15:
	movq	-808(%rbp), %rdi
	callq	__Unwind_Resume
Lfunc_end5:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table10:
Lexception5:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset57 = Lfunc_begin5-Lfunc_begin5      ## >> Call Site 1 <<
	.long	Lset57
Lset58 = Ltmp84-Lfunc_begin5            ##   Call between Lfunc_begin5 and Ltmp84
	.long	Lset58
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset59 = Ltmp84-Lfunc_begin5            ## >> Call Site 2 <<
	.long	Lset59
Lset60 = Ltmp85-Ltmp84                  ##   Call between Ltmp84 and Ltmp85
	.long	Lset60
Lset61 = Ltmp86-Lfunc_begin5            ##     jumps to Ltmp86
	.long	Lset61
	.byte	0                       ##   On action: cleanup
Lset62 = Ltmp85-Lfunc_begin5            ## >> Call Site 3 <<
	.long	Lset62
Lset63 = Lfunc_end5-Ltmp85              ##   Call between Ltmp85 and Lfunc_end5
	.long	Lset63
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp90:
	.cfi_def_cfa_offset 16
Ltmp91:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp92:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
	.weak_definition	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE18__construct_at_endINS_13move_iteratorIPS1_EEEENS_9enable_ifIXsr21__is_forward_iteratorIT_EE5valueEvE4typeESB_SB_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp93:
	.cfi_def_cfa_offset 16
Ltmp94:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp95:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	%rsi, -208(%rbp)
	movq	%rdx, -216(%rbp)
	movq	%rdi, -224(%rbp)
	movq	-224(%rbp), %rdx
	movq	%rdx, -200(%rbp)
	movq	-200(%rbp), %rsi
	addq	$24, %rsi
	movq	%rsi, -192(%rbp)
	movq	-192(%rbp), %rsi
	movq	%rsi, -184(%rbp)
	movq	-184(%rbp), %rsi
	movq	8(%rsi), %rsi
	movq	%rsi, -232(%rbp)
	movq	%rdx, -240(%rbp)        ## 8-byte Spill
LBB12_1:                                ## =>This Inner Loop Header: Depth=1
	leaq	-216(%rbp), %rax
	leaq	-208(%rbp), %rcx
	movq	%rcx, -24(%rbp)
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	cmpq	(%rcx), %rax
	je	LBB12_4
## BB#2:                                ##   in Loop: Header=BB12_1 Depth=1
	leaq	-208(%rbp), %rax
	movq	-232(%rbp), %rcx
	movq	-240(%rbp), %rdx        ## 8-byte Reload
	movq	16(%rdx), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movq	%rax, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rsi
	movq	%rsi, -128(%rbp)
	movq	-128(%rbp), %rsi
	movq	%rax, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	%rsi, -120(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rcx
	movq	-120(%rbp), %rsi
	movq	%rsi, -88(%rbp)
	movq	-88(%rbp), %rsi
	movq	%rax, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	16(%rdx), %rax
	addq	$8, %rax
	movq	%rax, 16(%rdx)
## BB#3:                                ##   in Loop: Header=BB12_1 Depth=1
	leaq	-208(%rbp), %rax
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, (%rax)
	jmp	LBB12_1
LBB12_4:
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC2EmmS4_
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC2EmmS4_
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC2EmmS4_: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEEC2EmmS4_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp96:
	.cfi_def_cfa_offset 16
Ltmp97:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp98:
	.cfi_def_cfa_register %rbp
	subq	$256, %rsp              ## imm = 0x100
	leaq	-136(%rbp), %rax
	leaq	-168(%rbp), %r8
	movq	%rdi, -208(%rbp)
	movq	%rsi, -216(%rbp)
	movq	%rdx, -224(%rbp)
	movq	%rcx, -232(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$24, %rdx
	movq	-232(%rbp), %rsi
	movq	%rdx, -184(%rbp)
	movq	$0, -192(%rbp)
	movq	%rsi, -200(%rbp)
	movq	-184(%rbp), %rdx
	movq	-192(%rbp), %rsi
	movq	-200(%rbp), %rdi
	movq	%rdx, -160(%rbp)
	movq	%rsi, -168(%rbp)
	movq	%rdi, -176(%rbp)
	movq	-160(%rbp), %rdx
	movq	%r8, -152(%rbp)
	movq	-152(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	-176(%rbp), %rdi
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdx, -128(%rbp)
	movq	%rsi, -136(%rbp)
	movq	%rdi, -144(%rbp)
	movq	-128(%rbp), %rdx
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movq	-144(%rbp), %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, 8(%rdx)
	cmpq	$0, -216(%rbp)
	movq	%rcx, -240(%rbp)        ## 8-byte Spill
	je	LBB13_2
## BB#1:
	movq	-240(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	-216(%rbp), %rdx
	movq	%rcx, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-64(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	%rcx, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movq	$0, -56(%rbp)
	movq	-48(%rbp), %rcx
	shlq	$3, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rdi
	callq	__Znwm
	movq	%rax, -248(%rbp)        ## 8-byte Spill
	jmp	LBB13_3
LBB13_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -248(%rbp)        ## 8-byte Spill
	jmp	LBB13_3
LBB13_3:
	movq	-248(%rbp), %rax        ## 8-byte Reload
	movq	-240(%rbp), %rcx        ## 8-byte Reload
	movq	%rax, (%rcx)
	movq	(%rcx), %rax
	movq	-224(%rbp), %rdx
	shlq	$3, %rdx
	addq	%rdx, %rax
	movq	%rax, 16(%rcx)
	movq	%rax, 8(%rcx)
	movq	(%rcx), %rax
	movq	-216(%rbp), %rdx
	shlq	$3, %rdx
	addq	%rdx, %rax
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rdx
	addq	$24, %rdx
	movq	%rdx, -88(%rbp)
	movq	-88(%rbp), %rdx
	movq	%rdx, -80(%rbp)
	movq	-80(%rbp), %rdx
	movq	%rax, (%rdx)
	addq	$256, %rsp              ## imm = 0x100
	popq	%rbp
	retq
	.cfi_endproc

	.private_extern	___clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## BB#0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev

	.globl	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED2Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED2Ev: ## @_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp99:
	.cfi_def_cfa_offset 16
Ltmp100:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp101:
	.cfi_def_cfa_register %rbp
	subq	$320, %rsp              ## imm = 0x140
	movq	%rdi, -280(%rbp)
	movq	-280(%rbp), %rdi
	movq	%rdi, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	8(%rax), %rcx
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	-248(%rbp), %rax
	movq	-256(%rbp), %rcx
	movq	%rax, -232(%rbp)
	movq	%rcx, -240(%rbp)
	movq	-232(%rbp), %rax
	movq	%rdi, -288(%rbp)        ## 8-byte Spill
	movq	%rax, -296(%rbp)        ## 8-byte Spill
LBB15_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-240(%rbp), %rax
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	cmpq	16(%rcx), %rax
	je	LBB15_3
## BB#2:                                ##   in Loop: Header=BB15_1 Depth=1
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	16(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, 16(%rax)
	movq	%rdx, -192(%rbp)
	movq	-192(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -128(%rbp)
	jmp	LBB15_1
LBB15_3:                                ## %_ZNSt3__114__split_bufferIPjRNS_9allocatorIS1_EEE5clearEv.exit
	movq	-288(%rbp), %rax        ## 8-byte Reload
	cmpq	$0, (%rax)
	je	LBB15_6
## BB#4:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rax), %rdx
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	subq	%rsi, %rdi
	sarq	$3, %rdi
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
	movq	%rdx, -312(%rbp)        ## 8-byte Spill
	movq	%rdi, -320(%rbp)        ## 8-byte Spill
## BB#5:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -80(%rbp)
	movq	-320(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -88(%rbp)
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %r8
	movq	%rsi, -48(%rbp)
	movq	%rdi, -56(%rbp)
	movq	%r8, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZdlPv
LBB15_6:
	addq	$320, %rsp              ## imm = 0x140
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED2Ev
	.p2align	4, 0x90
__ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED2Ev: ## @_ZNSt3__15stackIjNS_5dequeIjNS_9allocatorIjEEEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp102:
	.cfi_def_cfa_offset 16
Ltmp103:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp104:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEED1Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIjNS_9allocatorIjEEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__15dequeIjNS_9allocatorIjEEED1Ev
	.p2align	4, 0x90
__ZNSt3__15dequeIjNS_9allocatorIjEEED1Ev: ## @_ZNSt3__15dequeIjNS_9allocatorIjEEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp105:
	.cfi_def_cfa_offset 16
Ltmp106:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp107:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIjNS_9allocatorIjEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__15dequeIjNS_9allocatorIjEEED2Ev
	.p2align	4, 0x90
__ZNSt3__15dequeIjNS_9allocatorIjEEED2Ev: ## @_ZNSt3__15dequeIjNS_9allocatorIjEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp108:
	.cfi_def_cfa_offset 16
Ltmp109:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp110:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEED2Ev
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIjNS_9allocatorIjEEED2Ev: ## @_ZNSt3__112__deque_baseIjNS_9allocatorIjEEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp111:
	.cfi_def_cfa_offset 16
Ltmp112:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp113:
	.cfi_def_cfa_register %rbp
	subq	$160, %rsp
	movq	%rdi, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	%rdi, -144(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5clearEv
	movq	-144(%rbp), %rdi        ## 8-byte Reload
	movq	%rdi, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -120(%rbp)
LBB19_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-112(%rbp), %rax
	cmpq	-120(%rbp), %rax
	je	LBB19_5
## BB#2:                                ##   in Loop: Header=BB19_1 Depth=1
	movq	-144(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -152(%rbp)        ## 8-byte Spill
## BB#3:                                ##   in Loop: Header=BB19_1 Depth=1
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	movq	-152(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -40(%rbp)
	movq	%rax, -48(%rbp)
	movq	$1024, -56(%rbp)        ## imm = 0x400
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	-56(%rbp), %rsi
	movq	%rax, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZdlPv
## BB#4:                                ##   in Loop: Header=BB19_1 Depth=1
	movq	-112(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -112(%rbp)
	jmp	LBB19_1
LBB19_5:
	movq	-144(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED1Ev
	addq	$160, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5clearEv
	.weak_definition	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5clearEv
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5clearEv: ## @_ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5clearEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp114:
	.cfi_def_cfa_offset 16
Ltmp115:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp116:
	.cfi_def_cfa_register %rbp
	subq	$464, %rsp              ## imm = 0x1D0
	movq	%rdi, -320(%rbp)
	movq	-320(%rbp), %rdi
	movq	%rdi, -312(%rbp)
	movq	-312(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -304(%rbp)
	movq	-304(%rbp), %rax
	movq	%rax, -296(%rbp)
	movq	-296(%rbp), %rax
	movq	%rdi, -368(%rbp)        ## 8-byte Spill
	movq	%rax, -376(%rbp)        ## 8-byte Spill
## BB#1:
	movq	-376(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -328(%rbp)
	movq	-368(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5beginEv
	movq	%rax, -344(%rbp)
	movq	%rdx, -336(%rbp)
	movq	-368(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv
	movq	%rax, -360(%rbp)
	movq	%rdx, -352(%rbp)
LBB20_2:                                ## =>This Inner Loop Header: Depth=1
	leaq	-360(%rbp), %rax
	leaq	-344(%rbp), %rcx
	movq	%rcx, -280(%rbp)
	movq	%rax, -288(%rbp)
	movq	-280(%rbp), %rax
	movq	-288(%rbp), %rcx
	movq	%rax, -264(%rbp)
	movq	%rcx, -272(%rbp)
	movq	-264(%rbp), %rax
	movq	8(%rax), %rax
	movq	-272(%rbp), %rcx
	cmpq	8(%rcx), %rax
	sete	%dl
	xorb	$-1, %dl
	movb	%dl, -377(%rbp)         ## 1-byte Spill
## BB#3:                                ##   in Loop: Header=BB20_2 Depth=1
	movb	-377(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB20_4
	jmp	LBB20_11
LBB20_4:                                ##   in Loop: Header=BB20_2 Depth=1
	leaq	-344(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	%rax, -136(%rbp)
	movq	-136(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rcx, -392(%rbp)        ## 8-byte Spill
	movq	%rax, -400(%rbp)        ## 8-byte Spill
## BB#5:                                ##   in Loop: Header=BB20_2 Depth=1
	movq	-400(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-392(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rsi
	movq	%rcx, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rcx
	movq	-48(%rbp), %rsi
	movq	%rcx, -16(%rbp)
	movq	%rsi, -24(%rbp)
## BB#6:                                ##   in Loop: Header=BB20_2 Depth=1
	jmp	LBB20_7
LBB20_7:                                ##   in Loop: Header=BB20_2 Depth=1
	leaq	-344(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	8(%rax), %rcx
	addq	$4, %rcx
	movq	%rcx, 8(%rax)
	movq	(%rax), %rdx
	movq	(%rdx), %rdx
	subq	%rdx, %rcx
	sarq	$2, %rcx
	cmpq	$1024, %rcx             ## imm = 0x400
	movq	%rax, -408(%rbp)        ## 8-byte Spill
	jne	LBB20_9
## BB#8:                                ##   in Loop: Header=BB20_2 Depth=1
	movq	-408(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	addq	$8, %rcx
	movq	%rcx, (%rax)
	movq	(%rax), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, 8(%rax)
LBB20_9:                                ## %_ZNSt3__116__deque_iteratorIjPjRjPS1_lLl1024EEppEv.exit
                                        ##   in Loop: Header=BB20_2 Depth=1
	jmp	LBB20_10
LBB20_10:                               ##   in Loop: Header=BB20_2 Depth=1
	jmp	LBB20_2
LBB20_11:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -416(%rbp)        ## 8-byte Spill
## BB#12:
	movq	-416(%rbp), %rax        ## 8-byte Reload
	movq	$0, (%rax)
LBB20_13:                               ## =>This Inner Loop Header: Depth=1
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	movq	%rdx, -424(%rbp)        ## 8-byte Spill
## BB#14:                               ##   in Loop: Header=BB20_13 Depth=1
	movq	-424(%rbp), %rax        ## 8-byte Reload
	cmpq	$2, %rax
	jbe	LBB20_18
## BB#15:                               ##   in Loop: Header=BB20_13 Depth=1
	movq	-328(%rbp), %rax
	movq	-368(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	%rax, -432(%rbp)        ## 8-byte Spill
	movq	%rdx, -440(%rbp)        ## 8-byte Spill
## BB#16:                               ##   in Loop: Header=BB20_13 Depth=1
	movq	-440(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	-432(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -176(%rbp)
	movq	%rcx, -184(%rbp)
	movq	$1024, -192(%rbp)       ## imm = 0x400
	movq	-176(%rbp), %rcx
	movq	-184(%rbp), %rsi
	movq	-192(%rbp), %rdi
	movq	%rcx, -152(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%rdi, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rdi
	callq	__ZdlPv
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -248(%rbp)
	movq	-248(%rbp), %rcx
	movq	8(%rcx), %rdx
	addq	$8, %rdx
	movq	%rcx, -216(%rbp)
	movq	%rdx, -224(%rbp)
	movq	-216(%rbp), %rcx
	movq	-224(%rbp), %rdx
	movq	%rcx, -200(%rbp)
	movq	%rdx, -208(%rbp)
	movq	-200(%rbp), %rcx
	movq	-208(%rbp), %rdx
	movq	%rdx, 8(%rcx)
## BB#17:                               ##   in Loop: Header=BB20_13 Depth=1
	jmp	LBB20_13
LBB20_18:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -256(%rbp)
	movq	-256(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	movq	%rdx, -448(%rbp)        ## 8-byte Spill
## BB#19:
	movq	-448(%rbp), %rax        ## 8-byte Reload
	subq	$1, %rax
	movq	%rax, -456(%rbp)        ## 8-byte Spill
	je	LBB20_20
	jmp	LBB20_23
LBB20_23:
	movq	-448(%rbp), %rax        ## 8-byte Reload
	subq	$2, %rax
	movq	%rax, -464(%rbp)        ## 8-byte Spill
	je	LBB20_21
	jmp	LBB20_22
LBB20_20:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	$512, 32(%rax)          ## imm = 0x200
	jmp	LBB20_22
LBB20_21:
	movq	-368(%rbp), %rax        ## 8-byte Reload
	movq	$1024, 32(%rax)         ## imm = 0x400
LBB20_22:
	addq	$464, %rsp              ## imm = 0x1D0
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED1Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED1Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED1Ev: ## @_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED1Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp117:
	.cfi_def_cfa_offset 16
Ltmp118:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp119:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5beginEv
	.weak_definition	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5beginEv
	.p2align	4, 0x90
__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5beginEv: ## @_ZNSt3__112__deque_baseIjNS_9allocatorIjEEE5beginEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp120:
	.cfi_def_cfa_offset 16
Ltmp121:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp122:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -88(%rbp)
	movq	-88(%rbp), %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	32(%rdi), %rcx
	shrq	$10, %rcx
	shlq	$3, %rcx
	addq	%rcx, %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	16(%rcx), %rdx
	cmpq	8(%rcx), %rdx
	sete	%sil
	movq	%rdi, -104(%rbp)        ## 8-byte Spill
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	movb	%sil, -113(%rbp)        ## 1-byte Spill
## BB#1:
	movb	-113(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB22_2
	jmp	LBB22_3
LBB22_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -128(%rbp)        ## 8-byte Spill
	jmp	LBB22_4
LBB22_3:
	movq	-96(%rbp), %rax
	movq	(%rax), %rax
	movq	-104(%rbp), %rcx        ## 8-byte Reload
	movq	32(%rcx), %rdx
	andq	$1023, %rdx             ## imm = 0x3FF
	shlq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, -128(%rbp)        ## 8-byte Spill
LBB22_4:
	movq	-128(%rbp), %rax        ## 8-byte Reload
	leaq	-80(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	-112(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -40(%rbp)
	movq	%rax, -48(%rbp)
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rsi
	movq	%rdx, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-80(%rbp), %rax
	movq	-72(%rbp), %rdx
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED2Ev
	.weak_def_can_be_hidden	__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED2Ev
	.p2align	4, 0x90
__ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED2Ev: ## @_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEED2Ev
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp123:
	.cfi_def_cfa_offset 16
Ltmp124:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp125:
	.cfi_def_cfa_register %rbp
	subq	$320, %rsp              ## imm = 0x140
	movq	%rdi, -280(%rbp)
	movq	-280(%rbp), %rdi
	movq	%rdi, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	8(%rax), %rcx
	movq	%rax, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movq	-248(%rbp), %rax
	movq	-256(%rbp), %rcx
	movq	%rax, -232(%rbp)
	movq	%rcx, -240(%rbp)
	movq	-232(%rbp), %rax
	movq	%rdi, -288(%rbp)        ## 8-byte Spill
	movq	%rax, -296(%rbp)        ## 8-byte Spill
LBB23_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-240(%rbp), %rax
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	cmpq	16(%rcx), %rax
	je	LBB23_3
## BB#2:                                ##   in Loop: Header=BB23_1 Depth=1
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rcx
	movq	16(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, 16(%rax)
	movq	%rdx, -192(%rbp)
	movq	-192(%rbp), %rdx
	movq	%rcx, -160(%rbp)
	movq	%rdx, -168(%rbp)
	movq	-160(%rbp), %rcx
	movq	-168(%rbp), %rdx
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rcx, -120(%rbp)
	movq	%rdx, -128(%rbp)
	jmp	LBB23_1
LBB23_3:                                ## %_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE5clearEv.exit
	movq	-288(%rbp), %rax        ## 8-byte Reload
	cmpq	$0, (%rax)
	je	LBB23_6
## BB#4:
	movq	-288(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	(%rax), %rdx
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rdi
	addq	$24, %rdi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	movq	(%rsi), %rsi
	subq	%rsi, %rdi
	sarq	$3, %rdi
	movq	%rcx, -304(%rbp)        ## 8-byte Spill
	movq	%rdx, -312(%rbp)        ## 8-byte Spill
	movq	%rdi, -320(%rbp)        ## 8-byte Spill
## BB#5:
	movq	-304(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -72(%rbp)
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -80(%rbp)
	movq	-320(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -88(%rbp)
	movq	-72(%rbp), %rsi
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %r8
	movq	%rsi, -48(%rbp)
	movq	%rdi, -56(%rbp)
	movq	%r8, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	__ZdlPv
LBB23_6:
	addq	$320, %rsp              ## imm = 0x140
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
	.weak_definition	__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
	.p2align	4, 0x90
__ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv: ## @_ZNSt3__15dequeIjNS_9allocatorIjEEE8pop_backEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp126:
	.cfi_def_cfa_offset 16
Ltmp127:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp128:
	.cfi_def_cfa_register %rbp
	subq	$512, %rsp              ## imm = 0x200
	movq	%rdi, -448(%rbp)
	movq	-448(%rbp), %rdi
	movq	%rdi, %rax
	movq	%rax, -440(%rbp)
	movq	-440(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -432(%rbp)
	movq	-432(%rbp), %rax
	movq	%rax, -424(%rbp)
	movq	-424(%rbp), %rax
	movq	%rax, -456(%rbp)
	movq	%rdi, %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	(%rax), %rax
	addq	32(%rdi), %rax
	subq	$1, %rax
	movq	%rax, -464(%rbp)
	movq	-456(%rbp), %rax
	movq	%rdi, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	-464(%rbp), %rdx
	shrq	$10, %rdx
	movq	(%rcx,%rdx,8), %rcx
	movq	-464(%rbp), %rdx
	andq	$1023, %rdx             ## imm = 0x3FF
	shlq	$2, %rdx
	addq	%rdx, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rax, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rcx
	movq	%rax, -48(%rbp)
	movq	%rcx, -56(%rbp)
	movq	-48(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%rdi, %rax
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	(%rax), %rcx
	addq	$-1, %rcx
	movq	%rcx, (%rax)
	movq	%rdi, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -160(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, %rdx
	movq	%rdx, -152(%rbp)
	movq	-152(%rbp), %rdx
	movq	16(%rdx), %rsi
	movq	8(%rdx), %rdx
	subq	%rdx, %rsi
	sarq	$3, %rsi
	cmpq	$0, %rsi
	movq	%rdi, -472(%rbp)        ## 8-byte Spill
	movq	%rax, -480(%rbp)        ## 8-byte Spill
	movq	%rcx, -488(%rbp)        ## 8-byte Spill
	jne	LBB24_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -496(%rbp)        ## 8-byte Spill
	jmp	LBB24_3
LBB24_2:
	movq	-488(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rax
	movq	16(%rax), %rcx
	movq	8(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	shlq	$10, %rcx
	subq	$1, %rcx
	movq	%rcx, -496(%rbp)        ## 8-byte Spill
LBB24_3:                                ## %_ZNKSt3__15dequeIjNS_9allocatorIjEEE12__back_spareEv.exit
	movq	-496(%rbp), %rax        ## 8-byte Reload
	movq	-480(%rbp), %rcx        ## 8-byte Reload
	movq	32(%rcx), %rdx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	addq	(%rcx), %rdx
	subq	%rdx, %rax
	cmpq	$2048, %rax             ## imm = 0x800
	jb	LBB24_8
## BB#4:
	movq	-456(%rbp), %rax
	movq	-472(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -176(%rbp)
	movq	-176(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	-8(%rcx), %rcx
	movq	%rax, -240(%rbp)
	movq	%rcx, -248(%rbp)
	movq	$1024, -256(%rbp)       ## imm = 0x400
	movq	-240(%rbp), %rax
	movq	-248(%rbp), %rcx
	movq	-256(%rbp), %rdx
	movq	%rax, -216(%rbp)
	movq	%rcx, -224(%rbp)
	movq	%rdx, -232(%rbp)
	movq	-224(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	-208(%rbp), %rdi
	callq	__ZdlPv
	movq	-472(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -416(%rbp)
	movq	-416(%rbp), %rax
	movq	16(%rax), %rcx
	addq	$-8, %rcx
	movq	%rax, -392(%rbp)
	movq	%rcx, -400(%rbp)
	movq	-392(%rbp), %rax
	movq	-400(%rbp), %rcx
	movq	%rax, -376(%rbp)
	movq	%rcx, -384(%rbp)
	movq	-376(%rbp), %rax
	movq	%rax, -504(%rbp)        ## 8-byte Spill
LBB24_5:                                ## =>This Inner Loop Header: Depth=1
	movq	-384(%rbp), %rax
	movq	-504(%rbp), %rcx        ## 8-byte Reload
	cmpq	16(%rcx), %rax
	je	LBB24_7
## BB#6:                                ##   in Loop: Header=BB24_5 Depth=1
	movq	-504(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -360(%rbp)
	movq	-360(%rbp), %rcx
	addq	$24, %rcx
	movq	%rcx, -352(%rbp)
	movq	-352(%rbp), %rcx
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	movq	16(%rax), %rdx
	addq	$-8, %rdx
	movq	%rdx, 16(%rax)
	movq	%rdx, -336(%rbp)
	movq	-336(%rbp), %rdx
	movq	%rcx, -304(%rbp)
	movq	%rdx, -312(%rbp)
	movq	-304(%rbp), %rcx
	movq	-312(%rbp), %rdx
	movq	%rcx, -288(%rbp)
	movq	%rdx, -296(%rbp)
	movq	-288(%rbp), %rcx
	movq	-296(%rbp), %rdx
	movq	%rcx, -264(%rbp)
	movq	%rdx, -272(%rbp)
	jmp	LBB24_5
LBB24_7:                                ## %_ZNSt3__114__split_bufferIPjNS_9allocatorIS1_EEE8pop_backEv.exit
	jmp	LBB24_8
LBB24_8:
	addq	$512, %rsp              ## imm = 0x200
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__17getlineIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_istreamIT_T0_EES9_RNS_12basic_stringIS6_S7_T1_EES6_
	.weak_definition	__ZNSt3__17getlineIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_istreamIT_T0_EES9_RNS_12basic_stringIS6_S7_T1_EES6_
	.p2align	4, 0x90
__ZNSt3__17getlineIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_istreamIT_T0_EES9_RNS_12basic_stringIS6_S7_T1_EES6_: ## @_ZNSt3__17getlineIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS_13basic_istreamIT_T0_EES9_RNS_12basic_stringIS6_S7_T1_EES6_
Lfunc_begin6:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception6
## BB#0:
	pushq	%rbp
Ltmp144:
	.cfi_def_cfa_offset 16
Ltmp145:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp146:
	.cfi_def_cfa_register %rbp
	subq	$544, %rsp              ## imm = 0x220
	movb	%dl, %al
	movq	%rdi, -424(%rbp)
	movq	%rsi, -432(%rbp)
	movb	%al, -433(%rbp)
	movq	-424(%rbp), %rsi
Ltmp129:
	leaq	-440(%rbp), %rdi
	movl	$1, %edx
	callq	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b
Ltmp130:
	jmp	LBB25_1
LBB25_1:
	leaq	-440(%rbp), %rax
	movq	%rax, -416(%rbp)
	movq	-416(%rbp), %rax
	movb	(%rax), %cl
	movb	%cl, -470(%rbp)         ## 1-byte Spill
## BB#2:
	movb	-470(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB25_3
	jmp	LBB25_34
LBB25_3:
	movq	-432(%rbp), %rax
	movq	%rax, -400(%rbp)
	movq	-400(%rbp), %rax
	movq	%rax, -392(%rbp)
	movq	%rax, -384(%rbp)
	movq	-384(%rbp), %rcx
	movq	%rcx, -376(%rbp)
	movq	-376(%rbp), %rcx
	movq	%rcx, -368(%rbp)
	movq	-368(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -480(%rbp)        ## 8-byte Spill
	je	LBB25_5
## BB#4:
	leaq	-401(%rbp), %rsi
	movq	-480(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -328(%rbp)
	movq	-328(%rbp), %rcx
	movq	%rcx, -320(%rbp)
	movq	-320(%rbp), %rcx
	movq	%rcx, -312(%rbp)
	movq	-312(%rbp), %rcx
	movq	16(%rcx), %rdi
	movb	$0, -401(%rbp)
	callq	__ZNSt3__111char_traitsIcE6assignERcRKc
	movq	-480(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -256(%rbp)
	movq	$0, -264(%rbp)
	movq	-256(%rbp), %rcx
	movq	-264(%rbp), %rsi
	movq	%rcx, -248(%rbp)
	movq	-248(%rbp), %rcx
	movq	%rcx, -240(%rbp)
	movq	-240(%rbp), %rcx
	movq	%rsi, 8(%rcx)
	jmp	LBB25_6
LBB25_5:
	leaq	-402(%rbp), %rsi
	movq	-480(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -304(%rbp)
	movq	-304(%rbp), %rcx
	movq	%rcx, -296(%rbp)
	movq	-296(%rbp), %rcx
	movq	%rcx, -288(%rbp)
	movq	-288(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -280(%rbp)
	movq	-280(%rbp), %rcx
	movq	%rcx, -272(%rbp)
	movq	-272(%rbp), %rdi
	movb	$0, -402(%rbp)
	callq	__ZNSt3__111char_traitsIcE6assignERcRKc
	movq	-480(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -352(%rbp)
	movq	$0, -360(%rbp)
	movq	-352(%rbp), %rcx
	movq	-360(%rbp), %rsi
	shlq	$1, %rsi
	movb	%sil, %dl
	movq	%rcx, -344(%rbp)
	movq	-344(%rbp), %rcx
	movq	%rcx, -336(%rbp)
	movq	-336(%rbp), %rcx
	movb	%dl, (%rcx)
LBB25_6:                                ## %_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5clearEv.exit
	movl	$0, -456(%rbp)
	movq	$0, -464(%rbp)
LBB25_7:                                ## =>This Inner Loop Header: Depth=1
	jmp	LBB25_8
LBB25_8:                                ##   in Loop: Header=BB25_7 Depth=1
	movq	-424(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -232(%rbp)
	movq	-232(%rbp), %rax
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -488(%rbp)        ## 8-byte Spill
## BB#9:                                ##   in Loop: Header=BB25_7 Depth=1
	movq	-488(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rcx
	movq	24(%rcx), %rdx
	cmpq	32(%rcx), %rdx
	movq	%rcx, -496(%rbp)        ## 8-byte Spill
	jne	LBB25_12
## BB#10:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-496(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rcx
	movq	80(%rcx), %rcx
Ltmp131:
	movq	%rax, %rdi
	callq	*%rcx
Ltmp132:
	movl	%eax, -500(%rbp)        ## 4-byte Spill
	jmp	LBB25_11
LBB25_11:                               ## %.noexc
                                        ##   in Loop: Header=BB25_7 Depth=1
	movl	-500(%rbp), %eax        ## 4-byte Reload
	movl	%eax, -204(%rbp)
	jmp	LBB25_13
LBB25_12:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-496(%rbp), %rax        ## 8-byte Reload
	movq	24(%rax), %rcx
	movq	%rcx, %rdx
	addq	$1, %rdx
	movq	%rdx, 24(%rax)
	movsbl	(%rcx), %edi
	callq	__ZNSt3__111char_traitsIcE11to_int_typeEc
	movl	%eax, -204(%rbp)
LBB25_13:                               ## %_ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcEv.exit
                                        ##   in Loop: Header=BB25_7 Depth=1
	movl	-204(%rbp), %eax
	movl	%eax, -504(%rbp)        ## 4-byte Spill
## BB#14:                               ##   in Loop: Header=BB25_7 Depth=1
	movl	-504(%rbp), %eax        ## 4-byte Reload
	movl	%eax, -468(%rbp)
	movl	-468(%rbp), %edi
	movl	%edi, -508(%rbp)        ## 4-byte Spill
	callq	__ZNSt3__111char_traitsIcE3eofEv
	movl	-508(%rbp), %edi        ## 4-byte Reload
	movl	%eax, %esi
	callq	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	testb	$1, %al
	jne	LBB25_15
	jmp	LBB25_20
LBB25_15:
	movl	-456(%rbp), %eax
	orl	$2, %eax
	movl	%eax, -456(%rbp)
	jmp	LBB25_29
LBB25_16:
Ltmp137:
	movl	%edx, %ecx
	movq	%rax, -448(%rbp)
	movl	%ecx, -452(%rbp)
## BB#17:
	movq	-448(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-424(%rbp), %rdi
	movq	(%rdi), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rdi
Ltmp138:
	movq	%rax, -520(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp139:
	jmp	LBB25_18
LBB25_18:
	callq	___cxa_end_catch
LBB25_19:
	movq	-424(%rbp), %rax
	addq	$544, %rsp              ## imm = 0x220
	popq	%rbp
	retq
LBB25_20:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-464(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -464(%rbp)
	movl	-468(%rbp), %edi
	callq	__ZNSt3__111char_traitsIcE12to_char_typeEi
	movb	%al, -469(%rbp)
	movb	-469(%rbp), %al
	movsbl	%al, %edi
	movsbl	-433(%rbp), %esi
	callq	__ZNSt3__111char_traitsIcE2eqEcc
	testb	$1, %al
	jne	LBB25_21
	jmp	LBB25_22
LBB25_21:
	jmp	LBB25_29
LBB25_22:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-432(%rbp), %rdi
	movsbl	-469(%rbp), %esi
Ltmp133:
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc
Ltmp134:
	jmp	LBB25_23
LBB25_23:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-432(%rbp), %rax
	movq	%rax, -200(%rbp)
	movq	-200(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rcx
	movq	%rcx, -184(%rbp)
	movq	-184(%rbp), %rcx
	movq	%rcx, -176(%rbp)
	movq	-176(%rbp), %rcx
	movzbl	(%rcx), %edx
	andl	$1, %edx
	cmpl	$0, %edx
	movq	%rax, -528(%rbp)        ## 8-byte Spill
	je	LBB25_25
## BB#24:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-528(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	%rcx, -536(%rbp)        ## 8-byte Spill
	jmp	LBB25_26
LBB25_25:                               ##   in Loop: Header=BB25_7 Depth=1
	movq	-528(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rcx
	movq	%rcx, -160(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, -152(%rbp)
	movq	-152(%rbp), %rcx
	movzbl	(%rcx), %edx
	sarl	$1, %edx
	movslq	%edx, %rcx
	movq	%rcx, -536(%rbp)        ## 8-byte Spill
LBB25_26:                               ## %_ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4sizeEv.exit
                                        ##   in Loop: Header=BB25_7 Depth=1
	movq	-536(%rbp), %rax        ## 8-byte Reload
	movq	-432(%rbp), %rcx
	movq	%rcx, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	%rcx, -104(%rbp)
	movq	-104(%rbp), %rcx
	movq	%rcx, -96(%rbp)
	movq	-96(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -40(%rbp)
	movq	$-1, -120(%rbp)
	movq	-120(%rbp), %rcx
	subq	$16, %rcx
	cmpq	%rcx, %rax
	jne	LBB25_28
## BB#27:
	movl	-456(%rbp), %eax
	orl	$4, %eax
	movl	%eax, -456(%rbp)
	jmp	LBB25_29
LBB25_28:                               ##   in Loop: Header=BB25_7 Depth=1
	jmp	LBB25_7
LBB25_29:
	cmpq	$0, -464(%rbp)
	jne	LBB25_31
## BB#30:
	movl	-456(%rbp), %eax
	orl	$4, %eax
	movl	%eax, -456(%rbp)
LBB25_31:
	movq	-424(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movl	-456(%rbp), %edx
	movq	%rax, -24(%rbp)
	movl	%edx, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movl	%edx, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	32(%rax), %esi
	orl	%edx, %esi
Ltmp135:
	movq	%rax, %rdi
	callq	__ZNSt3__18ios_base5clearEj
Ltmp136:
	jmp	LBB25_32
LBB25_32:                               ## %_ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj.exit
	jmp	LBB25_33
LBB25_33:
	jmp	LBB25_34
LBB25_34:
	jmp	LBB25_19
LBB25_35:
Ltmp140:
	movl	%edx, %ecx
	movq	%rax, -448(%rbp)
	movl	%ecx, -452(%rbp)
Ltmp141:
	callq	___cxa_end_catch
Ltmp142:
	jmp	LBB25_36
LBB25_36:
	jmp	LBB25_37
LBB25_37:
	movq	-448(%rbp), %rdi
	callq	__Unwind_Resume
LBB25_38:
Ltmp143:
	movl	%edx, %ecx
	movq	%rax, %rdi
	movl	%ecx, -540(%rbp)        ## 4-byte Spill
	callq	___clang_call_terminate
Lfunc_end6:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table25:
Lexception6:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\343\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	91                      ## Call site table length
Lset64 = Ltmp129-Lfunc_begin6           ## >> Call Site 1 <<
	.long	Lset64
Lset65 = Ltmp132-Ltmp129                ##   Call between Ltmp129 and Ltmp132
	.long	Lset65
Lset66 = Ltmp137-Lfunc_begin6           ##     jumps to Ltmp137
	.long	Lset66
	.byte	1                       ##   On action: 1
Lset67 = Ltmp132-Lfunc_begin6           ## >> Call Site 2 <<
	.long	Lset67
Lset68 = Ltmp138-Ltmp132                ##   Call between Ltmp132 and Ltmp138
	.long	Lset68
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset69 = Ltmp138-Lfunc_begin6           ## >> Call Site 3 <<
	.long	Lset69
Lset70 = Ltmp139-Ltmp138                ##   Call between Ltmp138 and Ltmp139
	.long	Lset70
Lset71 = Ltmp140-Lfunc_begin6           ##     jumps to Ltmp140
	.long	Lset71
	.byte	0                       ##   On action: cleanup
Lset72 = Ltmp139-Lfunc_begin6           ## >> Call Site 4 <<
	.long	Lset72
Lset73 = Ltmp133-Ltmp139                ##   Call between Ltmp139 and Ltmp133
	.long	Lset73
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset74 = Ltmp133-Lfunc_begin6           ## >> Call Site 5 <<
	.long	Lset74
Lset75 = Ltmp136-Ltmp133                ##   Call between Ltmp133 and Ltmp136
	.long	Lset75
Lset76 = Ltmp137-Lfunc_begin6           ##     jumps to Ltmp137
	.long	Lset76
	.byte	1                       ##   On action: 1
Lset77 = Ltmp141-Lfunc_begin6           ## >> Call Site 6 <<
	.long	Lset77
Lset78 = Ltmp142-Ltmp141                ##   Call between Ltmp141 and Ltmp142
	.long	Lset78
Lset79 = Ltmp143-Lfunc_begin6           ##     jumps to Ltmp143
	.long	Lset79
	.byte	1                       ##   On action: 1
Lset80 = Ltmp142-Lfunc_begin6           ## >> Call Site 7 <<
	.long	Lset80
Lset81 = Lfunc_end6-Ltmp142             ##   Call between Ltmp142 and Lfunc_end6
	.long	Lset81
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2

	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ## @_ZNSt3__111char_traitsIcE11eq_int_typeEii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp147:
	.cfi_def_cfa_offset 16
Ltmp148:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp149:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	cmpl	-8(%rbp), %esi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE3eofEv:       ## @_ZNSt3__111char_traitsIcE3eofEv
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp150:
	.cfi_def_cfa_offset 16
Ltmp151:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp152:
	.cfi_def_cfa_register %rbp
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE12to_char_typeEi
	.weak_definition	__ZNSt3__111char_traitsIcE12to_char_typeEi
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE12to_char_typeEi: ## @_ZNSt3__111char_traitsIcE12to_char_typeEi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp153:
	.cfi_def_cfa_offset 16
Ltmp154:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp155:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	movb	%dil, %al
	movsbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE2eqEcc
	.weak_definition	__ZNSt3__111char_traitsIcE2eqEcc
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE2eqEcc:       ## @_ZNSt3__111char_traitsIcE2eqEcc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp156:
	.cfi_def_cfa_offset 16
Ltmp157:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp158:
	.cfi_def_cfa_register %rbp
	movb	%sil, %al
	movb	%dil, %cl
	movb	%cl, -1(%rbp)
	movb	%al, -2(%rbp)
	movsbl	-1(%rbp), %esi
	movsbl	-2(%rbp), %edi
	cmpl	%edi, %esi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE6assignERcRKc
	.weak_definition	__ZNSt3__111char_traitsIcE6assignERcRKc
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE6assignERcRKc: ## @_ZNSt3__111char_traitsIcE6assignERcRKc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp159:
	.cfi_def_cfa_offset 16
Ltmp160:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp161:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movb	(%rsi), %al
	movq	-8(%rbp), %rsi
	movb	%al, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__111char_traitsIcE11to_int_typeEc
	.weak_definition	__ZNSt3__111char_traitsIcE11to_int_typeEc
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11to_int_typeEc: ## @_ZNSt3__111char_traitsIcE11to_int_typeEc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp162:
	.cfi_def_cfa_offset 16
Ltmp163:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp164:
	.cfi_def_cfa_register %rbp
	movb	%dil, %al
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj
	.weak_definition	__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj
	.p2align	4, 0x90
__ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj: ## @_ZNSt3__15dequeIjNS_9allocatorIjEEE9push_backEOj
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp165:
	.cfi_def_cfa_offset 16
Ltmp166:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp167:
	.cfi_def_cfa_register %rbp
	subq	$336, %rsp              ## imm = 0x150
	movq	%rdi, -256(%rbp)
	movq	%rsi, -264(%rbp)
	movq	-256(%rbp), %rsi
	movq	%rsi, %rdi
	movq	%rdi, -248(%rbp)
	movq	-248(%rbp), %rdi
	addq	$40, %rdi
	movq	%rdi, -240(%rbp)
	movq	-240(%rbp), %rdi
	movq	%rdi, -232(%rbp)
	movq	-232(%rbp), %rdi
	movq	%rdi, -272(%rbp)
	movq	%rsi, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	%rdi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	movq	%rcx, -40(%rbp)
	movq	-40(%rbp), %rcx
	movq	16(%rcx), %rdx
	movq	8(%rcx), %rcx
	subq	%rcx, %rdx
	sarq	$3, %rdx
	cmpq	$0, %rdx
	movq	%rsi, -296(%rbp)        ## 8-byte Spill
	movq	%rdi, -304(%rbp)        ## 8-byte Spill
	movq	%rax, -312(%rbp)        ## 8-byte Spill
	jne	LBB32_2
## BB#1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	%rcx, -320(%rbp)        ## 8-byte Spill
	jmp	LBB32_3
LBB32_2:
	movq	-312(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rcx
	movq	8(%rax), %rax
	subq	%rax, %rcx
	sarq	$3, %rcx
	shlq	$10, %rcx
	subq	$1, %rcx
	movq	%rcx, -320(%rbp)        ## 8-byte Spill
LBB32_3:                                ## %_ZNKSt3__15dequeIjNS_9allocatorIjEEE12__back_spareEv.exit
	movq	-320(%rbp), %rax        ## 8-byte Reload
	movq	-304(%rbp), %rcx        ## 8-byte Reload
	movq	32(%rcx), %rdx
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	addq	$40, %rcx
	movq	%rcx, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rcx
	addq	(%rcx), %rdx
	subq	%rdx, %rax
	cmpq	$0, %rax
	jne	LBB32_5
## BB#4:
	movq	-296(%rbp), %rdi        ## 8-byte Reload
	callq	__ZNSt3__15dequeIjNS_9allocatorIjEEE19__add_back_capacityEv
LBB32_5:
	movq	-272(%rbp), %rax
	movq	-296(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, %rdi
	movq	%rax, -328(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__112__deque_baseIjNS_9allocatorIjEEE3endEv
	leaq	-288(%rbp), %rcx
	movq	%rax, -288(%rbp)
	movq	%rdx, -280(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	-264(%rbp), %rcx
	movq	%rcx, -80(%rbp)
	movq	-80(%rbp), %rcx
	movq	-328(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -168(%rbp)
	movq	%rax, -176(%rbp)
	movq	%rcx, -184(%rbp)
	movq	-168(%rbp), %rax
	movq	-176(%rbp), %rcx
	movq	-184(%rbp), %rdx
	movq	%rdx, -160(%rbp)
	movq	-160(%rbp), %rdx
	movq	%rax, -136(%rbp)
	movq	%rcx, -144(%rbp)
	movq	%rdx, -152(%rbp)
	movq	-136(%rbp), %rax
	movq	-144(%rbp), %rcx
	movq	-152(%rbp), %rdx
	movq	%rdx, -120(%rbp)
	movq	-120(%rbp), %rdx
	movq	%rax, -96(%rbp)
	movq	%rcx, -104(%rbp)
	movq	%rdx, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	-112(%rbp), %rcx
	movq	%rcx, -88(%rbp)
	movq	-88(%rbp), %rcx
	movl	(%rcx), %esi
	movl	%esi, (%rax)
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -224(%rbp)
	movq	-224(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -216(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -208(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rcx
	addq	$1, %rcx
	movq	%rcx, (%rax)
	addq	$336, %rsp              ## imm = 0x150
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%u\n"

L_.str.1:                               ## @.str.1
	.asciz	"0\n"


.subsections_via_symbols
