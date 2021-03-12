#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NAMESIZE	32

struct node_st {
	int id;
	char name[NAMESIZE];
	struct list_head node;
};

int main(void)
{
	struct node_st *new;
	struct list_head *pos;

	LIST_HEAD(head);

	for (int i = 1; i <= 10; i++) {
		new = malloc(sizeof(*new));
		// if error;
		new->id = i;
		snprintf(new->name, NAMESIZE, "stu%d", i);
		list_add(&new->node, &head);
	}

	list_for_each(pos, &head) {
		new = list_entry(pos, struct node_st, node);
		printf("%d %s\n", new->id, new->name);
	}

	return 0;
}

