#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char *ptr = NULL;
	int fd;
	struct stat res;

	if (argc < 2)
		exit(1);

	fd = open(argv[1], O_RDONLY);
	// if error

	fstat(fd, &res);
	// if error

	ptr = mmap(NULL, res.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	// if error

	puts(ptr);
	munmap(ptr, res.st_size);

	exit(0);
}

