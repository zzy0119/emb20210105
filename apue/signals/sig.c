#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

static void handler(int s)
{
	printf("arg s:%d\n", s);
	for (int i = 0; i < 3; i ++) {
		write(1, "!", 1);
		sleep(1);
	}
}

int main(void)
{
	int i = 0;
	sighandler_t sig = signal(SIGINT, handler);

	signal(SIGQUIT, handler);

	while (1) {
		i ++;
		if (i > 10)
			signal(SIGINT, sig);
		write(1, "*", 1);
		sleep(1);
	}

	exit(0);
} 
