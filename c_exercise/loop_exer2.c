/*
 1. 读入一个整型数,将这个整型数的每一位打印
 	12345
		% 10 ----> 5
		/ 10 ----> 1234
 2. 读入一个整型数，求得他的倒序数(回文数)
 	123---->321
 */
#include <stdio.h>

int main(void)
{
	int num;
	int res = 0;

	printf("请输入一个整型数:");
	scanf("%d", &num);

#if 0
	// 123
	for (; num > 0; num = num / 10) {
		res = res * 10 + num % 10;
		printf("%d, ", num % 10);
	}
	printf("\n");
#endif
	while (num > 0) {
		res = res * 10 + num % 10;
		num = num / 10; // num /= 10
	}

	printf("逆序数:%d\n", res);

	return 0;
}

