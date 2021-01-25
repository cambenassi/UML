#include <stdio.h>
#include <stdlib.h>
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
	pBit_flags->capacity = 160;
	pBit_flags->data = (int*)malloc(sizeof(int) * 5);
	if (!pBit_flags->data)
		return NULL;

	for (int i = 0; i < 5; i++)
		pBit_flags->data[i] = 0;

	return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_positon)
{
	vector* pBit_flags = (BIT_FLAGS*)hBit_flags;
	int i =  flag_positon / 32;
	int position = flag_positon % 32;
	int newCapacity;
	unsigned int flag = 1;
	int* pTemp;
	
	while (flag_positon > pBit_flags->capacity) {
		newCapacity = (pBit_flags->capacity / 32) * 2;
		pTemp = (int*)realloc(pBit_flags->data, sizeof(int) * newCapacity);
		if (!pBit_flags->data)
			return FAILURE;
		pBit_flags->data = pTemp;
		for (int j = pBit_flags->capacity / 32; j < (pBit_flags->capacity  / 32) * 2; j++)
			pBit_flags->data[j] = 0;
		pBit_flags->capacity = pBit_flags->capacity * 2;
	}

	flag = flag << position;
	pBit_flags->data[i] = pBit_flags->data[i] | flag;

	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	vector* pBit_flags = (BIT_FLAGS)hBit_flags;
	
	int i = flag_position / 32;
	int position = flag_position % 32;

	unsigned int flag = 1;

	flag = flag << position;

	if (pBit_flags->data[i] & flag)
		return 1;
	else
		return -1;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	vector* pBit_flags = (BIT_FLAGS*)*phBit_flags;

	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}

void bit_flags_print(BIT_FLAGS* hBit_flags) {
	vector* pBit_flags = (BIT_FLAGS*)hBit_flags;

	for (int i = 0; i < pBit_flags->capacity; i++) {
		if (bit_flags_check_flag(hBit_flags, i) == 1)
			printf("%d\n", i);
	}
}