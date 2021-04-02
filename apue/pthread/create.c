#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

static void *thr_job(void *s)
{
	for (int i = 0; i < 5; i++) {
		write(1, "*", 1);
		sleep(1);
	}
	
	return (void *)0;
}

int main(void)
{
	pthread_t tid;
	int err;

	err = pthread_create(&tid, NULL, thr_job, NULL);
	if (err) {
		fprintf(stderr, "pthread_create():%s\n", strerror(err));
		exit(1);
	}

	for (int i = 0; i < 3; i++) {
		write(1, "!", 1);
		sleep(1);
	}

	// 收尸
	pthread_join(tid, NULL);

	pthread_exit((void *)0);
	// return 0;
}

