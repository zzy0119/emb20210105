#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("hello");
	fflush(NULL);
	printf("world");

	fprintf(stderr, "i am error");

	write(1, "good", 4);
	write(1, "morning", 7);


	return 0;
}
