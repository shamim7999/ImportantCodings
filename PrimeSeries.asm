.data
msg1: .asciiz "Enter your Range: "
sp: .asciiz " "
prime: .asciiz "Prime Series is: 2 "
.text

main:
	li $v0, 4
	la $a0, msg1
	syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0
	
	addi $t1, $zero, 2
	addi $t3, $zero, 0
	addi $t2, $zero, 0
	addi $t4, $zero, 0
	
	li $v0, 4
	la $a0, prime
	syscall
	
	jal for1
	
	li $v0, 10
	syscall
	
	
	for1:
		addi $t1, $t1, 1
		bgt $t1, $t0, exit
		addi $t2, $zero, 2
	for2:
		beq $t1, $t2, print
		rem $t3, $t1, $t2
		beq $t3, 0, exitFor2
		addi $t2, $t2, 1
		j for2
		
	print:
		li $v0, 1
		move $a0, $t1
		syscall
		
		li $v0, 4
		la $a0, sp
		syscall
		
		#addi $t1, $t1, 1
		
		j for1
	exit:
		jr $ra
	
	exitFor2:
		#addi $t1, $t1, 1
		j for1
