#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

#define BUFSIZE	100

#define LOCKFILE	"/var/run/daemon.pid"

int mydaemon(void);
int run_already(void);
int main(void)
{
	FILE *fp = NULL;
	time_t tm;
	struct tm *tmp;
	char buf[BUFSIZE] = {};
	// 将时间字符串"yy-mm-dd hh:mm:ss"写入/tmp/out,每过一秒就写一次	

#if 0
	if (mydaemon() == -1) {
		fprintf(stderr, "mydaemon() failed\n");
		exit(1);
	}
#endif

	if (daemon(0, 0) == -1) {
		perror("daemon()");
		exit(1);
	}

	if (run_already() == -1) {
		syslog(LOG_ERR, "run_already() failed");
		exit(1);
	}

	openlog(NULL, LOG_PID, LOG_DAEMON);

	fp = fopen("/tmp/out", "w");
	if (NULL == fp) {
		// perror("fopen()");
		syslog(LOG_ERR, "fopen():%s", strerror(errno));
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

// 		syslog(LOG_INFO, "%s 写入了/tmp/out", \
				buf);
	
		sleep(1);
	}

	fclose(fp);
	closelog();

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

int run_already(void)
{
	int fd;
	char buf[BUFSIZE] = {};

	fd = open(LOCKFILE, O_WRONLY | O_CREAT, 0664);	
	if (fd == -1) {
		syslog(LOG_ERR, "open():%s", strerror(errno));
		return -1;
	}

	if (lockf(fd, F_TLOCK, 0) == -1) {
		syslog(LOG_ERR, "lockf():%s", strerror(errno));
		close(fd);
		return -1;
	}

	ftruncate(fd, 0);
	snprintf(buf, BUFSIZE, "%d", getpid());
	write(fd, buf, strlen(buf));

	return 0;
}








