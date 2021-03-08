#ifndef __QUEUE_H
#define __QUEUE_H

enum {LASTDEQ, LASTENQ};

typedef struct {
	void *base;
	int front; //队列头元素的下标
	int tail;// 队尾元素的下标
	int size;
	int capacity;	
	int flag;
}queue_t;

int queueInit(int size, int capcity, queue_t **q);

int queueEmpty(const queue_t *q);

int queueFull(const queue_t *q);

int enq(queue_t *q, const void *data);

int deq(queue_t *q, void *data);

void queueDestroy(queue_t *);

#endif
