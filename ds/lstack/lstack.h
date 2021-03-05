#ifndef __LSTACK_H
#define __LSTACK_H
#include <llist.h>

// 链栈
typedef llisthead_t lstack_t;

int lstackInit(int size, lstack_t **ls);

int lstackIsEmpty(lstack_t *ls);

// 入栈
int lstackPush(lstack_t *ls, const void *data); 

// 出栈
int lstackPop(lstack_t *ls, void *data);

// 销毁
void lstackDestroy(lstack_t *ls);

#endif

