/*  --- String1.s ---   */
/*  Garrett Geesink  */
/*  CS3B 3 PM Class  */
/*  Tuesday/Thursday */


@ ===================================================
@ int String_length_1(string s1)
@ ===================================================
@ Returns the length of a string
@ 	Input: 	r1 : string s1
@ 	Output: r0 : int (the length of the string in r1)
@ ===================================================

	.global String_length_1

String_length_1:

	push	{r1, r2, r4-r11, LR}
	mov		r0, #0			@ Start the length counter at 0

lenLoop:
	ldrb	r2, [r1], #1	@ Load the current ascii character

	cmp		r2, #0			@ Stop when a "/0" is loaded
	beq 	lenEnd

	add		r0, r0, #1		@ Add 1 to the # of characters
	bal		lenLoop			@ Loop to lenLoop

lenEnd:						@ Return
	pop	{r1, r2, r4-r11, LR}
	bx		lr
	
@ ===============================================	
@ bool String_equals(string s1, string s2)
@ ===============================================
@ Compares 2 strings. If they are identical, returns 1. Else, returns 0.
@ 	Input:	r1 : string s1
@			r2 : string s2
@ 	Output: r0 : bool (returns 1 if strings are equal, else returns 0)
@ ===============================================

	.global String_equals

String_equals:
	push 	{r1, r2, r4-r11, LR}
	mov	r0, #1				@ set r0 to true

equLoop:
	ldrb	r3, [r1], #1	@ Load a single character of s1 into r3
	ldrb	r4, [r2], #1	@ Load a single character of s2 into r4

	cmp		r3, r4			@ Compare the characters
	movne	r0, #0			@ If characters are not equal, set r0 to false and return
	bne		equEnd			

	cmp		r3, #0			@ Return if r3 is a null character
	beq		equEnd				

	b		equLoop			@ Loop	

equEnd:						@ Return
	pop 	{r1, r2, r4-r11, LR}
	bx		LR
	
@ ===============================================	
@ bool String_equalsIgnoreCase(string s1, string s2)
@ ===============================================
@ Compares 2 strings. If they are identical ignoring case, returns 1. Else, returns 0.
@ 	Input:	r1 : string s1
@			r2 : string s2
@ 	Output: r0 : bool (returns 1 if strings are equal ignoring case, else returns 0)
@ ===============================================

	.global String_equalsIgnoreCase

String_equalsIgnoreCase:
	push 	{r1, r2, r4-r11, LR}

	bl		String_copy			@ Copy s1 into r0
	mov		r1, r0				@ Move s1 copy into r1
	bl		String_toLowerCase	@ r0 = s1 copy toLower
	mov 	r1, r0
	push	{r1}				@ Push the copy to save it

	mov		r1, r2				@ Move s2 into r1
	bl		String_copy			@ Copy s2 into r0
	mov		r1, r0				@ Move s2 copy into r1
	bl		String_toLowerCase	@ s2 copy toLower
	mov		r2, r0				@ Move s2 copy into r2

	pop		{r1}				@ Restore copy of r1
	bl		String_equals		@ Test if strings are equal, put boolean result into r0

	pop		{r1, r2, r4-r11, LR}
	bx		LR
	
@ ===============================================	
@ string String_copy(string s1)
@ ===============================================
@ Creates a copy of a string in r1
@ 	Input:	r1 : string s1 (String to copy)
@ 	Output: r0 : string (A copy of the string in r1)
@ ===============================================

	.global 	String_copy

String_copy:
	push	{r1, r2, r4-r11, LR}

	bl	String_length_1		@ r0 = length of s1
	bl	String_alloc		@ r0 = memory address long enough to store the copy
	push	{r0}			@ Save the new address

copyLoop:
	ldrb	r2, [r1], #1	@ Load 1 character from s1 into r2, s1++
	
	cmp		r2, #0			@ End if r2 = null character
	beq		copyEnd			
	
	strb	r2, [r0], #1	@ Store the character from r2 into r0
	b		copyLoop		@ Loop

copyEnd:
	strb 	r2, [r0]		@ Add a null character to our copy in r0
	
	pop		{r0}			@ Restore the address of the copy
	pop 	{r1, r2, r4-r11, LR}
	bx		LR
	
@ ===============================================	
@ string String_substring_1(string s1, int beginIndex, int endIndex)
@ ===============================================
@ Creates a new string in r0 consisting of characters from
@ s1 starting with beginIndex and ending with endIndex.
@ 	Input:	r1 : string s1 (String to turn into substring)
@			r2 : int beginIndex (The starting index)
@			r3 : int endIndex (The ending index)
@ 	Output: r0 : string (Newly created substring of s1)
@ ===============================================

	.global 	String_substring_1

String_substring_1:
	push	{r1-r11, LR}

	bl	String_length_1		@ r0 = length of s1
	mov		r4, r0			@ Move the length into r4

	cmp		r2, r3			@ Invalid index if startIndex > end
	bgt		invalidIndex

	cmp		r2, r4			@ Invalid index if startIndex >= length
	bge		invalidIndex		

	cmp		r3, r4			@ Invalid index if endIndex >= length
	bge		invalidIndex

	sub		r0, r3, r2		@ r0 = startIndex - endIndex
	@ add		r0, #1
	bl		String_alloc	@ r0 = address of new substring

	add		r1, r2			@ Offset the string by startIndex
	push	{R0}			@ Save substring

sub1Loop:
	ldrb	r4, [r1], #1	@ Load a byte of s1 into r4, s1++
	strb	r4, [r0], #1	@ Store the byte into r0, substring++

	cmp		r2, r3			@ Compares index equals startIndex
	beq		sub1End			@ If index equals endIndex then return

	add		r2, #1			@ index++
	b		sub1Loop		@ Loop
	

invalidIndex:
	bl	Set_overflow		@ Set the overflow flag to indicate invalid index
	mov	r0, #0				@ Return null substring
	
	pop		{r1-r11, LR}
	bx LR
	
sub1End:
	pop		{r0}			@ Restore substring address
	
	pop		{r1-r11, LR}
	bx		LR
	
@ ===============================================	
@ string String_substring_2(string s1, int beginIndex)
@ ===============================================
@ Creates a new string in r0 consisting of characters from
@ s1[startIndex] end of s1
@ 	Input:	r1 : string s1 (String to turn into substring)
@			r2 : int beginIndex (The starting index)
@ 	Output: r0 : string (Newly created substring of s1)
@ ===============================================

	.global 	String_substring_2

String_substring_2:
	push	 {r3-r11, LR}

	bl		String_length_1		@ r0 = length of r1
	sub		r3, r0, #1			@ r3 = endIndex = length - 1

	bl		String_substring_1	@ Return the substring

	pop		{r3-r11, LR}
	bx		LR

@ ===============================================	
@ byte String_charAt(string s1, int position)
@ ===============================================
@ Returns the character in the indicated position. If the
@ request is impossible to fulfill, returns 0
@ 	Input:	r1 : string s1 (String to get character from)
@			r2 : int position (The position of the character to return)
@ 	Output: r0 : byte (A character from s1)
@ ===============================================

.global 	String_charAt

String_charAt:
	push 	{r1-r11, LR}

	bl	String_length_1		@ r0 = length of s1
	mov	r3, r0				@ r3 = length

	cmp	r2, r3				@ Invalid position if position >= length
	bge	invalidPos			

	ldrb	r0, [r1, r2]	@ r0 = character of s1 at specified position
	b		charEnd

invalidPos:
	bl	Set_overflow		@ Set the overflow flag to denote invalid position
	mov	r0, #0				@ Return a null character

charEnd:
	pop 	{r1-r11, LR}
	bx	LR


@ ===============================================	
@ bool String_startsWith_1(string s1, string prefix, int pos)
@ ===============================================
@ checks whether the substring starting from the
@ specified index exists within string1.
@ 	Input:	r1 : string s1 (String to compare)
@			r2 : string prefix (Substring to compare)
@			r3 : int pos (The position of s1 to check for the prefix)
@ 	Output: r0 : bool (Return 1 if the substring exists at pos, else return 0)
@ ===============================================

	.global 	String_startsWith_1

String_startsWith_1:
	push 	{r1-r11, LR}

	bl	String_length_1
	mov	r4, r0

	cmp	r3, r4
	bge	invalidStart		@ If position >= length, then branch to bad index

	add	r1, r3				@ Begin at position 1
	mov	r5, #0
	
startLoop:
	ldrb	r0, [r1]		@ Load a character of s1

	cmp	r0, #0				@ If null loaded, end loop
	beq	startEnd			@ End if r0 = 0

	bl	String_startsWith_2	@ Check for substring in s1
	
	cmp	r0, #1				@ End loop if the substring was found
	beq	startEnd			@ Return if found

	add	r1, #1				@ Pos++
	b	startLoop			@ Loop

invalidStart:
	bl	Set_overflow		@ Set overflow flag to denote invalid arguments
	mov	r0, #0				@ Return a null character

startEnd:
	pop 	{r1-r11, LR}
	bx	LR

@ ===============================================	
@ bool String_startsWith_2(string s1, string prefix)
@ ===============================================
@ Checks whether the string begins with prefix
@ 	Input:	r1 : string s1 (String to compare)
@			r2 : string prefix (Substring to compare)		
@ 	Output: r0 : bool (Return 1 if the s1 begins with prefix, else return 0)
@ ===============================================

	.global 	String_startsWith_2

String_startsWith_2:
	push 	{r1-r11, LR}
	mov	r0, #0					@ Set boolean flag to 0

start2Loop:
	ldrb	r3, [r1], #1		@ Load a single character of s1, s1++
	ldrb	r4, [r2], #1		@ Load a single character of prefix, prefix++

	cmp	r4, #0					@ Return 1 if r4 = null character
	moveq	r0, #1				@ Return 1
	beq	start2End

	cmp	r3, #0					@ Return if s1 character = null
	beq	start2End				

	cmp	r3, r4					@ Return if the characters are not equal
	bne	start2End				

	b	start2Loop				@ Loop

start2End:
	pop 	{r1-r11, LR}
	bx	LR

@ ===============================================	
@ bool String_endsWith(string s1, string suffix)
@ ===============================================
@ Checks whether the string ends with the specified suffix.
@ 	Input:	r1 : string s1 (String to compare)
@			r2 : string suffix (Substring to compare)		
@ 	Output: r0 : bool (Return 1 if the s1 ends with suffix, else return 0)
@ ===============================================

	.global 	String_endsWith

String_endsWith:
	push 	{r1-r11, LR}

	bl	String_length_1			@ r0 = length of s1
	mov	r3, r0					@ r3 = string length
	push	{r1}				@ Save s1

	mov	r1, r2					@ move suffix into r1
	bl	String_length_1			@ r0 = length of suffix
	mov	r4, r0					@ r4 = suffix length
	pop	{r1}					@ Loads the string

	cmp	r4, r3					@ Compare lengths
	movhi	r0, #0				@ Return false if suffix longer than s1
	bhi	endEnd
	
	sub	r3, r4					@ r3 = s1 length - suffix length
	bl	String_startsWith_1		@ r0 = result of String_startsWith_1

endEnd:
	pop 	{r1-r11, LR}
	bx	LR


@ ================ Helper Functions not Required for Grading ============================


/*
@ ===========================================
@ void String_To_Lower(string s1)
@ ===========================================
@	Input: The address of a string in r1
@	Output: Converts all lowercase ascii
@			characters in the string into
@			uppercase and puts it in r1
@
@	Preserves the contents of all registers
@ ============================================
String_To_Lower:
	push 	{r0, r4-r11, lr}
	bl 		String_Length_1	@ r0 = Length of string
	
lowLoop:
	cmp		r0, #0			@ base case: r0 = 0 (null character)
	beq		lowEnd			@ end loop if r0 = 0
	ldrb	r4, [r1]		@ put 1 character of string into r4
	
	cmp	r0, #'A'	
	blt	upperToLower

	cmp	r0, #'Z'
	bgt	upperToLower
	
lowEnd:
	add		r1, #1			@ Move to next character
	sub		r0, #1			@ r0 = r0 - 1
	b 		lowLoop			@ loop

lowEnd:
	pop		{r0, r4-r11, lr}
	bx		lr

@ Add 32 from ascii character if it is uppercase
lowerToUpper:
	sub		r4, #32
	strb	r4, [r1]
	b		back

    bx lr
*/	
@ ===============================================	
@ string String_alloc(int length)
@ ===============================================
@ Dynamically allocates enough memory to hold a string of the specified length 
@ 	Input:	r0 : int length (Length of memory to allocate)
@ 	Output: r0 : string& (The memory address large enough to hold the string)
@ ===============================================

	.extern		malloc
	.global 	String_alloc

String_alloc:
	push	{r1-r3,r4-r11, LR}

	add		r0, #1			@ Add 1 to string length for null character
	bl		malloc

	pop 	{r1-r3,r4-r11, LR}
	bx		LR
	
@ ===============================================
@ Subroutine Set_overflow: This method sets the overflow flag
@ ===============================================
@ Sets the overflow flag
@	No input
@	Output: the overflow flag is set
@ ===============================================

	.global 	Set_overflow

Set_overflow:
	push 	{r0, r4-r11, LR}

	mov	r0, #0x80000000		@ MSB = 1
	subs	r0, #1			@ MSB = 0 -> C = 1, V = 1
	mov	R0, #0x10
	asrs	r0, #1			@ R0 = 0x1 -> C = 0, V unchanged

	pop 	{r0, r4-r11, LR}
	bx	LR	

	.end				@End of Program
	
	
	
	
	
	
