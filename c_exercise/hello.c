#include <stdio.h>

int main(void)
{
	// void short int long (long long) char float double long double
	// struct union enum 

	// 定义变量
	int var;

	// 读取用户带计算数值
	scanf("%d", &var);

	if (var >= 0) {
		printf("%d是一个正数\n", var);
	} else {
		printf("%d是一个负数\n", var);
	}

	printf("hello world\n");

	return 0;
}

