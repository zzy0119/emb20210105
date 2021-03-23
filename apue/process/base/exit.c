#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler1(void)
{
	printf("%s is called\n", __FUNCTION__);
}

void handler2(void)
{
	printf("%s is called\n", __FUNCTION__);
}

void handler3(void)
{
	printf("%s is called\n", __FUNCTION__);
}

void test(void)
{

	// return;
	exit(0);
}

int main(void)
{

	atexit(handler1);
	atexit(handler2);
	atexit(handler3);
	// test();
	printf("hello world");

	exit(EXIT_SUCCESS);
	// _exit(EXIT_SUCCESS);
}

