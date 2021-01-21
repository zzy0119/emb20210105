#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N	10

int main(void)
{
	int arr[N] = {};
	int i, j;
	int t;
	int max;

	srand(getpid());
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 冒泡排序
	for (i = 0; i < N-1; i++) {
		// 每一趟要比较的元素的范围
		for (j = 0; j < N-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}

	// 选择排序
	for (i = 0; i < N-1; i++) {
		// arr[i]选择的
		max = i;
		for (j = i+1; j < N; j++) {
			if (arr[j] > arr[max])	
				max = j;
		}
		if (max != i) {
			t = arr[i];
			arr[i] = arr[max];
			arr[max] = t;
		}
	}

	// 直接插入排序
	for (i = 1; i < N; i++) {
		t = arr[i];
		for (j = i-1; j >= 0; j--) {
			if (t < arr[j]) {
				arr[j+1] = arr[j];	
			} else 
				break;
		}
		// j < 0 || break
		arr[j+1] = t;
	}

	for (i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

