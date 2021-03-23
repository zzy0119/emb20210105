#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(void)
{
	// "KEY=VALUE"

#if 0
	for (int i = 0; environ[i]; i++)
		puts(environ[i]);
#endif
	char *p = getenv("PATH");
	puts(p);

	setenv("PATH", ".", 1);

	p = getenv("PATH");
	puts(p);

	return 0;
}



