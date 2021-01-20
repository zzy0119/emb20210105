#include <stdio.h>

int fib(int n);
int main(void)
{
	for (int i = 1; i < 20; i++) {
		printf("%d ", fib(i));
	}
	printf("\n");

	return 0;
}

/*
 终止条件
 递归点
 */
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	if (n < 1)
		return -1;

	return fib(n-1) + fib(n-2);
}


