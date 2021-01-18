#include <stdio.h>

int main(void)
{
	int score;

	do {
		printf("输入整型数:");
		scanf("%d", &score);	
	}while(score < 0 || score > 100);

	printf("score:%d\n", score);

	return 0;
}

