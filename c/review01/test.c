/*
 1. 定义一个接口函数，实现给任意类型数组找到最大值或者最小值
 （注意一个函数同时满足，最大还是最小依赖用户传递的比较函数）
 
 2. 实现库函数atoi(3),将所给定的字符串转成整型数，包括负数
 测试用argv[1]转换为整型

 3. 将argv命令中的每一个参数，存储到自己开辟的指针数组中，其中
 命令行每一个字符串中的每一个字符都要存储到堆空间中。
 ./a.out hello world
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(const void *data1, const void *data2);

int max_or_min(void *arr, int nmemb, int size, cmp_t cmp);
int myatoi(const char *p);

static int int_cmp(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d1 - *d2;
}

static int int_cmp2(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d2 - *d1;
}

int main(int argc, char *argv[])
{
	int arr[] = {3,1,8,9,2,3,4,6,1};
	int max_index, min_index;

	if (argc < 2)
		return 1;
	
	printf("%d\n", myatoi(argv[1]));


	max_index = max_or_min(arr, sizeof(arr) / sizeof(*arr), sizeof(int), int_cmp);
	printf("max:%d\n", arr[max_index]);

	min_index = max_or_min(arr, sizeof(arr) / sizeof(*arr), sizeof(int), int_cmp2);

	printf("min:%d\n", arr[min_index]);
	
	return 0;
}

int max_or_min(void *arr, int nmemb, int size, cmp_t cmp)
{
	int i;
	char *tmp;
	int j;

	tmp = malloc(size);

	memcpy(tmp, arr, size);
	j = 0;
	for (i = 1; i < nmemb; i++) {
		if (cmp(tmp, (char *)arr+i*size) < 0) {
			memcpy(tmp, (char *)arr+i*size, size);
			j = i;
		}
	}

	free(tmp);	
	return j;
}


int myatoi(const char *p)
{
	int ret = 1;
	int res = 0;

	if (p == NULL)
		return 0; // exit(); 进程终止了
	if (*p == '-') {
		ret = -1;
		p++;
	}

	while (*p) {
		if (*p < '0' || *p > '9')
			break;
		res = res * 10 + (*p - '0');
		p++;
	}

	return res * ret;
}


