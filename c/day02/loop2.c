#include <stdio.h>

int main(void)
{
	int i;

	for (i = 0/*循环第1次会执行，并只执行一次*/; i < 10/*2 循环条件*/; i++/*4 循环变量的改变*/) {
		if (i % 2 == 0)
			// continue; // 4
			break; // 终止循环
		printf("第%d次循环\n", i+1); /*3 循环体*/	
	}

	return 0;
}

