#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include<assert.h>

Queue initializeQueue(void)
{
	return createList();
}

int queueIsEmpty(const Queue queue)
{
	return isListEmpty(queue);
}

int queueIsFull(const Queue queue)
{
	return FALSE;
}

void enqueue(Queue* queue, const Data data)
{
	addToBeginning(queue, createNode(data));
}

void dequeue(Queue* queue)
{
	deleteLast(queue);
}

Data peekQueue(const Queue queue)
{
	return getValueOfLast(queue);
}
