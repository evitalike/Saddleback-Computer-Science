.global DeleteFromList

.data
indexPrompt:		.asciz "Enter an index in the list to delete: "
listEmptyPrompt:	.asciz "You cannot delete from the list because the list is empty!\n\n"


@ ======= void DeleteFromList(r0 list) =====
@ Get user input of an index in the list to delete
@ and delete the element at that index
@ =========================================

.text
.balign 4
DeleteFromList:
	push {r4-r8, r10-r12, lr}

	mov r4, r0		@ Store pointer to list

	bl List_length	@ Get the length of the list
	mov r5, r0

	cmp r5, #0		@ Branch if list is empty
	beq dListEmpty

	dListNotEmpty:
		bl GetIntInput

	dListEmpty:		@ If list is emtpy, output list is empty prompt
		ldr r1, =listEmptyPrompt
		bl putstring
	dEndListNotEmpty:

	pop {r4-r8, r10-r12, pc}
	
