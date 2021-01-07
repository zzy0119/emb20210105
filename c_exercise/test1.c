#include <stdio.h>

int main(void)
{
	int i;
	int cnt = 0;
	
	for (i = 100; i < 1000; i++) {
		if (i % 10 == 6 && i % 3 == 0 && i % 5 != 0) {
			printf("%d\n", i);		
			cnt ++;
		}
	}

	printf("有%d个\n", cnt);

	return 0;
}

