#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	int num = 100;

	pid = vfork();
	if (-1 == pid) {
		perror("vfork()");
		exit(1);
	}
	if (pid == 0) {
		num ++;	
		printf("[%d] num:%d\n", getpid(), num);
		sleep(1);
		_exit(0);
	}
	printf("[%d] num:%d\n", getpid(), num);

	exit(0);
}
