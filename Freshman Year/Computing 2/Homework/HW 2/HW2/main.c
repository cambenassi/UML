/***********************************************************
Author: <Cameron Benassi>
Date: <1/27/2020>
Effort: <15 minutes>
Purpose: <The purpose of this assignment is to demonstrate how
left\right shift works and how moving a variable one bit can 
change it>
***********************************************************/

#include <stdio.h>

int main(int argc, char* argv[]) {

	unsigned int x = 1;
	
	for (int i = 0; x != 0; i++) {
		printf("%d: %u\n", i, x);
		x = x << 1;
	}
	
	return 0;
}