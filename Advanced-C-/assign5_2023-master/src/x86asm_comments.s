# -----------------------------------
# Program x86asm.s
# Compute and print the sum 0+...+N
# -----------------------------------

	.section .data	# storage of the variables
	.equ N, 1000	# N = 1000
S:	.long 0		# s=0
Msg:	.ascii "The sum from 11 to %d is %d\n\0"


	.section .text	# instructions (program text)
.globl main
main:
	pushl %ebp	# store ebp on the stack
	movl %esp, %ebp	# esp = ebp

 	# initialize
        movl $N, %ebx	# ebx = N=1000

 	# compute sum
L1:
	addl %ebx, S	#S=S + ebx
	decl %ebx       # ebx = ebx - 1
	cmpl $10, %ebx  # if( ebx ==10)
	jle  L2		# jump L2
        movl $L1, %eax	# move L1 to eax
        jmp *%eax	# jump L1

L2:
	# print result
	pushl S		# copy the value of S to the stack
	pushl $N	# copy the value of N to the stack
	pushl $Msg	# push the address of Msg
	call printf	# print Msg, N, S
	popl %eax	# remove the Msg of the stack
	popl %eax	# remove the N of the stack
	popl %eax	# remove the S of the stack

	# exit
	movl $0, %eax  	# eax = 0
        leave		# exit procedure
 	ret		#go back to address shown by stack pointer
