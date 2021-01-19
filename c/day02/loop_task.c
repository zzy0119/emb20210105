/*
 1. 读入一个四则运算式，计算其结果
 例如:读入1+2
 输出 1+2=3
 例如:读入2*3
 输出 2*3=6

 2. 读入一个四位整型数，判断十位出现的次数

 3. 打印输出菱形,例如读入了4行，则输出一下图型
        *				l0	n-l-1	1 2*l+1
	  * * *				l1	n-l-1	3
	* * * * *			l2	n-l-1	5
  * * * * * * *			l3	n-l-1	7
    * * * * *		l = n-2	n-l-1	2*l+1	
	  * * *			l--		n-l-1	
	    *

 4. 一个2000以内的整型数，它+100后是一个完全平方数,再加上168
 又是一个完全平方数,请问该数为多少(sqrt(x))
 gcc -o four four.c -lm

 */
#include <stdio.h>
#include <math.h>

int main(void)
{
#if 0
	int row;

	printf("多少行:");
	scanf("%d", &row);

	// 上半部分
	for (int l = 0; l < row; l++) {
		// 空格
		for (int j = 0; j < row-l-1; j++)
			printf("  ");
		for (int j = 0; j < 2*l+1; j++)
			printf("* ");
		printf("\n");
	}

	// 下半部分
	for (int l = row-2; l >= 0; l--) {
		for (int j = 0; j < row-l-1; j++)
			printf("  ");
		for (int j = 0; j < 2*l+1; j++)
			printf("* ");
		printf("\n");
	}
#endif

#if 0
	int x, y;
	int i, j, k;

	for (i = 0; i < 2000; i++) {
		x = i+100;
		y = i+268;
		for (j = 1; j < x; j++) {
			if (j * j == x)
				break;
		}

		for (k = 1; k < y; k++)
			if (k * k == y)
				break;
		if (j < x && k < y) {
			printf("%d符合条件\n", i);	
		}
	}
#endif

	double x, y;
	for (int i = 0; i < 2000; i ++) {
		x = sqrt(i+100);
		y = sqrt(i+268);
		if (x == (int)x && y == (int)y) {
			printf("%d符合条件\n", i);	
		}
	}

	return 0;
}

