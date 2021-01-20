#include <stdio.h>

int maxCommonDivison(int m, int n);
int maxCommonDivison2(int m, int n);
int main(void)
{
	int m, n;

	scanf("%d%d", &m, &n);
	printf("%d\n", maxCommonDivison2(m, n));
	
	return 0;
}

int maxCommonDivison(int m, int n)
{
	int t;
	if (m < n) {
		t = m;
		m = n;
		n = t;
	}
	
	for (int i = n; i > 0; i--) {
		if (m % i == 0 && n %i == 0)
			return i;
	}
}

int maxCommonDivison2(int m, int n)
{
	int t;

	if (m < n) {
		t = m;
		m = n;
		n = t;
	}
	while (1) {
		t = m % n;
		if (t == 0) 
			return n;
		m = n;
		n = t;
	}
}

