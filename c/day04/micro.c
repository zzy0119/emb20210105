/*
#开头的---》预处理指令
gcc四个步骤
	1. 预处理:头文件的展开，宏的替换....  -E
	2. 编译:翻译成汇编 -S
	3. 汇编:生成目标文件 -c
	4. 链接:动态链接(库函数)
 */
#include <stdio.h>

#define NUM 	10
#define SQUARE(x)	(x)*(x)
#define SWAP(x, y) \
	do {\
		typeof(x) t; t = x; x = y; y = t;\
	}while(0)

int main(void)
{
	int i;
	int score;
	int m, n;

	printf("good morning\n");

#if 0
	for (i = 0; i < NUM; i++)
		scanf("%d", &score);
#endif
	i = 5;
	printf("%d\n", SQUARE(i+2)); // i+2*i+2

	m = 10;
	n = 20;
	SWAP(m, n);
	printf("m:%d, n:%d\n", m, n);
	
	return 0;
}


