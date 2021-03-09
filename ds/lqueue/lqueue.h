#ifndef __LQUEUE_H
#define __LQUEUEU_H
#include <llist.h>

// 链栈
typedef llisthead_t lqueue_t;

int lqueueInit(int size, lqueue_t **ls);

int lqueueIsEmpty(lqueue_t *ls);

int lenqueue(lqueue_t *ls, const void *data); 

int ldequeue(lqueue_t *ls, void *data);

// 销毁
void lqueueDestroy(lqueue_t *ls);

#endif

