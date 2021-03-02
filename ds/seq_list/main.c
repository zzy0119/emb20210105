#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "seqlist.h"

#define NAMESIZE	32

struct stu_st {
	char name[NAMESIZE];
	int age;
};

static void showStu(const void *data)
{
	const struct stu_st *d = data;

	printf("%s %d\n", d->name, d->age);
}

static int intcmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const int *k = key;

	return d->age - *k;
}

static int nameCmp(const void *data, const void *key)
{
	const struct stu_st *d =  data;
	const char *k = key;

	return strcmp(d->name, k);
}

static int ageCmp(const void *data, const void *newdata)
{
	const struct stu_st *d = data;
	const struct stu_st *new = newdata;

	return new->age - d->age;
}

int main(void)
{
	seqlist_t *mylist;
	int key;
	struct stu_st *f;
	struct stu_st s;
	char *delname;

	mylist = seqlistInit(sizeof(struct stu_st));
	// if error

	srand(getpid());

	for (int i = 1; i <= 20; i += 2) {
		s.age = 20 + rand() % 10;
		snprintf(s.name, NAMESIZE, "stu%d", i);
		seqlistSortInsert(mylist, &s, ageCmp);
	}

	seqlistTraval(mylist, showStu);

	key = 25;	
	f = seqlistFind(mylist, &key, intcmp);
	if (f == NULL)
		printf("沒有值位%d的元素\n", key);
	else 
		printf("找到了%s\n", f->name);

	// 删除
	delname = "stu11";		
	seqlistDelete(mylist, delname, nameCmp);
	seqlistTraval(mylist, showStu);

	seqlistDestroy(mylist);

	return 0;
}

