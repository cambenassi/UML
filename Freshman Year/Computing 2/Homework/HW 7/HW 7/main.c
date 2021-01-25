/**********************************************************************
Program: <Parentheses Checker>
Author: <Cam Benassi>
Date: <3/27/2020>
Time spent: <2.5 hours>
Purpose: Use linked lists to implement a stack that checks the validity
		 of strings
***********************************************************************/

#include <stdio.h>
#include "stack.h"


int main(int arc, char* argv[]) {

	LINKEDLIST stack = ll_init();
	char input, kb;
	int fail = 0, numLoops, skipFinalTest;

	scanf_s("%d", &numLoops);
	while ((kb = getchar()) != '\n' && kb != EOF);

	for (int i = 0; i < numLoops; i++) {
		skipFinalTest = 0;
		do {
			scanf_s("%c", &input);
			
			if (input == '\n') {
				input = NULL;
				break;
			}
			
			if (input == '{' || input == '(' || input == '[') {
				stack_push(stack, input);
				//stack_print(stack);
			}
			if (input == '}' || input == ')' || input == ']') {
				fail = stack_check(stack, input);
				if (fail == 1) {
					break;
				}
			}

		} while (input != '\n');

		if (stack_empty_check(stack) == 1)
			if (stack_check(stack, '[') == 1 || stack_check(stack, '(') == 1 || stack_check(stack, '{') == 1) 
				fail = 1;
			
		if (fail == 0)
			printf("Yes\n");
		else if (fail == 1)
			printf("No\n");

		
		stack_clear(stack);
		LINKEDLIST stack = ll_init();
		while (input != '\n' && input != '\0')
			scanf_s("%c", &input);
		input = NULL;
		
	}
	
	stack_clear(stack);

	return 0;
}