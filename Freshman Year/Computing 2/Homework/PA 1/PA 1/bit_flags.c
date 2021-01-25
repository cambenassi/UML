/***********************************************************
Author: <Cameron Benassi>
Date: <3/5/2020>
Effort: <2 hours>
Purpose: <To combine all the topics from the previous homeowrks,
but to also incorperate them into functions, and access them
with a void pointer system>
Proposed Function: <In my data structure, I think that a next/prev
node system is missing. In my proposed function, I would create
a function that turnes various vector data types into a linked
list, so you can traverse a series of integers and access their
individual bits.>
***********************************************************/

#include <stdio.h>
#include "bit_flags.h"

struct vector
{
	int size;   
	int capacity; 
	int* data;
};

typedef struct vector vector;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	vector* pBit_flags = NULL;

	pBit_flags = (vector*)malloc(sizeof(vector));
	if (!pBit_flags)
		return NULL;
	pBit_flags->size = number_of_bits;
	pBit_flags->capacity = (number_of_bits / 32) + 1;
	pBit_flags->data = (int*)malloc(sizeof(int) * (32 * pBit_flags->capacity));
	if (!pBit_flags->data)
		return NULL;

	for (int i = 0; i < pBit_flags->capacity; i++)
		pBit_flags->data[i] = 0;

	return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_positon)
{
	vector* pBit_flags = (BIT_FLAGS*)hBit_flags;
	int count = 0;

	if (flag_positon > 31) {
		count = (flag_positon / 32) + 1;
		if (count > pBit_flags->capacity) {
			pBit_flags->data = (int*)realloc(pBit_flags->data, sizeof(int) * count);
			if (!pBit_flags) {
				free(pBit_flags->data);
				return FAILURE;
			}
			for (int i = pBit_flags->capacity; i < count; i++)
				pBit_flags->data[i] = 0;
			pBit_flags->capacity = count;
		}
		pBit_flags->size = flag_positon;
		pBit_flags->data[count - 1] = (1 << flag_positon % 32) | 0;

		return SUCCESS;
	}
	if (flag_positon > pBit_flags->size)
		pBit_flags->size = flag_positon;
	pBit_flags->data[count] = (1 << flag_positon % 32) | 0;

	return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	vector* pBit_flags = (BIT_FLAGS*)hBit_flags;
	int count = 0;

	if (flag_position > 31) {
		count = (flag_position / 32) + 1;
		if (count > pBit_flags->capacity) {
			pBit_flags->data = (int*)realloc(pBit_flags->data, sizeof(int) * count);
			if (!pBit_flags) {
				free(pBit_flags->data);
				return FAILURE;
			}
			for (int i = pBit_flags->capacity; i < count; i++)
				pBit_flags->data[i] = 0;
			pBit_flags->capacity = count;
		}
		pBit_flags->size = flag_position;
		pBit_flags->data[count - 1] &= ~(1 << flag_position);

		return SUCCESS;
	}
	if (flag_position > pBit_flags->size)
		pBit_flags->size = flag_position;
	pBit_flags->data[count] &= ~(1 << flag_position);

	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	vector* pBit_flags = (BIT_FLAGS)hBit_flags;
	int c;

	if (flag_position > pBit_flags->size)
		return -1;
	c = (pBit_flags->data[0] >> flag_position) & 1;
	
	return c;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	vector* pBit_flags = (BIT_FLAGS*)hBit_flags;

	return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	vector* pBit_flags = (BIT_FLAGS*)hBit_flags;

	return pBit_flags->capacity * 32;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	vector* pBit_flags = (BIT_FLAGS*)* phBit_flags;

	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}

void print_flags(BIT_FLAGS* hBit_flags) {
	vector* pBit_flags = (BIT_FLAGS)*hBit_flags;

	for (int i = 0; i < pBit_flags->size; i++) {
		if (bit_flags_check_flag(hBit_flags, i) == 1)
			printf("%d\n", i);
	}
}