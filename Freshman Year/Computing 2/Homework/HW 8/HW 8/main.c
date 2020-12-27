#include <stdio.h>
#include "priority_queue.h"

int main(int agrc, char* argv[])
{
	PRIORITY_QUEUE queue = NULL; 
	Status* pstatus = SUCCESS;
	queue = priority_queue_init_default();

	priority_queue_insert(queue, 2, 1);
	priority_queue_insert(queue, 7, 1);
	priority_queue_insert(queue, 26, 1);
	priority_queue_insert(queue, 25, 1);
	priority_queue_insert(queue, 19, 1);
	priority_queue_insert(queue, 17, 1);
	priority_queue_insert(queue, 1, 1);
	priority_queue_insert(queue, 90, 1);
	priority_queue_insert(queue, 3, 1);
	priority_queue_insert(queue, 36, 1);
	test_print(queue);

	priority_queue_service(queue);
	test_print(queue);

	printf("Front: %d\n", priority_queue_front(queue, pstatus));

	if (priority_queue_is_empty(queue) == TRUE)
		printf("Is empty\n");
	else
		printf("Not Empty\n");


	priority_queue_destroy(&queue);

	return 0;
}


