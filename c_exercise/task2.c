/*
1. 统计100到300之间有多少个质数

2. 读入一个万位数(5位数),将这个数的偶数位重新组成一个新的数
82376--->826

3. 打印99乘法表
*/
#include <stdio.h>

int main(void)
{
	int i, j;
	int cnt = 0;
	int primer_cnt = 0;

	for (i = 100; i <= 300; i++) {
#if 0
		cnt = 0;
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				cnt ++;	
			}
		}
		if (cnt == 2) {
			primer_cnt ++;	
		}
#endif
		for (j = 2; j < i; j++) {
			if (i % j == 0)
				break;
		}
		if (i == j)
			primer_cnt ++;
	}
	printf("有%d个\n", primer_cnt);

	return 0;
}

