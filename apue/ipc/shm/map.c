#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

int main(void)
{
	char *ptr;
	pid_t pid;

	ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, \
			MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	if (MAP_FAILED == ptr) {
		perror("mmap()");
		exit(1);
	}

	pid = fork();
	if (pid == -1) {
		perror("fork()");
		munmap(ptr, 1024);
		exit(1);
	}
	if (pid == 0) {
		memcpy(ptr, "good morning", 12);
		munmap(ptr, 1024);
		exit(0);
	}

	wait(NULL);
	puts(ptr);	
	munmap(ptr, 1024);

	exit(0);
}

