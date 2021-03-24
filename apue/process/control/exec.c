#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	char *opts[] = {"ls", "-l", NULL};

	printf("%s start\n", __FUNCTION__);

	pid = fork();
	// if error
	if (pid == 0) {
		// execl("/bin/ls", "ls", "-l", NULL);
		// execlp("ls", "ls", "-l", NULL);
		execv("/bin/ls", opts);
		perror("execl()");
		exit(1);
	}

	wait(NULL);
	printf("%s end\n", __FUNCTION__);

	exit(0);
}

