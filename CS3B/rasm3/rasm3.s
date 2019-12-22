/* ------- rasm3.s ------- */
/* Garrett & Aaron Geesink */
/* --- CS3B 3 PM Class --- */
/* --- Tuesday/Thursday ---*/
@ ==============================
@ This is the driver for rasm 3
@ ==============================

.data
	strTitle:	.asciz	"Name: Garrett & Aaron Geesink\nAssignment: RASM 3\nDate: 11/5/2019\n\n"
	strInput1:	.asciz	"Enter string s1: "
	strInput2:	.asciz	"Enter string s2: "
	strInput3:	.asciz	"Enter string s3: "
	
	strTrue:	.asciz	"TRUE"
	strFalse:	.asciz	"FALSE"
	strError:	.asciz	"Error: r0 not boolean"
	strLength1:	.asciz	"s1.length() = "
	strLength2:	.asciz	"\ns2.length() = "
	strLength3:	.asciz	"\ns3.length() = "
	strEquals1:	.asciz	"\nString_equals(s1,s3) = "
	strEquals2:	.asciz	"\nString_equals(s1,s1) = "
	strEIC1:	.asciz	"\nString_equalsIgnoreCase(s1,s3) = "
	strEIC2:	.asciz	"\nString_equalsIgnoreCase(s1,s2) = "
	strCopy1:	.asciz	"\ns4 = String_copy(s1)"
	strCopy2:	.asciz	"\ns1 = "
	strCopy3:	.asciz	"\ns4 = "
	strSub1:	.asciz	"\nString_substring_1(s3,4,13) = "
	strSub2:	.asciz	"\nString_substring_2(s3,7) = "
	strChar:	.asciz	"\nString_charAt(s2,4) = "
	strStarts1:	.asciz	"\nString_startsWith_1(s1,11,'hat.') = "
	strStarts2:	.asciz	"\nString_startsWith_2(s1,'Cat') = "
	strEnds:	.asciz	"\nString_endsWith(s1,'in the hat.') = "
	strIndex1:	.asciz	"\nString_indexOf_1(s2,'g') = "
	strIndex2:	.asciz	"\nString_indexOf_2(s2,'g',9) = "
	strIndex3:	.asciz	"\nString_indexOf_3(s2,'eggs') = "
	strLast1:	.asciz	"\nString_lastIndexOf_1(s2,'g') = "
	strLast2:	.asciz	"\nString_lastIndexOf_2(s2,'g',6) = "
	strLast3:	.asciz	"\nString_lastIndexOf_3(s2,'egg') = "
	strReplace:	.asciz	"\nString_replace(s1,'a','o') = "
	strLower:	.asciz	"\nString_toLowerCase(s1) = "
	strUpper:	.asciz	"\nString_toUpperCase(s1) = "
	strConcat1:	.asciz	"\nString_concat(s1, ' ');"
	strConcat2:	.asciz	"\nString_concat(s1, s2) = "
	
	strArg1:	.asciz	"hat."
	strArg2:	.asciz	"Cat"
	strArg3:	.asciz	"in the hat."
	strArg4:	.asciz	"eggs"
	strArg5:	.asciz	"egg"
	strSpace:	.asciz	" "
	
	str1Ptr: 	.skip	100
	str2Ptr:	.skip	100
	str3Ptr:	.skip	100
	iLen1:		.word 	0
	iLen2:		.word 	0
	iLen3:		.word	0
	
	strVal:		.skip 	100
	strTemp:	.skip 	12
	
	cLF:		.byte	10
	
.text
	.global _start
	.extern malloc
	.extern free
	.equ	BUFSIZE, 100

_start:
	ldr r1, =strTitle		@ Display strTitle1
	bl putstring
	
@ ===================   Input s1 ========================
@ Input string1, store in memory
	ldr r1, =strInput1		@Output strInput1
	bl putstring

	ldr r1, =str1Ptr		@ r1 = strVal
    ldr r2, =BUFSIZE		@ r2 = number of buffer entries
    bl getstring			@ read in the string
	
@ Get size of input, store in memory
	bl	String_length_1		@ r0 = length of strVal
	ldr	r1, =iLen1			@ load iLen1
	str	r0, [r1]			@ store length of strVal into memory
/*
@ Allocate memory and store memory address in str1Ptr
	bl malloc				@ r0 = memory allocated for new s1
	ldr	r1, =str1Ptr		@ load ptrString
	str	r0, [r1]			@ store allocated memory into a pointer
	
@ Copy characters of strVal into str1Ptr
	ldr	r2, =strVal			@ r2 = &strVal
	ldr	r4, =str1Ptr		@ r4 = &str1Ptr
	ldr r4, [r4]			@ dereference str1Ptr
	ldr	r5, =iLen1			@ r5 = &iLen1
	ldr	r5, [r5]			@ r5 = length of string1
	add r5, #1				@ add 1 to string length to read null character
loop1:
	cmp	r5, #0				@ if r5 = 0, endloop
	beq	endLoop1		
	ldrb r6, [r2], #1		@ store a character of string1 into r6, strVal++
	strb r6, [r4], #1		@ store the character into str1Ptr, str1Ptr++
	sub r5, #1				@ r5--
	b loop1					@ loop until all string1 characters are put into str1Ptr
endLoop1:
*/
@ ===================   Input s2 ========================
@ Input string2, store in memory
	ldr r1, =strInput2		@Output strInput2
	bl putstring

	ldr r1, =str2Ptr			@ r1 = strVal
    ldr r2, =BUFSIZE		@ r2 = number of buffer entries
    bl getstring			@ read in the string

@ Get size of input, store in memory
	bl	String_length_2		@ r0 = length of strVal
	ldr	r1, =iLen2			@ load iLen2
	str	r0, [r1]			@ store length of strVal into memory
/*
@ Allocate memory and store memory address in str1Ptr
	bl malloc				@ r0 = memory allocated for new s2
	ldr	r1, =str2Ptr		@ load ptrString
	str	r0, [r1]			@ store allocated memory into a pointer
	
@ Copy characters of strVal into str1Ptr
	ldr	r2, =strVal			@ r2 = &strVal
	ldr	r4, =str2Ptr		@ r4 = &str2Ptr
	ldr r4, [r4]			@ dereference str2Ptr
	ldr	r5, =iLen2			@ r5 = &iLen2
	ldr	r5, [r5]			@ r5 = length of string2
	add r5, #1				@ add 1 to string length to read null character
loop2:
	cmp	r5, #0				@ if r5 = 0, endloop
	beq	endLoop2		
	ldrb r6, [r2], #1		@ store a character of s2 into r6, strVal++
	strb r6, [r4], #1		@ store the character into str2Ptr, str2Ptr++
	sub r5, #1				@ r5--
	b loop2					@ loop until all string1 characters are put into str1Ptr
endLoop2:
*/
@ ===================   Input s3 ========================
@ Input string3, store in memory
	ldr r1, =strInput3		@Output strInput3
	bl putstring

	ldr r1, =str3Ptr			@ r1 = strVal
    ldr r2, =BUFSIZE		@ r2 = number of buffer entries
    bl getstring			@ read in the string
	
@ Get size of input, store in memory
	bl	String_length_2		@ r0 = length of strVal
	ldr	r1, =iLen3			@ load iLen3
	str	r0, [r1]			@ store length of strVal into memory
/*
@ Allocate memory and store memory address in str3Ptr
	bl malloc				@ r0 = memory allocated for new s3
	ldr	r1, =str3Ptr		@ load ptrString
	str	r0, [r1]			@ store allocated memory into a pointer
	
@ Copy characters of strVal into str1Ptr
	ldr	r2, =strVal			@ r2 = &strVal
	ldr	r4, =str3Ptr		@ r4 = &str3Ptr
	ldr r4, [r4]			@ dereference str3Ptr
	ldr	r5, =iLen3			@ r5 = &iLen3
	ldr	r5, [r5]			@ r5 = length of string3
	add r5, #1				@ add 1 to string length to read null character
loop3:
	cmp	r5, #0				@ if r5 = 0, endloop
	beq	endLoop3		
	ldrb r6, [r2], #1		@ store a character of s3 into r6, strVal++
	strb r6, [r4], #1		@ store the character into str3Ptr, str3Ptr++
	sub r5, #1				@ r5--
	b loop3					@ loop until all string1 characters are put into str3Ptr
endLoop3:
*/
@ =================== String length ===================
	ldr r1, =strLength1		@ Length1 message
	bl putstring
	
	ldr r0, =iLen1			@ Display Length1
	ldr	r0,	[r0]
	ldr r1, =strTemp
	bl intasc32
	bl putstring
	
	ldr r1, =strLength2		@ Length2 message
	bl putstring
	
	ldr r0, =iLen2			@ Display Length2
	ldr	r0,	[r0]
	ldr r1, =strTemp
	bl intasc32
	bl putstring
	
	ldr r1, =strLength3		@ Length3 message
	bl putstring
	
	ldr r0, =iLen3			@ Display Length3
	ldr	r0,	[r0]
	ldr r1, =strTemp
	bl intasc32
	bl putstring
	
@ =================== String equals =================== 
	ldr r1, =strEquals1		@ Equals1 message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1,s3)
	ldr r2, =str3Ptr
	bl String_equals		@ Call function
	bl Print_bool			@ Print boolean value
	
	ldr r1, =strEquals2		@ Equals2 message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1,s1)
	ldr r2, =str1Ptr
	bl String_equals		@ Call function
	bl Print_bool			@ Print boolean value
	
@ ============== String equalsIgnoreCase ============== 
	ldr r1, =strEIC1		@ EIC1 message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1,s3)
	ldr r2, =str3Ptr
	bl String_equalsIgnoreCase	@ Call function
	bl Print_bool			@ Print boolean value
	
	ldr r1, =strEIC2		@ EIC2 message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1,s2)
	ldr r2, =str2Ptr
	bl String_equalsIgnoreCase	@ Call function
	bl Print_bool			@ Print boolean value
	
@ =================== String copy =================== 
	ldr r1, =strCopy1		@ Copy1 message
	bl putstring
	
	ldr r1, =strCopy2		@ Copy2 message
	bl putstring
	
	ldr r1, =str1Ptr		@ Load argument (s1)
	bl putstring			@ Print s1
	bl String_copy			@ Function call (r0 = copy of s1)
	
	ldr r1, =strCopy3		@ Copy3 message
	bl putstring
	
	mov r1, r0				@ Move copy into r1
	bl putstring			@ Print copy s4
	
@ ================= String substring ================= 
	ldr r1, =strSub1		@ Sub1 message
	bl putstring
	ldr r1, =str3Ptr		@ Load arguments (s3, 4, 13)
	mov r2, #4
	mov r3, #13
	bl String_substring_1	@ Function call (r0 = &substring)
	
	mov r1, r0				@ Move substring to r1
	bl putstring			@ Print substring
	
	ldr r1, =strSub2		@ Sub2 message
	bl putstring
	ldr r1, =str3Ptr		@ Load arguments (s3, 7)
	mov r2, #7
	bl String_substring_2	@ Function call (r0 = &substring)
	
	mov r1, r0				@ Move substring to r1
	bl putstring			@ Print substring
	
@ =================== String charAt =================== 
	ldr r1, =strChar		@ Char message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, #4)
	mov r2, #4
	bl String_charAt		@ Function call (r0 = character in s2)
	
	ldr r1, =strTemp
	strb r0, [r1]			@ Loads character into r1
	bl	putch				@ ODisplay character
	
@ ================= String startsWith ================= 
	ldr r1, =strStarts1		@ Starts1 message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1, 11, "hat.")
	mov r3, #11
	ldr r2, =strArg1
	bl String_startsWith_1	@ Function call (r0 = bool)
	bl Print_bool
	
	ldr r1, =strStarts2		@ Starts2 message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1, "Cat")
	ldr r2, =strArg2
	bl String_startsWith_2	@ Function call (r0 = bool)
	bl Print_bool
	
@ =================== String endsWith =================== 
	ldr r1, =strEnds		@ Ends message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1, "in the hat.")
	ldr r2, =strArg3
	bl String_endsWith		@ Function call (r0 = bool)
	bl Print_bool
	
@ =================== String indexOf =================== 
	ldr r1, =strIndex1		@ Index1 message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, 'g')
	mov r2, #'g'
	bl String_indexOf_1		@ Function call (r0 = int index)
	ldr r1, =strTemp
	bl intasc32				@ Convert index to ascii
	bl putstring			@ Print index
	
	ldr r1, =strIndex2		@ Index2 message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, 'g', 9)
	mov r2, #'g'
	mov r3, #9
	bl String_indexOf_2		@ Function call (r0 = int index)
	ldr r1, =strTemp
	bl intasc32				@ Convert index to ascii
	bl putstring			@ Print index
	
	ldr r1, =strIndex3		@ Index3 message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, "eggs")
	ldr r2, =strArg4
	bl String_indexOf_3		@ Function call (r0 = int index)
	ldr r1, =strTemp
	bl intasc32				@ Convert index to ascii
	bl putstring			@ Print index
	
@ ================= String lastIndexOf ================= 
	ldr r1, =strLast1		@ Last1 message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, 'g')
	mov r2, #'g'
	bl String_lastIndexOf_1 @r0 = int index
	ldr r1, =strTemp
	bl intasc32				@ Convert index to ascii
	bl putstring			@ Print index
	
	ldr r1, =strLast2		@ Last2 message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, 'g', 6)
	mov r2, #'g'
	mov r3, #6
	bl String_lastIndexOf_2 @ r0 = int index
	ldr r1, =strTemp
	bl intasc32				@ Convert index to ascii
	bl putstring			@ Print index
	
	ldr r1, =strLast3		@ Last3 message
	bl putstring
	ldr r1, =str2Ptr		@ Load arguments (s2, "egg")
	ldr r2, =strArg5
	bl String_lastIndexOf_3 @ r0 = int index
	ldr r1, =strTemp
	bl intasc32				@ Convert index to ascii
	bl putstring			@ Print index
	
@ =================== String replace =================== 
	ldr r1, =strReplace		@ Replace message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1, 'a', 'o')
	mov r2, #'a'
	mov r3, #'o'
	bl String_replace		@ r0 = address of new string
	mov r1, r0				@ Move new string to r1
	bl putstring			@ Print string
	
@ ================= String toLowerCase ================= 
	ldr r1, =strLower		@ Lower message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1)
	bl String_toLowerCase	@ r0 = lowercase r1
	mov r1, r0				@ Move new string to r1
	bl putstring			@ Print string

@ ================= String toUpperCase ================= 
	ldr r1, =strUpper		@ Upper message
	bl putstring
	ldr r1, =str1Ptr		@ Load arguments (s1)
	bl String_toUpperCase	@ r0 = uppercase r1
	mov r1, r0				@ Move new string to r1
	bl putstring			@ Print string
	
@ =================== String concat =================== 
	ldr r1, =strConcat1		@ Concat message 1
	bl putstring
	
	ldr r1, =str1Ptr		@ Load arguments (s1, " ")
	ldr r2, =strSpace
	bl String_concat		@ r0 = s1 + " "
	
	ldr r1, =strConcat2		@ Concat message 2
	bl putstring
	
	mov r1, r0				@ Load arguments (s1, s2)
	ldr r2, =str2Ptr
	bl String_concat		@ r0 = s1 + " " + s2
	mov r1, r0				@ Move r0 into r1
	bl putstring
	
@ ===================== Program end ========================
	ldr r1, =cLF
	bl putch

	mov r0, #0				@ Terminate program
	mov r7, #1
	svc 0

@ ===============================================	
@ void Print_bool(int boolean)
@ ===============================================
@ 	Input:	r0 : int 0 or int 1 (boolean value)
@ 	Output: Prints "TRUE" if r0 = 1. Else prints "False"
@ ===============================================
	
Print_bool:
	push 	{r1,r4-r11, LR}
	
	cmp		r0, #1
	beq		true
	
	cmp		r0, #0
	beq		false
	
	b error
	
true:
	ldr r1, =strTrue		@ Display "TRUE"
	bl putstring
	
	b boolEnd

false:
	ldr r1, =strFalse		@ Display "FALSE"
	bl putstring
	
	b boolEnd
	
error:
	ldr r1, =strError		@ Error message
	bl putstring
	
boolEnd:
	pop		{r1,r4-r11, LR}
	bx lr

	.end
