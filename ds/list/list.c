#include "list.h"
#include <stdlib.h>
#include <string.h>

int listheadInit(int size, listhead_t **l)
{
	listhead_t *h;

	h = malloc(sizeof(listhead_t));
	if (NULL == h)
		return -1;

	h->next = NULL;
	h->size = size;
	h->nmemb = 0;

	*l = h;

	return 0;
}


int listInsert(listhead_t *l, const void *data, int way)
{
	node_t *new;	
	node_t *p;

	new = malloc(sizeof(node_t));
	if (NULL == new)
		return -1;
	new->data = malloc(l->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, l->size);
	if (way == HEADINSERT) {
		new->next = l->next;
		l->next = new;
	} else if (way == TAILINSERT) {
		for (p = l->next; p->next != NULL; p = p->next)	
			;
		p->next = new;
		new->next = NULL;
	}

	return 0;
}

/*
int listDelete(listhead_t *l, const void *key, cmp_t cmp)
{

}
*/

void listTraval(const listhead_t *l, pri_t pri)
{
	node_t *p;

	for (p = l->next; p != NULL; p = p->next) {
		pri(p->data);
	}
}

/*
static void nodeDestroy(node_t **p)
{
	if ((*p)->next == NULL) {
		free(*p);
		*p = NULL;
	}

	nodeDestroy(&(*p)->next);
}

void listDestroy(listhead_t *l)
{
	nodeDestroy(&l->next);	
	free(l);
}
*/

void listDestroy(listhead_t *l)
{
	node_t *p, *n;

	for (p = l->next, n = p->next; ; n = n->next) {
		free(p);
		p = n;
		if (p == NULL)
			break;
	}

	free(l);
}



