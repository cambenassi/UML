#include <stdio.h>

#include "bit_flags.h"
#include "status.h"

int main(int argc, char* argv[]) {

	BIT_FLAGS newBit = bit_flags_init_number_of_bits(35);
	bit_flags_set_flag(newBit, 0);
	bit_flags_set_flag(newBit, 12);
	print_flags(newBit);
	
	bit_flags_destroy(&newBit);

	return 0;
}
