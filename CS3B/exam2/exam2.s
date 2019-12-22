/*	exam2.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data				
	strTemp:		.skip 256	@temp memory for string inputs
	iLen1:			.word 0		@length of string 1
	iLen2:			.word 0		@length of string 2
	
	cLF:			.byte 10	@newline character
					.align 4
					
	szMsg1:			.asciz "Enter String #1: "
	szMsg2:			.asciz "Enter String #2: "
	szMsg3:			.asciz "Displaying string #1: "
	szMsg4:			.asciz "Displaying string #2: "
	szSwap:			.asciz "\tSWAPPING ....\n"
	szUpper:		.asciz "\tConverting to Upper Case ....\n"
	
	str1Ptr:		.word 0		@pointer to string 1
	str2Ptr:		.word 0		@pointer to string 2
	
.text
	.global _start			@provide program start address to the linker
	.equ	BUFSIZE, 256	@size of input buffer
	.extern malloc			@include the external malloc macro
	.extern free			@include the external free macro

_start:

@ user input for string 1
	ldr 	r1, =szMsg1		@r1 = &szMsg1
	bl		putstring		@display message to prompt user input
	
	ldr		r1, =strTemp	@r1 = &strTemp
	ldr 	r2, =BUFSIZE	@r2 = &BUFSIZE
	bl		getstring		@get string one and put it into memory
	
	ldr		r1, =cLF
	bl		putch			@newline
	
@ allocate memory equal to the length of string 1
	ldr		r1, =strTemp
	bl		String_Length	@get length of string 1
	ldr		r1, =iLen1
	str		r0, [r1]		@store length into memory
	bl		malloc			@allocate bytes equal to length
	ldr		r1, =str1Ptr
	str		r0, [r1]		@store address of malloc into str1Ptr
	
@ loop through strTemp, copying each character byte into str1Ptr
	ldr		r2, =strTemp	@r2 = &strTemp
	ldr		r4, =str1Ptr	@r4 = &str1Ptr
	ldr		r4, [r4]		@dereference r4 to get address of malloc
	ldr		r5, =iLen1		@r5 = &iLen1
	ldr		r5, [r5]		@r5 = length of string 1
	add		r5, #1			@add 1 to length to get null char
loop1:
	cmp		r5, #0			@base case: r5 = 0
	beq		endloop1		@end loop if r5 = 0
	ldrb	r6, [r2], #1	@put 1 character of string 1 into r6, strTemp++
	strb	r6, [r4], #1	@store the character into str1Ptr, str1Ptr++
	sub		r5, #1			@r5 = r5 - 1
	b 		loop1			@loop until all string 1 characters are put into str1Ptr
endloop1:
@ user input for string 2
	ldr 	r1, =szMsg2		@r1 = &szMsg2
	bl		putstring		@display message to prompt user input
	
	ldr		r1, =strTemp	@r1 = &strTemp
	ldr 	r2, =BUFSIZE	@r2 = &BUFSIZE
	bl		getstring		@get string one and put it into memory
	
	ldr		r1, =cLF
	bl		putch			@newline
	
@ allocate memory equal to the length of string 2
	ldr		r1, =strTemp
	bl		String_Length	@get length of string 2
	ldr		r1, =iLen2
	str		r0, [r1]		@store length into memory
	bl		malloc			@allocate bytes equal to length
	ldr		r1, =str2Ptr
	str		r0, [r1]		@store address of malloc into str2Ptr
	
@ loop through strTemp, copying each character byte into str2Ptr
	ldr		r2, =strTemp	@r2 = &strTemp
	ldr		r4, =str2Ptr	@r4 = &str2Ptr
	ldr		r4, [r4]		@dereference r4 to get address of malloc
	ldr		r5, =iLen2		@r5 = &iLen2
	ldr		r5, [r5]		@r5 = length of string 1
	add		r5, #1			@add 1 to string to get the null character
loop2:
	cmp		r5, #0			@base case: r5 = 0
	beq		endloop2		@end loop if r5 = 0
	ldrb	r6, [r2], #1	@put 1 character of string 1 into r6, strTemp++
	strb	r6, [r4], #1	@store the character into str2Ptr, str2Ptr++
	sub		r5, #1			@r5 = r5 - 1
	b 		loop2			@loop until all string 1 characters are put into str2Ptr
endloop2:
	
@ Displaying string 1
	ldr		r1, =szMsg3		
	bl 		putstring		@display string 1 message
	
	ldr		r1, =str1Ptr
	ldr		r1, [r1]
	bl		putstring		@display string 1
	
	ldr		r1, =cLF
	bl		putch			@newline
	
	ldr		r1, =cLF
	bl		putch			@newline

@ Displaying string 2
	ldr		r1, =szMsg4		
	bl 		putstring		@display string 2 message
	
	ldr		r1, =str2Ptr
	ldr		r1, [r1]
	bl		putstring		@display string 2
	
	ldr		r1, =cLF
	bl		putch			@newline

@ Swapping and converting to upper case
	ldr		r1, =szSwap
	bl		putstring		@Dsiplay szSwap message

	ldr 	r1, =str1Ptr
	ldr		r2, =str2Ptr
	bl		String_Swap		@swap str1Ptr with str2Ptr

	ldr		r1, =szUpper
	bl		putstring		@display szUpper message
	
	ldr 	r1, =str1Ptr
	ldr		r1, [r1]
	bl		String_To_Upper	@make string 1 upper case
	
	ldr 	r1, =str2Ptr
	ldr		r1, [r1]
	bl		String_To_Upper	@make string 2 upper case

@ Displaying new string 1
	ldr		r1, =szMsg3
	bl 		putstring		@display string 1 message
	
	ldr		r1, =str1Ptr
	ldr		r1, [r1]
	bl		putstring		@display string 1
	
	ldr		r1, =cLF
	bl		putch			@newline
	
	ldr		r1, =cLF
	bl		putch			@newline

@ Displaying new string 2
	ldr		r1, =szMsg4		
	bl 		putstring		@display string 2 message
	
	ldr		r1, =str2Ptr	
	ldr		r1, [r1]
	bl		putstring		@display string 2
	
	ldr		r1, =cLF
	bl		putch			@newline
	
@ Call service command to terminate program successfully
	ldr		r0, =str1Ptr	@r0 = &str1Ptr
	ldr		r0, [r0]		@r0 = address of malloc memory
	bl 		free			@ free dynamic memory
	
	ldr		r0, =str2Ptr	@r0 = &str2Ptr
	ldr		r0, [r0]		@r0 = address of malloc memory
	bl 		free			@ free dynamic memory

	mov 	r0, #0
	mov 	r7, #1
	svc 	0

@End of Program
	.end
