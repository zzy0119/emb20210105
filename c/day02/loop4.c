#include <stdio.h>

int main(void)
{
	int i = 0;

LOOP:
	if (i < 10) {
		printf("%d\n", i);
		i++;
		goto LOOP; // 不推荐
	}

	return 0;
}

