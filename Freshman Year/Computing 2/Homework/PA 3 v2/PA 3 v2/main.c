/***********************************************************
Author: <Cam Benassi>
Date: <April 24th, 2020>
Effort: <3 hours>
Purpose: <In order to store up to 2,000,000,000 integers, this
program flips the bits of an integer to process data, so each
integer in an array can account 32 numbers instead of just one>
***********************************************************/

#include <stdio.h>
#include "bit_flags.h"
#include "status.h"

int main(int argc, char* argv[]) {
	BIT_FLAGS newBit = bit_flags_init_number_of_bits(0);
	int input;

	scanf("%d", &input);

	while (input != -1) {
		bit_flags_set_flag(newBit, input);
		scanf("%d", &input);
	}

	bit_flags_print(newBit);

	bit_flags_destroy(&newBit);

	return 0;
}
