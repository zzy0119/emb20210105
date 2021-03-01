#include <stdio.h>

#if 0
#define RED		1
#define GREEN	2
#define YELLOW	3
#define BLACK	4
#endif

enum {RED, GREEN, YELLOW=9, BLACK};

int main(void)
{
	printf("%d %d %d %d\n", RED, GREEN, YELLOW, BLACK);


	return 0;
}

