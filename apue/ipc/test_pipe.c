/*
	父进程讲argv[1]文件陆续写入管道，子进程读管道数据并大小写转换写到终端 
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE	10

int changeStr(char *p);
int copyFile(int rfd, int wfd, int flag);
int main(int argc, char *argv[])
{
	int fd;
	int pfd[2];
	pid_t pid;

	if (argc < 2)
		exit(1);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open()");
		exit(1);
	}

	if (pipe(pfd) == -1) {
		perror("pipe()");
		goto ERROR1;
	}

	pid = fork();
	if (pid == -1) {
		perror("fork()");
		goto ERROR2;
	}

	if (pid == 0) {
		close(pfd[1]);
		copyFile(pfd[0], 1, 1);
		close(pfd[0]);
		exit(0);
	}

	close(pfd[0]);
	copyFile(fd, pfd[1], 0);
	close(pfd[1]);

	wait(NULL);

	exit(0);
ERROR2:
	close(pfd[0]);
	close(pfd[1]);
ERROR1:
	close(fd);
	exit(1);
}

// copy file
int copyFile(int rfd, int wfd, int flag)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while (1) {
		memset(buf, '\0', BUFSIZE);
		cnt = read(rfd, buf, BUFSIZE-1);
		if (cnt == -1) {
			return errno;
		}
		if (cnt == 0)
			break;
		if (flag)
			changeStr(buf);
		write(wfd, buf, cnt);
	}

	return 0;
}

int changeStr(char *p)
{
	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {
			*p = *p + ('a'-'A');
		}
		else if (*p >= 'a' && *p <= 'z') {
			*p = *p - ('a'-'A');
		}
		p++;
	}

	return 0;
}




