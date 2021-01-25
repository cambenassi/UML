#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct node {
	int value;
	int priority;
}typedef Node;

struct Priority_queue
{
	int size;
	int capacity;
	Node** data;
}typedef priority_queue;


PRIORITY_QUEUE priority_queue_init_default(void)
{
	priority_queue* pQueue;

	pQueue = (priority_queue*)malloc(sizeof(priority_queue));
	if (pQueue != NULL) {
		pQueue->size = 0;
		pQueue->capacity = 1;
		pQueue->data = (Node**)malloc(sizeof(Node*) * pQueue->capacity);
		if (pQueue->data == NULL){
			free(pQueue);
			return NULL;
		}
		for (int i = 0; i < pQueue->capacity; i++)
		{
			pQueue->data[i] = NULL;
		}
	}
	return (PRIORITY_QUEUE)pQueue;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	priority_queue* pQueue = (priority_queue*)*phQueue;
	int i;

	for (i = 0; i < pQueue->size; i++) {
		if(pQueue->data[i] != NULL)
			free(pQueue->data[i]);
	}
	
	free(pQueue->data);
	free(pQueue);
	*phQueue = NULL;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	priority_queue* pQueue = (priority_queue*)hQueue;
	Node* pTemp;
	int i, parent, current;

	if (pQueue->size >= pQueue->capacity) {
		Node** ppTemp;
		ppTemp = (Node**)malloc(sizeof(Node*) * (pQueue->capacity * 2));
		if (ppTemp == NULL) {
			free(ppTemp);
			return FAILURE;
		}
		for (i = 0; i < pQueue->capacity * 2; i++) {
			ppTemp[i] = pQueue->data[i];
		}
		pQueue->capacity *= 2;
		free(pQueue->data);
		pQueue->data = ppTemp;
	}

	pTemp = (Node*)malloc(sizeof(Node));

	if (pTemp != NULL) {
		(pQueue->data[pQueue->size]) = pTemp;
	}

	pQueue->data[pQueue->size]->value = data_item;
	pQueue->data[pQueue->size]->priority = priority_level;
	
	parent = (pQueue->size - 1) / 2;
	current = pQueue->size;

	while (parent >= 0 && pQueue->data[parent]->priority < pQueue->data[current]->priority) {
		Node* temp = pQueue->data[current];
		pQueue->data[current] = pQueue->data[parent];
		pQueue->data[parent] = temp;

		current = parent;
		parent = (current - 1) / 2;
	}

	pQueue->size++;

	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	priority_queue* pQueue = (priority_queue*)hQueue;
	Node* temp;
	int parent, child1, child2;

	temp = pQueue->data[0];

	pQueue->data[0] = pQueue->data[pQueue->size - 1];
	pQueue->data[pQueue->size - 1] = NULL;

	pQueue->size--;

	parent = 0;
	child1 = 1;
	child2 = 2;


	if (pQueue->data[child1] != NULL && pQueue->data[child2] != NULL) {
		while ((pQueue->data[parent]->priority < pQueue->data[child1]->priority || pQueue->data[parent]->priority < pQueue->data[child2]->priority) &&
			(child1 < pQueue->size && child2 < pQueue->size))
		{
			if (child1 > child2) {
				Node* swap = pQueue->data[parent];
				pQueue->data[parent] = pQueue->data[child1];
				pQueue->data[child1] = swap;

				parent = child1;
			}
			else {
				Node* swap = pQueue->data[parent];
				pQueue->data[parent] = pQueue->data[child2];
				pQueue->data[child2] = swap;

				parent = child2;
			}

			child1 = (parent * 2) + 1;
			child2 = (parent * 2) + 2;

		}
	}
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	priority_queue* pQueue = (priority_queue*)hQueue;

	if (priority_queue_is_empty(hQueue) == TRUE) {
		if (pStatus != NULL)
			pStatus = FAILURE;
	}
	else {
		return pQueue->data[0]->value;
	}
	
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	priority_queue* pQueue = (priority_queue*)hQueue;

	if (pQueue->data[0] == NULL)
		return TRUE;
	else
		return FALSE;
}

void test_print(PRIORITY_QUEUE hQueue)
{
	priority_queue* pQueue = (priority_queue*)hQueue;

	for (int i = 0; i < pQueue->size; i++) {
		printf("%d ", pQueue->data[i]->priority);
	}
	printf("\n");
}