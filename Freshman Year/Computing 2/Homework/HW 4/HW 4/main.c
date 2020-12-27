/***********************************************************
Author: <Cam Benassi>
Date: <2/13/2020>
Effort: <15 mins>
Purpose: <To demonstrate how to flip a singular bit in a number>
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[]) {
	unsigned int flag_holder = 0;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	display_32_flags(flag_holder);

	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);

	display_32_flags(flag_holder);
	
	return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position) {
	*flag_holder = (1 << flag_position) | *flag_holder;
}

int check_flag(unsigned int flag_holder, int flag_position) {
	int c = (flag_holder >> flag_position) & 1;
	return c;
}

void display_32_flags(unsigned int flag_holder) {
	for (int i = 31; i >= 0; i--) {
		printf("%u", check_flag(flag_holder, i));
		if (i % 4 == 0)
			printf(" ");
	}
	printf("\n");
}

void unset_flag(unsigned int* flag_holder, int flag_position) {
	*flag_holder &= ~(1 << flag_position);

}

