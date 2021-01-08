#include <stdio.h>

int main(void)
{
	int row, col;

	for (row = 1; row < 10; row ++) {
		for (col = 1; col <= row; col++) {
			printf("%d*%d=%2d ", col, row, col*row);
		}
		printf("\n");
	}

	return 0;
}

