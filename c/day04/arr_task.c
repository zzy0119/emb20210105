/*
 1. 定义一个又10个元素组成的整型数组，值随机产生，
 将数组中的最大元素和最小元素交换
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N	10

int main(void)
{
	int arr[N] = {};
	int i;
	int max, min;

	srand(getpid());
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 100;	
		printf("%d ", arr[i]);
	}
	printf("\n");

	max = min = 0;
	for (i = 1; i < N; i++) {
		if (arr[i] > arr[max]) {
			max = i; 
		}
		if (arr[i] < arr[min])
			min = i;
	}
	i = arr[max];
	arr[max] = arr[min];
	arr[min] = i;

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}

