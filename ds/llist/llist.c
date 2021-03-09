#include <llist.h>
#include <stdlib.h>
#include <string.h>

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

/*
 将新的结点插入到两个结点之间
 */
static void nodeInsert(struct node_st *new, struct node_st *pv, struct node_st *nt)
{
	new->next = nt;
	new->prev = pv;
	pv->next = new;
	nt->prev = new;
}

/*插入*/
int llistInsert(llisthead_t *list, const void *data, int way)
{
	struct node_st *me;

	me = malloc(sizeof(struct node_st));
	if (NULL == me)
		return -1;
	me->data = malloc(list->size);
	if (NULL == me->data) {
		free(me);
		return -1;
	}
	memcpy(me->data, data, list->size);

	if (way == INSERTHEAD)
		nodeInsert(me, &list->node, list->node.next);
	else if (way == INSERTTAIL)
		nodeInsert(me, list->node.prev, &list->node);
	else {
		free(me->data);
		free(me);
		return -1;
	}

	return 0;
}

/*遍历*/
void llistTraval(const llisthead_t *list, pri_t pri)
{
	struct node_st *cur;

	for (cur = list->node.next; cur != &list->node; cur = cur->next) {
		pri(cur->data);
	}
}

static void nodeDelete(struct node_st *del)
{
	del->prev->next = del->next;
	del->next->prev = del->prev;

	free(del->data);
	free(del);
}

static struct node_st *nodeFind(const llisthead_t *list, const void *key, cmp_t cmp)
{
	struct node_st *cur;

	for (cur = list->node.next; cur != &list->node; cur = cur->next) {
		if (!cmp(cur->data, key)) {
			return cur;
		}
	}

	return NULL;
}

/*删除*/
int llistDelete(llisthead_t *list, const void *key, cmp_t cmp)
{
	struct node_st *f = nodeFind(list, key, cmp);
	if (NULL == f)
		return -1;
	nodeDelete(f);

	return 0;
}
	
/*查找*/
void *llistSearch(const llisthead_t *list, const void *key, cmp_t cmp)
{
	struct node_st *f = nodeFind(list, key, cmp);
	if (f == NULL)
		return NULL;
	return f->data;
}

/*摘除:删掉指定结点的同事获得数据*/
int llistFetch(llisthead_t *list, const void *key, cmp_t cmp, void *data)
{
	struct node_st *f = nodeFind(list, key, cmp);	
	if (NULL == f)
		return -1;
	memcpy(data, f->data, list->size);

	nodeDelete(f);

	return 0;
}

/*是否为空*/
int llistIsEmpty(const llisthead_t *list)
{
	return list->node.next == &list->node && list->node.prev == &list->node;
}

/*销毁*/
void listDestroy(llisthead_t *list)
{
	struct node_st *cur;
	
	if (!llistIsEmpty(list)) {
		for (cur = (list->node.next)->next; ; cur = cur->next) {
			nodeDelete(cur->prev);
			if (cur == &list->node)
				break;
		}
	}

	free(list);
}

