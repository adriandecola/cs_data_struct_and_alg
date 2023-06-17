# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
				# (1) What are we setting up here?
				# Ans:
	pushq %rbp		#  Here we are putting the address of main into 
	movq  %rsp, %rbp	#  the register rbp. We then move that 
				#  value/addrress from register rbp to rsp. 

				# (2) What is going on here
				# Ans:
	movq $1, %rax		#  Here we put the value 1 into the rax and 
	movq $1, %rdi		#  rdi registers. After that we copy the
	leaq .hello.str,%rsi	#  address of the hello string on to the 
				#  rsi register.


				# (3) What is syscall? We did not talk about this
				# in class.
				# Ans:
				#  syscall hands over control to the operating 
				#  system. We have already loaded in values 
				#  into the registers rax, rdi, and rsi  so the 
				#  operating knows what to do.

	syscall			# Which syscall is being run?
				# Ans: 
				#  The 'write' syscall is being run as we 
				# loaded in the value 1 into the rax and rdi 
				# registers.

				# (4) What would another option be instead of 
				# using a syscall to achieve this?
				# Ans: 
				#  Instead of running syscall, we could have
				#  included the standard input output library
				#  in out code and then instead called the
 				#  printf fuction, though this would also
				#  require a write syscall.

	movq	$60, %rax	# (5) We are again setting up another syscall
	movq	$0, %rdi	# What command is it?
				# Ans:	
	syscall			#  Here we are setting up the program to 
				#  use the exit syscall. We return the value
				#  of 0 from our main function.

	popq %rbp		# (Note we do not really need
			 	# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	
					#  There is a 13 here because the 
					#  "Hello World!\n" string contains
					#  13 characters/bytes. That is, 
					#  the 12 characters shown and the 
					#  null character at the end. 
