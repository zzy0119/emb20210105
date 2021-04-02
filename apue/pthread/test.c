#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define START	100
#define END		300

#define THRNR	END-START+1	

static int is_primer(int n)
{
	for (int i = 2; i < n; i ++)
		if (n % i == 0)
			return 0;

	return 1;
}

static void *thrs(void *s)
{
	int n = (int)s;

	if (is_primer(n))
		printf("%d is a primer\n", n);
	pthread_exit((void *)0);
}

int main(void)
{
	pthread_t tids[THRNR] = {};
	int err;

	for (int i = START; i <= END; i++) {
		err = pthread_create(tids+i-START, NULL, thrs, (void *)i);
		// if error
	}
	
	for (int i = START; i <= END; i++)
		pthread_join(tids[i-START], NULL);

	exit(0);
}
