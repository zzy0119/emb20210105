#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("pid:%d, ppid:%d\n", pid, ppid);

	// 创建子进程
	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	// 两份代码在运行
	if (pid == 0) {
		// child
		printf("child's pid:%d, child's parent pid:%d\n", getpid(), getppid());
		exit(0);
	}

	// 调用进程
	for (int i = 0; i < 3; i++) {
		write(1, "*", 1);
		sleep(1);
	}


	exit(0);
}

