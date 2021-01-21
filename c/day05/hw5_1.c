#include <stdio.h>

#define N	9	

int main(void)
{
	int n;
	int arr[N] = {};
	int i, j;
	int sum = 0;

	do {
		printf("产生多少个10以内整型数:");
		scanf("%d", &n); 
	} while (n < 1 || n > 9);

	for (i = 0; i < n; i++) {
		scanf("%d", arr+i); // &arr[i]
		if (arr[i] < 1 || arr[i] > 9) {
			printf("不符合个位数！请重新输入:");	
			i--;
			continue;
		}
		for (j = i-1; j >= 0; j--) {
			if (arr[i] == arr[j]) {
				break;	
			}
		}
		if (j >= 0) {
			i--;
			printf("输入有重复!请重新输入:");
			continue;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				printf("%d ", arr[i] * 10 + arr[j]);
				sum += (arr[i] * 10 + arr[j]);
			}
		}
	}

	printf("合为:%d\n", sum);

	return 0;
}
