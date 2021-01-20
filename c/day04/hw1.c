#include <stdio.h>

int reverseNumber(int n);
int isPalindromeNumber(int n);
int main(void)
{
	int n, i;
	int m, ver;

	printf("请输入一个整型数:");
	scanf("%d", &n);

	i = 0;
	while (i < 7) {
		if (isPalindromeNumber(n)) {
			printf("%d是一个回文整型数\n", n);
			break;
		}
		ver = reverseNumber(n);
		m = n + ver;
		printf("%d+%d=%d\n", n, ver, m);
		n = m;
		i++;
	}
	if (i == 7) {
		printf("经过7次也未得到回文数\n");
	}

	return 0;
}

// 倒数
int reverseNumber(int n)
{
	int res = 0;

	while (n > 0) {
		res = res * 10 + n % 10;
		n /= 10;
	}

	return res;
}

int isPalindromeNumber(int n)
{
	return n == reverseNumber(n);
}



