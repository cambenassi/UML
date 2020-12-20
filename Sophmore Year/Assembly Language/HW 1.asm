	.data
	
#defining the two variables
x:	.word 0
y:	.word 0
m1:	.asciiz "The sum of "
m2:	.asciiz " and "
m3:	.asciiz " is "
	
	.text

main:

	li $v0, 5 	#storing 5 into register $v0, telling the computer to scan an input and to store it in x
	syscall	
	sw $v0, x
	
	li $v0, 5	#same as above, but storing into y
	syscall
	sw $v0, y 
	
	lw $t8, x	#moving the values of x and y into registers $t8 and $t9
	lw $t9, y
	
	jal sum		#jumps to sum function, moves the result to $t0
	move $t0, $a0
	
	li $v0, 4	#printing the end result by setting $v0 to 4 for string, 1 for int, and using syscall to execute
	la $a0, m1	#la used to load address of strings
	syscall
	li $v0, 1
	lw $a0, x	#lw used to load ints
	syscall
	li $v0, 4
	la $a0, m2
	syscall
	li $v0, 1
	lw $a0, y
	syscall
	li $v0, 4
	la $a0, m3
	syscall	
	li $v0, 1
	move $a0, $t0  
	syscall 
	
	li $v0, 10	#program tells computer it has reached end of program
	syscall	
		
sum:			#Definition of Sum, arguments - $t8 == x, $t9 == y, value is stored in $a0
	sll $a0, $t8, 3
	jr $ra
	
	
