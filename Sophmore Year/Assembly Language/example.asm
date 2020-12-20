
	.data

array:	.word	100, 0x37, 0	# array[0] = 100, array[1] = 0x37, array[2] = 0, each array element is 4 bytes
st:	.asciiz	"abc"
x:	.word	2

	.text
	
	#  	y = x[i] 
	#  	lw	x + 4*i
	
	
	la	$t0, x
	lw	$t9, 4($t0)	# x[1]
	lw	$t9, 8($t0)	# x[2]
	
	li	$t0, 1
	#muli	$t0, $t0, 4
	lw	$t9, x($t0)
	
	addi	$t0, $t0, 4
	lw	$t9, x($t0)
	
	
	lb	$t9, st+2
	lb	$t8, st+1
	sb	$t8, st		# store byte
	sw	$t8, st		# store word
	
	la	$a0, array	# $a0 = &array		load address
	lw	$s3, array	# $s3 = array[0]	load word
	lb 	$s0, array
	
	la	$a1, array+4	# $a1 = 0x10010004
	lw	$s1, array+4	# $s1 = array[1]
