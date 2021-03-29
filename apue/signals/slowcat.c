#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFSIZE	10
#define CPS		10

static int token = 0;

static void alrm_handler(int s)
{
	// alarm(1);
	token = 1;
}

int main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;
	struct itimerval itv;

	signal(SIGALRM, alrm_handler);
	// sigaction
	// alarm(1);
	itv.it_interval.tv_sec = 0;
	itv.it_interval.tv_usec = 100000;
	itv.it_value.tv_sec = 3;
	itv.it_value.tv_usec = 500000;
	setitimer(ITIMER_REAL, &itv, NULL);

	if (argc < 2)
		return 1;
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd) {
		perror("open()");
		return 1;
	}

	while (1) {
		// 流量控制
		while (token == 0)
			pause();
		token = 0;
		
		memset(buf, '\0', BUFSIZE);
		cnt = read(fd, buf, BUFSIZE);
		if (cnt == -1) {
			perror("read()");
			goto ERROR;
		}
		if (cnt == 0) {
			// EOF
			break;
		}
		write(1, buf, cnt);
	}

	close(fd);
	
	return 0;
ERROR:
	close(fd);
	return 1;
}

