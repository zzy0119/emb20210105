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

int main(void)
{
	int i;
	int score;

	printf("good morning\n");

	for (i = 0; i < NUM; i++)
		scanf("%d", &score);
	
	return 0;
}


