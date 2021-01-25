/***********************************************************
Author: <Cameron Benassi>
Date: <2/20/20>
Effort: <30 mins>
Purpose: <To swap bits of an integer stored in an array>
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);

void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[]) {
	unsigned int flag_holder[5] = { 0 };
	char temp;

	scanf_s("%c", &temp);

	set_flag(flag_holder, 0);

	display_flags(flag_holder, 1);
	//display_flags(flag_holder, );

	return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position) {
	int count = 0;
	
	while (flag_position > 31) {
		flag_position -= 32;
		count++;
	}
	
	flag_holder[count] = (1 << flag_position) | flag_holder[count];
}

void unset_flag(unsigned int flag_holder[], int flag_position) {
	int count = 0;

	while (flag_position > 31) {
		flag_position -= 32;
		count++;
	}

	flag_holder[count] &= ~(1 << flag_position);
}

int check_flag(unsigned int flag_holder[], int flag_position) {
	int count = 0;

	while (flag_position > 31) {
		flag_position -= 32;
		count++;
	}

	int c = (flag_holder[count] >> flag_position) & 1;
	return c;
}

void display_32_flags_as_array(unsigned int flag_holder) {
	int count = 0;

	for (int i = 0; i <= 31; i++) {
		printf("%u", check_flag(&flag_holder, i));
		count++;
		if (count == 4) {
			printf(" ");
			count = 0;
		}
	}
	printf("\n");
}

void display_flags(unsigned int flag_holder[], int size){
	for (int i = 0; i < size; i++)
		display_32_flags_as_array(flag_holder[i]);
}
