/*
1. 读入一个整型变量，判断其奇偶性
*/

#include <stdio.h>

int main(void)
{
	int number;

	printf("请输入一个整型数:");
	scanf("%d", &number);

	// 处理
	if (number % 2 == 0) {
		printf("%d是一个偶数\n", number);
	} else {
		printf("%d是一个奇数\n", number);
	}

	return 0;
}

