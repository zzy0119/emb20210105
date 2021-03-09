#include <stdlib.h>
#include "lqueue.h"

int lqueueInit(int size, lqueue_t **ls)
{
	return llisthead_init(size, ls);
}

int lqueueIsEmpty(lqueue_t *ls)
{
	return llistIsEmpty(ls);
}

int lenqueue(lqueue_t *ls, const void *data)
{
	return llistInsert(ls, data, INSERTTAIL);
}

static int alwaysCmp(const void *data, const void *key)
{
	return 0;
}

int ldequeue(lqueue_t *ls, void *data)
{
	return llistFetch(ls, NULL, alwaysCmp, data);
}

// 销毁
void lqueueDestroy(lqueue_t *ls)
{
	listDestroy(ls);
}

