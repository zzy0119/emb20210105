#include <stdio.h>

#include "stack.h"

int main(void)
{
	stack_t *mystack;
	int p;

	stackInit(sizeof(int), 10, &mystack);

	for (int i = 1; i < 100; i++) {
		if (stackPush(mystack, &i) != 0)
			break;
	}

	while (!stackIsEmpty(mystack)) {
		stackPop(mystack, &p);
		printf("%d\n", p);
	}

	stackDestroy(mystack);

	return 0;
}

