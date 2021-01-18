/*
 循环练习题:
 1. 小明今天进行篮球比赛，需要运球10次，但运球第5次的时候
 突然肚子疼无法继续训练，这时需要停止循环，写一段代码，呈现
 此次训练过程

 2. 从键盘输入整数 n，输出 1+3+5+7+……前 n 项的和。
 */
#include <stdio.h>

int main(void)
{
	int i, n;
	int res = 0;

	for (i = 1; i <= 10; i++) {
		if (i == 5)	 {
			printf("小明坏肚子了！不能继续训练\n");
			break;
		}
		printf("第%d次运球\n", i);
	}

	printf("输入整型数:");
	scanf("%d", &n);	

	for (i = 1; i <= n; i++) {
		if (i % 2 == 0)
			continue;
		res += i;
		printf("%d+", i);
	}

	printf("\b=%d\n", res);

	return 0;
}

