/***********************************************************
Author: <Cameron Benassi>
Date: <3/20/20>
Effort: <15 mins>
Purpose: <to write a function that reverses a linked list>
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare function here
void reverse(Node** head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i; 
	Node* temp;

	//set up a test list with values 9->8->7->6->5->4->3->2->1->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}
	//call your function to reverse the list (should work for any list given the head
	reverse(&head);
	//print the reversed list
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//define your function here
void reverse(Node** head) {
	Node* current = *head, * next = NULL, *prev = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}