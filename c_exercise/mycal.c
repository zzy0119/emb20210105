/*
   已知1990.1.1是星期1,读入用户输入的1990后的日期，
   打印相应的日历
   ./mycal 
   2008/3
   三月 2008         
   日 一 二 三 四 五 六  
   					 1  
   2  3  4  5  6  7  8  
   9 10 11 12 13 14 15  
   16 17 18 19 20 21 22  
   23 24 25 26 27 28 29  
   30 31           

   1990.1.1~2008.3.1总天数 % 7 == 2008.3.1星期几
   总天数==1990~2008不包括2008总天数+2008.1.1~2008.3.1

 */
#include <stdio.h>

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
		sumdays += (365+(i % 4 == 0 && i % 100 != 0 || i % 400 == 0));
	}

	// year.1.1~year.month.1
	for (i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || \
				i == 10 || i == 12)
			sumdays += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			sumdays += 30;
		else {
			if (year % 4 == 0 && year % 100 != 0 || \
					year % 400 == 0)	
				sumdays += 29;
			else
				sumdays += 28;
		} 
	}
	sumdays += 1;

	weekday = sumdays % 7;
	// printf("%d\n", weekday);

	// 用户输入的月份有多少天
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || \
			month == 10 || month == 12)
		monthdays = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		monthdays = 30;
	else {
		if (year % 4 == 0 && year % 100 != 0 || \
				year % 400 == 0)	
			monthdays = 29;
		else
			monthdays = 28;
	} 

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



