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

#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"

typedef void* BIT_FLAGS;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_positon);
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);
int bit_flags_get_size(BIT_FLAGS hBit_flags);
int bit_flags_get_capacity(BIT_FLAGS hBit_flags);
void bit_flags_destroy(BIT_FLAGS* phBit_flags);
void print_flags(BIT_FLAGS* hBit_flags);
#endif