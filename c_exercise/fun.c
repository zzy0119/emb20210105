#include <stdio.h>

// 声明
int isLeap(int y);
int daysMonth(int m, int y);
int main(void)
{
	int sumdays = 0;
	int year, month;
	int i;
	int weekday;
	int monthdays;

	printf("输入日期(year/month):");
	scanf("%d/%d", &year, &month);

	// 1990～year-1
	for (i = 1990; i < year; i++) {
		// 调用
		sumdays = sumdays + 365 + isLeap(i);// y = i
	}

	// year.1.1~year.month.1
	for (i = 1; i < month; i++) {
		sumdays += daysMonth(i, year);
	}
	sumdays += 1;

	weekday = sumdays % 7;
	// printf("%d\n", weekday);

	// 用户输入的月份有多少天
	monthdays = daysMonth(month, year);

	// 打印日历--->year/month/1是星期weekday, month月有monthdays
	printf("       %d月 %d\n", month, year);
	printf("日 一 二 三 四 五 六\n");
	for (i = 0; i < weekday; i++)
		printf("   ");
	for (i = 1; i <= monthdays; i++) {
		printf("%2d", i);	
		if ((weekday+i) % 7 == 0)
			printf("\n");
		else
			printf(" ");
	}
	printf("\n");

	return 0;
}

// 函数的定义:函数的功能实现者
int isLeap(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || \
			y % 400 == 0)	
		return 1;
	else
		return 0;
}

// 判断月份有多少天
int daysMonth(int m, int y)
{
	int res;

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || \
			m == 10 || m == 12)
		res = 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		res = 30;
	else {
		res = 28 + isLeap(y);		
	} 

	return res;
}






