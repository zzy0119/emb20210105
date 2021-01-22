#include <stdio.h>

int maxArray(int *p, int n);
int main(void)
{
	int arr[] = {3,2,1,6,7,89,4};

	printf("%d\n", maxArray(arr, sizeof(arr) / sizeof(arr[0])));

	return 0;
}

// 返回给定的整型数组中所有元素的最大值
int maxArray(int *p, int n)
{
	int i;
	int max;

	max = p[0];
	for (i = 1; i < n; i++) {
		if (max < *(p+i)) {
			max = p[i];
		}
	}
	return max;
}


