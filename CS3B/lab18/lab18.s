/*	lab18.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data				
	szValA:			.skip 12
	szValB:			.skip 12
	
	iLenA:			.word 0
	iLenB:			.word 0
	cLF:			.byte 10
					.align 4
					
	szMsg1:			.asciz "Enter String 1: "
	szMsg2:			.asciz "Enter String 2: "
	szMsg3:			.asciz "Here's the concatenated string: "
	ptrString:		.word 0
					.align 4
	
.text
	.global _start			@provide program start address to the linker
	.equ	BUFSIZE, 15		@size of input buffer
	.extern malloc			@include the external malloc macro
	.extern free			@include the external free macro

_start:

@ user input for string 1
	ldr 	r1, =szMsg1		@r1 = &szMsg1
	bl		putstring		@display message to prompt user input
	
	ldr		r1, =szValA		@r1 = &szValA
	ldr 	r2, =BUFSIZE	@r2 = &BUFSIZE
	bl		getstring		@get string one and put it into memory
	
@ user input for string 2
	ldr 	r1, =szMsg2		@r1 = &szMsg2
	bl		putstring		@display message to prompt user input
	
	ldr		r1, =szValB		@r1 = &szValB
	ldr 	r2, =BUFSIZE	@r2 = &BUFSIZE
	bl		getstring		@get string 2 and put it into memory
	
@ get length of string 1 and 2 and add them together
	bl		String_Length	@r0 = length of string 2
	ldr		r1, =iLenB		@r1 = &iLenB
	str		r0, [r1]		@store length of string 2 into memory
	mov		r3, r0			@r3 = length of string 2
	
	ldr		r1, =szValA		@r1 = &szValA
	bl		String_Length	@r0 = length of string 1
	ldr		r1, =iLenA		@r1 = &iLenA
	str		r0, [r1]		@store length of string 1 into memory
	add		r3, r0, r3		@r3 = length string 1 + length string 2
	
@ allocate memory equal to the length of both strings
	mov		r0, r3			@move length of both strings into r0
	push	{r3}
	bl 		malloc			@allocate memory equal to length of both strings
	pop		{r3}
	
	ldr		r1, =ptrString	@r1 = &ptrString
	str		r0, [r1]		@ptrString -> memory allocated for both strings
	
@ loop through szValA, copying each character byte into ptrString
	ldr		r2, =szValA		@r2 = &szValA
	ldr		r4, =ptrString	@r4 = &ptrString
	ldr		r4, [r4]		@dereference r4 to get address of malloc
	ldr		r5, =iLenA		@r5 = &iLenA
	ldr		r5, [r5]		@r5 = length of string 1
loop1:
	cmp		r5, #0			@base case: r5 = 0
	beq		endloop1		@end loop if r5 = 0
	ldrb	r6, [r2], #1	@put 1 character of string 1 into r6, szValA++
	strb	r6, [r4], #1	@store the character into ptrString, ptrString++
	sub		r5, #1			@r5 = r5 - 1
	b 		loop1			@loop until all string 1 characters are put into ptrString
endloop1:

@ loop through szValB, copying each character byte into ptrString	
	ldr		r2, =szValB		@r2 = &szValB
	ldr		r5, =iLenB		@r5 = &iLenB
	ldr		r5, [r5]		@r5 = length of string 2
	add		r5, #1			@add 1 to string 2 legnth so that null character is read in
loop2:
	cmp		r5, #0			@base case: r5 = 0
	beq		endloop2		@end loop if r5 = 0
	ldrb	r6, [r2], #1	@put 1 character of string 2 into r6, szValB++
	strb	r6, [r4], #1	@store the character into ptrString, ptrString++
	sub		r5, #1			@r5 = r5 - 1
	b 		loop2			@loop until all string 2 characters are put into ptrString
endloop2:

@print the concatenated string
	ldr 	r1, =szMsg3		@r1 = &szMsg3
	bl		putstring		@display concatenation message
	ldr		r1, =ptrString	@r1 = &ptrString
	ldr		r1, [r1]
	bl		putstring		@print concatenated string to console
	ldr		r1, =cLF		@r1 = &cLF
	bl		putch			@newline
	
@ Call service command to terminate program successfully
	ldr		r0, =ptrString	@r0 = &ptrString
	ldr		r0, [r0]		@r0 = address of malloc memory
	bl 		free			@ free dynamic memory

	mov r0, #0
	mov r7, #1
	svc 0

@End of Program
	.end
