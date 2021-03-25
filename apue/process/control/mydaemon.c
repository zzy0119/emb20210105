#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE	100

int mydaemon(void);
int main(void)
{
	FILE *fp = NULL;
	time_t tm;
	struct tm *tmp;
	char buf[BUFSIZE] = {};
	// 将时间字符串"yy-mm-dd hh:mm:ss"写入/tmp/out,每过一秒就写一次	

	if (mydaemon() == -1) {
		fprintf(stderr, "mydaemon() failed\n");
		exit(1);
	}

	fp = fopen("/tmp/out", "w");
	if (NULL == fp) {
		perror("fopen()");
		exit(1);
	}

	while (1) {
		time(&tm);	
		tmp = localtime(&tm);
		// if error
		memset(buf,'\n', BUFSIZE);
		strftime(buf, BUFSIZE, "%Y-%m-%d %H:%M:%S\n", tmp);
		fputs(buf, fp);
		fflush(NULL);
	
		sleep(1);
	}

	fclose(fp);

	exit(0);
}

int mydaemon(void)
{
	pid_t pid;
	int fd;

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		return -1;
	}
	if (pid > 0)
		exit(0);
	if (setsid() == -1) {
		perror("setsid()");
		return -1;
	}
	// PID == PGID == SID 脱离控制终端
	umask(0);
	chdir("/");
	// 0, 1, 2重定向

	fd = open("/dev/null", O_RDWR);
	if (fd == -1) {
		perror("open()");
		return -1;
	}
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2)
		close(fd);

	return 0;
}


