#include <stdio.h>

/*
 循环
 while (条件表达式) {
 	循环体;
 }

 for

 do while

 break;
 continue;
 */

int main(void)
{
	int i;

	i = 0;
	while (i < 10) { // 条件多为关系表达式或逻辑表达式
		printf("正在写第%d遍\n", i+1);
		i ++;
	}

	return 0;
}

