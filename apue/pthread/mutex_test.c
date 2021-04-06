/*
 有5个任务线程，分别向标准输出循环打印'a','b','c','d','e',
 现在整个进程执行5秒钟，如何使得终端打印的字符串是有序的abcdeabcdeabcde..... 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THRNR	5

static int cur_id = 0;
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static void *thr_job(void *s)
{
	int id = (int)s;

	while (1) {
		pthread_mutex_lock(&mut);
		while (cur_id != id) {
			pthread_cond_wait(&cond, &mut);
		}
		printf("%c", 'a'+id);
		fflush(NULL);
		cur_id = -1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mut);
	}

}

int main(void)
{
	pthread_t tids[THRNR] = {};
	int err;

	for (int i = 0; i < THRNR; i++) {
		err = pthread_create(tids+i, NULL, thr_job, (void *)i);
		// if error;
	}

	alarm(5);

	for (int i = 0; i < THRNR; i = (i+1) % THRNR) {
		pthread_mutex_lock(&mut);
		while (cur_id != -1) {
			pthread_cond_wait(&cond, &mut);
		}
		cur_id = i;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mut);
	}

	exit(0);
}

