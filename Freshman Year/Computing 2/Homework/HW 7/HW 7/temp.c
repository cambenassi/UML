/**********************************************************************
Program: <name of program>
Author: <your name>
Date: <date you finish the program>
Time spent: <total amount of time spent on the project>
Purpose: The purpose of this program is to ...
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	char data;
	Node* next;
};

struct linkedlist
{
	Node* head;
};


typedef struct linkedlist linkedlist;
typedef void* LINKEDLIST;

LINKEDLIST ll_init(void);

void stack_push(LINKEDLIST linkedlist, char input);

void stack_pop(LINKEDLIST linkedlist);

int stack_check(LINKEDLIST linkedlist, char input);

void stack_print(LINKEDLIST linkedlist);

int stack_empty_check(LINKEDLIST hStack);

void stack_clear(LINKEDLIST* hStack);

void clear_kb();

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

LINKEDLIST ll_init(void) {

	linkedlist* stack = (linkedlist*)calloc(1, sizeof(linkedlist));
	return stack;
}

void stack_push(LINKEDLIST hStack, char input) {

	linkedlist* pStack = (linkedlist*)hStack;
	Node* temp_node = pStack->head;

	Node* pNode = (Node*)malloc(sizeof(Node));
	if (pNode) {
		pNode->data = input;
		pNode->next = NULL;
	}

	if (temp_node == NULL) {
		pStack->head = pNode;
		return;
	}

	pNode->next = pStack->head;
	pStack->head = pNode;

}

void stack_print(LINKEDLIST hStack) {

	linkedlist* pStack = (linkedlist*)hStack;
	Node* pNode = pStack->head;

	while (pNode) {
		printf("%c", pNode->data);
		pNode = pNode->next;
	}
	printf("\n");
}

int stack_check(LINKEDLIST hStack, char input) {

	linkedlist* pStack = (linkedlist*)hStack;
	Node* temp = NULL;
	temp = pStack->head;

	if (temp == NULL) {
		return 1;
	}

	if (temp->data == '{') {
		//printf("checking: %c to match with %c\n", temp->data, input);
		if (input == '}') {
			stack_pop(pStack);
			return 0;
		}
		//printf("No\n");
		return 1;
	}
	if (temp->data == '(') {
		//printf("checking: %c to match with %c\n", temp->data, input);
		if (input == ')') {
			stack_pop(pStack);
			return 0;
		}
		//printf("No\n");
		return 1;
	}
	if (temp->data == '[') {
		//printf("checking: %c to match with %c\n", temp->data, input);
		if (input == ']') {
			stack_pop(pStack);
			return 0;
		}
		//printf("No\n");
		return 1;
	}

	return 0;
}

void stack_pop(LINKEDLIST hStack) {

	linkedlist* pStack = (linkedlist*)hStack;
	Node* pNode = pStack->head;

	//printf("popping %c\n", pNode->data);
	pStack->head = pNode->next;

	free(pNode);

}

int stack_empty_check(LINKEDLIST hStack) {

	linkedlist* pStack = (linkedlist*)hStack;

	if (!pStack->head) {
		return 0;
	}
	else
		return 1;
}

void stack_clear(LINKEDLIST* hStack) {

	linkedlist* pStack = (linkedlist*)hStack;
	Node* pNode = pStack->head, * pTemp;

	while (pNode != NULL) {
		pTemp = pNode;
		pNode = pNode->next;
		free(pTemp);
	}

	free(pStack);
	*hStack = NULL;
}

void clear_kb() {
	while (getchar() != '\n');
}