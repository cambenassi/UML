#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int r, c, ** array;

	array = (int**)malloc(30 * sizeof(int**));
	if (!array)
		return 1;

	for (r = 0; r < 30; r++) {
		array[r] = (int*)malloc(20 * sizeof(int*));
		if (!array[r])
			return 2;
		for (c = 0; c < 20; c++)
			array[r][c] = r + c;
	}

	printf("Hello world! I have created a dynamic 2D-array of 20x30 integers!\n");
	for (c = 0; c < 20; c++) {
		for (r = 0; r < 30; r++)
			printf("%3d", array[r][c]);
		printf("\n");
	}

	return 0;
}