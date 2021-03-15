#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

#if 0
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("errno:%d\n", errno);
		perror("open()");
		return 1;
	}
	printf("fd:%d\n", fd);
#endif
	// mode & ~umask
	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd) {
		perror("open()");
		return 1;
	}

	close(fd);

	return 0;
}

