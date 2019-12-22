@ ===============================================    
@ int String_length_2(string s1)
@ ===============================================
@ Given a null terminated string  as input, returns an integer representing 
@ the length of a null terminated string, excluding the null character.
@     Input:	r1 : string s1
@     Output: 	r0 : int (the length of the string in r1)
@ ===============================================
	
	.global String_length_2
	
String_length_2:
	push 	{r1, r2, r4-r11, lr}
	mov		r0, #0					@ Initialize counter

String_Length_2_loop:
	ldrb	r2, [r1], #1			@ load one character of the string, s1++

	cmp		r2, #0					@ check if current character is null
	beq		String_Length_2_return	@ If char equals null then return

	add		r0, #1					@ counter++
	b		String_Length_2_loop	@ loop until all characters counted

String_Length_2_return:
	pop		{r1, r2, r4-r11, lr}
	bx		lr						@ return to lr


@ ===============================================    
@ int String_indexOf_1(String s1, char ch)
@ ===============================================
@ Returns the index of first occurrence of the specified character ch in s1.
@ searching begins at index location 0
@     Input:	r1 : string s1 (string to search)
@				r2 : char ch (character to search for)
@     Output: 	r0 : int (the index location of the character, beginning at location 0)
@ ===============================================

	.global String_indexOf_1
	
String_indexOf_1:
	push 	{r1-r3, r4-r11, lr}
	mov 	r0, #0					@ r0 = 0
	
String_indexOf_1_loop:
	ldrb 	r3, [r1], #1			@ r3 = one character of the string, s1++
	
	cmp 	r3, #0					@ check if current character is null
	beq 	String_indexOf_1_null	@ branch if null
	
	cmp 	r3, r2					@ Check to see if the current char is the one we want
	beq 	String_indexOf_1_end	@ branch if char found
	
	add 	r0, #1					@ s1++	
	b		String_indexOf_1_loop	@loop until character is found or character is null
		
String_indexOf_1_null:
	mvn r0, #0						@ If char is not found, return -1
		
String_indexOf_1_end:
	pop		{r1-r3, r4-r11, lr}
	bx		lr						@ return to lr

@ ===============================================    
@ int String_indexOf_2(String s1, char ch, int fromIndex)
@ ===============================================
@ Returns the index of first occurrence of the specified character ch in s1.
@ searching begins at index location fromIndex
@     Input:	r1 : string s1 (string to search)
@				r2 : char ch (character to search for)
@				r3 : int fromIndex (index location where search starts)
@     Output: 	r0 : int (index location of the character, beginning at location 0)
@ ===============================================

	.global String_indexOf_2
	
String_indexOf_2:
	push 	{r1-r3, r4-r11, lr}
	
	cmp 	r3, #0					@ compare fromIndex to 0
	blt		String_indexOf_2_null	@ return -1 if fromIndex < 0
	
	bl		String_length_2			@ r0 = length of s1
	cmp 	r3, r0					@ compare fromIndex to 0
	bgt		String_indexOf_2_null	@ return -1 if fromIndex > s1 length
	
	mov		r0, r3					@ r0 = fromIndex
	add		r1, r0					@ s1 = s1 + fromIndex (s1 index set to fromIndex)
	
String_indexOf_2_loop:
	ldrb 	r4, [r1], #1			@ r4 = one character of the string, s1++
	
	cmp 	r4, #0					@ check if current character is null
	beq 	String_indexOf_2_null	@ branch if null
	
	cmp 	r4, r2					@ Check if the current char is the one we want
	beq 	String_indexOf_2_end	@ branch if char found
	
	add 	r0, #1					@ s1++	
	b		String_indexOf_2_loop	@ loop until character is found or character is null
		
String_indexOf_2_null:
	mvn 	r0, #0					@ If char is not found, return -1
		
String_indexOf_2_end:
	pop		{r1, r2, r3, R4-R11, lr}
	bx		lr						@ return to lr


@ ===============================================    
@ int String_indexOf_3(String s1, String str)
@ ===============================================
@ Returns the index of first occurrence of the specified String str in s1.
@ searching begins at index location 0
@     Input:	r1 : string s1 (string to search)
@				r2 : String str (string to search for)
@     Output: 	r0 : int (the index location of the string, beginning at location 0)
@ ===============================================

	.global String_indexOf_3
	
String_indexOf_3:
	push 	{r1-r3, r4-r11, lr}
	
	mov 	r4, r1					@ r4 = s1
	mov 	r5, r2					@ r2 = str
	
	@mov 	r0, #0					@ r0 = 0
	
	mov		r1, r4					@ r1 = s1 (redundant)
	bl		String_length_2			@ r0 = length of s1
	mov 	r6, r0					@ r6 = length of s1
	
	mov 	r1, r5					@ r1 = str
	bl		String_length_2			@ r0 = length of str
	mov		r7, r0					@ r7 = length of str

@ return -1 if s1 is smaller than str
	cmp 	r6, r7					@ compare length of s1 and str
	blt 	String_indexOf_3_null	@ branch if s1 length < str length

	mov 	r6, #0					@ r6 = 0 (index location)
	
String_indexOf_3_loop:
	ldrb 	r7, [r4]			@ r7 = one character of the string, s1++
	
	cmp 	r7, #0					@ check if current character is null
	beq 	String_indexOf_3_null	@ branch if null
	
@check if remaining characters of s1 are str
	mov		r1, r4					@ r1 = s1
	mov		r2, r5					@ r2 = str
	bl		String_contains			@ returns 1 if remaining chars of s1 contain str
	cmp 	r0, #1					@ check if String_starts_with_2 is true
	beq 	String_indexOf_3_found	@ branch is index location found

	add 	r4, #1					@s1++
	add 	r6, #1					@index location++
	b 		String_indexOf_3_loop	@ loop until all character in s1 are checked
		
String_indexOf_3_null:
	mvn 	r0, #0					@ If char is not found, return -1
	b		String_indexOf_3_end	@ branch to end
	
String_indexOf_3_found:
	mov		r0, r6					@ r0 = index location of str in s1
		
String_indexOf_3_end:
	pop		{r1-r3, r4-r11, lr}
	bx		lr						@ return to lr

@ ===============================================    
@ int String_lastIndexOf_1(String s1, char ch)
@ ===============================================
@ returns the last occurrence of the character ch in s1.
@ searching begins at index location 0
@     Input:	r1 : string s1 (string to search)
@				r2 : char ch (character to search for)
@     Output: 	r0 : int (index location of the last occurence, beginning at location 0)
@ ===============================================

	.global String_lastIndexOf_1
	
String_lastIndexOf_1:
	push 	{r1-r3, r4-r11, lr}
	mvn 	r0, #0					@ r0 = -1
	mov		r4, #0					@ r4 = 0 (counter)
	
String_lastIndexOf_1_loop:
	ldrb 	r3, [r1], #1			@ r3 = one character of the string, s1++
	
	cmp 	r3, #0					@ check if current character is null
	beq 	String_lastIndexOf_1_end	@ branch if null
	
	cmp 	r3, r2					@ Check to see if the current char is the one we want
	beq 	String_lastIndexOf_1_found	@ branch if char found

String_lastIndexOf_1_back:
	add		r4, #1					@ counter++
	b		String_lastIndexOf_1_loop	@ loop until character is null
		
String_lastIndexOf_1_end:
	pop		{r1-r3, r4-r11, lr}
	bx		lr						@ return to lr
	
String_lastIndexOf_1_found:
	mov		r0, r4					@ set r0 to current index if character is found
	b		String_lastIndexOf_1_back	@ continue loop

@ ===============================================    
@ int String_lastIndexOf_2(String s1, char ch, int fromIndex)
@ ===============================================
@ returns the last occurrence of the character ch in s1.
@ searching begins at index location fromIndex
@     Input:	r1 : string s1 (string to search)
@				r2 : char ch (character to search for)
@				r3 : int fromIndex (index location where search starts)
@     Output: 	r0 : int (index location of the last occurence, beginning at location 0)
@ ===============================================

	.global String_lastIndexOf_2
	
String_lastIndexOf_2:
	push 	{r1-r3, r4-r11, lr}
	
	cmp 	r3, #0					@ compare fromIndex to 0
	blt		String_lastIndexOf_2_neg	@ return -1 if fromIndex < 0
	
	bl		String_length_2			@ r0 = length of s1
	cmp 	r3, r0					@ compare fromIndex to 0
	bgt		String_lastIndexOf_2_neg	@ return -1 if fromIndex > s1 length
	
	mvn		r0, #0					@ r0 = -1
	add		r1, r3					@ s1 = s1 + fromIndex (s1 index set to fromIndex)
	
	mov		r4, r3					@ r4 = fromIndex (counter)
	
String_lastIndexOf_2_loop:
	ldrb 	r3, [r1], #1			@ r3 = one character of the string, s1++
	
	cmp 	r3, #0					@ check if current character is null
	beq 	String_lastIndexOf_2_end	@ branch if null
	
	cmp 	r3, r2					@ Check to see if the current char is the one we want
	beq 	String_lastIndexOf_2_found	@ branch if char found

String_lastIndexOf_2_back:
	add		r4, #1					@ counter++
	b		String_lastIndexOf_1_loop	@ loop until character is null
		
String_lastIndexOf_2_end:
	pop		{r1-r3, r4-r11, lr}
	bx		lr						@ return to lr
	
String_lastIndexOf_2_found:
	mov		r0, r4					@ set r0 to current index if character is found
	b		String_lastIndexOf_2_back	@ continue loop
	
String_lastIndexOf_2_neg:
	mvn		r0, #0					@ r0 = -1
	b		String_lastIndexOf_2_end	@ branch to end

@ ===============================================    
@ int String_lastIndexOf_3(String s1, String str)
@ ===============================================
@ returns the last occurrence of the string str in s1.
@ searching begins at index location 0
@     Input:	r1 : string s1 (string to search)
@				r2 : string str (string to search for)
@     Output: 	r0 : int (index location of the last occurence, beginning at location 0)
@ ===============================================

	.global String_lastIndexOf_3
	
String_lastIndexOf_3:
	push 	{r1-r3, r4-r11, lr}
	
	mov 	r4, r1					@ r4 = s1
	mov 	r5, r2					@ r2 = str
	
	mov 	r0, #0					@ r0 = 0
	
	mov		r1, r4					@ r1 = s1 (redundant)
	bl		String_length_2			@ r0 = length of s1
	mov 	r6, r0					@ r6 = length of s1
	
	mov 	r1, r5					@ r1 = str
	bl		String_length_2			@ r0 = length of str
	mov		r7, r0					@ r7 = length of str

@ return -1 if s1 is smaller than str
	cmp 	r6, r7					@ compare length of s1 and str
	blt 	String_lastIndexOf_3_neg	@ branch if s1 length < str length

	mov r6, #0						@ r6 = 0 (index location)
	mvn r8,	#0						@ r8 = -1
	
String_lastIndexOf_3_loop:
	ldrb 	r7, [r4]				@ r3 = one character of the string, s1++
	
	cmp 	r7, #0					@ check if current character is null
	beq 	String_lastIndexOf_3_end	@ branch if null
	
@check if remaining characters of s1 are str
	mov		r1, r4					@ r1 = s1
	mov		r2, r5					@ r2 = str
	bl		String_startsWith_2		@ returns 1 if remaining chars of s1 contain str
	cmp 	r0, #1					@ check if String_starts_with_2 is true
	beq 	String_lastIndexOf_3_found	@ branch if index location found
String_lastIndexOf_3_back:
	add 	r4, #1					@ s1++
	add 	r6, #1					@ index location++
	b 		String_lastIndexOf_3_loop	@ loop until all character in s1 are checked
		
String_lastIndexOf_3_neg:
	mvn 	r0, #0					@ If char is not found, return -1
	b		String_lastIndexOf_3_end	@ branch to end
	
String_lastIndexOf_3_found:
	mov		r8, r6					@ r0 = index location of str in s1
	b		String_lastIndexOf_3_back
		
String_lastIndexOf_3_end:
	mov		r0, r8					@ r0 = index of substring
	pop		{r1-r3, r4-r11, lr}
	bx		lr						@ return to lr

@ ===============================================    
@ String String_concat(String s1, String str)
@ ===============================================
@ Concatenates the specified string str to the end of string s1
@ dynamically allocates memory for the new string
@     Input:	r1 : string s1 (original string)
@				r2 : string str (string to concatenate onto s1)
@     Output: 	r0 : string (newly created concatenated string)
@ ===============================================

	.global String_concat
	.extern malloc

String_concat:
	push 	{r1-r3, r4-r11, lr}
	
	mov		r4, r1					@ r4 = s1
	mov		r5, r2					@ r5 = str
	
@ allocate memory for concatenated string
	bl		String_length_2			@ r0 = length of s1
	mov		r3, r0					@ r3 = length of s1
	mov		r6, r0					@ r6 = length of s1
	
	mov		r1, r2					@ r1 = str
	bl		String_length_2			@ r0 = length of str
	mov		r7, r0					@ r7 = length of str
	add		r3, r0, r3				@ r3 = length of s1 + str
	add		r3, #1					@ add one for the null character
	
	mov		r0, r3					@ r0 = num bytes to allocate
	bl		malloc					@ allocate space for concatenated string
	mov		r8, r0					@ r8 = allocated memory
	push 	{r8}					@ push allocated memory for easy retireval
	
@ loop through s1, copying each character byte into allocated memory
String_replace_loop1:
	cmp		r6, #0					@ base case: r6 = 0
	beq		String_replace_endloop1	@ end loop if r6 = 0
	ldrb	r9, [r4], #1			@ put 1 character of s1 into r9, s1++
	strb	r9, [r8], #1			@ store the character into new memory, new memory++
	sub		r6, #1					@ r6 = r6 - 1
	b 		String_replace_loop1	@ loop until all string 1 characters are put into ptrString
String_replace_endloop1:

@ loop through str, copying each character byte into allocated memory
	add		r7, #1					@ add one to length to get null character
String_replace_loop2:
	cmp		r7, #0					@ base case: r6 = 0
	beq		String_replace_endloop2	@ end loop if r6 = 0
	ldrb	r9, [r5], #1			@ put 1 character of s1 into r9, s1++
	strb	r9, [r8], #1			@ store the character into new memory, new memory++
	sub		r7, #1					@ r6 = r6 - 1
	b 		String_replace_loop2	@ loop until all string 1 characters are put into ptrString
String_replace_endloop2:

@ Get the concatenated string and branch to lr
	pop		{r0}					@ pop to get beginning of allocated memory
	
	pop 	{r1-r3, r4-r11, lr}
	bx		lr						@ return to lr

@ ===============================================    
@ String String_replace(String s1, char oldChar, char newChar)
@ ===============================================
@ returns the new updated string after changing all 
@ the occurrences of oldChar with the newChar in s1.
@ dynamically allocates memory for the new string.
@     Input:	r1 : string s1 (original string)
@				r2 : char oldChar (character to be replaced)
@				r3 : char newChar (character to replace oldChar)
@     Output: 	r0 : string (newly created replaced string)
@ ===============================================

	.global String_replace

String_replace:
	push 	{r1, r2, r4-r11, lr}
	bl		String_copy				@ r0 = copy of s1
	push	{r0}
	mov		r1, r0					@ r1 = s1
	bl 		String_length_2			@ r0 = Length of string
	
String_replace_loop:
	cmp		r0, #0					@ base case: r0 = 0
	beq		String_replace_end		@ end loop if counter = 0

	ldrb	r4, [r1]				@ put 1 character of string into r4
	
	cmp		r4, r2					@ check to see if ascii character = oldChar
	beq		changeCharacter			@ branch if this character = oldChar

String_replace_back:
	add		r1, #1					@ s1++
	sub		r0, #1					@ counter--
	b		String_replace_loop		@ loop until all characters checked
	
String_replace_end:
	pop		{r0}
	pop		{r1, r2, r4-r11, lr}
	bx		lr						@ return to lr
	
changeCharacter:
	strb	r3, [r1]					@ change current character to newChar
	b		String_replace_back		@ continue loop


@ ===============================================    
@ String String_toLowerCase(String s1)
@ ===============================================
@ converts the string s1 to lower case
@ dynamically allocates memory for the new string
@     Input:	r1 : string s1 (original string)
@     Output: 	r0 : string (newly created lower case string)
@ ===============================================
	
	.global String_toLowerCase

String_toLowerCase:
	push 	{r1, r2, r4-r11, lr}
	bl		String_copy				@ r0 = copy of s1
	push	{r0}
	mov		r1, r0					@ r1 = s1
	bl 		String_length_2			@ r0 = Length of string
	
String_toLowerCase_loop:
	cmp		r0, #0					@ base case: r0 = 0
	beq		String_toLowerCase_end	@ end loop if r0 = 0
	ldrb	r4, [r1]				@ put 1 character of string into r4
	
	cmp		r4, #'Z'				@ check to see if ascii character is less than Z
	ble		upperCaseTest			@ branch if character is less than Z
	
String_toLowerCase_back:
	add		r1, #1					@ s1++
	sub		r0, #1					@ r0 = r0 - 1
	b 		String_toLowerCase_loop	@ loop until all string 1 characters are put into str1Ptr

String_toLowerCase_end:
	pop		{r0}
	pop		{r1, r2, r4-r11, lr}
	bx		lr						@ return to lr

upperCaseTest:
	cmp		r4, #'A'				@ check to see if ascii character is greater than A
	bgt		toLowerCase				@ branch if upper case
	b		String_toLowerCase_back	@ return to loop if not

toLowerCase:
	add		r4, #32					@ change lowercase to upper case
	strb	r4, [r1]				@ store character back into string
	b		String_toLowerCase_back	@ continue loop

@ ===============================================    
@ String String_toUpperCase(String s1)
@ ===============================================
@ converts the string s1 to upper case
@ dynamically allocates memory for the new string
@     Input:	r1 : string s1 (original string)
@     Output: 	r0 : string (newly created upper case string)
@ ===============================================

	.global String_toUpperCase

String_toUpperCase:
	push 	{r1, r2, r4-r11, lr}
	bl		String_copy				@ r0 = copy of s1
	push	{r0}
	mov		r1, r0					@ r1 = s1
	bl 		String_length_2			@ r0 = Length of string
	
String_toUpperCase_loop:
	cmp		r0, #0					@ base case: r0 = 0
	beq		String_toUpperCase_end	@ end loop if r0 = 0
	ldrb	r4, [r1]				@ put 1 character of string into r4
	cmp		r4, #'a'				@ check to see if ascii character is greater than a
	bge		toUpperCase				@ branch if character is greater than a
	
String_toUpperCase_back:
	add		r1, #1					@ s1++
	sub		r0, #1					@ r0 = r0 - 1
	b 		String_toUpperCase_loop	@ loop until all string 1 characters are put into str1Ptr

String_toUpperCase_end:
	pop		{r0}
	pop		{r1, r2, r4-r11, lr}
	bx		lr						@ return to lr

lowerCaseTest:
	cmp		r4, #'z'				@ check to see if ascii character is less than z
	ble		toLowerCase				@ branch if lower case
	b		String_toUpperCase_back	@ return to loop if not
	
toUpperCase:
	sub		r4, #32					@ change lowercase to upper case
	strb	r4, [r1]				@ store character back into string
	b		String_toUpperCase_back	@ continue loop

@ ===============================================
	.global String_contains
String_contains:
	push	{r4-r8, lr}
	mov		r4, r1
	mov		r5, r2

String_contains_loop:
	ldrb	r1, [r4], #1
	ldrb	r2, [r5], #1

	cmp 	r2, #0
	beq		String_contains_found

	cmp 	r1, #0
	beq		String_contains_null

	cmp		r1, r2
	bne		String_contains_null

	b		String_contains_loop

String_contains_found:
	mov		r0, #1
	b		String_contains_end

String_contains_null:
	mov		r0, #0

String_contains_end:
	pop		{r4-r8, PC}

@End of Program
	.end
