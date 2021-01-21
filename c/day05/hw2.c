#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N	10

int main(void)
{
	int score[N] = {};
	int grade[N+1] = {};
	int i, j;

	srand(getpid());
	for (i = 0; i < N; i++) {
		score[i] = rand() % 101;
		grade[score[i] / 10] ++;
		printf("%d ", score[i]);
	}
	printf("\n");

	printf("100:");
	for (i = 0; i < grade[10]; i++)
		printf("* ");
	printf("\n");

	for (i = 9; i >= 0; i--) {
		printf("%2d~%2d:", i*10, i*10+9);
		for (j = 0; j < grade[i]; j++)
			printf("* ");
		printf("\n");
	}

	return 0;
}

