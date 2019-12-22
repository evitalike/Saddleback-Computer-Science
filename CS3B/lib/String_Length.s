@ Subroutine String_Length accepts the address of a string and counts the characters in the string, excluding the NULL character and returns that value as an int (word) in the R0 register. will read a string of characters terminated by a null
@    R1: Points to first byte of string to count
@    LR: Contains the return address

@ Returned register contents:
@    R0: Number of characters in the string (does not include null).
@ All registers are preserved as per AAPCS
	
	.global String_Length
	
String_Length:
	push 	{r1, r2, R4-R11, lr}

	mov	r0, #0		@ Initialize counter

loop:
	ldrb	r2, [r1], #1

	cmp		r2, #0
	beq		return		@ If char equals null then return

	add		r0, #1
	b		loop

return:
	pop	{r1, r2, R4-R11, lr}

	bx	LR
	
@End of Program
	.end