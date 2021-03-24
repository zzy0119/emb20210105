#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, wait_pid;

	pid = fork();
	// if error;

	if (pid == 0) {
		setpgid(getpid(), getpid());
		printf("pid:%d, pgid:%d\n", getpid(), \
				getpgid(0));
		exit(0);
	}
	printf("parent pid:%d, pgid:%d\n", getpid(), \
			getpgid(0));
// 	wait(NULL);
	wait_pid = waitpid(-pid, NULL, 0);
	printf("child pid:%d, wait pid:%d\n", \
			pid, wait_pid);

	exit(0);
}

