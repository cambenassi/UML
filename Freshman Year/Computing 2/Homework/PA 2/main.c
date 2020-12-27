/***********************************************************
Author: <Cameron Benassi>
Date: <4/3/2020>
Effort: <2 hours>
Purpose: <To implement a doubly linked list in a queue>
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Car;

struct node
{
	char direction;
	int length;
	Car* next;
	Car* prev;
};

struct queue 
{
	Car* front;
	Car* rear;
};

typedef struct queue Queue;

typedef void* QUEUE;

QUEUE queue_init(void);
void queue_destroy(QUEUE* Queue);
Car* newNode(char direction, int length);
int queue_enqueue(QUEUE hQueue, char direction, int length);
void queue_dequeue(QUEUE hQueue);
void queue_print(QUEUE hQueue);
int get_length_top(QUEUE hQueue);
int is_queue_empty(QUEUE hQueue);

int main(int argc, char* argv[])
{
	int numTests = 0;
	char kb;

	scanf("%d", &numTests);

	for (int i = 0; i < numTests; i++) {
		int shipLength, numCars, carTotalLength = 0, tripCounter = 0;;
		QUEUE leftBank = queue_init();
		QUEUE rightBank = queue_init();

		scanf("%d %d", &shipLength, &numCars);
		for (int j = 0; j < numCars; j++) {
			char direction;
			int length;

			while ((kb = getchar()) != '\n' && kb != EOF);
			scanf("%d %c", &length, &direction);
			
			if (direction == 'l')
				queue_enqueue(leftBank, direction, length);
			else
				queue_enqueue(rightBank, direction, length);
		}
		shipLength *= 100;

		if (is_queue_empty(leftBank) == 0)			//ship starts at left bank, if empty then add a trip
			tripCounter++;			

		while(is_queue_empty(leftBank)){
			carTotalLength = 0;
			while (shipLength >= carTotalLength + get_length_top(leftBank) && is_queue_empty(leftBank) == 1){
				carTotalLength += get_length_top(leftBank);
				queue_dequeue(leftBank);
			}
			tripCounter++;
			if (is_queue_empty(rightBank) == 0 && is_queue_empty(leftBank) == 1)
				tripCounter++;
			
		}

		while (is_queue_empty(rightBank)) {
			carTotalLength = 0;
			while (shipLength >= carTotalLength + get_length_top(rightBank) && is_queue_empty(rightBank) == 1) {
				carTotalLength += get_length_top(rightBank);
				queue_dequeue(rightBank);
			}
			tripCounter++;
			if (is_queue_empty(leftBank) == 0 && is_queue_empty(rightBank) == 1)
				tripCounter++;

		}

		while ((kb = getchar()) != '\n' && kb != EOF);
		printf("%d\n", tripCounter);
		queue_destroy(&leftBank);
		queue_destroy(&rightBank);
	}
	

	return 0;
}

QUEUE queue_init(void) {

	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->front = newQueue->rear = NULL;
	return (QUEUE)newQueue;
}

void queue_destroy(QUEUE* phQueue) {
	Queue* pQ = (Queue*)*phQueue;
	Car* pNode = pQ->front;
	Car* pTemp;

	while (pNode) {
		if (pNode->next) {
			pTemp = pNode->next;
			free(pNode);
			pNode = pTemp;
		}
		else {
			free(pNode);
			break;
		}
	}

	free(pQ);
	*phQueue = NULL;
}

Car* newNode(char direction, int length) {

	Car* new = (Car*)malloc(sizeof(Car));
	new->direction = direction;
	new->length = length;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

int queue_enqueue(QUEUE hQueue, char direction, int length) {

	Queue* pQueue = (Queue*)hQueue;

	Car* pNew = newNode(direction, length);

	if (pNew == NULL)
		return 1;

	if (pQueue->rear == NULL) {
		pQueue->front = pQueue->rear = pNew;
		return 0;
	}

	pQueue->rear->next = pNew;
	pQueue->rear = pNew;
	return 0;
}

void queue_print(QUEUE hQueue) {

	Queue* pQueue = (Queue*)hQueue;
	Car* pTemp = pQueue->front;

	if (pTemp->next == NULL) {
		printf("Length: %d Direction: %c\n", pTemp->length, pTemp->direction);
		return;
	}


	while (pTemp){
		printf("Length: %d Direction: %c\n", pTemp->length, pTemp->direction);
		pTemp = pTemp->next;
	} 

}

int get_length_top(QUEUE hQueue) {
	
	Queue* pQueue = (Queue*)hQueue;
	Car* pTemp = pQueue->front;

	if (pTemp == NULL)
		return 0;
	return pTemp->length;
}

void queue_dequeue(QUEUE hQueue) {
	Queue* pQ = (Queue*)hQueue;
	Car* pNode;

	pNode = pQ->front;

	pQ->front = pQ->front->next;

	if (pQ->front == NULL)
		pQ->rear == NULL;

	free(pNode);
}
int is_queue_empty(QUEUE hQueue) {

	Queue* pQ = (Queue*)hQueue;

	if (pQ->front == NULL)
		return 0;
	else
		return 1;

}