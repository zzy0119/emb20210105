#include "llist.h"

int llisthead_init(int size, llisthead_t **list)
{
	llisthead_t *me;

	me = malloc(sizeof(llisthead_t));
	if (NULL == me)
		return -1;
	me->node.data = NULL;
	me->node.prev = me->node.next = &me->node;
	me->size = size;
	me->nmemb = 0;

	*list = me;

	return 0;
}

