	.file	"GuessingGame.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"=================================================== "
	.align 8
.LC1:
	.string	"| Here are the results of your guessing abilities | "
	.align 8
.LC2:
	.string	"Game %d took you %d guesses. \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %edi
	call	time
	movl	%eax, %edi
	call	srand
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	call	guessingGame
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	%eax, -32(%rbp,%rdx,4)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %edi
	call	puts
	movl	$.LC0, %edi
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L4:
	cmpl	$4, -4(%rbp)
	jle	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.string	"======================================== "
	.align 8
.LC4:
	.string	"|         Pick a number 1-10           | "
.LC5:
	.string	"Make a guess: "
.LC6:
	.string	"%d"
.LC7:
	.string	"You got it! "
.LC8:
	.string	"No guess lower! "
.LC9:
	.string	"No guess higher! "
	.text
	.globl	guessingGame
	.type	guessingGame, @function
guessingGame:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC3, %edi
	call	puts
	movl	$.LC4, %edi
	call	puts
	movl	$.LC3, %edi
	call	puts
	movl	$0, -4(%rbp)
	call	rand
	movl	%eax, %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	leal	1(%rdx), %eax
	movl	%eax, -12(%rbp)
	movb	$0, -5(%rbp)
	jmp	.L8
.L11:
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -4(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jne	.L9
	movb	$1, -5(%rbp)
	movl	$.LC7, %edi
	call	puts
	jmp	.L8
.L9:
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jle	.L10
	movl	$.LC8, %edi
	call	puts
	jmp	.L8
.L10:
	movl	$.LC9, %edi
	call	puts
.L8:
	movzbl	-5(%rbp), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	.L11
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	guessingGame, .-guessingGame
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
