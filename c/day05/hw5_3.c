#include <stdio.h>

#define N	10

int main(void)
{
	int arr[N] = {0, 10, 0, 0, 20, 10, 0, 0, 10, 0};
	int n;
	int num;
	int i;

	printf("几道题:");
	scanf("%d", &n);

	i = 0; 
	while (i < n) {
		printf("几号选手:");
		scanf("%d", &num);
		arr[num-1] += 10;
		i++;
	}

	for (i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

