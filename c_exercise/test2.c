#include <stdio.h>

int main(void)
{
	int y, m, d;
	int sumdays = 0;
	int i;

	printf("请输入日期(y/m/d):");
	scanf("%d/%d/%d", &y, &m, &d);

	// [1,m)	
	for (i = 1; i < m; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || \
				i == 8 || i == 10 || i == 12)
			sumdays += 31; // sumdays = sumdays + 31
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			sumdays += 30;
		else
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
				sumdays += 29;
			else 
				sumdays += 28;
	}

	sumdays += d;

	printf("%d/%d/%d是这一年的第%d天\n", y, m, d, sumdays);

	return 0;
}

