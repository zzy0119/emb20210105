#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid, ppid;
	int num = 100;

	pid = getpid();
	ppid = getppid();

	printf("pid:%d, ppid:%d\n", pid, ppid);
	
	printf("!!!!!!!hello world!!!!!!!!!!!");

	fflush(NULL);

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

		printf("before write:%d\n", num);
		num = 200;
		printf("after write:%d\n", num);

		sleep(2);

		exit(0);
	}

#if 0
	// 调用进程
	for (int i = 0; i < 3; i++) {
		write(1, "*", 1);
		sleep(1);
	}
#endif

	// 收尸
	wait(NULL);

	printf("after child process write:%d\n", num);


	exit(0);
}

