
#include <stdio.h>

long factorial(int n);
int getBall(int n, int m);
// 返回杨辉三角第m行第n列的值
int triangle(int m, int n)
{
	if (m == 0 || n == 0 || m == n)
		return 1;
	return triangle(m-1, n) + triangle(m-1, n-1);
}

int main(void)
{
	int n;
	int m;
	long res = 0;

#if 0

	// 读入层数
	scanf("%d", &n);

	for (int row = 0; row < n; row ++) {
		for (int col = 0; col <= row; col ++)
			printf("%d ", triangle(row, col));
		printf("\n");
	}
	scanf("%d%d", &n, &m);
	printf("%d\n", getBall(n, m));	
#endif

	n = 10;	
	for (int i = 1; i <= n; i++) {
		res += factorial(i);	
	}
	printf("%ld\n", res);

	return 0;
}

// 在n个球中，任意取m个（不放回），求有多少种不同取法。

int getBall(int n, int m)
{
	if (n < m)
		return 0;
	if (n == m)
		return 1;
	if (m == 0)
		return 1;

	return getBall(n-1, m) + getBall(n-1, m-1);
}

// 请输入整数n，求1!+2!+3!+4!+5!+6!+7!+…+n!的和。
long factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

// 爬楼梯，他可以每次走1级、2级或者3级，输入楼梯的级数，求不同的走法数
int stair(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;

	return stair(n - 1) + start(n - 2) + stair(n - 3);
}



