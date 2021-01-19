/*
 1. 判断给定的数值是否为完全平方数

 2. 得到给的月份多少天 (年/月)
 */
#include <stdio.h>

int isPerfectSquare(int n);
int isLeap(int y);
int dayOfMonth(int m, int y);

int main(void)
{
#if 0
	int num;

	scanf("%d", &num);
	if (isPerfectSquare(num)) {
		printf("%d是一个完全平方数\n", num);
	} else {
		printf("%d不是一个完全平方数\n", num);
	}
#endif
	int month, year;	

	scanf("%d%d", &month, &year);

	printf("%d年%d月有%d天\n", year, month, dayOfMonth(month, year));

	return 0;
}

int isPerfectSquare(int n)
{
	for (int i = 1; i < n; i++) {
		if (i * i == n)	
			return 1;
	}

	return 0;
}

// 给定一个年份，判断是否为闰年
int isLeap(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

// 判断月份有多少天
int dayOfMonth(int m, int y)
{
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28+isLeap(y);
		default:
			return -1;
	}

}

