#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
 现有100~300之间201数
 要求创建201进程同时筛质数

分块:
创建4个任务进程
1号100~150
2号151~200
...

交叉分配
3个任务进程
1号100 103
2号101 104
3号102 105

 */

#define START 	100
#define END		300

static int isPrimer(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;

	return 1;
}

int main(void)
{
	pid_t pid;
	int i;

	for (i = START; i <= END; i++) {
		pid = fork();
		if (-1 == pid) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			if (isPrimer(i))	
				printf("[%d]%d is a primer\n", \
						getpid(), i);
			exit(0);
		}
	}

	for (i = START; i <= END; i++)
		wait(NULL);


	exit(0);
}

