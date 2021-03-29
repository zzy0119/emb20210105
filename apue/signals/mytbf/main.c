#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "tbf.h"

// 令牌桶:速率 令牌 上限

#define BUFSIZE	10
#define CPS		BUFSIZE	
#define BURST	100

int main(int argc, char *argv[])
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;
	int tbfid;
	int n;

	tbfid = tbf_init(CPS, BURST);
	// if error

	if (argc < 2)
		return 1;
	do {
		fd = open(argv[1], O_RDONLY);
		if (-1 == fd) {
			// 是否为假错
			if (errno == EINTR)
				continue;
			perror("open()");
			return 1;
		}
		break;
	} while (1);

	while (1) {
		// 流量控制
		n = tbf_fetchtoken(tbfid, CPS);
		
		memset(buf, '\0', BUFSIZE);
		while (1) {
			cnt = read(fd, buf, n);
			if (cnt == -1) {
				if (errno == EINTR)
					continue;
				perror("read()");
				goto ERROR;
			}
			break;
		}
		if (n > cnt)
			tbf_returntoken(tbfid, n-cnt);
		if (cnt == 0) {
			// EOF
			break;
		}
		write(1, buf, cnt);
	}

	tbf_destroy(tbfid);

	close(fd);
	
	return 0;
ERROR:
	close(fd);
	return 1;
}

