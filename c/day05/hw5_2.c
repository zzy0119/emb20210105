#include <stdio.h>

#define	N	4

int main(void)
{
	int n;
	int arr[N] = {};
	int i;
	int t;

	do {
		printf("请输入一个四位整型数:");
		scanf("%d", &n);
	} while (n < 1000 || n > 9999);
	
	i = 0;
	while (n > 0) {
		arr[i++] = (n % 10 + 9) % 10;
		n /= 10;
	}

	for (i = 0; i < N; i++) {
		if (i == 0 || i == 1) {
			t = arr[i];
			arr[i] = arr[i+2];
			arr[i+2] = t;
		}
	}

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

