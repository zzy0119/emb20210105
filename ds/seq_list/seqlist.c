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



