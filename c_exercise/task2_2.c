#include <stdio.h>

int main(void)
{
	int num;
	int i, tmp;
	int res = 0;

	printf("请输入一个五位数:");
	scanf("%d", &num);

	if (num < 10000 || num > 99999)
		printf("输入无效\n");
	else {
		// 32947---->24
		i = 10000;
		while (i > 0) {
			tmp = num / i;
			if (tmp % 10 % 2 == 0)
				res = res * 10 + tmp % 10;
			i /= 10;
		}
	}
	printf("结果:%d\n", res);

	return 0;
}

