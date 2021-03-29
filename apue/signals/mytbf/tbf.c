#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "tbf.h"

typedef struct {
	int token;
	int cps;
	int burst;
}tbf_t;

static tbf_t *jobs[MAXTBFS];
static int inited = 0;

static void alrm_handler(int s)
{
	// 遍历令牌桶库
	int i;

	alarm(1);

	for (i = 0; i < MAXTBFS; i++) {
		if (jobs[i]) {
			jobs[i]->token += jobs[i]->cps;
			if (jobs[i]->token > jobs[i]->burst)
				jobs[i]->token = jobs[i]->burst;
		}
	}
}

static void moduler_load(void)
{
	signal(SIGALRM, alrm_handler);
	alarm(1);
}

static int get_free_pos(void)
{
	for (int i = 0; i < MAXTBFS; i++)
		if (jobs[i] == NULL)
			return i;

	return -1;
}

int tbf_init(int cps, int burst)
{
	tbf_t *t;
	int pos;

	if (inited == 0) {
		moduler_load();
		inited = 1;
	}

	t = malloc(sizeof(tbf_t));
	if (NULL == t)
		return -1;
	t->token = 0;
	t->cps = cps;
	t->burst = burst;

	pos = get_free_pos();
	if (pos < 0) {
		free(t);
		return -1;
	}
	jobs[pos] = t;

	return pos;
}

int tbf_fetchtoken(int tbf_id, int ntokens)
{
	int n;

	if (tbf_id >= MAXTBFS || tbf_id < 0)
		return -1;

	while (jobs[tbf_id]->token <= 0)
		pause();
	if (jobs[tbf_id]->token > ntokens)
		n = ntokens;
	else
		n = jobs[tbf_id]->token;

	jobs[tbf_id]->token -= n;

	return n;
}

void tbf_destroy(int tbf_id)
{
	free(jobs[tbf_id]);
	jobs[tbf_id] = NULL;
}

void tbf_destroy_all(void)
{
	int i;

	for (i = 0; i < MAXTBFS; i++) {
		free(jobs[i]);
		jobs[i] = NULL;
	}
}

int tbf_returntoken(int tbf_id, int ntokens)
{
	if (tbf_id >= MAXTBFS || tbf_id < 0)
		return -1;
	jobs[tbf_id]->token += ntokens;
	if (jobs[tbf_id]->token > jobs[tbf_id]->burst)
		jobs[tbf_id]->token = jobs[tbf_id]->burst;

	return 0;
}





