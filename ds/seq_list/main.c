#include <stdio.h>

#include "seqlist.h"

static void showInt(const void *data)
{
	const int *d = data;

	printf("%d\n", *d);
}

static int intcmp(const void *data, const void *key)
{
	const int *d = data;
	const int *k = key;

	return *d - *k;
}

int main(void)
{
	seqlist_t *mylist;
	int key;
	void *f;

	mylist = seqlistInit(sizeof(int));
	// if error

	for (int i = 1; i <= 20; i += 2) {
		seqlistInsert(mylist, &i);
	}

	seqlistTraval(mylist, showInt);

	key = 25;	
	f = seqlistFind(mylist, &key, intcmp);
	if (f == NULL)
		printf("沒有值位%d的元素\n", key);
	else 
		printf("找到了%d\n", *(int *)f);

	return 0;
}

