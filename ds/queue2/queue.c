#include <stdlib.h>
#include <string.h>

#include "queue.h"

int queueInit(int size, int capcity, queue_t **q)
{
	*q = malloc(sizeof(queue_t));
	if (NULL == *q)
		return -1;
	(*q)->base = calloc(capcity, size);
	if (NULL == (*q)->base) {
		free(*q);
		return -1;
	}
	(*q)->front = (*q)->tail = 0;
	(*q)->capacity = capcity;
	(*q)->size = size;
	(*q)->flag = LASTDEQ;

	return 0;
}

int queueEmpty(const queue_t *q)
{
	return q->front == q->tail;
}

int queueFull(const queue_t *q)
{
	return q->front == (q->tail+1) % q->capacity;
}

int enq(queue_t *q, const void *data)
{
	if (queueFull(q))
		return -1;
	memcpy((char *)q->base + q->tail * q->size, data, q->size);
	q->tail = (q->tail + 1) % q->capacity;

	return 0;
}

int deq(queue_t *q, void *data)
{
	if (queueEmpty(q))
		return -1;
	memcpy(data, (char *)q->base + q->front * q->size, q->size);
	q->front = (q->front + 1) % q->capacity;

	return 0;
} 

void queueDestroy(queue_t *q)
{
	free(q->base);
	free(q);
}


