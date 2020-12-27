#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
	Node* pNode = pStack->head, *pTemp;

	while (pNode != NULL) {
		pTemp = pNode;
		pNode = pNode->next;
		free(pTemp);
	}

	free(pStack);
	*hStack = NULL;
}

void clear_kb() {
	while(getchar() != '\n');
}