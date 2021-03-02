#include <stdio.h>

#include "list.h"

static void showInt(const void *data)
{
	const int *d = data;

	printf("%d\n", *d);
}

int main(void)
{
	int arr[] = {3,1,6,7,8,9,4};
	listhead_t *head;

	listheadInit(sizeof(int), &head);

	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		listInsert(head, arr+i, HEADINSERT);
	}

	listTraval(head, showInt);

	listDestroy(head);

	return 0;
}

