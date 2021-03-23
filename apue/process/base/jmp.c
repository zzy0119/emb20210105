#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf env;

static int div2num(int a, int b)
{
	if (b == 0) 
		// 跳到 读入位置重新读入
		longjmp(env, 1);

	return a / b;
}

int main(void)
{
	int m, n;

	if (setjmp(env) == 0) {
		printf("请输入两个整型变量:");
	} else {
		// 跳转
		printf("请重新输入:");
	}
	scanf("%d%d", &m, &n);

	printf("%d\n", div2num(m, n));

	exit(0);
}
