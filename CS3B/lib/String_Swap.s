@*****************************************************************************
@ Function: String_Swap
@ Input: Pointer to the address of a string in r1 and r2
@ Output: The address of the string in r1 is swapped with
@	with the address of the string in r2
@ All registers are preserved
@*****************************************************************************

	.global String_Swap

String_Swap:
	push 	{r4-r11, lr}
	
	ldr		r4, [r1]
	ldr		r5, [r2]
	str		r4, [r2]
	str		r5, [r1]
	
	pop		{r4-r11, lr}

	bx		lr

@End of Program
	.end
