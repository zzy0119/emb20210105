#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	pid_t pid;
	int shmid;
	int created = 1;
	char *p;

	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | IPC_EXCL | 0600);
	if (shmid == -1) {
		if (errno == EEXIST) {
			shmid = shmget(IPC_PRIVATE, 1024, 0);
			created = 0;
		} else {
			perror("shmget()");
			exit(1);
		}
	}

	pid = fork(); 
	if (pid == -1) {
		perror("fork()");
		if (created)
			shmctl(shmid, IPC_RMID, NULL);
		exit(1);
	}
	if (pid == 0) {
		p = shmat(shmid, NULL, 0);
		strcpy(p, "hello world");
		shmdt(p);
		exit(0);
	}
	wait(NULL);

	p = shmat(shmid, NULL, SHM_RDONLY);
	puts(p);
	shmdt(p);

	if (created)	
		shmctl(shmid, IPC_RMID, NULL);

	exit(0);
}

