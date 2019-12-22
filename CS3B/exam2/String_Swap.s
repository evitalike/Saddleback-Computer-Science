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
