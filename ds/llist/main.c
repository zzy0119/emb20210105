#include <stdio.h>
#include <string.h>

#include "llist.h"

#define NAMESIZE	32

struct stu_st {
	int age;
	char name[NAMESIZE];
};

static void showStu(const void *data);
static int namecmp(const void *data, const void *key);
int main(void)
{
	llisthead_t *head;
	struct stu_st stu;

	llisthead_init(sizeof(struct stu_st), &head);

	for (int i = 0; i < 10; i++) {
		stu.age = 20 + i;
		snprintf(stu.name, NAMESIZE, "stu%02d", i+1);
		llistInsert(head, &stu, INSERTTAIL);
	}

	llistTraval(head, showStu);

	printf("*****************delete******************\n");
	char *delname = "stu10";
	llistDelete(head, &delname, namecmp);
	llistTraval(head, showStu);

	listDestroy(head);

	return 0;
}

static void showStu(const void *data)
{
	const struct stu_st *d = data;
	printf("%d %s\n", d->age, d->name);
}

static int namecmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	char *const*k = key;

	return strcmp(d->name, *k);
}



