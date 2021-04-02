#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THRNR	4
#define START	100
#define END		300

/*
 job > 0所发放的任务
 job == 0 任务已经被取走
 job == -1 所有任务发放完成
 */
static int job = 0; // 临界区
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

static void *thr_job(void *s)
{


}

int main(void)
{
	pthread_t tids[THRNR] = {};
	int i;

	for (i = 0; i < THRNR; i++)	{
		pthread_create(tids+i, NULL, thr_job, NULL);
		// if error
	}

	// 发放任务
	for (i = START; i <= END; i++) {
		pthread_mutex_lock(&mut);
		while (job != 0) {
			// 上次任务还未被取走
			pthread_mutex_unlock(&mut);
			sched_yield();
			pthread_mutex_lock(&mut);
		}
		job = i;
		pthread_mutex_unlock(&mut);
	}

	// 任务发放完成
	pthread_mutex_lock(&mut);
	while (job > 0) {
		// 最后一个任务还未取走
		pthread_mutex_unlock(&mut);
		sched_yield();
		pthread_mutex_lock(&mut);
	}
	job = -1;
	pthread_mutex_unlock(&mut);

	for (i = 0; i < THRNR; i++)
		pthread_join(tids[i], NULL);

	pthread_mutex_destroy(&mut);

	exit(0);
}







