#include <stdlib.h>
#include <string.h>

#include "stack.h"

int stackInit(int size, int capacity, stack_t **s)
{
	*s = malloc(sizeof(stack_t));
	if (NULL == *s) {
		return -1;
	}
	(*s)->base = (*s)->top = calloc(capacity, size);
	if ((*s)->base == NULL) {
		free(*s);
		return -1;
	}
	(*s)->capacity = capacity;
	(*s)->size = size;

	return 0;
}

int stackIsEmpty(const stack_t *s)
{
	return s->top == s->base;
}

int stackIsFull(const stack_t *s)
{
	return ((char *)s->top - (char *)s->base) / s->size == s->capacity;
}

int stackPush(stack_t *s, const void *data)
{
	if (stackIsFull(s))
		return -1;

	memcpy(s->top, data, s->size);

	s->top = (char *)s->top + s->size;

	return 0;
}

int stackPop(stack_t *s, void *data)
{
	if (stackIsEmpty(s))
		return -1;

	s->top = (char *)s->top - s->size;
	memcpy(data, s->top, s->size);

	return 0;
}	

void stackDestroy(stack_t *s)
{
	free(s->base);
	free(s);
}

