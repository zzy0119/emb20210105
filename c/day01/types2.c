#include <stdio.h>

int main(void)
{
	char ch1 = 'a';
	int var;
	float f;

	var = ch1; // 自动类型强转(隐式转换)
	// 显式转换 (数据类型)变量


	printf("var:%d\n", var);

	printf("%d\n", var + ch1);

	f = var + ch1;
	printf("f:%f\n", f);

	f = 1.9;
	printf("%d\n", (int)f+1);

	return 0;
}

