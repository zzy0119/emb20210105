#include <stdio.h>

#include "queue.h"

int main(void)
{
	queue_t *me;
	int n;

	queueInit(sizeof(int), 5, &me);

	for (int i = 1; i < 10; i++) {
		enq(me, &i);
	}

	while (!queueEmpty(me)) {
		deq(me, &n);
		printf("%d\n", n);
	}

	queueDestroy(me);

	return 0;
}
