#include <stdio.h>

#include "seqlist.h"

static void showInt(const void *data)
{
	const int *d = data;

	printf("%d\n", *d);
}

int main(void)
{
	seqlist_t *mylist;

	mylist = seqlistInit(sizeof(int));
	// if error

	for (int i = 1; i <= 20; i += 2) {
		seqlistInsert(mylist, &i);
	}

	seqlistTraval(mylist, showInt);

	return 0;
}

