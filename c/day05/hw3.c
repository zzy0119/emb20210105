#include <stdio.h>

#define N	41

int main(void)
{
	int arr[N] = {};
	int cnt = 0;
	int killed = 0;
	int i;

	for (i = 0; killed < N-1; i = (i+1) % N) {
		if (arr[i] == 0) {
			cnt ++;
			if (cnt == 3) {
				arr[i] = 1;
				killed ++;
				cnt = 0;
			}
		}
	}

	for (i = 0; i < N; i++) {
		if (arr[i] == 0) {
			printf("%d号留下来了\n", i+1);
		}
	}

	return 0;
}

