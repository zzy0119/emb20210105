#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	char buf[100] = {};
	int ret;

	if (argc < 2)
		return 1;

	fd = open(argv[1], O_RDWR/* | O_APPEND*/);
	if (fd == -1) {
		perror("open()");
		return 1;
	}
	printf("%ld\n", lseek(fd, 0, SEEK_CUR));
	lseek(fd, 10, SEEK_SET);
	
	read(fd, buf, 10);
	puts(buf);

	ret = lseek(fd, -40, SEEK_END);
	if (ret == -1) {
		perror("lseek()");
		close(fd);
		return 1;
	}
	printf("ret:%d\n", ret);
	write(fd, "helloworld", 10);

	// 空洞文件
	lseek(fd, 1024, SEEK_END);
	write(fd, "e", 1);


	close(fd);

	return 0;
}

