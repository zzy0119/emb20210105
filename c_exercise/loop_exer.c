/*
 1. 求100的前n项和
 2. 判断100以内有多少同能能被3和5整除的数
 */
#include <stdio.h>

int main(void)
{
	int sum = 0;
	int i;

	for (i = 100; i > 0; /*i = i - 1*/ i--) {
		// sum = sum + i;
		sum += i;
	}
	printf("sum:%d\n", sum);

	sum = 0;
	for (i = 1; i < 100; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			sum ++; // sum = sum + 1
			printf("%d\n", i);
		}
	}
	printf("%d\n", sum);

	return 0;
}

