#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/*
数组:相同类型元素的集合 
定义:type name[nmembs];
赋值: name[0],name[1], name[nmembs-1];
初始化:定义的同时赋值
	type name[nmembs] = {};
遍历:访问每一个元素,同赋值
 */
int main(void)
{
	int arr[5]; // 定义
	int i;
	int arr2[3] = {1,3}; // 初始化

	// srand(time(NULL));
	srand(getpid());
	// 赋值
	for (i = 0; i < 5; i++) {
		arr[i] = rand() % 100;
	}

	// 遍历
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

