/*
1. 写一段代码，向终端打印
    *
  * * *
* * * * *

2. 读入两个整型数,计算两个整型数的乘积，并打印输出

3. 读入用户输入的年份，判断是否为闰年

4. 读入一个月份, 判断输入哪个季节

*/
#include <stdio.h>

int main(void)
{
/*
	int m, n;
	
	printf("请输入两个变量:");
	scanf("%d%d", &m, &n);
	
	printf("%dx%d=%d\n", m, n, m*n);
*/
/*
	// 作业3
	int year;

	printf("请输入年份:");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		printf("%d年是闰年\n", year);
	} else {
		printf("%d年是平年\n", year);
	}
*/
	int month;
	
	printf("请输入月份:");
	scanf("%d", &month);	

	if (month < 1 || month > 12) {
		printf("没有该季节\n");
	} else {
		if (month >= 3 && month <= 5) {
			printf("春天\n");
		} else if (month > 5  && month <= 8) {
			printf("夏天\n");
		} else if (month > 8 && month <= 11) {
			printf("秋天\n");
		} else {
			printf("冬天\n");
		}
	}

	return 0;
}






