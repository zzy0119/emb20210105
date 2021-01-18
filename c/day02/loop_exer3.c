/*
 1. 读入一个整型数,求得这个数的逆序数
 456---->654

 2. 一个数的每一位的立方和等于这个数的本身，则称为水仙花数.
 问100~999之间有多少个水仙花数
 */

#include <stdio.h>

int main(void)
{
	int num;
	int res = 0;
	int i;

	scanf("%d", &num);

	while (num > 0) {
		res = res * 10 + num % 10;	
		num /= 10;
	}
	printf("res:%d\n", res);
	
	for (i = 100; i < 1000; i++) {
		res = 0;	
		num = i;
		while (num > 0) {
			res += (num % 10) * (num % 10) * (num % 10);
			num /= 10;
		}
		if (res == i)
			printf("%d是水仙花数\n", i);
	}


	return 0;
}

