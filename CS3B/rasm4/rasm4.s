/*  --- rasm4.s ---   */
/*  Garrett & Aaron Geesink  */
/*  CS3B 3 PM Class  */
/*  Tuesday/Thursday */

.data
	.equ 		SIZE, 512
	.equ 		MIN, 1
	.equ 		MAX, 7
	.equ 		MIN_CH, 'a'
	.equ 		MAX_CH, 'b'
	
	inBuffer:	.skip SIZE
	strBuffer:	.skip SIZE	@ Buffer used for user input

	@ Menu output
	menu1:			.asciz "                 RASM4 TEXT EDITOR\n"
	menu2:			.asciz "		Data Structure Memory Consumption: "
	bytes:			.asciz " bytes\n"
	menu3:			.asciz "		Number of Nodes: "
	menu4:			.asciz "\n <1> View all strings\n\n"
	menu5:			.asciz " <2> Add string\n" 
	menu6:			.asciz "	<a> from keyboard\n"
	menu7:			.asciz "	<b> from file (input.txt)\n\n"
	menu8:			.asciz " <3> Delete string\n\n"
	menu9:			.asciz " <4> Edit string\n\n"
	menu10:			.asciz " <5> Search string\n\n"
	menu11:			.asciz " <6> Save file (output.txt)\n\n"
	menu12:			.asciz " <7> Quit\n\n"
	
	strInvalidInput: .asciz "ERROR: input out of range\n"	@ Error when user enters invalid menu input
	strInputNum:		.asciz "Enter a number (1-7): "							@ Prompt for input
	strCharPrompt:	.asciz "Enter a character (a or b): "
	strInputPrompt:	.asciz "Enter a string to add to the list: "
	strPausePrompt:	.asciz "Press enter to continue... "				@ Prompt user for any key
	strInputConfirm:	.asciz "String added!\n\n"
	strFileConfirm:	.asciz "Strings added from "
	strIndex:	.asciz	"Enter an Index #: "						@ Prompt for user to enter a index #
	deleted:		.asciz "String deleted!"					@ Displays String has been deleted
	replaced:		.asciz "String replaced!"					@ Displays String has been replaced
	strReplace:	.asciz "Enter a string to replace old string: "		@ Prompt user to enter a string
	strSearch:	.asciz	"Enter a string to search for: "	@ Prompt user for string to search
	strOutputConfirm:	.asciz "List saved to file "				@ Confirm to the user that the list was saved
	strFileName:	.asciz "output.txt"									@ Name of the file to output the list to
	
	clearCmd:		.asciz "clear"			@ System call for c++ clear command
	inFile:			.asciz "input.txt"

	keyBuff:		.word 0
	stringList:		.word 0					@ Stores a pointer to the string list used to dynamically store all of the strings
	dataUsage:		.word 0					@ Address holding program data usage
	nodeUsage:		.word 0
	userIndex:		.word 0
	currentFileHandle:	.word 0
	
	userString:		.skip SIZE				@ User input
	pauseBuffer:	.skip SIZE				@ Buffer where user input goes when paused.
	memoryBytes:	.skip 12				@ Memory Consumption
	nodeBuffer:		.skip 12
	strInput:		.skip SIZE				@ String input by user
	inputInvalidMsg:	.asciz "INVALID NUMERIC STRING. RE-ENTER VALUE\n"	@ Invalid input messages
	inputOverflowMsg:	.asciz "OVERFLOW OCCURRED. RE-ENTER VALUE\n"

	cLF:			.byte 10
	
.text
	.global _start
	.extern malloc
	.extern free
	.extern system
	
_start:
@ ============ Construct the empty linked list ===================
	bl List

	ldr r4, =stringList		@ Store a pointer to the new list in the local static variable
	str r0, [r4]

menu:
@ ========= Clear the screen ============
		ldr r0, =clearCmd
		bl system
	
@ ========= Output menu screen ==============		
		ldr r1, =menu1
		bl putstring
		ldr r1, =menu2
		bl putstring

@ ======== Gets data consumption for menu output =======
		bl data_usage
		ldr r1, =memoryBytes
		bl intasc32

		ldr r1, =memoryBytes
		bl putstring

		ldr r1, =bytes
		bl  putstring
		
@ ============= Print Number of Nodes ==============
		ldr r1, =menu3
		bl putstring
		
		ldr r1, =nodeBuffer
		ldr r0, =nodeUsage
		ldr r0, [r0]
		bl intasc32
		bl putstring
@ ============ Continue with menu =================
		ldr r1, =menu4
		bl putstring
		ldr r1, =menu5
		bl putstring
		ldr r1, =menu6
		bl putstring
		ldr r1, =menu7
		bl putstring
		ldr r1, =menu8
		bl putstring
		ldr r1, =menu9
		bl putstring
		ldr r1, =menu10
		bl putstring
		ldr r1, =menu11
		bl putstring
		ldr r1, =menu12
		bl putstring
		
@ =================== Case control structure ===================
		mov r0, #MIN
		mov r1, #MAX
		ldr r2, =GetIntInput
		bl GetValueInRange
		mov r4, r0

@ ================== <7> Quit the program =====================
@ Quit the program if the user chooses 7
		cmp r4, #MAX
		beq rasm4EndInputNot7
		
@ ================== <1> View All Strings =====================
		cmp r4, #1
		beq rasm4DisplayList
		bal rasm4EndDisplayList

		rasm4DisplayList:		@ Display the list
			ldr r0, =stringList
			ldr r0, [r0]
			bl DisplayList
		rasm4EndDisplayList:

		cmp r4, #1						@ Branch out of the switch
		beq rasm4EndSwitch
		
@ ====================== <2> Add a String =======================
		cmp r4, #2
		beq rasm4AddToList
		bal rasm4EndAddToList

		rasm4AddToList:
			ldr r0, =stringList
			ldr r0, [r0]
			bl AddToList
		rasm4EndAddToList:

		cmp r4, #2							@ Branch out of the switch
		beq rasm4EndSwitch

@ ==================== <3> Delete String ========================
		cmp r4, #3
		beq rasm4DeleteFromList
		bal rasm4EndDeleteFromList

		rasm4DeleteFromList:
			ldr r1, =strIndex		@ Gets index # input from the user
			bl putstring

			ldr r1, =strBuffer
			mov r2, #SIZE
			bl getstring

			ldr r1, =strBuffer 			@ Converts input from ascii to int
			bl ascint32

			ldr r1, =userIndex
			str r0, [r1]
			
			ldr r0, =stringList			@ r0= string list, r1= index#
			ldr r0, [r0]
			ldr r1, =userIndex
			ldr r1, [r1]
			sub r1, #1					@ Aligns index for user
			bl  List_remove				@ Call List_remove to delete node from list

			ldr r1, =deleted
			bl putstring

			ldr r1, =cLF
			bl putch
			ldr r1, =cLF
			bl putch

		rasm4EndDeleteFromList:

		cmp r4, #3						@ Branch out of the switch
		beq rasm4EndSwitch
		
@ ====================== <4> Edit String =========================
		cmp r4, #4
		beq rasm4EditString
		bal rasm4EndEditString

		rasm4EditString:
			ldr r1, =strIndex	@ Gets index # input from the user
			bl putstring

			ldr r1, =strBuffer
			mov r2, #SIZE
			bl getstring

			ldr r1, =strBuffer		@ Converts input from ascii to int
			bl ascint32

			ldr r1, =userIndex
			str r0, [r1]

			ldr r1, =strReplace	@ Prompt user for the string to replace old string
			bl putstring

			ldr r1, =userString
			mov r2, #SIZE
			bl getstring

			mov r3, r0
			ldr r0, =stringList
			ldr r0, [r0]
			ldr r1, =userIndex
			ldr r1, [r1]
			sub r1, #1				@ Aligns index for user
			ldr r2, =userString
			bl List_setstr

			ldr r1, =replaced
			bl putstring

			ldr r1, =cLF
			bl putch
			ldr r1, =cLF
			bl putch

		rasm4EndEditString:

		cmp r4, #4					@ Branch out of the switch
		beq rasm4EndSwitch
		
@ =================== <5> String Search ==========================
			cmp r4, #5
			beq rasm4SearchString
			bal rasm4EndSearchString

			rasm4SearchString:
				ldr r1, =strSearch		@ Prompt user for the string
				bl putstring

				ldr r1, =userString
				mov r2, #SIZE
				bl getstring

				ldr r0, =stringList			@ receives a substring and displays all string with the substring in them
				ldr r0, [r0]
				ldr r1, =userString
				ldr r2, =String_containsIgnoreCase
				bl  List_printMatch

			rasm4EndSearchString:
			
			cmp r4, #5						@ Branch out of the switch
			beq rasm4EndSwitch
			
@ ======================== <6> Save File =========================
		cmp r4, #6
		beq rasm4SaveFile
		bal rasm4EndSaveFile

		rasm4SaveFile:
			ldr r0, =stringList				@ Output the list to the file
			ldr r0, [r0]
			ldr r1, =strFileName
			bl List_outputToFile

			ldr r1, =strOutputConfirm	@ Confirm to the user that the list was saved
			bl putstring
			ldr r1, =strFileName
			bl putstring

			ldr r1, =cLF					@ Put two endlines
			bl putch
			ldr r1, =cLF
			bl putch
		rasm4EndSaveFile:
		
@ ================== End Case control structure ==================
rasm4EndSwitch:

		ldr r1, =strPausePrompt			@ Put the pause prompt
		bl putstring

		ldr r1, =pauseBuffer			@ Get the pause input
		mov r2, #SIZE
		bl getstring
		
@ ======================== Menu Loop =============================
		b menu				@ Jump back to the menu
	
@ ========================== Program end =========================
@ End the program
rasm4EndInputNot7:

		ldr r0, =stringList		@ Destroy the list
		ldr r0, [r0]
		bl d_List
	
		mov r0, #0				@ Terminate program
		mov r7, #1
		svc 0

@ =================== data_usage function =================
@ Returns the amount of bytes of data used by the program into r0
@ =========================================================
data_usage:
		ldr r0, =dataUsage
		ldr r0, [r0]
		bx lr

@ ================= GetIntInput function ================
@ Prompts user for an integer value and puts it into r0
@ =======================================================
GetIntInput:
		push {r4-r8, r10-r12, lr}
		
		_inloop:
			ldr r1, =strInputNum	@ Output the input prompt
			bl putstring 
			
			ldr r1, =strInput		@ Get string input from the user
			mov r2, #SIZE
			bl getstring
			
			cmp r0, #0				@ Check to see if the user entered anything
			beq _inputsuccess
			
			ldr r1, =strInput		@ Convert the input to an integer
			bl ascint32
			
			bvs _inputoverflow		@ Input is too big if overflow flag is set
			cmpcs r0, #0			@ Input is invalid if r0 = 0 and carry flag is set
			beq _inputinvalid
			bal _inputsuccess		@ If we make it past the previous branches, branch to the end
			
		_inputinvalid:
			ldr r1, =inputInvalidMsg	@ Output invalid message
			bl putstring
			bal _inloop					@ Branch back to the input loop
			
		_inputoverflow:
			ldr r1, =inputOverflowMsg	@ Output overflow message
			bl putstring
			bal _inloop				@ Branch back to the input loop
			
		_inputsuccess:
			
			pop {r4-r8, r10-r12, pc}	@ Exit function

@ ================ GetValueInRange function =================
@ Returns a value into r0 between the range of [min, max]
@ ===========================================================
GetValueInRange:
		push {r4-r8, r10-r12, lr}

		mov r4, r0		@ Preserve arguments
		mov r5, r1
		mov r6, r2

		blx r6		@ Generate a value and store it in r7
		mov r7, r0
		
		mov r1, r7	@ Check to see if the integer input is a valid option
		mov r2, r4
		mov r3, r5
		bl inrange
		
		cmp r0, #0
		beq rasm4OutOfRange			@ If input out of range, loop again
		bal rasm4EndOutOfRange		@ If input in range, branch out of input loop

		rasm4OutOfRange:				@ If input is out of range, give user feedback
			ldr r1, =strInvalidInput
			bl putstring
			bal rasm4EndOutOfRange
		rasm4EndOutOfRange:

		mov r0, r7		@ Move the int input back into return register
		pop {r4-r8, r10-r12, pc}
	
@ =============== inrange function ===============
@ Returns 0 or 1 into r0 if the
@ number in r1 is within the range specified by r2 and r3
@ ================================================
inrange:
		cmp r1, r2		@ Branch to "out of range" label if num < min
		blt _outrange
		cmp r1, r3		@ Branch to "out of range" label if num > max
		bgt _outrange
		bal _inrange	@ If we make it to here, we know the number is in range
		
		_outrange:		@ Branch here if the number is out of range
			mov r0, #0
			bal _end
	 
		_inrange:		@ Branch here if the number is in range
			mov r0, #1
			
		_end:
			mov pc, lr	@ Branch back to the instruction specified by the link register
		
@ ================ void AddToList(r0 list) =================	
AddToList:
	push {r4-r8, r10-r12, lr}

	mov r4, r0					@ Preserve the pointer to the list

	mov r0, #MIN_CH				@ Get either an 'a' or a 'b'
	mov r1, #MAX_CH
	ldr r2, =getch
	bl GetValueInRange
	mov r5, r0					@ Store the value received
	
	cmp r5, #'a'			@ If option 'a' is input, get a string from the user
	bne endAddStrInput

	mov r0, r4				@ Call AddStringInput
	bl AddStringInput
	
endAddStrInput:
	cmp r5, #'a'				@ Branch out of switch
	beq addEndSwitchOption

	mov r0, r4				@ If 'b' is input, initialize list from file
	cmp r5, #'b'
	bleq AddStringsFromFile

addEndSwitchOption:

	pop {r4-r8, r10-r12, pc}
	
@ ===================== r0 getch() =========================
getch:
	push {r4-r8, r10-r12, lr}

	ldr r1, =strCharPrompt		@ Output a prompt
	bl putstring

	ldr r1, =keyBuff				@ Get a string
	mov r2, #SIZE
	bl getstring
	ldrb r0, [r1]					@ Return the first character in the string

	pop {r4-r8, r10-r12, pc}
	
@ ============ void AddStringInput(r0 list) =================
AddStringInput:
	push {r4-r8, r10-r12, lr}

	mov r4, r0				@ Store list pointer

	ldr r1, =strInputPrompt	@ Output a prompt
	bl putstring

	ldr r1, =inBuffer		@ Get a string
	mov r2, #SIZE
	bl getstring

	mov r0, r4				@ Add the string inputed by the user
	bl List_addstr

	ldr r1, =strInputConfirm	@ Output string added confirmation
	bl putstring

	pop {r4-r8, r10-r12, pc}
	
@ ============ void AddStringsFromFile(r0 list) ==============
AddStringsFromFile:
	push {r4-r8, r10-r12, lr}
	
	ldr r1, =inFile				@ Initialize the list from the file
	bl List_inputFromFile

	ldr r1, =strFileConfirm	@ Confirm that input succeeded to the user
	bl putstring
	ldr r1, =inFile
	bl putstring

	ldr r1, =cLF				@ Put two endlines
	bl putch
	ldr r1, =cLF
	bl putch

	pop {r4-r8, r10-r12, pc}
	
@ ========== void List_addstr(r0 list, r1 dataPtr) ============
List_addstr:
	push {r4-r8, r10-r12, lr}

	mov r4, r0			@ Preserve arguments in variable registers
	mov r5, r1

	mov r1, r5			@ Get the length of the string
	bl String_length_2
	mov r6, r0

	mov r0, r4			@ Add the data to the list, plus one
	mov r1, r5			@ to include null character
	add r2, r6, #1
	bl List_add

	pop {r4-r8, r10-r12, pc}
	
@ ========= void List_add(r0 list, r1 dataPtr, r2 dataLen) ========
List_add:
	push {r4-r8, r10-r12, lr}

	mov r4, r0		@ Preserve the list pointer in r4
	mov r5, r2

	mov r0, r1		@ Construct a node from the given data
	mov r1, r2
	bl Node

	ldr r3, [r4, #4]	@ Load r3 with the tail pointer

	cmp r3, #0
	beq firstNode		@ If the tail pointer is null, branch to first node case
	bal notFirstNode	@ If tail is not null, branch to not first node case

	firstNode:		@ If this is the first node,
		str r0, [r4]			@ both head and tail should point to it
		str r0, [r4, #4]
		bal ladd__end

	notFirstNode:		@ Branch here if this is not the first node 
		str r0, [r3, #4]		@ Store the pointer to the newly constructed node
								@ in the "next" word pointed to by the tail pointer
								
		str r0, [r4, #4]		@ Store the pointer to the newly constructed node
								@ in the "tail" word pointed to by the list pointer

	ladd__end:
		mov r0, r5				@ Increase data usage global var
		bl update_data_usage	@ by data length added

		pop {r4-r8, r10-r12, pc}

@ =========== r0 =node <constructor>(r0 dataPtr, r1 dataLen) =============
Node:
	push {r4-r8, r10-r12, lr}

	mov r4, r0			@ Preserve arguments in non-volatile registers
	mov r5, r1

	mov r0, #8			@ Allocate 8 bytes for the node - four for
	bl malloc			@ the data pointer and four for the next pointer
	mov r6, r0

	mov r0, r5			@ Allocate a data segment of the size of the data
	bl malloc
	mov r7, r0

	mov r1, r4			@ Copy the data given into the new
	mov r2, r0			@ data allocated
	mov r3, r5
	bl memcpy

	mov r8, #0			@ Move zero into eight - this will be the nodes next pointer

	str r7, [r6]		@ Store the data pointer in the first word of r6,
	str r8, [r6, #4]	@ then store null in the second word

	mov r0, #8			@ Increase data usage by 8
	bl update_data_usage

	ldr r0, =nodeUsage	@ Add 1 to Number of nodes
	ldr r0, [r0]
	
	add r0, #1
	
	ldr r1, =nodeUsage
	str r0, [r1]
	
	mov r0, r6			@ Move the node pointer r6 into r0 and return

	pop {r4-r8, r10-r12, pc}
	
@ ======= void memcpy(r1 source, r2 destination, r3 bytes) =========
@ Copy the source byte-for-byte into the destination
@ ==================================================================
memcpy:
	byteNotZero:
		cmp r3, #0			@ If number of bytes to copy is currently zero, branch to end
		ble memEnd
		ldrb r0, [r1], #1	@ Load the byte at r1 into r0,
		strb r0, [r2], #1	@ then store r0 into the byte at r2
		sub r3, r3, #1		@ Decrement r3
		bal byteNotZero
	memEnd:
		bx lr

@ ================== update_data_usage function ====================		
update_data_usage:
	push {r4}
	
	mov r4, r0

	ldr r0, =dataUsage
	ldr r0, [r0]

	add r0, r0, r4
	
	ldr r1, =dataUsage
	str r0, [r1]

	pop {r4}
	bx lr
	
@ ============== void List_inputFromFile(r0 list, r1 fileName) =================
List_inputFromFile:
	push {r4-r8, r10-r12, lr}

	mov r4, r0		@ Preserve passed arguments
	mov r5, r1

	mov r1, r5		@ Open the file as read-only
	mov r2, #0
	bl open_file
	mov r6, r0

	notFileEOF:
		mov r0, r6		@ Read the next line in the file
		bl read_line
		mov r7, r1
		mov r8, r2

		cmp r7, #0		@ Check to see if the function returned null character
		beq endNotFileEOF

		mov r0, r4		@ Add the line recieved as a null-terminated string
		mov r1, r7
		bl List_addstr

		cmp r8, #0		@ Check end of file flag
		beq notFileEOF 

	endNotFileEOF:
		

	mov r0, r6			@ Close the file
	bl close_file

	pop {r4-r8, r10-r12, pc}
	
@ ============= void <destructor>(r0 list) ===============
d_List:
	push {r4-r8, r10-r12, lr}

	mov r4, r0		@ Preserve the arguments in non-volatile registers
	
	mov r5, #0		@ Use r5 as the "previous" node pointer
	ldr r6, [r4]	@ Use r5 as the "current" pointer, starting at the head

	currentNotNull:
		cmp r6, #0		@ Compare the current node with null
		beq dlEnd
	 
		mov r5, r6			@ Update previous to current,
		ldr r6, [r6, #4]	@ update current to the node after it
		
		mov r0, r5			@ Delete the previous node
		bl d_Node

		bal currentNotNull		@ Branch back to loop

	dlEnd:
		pop {r4-r8, r10-r12, pc}
	
@ =========== void <destructor>(r0 node) ==============
d_Node:
	push {r4, lr}

	mov r4, r0

	ldr r0, [r4]		@ Free the memory pointed to by the nodes data pointer
	bl free

	mov r0, r4			@ Free the memory used to hold the data pointer and next pointer
	bl free

	mov r0, #-8			@ Reduce data usage by 8
	bl update_data_usage
	
	ldr r0, =nodeUsage	@ Subtract 1 to Number of nodes
	ldr r0, [r0]
	
	sub r0, #1
	
	ldr r1, =nodeUsage
	str r0, [r1]

	pop {r4, pc}
	
@ =========== r0 =list <constructor>() ====================
List:
	push {r4-r8, r10-r12, lr}

	mov r0, #8			@ Increase data usage by 8
	bl update_data_usage

	mov r0, #8			@ Allocate eight bytes - four for "head"
	bl malloc			@ and four for "tail"
	
	mov r1, #0
	str r1, [r0]		@ Store null pointer in "head" data word
	str r1, [r0, #4]	@ Store null pointer in "tail" data word

	pop {r4-r8, r10-r12, pc}
	
@ ======== void List_remove(r0 list, r1 index) ==========
List_remove:
	push {r4-r8, r10-r12, lr}

	mov r4, r0			@ Preserve argument registers
	mov r5, r1

	bl List_getNodePair	@ Get the node to delete in r1 and the node before it in r0

	cmp r0, #0			@ Check the previous pointer and branch
	beq previousNull

								@ If previous node is not null, make previous point
	ldr r2, [r1, #4]			@ to the node after current
	str r2, [r0, #4]
	bal endPreviousNotNull

previousNull:						@ If the previous node is null, update the head of the 
		ldr r2, [r1, #4]			@ list to the node after the node to delete
		str r2, [r4]

endPreviousNotNull:

	ldr r2, [r4, #4]		@ If the current node is not the tail node,
	cmp r1, r2				@ branch past the if statement
	bne endCurrentIsTail

								@ If current node is the tail node,
		str r0, [r4, #4]		@ update the tail to point to previous node
endCurrentIsTail:

	mov r0, r1		@ Destroy the current node
	bl d_Node

	pop {r4-r8, r10-r12, pc}
	
@ ===== r0 =prevNode, r1 =currentNode List_getNodePair(r0 list, r1 index) =====
List_getNodePair:
	push {r4-r8, r10-r12, lr}

	cmp r1, #0				@ Branch to fail case if index is less than zero
	blt gnpError

	mov r2, #0				@ Use r2 as a pointer to the previous node

	ldr r3, [r0]			@ Use r3 as a pointer to the current node
							@ Start at the lists head pointer
							
	indexNotZero_CurrentNotNull:
		cmp r3, #0				@ If the current node pointer is null,
		beq gnpError	@ branch to fail case

		cmp r1, #0				@ Branch to found case if 
		ble gnpFound	@ current index is zero

		mov r2, r3				@ Update previous with current pointer
		ldr r3, [r3, #4]		@ Load the current node pointer 
								@ with its own "next" pointer
		sub r1, r1, #1			@ Decrement the index

		@ Branch back to loop start
		bal indexNotZero_CurrentNotNull

	gnpError:		@ In the failure case, return null pointer
		mov r0, #0
		mov r1, #0
		bal gnpEnd

	gnpFound:		@ In the correct case, return r2 as the previous node
		mov r0, r2			@ and return r1 as the current node
		mov r1, r3

	gnpEnd:
		pop {r4-r8, r10-r12, pc}

@ ==== void List_set(r0 list, r1 index, r2 dataPtr, r3 dataLen) =====
List_set:
	push {r4-r8, r10-r12, lr}
	
	mov r4, r0				@ Preserve values of argument registers
	mov r5, r1
	mov r6, r2
	mov r7, r3

	bl List_getNodePair		@ Get the node pair at the given index

	cmp r1, #0			@ Branch to end if current is null
	beq lSetEnd

	lsCurrentNotNull:
		mov r8, r1		@ Store current node

		mov r0, r7		@ Allocate a data segment of the size of the data
		bl malloc
		mov r10, r0

		mov r1, r6		@ Copy the data given into the new
		mov r2, r10		@ data allocated
		mov r3, r7
		bl memcpy
		
		ldr r0, [r8]	@ Free the data pointed to by the node to change
		bl free

		str r10, [r8]	@ Store the new pointer in the data pointer
						@ of the current node
	lSetEnd:
		pop {r4-r8, r10-r12, pc}

@ ====== void List_setstr(r0 list, r1 index, r2 str) ======
List_setstr:
	push {r4-r8, r10-r12, lr}

	mov r4, r0			@ Preserve arguments in variable registers
	mov r5, r1
	mov r6, r2

	mov r1, r6			@ Get the length of the string
	bl String_length_2
	mov r7, r0

	mov r0, r4			@ Set the data in the node,
	mov r1, r5			@ plus one for the null terminator
	mov r2, r6
	add r3, r7, #1
	bl List_set

	pop {r4-r8, r10-r12, pc}	
	
@ ===== void List_printMatch(r0 list, r1 dataPtr, r2 comparerRoutine) =====
List_printMatch:
	push {lr}

	ldr r3, =printStringAndEndl	 @ Print string and endline for each match by the comparer routine
	bl List_foreachMatch

	pop {pc}
	
@ ==== void List_foreachMatch(r0 list, r1 dataPtr, r2 comparerRoutine, r3 actionRoutine) ====
List_foreachMatch:
	push {r4-r8, r10-r12, lr}

	mov r4, r0			@ Preserve the arguments in non-volatile registers
	mov r5, r1
	mov r7, r2
	mov r8, r3
	
	ldr r10, [r4]		@ Use r6 as the "current" pointer, starting at the head

	lFEMCurrentNotNull:
		cmp r10, #0		@ Compare the current node with null
		beq lFEMEnd
	
		ldr r1, [r10]	@ Branch to the routine that compares the data
		mov r2, r5		@ in the current pointer with the pointer given
		blx r7

		cmp r0, #0			@ Do the action if r0 is true,
		beq lFEMSkip	@ otherwise skip the action

		lFEMAction:		@ Load r1 with the data pointer of the current node
			ldr r1, [r10]				@ and branch to the action routine	
			blx r8
		lFEMSkip:

		ldr r10, [r10, #4]				@ Load current node pointer with its own next pointer
		bal lFEMCurrentNotNull

	lFEMEnd:
		pop {r4-r8, r10-r12, pc}
		
@ ======= void printStringAndEndl(r1 str) ========
printStringAndEndl:
	push {lr}

	bl putstring		@ Display string specified

	ldr r1, =cLF		@ Put an endline
	bl putch

	pop {pc}

@ =====  void List_outputToFile(r0 list, r1 fileName) =====
List_outputToFile:
	push {r4-r8, r10-r12, lr}

	mov r4, r0			@ Preserve arguments passed in
	mov r5, r1

	mov r1, r5			@ Open file - write only, create if it doesnt exist,
	mov r2, #01101		@ truncate if it does exist
	bl open_file
	mov r6, r0

	ldr r0, =currentFileHandle	@ Store the current file handle in the static variable
	str r6, [r0]

	mov r0, r4							@ Call the foreach method, saving each string to the file
	ldr r1, =List_saveStringAndEndline	@ in the static variable
	bl List_foreach

	ldr r0, =currentFileHandle			@ Close the file
	ldr r0, [r0]
	bl close_file

	pop {r4-r8, r10-r12, pc}

@ ====  void List_saveStringAndEndline(r1 cstring) ====
List_saveStringAndEndline:
	push {r4-r8, r10-r12, lr}

	ldr r0, =currentFileHandle		@ Store the string passed into the current file
	ldr r0, [r0]
	bl write_to_file

	ldr r0, =currentFileHandle		@ Put a carriage return
	ldr r0, [r0]
	ldr r1, =cLF
	mov r2, #1
	mov r7, #4
	svc 0

	pop {r4-r8, r10-r12, pc}

@ ====== void List_foreach(r0 list, r1 actionRoutine) =======
List_foreach:
	push {r4-r8, r10-r12, lr}

	mov r4, r0		@ Preserve the arguments in non-volatile registers
	mov r5, r1
	
	ldr r6, [r4]	@ Use r6 as the "current" pointer, starting at the head

	LFECurrentNotNull:
		cmp r6, #0			@ Compare the current node with null
		beq lforeach__end
	
		ldr r1, [r6]			@ Load r1 with the data pointer of the current node
		blx r5					@ and branch to the action routine

		ldr r6, [r6, #4]		@ Load current node pointer with its own next pointer
		bal LFECurrentNotNull

	lforeach__end:
		pop {r4-r8, r10-r12, pc}

	.end				@ End of Program

		
	
	

