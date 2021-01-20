#include <stdio.h>

int main(void)
{
	int arr[5] = {1,2,3,4,5};

	printf("arr:%p\n", arr); // int *
	printf("arr+1:%p\n", arr+1);
	printf("*(arr+1):%d\n", *(arr+1));
	printf("1[arr]:%d\n", 1[arr]);
	printf("sizeof(arr):%ld\n", sizeof(arr));

	return 0;
}

