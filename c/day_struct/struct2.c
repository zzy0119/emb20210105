#include <stdio.h>

typedef struct test_st {
	char var1;
	short var2;
	char var3;
}test_t;

typedef struct {
	char var1;
	int var2;
	long var3;
	char var4;
}test2_t;

int main(void)
{
	test_t t;
	test2_t t2;

	printf("%p, %p\n", &t.var1, &t.var2);
	printf("%ld\n", sizeof(t));

	printf("%ld\n", sizeof(t2));

	return 0;
}

