/*	fact.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */
	
	.global fact			@provide program start

fact:
	push	{r1, r2, lr}
	
@base case: if r0 == 1 or r0 == 0, end the factorial
	cmp 	r0, #0
	beq		endFact
	cmp		r0, #1
	beq 	endFact
	
@recursive case: multiply r0 by fact(r0-1)
	mov		r1, r0			@r1 = n
	sub 	r0, r0, #1		@r0--
		
	bl		fact			@fact(n - 1)
	
	mul		r2, r1, r0
	mov 	r0, r2
	pop		{r1, r2, lr}
	bx		lr
	
endFact:
	mov 	r0, #1
	pop		{r1, r2, lr}
	bx		lr
	
@End of Program
	.end