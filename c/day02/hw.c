#include <stdio.h>

int main(void)
{
#if 0
	int num;	
	int i, j;
	int sum;

	printf("输入范围:");
	scanf("%d", &num);

	for (i = 1; i < num; i++) {
		sum = 0;
		for (j = 1; j < i; j++)	{
			if (i % j == 0)
				sum += j;
		}
		if (sum == i) {
			printf("%d是一个完数\n", i);
		}
	}
#endif

	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 0; j < i-1; j++)
			printf("       ");
		for (j = i; j < 10; j++) {
			printf("%d*%d=%2d ", i, j, i*j);
		}
		printf("\n");
	}

	return 0;
}

