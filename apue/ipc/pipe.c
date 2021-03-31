#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUFSIZE	100

int main(void)
{
	int pfd[2] = {};
	pid_t pid;
	char buf[BUFSIZE] = {};

	if (pipe(pfd) == -1) {
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if (pid == -1) {
		perror("fork()");
		close(pfd[0]);
		close(pfd[1]);
		exit(1);
	}

	if (pid == 0) {
		close(pfd[0]);
		sleep(1);
		write(pfd[1], "good morning", 12);
		close(pfd[1]);
		exit(0);
	}

	close(pfd[1]);
	read(pfd[0], buf, BUFSIZE);
	close(pfd[0]);
	puts(buf);

	wait(NULL);

	exit(0);
}

