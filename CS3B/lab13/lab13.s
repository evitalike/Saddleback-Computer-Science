/*	lab13.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data
	iVal:	.word 0
	
	szMsg:	.asciz "\nInput an integer: "
	LTMsg:	.asciz " is less than 0\n"
	GTMsg:	.asciz " is greater than 0\n"
	EQMsg:	.asciz " is equal to 0\n"
	LF:		.byte 10
	szVal:	.skip 	12
	
.text
	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer

_start:
	ldr 	r1, =szMsg		@r1 = &szMsg
	bl 		putstring		@display input msg
	
	ldr		r1, =szVal		@r1 = &szVal
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl 		getstring		@read in the string
	bl		ascint32		@turn ascii into integer
	ldr		r1, =iVal		@r1 = &szVal
	str 	r0, [r1]		@store iVal into memory
	
	ldr 	r1, =LF
	bl 		putch
	
	ldr		r0, =iVal		@load address of iVal from memory
	ldr		r0, [r0]		@dereference address to get iVal
	
	cmp		r0, #0			@comparison to set flags
	blt		lessThan		@message if less than 0
	bgt		greaterThan		@message if greater than 0
	b		equal			@message if equal to 0
	
lessThan:
	@display less than message
	ldr		r1, =szVal
	bl		putstring
	ldr		r1, =LTMsg
	bl		putstring
	
	b		end				@branch to end

greaterThan:
	@display greater than message
	ldr		r1, =szVal
	bl		putstring
	ldr		r1, =GTMsg
	bl		putstring

	b		end				@branch to end

equal:
	@display equal to message
	ldr		r1, =szVal
	bl		putstring
	ldr		r1, =EQMsg
	bl		putstring		@branch to end
	
	b 		end

@ Call service command to terminate program successfully
end:
	mov r0, #0
	mov r7, #1
	svc 0
	
.end	
