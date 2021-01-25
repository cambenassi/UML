#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"

typedef void* BIT_FLAGS;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_positon);
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);
void bit_flags_destroy(BIT_FLAGS* phBit_flags);
void bit_flags_print(BIT_FLAGS* hBit_flags);
#endif