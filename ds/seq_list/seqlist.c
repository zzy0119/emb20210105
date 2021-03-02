#include "seqlist.h"
#include <stdlib.h>
#include <string.h>

seqlist_t *seqlistInit(int size)
{
	seqlist_t *s;

	s = malloc(sizeof(seqlist_t));
	if (NULL == s)
		return NULL;
	s->arr = NULL;	
	s->size = size;
	s->nmemb = 0;

	return s;
}

int seqlistInsert(seqlist_t *s, const void *data)
{
	s->arr = realloc(s->arr, (s->nmemb+1)*s->size);
	if (NULL == s->arr)
		return -1;
	memcpy((char *)s->arr+s->nmemb*s->size, data, s->size);
	s->nmemb ++;

	return 0;
}

void seqlistTraval(const seqlist_t *s, void (*pri)(const void *data))
{
	for (int i = 0; i < s->nmemb; i++) {
		pri((char *)s->arr+i*s->size);	
	}
}

static int findIndex(const seqlist_t *s, const void *key, cmp_t cmp)
{
	for (int i = 0; i < s->nmemb; i++) {
		if (cmp((char *)s->arr + i * s->size, key) == 0)
			return i;
	}

	return -1;
}

void *seqlistFind(const seqlist_t *s, const void *key, cmp_t cmp)
{
	int f = findIndex(s, key, cmp);
	if (f == -1)
		return NULL;
	return (char *)s->arr + f*s->size;
}

// 删除
int seqlistDelete(seqlist_t *s, const void *key, cmp_t cmp)
{
	int f = findIndex(s, key, cmp);	
	if (f == -1)
		return -1;
	memcpy((char *)s->arr+f*s->size, (char *)s->arr+(f+1)*s->size, \
			(s->nmemb-(f+1)) * s->size);
	s->nmemb --;

	return 0;
}

// 修改
int seqlistUpdate(const seqlist_t *s, const void *key, cmp_t cmp, const void *newdata)
{
	int i = findIndex(s, key, cmp);
	if (i == -1)
		return -1;

	memcpy((char *)s+i*s->size, newdata, s->size);

	return 0;
}

// 销毁
void seqlistDestroy(seqlist_t *s)
{
	free(s->arr);
	s->arr = NULL;
	free(s);
}

int seqlistSortInsert(seqlist_t *s, const void *data, cmp_t cmp)
{
	int i;

	for (i = 0; i < s->nmemb; i++) {
		if (cmp((char *)s->arr+i*s->size, data) > 0)
			break;
	}
	s->arr = realloc(s->arr, (s->nmemb+1) * s->size);	
	if (s->arr == NULL)
		return -1;
	if (s->nmemb > 0)
		memmove((char *)s->arr+(i+1)*s->size, (char *)s->arr+i*s->size, \
				(s->nmemb-i)*s->size);
	memcpy((char *)s->arr+i*s->size, data, s->size);

	s->nmemb ++;

	return 0;
}


