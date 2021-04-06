#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

static void exit_handler1(void *s)
{
	printf("%s is called\n", __FUNCTION__);
}

static void exit_handler2(void *s)
{
	printf("%s is called\n", __FUNCTION__);
}

static void *thr_job(void *s)
{
	pthread_cleanup_push(exit_handler1, NULL);
	pthread_cleanup_push(exit_handler2, NULL);

	for (int i = 0; i < 5; i++) {
		write(1, "*", 1);
		sleep(1);
	}
	
	// return (void *)0;
	pthread_exit((void *)0);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
}

int main(void)
{
	pthread_t tid;
	int err;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	err = pthread_create(&tid, &attr, thr_job, NULL);
	if (err) {
		fprintf(stderr, "pthread_create():%s\n", strerror(err));
		exit(1);
	}

	// pthread_detach(tid);

	for (int i = 0; i < 3; i++) {
		write(1, "!", 1);
		sleep(1);
	}

	// 收尸
	// pthread_join(tid, NULL);

	pthread_exit((void *)0);
	// return 0;
}

