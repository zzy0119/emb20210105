#include <stdlib.h>
#include "lstack.h"

int lstackInit(int size, lstack_t **ls)
{
	return llisthead_init(size, ls);
}

int lstackIsEmpty(lstack_t *ls)
{
	return llistIsEmpty(ls);
}

// 入栈
int lstackPush(lstack_t *ls, const void *data)
{
	return llistInsert(ls, data, INSERTHEAD);
}

static int alwaysCmp(const void *data, const void *key)
{
	return 0;
}

// 出栈
int lstackPop(lstack_t *ls, void *data)
{
	return llistFetch(ls, NULL, alwaysCmp, data);
}

// 销毁
void lstackDestroy(lstack_t *ls)
{
	listDestroy(ls);
}

