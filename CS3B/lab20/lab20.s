/*	lab20.s 
	Programmed by: Aaron Geesink
	Barnett CS3B 3PM Class */

.data		
					.equ		SIZE, 1024
		
	keyBuffer:		.skip SIZE
	headPtr:		.word 0		@ head of linked list
	tailPtr:		.word 0		@ tail of linked list
	
	newNodePtr:		.word 0		@ pointer to create new node
								@ first 4 bytes point to new string address
								@ last 4 bytes point to next node
	newItemPtr:		.word 0		@ pointer to the new item
	
	szMsg1:			.asciz "Please enter string 1: "
	szMsg2:			.asciz "Please enter string 2: "
	szMsg3:			.asciz "\nHere is the contents of the List:\n"
	cLF:			.byte 10
	
.text
	.global 	_start			@ provide program start address to the linker
	.extern		malloc			@ external malloc macro
	.extern		free

_start:

@ =========== user input for string 1 ===========
	ldr 	r1, =szMsg1			@ r1 = &szMsg1
	bl		putstring			@ display message to prompt user input
	
	ldr		r1, =keyBuffer		@ r1 = &keyBuffer
	ldr 	r2, =SIZE			@ r2 = 4 bytes
	bl		getstring			@ get string one and put it into memory
	
	bl		String_Length		@ r0 = length of string 1
	mov		r3, r0
	
	push	{r1, r2, r3}
	bl		malloc				@ allocate memory for the string
	pop		{r1, r2, r3}
	ldr		r4, =newItemPtr		@ r3 = &newItemPtr
	str		r0, [r4]			@ newItemPtr -> newly allocated string memory

@ Copy from keyBuffer into *newItemPtr
	@ldr		r4, [r3]			@ r4 = beginning address of allocated memory
loop1:
	cmp		r3, #0				@ base case: r3 = 0
	beq		endloop1			@ end loop if r3 = 0
	ldrb	r4, [r1], #1		@ put 1 character of string 1 into r4, keyBuffer++
	strb	r4, [r0], #1		@ store the character into newItemPtr, newItemPtr++
	sub		r3, #1				@ r5 = r5 - 1
	b 		loop1				@ loop until all string chars are put into newItemPtr
endloop1:

	mov		r4, #0
	strb	r4, [r0]			@ hard code the null character into the string
	
@ Print string 1 from newItemPtr
	ldr		r1, =newItemPtr
	ldr		r1, [r1]
	bl		putstring			@ print the allocated string
	ldr		r1, =cLF
	bl		putch				@ print '\n'
	
@ Create the new node
	mov		r0, #8				@ nodeType struct, 8 bytes
	bl		malloc
	
	ldr		r1, =newNodePtr		
	str		r0, [r1]			@ newNodePtr -> 8 byte struct
	
@ Store the new items address into the new node
	ldr		r3, =newItemPtr
	ldr		r3, [r3]			@ r3 = &new string memory
	str		r3, [r0], #4		@ newNode.data = &new string memory
	mov		r3, #0				@ r3 = null
	str		r3, [r0]			@ newNode.next = null
	
@ print the string from newNodePtr to confirm it is in the node
	ldr		r1, =szMsg3
	bl		putstring			@ print message for node output

	ldr		r1, =newNodePtr
	ldr		r1, [r1]
	ldr		r1, [r1]
	bl		putstring			@ print new string from inside the node
	
	ldr		r1, =cLF
	bl		putch				@ print '\n'
	
	ldr		r1, =cLF
	bl		putch				@ print '\n'
	
@ =========== user input for string 2 ===========
	ldr 	r1, =szMsg2			@ r1 = &szMsg2
	bl		putstring			@ display message to prompt user input
	
	ldr		r1, =keyBuffer		@ r1 = &keyBuffer
	ldr 	r2, =SIZE			@ r2 = 4 bytes
	bl		getstring			@ get string one and put it into memory
	
	bl		String_Length		@ r0 = length of string 1
	mov		r3, r0
	
	push	{r1, r2, r3}
	bl		malloc				@ allocate memory for the string
	pop		{r1, r2, r3}
	ldr		r4, =newItemPtr		@ r3 = &newItemPtr
	str		r0, [r4]			@ newItemPtr -> newly allocated string memory

@ Copy from keyBuffer into *newItemPtr
	@ldr		r4, [r3]			@ r4 = beginning address of allocated memory
loop2:
	cmp		r3, #0				@ base case: r3 = 0
	beq		endloop2			@ end loop if r3 = 0
	ldrb	r4, [r1], #1		@ put 1 character of string 1 into r4, keyBuffer++
	strb	r4, [r0], #1		@ store the character into newItemPtr, newItemPtr++
	sub		r3, #1				@ r5 = r5 - 1
	b 		loop2				@ loop until all string chars are put into newItemPtr
endloop2:

	mov		r4, #0
	strb	r4, [r0]			@ hard code the null character into the string
	
@ Print string 2 from newItemPtr
	ldr		r1, =newItemPtr
	ldr		r1, [r1]
	bl		putstring			@ print the allocated string
	ldr		r1, =cLF
	bl		putch				@ print '\n'
	
@ Create the new node
	mov		r0, #8				@ nodeType struct, 8 bytes
	bl		malloc
	
	push 	{r0}
	
	@ldr		r1, =newNodePtr		
	@str		r0, [r1]			@ newNodePtr -> 8 byte struct
	
@ Store the new items address into the new node
	ldr		r3, =newItemPtr
	ldr		r3, [r3]			@ r3 = &new string memory
	str		r3, [r0], #4		@ newNode.data = &new string memory
	mov		r3, #0				@ r3 = null
	str		r3, [r0]			@ newNode.next = null
	
@ connect node 1 with node 2
	pop 	{r0}				@ r0 = ptr to second node
	
	ldr 	r1, =newNodePtr		@ r1 = ptr to first node
	ldr		r1,	[r1]			@ r1 = node1.dataPtr
	add		r1, #4				@ r1 = node1.nextPtr
	@ldr		r0, [r0]			@ r0 = first adress of second node
	
	str		r0, [r1]			@ node1.nextPtr -> first address of second node
	
@ print the two strings from newNodePtr to confirm they are linked together
	ldr		r1, =szMsg3
	bl		putstring			@ print message for node output

	ldr		r1, =newNodePtr
	ldr		r1, [r1]			@ r1 = node1.dataPtr
	push 	{r1}
	ldr		r1, [r1]			@ r1 = node1 data
	bl		putstring			@ print string 1 from inside the node
	
	pop 	{r1}				@ r1 = node1.dataPtr
	add		r1, #4				@ r1 = node1.nextPtr
	ldr		r1, [r1]			@ r1 = node2.dataPtr
	ldr		r1, [r1]			@ r1 = node2 data
	bl		putstring			@ print string 2 from inside the node
	
	ldr		r1, =cLF
	bl		putch				@ print '\n'
	
@ Service command to terminate the program successfully
	mov 	r0, #0
	mov 	r7, #1
	svc 	0

@End of Program
	.end
