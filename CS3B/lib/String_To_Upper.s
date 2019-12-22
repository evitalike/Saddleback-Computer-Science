@*****************************************************************************
@ Function: String_To_Upper
@ Input: Address of a string in r1
@ Output: The lowercase characters of the string are set to upper case
@	All registers are preserved
@*****************************************************************************

	.global String_To_Upper

String_To_Upper:
	push 	{r0, r1, r4-r11, lr}
	
	bl 		String_Length	@r0 = Length of string
loop:
	cmp		r0, #0			@base case: r0 = 0
	beq		return			@end loop if r0 = 0
	ldrb	r4, [r1]		@put 1 character of string into r4
	cmp		r4, #97			@check to see if ascii character is lower case
	bge		lowerToUpper	@branch if character is lower case
back:
	add		r1, #1			@string++
	sub		r0, #1			@r0 = r0 - 1
	b 		loop			@loop until all string 1 characters are put into str1Ptr

return:
	pop		{r0, r1, r4-r11, lr}
	bx		lr				@return to main
	
lowerToUpper:
	sub		r4, #32			@change lowercase to upper case
	strb	r4, [r1]		@store character back into string
	b		back			@continue

@End of Program
	.end
