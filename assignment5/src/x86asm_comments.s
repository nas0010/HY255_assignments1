# -----------------------------------
# Program x86asm.s
# Compute and print the sum 0+...+N
# -----------------------------------

	.section .data	# section that declares data and saves them in memory
N:	.long 1000	    # the sum of N=1000 numbers
S:	.long 0		    # value of variable S=0
Msg:	.ascii "The sum from 0 to %d is %d\n\0"


	.section .text	# section that contains commands
.globl main
main:	
	pushl %ebp	    # push ebp in stack
	movl %esp, %ebp	# set ebp equal to the contents of esp

 	# initialize
    movl N, %ebx	# initialise ebx with the value of N(1000)

 	# compute sum
L1:
	addl %ebx, S	# add to S the content of ebx and store result in S
	decl %ebx       # decline by 1 value of ebx and store result in ebx
	cmpl $0, %ebx   # compare contet of ebx with 0 and store result in %eflags
	jng  L2	    	# jump to L2
    movl $L1, %eax	# copy content of L1 in eax
    jmp *%eax   	# jump to where eax is pointing (L1 from previous instruction)

L2:
	# print result
	pushl S	    	# push S in stack 
	pushl N	        # push N in stack
	pushl $Msg  	# push the address of Msg in stack
	call printf 	# prints "The sum from 0 to N is S"N and S are what is stored in them
	popl %eax   	# pop Msg from stack as eax points to top of stack
	popl %eax   	# pop N from stack
	popl %eax   	# pop S from stack

	# exit
	movl $0, %eax  	# set eax equal to 0
    leave	    	# high level procedure exit
 	ret             # return
