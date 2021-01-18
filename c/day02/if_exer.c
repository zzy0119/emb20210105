/*
 输入3个整型数a, b, c,先将a,b中的较大值存入a中，较小数存入b中；再让a与c比较，将较大数存a中，较小数存c中；最后比较b和c，将较大数存b中，较小数存c中；从而实现abc从大到小排序
 */
#include <stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	if (a < b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	if (a < c) {
		a = a ^ c;
		c = a ^ c;
		a = a ^ c;
	}

	if (b < c) {
		b = b ^ c;
		c = b ^ c;
		b = b ^ c;
	}

	printf("a:%d, b:%d, c:%d\n", a, b, c);

	return 0;
}

