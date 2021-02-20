#include <stdio.h>

int mystrlen(char *p);
int main(void)
{
	char str[] = "good morning";

	printf("%d\n", mystrlen(str));

	return 0;
}

int mystrlen(char *p)
{
	int i = 0;

	for (; p[i] != '\0'; i++)
		;

	return i;
}

