#include <stdio.h>

/*
 1. 定义一下接口函数
 	<1>求出非波那锲数列的第n项
		1 1 2 3 5 8 
	<2>求出给定的三个整型数当中最小的那一个
 */

int maxOfTwoNum(int m, int n);
int fib(int n);
int minThreeNum(int a, int b, int c);
int main(void)
{
#if 0
	int num1, num2;
	int ret;

	scanf("%d%d", &num1, &num2);

	ret = maxOfTwoNum(num1, num2);
	printf("最大:%d\n", ret);
#endif
	for (int i = 1; i <= 20; i ++) {
		printf("%d ", fib(i));
	}
	printf("\n");

	printf("%d\n", minThreeNum(10, 3, 22));

	return 0;
}

/*求两个整型数的最大值*/
int maxOfTwoNum(int m, int n)
{
	if (m > n)
		return m;
	else
		return n;
}

int fib(int n)
{
	int one, two;
	int cur;

	if (n == 1 || n == 2)
		return 1;

	one = 1;
	two = 1;

	while (n >= 3) {
		cur = one + two;	
		one = two;
		two = cur;
		n --;
	}

	return cur;
}

int minThreeNum(int a, int b, int c)
{
	int min;	

	min = a > b ? b : a;
	min = min > c ? c : min;

	return min;
}





