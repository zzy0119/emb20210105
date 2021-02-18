#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myqsort(int *arr, int low, int high);
int main(int argc, char *argv[])
{
	int *a = NULL;
	int i;
	int len;

	if (argc < 2)
		return 1;

	// "76123465"
	len = strlen(argv[1]);
	// a = malloc(len*sizeof(int));
	a = calloc(len, sizeof(int));

	printf("排序前:");
	for (i = 0; argv[1][i]; i++) {
		a[i] = argv[1][i] - '0';
		printf("%d ", a[i]);
	}
	printf("\n");	

	myqsort(a, 0, len-1);	
	printf("排序后:");
	for (i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");

	free(a);
	
	return 0;
}

static void swap(int *arr, int oneindex, int twoindex)
{
	int t;

	t = arr[oneindex];
	arr[oneindex] = arr[twoindex];
	arr[twoindex] = t;
}

/*
 1.为标兵确定位置
 2.分区
 */
int partition(int *arr, int low, int high)
{
	// 选
	int k = arr[low];

	while (low < high) {
		while (arr[high] >= k && low < high)
			high--;
		if (low < high) {
			// high下标元素小于标兵
			swap(arr, low, high);
		}
		while (arr[low] <= k && low < high)
			low++;
		if (low >= high)
			break;
		swap(arr, low, high);
	}
	arr[low] = k;

	return low;
}

void myqsort(int *arr, int low, int high)
{
	int base;

	if (low >= high)	
		return ;
	base = partition(arr, low, high);
	myqsort(arr, low, base-1);
	myqsort(arr, base+1, high);
}
