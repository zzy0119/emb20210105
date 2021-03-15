#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE	100

int main(int argc, char *argv[])
{
	int rfd, wfd;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 3)
		return 1;

	rfd = open(argv[1], O_RDONLY);
	if (-1 == rfd) {
		perror("open()");
		goto ERROR1;
	}
	wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (-1 == wfd) {
		perror("open()");
		goto ERROR2;
	}

	while (1) {
		cnt = read(rfd, buf, BUFSIZE);
		if (cnt == -1) {
			perror("read()");
			goto READERROR;
		}
		if (cnt == 0)
			break;
		write(wfd, buf, cnt);	
	}

	close(rfd);
	close(wfd);

	return 0;
READERROR:
	close(wfd);
ERROR2:
	close(rfd);
ERROR1:
	return 1;
}

