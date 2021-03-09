#include <stdio.h>

#include "lqueue.h"

int main(void)
{
	lqueue_t *me;
	int n;

	lqueueInit(sizeof(int), &me);

	for (int i = 1; i < 10; i++) {
		lenqueue(me, &i);
	}

	while (!lqueueIsEmpty(me)) {
		ldequeue(me, &n);
		printf("%d\n", n);
	}

	lqueueDestroy(me);

	return 0;
}
