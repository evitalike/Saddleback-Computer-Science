/*	lab14.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data
	iVal:	.word 0
	
	inputMsg:	.asciz "Enter number grade (0 - 100): "
	outputMsg:	.asciz "Letter Grade is: "
	LF:			.byte 10
	szVal:		.skip 12
	szA:		.asciz "A\n\n"
	szB:		.asciz "B\n\n"
	szC:		.asciz "C\n\n"
	szD:		.asciz "D\n\n"
	szF:		.asciz "F\n\n"
	szError:	.asciz "***ERROR*** invalid value\n\n"
	szEnd:		.asciz "Lab 14 Complete!\n"
	
.text
	.global _start			@provide program start
	.equ	BUFSIZE,20		@size of input buffer

_start:

loop:
	ldr 	r1, =inputMsg	@r1 = &inputMsg
	bl 		putstring		@display input msg
	
	ldr		r1, =szVal		@r1 = &szVal
	ldr		r2, =BUFSIZE	@r2 = number of buffer entries
	bl 		getstring		@read in the string
	bl		ascint32		@turn ascii into integer
	ldr		r1, =iVal		@r1 = &szVal
	str 	r0, [r1]		@store iVal into memory
	
	ldr		r0, =iVal		@load address of iVal from memory
	ldr		r0, [r0]		@dereference address to get iVal
	
	cmp		r0, #100
	bgt		error			@message if number is GT 100 or ascii
	cmp		r0, #89
	bgt		gradeA			@message if grade is A
	cmp		r0, #79
	bgt		gradeB			@message if grade is B
	cmp		r0, #69
	bgt		gradeC			@message if grade is C
	cmp		r0, #59
	bgt		gradeD			@message if grade is D
	cmp		r0, #0
	bgt		gradeF			@message if grade is F
	blt		endLoop			@message if negative number inputted
	
error:
	@display error message
	ldr		r1, =outputMsg
	bl		putstring
	ldr		r1, =szError
	bl		putstring
	
	b		loop			@branch to loop

gradeA:
	@display grade A message
	ldr		r1, =outputMsg
	bl		putstring
	ldr		r1, =szA
	bl		putstring
	
	b		loop			@branch to loop

gradeB:
	@display grade B message
	ldr		r1, =outputMsg
	bl		putstring
	ldr		r1, =szB
	bl		putstring
	
	b		loop			@branch to loop
	
gradeC:
	@display grade C message
	ldr		r1, =outputMsg
	bl		putstring
	ldr		r1, =szC
	bl		putstring
	
	b		loop			@branch to loop

gradeD:
	@display grade A message
	ldr		r1, =outputMsg
	bl		putstring
	ldr		r1, =szD
	bl		putstring
	
	b		loop			@branch to loop

gradeF:
	@display grade A message
	ldr		r1, =outputMsg
	bl		putstring
	ldr		r1, =szF
	bl		putstring
	
	b		loop			@branch to loop

endLoop:
	@display end program message
	ldr		r1, =szEnd
	bl		putstring
	
	@ Call service command to terminate program successfully
	mov r0, #0
	mov r7, #1
	svc 0
	
.end	
